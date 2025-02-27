#include "tester.h"

void integersBubble(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
    }
}

void integersSelect(void *elements, int primero, int size) {
    int *array = (int*) elements;
    int minIndex = primero;
    for(int j = primero+1; j < size; ++j)
    {
        if (array[minIndex] > array[j]) 
        {
            minIndex = j;
        }
        
    }
    swap(array[primero], array[minIndex]);
}

void integersInsert(void *elements, int i, int size) {
    int *array = (int*) elements;
			int temp = array[i];
		    int j=i-1;
		        while(j >= 0 && temp<array[j]){
			        array[j+1]=array[j];
			        j=j-1;
		        }
		        array[j+1]=temp;	
}

void integersShell(void *elements, int i, int gap) {
    int *array = (int*) elements;
			int j=i+gap;
            int z=i-1;
            if (gap==1)
            {
                if (array[j]<array[i])
                {
                swap(array[j],array[i]);
                }
                int temp = array[i];
            	while(z >= 0 && temp<array[z])
                {
			        array[z+1]=array[z];
			        z=z-1;
		        }
		        array[z+1]=temp;	
            }
            else if (array[j]<array[i])
			{
				swap(array[j],array[i]);
			}
            
}

int quick(void *elements,int primero,int ultimo)
{
    int *array = (int*) elements;
	int pivot=ultimo;
	int max;
	int i=primero-1;
		for(int j=primero;j<pivot;j++)
		{
			if (array[j]<=array[pivot])
			{
				i++;
				swap(array[j],array[i]);
			}
		}
		swap(array[i + 1], array[ultimo]); 
    	return (i + 1); 
	}
  
void quicksort2(void *elements, int primero, int ultimo) 
{ 
    int *array = (int*) elements;
    if (primero < ultimo) 
    { 
        int pivot2 = quick(array, primero, ultimo); 
        quicksort2(array, primero, pivot2 - 1); 
        quicksort2(array, pivot2 + 1, ultimo); 
    } 
} 

void integersQuick(void *elements, int i, int size) {
    int *array = (int*) elements;
    quicksort2(array, 0, size-1);
}



void merge(void *elements, int low, int middle, int high) 
{
    int *array = (int*) elements;
    int i, j, k; 
    int size1 = middle - low + 1; 
    int size2 =  high - middle; 
  
    int left[size1];
    int right[size2]; 
  
    for (i = 0; i < size1; i++) 
        left[i] = array[low + i]; 
    for (j = 0; j < size2; j++) 
        right[j] = array[middle + 1+ j]; 
  
    i = 0; // array aux izquierda
    j = 0; // array aux derecha 
    k = low; // array donde se reemplazan los valores
    
    while (i < size1 && j < size2) 
    { 
        if (left[i] <= right[j]) 
        { 
            array[k] = left[i]; 
            i++; 
        } 
        else
        { 
            array[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < size1) 
    { 
        array[k] = left[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < size2) 
    { 
        array[k] = right[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergesort2(void *elements, int low, int high) 
{ 
    int *array = (int*) elements;
    if (low < high) 
    {
        int middle = (low+high)/2; 
        mergesort2(array, low, middle); 
        mergesort2(array, middle+1, high); 
  
        merge(array, low, middle, high); 
    } 
} 

void integersMerge(void *elements, int i, int size) {
    int *array = (int*) elements;
    mergesort2(array, 0, size-1);
}

Sort* Tester::getSort(Algorithm sort, void *array, size_t size) {
    switch (sort) {
        case bubblesort: return new BubbleSort(array, size);
        case selectsort: return new SelectSort(array, size);
        case insertsort: return new InsertSort(array, size);
        case shellsort: return new ShellSort(array, size);
        case quicksort: return new QuickSort(array, size);
        case mergesort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid sort");
    }
}

fptr Tester::getCompare(Algorithm sort) {
    switch (sort) {
        case bubblesort: return &integersBubble;
        case selectsort: return &integersSelect;
        case insertsort: return &integersInsert;
        case shellsort: return &integersShell;
        case quicksort: return &integersQuick;
        case mergesort: return &integersMerge;
        default: throw invalid_argument("Not a valid comparer");
    }
}

void Tester::integerSorts(int *array, size_t size) {
    Sort* sort;
    int temp[size];

    Algorithm algorithm[] = { bubblesort, selectsort, insertsort, shellsort, quicksort, mergesort};
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}
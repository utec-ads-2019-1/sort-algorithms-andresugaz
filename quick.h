#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            /*for (int i = 0; i < size; i++) 
            {
                compare(elements, i, size);
            }*/
        int x=0;
        compare(elements, x, size);
        }

        inline string name() { return "QuickSort"; }
};

#endif
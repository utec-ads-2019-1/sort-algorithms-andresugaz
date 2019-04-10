#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
            
        int x=0;
        compare(elements, x, size);
        
        }

        inline string name() { return "MergeSort"; }
};

#endif
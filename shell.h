#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(void (*compare)(void*, int, int)) {
  	    int gap = size;
        int fijo = size;
        do
	    {
		    gap=gap/2;
		    for (int i=0;i<fijo-gap;i++)
		    {
                compare(elements, i, gap);
		    }
	    }while(gap!=1);
        }
        
        inline string name() { return "ShellSort"; }
};

#endif
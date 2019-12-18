#ifndef H_OOC_SAMPLE_CLS_CLASS
#define H_OOC_SAMPLE_CLS_CLASS

#include <stdlib.h>

struct Class {
    size_t size;
    void* (*ctor) (void * self, va_list * app);
    void* (*dtor) (void * self);
    void* (*clone) (const void * self);
    int (*differ) (const void * self, const void * b);
};

#endif


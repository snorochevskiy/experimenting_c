#ifndef H_OOC_SAMPLE_NEW
#define H_OOC_SAMPLE_NEW

#include <stddef.h>

size_t sizeOf (const void * self);

void * new (const void * _class, ...);
void delete (void * self);

void * clone (const void * self);

int differ (const void * self, const void * b);

#endif

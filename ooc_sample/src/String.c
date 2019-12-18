#ifndef C_OOC_SAMPLE_CLS_STRING
#define C_OOC_SAMPLE_CLS_STRING

#include <stdarg.h>
#include <assert.h>
#include <string.h>

#include "../include/new.h"
#include "../include/Class.h"
#include "../include/String.h"

struct String {
    /* must be first */
    const void * class;
    char* text;
};

/*
All these methods arestaticbecause they should only be called throughnew(), delete(), or the selectors.
*/

static void * String_ctor (void * _self, va_list * app)
{   struct String * self =_self;
    const char * text = va_arg(*app, const char*);
    self->text = malloc(strlen(text) + 1);
    assert(self->text);
    strcpy(self->text,text);
    return self;
}

static void * String_dtor (void *_self)
{   struct String * self =_self;
    free(self->text), self->text = 0;
    return self;
}

static void * String_clone (const void * _self)
{   const struct String * self =_self;
    return new(String, self->text);
}


static int String_differ(const void * _self, const void * _b)
{   const struct String * self = _self;
    const struct String * b = _b;

    if (self == b)
        return 0;
    if (!b || b->class != String)
        return 1;
    return strcmp(self->text, b->text);
}

static const struct Class _String = {
    sizeof(struct String),
    String_ctor,
    String_dtor,
    String_clone,
    String_differ
};
const void * String = &_String;

#endif


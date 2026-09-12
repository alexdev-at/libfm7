#ifndef _STDDEF_H_
#define _STDDEF_H_

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef unsigned int size_t;
typedef signed int ptrdiff_t;

#define offsetof(type, member) ((size_t)&(((type*)0)->member))

#endif


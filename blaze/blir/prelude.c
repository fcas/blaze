#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Python.h"

#ifdef __cplusplus
extern "C" {
#endif

// ------------------------------------------------------------------------

typedef struct {
    char *data;
    int  nd;
    int  *strides;
} ndarray;

// ------------------------------------------------------------------------
// String Operations
// ------------------------------------------------------------------------

int isNull(void* ptr)
{
    return ptr==NULL;
}

int length(char* string)
{
    return strlen(string);
}

char strIndex(char* string, int i)
{
    return string[i];
}

char* append(char* x, char* y)
{
    // leaks memory...
    char* buf = malloc((strlen(x)+strlen(y))*sizeof(char));
    strcpy(buf, x);
    strcat(buf, y);
    return buf;
}

int strHead(char* str)
{
    return (int)(str[0]);
}

char* strTail(char* str)
{
    return str+1;
}

int strFind(char* str, char c)
{
    int i = 0;
    while(*str!='\0') {
        if (*str==c) {
            return i;
        }
        ++i;
        ++str;
    }
    return -1;
}

// ------------------------------------------------------------------------
// Printing
// ------------------------------------------------------------------------

void show_int(int i)
{
    printf("%i\n", i);
}

void show_float(double f)
{
    printf("%f\n", f);
}

void show_string(char* s)
{
    printf("%s\n", s);
}

void show_bool(int b)
{
    if (b) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void show_array(ndarray *a) {
    printf("array(%p)", a->data);
}

#if PY_VERSION_HEX >= 0x03000000
PyMODINIT_FUNC
PyInit_prelude(void)
{
    PyObject *m;

    m = PyModule_Create(NULL);
    if (m == NULL)
        return NULL;
    return m;
}
#else
PyMODINIT_FUNC
initprelude(void)
{
    PyObject *m;

    m = Py_InitModule("prelude", NULL);
    if (m == NULL)
        return;
}
#endif

#ifdef __cplusplus
}
#endif

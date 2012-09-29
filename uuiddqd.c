#include <Python.h>
#include <uuid/uuid.h>
#include "uuiddqd.h"

PyMODINIT_FUNC
inituuiddqd(void)
{
    (void) Py_InitModule("uuiddqd", UuiddqdMethods);
}

static PyObject *
uuiddqd_generate(PyObject *self, PyObject *args)
{
    uuid_t my_uuid;
    uuid_generate(my_uuid);

    char stringy[36];
    uuid_unparse(my_uuid, stringy);
    return Py_BuildValue("s", stringy);
}

static PyMethodDef UuiddqdMethods[] = {
    {"generate",  uuiddqd_generate, METH_VARARGS,
     "Generates unique uuid."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

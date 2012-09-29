#include <Python.h>
#include <uuid/uuid.h>
#include "uuiddqd3.h"

static struct PyModuleDef uuiddqdmodule = {
   PyModuleDef_HEAD_INIT,
   "uuiddqd",   /* name of module */
   NULL, /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   UuiddqdMethods
};

PyMODINIT_FUNC
PyInit_uuiddqd(void)
{
  PyObject *m;

  m = PyModule_Create(&uuiddqdmodule);
  if(m == NULL)
    return NULL;

  return m;
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


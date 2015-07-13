#include <Python.h>

static PyObject *
foo_test(PyObject *self, PyObject *args) {
	float  a, b;
	if(!PyArg_ParseTuple(args, "ff", &a, &b)) {
		return NULL;
	}

	return PyLong_FromLong(a+b);
}

static PyMethodDef foo_methods[] = {
	{"test", foo_test, METH_VARARGS, "Test Method"},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef foomodule = {
	PyModuleDef_HEAD_INIT,
	"foo",
	"My Module",
	-1,
	foo_methods
};

PyMODINIT_FUNC
PyInit_foo(void)
{
	PyObject *m = PyModule_Create(&foomodule);
	if (m == NULL) {
		return NULL;
	}

	return m;
}
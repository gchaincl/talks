#include <Python.h>

/*
import json
mydict = {}
mydict["foo"] = "bar"
json.dumps(mydict)

'{"foo":"bar"}'
*/

int
main(int argc, char *argv[])
{
	PyObject *pName, *pModule, *pFunc, *pValue, *pDict, *pArgs;

	Py_Initialize();

	pName = PyUnicode_FromString("json");
	pModule = PyImport_Import(pName); // import json

	pFunc = PyObject_GetAttrString(pModule, "dumps");

	pDict = PyDict_New(); // mydict = {}
	PyDict_SetItem(pDict, PyUnicode_FromString("foo"), PyUnicode_FromString("bar")); // mydict["foo"] = "bar"

	pArgs = PyTuple_New(1);
	PyTuple_SetItem(pArgs, 0, pDict); // t = (mydict,)

	pValue = PyObject_CallObject(pFunc, pArgs); // json.dumps(*t) or

	printf("Result of call: %s\n", PyUnicode_AsUTF8(pValue));
}
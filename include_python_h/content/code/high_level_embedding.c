#include <Python.h>

int
main(int argc, char *argv[])
{
	printf("Hello from C code\n");

	Py_Initialize();
	PyRun_SimpleString(
		"from time import time,ctime\n"
		"print('Today is',ctime(time()))\n"
	);
	Py_Finalize();
	return 0;
}
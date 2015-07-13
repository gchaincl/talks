from distutils.core import setup, Extension

foo_module = Extension("foo",
        sources = ["foo.c"]
)

setup(
        name = 'foo lib',
        version = '0.1',
        ext_modules = [foo_module],
)
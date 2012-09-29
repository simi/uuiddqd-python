from distutils.core import setup, Extension

module1 = Extension('uuiddqd',
                    sources = ['uuiddqd.c'],
                    libraries = ['uuid'])

setup (name = 'Uuiddqd',
       version = '0.1',
       description = 'libuuid python binding',
       ext_modules = [module1])

from distutils.core import setup, Extension
import sys

if sys.version[0] == '2':
  module1 = Extension('uuiddqd',
                      sources = ['uuiddqd.c'],
                      libraries = ['uuid'])
else:
  module1 = Extension('uuiddqd',
                      sources = ['uuiddqd3.c'],
                      libraries = ['uuid'])


setup (name = 'Uuiddqd',
       version = '0.1',
       description = 'libuuid python binding',
       ext_modules = [module1])

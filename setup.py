from setuptools import setup, Extension

module = Extension('matrix', sources=['simply.c'])

setup(
    name='matrix',
    version='1.0',
    ext_modules=[module]
)
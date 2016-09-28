========================================================================================================
 pycapicompat.h - Extra CAPI functions for compatibility between various C-based Python implementations
========================================================================================================

:UPDATE: as of 2016-Sep-28 pycapicompat.h is no longer active. All relevant bits
         went into Cython codebase directly: https://github.com/cython/cython/pull/528

--------

( below is original project description )

`pycapicompat.h` is a C-header with additional CAPI functions providing unified
access to C-based functionality between various C-bases Python implementations.
Currently covered are:

- Pyston_
- CPython_

we would also be glad to cover PyPy_ and we will try to do so on a best effort basis.
Patches are, as always, welcome.


.. _Pyston:     https://pyston.org/
.. _CPython:    https://www.python.org/
.. _PyPy:       http://pypy.org/

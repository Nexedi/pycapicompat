#ifndef _PYCAPICOMPAT_H_
#define _PYCAPICOMPAT_H_

/* pycapicompat.h - Extra CAPI functions for compatibility between various C-based Python implementations
 * This file has been placed into Public Domain.
 *
 * The recommended way to use pycapicompat.h is to copy it from canonical
 * location to your project on as-needed basis and include locally.
 *
 * The canonical location is:
 *
 *   https://lab.nexedi.com/nexedi/pycapicompat/raw/master/pycapicompat.h
 *   (or https://lab.nexedi.com/nexedi/pycapicompat.git for Git access)
 *
 * Last updated: 2016-06-13
 */

#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif

// TODO(Daetalus)
#if 0
#ifndef IMPLEMENTATION_SUPPORTS_EXTENDED_C_API
#define PyErr_GetExcInfoType() PyThreadState_GET()->exc_type
#endif
#ifdef PYSTON_VERSION
  foo = PyErr_GetExcInfoType(); // a new API function
#else
  foo = PyThreadState_GET()->exc_type; // direct field access
#endif
#endif

// info about free variables
// TODO(Daetalus) verify and fill more
#ifdef CPYTHON_VERSION
// TODO(Daetalus) see how Cython does this check
#elif defined(PYSTON_VERSION)
void PyCode_HasFreeVars(BoxedCode* code) {
  return code->source->getScopeInfo()->takesClosure();
}
#else
# error TODO pypy:PyCode_HasFreeVars not implemented for your python version
#endif

// TODO(Daetalus) add more stuff.


#ifdef __cplusplus
}
#endif

#endif

#ifndef _PYCAPICOMPAT_H_
#define _PYCAPICOMPAT_H_

/* pycapicompat.h - Extra CAPI functions for compatibility between various C-based Python implementations
 * Copyright (C) 2016 Nexedi SA and Contributors.
 * This file is licensed under the MIT license:
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * ~~~~~~~~
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

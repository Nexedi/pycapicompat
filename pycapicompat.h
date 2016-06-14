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
 * Last updated: 2016-06-17
 */

#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif

/* we support: CPython, Pyston, PyPy.
 * define also CPYTHON_VERSION as PY_VERSION is defined on all implementations */
#if !defined(PYSTON_VERSION) && !defined(PYPY_VERSION)
# define CPYTHON_VERSION    PY_VERSION
#endif


#ifdef CPYTHON_VERSION

// PyCode. Check whether there are free variables
static inline int PyCode_HasFreeVars(PyCodeObject *co) {
    return PyCode_GetNumFree(co) > 0 ? 1 : 0;
}

// PyFrame. Set frame line number
static inline void
PyFrame_SetLineNumber(PyFrameObject *f, int lineno) {
    f->f_lineno = lineno;
}

#elif defined(PYSTON_VERSION)

// PyCode_HasFreeVars(co)               provided out of the box
// PyFrame_SetLineNumber(f, lineno)     provided out of the box

#elif defined(PYPY_VERSION)

// TODO: PyFrame_SetLineNumber(f, lineno)
// TODO: PyCode_HasFreeVars(co)

#endif

#ifdef __cplusplus
}
#endif

#endif

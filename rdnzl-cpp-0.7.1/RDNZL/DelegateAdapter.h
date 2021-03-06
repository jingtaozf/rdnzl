// $Header: /usr/local/cvsrep/rdnzl-cpp/RDNZL/DelegateAdapter.h,v 1.13 2008/02/14 07:34:30 edi Exp $
//
// Copyright (c) 2004-2008, Dr. Edmund Weitz.  All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//
//   * Redistributions in binary form must reproduce the above
//     copyright notice, this list of conditions and the following
//     disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR 'AS IS' AND ANY EXPRESSED
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "DotNetContainer.h"

public ref class DelegateAdapter {
 public:
  ~DelegateAdapter();
  void init(int index);
  Object ^invoke (cli::array<Object^> ^args);
  static void *(*callback)(int, void *);
  static void (*release)(int);
 private:
  // the index into the Lisp hash table which holds the closures -
  // should be a 64-bit integer in the future
  int indexIntoLisp;
};

extern "C" {
  __declspec(dllexport) void setFunctionPointers(void *(*callback_fp)(int, void *), void (*release_fp)(int));
}

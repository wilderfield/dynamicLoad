#pragma once

#ifndef _WIN32
# include <dlfcn.h>
#else
# include <windows.h>
# define RTLD_LAZY 0
# define RTLD_GLOBAL 0
# define RTLD_NOW 0

inline void*
dlopen(const char* dllname, int)
{
  return LoadLibrary(dllname);
}

inline void
dlclose(void* handle)
{
  FreeLibrary(HMODULE(handle));
}

inline const char*
dlerror()
{
  return "";
}

inline void*
dlsym(void* handle, const char* symbol)
{
  return GetProcAddress(HMODULE(handle),symbol);
}

#endif


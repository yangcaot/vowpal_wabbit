#pragma once

#if defined _WIN32 || defined __CYGWIN__
  #ifdef VWDLL_EXPORTS
    #ifdef __GNUC__
      #define VW_DLL_PUBLIC __attribute__ ((dllexport))
    #else
      #define VW_DLL_PUBLIC __declspec(dllexport)
    #endif
  #else
    #ifdef __GNUC__
      #define VW_DLL_PUBLIC __attribute__ ((dllimport))
    #else
      #define VW_DLL_PUBLIC __declspec(dllimport)
    #endif
  #endif
  #define VW_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define VW_DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define VW_DLL_LOCAL __attribute__ ((visibility ("hidden")))
  #else
    #define VW_DLL_PUBLIC
    #define VW_DLL_LOCAL
  #endif
#endif
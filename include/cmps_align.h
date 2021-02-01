/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                             CMPS_ALIGN.h                                    *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 *                                                                            *
 * Distributed under the terms of the Apache 2 License.                       *
 *                                                                            *
 * The full licence is in the file LICENSE, distributed with this software.   *
 ******************************************************************************/

#ifndef __CMPS_ALIGN_H__
#define __CMPS_ALIGN_H__

#include "cmps_instruction_set.h"

/******************************************************************************
 * PLATFORM CHECKS FOR ALIGNED MALLOC FUNCTIONS                               *
 ******************************************************************************/

#if ((defined __QNXNTO__) || (defined _GNU_SOURCE) || ((defined _XOPEN_SOURCE) && (_XOPEN_SOURCE >= 600))) \
 && (defined _POSIX_ADVISORY_INFO) && (_POSIX_ADVISORY_INFO > 0)
  #define CMPS_HAS_POSIX_MEMALIGN 1
#else
  #define CMPS_HAS_POSIX_MEMALIGN 0
#endif

#if defined(CMPS_X86_INSTR_SET_AVAILABLE)
    #define CMPS_HAS_MM_MALLOC 1
#else
    #define CMPS_HAS_MM_MALLOC 0
#endif

/******************************************************************************
 * STACK ALLOCATION                                                           *
 ******************************************************************************/

#ifndef CMPS_ALLOCA
    #if defined(__linux__)
        #define CMPS_ALLOCA alloca
    #elif defined(_MSC_VER)
        #define CMPS_ALLOCA _alloca
    #endif
#endif

/******************************************************************************
 * DEFAULT ALIGNMENT                                                          *
 ******************************************************************************/

#if CMPS_X86_INSTR_SET >= CMPS_X86_AVX512_VERSION
    #define CMPS_DEFAULT_ALIGNMENT 64
#elif CMPS_X86_INSTR_SET >= CMPS_X86_AVX_VERSION
    #define CMPS_DEFAULT_ALIGNMENT 32
#elif CMPS_X86_INSTR_SET >= CMPS_X86_SSE2_VERSION
    #define CMPS_DEFAULT_ALIGNMENT 16
#elif CMPS_ARM_INSTR_SET >= CMPS_ARM8_64_NEON_VERSION
    #define CMPS_DEFAULT_ALIGNMENT 32
#elif CMPS_ARM_INSTR_SET >= CMPS_ARM7_NEON_VERSION
    #define CMPS_DEFAULT_ALIGNMENT 16
#else
    // some versions of gcc do nos handle alignment set ot 0
    // see https://gcc.gnu.org/bugzilla/show_bug.cgi?id=69089
    #if __GNUC__ < 7
        #define CMPS_DEFAULT_ALIGNMENT 8
    #else
        #define CMPS_DEFAULT_ALIGNMENT 0
    #endif
#endif

#endif

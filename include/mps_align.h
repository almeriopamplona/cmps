/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                             MPS_ALIGN.h                                    *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 *                                                                            *
 * Distributed under the terms of the Apache 2 License.                       *
 *                                                                            *
 * The full licence is in the file LICENSE, distributed with this software.   *
 ******************************************************************************/

#ifndef __MPS_ALIGN_H__
#define __MPS_ALIGN_H__

#include "mps_instruction_set.h"

/******************************************************************************
 * PLATFORM CHECKS FOR ALIGNED MALLOC FUNCTIONS                               *
 ******************************************************************************/

#if ((defined __QNXNTO__) || (defined _GNU_SOURCE) || ((defined _XOPEN_SOURCE) && (_XOPEN_SOURCE >= 600))) \
 && (defined _POSIX_ADVISORY_INFO) && (_POSIX_ADVISORY_INFO > 0)
  #define MPS_HAS_POSIX_MEMALIGN 1
#else
  #define MPS_HAS_POSIX_MEMALIGN 0
#endif

#if defined(MPS_X86_INSTR_SET_AVAILABLE)
    #define MPS_HAS_MM_MALLOC 1
#else
    #define MPS_HAS_MM_MALLOC 0
#endif

/******************************************************************************
 * STACK ALLOCATION                                                           *
 ******************************************************************************/

#ifndef MPS_ALLOCA
    #if defined(__linux__)
        #define MPS_ALLOCA alloca
    #elif defined(_MSC_VER)
        #define MPS_ALLOCA _alloca
    #endif
#endif

/******************************************************************************
 * DEFAULT ALIGNMENT                                                          *
 ******************************************************************************/

#if MPS_X86_INSTR_SET >= MPS_X86_AVX512_VERSION
    #define MPS_DEFAULT_ALIGNMENT 64
#elif MPS_X86_INSTR_SET >= MPS_X86_AVX_VERSION
    #define MPS_DEFAULT_ALIGNMENT 32
#elif MPS_X86_INSTR_SET >= MPS_X86_SSE2_VERSION
    #define MPS_DEFAULT_ALIGNMENT 16
#elif MPS_ARM_INSTR_SET >= MPS_ARM8_64_NEON_VERSION
    #define MPS_DEFAULT_ALIGNMENT 32
#elif MPS_ARM_INSTR_SET >= MPS_ARM7_NEON_VERSION
    #define MPS_DEFAULT_ALIGNMENT 16
#else
    // some versions of gcc do nos handle alignment set ot 0
    // see https://gcc.gnu.org/bugzilla/show_bug.cgi?id=69089
    #if __GNUC__ < 7
        #define MPS_DEFAULT_ALIGNMENT 8
    #else
        #define MPS_DEFAULT_ALIGNMENT 0
    #endif
#endif

#endif

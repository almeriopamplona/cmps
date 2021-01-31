/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                             MPS_CONFIG.h                                   *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 *                                                                            *
 * Distributed under the terms of the Apache 2 License.                       *
 *                                                                            *
 * The full licence is in the file LICENSE, distributed with this software.   *
 ******************************************************************************/

#ifndef __MPS_CONFIG_H__
#define __MPS_CONFIG_H__

#include "mps_align.h"

#define MPS_VERSION_MAJOR 1
#define MPS_VERSION_MINOR 0
#define MPS_VERSION_PATCH 0

#ifndef MPS_DEFAULT_ALLOCATOR
    #if MPS_X86_INSTR_SET_AVAILABLE
        #define MPS_DEFAULT_ALLOCATOR(T) malloc(T, MPS_DEFAULT_ALIGNMENT)
    #else
        #define MPS_DEFAULT_ALLOCATOR(T) malloc(T)
    #endif
#endif

#ifndef MPS_STACK_ALLOCATION_LIMIT
    #define MPS_STACK_ALLOCATION_LIMIT 20000
#endif

#if defined(__LP64__) || defined(_WIN64)
    #define MPS_64_BIT_ABI
#else
    #define MPS_32_BIT_ABI
#endif

#endif

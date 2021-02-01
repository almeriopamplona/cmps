/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                             CMPS_CONFIG.h                                  *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 *                                                                            *
 * Distributed under the terms of the Apache 2 License.                       *
 *                                                                            *
 * The full licence is in the file LICENSE, distributed with this software.   *
 ******************************************************************************/

#ifndef __CMPS_CONFIG_H__
#define __CMPS_CONFIG_H__

#include "cmps_align.h"

#define CMPS_VERSION_MAJOR 1
#define CMPS_VERSION_MINOR 0
#define CMPS_VERSION_PATCH 0

#ifndef CMPS_DEFAULT_ALLOCATOR
    #if CMPS_X86_INSTR_SET_AVAILABLE
        #define CMPS_DEFAULT_ALLOCATOR(T) malloc(T, CMPS_DEFAULT_ALIGNMENT)
    #else
        #define CMPS_DEFAULT_ALLOCATOR(T) malloc(T)
    #endif
#endif

#ifndef CMPS_STACK_ALLOCATION_LIMIT
    #define CMPS_STACK_ALLOCATION_LIMIT 20000
#endif

#if defined(__LP64__) || defined(_WIN64)
    #define CMPS_64_BIT_ABI
#else
    #define CMPS_32_BIT_ABI
#endif

#endif

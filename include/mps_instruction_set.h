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

/* Simplified version of boost.predef */

#ifndef __MPS_INSTRUCTION_SET_H__
#define __MPS_INSTRUCTION_SET_H__

/******************************************************************************
 * VERSION NUMBER                                                             *
 ******************************************************************************/

#define MPS_VERSION_NUMBER(major, minor, patch) \
((((major) % 100) * 10000000) + (((minor) % 100) * 100000) + ((patch) % 100000))

#define MPS_VERSION_NUMBER_NOT_AVAILABLE MPS_VERSION_NUMBER(0, 0, 0)
#define MPS_VERSION_NUMBER_AVAILABLE     MPS_VERSION_NUMBER(0, 0, 1)

/******************************************************************************
 * CLEAR INSTRUCTION SET                                                      *
 ******************************************************************************/

#undef MPS_X86_INSTR_SET
#undef MPS_X86_INSTR_SET_AVAILABLE

#undef MPS_X86_AMD_INSTR_SET
#undef MPS_X86_AMD_INSTR_SET_AVAILABLE

#undef MPS_PPC_INSTR_SET
#undef MPS_PPC_INSTR_SET_AVAILABLE

#undef MPS_ARM_INSTR_SET
#undef MPS_ARM_INSTR_SET_AVAILABLE

/******************************************************************************
 * USER CONFIGURATION                                                         *
 ******************************************************************************/

#ifdef MPS_FORCE_X86_INSTR_SET
    #define MPS_X86_INSTR_SET           MPS_FORCE_X86_INSTR_SET
    #define MPS_X86_INSTR_SET_AVAILABLE MPS_VERSION_NUMBER_AVAILABLE
    #ifdef _MSC_VER
        #pragma   message("Warning: Forcing X86 instruction set")
    #else
        #warning "Forcing X86 instruction set"
    #endif
#elif defined(MPS_FORCE_X86_AMD_INSTR_SET)
    #define MPS_X86_AMD_INSTR_SET           MPS_FORCE_X86_AMD_INSTR_SET
    #define MPS_X86_AMD_INSTR_SET_AVAILABLE MPS_VERSION_NUMBER_AVAILABLE
    #ifdef _MSC_VER
        #pragma   message("Warning: Forcing X86 AMD instruction set") 
    #else 
        #warning "Forcing X86 AMD instruction set"
    #endif
#elif defined(MPS_FORCE_PPC_INSTR_SET)
    #define MPS_PPC_INSTR_SET MPS_FORCE_PPC_INSTR_SET
    #define MPS_PPC_INSTR_SET_AVAILABLE MPS_VERSION_NUMBER_AVAILABLE
    #ifdef _MSC_VER
        #pragma message("Warning: Forcing PPC instruction set")
    #else
        #warning "Forcing PPC instruction set"
    #endif
#elif defined(MPS_FORCE_ARM_INSTR_SET)
    #define MPS_ARM_INSTR_SET MPS_FORCE_ARM_INSTR_SET
    #define MPS_ARM_INSTR_SET_AVAILABLE MPS_VERSION_NUMBER_AVAILABLE
    #ifdef _MSC_VER
        #pragma message("Warning: Forcing ARM instruction set")
    #else
        #warning "Forcing ARM instruction set"
    #endif
#endif

/******************************************************************************
 * X86 INSTRUCTION SET                                                        *
 ******************************************************************************/

#define MPS_X86_SSE_VERSION    MPS_VERSION_NUMBER(1, 0, 0)
#define MPS_X86_SSE2_VERSION   MPS_VERSION_NUMBER(2, 0, 0)
#define MPS_X86_SSE3_VERSION   MPS_VERSION_NUMBER(3, 0, 0)
#define MPS_X86_SSSE3_VERSION  MPS_VERSION_NUMBER(3, 1, 0)
#define MPS_X86_SSE4_1_VERSION MPS_VERSION_NUMBER(4, 1, 0)
#define MPS_X86_SSE4_2_VERSION MPS_VERSION_NUMBER(4, 2, 0)
#define MPS_X86_AVX_VERSION    MPS_VERSION_NUMBER(5, 0, 0)
#define MPS_X86_FMA3_VERSION   MPS_VERSION_NUMBER(5, 2, 0)
#define MPS_X86_AVX2_VERSION   MPS_VERSION_NUMBER(5, 3, 0)
#define MPS_X86_AVX512_VERSION MPS_VERSION_NUMBER(6, 0, 0)
#define MPS_X86_MIC_VERSION    MPS_VERSION_NUMBER(9, 0, 0)

#if !defined(MPS_X86_INSTR_SET) && defined(__MIC__)
    #define MPS_X86_INSTR_SET MPS_X86_MIC_VERSION
#endif

// AVX512 instructions are supported starting with gcc 6
// see https://www.gnu.org/software/gcc/gcc-6/changes.html
#if !defined(MPS_X86_INSTR_SET) && (defined(__AVX512__) || defined(__KNCNI__) || defined(__AVX512F__)\
    && (!defined(__GNUC__) || __GNUC__ >= 6))
    #define MPS_X86_INSTR_SET MPS_X86_AVX512_VERSION

    #if defined(__AVX512VL__)
        #define MPS_AVX512VL_AVAILABLE 1
    #endif

    #if defined(__AVX512DQ__)
        #define MPS_AVX512DQ_AVAILABLE 1
    #endif

    #if defined(__AVX512BW__)
        #define MPS_AVX512BW_AVAILABLE 1
    #endif

    #if __GNUC__ == 6
        #define MPS_AVX512_SHIFT_INTRINSICS_IMM_ONLY 1
    #endif
#endif

#if !defined(MPS_X86_INSTR_SET) && defined(__AVX2__)
    #define MPS_X86_INSTR_SET MPS_X86_AVX2_VERSION
#endif

#if !defined(MPS_X86_INSTR_SET) && defined(__FMA__)
    #define MPS_X86_INSTR_SET MPS_X86_FMA3_VERSION
#endif

#if !defined(MPS_X86_INSTR_SET) && defined(__AVX__)
    #define MPS_X86_INSTR_SET MPS_X86_AVX_VERSION
#endif

#if !defined(MPS_X86_INSTR_SET) && defined(__SSE4_2__)
    #define MPS_X86_INSTR_SET MPS_X86_SSE4_2_VERSION
#endif

#if !defined(MPS_X86_INSTR_SET) && defined(__SSE4_1__)
    #define MPS_X86_INSTR_SET MPS_X86_SSE4_1_VERSION
#endif

#if !defined(MPS_X86_INSTR_SET) && defined(__SSSE3__)
    #define MPS_X86_INSTR_SET MPS_X86_SSSE3_VERSION
#endif

#if !defined(MPS_X86_INSTR_SET) && defined(__SSE3__)
    #define MPS_X86_INSTR_SET MPS_X86_SSE3_VERSION
#endif

#if !defined(MPS_X86_INSTR_SET) && (defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 2))
    #define MPS_X86_INSTR_SET MPS_X86_SSE2_VERSION
#endif

#if !defined(MPS_X86_INSTR_SET) && (defined(__SSE__) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 1))
    #define MPS_X86_INSTR_SET MPS_X86_SSE_VERSION
#endif

#if !(defined MPS_X86_INSTR_SET)
    #define MPS_X86_INSTR_SET MPS_VERSION_NUMBER_NOT_AVAILABLE
#else
    #define MPS_X86_INSTR_SET_AVAILABLE MPS_VERSION_NUMBER_AVAILABLE
#endif

/******************************************************************************
 * X86_AMD INSTRUCTION SET                                                    *
 ******************************************************************************/

#define MPS_X86_AMD_SSE4A_VERSION MPS_VERSION_NUMBER(4, 0, 0)
#define MPS_X86_AMD_FMA4_VERSION  MPS_VERSION_NUMBER(5, 1, 0)
#define MPS_X86_AMD_XOP_VERSION   MPS_VERSION_NUMBER(5, 1, 1)

#if !defined(MPS_X86_AMD_INSTR_SET) && defined(__XOP__)
    #define MPS_X86_AMD_INSTR_SET MPS_X86_AMD_XOP_VERSION
#endif

#if !defined(MPS_X86_AMD_INSTR_SET) && defined(__FMA4__)
    #define MPS_X86_AMD_INSTR_SET MPS_X86_AMD_FMA4_VERSION
#endif

#if !defined(MPS_X86_AMD_INSTR_SET) && defined(__SSE4A__)
    #define MPS_X86_AMD_INSTR_SET MPS_X86_AMD_SSE4A_VERSION
#endif

#if !defined(MPS_X86_AMD_INSTR_SET)
    #define MPS_X86_AMD_INSTR_SET MPS_VERSION_NUMBER_NOT_AVAILABLE
#else
    // X86_AMD implies X86
    #if MPS_X86_INSTR_SET > MPS_X86_AMD_INSTR_SET
        #undef MPS_X86_AMD_INSTR_SET
        #define MPS_X86_AMD_INSTR_SET MPS_X86_INSTR_SET
    #endif
    #define MPS_X86_AMD_INSTR_SET_AVAILABLE MPS_VERSION_NUMBER_AVAILABLE
#endif

/******************************************************************************
 * ARM INSTRUCTION SET                                                        *
 ******************************************************************************/

#define MPS_ARM7_NEON_VERSION    MPS_VERSION_NUMBER(7, 0, 0)
#define MPS_ARM8_32_NEON_VERSION MPS_VERSION_NUMBER(8, 0, 0)
#define MPS_ARM8_64_NEON_VERSION MPS_VERSION_NUMBER(8, 1, 0)

// TODO __ARM_FEATURE_FMA
#if !defined(MPS_ARM_INSTR_SET) && (defined(__ARM_NEON))
    #if __ARM_ARCH >= 8
        #if defined(__aarch64__)
            #define MPS_ARM_INSTR_SET MPS_ARM8_64_NEON_VERSION
        #else
            #define MPS_ARM_INSTR_SET MPS_ARM8_32_NEON_VERSION
        #endif
    #elif __ARM_ARCH >= 7
        #define MPS_ARM_INSTR_SET MPS_ARM7_NEON_VERSION
    #elif defined(MPS_ENABLE_FALLBACK)
        #warning "NEON instruction set not supported, using fallback mode."
    #else
        static_assert(false, "NEON instruction set not supported.");
    #endif
#endif

#if !defined(MPS_ARM_INSTR_SET)
    #define MPS_ARM_INSTR_SET MPS_VERSION_NUMBER_NOT_AVAILABLE
#else
    #define MPS_ARM_INSTR_SET_AVAILABLE MPS_VERSION_NUMBER_AVAILABLE
#endif

/******************************************************************************
 * GENERIC INSTRUCTION SET                                                    *
 ******************************************************************************/

#undef MPS_INSTR_SET
#undef MPS_INSTR_SET_AVAILABLE

#if defined(MPS_X86_AMD_AVAILABLE)
    #if MPS_X86_INSTR_SET > MPS_X86_AMD_INSTR_SET
        #define MPS_INSTR_SET MPS_X86_INSTR_SET
    #else
        #define MPS_INSTR_SET MPS_X86_AMD_INSTR_SET
    #endif
#endif

#if !defined(MPS_INSTR_SET) && defined(MPS_X86_INSTR_SET_AVAILABLE)
    #define MPS_INSTR_SET MPS_X86_INSTR_SET
#endif

#if !defined(MPS_INSTR_SET) && defined(MPS_PPC_INSTR_SET_AVAILABLE)
    #define MPS_INSTR_SET MPS_PPC_INSTR_SET
#endif

#if !defined(MPS_INSTR_SET) && defined(MPS_ARM_INSTR_SET_AVAILABLE)
    #define MPS_INSTR_SET MPS_ARM_INSTR_SET
#endif

#if !defined(MPS_INSTR_SET)
    #define MPS_INSTR_SET MPS_VERSION_NUMBER_NOT_AVAILABLE
#elif MPS_INSTR_SET != MPS_VERSION_NUMBER_NOT_AVAILABLE
    #define MPS_INSTR_SET_AVAILABLE MPS_VERSION_NUMBER_AVAILABLE
#endif

#endif

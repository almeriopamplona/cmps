/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                ARRAYS.H                                    *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 29.01.2021                                              *
 * Modification date: 07.01.2021                                              *
 ******************************************************************************
 * Copyright (c) Almério José Venâncio Pains Soares Pamplona                  *
 *                                                                            *
 * Distributed under the terms of the Apache 2 License.                       *
 *                                                                            *
 * The full license is in the file LICENSE, distributed with this software.   *
 ******************************************************************************
 * Description:                                                               *
 *                                                                            *
 * In the present script, array objects are created.Furthermore, functions    *
 * for creation, destruction, operations and manipulation are defined.        *
 *                                                                            *
 ******************************************************************************/

#ifndef __ARRAYS_H__
#define __ARRAYS_H__

/* Defining macro constants: */

#define MEM_SIZE        128

/* Defining data-types:      */

typedef double         real;      /* variables that are in the Real     field */
typedef unsigned long  integer;   /* variables that are in the Integer  field */ 
typedef unsigned int   integer32; /* variables that are in the 32 Bytes field */

/* Defining array objects: */

typedef struct intArray 
{
    integer size;
    integer *arr;

} intArray;

typedef struct int32Array 
{
    integer   size;
    integer32 *arr;

} int32Array;

typedef struct realArray
{
    integer size;
    real    *arr;

} realArray;

/******************************************************************************
 * CONSTRUCTORS AND DISTRUCTORS                                               *
 ******************************************************************************/

/******************************************************************************
 * Function:    makeIntXXArray                                                *
 * -------------------------------------------------------------------------- *
 * description: creates an array with integer elements and allocates it in a  *
 *              memory space.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  intXXArray *a    // pointer to some integerXX array a              *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: intXXArray                                                         *
 ******************************************************************************/
intArray*   makeIntArray(const integer size); 
int32Array* makeInt32Array(const integer size);
realArray*  makeRealArray(const integer size);

/******************************************************************************
 * Function:    freeIntArray                                                  *
 * -------------------------------------------------------------------------- *
 * description: deallocates an array with integer elements from the memory.   *                                                 *
 * -------------------------------------------------------------------------- *
 * input:  intArray *a      // pointer to some integer array a                *
 * -------------------------------------------------------------------------- *
 * output: a                // deallocated integer array                      *
 ******************************************************************************/
void freeIntArray(intArray *self);
void freeInt32Array(int32Array *self);
void freeRealArray(realArray *self);

/******************************************************************************
 * Function:    zeroIntArray                                                  *
 * -------------------------------------------------------------------------- *
 * description: set n elements with zero value into an integer array.         *                                                 *
 * -------------------------------------------------------------------------- *
 * input:  intArray *a      // pointer to some integer array a                *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: a                // integer array whose elements have zero value   *
 ******************************************************************************/
void zeroIntArray(intArray *a, const integer size);
void zeroIn32tArray(int32Array *a, const integer size);
void zeroRealArray(realArray *a, const integer size);

/******************************************************************************
 * Function:    linspace                                                      *
 * -------------------------------------------------------------------------- *
 * description: creates a sequence of real elements, with predefined start    *
 *              and points, and also a specific size.                         *
 * -------------------------------------------------------------------------- *
 * input:  real    *a     // pointer to some real array a                     *
 *         real    start  // first element of the sequence                    *
 *         real    stop   // last  element of the sequence                    *
 *         integer size   // total number of elements                         *
 * -------------------------------------------------------------------------- *
 * output: a              // an array of a sequence of real elements          *
 ******************************************************************************/
void linspace (realArray *a, real start, real stop, const integer size); 

/******************************************************************************
 * Function:    linspace2                                                      *
 * -------------------------------------------------------------------------- *
 * description: creates a sequence of real elements, with predefined start    *
 *              and points, and also a specific size.                         *
 * -------------------------------------------------------------------------- *
 * input:  real *a     // pointer to some real array a                        *
 *         real start  // first element of the sequence                       *
 *         real stop   // last  element of the sequence                       *
 *         real dx     // increment step                                      *
 * -------------------------------------------------------------------------- *
 * output: a           // an array of a sequence of real elements             *
 ******************************************************************************/
void linspace2 (realArray *a, real start, real stop, real dx);

#endif

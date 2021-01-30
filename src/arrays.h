/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                ARRAYS.H                                    *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 29.01.2021                                              *
 * Modification date: 29.01.2021                                              *
 ******************************************************************************
 * Description:                                                               *
 *                                                                            *
 * In the present script, array objects are created.Furthermore, functions    *
 * for creation, destruction, operations and manipulation are defined.        *
 *                                                                            *
 ******************************************************************************/

#ifdef  __ARRAYS_H__
#define __ARRAYS_H__

// Defining macro constants:

#define MEM_SIZE        128

// Defining data-types:

typedef double         real;        // variables that are in the Real     field 
typedef unsigned long  integer;     // variables that are in the Integer  field  
typedef unsigned int   integer32;   // variables that are in the 32 Bytes field

// Defining array objects:

struct intArray 
{
    integer size;
    integer sizeMax;
    integer *v;

}__attribute__((packed));

struct int32Array 
{
    integer32  size;
    integer32 *v;

}__attribute__((packed));

/******************************************************************************
 * ARRAYS CREATION                                                            *
 ******************************************************************************/

/* Integer ------------------------------------------------------------------ */

void makeIntArray(intArray *a, const integer size);

void freeIntArray(intArray *a);

void zeroIntArray(intArray *a, const integer size);

/* Integer32 ---------------------------------------------------------------- */

void makeInt32Array(int32Array *a, const integer size);

void freeInt32Array(int32Array *a);

void zeroIn32tArray(int32Array *a, const integer size);

/* Real --------------------------------------------------------------------- */

void linspace (real *a, real start, real stop, const integer size); 

void linspace2 (real *a, real start, real stop, real dx);

#endif

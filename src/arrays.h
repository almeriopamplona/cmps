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

/******************************************************************************
 * Function:    makeIntArray                                                  *
 * -------------------------------------------------------------------------- *
 * description: creates an array with integer elements and allocates it in a  *
 *              memory space.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  intArray *a      // pointer to some integer array a                *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: a                // allocated integer array                        *
 ******************************************************************************/
void makeIntArray(intArray *a, const integer size);

/******************************************************************************
 * Function:    freeIntArray                                                  *
 * -------------------------------------------------------------------------- *
 * description: deallocates an array with integer elements from the memory.   *                                                 *
 * -------------------------------------------------------------------------- *
 * input:  intArray *a      // pointer to some integer array a                *
 * -------------------------------------------------------------------------- *
 * output: a                // deallocated integer array                      *
 ******************************************************************************/
void freeIntArray(intArray *a);

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

/* Integer32 ---------------------------------------------------------------- */

/******************************************************************************
 * Function:    makeInt32Array                                                *
 * -------------------------------------------------------------------------- *
 * description: creates an array with integer32 elements and allocates it in  *
 *              s memory space.                                               *
 * -------------------------------------------------------------------------- *
 * input:  intArray *a      // pointer to some integer32 array a              *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: a                // allocated integer32 array                      *
 ******************************************************************************/
void makeInt32Array(int32Array *a, const integer size);

/******************************************************************************
 * Function:    freeInt32Array                                                *
 * -------------------------------------------------------------------------- *
 * description: deallocates an array with integer32 elements from the memory. *                                                 *
 * -------------------------------------------------------------------------- *
 * input:  intArray *a      // pointer to some integer32 array a              *
 * -------------------------------------------------------------------------- *
 * output: a                // deallocated integer32 array                    *
 ******************************************************************************/
void freeInt32Array(int32Array *a);

/******************************************************************************
 * Function:    zeroIntArray                                                  *
 * -------------------------------------------------------------------------- *
 * description: set n elements with zero value into an integer32 array.       *                                                 *
 * -------------------------------------------------------------------------- *
 * input:  intArray *a      // pointer to some integer32 array a              *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: a                // integer32 array whose elements have zero value *
 ******************************************************************************/
void zeroIn32tArray(int32Array *a, const integer size);

/* Real --------------------------------------------------------------------- */


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
void linspace (real *a, real start, real stop, const integer size); 

/******************************************************************************
 * Function:    linspace2                                                     *
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
void linspace2 (real *a, real start, real stop, real dx);

#endif

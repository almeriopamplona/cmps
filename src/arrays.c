/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                ARRAYS.H                                    *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 29.01.2021                                              *
 * Modification date: 29.01.2021                                              *
 ******************************************************************************/

#include <stdio.h>  /*input and output variable manipulation*/
#include <stdlib.h> /*address and memory manipulation*/
#include <math.h>   /*mathematical functions*/

#include "arrays.h"

/******************************************************************************
 * ARRAYS CREATION                                                            *
 ******************************************************************************/

/* Integer ------------------------------------------------------------------ */

void makeIntArray(intArray *a, const integer size)
{
    a -> size = size; 
    a -> v    = (integer *) malloc(size * sizeof(integer), MEM_SIZE);
}

void freeIntArray(intArray *a)
{
    free(a -> v);

    a -> size = 0;
}

void zeroIntArray(intArray *a, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        a -> v[i] = 0;
    }
}

/* Integer32 ---------------------------------------------------------------- */

void makeInt32Array(int32Array *a, const integer size)
{
    a -> size = size; 
    a -> v    = (integer32 *) malloc(size * sizeof(integer32), MEM_SIZE);
}

void freeInt32Array(int32Array *a)
{
    free(a -> v);

    a -> size = 0;
}

void zeroInt32Array(int32Array *a, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        a -> v[i] = 0;
    }
}

/* Real --------------------------------------------------------------------- */

void linspace (real *a, real start, real stop, const integer size) 
{    
    if (size > 1) 
    {
        real da = (stop - start) / (size - 1); /*sequence increment step*/ 

        for (register unsigned int i = 0; i < size; i++) 
        {
            a[i] = start + i * da; 
        }
    }
    else 
    {
        *a = 0.5 * (stop + start)
    }
}

void linspace2 (real *a, real start, real stop, real dx) 
{
    register integer size; /*total number of elements*/
    scalar_t da2;          /*sequence increment      */
     
    size = floor((stop - start) / da); 
    da2  = (stop - start) / size;     

    for (register unsigned int i = 0; i < size; i++) 
    {
        a[i] = start + i * da2;
    }
}

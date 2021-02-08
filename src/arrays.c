/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                ARRAYS.C                                    *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 07.02.2021                                              *
 * Modification date: 07.02.2021                                              *
 ******************************************************************************
 * Copyright (c) Almério José Venâncio Pains Soares Pamplona                  *
 *                                                                            *
 * Distributed under the terms of the Apache 2 License.                       *
 *                                                                            *
 * The full license is in the file LICENSE, distributed with this software.   *
 ******************************************************************************

#include "arrays.h" 

#include <stdio.h>  /*input and output variable manipulation*/
#include <stdlib.h> /*address and memory manipulation*/
#include <string.h> /*string manipulation*/
#include <math.h>   /*mathematical functions*/

/******************************************************************************
 * CONSTRUCTORS AND DISTRUCTORS                                               *
 ******************************************************************************/

/* Integer ------------------------------------------------------------------ */

intArray* makeIntArray(const integer size)
{ 
    intArray *self = (intArray *) malloc(sizeof(intArray));

    self->size = size;
    self->arr  = (integer *) malloc(size * sizeof(integer));

    if (self == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate the object\n");
        exit (EXIT_FAILURE);
    }

    return self;
}

int32Array* makeInt32Array(const integer size)
{
    int32Array *self = (int32Array *) malloc(sizeof(int32Array));

    self->size = size;
    self->arr  = (integer32 *) malloc(size * sizeof(integer32));

    if (self == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate the object\n");
        exit (EXIT_FAILURE);
    }

    return self;
}

realArray* makeRealArray(const integer size)
{
    realArray *self = (realArray *) malloc(sizeof(realArray));

    self->size = size;
    self->arr  = (real *) malloc(size * sizeof(real));

    if (self == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate the object\n");
        exit (EXIT_FAILURE);
    }

    return self;
}

void freeIntArray(intArray *self)
{
    free(self->arr);
    free(self);
}

void freeInt32Array(int32Array *self)
{
    free(self->arr);
    free(self);
}

void freeRealArray(realArray *self)
{
    free(self->arr);
    free(self);
}

void zeroIntArray(intArray *a, const integer size)
{
    register integer i;

    for (i = 0; i < size; i++)
    {
        a->arr[i] = 0;
    }
}

void zeroInt32Array(int32Array *a, const integer size)
{
    register integer32 i;
    for (i = 0; i < size; i++)
    {
        a->arr[i] = 0;
    }
}

void zeroRealArray(realArray *a, const integer size)
{
    register integer i;
    for (i = 0; i < size; i++)
    {
        a->arr[i] = 0.0;
    }
}

void linspace (realArray *a, real start, real stop, const integer size) 
{    
    if (size > 1) 
    {
        real da = (stop - start) / (size - 1); /*sequence increment step*/ 

        register integer i;

        for (i = 0; i < size; i++) 
        {
            a->arr[i] = start + i * da; 
        }
    }
    else 
    {
        *(a->arr) = 0.5 * (stop + start);
    }
}

void linspace2 (realArray *a, real start, real stop, real dx) 
{
    register integer size; /*total number of elements*/
    real da2;              /*sequence increment      */
     
    size = floor((stop - start) / dx); 
    da2  = (stop - start) / size;     

    register integer i;
    
    for ( i = 0; i < size; i++) 
    {
        a->arr[i] = start + i * da2;
    }
}

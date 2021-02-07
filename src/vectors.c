/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                VECTORS.C                                   *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Copyright (c) Almério José Venâncio Pains Soares Pamplona                  *
 *                                                                            *
 * Distributed under the terms of the Apache 2 License.                       *
 *                                                                            *
 * The full license is in the file LICENSE, distributed with this software.   *
 ******************************************************************************
 * Creation date    : 28.01.2021                                              *
 * Modification date: 07.02.2021                                              *
 ******************************************************************************
 * LIBRARIES:                                                                 *
 ******************************************************************************/

#include "vectors.h"

#include <stdio.h>  /*input and output variable manipulation*/
#include <stdlib.h> /*address and memory manipulation*/
#include <string.h>
#include <math.h>   /*mathematical functions*/

/******************************************************************************
 * CONSTRUCTORS AND DISTRUCTORS                                               *
 ******************************************************************************/

vector1D* makeVector1D(const integer size)
{
    /*initialize object's memory block*/
    vector1D *self = (vector1D *) malloc(sizeof(vector1D));
    /*vector's size*/
    self->size = size;
    /*vector initialization in the object's memory block*/
    self->x    = (real *)malloc(size * sizeof(real));

    if (self == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate x\n");
        exit (EXIT_FAILURE);
    }

    return self;
}

void freeVector1D(vector1D *self)
{
    free(self->x);
    free(self);
}

vector2D* makeVector2D(const integer size)
{
    /*initialize object's memory block*/
    vector2D *self = (vector2D *)malloc(sizeof(vector2D));
    /*vector's size*/
    self->size = size;
    /*vector initialization in the object's memory block*/
    self->x    = (real *)malloc(size * sizeof(real));
    self->y    = (real *)malloc(size * sizeof(real));

    if (self == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate x or y\n");
        exit (EXIT_FAILURE);
    }
}

void freeVector2D(vector2D *self)
{
    free(self->x);
    free(self->y);
    free(self);
}

vector3D* makeVector3D(const integer size)
{
    /*initialize object's memory block*/
    vector3D *self = (vector3D *)malloc(sizeof(vector3D));
    /*vector's size*/
    self->size = size;
    /*vector initialization in the object's memory block*/
    self->x    = (real *)malloc(size * sizeof(real));
    self->y    = (real *)malloc(size * sizeof(real));
    self->z    = (real *)malloc(size * sizeof(real));

    if (self == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate x or y\n");
        exit (EXIT_FAILURE);
    }
}

void freeVector3D(vector3D *self)
{
    free(self->x);
    free(self->y);
    free(self->z);
    free(self);
}

/******************************************************************************
 * GENERAL PURPOSE METHODS                                                    *
 ******************************************************************************/

void copyVector1D(vector1D* __restrict src, vector1D* __restrict dst)
{ 
   memcpy(dst->x, src->x, src->size * sizeof(real));
}

void copyVector2D(vector2D* __restrict src, vector2D* __restrict dst)
{
    memcpy(dst->x, src->x, src->size * sizeof(real));
    memcpy(dst->y, src->y, src->size * sizeof(real));    
}

void copyVector3D(vector3D* __restrict src, vector3D* __restrict dst)
{
    memcpy(dst->x, src->x, src->size * sizeof(real));
    memcpy(dst->y, src->y, src->size * sizeof(real));
    memcpy(dst->z, src->z, src->size * sizeof(real));   
}

void transverseVector1D(vector1D *self)
{
    register integer i;
    printf("vector1D::x = {%g,", self->x[0]);
    for(i = 1; i < self->size-1; i++)
    {
        printf(" %g,", self->x[i]);
    }
    printf(" %g}\n", self->x[self->size-1]);
}

void transverseVector2D(vector2D *self, const unsigned int components)
{
    register integer i; /*initiate the loop counter*/

    if (components == 0)     /*print the component x of the vector*/
    {
        printf("vector2D::x = {%g,", self->x[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->x[i]);
        }
        printf(" %g}\n", self->x[self->size-1]);
        
    }
    else if (components == 1) /*print the component y of the vector*/
    {
        printf("vector2D::y = {%g,", self->y[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->y[i]);
        }
        printf(" %g}\n", self->y[self->size-1]);
    }
    else if (components == 2) /*print the both components x and y */
    {    
        printf("vector2D::x = {%g,", self->x[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->x[i]);
        }
        printf(" %g}\n", self->x[self->size-1]);
        
        printf("vector2D::y = {%g,", self->y[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->y[i]);
        }
        printf(" %g}\n", self->y[self->size-1]);
    }    
}

void transverseVector3D(vector3D *self, const unsigned int components)
{
   register integer i; /*initiate loop counter*/

    if (components == 0)     /*print the component x of the vector*/
    {
        printf("vector3D::x = {%g,", self->x[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->x[i]);
        }
        printf(" %g}\n", self->x[self->size-1]);
        
    }
    else if (components == 1) /*print the component y of the vector*/
    {
        printf("vector3D::y = {%g,", self->y[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->y[i]);
        }
        printf(" %g}\n", self->y[self->size-1]);
    }
    else if (components == 2) /*print the component z of the vector*/
    {
        printf("vector3D::z = {%g,", self->z[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->z[i]);
        }
        printf(" %g}\n", self->z[self->size-1]);
    }
    else if (components == 3) /*print the every component of the vector*/
    {    
        printf("vector3D::x = {%g,", self->x[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->x[i]);
        }
        printf(" %g}\n", self->x[self->size-1]);
        
        printf("vector3D::y = {%g,", self->y[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->y[i]);
        }
        printf(" %g}\n", self->y[self->size-1]);

        printf("vector3D::z = {%g,", self->z[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->z[i]);
        }
        printf(" %g}\n", self->z[self->size-1]);
    }
    else if (components == 12) /*print the every component of the vector*/
    {    
        printf("vector3D::x = {%g,", self->x[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->x[i]);
        }
        printf(" %g}\n", self->x[self->size-1]);
        
        printf("vector3D::y = {%g,", self->y[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->y[i]);
        }
        printf(" %g}\n", self->y[self->size-1]);
    }
    else if (components == 13) /*print the every component of the vector*/
    {    
        printf("vector3D::x = {%g,", self->x[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->x[i]);
        }
        printf(" %g}\n", self->x[self->size-1]);
        
        printf("vector3D::z = {%g,", self->z[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->z[i]);
        }
        printf(" %g}\n", self->z[self->size-1]); 
    }  
    else if (components == 23) /*print the every component of the vector*/
    {    
        printf("vector3D::y = {%g,", self->y[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->y[i]);
        }
        printf(" %g}\n", self->y[self->size-1]);
        
        printf("vector3D::z = {%g,", self->z[0]);
        for(i = 1; i < self->size-1; i++)
        {
            printf(" %g,", self->z[i]);
        }
        printf(" %g}\n", self->z[self->size-1]); 
    }
}

/******************************************************************************
 * HANDFUL VECTORS                                                            *
 ******************************************************************************/

void zeroVector1D(vector1D *self)
{
    register integer i;

    for(i = 0; i < self->size; i++)
    {
        self->x[i] = 0;
    }
}

void zeroVector2D(vector2D *self)
{
    register integer i;

    for(i = 0; i < self->size; i++)
    {
        self->x[i] = 0;
        self->y[i] = 0;
    }
}

void zeroVector3D(vector3D *self)
{
    register integer i;

    for(i = 0; i < self->size; i++)
    {
        self->x[i] = 0;
        self->y[i] = 0;
        self->z[i] = 0;
    }
}
/******************************************************************************
 * ARITMETHIC                                                                 *
 ******************************************************************************/

void addVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size)
{
    register integer i;

    for (i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] + w -> x[i];
    }
}

void addVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] + w -> x[i];
        s -> y[i] = v -> y[i] + w -> y[i];
    }
}

void addVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] + w -> x[i];
        s -> y[i] = v -> y[i] + w -> y[i];
        s -> z[i] = v -> z[i] + w -> z[i];
    }
}

void subVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] - w -> x[i];
    }
}

void subVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] - w -> x[i];
        s -> y[i] = v -> y[i] - w -> y[i];
    }
}

void subVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] - w -> x[i];
        s -> y[i] = v -> y[i] - w -> y[i];
        s -> z[i] = v -> z[i] - w -> z[i];
    }
}

void mulVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] * w -> x[i];
    }
}


void mulVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] * w -> x[i];
        s -> y[i] = v -> y[i] * w -> y[i];
    }
}

void mulVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] * w -> x[i];
        s -> y[i] = v -> y[i] * w -> y[i];
        s -> z[i] = v -> z[i] * w -> z[i];
    }
}

void divVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] / w -> x[i];
    }
}

void divVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size)
{
    register integer i;

    for (i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] / w -> x[i];
        s -> y[i] = v -> y[i] / w -> y[i];
    }
}

void divVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size)
{
    register integer i;

    for(i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] / w -> x[i];
        s -> y[i] = v -> y[i] / w -> y[i];
        s -> z[i] = v -> z[i] / w -> z[i];
    }
}

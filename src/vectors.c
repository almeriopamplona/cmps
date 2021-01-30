/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                VECTORS.C                                   *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 28.01.2021                                              *
 * Modification date: 29.01.2021                                              *
 ******************************************************************************/

#include <stdio.h>  /*input and output variable manipulation*/
#include <stdlib.h> /*address and memory manipulation*/
#include <math.h>   /*mathematical functions*/

#include "vectors.h"

/******************************************************************************
 * VECTORS CREATION                                                           *
 ******************************************************************************/

/*1D ALGEBRA ---------------------------------------------------------------- */

void zeroVector1D(vector1D *v, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        v -> x[i] = 0;
    }
}

void makeVector1D(vector1D *v, const integer size)
{
    v -> size = size;
    v -> x    = (real *) malloc(v -> size * sizeof(real), MEM_SIZE);

    if (v -> x == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate x\n");
        exit (EXIT_FAILURE);
    }

    zeroVector(v, size);
}

void freeVector1D(vector1D *v)
{
    free(v -> x);

    v -> size = 0;
}

void copyVector1D(vector1D *v, vector1D *w, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        w -> x[i] = v -> x[i];
    }
}

/*2D ALGEBRA ---------------------------------------------------------------- */

void zeroVector2D(vector2D *v, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        v -> x[i] = 0;
        v -> y[i] = 0;
    }
}

void makeVector2D(vector2D *v, const integer size)
{
    v -> size = size;
    v -> x    = (real *) malloc(v -> size * sizeof(real), MEM_SIZE);
    v -> y    = (real *) malloc(v -> size * sizeof(real), MEM_SIZE);

    if (v -> x == NULL) || (v -> y == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate x or y\n");
        exit (EXIT_FAILURE);
    }

    zeroVector(v, size);
}

void freeVector2D(vector2D *v)
{
    free(v -> x);
    free(v -> y);

    v -> size = 0;
}

void copyVector2D(vector2D *v, vector2D *w, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        w -> x[i] = v -> x[i];
        w -> y[i] = v -> y[i];
    }
}

/*3D ALGEBRA ---------------------------------------------------------------- */

void zeroVector3D(vector3D *v, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        v -> x[i] = 0;
        v -> y[i] = 0;
        v -> z[i] = 0;
    }
}

void makeVector3D(vector3D *v, const integer size)
{
    v -> size = size;
    v -> x    = (real *) malloc(v -> size * sizeof(real), MEM_SIZE);
    v -> y    = (real *) malloc(v -> size * sizeof(real), MEM_SIZE);
    v -> z    = (real *) malloc(v -> size * sizeof(real), MEM_SIZE);

    if (v -> x == NULL) || (v -> y == NULL) || (v -> z == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate x or y or z\n");
        exit (EXIT_FAILURE);
    }

    zeroVector(v, size);
}

void freeVector3D(vector3D *v)
{
    free(v -> x);
    free(v -> y);
    free(v -> z);

    v -> size = 0;
}

void copyVector3D(vector3D *v, vector3D *w, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        w -> x[i] = v -> x[i];
        w -> y[i] = v -> y[i];
        w -> z[i] = v -> z[i];
    }
}

/******************************************************************************
 * VECTORS OPERATION                                                          *
 ******************************************************************************/

/*1D ALGEBRA ---------------------------------------------------------------- */

void addVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] + w -> x[i];
    }
}

void subVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] - w -> x[i];
    }
}

void mulVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] * w -> x[i];
    }
}

void divVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] / w -> x[i];
    }
}

/*2D ALGEBRA ---------------------------------------------------------------- */

void addVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] + w -> x[i];
        s -> y[i] = v -> y[i] + w -> y[i];
    }
}

void subVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] - w -> x[i];
        s -> y[i] = v -> y[i] - w -> y[i];
    }
}

void mulVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] * w -> x[i];
        s -> y[i] = v -> y[i] * w -> y[i];
    }
}

void divVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] / w -> x[i];
        s -> y[i] = v -> y[i] / w -> y[i];
    }
}

/*3D ALGEBRA ---------------------------------------------------------------- */

void addVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] + w -> x[i];
        s -> y[i] = v -> y[i] + w -> y[i];
        s -> z[i] = v -> z[i] + w -> z[i];
    }
}

void subVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] - w -> x[i];
        s -> y[i] = v -> y[i] - w -> y[i];
        s -> z[i] = v -> z[i] - w -> z[i];
    }
}

void mulVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] * w -> x[i];
        s -> y[i] = v -> y[i] * w -> y[i];
        s -> z[i] = v -> z[i] * w -> z[i];
    }
}

void divVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size)
{
    for (register unsigned int i = 0; i < size; i++)
    {
        s -> x[i] = v -> x[i] / w -> x[i];
        s -> y[i] = v -> y[i] / w -> y[i];
        s -> z[i] = v -> z[i] / w -> z[i];
    }
}

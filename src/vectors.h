/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                VECTORS.H                                   *
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
 * Description:                                                               *
 *                                                                            *
 * In the present script, vector objects are created as vector1D, vector2D,   *
 * and vector3D.Furthermore, functions for creation, destruction, operations  *
 * and manipulation are defined.                                              *
 *                                                                            *
 ******************************************************************************/

#ifndef  __VECTORS_H__
#define  __VECTORS_H__

/******************************************************************************
 * TYPE DEFINITIONS                                                           *
 ******************************************************************************/

/* Defining macro constants:*/

#define MEM_SIZE        128

/* Defining data-type:      */

typedef double          real;     /* variables that are in the Real    field */  
typedef unsigned long   integer;  /* variables that are in the Integer field */

/* Defining vector objects: */

typedef struct vector1D 
{
	integer  size;
	real    *x;

} vector1D;

typedef struct  vector2D
{
    integer  size;
    real    *x, *y;

} vector2D;

typedef struct  vector3D
{
    integer  size;
    real    *x, *y, *z;

} vector3D;

/******************************************************************************
 *CONSTRUCTORS AND DISTRUCTORS                                                *
 ******************************************************************************/

/******************************************************************************
 * Function:    makeVectorXD                                                  *
 * -------------------------------------------------------------------------- *
 * description: creates a vector v, attributes the total number of elements,  *
 *              dynamically allocates memory for each of the vector's         * 
 *              components.                                                   *
 * -------------------------------------------------------------------------- *
 * input:  const unsigned long size   // total number of elements             *
 * -------------------------------------------------------------------------- *
 * output: vectorXD *v                // vector v                             *
 ******************************************************************************/
vector1D* makeVector1D(const integer size);
vector2D* makeVector2D(const integer size);
vector3D* makeVector3D(const integer size);

/******************************************************************************
 * Function:    freeVectorXD                                                  *
 * -------------------------------------------------------------------------- *
 * description: free the memory dynamically allocated of each component of    *
 *              the vector v and set the total elements as zero.              *
 * -------------------------------------------------------------------------- *
 * input:  vectorXD *v      // pointer to some vector v                       *
 * -------------------------------------------------------------------------- *
 * output: vector v with empty v->x                                           *
 ******************************************************************************/
void freeVector1D(vector1D *self);
void freeVector2D(vector2D *self);
void freeVector3D(vector3D *self);

/******************************************************************************
 * GENERAL PURPOSE METHODS                                                    *
 ******************************************************************************/

/******************************************************************************
 * Function:    copyVectorXD                                                  *
 * -------------------------------------------------------------------------- *
 * description: uses memcpy to copy the elements of vector's components into  *
 *              another vector's components.                                  *
 * -------------------------------------------------------------------------- *
 * input:  vectorXD *src   // pointer to the source  vector                   *
 *         vectorXD *dst   // pointer to the destine vector                   *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void copyVector1D(vector1D* __restrict src, vector1D* __restrict dst);
void copyVector2D(vector2D* __restrict src, vector2D* __restrict dst);
void copyVector3D(vector3D* __restrict src, vector3D* __restrict dst);

/******************************************************************************
 * Function:    transverseVectorXD                                            *
 * -------------------------------------------------------------------------- *
 * description: prints every element of the vector's components. For 2D and   *
 *              3D vectors, there is the option to choose which component one *
 *              wants to print:                                               *
 *                  - 2D:  0 -> x;    1 -> y;    2 -> x,y                     *
 *                  - 3D:  0 -> x;    1 -> y;    2 -> z;  3 -> x,y,z;         *
 *                        12 -> x,y; 13 -> x,z; 23 -> y,z                     *
 * -------------------------------------------------------------------------- *
 * input:  vectorXD *self                  // pointer to the source  vector   *
 *         const unsigned int components   // print options for 2D and 3D     *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void transverseVector1D(vector1D *self);
void transverseVector2D(vector2D *self, const unsigned int components);
void transverseVector3D(vector3D *self, const unsigned int components);

/******************************************************************************
 * HANDFUL VECTORS                                                            *
 ******************************************************************************/

/******************************************************************************
 * Function:    zeroVectorXD                                                  *
 * -------------------------------------------------------------------------- *
 * description: create a vector, every element of each component is zero.     *
 * -------------------------------------------------------------------------- *
 * input:  vectorXD *self      // pointer to some vector                      *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void zeroVector1D(vector1D *self);
void zeroVector2D(vector2D *self);
void zeroVector3D(vector3D *self);

/******************************************************************************
 * ELEMENTWISE OPERATIONS                                                     *
 ******************************************************************************/

/******************************************************************************
 * Function:    addVectorXD                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to add two vectors, v and w, into one     *
 *              vector s.                                                     *
 * -------------------------------------------------------------------------- *
 * input:  vectorXD *v      // second vector v                                *
 *         vectorXD *w      // first  vector w                                *
 *         vectorXD *s      // addition result s                              *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void addVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size);
void addVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size);
void addVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size);

/******************************************************************************
 * Function:    subVectorXD                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to subtract vectors w from vector v into  *
 *              one vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vectorXD *v      // second vector v                                *
 *         vectorXD *w      // first  vector w                                *
 *         vectorXD *s      // subtraction result s                           *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void subVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size);
void subVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size);
void subVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size);

/******************************************************************************
 * Function:    mulVectorXD                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to multiply vectors w and v into one      *
 *              vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vectorXD *v      // second vector v                                *
 *         vectorXD *w      // first  vector w                                *
 *         vectorXD *s      // multiplication result s                        *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void mulVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size);
void mulVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size);
void mulVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size);

/******************************************************************************
 * Function:    divVector1D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to divide vectors v by vector w into      *
 *              one vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vectorXD *v      // second vector v                                *
 *         vectorXD *w      // first  vector w                                *
 *         vectorXD *s      // division result s                              *
 *         integer   size   // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void divVector1D(vector1D *v, vector1D *w, vector1D *s, const integer size);
void divVector2D(vector2D *v, vector2D *w, vector2D *s, const integer size);
void divVector3D(vector3D *v, vector3D *w, vector3D *s, const integer size);

#endif

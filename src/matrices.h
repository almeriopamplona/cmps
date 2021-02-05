/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                MATRICES.H                                   *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 04.02.2021                                              *
 * Modification date: 05.02.2021                                              *
 ******************************************************************************
 * Description:                                                               *
 *                                                                            *
 * In the present script, vector objects are created as vector1D, vector2D,   *
 * and vector3D.Furthermore, functions for creation, destruction, operations  *
 * and manipulation are defined.                                              *
 *                                                                            *
 ******************************************************************************/

#ifndef __MATRICES_H__
#define __MATRICES_H__

/******************************************************************************
 * TYPE DEFINITIONS                                                           *
 ******************************************************************************/

/* Defining macro constants: */

/* Defining data-type:       */

typedef double          real;      /* variables that are in the Real    field */ 
typedef unsigned long   integer;   /* variables that are in the Integer field */

typedef struct
{
    integer row;
    integer column;
    real    *matrix;

} Matrix;

/******************************************************************************
 * Functions                                                                  *
 ******************************************************************************/

void zeroMatrix(Matrix *A);
void makeMatrix(Matrix *A, const unsigned int r, const unsigned int c);
void freeMatrix(Matrix *A);
void copyMatrix(Matrix *A, Matrix *B);
void identityMatrix(Matrix *A);
void transverseMatrix(Matrix *A);
void indexMatrix(Matrix *A,  Matrix *B, unsigned int xStart, unsigned int xEnd, 
    unsigned int yStart, unsigned int yEnd);

#endif

/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                MATRICES.H                                   *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 04.02.2021                                              *
 * Modification date: 07.02.2021                                              *
 ******************************************************************************
 * Copyright (c) Almério José Venâncio Pains Soares Pamplona                  *
 *                                                                            *
 * Distributed under the terms of the Apache 2 License.                       *
 *                                                                            *
 * The full license is in the file LICENSE, distributed with this software.   *
 ******************************************************************************
 * Description:                                                               *
 *                                                                            *
 * In the present script, matrices objects are created with some general      *
 * purpouse functions to manipulate them.                                     *
 *                                                                            *
 ******************************************************************************/

#ifndef __MATRICES_H__
#define __MATRICES_H__

#include "vectors.h"

/******************************************************************************
 * MEMORY ALIGN                                                               *
 ******************************************************************************/
#define ALIGN_BYTES             128

/******************************************************************************
 * TYPE DEFINITIONS                                                           *
 ******************************************************************************/

/* Defining macro constants: */

/* Defining data-type:       */

typedef double          real;      /* variables that are in the Real    field */ 
typedef unsigned long   integer;   /* variables that are in the Integer field */

typedef struct Matrix
{
    integer row;
    integer col;
    real    *matrix;

} Matrix;

/******************************************************************************
 * CONSTRUCTOR, DESTRUCTOR                                                    *
 ******************************************************************************/

/******************************************************************************
 * Function:    makeMatrix                                                    *
 * -------------------------------------------------------------------------- *
 * description: creates a struct Matrix object initializing it with malloc,   *
 *              as also the matrix element.                                   *
 * -------------------------------------------------------------------------- *
 * input:  const integer row   // total number of rows                        *
 *         const integer col   // total number of columns                     *
 * -------------------------------------------------------------------------- *
 * output: Matrix *self                                                       *
 ******************************************************************************/
Matrix *makeMatrix(const integer row, const integer col);

/******************************************************************************
 * Function:    freeMatrix                                                    *
 * -------------------------------------------------------------------------- *
 * description: deallocates memory from self->matrix and the object itself.   *
 * -------------------------------------------------------------------------- *
 * input:  Matrix *self   // struct Matrix object                             *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void freeMatrix(Matrix *self);

/******************************************************************************
 * GENERAL PURPOSE METHODS                                                    *
 ******************************************************************************/

/******************************************************************************
 * Function:    copyMatrix                                                    *
 * -------------------------------------------------------------------------- *
 * description: copies a source matrix into a destine matrix using memcpy.    *
 * -------------------------------------------------------------------------- *
 * input:  Matrix* __restrict src // source  matrix                           *
 *         Matrix* __restrict dst // destine matrix                           * 
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void copyMatrix(Matrix* __restrict src, Matrix* __restrict dst);

/******************************************************************************
 * Function:    getColumn                                                     *
 * -------------------------------------------------------------------------- *
 * description: copies a column from a source matrix into a vector.           *
 * -------------------------------------------------------------------------- *
 * input:  Matrix*   __restrict src // source  matrix                         *
 *         vector1D* __restrict dst // destine vector                         *
 *         const integer column     // desired column from the source matrix  *
 *         const integer nrows      // number of desired rows into the column *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void getColumn(Matrix* __restrict src, vector1D* __restrict dst, 
    const integer column, const integer nrows);

/******************************************************************************
 * Function:    getRow                                                        *
 * -------------------------------------------------------------------------- *
 * description: copies a row from a source matrix into a vector.              *
 * -------------------------------------------------------------------------- *
 * input:  Matrix*       src        // source  matrix                         *
 *         vector1D*     dst        // destine vector                         *
 *         const integer row        // desired row from the source matrix     *
 *         const integer ncols      // number of desired columns into the row *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void getRow(Matrix *src, vector1D *dst, const integer row, const integer ncols);

/******************************************************************************
 * Function:    getContSubmatrix                                              *
 * -------------------------------------------------------------------------- *
 * description: copies a sub-matrix from a source matrix into a destine       *
 *              matrix. This generated sub-matrix is a block of subsequent    *
 *              rows and columns.                                             *
 * -------------------------------------------------------------------------- *
 * input:  Matrix*       src        // source  matrix                         *
 *         Matrix*       dst        // destine sub-matrix                     *
 *         const integer startRow   // starting row     from the src matrix   *
 *         const integer startCol   // starting columns form the src matrix   *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void getConstSubmatrix(Matrix *src, Matrix *dst, const integer startRow, 
    const integer startCol);

/******************************************************************************
 * Function:    getGeneralSubmatrix                                           *
 * -------------------------------------------------------------------------- *
 * description: copies a sub-matrix from a source matrix into a destine       *
 *              matrix. This generated sub-matrix is a block of not necessary *
 *              subsequent rows and columns.                                  *
 * -------------------------------------------------------------------------- *
 * input:  Matrix        *src   // source  matrix                             *
 *         Matrix        *dst   // destine sub-matrix                         *
 *         const integer *row   // array with all the desired rows from src   *
 *         const integer *col   // array with all the desired cols form src   *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void getGeneralSubmatrix(Matrix *src, Matrix *dst, integer *row, integer *col);

/******************************************************************************
 * Function:    getGeneralSubmatrix                                           *
 * -------------------------------------------------------------------------- *
 * description: copies a sub-matrix from a source sub-matrix into a destine   *
 *              matrix.                                                       *
 * -------------------------------------------------------------------------- *
 * input:  Matrix        *dst   // source  sub-matrix                         *
 *         Matrix        *src   // destine matrix                             *
 *         const integer *row   // array with all the desired rows from dst   *
 *         const integer *col   // array with all the desired cols form dst   *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void setGeneralSubmatrix(Matrix *dst, Matrix *src, integer *row, integer *col);

/******************************************************************************
 * Function:    transverseMatrix                                              *
 * -------------------------------------------------------------------------- *
 * description: prints the desired matrix in a traditional mathematical       *
 *              representation.                                               *
 * -------------------------------------------------------------------------- *
 * input:  Matrix *src   // source  matrix                                    *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void transverseMatrix(Matrix *src);

/******************************************************************************
 * HANDFUL MATRICES TYPES                                                     *
 ******************************************************************************/

/******************************************************************************
 * Function:    zeroMatrix                                                    *
 * -------------------------------------------------------------------------- *
 * description: fills every element from a matrix with zeros.                 *
 * -------------------------------------------------------------------------- *
 * input:  Matrix *src   // source  matrix                                    *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void zeroMatrix(Matrix *src);

/******************************************************************************
 * Function:    identityoMatrix                                               *
 * -------------------------------------------------------------------------- *
 * description: fills a matrix as an identity matrix.                         *
 * -------------------------------------------------------------------------- *
 * input:  Matrix *src   // source  matrix                                    *
 * -------------------------------------------------------------------------- *
 * output: void                                                               *
 ******************************************************************************/
void identityMatrix(Matrix *src);

#endif

/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                MATRICES.C                                  *
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
 * Creation date    : 04.02.2021                                              *
 * Modification date: 07.02.2021                                              *
 ******************************************************************************
 * LIBRARIES:                                                                 *
 ******************************************************************************/
#include "matrices.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
 * CONSTRUCTOR AND DESTRUCTOR                                                 *
 ******************************************************************************/

Matrix *makeMatrix(const integer r, const integer c)
{
    /*initialize object's memory block*/
    Matrix *self = (Matrix *) malloc (sizeof(Matrix));     
    /*row's    size*/
    self->row    = r;
    /*column's size*/                                     
    self->col    = c;
    /*matrix initialization in the object's memory block*/                                     
    self->matrix = (real *) malloc( r * c * sizeof(real)); 

    /*verify if the object's memory block was allocated into RAM*/
    if (self == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate\n");
        exit (EXIT_FAILURE);
    }

    return self;
}

void freeMatrix(Matrix *self)
{
    free(self->matrix);
    free(self);
}

/******************************************************************************
 * GENERAL PURPOSE METHODS                                                    *
 ******************************************************************************/

void copyMatrix(Matrix* __restrict src, Matrix* __restrict dst)
{
    memcpy(dst->matrix, src->matrix, src->row * src->col * sizeof(real));
}

void getColumn(Matrix* __restrict src, vector1D* __restrict dst, 
    const integer column, const integer nrows)
{
    memcpy(dst->x, src->matrix + column*nrows, nrows * sizeof(real));
}

void getRow(Matrix *src, vector1D* dst, const integer row, const integer ncols)
{
    register integer j;

    for(j = 0; j < ncols; j++)
    {
        dst->x[j] = *(src->matrix + row + ncols * j);
    }
}

void transverseMatrix(Matrix *src)
{
    register integer i;  /*row    counter loop*/
    register integer j;  /*column counter loop*/

    for(i = 0; i < src->row; i++)
    {
        for(j = 0; j < src->col; j++)
        {
            printf("%g\t", src->matrix[i + src->col*j]);
        }

        printf("\n");
    }
}

void getConstSubmatrix(Matrix *src, Matrix *dst, const integer startRow, 
    const integer startCol)
{
    if(dst->row > src->row || dst->col > src->row)
    {
        printf ("ERROR: sub-matrix with inappropriate dimensions\n");
        exit (EXIT_FAILURE);
    }

    /*verify limits of the entry values: startRow and startCol*/
    if(startRow >= 0 &&  startCol >= 0 && startRow < src->row - 1 && 
       startCol < src->col - 1) 
    {
        register integer ib;             /*row counter of matrix B*/
        register integer jb;             /*col counter of matrix B*/
        register integer ja = startCol;  /*col counter of matrix A*/

        for(ib = 0; ib < dst->row; ib++)
        {
            for(jb = 0; jb < dst->col; jb++)
            {
                *(dst->matrix + ib + dst->col*jb) = *(src->matrix + startRow + 
                    ib + src->col*ja);

                ja++; /*walking along the matrix A columns*/ 
            }

            ja = startCol; /*restarting the column's counter of the matrix A*/
        }
    }
    else
    {
        printf ("ERROR: start row or start column are not correct\n");
        exit (EXIT_FAILURE);
    }
}

void getGeneralSubmatrix(Matrix *src, Matrix *dst, integer *row, integer *col)
{
    if(dst->row > src->row || dst->col > src->row)
    {
        printf ("ERROR: sub-matrix with inappropriate dimensions\n");
        exit (EXIT_FAILURE);
    }

    register integer ib;
    register integer jb;
    
    for(ib = 0; ib < dst->row; ib++)
    {   
        for(jb = 0; jb < dst->col; jb++)
        {
            *(dst->matrix + ib + dst->col * jb) = *(src->matrix + *(row + ib) + 
                src->col * *(col + jb));
        }
    }
}

void setGeneralSubmatrix(Matrix *dst, Matrix *src, integer *row, integer *col)
{
    if(src->row > dst->row || src->col > dst->row)
    {
        printf ("ERROR: sub-matrix with inappropriate dimensions\n");
        exit (EXIT_FAILURE);
    }

    register integer ib;
    register integer jb;
    
    for(ib = 0; ib < src->row; ib++)
    {   
        for(jb = 0; jb < src->col; jb++)
        {
            *(src->matrix + *(row + ib) + src->col * *(col + jb)) = *(
                dst->matrix + ib + dst->col * jb);
        }
    }
}

/******************************************************************************
 * HANDFUL MATRICES TYPES                                                     *
 ******************************************************************************/

void zeroMatrix(Matrix *src)
{
    register integer i;  /*row    counter loop*/
    register integer j;  /*column counter loop*/

    for(i = 0; i < src->row; i++)
    {
        for(j = 0; j < src->col; j++)
        {
            src->matrix[i + src->col*j] = 0.0;
        }
    }
}

void identityMatrix(Matrix *src)
{
    register integer i;  /*row    counter loop*/
    register integer j;  /*column counter loop*/

    for(i = 0; i < src->row; i++)
    {
        for(j = 0; j < src->col; j++)
        {
            if (i == j)
            {
                src->matrix[i + src->row*j] = 1.0;
            }
            else
            {
                src->matrix[i + src->row*j] = 0.0;
            }
        }
    }
}

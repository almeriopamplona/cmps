/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                MATRICES.C                                  *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 04.02.2021                                              *
 * Modification date: 05.02.2021                                              *
 ******************************************************************************
 * LIBRARIES:                                                                 *
 ******************************************************************************/
#include "matrices.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
 * SEVERAL TYPES OF MATRICES CREATIONS                                        *
 ******************************************************************************/

void zeroMatrix(Matrix *A)
{
    register unsigned int i;  /*row    counter loop*/
    register unsigned int j;  /*column counter loop*/

    for(i = 0; i < A->row; i++)
    {
        for(j = 0; j < A->column; j++)
        {
            A->matrix[i + A->row*j] = 0.0;
        }
    }
}

void makeMatrix(Matrix *A, const unsigned int r, const unsigned int c)
{
    A->row    = r;                                    /*row's    size*/
    A->column = c;                                    /*column's size*/
    A->matrix = (real *) malloc(r * c * sizeof(real)); /*header allocation*/

    /*Verify if the header was allocated in RAM*/
    if (A->matrix == NULL) 
    {
        printf ("ERROR: no free space in RAM to allocate *[%d]\n",r);
        exit (EXIT_FAILURE);
    }

    /*Initiate a zero matrix*/
    zeroMatrix(A);
}

void freeMatrix(Matrix *A)
{
    /* Free memory of the element's header*/
    free(A->matrix);
}

void copyMatrix(Matrix *A, Matrix *B)
{
    /*
    register unsigned int i;  /*row    counter loop
    register unsigned int j;  /*column counter loop

    for(i = 0; i < A->row; i++)
    {
        for(j = 0; j < A->column; j++)
        {
            B->matrix[i + B->row*j] = A->matrix[i + A->row*j];
        }
    }*/

    memcpy(B->matrix, A->matrix, A->row * A->column);
}

void identityMatrix(Matrix *A)
{
    register unsigned int i;  /*row    counter loop*/
    register unsigned int j;  /*column counter loop*/

    for(i = 0; i < A->row; i++)
    {
        for(j = 0; j < A->column; j++)
        {
            if (i == j)
            {
                A->matrix[i + A->row*j] = 1.0;
            }
            else
            {
                A->matrix[i + A->row*j] = 0.0;
            }
        }
    }
}

/******************************************************************************
 * GETTING MATRIX ELEMENTS                                                    *
 ******************************************************************************/

void transverseMatrix(Matrix *A)
{
    register unsigned int i;  /*row    counter loop*/
    register unsigned int j;  /*column counter loop*/

    for(i = 0; i < A->row; i++)
    {
        for(j = 0; j < A->column; j++)
        {
            printf("%g\t", A->matrix[i + A->row*j]);
        }

        printf("\n");
    }
}

void indexMatrix(Matrix *A,  Matrix *B, unsigned int xStart, unsigned int xEnd, 
    unsigned int yStart, unsigned int yEnd)
{
    if(xStart < 0 || yStart < 0)
    {
        printf ("ERROR: initial index less than zero\n");
        exit (EXIT_FAILURE);
    }

    if(xEnd > A->row || yEnd > A->column)
    {
        printf ("ERROR: final index greater than matrix limits\n");
        exit (EXIT_FAILURE);
    }

    register unsigned int i;
    register unsigned int j;
    register unsigned int m = xStart;
    register unsigned int n = yStart;

    for(i = 0; i < B->row; i++)
    {
        for (j = 0; j < B->column; j++)
        {
            B->matrix[i + B->row*j] = A->matrix[m + A->row*n];
            n++; 
        }
        n = yStart;
        m++;
    }
}

/******************************************************************************
 * LINEAR ALGEBRA                                                             *
 ******************************************************************************/
/*
Matrix LU(Matrix *A)
{
    Matrix *L = (Matrix *)malloc(sizeof(Matrix))
    Matrix *
    if(m = 1)
    {

    }
}
*/

/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                               STRUCTURE.H                                  *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 27.01.2021                                              *
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
 * Defining the fundamental objects to build the MPS method application.      *
 * Furthermore, some important numerical constants are also defined as macros.*
 *                                                                            *
 ******************************************************************************/

#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

#include "arrays.h"
#include "linearalgebra.h"
#include <string.h>

/******************************************************************************
 * NUMERICAL CONSTANT PARAMETERS                                              *
 ******************************************************************************/

#define PI 3.141592653589793238462643383279502884197169399375105820974944592308
#define DTMAX    5e-03    // maximum  time step
#define DTMIN    5e-11    // minimum  time step
#define DTIMP    1e-02    // printing time step
#define NCXMAX   500      // maximum number of cells in x-direction
#define NCYMAX   500      // maximum number of cells in y-direction
#define NCZMAX   500      // maximum number of cells in z-direction
#define PNMAX    2e+04    // maximum number of particles in simulation
#define DNMAX    5e+03    // maximum number of dummy     in simulation
#define WNMAX    1e+03    // maximum number of wall      in simulation
#define MAXIT    50       // maximum iteration number

/******************************************************************************
 * STRUCTURES                                                                 *
 ******************************************************************************/

/* Boolean structure: */
typedef enum boolean {

    true  = 1,
    false = 0 

} boolean;

/* Fluid particle: */
typedef struct fluid {
    intArray index;        /* material index                                  */
    intArray idMat;        /* material id                                     */
    intArray neighS;       /* neighbour's id list for small radius            */
    intArray neighL;       /* neighbour's id list for large radius            */
    vector1D pressure;     /* pressure                                        */
    vector1D pressurek0;   /* pressure variation                              */
    vector1D temperature;  /* temperature                                     */
    vector1D pndS;         /* particle number of density for small radius     */
    vector1D pndL;         /* particle number of density for large radius     */
    vector1D pndB;         /* particle number of density for boundaries       */
    vector1D pndMat;       /* particle number of density per material         */
    vector1D dNeighS;
    vector1D dNeighL;
    vector3D r;
    vector3D rn;
    vector3D dr;
    vector3D u;
    vector3D un;
    vector3D du;
    vector3D normal;      /* normal vector for solid wall particles           */ 

} fluid;


/* Neighbourhood linked list: */
typedef struct neighbour {
  
    int    neighS;        /* neighbour with small radius                      */
    int    neighL;        /* neighbour with large radius                      */
    int    nNeighS;       /* number of neighbours with small radius           */
    int    nNeighL;       /* number of neighbours with large radius           */

} neighbur; 

#endif

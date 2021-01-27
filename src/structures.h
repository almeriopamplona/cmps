/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                               STRUCTURE.H                                  *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 27.01.2021                                              *
 * Modification date: 27.01.2021                                              *
 ******************************************************************************
 * Description:                                                               *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

#ifdef  __STRUCTURES_H__
#define __STRUCTURES_H__

/******************************************************************************
 * NUMERICAL CONSTANT PARAMETERS                                              *
 ******************************************************************************/

#define PI 3.141592653589793238462643383279502884197169399375105820974944592308
#define DTMAX    5e-03  // maximum  time step
#define DTMIN    5e-11  // minimum  time step
#define DTIMP    1e-02  // printing time step
#define NCXMAX   500    // maximum number of cells in x-direction
#define NCYMAX   500    // maximum number of cells in y-direction
#define NCZMAX   500    // maximum number of cells in z-direction
#define PNMAX    2e+04  // maximum number of particles in simulation
#define DNMAX    5e+03  // maximum number of dummy     in simulation
#define WNMAX    1e+03  // maximum number of wall      in simulation
#define MAXIT    50     // maximum iteration number

/******************************************************************************
 * STRUCTURES                                                                 *
 ******************************************************************************/

// Boolean structure:
typedef enum boolean {

  true  = 1,
  false = 0 

} bool_t;

// Fluid
typedef struct fluid {

  int    type;
  int    material;
  double x;
  double y;
  double z;
  double ux;
  double uy;
  double uz;
  double p;
  double 
} fluid_t;

#endif

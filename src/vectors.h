/******************************************************************************
 *                   MPS - MOVING PARTICLES SEMI-IMPLICIT                     *
 *                                VECTORS.H                                   *
 ******************************************************************************
 * Author: Almério José Venâncio Pains Soares Pamplona                        *
 * E-mail: almeriopamplona@gmail.com                                          *
 ******************************************************************************
 * Creation date    : 28.01.2021                                              *
 * Modification date: 29.01.2021                                              *
 ******************************************************************************
 * Description:                                                               *
 *                                                                            *
 * In the present script, vector objects are created as vector1D, vector2D,   *
 * and vector3D.Furthermore, functions for creation, destruction, operations  *
 * and manipulation are defined.                                              *
 *                                                                            *
 ******************************************************************************/

#ifdef  __VECTORS_H__
#define __VECTORS_H__

/******************************************************************************
 * TYPE DEFINITIONS                                                           *
 ******************************************************************************/

// Defining macro constants:

#define MEM_SIZE        128

// Defining data-type:

typedef double          real;      // variables that are in the Real    field  
typedef unsigned long   integer;   // variables that are in the Integer field

// Defining vector objects:

struct vector1D 
{
	integer  size;
	integer  sizeMax;
	real    *x;

} __attribute__((packed));

struct vector2D 
{
    integer  size;
    integer  sizeMax;
    real    *x, *y;

} __attribute__((packed));

struct vector3D 
{
    integer  size;
    integer  sizeMax;
    real    *x, *y, *z;

} __attribute__((packed));

/******************************************************************************
 *VECTORS CREATION                                                            *
 ******************************************************************************/

/*1D ALGEBRA ---------------------------------------------------------------- */

/******************************************************************************
 * Function:    zeroVector1D                                                  *
 * -------------------------------------------------------------------------- *
 * description: create a vector {x}, where x is an array with n elements, and *
 *              this elements have 0 as their value.                          *
 * -------------------------------------------------------------------------- *
 * input:  vector1D *v      // pointer to some vector v                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: v->x = [0, ..., 0]                                                 *
 ******************************************************************************/
void zeroVector1D(vector1D *v, const integer n);

/******************************************************************************
 * Function:    makeVector1D                                                  *
 * -------------------------------------------------------------------------- *
 * description: creates a vector v, attributes the total number of elements,  *
 *              dynamically allocates memory for each of the vector's         * 
 *              components and attributes value 0 for every element.          *
 * -------------------------------------------------------------------------- *
 * input:  vector1D *v      // pointer to some vector v                       *
 *         int       n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: v                // vector v                                       *
 ******************************************************************************/
void makeVector1D(vector1D *v, const integer n);

/******************************************************************************
 * Function:    freeVector1D                                                  *
 * -------------------------------------------------------------------------- *
 * description: free the memory dynamically allocated of each component of    *
 *              the vector v and set the total elements as zero.              *
 * -------------------------------------------------------------------------- *
 * input:  vector1D *v      // pointer to some vector v                       *
 * -------------------------------------------------------------------------- *
 * output: vector v with empty v->x, besides v->n = 0.                        *
 ******************************************************************************/
void freeVector1D(vector1D *v);

/******************************************************************************
 * Function:    copyVector1D                                                  *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to copy the elements of one vector's      *
 *              components into another vector's components.                  *
 * -------------------------------------------------------------------------- *
 * input:  vector1D *v      // pointer to some vector v                       *
 *         vector1D *w      // pointer to some vector w                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: w                // vector w                                       *
 ******************************************************************************/
void copyVector1D(vector1D *v, vector1D *w, const integer n);

/*2D ALGEBRA ---------------------------------------------------------------- */

/******************************************************************************
 * Function:    zeroVector2D                                                  *
 * -------------------------------------------------------------------------- *
 * description: create a vector {x, y}, where x and y are arrays with n       *
 *              n elements, and this elements have 0 as their value.          *
 * -------------------------------------------------------------------------- *
 * input:  vector2D *v      // pointer to some vector v                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: v->x = [0, ..., 0], v->y = [0, ..., 0]                             *
 ******************************************************************************/
void zeroVector2D(vector2D *v, const integer n);

/******************************************************************************
 * Function:    makeVector2D                                                  *
 * -------------------------------------------------------------------------- *
 * description: creates a vector v, attributes the total number of elements,  *
 *              dynamically allocates memory for each of the vector's         * 
 *              components and attributes value 0 for every element.          *
 * -------------------------------------------------------------------------- *
 * input:  vector2D *v      // pointer to some vector v                       *
 *         int       n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: v                // vector v                                       *
 ******************************************************************************/
void makeVector2D(vector2D *v, const integer n);

/******************************************************************************
 * Function:    freeVector2D                                                    *
 * -------------------------------------------------------------------------- *
 * description: free the memory dynamically allocated of each component of    *
 *              the vector v and set the total elements as zero.              *
 * -------------------------------------------------------------------------- *
 * input:  vector2D *v      // pointer to some vector v                       *
 * -------------------------------------------------------------------------- *
 * output: vector v with empty v->x, besides v->n = 0.                        *
 ******************************************************************************/
void freeVector2D(vector2D *v);

/******************************************************************************
 * Function:    copyVector2D                                                  *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to copy the elements of one vector's      *
 *              components into another vector's components.                  *
 * -------------------------------------------------------------------------- *
 * input:  vector2D *v      // pointer to some vector v                       *
 *         vector2D *w      // pointer to some vector w                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: w                // vector w                                       *
 ******************************************************************************/
void copyVector2D(vector2D *v, vector2D *w, const integer n);

/*3D ALGEBRA ---------------------------------------------------------------- */

/******************************************************************************
 * Function:    zeroVector3D                                                  *
 * -------------------------------------------------------------------------- *
 * description: create a vector {x, y, z}, where x, y and z are arrays with n *
 *              n elements, and this elements have 0 as their value.          *
 * -------------------------------------------------------------------------- *
 * input:  vector3D *v      // pointer to some vector v                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: v->x = [0, ..., 0], v->y = [0, ..., 0], v->z = [0, ..., 0]         *
 ******************************************************************************/
void zeroVector3D(vector3D *v, const integer n);

/******************************************************************************
 * Function:    makeVector3D                                                  *
 * -------------------------------------------------------------------------- *
 * description: creates a vector v, attributes the total number of elements,  *
 *              dynamically allocates memory for each of the vector's         * 
 *              components and attributes value 0 for every element.          *
 * -------------------------------------------------------------------------- *
 * input:  vector3D *v      // pointer to some vector v                       *
 *         int       n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: v                // vector v                                       *
 ******************************************************************************/
void makeVector3D(vector3D *v, const integer n);

/******************************************************************************
 * Function:    freeVector3D                                                  *
 * -------------------------------------------------------------------------- *
 * description: free the memory dynamically allocated of each component of    *
 *              the vector v and set the total elements as zero.              *
 * -------------------------------------------------------------------------- *
 * input:  vector3D *v      // pointer to some vector v                       *
 * -------------------------------------------------------------------------- *
 * output: vector v with empty v->x, besides v->n = 0.                        *
 ******************************************************************************/
void freeVector3D(vector3D *v);

/******************************************************************************
 * Function:    copyVector3D                                                  *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to copy the elements of one vector's      *
 *              components into another vector's components.                  *
 * -------------------------------------------------------------------------- *
 * input:  vector3D *v      // pointer to some vector v                       *
 *         vector3D *w      // pointer to some vector w                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: w                // vector w                                       *
 ******************************************************************************/
void copyVector3D(vector3D *v, vector3D *w, const integer n);



/******************************************************************************
 * VECTORS OPERATION                                                          *
 ******************************************************************************/

/*1D ALGEBRA ---------------------------------------------------------------- */

/******************************************************************************
 * Function:    addVector1D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to add two vectors, v and w, into one     *
 *              vector s.                                                     *
 * -------------------------------------------------------------------------- *
 * input:  vector1D *v      // pointer to some vector v                       *
 *         vector1D *w      // pointer to some vector w                       *
 *         vector1D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the addition                  *
 ******************************************************************************/
void addVector1D(vector1D *v, vector1D *w, vector1D *s, const integer n);

/******************************************************************************
 * Function:    subVector1D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to subtract vectors w from vector v into  *
 *              one vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector1D *v      // pointer to some vector v                       *
 *         vector1D *w      // pointer to some vector w                       *
 *         vector1D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void subVector1D(vector1D *v, vector1D *w, vector1D *s, const integer n);

/******************************************************************************
 * Function:    mulVector1D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to multiply vectors w and v into one      *
 *              vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector1D *v      // pointer to some vector v                       *
 *         vector1D *w      // pointer to some vector w                       *
 *         vector1D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void mulVector1D(vector1D *v, vector1D *w, vector1D *s, const integer n);

/******************************************************************************
 * Function:    divVector1D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to divide vectors v by vector w into      *
 *              one vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector1D *v      // pointer to some vector v                       *
 *         vector1D *w      // pointer to some vector w                       *
 *         vector1D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void divVector1D(vector1D *v, vector1D *w, vector1D *s, const integer n);


/*2D ALGEBRA ---------------------------------------------------------------- */

/******************************************************************************
 * Function:    addVector2D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to add two vectors, v and w, into one     *
 *              vector s.                                                     *
 * -------------------------------------------------------------------------- *
 * input:  vector2D *v      // pointer to some vector v                       *
 *         vector2D *w      // pointer to some vector w                       *
 *         vector2D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the addition                  *
 ******************************************************************************/
void addVector3D(vector2D *v, vector2D *w, vector2D *s, const integer n);

/******************************************************************************
 * Function:    subVector2D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to subtract vectors w from vector v into  *
 *              one vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector2D *v      // pointer to some vector v                       *
 *         vector2D *w      // pointer to some vector w                       *
 *         vector2D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void subVector2D(vector2D *v, vector2D *w, vector2D *s, const integer n);

/******************************************************************************
 * Function:    mulVector2D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to multiply vectors w and v into one      *
 *              vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector2D *v      // pointer to some vector v                       *
 *         vector2D *w      // pointer to some vector w                       *
 *         vector2D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void mulVector3D(vector2D *v, vector2D *w, vector2D *s, const integer n);

/******************************************************************************
 * Function:    divVector2D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to divide vectors v by vector w into      *
 *              one vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector2D *v      // pointer to some vector v                       *
 *         vector2D *w      // pointer to some vector w                       *
 *         vector2D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void divVector2D(vector2D *v, vector2D *w, vector2D *s, const integer n);


/*3D ALGEBRA ---------------------------------------------------------------- */

/******************************************************************************
 * Function:    addVector3D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to add two vectors, v and w, into one     *
 *              vector s.                                                     *
 * -------------------------------------------------------------------------- *
 * input:  vector3D *v      // pointer to some vector v                       *
 *         vector3D *w      // pointer to some vector w                       *
 *         vector3D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the addition                  *
 ******************************************************************************/
void addVector3D(vector3D *v, vector3D *w, vector3D *s, const integer n);

/******************************************************************************
 * Function:    subVector3D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to subtract vectors w from vector v into  *
 *              one vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector3D *v      // pointer to some vector v                       *
 *         vector3D *w      // pointer to some vector w                       *
 *         vector3D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void subVector3D(vector3D *v, vector3D *w, vector3D *s, const integer n);

/******************************************************************************
 * Function:    mulVector3D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to multiply vectors w and v into one      *
 *              vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector3D *v      // pointer to some vector v                       *
 *         vector3D *w      // pointer to some vector w                       *
 *         vector3D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void mulVector3D(vector3D *v, vector3D *w, vector3D *s, const integer n);

/******************************************************************************
 * Function:    divVector3D                                                   *
 * -------------------------------------------------------------------------- *
 * description: uses lazy computing to divide vectors v by vector w into      *
 *              one vector s.                                                 *
 * -------------------------------------------------------------------------- *
 * input:  vector3D *v      // pointer to some vector v                       *
 *         vector3D *w      // pointer to some vector w                       *
 *         vector3D *s      // pointer to some vector s                       *
 *         integer   n      // total number of elements                       *
 * -------------------------------------------------------------------------- *
 * output: s                // result vector of the subtraction               *
 ******************************************************************************/
void divVector3D(vector3D *v, vector3D *w, vector3D *s, const integer n);

#endif

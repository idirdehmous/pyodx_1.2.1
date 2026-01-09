#define PY_SSIZE_T_CLEAN
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <Python.h>

//  THIS IS A DRAFT OF INIT MODULE !!!
//  //Init some specific python environment veriables
//  //Init some ODB envs 
// C wrappers
static PyObject* pyodx_Init_method( PyObject *Py_UNUSED(self)){
// INIALISATION OF PYTHON ENVIRONNEMT AND SOME SPECIFIC ODB VARIBALES !
// pyodb can run whitout , just for more rebustness 
// THIS MODDULE IS UNDER DEV !
    printf ("%s\n" ,"--------------------------------------------------" )  ;
    printf ("%s\n", "THE MODULE  pyodx_Init  IS UNDER DEVELOPMENT !" )  ;
    printf ("%s\n" ,"--------------------------------------------------" )   ;
return NULL ;
}


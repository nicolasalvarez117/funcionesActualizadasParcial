#include <stdio.h>
#include <stdlib.h>
#include "imput.h"
#include "empleados.h"
#include "ordenamiento.h"

/**
  *\brief Ordena por apellido ascendente el array de empleados.
  *\param el array a ordenar, la cantidad de elementos, y un auxiliar para hacer el movimiento de lugares.
**/
void ordenarEmpleadosApellido(eEmpleados arrayEmpleados[],int cantidadElementos,eEmpleados auxEmpleados)
{
    int i,j;

    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(arrayEmpleados[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(arrayEmpleados[j].legajo == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayEmpleados[i].apellido,arrayEmpleados[j].apellido) > 0)
                        {
                            auxEmpleados = arrayEmpleados[j];
                            arrayEmpleados[j] = arrayEmpleados[i];
                            arrayEmpleados[i] = auxEmpleados;

                        }
                    }
                }
}


/**
  *\brief Ordena por precio descendente el array de Menus.
  *\param el array a ordenar, la cantidad de elementos, y un auxiliar para hacer el movimiento de lugares.
**/
void ordenarMenuesPrecio(eMenues arrayMenues[],int cantidadElementos,eMenues auxMenues)
{
    int i,j;

    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(arrayMenues[i].id == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(arrayMenues[j].id == -1)
                        {
                            continue;
                        }
                        if(arrayMenues[i].precio < arrayMenues[j].precio)
                        {
                            auxMenues = arrayMenues[j];
                            arrayMenues[j] = arrayMenues[i];
                            arrayMenues[i] = auxMenues;

                        }
                    }
                }
}

/**
  *\brief Ordena por descripcion ascendente el array de Menus.
  *\param el array a ordenar, la cantidad de elementos, y un auxiliar para hacer el movimiento de lugares.
**/
void ordenarMenuesDescripcion(eMenues arrayMenues[],int cantidadElementos,eMenues auxMenues)
{
    int i,j;

    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(arrayMenues[i].id == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(arrayMenues[j].id == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayMenues[i].descripcion,arrayMenues[j].descripcion) > 0)
                        {
                            auxMenues = arrayMenues[j];
                            arrayMenues[j] = arrayMenues[i];
                            arrayMenues[i] = auxMenues;

                        }
                    }
                }
}



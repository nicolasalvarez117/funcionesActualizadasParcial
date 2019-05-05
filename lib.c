#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "lib.h"

#define ACUPADO 1
#define LIBRE -1

#define TRUE 1
#define FALSE 0

//-------------------------BUSCAR ESPACIO LIBRE-----------------------------------
/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor retorna -1.
**/
int buscarPrimerOcurrencia(t_Asociado arrayAsociados[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayAsociados[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

//------------------------INICIALIZAR DATOS-------------------------------------------
/**
  *\brief inicializa los valores unicos  con LIBRE(-1).
  *\param el array  y la cantidad de elementos del array.
**/
void inicializarArray(t_Asociado arrayAsociados[],int cantidadDeElementos)
{
    int i;
    for(i=0;i<cantidadDeElementos;i++)
    {
        arrayAsociados[i].estado = LIBRE;
        arrayAsociados[i].id = 0;

    }
}

//----------------MENUS DE OPCIONES----------------------------
/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu(int *resultado)
{
    int i;
    char aux[15];
    getNumber("1:ALTA\n2:BAJA\n3:MODIFICAR\n4:SALIR: ","opcion incorrecta: ",1,4,1,2,aux);
    *resultado = atoi(aux);

}

/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu2(int *resultado)
{
    int i;
    char aux[15];
    getNumber("1:ASOCIADOS\n2:SALIR: ","opcion incorrecta: ",1,2,1,2,aux);
    *resultado = atoi(aux);

}
//---------------------------------ALTA BAJA Y MODIFICACION-----------------------------------
void Alta(t_Asociado str[],int cantidadElementos)
{
    int espacioLibre;
    char auxiliar[51];
    espacioLibre = buscarPrimerOcurrencia(str,5,-1);

    if(espacioLibre != -1)
    {
        getName("\nIngrese nombre:  ","error",1,51,str[espacioLibre].nombre);
        getName("\nIngrese apellido:  ","error",1,51,str[espacioLibre].apellido);
        getDni("\nIngrese DNI: ","error",1,9,str[espacioLibre].dni);
        getNumber("\nIngrese edad: ","error",1,120,1,4,str[espacioLibre].edad);
        str[espacioLibre].id = ++str[espacioLibre].id;
        str[espacioLibre].estado = 1;
    }
    else
    {
        printf("No encontro lugar");
    }
}
//-----------------------------LISTAR DATOS POR PANTALLA---------------------------------------
/**
  *\brief Lista los datos necesarios por pantalla del array empleados.
  *\param el array de empleados, el del sector, la cantidad de empleados y el valor ocupado para la lista logica.
**/
void mostrarLista(t_Asociado str[],int cantidadElementos,int valorOcupado)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(str[i].estado != -1)
        {
           printf("%d %s %s %s ",str[i].id,str[i].dni,str[i].nombre,str[i].apellido);
        }
    }
}

/**
  *\brief Toma una DNI como caracteres numericos ingresada por el usuario.
  *\param Recibe un mensaje, mensaje para error, minimo cantidad de caracteres, y un maximo.
  *\param Cantidad de reintentos por error, y un puntero a resultado final.
  *\return Un entero para la verificacion de exito o de error en el programa.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
int getDni(    char* msg,
                char* msgError,
                int minimo,
                int maximo,
                char* resultado)
{
    int retorno = -1;
    int flag = 1;
    char bufferStr[4096];
    if( msg != NULL &&
        msgError != NULL &&
        minimo < maximo &&
        resultado != NULL)
    {
      do
      {
        printf(msg);
        if(!getString(minimo,maximo,bufferStr))
        {
            if(isValidNumber(bufferStr))
            {
                if(isValidDni(bufferStr))
                {
                    strncpy(resultado,bufferStr,maximo);
                    flag = 0;
                    retorno = 0;
                }
                else
                {
                    printf(msgError);
                }

            }
            else
            {
                printf(msgError);
            }
        }
        else
        {
            printf(msgError);
        }
    }while(flag);
    }
    return retorno;
}

/**
  *\brief Valida si el array de DNI es completo.
  *\param Recibe el array con la cadena de numerica.
  *\return TRUE o FALSE.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
int isValidDni(char str[])
{
    int retorno = FALSE;
    if(!(str[7] == '\0' || str[7] == NULL))
    {
        retorno = TRUE;
    }
    return retorno;
}

void baja(t_Asociado str[],int cantidadElementos)
{
   int espacioLibre;
   char auxDato[51];
   espacioLibre = buscarPrimerOcurrencia(str,5,1);
   if(espacioLibre != -1)
   {
    mostrarLista(str,cantidadElementos,-1);
    getNumber("que id desea dar de baja","error",1,cantidadElementos,1,cantidadElementos,auxDato);
    espacioLibre = buscarPrimerOcurrencia(str,5,atoi(auxDato));

        if(espacioLibre != -1)
        {
            str[espacioLibre].estado = -1;
            printf("\nBaja exitosa");
        }
        else
        {
            printf("\nEl dato no existe");
        }
   }
   else
   {
       printf("\nno hay datos cargados");
   }
}

void modificacion( t_Asociado str[],int cantidadElementos)
{
    int espacioLibre;
    char auxDato[51];
    espacioLibre = buscarPrimerOcurrencia(str,5,1);
    if(espacioLibre != -1)
    {
        mostrarLista(str,cantidadElementos,-1);
        getNumber("ingrese la id a modificar","error",1,cantidadElementos,1,cantidadElementos,auxDato);
        espacioLibre = buscarPrimerOcurrencia(str,5,atoi(auxDato));
        if(espacioLibre != -1)
        {
            getName("\nIngrese nuevo nombre:  ","error",1,51,str[espacioLibre].nombre);
            getName("\nIngrese nuevo apellido:  ","error",1,51,str[espacioLibre].apellido);
        }
        else
        {
            printf("El dato no existe");
        }
    }
    else
    {
        printf("no hay datos cargados");
    }
}

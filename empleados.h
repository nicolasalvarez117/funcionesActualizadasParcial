#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct
{
  int idMenu;
  int legajoEmpleado;
  int dia;
  int mes;
  int anio;
}eEmpleado_Menu;


typedef struct
{
  int idSector;
  int legajoEmpleado;
}eEmpleado_Sector;

typedef struct
{
  int idSector;
  char descripcion[20];
}eSector;

typedef struct
{
    int id;
    int empleadoLegajo;
    int precio;
    char descripcion[50];

}eMenues;

typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
    int legajo;
    float sueldoBruto;
    int fechaIngreso;
    int idSector;
    int idMenu;
    char sexoEmpleado;
    int estado;
    int precioMenuAcumulado;
    eFecha t_Fecha;

}eEmpleados;
//------------------------------------------------------------------------------------
int buscarPrimerOcurrencia(eEmpleados arrayEmpleados[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia2(eMenues arrayMenues[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia3(eEmpleados arrayEmpleados[],int cantidadDeElementos,int valor);
//-------------------------------------------------------------------------------------
void inicializarArrayEmpleados(eEmpleados arrayEmpleados[],int cantidadDeElementos);
void inicializarArrayMenues(eMenues arrayMenues[],int cantidadDeElementos);
//-------------------------------------------------------------------------------------
void mostrarListaEmpleados(eEmpleados arrayEmpleados[],eSector arraySector[], int cantidadElementos,int valorOcupado);
void mostrarSectores(eSector arraySector[],int cantidad);
void mostrarMenues(eMenues arrayMenues[],int cantidad);
//----------------------------------------------------------------------------------------
void cargarEmpleado(eEmpleados arrayEmpleados[],
                    eSector arraySector[],
                    eEmpleado_Sector idEmpleadoSector[],
                    int cantidadEmpleados,
                    int valorOcupado,
                    int maxCaracter,
                    int auxLegajo);
void borrarEmpleado(eEmpleados arrayEmpleados[], int cantidadElementos);
void modificarEmpleado(eEmpleados arrayEmpleados[],eSector arraySector[], int cantidadElementos,int opcion,int legajo);
//--------------------------------------------------------------------------------------------
void hardcodearDatosEmpleados(eEmpleados arrayEmpleados[]);
void hardcodearDatosMenues(eMenues arrayMenues[]);
void hardcodearDatosSector(eSector arraySector[]);
//-----------------------------------------------------------------------------------------------
void menu(int *resultado);
void menu2(int *resultado);
void menu3(int *resultado);
//-----------------------------------------------------------------------------------------------
void cargarMenu(eMenues arrayMenues[],int cantidadMenues,int valorOcupado,int maxCaracter);
void modificarMenues(eMenues arrayMenues[],int cantidadElementos);
void borrarMenues(eMenues arrayMenues[], int cantidadElementos);
//-----------------------------------------------------------------------------------------------
void cargarAlmuerzo(eEmpleado_Menu idEmpleadoMenu[],eEmpleados arrayEmpleados[],eMenues arrayMenues[],
                     int cantidadElementos,int legajo,int maxCaracter);
void borrarAlmuerzo(eEmpleado_Menu idEmpleadoMenu[], int cantidadElementos);
//----------------------------------------------------------------------------
void mostrarAlmuerzos(eEmpleados arrayEmpleado[],eMenues arrayMenues[],eEmpleado_Menu idEmpleadoMenu[],int cantidad);








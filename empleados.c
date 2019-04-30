#include <stdio.h>
#include <stdlib.h>
#include "imput.h"
#include "empleados.h"
#include "ordenamiento.h"

#define OCUPADO 1
#define LIBRE -1

#define FALSE 0
#define TRUE 1

#define QTY_EMPLEADOS 10
#define QTY_MENUES 5
#define QTY_SECTORES 5

//-------------------------BUSCAR ESPACIO LIBRE-----------------------------------
/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor retorna -1.
**/
int buscarPrimerOcurrencia(eEmpleados arrayEmpleados[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayEmpleados[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor retorna -1.
**/
int buscarPrimerOcurrencia2(eMenues arrayMenues[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayMenues[i].id == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor retorna -1.
**/
int buscarPrimerOcurrencia3(eEmpleados arrayEmpleados[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayEmpleados[i].legajo == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}
//------------------------INICIALIZAR DATOS-------------------------------------------
/**
  *\brief inicializa los valores unicos de arrayEmpleado con LIBRE(-1) y el precio de menues que va a acumular.
  *\param el array de empleados y la cantidad de elementos del array.
**/
void inicializarArrayEmpleados(eEmpleados arrayEmpleados[],int cantidadDeElementos)
{
    int i;
    for(i=0;i<cantidadDeElementos;i++)
    {
        arrayEmpleados[i].estado = LIBRE;
        arrayEmpleados[i].legajo = LIBRE;
        arrayEmpleados[i].idMenu = LIBRE;
        arrayEmpleados[i].precioMenuAcumulado = 0;
    }
}

/**
  *\brief inicializa los valores unicos de arrayMenues con LIBRE(-1).
  *\param el array de Menues y la cantidad de elementos del array.
**/
void inicializarArrayMenues(eMenues arrayMenues[],int cantidadDeElementos)
{
    int i;
    for(i=0;i<cantidadDeElementos;i++)
    {
        arrayMenues[i].id = LIBRE;

    }
}

/**
  *\brief Lista los datos necesarios por pantalla del array empleados.
  *\param el array de empleados, el del sector, la cantidad de empleados y el valor ocupado para la lista logica.
**/
//-----------------------------LISTAR DATOS POR PANTALLA---------------------------------------
void mostrarListaEmpleados(eEmpleados arrayEmpleados[],eSector arraySector[], int cantidadElementos,int valorOcupado)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(arrayEmpleados[i].estado == 1)
        {
            printf("legajo: %d %s %s %c",arrayEmpleados[i].legajo,arrayEmpleados[i].nombre,arrayEmpleados[i].apellido,arrayEmpleados[i].sexoEmpleado);
            printf(" %.2f %s\n",arrayEmpleados[i].sueldoBruto,arraySector[arrayEmpleados[i].idSector-1].descripcion);

        }
    }
}

/**
  *\brief Muestra la lista de sectores y sus IDs cargados en el arraySector.
  *\param el array donde contiene los datos a mostrar y la cantidad de elementos del array.
**/
void mostrarSectores(eSector arraySector[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf("%d %s \n",arraySector[i].idSector,arraySector[i].descripcion);
    }
}

/**
  \brief muestra los Menus cargados en el arrayMenues.
  \param el array de menus y la cantidad de elementos del array.
**/
void mostrarMenues(eMenues arrayMenues[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf("%d %s %d\n",arrayMenues[i].id,arrayMenues[i].descripcion,arrayMenues[i].precio);
    }
}
//------------------ALTA , BAJA Y MODIFICACION-----------------------------------
/**
  *\brief Da el alta a un empleado, pidiendo al usuario todos los datos necesarios.
  *\param El array de empleados y de sector, la cantidad de empleados.
  *\param el valor ocupado para encontrar el espacio libre.
  *\param el maximo de caracteres y el legajo autoincremental.
**/
void cargarEmpleado(eEmpleados arrayEmpleados[],
                    eSector arraySector[],
                    eEmpleado_Sector idEmpleadoSector[],
                    int cantidadEmpleados,
                    int valorOcupado,
                    int maxCaracter,
                    int auxLegajo)
{
    int i;
    char auxNacionalidad[10];
    char auxSexo;
    int flag = 0;
    char auxDia[10];
    char auxMes[10];
    char auxAnio[10];
    char auxSalario[20];
    char auxSector[10];
    i = buscarPrimerOcurrencia(arrayEmpleados,cantidadEmpleados,valorOcupado);
    if(i!=-1)
    {
        getName("Ingrese Nombre: ","\ncaracter incorrecto\n",1,maxCaracter,arrayEmpleados[i].nombre);
        getName("Ingrese Apellido: ","\ncaracter incorrecto\n",1,maxCaracter,arrayEmpleados[i].apellido);
        getSexo("Ingrese el sexo M o F: ","sexo incorrecto\n",&auxSexo);
        getNumber("ingrese el salario: ","caracter incorrecto",1,100000,1,15,auxSalario);
        getNumber("fecha de ingreso\nDia: ","caracter incorrecto",1,31,1,3,auxDia);
        getNumber("\nMes: ","caracter incorrecto",1,12,1,3,auxMes);
        getNumber("\nAño: ","caracter incorrecto",1930,2019,1,5,auxAnio);
        mostrarSectores(arraySector,QTY_SECTORES);
        getNumber("sector en el que trabaja: ","caracter incorrecto",1,5,1,2,auxSector);

        arrayEmpleados[i].sexoEmpleado = auxSexo;
        arrayEmpleados[i].idSector = atoi(auxSector);
        arrayEmpleados[i].t_Fecha.dia = atoi(auxDia);
        arrayEmpleados[i].t_Fecha.mes = atoi(auxMes);
        arrayEmpleados[i].t_Fecha.anio = atoi(auxAnio);
        arrayEmpleados[i].sueldoBruto = atof(auxSalario);
        arrayEmpleados[i].legajo = auxLegajo + 1;
        arrayEmpleados[i].estado = OCUPADO;
        idEmpleadoSector[i].idSector = atoi(auxSector);
        idEmpleadoSector[i].legajoEmpleado = atoi(auxLegajo);
        system("cls");
        printf("\nAlta exitosa");

    }
    else
    {
        printf("\nNo hay espacio\n");
    }
}

/**
  *\brief Hace una baja logica dentro de array empleados, si el legajo existe, carga estado con LIBRE(-1).
  *\param el array empleados y la cantidad de elementos del array.
**/
void borrarEmpleado(eEmpleados arrayEmpleados[], int cantidadElementos)
{

    int i;
    int loEncontro = FALSE;
    char auxLegajo[20];
    int legajo;
    getNumber("Ingrese el legajo a dar de baja: ","caracter incorrecto",1,cantidadElementos,1,5,auxLegajo);
    legajo = atoi(auxLegajo);
    for(i=0; i<cantidadElementos; i++)
    {
        if(legajo == arrayEmpleados[i].legajo)
        {

            arrayEmpleados[i].estado = LIBRE;
            arrayEmpleados[i].legajo = LIBRE;
            printf("Baja exitosa");
            loEncontro = TRUE;
            break;//modifcar
        }

    }
    if(loEncontro==FALSE)
    {
        printf("El dato no existe");
    }

}

/**
  *\brief Modifica un dato de array empleado, segun la opcion correspondiente. Trabaja con un menu de opciones.
  *\param El array empleados y sector, la cantidad de empleados, la opcion ingresada y el legajo que deseamos modificar.
**/
void modificarEmpleado(eEmpleados arrayEmpleados[],eSector arraySector[], int cantidadElementos,int opcion2,int legajo)
{

    int i;
    char auxNombre[51];
    for(i=0; i<cantidadElementos; i++)
    {
        if(legajo == arrayEmpleados[i].legajo)
        {

            switch(opcion2)
            {
            case 1:
                getName("ingrese nuevo nombre: ","caracter incorrecto",1,51,auxNombre);
                strncpy(arrayEmpleados[i].nombre,auxNombre,51);
                getName("Ingrese el nuevo apellido: ","caracter incorrecto",1,51,auxNombre);
                strncpy(arrayEmpleados[i].apellido,auxNombre,51);
                break;
            case 2:
                getNumber("ingrese el salario: ","caracter incorrecto",1,100000,1,15,auxNombre);
                arrayEmpleados[i].sueldoBruto = atof(auxNombre);
                printf("\nmodificacion exitosa");
                break;
            case 3:
                getNumber("ingrese el nuevo sector: ","caracter incorrecto",1,QTY_SECTORES,1,QTY_SECTORES,auxNombre);
                arrayEmpleados[i].idSector = atof(auxNombre);
                break;
            }
        }

    }
}
//--------------------Harcodear datos------------------------
/**
  *\brief Simula una carga de datos para la prueba del programa.
  *\param el array donde cargar los datos.
**/
void hardcodearDatosEmpleados(eEmpleados arrayEmpleados[])
{
    int i;
    int legajos[]={1,2,3,4,5};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo"};
    char apellidos[][50] ={"gonzales","alvarez","rodriguez","avila","urti"};
    char sexo[]={'F','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000};
    int estado[5] = {1,1,1,1,1};
    int dia[5]={10,5,20,26,2};
    int mes[5]={12,10,7,2,5};
    int anio[5]={2000,1992,2005,2010,2015};

    int sector[] = {2,2,1,3,4};

    for(i=0; i<5; i++)
    {
        arrayEmpleados[i].legajo = legajos[i];
        arrayEmpleados[i].sexoEmpleado = sexo[i];
        arrayEmpleados[i].sueldoBruto = sueldosBruto[i];
        arrayEmpleados[i].estado = estado[i];
        arrayEmpleados[i].idSector = sector[i];
        strncpy(arrayEmpleados[i].nombre,nombres[i],50);
        strncpy(arrayEmpleados[i].apellido,apellidos[i],50);
        arrayEmpleados[i].t_Fecha.dia = dia[i];
        arrayEmpleados[i].t_Fecha.mes = mes[i];
        arrayEmpleados[i].t_Fecha.anio = anio[i];
    }
}

/**
  *\brief Simula una carga de datos en array Menues para testear el programa.
  *\param el array donde cargar los datos.
**/
void hardcodearDatosMenues(eMenues arrayMenues[])
{
    int i;
    int id[]={1,2,3,4,5};
    char nombres[][50]={"Milanesa","Sopa","Pizza","Pescado","Asado"};

    int precio[]={200,90,150,250,300};

    for(i=0; i<5; i++)
    {
        arrayMenues[i].id = id[i];
        strcpy(arrayMenues[i].descripcion,nombres[i]);
        arrayMenues[i].precio = precio[i];

    }
}
/**
  *\brief Simula una carga de sectores para testear el programa.
  *\param el array sectores adonde se cargan los datos.
**/
void hardcodearDatosSector(eSector arraySector[])
{
    int i;
    int id[]={1,2,3,4,5};
    char nombres[][50]={"Contabilidad","RRHH","Ventas","Administracion","Limpieza"};

    for(i=0; i<5; i++)
    {
        arraySector[i].idSector = id[i];
        strcpy(arraySector[i].descripcion,nombres[i]);
    }
}
//----------------MENUS DE OPCIONES----------------------------
/**
  *\brief imprime por pantalla el menu de ABM empleados.
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu(int *resultado)
{
    int i;
    char aux[15];
    getNumber("1:ALTA\n2:BAJA\n3:MODIFICAR\n4:LISTA ORDENADA\n5:SALIR: ","opcion incorrecta: ",1,5,1,2,aux);
    *resultado = atoi(aux);

}
/**
  *\brief imprime por pantalla el menu de ABM menues.
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu2(int *resultado)
{
    int i;
    char aux[15];
    getNumber("1:ALTA\n2:BAJA\n3:MODIFICAR\n4:LISTA ORDENADA\n5:SALIR: ","opcion incorrecta: ",1,5,1,2,aux);
    *resultado = atoi(aux);

}

/**
  *\brief imprime por pantalla el menu de almuerzos.
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menu3(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\n1:ALTA DE ALMUERZO\n2:LISTA DE ALMUERZOS\n3:SALIR\n: ","opcion incorrecta: ",1,3,1,2,aux);
    *resultado = atoi(aux);

}
//------------------ABM DE MENUES-----------------------------
void cargarMenu(eMenues arrayMenues[],int cantidadMenues,int valorOcupado,int maxCaracter)
{
    char auxMenu[51];
    int i;
    int j;
    i = buscarPrimerOcurrencia2(arrayMenues,cantidadMenues,-1);
    if(i != -1)
    {
        getNumber("Ingrese el nuevo menu","caracter incorrecto",1,cantidadMenues,1,cantidadMenues,auxMenu);
        strncpy(arrayMenues[i].descripcion,auxMenu,51);
        if(i)
        {
             arrayMenues[i].id = arrayMenues[i-1].id + 1;

        }
        else
        {
            arrayMenues[i].id = 1;

        }
        getNumber("Ingrese el precio del menu: ","precio incorrecto: ",1,1000,1,5,auxMenu);
        arrayMenues[i].precio = atoi(auxMenu);
        printf("\nALTA EXITOSA");
    }
    else
    {
        printf("no hay espacio");
    }
}

/**
  *\brief Modifica un dato de array Menues, segun la opcion correspondiente. Trabaja con un menu de opciones.
  *\param El array menues, la cantidad de menues maxima, la opcion ingresada y la id que desea modificar.
**/
void modificarMenues(eMenues arrayMenues[],int cantidadElementos)
{

    int i;
    int id;
    char auxMenu[51];
    char auxOpcion[15];
    char auxId[15];
    int opcion;

    mostrarMenues(arrayMenues,cantidadElementos);
    getNumber("\n1:MOD_DESCRIPCION\n2:MOD_PRECIO\n3:SALIR\n","opcion incorrecto",1,3,1,2,auxOpcion);
    getNumber("\nQue id desea modificar: ","caracter incorrecto",1,cantidadElementos,1,3,auxId);

    id = atoi(auxId);
    opcion = atoi(auxOpcion);
    for(i=0; i<cantidadElementos; i++)
    {
        if(id == arrayMenues[i].id)
        {

            switch(opcion)
            {
            case 1:
                getName("ingrese nuevo Menu: ","caracter incorrecto",1,51,auxMenu);
                strncpy(arrayMenues[i].descripcion,auxMenu,51);
                printf("\nmodificacion exitosa");
                break;
            case 2:
                getNumber("ingrese el nuevo precio: ","caracter incorrecto",1,1000,1,5,auxMenu);
                arrayMenues[i].precio = atoi(auxMenu);
                printf("\nmodificacion exitosa");
                break;
            }
        }

    }
}
/**
  *\brief Hace una baja logica dentro de array Menues, si la id del menu existe, carga la id con 0.
  *\param el array empleados y la cantidad de elementos del array.
**/
void borrarMenues(eMenues arrayMenues[], int cantidadElementos)
{

    int i;
    int loEncontro = FALSE;
    char auxMenu[20];
    int id;
    getNumber("Ingrese la id del menu a dar de baja: ","caracter incorrecto",1,cantidadElementos,1,5,auxMenu);
    id = atoi(auxMenu);
    for(i=0; i<cantidadElementos; i++)
    {
        if(id == arrayMenues[i].id)
        {

            arrayMenues[i].id = 0;
            printf("Baja exitosa");
            loEncontro = TRUE;
            break;
        }

    }
    if(loEncontro==FALSE)
    {
        printf("El dato no existe");
    }

}
//-------------------ABM DE ALMUERZOS----------------------------
/**
  *\brief Da el alta a un almuerzo enlasado a un empleado con la id del almuerzo y el legajo del empleado.
  *\param las estructuras y la estructura que enlaza a las dos,la cantidad de elementos y el legajo del empleado.
**/
void cargarAlmuerzo(eEmpleado_Menu idEmpleadoMenu[],eEmpleados arrayEmpleados[],eMenues arrayMenues[],
                     int cantidadElementos,int legajo,int maxCaracter)
{
    char auxAlmuerzo[51];
    int i,j;
    char dia[10];
    char mes[10];
    char anio[10];
    i = buscarPrimerOcurrencia3(arrayEmpleados,QTY_EMPLEADOS,legajo);
    if(i != -1)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(idEmpleadoMenu[i].idMenu == -1)
            {
            getNumber("Ingrese el menu: ","caracter incorrecto",1,cantidadElementos,1,cantidadElementos,auxAlmuerzo);
            getNumber("dia: ","caracter incorrecto",1,31,1,3,dia);
            getNumber("mes: ","caracter incorrecto",1,12,1,3,mes);
            getNumber("anio: ","caracter incorrecto",2000,2019,1,6,anio);
            arrayEmpleados[i].idMenu = atoi(auxAlmuerzo);
            idEmpleadoMenu[i].idMenu = atoi(auxAlmuerzo);
            idEmpleadoMenu[i].legajoEmpleado = legajo;
            idEmpleadoMenu[i].dia = atoi(dia);
            idEmpleadoMenu[i].mes  = atoi(mes);
            idEmpleadoMenu[i].anio = atoi(anio);
            printf("\nLos datos han sido cargados correctamente");
            break;
            }
        }

    }
    else
    {
        printf("el dato no existe");
    }
}
/**
  *\brief Elimina un almuerzo cargado en el sistema.
  *\param el array donde se cargo el almuerzo y la cantidad de elementos.
**/
void borrarAlmuerzo(eEmpleado_Menu idEmpleadoMenu[], int cantidadElementos)
{

    int i;
    int loEncontro = FALSE;
    char auxMenu[20];
    int id;
    getNumber("Ingrese la id del almuerzo a eliminar: ","caracter incorrecto",1,cantidadElementos,1,5,auxMenu);
    id = atoi(auxMenu);
    for(i=0; i<cantidadElementos; i++)
    {
        if(id == idEmpleadoMenu[i].idMenu)
        {

            idEmpleadoMenu[i].idMenu = 0;
            idEmpleadoMenu[i].legajoEmpleado = 0;
            printf("se a borrado el almuerzo");
            loEncontro = TRUE;
            break;
        }

    }
    if(loEncontro==FALSE)
    {
        printf("El dato no existe");
    }

}

void mostrarAlmuerzos(eEmpleados arrayEmpleado[],eMenues arrayMenues[],eEmpleado_Menu idEmpleadoMenu[],int cantidad)
{
    int i,j;
    for(i=0;i<cantidad;i++)
    {
        if(idEmpleadoMenu[i].idMenu != -1)
        {

            printf("\nlegajo: %d %s %s %s %d",idEmpleadoMenu[i].legajoEmpleado,arrayEmpleado[idEmpleadoMenu[i].legajoEmpleado-1].nombre,
                        arrayEmpleado[idEmpleadoMenu[i].legajoEmpleado-1].apellido,
                        arrayMenues[idEmpleadoMenu[i].idMenu-1].descripcion,
                        arrayMenues[idEmpleadoMenu[i].idMenu-1].precio);

            printf("\ndia: %d mes: %d anio: %d",idEmpleadoMenu[i].dia,idEmpleadoMenu[i].mes,idEmpleadoMenu[i].anio);


        }
    }
}








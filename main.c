#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "imput.h"
#include "ordenamiento.h"

#define QTY_EMPLEADOS 5
#define QTY_MENUES 5
#define QTY_SECTORES 5

int main()
{
    eEmpleados arrayEmpleados[QTY_EMPLEADOS], auxEmpleados;
    eMenues arrayMenues[QTY_MENUES],auxMenues;
    eSector arraySector[QTY_SECTORES];
    eEmpleado_Menu idEmpleadoMenu[QTY_EMPLEADOS];
    eEmpleado_Sector idEmpleadoSector[QTY_EMPLEADOS];
    int i;
    int opcion;
    int opcion2;
    char auxMemoria[15];
    char auxOpcion[15];
    int auxLegajo = 0;
    inicializarArrayEmpleados(arrayEmpleados,QTY_EMPLEADOS);
    inicializarArrayMenues(arrayMenues,QTY_MENUES);

    hardcodearDatosSector(arraySector);
    hardcodearDatosEmpleados(arrayEmpleados);
    hardcodearDatosMenues(arrayMenues);

    for(i=0;i<QTY_EMPLEADOS;i++)
    {
        idEmpleadoMenu[i].idMenu = -1;
    }

    do
    {

      getNumber("\n1:EMPLEADOS\n2:ALMUERZOS\n3:MENUES\n4:SECTOR\n5:SALIR\n","opcion incorrecta",1,5,1,2,auxOpcion);
      opcion = atoi(auxOpcion);
      switch(opcion)
      {
        case 1:
        {
            menu(&opcion2);
            switch(opcion2)
            {
            case 1:
               cargarEmpleado(arrayEmpleados,arraySector,idEmpleadoSector,QTY_EMPLEADOS,-1,51,auxLegajo);
               auxLegajo++;
               break;


            case 2:
                mostrarListaEmpleados(arrayEmpleados,arraySector,QTY_EMPLEADOS,-1);
                borrarEmpleado(arrayEmpleados,QTY_EMPLEADOS);
                break;
            case 3:
                mostrarListaEmpleados(arrayEmpleados,arraySector,QTY_EMPLEADOS,-1);
                getNumber("Que legajo desea modificar? ","caracter incorrecto",1,QTY_EMPLEADOS,1,2,auxMemoria);
                getNumber("1:MOD_NOMBRE Y APELLIDO\n2:SALARIO\n3:SECTOR\n4:SALIR\n","opcion incorrecta",
                          1,4,1,2,auxOpcion);
                opcion2 = atoi(auxOpcion);
                modificarEmpleado(arrayEmpleados,arraySector,QTY_EMPLEADOS,opcion2,atoi(auxMemoria));
                break;
            }
        }
        case 2:
            {
                mostrarMenues(arrayMenues,QTY_MENUES);
                menu3(&opcion2);
                switch(opcion2)
                {
                case 1:
                    mostrarListaEmpleados(arrayEmpleados,arraySector,QTY_EMPLEADOS,-1);
                    getNumber("legajo de almuerzo","caracter incorrecto",1,QTY_EMPLEADOS,1,5,auxMemoria);
                    cargarAlmuerzo(idEmpleadoMenu,arrayEmpleados,arrayMenues,QTY_EMPLEADOS,atoi(auxMemoria),51);
                    break;
                case 2:
                    mostrarAlmuerzos(arrayEmpleados,arrayMenues,idEmpleadoMenu,QTY_EMPLEADOS);
                    break;

                }

            }
            case 3:
                menu2(opcion2);
                switch(opcion2)
                {
                    case 1:
                        cargarMenu(arrayMenues,QTY_MENUES,-1,51);
                        break;

                }






      }
    }while(opcion != 5);


}

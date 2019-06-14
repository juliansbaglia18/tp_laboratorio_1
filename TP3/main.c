#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

/** \brief muestra el menu y se selecciona la opcion
 *
 * \return la opcion elegida
 *
 */
char menu(void);

int main()
{
    char option[3];
    int validateController;
    int validateLoadText = 0;
    int validateLoadBinary = 0;
    int validateAdd;
    int validateEdit;
    int validateRemove;
    int validateList;
    int validateSort;
    int validateSave;
    int flagSave = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menu())
        {

        case '1':
            if(validateLoadText == 0)
            {
                validateController = controller_loadFromText("data.csv",listaEmpleados);
                if(validateController == 1)
                {
                    printf("Se cargo el archivo.\n");
                }
                else
                {
                    printf("No se cargo el archivo.\n");
                }
                validateLoadText = 1;
            }
            else if(validateLoadText == 1)
            {
                printf("El archivo esta cargado\n");
            }

            system("pause");
            break;
        case '2':
            if (validateLoadBinary == 0)
            {
                validateController = controller_loadFromBinary("data.bin",listaEmpleados);
                if(validateController == 1)
                {
                    printf("Se cargo el archivo.\n");
                }
                else
                {
                    printf("No se cargo el archivo.\n");
                }
                validateLoadBinary = 1;
            }
            else if(validateLoadBinary == 1)
            {
                printf("El archivo está cargado\n");
            }

            system("pause");
            break;
        case '3':
            validateAdd = controller_addEmployee(listaEmpleados);
            if(validateAdd == 0)
            {
                printf("Se cargo el empleado.\n");
                flagSave = 1;

            }
            else
            {
                printf("No se cargo el empleado.\n");
            }
            system("pause");
            break;
        case '4':
            validateEdit = controller_editEmployee(listaEmpleados);
            if(validateEdit == 0)
            {
                printf("Se modifico el empleado.\n");
            }
            else
            {
                printf("No se modifico el empleado.\n");
                flagSave = 1;

            }
            system("pause");
            break;
        case '5':
            validateRemove = controller_removeEmployee(listaEmpleados);
            if(validateRemove == -1)//modificar
            {
                printf("No se encontro el ID.\n");
            }
            else if(validateRemove == -2)
            {
                printf("Se elimino el empleado.\n");
                flagSave = 1;
            }

            system("pause");
            break;
        case '6':
            validateList = controller_ListEmployee(listaEmpleados);
            if(validateList == 0)
            {
                printf("Se cargo la lista.\n");
            }
            else
            {
                printf("No se cargo la lista.\n");
            }

            system("pause");
            break;
        case '7':
            validateSort = controller_sortEmployee(listaEmpleados);
            if(validateSort == 0)
            {
                printf("Se ordeno la lista.\n");
            }
            else
            {
                printf("No se ordeno la lista.\n");
            }

            system("pause");
            break;
        case '8':
            validateSave = controller_saveAsText("data.csv", listaEmpleados);
            if(validateSave == -1)
            {
                printf("Se guardo el archivo.\n");
                flagSave = 0;
            }
            else
            {
                printf("No se guardo el archivo.\n");
            }

            system("pause");
            break;
        case '9':
            validateSave = controller_saveAsBinary("data.bin", listaEmpleados);
            if(validateSave == -1)
            {
                printf("Se guardo el archivo.\n");
                flagSave = 0;
            }
            else
            {
                printf("No se guardo el archivo");
            }

            system("pause");
            break;

        case 27:
            if(flagSave == 1)
            {
                printf("Seguro que desea salir sin guardar?(s/n)");
                option[1] = tolower(getch());
                while(option[1] != 's' && option[1] != 'n')
                {
                    printf("\nOpcion invalida. Vuelva a ingresar: ");
                    option[1] = tolower(getche());
                }
                if(option[1] == 's')
                {
                    strcpy(option,"Si");
                    printf("\n%s",option);

                }
                else
                {
                    strcpy(option,"No");
                    printf("\n%s",option);
                }
            }
            else
            {

                printf("Seguro que desea salir?(s/n) \n");
                option[1] = tolower(getch());
                while(option[1] != 's' && option[1] != 'n')
                {
                    printf("\nOpcion invalida. Vuelva a ingresar: ");
                    option[1] = tolower(getch());
                }
                if(option[1] == 's')
                {
                    strcpy(option,"Si");
                    printf("%s",option);
                    printf("\n");
                }
                else
                {
                    strcpy(option,"No\n");
                    printf("%s",option);
                    printf("\n");
                    system("pause");
                }
            }
            break;/** \brief Ordena la lista de empleados por horas trabajadas.
 *
 * \param thisUno void* objeto generico uno
 * \param thisDos void* objeto generico dos
 * \return int -  -1 si funciona correctamente.
 *             -  0 si no funciona correctamente.
 */

        default:
            printf("ERROR. Opcion invalida\n");
            system("pause");
            break;
        }
    }
    while(strcmp(option,"Si")!= 0);
    return 0;
}

char menu()
{
    char c;

    system("cls");
    printf("\t\tMENU\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3.Alta de empleado.\n4.Modificar datos de empleado.\n5.Baja de empleado.\n6.Listar empleados.\n");
    printf("7.Ordenar empleados.\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9.Guardar los datos de los empleados en el archivo data.csv (modo binario).\nESC.Salir.\n");
    printf("\nElija una opcion: ");
    c=getche();

    while(c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != 27)
    {
        printf("\nERROR. Opcion invalida. Elija una opcion: ");
        c=getche();
    }
    system("cls");

    return c;
}

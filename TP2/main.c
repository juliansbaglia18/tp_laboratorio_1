#include <stdio.h>
#include <stdlib.h>
#include "sbaglia.h"
#include "ArrayEmployees.h"
#define MAX_EMPLOYEES 1000


int main()
{
    char option;
    Employee empleados[MAX_EMPLOYEES];
    char auxName[51];
    char auxLastName[51];
    int auxId = 0;
    int auxSector;
    float auxSalary;
    int theId;
    int index;
    int flag = 0;


    initEmployees(empleados, MAX_EMPLOYEES);

    do
    {
        option = getChar("\t\tMENU\n\t1)Alta de empleados.\n\t2)Modificar empleados.\n\t3)Baja de empleados.\n\t4)Informar.\n\t0)Salir.\nSeleccione la opcion deseada: ");
        switch (option)
        {
        case '1':
            flag = 1;
            auxId++;
            while(getStringLetras("Indique el nombre: ", auxName)!= 1)
            {
                printf("Nombre invalido. ");
            }

            while(getStringLetras("Indique el apellido: ", auxLastName)!= 1)
            {
                printf("Apellido invalido. ");
            }
            auxSector = getInt("Indique el sector: ");
            auxSalary = getFloat("Indique el salario: ");
            addEmployee(empleados, MAX_EMPLOYEES, auxId, auxName, auxLastName,auxSalary, auxSector);
            printEmployees(empleados, MAX_EMPLOYEES);
            system("pause");
            system("cls");
            break;

        case '2':
            if(flag == 0)
            {
                printf("\nSe debe dar de alta al menos a un empleado.\n");
                system("pause");
                system("cls");
                break;
            }
            theId = getInt("Indique el id del empleado que desea modificar: ");

            index = findEmployeeById(empleados, MAX_EMPLOYEES, theId);
            if(index == -1)
            {
                printf("Id invalido.");
                break;
            }
            while(getStringLetras("Indique el nuevo nombre: ", auxName)!= 1)
            {
                printf("Nombre invalido. ");
            }

            while(getStringLetras("Indique el nuevo apellido: ", auxLastName)!= 1)
            {
                printf("Apellido invalido. ");
            }
            auxSector = getInt("Indique el nuevo sector: ");
            auxSalary = getFloat("Indique el nuevo salario: ");

            strcpy(empleados[index].name, auxName);
            strcpy(empleados[index].lastName, auxLastName);
            empleados[index].salary = auxSalary;
            empleados[index].sector = auxSector;
            printEmployees(empleados, MAX_EMPLOYEES);

            system("pause");
            system("cls");
            break;

        case '3':
            if(flag == 0)
            {
                printf("\nSe debe dar de alta al menos a un empleado.\n");
                system("pause");
                system("cls");
                break;
            }
            theId = getInt("Indique el id del empleado que desea dar de baja: ");

            if(removeEmployee(empleados, MAX_EMPLOYEES, theId) == -1)
            {
                printf("Error al dar de baja.\n");
            }
            printEmployees(empleados, MAX_EMPLOYEES);

            system("pause");
            system("cls");
            break;

        case '4':
            if(flag == 0)
            {
                printf("\nSe debe dar de alta al menos a un empleado.\n");
                system("pause");
                system("cls");
                break;
            }
            option = getChar("\t\t\t1.Ordenar por apellidos.\n\t\t\t2.Ordenar por sector.\nSeleccione la opcion deseada: ");
            switch(option)
            {
            case '1':
                option = getChar("\t\t\t\t1.Ordenar de manera ascendente.\n\t\t\t\t2.Ordenar de manera descendente.\nSeleccione la opcion deseada: ");
                switch(option)//por apellidos
                {
                case '1':
                    sortEmployees(empleados, MAX_EMPLOYEES, 1);
                    printf("Se ordenaron los empleados por apellido de forma ascendente.\n");
                    break;
                case '2':
                    sortEmployees(empleados, MAX_EMPLOYEES, 0);
                    printf("Se ordenaron los empleados por apellido de forma descendente.\n");
                    break;
                default:
                    printf("Error. Opcion invalida.\n");
                    break;
                }
                break;

            case '2':
                option = getChar("\t\t\t\t1.Ordenar de manera ascendente.\n\t\t\t\t2.Ordenar de manera descendente.\nSeleccione la opcion deseada: ");
                switch(option)//por sector
                {
                case '1':
                    sortEmployees(empleados, MAX_EMPLOYEES, 3);
                    printf("Se ordenaron los empleados por sector de forma ascendente.\n");
                    break;
                case '2':
                    sortEmployees(empleados, MAX_EMPLOYEES, 2);
                    printf("Se ordenaron los empleados por sector de forma descendente.\n");
                    break;
                default:
                    printf("Error. Opcion invalida.\n");
                    break;
                }
                break;

            default:
                printf("Error. Opcion invalida.\n");
                break;
            }
            printEmployees(empleados, MAX_EMPLOYEES);
            system("pause");
            system("cls");
            break;

        case '0':
            break;

        default:
            printf("Error. Opcion invalida.\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != '0');

    return 0;
}

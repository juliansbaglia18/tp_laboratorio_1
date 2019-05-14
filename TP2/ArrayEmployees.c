//lamia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sbaglia.h"
#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    int i;
        for(i=0; i<len; i++)
        {
            list[i].isEmpty= 0;
        }

    return 0;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int free;

    free = freePosition(list, len);
    if(free == -1)
    {
        return -1;
    }
    else
    {
        list[free].id = id;
        strcpy(list[free].name,name);
        strcpy(list[free].lastName,lastName);
        list[free].salary = salary;
        list[free].sector = sector;
        list[free].isEmpty = 1;

        return 0;
    }
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    for(i=0; i < len; i++)
    {
        if(list[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

/** \brief Remove a Employee by Id
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int index;
    index = findEmployeeById(list, len, id);
    if(index == -1)
    {
        return -1;
    }
    else
    {
        list[index].isEmpty = 0;
        printf("Se dio de baja a %s %s\n",list[index].lastName, list[index].name);
    }
    return 0;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmpleados;
    int i;
    int j;
    if(order == 1)
    {
        for(i = 0; i < len; i++)
        {
            for(j = 0; j < len; j++)
            {
                if(strcmp(list[j].lastName, list[i].lastName) < 0)
                {
                    auxEmpleados = list[i];
                    list[i]=list[j];
                    list[j]=auxEmpleados;
                }
            }
        }
    }
    else if(order ==  0)
    {
        for(i = 0; i < len; i++)
        {
            for(j = 0; j < len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName) > 0)
                {
                    auxEmpleados = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleados;
                }
            }
        }
    }
    else if(order == 2)
    {
        for(i = 0; i < len; i++)
        {
            for(j = 0; j < len; j++)
            {
                if(list[j].sector < list[i].sector)
                {
                    auxEmpleados = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleados;
                }
            }
        }
    }
    else if(order == 3)
    {
        for(i = 0; i < len; i++)
        {
            for(j = 0; j < len; j++)
            {
                if(list[j].sector > list[i].sector)
                {
                    auxEmpleados = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleados;
                }
            }
        }
    }
    return 0;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length)
{
    int i;
    printf("Id\tApellido\tNombre\tSalario\tSector\n");
    for(i = 0; i < length; i++)
    {
        if(list[i].isEmpty==1)
        {
            printf("%d\t%-s\t\t%-s\t%-.2f\t%-d\n",list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
        }
    }
    return 0;
}

/** \brief busca la primer posicion libre la estructura
 *
 * \param list estructura en la cual buscar
 * \param length largo de la estructura
 * \return retorna el indice o -1 si hay un error
 *
 */

int freePosition(Employee* list, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        if(list[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}





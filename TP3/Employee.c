#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "sbaglia.h"

/** \brief Crea el id de un empleado.
 *
 * \param this Employee* empleado.
 * \param id int Crea el id
 * \return int 0 si funciona correctamente y 1 si no funciona.
 */
int employee_setId(Employee* this,int id)
{

    int retorno = -1;

    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Crea el nombre de un empleado.
 *
 * \param this Employee* empleado.
 * \param nombre char* Crea el nombre
 * \return int 0 si funciona correctamente y -1 si no funciona correctamente.
 */
int employee_setNombre(Employee* this,char* nombre)
{

    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }

    return retorno;
}

/** \brief Crea las horas trabajadas de un empleado.
 *
 * \param this Employee* empleado.
 * \param horasTrabajadas int Crea las horas trabajadas
 * \return int 0 si funciona correctamente y -1 si no funciona correctamente.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int retorno = -1;

    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Crea el sueldo de un empleado.
 *
 * \param this Employee* empleado.
 * \param sueldo int Crea el sueldo
 * \return int 0 si funciona correctamente y -1 si no funciona correctamente.
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->sueldo = sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Construye un nuevo empleado.
 *
 * \param  void
 * \return NULL si no hay memoria y Employee* si funciona.
 */
Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*)malloc(sizeof(Employee));
    if (newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }
    return newEmployee;
}

/** \brief Carga los campos con datos.
 *
 * \param idStr char* es el id
 * \param nombreStr char* es el nombre
 * \param horasTrabajadasStr char* es el sueldo
 * \param sueldoStr char* es las horas trabajadas
 * \return NULL si no hay memoria y Employee* si funciona.
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();
    int idAux;
    int horasAux;
    int sueldoAux;

    idAux = atoi(idStr);
    horasAux = atoi(horasTrabajadasStr);
    sueldoAux = atoi(sueldoStr);
    if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setNombre(newEmployee, nombreStr);
        employee_setId(newEmployee, idAux);
        employee_setHorasTrabajadas(newEmployee, horasAux);
        employee_setSueldo(newEmployee, sueldoAux);
    }

    return newEmployee;
}

/** \brief Ordena la lista de empleados.
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int 0 si funciona correctamente y -1 si no funciona correctamente.
 */
int employee_sortEmployee(LinkedList* pArrayListEmployee)
{
    char option;
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("\t1.Ordenar lista por nombre\n\t2.Ordenar lista por horas trabajadas\n");
        printf("\t3.Ordenar lista por sueldo\n\tESC.Volver al menu.\n\nElija una opcion: ");
        option = getche();
        while(option != '1' && option != '2' && option != '3' && option != 27)
        {
            printf("\nERROR. Opcion invalida. Elija una opcion: ");
            option = getch();
        }
        switch(option)
        {
            case '1':
            printf("\n\nOrdenando por nombre...\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorNombre,1);
            break;

            case '2':
            printf("\n\nOrdenando por horas trabajadas...\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorHoras,1);
            break;

            case '3':
            printf("\n\nOrdenando por sueldo...\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorSueldo,1);
            break;

            case 27:
            printf("\n\nVolver.\n");
            system("pause");
            break;

            default:
            printf("ERROR. Opcion invalida.\n");
            system("pause");
            break;
        }
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el id de un empleado.
 *
 * \param this Employee* empleado.
 * \param id int* obtiene el id
 * \return int 0 si funciona correctamente y -1 si no funciona correctamente.
 */
int employee_getId(Employee* this, int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
}

/** \brief Obtiene el nombre de un empleado.
 *
 * \param this Employee* empleado.
 * \param nombre char* Obtiene el nombre
 * \return int 0 si funciona correctamente y -1 si no funciona correctamente.
 */
int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL  && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param this Employee* empleado.
 * \param horasTrabajadas int* Obtiene las horas trabajadas
 * \return int 0 si funciona correctamente y -1 si no funciona correctamente.
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el sueldo de un empleado.
 *
 * \param this Employee* empleado.
 * \param sueldo int* Obtiene el sueldo
 * \return int 0 si funciona correctamente y -1 si no funciona correctamente.
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordena la lista de empleados por nombre.
 *
 * \param thisUno void* objeto generico uno
 * \param thisDos void* objeto generico dos
 * \return int -1 si funciona correctamente y 0 si no funciona correctamente.
 */
int employee_ordenarPorNombre(void* thisUno, void* thisDos)
{
    char nombreUno[50];
    char nombreDos[50];
    int retorno = 0;

    employee_getNombre(thisUno, nombreUno);
    employee_getNombre(thisDos, nombreDos);

    if(strcmp(nombreUno, nombreDos) < 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreUno, nombreDos) > 0)
    {
        retorno = -1;
    }
    return retorno;
}

/** \brief Ordena la lista de empleados por horas trabajadas.
 *
 * \param thisUno void* objeto generico uno
 * \param thisDos void* objeto generico dos
 * \return int -1 si funciona correctamente y 0 si no funciona correctamente.
 */
int employee_ordenarPorHoras(void* thisUno, void* thisDos)
{
    int horasUno;
    int horasDos;
    int retorno = 0;

    employee_getHorasTrabajadas(thisUno, &horasUno);
    employee_getHorasTrabajadas(thisDos, &horasDos);

    if(horasUno > horasDos)
    {
        retorno = 1;
    }
    else if(horasUno < horasDos)
    {
        retorno = -1;
    }

    return retorno;
}

/** \brief Ordena la lista de empleados por sueldo.
 *
 * \param thisUno void* objeto generico uno
 * \param thisDos void* objeto generico dos
 * \return int -1 si funciona correctamente y 0 si no funciona correctamente.
 */
int employee_ordenarPorSueldo(void* thisUno, void* thisDos)
{
    int sueldoUno;
    int sueldoDos;
    int retorno = 0;

    employee_getSueldo(thisUno, &sueldoUno);
    employee_getSueldo(thisDos, &sueldoDos);

    if(sueldoUno > sueldoDos)
    {
        retorno = 1;
    }
    else if(sueldoUno < sueldoDos)
    {
        retorno = -1;
    }

    return retorno;
}

/** \brief Elimina un empleado.
 *
 * \param this Employee* empleado a eliminar.
 * \return void
 */
void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

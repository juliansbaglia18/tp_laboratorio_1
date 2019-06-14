#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* pEmployee;

    char idAux[100];
    char nombreAux[100];
    char horasTrabajadasAux[100];
    char sueldoAux[100];

    int retorno = -1;
    int flag = 1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
                flag = 0;
            }

            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            pEmployee = employee_newParametros(idAux, nombreAux, horasTrabajadasAux, sueldoAux);

            if(pEmployee != NULL)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* pEmployee;
    int retorno = -1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            pEmployee = employee_new();
            fread(pEmployee,sizeof(Employee),1,pFile);
            ll_add(pArrayListEmployee,pEmployee);
        }
        retorno = 0;
    }
    return retorno;
}

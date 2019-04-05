#ifndef MILIBRERIA_H_INCLUDED
#define MILIBRERIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int sumar(float primerNum, float segundoNum)
/**\brief sumar los dos numeros ingresados.
 *\param primerNum int (primer numero ingresado).
 *\param segundoNum int (segundo numero ingresado).
 *\return int el resultado es retornado.
 */
{
    int resultado = primerNum + segundoNum;
    return resultado;
}
int restar(float primerNum, float segundoNum)
/**\brief restar los dos numeros ingresados.
 *\param primerNum int (primer numero ingresado).
 *\param segundoNum int (segundo numero ingresado).
 *\return int el resultado es retornado.
 */
{
    int resultado = primerNum - segundoNum;
    return resultado;
}
float dividir(float primerNum, float segundoNum)
/**\brief dividir los dos numeros ingresados.
 *\param primerNum int (primer numero ingresado).
 *\param segundoNum int (segundo numero ingresado).
 *\return int el resultado es retornado
 */
{
    float resultado = primerNum / segundoNum;
    return resultado;
}
int multiplicar(float primerNum, float segundoNum)
/**\brief multiplicar los dos numeros ingresados.
 *\param primerNum int (primer numero ingresado).
 *\param segundoNum int (segundo numero ingresado).
 *\return int el resultado es retornado.
 */
{
    int resultado = primerNum * segundoNum;
    return resultado;
}
int factorial1(float primerNum)
/**\brief factorial del primer numero ingresado.
 *\param primerNum int (primer numero ingresado).
 *\return int el resultado es retornado.
 */
{
    int i;
    int resultado = 1;
    for(i = 1; i <= primerNum; i++)
    {
        resultado *= i;
    }
    return resultado;
}
int factorial2(float segundoNum)
/**\brief factorial del segundo numero ingresado.
 *\param segundoNum int (segundo numero ingresado).
 *\return int el resultado es retornado.
 */
{
    int i;
    int resultado = 1;
    for(i = 1; i <= segundoNum; i++)
    {
        resultado *= i;
    }
    return resultado;
}

#endif // MILIBRERIA_H_INCLUDED

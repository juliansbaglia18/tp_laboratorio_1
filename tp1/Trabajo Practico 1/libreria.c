#include <stdio.h>

int sumar(float primerNum, float segundoNum)
{
    int resultado = primerNum + segundoNum;
    return resultado;
}
int restar(float primerNum, float segundoNum)
{
    int resultado = primerNum - segundoNum;
    return resultado;
}
float dividir(float primerNum, float segundoNum)
{
    float resultado = primerNum / segundoNum;
    return resultado;
}
int multiplicar(float primerNum, float segundoNum)
{
    int resultado = primerNum * segundoNum;
    return resultado;
}
int factorial1(float primerNum)
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
{
    int i;
    int resultado = 1;
    for(i = 1; i <= segundoNum; i++)
    {
        resultado *= i;
    }
    return resultado;
}

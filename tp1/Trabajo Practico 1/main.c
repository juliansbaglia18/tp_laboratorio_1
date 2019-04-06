#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main()
{
    int rtaA = 0;
    int rtaB = 0;
    float rtaC = 0;
    int rtaD = 0;
    int rtaE1 = 0;
    int rtaE2 = 0;
    int opcion;
    float primerNum = 0;
    float segundoNum = 0;

    printf("\t\tCalculadora TP1\n");
    printf("\nOpciones:\n\t1)Ingresar primer operando.\n\t2)Ingresar segundo operando.\n\t3)Calcular todas las opeaciones.\n\t4)Informar resultados.\n\t5)Salir.");

    do{
    printf("\nIndique el numero de la opcion que desea: ");
    fflush(stdin);
    scanf("%d", &opcion);
    fflush(stdin);

    while(opcion<1 || opcion>5)
    {//Validacion de opciones
        printf("\nERROR. Opcion %d invalida!!\nIndique el numero de la opcion que desea: ",opcion);
        scanf("%d", &opcion);
    }

    switch (opcion)
    {
    case 1:
        printf("\t1)Indique valor del primer numero: ");
        scanf("%f",&primerNum);
        fflush(stdin);
        printf("\n\tA = %.2f\n\tB = %.2f",primerNum,segundoNum);
        break;
    case 2:
        printf("\t2)Indique valor del segundo numero: ");
        scanf("%f",&segundoNum);
        fflush(stdin);
        printf("\n\tA = %.2f\n\tB = %.2f",primerNum,segundoNum);

        break;
    case 3:
        rtaA = sumar(primerNum, segundoNum);
        rtaB = restar(primerNum, segundoNum);
        rtaC = dividir(primerNum, segundoNum);
        rtaD = multiplicar(primerNum, segundoNum);
        rtaE1 = factorial1(primerNum);
        rtaE2 = factorial2(segundoNum);
        printf("\n\t3) Operaciones realizadas.");
        break;
    case 4:
        printf("\n\t4)a)El resultado de A+B es: %d", rtaA);
        printf("\n\t  b)El resultado de A-B es: %d", rtaB);
        if(segundoNum != 0)
        {
            printf("\n\t  c)El resultado de A/B es: %.2f", rtaC);
        }else
        {
            printf("\n\t  c)No es posible dividir por cero.");
        }
        printf("\n\t  d)El resultado de A*B es: %d", rtaD);
        if(primerNum>=0)
        {
            printf("\n\t  e)El factorial de A es: %d y", rtaE1);
        }else
        {
            printf("\n\t  e)No se puede realizar el factorial del numero negativo en A y");
        }
        if(segundoNum>=0)
        {
            printf(" el factorial de B es: %d.", rtaE2);
        }else
        {
            printf(" no se puede realizar el factorial del numero negativo en B");
        }

        break;
    }

    }while (opcion!=5);
    printf("\n\t5)Salir.\nFin.\n");
    return 0;
}


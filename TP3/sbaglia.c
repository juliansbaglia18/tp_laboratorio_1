#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sbaglia.h"

/**
 * \brief Solicita un número al usuario y lo devuelve en una variable
 * \param mensaje Es el mensaje a ser mostrado
 * \param auxiliar Es donde se guardara el entero
 * \return void
 *
 */
void getInt(char mensaje[], int* auxiliar)
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",auxiliar);
}

/**
 * \brief Solicita un número al usuario y lo devuelve en una variable
 * \param mensaje Es el mensaje a ser mostrado
 * \param auxiliar Es donde se guardara el flotante
 * \return El número ingresado por el usuario
 *
 */
void getFloat(char mensaje[], float* auxiliar)
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",auxiliar);
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
void getChar(char mensaje[], char* auxiliar)
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",auxiliar);
}

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}



/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    //scanf ("%s", input);
    gets(input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief Ordenar un array de numeros enteros
 *
 * \param dato el array a ordenar
 * \param tam el tamaño del array
 * \param lado 0 para ordenar de menor a mayor y 1 para mayor a menor
 * \return 0 si no hay problemas o 1 si hay error
 *
 */
int orderInt(char mensaje[], int* dato, int tam, int lado)
{
    printf("%s\n", mensaje);

    int aux;
    int i;
    int j;

    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            if(lado == 0)
            {
                if(dato[j] > dato[i])
                {
                    aux = dato[i];
                    dato[i]=dato[j];
                    dato[j]=aux;
                }
            }
            else if(lado == 1)
            {

                if(dato[j] < dato[i])
                {
                    aux = dato[i];
                    dato[i]=dato[j];
                    dato[j]=aux;
                }
            }
            else
                return 1;
        }
    }
    return 0;
}

/** \brief calcula el maximo o el minimo de un array
 *
 * \param array el array de donde se sacaran los datos
 * \param tam el tamaño del array
 * \param option 0 si se quiere calcular el minimo o 1 si se quiere cacular el maximo
 * \return devuelve el minimo o maximo
 *
 */
int calcularMaxOMin(int* array, int tam, int option)
{
    int i;
    int dato;
    dato = array[0];

    for (i=0; i < tam; i++)
    {
        if(option == 0)
        {
            if (array[i] < dato)
            {
                dato = array[i];
            }
        }
        else if(option == 1)
        {
            if (array[i] > dato)
            {
                dato = array[i];
            }
        }
    }
    return dato;
}

/** \brief Convierte un string a mayusculas
 *
 * \param caracter string a convertir
 * \return void
 *
 */

void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0;i<largo;i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}

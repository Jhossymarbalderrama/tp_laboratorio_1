
#include <stdio.h>
#include <stdlib.h>

#include "ControlesValidaciones.h"


/** \brief Verificacion de que haya ingresado por lo menos 1 valor en los operadores 1 o 2 (Opciones del menu 1 o 2).
 *
 * \param operador1 float
 * \param operador2 float
 * \param tSuma float
 * \param tResta float
 * \param tDivision float
 * \param tMultipl float
 * \param tFactoA int
 * \param tFactoB int
 * \param flag int
 * \param flag2 int
 * \return void
 *
 */
void resultadosControles(float operador1,float operador2,float tSuma,float tResta,float tDivision,float tMultipl,long long int tFactoA,long long int tFactoB,int flag,int flag2){
        if(flag == 1){
                if(flag2 == 1){
                    resultadosView(operador1,operador2,tSuma,tResta,tDivision,tMultipl,tFactoA,tFactoB);
                }else{
                    printf("Error. Debe Calcular las operaciones Primero.\n");
                    system("pause");
                }
        }else{
            printf("Error. Debe Ingresar un valor al Operador 1 o 2.\n");
            system("pause");
        }
}


/** \brief  Prints de Resultados y verificacion de errores de factorial / Division.
 *
 * \param operador1 float
 * \param operador2 float
 * \param tSuma float
 * \param tResta float
 * \param tDivision float
 * \param tMultipl float
 * \param tFactoA int
 * \param tFactoB int
 * \return void
 *
 */
void resultadosView(float operador1,float operador2,float tSuma,float tResta,float tDivision,float tMultipl,long long int tFactoA,long long int tFactoB)
{
    printf("   a. -El resultado de %.2f + %.2f es: %.2f \n",operador1,operador2,tSuma);
    printf("   b. -El resultado de %.2f - %.2f es: %.2f \n",operador1,operador2,tResta);
    if(operador2 == 0)
    {
        printf("   c. -No es Posible dividir por cero.\n");
    }
    else
    {
        printf("   c. -El resultado de %.2f / %.2f es: %.2f \n",operador1,operador2,tDivision);
    }
    printf("   d. -El resultado de %.2f * %.2f es: %.2f \n",operador1,operador2,tMultipl);
    if(tFactoA != -1)
    {
        printf("   e. -El resultado del Factorial de %.2f es: %lld",operador1,tFactoA);

    }
    else
    {
        printf("   e. -No se pudo sacar el Factorial de : %.2f",operador1);
    }
    if(tFactoB != -1)
    {
        printf(" y el Factorial de %.2f es: %lld \n",operador2,tFactoB);
    }
    else
    {
        printf(" y No se pudo sacar el Factorial de : %.2f\n",operador2);
    }
    system("pause");
}


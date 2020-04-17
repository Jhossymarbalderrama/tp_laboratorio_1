#include <stdio.h>
#include <stdlib.h>

#include "MenuPrincipal.h"
/** \brief Menu de Opciones Principales
 *
 * \return char
 */
int menu(float operatorA, float operatorB)
{
    int opcion;

    printf("-----     Calculadora     -----\n\n");
    printf("1 - Ingresar 1er Operador. (A = %.2f)\n",operatorA);
    printf("2 - Ingresar 2do Operador. (B = %.2f)\n",operatorB);
    printf("3 - Calcular todas las operaciones.\n");
    printf("      a. Calcular la Suma (%.2f + %.2f).\n",operatorA,operatorB);
    printf("      b. Calcular la Resta (%.2f - %.2f).\n",operatorA,operatorB);
    printf("      c. Calcular la Division (%.2f / %.2f).\n",operatorA,operatorB);
    printf("      d. Calcular la Multiplicacion (%.2f * %.2f).\n",operatorA,operatorB);
    printf("      e. Calcular la Factorial (%.2f !).\n\n",operatorA);
    printf("4 - Informar resultados.\n");
    printf("5 - Salir.\n\n");

    printf("Ingrese Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}


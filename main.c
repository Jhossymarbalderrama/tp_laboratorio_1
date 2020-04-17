#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#include "MenuPrincipal.h"
#include "FuncionesCalculos.h"
#include "ControlesValidaciones.h"

int main()
{
    char seguir = 'n';
    float operador1 = 0;
    float operador2 = 0;

    float totalSuma;
    float totalResta;
    float totalDivision;
    float totalMultiplicacion;
    long long int totalFactorialA = 0;
    long long int totalFactorialB = 0;

    int flag = 0;
    int flag2 = 0;

    do
    {
        switch(menu(operador1,operador2))
        {
        case 1:

            printf("\n----- Ingreso del Primer Operado -----\n\n");
            printf("Ingrese 1er Operador: ");
            scanf("%f",&operador1);
            flag = 1;
            break;
        case 2:
            printf("\n----- Ingreso del Segundo Operado -----\n\n");
            printf("Ingrese 2do Operador: ");
            scanf("%f",&operador2);
            flag = 1;
            break;
        case 3:
                printf("\n----- Calcular Operaciones -----\n\n");
            if(flag == 1){
                totalSuma = funtionSuma(operador1,operador2);
                totalResta = funtionResta(operador1,operador2);
                totalDivision = funtionDivision(operador1,operador2);
                totalMultiplicacion = funtionMultiplicacion(operador1,operador2);
                totalFactorialA = funtionFactorial(operador1);
                totalFactorialB = funtionFactorial(operador2);
                printf("Calculos Completados.\n");
                flag2 = 1;
            }else{
                printf("Error. Debe Ingresar un valor al Operador 1 o 2.\n");
            }
                system("pause");
                break;
        case 4:
            printf("\n----- Resultados -----\n");
            resultadosControles(operador1,operador2,totalSuma,totalResta,totalDivision,totalMultiplicacion,totalFactorialA,totalFactorialB,flag,flag2);
            break;
        case 5:
            printf("Usted eligio Salir\n");
            printf("Confirma salida? (S / N):  ");
            seguir = getche();
            printf("\n");
            break;
        default:
            printf("\nOpcion Invalida\n");
            system("pause");
            break;
        }
        system("cls");
    }
    while(seguir == 'n');

    return 0;
}



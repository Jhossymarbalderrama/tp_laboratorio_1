#include <stdio.h>
#include <stdlib.h>

#include "gets.h"
#include "menu.h"
#include "ArrayEmployees.h"

#define T 1000 /**Cantidad de Empleados*/

int main()
{
    eEmployee lista[T];
    char salir = 'n';
    int id = 1;
    int flag = 0;

    if(initEmployees(lista,T) == 0)
    {
        do
        {
            //hardCode(lista);
            switch(menu())
            {
            case 1:
                if(altaDeEmpleados(lista, T, id) == 0)
                {
                    id++;
                    flag = 1;
                }
                break;
            case 2:
                if(flag == 1){
                    ask_id_modification_Employee(lista,T);
                }else{
                    error_opc_2_3_4();
                }
                break;
            case 3:
                if(flag == 1){
                    if(ask_id_Employee(lista,T)==0){
                        id--;
                    }
                }else{
                    error_opc_2_3_4();
                }
                break;
            case 4:
                if(flag == 1){
                    informes_Employee(lista,T);
                }else{
                    error_opc_2_3_4();
                }
                break;
            case 5:
                printf("\nConfirmar Salida? [S / N]: ");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                printf("Opcion invalida\n");
                fflush(stdin);
            }
            system("pause");
            system("cls");

        }
        while(salir == 'n');
    }else{
        printf("ERROR. No se pudo Inicializar los Empleados\n");
    }


    return 0;
}

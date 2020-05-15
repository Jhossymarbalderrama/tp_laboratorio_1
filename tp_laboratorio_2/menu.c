#include "menu.h"

int menu(void){
    int valor;
    printf("-------  Sistema de Administracion para Empleados  -------\n\n-----  Menu de Opciones  -----\n");
    printf("1- Alta de Empleados.\n2- Modificacion de Empleados.\n3- Baja de Empleados.\n4- Informes.\n5- Salir.\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&valor);
    return valor;
}

int menu_Modification_Employee(void){
    int valor;
    printf("------  Menu de Modificacion de Empleado  -----\n\n");
    printf("1- Nombre.\n2- Apellido.\n3- Salario.\n4- Sector.\n5- Volver al Menu Principal.\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&valor);
    return valor;
}

int menu_Informes_Employees(void){
    int valor;
    printf("------  Menu Informes de Empleado  -----\n\n");
    printf("1- Mostrar Empleados.\n2- Mostar Empleados Ordenados Alfabeticamente por Apellido y Sector.\n3- Total y Promedio de los Salarios.\n4- Cuantos Empleados superan el salario promedio.\n5- Volver al Menu Principal.\n");
    printf("Ingrese Opcion: ");
    scanf("%d",&valor);
    return valor;
}

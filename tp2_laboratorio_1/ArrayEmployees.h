#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/**Altas de Empleados*/
/**2.1*/int initEmployees(eEmployee lista[],int len);
int initEmployeesAllOk(eEmployee lista[],int len);
int verificacion_Id(eEmployee lista[],int len,int id);
int existe_ID(eEmployee lista[],int len,int id);
int altaDeEmpleados(eEmployee lista[],int len,int id);
int buscarLibre(eEmployee lista[], int len);
/**2.2*/eEmployee addEmployee(eEmployee lista[],int len,int id,char name[],char lastName[],float salary,int sector);
/**Modificacion de Empleado*/
void modification_Employee(eEmployee lista[],int len,int id);
void ask_id_modification_Employee(eEmployee lista[],int len);
/**Baja de Empleados*/
int ask_id_Employee(eEmployee lista[],int len);
/**2.3*/int findEmployeeById(eEmployee lista[],int len,int id);
/**2.4*/int removeEmployee(eEmployee lista[],int len,int id);
/**Informes*/
void printEmployee(eEmployee lista);
/**2.6*/int printEmployees(eEmployee lista[],int len);
void print_Employee_Indice(eEmployee lista[],int len,int indice);
void informes_Employee(eEmployee lista[],int len);
/**2.5*/int sortEmployees(eEmployee lista[],int len,int order);
int sort_Employee_Ascendente(eEmployee lista[],int len);
int sort_Employee_Descendente(eEmployee lista[],int len);
int cant_Employee(eEmployee lista[],int len);
float total_salary(eEmployee lista[],int len);
void total_promedio_De_Salarios(eEmployee lista[],int len);
float promedio_Employee(int cant_employee,float total_salary);
void cuantos_Superan_el_salario_Promedio(eEmployee lista[],int len);
void error_opc_2_3_4(void);

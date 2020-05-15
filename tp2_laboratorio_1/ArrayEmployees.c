#include "ArrayEmployees.h"
#include "gets.h"
#include "menu.h"

/** \brief Para indicar que todas las posiciones del array estan vacias,
           esta funcion pone la bandera (isEmpty) es TRUE en todas las posiciones del array.
 *
 * \param lista[] eEmployee
 * \param len int
 * \return int return (-1) si ahi error [invalido longitud o Puntero Nulo], (0) si esta todo Ok
 *
 */
int initEmployees(eEmployee lista[],int len)
{
    int allOk = -1;

    for(int i = 0; i < len; i++)
    {
        lista[i].isEmpty = 1;
    }

    allOk = initEmployeesAllOk(lista,len);

    return allOk;
}

/** \brief Inicializa toda la structura el campo de IsEmpty en 1
 *
 * \param lista[] eEmployee
 * \param len int
 * \return int -1 si ahi error, 0 si esta todo OK
 *
 */
int initEmployeesAllOk(eEmployee lista[],int len)
{
    int allOk = -1;

    for(int i = 0; i < len; i++)
    {
        /*
        lista[i].isEmpty = 1;
        allOk = 0;
        */
        if(lista[i].isEmpty != 1)
        {
            allOk = -1;
            break;
        }else{
            allOk = 0;
        }
    }

    return allOk;
}

int verificacion_Id(eEmployee lista[],int len,int id){
    int id_retorno = -1;
    id--;

    do{
        id++;
        id_retorno = existe_ID(lista,len,id);

    }while(id_retorno == -1);


    return id;
}

int existe_ID(eEmployee lista[],int len,int id){
    int ocupado = 0;

    for(int i = 0; i < len ; i++){
        if(lista[i].isEmpty == 0 && lista[i].id == id){
            ocupado = -1;
        }
    }

    return ocupado;
}

/** \brief Alta de Empleados, Pido datos del Empleados Nombre,Apellido,salario,sector
 *
 * \param lista[] eEmployee
 * \param len int
 * \param id int
 * \return int 0 si esta todo Ok
 *
 */
int altaDeEmpleados(eEmployee lista[],int len,int id)
{
    int allOk = 0;
    int indice;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    id = verificacion_Id(lista,len,id);

    system("cls");
    printf("[-------  Sistema de Administracion para Empleados  -------]\n");
    printf("----- Alta de Empleados -----\n\n");

    indice = buscarLibre(lista, len);

    if(indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas Empleados\n");
    }
    else
    {
        getChar("Ingrese su Nombre: ",51,name);
        getChar("Ingrese su Apellido: ",51,lastName);
        salary = getFloat("Ingrese su Salario: ");
        sector = getInt("Ingrese su Sector: ");

        lista[indice] = addEmployee(lista,len,id,name,lastName,salary,sector);
    }

    return allOk;
}

/** \brief Busco un Indice Vacio / Libre
 *
 * \param lista[] eEmployee
 * \param len int
 * \return int
 *
 */
int buscarLibre(eEmployee lista[], int len)
{
    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

/** \brief Agrega en una nueva estructura de empleados los datos y retorna  la estructura ya cargada.
 *
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return eEmployee
 *
 */
eEmployee addEmployee(eEmployee lista[],int len,int id,char name[],char lastName[],float salary,int sector)
{
    eEmployee newEmployee;

    newEmployee.id = id;
    strcpy(newEmployee.name,name);
    strcpy(newEmployee.lastName,lastName);
    newEmployee.salary = salary;
    newEmployee.sector = sector;
    newEmployee.isEmpty = 0;
    return newEmployee;
}

/** \brief Imprime Un Empleado
 *
 * \param lista eEmployee
 * \return void
 *
 */
void printEmployee(eEmployee lista)
{
    printf("%3d\t     %10s\t        %10s\t       %.3f\t       %4d\n",
           lista.id,
           lista.name,
           lista.lastName,
           lista.salary,
           lista.sector);
}


/** \brief Imprime el array de Empleados de forma encolumnada
 *
 * \param lista[] eEmployee
 * \param len int
 * \return void
 *
 */
int printEmployees(eEmployee lista[],int len)
{
    int allOk = -1;

    int flag = 0;
    //system("cls");
    printf("------- Lista de Empleados -------\n\n");

    printf(" ID    |      NOMBRE       |      APELLIDO     |      SALARIO     |   SECTOR \n\n");
    for(int i=0; i < len; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            printEmployee(lista[i]);
            flag = 1;
            allOk = 0;
        }
    }

    if( flag == 0)
    {
        printf("\n---   No hay Empleados que mostrar   ---\n");
    }
    system("pause");

    return allOk;
}

/** \brief  Pido ID Busco por ID y llamo a la Funcion Remove
 *
 * \param lista[] eEmployee
 * \param len int
 * \return void
 *
 */
int ask_id_Employee(eEmployee lista[],int len)
{
    int id;
    char seguir = 'n';
    int indice;
    int allOk=-1;

    do
    {
        system("cls");
        printf("[-------  Sistema de Administracion para Empleados  -------]\n");
        printf("-----    Baja de Empleados   -----\n\n");
        id = getInt("Ingrese la ID: ");


        indice = findEmployeeById(lista,len,id);



        if(indice == -1){
            printf("La Id Ingresada es Incorrecta. Reintente\n");
            seguir = 's';
        }else{
              print_Employee_Indice(lista,len,indice);

                printf("Confirma Empleado? [S / N]: ");
                fflush(stdin);
                seguir = getchar();
                if(seguir == 'N')
                {
                seguir = 'n';
                }
        }

    }
    while(seguir == 'n');

    if(indice != -1){
        allOk = removeEmployee(lista,len,id);
        if(allOk == 0)
        {
            printf("-- [El Empleado se dio de Baja Exitosamente.] --\n");
        }
        else
        {
            printf("Error. Hubo un problema al Dar de Baja el Empleado\n");
        }
    }
  return allOk;
}

/** \brief  Elimina de Manera Logica (IsEmpty Flag en 1) un Empleado recibiendo como parametro su ID.
 *
 * \param lista[] eEmployee
 * \param len int
 * \param id int
 * \return int Return (-1) si ahi Error ,0 Si esta todo Bien.
 *
 */
int removeEmployee(eEmployee lista[],int len,int id)
{
    int allOk = -1;

    for(int i = 0 ; i < len ; i++)
    {
        if(lista[i].id == id)
        {
            lista[i].isEmpty = 1;
            allOk = 0;
        }
    }

    return allOk;
}

/** \brief Busca un Empleado Recibiendo como parametro de busqueda su Id.
 *
 * \param lista[] eEmployee
 * \param len int
 * \param id int
 * \return int Retorna el Indice de la posicion del Empleado o (-1) si (Invalida Longitud  o Puntero Nulo o Empleado No encontrado).
 *
 */
int findEmployeeById(eEmployee lista[],int len,int id)
{
    int indice = -1;
    if(lista == NULL)
    {
        printf("Error.Invalida Longitud o Lista Vacia.\n");
    }
    else
    {
        for(int i=0; i < len; i++)
        {
            if( lista[i].isEmpty == 0 && lista[i].id == id)
            {
                indice = i;
            }
        }
    }

    return indice;
}

/** \brief Pido el Ingreso de ID para Buscarlo en la Estructura , y si es el Empleado que busco Voy a Modificar
 *
 * \param lista[] eEmployee
 * \param len int
 * \return void
 *
 */
void ask_id_modification_Employee(eEmployee lista[],int len)
{
    int id;
    char seguir = 'n';
    int indice;

    do
    {
        system("cls");
        printf("[-------  Sistema de Administracion para Empleados  -------]\n");
        printf("\n\n-----    Modificacion de Empleado  -----\n\n");
        id = getInt("Ingrese la ID: ");


        indice = findEmployeeById(lista,len,id);

        print_Employee_Indice(lista,len,indice);


        printf("Confirma Empleado? [S / N]: ");
        fflush(stdin);
        seguir = getchar();
        if(seguir == 'N')
        {
            seguir = 'n';
        }
    }
    while(seguir == 'n');


    modification_Employee(lista,len,id);

}

/** \brief  Imprime Empleado Por Indice
 *
 * \param lista[] eEmployee
 * \param len int
 * \param indice int
 * \return void
 *
 */
void print_Employee_Indice(eEmployee lista[],int len,int indice)
{
    printf(" ID    |      NOMBRE       |      APELLIDO     |      SALARIO     |   SECTOR \n\n");
    for(int i=0; i < len; i++)
    {
        if(lista[i].isEmpty == 0 && i == indice)
        {
            printEmployee(lista[i]);
        }
    }
}


/** \brief  Modifico Al empleado  segun la Opcion Ingresada (Nombre,Apellido,Salario,Sector)
 *
 * \param lista[] eEmployee
 * \param len int
 * \param id int
 * \return void
 *
 */
void modification_Employee(eEmployee lista[],int len,int id)
{
    int allOk = -1;
    char seguir = 'n';
    int indice;

    char name[51];
    char lastName[51];
    float salary;
    int sector;

    indice = findEmployeeById(lista,len,id);


    do
    {
        if(allOk == 0)
        {
            print_Employee_Indice(lista,len,indice);
        }

        switch(menu_Modification_Employee())
        {
        case 1:
            getChar("Ingrese su el Nuevo Nombre: ",51,name);
            strcpy(lista[indice].name,name);
            allOk = 0;
            system("cls");
            break;
        case 2:
            getChar("Ingrese su el Nuevo Apellido: ",51,lastName);
            strcpy(lista[indice].lastName,lastName);
            allOk = 0;
            system("cls");
            break;
        case 3:
            salary = getFloat("Ingrese el Nuevo Salario: ");
            lista[indice].salary = salary;
            allOk = 0;
            system("cls");
            break;
        case 4:
            sector = getInt("Ingrese el Nuevo Sector: ");
            lista[indice].sector = sector;
            allOk = 0;
            system("cls");
            break;
        case 5:
            printf("\nConfirmar Salida? [S / N]: ");
            fflush(stdin);
            seguir = getchar();
            break;
        default:
            printf("[Opcion invalida]\n");
            fflush(stdin);
        }
        //system("cls");
    }
    while(seguir == 'n');

}

/** \brief  Menu Informes -
 *
 * \param lista[] eEmployee
 * \param len int
 * \return void
 *
 */
void informes_Employee(eEmployee lista[],int len)
{
    int allOk = 0;
    int orden;
    char seguir = 'n';

    do
    {
        system("cls");
        switch(menu_Informes_Employees())
        {
        case 1:
            if(printEmployees(lista,len) == -1){
                printf("ERROR. No se puede Mostrar los Empleados.\n");
            }
            break;
        case 2:
            /**Mostar Empleados Ordenados Alfabeticamente por Apellido y Sector.*/
            /**[1] UP
               [0] DOWN
            */
            orden = getInt("\n[Criterio del Ordenamiento]\n[0] Ascendente\n[1] Descendente.\nIngrese el Criterio: ");
            allOk = sortEmployees(lista,len,orden);
            if(allOk != 0)
            {
                printf("ERROR.[ Invalido la longitud o Puntero Nulo]\n");
            }
            break;
        case 3:
            /**Total y Promedio de los Salarios.*/
            total_promedio_De_Salarios(lista,len);
            break;
        case 4:
            /**Cuantos Empleados superan el salario promedio.*/
            cuantos_Superan_el_salario_Promedio(lista,len);
            break;
        case 5:
            printf("\nConfirmar Salida? [S / N]: ");
            fflush(stdin);
            seguir = getchar();
            break;
        default:
            printf("[Opcion invalida]\n");
            fflush(stdin);
            system("pause");
        }
    }
    while(seguir == 'n');
}

/** \brief  Ordena el Array de Empleados por apellido y sector de manera Ascendente o Descendente.
 *
 * \param lista[] eEmployee
 * \param len int
 * \param order int
 * \return int -1 si ahi Error, 0 Si esta todo Bien.
 *
 */
int sortEmployees(eEmployee lista[],int len,int order)
{
    int allOk = -1;

    if(lista == NULL)
    {
        return allOk;
    }
    else
    {
        if(order == 0)
        {
            allOk = sort_Employee_Ascendente(lista,len);
        }
        else
        {
            allOk = sort_Employee_Descendente(lista,len);
        }
    }

    return allOk;
}

/** \brief Ordenamiento de empleados En el array de manera Ascendente
 *
 * \param lista[] eEmployee
 * \param len int
 * \return int -1 error,0 todo bien.
 *
 */
int sort_Employee_Ascendente(eEmployee lista[],int len)
{
    int allOk = -1;
    eEmployee aux;

    for(int i= 0 ; i < len-1 ; i++)
    {
        for(int j = i+1; j < len ; j++)
        {
            if( lista[i].isEmpty == 0 && lista[j].isEmpty == 0)
            {
                if(strcmp(lista[i].lastName,lista[j].lastName)>0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;

                }
                else if(strcmp(lista[i].lastName,lista[j].lastName) == 0 && lista[i].sector > lista[j].sector)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                allOk = 0;
            }
        }
    }

    printf("[- ORDENAMIENTO ASCENDENTEMENTE -]\n\n");

    if(printEmployees(lista,len) == -1){
        printf("ERROR. No se puede Imprimir los Empleados.\n");
    }

    return allOk;
}


/** \brief Ordenamiento de empleados En el array de manera Descendente
 *
 * \param lista[] eEmployee
 * \param len int
 * \return int -1 error, 0 Todo Bien.
 *
 */
int sort_Employee_Descendente(eEmployee lista[],int len)
{
    int allOk = -1;
    eEmployee aux;

    for(int i= 0 ; i < len-1 ; i++)
    {
        for(int j = i+1; j < len ; j++)
        {
            if( lista[i].isEmpty == 0 && lista[j].isEmpty == 0)
            {
                if(strcmp(lista[i].lastName,lista[j].lastName)<0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                else if(strcmp(lista[i].lastName,lista[j].lastName)<0 && lista[i].sector < lista[j].sector)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
                allOk = 0;
            }
        }
    }

    printf("[- ORDENAMIENTO DESCENDENTEMENTE -]\n\n");

    if(printEmployees(lista,len) == -1){
        printf("ERROR. No se puede Imprimir los Empleados.\n");
    }

    return allOk;
}

/** \brief Imprime  el total y  Promedio de los Salarios
 *
 * \param lista[] eEmployee
 * \param len int
 * \return void
 *
 */
void total_promedio_De_Salarios(eEmployee lista[],int len)
{
    int acumulador_Employee;
    float acumulador_Employee_Salary;
    float promedio;

    acumulador_Employee = cant_Employee(lista,len);
    acumulador_Employee_Salary = total_salary(lista,len);

    promedio = promedio_Employee(acumulador_Employee,acumulador_Employee_Salary);

    printf("\n[Total Salario] : %0.3f\n[Promedio de Salarios] : %0.2f\n",acumulador_Employee_Salary, promedio);
    system("pause");
}


/** \brief Cuento la cantidad de Empleados que ahi.
 *
 * \param lista[] eEmployee
 * \param len int
 * \return int retorno la cantidad de empleados.
 *
 */
int cant_Employee(eEmployee lista[],int len)
{
    int cant = 0;

    for(int i =0 ; i < len ; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            cant++;
        }
    }

    return cant;
}

/** \brief Acumulo sumando todos los salarios de los empleados, para obtener El Total.
 *
 * \param lista[] eEmployee
 * \param len int
 * \return float Retorno El Salario Total
 *
 */
float total_salary(eEmployee lista[],int len)
{
    float total_salary = 0;

    for(int i =0 ; i < len ; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            total_salary = total_salary + lista[i].salary;
        }
    }

    return total_salary;
}

/** \brief Calculo El promedio de los salarios de los Empleados.
 *
 * \param cant_employee int
 * \param total_salary float
 * \return float Retorno el Promedio
 *
 */
float promedio_Employee(int cant_employee,float total_salary)
{
    return total_salary / cant_employee;
}

/** \brief Muestro el Promedio TOTAL de todos los empleados y La cantidad de Empleados que lo superan
 *
 * \param lista[] eEmployee
 * \param len int
 * \return void
 *
 */
void cuantos_Superan_el_salario_Promedio(eEmployee lista[],int len)
{
    int acumulador_Employee;
    float acumulador_Employee_Salary;
    float promedio;
    int cant = 0;

    acumulador_Employee = cant_Employee(lista,len);
    acumulador_Employee_Salary = total_salary(lista,len);

    promedio = promedio_Employee(acumulador_Employee,acumulador_Employee_Salary);

    for(int i = 0; i < len; i++)
    {
        if(lista[i].salary >= promedio && lista[i].isEmpty == 0)
        {
            cant++;
        }
    }

    printf("[El promedio es]: %0.2f\n",promedio);
    printf("La cantidad de Empleados que supera el Promedio es : %d\n",cant);
    system("pause");
}


/** \brief  Flag de Entradas a las Opciones 2,3,4 del Menu Principal-
 *
 * \param void
 * \return void
 *
 */
void error_opc_2_3_4(void)
{
    printf("Debe tener al menos 1 Empleado Cargado.[Cargue un EMPLEADO]\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "FuncionesCalculos.h"


/** \brief Recibe 2 valores, los suma y retorna el Total de la Suma.
 *
 * \param a float
 * \param b float
 * \return float
 *
 */
float funtionSuma(float a, float b)
{
    float total;

    return  total = a + b;
}


/** \brief Recibe 2 valores, los resta y retorna el Total de la resta.
 *
 * \param a float
 * \param b float
 * \return float
 *
 */
float funtionResta(float a, float b)
{
    float total;

    return total = a - b;
}


/** \brief Recibe 2 Valores, los divide y retorna el total. Tambien Valida que el segundo valor (el Valor "b") sea distinto de "0".
 *
 * \param a float
 * \param b float
 * \return float
 *
 */
float funtionDivision(float a, float b)
{
    float total;

    if(b == 0)
    {
        total = -1;
        return total;
    }
    else
    {
        total = a / b;
    }

    return total;
}

/** \brief Multiplica el valor "a" con el "b" y retorna su total.
 *
 * \param a float
 * \param b float
 * \return float
 *
 */
float funtionMultiplicacion(float a, float b)
{
    float total;

    return total = a * b ;
}

/** \brief  Funcion Factorial, recibe un valor saca su Factorial y devuelve el resultado total, y valida que sea un entero.
 *
 * \param a float
 * \return int
 *
 */
long long int funtionFactorial(float a)
{
    int aEntero = (int) a;
    int auxiliar = 0;

    long long int fact=1;

    if(a - aEntero == 0)
    {
        if(a >= 0){
            for(int i = 1; i <= a; i++)
            {
                fact = fact * i;
            }
        }

        if(a < 0){
            auxiliar = abs(a);

            for(int i = 1; i <= auxiliar; i++)
            {
                fact = fact * i;
            }

            fact = fact - (fact  * 2);
        }
    }
    else
    {
        return -1;
    }

    return fact;
}

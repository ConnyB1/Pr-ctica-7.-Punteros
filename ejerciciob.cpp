/*
Nombre del archivo: mi_programa.c
Autor: Tu Nombre
Fecha de creación: 12 de septiembre de 2023
Descripción: Este codigo me da a escoger entre varios puntos de los cuales cada uno hace algo distinto y van desde ordenar a sumas y restas
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h> 

void ordenarPalabras(char *palabras[], int n);
void puntoa(int argc, char **argv);

int main(int argc, char *argv[])
{   
    int test = 1;
    
    char op;
    do
    {
        
        printf("\n\tmenu\n");
        printf("a) Argumentos en la Línea de Comandos\n");
        printf("b) Ordenación de Palabras\n");
        printf("c) Matriz Multidimensional\n");
        op = getch(); // lee pero se asegura de que sean los datos que se piden
        op = tolower(op); //convierte a minuscula
        if (isalpha(op))
        {
            printf("%c", op);
        }
        if (op == 'a')
        {
            puntoa(argc, argv); // primero ingresa ./ejerciciob x y en la cosola para que funcione esta opcion
            test = 0;
        }
        else
        {
            if (op == 'b')
            {
                char *palabras[] = {"manzana","banana", "cereza", "uva", "naranja"};

                int n = sizeof(palabras) / sizeof(palabras[0]);
                ordenarPalabras(palabras, n);

                printf("\nPalabras ordenadas alfabéticamente:\n");
                for (int i = 0; i < n; i++) //imprime las palabras
                {
                    printf("%s\n", palabras[i]);
                }
                test = 0;
            }
            else
            {
                if (op == 'c') //me da una matriz para luego sumar sus elementtos
                {
                    printf("\n\n");
                    int matriz[3][3] = 
                    {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                    };

                    int suma = 0;
                    int max_valor = matriz[0][0];
                    int fila_max = 0;
                    int columna_max = 0;

                    int *ptr = &matriz[0][0];

                    for (int i = 0; i < 3; i++) 
                    {
                        for (int j = 0; j < 3; j++) 
                        {
                            suma += *ptr; 
                            if (*ptr > max_valor) 
                            {
                                max_valor = *ptr;
                                fila_max = i;
                                columna_max = j;
                            }
                    ptr++; 
                        }
                    }
                    printf("La suma de todos los elementos de la matriz es: %d\n", suma);
                    printf("El elemento más grande en la matriz es %d, ubicado en la fila %d y columna %d.\n", max_valor, fila_max, columna_max);
                    system("pause");
                    system("cls");
                    test = 0;
                }
                else
                {
                    printf("introduce un valor valido\n\n");
                }                           
            }
        }                               
    } while (test == 1);

    
}

void ordenarPalabras(char *palabras[], int n)  //ordena las palabras del punto b
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++) 
        {
            if (strcmp(palabras[i], palabras[j]) > 0) 
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }
}

void puntoa(int argc, char **argv) //hace operaciones con los numeros que le demos en la consola
{
    if (argc != 3) 
    {
        printf("Uso: %s <numero1> <numero2>\n", argv[0]);
    }

    int numero1 = atoi(argv[1]);
    int numero2 = atoi(argv[2]);

    int suma = numero1 + numero2;
    int resta = numero1 - numero2;
    int multiplicacion = numero1 * numero2;

    if (numero2 == 0)
    {
        printf("No es posible dividir por cero.\n");
    } 
    else 
    {
        float division = (float)numero1 / numero2;

        printf("Suma: %d\n", suma);
        printf("Resta: %d\n", resta);
        printf("Multiplicación: %d\n", multiplicacion);
        printf("División: %.2f\n", division);
    }
}
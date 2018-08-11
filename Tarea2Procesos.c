//Materia: Sistemas Operativos
//Grupo: 
//Alumnos: Arjona Jiménez Gerardo, Fuentes Samaniego Irving

#include <stdio.h>

int promedio(int valores[], int cantidad) {
    int i;
    int suma = 0;

    for (i = 0; i < cantidad; ++i)
        suma += valores[i];

    return suma / (int) cantidad;
}


int main() {

    int numeros[10];
    int n=10, i,pid;

        printf("Ingrese 10 valores del 1 al 7\n ");

        for (i = 0; i < n; ++i) {
            printf("  Valor %d: ", i + 1);
            scanf("%d", &numeros[i]);
        }

        pid = fork();

        if(pid!=0){
        printf("Hola soy el padre\n");
        printf("El promedio es %.1d\n", promedio(numeros, n));
    
        }
        else
        printf("Hola soy el hijo\n");         
        printf("adios\n");

        return 0;
}

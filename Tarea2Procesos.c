//Materia: Sistemas Operativos
//Grupo: 4
//Alumnos: Arjona Jiménez Gerardo, Fuentes Samaniego Irving

#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)        
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

int promedio(int valores[], int length) {
    int i;
    int suma = 0;

    for (i = 0; i < length; ++i)
        suma += valores[i];

    return suma / (int) length;
}

int moda(int valores[], int length) {
    int i, j=1,moda_actual=0, moda_mayor=0, valor_mayor, valor_actual;

    bubbleSort(valores, length);
    for(i=0; i<length;i++){
        if(valores[i]==valores[j]){
             valor_actual=valores[i];
             moda_actual++;
        }
        else{
            if (moda_actual>moda_mayor){
                moda_mayor=moda_actual;
                valor_mayor=valores[i];
            }
            moda_actual=0;
        }
        j++;
    }

    return valor_mayor;
}


void main() {

    int numeros[10],valores[10];
    int i, length, pid;

        printf("Ingrese 10 valores del 1 al 7\n ");

        for (i = 0; i < 10; ++i) {
            printf("  Valor %d: ", i + 1);
            scanf("%d", &numeros[i]);
        }

        length = sizeof(numeros)/sizeof(int);

        pid = fork();

        if(pid!=0){
            printf("Proceso padre: Calculando el promedio...\n");
            printf("El promedio es %.1d\n", promedio(numeros, length));    
        }
        else{
            printf("Proceso hijo: Calculando la moda...\n");
            printf("La moda es %d\n", moda(numeros, length));         
        }
}
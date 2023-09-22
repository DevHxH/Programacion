//Ejercicio 15 Matrices
#include <stdio.h>
void prom(int matriz[][3]);
void porcentajeTrimestralAprobados(int matriz [5][3]);
void promedioGeneral(int matriz[][3]);

void main(){
int notas[5][3];
char nombre[30];
int i,j;
printf("ingrese el nombre del alumno\n");
gets(nombre);

for(i=0;i<5;i++){
    for(j=0;j<3;j++){

        printf("ingrese la nota %d del cuatrimestre %d: \n",j+1, i+1);
        scanf("%d", &notas[i][j]);
    }
}

printf("        ---------------------------------------------------------\n");
printf("         Matematica     Lengua    Ingles    Geografia    Biologia\n");
printf("        ---------------------------------------------------------\n");

for(i=0;i<3;i++){
    for(j=0;j<5;j++){

            printf("           %d", notas[j][i]);
}
printf("\n");


}

printf("El nombre y Apellido es: %s\n",nombre);
printf("El promedio de las materias son: \n");

prom(notas);

printf("el porcentaje trimestrales son: \n");
porcentajeTrimestralAprobados(notas);
promedioGeneral(notas);
}
void promedioGeneral(int matriz[5][3]){
int i,j;
    int acum=0;
    for(i=0;i<3;i++){
    for( j=0;j<5;j++){
    acum+=matriz[i][j];
    }
}
printf("El promedio general es: %.2f", (float)acum/(i*j));

}
void porcentajeTrimestralAprobados(int matriz[5][3]){
    int i,j;
    int acum[3]={0};
    for(i=0;i<3;i++){
    for( j=0;j<5;j++){
            if(matriz[j][i>6]){
                acum[i]+=matriz[j][i];
            }

    }
printf("porcentaje del %d cuatrimestre es: %d %% \n",i+1,(acum[i]*100)/j);
}
}
void prom(int matriz[5][3]){
int acumM[5]={0};
int i,j=0;
for(i=0;i<5;i++){
    for( j=0;j<3;j++){
    acumM[i]+=matriz[i][j];
    }
     printf("promedio es: %.2f\n",(float)acumM[i]/3);


}

}
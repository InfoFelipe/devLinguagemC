#include<stdio.h>
#include<math>

int main (){

int indice;
float total = 0, elementosNumericos [100];

for (indice = 0; indice < 100; indice++){

    printf("Digite o elemento %d:", indice);
    scanf("%f", &elementosNumericos[indice]);
}
printf("Elementos Numéricos: \n");
for (indice = 0; indice < 3; indice++){

  printf("%f", elementosNumericos[indice]);
  total += elementosNumericos[indice];
}
printf("\nTotal: %f\n", total);
}

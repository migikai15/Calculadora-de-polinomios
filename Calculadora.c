# Calculadora-de-polinomios
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

int calpoli(int poli[], int x, int grau);
void mostrarpoli(int poli[], int grau);
void somapoli(int poli[], int poli2[], int poli3s[], int grau, int grau2, int x);
void mutpoli(int poli[], int poli2[], int poli3[], int grau, int grau2);

int main(void) {
    int a, i, grau, grau2, b, c,x;
    int poli[100];
    int poli2[100];
    int poli3s[100];
    char gracinha[30] = " polinômios       |";
    bool polinomioInserido = false;
    do {
        printf(" _______________________________________\n");
        printf("|1-informar e calcular%s \n", gracinha);
        printf("|2-somar polinômios                     |\n");
        printf("|3-multiplicar polinômios               |\n");
        printf("|4-encerrar programa                    |\n");
        printf("|_______________________________________|\n");
        scanf("%d", &a);

        switch (a) {
            case 1:
                strcpy(gracinha, " outro polinômio  |");
                for (int i = 0; i < 100; i++) {
                    poli[i] = 0;}
                for (int i = 0; i < 100; i++) {
                    poli2[i] = 0;}
                printf("\n");
                printf("Qual grau do seu primeiro polinômio?\n");
                printf("\n");
                scanf("%d", &grau);
                printf("\n");
                printf("Informe o primeiro polinômio\n");

                for (i = 0; i <= grau; i++) {
                    printf("%d° coeficiente: ", i + 1);
                    scanf("%d", &poli[i]);
                }
                printf("\n");
                printf("Qual grau do seu segundo polinômio?\n");
                printf("\n");
                scanf("%d", &grau2);
                printf("\n");
                printf("Informe o segundo polinômio\n");

                for (i = 0; i <= grau2; i++) {
                    printf("%d° coeficiente: ", i + 1);
                    scanf("%d", &poli2[i]);
                }

                printf("Informe X: ");
                scanf("%d", &x);

                int polinomio = calpoli(poli, x, grau);
                int polinomio2 = calpoli(poli2, x, grau2);

                printf("Valor do 1° polinômio: %d\n", polinomio);
                printf("Valor do 2° polinômio: %d\n", polinomio2);

                mostrarpoli(poli, grau);
                mostrarpoli(poli2, grau2);

                polinomioInserido = true;
                break;

            case 2:
                if (!polinomioInserido) {
                    printf("!!!!!! Primeiro insira um polinomio !!!!!\n");
                    break;
                }
                somapoli(poli, poli2, poli3s, grau2, grau, x);  
                if (grau > grau2) {
                    int soma = calpoli(poli3s, x, grau);
                    printf("Valor da soma dos polinômios: %d\n", soma);
                    mostrarpoli(poli3s, grau);
                } else {
                    int soma = calpoli(poli3s, x, grau2);
                    printf("Valor da soma dos polinômios: %d\n", soma);
                    mostrarpoli(poli3s, grau2);
                }
                break;

            case 3:
                if (!polinomioInserido) {
                    printf("!!!!!! Primeiro insira um polinomio !!!!!\n");
                    break;
                }
                printf("Valor da multiplicação dos polinômios: %d",polinomio * polinomio2);
                printf("\n");
                mutpoli(poli, poli2, poli3s, grau, grau2);
                mostrarpoli(poli3s, grau + grau2);
                break;

            case 4:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (a != 4);

    return 0;
}

int calpoli(int poli[], int x, int grau) {
    int p = 0;
    for (int i = 0; i <= grau; i++) {
        p += (poli[i] * pow(x, grau - i));
    }
     printf("\n");
     return p;
}
void mostrarpoli(int poli[], int grau) {
    printf("\n");
    printf("P(x) = "); 

    for (int i = 0; i <= grau; i++) { //para nao imprimir um x no fim
         if (i == grau){
           if (poli[i] == 0){   //para nao imprimir um0 no fim
             break;
            }else if(poli[i] <0){
               printf("  %d",poli[i]);
               break;
            }else{
               printf(" + %d",poli[i]);
                break;
            }
            
         }
         
         if (poli[i] != 0) {
            if (poli[i] > 0) {
                if (i == 0) {
                    printf("%dx^%d", poli[i],grau );              
                } else {
                    if (i == grau) {
                      if(poli[i]==1){
                          printf("+ x^%d",grau - i);}
                      } else{
                          printf(" + %dx^%d", poli[i], grau - i);
                }
                }
          } else if (poli[i] < 0) {
                if (i == 0) {
                    printf(" - %dx^%d", abs(poli[i]),grau -i);//pegar numero sem sinal
                } else {
                    if (i == grau) {
                        printf(" - x^%d", grau - i);
                    } else {
                        printf(" - %dx^%d", abs(poli[i]), grau - i);
                    }
                }
            }
        }
    }
    printf("\n");
}
void somapoli(int poli[], int poli2[], int poli3s[], int grau, int grau2, int x) {
     int j = 0; 
     if(grau2 > grau){
       j = grau2 - grau;
       for(int i = 0;i<=j-1;i++){
          poli3s[i] = poli[i];}
       for(int y = 0;y <= grau;y++){
          poli3s[y+j] = poli2[y] + poli[y+j];
    }
     }
     else if (grau2 == grau){
          for (int i = grau ;i >=0;i--){
             poli3s[i] = poli[i] + poli2[i];}
      }
     else{
        j = grau - grau2;
        for(int i = 0;i<=j-1;i++){
          poli3s[i] = poli2[i];}
        for(int y = 0;y <= grau2;y++){
          poli3s[y+j] = poli2[y+j] + poli[y];}

     }
}
void mutpoli(int poli[], int poli2[], int poli3[], int grau, int grau2) {
    int i, j;

    for (i = 0; i <= grau + grau2; i++) {
        poli3[i] = 0;
    }

    for (i = 0; i <= grau; i++) {
        for (j = 0; j <= grau2; j++) {
            poli3[i + j] += poli[i] * poli2[j];
        }
    }
}

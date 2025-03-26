# Calculadora de Polinômios

## Descrição
Este projeto implementa uma calculadora de polinômios em linguagem C. O programa permite ao usuário inserir dois polinômios, calcular seus valores para um dado X, somá-los e multiplicá-los.

## Funcionalidades
- Inserir e calcular o valor de um polinômio para um dado X.
- Exibir os polinômios inseridos.
- Somar dois polinômios.
- Multiplicar dois polinômios.
- Interface interativa via terminal.


## Estrutura do Código
- `calpoli(int poli[], int x, int grau)`: Calcula o valor de um polinômio para um dado X.
- `mostrarpoli(int poli[], int grau)`: Exibe o polinômio formatado.
- `somapoli(int poli[], int poli2[], int poli3s[], int grau, int grau2, int x)`: Realiza a soma de dois polinômios.
- `mutpoli(int poli[], int poli2[], int poli3[], int grau, int grau2)`: Realiza a multiplicação de dois polinômios.
- `main()`: Controla o fluxo do programa e interação com o usuário.



## Exemplo de Entrada e Saída
### Entrada:
```
Qual grau do seu primeiro polinômio?
2
Informe o primeiro polinômio
1º coeficiente: 3
2º coeficiente: 2
3º coeficiente: 1

Informe X: 2
```
### Saída:
```
Valor do 1º polinômio: 11
P(x) = 3x^2 + 2x^1 + 1
```




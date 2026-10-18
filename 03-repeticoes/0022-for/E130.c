// 0022 · For
// Exercício E130 · ★★☆
//
// O treino manda fazer 5 séries de flexões e o programa deveria mostrar
// "Série 1" até "Série 5". Ele compila com um AVISO e mostra só:
//
//   Série 6
//
// O código com o erro está logo abaixo. Rode, leia o aviso do gcc e conserte:
// o programa tem que compilar sem aviso e mostrar Série 1 até Série 5.
//
// Dicas:
// 1. O aviso fala em "misleading indentation": a indentação engana.
// 2. Olhe o fim da linha do for. Um ; sozinho é um comando vazio.
// 3. Resposta esperada: o ";" logo depois do for vira o corpo do laço (vazio).
//    O laço gira 5 vezes sem fazer nada, i termina em 6 e o bloco { } roda
//    uma vez só, depois. Tirando o ";", mostra Série 1 a Série 5.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int i;

    for (i = 1; i <= 5; i++);
    {
        printf("Série %d\n", i);
    }
    return 0;
}

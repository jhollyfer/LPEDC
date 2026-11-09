// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0514 · ★★☆ · Encaixar na fila preferencial
//
// A fila do cartório é ordenada pela idade, do mais velho para o mais novo.
// Ela cabe até 10 pessoas e hoje tem 6:
//
//   int idades[10] = {91, 84, 77, 70, 66, 61};
//   int n = 6;
//
// Escreva int inserir(int v[], int n, int cap, int idade), que encaixa a idade
// no lugar certo (empurrando os mais novos uma casa para a direita) e devolve
// o novo tamanho. Se a fila estiver cheia, não mexe e devolve n. Insira 80,
// 95 e 60, mostrando a fila depois de cada inserção:
//
//   Saída esperada:
//   Entrou 80: 91 84 80 77 70 66 61
//   Entrou 95: 95 91 84 80 77 70 66 61
//   Entrou 60: 95 91 84 80 77 70 66 61 60
//
// Dicas:
// 1. Comece do fim: i = n - 1. Enquanto i >= 0 e v[i] < idade, copie v[i]
//    para v[i + 1] e ande i para trás.
// 2. Quando o laço para, o lugar livre é i + 1.
// 3. Por que do fim? Se você empurrar a partir do começo, cada cópia apaga o
//    valor que ainda ia ser copiado.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int idades[10] = {91, 84, 77, 70, 66, 61};
    int n = 6;
    (void) idades, (void) n; // apague esta linha quando escrever

    return 0;
}

// Lista · Módulo 21 · Programação dinâmica
// Exercício P2115 · ★★☆ · A trilha que só sobe
//
// Um trilheiro mediu a altitude (em metros) de 12 pontos de uma trilha na
// Serra do Tepequém, na ordem do caminho:
//
//   640 702 655 690 735 610 760 720 805 780 850 830
//
// Ele quer escolher pontos para fotografar, sem mudar a ordem, de modo que
// cada foto seja num ponto MAIS ALTO que a anterior, com o maior número de
// fotos. Escreva do zero a subsequência crescente máxima O(n²) com
// RECONSTRUÇÃO: além de lis[i], guarde ant[i], o ponto anterior na melhor
// sequência que termina em i (-1 se não há). Mostre a sequência.
//
//   Saída esperada:
//   Fotos: 7
//   Altitudes: 640 655 690 735 760 805 850
//
// Dicas:
// 1. Ao atualizar lis[i] = lis[j] + 1, faça ant[i] = j.
// 2. Ache o i com maior lis e siga ant[] até -1, guardando num vetor; mostre
//    o vetor de trás para a frente.
// 3. Resposta esperada: 7 fotos: 640 655 690 735 760 805 850. Empate de
//    lis: fica o primeiro j que achou (use >, não >=).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}

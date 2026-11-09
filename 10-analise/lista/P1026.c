// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1026 · ★★★ · Duas implementações da lista de presença
//
// A portaria do evento marca quem entrou (pelo número do crachá) e depois
// responde "fulano entrou?". Implemente a MESMA interface de dois jeitos,
// num arquivo só, e meça qual compensa (os nomes ganharam um sufixo só para
// as duas caberem no mesmo arquivo):
//
//   Presenca *pres_cria_X(int capacidade);
//   void pres_marca_X(Presenca *p, int cracha);
//   bool pres_entrou_X(Presenca *p, int cracha);   // sem const: soma passos
//   long pres_passos_X(const Presenca *p);   // passos gastos até agora
//   void pres_libera_X(Presenca *p);
//
// - X = A, vetor DESORDENADO: marca põe no fim (1 passo); entrou é a busca
//   sequencial (1 passo por comparação).
// - X = B, vetor ORDENADO: marca desloca os maiores para abrir espaço (1
//   passo por deslocamento, mais 1 para gravar); entrou é a busca binária
//   (1 passo por volta).
//
// Carga de teste: marque os crachás (7 * k) % 1000 para k = 0..999 (os
// números de 0 a 999, embaralhados) e depois pergunte por 0, 1, ..., 1999
// (metade entrou, metade não). Mostre os passos de cada fase. A struct de
// cada versão pode ser igual: int *v, int n e long passos.
//
//   Saída esperada:
//   A (desordenado): marcar 1000 passos, consultar 1500500 passos
//   B (ordenado):    marcar 214213 passos, consultar 18987 passos
//   Respostas iguais: sim
//
// Dicas:
// 1. Em B, a marcação é a inserção ordenada: i = n; while (i > 0 &&
//    v[i - 1] > x) { v[i] = v[i - 1]; i--; } e depois v[i] = x.
// 2. A consulta de A custa até n por pergunta: 1000 perguntas sem sucesso
//    custam 1000 · 1000. A de B custa cerca de log₂ 1000 ≈ 10.
// 3. Nenhuma é "a melhor": com muitas marcações e poucas consultas, A ganha;
//    com muitas consultas, B ganha. Como o cliente só usa a interface, dá
//    para trocar uma pela outra sem mexer nele.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}

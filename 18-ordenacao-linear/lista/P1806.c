// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1806 · ★☆☆ · De trás para frente ou da frente para trás?
//
// As inscrições da corrida de rua chegam em ordem de inscrição, cada uma com
// o nome e a categoria (0 = 5 km, 1 = 10 km, 2 = meia, 3 = maratona). A
// organização quer a lista por categoria e, dentro dela, na ORDEM DE
// INSCRIÇÃO: é preciso uma ordenação ESTÁVEL.
//
// Complete o counting sort por categoria com um parâmetro bool de_tras: com
// true, a colocação anda de n - 1 até 0 (a versão do Cormen); com false,
// anda de 0 até n - 1, mas continua usando --c[x]. Mostre as duas saídas e
// diga, para cada uma, se ficou estável (compare a ordem dos nomes dentro de
// cada categoria com a ordem de inscrição, guardada no campo ordem).
//
//   Saída esperada:
//   de trás: Bruno(0) Elis(0) Ana(1) Davi(1) Gil(1) Fabio(2) Carla(3) Hana(3) -> estável
//   da frente: Elis(0) Bruno(0) Gil(1) Davi(1) Ana(1) Fabio(2) Hana(3) Carla(3) -> NÃO estável
//
// Dicas:
// 1. Com --c[x], cada bloco é preenchido de trás para frente. Se a leitura
//    também é de trás para frente, o último inscrito de cada categoria fica
//    no fim do bloco: a ordem se mantém.
// 2. Lendo da frente com --c[x], o PRIMEIRO inscrito vai para o fim do bloco:
//    os empates saem invertidos. Para ler da frente e ser estável, seria
//    preciso usar as posições iniciais dos blocos com c[x]++.
// 3. Estável: para todo i, se saida[i].cat == saida[i + 1].cat, então
//    saida[i].ordem < saida[i + 1].ordem.
// 4. Resposta esperada: de trás para frente é estável (Ana antes de Davi nos
//    10 km); da frente para trás, não.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define N 8
#define K 4

typedef struct {
    const char *nome;
    int cat;
    int ordem; // ordem de inscrição
} Inscricao;

void counting(const Inscricao v[], Inscricao saida[], int n, bool de_tras) {
    (void)v; // apague e escreva a função
    (void)saida;
    (void)n;
    (void)de_tras;
}

int main(void) {
    Inscricao v[N] = {{"Ana", 1, 1}, {"Bruno", 0, 2}, {"Carla", 3, 3}, {"Davi", 1, 4},
                      {"Elis", 0, 5}, {"Fabio", 2, 6}, {"Gil", 1, 7}, {"Hana", 3, 8}};
    Inscricao saida[N];

    counting(v, saida, N, true);
    return 0;
}

// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1809 · ★☆☆ · A tabela do campeonato em ordem decrescente, estável
//
// No campeonato de futsal do bairro, os times já estão em ordem alfabética.
// A tabela tem de sair por PONTOS, do maior para o menor, e os empatados
// continuam em ordem alfabética. Os pontos vão de 0 a 15.
//
// Complete o counting sort decrescente e estável. Para isso, ordene pela chave
// invertida, MAX - pontos, em ordem crescente. Quem tem mais pontos tem chave
// menor e vai para o começo, e a estabilidade do counting sort preserva a
// ordem alfabética dos empates.
//
//   Saída esperada:
//   1. Goias            15
//   2. Para             12
//   3. Amazonas          9
//   4. Bahia             9
//   5. Ceara             9
//   6. Espirito Santo    7
//   7. Fortaleza         4
//   8. Distrito Federal  2
//
// Dicas:
// 1. Use chave(t) = 15 - t.pontos em todos os lugares em que o counting sort
//    usaria t.pontos.
// 2. Não dá para ordenar crescente e inverter o vetor depois: a inversão
//    também inverte os empates (Bahia sairia antes de Amazonas).
// 3. Confira os empates: Amazonas, Bahia e Ceara têm 9 pontos.
// 4. Resposta esperada: Goias 15, Para 12, Amazonas 9, Bahia 9, Ceara 9,
//    Espirito Santo 7, Fortaleza 4, Distrito Federal 2.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 8
#define MAX 15

typedef struct {
    const char *nome;
    int pontos;
} Time;

void ordena(const Time v[], Time saida[], int n) {
    for (int i = 0; i < n; i++) saida[i] = v[i]; // apague e escreva o counting sort
}

int main(void) {
    Time v[N] = {{"Amazonas", 9}, {"Bahia", 9}, {"Ceara", 9}, {"Distrito Federal", 2},
                 {"Espirito Santo", 7}, {"Fortaleza", 4}, {"Goias", 15}, {"Para", 12}};
    Time saida[N];

    ordena(v, saida, N);
    for (int i = 0; i < N; i++) printf("%d. %-16s %2d\n", i + 1, saida[i].nome, saida[i].pontos);
    return 0;
}

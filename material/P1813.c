// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1813 · ★★☆ · Três chaves, três passadas estáveis
//
// A central de suporte quer os chamados ordenados por PRIORIDADE (0 a 3, 0
// é a mais urgente), depois por SETOR (0 a 4) e, dentro disso, pelo MINUTO em
// que chegaram (0 a 59). Em vez de um comparador com três critérios, use o
// truque do radix: passadas estáveis, da chave MENOS significativa para a
// MAIS significativa.
//
// Escreva um counting sort genérico que recebe a função da chave:
//
//   void counting(Chamado v[], int n, int (*chave)(const Chamado *), int k);
//
// e faça três passadas: por minuto, por setor e por prioridade, mostrando a
// ordem dos chamados depois de cada uma e, no fim, os campos de cada um.
//
//   Saída esperada:
//   por minuto:     #4 #5 #1 #3 #7 #2 #6 #8
//   por setor:      #5 #8 #3 #6 #4 #2 #1 #7
//   por prioridade: #3 #6 #1 #8 #4 #2 #7 #5
//     #3 prioridade 0, setor 1, minuto 15
//     #6 prioridade 0, setor 1, minuto 40
//     #1 prioridade 0, setor 3, minuto 12
//     #8 prioridade 1, setor 0, minuto 59
//     #4 prioridade 1, setor 2, minuto  5
//     #2 prioridade 1, setor 2, minuto 33
//     #7 prioridade 2, setor 4, minuto 20
//     #5 prioridade 3, setor 0, minuto  8
//
// Dicas:
// 1. A função da chave devolve um inteiro de 0 a k - 1; o counting sort usa
//    chave(&v[i]) onde usaria v[i]. Escreva int por_minuto(const Chamado *c)
//    e as outras duas.
// 2. Por que da menos para a mais significativa? A última passada decide a
//    ordem principal; a estabilidade preserva, nos empates, a ordem deixada
//    pelas passadas anteriores.
// 3. Cada passada custa Θ(n + k): o total é Θ(3n + 60 + 5 + 4), linear.
// 4. Resposta esperada: no fim, #3 #6 #1 #8 #4 #2 #7 #5. Em #4 e #2,
//    mesma prioridade e setor, e o minuto 5 vem antes do 33 porque a
//    primeira passada deixou os dois nessa ordem.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define N 8

typedef struct {
    int id, prioridade, setor, minuto;
} Chamado;

int main(void) {
    Chamado v[N] = {{1, 0, 3, 12}, {2, 1, 2, 33}, {3, 0, 1, 15}, {4, 1, 2, 5},
                    {5, 3, 0, 8},  {6, 0, 1, 40}, {7, 2, 4, 20}, {8, 1, 0, 59}};

    for (int i = 0; i < N; i++) printf("#%d ", v[i].id);
    printf("\n");
    return 0;
}

## 0186 · P e NP

- **Problema de decisão**: resposta **sim ou não** ("existe rota de no máximo
  300 km?"). Otimização vira decisão com um limite (CORMEN et al., 2024, cap. 34).
- **P**: problemas de decisão que se **resolvem** em tempo polinomial, O(n^k)
  com k fixo: caminho mínimo, Euler (0182), pontes (0184)
  (CORMEN et al., 2024, cap. 34).
- **NP**: um "sim" tem um **certificado** (prova curta) que um
  **verificador** confere em tempo polinomial. Quem resolve rápido confere
  rápido: **P ⊆ NP** (LINTZMAYER; MOTA, 2023).
- **NP-difícil**: todo problema de NP se reduz a ele em tempo polinomial
  (0187). **NP-completo**: está em NP **e** é NP-difícil. Um NP-completo
  polinomial daria P = NP, questão em aberto (KLEINBERG; TARDOS, 2006, cap. 8).
- **SAT**: fórmula em **forma normal conjuntiva** (um E de **cláusulas**, cada
  uma um OU de **literais** `x` ou `não x`); existe atribuição que deixa todas
  verdadeiras? Foi o primeiro NP-completo (COOK, 1971).
- **3-SAT**: no máximo três literais por cláusula (no Cormen, exatamente
  três); continua NP-completo (KARP, 1972).
- **Força bruta com máscara**: as 2ⁿ atribuições são os valores de um
  contador; o bit `v - 1` diz se `v` é verdadeira, lido com
  `(mascara >> (v - 1)) & 1`.

| Classe | O que se exige | Exemplos |
| --- | --- | --- |
| P | resolver em tempo polinomial | caminho mínimo, Euler, pontes, MST |
| NP | verificar um "sim" em tempo polinomial | tudo de P, SAT, clique, hamiltoniano |
| NP-completo | estar em NP e ser NP-difícil | SAT, 3-SAT, clique, cobertura de vértices, ciclo hamiltoniano |
| NP-difícil | todo NP se reduz a ele (pode nem estar em NP) | os NP-completos, caixeiro viajante (otimização) |

> [!WARNING]
> **NP não quer dizer "não polinomial"**, e sim *polinomial não
> determinístico*. NP-completo é "sem algoritmo polinomial conhecido", não
> "impossível". E reduzir A a B mostra que B é **pelo menos tão difícil**
> quanto A, não o contrário (0187).

{{exemplo}}

Um churrasco da firma com cinco condições sobre Ana, Beto, Caio e Davi.
Conferir um palpite é rápido; achar um grupo pode exigir todas as
combinações. O palpite falha na quinta cláusula, e a força bruta acha uma
atribuição na décima primeira de 16:

{{ideia}}

A fórmula é uma matriz de literais `+v` / `-v` (como no DIMACS), com zero ao
fim de cada cláusula:

```c
#include <stdbool.h>
#include <stdio.h>

#define NV 4 // variáveis: 1 Ana, 2 Beto, 3 Caio, 4 Davi
#define NC 5 // cláusulas
#define MAXL 3

const char *nomes[NV + 1] = {"", "Ana", "Beto", "Caio", "Davi"};
// cada cláusula é um OU de literais; +v = "v vai", -v = "v não vai"; 0 encerra
const int formula[NC][MAXL + 1] = {
    {1, 2, 0},   // Ana ou Beto (alguém precisa levar a churrasqueira)
    {-1, -3, 0}, // Ana e Caio brigaram: não os dois
    {3, 4, 0},   // Caio ou Davi (alguém faz o carvão pegar)
    {-2, 4, 0},  // Beto só vai se Davi for
    {-4, -1, 3}, // se Davi e Ana forem, Caio tem que ir
};

// verificador: O(tamanho da fórmula). vai[v] é a atribuição (o certificado)
bool satisfaz(const bool vai[]) {
    for (int c = 0; c < NC; c++) {
        bool algum = false;
        for (int i = 0; i < MAXL && formula[c][i] != 0; i++) {
            int lit = formula[c][i];
            if ((lit > 0 && vai[lit]) || (lit < 0 && !vai[-lit])) algum = true;
        }
        if (!algum) return false; // uma cláusula falsa derruba tudo
    }
    return true;
}

void mostra(const bool vai[]) {
    for (int v = 1; v <= NV; v++) printf(" %s=%s", nomes[v], vai[v] ? "sim" : "não");
    printf("\n");
}

int main(void) {
    bool palpite[NV + 1] = {false, true, false, false, true}; // Ana e Davi
    printf("Palpite:");
    mostra(palpite);
    printf("Verificador: %s\n", satisfaz(palpite) ? "satisfaz" : "não satisfaz");

    // força bruta: as 2^n atribuições, como os bits de um contador
    long testadas = 0;
    for (int mascara = 0; mascara < (1 << NV); mascara++) {
        bool vai[NV + 1] = {false};
        for (int v = 1; v <= NV; v++) vai[v] = (mascara >> (v - 1)) & 1;
        testadas++;
        if (satisfaz(vai)) {
            printf("Achei depois de %ld de %d tentativas:", testadas, 1 << NV);
            mostra(vai);
            return 0;
        }
    }
    printf("Insatisfatível: %ld tentativas\n", testadas);
    return 0;
}
// Saída:
// Palpite: Ana=sim Beto=não Caio=não Davi=sim
// Verificador: não satisfaz
// Achei depois de 11 de 16 tentativas: Ana=não Beto=sim Caio=não Davi=sim
```

O fluxograma é o verificador, O(tamanho da fórmula). A força bruta o chama
até 2ⁿ vezes:

{{fluxograma}}

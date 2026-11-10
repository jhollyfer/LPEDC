## 0186 · P e NP

Você organiza o churrasco da firma com cinco condições: alguém leva a
churrasqueira, dois colegas brigados não vão juntos... Um amigo diz "chama a
Ana e o Davi", e conferir leva dez segundos. Achar um grupo sem palpite pode
exigir todas as combinações. A pergunta mais famosa da computação gira em
torno dessa assimetria entre **achar** e **conferir**.

**Problema de decisão** é o de resposta **sim ou não**: "existe ciclo
hamiltoniano?", "existe rota de no máximo 300 km?". Otimização ("qual a menor
rota?") vira decisão com um limite.

**P** é a classe dos problemas de decisão que se **resolvem** em tempo
polinomial, O(n^k) para algum k fixo: ordenar, achar caminho mínimo, testar
circuito euleriano (0182), achar pontes (0184).

**NP** é a classe em que um "sim" tem um **certificado** (prova curta) que um
**verificador** confere em tempo polinomial: no churrasco, a lista de quem
vai; no hamiltoniano, a rota (o E1093 é um verificador). Quem resolve rápido
também confere rápido: **P ⊆ NP**.

**NP-difícil** é o problema ao qual **todo** problema de NP se reduz em tempo
polinomial (0187). **NP-completo** é quem está em NP **e** é NP-difícil. Se um
NP-completo tiver algoritmo polinomial, P = NP. Ninguém sabe; a maioria aposta
que P ≠ NP, e a questão vale um milhão de dólares.

| Classe | O que se exige | Exemplos |
| --- | --- | --- |
| P | resolver em tempo polinomial | caminho mínimo, Euler, pontes, MST |
| NP | verificar um "sim" em tempo polinomial | tudo de P, SAT, clique, hamiltoniano |
| NP-completo | estar em NP e ser NP-difícil | SAT, 3-SAT, clique, cobertura de vértices, ciclo hamiltoniano |
| NP-difícil | todo NP se reduz a ele (pode nem estar em NP) | os NP-completos, caixeiro viajante (otimização) |

**SAT** (satisfatibilidade) foi o primeiro NP-completo (Cook-Levin, 1971). A
fórmula está em **forma normal conjuntiva** (FNC): um E de **cláusulas**,
cada uma um OU de **literais** (`x` ou `não x`). Existe uma atribuição que
deixa todas verdadeiras? **3-SAT** tem no máximo três literais por cláusula
(no Cormen, exatamente três) e continua NP-completo.

As variáveis são Ana, Beto, Caio e Davi. O palpite do amigo falha na quinta
cláusula; a força bruta percorre as 2⁴ = 16 atribuições e acha uma na décima
primeira:

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

O A371 mede o crescimento de 2ⁿ. O A372 mostra outro NP-completo: boletos que
somam exatamente o valor de um Pix.

> [!WARNING]
> **NP não quer dizer "não polinomial"**, e sim *polinomial não
> determinístico*. NP-completo não é "impossível", é "sem algoritmo
> polinomial conhecido". E reduzir A a B mostra que B é **pelo menos tão
> difícil** quanto A, não o contrário (0187).

> [!TIP]
> A máscara é a atribuição: o bit `v - 1` diz se `v` é verdadeira, lido com
> `(mascara >> (v - 1)) & 1`.

> [!NOTE]
> **Pergunta para você:** se você trocar a ordem dos bits (Ana no bit mais
> alto e Davi no mais baixo), a força bruta acha a mesma atribuição? Em
> quantas tentativas?

{{pratique}}

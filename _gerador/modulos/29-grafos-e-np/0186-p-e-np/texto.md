## 0186 · P e NP

Você organiza o churrasco da firma e quer um grupo que respeite cinco
condições: alguém leva a churrasqueira, dois colegas brigados não vão
juntos, alguém sabe acender o carvão... Um amigo diz "chama a Ana e o Davi".
Conferir o palpite leva dez segundos: é só passar condição por condição.
Achar um grupo que funcione, sem palpite nenhum, pode exigir testar todas as
combinações de quem vai e quem não vai.

Essa assimetria entre **achar** e **conferir** é o coração da pergunta mais
famosa da computação.

**Problema de decisão** é um problema cuja resposta é **sim ou não**: "existe
um grupo que satisfaz as condições?", "existe ciclo hamiltoniano?", "existe
rota de no máximo 300 km?". Os problemas de otimização ("qual a menor rota?")
viram decisão com um limite, e a teoria toda é feita com eles.

**P** é a classe dos problemas de decisão que se **resolvem** em tempo
polinomial, O(n^k) para algum k fixo: ordenar, achar caminho mínimo, testar
se há circuito euleriano (0182), achar pontes (0184).

**NP** é a classe dos problemas em que, quando a resposta é sim, existe um
**certificado** (uma prova curta) que um **verificador** confere em tempo
polinomial. No churrasco, o certificado é a lista de quem vai; no
hamiltoniano, a rota (o E1093 é um verificador). Todo problema de P está em
NP: quem resolve rápido também confere rápido, então **P ⊆ NP**.

**NP-difícil** é um problema ao qual **todo** problema de NP pode ser reduzido
em tempo polinomial (0187): resolvê-lo rápido resolveria todos. **NP-completo**
é quem está em NP **e** é NP-difícil: os mais difíceis de NP. Se um único
NP-completo tiver algoritmo polinomial, então P = NP. Ninguém sabe se isso é
verdade; a maioria aposta que P ≠ NP, e a questão vale um prêmio de um
milhão de dólares.

| Classe | O que se exige | Exemplos |
| --- | --- | --- |
| P | resolver em tempo polinomial | caminho mínimo, Euler, pontes, MST |
| NP | verificar um "sim" em tempo polinomial | tudo de P, SAT, clique, hamiltoniano |
| NP-completo | estar em NP e ser NP-difícil | SAT, 3-SAT, clique, cobertura de vértices, ciclo hamiltoniano |
| NP-difícil | todo NP se reduz a ele (pode nem estar em NP) | os NP-completos, caixeiro viajante (otimização) |

**SAT** (satisfatibilidade) foi o primeiro NP-completo (teorema de
Cook-Levin, 1971). A fórmula está em **forma normal conjuntiva** (FNC): um E
de **cláusulas**, cada cláusula um OU de **literais** (`x` ou `não x`). A
pergunta: existe uma atribuição de verdadeiro e falso que deixa todas as
cláusulas verdadeiras? **3-SAT** é o caso em que toda cláusula tem no máximo
três literais (no Cormen, exatamente três), e continua NP-completo.

Vamos ver na prática. As quatro variáveis são Ana, Beto, Caio e Davi. O
palpite do amigo cai na quinta cláusula; a força bruta percorre as 2⁴ = 16
atribuições como os bits de um contador e acha uma na décima primeira:

{{ideia}}

A fórmula fica numa matriz com os literais no formato `+v` / `-v` (o mesmo
dos arquivos DIMACS usados pelos programas que resolvem SAT), e o zero
encerra cada cláusula:

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

Repara no fluxograma: é o verificador. Ele passa uma vez por cada literal,
então custa O(tamanho da fórmula). A força bruta chama esse verificador até
2ⁿ vezes, e é aí que mora o exponencial:

{{fluxograma}}

O A371 mede quanto 2ⁿ cresce. O A372 mostra outro problema NP-completo com
o mesmo par verificador e força bruta: escolher boletos que somam
exatamente o valor de um Pix.

> [!WARNING]
> **NP não quer dizer "não polinomial".** Quer dizer *polinomial não
> determinístico*: um "chute" certo verificado em tempo polinomial. Todo
> problema de P está em NP. Outro tropeço de prova: NP-completo não é
> "impossível", é "não se conhece algoritmo polinomial". E reduzir A a B
> mostra que B é **pelo menos tão difícil** quanto A, não o contrário (0187).

> [!TIP]
> **Por dentro do C:** `1 << NV` é 2ⁿ, e a máscara é a atribuição: o bit
> `v - 1` diz se a variável `v` é verdadeira, lido com `(mascara >> (v - 1)) & 1`.
> Percorrer de 0 a 2ⁿ - 1 visita cada atribuição uma vez, sem recursão. Num
> `int` de 32 bits isso funciona até n = 30; com `1 << 31` o resultado não
> cabe num `int` com sinal (comportamento indefinido). Para mais variáveis
> use `unsigned long long` e `1ULL << n`, e espere sentado: 2⁶⁰ testes a um
> bilhão por segundo levam 36 anos.

> [!NOTE]
> **Pergunta para você:** se você trocar a ordem dos bits (Ana no bit mais
> alto e Davi no mais baixo), a força bruta acha a mesma atribuição? Em
> quantas tentativas? Responda antes de rodar.

{{pratique}}

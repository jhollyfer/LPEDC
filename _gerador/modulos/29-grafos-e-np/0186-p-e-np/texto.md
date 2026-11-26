## 0186 · P e NP

Você organiza o churrasco da firma com cinco condições: alguém precisa levar a
churrasqueira, dois colegas brigados não vão juntos, e assim por diante. Um
amigo sugere "chama a Ana e o Davi", e conferir se a sugestão atende às cinco
condições leva dez segundos. Achar um grupo bom sem palpite nenhum, porém,
pode exigir testar todas as combinações de convidados. A pergunta mais famosa
da computação gira em torno dessa diferença entre **achar** uma resposta e
**conferir** uma resposta pronta.

Para comparar problemas, a teoria olha só para **problemas de decisão**,
aqueles cuja resposta é sim ou não: "este grafo tem ciclo hamiltoniano?",
"existe rota de no máximo 300 km?". Isso não perde generalidade, porque um
problema de otimização ("qual a menor rota?") vira um de decisão quando você
fixa um limite e pergunta se dá para ficar abaixo dele. Se a decisão for
difícil, a otimização também é (CORMEN et al., 2024, cap. 34).

A classe **P** reúne os problemas de decisão que se **resolvem** em tempo
polinomial, isto é, com custo O(n^k) para algum k fixo, sendo n o tamanho da
entrada. Quase tudo o que você viu no curso está aqui: achar caminho mínimo,
testar circuito euleriano (0182), achar pontes (0184). Polinomial é a
fronteira que a teoria usa para "rápido": n³ cresce devagar perto de 2ⁿ
(CORMEN et al., 2024, cap. 34).

A classe **NP** exige menos: não pede para resolver, pede para **conferir**.
Um problema está em NP quando toda resposta "sim" tem um **certificado**, uma
prova curta, e existe um **verificador**, um algoritmo polinomial que recebe a
entrada e o certificado e confirma o "sim" (LINTZMAYER; MOTA, 2023). No
churrasco, o certificado é a lista de convidados; no ciclo hamiltoniano, é a
própria rota, que se confere numa passada. Se você resolve um problema rápido,
também confere rápido: basta ignorar o certificado e resolver. Por isso **P ⊆
NP**.

O nome engana. NP vem de *polinomial não determinístico*, porque a classe foi
definida com uma máquina que "chuta" o certificado certo e depois o confere.
Não quer dizer "não polinomial": todo problema de P também está em NP.

Dentro de NP há os problemas mais difíceis da classe. Um problema é
**NP-difícil** quando todo problema de NP se reduz a ele em tempo polinomial;
a redução é o assunto do 0187, e por ora basta a ideia de que resolver o
NP-difícil rápido resolveria todos os de NP rápido. Um problema é
**NP-completo** quando está em NP **e** é NP-difícil. A consequência é forte:
se um único NP-completo tiver algoritmo polinomial, então P = NP. Ninguém
sabe se isso acontece; a maioria dos pesquisadores aposta que P ≠ NP, e a
questão segue em aberto (KLEINBERG; TARDOS, 2006, cap. 8). A tabela resume as
quatro classes:

| Classe | O que se exige | Exemplos |
| --- | --- | --- |
| P | resolver em tempo polinomial | caminho mínimo, Euler, pontes, MST |
| NP | verificar um "sim" em tempo polinomial | tudo de P, SAT, clique, hamiltoniano |
| NP-completo | estar em NP e ser NP-difícil | SAT, 3-SAT, clique, cobertura de vértices, ciclo hamiltoniano |
| NP-difícil | todo NP se reduz a ele (pode nem estar em NP) | os NP-completos, caixeiro viajante (otimização) |

O primeiro problema provado NP-completo foi o **SAT**, a satisfatibilidade de
fórmulas lógicas (COOK, 1971). A fórmula vem em **forma normal conjuntiva**
(FNC): um E de **cláusulas**, e cada cláusula é um OU de **literais**, sendo
literal uma variável `x` ou a negação dela, `não x`. A pergunta é se existe
uma atribuição de verdadeiro e falso às variáveis que deixe todas as
cláusulas verdadeiras. No churrasco, cada colega é uma variável (vai ou não
vai) e cada condição é uma cláusula. O **3-SAT** limita cada cláusula a no
máximo três literais (no Cormen, exatamente três) e continua NP-completo
(KARP, 1972).

Sem algoritmo esperto, resta a força bruta: testar as 2ⁿ atribuições de n
variáveis. Em C, a atribuição cabe num inteiro, a **máscara**: o bit `v - 1`
diz se a variável `v` é verdadeira. Contar a máscara de 0 até 2ⁿ - 1 passa
por todas as atribuições, e cada uma é conferida pelo verificador:

```c
unsigned mascara = 10; // binário 1010
for (int v = 1; v <= 4; v++) {
    printf("x%d = %u\n", v, (mascara >> (v - 1)) & 1);
}
// x1 = 0
// x2 = 1
// x3 = 0
// x4 = 1
```

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

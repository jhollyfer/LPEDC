## 0126 · Permutações

No assunto 0125, a pergunta era quais itens entram. Agora todos entram, e a
pergunta é em que ordem. A organização de um sarau com três grupos, rap, samba
e forró, quer conhecer todas as ordens possíveis de apresentação para escolher
a melhor. Qualquer um dos 3 pode abrir a noite; para o segundo lugar sobram 2;
para o último, 1. São 3 × 2 × 1 = 6 ordens.

Cada ordem é uma **permutação**: um arranjo dos `n` elementos em sequência,
usando cada um exatamente uma vez. A conta do sarau vale em geral: há `n`
escolhas para a primeira posição, `n - 1` para a segunda, e assim por diante
até 1, e o total é o fatorial, **n!** (FEOFILOFF, 2009).

A recursão gera as permutações decidindo **uma posição por vez**. A função
`permuta(v, i)` trabalha com uma promessa: as posições `0` até `i - 1` do vetor
já estão decididas, e os candidatos à posição `i` são os elementos que sobraram,
guardados em `v[i..n-1]` (WIRTH, 1989). Quando `i` chega a `n`, não há mais
posição a decidir, e a ordem completa é mostrada.

Para cada candidato `j`, de `i` até `n - 1`, a função faz três movimentos.
**Escolhe**: troca `v[i]` com `v[j]`, e o candidato vai para a posição `i`.
**Desce**: chama `permuta(v, i + 1)`, que cuida das posições seguintes.
**Desfaz**: troca `v[i]` com `v[j]` de novo, e o vetor volta a ser o que era
antes da escolha (FEOFILOFF, 2009). Com o vetor {rap, samba, forró} e `i = 0`,
a primeira volta do laço troca o rap com ele mesmo e gera as ordens que abrem
com rap; a segunda troca rap com samba e gera as que abrem com samba; a
terceira, as que abrem com forró.

O terceiro movimento é o que separa este assunto do anterior. Nos
subconjuntos, a escolha ficava num parâmetro e se desfazia sozinha na volta da
chamada. Aqui a troca mexe no **vetor**, e o vetor é um só, compartilhado por
todas as chamadas, porque o C passa vetor como endereço. Se você não destroca,
a próxima volta do laço recebe o vetor bagunçado pela chamada anterior, e os
candidatos deixam de ser os que deveriam (TENENBAUM; LANGSAM; AUGENSTEIN,
1995, cap. 3).

Um efeito colateral das trocas: as ordens não saem em ordem de dicionário.
Para três elementos a diferença aparece só no fim, mas cresce com `n`. Quem
precisa da ordem lexicográfica usa outro método de geração (KNUTH, 2011).

O custo cresce mais rápido que o dos subconjuntos. São `n!` folhas, e cada uma
gasta `n` passos para mostrar a ordem, então o total é **O(n · n!)**, pior que
O(n · 2ⁿ). Para ter ideia, 13! vale 6.227.020.800 e já não cabe num `int` de
32 bits; 20!, cerca de 2,4 · 10¹⁸, fica perto do limite de um `long long`
(FEOFILOFF, 2009). Se os elementos são textos, troque os ponteiros e não os
textos: trocar dois `char *` custa 8 bytes por elemento, qualquer que seja o
tamanho do nome.

> [!WARNING]
> Sem o **desfaz**, o programa ainda mostra n! linhas, mas com ordens
> repetidas e outras faltando. Toda alteração feita antes da chamada recursiva
> é desfeita depois dela, na ordem inversa.

{{exemplo}}

Num sarau, três grupos (rap, samba e forró) se apresentam em todas as ordens
possíveis. As 6 folhas da árvore são as 6 ordens, na sequência da saída:

{{ideia}}

O vetor guarda ponteiros para os nomes (assunto 0048): trocar dois elementos é
trocar dois ponteiros, e os textos não saem do lugar.

```c
#include <stdio.h>

#define N 3

int ordens = 0;

void troca(const char **a, const char **b) {
    const char *t = *a;   // troca só os ponteiros, não as letras
    *a = *b;
    *b = t;
}

// as posições 0..i-1 já estão decididas; decide a posição i
void permuta(const char *v[], int i) {
    if (i == N) {
        ordens++;
        printf("%d: %s, %s, %s\n", ordens, v[0], v[1], v[2]);
        return;
    }
    for (int j = i; j < N; j++) {
        troca(&v[i], &v[j]);    // escolhe: v[j] vai para a posição i
        permuta(v, i + 1);      // decide o resto
        troca(&v[i], &v[j]);    // desfaz: devolve o vetor como estava
    }
}

int main(void) {
    const char *shows[N] = {"Rap", "Samba", "Forró"};
    permuta(shows, 0);
    printf("%d ordens; no fim: %s, %s, %s\n", ordens, shows[0], shows[1], shows[2]);
    return 0;
}
// Saída:
// 1: Rap, Samba, Forró
// 2: Rap, Forró, Samba
// 3: Samba, Rap, Forró
// 4: Samba, Forró, Rap
// 5: Forró, Samba, Rap
// 6: Forró, Rap, Samba
// 6 ordens; no fim: Rap, Samba, Forró
```

Na última linha, o vetor voltou a ser `Rap, Samba, Forró`: cada chamada
desfez o que fez. O laço do `j` abre os ramos, com troca e destroca em volta da
chamada recursiva:

{{fluxograma}}

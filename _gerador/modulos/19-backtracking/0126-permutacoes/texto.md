## 0126 · Permutações

Num sarau, três grupos (rap, samba e forró) se apresentam, e a organização quer
todas as ordens possíveis: 3 × 2 × 1 = **6**. Cada ordem é uma
**permutação**, e `n` elementos têm **n!** delas.

A recursão decide **uma posição por vez**. `permuta(v, i)` sabe que `0..i-1`
já estão decididas, e os candidatos à posição `i` são os de `v[i..n-1]`. Para
cada `j` de `i` até `n - 1`:

1. **escolhe**: troca `v[i]` com `v[j]`;
2. **desce**: chama `permuta(v, i + 1)`;
3. **desfaz**: troca `v[i]` com `v[j]` de novo.

O passo 3 é indispensável: no assunto anterior, a escolha se desfazia sozinha
por estar num parâmetro; aqui ela mexe no **vetor**, que é um só para todas as
chamadas. Quando `i` chega a `n`, a ordem é mostrada. As 6 folhas da árvore
são as 6 ordens, na sequência em que o programa as mostra:

{{ideia}}

O vetor guarda ponteiros para os nomes (assunto 0048): trocar dois elementos
é trocar dois ponteiros, e os textos não saem do lugar.

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
desfez o que fez. A ordem de saída **não** é a de dicionário (quem precisa
dela usa o exemplo A251).

O laço do `j` abre os ramos, e cada volta tem o par troca e destroca em volta
da chamada recursiva:

{{fluxograma}}

> [!WARNING]
> Sem o **desfaz**, o programa ainda mostra 6 linhas, mas com ordens repetidas
> e outras faltando, e o vetor termina bagunçado. Toda alteração feita antes
> da chamada recursiva precisa ser desfeita depois dela, na ordem inversa.

> [!TIP]
> **Por dentro do C:** são `n!` folhas, e cada uma gasta `n` passos para
> mostrar: o custo é **O(n · n!)**, pior que os 2ⁿ dos subconjuntos. 13!
> (6.227.020.800) não cabe num `int` de 32 bits, e 20! (cerca de 2,4 · 10¹⁸)
> fica no limite de um `long long`. Trocar ponteiros custa 8 bytes por
> elemento, qualquer que seja o tamanho do nome.

> [!NOTE]
> **Pergunta para você:** com um quarto grupo, de pagode, no fim do vetor,
> quantas linhas saem? Qual grupo abre o sarau na linha 7? E na 19?

{{pratique}}

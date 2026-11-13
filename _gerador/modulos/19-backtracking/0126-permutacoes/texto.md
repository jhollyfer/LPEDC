## 0126 · Permutações

- **Permutação**: uma ordem dos `n` elementos. Há **n!** delas: `n` escolhas
  para a primeira posição, `n - 1` para a segunda, e assim por diante
  (FEOFILOFF, 2009).
- **Uma posição por vez**: `permuta(v, i)` sabe que `0..i-1` já estão
  decididas; os candidatos à posição `i` estão em `v[i..n-1]`
  (WIRTH, 1989).
- **Escolhe, desce, desfaz**: para cada `j` de `i` a `n - 1`, troca `v[i]` com
  `v[j]`, chama `permuta(v, i + 1)` e troca de novo (FEOFILOFF, 2009).
- **Desfazer**: a troca mexe no **vetor**, que é um só para todas as chamadas.
  Sem destrocar, as chamadas seguintes recebem o vetor bagunçado
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 3).
- **Ordem de saída**: o método da troca **não** gera a ordem de dicionário
  (KNUTH, 2011).
- **Custo**: `n!` folhas com `n` passos cada, **O(n · n!)**, pior que os 2ⁿ
  dos subconjuntos. 13! já não cabe num `int` de 32 bits (FEOFILOFF, 2009).

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

## 0090 · Busca binária

- **Busca binária**: num vetor **ordenado**, olha a gaveta do meio. Se tem a
  chave, acabou; se a chave é maior, descarta a esquerda; se é menor,
  descarta a direita. Cada pergunta joga fora metade do que sobrou
  (ZIVIANI, 2010, cap. 5).
- **Invariante** (0073): "se `x` está no vetor, está em `v[ini..fim]`", com
  os dois extremos inclusive. Quando `ini` passa de `fim`, o intervalo está
  vazio e a resposta é `-1` (FEOFILOFF, 2009).
- **Custo**: com 15 elementos sobram 15, 7, 3, 1, no máximo 4 voltas; com um
  milhão, 20. Pior caso ⌊log₂ n⌋ + 1 voltas, **O(log n)** (0072)
  (ZIVIANI, 2010, cap. 5).
- **Pré-condição**: o vetor tem de estar ordenado. Num vetor bagunçado, a
  busca responde errado sem avisar (FEOFILOFF, 2009).
- **Meio sem overflow**: `ini + (fim - ini) / 2`. Com `(ini + fim) / 2`, a
  soma passa de `INT_MAX` em vetores enormes, bug que ficou anos escondido em
  bibliotecas (BLOCH, 2006).

> [!WARNING]
> Busca binária é famosa por erros de um. Com o intervalo fechado `[ini, fim]`,
> `while (ini < fim)` deixa de olhar o último candidato e `fim = meio` pode
> nunca encolher. Escolha um estilo (fechado ou semiaberto `[ini, fim)`) e
> siga as regras dele.

{{exemplo}}

O catálogo do atacadão tem 15 códigos em ordem e você procura o 216. O meio
(índice 7) tem 189, menor: a esquerda sai. O novo meio (11) tem 245, maior: a
direita sai. Na terceira volta, o meio (9) é o 216:

{{ideia}}

Um `printf` mostra o intervalo de cada volta:

```c
#include <stdio.h>

// v está em ordem crescente; devolve o índice de x ou -1
int busca_binaria(const int v[], int n, int x, int *voltas) {
    int ini = 0, fim = n - 1;
    *voltas = 0;
    while (ini <= fim) {              // ainda sobra alguém no intervalo
        int meio = ini + (fim - ini) / 2;
        (*voltas)++;
        printf("  ini=%2d fim=%2d meio=%2d v[meio]=%d\n", ini, fim, meio, v[meio]);
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;           // x só pode estar à direita
        } else {
            fim = meio - 1;           // x só pode estar à esquerda
        }
    }
    return -1;
}

int main(void) {
    int codigos[] = {103, 118, 125, 140, 152, 167, 171, 189,
                     204, 216, 230, 245, 258, 263, 279};
    int n = sizeof codigos / sizeof codigos[0];
    int voltas;

    printf("Procurando 216:\n");
    int pos = busca_binaria(codigos, n, 216, &voltas);
    printf("posição %d em %d voltas\n", pos, voltas);

    printf("Procurando 150:\n");
    pos = busca_binaria(codigos, n, 150, &voltas);
    printf("posição %d em %d voltas\n", pos, voltas);
    return 0;
}
// Saída:
// Procurando 216:
//   ini= 0 fim=14 meio= 7 v[meio]=189
//   ini= 8 fim=14 meio=11 v[meio]=245
//   ini= 8 fim=10 meio= 9 v[meio]=216
// posição 9 em 3 voltas
// Procurando 150:
//   ini= 0 fim=14 meio= 7 v[meio]=189
//   ini= 0 fim= 6 meio= 3 v[meio]=140
//   ini= 4 fim= 6 meio= 5 v[meio]=167
//   ini= 4 fim= 4 meio= 4 v[meio]=152
// posição -1 em 4 voltas
```

### Passo a passo

A busca por 150, que não está no catálogo:

| volta | ini | fim | meio | v[meio] | decisão |
| --- | --- | --- | --- | --- | --- |
| 1 | 0 | 14 | 7 | 189 | 189 > 150: `fim = 6` |
| 2 | 0 | 6 | 3 | 140 | 140 < 150: `ini = 4` |
| 3 | 4 | 6 | 5 | 167 | 167 > 150: `fim = 4` |
| 4 | 4 | 4 | 4 | 152 | 152 > 150: `fim = 3` |
| fim | 4 | 3 | | | `ini > fim`: devolve `-1` |

O `ini = 4` final é a posição em que o 150 **deveria** entrar (exemplo A180).

Três perguntas por volta, e cada volta mexe em `ini` **ou** em `fim`, nunca
nos dois:

{{fluxograma}}

## 0090 · Busca binária

No jogo "pensei num número de 1 a 100", quem chuta 1, 2, 3 e assim por diante
pode precisar de 100 tentativas. Quem chuta 50, ouve "menor", chuta 25, ouve
"maior", chuta 37, acerta em no máximo 7. A diferença é que cada resposta
"maior" ou "menor" descarta metade dos números que ainda eram possíveis. A
busca sequencial do 0089 não aproveita nada disso, porque olhar um elemento
não diz nada sobre os outros. Num vetor **ordenado**, diz.

A **busca binária** é esse jogo num vetor ordenado. Você olha a gaveta do
meio. Se ela tem a chave, acabou. Se a chave é maior que o valor do meio, ela
só pode estar à direita, e a metade esquerda é descartada. Se é menor, a
direita é descartada. Cada comparação joga fora metade do que sobrou
(ZIVIANI, 2010, cap. 5).

O código guarda o pedaço que ainda pode conter a chave entre dois índices,
`ini` e `fim`, com os dois extremos incluídos. Essa frase vira um
**invariante**, a afirmação que o assunto 0073 ensinou a manter verdadeira em
toda volta do laço: "se `x` está no vetor, está em `v[ini..fim]`". No começo,
`ini` vale 0 e `fim` vale `n - 1`, e o invariante vale porque o pedaço é o
vetor inteiro. A cada volta, um dos extremos pula para depois do meio, e o
invariante continua valendo. Quando `ini` passa de `fim`, o pedaço está vazio,
e o invariante garante que a chave não está no vetor: a resposta é `-1`
(FEOFILOFF, 2009).

```c
while (ini <= fim) {
    int meio = ini + (fim - ini) / 2;
    if (v[meio] == x) return meio;
    if (v[meio] < x) ini = meio + 1; // descarta a esquerda e o meio
    else fim = meio - 1;             // descarta a direita e o meio
}
return -1;
```

O ganho aparece no custo. Com 15 elementos, o pedaço passa por 15, 7, 3 e 1:
no máximo **4** voltas. Com um milhão de elementos, 20 voltas. No pior caso a
busca faz ⌊log₂ n⌋ + 1 voltas, e na notação do 0072 isso é **O(log n)**
(ZIVIANI, 2010, cap. 5). Dobrar o vetor custa só uma volta a mais, enquanto na
busca sequencial dobrar o vetor dobra o trabalho.

O preço é a pré-condição: o vetor tem de estar ordenado. Num vetor bagunçado,
a busca binária não trava nem dá erro, ela só responde errado, e sem avisar
(FEOFILOFF, 2009). Se o vetor muda o tempo todo, manter a ordem pode custar
mais que a economia na busca; os assuntos 0091 a 0096 tratam de como ordenar.

Repare na conta do meio. A forma `(ini + fim) / 2` parece natural, mas a soma
pode passar de `INT_MAX`, o maior `int`, em vetores com mais de um bilhão de
elementos, e o resultado vira um índice negativo. A forma
`ini + (fim - ini) / 2` dá o mesmo meio sem nunca somar dois índices grandes.
Esse bug ficou anos escondido em bibliotecas usadas no mundo todo (BLOCH,
2006).

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

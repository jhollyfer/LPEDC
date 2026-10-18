## 0090 · Busca binária

Lembra da brincadeira "pensei num número de 1 a 100"? Quem chuta 1, 2, 3...
pode precisar de 100 tentativas. Quem chuta 50, ouve "menor", chuta 25 e assim
por diante, acerta em no máximo 7. A diferença é uma informação a mais: a
ordem.

A **busca binária** é esse jogo num vetor **ordenado**. Olhe a gaveta do
meio. Se ela tem a chave, acabou. Se a chave é maior, tudo o que está à
esquerda do meio é menor ainda e pode ser **descartado** de uma vez. Se é
menor, descarte a direita. Cada pergunta joga fora metade do que sobrou.

O código guarda o pedaço que ainda pode ter a chave entre dois índices, `ini`
e `fim` (os dois inclusive). Isso é um **invariante** (assunto 0073): "se `x`
está no vetor, está em `v[ini..fim]`". Cada volta encolhe o intervalo e mantém
o invariante. Quando `ini` passa de `fim`, o intervalo ficou vazio e a
resposta é `-1`.

Quantas voltas? Com 15 elementos sobram 15, 7, 3, 1: no máximo **4**. Com um
milhão, no máximo 20. Com um bilhão, 30. É o **O(log n)** do assunto 0072: a
cada vez que `n` dobra, a busca ganha só **uma** volta a mais.

O preço é a pré-condição: o vetor precisa estar em ordem. Num vetor bagunçado,
a busca binária não dá erro nenhum, só responde errado. Ordenar custa caro, e
é por isso que o resto do módulo existe.

Vamos ver na prática. O catálogo do atacadão tem 15 códigos em ordem e você
procura o 216. O meio (índice 7) tem 189, menor que 216: a metade esquerda
inteira fica cinza. O novo meio (11) tem 245, maior: a direita dele também
sai. Na terceira volta, o meio (9) é o 216:

{{ideia}}

O mesmo exemplo em C. O `printf` dentro do laço mostra o intervalo de cada
volta:

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

A busca por 150, que não está no catálogo. Repara no intervalo encolhendo até
ficar vazio:

| volta | ini | fim | meio | v[meio] | decisão |
| --- | --- | --- | --- | --- | --- |
| 1 | 0 | 14 | 7 | 189 | 189 > 150: `fim = 6` |
| 2 | 0 | 6 | 3 | 140 | 140 < 150: `ini = 4` |
| 3 | 4 | 6 | 5 | 167 | 167 > 150: `fim = 4` |
| 4 | 4 | 4 | 4 | 152 | 152 > 150: `fim = 3` |
| fim | 4 | 3 | | | `ini > fim`: devolve `-1` |

Repara que o `ini = 4` final é exatamente onde o 150 **deveria** estar para o
vetor continuar ordenado. Essa informação vale ouro (veja o exemplo A180).

Repara no fluxograma: diferente da busca sequencial, aqui são três perguntas
por volta. A volta termina mexendo em `ini` **ou** em `fim`, nunca nos dois:

{{fluxograma}}

> [!WARNING]
> Busca binária é famosa por erros de um. `while (ini < fim)` com o intervalo
> fechado `[ini, fim]` deixa de olhar o último candidato. E `fim = meio` (em
> vez de `meio - 1`) no intervalo fechado pode nunca encolher: com `ini = 4` e
> `fim = 4`, o meio é 4 de novo, para sempre. Escolha um estilo (fechado, como
> no A179, ou semiaberto `[ini, fim)`, como no A180) e siga as regras dele em
> todas as linhas.

> [!TIP]
> **Por dentro do C:** por que `ini + (fim - ini) / 2` e não
> `(ini + fim) / 2`? Num vetor com mais de 1 bilhão de elementos, `ini + fim`
> passa de `INT_MAX` (2.147.483.647) e dá **overflow**, que no C é
> comportamento indefinido. Esse bug ficou escondido por anos em
> implementações famosas da busca binária e só apareceu em 2006, quando os vetores ficaram
> grandes. Outro detalhe: a busca binária pula pela memória (índice 7, depois
> 11, depois 9), então não aproveita a linha de cache como a sequencial. Por
> isso, para vetores bem pequenos, a sequencial pode ganhar. A `stdlib.h` traz
> uma pronta, a `bsearch`, que você vai usar no assunto 0096.

> [!NOTE]
> **Pergunta para você:** quantas voltas o A179 dá para achar o 103, o
> primeiro do catálogo? E qual é o máximo de voltas para um vetor de 1000
> elementos? Faça o teste de mesa antes de rodar.

{{pratique}}

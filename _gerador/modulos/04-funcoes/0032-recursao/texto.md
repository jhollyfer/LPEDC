## 0032 · Recursão

Cinco amigos vão ao cinema e querem saber de quantos jeitos podem sentar nas
cinco cadeiras. O primeiro tem 5 escolhas. Depois que ele senta, o problema
fica **igual, mas menor**: de quantos jeitos 4 pessoas sentam em 4 cadeiras?
O segundo tem 4 escolhas, e o problema encolhe de novo, até sobrar 1 pessoa
com 1 jeito. A resposta é 5 × 4 × 3 × 2 × 1 = 120, o **fatorial** de 5,
escrito 5!.

Repare no raciocínio: "para resolver o de 5, resolvo o de 4 e multiplico por
5". Você descreveu o problema usando ele mesmo, em tamanho menor. Uma função
que faz isso, que resolve um problema chamando **a si mesma** com uma versão
menor dele, é uma **função recursiva** (DEITEL; DEITEL, 2011, cap. 5). Pense
numa boneca russa: para chegar à menor, você abre uma boneca e encontra outra
igual, só que menor, e repete até a última, que não abre.

Toda função recursiva tem duas partes (FEOFILOFF, 2009, cap. 5). O **caso
base** é o problema pequeno o bastante para responder direto, sem nova
chamada: com 1 pessoa, há 1 jeito. É a boneca que não abre. O **caso
recursivo** reduz o problema a um menor e usa a resposta dele: para `n`
pessoas, a resposta é `n * fatorial(n - 1)`. Em C, as duas partes cabem num
`if`: se `n <= 1`, devolva 1; senão, devolva `n * fatorial(n - 1)`.

Uma regra não pode falhar: cada chamada tem de chegar **mais perto** do caso
base (FEOFILOFF, 2009, cap. 5). No fatorial, o `n` diminui 1 a cada chamada e
acaba chegando a 1. Se o problema não encolhe, ou encolhe sem nunca acertar o
caso base, a função chama a si mesma para sempre.

Na hora de escrever, **confie na função** (FEOFILOFF, 2009, cap. 5). Não
tente seguir todas as chamadas de cabeça, porque elas se aninham fundo
demais. Suponha que `fatorial(n - 1)` já funciona e pergunte: com essa
resposta na mão, como monto a de `n`? Depois confira o caso base em separado.
Se os dois estão certos, a função está certa para qualquer `n`. É o mesmo
raciocínio da indução matemática.

Por dentro, nada de especial acontece: cada chamada recursiva é uma chamada
comum e ganha **seu próprio quadro** na pilha do assunto 0031 (BACKES, 2013,
cap. 9). Na **ida**, `fatorial(5)` chama `fatorial(4)`, que chama `fatorial(3)`, e
a pilha cresce até `fatorial(1)`. Nesse ponto há cinco quadros de `fatorial`
ao mesmo tempo, cada um com o seu `n`, todos parados menos o do topo. Na
**volta**, o caso base devolve 1, e cada quadro recebe a resposta de cima,
multiplica pelo seu `n` e devolve ao de baixo: 1, 2, 6, 24, 120.

Recursão e laço resolvem os mesmos problemas: todo cálculo recursivo pode ser
reescrito com repetição, e vice-versa (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
cap. 3). A diferença está no custo e na clareza. A recursão gasta memória
proporcional à **profundidade**: `fatorial(5)` ocupa 5 quadros de uma vez,
enquanto um laço usaria um só. Ela compensa quando o problema já é recursivo
por natureza, como percorrer uma árvore ou dividir um vetor ao meio, porque aí
a versão com laço fica bem mais difícil de ler.

O tipo também impõe limite. O fatorial cresce muito depressa: 12! =
479.001.600 cabe num `int` de 32 bits, mas 13! = 6.227.020.800 passa do
máximo de 2.147.483.647 e estoura.

> [!WARNING]
> Caso base que nunca chega. Com `if (n == 1)` no lugar de `if (n <= 1)`,
> `fatorial(0)` chama `fatorial(-1)`, `fatorial(-2)`... e não para. Cada
> chamada empilha um quadro, a pilha acaba e o programa morre com **stack
> overflow** (`Segmentation fault`).

{{exemplo}}

De quantos jeitos 5 amigos sentam em 5 cadeiras? 5 × 4 × 3 × 2 × 1 = 120. Na
ida a pilha cresce até `fatorial(1)`; na volta cada quadro multiplica e
devolve: 1, 2, 6, 24, 120:

{{ideia}}

```c
#include <stdio.h>

int fatorial(int n) {
    if (n <= 1) {
        return 1; // caso base: resolve direto, sem chamar ninguém
    }
    return n * fatorial(n - 1); // caso recursivo: um problema menor
}

int main(void) {
    printf("5 amigos: %d jeitos\n", fatorial(5));
    printf("12 amigos: %d jeitos\n", fatorial(12)); // o maior que cabe num int
    return 0;
}
// Saída:
// 5 amigos: 120 jeitos
// 12 amigos: 479001600 jeitos
```

Não há laço no código, mas o fluxograma tem duas voltas: a ida (empilha com
`n - 1`) e a volta (cada quadro multiplica e sai):

{{fluxograma}}

### Passo a passo

O teste de mesa de `fatorial(5)`. As chamadas descem; os retornos sobem:

| Chamada | n | `n <= 1`? | Espera | Devolve |
| --- | --- | --- | --- | --- |
| `fatorial(5)` | 5 | Não | `5 * fatorial(4)` | 5 × 24 = **120** |
| `fatorial(4)` | 4 | Não | `4 * fatorial(3)` | 4 × 6 = 24 |
| `fatorial(3)` | 3 | Não | `3 * fatorial(2)` | 3 × 2 = 6 |
| `fatorial(2)` | 2 | Não | `2 * fatorial(1)` | 2 × 1 = 2 |
| `fatorial(1)` | 1 | Sim | nada | 1 |

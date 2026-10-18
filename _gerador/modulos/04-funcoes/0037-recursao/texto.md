## 0037 · Recursão

Cinco amigos vão ao cinema e querem saber de quantos jeitos dá para sentar nas
cinco cadeiras. O primeiro tem 5 escolhas. Depois que ele senta, o problema
virou outro, **igual mas menor**: de quantos jeitos 4 pessoas sentam em 4
cadeiras? E assim vai, até sobrar 1 pessoa, que só tem 1 jeito. A resposta é
5 × 4 × 3 × 2 × 1 = 120, o **fatorial** de 5.

Repare no raciocínio: "para resolver o de 5, eu resolvo o de 4 e multiplico
por 5". Uma função que resolve o problema chamando **a si mesma** com uma
versão menor do problema é uma **função recursiva**. Ela tem sempre duas
partes:

- o **caso base**: o problema pequeno o bastante para responder direto, sem
  chamar ninguém (1 pessoa: 1 jeito);
- o **caso recursivo**: reduz o problema a um menor e usa a resposta dele
  (`n * fatorial(n - 1)`).

E uma regra que não pode falhar: cada chamada tem que chegar **mais perto** do
caso base. Se não chega, a função chama a si mesma para sempre.

Um jeito bom de pensar é **confiar na função**. Ao escrever o caso recursivo,
não tente seguir as chamadas de cabeça. Suponha que `fatorial(n - 1)` já
funciona e pergunte só: com essa resposta na mão, como eu monto a de `n`?
Depois confira o caso base. Se os dois estão certos, a função está certa.

Não tem mágica: cada chamada é uma chamada comum, com o **seu próprio quadro**
na pilha (assunto 0036). `fatorial(5)` empilha `fatorial(4)`, que empilha
`fatorial(3)`... São cinco quadros de `fatorial` ao mesmo tempo, cada um com o
seu `n`, e todos parados esperando, menos o do topo.

Vamos ver na prática. Na **ida**, a pilha cresce até `fatorial(1)`, que é o
caso base e devolve 1 sem chamar ninguém. Na **volta**, cada quadro recebe a
resposta de cima, faz a sua multiplicação e devolve para o de baixo: 1, 2, 6,
24, 120:

{{ideia}}

O código é quase a definição matemática:

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

Repara no fluxograma: não existe `for` nem `while` no código, mas existem
duas voltas. A primeira é a ida (empilha de novo com `n - 1` até o caso
base); a segunda é a volta (cada quadro esperando faz a sua multiplicação e
sai):

{{fluxograma}}

### Passo a passo

O teste de mesa de `fatorial(5)`. As chamadas descem; os retornos sobem, de
baixo para cima da tabela:

| Chamada | n | `n <= 1`? | Espera | Devolve |
| --- | --- | --- | --- | --- |
| `fatorial(5)` | 5 | Não | `5 * fatorial(4)` | 5 × 24 = **120** |
| `fatorial(4)` | 4 | Não | `4 * fatorial(3)` | 4 × 6 = 24 |
| `fatorial(3)` | 3 | Não | `3 * fatorial(2)` | 3 × 2 = 6 |
| `fatorial(2)` | 2 | Não | `2 * fatorial(1)` | 2 × 1 = 2 |
| `fatorial(1)` | 1 | Sim | nada | 1 |

Recursão e laço resolvem os mesmos problemas: todo `for` vira recursão e toda
recursão vira laço (às vezes com bastante trabalho). O fatorial com `for` é
até mais simples e mais barato. A recursão brilha quando o problema **é**
recursivo por natureza: pastas dentro de pastas, árvores, "divide ao meio e
resolve cada metade".

> [!WARNING]
> Caso base que nunca chega. Com `if (n == 1)` no lugar de `if (n <= 1)`,
> `fatorial(0)` chama `fatorial(-1)`, que chama `fatorial(-2)`... e nunca para.
> O mesmo acontece se você esquecer de diminuir (`fatorial(n)` em vez de
> `fatorial(n - 1)`). Cada chamada empilha um quadro, a pilha acaba e o
> programa morre com **stack overflow**: o AddressSanitizer mostra
> `stack-overflow`, e sem ele aparece só `Segmentation fault`.

> [!TIP]
> **Por dentro do C:** cada `fatorial` empilha um quadro com o `n`, o
> endereço de retorno e espaço para a conta pendente. Por isso a recursão
> gasta memória proporcional à **profundidade**: `fatorial(5)` usa 5 quadros
> de uma vez; um laço usaria um só. Outro limite é o tipo: 12! = 479.001.600
> cabe num `int` de 32 bits, mas 13! = 6.227.020.800 já não cabe e dá
> overflow (o `-fsanitize=undefined` do `rodar` acusa). Curiosidade: com
> `gcc -O2`, o compilador às vezes transforma a recursão em laço sozinho.

> [!NOTE]
> **Pergunta para você:** quanto vale `fatorial(0)` com o código acima? E
> quantos quadros de `fatorial` a chamada `fatorial(12)` empilha no ponto mais
> fundo?

{{pratique}}

## 0032 · Recursão

Cinco amigos vão ao cinema e querem saber de quantos jeitos podem sentar nas
cinco cadeiras. O primeiro tem 5 escolhas. Depois que ele senta, o problema é
**igual, mas menor**: de quantos jeitos 4 pessoas sentam em 4 cadeiras? E assim
até sobrar 1 pessoa, com 1 jeito. A resposta é 5 × 4 × 3 × 2 × 1 = 120, o
**fatorial** de 5.

O raciocínio foi: "para resolver o de 5, resolvo o de 4 e multiplico por 5".
Uma função que resolve o problema chamando **a si mesma** com uma versão menor
dele é uma **função recursiva**. Ela tem duas partes:

- o **caso base**: o problema pequeno o bastante para responder direto, sem
  chamar ninguém (1 pessoa: 1 jeito);
- o **caso recursivo**: reduz o problema a um menor e usa a resposta dele
  (`n * fatorial(n - 1)`).

Regra que não pode falhar: cada chamada tem que chegar **mais perto** do caso
base. Senão a função chama a si mesma para sempre.

**Confie na função.** Ao escrever o caso recursivo, não siga as chamadas de
cabeça. Suponha que `fatorial(n - 1)` já funciona e pergunte: com essa resposta
na mão, como monto a de `n`? Depois confira o caso base. Com os dois certos, a
função está certa.

Cada chamada recursiva é comum, com **seu próprio quadro** na pilha (assunto
0031). `fatorial(5)` empilha `fatorial(4)`, que empilha `fatorial(3)`... São
cinco quadros de `fatorial` ao mesmo tempo, cada um com seu `n`, todos
parados, menos o do topo.

Na **ida**, a pilha cresce até `fatorial(1)`, o caso base, que devolve 1 sem
chamar ninguém. Na **volta**, cada quadro recebe a resposta de cima, multiplica
e devolve ao de baixo: 1, 2, 6, 24, 120:

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

Não há `for` nem `while`, mas o fluxograma tem duas voltas. A primeira é a ida
(empilha de novo com `n - 1` até o caso base); a segunda é a volta (cada quadro
em espera multiplica e sai):

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
recursão vira laço (às vezes com muito trabalho). O fatorial com `for` é mais
simples e mais barato. A recursão compensa quando o problema **é** recursivo
por natureza: pastas dentro de pastas, árvores, "divide ao meio e resolve cada
metade".

> [!WARNING]
> Caso base que nunca chega. Com `if (n == 1)` no lugar de `if (n <= 1)`,
> `fatorial(0)` chama `fatorial(-1)`, `fatorial(-2)`... e nunca para. O mesmo
> ocorre se você esquecer de diminuir (`fatorial(n)` em vez de
> `fatorial(n - 1)`). Cada chamada empilha um quadro, a pilha acaba e o
> programa morre com **stack overflow**: o AddressSanitizer mostra
> `stack-overflow`, e sem ele aparece só `Segmentation fault`.

> [!TIP]
> A recursão gasta memória proporcional à **profundidade**: `fatorial(5)` usa
> 5 quadros de uma vez; um laço usaria um. Outro limite é o tipo: 12! =
> 479.001.600 cabe num `int` de 32 bits, mas 13! = 6.227.020.800 dá overflow (o
> `-fsanitize=undefined`, nas flags de estudo, acusa).

> [!NOTE]
> **Pergunta para você:** quanto vale `fatorial(0)` com o código acima? E
> quantos quadros de `fatorial` a chamada `fatorial(12)` empilha no ponto mais
> fundo?

{{pratique}}

## 0032 · Recursão

- **Função recursiva**: resolve o problema chamando a si mesma com uma versão
  menor dele (DEITEL; DEITEL, 2011, cap. 5).
- **Caso base**: o problema pequeno o bastante para responder direto, sem nova
  chamada (FEOFILOFF, 2009, cap. 5).
- **Caso recursivo**: reduz o problema e usa a resposta menor
  (`n * fatorial(n - 1)`). Cada chamada tem de chegar **mais perto** do caso
  base (FEOFILOFF, 2009, cap. 5).
- **Confie na função**: suponha que a chamada menor já funciona e monte a
  resposta de `n` com ela; depois confira o caso base (FEOFILOFF, 2009, cap. 5).
- **Ida e volta**: cada chamada tem seu quadro (assunto 0031). Na ida a pilha
  cresce até o caso base; na volta cada quadro combina a resposta e sai
  (BACKES, 2013, cap. 9).
- **Recursão e laço**: resolvem os mesmos problemas. A recursão gasta memória
  proporcional à profundidade e compensa quando o problema é recursivo por
  natureza: árvores, "divide ao meio" (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
  cap. 3).

> [!WARNING]
> Caso base que nunca chega: com `if (n == 1)`, `fatorial(0)` chama
> `fatorial(-1)` e não para. A pilha estoura (**stack overflow**,
> `Segmentation fault`). E 13! já não cabe num `int` de 32 bits.

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

## 0131 · Divisão e conquista

Uma corrente do grupo da família: quem recebe repassa para 3 contatos.
Quantas mensagens saem na rodada 20? A conta é 3²⁰, e um laço que multiplica
por 3 vinte vezes gasta multiplicação demais.

Mas 3²⁰ = 3¹⁰ · 3¹⁰: quem sabe 3¹⁰ resolve 3²⁰ com **uma** multiplicação. E
3¹⁰ = 3⁵ · 3⁵, e 3⁵ = 3² · 3² · 3 (expoente ímpar deixa sobrar um 3). O
problema vira outro do mesmo tipo, com metade do tamanho.

Essa é a **divisão e conquista** (*divide and conquer*), com três passos que
você já viu no merge sort (0094):

1. **dividir**: quebre o problema em pedaços menores do mesmo tipo;
2. **conquistar**: resolva cada pedaço com a própria função (recursão, 0032).
   Pedaço pequeno o bastante é o **caso base**, resolvido direto;
3. **combinar**: junte as respostas dos pedaços na resposta do todo.

A busca binária (0090) divide e descarta uma metade. O merge sort gasta o
esforço na combinação; o quick sort (0095), na divisão, e não combina nada.

Na potência, dividir é cortar o expoente ao meio e combinar é elevar ao
quadrado (com mais um `x` se o expoente é ímpar). O caso base é `n == 0`,
porque x⁰ = 1.

Cada chamada corta `n` pela metade: T(n) = T(n/2) + O(1), que dá
**O(log n)** pelo assunto 0115. Para n = 1 milhão, são uns 20 níveis contra
1 milhão de voltas do laço.

No desenho, a recursão desce dividindo o expoente (20, 10, 5, 2, 1, 0) e sobe
combinando: o 1 do caso base vira 3, 9, 243, e assim até 3²⁰.

{{ideia}}

O `printf` mostra cada resultado parcial quando a chamada termina, e `mult`
soma as multiplicações:

```c
#include <stdio.h>

static int mult = 0; // quantas multiplicações foram feitas

// x elevado a n, dividindo o expoente ao meio
long long potencia(long long x, int n) {
    if (n == 0) {
        return 1;                          // caso base: x^0 = 1
    }
    long long metade = potencia(x, n / 2); // conquista: resolve o pedaço menor
    long long r;
    if (n % 2 == 0) {
        r = metade * metade;               // combina: x^n = (x^(n/2))^2
        mult += 1;
    } else {
        r = metade * metade * x;           // n ímpar: sobra um x
        mult += 2;
    }
    printf("3^%-2d = %lld\n", n, r);
    return r;
}

int main(void) {
    long long total = potencia(3, 20);
    printf("Na rodada 20: %lld mensagens\n", total);
    printf("%d multiplicações (o laço simples faria 19)\n", mult);
    return 0;
}
// Saída:
// 3^1  = 3
// 3^2  = 9
// 3^5  = 243
// 3^10 = 59049
// 3^20 = 3486784401
// Na rodada 20: 3486784401 mensagens
// 7 multiplicações (o laço simples faria 19)
```

Os resultados saem de baixo para cima, pela pilha de chamadas (0031).

O fluxograma segue a chamada com `n = 20`: ela chama a si mesma com 10,
recebe 59049 e, como 20 é par, só eleva ao quadrado:

{{fluxograma}}

> [!WARNING]
> `return potencia(x, n / 2) * potencia(x, n / 2);` dá o resultado certo, mas
> faz **duas** chamadas por nível: T(n) = 2T(n/2) + O(1), que é O(n). Guarde a
> metade numa variável. Divisão e conquista só compensa quando os pedaços
> **não se repetem**.

> [!TIP]
> **Por dentro do C:** o perigo é o **estouro do `long long`**:
> 3³⁹ cabe, 3⁴⁰ não, e o gcc com as flags de estudo acusa `runtime error`.
> Para só os últimos dígitos, use `% m` após cada multiplicação (A261).

> [!NOTE]
> **Pergunta para você:** quantas multiplicações a função faz para 3¹⁶? E para
> 3¹⁵? Por que o expoente 15, menor, dá mais trabalho? Pista: escreva 16 e 15
> em binário.

{{pratique}}

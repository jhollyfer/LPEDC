## 0131 · Divisão e conquista

Uma corrente começa no grupo da família: quem recebe repassa para 3 contatos
novos. Na primeira rodada saem 3 mensagens; na segunda, 9; na terceira, 27.
Quantas mensagens saem na rodada 20? A conta é 3²⁰. O jeito óbvio é um laço
que multiplica por 3 vinte vezes. Funciona, mas dá para fazer bem melhor.

Repare que 3²⁰ = 3¹⁰ · 3¹⁰. Quem sabe 3¹⁰ resolve 3²⁰ com **uma**
multiplicação. E 3¹⁰ = 3⁵ · 3⁵. E 3⁵ = 3² · 3² · 3 (expoente ímpar: sobra um
3). O problema grande vira um problema do mesmo tipo com a metade do tamanho.

Essa é a técnica de **divisão e conquista** (em inglês, *divide and conquer*).
Ela tem três passos, e você já viu os três no merge sort (assunto 0094):

1. **dividir**: quebre o problema em pedaços menores do mesmo tipo;
2. **conquistar**: resolva cada pedaço com a própria função (recursão, assunto
   0032). Pedaço pequeno o bastante é o **caso base**, resolvido direto;
3. **combinar**: junte as respostas dos pedaços na resposta do todo.

A busca binária (0090) divide e descarta uma das metades. O merge sort divide
em duas metades e gasta o trabalho na combinação (a intercalação). O quick
sort (0095) gasta o trabalho na divisão (o particionamento) e não tem nada a
combinar. A técnica é a mesma; muda onde mora o esforço.

Na potência, a divisão é cortar o expoente ao meio, e a combinação é elevar
ao quadrado (mais um `x` quando o expoente é ímpar). O caso base é `n == 0`,
porque x⁰ = 1.

Por que é rápido? Cada chamada corta `n` pela metade, então a recursão desce
uns `log₂ n` níveis, e cada nível faz uma ou duas multiplicações. A
recorrência é T(n) = T(n/2) + O(1), e pelo assunto 0115 isso dá **O(log n)**.
Para n = 1 milhão, são uns 20 níveis contra 1 milhão de voltas do laço.

Vamos ver na prática. A recursão desce dividindo o expoente (20, 10, 5, 2, 1,
0) e sobe combinando: o 1 do caso base vira 3, que vira 9, que vira 243, e
assim até 3²⁰. Repare que o 3⁴ nem aparece: o caminho até 20 não passa por ele.

{{ideia}}

O mesmo exemplo em C. O `printf` dentro da função mostra cada resultado
parcial na hora em que a chamada termina, e o contador `mult` soma as
multiplicações:

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

Os resultados saem de baixo para cima: a chamada de 3²⁰ é a primeira a
começar e a última a terminar. É a pilha de chamadas do assunto 0031.

Repara no fluxograma: é a chamada de cima, com `n = 20`. Ela não é o caso
base, chama a si mesma com 10, recebe 59049 e, como 20 é par, só eleva ao
quadrado. Cada chamada de dentro percorre o mesmo fluxograma com o seu `n`:

{{fluxograma}}

> [!WARNING]
> O erro clássico é escrever `return potencia(x, n / 2) * potencia(x, n / 2);`.
> O resultado sai certo, mas a função passa a fazer **duas** chamadas iguais
> por nível, e elas fazem duas cada uma, e assim por diante. A recorrência
> vira T(n) = 2T(n/2) + O(1), que é O(n): todo o ganho vai embora. Guarde o
> resultado da metade numa variável e use duas vezes. Divisão e conquista só
> compensa quando os pedaços **não se repetem**.

> [!TIP]
> **Por dentro do C:** a recursão empilha um frame para cada bit do
> expoente, mais o do caso base: para n = 20 (5 bits) são 6 frames na pilha,
> para n = 1 bilhão (30 bits) seriam 31. O perigo aqui
> não é a pilha, é o **estouro do `long long`**: ele guarda até
> 9 223 372 036 854 775 807, e 3³⁹ ainda cabe, mas 3⁴⁰ não. Estouro de inteiro
> com sinal é comportamento indefinido, e o `rodar` acusa com `runtime error`.
> Quando só interessam os últimos dígitos, faça cada multiplicação seguida de
> `% m`: o número nunca passa de `m²` (o exemplo A261 faz isso).

> [!NOTE]
> **Pergunta para você:** quantas multiplicações a função faz para 3¹⁶? E para
> 3¹⁵? Por que o expoente 15, menor, dá mais trabalho? Pista: escreva 16 e 15
> em binário.

{{pratique}}

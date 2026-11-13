## 0131 · Divisão e conquista

Uma corrente no grupo da família: quem recebe a mensagem repassa para 3
contatos. Quantas mensagens saem na rodada 20? A conta é 3²⁰, e o jeito
óbvio é um laço que multiplica por 3 vinte vezes. Funciona, mas o número de
multiplicações cresce junto com o expoente. Para um expoente de 1 milhão,
seria 1 milhão de voltas.

Existe um atalho. 3²⁰ é 3¹⁰ vezes 3¹⁰: quem já sabe 3¹⁰ chega a 3²⁰ com uma
única multiplicação. E 3¹⁰ é 3⁵ vezes 3⁵. E 3⁵ é 3² vezes 3² vezes 3, porque
o expoente ímpar deixa sobrar um 3. A cada passo, o problema vira outro do
mesmo tipo com metade do tamanho. É como dividir a arrumação de uma casa:
cada cômodo é uma arrumação menor, e no fim a casa está arrumada porque cada
cômodo está.

Essa estratégia tem nome. A **divisão e conquista** (*divide and conquer*)
resolve um problema quebrando-o em pedaços menores do mesmo tipo, resolvendo
cada pedaço e juntando as respostas (CORMEN et al., 2024, cap. 4). Ela
trabalha em três passos. **Dividir** quebra o problema em pedaços menores.
**Conquistar** resolve cada pedaço chamando a própria função, ou seja, por
recursão (assunto 0032). **Combinar** junta as respostas dos pedaços na
resposta do todo (CORMEN et al., 2024, cap. 4).

A recursão precisa parar em algum lugar. O pedaço pequeno o bastante para
ser resolvido direto, sem dividir de novo, é o **caso base** (ZIVIANI, 2010,
cap. 2). Na potência, o caso base é `n == 0`, porque qualquer x⁰ vale 1.
Sem ele, a função cortaria o expoente para sempre e a pilha estouraria.

Na potência rápida, dividir é cortar o expoente ao meio e combinar é elevar
o resultado ao quadrado. Se o expoente é ímpar, a divisão inteira perde uma
unidade, e a combinação multiplica mais um `x` para compensar: xⁿ =
(x^(n/2))², com um `x` a mais quando `n` é ímpar (LINTZMAYER; MOTA, 2023).
Com `n = 5`, a chamada calcula x², eleva ao quadrado (x⁴) e multiplica por
`x` (x⁵).

Você já viu essa estratégia em outros lugares, só que com o esforço em
pontos diferentes. O merge sort (0094) divide sem esforço, ao meio, e gasta
o trabalho na combinação, a intercalação. O quick sort (0095) gasta o
trabalho na divisão, a partição, e não precisa combinar nada. A busca
binária (0090) divide e simplesmente descarta uma das metades (FEOFILOFF,
2009). Ao estudar um algoritmo desse tipo, pergunte onde está o trabalho.

O custo sai de uma recorrência. Cada chamada da potência faz uma chamada
com metade do expoente e mais um trabalho constante: T(n) = T(n/2) + O(1).
Pelo teorema mestre (assunto 0115), isso dá **O(log n)**. Para n = 1 milhão,
são uns 20 níveis de recursão contra 1 milhão de voltas do laço (CORMEN et
al., 2024, cap. 4).

Há uma condição para a estratégia compensar: os pedaços **não podem se
repetir**. Se dois pedaços diferentes pedem a mesma sub-resposta, a
recursão a calcula de novo a cada vez, e o tempo explode (ZIVIANI, 2010,
cap. 2). Quando os pedaços se repetem, a ferramenta certa é a programação
dinâmica, do módulo 21.

> [!WARNING]
> `return potencia(x, n / 2) * potencia(x, n / 2);` dá o resultado certo, mas
> faz **duas** chamadas por nível: T(n) = 2T(n/2) + O(1), que é O(n). Guarde a
> metade numa variável.

{{exemplo}}

Numa corrente de mensagens, cada um repassa para 3 contatos: na rodada 20,
saem 3²⁰. A recursão desce dividindo o expoente (20, 10, 5, 2, 1, 0) e sobe
combinando: o 1 do caso base vira 3, 9, 243, até 3²⁰.

{{ideia}}

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

Os resultados saem de baixo para cima, pela pilha de chamadas (0031). Cuidado
com o estouro: 3³⁹ cabe num `long long`, 3⁴⁰ não. O fluxograma segue a chamada
com `n = 20`:

{{fluxograma}}

## 0007 · Aritmética

Com a entrada (0006) e a saída (0005) prontas, falta o meio do modelo:
o **processamento**, calcular o que vai sair a partir do que entrou. Quase
todo cálculo começa nas quatro operações da escola, e o C as escreve de um
jeito familiar. Familiar demais, porque uma delas, a divisão, não se
comporta como na calculadora.

Pense em cinco amigos que pedem três pizzas de 8 fatias. São 24 fatias, e
cada um pega uma por rodada. Quatro rodadas completas dão 20 fatias, e
sobram 4 na caixa. Ninguém corta fatia ao meio. A divisão entre inteiros do
C funciona assim: conta as rodadas completas e deixa a sobra de lado.

Antes, dois nomes. Em `24 / 5`, o `/` é o **operador**, o símbolo da
operação, e 24 e 5 são os **operandos**, os valores sobre os quais ele age.
Operadores, operandos e parênteses formam uma **expressão**, e toda
expressão tem um valor (DEITEL; DEITEL, 2011, cap. 2). `24 - 4` vale 20;
`3 * 8` vale 24.

| Operador | Faz | Exemplo | Resultado |
| --- | --- | --- | --- |
| `+` `-` | soma, subtração | `24 - 4` | `20` |
| `*` | multiplicação | `3 * 8` | `24` |
| `/` | divisão | `24 / 5` | `4` (!) |
| `%` | resto da divisão | `24 % 5` | `4` |

A pegadinha está no `/`. Quando os **dois** operandos são inteiros, a
divisão é **inteira**: o resultado é inteiro e a parte fracionária vai
embora, sem arredondar. `7 / 2` dá 3, e `2 / 3` dá 0. Basta **um** lado
ser real para a divisão ser real: `159.0 / 5` dá 31,8 (DEITEL; DEITEL,
2011, cap. 2). O que decide é o tipo dos operandos, não a variável que vai
receber o resultado.

```c
printf("%d %d\n", 24 / 5, 24 % 5);   // 4 4
printf("%.1f\n", 159.0 / 5);         // 31.8
```

O **`%`**, chamado de módulo, devolve o resto da divisão inteira e só
aceita inteiros. O `/` diz quantas vezes o 5 cabe no 24; o `%` diz o que
sobrou. As duas respostas sempre se encaixam:
`(a / b) * b + a % b == a` (DEITEL; DEITEL, 2011, cap. 2). O resto parece
modesto, mas aparece em todo lugar. `2026 % 10` dá 6, o último dígito.
`n % 2` dá 0 quando `n` é par e 1 quando é ímpar. E `segundos % 60` dá os
segundos que sobram depois de contar os minutos.

Com números negativos, o C segue uma regra fixa desde o C99: a divisão
corta em direção ao zero, então `-7 / 2` dá -3, e o resto fica com o sinal
do dividendo, o número da esquerda, então `-7 % 3` dá -1 (FEOFILOFF, 2009,
ap. C). A igualdade do parágrafo anterior continua valendo: -3 × 2 + (-1)
dá -7.

Quando a expressão tem vários operadores, entra a **precedência**, a ordem
em que eles agem. Ela é a da escola: `*`, `/` e `%` antes de `+` e `-`.
No empate de precedência, a conta segue da esquerda para a direita, regra
chamada **associatividade**: `100 / 10 / 2` é `(100 / 10) / 2`, que dá 5
(BACKES, 2013, cap. 3). Em `2 + 3 * 4 % 5`, primeiro `3 * 4` dá 12, depois
`12 % 5` dá 2 e por fim `2 + 2` dá 4. Parênteses mandam em tudo e deixam a
intenção clara para quem lê.

Falta a potência, e o C não tem operador para ela. O `^` existe, mas faz
outra coisa (assunto 0065). Para elevar ao quadrado, multiplique, `x * x`,
ou use a função `pow` do 0010 (DEITEL; DEITEL, 2011, cap. 2).

Por último, a divisão por zero. Com inteiros, ela derruba o programa na
hora, com a mensagem `Floating point exception`. Com `double`, o programa
continua e o resultado é `inf`, o infinito (ISO/IEC, 2018). Nos dois casos
a conta está errada; confira o divisor antes de dividir.

> [!WARNING]
> Com `int a = 7, b = 8;`, `double media = (a + b) / 2;` guarda **7.0**: a
> divisão é entre dois `int` **antes** de ir para o `double`. Escreva
> `(a + b) / 2.0`. E `a + b / 2` divide só o `b`.

{{exemplo}}

Cinco amigos dividem três pizzas de 8 fatias e uma conta de R$ 159. O `/`
conta as rodadas completas de fatias e o `%` as que sobram:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int pizzas = 3;
    int fatias = pizzas * 8;      // 24
    int amigos = 5;

    int cada = fatias / amigos;   // divisão inteira: 4
    int sobra = fatias % amigos;  // resto: 4

    printf("%d fatias para %d amigos\n", fatias, amigos);
    printf("Cada um come %d, sobram %d\n", cada, sobra);

    double conta = 159.00;
    printf("Cada um paga R$ %.2f\n", conta / amigos); // real / int: divisão real
    printf("Com inteiros: R$ %d\n", 159 / amigos);    // int / int: corta o resto
    return 0;
}
// Saída:
// 24 fatias para 5 amigos
// Cada um come 4, sobram 4
// Cada um paga R$ 31.80
// Com inteiros: R$ 31
```

Cada conta é um retângulo, e a ordem importa: `cada` e `sobra` dependem de
`fatias`:

{{fluxograma}}

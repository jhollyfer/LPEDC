## 0008 · Conversão e cast

Você zerou o hodômetro parcial no último tanque. Agora rodou 523 km e gastou
41 litros para encher de novo. Quantos km por litro? A conta é 523 ÷ 41 ≈
12,76. O C, com dois `int`, responde 12.

Toda expressão tem um **valor** e um **tipo**. Com operandos do mesmo tipo, o
resultado tem esse tipo: `int / int` é `int`. Com tipos diferentes, o C faz a
**conversão automática**: o operando "menor" sobe para o tipo do "maior".
A escada é `char` → `short` → `int` → `long` → `long long` → `float` →
`double`. `523 / 41.0` vira `523.0 / 41.0` e dá 12,756...

Na **atribuição** é o contrário: o valor vira o tipo da variável da
**esquerda**, caiba ou não. `double d = 12;` guarda 12.0. `int i = 12.76;`
guarda 12: a parte fracionária é **cortada**, não arredondada (`-9.99` vira
-9). Valor grande demais num tipo pequeno perde bits. Com as opções do curso,
o compilador não avisa.

O **cast** escolhe a conversão: o tipo entre parênteses antes do valor,
`(double) km`. Ele cria uma **cópia temporária** convertida; `km` continua
`int`. Sua precedência é maior que a de `*` e `/`, então `(double) km /
litros` converte só o `km`, o que basta para a divisão ser real.

No desenho, pelo caminho de cima os dois `int` se dividem, sai 12 e só então
vira 12.0, tarde demais. Pelo de baixo, o cast transforma 523 em 523.0 antes
da divisão:

{{ideia}}

O consumo do carro em C:

```c
#include <stdio.h>

int main(void) {
    int km = 523;     // rodados desde o último tanque
    int litros = 41;  // para encher de novo

    double errado = km / litros;            // int / int = 12; depois vira 12.0
    double certo = (double) km / litros;    // 523.0 / 41 = 12.756...
    double tarde = (double) (km / litros);  // o cast chegou depois da divisão

    printf("Sem cast:      %.2f km/l\n", errado);
    printf("Com cast:      %.2f km/l\n", certo);
    printf("Cast atrasado: %.2f km/l\n", tarde);

    int inteiro = certo;                    // double -> int: corta, não arredonda
    printf("Num int:       %d km/l\n", inteiro);
    return 0;
}
// Saída:
// Sem cast:      12.00 km/l
// Com cast:      12.76 km/l
// Cast atrasado: 12.00 km/l
// Num int:       12 km/l
```

A pergunta "tem um real na divisão?" é respondida pelo compilador, pelos
tipos. Com o cast, o exemplo segue pelo Sim:

{{fluxograma}}

> [!WARNING]
> O cast precisa chegar **antes** da divisão. Em `(double) (km / litros)`, os
> parênteses mandam dividir primeiro: `523 / 41` dá 12 e o cast só o
> transforma em 12.0. Igualmente, `double media = soma / n;` com `soma` e `n`
> inteiros perde os decimais antes do `=`. Converta um operando:
> `(double) soma / n`.

> [!TIP]
> Um `int` e um `double` de mesmo valor têm bits diferentes: converter é uma
> operação real do processador. O `float` guarda inteiros exatos só até
> 2²⁴ = 16.777.216 (`float f = 16777217;` vira 16777216), e o `double`, até
> 2⁵³. Converter um `double` grande demais para `int` é comportamento
> indefinido.

> [!NOTE]
> **Pergunta para você:** quanto vale `int x = 7 / 2 * 2.0;`? Faça passo a
> passo, olhando o tipo de cada pedaço, e depois confira.

{{pratique}}

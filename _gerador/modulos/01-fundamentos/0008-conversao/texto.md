## 0008 · Conversão e cast

No 0007, `(a + b) / 2` perdeu os decimais porque os dois lados eram
inteiros. Isso vai acontecer sempre que um cálculo misturar tipos ou
guardar um resultado num tipo diferente. Para não ser pego de surpresa, você
precisa saber quando o C converte um valor sozinho e como pedir a conversão
quando ela não vem.

Pense no carro. Você rodou 523 km e gastou 41 litros para encher o tanque.
A calculadora diz que o consumo é 523 ÷ 41 ≈ 12,76 km por litro. O C, com
dois `int`, responde 12. Ninguém errou a conta: o C fez exatamente o que os
tipos pediam, uma divisão inteira.

O ponto de partida é este: toda expressão tem um valor e um **tipo**.
Quando os operandos têm o mesmo tipo, o resultado tem esse tipo, e por isso
`int / int` dá `int` (DEITEL; DEITEL, 2011). Quando os tipos são
diferentes, o C faz a **conversão automática**, também chamada de
conversão implícita: o operando "menor" sobe para o tipo do "maior" antes
da conta. A escada é `char` → `short` → `int` → `long` → `long long` →
`float` → `double` (DEITEL; DEITEL, 2011). Em `523 / 41.0`, o 523 sobe
para `double`, a conta vira `523.0 / 41.0` e dá 12,756...

Na **atribuição**, a conversão segue outra regra: o valor vira o tipo da
variável da **esquerda**, caiba ou não. `double d = 12;` guarda 12.0, sem
problema. `int i = 12.76;` guarda 12, porque a parte fracionária é
**cortada**, não arredondada; `-9.99` vira -9 (BACKES, 2013, cap. 2). E um
valor grande demais para um tipo pequeno perde bits, como o odômetro do
0003. Com as opções do curso, o compilador não avisa nenhum desses cortes.

Quando a conversão automática não basta, você escolhe a sua com o **cast**,
ou conversão explícita: o tipo entre parênteses na frente do valor,
`(double) km`. O cast não muda a variável. Ele cria uma **cópia
temporária** já convertida e a entrega para a conta; `km` continua `int`
depois (DEITEL; DEITEL, 2011).

```c
int km = 523, litros = 41;
printf("%d\n", km / litros);              // 12
printf("%.2f\n", (double) km / litros);   // 12.76
```

Repare na segunda linha. A precedência do cast é maior que a de `*` e `/`,
então `(double) km / litros` converte só o `km`, e só depois divide
(BACKES, 2013, cap. 3). Basta isso: com um lado `double`, a conversão
automática sobe o `litros` e a divisão é real.

Um `int` e um `double` de mesmo valor têm bits completamente diferentes na
memória, e o processador faz trabalho de verdade para passar de um para o
outro. Às vezes nem cabe. O `float` guarda
inteiros exatos só até 2²⁴ = 16.777.216: `float f = 16777217;` vira
16777216. O `double` vai até 2⁵³. E converter para `int` um `double` maior
que o `int` aguenta é comportamento indefinido (ISO/IEC, 2018).

> [!WARNING]
> O cast precisa chegar **antes** da divisão. Em `(double) (km / litros)`,
> os parênteses mandam dividir primeiro: `523 / 41` dá 12 e o cast só o
> transforma em 12.0. O mesmo vale para `double media = soma / n;` com dois
> inteiros. Converta um operando: `(double) soma / n`.

{{exemplo}}

Um carro rodou 523 km com 41 litros. Pelo caminho de cima, os dois `int` se
dividem, sai 12 e só então vira 12.0; pelo de baixo, o cast transforma 523 em
523.0 antes da divisão:

{{ideia}}

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

Quem responde "tem um real na divisão?" é o compilador, pelos tipos. Com o
cast, o exemplo segue pelo Sim:

{{fluxograma}}

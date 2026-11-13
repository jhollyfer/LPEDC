## 0008 · Conversão e cast

- **Tipo da expressão**: operandos do mesmo tipo dão resultado desse tipo;
  `int / int` é `int` (DEITEL; DEITEL, 2011).
- **Conversão automática**: com tipos diferentes, o operando "menor" sobe para
  o tipo do "maior". A escada é `char` → `short` → `int` → `long` →
  `long long` → `float` → `double` (DEITEL; DEITEL, 2011).
- **Conversão na atribuição**: o valor vira o tipo da variável da **esquerda**,
  caiba ou não. `int i = 12.76;` guarda 12: a parte fracionária é **cortada**
  (`-9.99` vira -9). Valor grande demais perde bits (BACKES, 2013, cap. 2).
- **Cast**: o tipo entre parênteses antes do valor, `(double) km`. Cria uma
  **cópia temporária** convertida; `km` continua `int`
  (DEITEL; DEITEL, 2011).
- **Precedência do cast**: maior que a de `*` e `/`. `(double) km / litros`
  converte só o `km`, o que basta para a divisão ser real
  (BACKES, 2013, cap. 3).
- **Limites da conversão**: o `float` guarda inteiros exatos só até
  2²⁴ = 16.777.216, e o `double` até 2⁵³. Converter um `double` grande demais
  para `int` é comportamento indefinido (ISO/IEC, 2018).

> [!WARNING]
> O cast precisa chegar **antes** da divisão. Em `(double) (km / litros)`, os
> parênteses mandam dividir primeiro: `523 / 41` dá 12 e o cast só o
> transforma em 12.0. Converta um operando: `(double) soma / n`.

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

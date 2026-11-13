## 0010 · math.h

O C tem operadores para as quatro operações e para o resto, e parou aí.
Não há operador de potência, de raiz nem de arredondamento. Mesmo assim,
muita conta do dia a dia precisa deles: a área de um círculo pede o raio ao
quadrado, a distância entre dois pontos pede uma raiz, e saber quantas latas
de tinta comprar pede arredondar para cima.

Pense na pizzaria: a grande, de 35 cm, custa R$ 59,90, e a média, de 25 cm,
R$ 39,90. Duas médias dão mais pizza que uma grande? A intuição diz que
não, mas a área cresce com o **quadrado** do raio. A conta mostra que duas
médias somam 981,75 cm², um pouco mais que os 962,11 cm² da grande. Para
fazer essa conta no C, você recorre a uma caixa de ferramentas pronta.

Essa caixa é a biblioteca de matemática, declarada no cabeçalho
**`<math.h>`**. Ela traz funções prontas, e quase todas recebem e devolvem
`double` (DEITEL; DEITEL, 2011, cap. 5). Uma **função** aqui é uma conta
com nome: você escreve o nome, passa os valores entre parênteses e recebe o
resultado no lugar da chamada. `pow(2, 10)` vale 1024, e você pode usar
essa chamada dentro de qualquer expressão, como usaria um número.

| Função | Faz | Exemplo | Resultado |
| --- | --- | --- | --- |
| `pow(x, y)` | x elevado a y | `pow(2, 10)` | 1024 |
| `sqrt(x)` | raiz quadrada | `sqrt(144)` | 12 |
| `fabs(x)` | valor absoluto de real | `fabs(-7.5)` | 7.5 |
| `floor(x)` | arredonda para **baixo** | `floor(-2.3)` | -3 |
| `ceil(x)` | arredonda para **cima** | `ceil(2.1)` | 3 |
| `round(x)` | para o mais perto (o meio vai para longe do zero) | `round(2.5)` | 3 |
| `fmod(x, y)` | resto de divisão real | `fmod(7.5, 2)` | 1.5 |
| `sin`, `cos`, `tan` | trigonometria, em **radianos** | `cos(0)` | 1 |

O `math.h`, porém, só **declara** as funções: diz o nome, o que cada uma
recebe e o que devolve. Por isso `sqrt(144)` funciona mesmo com um `int`: o
compilador lê a declaração e converte o 144 para `double`. O código das
funções mora em outro lugar, na biblioteca `libm`, e o ligador (0001) só a
junta ao programa se você pedir com `-lm` no fim do comando do `gcc` (GNU,
s.d.). Sem isso, a compilação para com `undefined reference to 'pow'`. As
flags de estudo do curso já incluem o `-lm`.

Os três arredondamentos parecem iguais com números positivos e divergem com
os negativos. O `floor` sempre desce, rumo ao menos infinito:
`floor(-2.3)` é -3. O `ceil` sempre sobe: `ceil(-2.7)` é -2. O `round` vai
para o inteiro mais perto, e quando está bem no meio vai para longe do
zero: `round(2.5)` é 3 e `round(-2.5)` é -3 (DEITEL; DEITEL, 2011,
cap. 5). O cast do 0008 é uma quarta coisa: ele **corta** a parte
fracionária, e `(int) -2.7` dá -2. Para "quantas latas preciso comprar", o
certo é o `ceil`: 2,78 latas viram 3.

Faltam dois detalhes que pegam desprevenido. O C padrão não define o
número pi. O `M_PI`, que aparece em muito código por aí, é uma extensão e
não existe com `-std=c17`; crie o seu com `#define PI 3.14159265358979`
(ISO/IEC, 2018). E o valor absoluto de inteiros, `abs`, não fica no
`math.h`, e sim no `<stdlib.h>`. Para números reais, a função é a `fabs`
(BACKES, 2013). Usar `abs(-2.75)` dá 2, porque o valor é convertido para
`int` antes; o `-Wextra` avisa.

> [!WARNING]
> `pow(27, 1/3)` dá **1**, não 3: `1/3` é divisão inteira e vale 0, e todo
> número elevado a 0 é 1. Escreva `1.0 / 3`. Do mesmo modo, `ceil(7 / 2)`
> dá 3, não 4: o `ceil` recebe o 3 já cortado.

{{exemplo}}

Duas pizzas médias de 25 cm dão mais pizza que uma grande de 35 cm? A área
cresce com o quadrado do raio: o diâmetro vira raio, `pow` eleva ao quadrado
e o resultado vezes pi dá a área:

{{ideia}}

```c
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979 // o C padrão não define o pi

int main(void) {
    double diametro_grande = 35.0, diametro_media = 25.0; // cm
    double preco_grande = 59.90, preco_medias = 2 * 39.90;

    double area_grande = PI * pow(diametro_grande / 2, 2);     // pi * r²
    double area_medias = 2 * PI * pow(diametro_media / 2, 2);

    printf("Grande: %.0f cm² por R$ %.2f\n", round(area_grande), preco_grande);
    printf("Duas médias: %.0f cm² por R$ %.2f\n", round(area_medias), preco_medias);
    printf("Diferença: %.1f cm²\n", fabs(area_grande - area_medias));
    printf("R$ por 100 cm²: grande %.2f, médias %.2f\n",
           preco_grande / area_grande * 100, preco_medias / area_medias * 100);

    // a pizza única com a mesma área das duas médias: r = raiz(área / pi)
    double diametro_igual = 2 * sqrt(area_medias / PI);
    printf("Duas médias = uma pizza de %.1f cm\n", diametro_igual);
    return 0;
}
// Saída:
// Grande: 962 cm² por R$ 59.90
// Duas médias: 982 cm² por R$ 79.80
// Diferença: 19.6 cm²
// R$ por 100 cm²: grande 6.23, médias 8.13
// Duas médias = uma pizza de 35.4 cm
```

Duas médias dão um pouco mais de pizza, mas cada 100 cm² da grande sai quase
R$ 2 mais barato. No fluxograma, `pow(...)` e `sqrt(...)` entram nas contas
como qualquer valor:

{{fluxograma}}

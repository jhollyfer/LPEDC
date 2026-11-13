## 0010 · math.h

- **`<math.h>`**: declara a biblioteca de matemática. Quase todas as funções
  recebem e devolvem `double` (DEITEL; DEITEL, 2011, cap. 5).
- **`libm`**: o `math.h` só declara; o código está na `libm`, que o ligador
  junta com `-lm`. Sem ela, aparece `undefined reference to 'pow'`
  (GNU, s.d.).
- **Arredondamentos**: `floor` sempre desce (`floor(-2.3)` é -3), `ceil`
  sempre sobe (`ceil(-2.7)` é -2), `round` vai para o inteiro mais perto. O
  cast **corta**: `(int) -2.7` dá -2. Para "quantas latas comprar", `ceil`:
  2,78 viram 3 (DEITEL; DEITEL, 2011, cap. 5).
- **Sem pi padrão**: o `M_PI` é extensão e não existe com `-std=c17`; crie o
  seu com `#define` (ISO/IEC, 2018).
- **`abs` e `fabs`**: o `abs` é de inteiros e fica no `<stdlib.h>`; para real,
  `fabs` (BACKES, 2013).

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

> [!WARNING]
> `pow(27, 1/3)` dá **1**, não 3: `1/3` é divisão inteira e vale 0. Escreva
> `1.0 / 3`. Do mesmo modo, `ceil(7 / 2)` dá 3, não 4: o `ceil` recebe o 3 já
> cortado.

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

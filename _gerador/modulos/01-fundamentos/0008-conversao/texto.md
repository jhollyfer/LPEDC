## 0008 · Conversão e cast

Você zerou o hodômetro parcial no último tanque. Agora rodou 523 km e
precisou de 41 litros para encher de novo. Quantos km por litro o carro faz?
A conta é 523 ÷ 41 ≈ 12,76. O C, com dois `int`, responde 12.

Toda expressão em C tem um **valor** e um **tipo**. Com operandos do mesmo
tipo, o resultado tem esse tipo: `int / int` é `int`. Com tipos diferentes,
o C faz uma **conversão automática**: o operando "menor" sobe para o tipo do
"maior" antes da conta. A escada é
`char` → `short` → `int` → `long` → `long long` → `float` → `double`.
`523 / 41.0` vira `523.0 / 41.0` e dá 12,756...

Na **atribuição** é o contrário: o valor vira o tipo da variável da
**esquerda**, caiba ou não. `double d = 12;` guarda 12.0, sem problema.
`int i = 12.76;` guarda 12: a parte fracionária é **cortada**, não
arredondada (e `-9.99` vira -9). Um valor grande demais num tipo pequeno
perde bits. O compilador, com as opções do curso, não avisa nada disso.

Quando você quer escolher a conversão, usa o **cast**: o tipo entre
parênteses na frente do valor, `(double) km`. O cast cria uma **cópia
temporária** convertida; a variável `km` continua `int` para sempre. Ele tem
precedência alta, maior que a de `*` e `/`, então `(double) km / litros`
converte só o `km`, e isso basta, porque aí a divisão já vira real.

Resumo: no C, o tipo de cada pedaço da conta decide o resultado. Antes de
confiar numa conta, pergunte de que tipo é cada operando.

Vamos ver na prática. Pelo caminho de cima, os dois `int` se dividem, sai 12,
e só então ele vira 12.0, tarde demais. Pelo caminho de baixo, o cast
transforma o 523 em 523.0 antes da divisão, e o resultado é real:

{{ideia}}

O mesmo exemplo em C:

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

Repara no fluxograma: a pergunta que decide o resultado é "tem um real na
divisão?". Ela é respondida pelo compilador, olhando os tipos, antes de o
programa rodar. O exemplo segue pelo Sim, graças ao cast:

{{fluxograma}}

> [!WARNING]
> O cast precisa chegar **antes** da divisão. `(double) (km / litros)` parece
> certo, mas os parênteses mandam dividir primeiro: `523 / 41` dá 12 e o cast
> só transforma o 12 em 12.0. O mesmo vale para guardar num `double`:
> `double media = soma / n;` com `soma` e `n` inteiros já perdeu os decimais
> antes do `=`. Converta um dos operandos: `(double) soma / n`.

> [!TIP]
> **Por dentro do C:** um `int` e um `double` com o "mesmo" valor têm bits
> completamente diferentes. O 12 num `int` são 4 bytes `0C 00 00 00`; o 12.0
> num `double` são 8 bytes no formato sinal, expoente e mantissa. Converter
> é uma instrução do processador (`cvtsi2sd` nos PCs), não um rótulo novo. O
> `double` guarda inteiros exatos até 2⁵³; o `float`, só até 2²⁴ = 16.777.216,
> e por isso `float f = 16777217;` vira 16777216. E converter um `double`
> grande demais para `int` é comportamento indefinido: não confie no
> resultado.

> [!NOTE]
> **Pergunta para você:** quanto vale `int x = 7 / 2 * 2.0;`? Faça passo a
> passo, olhando o tipo de cada pedaço, e depois confira.

{{pratique}}

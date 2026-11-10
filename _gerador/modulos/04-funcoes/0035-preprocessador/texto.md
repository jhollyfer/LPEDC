## 0035 · Pré-processador: macros e #ifdef

O "localizar e substituir" do editor troca todo `TAXA` por `0.05` no arquivo,
sem entender nada do texto. O **pré-processador** do C faz o mesmo e roda
**antes** do compilador. Toda linha que começa com `#` é para ele: `#include`
cola um arquivo, `#define` cria uma substituição. Quando o compilador recebe o
código, as diretivas já sumiram.

Você já usa `#define TAXA 0.05` para constantes. Com parâmetros, o `#define`
vira uma **macro**:

```c
#define QUAD(x) ((x) * (x))
```

Cada `QUAD(alguma coisa)` vira `((alguma coisa) * (alguma coisa))`. Parece
função, mas não é: não tem tipo, chamada nem pilha. É **troca de texto**. O
nome e o `(` ficam colados: `QUAD (x)`, com espaço, é uma constante que vale
`(x) ((x) * (x))`.

Troca de texto não respeita a precedência dos operadores. Sem parênteses,
`QUAD_RUIM(lado + 3)` vira `lado + 3 * lado + 3`, e a multiplicação vem
primeiro. A regra: **parênteses em volta de cada parâmetro e da expressão
inteira**.

No exemplo, o terreno tem `lado + 3` metros de lado, com `lado = 2`.
`QUAD_RUIM(lado + 3)` chega ao compilador como `lado + 3 * lado + 3`, que dá
11. A versão com parênteses chega como `((lado + 3) * (lado + 3))` e dá 25:

{{ideia}}

O mesmo exemplo em C, com mais uma armadilha, a da divisão:

```c
#include <stdio.h>

#define QUAD_RUIM(x) x * x       // sem parênteses: perigo
#define QUAD(x) ((x) * (x))      // parênteses no parâmetro E em volta de tudo

int main(void) {
    int lado = 2;

    // terreno quadrado de lado (2 + 3) metros
    printf("QUAD_RUIM(lado + 3) = %d\n", QUAD_RUIM(lado + 3)); // 2 + 3 * 2 + 3
    printf("QUAD(lado + 3)      = %d\n", QUAD(lado + 3));      // ((2 + 3) * (2 + 3))

    // quantos lotes de 5 x 5 cabem em 100 m2?
    printf("100 / QUAD_RUIM(5)  = %d\n", 100 / QUAD_RUIM(5));  // 100 / 5 * 5
    printf("100 / QUAD(5)       = %d\n", 100 / QUAD(5));       // 100 / ((5) * (5))
    return 0;
}
// Saída:
// QUAD_RUIM(lado + 3) = 11
// QUAD(lado + 3)      = 25
// 100 / QUAD_RUIM(5)  = 100
// 100 / QUAD(5)       = 4
```

O pré-processador não sabe nada de C: só procura o nome da macro e troca. Quem
descobre o erro (quando descobre) é o compilador, olhando um código que você
não escreveu:

{{fluxograma}}

O pré-processador também decide **o que entra** no programa, com a
**compilação condicional**:

```c
#ifdef DEPURAR          // se o nome DEPURAR foi definido...
    printf("[debug] total = %d\n", total);
#endif
```

Com `#define DEPURAR` no topo, a linha entra. Sem ele, nem chega ao
compilador: o executável não guarda vestígio dela. Existem também `#ifndef`
(se **não** foi definido, o do include guard), `#if`, `#elif`, `#else` e
`#undef`. Dá para definir o nome pela linha de comando: `gcc -DDEPURAR
programa.c`. E `#if 0` ... `#endif` desliga um trecho inteiro, mesmo com
comentários `/* */` dentro.

O exemplo A070 usa:

- `__LINE__`, o número da linha, e `__func__`, o nome da função atual: úteis
  em mensagens de depuração;
- `#x` dentro de uma macro, que transforma o argumento em texto:
  `MOSTRAR(7 * 6)` mostra `7 * 6 = 42`, a expressão e o valor numa linha.

> [!WARNING]
> A macro avalia o argumento **cada vez que ele aparece**. Com
> `#define MAIOR(a, b) ((a) > (b) ? (a) : (b))`, `MAIOR(x++, y)` pode
> incrementar `x` **duas vezes**. E não ponha `;` no fim do `#define`:
> `#define TAXA 0.05;` faz `preco * TAXA + 1` virar `preco * 0.05; + 1`. Às
> vezes compila e erra a conta; às vezes o erro aponta para uma linha
> aparentemente perfeita.

> [!TIP]
> Para cálculos, o C moderno prefere funções pequenas: têm checagem de tipos e
> não têm essas armadilhas. Macro fica para o que só ela faz: constantes,
> `#ifdef`, `__LINE__` e `#x`.

> [!NOTE]
> **Pergunta para você:** com `#define DOBRO(x) (x) + (x)`, quanto vale
> `10 * DOBRO(3)`? Os parênteses no parâmetro bastam?

{{pratique}}

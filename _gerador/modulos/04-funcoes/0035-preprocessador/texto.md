## 0035 · Pré-processador: macros e #ifdef

Sabe o "localizar e substituir" do VS Code? Troca todo `TAXA` por `0.05` no
arquivo inteiro, sem entender nada do que está escrito. O **pré-processador**
do C é exatamente isso, e roda **antes** do compilador. Toda linha que começa
com `#` é para ele: `#include` cola um arquivo, `#define` cria uma
substituição. Quando o compilador recebe o código, as diretivas já sumiram.

Você já usa `#define TAXA 0.05` para constantes. Mas o `#define` também aceita
parâmetros, e aí vira uma **macro**:

```c
#define QUAD(x) ((x) * (x))
```

Onde aparecer `QUAD(alguma coisa)`, o pré-processador escreve
`((alguma coisa) * (alguma coisa))`. Parece uma função, mas não é: não tem
tipo, não tem chamada, não tem pilha. É **troca de texto**. O nome e o `(`
ficam colados: `QUAD (x)` com espaço já é outra coisa (uma constante que vale
`(x) ((x) * (x))`).

E troca de texto não respeita a precedência dos operadores. Sem parênteses,
`QUAD_RUIM(lado + 3)` vira `lado + 3 * lado + 3`, e a multiplicação vem
primeiro. A regra que resolve: **parênteses em volta de cada parâmetro e em
volta da expressão inteira**.

Vamos ver na prática. O terreno tem `lado + 3` metros de lado, com `lado = 2`.
O texto `QUAD_RUIM(lado + 3)` passa pelo pré-processador e chega ao compilador
como `lado + 3 * lado + 3`, que dá 11. A versão com parênteses chega como
`((lado + 3) * (lado + 3))` e dá 25:

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

Repara no fluxograma: o pré-processador não pergunta nada sobre o C. Ele só
procura o nome da macro e troca. Quem descobre o erro (quando descobre) é o
compilador, olhando um código que você nem escreveu:

{{fluxograma}}

O pré-processador também decide **o que entra** no programa, com a
**compilação condicional**:

```c
#ifdef DEPURAR          // se o nome DEPURAR foi definido...
    printf("[debug] total = %d\n", total);
#endif
```

Com `#define DEPURAR` no topo, a linha entra. Sem ele, ela nem chega ao
compilador: o executável fica sem nenhum vestígio dela. Existem também
`#ifndef` (se **não** foi definido, o mesmo do include guard), `#if`, `#elif`,
`#else` e `#undef`. Dá para definir o nome pela linha de comando, sem mexer no
código: `gcc -DDEPURAR programa.c`. Um truque útil: `#if 0` ... `#endif` desliga
um trecho inteiro, mesmo que ele tenha comentários `/* */` dentro.

Ferramentas que o exemplo A070 usa:

- `__LINE__` vira o número da linha, e `__func__` o nome da função atual. Os
  dois são ótimos em mensagens de depuração.
- `#x` dentro de uma macro transforma o argumento em texto: `MOSTRAR(7 * 6)`
  mostra `7 * 6 = 42`: a expressão e o valor numa linha só, sem repetir nada.

> [!WARNING]
> A macro avalia o argumento **cada vez que ele aparece**. Com
> `#define MAIOR(a, b) ((a) > (b) ? (a) : (b))`, a chamada `MAIOR(x++, y)`
> pode incrementar `x` **duas vezes**. E não ponha `;` no fim do `#define`:
> `#define TAXA 0.05;` faz `preco * TAXA + 1` virar `preco * 0.05; + 1`. Às
> vezes compila e faz a conta errada; às vezes dá um erro que aponta para uma
> linha que parece perfeita.

> [!TIP]
> **Por dentro do C:** salve o código acima como `terreno.c`, rode
> `gcc -E terreno.c | tail -12` e veja o que o compilador recebe de verdade:
> `printf(..., lado + 3 * lado + 3)`, sem
> nenhuma macro. Por isso macro não aparece no depurador e não tem endereço.
> Para cálculos, o C moderno prefere funções pequenas: com `gcc -O2`, o
> compilador costuma copiar o corpo de uma função curta direto no lugar da
> chamada (isso se chama *inlining*), e você ganha a mesma velocidade com
> conferência de tipos e sem as armadilhas. Macro fica para o que só ela
> faz: constantes, `#ifdef`, `__LINE__` e `#x`.

> [!NOTE]
> **Pergunta para você:** com `#define DOBRO(x) (x) + (x)`, quanto vale
> `10 * DOBRO(3)`? Os parênteses no parâmetro bastam?

{{pratique}}

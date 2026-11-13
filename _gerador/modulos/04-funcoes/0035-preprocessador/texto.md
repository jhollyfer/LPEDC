## 0035 · Pré-processador: macros e #ifdef

- **Pré-processador**: roda **antes** do compilador e trata as linhas que
  começam com `#`. Quando o compilador recebe o código, as diretivas já sumiram
  (DEITEL; DEITEL, 2011, cap. 13).
- **Macro**: um `#define` com parâmetros. Não é função: não tem tipo, chamada
  nem pilha; é **troca de texto**. O nome e o `(` ficam colados (GNU, s.d.).
- **Parênteses**: a troca ignora a precedência. Ponha parênteses em volta de
  cada parâmetro e da expressão inteira (DEITEL; DEITEL, 2011, cap. 13).
- **Compilação condicional**: `#ifdef`, `#ifndef`, `#if`, `#elif`, `#else` e
  `#endif` decidem o que chega ao compilador; `gcc -DNOME` define pela linha de
  comando, e `#if 0` desliga um trecho (BACKES, 2013, cap. 13).
- **Macros prontas e `#x`**: `__LINE__` dá a linha e `__func__` a função
  atual; `#x` numa macro transforma o argumento em texto (GNU, s.d.).
- **Função ou macro**: para cálculo, prefira função pequena, que confere os
  tipos; macro fica para constantes, `#ifdef`, `__LINE__` e `#x` (LAGO, s.d.).

```c
#define QUAD(x) ((x) * (x))
```

> [!WARNING]
> A macro avalia o argumento cada vez que ele aparece: `MAIOR(x++, y)` pode
> incrementar `x` duas vezes. E sem `;` no `#define`: `#define TAXA 0.05;`
> faz `preco * TAXA + 1` virar `preco * 0.05; + 1`.

{{exemplo}}

O terreno tem `lado + 3` metros de lado, com `lado = 2`.
`QUAD_RUIM(lado + 3)` chega ao compilador como `lado + 3 * lado + 3` e dá 11;
a versão com parênteses dá 25:

{{ideia}}

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

O pré-processador só procura o nome e troca; quem acha o erro, quando acha, é
o compilador:

{{fluxograma}}

A compilação condicional, com `#define DEPURAR` no topo ou `gcc -DDEPURAR`:

```c
#ifdef DEPURAR          // se o nome DEPURAR foi definido...
    printf("[debug] total = %d\n", total);
#endif
```

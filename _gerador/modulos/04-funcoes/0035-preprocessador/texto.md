## 0035 · Pré-processador: macros e #ifdef

O "localizar e substituir" do editor troca todo `TAXA` por `0.05` no arquivo,
sem entender nada do texto. Ele não sabe se `TAXA` é variável, comentário ou
pedaço de outra palavra; só troca. O C tem uma etapa que trabalha desse
jeito, e você já a usa sem perceber, toda vez que escreve `#include` ou
`#define`.

Essa etapa é o **pré-processador**. Ele roda **antes** do compilador e cuida
de toda linha que começa com `#`, as **diretivas** (DEITEL; DEITEL, 2011, cap.
13). O `#include` cola um arquivo; o `#define` cria uma substituição. Quando o
compilador recebe o código, as diretivas já sumiram e as trocas já foram
feitas. O compilador nunca vê o nome `TAXA`, só o `0.05` que ficou no lugar.

Você já usa `#define TAXA 0.05` para constantes. Com parâmetros, o `#define`
vira uma **macro**:

```c
#define QUAD(x) ((x) * (x))
```

Cada `QUAD(alguma coisa)` no código vira `((alguma coisa) * (alguma
coisa))`. Parece uma função, mas não é: não tem tipo, não faz chamada, não
cria quadro na pilha. É **troca de texto**, feita antes de compilar (GNU,
s.d.). Um detalhe de escrita decide tudo: o nome e o `(` ficam colados. Com
espaço, `#define QUAD (x) ((x) * (x))` define uma constante sem parâmetro,
que vale o texto `(x) ((x) * (x))`.

Por ser troca de texto, a macro não respeita a precedência dos operadores
(DEITEL; DEITEL, 2011, cap. 13). Suponha `#define QUAD_RUIM(x) x * x` e o
terreno com `lado = 2`. A chamada `QUAD_RUIM(lado + 3)` chega ao compilador
como `lado + 3 * lado + 3`, a multiplicação vem primeiro e o resultado é 11,
não 25. A regra é pôr **parênteses em volta de cada parâmetro e em volta da
expressão inteira**, como no `QUAD` acima. Os de dentro protegem o argumento;
os de fora protegem a macro quando ela aparece no meio de outra conta.

O pré-processador também decide o que chega ao compilador. Isso é a
**compilação condicional** (BACKES, 2013, cap. 13). Um trecho entre
`#ifdef DEPURAR` e `#endif` só é compilado se o nome `DEPURAR` estiver
definido; o `#ifndef` faz o contrário. O `#if` testa uma expressão constante,
e `#elif` e `#else` dão os outros caminhos, como num `if` comum. O nome pode
vir do próprio código ou da linha de comando: `gcc -DDEPURAR` define
`DEPURAR` sem mexer no arquivo. E `#if 0` ... `#endif` desliga um trecho
inteiro de uma vez. O include guard do assunto 0034 é uma compilação
condicional.

Algumas peças prontas ajudam a depurar (GNU, s.d.). A macro `__LINE__` vira o
número da linha em que aparece. O identificador `__func__`, que o compilador
cria dentro de cada função, guarda o nome da função atual. E o operador `#`,
usado dentro de uma macro, transforma o argumento em texto: numa macro
`MOSTRAR(x)` que imprime `#x` e depois `(x)`, a chamada `MOSTRAR(lado + 3)`
escreve `lado + 3 = 5`. Com isso dá para montar mensagens de erro que dizem
onde e o quê.

Função ou macro? Para cálculo, prefira uma função pequena (LAGO, s.d.). Ela
confere os tipos dos argumentos, avalia cada argumento uma vez e aparece no
depurador. A macro fica para o que só ela faz: constantes, compilação
condicional, `__LINE__` e o operador `#`.

> [!WARNING]
> A macro avalia o argumento **cada vez que ele aparece**: com
> `#define MAIOR(a, b) ((a) > (b) ? (a) : (b))`, `MAIOR(x++, y)` pode
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

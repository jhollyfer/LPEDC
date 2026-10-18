## 0034 · Módulos: .h, .c e compilação separada

Quando várias partes de um programa precisam converter quilômetros em milhas,
ninguém cola o código da conversão em cada uma delas. Ele mora num lugar só, e
quem precisa usa. No C, esse lugar é um **módulo**: um par de arquivos.

- **`conversao.h`** (o *header*, cabeçalho): a **interface**. Diz **o que** o
  módulo oferece: os protótipos das funções, as constantes, os tipos. É o
  contrato que quem usa precisa conhecer.
- **`conversao.c`**: a **implementação**. Diz **como**: o corpo das funções e
  tudo o que é interno do módulo. Ele inclui o próprio `.h`, para o
  compilador conferir que a implementação bate com o contrato.

Quem quer usar escreve `#include "conversao.h"`. Lembre que o `#include` só
**cola** o texto do arquivo ali. Com o `.h` colado, o compilador conhece os
protótipos e confere cada chamada. Com aspas, o arquivo é procurado primeiro
na pasta do seu `.c`; com `< >`, só nas pastas do sistema.

Cada `.c` é compilado **sozinho**, sem saber que os outros existem. O
compilador transforma cada um num **arquivo objeto** (`.o`). Quando ele vê a
chamada `km_para_milhas(100)` em `A067.c`, só sabe que a função existe (o
protótipo prometeu), e deixa um buraco com o nome dela. Quem tapa o buraco é o
**ligador** (*linker*), que junta os `.o` e procura cada nome. Isso é a
**compilação separada**:

```bash
gcc -std=c17 -Wall -Wextra -c conversao.c       # gera conversao.o
gcc -std=c17 -Wall -Wextra -c A067.c            # gera A067.o
gcc A067.o conversao.o -o viagem                # o ligador junta
gcc -std=c17 -Wall -Wextra A067.c conversao.c -o viagem   # ou tudo de uma vez
```

Num projeto grande, mudar um `.c` recompila só ele e liga de novo, em vez de
recompilar tudo. O `rodar` do curso compila junto todo `.c` de apoio que
estiver na pasta (todo arquivo que não se chama `A000.c` ou `E000.c`).

Vamos ver na prática. O `conversao.h` é incluído pelos dois `.c`. Cada um vira
um `.o` separado, e o ligador junta os dois no executável `viagem`:

{{ideia}}

O módulo fica na pasta do assunto. O `conversao.h`:

```c
// conversao.h · a interface do módulo: O QUE ele oferece
#ifndef CONVERSAO_H
#define CONVERSAO_H

double celsius_para_fahrenheit(double celsius);
double km_para_milhas(double km);
double reais_para_dolares(double reais, double cotacao);
int conversoes_feitas(void);

#endif
```

O `conversao.c` tem o corpo das quatro funções, um contador `static` e uma
função auxiliar `static` (abra o arquivo na pasta). E o programa que usa só
precisa do `.h`:

```c
#include <stdio.h>

#include "conversao.h" // aspas: procura primeiro na pasta deste arquivo

int main(void) {
    printf("30 °C = %.1f °F\n", celsius_para_fahrenheit(30));
    printf("100 km = %.1f milhas\n", km_para_milhas(100));
    printf("R$ 1000.00 = US$ %.2f\n", reais_para_dolares(1000, 5.40));
    return 0;
}
// Compilando à mão (o rodar faz isso sozinho):
//   gcc -std=c17 -Wall -Wextra A067.c conversao.c -o viagem
// Saída:
// 30 °C = 86.0 °F
// 100 km = 62.1 milhas
// R$ 1000.00 = US$ 185.19
```

Repara no fluxograma: cada `.c` passa pelo compilador separado, e o erro de
"função que não existe" só aparece no fim, no ligador:

{{fluxograma}}

Três peças fecham o assunto:

- **include guard**: o trio `#ifndef CONVERSAO_H` / `#define CONVERSAO_H` /
  `#endif` faz o conteúdo do `.h` entrar **uma vez só** por `.c`, mesmo que
  ele seja incluído duas vezes (direto e por dentro de outro `.h`). Na
  primeira vez, `CONVERSAO_H` não existe: o texto entra e o nome é definido.
  Na segunda, o nome já existe e o texto é pulado. Use o nome do arquivo em
  maiúsculas.
- **`static` fora de função** esconde do resto do programa: o `contador` e a
  `contar` de `conversao.c` não existem para os outros arquivos. É o
  `private` do C, e é o que deixa o módulo mudar por dentro sem quebrar quem
  usa.
- **`extern`** declara uma global que foi **definida** noutro arquivo:
  `extern int limite;` no `.h`, `int limite = 10;` em **um** `.c` só. Use com
  moderação: global compartilhada entre arquivos é global de novo.

> [!WARNING]
> Pôr o **corpo** de uma função no `.h`. Se dois `.c` incluem esse `.h`, a
> função existe duas vezes e o ligador reclama `multiple definition of`. O
> include guard **não** salva: ele evita repetição dentro de um mesmo `.c`,
> não entre arquivos diferentes. No `.h` vão protótipos, `#define` e, mais
> para a frente, tipos. E nunca escreva `#include "conversao.c"`: funciona
> por acaso no começo e quebra assim que o projeto cresce.

> [!TIP]
> **Por dentro do C:** rode `gcc -c conversao.c` e depois `nm conversao.o`. As
> funções públicas aparecem com `T` (maiúsculo: visível para os outros); a
> `contar`, com `t`, e o `contador`, com `b` (minúsculos: `static`, só deste
> arquivo). Agora `gcc -c A067.c` e `nm A067.o`: as três conversões aparecem
> com `U`, de *undefined*. São os buracos que o ligador tapa. O `.h` não gera
> nada sozinho: ele só existe para o compilador.

> [!NOTE]
> **Pergunta para você:** se você apagar o `#include "conversao.h"` do
> `A067.c`, o programa compila? O que o gcc avisa? E se você apagar só o
> `conversao.c` da linha do `gcc`?

{{pratique}}

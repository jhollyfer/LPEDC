## 0034 · Módulos: .h, .c e compilação separada

Quando várias partes de um programa precisam converter quilômetros em milhas,
ninguém cola a conversão em cada uma. Ela mora num lugar só, e quem precisa a
usa. No C, esse lugar é um **módulo**: um par de arquivos.

- **`conversao.h`** (o *header*, cabeçalho): a **interface**. Diz **o que** o
  módulo oferece: protótipos das funções, constantes, tipos. É o contrato que
  quem usa precisa conhecer.
- **`conversao.c`**: a **implementação**. Diz **como**: o corpo das funções e
  tudo o que é interno. Inclui o próprio `.h`, para o compilador conferir que a
  implementação bate com o contrato.

Quem quer usar escreve `#include "conversao.h"`. O `#include` só **cola** o
texto do arquivo ali, e com ele o compilador conhece os protótipos e confere
cada chamada. Com aspas, o arquivo é procurado primeiro na pasta do seu `.c`;
com `< >`, só nas pastas do sistema.

Cada `.c` é compilado **sozinho**, sem saber dos outros, e vira um **arquivo
objeto** (`.o`). Ao ver `km_para_milhas(100)` em `viagem.c`, o compilador só
sabe que a função existe (o protótipo prometeu) e deixa um buraco com o nome
dela. Quem tapa o buraco é o **ligador** (*linker*), que junta os `.o` e
procura cada nome. Isso é a **compilação separada**:

```bash
gcc -std=c17 -Wall -Wextra -c conversao.c       # gera conversao.o
gcc -std=c17 -Wall -Wextra -c viagem.c            # gera viagem.o
gcc viagem.o conversao.o -o viagem                # o ligador junta
gcc -std=c17 -Wall -Wextra viagem.c conversao.c -o viagem   # ou tudo de uma vez
```

Num projeto grande, mudar um `.c` recompila só ele e liga de novo. No curso, o
gcc com as flags de estudo compila junto todo `.c` de apoio da pasta (todo
arquivo que não se chama `A000.c` ou `E000.c`).

O `conversao.h` é incluído pelos dois `.c`. Cada um vira um `.o`, e o ligador
junta os dois no executável `viagem`:

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
função auxiliar `static` (abra o arquivo na pasta). O programa que usa só
precisa do `.h` (chame-o de `viagem.c`):

```c
#include <stdio.h>

#include "conversao.h" // aspas: procura primeiro na pasta deste arquivo

int main(void) {
    printf("30 °C = %.1f °F\n", celsius_para_fahrenheit(30));
    printf("100 km = %.1f milhas\n", km_para_milhas(100));
    printf("R$ 1000.00 = US$ %.2f\n", reais_para_dolares(1000, 5.40));
    return 0;
}
// Compilando à mão (o gcc com as flags de estudo faz isso sozinho):
//   gcc -std=c17 -Wall -Wextra viagem.c conversao.c -o viagem
// Saída:
// 30 °C = 86.0 °F
// 100 km = 62.1 milhas
// R$ 1000.00 = US$ 185.19
```

Cada `.c` passa pelo compilador separado, e o erro de "função que não existe"
só aparece no fim, no ligador:

{{fluxograma}}

Três peças fecham o assunto:

- **include guard**: `#ifndef CONVERSAO_H` / `#define CONVERSAO_H` / `#endif`
  faz o conteúdo do `.h` entrar **uma vez** por `.c`, mesmo incluído duas vezes
  (direto e por dentro de outro `.h`). Na primeira vez, `CONVERSAO_H` não
  existe: o texto entra e o nome é definido. Na segunda, o nome já existe e o
  texto é pulado. Use o nome do arquivo em maiúsculas.
- **`static` fora de função** esconde do resto do programa: o `contador` e a
  `contar` de `conversao.c` não existem para os outros arquivos. Assim o módulo
  muda por dentro sem quebrar quem o usa.
- **`extern`** declara uma global **definida** noutro arquivo: `extern int
  limite;` no `.h`, `int limite = 10;` em **um** `.c` só. Use com moderação:
  global compartilhada entre arquivos é global de novo.

> [!WARNING]
> Pôr o **corpo** de uma função no `.h`. Se dois `.c` incluem esse `.h`, a
> função existe duas vezes e o ligador reclama `multiple definition of`. O
> include guard **não** salva: ele evita repetição dentro de um `.c`, não entre
> arquivos. No `.h` vão protótipos, `#define` e, mais adiante, tipos. E nunca
> escreva `#include "conversao.c"`: funciona por acaso no começo e quebra
> quando o projeto cresce.

> [!NOTE]
> **Pergunta para você:** se você apagar o `#include "conversao.h"` do
> `viagem.c`, o programa compila? O que o gcc avisa? E se você apagar só o
> `conversao.c` da linha do `gcc`?

{{pratique}}

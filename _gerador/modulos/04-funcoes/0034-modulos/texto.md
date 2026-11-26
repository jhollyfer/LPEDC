## 0034 · Módulos: .h, .c e compilação separada

Quando várias partes de um programa precisam converter quilômetros em milhas,
ninguém cola a conversão em cada uma. Ela mora num lugar só, e quem precisa a
usa. Até aqui, tudo cabia num arquivo `.c`, com as funções em cima e o `main`
embaixo. Num programa maior, esse arquivo vira centenas de linhas, e uma
função útil fica presa a um programa só. A saída é repartir o código em
arquivos.

Em C, cada pedaço é um **módulo**, formado por um par de arquivos (BACKES,
2013, cap. 13). Pense no cardápio e na cozinha de um restaurante. O cardápio
diz **o que** a casa oferece, com nome e preço; o cliente lê o cardápio e
pede, sem entrar na cozinha. A cozinha diz **como** cada prato é feito, e o
cliente não precisa saber. No módulo, o cardápio é o arquivo **`.h`**, o
cabeçalho (*header*), que forma a **interface**: os protótipos das funções, as
constantes e, mais adiante, os tipos. É o contrato que quem usa o módulo
precisa conhecer. A cozinha é o arquivo **`.c`**, a **implementação**: o
corpo das funções e tudo o que é interno. O `.c` inclui o próprio `.h`, para o
compilador conferir que a implementação bate com o contrato.

Quem quer usar o módulo escreve `#include "conversao.h"`. O `#include` só
**cola** o texto do arquivo naquele ponto (DEITEL; DEITEL, 2011, cap. 5). Com
os protótipos colados, o compilador conhece as funções e confere cada chamada.
A forma de escrever o nome muda onde o arquivo é procurado. Com aspas, a busca
começa na pasta do seu `.c`; com `< >`, como em `<stdio.h>`, a busca vai só às
pastas do sistema.

Cada `.c` é compilado **sozinho**, sem saber dos outros, e vira um **arquivo
objeto** (`.o`), um pedaço de código de máquina ainda incompleto (KERNIGHAN;
RITCHIE, 1989, cap. 4). Ao ver `km_para_milhas(100)` em `viagem.c`, o
compilador só sabe que a função existe, porque o protótipo prometeu, e deixa
um buraco com o nome dela. Quem tapa o buraco é o **ligador** (*linker*): ele
junta os `.o`, procura cada nome e gera o executável. Esse processo em duas
etapas é a **compilação separada**:

```bash
gcc -std=c17 -Wall -Wextra -c conversao.c       # gera conversao.o
gcc -std=c17 -Wall -Wextra -c viagem.c            # gera viagem.o
gcc viagem.o conversao.o -o viagem                # o ligador junta
gcc -std=c17 -Wall -Wextra viagem.c conversao.c -o viagem   # ou tudo de uma vez
```

A vantagem aparece no projeto grande: mudar um `.c` recompila só ele, e o
ligador junta tudo de novo. No curso, o gcc com as flags de estudo compila
junto todo `.c` de apoio da pasta, ou seja, todo arquivo que não se chama
`A000.c` ou `E000.c`.

Um `.h` pode acabar incluído duas vezes no mesmo `.c`, por exemplo quando
outro `.h` também o inclui. Aí as definições dele aparecem em dobro e o
compilador reclama. O **include guard** evita isso com três linhas:
`#ifndef CONVERSAO_H` e `#define CONVERSAO_H` no topo, `#endif` no fim (GNU,
s.d.). Na primeira inclusão, o nome ainda não existe, o conteúdo entra e o
nome é definido. Na segunda, o nome já existe e o conteúdo inteiro é pulado.

O módulo também esconde o que é interno. Uma global ou uma função marcada com
**`static`** fora de qualquer função fica visível só dentro do seu `.c`
(KERNIGHAN; RITCHIE, 1989, cap. 4). Assim você muda a cozinha por dentro sem
quebrar quem usa o cardápio. O caminho oposto é o **`extern`**: ele declara
uma global definida noutro arquivo. Você escreve `extern int limite;` no `.h`
e `int limite = 10;` em um `.c` só, e todos os arquivos que incluem o `.h`
passam a enxergar a mesma variável (BACKES, 2013, cap. 13).

> [!WARNING]
> Pôr o **corpo** de uma função no `.h`. Se dois `.c` incluem esse `.h`, a
> função existe duas vezes e o ligador reclama `multiple definition of`. O
> include guard **não** salva: ele evita repetição dentro de um `.c`, não entre
> arquivos. E nunca escreva `#include "conversao.c"`.

{{exemplo}}

A conversão de unidades mora num módulo só. O `conversao.h` é incluído pelos
dois `.c`; cada um vira um `.o`, e o ligador junta os dois no executável
`viagem`:

{{ideia}}

O `conversao.h`:

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

O `conversao.c` (na pasta do assunto) tem o corpo das funções, um contador
`static` e uma função auxiliar `static`. O `viagem.c` só precisa do `.h`:

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

Cada `.c` passa pelo compilador separado; o erro de "função que não existe"
só aparece no ligador:

{{fluxograma}}

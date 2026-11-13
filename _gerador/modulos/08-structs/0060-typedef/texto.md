## 0060 · Typedef

No assunto anterior, todo pedido era declarado como `struct pedido p1;`. As
duas palavras sempre juntas cansam num programa grande, e o nome do tipo fica
mais comprido que a ideia que ele representa. O C oferece um jeito de dar um
nome mais curto, ou mais expressivo, a um tipo que já existe.

No grupo da família, ninguém chama o seu tio de "José Carlos da Silva". É
"Zé". O apelido não cria outra pessoa: é o mesmo tio, com um nome mais
prático. O **typedef** faz isso com tipos: ele dá um **apelido** a um tipo
existente e cria um sinônimo, sem criar um tipo novo (BACKES, 2013, cap. 8).

A forma de escrever segue uma regra simples. Escreva a declaração de uma
variável do jeito de sempre e ponha a palavra `typedef` na frente. O nome que
seria a variável passa a ser o nome do tipo (FEOFILOFF, 2009, ap. J):

```c
double Reais;          // uma variável chamada Reais
typedef double Reais;  // um apelido: Reais agora é o mesmo que double
```

Depois da segunda linha, `Reais saldo;` e `double saldo;` declaram
exatamente a mesma coisa. O ganho é de leitura: quem vê `Reais` entende que
ali mora dinheiro, e o compilador continua vendo um `double`.

O uso mais comum é com struct, e há duas maneiras. Você pode batizar uma
struct que já tem nome, com `typedef struct pix Pix;`, ou fazer tudo de uma
vez, declarando a struct sem nome e dando o apelido logo depois da chave
(DEITEL; DEITEL, 2011, cap. 10):

```c
typedef struct {
    char chave[40];
    Reais valor;
    int hora;
} Pix;
```

A partir daí, `Pix p;` basta, sem a palavra `struct`. Repare que o campo
`valor` usa o apelido `Reais` definido antes: um typedef pode usar outro.
Escrever nome de tipo com a inicial maiúscula é uma convenção, e ela ajuda a
separar tipo de variável no meio do código: `Pix` é o tipo, `p` é a variável
(DEITEL; DEITEL, 2011, cap. 10).

Struct, union e enum, com ou sem `typedef`, formam o que os livros e o edital
chamam de **tipos definidos pelo programador**: tipos que não vêm prontos com
a linguagem, e que você monta para descrever o seu problema (CELES; CERQUEIRA;
RANGEL, 2016). Os próximos assuntos apresentam o enum e a union.

Você já usou vários typedefs sem saber. `size_t`, o tipo que o `sizeof`
devolve, `uint8_t`, `int32_t` e o `FILE` do módulo 09 são apelidos definidos
nos cabeçalhos da biblioteca (KERNIGHAN; RITCHIE, 1988, cap. 6). O `uint8_t`
mostra a vantagem: ele quer dizer "exatamente 8 bits sem sinal" em qualquer
máquina, e cada compilador o liga ao tipo certo por baixo. Você escreve o
mesmo código e o apelido cuida da diferença entre máquinas.

Como o typedef só dá outro nome, o compilador não distingue o apelido do
original. Isso tem um lado bom (o apelido funciona em qualquer lugar que
aceita o tipo) e um lado perigoso, que o alerta abaixo mostra.

> [!WARNING]
> `typedef` cria um **sinônimo**, não um tipo novo. Com `typedef double Reais;`
> e `typedef double Dolares;`, `Reais r = dolares;` compila: os dois são
> `double`. Para o compilador barrar a mistura, embrulhe numa struct:
> `typedef struct { double v; } Reais;`. E `typedef int *PInt;` esconde que
> `PInt a, b;` são ponteiros.

{{exemplo}}

Um Pix de R$ 1.500,00 às 22h esbarra no limite noturno de R$ 1.000,00 (entre
20h e 6h). `Pix` e `Reais` são só etiquetas coladas em tipos que já existiam:

{{ideia}}

```c
#include <stdbool.h>
#include <stdio.h>

typedef double Reais; // Reais é só outro nome para double

typedef struct {      // struct sem nome, batizada de Pix pelo typedef
    char chave[40];
    Reais valor;
    int hora;         // 0 a 23
} Pix;

#define LIMITE_NOTURNO 1000.0

bool pix_permitido(Pix p) {
    bool noturno = p.hora >= 20 || p.hora < 6;
    return !(noturno && p.valor > LIMITE_NOTURNO);
}

int main(void) {
    Pix p = {"ana@email.com", 1500.00, 22}; // sem a palavra struct

    printf("Pix de R$ %.2f para %s às %dh\n", p.valor, p.chave, p.hora);
    if (pix_permitido(p)) {
        printf("Enviado!\n");
    } else {
        printf("Bloqueado: o limite noturno é R$ %.2f\n", LIMITE_NOTURNO);
    }
    return 0;
}
// Saída:
// Pix de R$ 1500.00 para ana@email.com às 22h
// Bloqueado: o limite noturno é R$ 1000.00
```

O Pix só é bloqueado se for horário noturno **e** o valor passar do limite:

{{fluxograma}}

## 0065 · Typedef

No grupo da família, ninguém chama o seu tio de "José Carlos da Silva". É
"Zé". O apelido não cria outra pessoa: é o mesmo tio, com um nome mais curto.

No assunto anterior, todo pedido era declarado como `struct pedido p1;`, com
as duas palavras, toda vez. Em programa grande isso cansa e polui. O C tem um
jeito de dar apelido a um tipo: o **typedef**.

A regra é: escreva uma declaração de variável normal e ponha `typedef` na
frente. O nome que seria a variável vira o **nome do tipo**:

```c
double Reais;          // uma variável chamada Reais
typedef double Reais;  // um apelido: Reais agora é o mesmo que double
```

O uso mais comum é com struct. Dá para batizar uma struct que já existe
(`typedef struct pix Pix;`) ou fazer tudo de uma vez, sem nem dar nome à
struct:

```c
typedef struct {
    char chave[40];
    Reais valor;
    int hora;
} Pix;
```

A partir daí você escreve só `Pix p;`, sem o `struct` na frente. Nomes de tipo com inicial maiúscula são uma convenção comum (e
a deste curso) para não confundir tipo com variável.

Vamos ver na prática. Um Pix de R$ 1.500,00 às 22h esbarra no limite noturno
de R$ 1.000,00 que os bancos aplicam entre 20h e 6h. Repare que `Pix` e
`Reais` são só etiquetas novas coladas em coisas que já existiam:

{{ideia}}

O programa usa os dois apelidos. A função recebe um `Pix` e decide:

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

Você já usou vários typedefs sem saber: `size_t`, `uint8_t`, `int32_t` e até
o `FILE` que vem no módulo 09 são apelidos definidos nos cabeçalhos da
biblioteca. O `uint8_t` existe para você dizer "quero exatamente 8 bits sem
sinal" sem depender do nome do tipo em cada máquina.

Repara no fluxograma: são duas perguntas em sequência. Só bloqueia se for
horário noturno **e** o valor passar do limite:

{{fluxograma}}

> [!WARNING]
> `typedef` cria um **sinônimo**, não um tipo novo. Com `typedef double Reais;`
> e `typedef double Dolares;`, o compilador aceita `Reais r = dolares;` sem
> piscar: para ele, os dois são `double`. Se você quer que o compilador
> barre a mistura, embrulhe numa struct: `typedef struct { double v; } Reais;`.
> Structs diferentes não se misturam. E cuidado com typedef que esconde
> demais: `typedef int *PInt;` faz `PInt a, b;` parecer inocente, mas esconde
> que são ponteiros.

> [!TIP]
> **Por dentro do C:** o typedef não existe no executável. Ele é resolvido
> pelo compilador e some, sem custo nenhum. Para ver de onde vem um apelido da
> biblioteca, rode `gcc -E A129.c | grep "typedef.* size_t;"`: no Linux de 64
> bits aparece `typedef long unsigned int size_t;`. Diferente do `#define`, que
> o pré-processador troca como texto, o typedef entende a gramática do C:
> `typedef char *Texto; Texto a, b;` faz **os dois** serem ponteiros, enquanto
> `#define Texto char *` deixaria `b` como um `char` comum.

> [!NOTE]
> **Pergunta para você:** e se o mesmo Pix de R$ 1.500,00 fosse feito às 6h
> em ponto? E às 5h59? Siga as duas perguntas do fluxograma para cada caso.

{{pratique}}

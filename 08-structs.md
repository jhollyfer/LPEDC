<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/08-structs/ e rode: cd _gerador && npm run gerar -->

# Módulo 08 · Tipos compostos

> [!IMPORTANT]
> **Mundo 2 · Memória e dados · Rota do jogo: etapa 8 de 29**
>
> **Missão:** agrupar dados com `struct`, `union`, `enum` e operações com bits.
>
> **Vem de:** [Módulo 07 · Memória dinâmica](07-memoria-dinamica.md). **Segue para:** [Módulo 27 · Detalhes de C que caem em prova](27-c-detalhes.md).
>
> **Checkpoints desta fase:**
> - [ ] Ler os assuntos 0059 a 0066 e refazer os exemplos
> - [ ] Resolver os 4 exercícios de cada assunto, escrevendo o código sozinho
> - [ ] Fechar a lista prática (P0801 a P0830)
> - [ ] Enfrentar os desafios do módulo
> - [ ] Chefão: resolver as questões de prova do módulo sem consultar

Até aqui, cada variável guardava uma coisa só: um número, um caractere, um
vetor de itens iguais. Os dados reais vêm em pacotes: um pedido tem tamanho,
quantidade e preço; um time tem nome, vitórias e empates. Este módulo ensina o
C a guardar pacotes.

No C, você desenha o pacote byte a byte: decide a ordem dos campos (e paga as
sobras de alinhamento), se ele anda por cópia ou por ponteiro (e paga a
cópia) e se dois campos dividem a mesma memória. Você passa a saber o que um
objeto **custa**.

O módulo fecha no nível do bit: máscaras e flags, o jeito mais compacto de
guardar sim/não. Struct, ponteiro para struct e `malloc` são as peças das
estruturas de dados que começam no módulo 10.

## O que você vai aprender

- **struct**: campos, ponto, cópia por atribuição e alinhamento
- **typedef**, e por que não cria um tipo novo
- **vetores de structs**: montar, percorrer e ordenar
- **ponteiro para struct**: seta `->`, struct no heap e custo de passar por valor
- **enum** para estados e opções
- **union** e **endianness**
- **bits** com `& | ^ ~ << >>`, máscaras e flags (as permissões `rwx` do Linux)

## Antes de começar

Este módulo usa os anteriores: funções, vetores, strings com `fgets`,
ponteiros, `malloc`/`realloc`/`free` (módulo 07) e `qsort`. Se `int *p =
malloc(n * sizeof *p);` não parece natural, revise o 07.

Os comentários com `sizeof` e ordem de bytes valem para um PC de 64 bits com
Linux (Intel, AMD ou ARM); em outra máquina os números podem mudar. Ao rodar,
troque a ordem dos campos de uma struct e compare o `sizeof`.

```bash
gcc ~/LPEDC/material/A117.c -o ~/LPEDC/material/A117 && ~/LPEDC/material/A117
```

| # | Assunto |
| --- | --- |
| [0059](#0059--struct) | Struct |
| [0060](#0060--typedef) | Typedef |
| [0061](#0061--vetor-de-structs) | Vetor de structs |
| [0062](#0062--ponteiro-para-struct) | Ponteiro para struct |
| [0063](#0063--enum) | Enum |
| [0064](#0064--union) | Union |
| [0065](#0065--bits-máscaras-e-flags) | Bits, máscaras e flags |
| [0066](#0066--juntando-tudo-o-cardápio) | Juntando tudo: o cardápio |

---

## 0059 · Struct

Você pede açaí pelo app: copo M, 2 unidades, R$ 18,50 cada. Para o sistema, o
pedido é um pacote de três informações de tipos diferentes (um caractere, um
inteiro e um preço) que andam sempre juntas.

Com variáveis soltas (`char tamanho`, `int quantidade`, `double preco`), dez
pedidos seriam trinta variáveis, e nada diz que `tamanho3` e `preco3` são do
mesmo pedido. O C resolve isso com a **struct**.

Uma struct **agrupa variáveis de tipos diferentes sob um nome só**. Cada
variável de dentro é um **campo** (ou membro). Nos livros e na prova também se
chama **registro** (ou estrutura). `int`, `char` e `double` são **dados
simples**: guardam um valor só. Vetor e struct são **dados compostos**: o
vetor junta valores do mesmo tipo (homogêneo); a struct, de tipos diferentes
(heterogêneo). Primeiro você descreve o molde:

```c
struct pedido {
    char tamanho;
    int quantidade;
    double preco;
};   // <- esse ; é obrigatório
```

Isso cria um **tipo novo**, `struct pedido` (as duas palavras). O molde não
ocupa memória: é a planta da casa. A memória aparece ao declarar uma
variável: `struct pedido p1;`.

Para inicializar, use chaves com os valores **na ordem dos campos**:
`{'M', 2, 18.50}`. Ou, mais seguro, com o nome de cada campo (C99):
`{.tamanho = 'M', .quantidade = 2, .preco = 18.50}`. Campo não citado começa
com zero. O **literal composto** cria uma struct "na hora", sem variável:
`(struct pedido){'G', 1, 22.00}`, útil para passar direto a uma função.

O **ponto** lê ou muda um campo: `p1.quantidade`, `p1.preco = 20.0`. Cada
campo é uma variável comum do seu tipo: `p1.tamanho` é `char`,
`&p1.quantidade` é `int *`.

A variável `p1` é um bloco de memória com os três campos em sequência. O
programa multiplica dois deles, chega a R$ 37,00 e decide o frete. O buraco
cinza entre `tamanho` e `quantidade` é explicado na dica abaixo:

<p align="center"><img src="material/0059-ideia.svg" alt="Diagrama da ideia: Struct" width="916"></p>

O mesmo pedido em C:

```c
#include <stdio.h>

// o molde: diz quais campos um pedido tem (ainda não reserva memória)
struct pedido {
    char tamanho;   // 'P', 'M' ou 'G'
    int quantidade; // quantos copos
    double preco;   // preço de cada copo
};

int main(void) {
    struct pedido p1 = {'M', 2, 18.50}; // os valores vão na ordem dos campos

    double total = p1.quantidade * p1.preco; // o ponto acessa um campo
    printf("Pedido: %d copos %c de R$ %.2f\n", p1.quantidade, p1.tamanho, p1.preco);
    printf("Total: R$ %.2f\n", total);

    if (total >= 30.0) {
        printf("Frete grátis!\n");
    } else {
        printf("Frete: R$ 5.00\n");
    }
    printf("O pedido ocupa %zu bytes\n", sizeof(struct pedido));
    return 0;
}
// Saída:
// Pedido: 2 copos M de R$ 18.50
// Total: R$ 37.00
// Frete grátis!
// O pedido ocupa 16 bytes
```

Uma struct pode ter vetores e outras structs dentro (`cliente.end.cidade`,
ponto encadeado). A atribuição `b = a` funciona entre structs do **mesmo
tipo** e copia todos os bytes, inclusive os vetores de dentro (vetor sozinho
não se copia com `=`).

A struct não muda os passos do programa; só leva os dados num pacote:

<p align="center"><img src="material/0059-fluxograma.svg" alt="Fluxograma: Struct" width="462"></p>

> [!WARNING]
> `struct pedido p2 = p1;` cria uma **cópia independente**: mudar
> `p2.quantidade` não mexe em `p1`. Também não funcionam `p1 == p2` (não
> compila; compare campo a campo) e `cliente.nome = "Ana";` (use
> `strcpy(cliente.nome, "Ana")`). E o `;` depois da `}` do molde é
> obrigatório: sem ele o erro aparece numa linha seguinte.

> [!TIP]
> Os campos seguem a ordem declarada, mas não colados. `char` (1) + `int` (4)
> + `double` (8) somam 13 bytes e o `sizeof` diz 16: o compilador alinha o
> `int` em múltiplo de 4 e o `double` em múltiplo de 8, pulando 3 bytes de
> **preenchimento** (*padding*) depois de `tamanho`. `offsetof(struct pedido,
> preco)`, de `<stddef.h>`, dá 8. Por causa desses bytes de lixo o C não
> compara structs com `==`.

> [!NOTE]
> **Pergunta para você:** se você trocar a ordem dos campos para `double
> preco; int quantidade; char tamanho;`, o `sizeof` muda? E com `char
> tamanho; double preco; int quantidade;`? Desenhe os bytes antes de rodar.

### Hora de praticar

**Exemplo A117 · A matrícula na academia**

```c
#include <stddef.h>
#include <stdio.h>

struct aluno {
    char plano;       // 'M' mensal, 'T' trimestral, 'A' anual
    int faltas;       // faltas no mês
    double mensalidade;
    int armario;      // 0 = sem armário
};

int main(void) {
    // com nome de campo, a ordem é livre; quem não aparece começa com zero
    struct aluno caio = {.mensalidade = 99.90, .plano = 'M'};
    printf("Caio: plano %c, R$ %.2f, %d faltas, armário %d\n",
           caio.plano, caio.mensalidade, caio.faltas, caio.armario);

    // literal composto: troca a struct inteira de uma vez
    caio = (struct aluno){'A', 0, 79.90, 12};
    printf("Caio: plano %c, R$ %.2f, %d faltas, armário %d\n",
           caio.plano, caio.mensalidade, caio.faltas, caio.armario);

    // comparar structs: campo a campo (== entre structs não compila)
    struct aluno duda = caio;
    duda.armario = 13;
    if (duda.plano == caio.plano && duda.mensalidade == caio.mensalidade) {
        printf("Duda e Caio têm o mesmo plano\n");
    }
    if (duda.armario != caio.armario) {
        printf("mas armários diferentes: %d e %d\n", duda.armario, caio.armario);
    }

    // onde cada campo começa dentro da struct
    printf("plano em %zu, faltas em %zu, mensalidade em %zu, armario em %zu\n",
           offsetof(struct aluno, plano), offsetof(struct aluno, faltas),
           offsetof(struct aluno, mensalidade), offsetof(struct aluno, armario));
    // 16 + 4 = 20, mas o total arredonda para múltiplo de 8 (o double): 24
    printf("sizeof: %zu bytes\n", sizeof(struct aluno));
    return 0;
}
// Saída:
// Caio: plano M, R$ 99.90, 0 faltas, armário 0
// Caio: plano A, R$ 79.90, 0 faltas, armário 12
// Duda e Caio têm o mesmo plano
// mas armários diferentes: 13 e 12
// plano em 0, faltas em 4, mensalidade em 8, armario em 16
// sizeof: 24 bytes
```

```bash
gcc ~/LPEDC/material/A117.c -o ~/LPEDC/material/A117 && ~/LPEDC/material/A117
```

**Exemplo A118 · A ficha copiada**

```c
#include <stdio.h>
#include <string.h>

struct endereco {
    char cidade[20];
    char uf[3];
};

// uma struct pode ter outra struct dentro (struct aninhada)
struct cliente {
    char nome[20];
    int pontos;
    struct endereco end;
};

int main(void) {
    // inicialização com nomes de campo (C99): a ordem não importa
    struct cliente ana = {
        .nome = "Ana",
        .pontos = 120,
        .end = {.cidade = "Recife", .uf = "PE"},
    };

    struct cliente copia = ana; // copia TODOS os bytes, inclusive os vetores
    strcpy(copia.nome, "Bia");  // campo vetor: strcpy, não =
    copia.pontos = 0;
    strcpy(copia.end.cidade, "Natal"); // ponto encadeado: copia.end.cidade

    printf("%s, %d pontos, %s-%s\n", ana.nome, ana.pontos, ana.end.cidade, ana.end.uf);
    printf("%s, %d pontos, %s-%s\n", copia.nome, copia.pontos, copia.end.cidade, copia.end.uf);
    return 0;
}
// Saída:
// Ana, 120 pontos, Recife-PE
// Bia, 0 pontos, Natal-PE
```

```bash
gcc ~/LPEDC/material/A118.c -o ~/LPEDC/material/A118 && ~/LPEDC/material/A118
```

#### Exercícios

**Exercício E349** · ★☆☆

Crie uma struct livro com os campos titulo (até 39 letras), autor (até 29
letras), ano (int) e preco (double). Declare uma variável já inicializada
com o livro abaixo e mostre os campos e o preço com 10% de desconto.


```text
Saída esperada:
Livro: Dom Casmurro
Autor: Machado de Assis
Ano: 1899
Preço: R$ 34.90
Na promoção: R$ 31.41
```

```bash
gcc ~/LPEDC/material/E349.c -o ~/LPEDC/material/E349 && ~/LPEDC/material/E349
```

**Exercício E351** · ★★☆

Um terreno retangular é descrito por dois cantos: o inferior esquerdo
(2, 1) e o superior direito (10, 6), em metros. Crie uma struct ponto
(x e y, double) e uma struct retangulo com dois campos struct ponto. Escreva
funções que recebem o retângulo e devolvem a área e o perímetro, e uma que
diz se um ponto (uma árvore, por exemplo) está dentro do terreno.


```text
Saída esperada:
Largura: 8.0 m, altura: 5.0 m
Área: 40.0 m2
Perímetro: 26.0 m
Árvore em (4.0, 3.0): dentro
Árvore em (11.0, 2.0): fora
```

```bash
gcc ~/LPEDC/material/E351.c -o ~/LPEDC/material/E351 && ~/LPEDC/material/E351
```

**Exercício E352** · ★★☆

Crie a struct jogadora com nome (até 19 letras) e gols (int). Guarde em a a
artilheira Marta, com 17 gols (o nome entra com strcpy), copie a para b com
uma atribuição e mostre b. Depois confira se as duas fichas são iguais,
comparando campo a campo (o == não funciona com struct).


```text
Saída esperada:
Marta: 17 gols
a e b são iguais
```

```bash
gcc ~/LPEDC/material/E352.c -o ~/LPEDC/material/E352 && ~/LPEDC/material/E352
```

**Exercício E353** · ★★★

Crie uma struct data (dia, mes, ano) e escreva:


```text
- struct data dia_seguinte(struct data d): devolve a data do dia seguinte,
  tratando fim de mês, fim de ano e fevereiro em ano bissexto;
- int comparar(struct data a, struct data b): devolve -1 se a vem antes,
  0 se são iguais e 1 se a vem depois.
```


Teste com as datas abaixo:


```text
Saída esperada:
28/02/2024 -> 29/02/2024
28/02/2025 -> 01/03/2025
31/12/2025 -> 01/01/2026
15/03/2025 vem antes de 02/11/2025
```

```bash
gcc ~/LPEDC/material/E353.c -o ~/LPEDC/material/E353 && ~/LPEDC/material/E353
```

---

## 0060 · Typedef

No grupo da família, ninguém chama o seu tio de "José Carlos da Silva". É
"Zé". O apelido não cria outra pessoa: é o mesmo tio, com nome mais curto.

No assunto anterior, todo pedido era declarado como `struct pedido p1;`. Em
programa grande isso cansa. O **typedef** dá apelido a um tipo. Struct, union
e enum, com ou sem `typedef`, são os **tipos definidos pelo programador** dos
livros e do edital.

A regra: escreva uma declaração de variável normal e ponha `typedef` na
frente. O nome que seria a variável vira o **nome do tipo**:

```c
double Reais;          // uma variável chamada Reais
typedef double Reais;  // um apelido: Reais agora é o mesmo que double
```

O uso mais comum é com struct. Dá para batizar uma struct existente
(`typedef struct pix Pix;`) ou fazer tudo de uma vez, sem nome para a struct:

```c
typedef struct {
    char chave[40];
    Reais valor;
    int hora;
} Pix;
```

A partir daí você escreve só `Pix p;`. Inicial maiúscula em nome de tipo é
convenção deste curso, para não confundir tipo com variável.

Um Pix de R$ 1.500,00 às 22h esbarra no limite noturno de R$ 1.000,00 que os
bancos aplicam entre 20h e 6h. No desenho, `Pix` e `Reais` são só etiquetas
coladas em coisas que já existiam:

<p align="center"><img src="material/0060-ideia.svg" alt="Diagrama da ideia: Typedef" width="858"></p>

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

Você já usou typedefs: `size_t`, `uint8_t`, `int32_t` e o `FILE` do módulo 09
são apelidos definidos nos cabeçalhos. O `uint8_t` diz "exatamente 8 bits sem
sinal", sem depender do nome do tipo em cada máquina.

São duas perguntas: o Pix só é bloqueado se for horário noturno **e** o valor
passar do limite:

<p align="center"><img src="material/0060-fluxograma.svg" alt="Fluxograma: Typedef" width="403"></p>

> [!WARNING]
> `typedef` cria um **sinônimo**, não um tipo novo. Com `typedef double Reais;`
> e `typedef double Dolares;`, `Reais r = dolares;` compila: os dois são
> `double`. Para o compilador barrar a mistura, embrulhe numa struct:
> `typedef struct { double v; } Reais;`. E `typedef int *PInt;` esconde que
> `PInt a, b;` são ponteiros.

> [!NOTE]
> **Pergunta para você:** e se o mesmo Pix de R$ 1.500,00 fosse feito às 6h
> em ponto? E às 5h59? Siga as duas perguntas do fluxograma para cada caso.

### Hora de praticar

**Exemplo A119 · A frota de ônibus**

```c
#include <stdio.h>
#include <string.h>

typedef char Placa[8];      // apelido para um vetor: Placa é "char[8]"
typedef unsigned Minutos;   // apelido para um tipo simples

typedef struct onibus Onibus; // apelido antes da struct existir

struct onibus {             // a struct com nome: dá para usar os dois nomes
    Placa placa;
    int linha;
    Minutos atraso;
};

void mostrar(Onibus o) {
    printf("Linha %d (%s): %u min de atraso\n", o.linha, o.placa, o.atraso);
}

int main(void) {
    Onibus a = {"QWE1R23", 512, 0};
    struct onibus b = {"RTY4U56", 307, 15}; // o nome completo também vale
    Minutos tolerancia = 10;

    mostrar(a);
    mostrar(b);
    if (b.atraso > tolerancia) {
        printf("Linha %d passou da tolerância de %u min\n", b.linha, tolerancia);
    }

    Placa nova;              // é um vetor de 8 char, como qualquer outro
    strcpy(nova, "ZXC7V89"); // vetor: strcpy, não =
    printf("Placa nova: %s, %zu bytes\n", nova, sizeof nova);
    printf("Onibus ocupa %zu bytes, igual a struct onibus: %zu\n",
           sizeof(Onibus), sizeof(struct onibus));
    return 0;
}
// Saída:
// Linha 512 (QWE1R23): 0 min de atraso
// Linha 307 (RTY4U56): 15 min de atraso
// Linha 307 passou da tolerância de 10 min
// Placa nova: ZXC7V89, 8 bytes
// Onibus ocupa 16 bytes, igual a struct onibus: 16
```

```bash
gcc ~/LPEDC/material/A119.c -o ~/LPEDC/material/A119 && ~/LPEDC/material/A119
```

**Exemplo A120 · A cor do site**

```c
#include <stdint.h>
#include <stdio.h>

typedef uint8_t Byte; // uint8_t já é um typedef (de unsigned char)

typedef struct {
    Byte r, g, b;     // cada canal de 0 a 255
} Cor;

Cor misturar(Cor a, Cor b) {
    Cor m = {(a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2};
    return m;
}

void mostrar(const char *nome, Cor c) {
    printf("%-8s #%02X%02X%02X  (%3d, %3d, %3d)\n", nome, c.r, c.g, c.b, c.r, c.g, c.b);
}

int main(void) {
    Cor laranja = {255, 136, 0};
    Cor branco = {255, 255, 255};

    mostrar("laranja", laranja);
    mostrar("branco", branco);
    mostrar("mistura", misturar(laranja, branco));
    printf("Uma Cor ocupa %zu bytes\n", sizeof(Cor));
    return 0;
}
// Saída:
// laranja  #FF8800  (255, 136,   0)
// branco   #FFFFFF  (255, 255, 255)
// mistura  #FFC37F  (255, 195, 127)
// Uma Cor ocupa 3 bytes
```

```bash
gcc ~/LPEDC/material/A120.c -o ~/LPEDC/material/A120 && ~/LPEDC/material/A120
```

#### Exercícios

**Exercício E355** · ★☆☆

Crie com typedef o tipo Produto (nome até 19 letras, quantidade int e preco
double). Escreva double subtotal(Produto p) e void mostrar(Produto p). No
main, crie Café (3 unidades a R$ 12.50) e Leite (6 a R$ 4.99), mostre os dois
e o total da compra.


```text
Saída esperada:
Café: 3 x R$ 12.50 = R$ 37.50
Leite: 6 x R$ 4.99 = R$ 29.94
Total: R$ 67.44
```

```bash
gcc ~/LPEDC/material/E355.c -o ~/LPEDC/material/E355 && ~/LPEDC/material/E355
```

**Exercício E357** · ★★☆

Na receita de bolo você soma 1/4 de xícara com 1/6 de xícara. Crie o tipo
Fracao (numerador e denominador inteiros) com typedef e escreva:


```text
- Fracao simplificar(Fracao f): divide os dois pelo MDC;
- Fracao somar(Fracao a, Fracao b) e Fracao multiplicar(Fracao a, Fracao b),
  que já devolvem a fração simplificada.
```



```text
Saída esperada:
1/4 + 1/6 = 5/12
2/3 * 9/4 = 3/2
3/4 + 1/4 = 1/1
```

```bash
gcc ~/LPEDC/material/E357.c -o ~/LPEDC/material/E357 && ~/LPEDC/material/E357
```

**Exercício E358** · ★★☆

Crie com typedef o apelido Reais para double e o tipo Cartao (struct sem
nome, com titular de até 19 letras e saldo em Reais). Escreva
Cartao pagar(Cartao c, Reais valor), que devolve uma cópia do cartão com o
valor descontado do saldo. Ana tem R$ 600.00 no vale-refeição e paga um
almoço de R$ 36.50: mostre o saldo antes e depois.


```text
Saída esperada:
Ana: R$ 600.00 -> R$ 563.50
```

```bash
gcc ~/LPEDC/material/E358.c -o ~/LPEDC/material/E358 && ~/LPEDC/material/E358
```

**Exercício E359** · ★★★

Ponteiro para função (assunto 0050) tem uma declaração difícil de ler:
double (*f)(double, double). Com typedef ela fica limpa. Crie:


```text
typedef double (*Operacao)(double, double);
```


e um tipo Botao (struct com um char simbolo e uma Operacao). Monte um
vetor com os quatro botões de uma calculadora (+ - * /) e, num laço, aplique
cada um aos números 12 e 4.


```text
Saída esperada:
12 + 4 = 16
12 - 4 = 8
12 * 4 = 48
12 / 4 = 3
```

```bash
gcc ~/LPEDC/material/E359.c -o ~/LPEDC/material/E359 && ~/LPEDC/material/E359
```

---

## 0061 · Vetor de structs

Na tabela do campeonato, cada linha é um time e todas têm as mesmas colunas:
nome, vitórias, empates, derrotas. Uma linha é uma struct. A tabela inteira é
um **vetor de structs**.

`Time tabela[4];` são quatro `Time` seguidos na memória: os bytes das structs
ficam **dentro** do vetor, um time colado no outro.

Para chegar a um campo, escolha a linha e depois a coluna: `tabela[2].nome`. O
índice vem **antes** do ponto, porque `tabela[2]` é um `Time`, e um `Time` tem
o campo `nome`. `tabela.nome[2]` não faz sentido: o vetor não tem campos.

A inicialização junta as duas sintaxes, chaves dentro de chaves:

```c
Time tabela[] = {
    {"Bahia", 8, 5, 3},
    {"Flamengo", 9, 6, 1},
};
```

Sem o tamanho entre colchetes, o compilador conta os elementos. O truque de
sempre dá a quantidade: `sizeof tabela / sizeof tabela[0]`.

São quatro times. O programa percorre o vetor, calcula os pontos de cada um (3
por vitória, 1 por empate) e guarda o **índice** do melhor até agora.
Palmeiras, no índice 2, termina na frente:

<p align="center"><img src="material/0061-ideia.svg" alt="Diagrama da ideia: Vetor de structs" width="858"></p>

O código faz esse passeio:

```c
#include <stdio.h>

typedef struct {
    char nome[20];
    int vitorias;
    int empates;
    int derrotas;
} Time;

int pontos(Time t) {
    return 3 * t.vitorias + t.empates;
}

int main(void) {
    Time tabela[] = {
        {"Bahia", 8, 5, 3},
        {"Flamengo", 9, 6, 1},
        {"Palmeiras", 10, 4, 2},
        {"Vasco", 7, 7, 2},
    };
    int n = sizeof tabela / sizeof tabela[0]; // 4 times

    int lider = 0; // índice do melhor até agora
    for (int i = 0; i < n; i++) {
        printf("%d. %-10s %2d pts\n", i, tabela[i].nome, pontos(tabela[i]));
        if (pontos(tabela[i]) > pontos(tabela[lider])) {
            lider = i;
        }
    }
    printf("Líder: %s, com %d pontos\n", tabela[lider].nome, pontos(tabela[lider]));
    printf("A tabela ocupa %zu bytes (%d x %zu)\n", sizeof tabela, n, sizeof(Time));
    return 0;
}
// Saída:
// 0. Bahia      29 pts
// 1. Flamengo   33 pts
// 2. Palmeiras  34 pts
// 3. Vasco      28 pts
// Líder: Palmeiras, com 34 pontos
// A tabela ocupa 128 bytes (4 x 32)
```

Guardar o índice, e não uma cópia, é de propósito: com ele você sabe **onde**
está o líder e pode mexer nele (`tabela[lider].vitorias++`). Uma cópia seria
um time solto, desligado da tabela.

É o padrão "maior até agora" do módulo de laços, comparando um valor
calculado de cada struct:

<p align="center"><img src="material/0061-fluxograma.svg" alt="Fluxograma: Vetor de structs" width="575"></p>

> [!WARNING]
> `tabela[i] = tabela[j]` copia o time **inteiro**. Use para trocar dois times
> ao ordenar: troque as structs, não campo a campo (trocar só o nome embaralha
> nomes e pontos). O C não confere limites: `tabela[4]` num vetor de 4 times
> lê lixo ou derruba o programa, como num vetor de `int`.

> [!NOTE]
> **Pergunta para você:** se o Vasco tivesse 9 vitórias, 7 empates e 0
> derrotas, quem seria o líder? E se houvesse empate em pontos com o
> Palmeiras, com o `>` do código, quem ficaria: o primeiro ou o último a
> aparecer na tabela?

### Hora de praticar

**Exemplo A121 · O estoque da farmácia**

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int estoque;
    int minimo; // abaixo disso, precisa repor
} Remedio;

// devolve o índice do remédio com esse nome, ou -1 se não achar
int buscar(const Remedio v[], int n, const char *nome) {
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void vender(Remedio v[], int n, const char *nome, int qtd) {
    int i = buscar(v, n, nome);
    if (i == -1) {
        printf("%s: não temos\n", nome);
    } else if (v[i].estoque < qtd) {
        printf("%s: só restam %d\n", nome, v[i].estoque);
    } else {
        v[i].estoque -= qtd; // mexe direto no elemento do vetor
        printf("%s: vendidas %d, restam %d\n", nome, qtd, v[i].estoque);
    }
}

int main(void) {
    Remedio farmacia[] = {
        {"Dipirona", 40, 10},
        {"Paracetamol", 12, 10},
        {"Ibuprofeno", 5, 8},
    };
    int n = sizeof farmacia / sizeof farmacia[0];

    vender(farmacia, n, "Paracetamol", 3);
    vender(farmacia, n, "Ibuprofeno", 6);
    vender(farmacia, n, "Amoxicilina", 1);
    vender(farmacia, n, "Dipirona", 30);

    printf("Repor:\n");
    for (int i = 0; i < n; i++) {
        if (farmacia[i].estoque < farmacia[i].minimo) { // 10 de 10 ainda não
            printf("  %s (%d de %d)\n", farmacia[i].nome, farmacia[i].estoque,
                   farmacia[i].minimo);
        }
    }
    return 0;
}
// Saída:
// Paracetamol: vendidas 3, restam 9
// Ibuprofeno: só restam 5
// Amoxicilina: não temos
// Dipirona: vendidas 30, restam 10
// Repor:
//   Paracetamol (9 de 10)
//   Ibuprofeno (5 de 8)
```

```bash
gcc ~/LPEDC/material/A121.c -o ~/LPEDC/material/A121 && ~/LPEDC/material/A121
```

**Exemplo A122 · A classificação ordenada**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int vitorias;
    int empates;
} Time;

int pontos(Time t) {
    return 3 * t.vitorias + t.empates;
}

// qsort entrega ponteiros genéricos para dois elementos do vetor
int comparar(const void *a, const void *b) {
    Time x = *(const Time *)a; // copia o time apontado
    Time y = *(const Time *)b;
    if (pontos(x) != pontos(y)) {
        return pontos(y) - pontos(x); // mais pontos primeiro
    }
    return y.vitorias - x.vitorias; // desempate: mais vitórias
}

int main(void) {
    Time tabela[] = {
        {"Bahia", 8, 5},
        {"Flamengo", 9, 6},
        {"Palmeiras", 10, 4},
        {"Fortaleza", 10, 3},
        {"Vasco", 7, 7},
    };
    int n = sizeof tabela / sizeof tabela[0];

    // qsort troca structs inteiras de lugar (28 bytes por vez)
    qsort(tabela, n, sizeof tabela[0], comparar);

    for (int i = 0; i < n; i++) {
        printf("%dº %-10s %2d pts, %2d vitórias\n", i + 1, tabela[i].nome,
               pontos(tabela[i]), tabela[i].vitorias);
    }
    return 0;
}
// Saída:
// 1º Palmeiras  34 pts, 10 vitórias
// 2º Fortaleza  33 pts, 10 vitórias
// 3º Flamengo   33 pts,  9 vitórias
// 4º Bahia      29 pts,  8 vitórias
// 5º Vasco      28 pts,  7 vitórias
```

```bash
gcc ~/LPEDC/material/A122.c -o ~/LPEDC/material/A122 && ~/LPEDC/material/A122
```

#### Exercícios

**Exercício E361** · ★☆☆

Monte a lista de compras abaixo como um vetor de structs (nome,
quantidade, preço unitário). Percorra o vetor mostrando o subtotal de cada
item, o total da compra e o item que mais pesou no bolso.


```text
Arroz 5kg   2 x R$ 27.90
Feijão      3 x R$ 8.49
Café        1 x R$ 18.90
Óleo        4 x R$ 7.99
```



```text
Saída esperada:
Arroz 5kg: R$ 55.80
Feijão: R$ 25.47
Café: R$ 18.90
Óleo: R$ 31.96
Total: R$ 132.13
Mais caro: Arroz 5kg
```

```bash
gcc ~/LPEDC/material/E361.c -o ~/LPEDC/material/E361 && ~/LPEDC/material/E361
```

**Exercício E363** · ★★☆

Leia do teclado 3 atletas: o nome (pode ter espaço) numa linha e, na linha
seguinte, a altura e a idade. Não mostre mensagens antes de ler. Guarde num
vetor de structs e mostre o mais alto e o mais velho.


```text
Entrada:
Rebeca Andrade
1.55 26
Darlan Romani
1.88 34
Rayssa Leal
1.50 17
```



```text
Saída esperada:
Mais alto: Darlan Romani (1.88 m)
Mais velho: Darlan Romani (34 anos)
```

```bash
gcc ~/LPEDC/material/E363.c -o ~/LPEDC/material/E363 && ~/LPEDC/material/E363
```

**Exercício E364** · ★★☆

Uma loja tem estes celulares em estoque:


```text
Moto G     R$ 1299.00
Galaxy A   R$ 1899.00
iPhone     R$ 5499.00
Redmi      R$ 999.00
```


Use qsort (assunto 0050) duas vezes: primeiro em ordem alfabética do nome,
depois do mais caro para o mais barato. Mostre a lista após cada ordenação.


```text
Saída esperada:
Por nome:
  Galaxy A   R$ 1899.00
  Moto G     R$ 1299.00
  Redmi      R$ 999.00
  iPhone     R$ 5499.00
Por preço:
  iPhone     R$ 5499.00
  Galaxy A   R$ 1899.00
  Moto G     R$ 1299.00
  Redmi      R$ 999.00
```

```bash
gcc ~/LPEDC/material/E364.c -o ~/LPEDC/material/E364 && ~/LPEDC/material/E364
```

**Exercício E366** · ★★★

Um terreno irregular tem 5 cantos, em metros, dados em ordem (dando a volta
no terreno):


```text
(0, 0)  (6, 0)  (6, 4)  (3, 7)  (0, 4)
```


Guarde os cantos num vetor de struct Ponto e calcule a área e o perímetro.
Para a área, use a fórmula do cadarço (shoelace): some x[i] * y[j] -
x[j] * y[i] para cada canto i, com j sendo o canto seguinte, e divida o
valor absoluto da soma por 2. O canto seguinte ao último é o primeiro.


```text
Saída esperada:
Área: 33.00 m2
Perímetro: 22.49 m
```

```bash
gcc ~/LPEDC/material/E366.c -o ~/LPEDC/material/E366 -lm && ~/LPEDC/material/E366
```

---

## 0062 · Ponteiro para struct

Você passa o cartão do ônibus na catraca e o validador desconta R$ 4,40. Ele
mexe no saldo do cartão **de verdade**, não de uma cópia. Se descontasse numa
cópia, você andaria de graça para sempre.

Com struct em função vale o mesmo. Como todo parâmetro em C, a struct vai
**por valor**: a função recebe uma cópia de todos os bytes, e mudar a cópia
não muda o original. Para a função alterar a struct de quem chamou, passe o
**endereço** dela: um `Cartao *`.

Com um ponteiro `c` para struct, o campo se acessa assim: `(*c).saldo`.
Primeiro `*c` chega à struct, depois `.saldo` ao campo. Os parênteses são
obrigatórios: o ponto tem prioridade maior que o `*`, e `*c.saldo` seria
`*(c.saldo)`, mas `c` é ponteiro e não tem campo.

O atalho é a **seta** `->`: `c->saldo` é igual a `(*c).saldo`. Variável struct
usa ponto (`cartao.saldo`); ponteiro para struct usa seta (`c->saldo`).

O ponteiro também leva a struct para o **heap**. `malloc(sizeof *c)` reserva
um `Cartao` inteiro e devolve o endereço; `sizeof *c` mede o tipo apontado e
acompanha mudanças. Como todo `malloc`, confira o `NULL` e termine com `free`.

O cartão da Luana mora no heap com R$ 10,00. A variável `c` no `main` guarda
só o endereço dele, e `cobrar_passagem` recebe uma cópia desse **endereço**,
não do cartão. As duas setas apontam para o mesmo lugar:

<p align="center"><img src="material/0062-ideia.svg" alt="Diagrama da ideia: Ponteiro para struct" width="858"></p>

São três passagens seguidas, e a terceira não passa:

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TARIFA 4.40

typedef struct {
    char titular[30];
    double saldo;
    int viagens;
} Cartao;

// recebe o ENDEREÇO do cartão: mexe no original, não numa cópia
bool cobrar_passagem(Cartao *c) {
    if (c->saldo < TARIFA) { // c->saldo é o mesmo que (*c).saldo
        return false;
    }
    c->saldo -= TARIFA;
    c->viagens++;
    return true;
}

int main(void) {
    Cartao *c = malloc(sizeof *c); // um Cartao inteiro no heap
    if (c == NULL) {
        return 1;
    }
    strcpy(c->titular, "Luana");
    c->saldo = 10.00;
    c->viagens = 0;

    for (int i = 1; i <= 3; i++) {
        if (cobrar_passagem(c)) {
            printf("Viagem %d: liberada, saldo R$ %.2f\n", i, c->saldo);
        } else {
            printf("Viagem %d: saldo insuficiente (R$ %.2f)\n", i, c->saldo);
        }
    }
    printf("%s fez %d viagens\n", c->titular, c->viagens);

    free(c);
    return 0;
}
// Saída:
// Viagem 1: liberada, saldo R$ 5.60
// Viagem 2: liberada, saldo R$ 1.20
// Viagem 3: saldo insuficiente (R$ 1.20)
// Luana fez 2 viagens
```

### Passo a passo

O teste de mesa das três chamadas, olhando o cartão no heap:

| Chamada | saldo antes | saldo < 4.40? | saldo depois | viagens |
| --- | --- | --- | --- | --- |
| 1ª | 10.00 | não | 5.60 | 1 |
| 2ª | 5.60 | não | 1.20 | 2 |
| 3ª | 1.20 | sim: devolve false | 1.20 | 2 |

A pergunta do saldo fica na função, mas o laço das três chamadas é do `main`.
Como a função mexe no original, cada volta enxerga o saldo da anterior:

<p align="center"><img src="material/0062-fluxograma.svg" alt="Fluxograma: Ponteiro para struct" width="820"></p>

> [!WARNING]
> Struct vai por valor. `void recarregar(Cartao c, double v) { c.saldo += v; }`
> compila, roda e não faz nada: recarrega uma cópia. Passe `Cartao *c`. Outros
> erros: `*c.saldo` não compila (use `c->saldo`) e `return &cartao;` de uma
> struct local devolve endereço que morre no `return` (use `malloc` ou devolva
> a struct por valor).

> [!TIP]
> Passar por valor copia a struct **a cada chamada**. Um `Cartao` tem 48 bytes,
> tanto faz; uma struct com `double leituras[1000]` copia 8016 bytes (A124),
> contra 8 do ponteiro. Struct grande anda por ponteiro, e `const Cartao *c`
> deixa claro que a função só lê e faz o compilador barrar alterações.

> [!NOTE]
> **Pergunta para você:** se `cobrar_passagem` recebesse `Cartao c` (sem o
> `*`) e o `main` passasse `*c`, o que a saída mostraria nas três viagens? E
> quantas viagens a Luana teria feito no fim?

### Hora de praticar

**Exemplo A123 · As comandas do bar**

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mesa;
    double total;
    int itens;
} Comanda;

// cria um vetor de comandas no heap e devolve o endereço (NULL se falhar)
Comanda *abrir_comandas(int n) {
    Comanda *v = malloc(n * sizeof *v);
    if (v == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        v[i] = (Comanda){i + 1, 0.0, 0}; // mesas 1, 2, 3...
    }
    return v;
}

void lancar(Comanda *c, double preco) {
    c->total += preco;
    c->itens++;
}

// devolve um ponteiro para a comanda mais cara: sem copiar nenhuma
const Comanda *mais_cara(const Comanda *v, int n) {
    const Comanda *m = &v[0];
    for (int i = 1; i < n; i++) {
        if (v[i].total > m->total) {
            m = &v[i];
        }
    }
    return m;
}

int main(void) {
    int n = 3;
    Comanda *bar = abrir_comandas(n);
    if (bar == NULL) {
        return 1;
    }

    lancar(&bar[0], 12.00); // chope na mesa 1
    lancar(&bar[2], 35.90); // porção na mesa 3
    lancar(&bar[0], 12.00);
    lancar(bar + 1, 8.50);  // bar + 1 é o mesmo que &bar[1]

    // o ponteiro anda de comanda em comanda: p++ pula sizeof(Comanda) bytes
    for (Comanda *p = bar; p < bar + n; p++) {
        printf("Mesa %d: %d itens, R$ %.2f\n", p->mesa, p->itens, p->total);
    }

    const Comanda *top = mais_cara(bar, n);
    printf("Maior conta: mesa %d\n", top->mesa);

    free(bar); // depois disso, top também fica solto: não use mais
    return 0;
}
// Saída:
// Mesa 1: 2 itens, R$ 24.00
// Mesa 2: 1 itens, R$ 8.50
// Mesa 3: 1 itens, R$ 35.90
// Maior conta: mesa 3
```

```bash
gcc ~/LPEDC/material/A123.c -o ~/LPEDC/material/A123 && ~/LPEDC/material/A123
```

**Exemplo A124 · O preço da cópia**

```c
#include <stdio.h>

typedef struct {
    char placa[8];
    double leituras[1000]; // velocidades registradas pelo radar
    int n;
} Radar;

// por valor: a função recebe uma CÓPIA dos 8016 bytes
void zerar_copia(Radar r) {
    r.n = 0; // zera a cópia; o original não muda
    printf("  dentro de zerar_copia: sizeof r = %zu\n", sizeof r);
}

// por ponteiro: a função recebe só um endereço (8 bytes)
void zerar(Radar *r) {
    r->n = 0;
    printf("  dentro de zerar: sizeof r = %zu\n", sizeof r);
}

// const: só lê; o compilador barra qualquer tentativa de alterar
double maior(const Radar *r) {
    double m = r->leituras[0];
    for (int i = 1; i < r->n; i++) {
        if (r->leituras[i] > m) {
            m = r->leituras[i];
        }
    }
    return m;
}

int main(void) {
    Radar r = {"ABC1D23", {62.5, 71.0, 58.3}, 3}; // o resto das leituras vira 0

    printf("Maior velocidade: %.1f km/h\n", maior(&r));
    zerar_copia(r);
    printf("Depois de zerar_copia: n = %d\n", r.n);
    zerar(&r);
    printf("Depois de zerar: n = %d\n", r.n);
    return 0;
}
// Saída:
// Maior velocidade: 71.0 km/h
//   dentro de zerar_copia: sizeof r = 8016
// Depois de zerar_copia: n = 3
//   dentro de zerar: sizeof r = 8
// Depois de zerar: n = 0
```

```bash
gcc ~/LPEDC/material/A124.c -o ~/LPEDC/material/A124 && ~/LPEDC/material/A124
```

#### Exercícios

**Exercício E367** · ★☆☆

A empresa deu 8% de reajuste. Crie o tipo Funcionario (nome e salário) e
escreva duas funções:


```text
- void reajustar(Funcionario *f, double pct): aumenta o salário do
  funcionário original;
- void mostrar(const Funcionario *f): só mostra (por isso o const).
```


Aplique o reajuste em Ana (R$ 3200.00) e Beto (R$ 4100.00).


```text
Saída esperada:
Ana: R$ 3200.00
Beto: R$ 4100.00
Depois do reajuste:
Ana: R$ 3456.00
Beto: R$ 4428.00
```

```bash
gcc ~/LPEDC/material/E367.c -o ~/LPEDC/material/E367 && ~/LPEDC/material/E367
```

**Exercício E369** · ★★☆

Crie o tipo Conta (titular e saldo) e três funções:


```text
- Conta *conta_criar(const char *titular, double saldo): aloca com malloc,
  preenche e devolve (NULL se faltar memória);
- bool transferir(Conta *de, Conta *para, double valor): só transfere se
  houver saldo, e devolve se deu certo;
- void conta_destruir(Conta *c): libera.
```


Crie Ana com R$ 500.00 e Beto com R$ 120.00. Transfira R$ 200.00 de Ana
para Beto e depois R$ 400.00 de Beto para Ana.


```text
Saída esperada:
Ana -> Beto, R$ 200.00: ok
Beto -> Ana, R$ 400.00: saldo insuficiente
Ana: R$ 300.00 | Beto: R$ 320.00
```

```bash
gcc ~/LPEDC/material/E369.c -o ~/LPEDC/material/E369 && ~/LPEDC/material/E369
```

**Exercício E370** · ★★☆

Escreva Produto *criar_produto(const char *nome, double preco), que aloca
com malloc um Produto (struct com nome de até 29 letras e preco double),
preenche e devolve o ponteiro (NULL se faltar memória). No main, crie o fone
abaixo, mostre e libere com free.


```text
Saída esperada:
Fone Bluetooth: R$ 149.90
```

```bash
gcc ~/LPEDC/material/E370.c -o ~/LPEDC/material/E370 && ~/LPEDC/material/E370
```

**Exercício E371** · ★★★

Leia produtos (nome sem espaço e preço) até a entrada acabar, guardando
num vetor de structs no heap que começa com capacidade 2 e dobra com
realloc quando enche. Mostre cada vez que a capacidade crescer e, no fim, a
lista e o total.


```text
Entrada:
Arroz 27.90
Feijao 8.49
Cafe 18.90
Oleo 7.99
Acucar 4.59
```



```text
Saída esperada:
capacidade: 2 -> 4
capacidade: 4 -> 8
5 produtos:
  Arroz      R$ 27.90
  Feijao     R$ 8.49
  Cafe       R$ 18.90
  Oleo       R$ 7.99
  Acucar     R$ 4.59
Total: R$ 67.87
```

```bash
gcc ~/LPEDC/material/E371.c -o ~/LPEDC/material/E371 && ~/LPEDC/material/E371
```

---

## 0063 · Enum

O app de delivery mostra o pedido em quatro etapas, sempre nesta ordem:
recebido, em preparo, saiu para entrega, entregue. Como guardar isso?

Números (0, 1, 2...) são ruins: em um mês ninguém lembra o que significa
`if (status == 2)`. Strings pedem `strcmp` toda hora, são lentas e um erro de
digitação passa batido. A terceira saída é o **enum** (enumeração).

Um enum é uma lista de **constantes inteiras com nome**:

```c
typedef enum { RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE } Status;
```

O primeiro nome vale 0 e cada um vale o anterior mais 1: `RECEBIDO` é 0,
`ENTREGUE` é 3. Você pode escolher valores (`DEZ = 10, VINTE = 20`); o que vem
depois continua a contagem. Por convenção, os nomes ficam em MAIÚSCULAS, como
no `#define`.

No C, o enum é **só um inteiro com apelido**: o compilador deixa somar,
comparar com `<` e guardar 42 numa variável `Status`.

A variável `s` começa em `RECEBIDO` e anda uma etapa por vez, com `s++`. Cada
valor tem um nome no código e um número na memória:

<p align="center"><img src="material/0063-ideia.svg" alt="Diagrama da ideia: Enum" width="870"></p>

O código percorre as etapas e traduz cada uma para texto com um `switch`:

```c
#include <stdio.h>

typedef enum {
    RECEBIDO,   // 0
    PREPARANDO, // 1
    A_CAMINHO,  // 2
    ENTREGUE    // 3
} Status;

const char *nome_status(Status s) {
    switch (s) {
    case RECEBIDO:
        return "recebido pelo restaurante";
    case PREPARANDO:
        return "em preparo";
    case A_CAMINHO:
        return "saiu para entrega";
    case ENTREGUE:
        return "entregue";
    }
    return "desconhecido"; // só chega aqui com um valor inválido
}

int main(void) {
    Status s = RECEBIDO;

    while (s != ENTREGUE) {
        printf("[%d] Pedido %s\n", s, nome_status(s));
        s++; // enum é um inteiro: avança para o próximo status
    }
    printf("[%d] Pedido %s. Bom apetite!\n", s, nome_status(s));
    return 0;
}
// Saída:
// [0] Pedido recebido pelo restaurante
// [1] Pedido em preparo
// [2] Pedido saiu para entrega
// [3] Pedido entregue. Bom apetite!
```

Enum combina com `switch`: cada `case` usa um nome. Um truque é pôr um último
nome que só conta os outros: `{ RECEBIDO, PREPARANDO, A_CAMINHO, ENTREGUE,
QTD_STATUS }`. `QTD_STATUS` vale 4 e serve de tamanho para um vetor de textos
(`const char *nomes[QTD_STATUS]`), que cresce sozinho com novos status.

O laço é comum, controlado por uma pergunta sobre o enum, e o `s++` faz o
pedido andar:

<p align="center"><img src="material/0063-fluxograma.svg" alt="Fluxograma: Enum" width="503"></p>

> [!WARNING]
> O C **não confere** se o valor de um enum é válido. `Status s = 42;` compila,
> e `s++` depois de `ENTREGUE` dá 4. Por isso `nome_status` tem
> `return "desconhecido"` depois do `switch`. Os nomes de um enum também são
> globais: dois enums com `ENTREGUE` não compilam. Daí o prefixo:
> `STATUS_ENTREGUE`, `PAG_PIX`.

> [!TIP]
> O enum some na compilação: `A_CAMINHO` vira o número 2 e a variável ocupa o
> mesmo que um `int` (4 bytes, A126). Ao contrário do `#define`, o compilador
> o conhece: sem o `case ENTREGUE:`, o `-Wall` avisa `enumeration value
> 'ENTREGUE' not handled in switch`, desde que o `switch` não tenha `default`.

> [!NOTE]
> **Pergunta para você:** em `enum { BRONZE = 1, PRATA, OURO = 5, DIAMANTE }`, quanto vale
> cada nível? E se o laço do exemplo usasse `s <= ENTREGUE` em vez de
> `s != ENTREGUE`, sem o `printf` depois do laço, a saída mudaria?

### Hora de praticar

**Exemplo A125 · As formas de pagamento**

```c
#include <stdio.h>

// prefixo PAG_ evita choque de nomes; QTD_PAG conta quantas formas existem
typedef enum { PAG_PIX, PAG_DEBITO, PAG_CREDITO, PAG_DINHEIRO, QTD_PAG } Pagamento;

typedef struct {
    double valor;
    Pagamento forma; // um enum dentro de uma struct
} Venda;

int main(void) {
    // vetores do tamanho do enum, indexados pelo próprio enum
    const char *nomes[QTD_PAG] = {"Pix", "débito", "crédito", "dinheiro"};
    const double taxa[QTD_PAG] = {0.0, 1.5, 3.2, 0.0}; // % que a maquininha cobra

    Venda vendas[] = {
        {50.00, PAG_PIX},
        {120.00, PAG_CREDITO},
        {35.00, PAG_DEBITO},
        {80.00, PAG_PIX},
        {20.00, 7}, // compila! o C não confere se 7 é uma forma válida
    };
    int n = sizeof vendas / sizeof vendas[0];

    int contagem[QTD_PAG] = {0};
    double taxas = 0;
    for (int i = 0; i < n; i++) {
        Pagamento f = vendas[i].forma;
        if (f < 0 || f >= QTD_PAG) { // quem confere é você
            printf("venda %d: forma inválida (%d)\n", i, f);
            continue;
        }
        contagem[f]++;
        taxas += vendas[i].valor * taxa[f] / 100;
    }

    for (Pagamento f = PAG_PIX; f < QTD_PAG; f++) {
        printf("%s: %d venda(s)\n", nomes[f], contagem[f]);
    }
    printf("Taxas pagas: R$ %.2f\n", taxas);
    return 0;
}
// Saída:
// venda 4: forma inválida (7)
// Pix: 2 venda(s)
// débito: 1 venda(s)
// crédito: 1 venda(s)
// dinheiro: 0 venda(s)
// Taxas pagas: R$ 4.37
```

```bash
gcc ~/LPEDC/material/A125.c -o ~/LPEDC/material/A125 && ~/LPEDC/material/A125
```

**Exemplo A126 · O troco em notas**

```c
#include <stdio.h>

// cada nome vale o que está escrito na nota: os valores não precisam ser seguidos
typedef enum {
    DOIS = 2,
    CINCO = 5,
    DEZ = 10,
    VINTE = 20,
    CINQUENTA = 50,
    CEM = 100,
} Nota;

int main(void) {
    const Nota notas[] = {CEM, CINQUENTA, VINTE, DEZ, CINCO, DOIS};
    int n = sizeof notas / sizeof notas[0];
    int troco = 137;

    printf("Troco de R$ %d:\n", troco);
    for (int i = 0; i < n; i++) {
        int qtd = troco / notas[i];
        if (qtd > 0) {
            printf("  %d nota(s) de R$ %d\n", qtd, notas[i]);
            troco %= notas[i];
        }
    }
    if (troco > 0) {
        printf("  sobrou R$ %d sem nota\n", troco);
    }
    printf("sizeof(Nota) = %zu bytes\n", sizeof(Nota));
    return 0;
}
// Saída:
// Troco de R$ 137:
//   1 nota(s) de R$ 100
//   1 nota(s) de R$ 20
//   1 nota(s) de R$ 10
//   1 nota(s) de R$ 5
//   1 nota(s) de R$ 2
// sizeof(Nota) = 4 bytes
```

```bash
gcc ~/LPEDC/material/A126.c -o ~/LPEDC/material/A126 && ~/LPEDC/material/A126
```

#### Exercícios

**Exercício E373** · ★☆☆

Declare o enum abaixo, com alguns valores escolhidos e outros não:


```text
enum Tamanho { P = 1, M, G, GG = 10, XG, XXG = GG * 2, ESP };
```


Guarde os sete tamanhos num vetor e os nomes deles num vetor de textos, e
mostre um por linha, num laço. Depois guarde G + XG numa variável
enum Tamanho e mostre: o C deixa, mesmo que somar tamanhos não faça
sentido.


```text
Saída esperada:
P = 1
M = 2
G = 3
GG = 10
XG = 11
XXG = 20
ESP = 21
G + XG = 14
```

```bash
gcc ~/LPEDC/material/E373.c -o ~/LPEDC/material/E373 && ~/LPEDC/material/E373
```

**Exercício E375** · ★★☆

Jokenpô! Crie os enums Jogada { PEDRA, PAPEL, TESOURA } e
Resultado { EMPATE, VITORIA, DERROTA }. Escreva
Resultado jogar(Jogada voce, Jogada outro) e rode as 5 partidas abaixo,
mostrando o placar no fim.


```text
voce     x outro
pedra    x tesoura
papel    x tesoura
tesoura  x tesoura
papel    x pedra
pedra    x papel
```



```text
Saída esperada:
pedra x tesoura: vitória
papel x tesoura: derrota
tesoura x tesoura: empate
papel x pedra: vitória
pedra x papel: derrota
Placar: 2 vitórias, 1 empate, 2 derrotas
```

```bash
gcc ~/LPEDC/material/E375.c -o ~/LPEDC/material/E375 && ~/LPEDC/material/E375
```

**Exercício E376** · ★★☆

Crie o enum Naipe { OUROS, ESPADAS, COPAS, PAUS } e a função
const char *nome_naipe(Naipe n), com um switch que tem um case para cada
naipe e nenhum default (assim o gcc avisa se um naipe for esquecido). O
"???" é devolvido depois do switch, só para valores inválidos. No main, um
laço mostra o 7 de cada naipe.


```text
Saída esperada:
7 de ouros
7 de espadas
7 de copas
7 de paus
```

```bash
gcc ~/LPEDC/material/E376.c -o ~/LPEDC/material/E376 && ~/LPEDC/material/E376
```

**Exercício E377** · ★★★

A catraca do metrô é uma máquina de estados. Ela está TRAVADA ou LIBERADA,
e recebe dois eventos: BILHETE e EMPURRAO. As regras:


```text
TRAVADA  + BILHETE  -> LIBERADA
TRAVADA  + EMPURRAO -> TRAVADA   (alguém tentou passar sem pagar)
LIBERADA + EMPURRAO -> TRAVADA   (uma pessoa passou)
LIBERADA + BILHETE  -> LIBERADA  (bilhete desperdiçado)
```


Use dois enums (Estado e Evento) e uma função
Estado transicao(Estado e, Evento ev). Começando TRAVADA, processe a
sequência BILHETE, EMPURRAO, EMPURRAO, BILHETE, BILHETE, EMPURRAO, EMPURRAO
e conte quantos passaram, quantas tentativas foram barradas e quantos
bilhetes foram desperdiçados.


```text
Saída esperada:
travada + bilhete -> liberada
liberada + empurrão -> travada
travada + empurrão -> travada
travada + bilhete -> liberada
liberada + bilhete -> liberada
liberada + empurrão -> travada
travada + empurrão -> travada
Passaram: 2 | Barrados: 2 | Bilhetes desperdiçados: 1
```

```bash
gcc ~/LPEDC/material/E377.c -o ~/LPEDC/material/E377 && ~/LPEDC/material/E377
```

---

## 0064 · Union

No coworking, a mesma mesa serve a uma designer de manhã e a um programador à
tarde. O espaço é um só, e o que estava em cima some (ou fica bagunçado).

A **union** (união) é isso na memória. Declara-se como a struct, com uma
diferença: na struct, cada campo tem seu pedaço, um depois do outro; na union,
**todos os campos começam no mesmo endereço** e dividem os mesmos bytes. O
tamanho é o do maior campo (arredondado ao alinhamento), e só um campo "vale"
por vez.

```c
typedef union {
    uint32_t numero;        // 4 bytes
    unsigned char bytes[4]; // os MESMOS 4 bytes
} Endereco;
```

A union tem dois usos. O primeiro é **economizar espaço** quando o dado é uma
coisa **ou** outra: um pagamento é Pix **ou** cartão **ou** boleto. O segundo
é **olhar os mesmos bytes de dois jeitos**: escrever um número de 4 bytes e
lê-lo byte a byte, sem conta.

O exemplo mostra o segundo. O IP 192.168.0.10 é, por baixo, um número de 32
bits: `0xC0A8000A` (C0 = 192, A8 = 168, 00 = 0, 0A = 10). O programa grava em
`ip.numero` e lê por `ip.bytes`. Observe a ordem dos bytes na memória:

<p align="center"><img src="material/0064-ideia.svg" alt="Diagrama da ideia: Union" width="882"></p>

Os bytes saem **ao contrário** do que você escreveu:

```c
#include <stdint.h>
#include <stdio.h>

// os dois campos começam no MESMO endereço: são dois jeitos de ler 4 bytes
typedef union {
    uint32_t numero;
    unsigned char bytes[4];
} Endereco;

int main(void) {
    Endereco ip;
    ip.numero = 0xC0A8000A; // 192.168.0.10, escrito como um número só

    printf("sizeof: %zu bytes\n", sizeof ip);
    printf("numero: 0x%08X\n", (unsigned)ip.numero);
    printf("bytes na memória:");
    for (int i = 0; i < 4; i++) {
        printf(" %02X", ip.bytes[i]); // lê os mesmos 4 bytes, um por um
    }
    printf("\n");

    if (ip.bytes[0] == 0x0A) {
        printf("little-endian: o byte menos significativo vem primeiro\n");
    } else {
        printf("big-endian: o byte mais significativo vem primeiro\n");
    }

    ip.bytes[3] = 10; // muda um byte: o número inteiro muda junto
    printf("depois de bytes[3] = 10: 0x%08X\n", (unsigned)ip.numero);
    return 0;
}
// Saída (num PC Intel/AMD ou ARM):
// sizeof: 4 bytes
// numero: 0xC0A8000A
// bytes na memória: 0A 00 A8 C0
// little-endian: o byte menos significativo vem primeiro
// depois de bytes[3] = 10: 0x0AA8000A
```

Essa ordem é a **endianness**. No **little-endian** (Intel, AMD e quase todo
ARM de celular), o byte **menos** significativo fica no endereço menor: o `0A`
do final vem primeiro. No **big-endian**, a ordem é a de leitura humana:
`C0 A8 00 0A`. Nenhum é "certo": é escolha de quem projetou o processador, e a
union deixa você vê-la.

A pergunta sobre o primeiro byte detecta a endianness. Numa máquina
big-endian, o mesmo programa seguiria pelo outro lado:

<p align="center"><img src="material/0064-fluxograma.svg" alt="Fluxograma: Union" width="426"></p>

> [!WARNING]
> Numa union, escrever num campo **estraga** os outros. Gravar `ip.numero` e
> ler `ip.bytes` é a intenção. Mas numa union para economizar espaço, ler um
> campo diferente do último gravado dá lixo, e o C não avisa. Por isso a union
> costuma vir com um **enum** que diz qual campo vale (a union "etiquetada" do
> A128); quem confere a etiqueta é você. E ler os bytes depende da
> endianness: a saída muda entre máquinas.

> [!TIP]
> A union não gera código: `ip.numero` e `ip.bytes[0]` são o mesmo endereço, e
> muda só o tipo de leitura. Em C, ler outro campo reinterpreta os bytes (é
> como se inspeciona um `float` bit a bit). Na rede a ordem é big-endian;
> `htonl` e `ntohl`, de `<arpa/inet.h>`, convertem os números.

> [!NOTE]
> **Pergunta para você:** se a union tivesse um terceiro campo,
> `uint16_t metades[2]`, quanto valeria `ip.metades[0]` logo depois de
> `ip.numero = 0xC0A8000A`? E `sizeof ip` mudaria?

### Hora de praticar

**Exemplo A127 · A balança da feira**

```c
#include <stdio.h>

// um produto da feira é vendido por unidade OU por quilo, nunca pelos dois
typedef union {
    int unidades;
    double quilos;
} Quantidade;

// a mesma informação numa struct: os dois campos ocupam espaço sempre
typedef struct {
    int unidades;
    double quilos;
} QuantidadeStruct;

int main(void) {
    Quantidade q;

    q.unidades = 12; // uma dúzia de ovos
    printf("unidades: %d\n", q.unidades);

    q.quilos = 2.5;  // agora 2,5 kg de tomate: os mesmos bytes, reescritos
    printf("quilos: %.1f\n", q.quilos);
    // 2.5 em double é 0x4004000000000000; num PC little-endian, os 4 bytes
    // que o int lê são os de baixo, todos zero
    printf("unidades agora: %d (lixo: a dúzia sumiu)\n", q.unidades);

    printf("union: %zu bytes, struct: %zu bytes\n", sizeof(Quantidade),
           sizeof(QuantidadeStruct));
    printf("1000 produtos: %zu contra %zu bytes\n", 1000 * sizeof(Quantidade),
           1000 * sizeof(QuantidadeStruct));
    printf("mesmo endereço? %s\n", (void *)&q.unidades == (void *)&q.quilos ? "sim" : "não");
    return 0;
}
// Saída (num PC Intel/AMD ou ARM):
// unidades: 12
// quilos: 2.5
// unidades agora: 0 (lixo: a dúzia sumiu)
// union: 8 bytes, struct: 16 bytes
// 1000 produtos: 8000 contra 16000 bytes
// mesmo endereço? sim
```

```bash
gcc ~/LPEDC/material/A127.c -o ~/LPEDC/material/A127 && ~/LPEDC/material/A127
```

**Exemplo A128 · Um pagamento, três formas**

```c
#include <stdio.h>

typedef enum { PIX, CARTAO, BOLETO } TipoPagamento;

// union "etiquetada": o enum diz qual campo da union vale agora
typedef struct {
    TipoPagamento tipo;
    double valor;
    union {
        char chave[40];        // PIX
        struct {               // CARTAO
            char final[5];
            int parcelas;
        } cartao;
        char codigo[48];       // BOLETO
    } dados;
} Pagamento;

void mostrar(const Pagamento *p) {
    printf("R$ %7.2f via ", p->valor);
    switch (p->tipo) {
    case PIX:
        printf("Pix para %s\n", p->dados.chave);
        break;
    case CARTAO:
        printf("cartão final %s em %dx\n", p->dados.cartao.final, p->dados.cartao.parcelas);
        break;
    case BOLETO:
        printf("boleto %.10s...\n", p->dados.codigo);
        break;
    }
}

int main(void) {
    Pagamento lista[] = {
        {PIX, 89.90, .dados.chave = "loja@exemplo.com"},
        {CARTAO, 1250.00, .dados.cartao = {"4321", 10}},
        {BOLETO, 342.17, .dados.codigo = "23790123456789012345678901234567890123456789"},
    };

    for (int i = 0; i < 3; i++) {
        mostrar(&lista[i]);
    }
    printf("sizeof(Pagamento) = %zu (a union ocupa só o maior campo: 48)\n", sizeof(Pagamento));
    return 0;
}
// Saída:
// R$   89.90 via Pix para loja@exemplo.com
// R$ 1250.00 via cartão final 4321 em 10x
// R$  342.17 via boleto 2379012345...
// sizeof(Pagamento) = 64 (a union ocupa só o maior campo: 48)
```

```bash
gcc ~/LPEDC/material/A128.c -o ~/LPEDC/material/A128 && ~/LPEDC/material/A128
```

#### Exercícios

**Exercício E379** · ★☆☆

Escreva um programa que declare os três tipos abaixo e mostre o sizeof de
cada um. Para a union Caixa e a struct Ficha, mostre também onde cada campo
começa (offsetof): é a diferença entre as duas, em números.


```text
union Caixa  { char c; int i; double d; };
struct Ficha { char c; int i; double d; };
union Nome   { char texto[10]; int codigo; };
```



```text
Saída esperada (num PC de 64 bits):
union Caixa: 8 bytes, campos em 0, 0 e 0
struct Ficha: 16 bytes, campos em 0, 4 e 8
union Nome: 12 bytes
```

```bash
gcc ~/LPEDC/material/E379.c -o ~/LPEDC/material/E379 && ~/LPEDC/material/E379
```

**Exercício E381** · ★★☆

Um arquivo vindo de uma máquina big-endian guardou números de 16 bits com
os dois bytes na ordem oposta à do seu PC. Escreva
uint16_t trocar_bytes(uint16_t x) usando uma union de um uint16_t com um
unsigned char[2] (sem operadores de bits), e teste com três valores.


```text
Saída esperada:
0xABCD -> 0xCDAB
0x0102 -> 0x0201
258 -> 513
```

```bash
gcc ~/LPEDC/material/E381.c -o ~/LPEDC/material/E381 && ~/LPEDC/material/E381
```

**Exercício E382** · ★★☆

Um app de reforma calcula a área de peças de formatos diferentes. Crie uma
union etiquetada:


```text
typedef enum { CIRCULO, RETANGULO, TRIANGULO } TipoForma;
typedef struct {
    TipoForma tipo;
    union {
        double raio;
        struct { double largura, altura; } ret;
        struct { double base, altura; } tri;
    } medida;
} Forma;
```


Escreva double area(const Forma *f) com um switch no tipo e some as
áreas de: um círculo de raio 2, um retângulo 3 x 4 e um triângulo de base 6
e altura 5.


```text
Saída esperada:
círculo: 12.57 m2
retângulo: 12.00 m2
triângulo: 15.00 m2
Total: 39.57 m2
```

```bash
gcc ~/LPEDC/material/E382.c -o ~/LPEDC/material/E382 && ~/LPEDC/material/E382
```

**Exercício E384** · ★★★

Na rede, a convenção é mandar os números em big-endian (a "ordem de
rede"). Use a union abaixo para escrever:


```text
typedef union {
    uint32_t n;
    uint16_t m[2];
    unsigned char b[4];
} Visao;
```



```text
- void mostrar_memoria(Visao x): mostra os 4 bytes na ordem da memória;
- int little_endian(void): devolve 1 se a máquina é little-endian;
- uint32_t ordem_de_rede(uint32_t x): devolve o número com os bytes
  arrumados para que, na memória, apareçam do mais significativo para o
  menos. Numa máquina big-endian, devolve x sem mexer.
```


Teste com x.n = 0x11223344: mostre a memória, m[0] e m[1], a endianness e
a memória do número convertido.


```text
Saída esperada (num PC Intel/AMD ou ARM):
memória: 44 33 22 11
m[0] = 0x3344, m[1] = 0x1122
esta máquina é little-endian
em ordem de rede, memória: 11 22 33 44
```

```bash
gcc ~/LPEDC/material/E384.c -o ~/LPEDC/material/E384 && ~/LPEDC/material/E384
```

---

## 0065 · Bits, máscaras e flags

`ls -l` mostra `-rwxr-xr-x` ao lado de cada arquivo, e `chmod 755` muda isso.
Por que 755? Cada permissão é **um bit**, e o C mexe em bits um por um.

### Binário em cinco minutos

Um **bit** é 0 ou 1; oito bits formam um **byte**. Um inteiro na memória é uma
fileira de bits em **base 2**: cada casa vale o dobro da casa à direita.

| casa | 2⁷ | 2⁶ | 2⁵ | 2⁴ | 2³ | 2² | 2¹ | 2⁰ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| vale | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |

Para ler um binário, some as casas com 1: `0110` = 4 + 2 = 6. Para escrever um
decimal em binário, tire a maior casa que cabe e repita: 13 = 8 + 4 + 1 =
`1101`. Os bits se numeram da direita para a esquerda, a partir do **bit 0**
(o que vale 1).

Binário é comprido, e há atalhos. Na **base 16** (hexadecimal), cada dígito (0
a 9 e A a F, de 10 a 15) vale **exatamente 4 bits**: `1110 1101` = `0xED` =
237. Na **base 8** (octal), cada dígito vale **3 bits**, por isso aparece nas
permissões (3 bits por grupo). No C, `0x` começa um hexadecimal e um **zero à
esquerda** começa um octal: `0755` é octal e vale 493, não 755.

### Os operadores bit a bit

Eles agem casa por casa em inteiros. Com `a = 0110` (6) e `b = 0011` (3):

| Operador | Nome | Regra para cada bit | `a op b` |
| --- | --- | --- | --- |
| `a & b` | E | 1 se os dois são 1 | `0010` (2) |
| `a \| b` | OU | 1 se algum é 1 | `0111` (7) |
| `a ^ b` | OU exclusivo | 1 se são diferentes | `0101` (5) |
| `~a` | NÃO | inverte cada bit | `...1001` |
| `a << 1` | desloca à esquerda | empurra, entra 0 à direita | `1100` (12) |
| `a >> 1` | desloca à direita | empurra, sai o bit 0 | `0011` (3) |

Deslocar 1 casa à esquerda multiplica por 2; à direita, divide por 2 (divisão
inteira). `1u << n` é o número com só o bit `n` ligado.

### Máscaras e flags

Uma **flag** é um bit que diz sim ou não. Várias cabem num inteiro, cada uma
no seu bit: `LER` = 4 (`100`), `ESCREVER` = 2 (`010`), `EXECUTAR` = 1 (`001`).
Um valor que escolhe certos bits é uma **máscara**. Quatro receitas bastam:

- **ligar** um bit: `p |= ESCREVER;`
- **desligar**: `p &= ~ESCREVER;` (o `~` faz uma máscara com todos os bits
  ligados menos aquele)
- **testar**: `if (p & ESCREVER)` (sobra 0 se o bit estava desligado)
- **inverter**: `p ^= ESCREVER;`

Um arquivo começa com `rw-` (110). Para ligar a execução, o OU com a máscara
`001` acende só o último bit:

<p align="center"><img src="material/0065-ideia.svg" alt="Diagrama da ideia: Bits, máscaras e flags" width="858"></p>

O programa aplica as quatro receitas e mostra os bits a cada passo:

```c
#include <stdio.h>

// cada permissão é um bit: 4 = 100, 2 = 010, 1 = 001
#define LER      4u // r
#define ESCREVER 2u // w
#define EXECUTAR 1u // x

void mostrar(const char *passo, unsigned p) {
    printf("%-12s %u%u%u = %u  %c%c%c\n", passo,
           (p >> 2) & 1u, (p >> 1) & 1u, p & 1u, p, // os 3 bits, um por um
           (p & LER) ? 'r' : '-',
           (p & ESCREVER) ? 'w' : '-',
           (p & EXECUTAR) ? 'x' : '-');
}

int main(void) {
    unsigned perm = LER | ESCREVER; // liga dois bits de uma vez: 110
    mostrar("inicial", perm);

    perm |= EXECUTAR;               // OU liga um bit
    mostrar("liga x", perm);

    perm &= ~ESCREVER;              // E com o inverso desliga um bit
    mostrar("desliga w", perm);

    if (perm & ESCREVER) {          // E isola um bit para testar
        printf("pode escrever\n");
    } else {
        printf("não pode escrever\n");
    }

    perm ^= EXECUTAR;               // OU exclusivo inverte um bit
    mostrar("inverte x", perm);
    return 0;
}
// Saída:
// inicial      110 = 6  rw-
// liga x       111 = 7  rwx
// desliga w    101 = 5  r-x
// não pode escrever
// inverte x    100 = 4  r--
```

`(p >> 2) & 1u` lê o bit 2: empurra-o para a casa 0 e apaga o resto com a
máscara `1`. O `chmod 755` completo, no A130, é a mesma ideia com três grupos
de 3 bits: dono `111`, grupo `101`, outros `101`.

A pergunta "pode escrever?" é um `&` com a máscara. Se sobrou algum bit, a
resposta é Sim:

<p align="center"><img src="material/0065-fluxograma.svg" alt="Fluxograma: Bits, máscaras e flags" width="488"></p>

> [!WARNING]
> Três armadilhas. (1) **Precedência**: `&`, `^` e `|` ficam **abaixo** do
> `==`. `if (p & ESCREVER == 0)` vira `p & (ESCREVER == 0)`, ou seja, `p & 0`,
> sempre falso. Use `if ((p & ESCREVER) == 0)`. (2) `&` não é `&&`:
> `p && ESCREVER` só pergunta se os dois são diferentes de zero e quase sempre
> dá verdadeiro. (3) Use **unsigned**: deslocar número negativo, ou por mais
> casas que o tipo tem (`1u << 32` em 32 bits), é comportamento indefinido.

> [!TIP]
> Cada operador bit a bit vira uma instrução do processador, por isso flags
> estão em toda parte (`open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644)`).
> 32 flags cabem num `unsigned` de 4 bytes; 32 `bool` ocupariam 32. Os campos
> de bits da struct (`unsigned ler : 1;`) têm ordem dependente do compilador:
> para formatos de arquivo e protocolos, prefira máscaras explícitas.

> [!NOTE]
> **Pergunta para você:** partindo de `perm = 0`, qual a sequência mais
> curta de operações para chegar em `r-x`? E quanto vale `perm` se você fizer
> `perm ^= LER` duas vezes seguidas?

### Hora de praticar

**Exemplo A129 · Os ingredientes da pizza**

```c
#include <stdio.h>

// cada ingrediente é um bit: 1u << n liga só o bit n
#define QUEIJO    (1u << 0)
#define TOMATE    (1u << 1)
#define CEBOLA    (1u << 2)
#define CALABRESA (1u << 3)
#define AZEITONA  (1u << 4)

void mostrar(const char *nome, unsigned p) {
    const char *ingredientes[] = {"queijo", "tomate", "cebola", "calabresa", "azeitona"};
    printf("%-12s", nome);
    for (int b = 0; b < 5; b++) {
        if (p & (1u << b)) {
            printf(" %s", ingredientes[b]);
        }
    }
    printf("\n");
}

int main(void) {
    unsigned calabresa = QUEIJO | CALABRESA | CEBOLA | AZEITONA;
    unsigned marguerita = QUEIJO | TOMATE;
    mostrar("calabresa", calabresa);
    mostrar("marguerita", marguerita);

    unsigned meu = calabresa & ~(CEBOLA | AZEITONA); // tira dois de uma vez
    mostrar("a minha", meu);

    mostrar("em comum", calabresa & marguerita);   // E: o que as duas têm
    mostrar("meio a meio", calabresa | marguerita); // OU: tudo junto

    unsigned alergia = CEBOLA | TOMATE;
    // "tem ALGUM" e "tem TODOS" são testes diferentes
    printf("marguerita tem algum de cebola/tomate? %s\n",
           (marguerita & alergia) != 0 ? "sim" : "não");
    printf("marguerita tem todos? %s\n",
           (marguerita & alergia) == alergia ? "sim" : "não");
    return 0;
}
// Saída:
// calabresa    queijo cebola calabresa azeitona
// marguerita   queijo tomate
// a minha      queijo calabresa
// em comum     queijo
// meio a meio  queijo tomate cebola calabresa azeitona
// marguerita tem algum de cebola/tomate? sim
// marguerita tem todos? não
```

```bash
gcc ~/LPEDC/material/A129.c -o ~/LPEDC/material/A129 && ~/LPEDC/material/A129
```

**Exemplo A130 · O chmod 755**

```c
#include <stdio.h>

// três grupos de 3 bits: dono (bits 8-6), grupo (5-3) e outros (2-0)
#define DONO   6
#define GRUPO  3
#define OUTROS 0

unsigned montar(unsigned dono, unsigned grupo, unsigned outros) {
    return (dono << DONO) | (grupo << GRUPO) | (outros << OUTROS);
}

void mostrar(unsigned modo) {
    const char letras[] = "rwx";
    printf("octal %03o, hexa 0x%03X, decimal %u\n", modo, modo, modo);
    printf("bits  ");
    for (int b = 8; b >= 0; b--) {
        printf("%u", (modo >> b) & 1u);
    }
    printf("\nls    ");
    for (int b = 8; b >= 0; b--) {
        // bit 8 é r, 7 é w, 6 é x, e o padrão se repete a cada 3
        printf("%c", ((modo >> b) & 1u) ? letras[(8 - b) % 3] : '-');
    }
    printf("\n");
}

int main(void) {
    unsigned modo = montar(7, 5, 5); // rwx r-x r-x
    mostrar(modo);

    unsigned outros = (modo >> OUTROS) & 7u; // máscara 111 pega 3 bits
    printf("outros podem escrever? %s\n", (outros & 2u) ? "sim" : "não");
    printf("é igual ao literal octal 0755? %s\n", modo == 0755 ? "sim" : "não");
    return 0;
}
// Saída:
// octal 755, hexa 0x1ED, decimal 493
// bits  111101101
// ls    rwxr-xr-x
// outros podem escrever? não
// é igual ao literal octal 0755? sim
```

```bash
gcc ~/LPEDC/material/A130.c -o ~/LPEDC/material/A130 && ~/LPEDC/material/A130
```

#### Exercícios

**Exercício E385** · ★☆☆

Escreva a função void mostrar(const char *nome, unsigned char r), que
mostra o nome, os 8 bits de r (com um espaço no meio), o valor em hexa e
em decimal. Com a = 0xCA e b = 0x5C (dois unsigned char), use a função
para mostrar a, b e os seis resultados abaixo, guardando cada um num
unsigned char:


```text
a & b    a | b    a ^ b    ~a    a << 1    a >> 3
```



```text
Saída esperada:
a       1100 1010 = 0xCA = 202
b       0101 1100 = 0x5C = 92
a & b   0100 1000 = 0x48 = 72
a | b   1101 1110 = 0xDE = 222
a ^ b   1001 0110 = 0x96 = 150
~a      0011 0101 = 0x35 = 53
a << 1  1001 0100 = 0x94 = 148
a >> 3  0001 1001 = 0x19 = 25
```

```bash
gcc ~/LPEDC/material/E385.c -o ~/LPEDC/material/E385 && ~/LPEDC/material/E385
```

**Exercício E387** · ★★☆

Escreva duas funções para um uint16_t (16 bits):


```text
- void mostrar_bits(uint16_t x): mostra os 16 bits, do 15 ao 0, com um
  espaço a cada 4;
- int contar_uns(uint16_t x): conta quantos bits estão ligados.
```


Use as duas em 2025, 255 e 4096 e diga a paridade (par ou ímpar) da
quantidade de bits 1. Esse "bit de paridade" é um jeito antigo e barato de
detectar um bit corrompido numa transmissão.


```text
Saída esperada:
2025: 0000 0111 1110 1001 -> 8 bits 1 (par)
255: 0000 0000 1111 1111 -> 8 bits 1 (par)
4096: 0001 0000 0000 0000 -> 1 bits 1 (ímpar)
```

```bash
gcc ~/LPEDC/material/E387.c -o ~/LPEDC/material/E387 && ~/LPEDC/material/E387
```

**Exercício E388** · ★★☆

As notificações do app ficam em flags: EMAIL (1), SMS (2) e PUSH (4).
Escreva void mostrar(unsigned f), que mostra numa linha se cada uma está
ligada ou desligada. Comece com email e push ligados, mostre, desligue o
push (só ele, sem mexer nos outros bits) e mostre de novo.


```text
Saída esperada:
email: ligado | sms: desligado | push: ligado
email: ligado | sms: desligado | push: desligado
```

```bash
gcc ~/LPEDC/material/E388.c -o ~/LPEDC/material/E388 && ~/LPEDC/material/E388
```

**Exercício E389** · ★★★

No CSS, uma cor como #FF8800 são três bytes juntos: vermelho (FF), verde
(88) e azul (00). Guarde cores num uint32_t (os 8 bits de cima ficam
zerados) e escreva:


```text
- uint32_t rgb(unsigned r, unsigned g, unsigned b): empacota;
- unsigned canal_r(uint32_t c), canal_g e canal_b: desempacotam;
- uint32_t escurecer(uint32_t c): divide cada canal por 2;
- uint32_t cinza(uint32_t c): os três canais viram a média deles.
```



```text
Saída esperada:
rgb(255, 136, 0) = #FF8800
#3366CC -> r = 51, g = 102, b = 204
#FF8800 escurecida = #7F4400
#3366CC em cinza = #777777
```

```bash
gcc ~/LPEDC/material/E389.c -o ~/LPEDC/material/E389 && ~/LPEDC/material/E389
```

---

## 0066 · Juntando tudo: o cardápio

A lanchonete quer um cardápio no app. Cada item tem nome, preço, categoria
(lanche, bebida ou sobremesa) e marcações: vegano, sem glúten, picante. O
cliente quer filtrar "só o que é vegano **e** sem glúten", e o dono quer
cadastrar itens sem mexer no código.

Cada peça do módulo resolve uma parte. A struct `Item` junta os dados e o
typedef encurta os tipos. O enum `Categoria` nomeia as categorias, e o
`QTD_CATEGORIAS` dimensiona o vetor de nomes. As marcações são flags num
`unsigned tags`, e o filtro é uma máscara. Os itens moram num vetor de structs
no heap, que cresce com `realloc`. As funções recebem ponteiros: `Cardapio *c`
para mexer no cardápio e `const Item *it` para só ler um item sem copiá-lo.

O `Cardapio` é uma struct que administra um vetor: guarda o ponteiro para os
itens, quantos existem (`n`) e quantos cabem (`cap`). Quando enche, dobra a
capacidade: de 0 vai a 2, 4 e 8, e com 6 itens sobram 2 vagas. Esse trio
(ponteiro, tamanho, capacidade) é a semente do **vetor dinâmico** que o
módulo 11 transforma em tipo abstrato de dados.

O filtro cabe numa linha. O item passa se tem **todas** as tags da máscara:
`(tags & mascara) == mascara`. O `&` apaga as tags fora da máscara; se sobra a
própria máscara, nenhuma faltou. Com máscara 0, todo item passa, e o mesmo
`filtrar` lista o cardápio inteiro.

O suco de caju tem as tags `011` (vegano e sem glúten). Contra a máscara
`011`, o `&` devolve `011`: passa. O burger de grão-de-bico tem `001`: o `&`
devolve `001`, falta o sem glúten, e ele fica de fora:

<p align="center"><img src="material/0066-ideia.svg" alt="Diagrama da ideia: Juntando tudo: o cardápio" width="957"></p>

```c
#include <stdio.h>
#include <stdlib.h>

typedef enum { LANCHE, BEBIDA, SOBREMESA, QTD_CATEGORIAS } Categoria;

// flags: cada característica é um bit
#define VEGANO     (1u << 0)
#define SEM_GLUTEN (1u << 1)
#define PICANTE    (1u << 2)

typedef struct {
    char nome[32];
    Categoria categoria;
    double preco;
    unsigned tags;
} Item;

typedef struct {
    Item *itens; // vetor no heap
    int n;       // quantos itens tem
    int cap;     // quantos cabem
} Cardapio;

int cardapio_adicionar(Cardapio *c, Item it) {
    if (c->n == c->cap) {
        int nova = c->cap == 0 ? 2 : 2 * c->cap;
        Item *novo = realloc(c->itens, nova * sizeof *novo);
        if (novo == NULL) {
            return 0;
        }
        c->itens = novo;
        c->cap = nova;
    }
    c->itens[c->n++] = it; // copia a struct inteira para dentro do vetor
    return 1;
}

void mostrar_item(const Item *it) {
    const char *categorias[QTD_CATEGORIAS] = {"lanche", "bebida", "sobremesa"};
    printf("  R$ %5.2f  %s (%s)%s%s%s\n", it->preco, it->nome, categorias[it->categoria],
           (it->tags & VEGANO) ? " [V]" : "",
           (it->tags & SEM_GLUTEN) ? " [SG]" : "",
           (it->tags & PICANTE) ? " [P]" : "");
}

// mostra os itens que têm TODAS as tags da máscara
void filtrar(const Cardapio *c, unsigned mascara) {
    for (int i = 0; i < c->n; i++) {
        if ((c->itens[i].tags & mascara) == mascara) {
            mostrar_item(&c->itens[i]);
        }
    }
}

int main(void) {
    Cardapio c = {NULL, 0, 0};
    Item itens[] = {
        {"X-Burger", LANCHE, 28.90, 0},
        {"Burger de grão-de-bico", LANCHE, 32.00, VEGANO},
        {"Tapioca de frango", LANCHE, 18.50, SEM_GLUTEN},
        {"Asinha apimentada", LANCHE, 24.00, PICANTE | SEM_GLUTEN},
        {"Suco de caju", BEBIDA, 9.00, VEGANO | SEM_GLUTEN},
        {"Pudim", SOBREMESA, 12.00, SEM_GLUTEN},
    };
    int n = sizeof itens / sizeof itens[0];

    for (int i = 0; i < n; i++) {
        if (!cardapio_adicionar(&c, itens[i])) {
            free(c.itens);
            return 1;
        }
    }

    printf("Cardápio (%d itens, capacidade %d):\n", c.n, c.cap);
    filtrar(&c, 0); // máscara vazia: todo item passa
    printf("Veganos e sem glúten:\n");
    filtrar(&c, VEGANO | SEM_GLUTEN);

    free(c.itens);
    return 0;
}
// Saída:
// Cardápio (6 itens, capacidade 8):
//   R$ 28.90  X-Burger (lanche)
//   R$ 32.00  Burger de grão-de-bico (lanche) [V]
//   R$ 18.50  Tapioca de frango (lanche) [SG]
//   R$ 24.00  Asinha apimentada (lanche) [SG] [P]
//   R$  9.00  Suco de caju (bebida) [V] [SG]
//   R$ 12.00  Pudim (sobremesa) [SG]
// Veganos e sem glúten:
//   R$  9.00  Suco de caju (bebida) [V] [SG]
```

O fluxograma é o do `filtrar`: um laço sobre o vetor e uma pergunta de bits
por item, para qualquer máscara:

<p align="center"><img src="material/0066-fluxograma.svg" alt="Fluxograma: Juntando tudo: o cardápio" width="504"></p>

> [!WARNING]
> `c->itens[c->n++] = it` copia o item para **dentro** do vetor: mexer depois
> em `it` (ou no vetor `itens` do `main`) não muda o cardápio. O inverso
> também engana: `Item *p = &c.itens[0]` fica **solto** após o próximo
> `realloc`, porque o vetor pode ter mudado de endereço. Em vetor que cresce,
> guarde índices, não ponteiros.

> [!TIP]
> Um `Item` ocupa 56 bytes: 32 do nome, 4 da categoria, 4 de preenchimento
> para alinhar o `double`, 8 do preço, 4 das tags e 4 de preenchimento no fim,
> para o próximo item também começar alinhado. Confira com
> `printf("%zu\n", sizeof(Item))`.

> [!NOTE]
> **Pergunta para você:** que máscara lista os itens que são sem glúten **e**
> picantes? E como você escreveria um filtro "tem **alguma** destas tags", em
> vez de "tem todas"?

### Hora de praticar

**Exemplo A131 · Os alunos da academia**

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { MENSAL, TRIMESTRAL, ANUAL, QTD_PLANOS } Plano;

// modalidades: cada uma é um bit
#define MUSCULACAO (1u << 0)
#define NATACAO    (1u << 1)
#define YOGA       (1u << 2)

typedef struct {
    char nome[16];
    Plano plano;
    unsigned modalidades;
} Aluno;

typedef struct {
    Aluno *v;
    int n, cap;
} Academia;

bool matricular(Academia *a, const char *nome, Plano plano, unsigned mods) {
    if (a->n == a->cap) {
        int nova = a->cap == 0 ? 2 : 2 * a->cap;
        Aluno *novo = realloc(a->v, nova * sizeof *novo);
        if (novo == NULL) {
            return false;
        }
        a->v = novo;
        a->cap = nova;
    }
    Aluno *al = &a->v[a->n]; // ponteiro usado logo, antes de outro realloc
    strcpy(al->nome, nome);
    al->plano = plano;
    al->modalidades = mods;
    a->n++;
    return true;
}

// devolve o índice (e não um ponteiro: o vetor pode mudar de lugar)
int procurar(const Academia *a, const char *nome) {
    for (int i = 0; i < a->n; i++) {
        if (strcmp(a->v[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// "alguma" das modalidades da máscara, não "todas"
void listar_alguma(const Academia *a, unsigned mascara) {
    for (int i = 0; i < a->n; i++) {
        if ((a->v[i].modalidades & mascara) != 0) {
            printf("  %s\n", a->v[i].nome);
        }
    }
}

int main(void) {
    const char *planos[QTD_PLANOS] = {"mensal", "trimestral", "anual"};
    Academia a = {NULL, 0, 0};

    bool ok = matricular(&a, "Bruna", ANUAL, MUSCULACAO | YOGA) &&
              matricular(&a, "Davi", MENSAL, NATACAO) &&
              matricular(&a, "Elis", MENSAL, MUSCULACAO) &&
              matricular(&a, "Fabio", TRIMESTRAL, MUSCULACAO | NATACAO | YOGA) &&
              matricular(&a, "Gil", ANUAL, 0);
    if (!ok) {
        free(a.v);
        return 1;
    }

    int i = procurar(&a, "Davi");
    if (i != -1) {
        a.v[i].modalidades |= YOGA; // Davi entrou na yoga
        a.v[i].plano = ANUAL;       // e trocou de plano
    }

    int por_plano[QTD_PLANOS] = {0};
    for (int k = 0; k < a.n; k++) {
        por_plano[a.v[k].plano]++;
    }
    for (Plano p = MENSAL; p < QTD_PLANOS; p++) {
        printf("%s: %d aluno(s)\n", planos[p], por_plano[p]);
    }

    printf("Fazem natação ou yoga:\n");
    listar_alguma(&a, NATACAO | YOGA);
    printf("%d alunos, capacidade %d\n", a.n, a.cap);

    free(a.v);
    return 0;
}
// Saída:
// mensal: 1 aluno(s)
// trimestral: 1 aluno(s)
// anual: 3 aluno(s)
// Fazem natação ou yoga:
//   Bruna
//   Davi
//   Fabio
// 5 alunos, capacidade 8
```

```bash
gcc ~/LPEDC/material/A131.c -o ~/LPEDC/material/A131 && ~/LPEDC/material/A131
```

**Exemplo A132 · A comanda e o pagamento**

```c
#include <stdio.h>

typedef struct {
    char nome[24];
    double preco;
} Item;

typedef struct {
    const Item *item; // aponta para o cardápio: não copia o item
    int qtd;
} Linha;

typedef enum { PIX, CARTAO, DINHEIRO } FormaPagamento;

typedef struct {
    FormaPagamento forma;
    union {
        char chave[40];   // PIX
        int parcelas;     // CARTAO
        double entregue;  // DINHEIRO: quanto o cliente deu
    } dados;
} Pagamento;

double total_comanda(const Linha linhas[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += linhas[i].item->preco * linhas[i].qtd; // ponteiro dentro de struct
    }
    return total;
}

void pagar(const Pagamento *p, double total) {
    switch (p->forma) {
    case PIX:
        printf("Pix de R$ %.2f para %s\n", total, p->dados.chave);
        break;
    case CARTAO:
        printf("Cartão: %dx de R$ %.2f\n", p->dados.parcelas, total / p->dados.parcelas);
        break;
    case DINHEIRO:
        printf("Dinheiro: recebeu R$ %.2f, troco R$ %.2f\n", p->dados.entregue,
               p->dados.entregue - total);
        break;
    }
}

int main(void) {
    const Item cardapio[] = {{"X-Burger", 28.90}, {"Suco de caju", 9.00}, {"Pudim", 12.00}};

    Linha mesa7[] = {{&cardapio[0], 2}, {&cardapio[1], 2}, {&cardapio[2], 1}};
    int n = sizeof mesa7 / sizeof mesa7[0];

    double total = total_comanda(mesa7, n);
    for (int i = 0; i < n; i++) {
        printf("%d x %s\n", mesa7[i].qtd, mesa7[i].item->nome);
    }
    printf("Total: R$ %.2f\n", total);

    Pagamento formas[] = {
        {PIX, .dados.chave = "lanchonete@exemplo.com"},
        {CARTAO, .dados.parcelas = 3},
        {DINHEIRO, .dados.entregue = 100.00},
    };
    for (int i = 0; i < 3; i++) {
        pagar(&formas[i], total);
    }
    return 0;
}
// Saída:
// 2 x X-Burger
// 2 x Suco de caju
// 1 x Pudim
// Total: R$ 87.80
// Pix de R$ 87.80 para lanchonete@exemplo.com
// Cartão: 3x de R$ 29.27
// Dinheiro: recebeu R$ 100.00, troco R$ 12.20
```

```bash
gcc ~/LPEDC/material/A132.c -o ~/LPEDC/material/A132 && ~/LPEDC/material/A132
```

#### Exercícios

**Exercício E391** · ★☆☆

O mercado imprime etiquetas para a prateleira. Crie:


```text
- um enum Setor { HORTIFRUTI, LATICINIOS, PADARIA };
- flags PROMO (bit 0), ORGANICO (bit 1) e REFRIGERADO (bit 2);
- um typedef struct Produto com nome, setor, preço e flags;
- void etiqueta(const Produto *p), que mostra uma linha por produto.
```


Use os três produtos abaixo.


```text
Saída esperada:
Banana prata (hortifrúti) R$ 6.99/kg [orgânico]
Iogurte natural (laticínios) R$ 4.50/kg [promo] [refrigerado]
Pão francês (padaria) R$ 16.90/kg
```

```bash
gcc ~/LPEDC/material/E391.c -o ~/LPEDC/material/E391 && ~/LPEDC/material/E391
```

**Exercício E393** · ★★☆

Monte um estoque que cresce: typedef struct { Produto *v; int n, cap; }
Estoque; com as funções


```text
- bool estoque_adicionar(Estoque *e, const char *nome, int qtd);
- bool estoque_remover(Estoque *e, const char *nome): acha pelo nome e
  puxa os seguintes uma posição para trás (a ordem se mantém);
- void estoque_listar(const Estoque *e) e void estoque_liberar(Estoque *e).
```


Adicione Arroz (12), Feijão (30), Café (8), Açúcar (15) e Leite (24).
Remova "Feijão" e depois "Macarrão" (que não existe).


```text
Saída esperada:
remover Feijão: ok
remover Macarrão: não encontrado
4 produtos (capacidade 8):
  Arroz: 12
  Café: 8
  Açúcar: 15
  Leite: 24
```

```bash
gcc ~/LPEDC/material/E393.c -o ~/LPEDC/material/E393 && ~/LPEDC/material/E393
```

**Exercício E394** · ★★☆

Crie o tipo Item (nome até 19 letras, preco e tags) com as flags DESTAQUE
(bit 0) e VEGANO (bit 1). Aloque com malloc um vetor de 3 itens: X-Burger
28.90 sem tags, Suco de caju 9.00 (DESTAQUE e VEGANO) e Pudim 12.00
(DESTAQUE). Escreva void listar(const Item *itens, int n), que mostra nome,
preço e " [destaque]" se a tag estiver ligada. Liste, tire o destaque só do
suco, liste de novo e libere o vetor.


```text
Saída esperada:
X-Burger R$ 28.90
Suco de caju R$ 9.00 [destaque]
Pudim R$ 12.00 [destaque]
-- tira o destaque do suco --
X-Burger R$ 28.90
Suco de caju R$ 9.00
Pudim R$ 12.00 [destaque]
```

```bash
gcc ~/LPEDC/material/E394.c -o ~/LPEDC/material/E394 && ~/LPEDC/material/E394
```

**Exercício E395** · ★★★

Uma agenda de tarefas. Cada Tarefa tem título, Prioridade (enum BAIXA,
MEDIA, ALTA), prazo (dia do mês) e tags em bits: TRABALHO, CASA, URGENTE.
Aloque o vetor com malloc, preencha com as 6 tarefas abaixo, ordene com
qsort (prioridade mais alta primeiro; empate: prazo menor primeiro) e
mostre a lista inteira e depois só as tarefas de TRABALHO.


```text
título            prioridade  prazo  tags
Pagar aluguel     ALTA        5      CASA | URGENTE
Revisar PR        MEDIA       3      TRABALHO
Comprar ração     BAIXA       8      CASA
Deploy da API     ALTA        2      TRABALHO | URGENTE
Reunião 1:1       MEDIA       3      TRABALHO
Lavar o carro     BAIXA       12     CASA
```



```text
Saída esperada:
[alta] dia 2: Deploy da API
[alta] dia 5: Pagar aluguel
[média] dia 3: Reunião 1:1
[média] dia 3: Revisar PR
[baixa] dia 8: Comprar ração
[baixa] dia 12: Lavar o carro
Trabalho:
[alta] dia 2: Deploy da API
[média] dia 3: Reunião 1:1
[média] dia 3: Revisar PR
```

```bash
gcc ~/LPEDC/material/E395.c -o ~/LPEDC/material/E395 && ~/LPEDC/material/E395
```

---

## Desafios do módulo

Resolva num arquivo seu, misturando os assuntos do módulo, do médio ao
difícil.

**1. Agenda com busca.** Monte uma agenda com 5 contatos (nome, telefone,
aniversário como struct `Data`). Leia um nome com `fgets` e mostre o contato,
ou "não encontrado". Depois mostre quem faz aniversário no mês 10.

<details><summary>Resposta</summary>

Um vetor de `Contato`, cada um com um campo `Data` aninhado
(`agenda[i].aniversario.mes`). A busca é um laço com
`strcmp(agenda[i].nome, nome) == 0`; tire o `'\n'` do `fgets` antes de
comparar, senão nada bate. Devolva o **índice** encontrado (ou -1), não uma
cópia.

</details>

**2. Desempate do campeonato.** Ordene uma tabela de times por pontos; no
empate, por saldo de gols; no empate, por gols marcados; e, por fim, pelo nome.

<details><summary>Resposta</summary>

Uma comparadora para o `qsort` com uma cascata de `if`: compare pontos; se
diferentes, devolva a diferença invertida (maior primeiro); senão passe para o
saldo, depois gols, e termine com `strcmp` nos nomes. O último critério garante
uma ordem única, porque o `qsort` não é estável.

</details>

**3. Os retângulos se encostam?** Com `typedef struct { double x, y; } Ponto;`
e um retângulo dado por dois cantos, escreva `bool sobrepoe(Retangulo a,
Retangulo b)`. Teste com (0,0)-(4,3) e (3,2)-(6,5), e com (0,0)-(2,2) e
(3,3)-(5,5).

<details><summary>Resposta</summary>

Dois retângulos **não** se sobrepõem quando um está todo à esquerda, à
direita, acima ou abaixo do outro: `a.sup.x < b.inf.x || b.sup.x < a.inf.x ||
a.sup.y < b.inf.y || b.sup.y < a.inf.y`. Negue isso. O primeiro par se
sobrepõe (no quadrado de (3,2) a (4,3)); o segundo, não.

</details>

**4. A struct gorda.** Escreva um programa que mostre o `sizeof` e o
`offsetof` de cada campo de `struct Sensor { char id; double leitura; char
status; int contador; };`. Crie uma versão com os campos reorganizados para
ocupar o mínimo e mostre quantos bytes ela economiza num vetor de 1 milhão de
sensores.

<details><summary>Resposta</summary>

`id` no byte 0, 7 de sobra, `leitura` no 8, `status` no 16, 3 de sobra,
`contador` no 20: **24 bytes**. Na ordem `double`, `int`, `char`, `char`: 8 + 4
+ 1 + 1 = 14, arredondado para **16**. São 8 bytes por sensor, 8 MB a menos no
vetor. Confira com `sizeof` e `offsetof`.

</details>

**5. Dentro do float.** Com uma union de `float` e `uint32_t`, separe os
campos do `-6.25f`: o bit de sinal (bit 31), o expoente (bits 30 a 23) e a
mantissa (bits 22 a 0).

<details><summary>Resposta</summary>

Os bits são `0xC0C80000`. Sinal: `bits >> 31` = **1** (negativo). Expoente:
`(bits >> 23) & 0xFF` = **129**, que, menos o desvio de 127, dá 2. Mantissa:
`bits & 0x7FFFFF` = `0x480000`, que representa a parte fracionária de
1,5625. E 1,5625 × 2² = 6,25.

</details>

**6. Quantos bits mudaram?** Escreva `int distancia(unsigned a, unsigned b)`
que conta em quantas casas os bits de `a` e `b` diferem (a distância de
Hamming). Quanto dá para 11 e 6?

<details><summary>Resposta</summary>

O `^` liga exatamente as casas diferentes; depois é só contar os bits 1:
`11 ^ 6` = `1011 ^ 0110` = `1101`, **3 bits**. É assim que códigos de correção
de erro medem quantos bits uma transmissão estragou.

</details>

**7. Potência de 2 numa linha.** Escreva `bool potencia_de_2(unsigned n)` só
com `n > 0 && (n & (n - 1)) == 0`. Para 64, 96 e 1, mostre o resultado e os
bits de `n` e de `n - 1`, um embaixo do outro, para ver por que funciona.

<details><summary>Resposta</summary>

Uma potência de 2 tem **um** bit ligado (`64` = `1000000`). Subtrair 1 apaga
esse bit e liga todos à direita (`63` = `0111111`), então o `&` dá zero. Se
houver mais de um bit ligado (`96` = `1100000`, `95` = `1011111`), o bit mais
alto sobrevive ao `&`. 64 e 1 dão verdadeiro; 96, falso.

</details>

**8. A data em 16 bits.** O sistema de arquivos FAT guarda uma data em 16
bits: dia nos bits 0 a 4, mês nos bits 5 a 8 e (ano - 1980) nos bits 9 a 15.
Empacote 18/10/2026 e desempacote de volta.

<details><summary>Resposta</summary>

`(46 << 9) | (10 << 5) | 18` = 23552 + 320 + 18 = **23890** (`0x5D52`). Para
voltar: dia = `d & 0x1F`, mês = `(d >> 5) & 0xF`, ano = `(d >> 9) + 1980`.
Cinco bits para o dia porque 2⁵ = 32 > 31; quatro para o mês, porque 2⁴ = 16 >
12; sete para o ano, o que vai até 1980 + 127 = 2107.

</details>

**9. Um conjunto em 64 bits.** Represente conjuntos de números de 0 a 63 num
`uint64_t` e escreva `inserir`, `contem`, `uniao`, `intersecao` e `tamanho`.
Teste com {1, 3, 5, 7} e {3, 4, 5}.

<details><summary>Resposta</summary>

Inserir `x`: `s |= (uint64_t)1 << x` (o 1 precisa ser de 64 bits, senão o
deslocamento estoura). Contém: `(s >> x) & 1`. União é `|`, interseção é `&`,
tamanho é contar bits. União {1, 3, 4, 5, 7} (5 elementos), interseção {3, 5}
(2 elementos). Cada operação de conjunto custa uma instrução.

</details>

**10. Playlist encadeada.** Sem `malloc`, crie 4 variáveis `Musica` (título,
duração em segundos e `struct Musica *proxima`) ligadas em sequência, com
`NULL` na última. Percorra a partir da primeira, mostrando cada uma e a duração
total em minutos e segundos.

<details><summary>Resposta</summary>

A struct precisa de nome para apontar para si mesma: `typedef struct Musica {
...; struct Musica *proxima; } Musica;`. O laço é `for (const Musica *m =
&primeira; m != NULL; m = m->proxima)`. Total em segundos `t`: `t / 60` minutos
e `t % 60` segundos. Isso já é uma **lista encadeada**; no módulo 11 os nós
passam a vir do `malloc`.

</details>

## Questões do POSCOMP

Questões reais do POSCOMP (SBC) sobre este módulo. O enunciado está no caderno oficial: abra o link, resolva e confira o gabarito.

| Ano | Questão | Assunto | Gabarito | Prova |
| --- | --- | --- | --- | --- |
| 2023 | 45 | Tipo enumeração, constantes nomeadas | C | [caderno](https://www.sbc.org.br/wp-content/uploads/2025/02/0761.001_Exame_POSCOMP_2023.pdf) |
| 2024 | 46 | Estruturas (struct) em linguagens de programação | E | [caderno](https://www2.uesb.br/curso/cienciadacomputacao/wp-content/uploads/2026/05/caderno_2024.pdf) |

O gabarito de 2023 vem de um blog de terceiros que reproduz o gabarito definitivo; confira no PDF oficial da SBC.


## Lista de exercícios práticos

30 exercícios que misturam os assuntos do módulo, no ritmo da prova do PPGI. Arquivos P0801.c a P0830.c, em `material/`; resoluções em `_respostas/08-structs/lista/`.

### ★☆☆ Aquecimento

**Exercício P0801** · ★☆☆ · A distância entre as paradas

No mapa da linha de ônibus, cada parada tem coordenadas (x, y) em km.
Crie typedef struct { double x, y; } Ponto; e escreva:


```text
double distancia(Ponto a, Ponto b);   // sqrt((bx - ax)² + (by - ay)²)
Ponto meio(Ponto a, Ponto b);         // o ponto médio, para o abrigo
```


Para as paradas abaixo, mostre a distância de cada trecho, o total do
percurso e o ponto médio entre a primeira e a última:


```text
Ponto paradas[4] = {{0.0, 0.0}, {3.0, 4.0}, {6.0, 8.0}, {6.0, 11.5}};
```



```text
Saída esperada:
Parada 1 -> 2: 5.00 km
Parada 2 -> 3: 5.00 km
Parada 3 -> 4: 3.50 km
Total: 13.50 km
Abrigo no meio: (3.00, 5.75)
```

**Dicas:**

1. Uma struct pode ser parâmetro e retorno, como um int: a função recebe
   uma cópia e devolve uma struct nova.
2. No meio: return (Ponto) {(a.x + b.x) / 2, (a.y + b.y) / 2}; (literal
   composto) ou declare um Ponto m e preencha os campos.
3. sqrt está no math.h.
4. Resposta esperada: a saída acima (13.50 km no total).

```bash
gcc ~/LPEDC/material/P0801.c -o ~/LPEDC/material/P0801 -lm && ~/LPEDC/material/P0801
```

---

**Exercício P0802** · ★☆☆ · A que horas o voo chega

Crie typedef struct { int h, m; } Horario; e escreva


```text
Horario somar(Horario ini, int minutos, int *dias);
```


que devolve o horário depois de passar minutos, sempre normalizado (m de 0
a 59, h de 0 a 23), e guarda em *dias quantas vezes passou da meia-noite.
Teste os três voos:


```text
Manaus 22:45 + 230 min (3h50)
Belém 06:10 + 95 min
Rio Branco 23:30 + 1500 min (uma viagem com conexões)
```



```text
Saída esperada:
Manaus 22:45 + 230 min = 02:35 (+1 dia)
Belém 06:10 + 95 min = 07:45
Rio Branco 23:30 + 1500 min = 00:30 (+2 dias)
```

**Dicas:**

1. Converta tudo para minutos desde 00:00: total = ini.h * 60 + ini.m +
   minutos.
2. *dias = total / (24 * 60); o resto da divisão por 1440 dá os minutos
   do dia, que viram h e m com / 60 e % 60.
3. Mostre com %02d para sair 02:35 e não 2:35.

```bash
gcc ~/LPEDC/material/P0802.c -o ~/LPEDC/material/P0802 && ~/LPEDC/material/P0802
```

---

**Exercício P0803** · ★☆☆ · O estoque baixo da farmácia

Crie o tipo Remedio (codigo int, nome com até 23 letras, estoque int,
minimo int) e guarde os 6 remédios abaixo num vetor de structs:


```text
101 Dipirona 40 20      102 Amoxicilina 8 15     103 Losartana 22 25
104 Omeprazol 60 30     105 Insulina 3 10        106 Paracetamol 35 20
```


Escreva int buscar(const Remedio *v, int n, int codigo), que devolve o
índice do remédio (ou -1). Mostre os remédios com estoque abaixo do
mínimo e quanto falta comprar, e depois procure os códigos 105 e 110:


```text
Saída esperada:
Comprar:
  Amoxicilina  faltam 7
  Losartana    faltam 3
  Insulina     faltam 7
Código 105: Insulina, estoque 3
Código 110: não cadastrado
```

**Dicas:**

1. Inicialize o vetor direto: Remedio v[6] = {{101, "Dipirona", 40, 20},
   ...}; os campos vão na ordem da struct.
2. Falta comprar = minimo - estoque.

```bash
gcc ~/LPEDC/material/P0803.c -o ~/LPEDC/material/P0803 && ~/LPEDC/material/P0803
```

---

**Exercício P0804** · ★☆☆ · O carro e o tanque

Crie typedef struct { char modelo[16]; double tanque, capacidade,
km_por_litro, odometro; } Carro; e escreva duas funções que recebem um
PONTEIRO para o carro e mexem nele com ->:


```text
double abastecer(Carro *c, double litros);  // devolve quanto entrou
double rodar(Carro *c, double km);          // devolve quanto rodou
```


abastecer não passa da capacidade; rodar gasta km / km_por_litro litros
e, se o combustível acabar antes, roda só o que der. Comece com um Mobi
(tanque 5 L, capacidade 47 L, 13.5 km/L, odômetro 10230) e faça: abastecer
50 L, rodar 300 km, rodar 400 km, abastecer 20 L.


```text
Saída esperada:
Abasteceu 42.00 L
  Mobi: tanque 47.00 L, odômetro 10230.0 km
Rodou 300.0 km
  Mobi: tanque 24.78 L, odômetro 10530.0 km
Rodou 334.5 km
  Mobi: tanque 0.00 L, odômetro 10864.5 km
Abasteceu 20.00 L
  Mobi: tanque 20.00 L, odômetro 10864.5 km
```

**Dicas:**

1. c->tanque é o mesmo que (*c).tanque.
2. Em abastecer: cabe = c->capacidade - c->tanque; entra o menor entre
   litros e cabe.
3. Em rodar: o máximo possível é c->tanque * c->km_por_litro.
4. Escreva void painel(const Carro *c) para mostrar o estado depois de
   cada operação.

```bash
gcc ~/LPEDC/material/P0804.c -o ~/LPEDC/material/P0804 && ~/LPEDC/material/P0804
```

---

**Exercício P0805** · ★☆☆ · Quantos dias tem o mês

Crie typedef enum { JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT,
NOV, DEZ } Mes; e escreva:


```text
bool bissexto(int ano);
int dias_no_mes(Mes m, int ano);
```


Use um switch no dias_no_mes (fevereiro depende do ano). Mostre os dias de
fevereiro em 2024, 2026, 1900 e 2000, e o total de dias de 2026 somando os
12 meses num laço que anda pelo enum:


```text
Saída esperada:
fev/2024: 29 dias
fev/2026: 28 dias
fev/1900: 28 dias
fev/2000: 29 dias
2026: 365 dias
```

**Dicas:**

1. Bissexto: divisível por 4 e não por 100, ou divisível por 400. Por
   isso 1900 não é e 2000 é.
2. No switch, vários case podem levar ao mesmo return: case ABR: case
   JUN: case SET: case NOV: return 30;
3. Um enum é um int: for (Mes m = JAN; m <= DEZ; m++) funciona.
4. Para o nome do mês, um vetor de strings indexado por m - 1.
5. Resposta esperada: a saída acima (2026 tem 365 dias).

```bash
gcc ~/LPEDC/material/P0805.c -o ~/LPEDC/material/P0805 && ~/LPEDC/material/P0805
```

---

**Exercício P0806** · ★☆☆ · As permissões do arquivo

No Linux, as permissões de um arquivo são 9 bits: rwx do dono, rwx do
grupo e rwx dos outros, do bit 8 ao bit 0 (r vale 4, w vale 2 e x vale 1
dentro de cada trio). Por isso chmod 754 é 111 101 100 em binário.
Escreva void mostrar(const char *rotulo, unsigned modo), que mostra o
rótulo, o número em octal (%o) e as letras (com '-' no lugar do bit
desligado), e teste com 0754 e 0644.
Depois, partindo de 0644, ligue o x do dono, desligue o r dos outros e
INVERTA o w do grupo, mostrando o modo depois de cada passo:


```text
Saída esperada:
chmod 754:             754 rwxr-xr--
chmod 644:             644 rw-r--r--
liga x do dono:        744 rwxr--r--
desliga r dos outros:  740 rwxr-----
inverte w do grupo:    760 rwxrw----
```

**Dicas:**

1. Em C, 0754 (com zero na frente) é um número OCTAL: cada dígito é
   exatamente um trio de bits.
2. Para as letras, ande do bit 8 ao 0: (modo >> b) & 1 diz se o bit b
   está ligado. A letra do bit b é "rwx"[(8 - b) % 3].
3. Ligar: modo |= 1u << 6. Desligar: modo &= ~(1u << 2). Inverter:
   modo ^= 1u << 4.

```bash
gcc ~/LPEDC/material/P0806.c -o ~/LPEDC/material/P0806 && ~/LPEDC/material/P0806
```

---

**Exercício P0807** · ★☆☆ · O endereço IP em 32 bits

Um endereço IPv4 como 192.168.10.42 são 4 bytes, e cabe num uint32_t
(do stdint.h), com o primeiro número nos 8 bits de cima. Escreva:


```text
uint32_t montar(int a, int b, int c, int d);
void mostrar(const char *rotulo, uint32_t ip);  // os 4 bytes: >> e & 0xFF
```


A máscara de rede /24 tem os 24 bits de cima ligados: 0xFFFFFF00. A REDE
de um IP é ip & mascara, e o número do computador na rede é ip & ~mascara.
Mostre o IP, em hexa e em pontos, a rede e o computador, para /24 e /16:


```text
Saída esperada:
192.168. 10. 42  0xC0A80A2A  IP
Com /24:
255.255.255.  0  0xFFFFFF00  máscara
192.168. 10.  0  0xC0A80A00  rede
  0.  0.  0. 42  0x0000002A  máquina
Com /16:
255.255.  0.  0  0xFFFF0000  máscara
192.168.  0.  0  0xC0A80000  rede
  0.  0. 10. 42  0x00000A2A  máquina
```

**Dicas:**

1. montar: ((uint32_t) a << 24) | (b << 16) | (c << 8) | d. O cast vem
   antes do << para a conta ser feita em 32 bits sem sinal.
2. mostrar: (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF e
   ip & 0xFF.
3. Máscara /n: os n bits de cima ligados: 0xFFFFFFFFu << (32 - n) (vale
   para n de 1 a 31).
4. Para mostrar um uint32_t em hexa: printf("%08X", (unsigned) ip).

```bash
gcc ~/LPEDC/material/P0807.c -o ~/LPEDC/material/P0807 && ~/LPEDC/material/P0807
```

---

**Exercício P0808** · ★☆☆ · Conserte o cadastro do sócio

O clube quer dar 20% de desconto na mensalidade dos sócios com mais de 10
anos de casa. O programa abaixo tem DOIS erros de propósito: o gcc avisa de
um (leia o warning); o outro é de lógica: o desconto é calculado, mas não
chega no sócio. Conserte os dois. O programa deve mostrar:


```text
Saída esperada:
Seu Lourival  23 anos: R$ 120.00
Kelly          4 anos: R$ 150.00
Dona Ivete    11 anos: R$ 96.00
```

**Dicas:**

1. %d é para int; para double, %.2f. Um formato errado mostra lixo.
2. A função recebe uma CÓPIA da struct: mudar a cópia não muda o sócio do
   main. Passe o endereço (Socio *) e use ->.

```bash
gcc ~/LPEDC/material/P0808.c -o ~/LPEDC/material/P0808 && ~/LPEDC/material/P0808
```

---

**Exercício P0809** · ★☆☆ · O mais velho da família

Crie typedef struct { int dia, mes, ano; } Data; e typedef struct { char
nome[20]; Data nascimento; } Pessoa; (uma struct dentro da outra). Escreva
int compara_data(Data a, Data b), que devolve negativo se a vem antes de
b, 0 se são iguais e positivo se a vem depois. Com a família abaixo,
mostre o mais velho, o mais novo e quem faz aniversário em março:


```text
Pessoa familia[5] = {{"Vó Nazaré", {12, 3, 1941}},
                     {"Tio Edu", {30, 11, 1968}},
                     {"Mãe", {5, 3, 1972}},
                     {"Lucas", {19, 7, 2001}},
                     {"Bia", {2, 1, 2009}}};
```



```text
Saída esperada:
Mais velho: Vó Nazaré (1941)
Mais novo: Bia (2009)
Aniversário em março: Vó Nazaré (dia 12) Mãe (dia 5)
```

**Dicas:**

1. Compare o ano; se for igual, o mês; se for igual, o dia:
   if (a.ano != b.ano) return a.ano - b.ano; ...
2. O mais velho nasceu ANTES: é o de menor data.
3. Para chegar no mês: familia[i].nascimento.mes (dois pontos seguidos).

```bash
gcc ~/LPEDC/material/P0809.c -o ~/LPEDC/material/P0809 && ~/LPEDC/material/P0809
```

---

**Exercício P0810** · ★☆☆ · A configuração com campos nomeados

O som do carro tem uma struct de configuração com vários campos:


```text
typedef struct {
    int volume, graves, agudos, balanco;
    bool loudness;
    char fonte[12];
} Config;
```


Com os inicializadores designados do C99, você escreve só os campos que
importam, em qualquer ordem, e o resto vira zero (false, "" para a
string): Config c = {.fonte = "Bluetooth", .volume = 18};. Monte os três
perfis abaixo assim e mostre cada um com uma função
void mostrar(const char *nome, const Config *c):
- padrao: nada informado (tudo zero);
- estrada: volume 22, graves 3, loudness ligado, fonte "Radio FM";
- show: fonte "Pendrive", agudos 4, graves 5, volume 30, balanco -2.


```text
Saída esperada:
padrao   vol  0, graves 0, agudos 0, balanço  0, loudness não, fonte ""
estrada  vol 22, graves 3, agudos 0, balanço  0, loudness sim, fonte "Radio FM"
show     vol 30, graves 5, agudos 4, balanço -2, loudness não, fonte "Pendrive"
```

**Dicas:**

1. Config padrao = {0}; zera tudo. Nos outros, use .campo = valor.
2. A ordem dos .campo não precisa seguir a da struct.
3. Mostre a string vazia entre aspas para ver que ela está lá: "%s".

```bash
gcc ~/LPEDC/material/P0810.c -o ~/LPEDC/material/P0810 && ~/LPEDC/material/P0810
```

### ★★☆ Para pensar

**Exercício P0811** · ★★☆ · O cardápio em duas ordens

A lanchonete guarda o cardápio num vetor de structs:


```text
typedef struct { char nome[24]; double preco; int calorias; } Item;
```



```text
X-Caboquinho      22.90  780 kcal     Tapioca           12.00  420 kcal
Pastel de carne    9.50  510 kcal     Açaí 500 ml       18.00  640 kcal
Suco de cupuaçu    8.00  190 kcal     Misto quente       9.50  380 kcal
```


(o vetor já está pronto no esqueleto). Ordene com qsort duas vezes: primeiro
em ordem alfabética do nome; depois
pelo preço (do mais barato ao mais caro; no empate, o de menos calorias
primeiro). Mostre as duas listas:


```text
Saída esperada:
Por nome:
  R$ 18.00  640 kcal  Açaí 500 ml
  R$  9.50  380 kcal  Misto quente
  R$  9.50  510 kcal  Pastel de carne
  R$  8.00  190 kcal  Suco de cupuaçu
  R$ 12.00  420 kcal  Tapioca
  R$ 22.90  780 kcal  X-Caboquinho
Por preço:
  R$  8.00  190 kcal  Suco de cupuaçu
  R$  9.50  380 kcal  Misto quente
  R$  9.50  510 kcal  Pastel de carne
  R$ 12.00  420 kcal  Tapioca
  R$ 18.00  640 kcal  Açaí 500 ml
  R$ 22.90  780 kcal  X-Caboquinho
```

**Dicas:**

1. A comparação recebe o endereço de cada Item: const Item *a = pa;
   e compara a->nome, a->preco...
2. Para double, não devolva a->preco - b->preco: a conversão para int
   corta a diferença (0.50 vira 0). Use (a->preco > b->preco) -
   (a->preco < b->preco).
3. qsort(cardapio, 6, sizeof cardapio[0], por_nome); o qsort move a
   struct inteira (36 ou 40 bytes) a cada troca.

```bash
gcc ~/LPEDC/material/P0811.c -o ~/LPEDC/material/P0811 && ~/LPEDC/material/P0811
```

---

**Exercício P0812** · ★★☆ · Ordenar os ponteiros, não as fichas

As fichas dos pacientes são grandes (cada uma tem um histórico de 200
caracteres), e mover uma ficha inteira a cada troca do qsort custa caro.
Crie as fichas no heap e um vetor de PONTEIROS para elas, e ordene os
ponteiros pela idade (do mais velho para o mais novo). As fichas não saem
do lugar:


```text
typedef struct { char nome[20]; int idade; char historico[200]; } Ficha;
```


Escreva Ficha *nova_ficha(const char *nome, int idade, const char *hist),
que aloca e preenche uma ficha (antes do strcpy, confira com strlen se o
texto cabe no campo; se não couber, devolva NULL). Crie as 4 fichas abaixo,
ordene e
mostre; mostre também quantos bytes cada troca move no qsort de ponteiros e
quantos moveria no de fichas. Libere tudo:


```text
Raimundo 58 "hipertensão"    Jéssica 31 "asma"
Benedito 74 "diabetes tipo 2"    Karina 45 "nenhum"
```



```text
Saída esperada:
1. 74 anos: Benedito (diabetes tipo 2)
2. 58 anos: Raimundo (hipertensão)
3. 45 anos: Karina (nenhum)
4. 31 anos: Jéssica (asma)
A ficha do Raimundo continua no mesmo endereço, agora na posição 2
Bytes por troca: 8 (ponteiro) contra 224 (ficha)
```

**Dicas:**

1. Ficha *f = malloc(sizeof *f); e preencha f->nome, f->idade,
   f->historico.
2. O vetor é Ficha *fichas[4]. Cada elemento é um ponteiro: o qsort recebe
   sizeof fichas[0] (8 bytes) e a comparação recebe um Ficha ** disfarçado:
   const Ficha *a = *(Ficha * const *) pa;
3. Para provar que a ficha não se moveu, guarde o endereço de fichas[0]
   (o Raimundo) antes do qsort e, depois, procure em que posição do vetor
   esse mesmo endereço foi parar.
4. Resposta esperada: a saída acima (os bytes por troca: 8 e 224).

```bash
gcc ~/LPEDC/material/P0812.c -o ~/LPEDC/material/P0812 && ~/LPEDC/material/P0812
```

---

**Exercício P0813** · ★★☆ · Pix, cartão ou dinheiro

O caixa da loja aceita três formas de pagamento, e cada uma tem dados
diferentes. Represente com uma union etiquetada:


```text
typedef enum { PIX, CARTAO, DINHEIRO } Forma;
typedef struct {
    Forma forma;   // a etiqueta: diz qual campo da union vale
    double valor;
    union {
        char chave[40];                              // PIX
        struct { char final[5]; int parcelas; } cartao; // CARTAO
        double recebido;                             // DINHEIRO
    } dados;
} Pagamento;
```


Escreva void recibo(const Pagamento *p), que usa um switch na etiqueta e
mostra o que vale para aquela forma (no dinheiro, o troco; no cartão, o
valor de cada parcela). Mostre os recibos dos três pagamentos abaixo e o
sizeof da union e do Pagamento:


```text
Saída esperada:
PIX de R$ 87.50 para loja@exemplo.com.br
Cartão final 4467: R$ 359.70 em 3x de R$ 119.90
Dinheiro: R$ 42.30, recebido R$ 50.00, troco R$ 7.70
sizeof da union: 40 bytes; sizeof do Pagamento: 56 bytes
```

**Dicas:**

1. Inicialize com campos nomeados: {.forma = CARTAO, .valor = 359.70,
   .dados.cartao = {"4467", 3}}.
2. Num Pagamento, só UM campo da union guarda dado de verdade. Ler outro
   (dados.recebido de um PIX) mostra os bytes da chave lidos como double:
   lixo. Por isso a etiqueta.
3. O tamanho da union é o do maior campo (a chave, 40 bytes).

```bash
gcc ~/LPEDC/material/P0813.c -o ~/LPEDC/material/P0813 && ~/LPEDC/material/P0813
```

---

**Exercício P0814** · ★★☆ · A cor em 16 bits

Telas pequenas (como a de uma maquininha de cartão) guardam cada cor em 16
bits no formato RGB565: 5 bits de vermelho (bits 15 a 11), 6 de verde (10 a
5) e 5 de azul (4 a 0). Partindo de uma cor de 8 bits por canal (0 a 255),
escreva:


```text
uint16_t para_565(int r, int g, int b);   // guarda os bits mais altos
void de_565(uint16_t c, int *r, int *g, int *b);  // volta para 0..255
```


Para converter, jogue fora os bits de baixo: r >> 3 (fica com 5 bits),
g >> 2 (6 bits), b >> 3. Para voltar, desloque para a esquerda e repita os
bits de cima nos de baixo: r8 = (r5 << 3) | (r5 >> 2) (e g8 = (g6 << 2) |
(g6 >> 4)). Converta as cores abaixo, mostrando o valor em hexa e a cor
recuperada (algumas perdem um pouco de precisão):


```text
laranja (255, 136, 0), verde-bandeira (0, 156, 59), branco (255, 255, 255)
```



```text
Saída esperada:
laranja        (255, 136,   0) -> 0xFC40 -> (255, 138,   0)
verde-bandeira (  0, 156,  59) -> 0x04E7 -> (  0, 158,  57)
branco         (255, 255, 255) -> 0xFFFF -> (255, 255, 255)
```

**Dicas:**

1. Montar: (uint16_t) (((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3)).
2. Separar: r5 = (c >> 11) & 0x1F; g6 = (c >> 5) & 0x3F; b5 = c & 0x1F.
3. 0x1F são 5 bits ligados (31) e 0x3F são 6 (63).

```bash
gcc ~/LPEDC/material/P0814.c -o ~/LPEDC/material/P0814 && ~/LPEDC/material/P0814
```

---

**Exercício P0815** · ★★☆ · O estoque por categoria

Uma loja de material de construção tem produtos de quatro categorias:


```text
typedef enum { HIDRAULICA, ELETRICA, PINTURA, FERRAGEM,
               N_CATEGORIAS } Categoria;
```


O último nome do enum (N_CATEGORIAS) vale 4 e serve de tamanho para vetores
indexados pela categoria. Com os produtos abaixo (nome, categoria,
quantidade, preço), calcule, num vetor de N_CATEGORIAS posições, quantos
itens e quanto dinheiro há em estoque em cada categoria, e mostre a
categoria com mais dinheiro parado:


```text
Tubo PVC 25mm      HIDRAULICA  40  12.90
Fio 2,5mm (rolo)   ELETRICA    15  189.00
Tinta 18L          PINTURA      8  329.90
Registro 3/4       HIDRAULICA  22  45.50
Disjuntor 20A      ELETRICA    30  28.00
Parafuso (cento)   FERRAGEM    60  9.80
Rolo de lã         PINTURA     25  24.90
```



```text
Saída esperada:
 62 itens  R$  1517.00  Hidráulica
 45 itens  R$  3675.00  Elétrica
 33 itens  R$  3261.70  Pintura
 60 itens  R$   588.00  Ferragem
Mais dinheiro parado: Elétrica
```

**Dicas:**

1. typedef struct { char nome[20]; Categoria cat; int qtd; double preco; }
   Produto;
2. int itens[N_CATEGORIAS] = {0}; double valor[N_CATEGORIAS] = {0}; e,
   para cada produto, itens[p.cat] += p.qtd.
3. Os nomes vêm de um vetor de strings na mesma ordem do enum:
   const char *nome_cat[N_CATEGORIAS] = {"Hidráulica", ...};

```bash
gcc ~/LPEDC/material/P0815.c -o ~/LPEDC/material/P0815 && ~/LPEDC/material/P0815
```

---

**Exercício P0816** · ★★☆ · Batalha naval

O tabuleiro de batalha naval é uma matriz 5x5 de structs:


```text
typedef struct { bool navio; bool atingida; } Casa;
```


Os navios ocupam as casas marcadas com '#' no mapa abaixo. Monte a matriz a
partir do mapa (as linhas são strings), dispare os tiros da lista e mostre,
para cada tiro, "água", "fogo!" ou "repetido". No fim, mostre o tabuleiro
('X' navio atingido, 'o' tiro na água, '#' navio intacto, '.' nada) e
quantas casas de navio sobraram:


```text
const char *mapa[5] = {".##..", ".....", "#...#", "#...#", "#...."};
int tiros[7][2] = {{0, 1}, {2, 2}, {0, 2}, {3, 0}, {0, 1}, {4, 4}, {2, 4}};
```



```text
Saída esperada:
Tiro (0, 1): fogo!
Tiro (2, 2): água
Tiro (0, 2): fogo!
Tiro (3, 0): fogo!
Tiro (0, 1): repetido
Tiro (4, 4): água
Tiro (2, 4): fogo!
.XX..
.....
#.o.X
X...#
#...o
Sobram 3 casas de navio
```

**Dicas:**

1. Casa t[5][5]; e t[i][j].navio = (mapa[i][j] == '#'); t[i][j].atingida =
   false;
2. Escreva const char *atirar(Casa t[5][5], int l, int c), que devolve a
   frase e marca a casa como atingida.
3. Um tiro numa casa já atingida é "repetido", tenha navio ou não.
4. Resposta esperada: a saída acima (sobram 3 casas de navio).

```bash
gcc ~/LPEDC/material/P0816.c -o ~/LPEDC/material/P0816 && ~/LPEDC/material/P0816
```

---

**Exercício P0817** · ★★☆ · Conserte a promoção da vitrine

O programa abaixo deveria dar 15% de desconto em todos os produtos da
vitrine e mostrar o total. Ele tem DOIS erros de propósito: um faz a
promoção não chegar nos produtos (o programa roda e mostra o preço
antigo); o outro o AddressSanitizer acusa quando roda. O gcc não avisa de
nenhum. Conserte os dois. O programa deve mostrar:


```text
Saída esperada:
Rede de dormir     R$ 102.00
Cuia pintada       R$  29.75
Colar de sementes  R$  40.80
Farinha 1 kg       R$  11.90
Total              R$ 184.45
```

**Dicas:**

1. Produto p = v[i]; cria uma CÓPIA da struct. Mexer em p não mexe em
   v[i]. Use um ponteiro: Produto *p = &v[i]; e p->preco.
2. p <= v + n passa uma casa do fim: v + n é o endereço logo depois do
   último produto.

```bash
gcc ~/LPEDC/material/P0817.c -o ~/LPEDC/material/P0817 && ~/LPEDC/material/P0817
```

---

**Exercício P0818** · ★★☆ · Os números complexos

Crie typedef struct { double re, im; } Complexo; e escreva soma,
multiplica (as duas devolvem um Complexo novo), double modulo(Complexo z)
e void mostrar(const char *rotulo, Complexo z), que mostra no formato
"a + bi" ou "a - bi". Com z = 1 + 2i e w = 3 - i, mostre z + w, z * w e
|z * w|. Depois mostre as potências de i, de i¹ a i⁸, multiplicando uma de
cada vez:


```text
Saída esperada:
z + w = 4 + 1i
z * w = 5 + 5i
|z * w| = 7.0711
i^1 = 0 + 1i
i^2 = -1 + 0i
i^3 = 0 - 1i
i^4 = 1 + 0i
i^5 = 0 + 1i
i^6 = -1 + 0i
i^7 = 0 - 1i
i^8 = 1 + 0i
```

**Dicas:**

1. (a + bi)(c + di) = (ac - bd) + (ad + bc)i.
2. |a + bi| = sqrt(a² + b²).
3. No mostrar, se z.im < 0, mostre " - " e o valor absoluto (fabs).
4. As potências de i se repetem a cada 4: i, -1, -i, 1.
5. Na conta de i³, a parte real sai como -0 (o double tem zero com sinal:
   -1 * 0 = -0) e o printf mostra "-0". Teste z.re == 0 (que vale para os
   dois zeros) e mostre 0.

```bash
gcc ~/LPEDC/material/P0818.c -o ~/LPEDC/material/P0818 -lm && ~/LPEDC/material/P0818
```

---

**Exercício P0819** · ★★☆ · A senha escondida com XOR

O operador ^ (ou exclusivo) tem uma propriedade útil: (x ^ k) ^ k == x.
Aplicar a mesma chave duas vezes devolve o original. Escreva void
cifrar(char *s, size_t n, unsigned char chave), que aplica ^ chave em cada
um dos n bytes de s, e void hexa(const char *s, size_t n), que mostra os n
bytes em hexadecimal. Cifre a mensagem com a chave 0x5A, mostre os bytes,
decifre e mostre de novo. Depois conte quantos bits a chave tem ligados e
mostre a chave em binário:


```text
char msg[] = "Encontro no Teatro Amazonas, 19h";
```



```text
Saída esperada:
Cifrada:
1F 34 39 35 34 2E 28 35 7A 34 35 7A 0E 3F 3B 2E
28 35 7A 1B 37 3B 20 35 34 3B 29 76 7A 6B 63 32
Decifrada: Encontro no Teatro Amazonas, 19h
Chave 0x5A = 01011010 (4 bits ligados)
```

**Dicas:**

1. Depois de cifrar, a mensagem pode ter um byte 0 no meio (quando o
   caractere é igual à chave): por isso a função recebe n e não usa o
   '\0'. Guarde n = strlen(msg) ANTES de cifrar.
2. Em hexa: printf("%02X ", (unsigned char) s[i]).
3. Para contar bits: while (x) { cont += x & 1; x >>= 1; }

```bash
gcc ~/LPEDC/material/P0819.c -o ~/LPEDC/material/P0819 && ~/LPEDC/material/P0819
```

---

**Exercício P0820** · ★★☆ · A série do tamanho certo

Desde o C99, o ÚLTIMO campo de uma struct pode ser um vetor sem tamanho (o
"membro flexível"): typedef struct { char nome[16]; int n; double v[]; }
Serie;. O sizeof da struct não conta o vetor, e você aloca a struct junto
com quantas posições quiser, num bloco só:


```text
Serie *s = malloc(sizeof *s + n * sizeof s->v[0]);
```


Escreva Serie *nova_serie(const char *nome, const double *dados, int n), e
crie duas séries de chuva (em mm), uma de 3 dias e outra de 7. Mostre cada
série, a média, o sizeof da struct e quantos bytes cada bloco tem. Libere
com UM free por série:


```text
Belém: 12.5 30.0 8.0
Manaus: 0.0 4.5 22.0 18.0 0.0 6.5 11.0
```



```text
Saída esperada:
sizeof(Serie) = 24 bytes
Belém (3 dias): 12.5 30.0  8.0
  média 16.83 mm, bloco de 48 bytes
Manaus (7 dias):  0.0  4.5 22.0 18.0  0.0  6.5 11.0
  média 8.86 mm, bloco de 80 bytes
```

**Dicas:**

1. sizeof(Serie) conta nome (16) e n (4), mais o preenchimento que
   alinha o double: 24 bytes. O vetor v não entra.
2. Depois do malloc, preencha s->n e copie os dados para s->v[i].
3. Como é um bloco só, um free(s) libera a struct e o vetor juntos.

```bash
gcc ~/LPEDC/material/P0820.c -o ~/LPEDC/material/P0820 && ~/LPEDC/material/P0820
```

### ★★★ Desafio

**Exercício P0821** · ★★★ · O catálogo ordenado por três chaves

O catálogo de uma loja de eletrônicos é um vetor de structs:


```text
typedef enum { CELULAR, NOTEBOOK, FONE } Categoria;
typedef struct {
    char nome[24]; Categoria cat; double preco; int estoque;
} Produto;
```


Ordene com qsort por uma chave COMPOSTA: primeiro a categoria (na ordem do
enum), depois o preço (do mais barato ao mais caro) e, no empate, o nome
(ordem alfabética). Depois mostre o catálogo agrupado, com um cabeçalho por
categoria e, no fim de cada grupo, o valor do estoque (preço x estoque) da
categoria:


```text
Saída esperada:
== Celulares ==
  Celular Lite       R$   999.00  x18
  Celular Alfa       R$  1899.00  x 4
  Celular Mega 5G    R$  1899.00  x10
  Estoque: R$ 44568.00
== Notebooks ==
  Notebook Basic     R$  2499.00  x 7
  Notebook Ultra 14  R$  4299.00  x 3
  Notebook Pro 16    R$  8999.00  x 1
  Estoque: R$ 39389.00
== Fones ==
  Fone com fio       R$    39.90  x60
  Fone Bluetooth X   R$   199.90  x25
  Fone Gamer         R$   199.90  x12
  Estoque: R$ 9790.30
```

**Dicas:**

1. Uma comparação com três critérios: if (a->cat != b->cat) return
   (int) a->cat - (int) b->cat; depois o preço com (x > y) - (x < y);
   por fim, strcmp dos nomes.
2. Para agrupar depois de ordenar, basta perceber quando a categoria muda
   de um produto para o próximo: aí fecha o grupo anterior e abre outro.
3. Os nomes das categorias: const char *nome_cat[] = {"Celulares",
   "Notebooks", "Fones"};

```bash
gcc ~/LPEDC/material/P0821.c -o ~/LPEDC/material/P0821 && ~/LPEDC/material/P0821
```

---

**Exercício P0822** · ★★★ · O conjunto de bits dos assentos

Um ônibus de viagem tem 100 lugares (0 a 99), e cada lugar vendido é um
bit: 100 bits cabem em 13 bytes (unsigned char v[13]). Crie


```text
typedef struct { unsigned char bits[13]; } Conjunto;
```


e escreva inserir, remover, contem (bool), tamanho (quantos bits ligados),
uniao e intersecao (as duas devolvem um Conjunto novo) e mostrar (lista os
números). Dois aplicativos venderam lugares sem conversar entre si:


```text
app A: 3 7 12 40 41 42 77 98
app B: 7 15 40 63 98 99
```


Mostre os vendidos de cada app, a união (todos os vendidos), a interseção
(lugares vendidos DUAS vezes: problema!) e quantos lugares ainda estão
livres. Depois o app A cancela o lugar 7; mostre a nova interseção:


```text
Saída esperada:
App A (8): 3 7 12 40 41 42 77 98
App B (6): 7 15 40 63 98 99
Vendidos (11): 3 7 12 15 40 41 42 63 77 98 99
Vendidos duas vezes (3): 7 40 98
Livres: 89 de 100 (em 13 bytes)
Depois do cancelamento, duas vezes (2): 40 98
```

**Dicas:**

1. O número k mora no byte k / 8, bit k % 8: ligar é bits[k / 8] |= 1u <<
   (k % 8); testar é (bits[k / 8] >> (k % 8)) & 1.
2. União e interseção são feitas BYTE a BYTE: r.bits[i] = a.bits[i] |
   b.bits[i] (ou &). São 13 operações para 100 números.
3. Conjunto vazio: Conjunto c = {0};
4. Livres = 100 - tamanho(união).

```bash
gcc ~/LPEDC/material/P0822.c -o ~/LPEDC/material/P0822 && ~/LPEDC/material/P0822
```

---

**Exercício P0823** · ★★★ · Do CSV para o vetor de structs

O formulário de inscrição da corrida de rua exportou um CSV, uma pessoa por
linha (nome;idade;cidade), e algumas linhas vieram com defeito:


```text
const char *linhas[7] = {"Ana Paula;34;Manaus", "Joel;abc;Parintins",
                         "Rosa;52;Manaus", "Iuri;19;Itacoatiara",
                         "Sem cidade;40", "Marta;27;Parintins",
                         "Caio;61;Manaus"};
```


Crie typedef struct { char nome[24]; int idade; char cidade[16]; } Atleta;
e escreva bool ler_atleta(const char *linha, Atleta *a), que separa os
três campos (com strchr ou andando com um ponteiro), confere se a idade é
só de dígitos, se há exatamente 3 campos e se cada texto cabe no seu
campo, e preenche *a. Guarde as linhas boas num vetor de Atleta, mostre as
recusadas e, das aceitas, a média de idade, o mais velho e quantos atletas
há por cidade:


```text
Saída esperada:
Recusada: "Joel;abc;Parintins"
Recusada: "Sem cidade;40"
Aceitas: 5
Média de idade: 38.6
Mais velho: Caio, 61 anos
Manaus: 3
Itacoatiara: 1
Parintins: 1
```

**Dicas:**

1. strchr(s, ';') devolve o endereço do próximo ';' (ou NULL). A
   distância (p - s) é o tamanho do campo: copie com memcpy e feche com
   '\0' (confira antes se cabe).
2. Para a contagem por cidade, um segundo vetor de structs { char
   cidade[16]; int total; } que cresce quando aparece cidade nova (procure
   com strcmp).
3. Converta a idade com a sua própria conta (o atoi aceitaria "abc" e
   devolveria 0 sem avisar).

```bash
gcc ~/LPEDC/material/P0823.c -o ~/LPEDC/material/P0823 && ~/LPEDC/material/P0823
```

---

**Exercício P0824** · ★★★ · Matriz esparsa vezes vetor

A rede de distribuição de água de um bairro tem 6 reservatórios, e a
matriz A diz quanto (em mil litros) cada reservatório j manda para o
ponto i. Quase tudo é zero, então A é guardada só pelos termos não nulos:


```text
typedef struct { int l, c; double v; } Termo;
```



```text
Termo a[7] = {{0, 0, 2.0}, {0, 3, 1.5}, {1, 1, 4.0}, {2, 5, 0.5},
              {3, 0, 1.0}, {3, 2, 3.0}, {5, 4, 2.5}};
```


Escreva void mult(const Termo *t, int k, const double *x, double *y,
int linhas), que calcula y = A x passando UMA vez pelos k termos (sem
montar a matriz 6x6): cada termo (l, c, v) soma v * x[c] em y[l]. Com o
vetor x de horas de bomba ligada abaixo, mostre y, quantas multiplicações
foram feitas e quantas a matriz cheia faria. Depois calcule a transposta
(troque l e c de cada termo) e mostre Aᵀ x:


```text
double x[6] = {3, 1, 2, 4, 2, 6};
```



```text
Saída esperada:
A x = 12.0 4.0 3.0 9.0 0.0 5.0
Multiplicações: 7 (a matriz cheia faria 36)
At x = 10.0 4.0 12.0 4.5 15.0 1.0
```

**Dicas:**

1. Zere y antes: for (int i = 0; i < linhas; i++) y[i] = 0;
2. Depois: for (int p = 0; p < k; p++) y[t[p].l] += t[p].v * x[t[p].c];
3. Matriz cheia: 6 x 6 = 36 multiplicações; esparsa: só k = 7.
4. Na transposta, monte um Termo tt[7] com tt[p].l = a[p].c e tt[p].c =
   a[p].l. A ordem dos termos não importa para a multiplicação.

```bash
gcc ~/LPEDC/material/P0824.c -o ~/LPEDC/material/P0824 && ~/LPEDC/material/P0824
```

---

**Exercício P0825** · ★★★ · Conserte o painel de sensores

O painel de uma estufa lê sensores de tipos diferentes, guardados numa
union etiquetada, e cada sensor tem flags de estado em bits. O programa
tem TRÊS erros de propósito: o gcc avisa de dois (leia os warnings) e o
terceiro é de lógica (o programa roda, mas mostra coisa errada).
Conserte os três. O programa deve mostrar:


```text
Saída esperada:
Estufa 1: 38.5 graus
  ALERTA
Estufa 2: 81% de umidade
Depósito: porta aberta
  bateria fraca
```

**Dicas:**

1. == tem precedência MAIOR que &: flags & ALERTA == ALERTA é lido como
   flags & (ALERTA == ALERTA), ou seja, flags & 1. Use parênteses.
2. Um case sem break "cai" no próximo: o sensor de umidade mostra duas
   linhas.
3. A etiqueta tem que bater com o campo da union que foi preenchido: ler
   .graus de um sensor que guardou .porcento interpreta os bytes errados.

```bash
gcc ~/LPEDC/material/P0825.c -o ~/LPEDC/material/P0825 && ~/LPEDC/material/P0825
```

---

**Exercício P0826** · ★★★ · Os conflitos da agenda

A agenda de uma fisioterapeuta está fora de ordem e tem compromissos que se
sobrepõem. Crie:


```text
typedef enum { SEG, TER, QUA, QUI, SEX } Dia;
typedef struct { int h, m; } Horario;
typedef struct { char titulo[24]; Dia dia; Horario ini, fim; } Compromisso;
```


Ordene com qsort por dia e, no mesmo dia, pelo horário de início. Depois
mostre a agenda e, para cada par de compromissos SEGUIDOS (na ordem) do
mesmo dia que se sobrepõem, uma linha de conflito com quantos minutos se
cruzam. Encostar (um termina 10:00 e o outro começa 10:00) não é conflito:


```text
Saída esperada:
seg 08:00-09:15 RPG Larissa
seg 09:00-10:00 Hidroterapia Seu Juca
seg 14:30-15:30 Avaliação Sr. Moacir
qua 09:00-10:00 Pilates Dona Cleide
qua 09:40-11:00 Reunião da clínica
qua 11:00-11:30 Retorno Paulinho
sex 18:00-20:00 Curso online
Conflito (seg): "RPG Larissa" e "Hidroterapia Seu Juca", 15 min
Conflito (qua): "Pilates Dona Cleide" e "Reunião da clínica", 20 min
```

**Dicas:**

1. int minutos(Horario t) { return t.h * 60 + t.m; } simplifica tudo.
2. Na comparação: primeiro a->dia - b->dia; depois minutos(a->ini) -
   minutos(b->ini).
3. Depois de ordenar, o compromisso i e o i + 1 do mesmo dia se cruzam se
   minutos(v[i + 1].ini) < minutos(v[i].fim). Os minutos cruzados são
   (o menor dos dois fins) - (início do segundo).
4. Resposta esperada: a saída acima (dois conflitos).

```bash
gcc ~/LPEDC/material/P0826.c -o ~/LPEDC/material/P0826 && ~/LPEDC/material/P0826
```

---

**Exercício P0827** · ★★★ · O crivo de primos em bits

O crivo de Eratóstenes marca os números compostos até N. Com um bool por
número, N = 1000 gasta 1001 bytes; com um BIT por número, gasta 126. Crie


```text
typedef struct { int n; unsigned char bits[126]; } Crivo;
```


em que o bit k ligado quer dizer "k é composto". Escreva void
montar(Crivo *c, int n), bool eh_primo(const Crivo *c, int k) e use-as
para mostrar quantos primos há até 1000, os primos entre 900 e 1000, o
maior intervalo entre dois primos seguidos até 1000 e a memória usada:


```text
Saída esperada:
Primos até 1000: 168
Entre 900 e 1000: 907 911 919 929 937 941 947 953 967 971 977 983 991 997
Maior intervalo: 20 (de 887 a 907)
Memória: 126 bytes de bits (com bool seriam 1001)
```

**Dicas:**

1. Ligue os bits de 0 e 1 (não são primos). Para cada i com i * i <= n
   que ainda é primo, marque i * i, i * i + i, i * i + 2i, ... como
   compostos.
2. Ligar o bit k: c->bits[k / 8] |= 1u << (k % 8). Testar: (c->bits[k /
   8] >> (k % 8)) & 1.
3. Para o maior intervalo, guarde o primo anterior enquanto anda de 2 a
   1000.
4. Resposta esperada: a saída acima (168 primos).

```bash
gcc ~/LPEDC/material/P0827.c -o ~/LPEDC/material/P0827 && ~/LPEDC/material/P0827
```

---

**Exercício P0828** · ★★★ · O cabeçalho do pacote em 32 bits

Um protocolo de sensores sem fio manda, antes de cada pacote, um cabeçalho
de 32 bits com quatro campos:


```text
bits 31-28: versão (4 bits)    bits 27-24: tipo (4 bits)
bits 23-16: tamanho (8 bits)   bits 15-0:  id (16 bits)
```


Crie typedef struct { unsigned versao, tipo, tamanho, id; } Cabecalho; e
escreva:


```text
bool empacotar(const Cabecalho *c, uint32_t *saida); // false: não cabe
Cabecalho desempacotar(uint32_t x);
```


Empacote os três cabeçalhos abaixo, mostre em hexa, desempacote e confira
que voltou igual. O terceiro tem tamanho 300, que não cabe em 8 bits:
empacotar recusa. Por fim, compare com uma struct de CAMPOS DE BITS
(unsigned versao : 4; ...), em que o compilador faz os deslocamentos, e
mostre o sizeof das duas:


```text
{2, 5, 64, 1027}   {15, 0, 255, 65535}   {1, 3, 300, 7}
```



```text
Saída esperada:
{2, 5, 64, 1027} -> 0x25400403 -> {2, 5, 64, 1027} ok
{15, 0, 255, 65535} -> 0xF0FFFFFF -> {15, 0, 255, 65535} ok
{1, 3, 300, 7} -> recusado: campo grande demais
Campos de bits: {2, 5, 64, 1027}
sizeof(Cabecalho) = 16, sizeof(Compacto) = 4
```

**Dicas:**

1. Empacotar: ((uint32_t) v << 28) | ((uint32_t) t << 24) | ((uint32_t)
   tam << 16) | id. Antes, recuse se v > 0xF, t > 0xF, tam > 0xFF ou id >
   0xFFFF.
2. Desempacotar: versao = (x >> 28) & 0xF; tipo = (x >> 24) & 0xF;
   tamanho = (x >> 16) & 0xFF; id = x & 0xFFFF.
3. Campos de bits: typedef struct { unsigned id : 16; unsigned tamanho : 8;
   unsigned tipo : 4; unsigned versao : 4; } Compacto; A ordem dos bits
   dentro da palavra depende do compilador: para mandar pela rede, as
   contas com << e >> são as que você controla.

```bash
gcc ~/LPEDC/material/P0828.c -o ~/LPEDC/material/P0828 && ~/LPEDC/material/P0828
```

---

**Exercício P0829** · ★★★ · A multa da biblioteca

A biblioteca municipal empresta livros por 14 dias e cobra R$ 1,50 por dia
de atraso. Crie typedef struct { int dia, mes, ano; } Data; e
typedef struct { char titulo[32]; char leitor[16]; Data saida, devolucao; }
Emprestimo;. Escreva long dias_desde_inicio(Data d), que conta os dias de
01/01/0001 até d (somando 365 ou 366 por ano completo e os dias dos meses
completos do ano de d), e use a diferença entre duas datas para achar o
atraso. Mostre, para cada empréstimo, os dias com o livro, o atraso e a
multa, e o total arrecadado:


```text
Saída esperada:
Dois Irmãos (Clarice): 9 dias, atraso 0, multa R$ 0.00
Vidas Secas (Otávio): 21 dias, atraso 7, multa R$ 10.50
Macunaíma (Fabiana): 32 dias, atraso 18, multa R$ 27.00
O Cortiço (Ramon): 21 dias, atraso 7, multa R$ 10.50
Total: R$ 48.00
```

**Dicas:**

1. Reaproveite o bissexto e o dias_no_mes do P0805.
2. dias = soma, de 1 até ano - 1, de (bissexto(a) ? 366 : 365) + soma
   dos meses de 1 até mes - 1 + dia. Para datas próximas, só a DIFERENÇA
   importa: o número em si é grande, use long.
3. Atraso = dias com o livro - 14, se for positivo; senão, 0.
4. Atenção às viradas: 20/12/2025 a 10/01/2026 são 21 dias, e 2028 é
   bissexto (29/02 existe).
5. Resposta esperada: a saída acima (total R$ 48.00).

```bash
gcc ~/LPEDC/material/P0829.c -o ~/LPEDC/material/P0829 && ~/LPEDC/material/P0829
```

---

**Exercício P0830** · ★★★ · A fila da triagem

No pronto-socorro, a triagem classifica cada paciente por cor, e a fila de
atendimento é ordenada pela gravidade (vermelho antes de laranja, antes de
amarelo, antes de verde) e, na mesma cor, pela ordem de chegada:


```text
typedef enum { VERDE, AMARELO, LARANJA, VERMELHO } Cor;
typedef struct { char nome[16]; Cor cor; int chegada; } Paciente;
```


A fila é um vetor de Paciente mantido SEMPRE em ordem: escreva
bool entrar(Paciente *fila, int *n, int cap, Paciente p), que encaixa o
paciente no lugar certo (como no P0514, empurrando quem tem prioridade
menor), e Paciente atender(Paciente *fila, int *n), que tira o primeiro.
Simule os eventos abaixo, na ordem, mostrando a fila depois de cada um
(chegada é o minuto em que o paciente chegou):


```text
chega Josué (verde, 0)    chega Ana (amarelo, 2)   chega Rui (verde, 3)
atende                    chega Lia (vermelho, 7)  chega Téo (amarelo, 8)
atende                    atende
```



```text
Saída esperada:
Chega Josué (verde, min 0)
  fila: Josué(verde)
Chega Ana (amarelo, min 2)
  fila: Ana(amarelo) Josué(verde)
Chega Rui (verde, min 3)
  fila: Ana(amarelo) Josué(verde) Rui(verde)
Atende Ana
  fila: Josué(verde) Rui(verde)
Chega Lia (vermelho, min 7)
  fila: Lia(vermelho) Josué(verde) Rui(verde)
Chega Téo (amarelo, min 8)
  fila: Lia(vermelho) Téo(amarelo) Josué(verde) Rui(verde)
Atende Lia
  fila: Téo(amarelo) Josué(verde) Rui(verde)
Atende Téo
  fila: Josué(verde) Rui(verde)
```

**Dicas:**

1. Escreva bool antes(const Paciente *a, const Paciente *b): a tem
   prioridade se a cor for MAIOR (o enum vai de VERDE = 0 a VERMELHO = 3)
   ou, na mesma cor, se a chegada for menor.
2. Em entrar: i = *n - 1; enquanto i >= 0 e antes(&p, &fila[i]), empurre
   fila[i] para fila[i + 1]. Uma struct se copia com = inteira.
3. Em atender: guarde fila[0], puxe todos uma casa para a frente e faça
   (*n)--.

```bash
gcc ~/LPEDC/material/P0830.c -o ~/LPEDC/material/P0830 && ~/LPEDC/material/P0830
```

## Questões no estilo da prova

Formato da prova do mestrado do PPGI/UFAM. Resolva no papel, marque uma letra
e só então abra o gabarito. Os trechos foram compilados com
`gcc -std=c17 -Wall -Wextra`. Quando a resposta depende da máquina, a questão
diz qual.

**Questão 1.** Em uma plataforma de 64 bits típica (`int` de 4 bytes,
alinhado em 4), quanto valem `sizeof(struct a)` e `sizeof(struct b)`?

```c
struct a { char x; int y; char z; };
struct b { int y; char x; char z; };
```

- (A) 6 e 6
- (B) 12 e 8
- (C) 12 e 12
- (D) 8 e 8
- (E) 9 e 6

<details><summary>Gabarito</summary>

**(B)**. Em `a`: `x` no byte 0, 3 bytes de preenchimento, `y` nos bytes 4 a
7, `z` no 8 e mais 3 de preenchimento no fim para o tamanho ser múltiplo de 4
(um vetor de `struct a` precisa manter cada `y` alinhado): 12. Em `b`: `y`
de 0 a 3, `x` no 4, `z` no 5, 2 bytes no fim: 8. Mesmos campos, ordem
diferente, tamanho diferente. Veja 0059.

</details>

**Questão 2.** Sobre struct, union e enum, considere as afirmações e marque a alternativa CORRETA.

- **I.** O tamanho de uma `union` é o do maior campo, arredondado para o alinhamento.
- **II.** O `sizeof` de uma `struct` é sempre a soma dos tamanhos dos campos.
- **III.** Num `enum` sem valores explícitos, o primeiro nome vale 0 e os seguintes sobem de 1 em 1.
- **IV.** Se `p` é um ponteiro para struct, `p->campo` equivale a `(*p).campo`.

- (A) Apenas I e II
- (B) Apenas II e IV
- (C) Apenas I e III
- (D) Apenas I, III e IV
- (E) Apenas II, III e IV

<details><summary>Gabarito</summary>

**(D).** I é verdadeira: os campos dividem o mesmo endereço. II é falsa: o compilador insere preenchimento (padding) para alinhar os campos, e a ordem deles muda o tamanho. III e IV são verdadeiras. Veja 0059, 0063 e 0064.

</details>

**Questão 3.** O que o trecho imprime?

```c
enum cor { AZUL, VERDE = 5, AMARELO, ROXO = 2, CINZA };
printf("%d %d %d %d %d\n", AZUL, VERDE, AMARELO, ROXO, CINZA);
```

- (A) `0 5 6 2 3`
- (B) `1 5 6 2 3`
- (C) `0 5 2 2 3`
- (D) `0 5 6 2 7`
- (E) não compila: valores de enum fora de ordem

<details><summary>Gabarito</summary>

**(A)**. O primeiro vale 0; cada nome sem valor vale o anterior mais 1.
`AMARELO` continua do 5 (6), e `CINZA` continua do 2 (3). Valores fora de
ordem e até repetidos são permitidos. Veja 0063.

</details>

**Questão 4.** O que o trecho imprime?

```c
typedef struct { int qtd; double preco; } Item;

Item a = {2, 9.5};
Item b = a;
Item *p = &a;
b.qtd = 7;
p->preco = 10.0;
printf("%d %.1f %d %.1f\n", a.qtd, a.preco, b.qtd, b.preco);
```

- (A) `7 10.0 7 10.0`
- (B) `2 9.5 7 10.0`
- (C) `7 9.5 7 9.5`
- (D) `2 10.0 7 10.0`
- (E) `2 10.0 7 9.5`

<details><summary>Gabarito</summary>

**(E)**. `b = a` copia o registro inteiro: `b` é independente, e mudar
`b.qtd` não mexe em `a`. Já `p` guarda o endereço de `a`, então
`p->preco` (o mesmo que `(*p).preco`) muda `a.preco`. `b.preco` continua com
a cópia antiga, 9.5. Veja 0059 e 0062.

</details>

**Questão 5.** Com `unsigned x = 0xB4;` (binário `1011 0100`), quanto valem
`x & 0x0F`, `x | 0x01` e `x >> 2`?

- (A) `0x0B`, `0xB5`, `0x2D`
- (B) `0x04`, `0xB4`, `0x2D`
- (C) `0x04`, `0xB5`, `0x2D`
- (D) `0x04`, `0xB5`, `0x5A`
- (E) `0xB0`, `0xB5`, `0x2D`

<details><summary>Gabarito</summary>

**(C)**. `& 0x0F` guarda só os 4 bits de baixo (`0100` = 0x04). `| 0x01`
liga o bit 0 (`1011 0101` = 0xB5). `>> 2` empurra tudo duas casas para a
direita (`0010 1101` = 0x2D); a resposta 0x5A seria `>> 1`. Veja 0065.

</details>

**Questão 6.** Qual o valor final de `flags` e o que o `printf` mostra?

```c
unsigned flags = 0x05;          /* 0101 */
flags |= 1u << 3;
flags &= ~(1u << 0);
printf("%u\n", (flags >> 2) & 1u);
```

- (A) `flags` = 0x0D; imprime 1
- (B) `flags` = 0x0C; imprime 1
- (C) `flags` = 0x0C; imprime 0
- (D) `flags` = 0x08; imprime 0
- (E) `flags` = 0x04; imprime 1

<details><summary>Gabarito</summary>

**(B)**. `|= 1u << 3` liga o bit 3: `1101` (0x0D). `&= ~(1u << 0)` desliga o
bit 0: `1100` (0x0C). `(flags >> 2) & 1u` testa o bit 2, que está ligado: 1.
São as três operações clássicas: ligar com `|`, desligar com `& ~`, testar
com `>>` e `&`. Veja 0065.

</details>

**Questão 7.** Em uma plataforma com `int` de 32 bits, o que o trecho
imprime?

```c
unsigned char c = 250;
c += 10;
int x = -1;
unsigned int u = 1;
printf("%d %d\n", c, x < u);
```

- (A) `260 1`
- (B) `4 1`
- (C) `260 0`
- (D) `-6 1`
- (E) `4 0`

<details><summary>Gabarito</summary>

**(E)**. `unsigned char` vai de 0 a 255 e a conta "dá a volta" módulo 256:
260 − 256 = 4 (para tipos sem sinal, isso é garantido pelo padrão). Na
comparação, o `int` −1 é convertido para `unsigned`, virando 4294967295, que
não é menor que 1: dá 0. O gcc avisa com `-Wsign-compare`. Veja 0065 (e
0171, que aprofunda com e sem sinal).

</details>

**Questão 8.** Em uma plataforma de 64 bits típica, o que o trecho imprime?

```c
#define PINT int *
typedef int *Pint;

int n = 0;
PINT a = &n, b = 0;
Pint c = &n, d = &n;
printf("%zu %zu %zu %zu\n", sizeof a, sizeof b, sizeof c, sizeof d);
```

- (A) `8 4 8 8`
- (B) `8 8 8 8`
- (C) `8 4 8 4`
- (D) `4 4 8 8`
- (E) não compila: `PINT` e `Pint` têm o mesmo nome

<details><summary>Gabarito</summary>

**(A)**. O `#define` só troca texto: a linha vira `int * a = &n, b = 0;`, e o
`*` vale só para `a`; `b` é um `int` (4 bytes). O `typedef` cria um nome de
tipo de verdade: `c` e `d` são os dois `int *` (8 bytes). E o C diferencia
maiúsculas de minúsculas, então os nomes não colidem. Veja 0060.

</details>

**Questão 9.** Sobre operadores bit a bit, com e sem sinal, considere as afirmações e marque a alternativa CORRETA.

- **I.** Em `unsigned`, `x << 1` equivale a multiplicar por 2, desde que não haja estouro.
- **II.** Com `int x = -1;` e `unsigned u = 1;`, a comparação `x < u` vale 1.
- **III.** `0x0F & 0xB4` vale `0x04`.
- **IV.** O deslocamento `>>` sobre um `unsigned` entra com bits 1 pela esquerda.

- (A) Apenas I e III
- (B) Apenas I e II
- (C) Apenas II e IV
- (D) Apenas III e IV
- (E) Apenas I, II e III

<details><summary>Gabarito</summary>

**(A).** I e III são verdadeiras (`1011 0100 & 0000 1111` deixa `0100`). II é falsa: o `-1` é convertido para `unsigned`, vira 4294967295 e a comparação dá 0. IV é falsa: em `unsigned`, o `>>` entra com zeros. Veja 0065 e 0171.

</details>

**Questão 10.** O que o trecho imprime?

```c
#define DOBRO(x) x * 2
#define DOBRO_OK(x) ((x) * 2)

printf("%d %d\n", DOBRO(3 + 1), DOBRO_OK(3 + 1));
```

- (A) `8 8`
- (B) `5 5`
- (C) `5 8`
- (D) `8 5`
- (E) não compila: macro não recebe expressão

<details><summary>Gabarito</summary>

**(C)**. O pré-processador cola o texto antes de compilar: `DOBRO(3 + 1)`
vira `3 + 1 * 2`, e a multiplicação vem primeiro: 5. Com parênteses em volta
do parâmetro e da expressão inteira, `((3 + 1) * 2)` dá 8. Veja 0004 e 0060.

</details>

## Para ler mais

- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 8: struct, union, enum e typedef; cap. 13: campos de bits.
- BACKES, A. *Linguagem C: descomplicada*. Apostila. Uberlândia: FACOM/UFU, [s.d.].
- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 10: estruturas, uniões, manipulações de bits e enumerações.
- CELES, W.; RANGEL, J. L. *Apostila de estruturas de dados*. Rio de Janeiro: PUC-Rio, 2002.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016. Tipos estruturados: struct, union, enum e typedef.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995. Cap. 1: estruturas e uniões em C.
- ZIVIANI, N. *Projeto de algoritmos: com implementações em Pascal e C*. 3. ed. rev. e ampl. São Paulo: Cengage Learning, 2010. Registros e tipos definidos pelo programador nas implementações em C.
- MARTINS, L. G. A. *Apostila de linguagem C: conceitos básicos*. Uberlândia: FACOM/UFU, [s.d.].
- ANTONELLO, R. *Linguagem C*. 1. ed. Disponível em: <http://www.antonello.com.br>.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Cap. 6: structures.
- CPPREFERENCE. *Struct declaration*; *Union declaration*; *Enumerations*; *Bitwise operators*. Disponível em: <https://en.cppreference.com/w/c/language>.
- LINUX MAN PAGES. *chmod(2)*, *inode(7)* (bits de permissão) e *byteorder(3)* (`htonl`, `ntohl`). Disponível em: <https://man7.org/linux/man-pages/>.

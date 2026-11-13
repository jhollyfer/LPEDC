## 0074 · TAD: interface (.h) e implementação (.c)

Os módulos seguintes constroem listas, pilhas, filas, árvores. Cada uma tem
dados guardados de um jeito e funções que mexem neles. Se o `main` puder
mexer direto nos campos, qualquer descuido estraga a estrutura, e qualquer
mudança no jeito de guardar obriga a reescrever todo programa que a usa. Falta
uma parede entre quem usa a estrutura e quem a constrói.

Na entrada do estacionamento do shopping há um painel: "VAGAS LIVRES: 3". A
cancela só abre se houver vaga. Você não sabe se o sistema usa sensor, câmera
ou planilha, e nem precisa saber. Você usa três "botões": entrar, sair e ver
quantas vagas sobram. Um **tipo abstrato de dado** (TAD) leva essa ideia ao
código. É um tipo definido pelas **operações** que oferece, e não pelo modo
como guarda os dados. Quem usa o tipo, o **cliente**, conhece só as
operações; quem implementa pode trocar tudo por dentro, desde que as
operações cumpram o prometido (CELES; RANGEL, 2002).

No C, essa divisão é física e fica em dois arquivos (CELES; RANGEL, 2002). O
primeiro é a **interface**, `contador.h`: o contrato. Ele declara o tipo e os
protótipos das funções, cada um com um comentário dizendo o que entra, o que
sai e o que pode dar errado. O cliente inclui esse arquivo e não vê mais
nada:

```c
typedef struct contador Contador; // tipo opaco: os campos ficam no contador.c

// Soma 1. Devolve true se somou; false se já estava no limite.
bool contador_incrementa(Contador *c);
```

O segundo é a **implementação**, `contador.c`. Ele define a `struct` com os
campos e escreve o corpo das funções. Ele também inclui o próprio `.h`, para o
compilador conferir que cada função bate com o protótipo prometido. O cliente
nunca inclui o `.c`; ele só é compilado junto (CELES; RANGEL, 2002).

Repare na primeira linha do trecho acima. O `.h` diz que existe uma
`struct contador`, mas não diz quais campos ela tem. Para o cliente, ela é
um **tipo incompleto**: dá para ter um ponteiro `Contador *`, mas não uma
variável `Contador`, nem `sizeof(Contador)`, nem `vagas->valor`, porque o
compilador não sabe o tamanho nem os campos. Esse é o **tipo opaco**, e é ele
que fecha a porta. Como o cliente não consegue criar a struct, todo TAD opaco
oferece uma `contador_cria`, que faz o `malloc` lá dentro e devolve o
ponteiro, e uma `contador_libera`, que faz o `free` (CELES; CERQUEIRA;
RANGEL, 2016).

A porta fechada é o que permite ao TAD cumprir um **invariante**, como no
assunto 0073. O contador promete `0 <= valor <= limite` o tempo todo. A
promessa só vale porque ninguém de fora escreve `vagas->valor = 99`: toda
mudança passa por `contador_incrementa` e `contador_decrementa`, que recusam a
operação em vez de quebrar a regra.

O `#include` só cola o texto do `.h` no começo do arquivo do cliente. O
cliente vira um `.o` sem saber o tamanho da struct, e não precisa: ponteiro
tem sempre o mesmo tamanho. Só o `contador.o` conhece os campos, e o
**ligador** (*linker*) junta os dois `.o` no executável. Por isso mudar a
struct exige recompilar só o `contador.c` (KERNIGHAN; RITCHIE, 1989,
seção 4.5). Essa é a **compilação separada**.

Toda estrutura dos módulos 11 a 16 segue o mesmo molde. Para um TAD `x`:

1. **Pasta do assunto**: `x.h`, `x.c` e os exemplos `A###.c`. O comando do
   exemplo compila junto todo `.c` da pasta que não se chama
   `A000.c`/`E000.c`. À mão: `gcc A147.c contador.c -o a147`.
2. **`x.h`**: *include guard* (`#ifndef X_H`), que impede o arquivo de ser
   colado duas vezes, `typedef struct x X;` e protótipos com prefixo `x_`,
   cada um com seu contrato.
3. **`x.c`**: inclui o próprio `"x.h"` e define a `struct x` com o invariante
   comentado; funções auxiliares internas são `static`, invisíveis fora dele.
4. **Nomes**: `x_cria` (devolve `NULL` se faltar memória), `x_libera` (aceita
   `NULL`) e verbos no presente: `x_insere`, `x_remove`. Leitura recebe
   `const X *`.
5. **Erros**: operação que pode falhar devolve `bool`, com o valor por
   ponteiro (`bool pilha_desempilha(Pilha *p, int *valor)`). O TAD não
   imprime erro; o cliente decide o que mostrar.
6. **Cliente**: `#include "x.h"` com aspas, guarda só `X *`, confere o `NULL`
   do `_cria` e chama `_libera` no fim.

> [!WARNING]
> `vagas->valor = 0;` ou `Contador c;` no cliente dá erro de **compilação**
> (`invalid use of incomplete typedef`): é o tipo opaco funcionando. Não mova
> a `struct` para o `.h`; se falta uma operação, acrescente uma função. E
> esquecer o `contador.c` ao compilar à mão dá `undefined reference`, erro do
> **ligador**.

{{exemplo}}

O estacionamento do shopping tem 3 vagas e o painel só abre a cancela se houver
vaga. O cliente (o arquivo do `main`) tem só um ponteiro para um bloco no heap
que não consegue abrir:

{{ideia}}

O contrato completo está em `contador.h`, na pasta do assunto. O cliente
estaciona 4 carros em 3 vagas:

```c
#include <stdio.h>

#include "contador.h" // só a interface: a struct está escondida em contador.c

int main(void) {
    Contador *vagas = contador_cria(3); // estacionamento com 3 vagas
    if (vagas == NULL) {
        printf("Sem memória\n");
        return 1;
    }

    const char *placas[4] = {"RIO2A18", "SPX3B45", "BHZ7C09", "CWB1D77"};
    for (int i = 0; i < 4; i++) {
        if (contador_incrementa(vagas)) {
            printf("%s entrou (%d/%d)\n", placas[i], contador_valor(vagas),
                   contador_limite(vagas));
        } else {
            printf("%s: lotado, espere\n", placas[i]);
        }
    }

    contador_decrementa(vagas); // um carro sai
    printf("Um carro saiu (%d/%d)\n", contador_valor(vagas), contador_limite(vagas));

    if (contador_incrementa(vagas)) {
        printf("CWB1D77 entrou (%d/%d)\n", contador_valor(vagas), contador_limite(vagas));
    }

    contador_libera(vagas);
    return 0;
}
// Saída:
// RIO2A18 entrou (1/3)
// SPX3B45 entrou (2/3)
// BHZ7C09 entrou (3/3)
// CWB1D77: lotado, espere
// Um carro saiu (2/3)
// CWB1D77 entrou (3/3)
```

O mesmo cliente outra vez, para ler lado a lado com a implementação que vem a
seguir:

```c
#include <stdio.h>

#include "contador.h" // só a interface: a struct está escondida em contador.c

int main(void) {
    Contador *vagas = contador_cria(3); // estacionamento com 3 vagas
    if (vagas == NULL) {
        printf("Sem memória\n");
        return 1;
    }

    const char *placas[4] = {"RIO2A18", "SPX3B45", "BHZ7C09", "CWB1D77"};
    for (int i = 0; i < 4; i++) {
        if (contador_incrementa(vagas)) {
            printf("%s entrou (%d/%d)\n", placas[i], contador_valor(vagas),
                   contador_limite(vagas));
        } else {
            printf("%s: lotado, espere\n", placas[i]);
        }
    }

    contador_decrementa(vagas); // um carro sai
    printf("Um carro saiu (%d/%d)\n", contador_valor(vagas), contador_limite(vagas));

    if (contador_incrementa(vagas)) {
        printf("CWB1D77 entrou (%d/%d)\n", contador_valor(vagas), contador_limite(vagas));
    }

    contador_libera(vagas);
    return 0;
}
// Saída:
// RIO2A18 entrou (1/3)
// SPX3B45 entrou (2/3)
// BHZ7C09 entrou (3/3)
// CWB1D77: lotado, espere
// Um carro saiu (2/3)
// CWB1D77 entrou (3/3)
```

O lado escondido fica em `contador.c`:

```c
#include <stdlib.h>

#include "contador.h"

// Invariante da struct: 0 <= valor <= limite e limite >= 1.
struct contador {
    int valor;
    int limite;
};

Contador *contador_cria(int limite) {
    if (limite < 1) {
        return NULL;
    }
    Contador *c = malloc(sizeof *c);
    if (c == NULL) {
        return NULL;
    }
    c->valor = 0;
    c->limite = limite;
    return c;
}

bool contador_incrementa(Contador *c) {
    if (c->valor == c->limite) {
        return false; // recusa em vez de quebrar o invariante
    }
    c->valor++;
    return true;
}
// ... contador_libera, contador_decrementa, contador_zera,
//     contador_valor e contador_limite seguem o mesmo estilo
```

O cliente fala com o TAD só pelas funções. Quem decide "lotado" é o
`contador_incrementa`, que devolve `false`:

{{fluxograma}}

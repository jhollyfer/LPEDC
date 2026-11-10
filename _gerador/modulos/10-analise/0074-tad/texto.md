## 0074 · TAD: interface (.h) e implementação (.c)

Na entrada do estacionamento do shopping, um painel: "VAGAS LIVRES: 3". A
cancela só abre se houver vaga. Você não sabe se o sistema usa sensor, câmera
ou planilha, e nem precisa. Usa três "botões": entrar, sair e ver quantas
vagas sobram.

Um **tipo abstrato de dado** (TAD) leva isso ao código: um tipo definido pelas
**operações** que oferece, não pelo modo como guarda os dados. Quem usa (o
**cliente**) conhece só as operações. Quem implementa pode trocar tudo por
dentro, desde que as operações cumpram o prometido.

No C, a divisão é física, em dois arquivos:

- **`contador.h`, a interface**: o contrato. Declara o tipo e os protótipos,
  cada um com um comentário sobre o que entra, o que sai e o que pode dar
  errado. O cliente o inclui.
- **`contador.c`, a implementação**: define a `struct` e escreve as funções.
  O cliente nunca o inclui; ele só é compilado junto.

O **tipo opaco** fecha a porta. O `.h` diz só `typedef struct contador
Contador;`, sem os campos. No cliente, `struct contador` é um **tipo
incompleto**: dá para ter um ponteiro `Contador *`, mas não uma variável
`Contador`, nem `sizeof`, nem `->valor`. Por isso todo TAD opaco tem uma
`_cria`, que faz o `malloc` lá dentro, e uma `_libera`, que faz o `free`.

Isso permite ao TAD garantir um **invariante**, como no 0073. O contador
promete `0 <= valor <= limite`. Se o cliente pudesse escrever
`vagas->valor = 99`, a promessa não valeria nada.

No exemplo, o cliente (o arquivo do `main`) inclui só o contrato; o
`contador.c` também o inclui e guarda a `struct` escondida. Na memória, o
cliente tem só um ponteiro para um bloco no heap que não consegue abrir:

{{ideia}}

O contrato completo está em `contador.h`, na pasta do assunto. O cliente estaciona 4 carros em 3 vagas:

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

O lado escondido fica em `contador.c`, que inclui o próprio `.h` para o
compilador conferir cada função contra o protótipo.

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

O lado escondido fica em `contador.c`. Ele inclui o próprio `.h`, e assim o
compilador confere que cada função bate com o protótipo prometido.

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

No fluxograma, o cliente fala com o TAD só pelas funções. Quem decide
"lotado" é o `contador_incrementa`, que devolve `false`:

{{fluxograma}}

### O padrão dos próximos módulos

Toda estrutura dos módulos 11 a 16 (lista, pilha, fila, árvore, hash, grafo)
segue este molde. Para um TAD `x`:

1. **Pasta do assunto**: `x.h`, `x.c` e os exemplos `A###.c`. O comando do
   exemplo compila junto todo `.c` da pasta que não se chama
   `A000.c`/`E000.c`. À mão: `gcc A147.c contador.c -o a147`.
2. **`x.h`**: comentário sobre o que o TAD é; *include guard* (`#ifndef X_H`);
   só os `#include` de que a interface precisa (em geral `<stdbool.h>`);
   `typedef struct x X;`; protótipos com prefixo `x_`, cada um com seu
   contrato em comentário.
3. **`x.c`**: inclui as bibliotecas e o próprio `"x.h"`; define a `struct x`
   com o invariante comentado em cima; funções auxiliares internas são
   `static` (invisíveis fora do arquivo).
4. **Nomes**: `x_cria` (devolve `NULL` se faltar memória), `x_libera` (aceita
   `NULL`) e verbos no presente para o resto: `x_insere`, `x_remove`,
   `x_valor`. Leitura recebe `const X *`.
5. **Erros**: operação que pode falhar devolve `bool`; valor de saída vai por
   ponteiro (`bool pilha_desempilha(Pilha *p, int *valor)`). O TAD não
   imprime erro: o cliente decide o que mostrar.
6. **Cliente**: `#include "x.h"` com aspas, guarda só `X *`, confere o `NULL`
   do `_cria` e chama `_libera` no fim. Nunca usa `->` num `X`.

> [!WARNING]
> Se o cliente tentar `vagas->valor = 0;` ou `Contador c;`, o erro é de
> **compilação**: `invalid use of incomplete typedef 'Contador'`. É o tipo
> opaco funcionando. Não "conserte" movendo a `struct` para o `.h`: qualquer
> cliente voltaria a quebrar o invariante. Se falta uma operação, acrescente
> uma função na interface. Outro tropeço: esquecer o `contador.c` ao compilar
> à mão. O erro `undefined reference to 'contador_cria'` é do **ligador**.

> [!TIP]
> **Por dentro do C:** o `#include "contador.h"` só cola texto: o cliente
> recebe os protótipos e a frase "existe uma `struct contador`". O `A147.o`
> nasce sem saber o tamanho da struct (ponteiro tem sempre 8 bytes em 64
> bits); só o `contador.o` conhece os campos. O ligador junta os dois. Por
> isso mudar a struct exige recompilar só o `contador.c`.

> [!NOTE]
> **Pergunta para você:** no exemplo A148, a conta guarda o saldo em
> centavos (`int`), e não em reais (`double`). Por quê? E se o banco quisesse
> trocar para `long long` amanhã, quais arquivos mudariam: `conta.h`,
> `conta.c` ou o cliente?

{{pratique}}

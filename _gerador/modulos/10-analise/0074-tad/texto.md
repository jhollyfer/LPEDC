## 0074 · TAD: interface (.h) e implementação (.c)

- **Tipo abstrato de dado** (TAD): tipo definido pelas **operações** que
  oferece, não pelo modo como guarda os dados. O **cliente** conhece só as
  operações (CELES; RANGEL, 2002).
- **Interface** (`contador.h`): o contrato. Declara o tipo e os protótipos, cada
  um com comentário sobre o que entra, o que sai e o que pode dar errado
  (CELES; RANGEL, 2002).
- **Implementação** (`contador.c`): define a `struct`, escreve as funções e
  inclui o próprio `.h`, para o compilador conferir cada função contra o
  protótipo (CELES; RANGEL, 2002).
- **Tipo opaco**: o `.h` diz só `typedef struct contador Contador;`. No cliente
  é um **tipo incompleto**: dá para ter `Contador *`, mas não variável, `sizeof`
  nem `->valor`. Por isso há `_cria` (faz o `malloc`) e `_libera`
  (CELES; CERQUEIRA; RANGEL, 2016).
- **Invariante do TAD**: o contador promete `0 <= valor <= limite`. Só vale
  porque o cliente não escreve `vagas->valor = 99`.
- **Compilação separada**: o `#include` só cola texto; só o `contador.o` conhece
  os campos, e o ligador junta tudo. Mudar a struct recompila só o `contador.c`
  (KERNIGHAN; RITCHIE, 1989, seção 4.5).
- **Molde dos módulos 11 a 16**, para um TAD `x`:
  1. **Pasta do assunto**: `x.h`, `x.c` e os exemplos `A###.c`. O comando do
     exemplo compila junto todo `.c` da pasta que não se chama
     `A000.c`/`E000.c`. À mão: `gcc A147.c contador.c -o a147`.
  2. **`x.h`**: *include guard* (`#ifndef X_H`), `typedef struct x X;` e
     protótipos com prefixo `x_`, cada um com seu contrato.
  3. **`x.c`**: inclui o próprio `"x.h"`, define a `struct x` com o invariante
     comentado; auxiliares internas são `static`.
  4. **Nomes**: `x_cria` (devolve `NULL` se faltar memória), `x_libera` (aceita
     `NULL`) e verbos no presente: `x_insere`, `x_remove`. Leitura recebe
     `const X *`.
  5. **Erros**: operação que pode falhar devolve `bool`, com o valor por ponteiro
     (`bool pilha_desempilha(Pilha *p, int *valor)`). O TAD não imprime erro.
  6. **Cliente**: `#include "x.h"` com aspas, guarda só `X *`, confere o `NULL`
     do `_cria` e chama `_libera` no fim.

> [!WARNING]
> `vagas->valor = 0;` ou `Contador c;` no cliente dá erro de **compilação**
> (`invalid use of incomplete typedef`): é o tipo opaco funcionando. Não mova a
> `struct` para o `.h`. E esquecer o `contador.c` ao compilar à mão dá
> `undefined reference`, erro do **ligador**.

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

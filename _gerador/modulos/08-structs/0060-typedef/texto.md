## 0060 · Typedef

- **Typedef**: dá um **apelido** a um tipo que já existe. Cria um sinônimo, não
  um tipo novo (BACKES, 2013, cap. 8).
- **Regra de leitura**: escreva a declaração de uma variável e ponha `typedef`
  na frente. O nome que seria a variável vira o nome do tipo
  (FEOFILOFF, 2009, ap. J).

```c
double Reais;          // uma variável chamada Reais
typedef double Reais;  // um apelido: Reais agora é o mesmo que double
```

- **Com struct**: batize uma struct existente (`typedef struct pix Pix;`) ou
  faça tudo de uma vez, sem nome para a struct. Depois basta `Pix p;`
  (DEITEL; DEITEL, 2011, cap. 10).

```c
typedef struct {
    char chave[40];
    Reais valor;
    int hora;
} Pix;
```

- **Tipos definidos pelo programador**: struct, union e enum, com ou sem
  `typedef` (CELES; CERQUEIRA; RANGEL, 2016).
- **Convenção**: inicial maiúscula em nome de tipo, para não confundir tipo com
  variável (DEITEL; DEITEL, 2011, cap. 10).
- **Typedefs da biblioteca**: `size_t`, `uint8_t`, `int32_t` e `FILE` são
  apelidos definidos nos cabeçalhos. `uint8_t` diz "8 bits sem sinal" em
  qualquer máquina (KERNIGHAN; RITCHIE, 1988, cap. 6).

> [!WARNING]
> `typedef` não cria tipo novo: com `typedef double Reais;` e
> `typedef double Dolares;`, `Reais r = dolares;` compila. Para barrar a
> mistura, embrulhe numa struct. E `typedef int *PInt;` esconde que
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

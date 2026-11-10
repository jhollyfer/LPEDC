## 0173 · Juntando tudo: o controle de acesso

O coworking tem porta com crachá, reunião, impressora, garagem e configuração.
O papel (visitante, membro ou admin) dá um pacote de permissões, com exceções:
o Bruno aluga vaga na garagem, e a Carla estourou a cota da impressora.

As permissões são **bits** num `unsigned`, e o papel é um **enum** que indexa
o vetor `base`. A **struct** `Usuario` guarda o papel e duas máscaras: `extra`
(o que ganhou) e `bloqueio` (o que perdeu). A permissão efetiva sai de uma
expressão:

`(base[u->papel] | u->extra) & ~u->bloqueio`

O `|` junta pacote e extras (com parênteses, porque `&` vem antes de `|`). O
`~` (nível 2) inverte o bloqueio, e o `&` apaga esses bits: **o bloqueio
vence**. "Pode tudo desta máscara?" é `(efetivas & mascara) == mascara`:
parênteses de novo, porque o `==` vem antes do `&`.

Tudo é `unsigned`: `~` num `int` daria negativo, e misturar sinais abre a
porta para o `-1 > 0u`. A planilha é um **VLA** `bool acesso[n][QTD_PERMS]`.

A Carla é membro (`00111`: imprimir, reunião, entrar) com a impressora
bloqueada. O desenho faz a conta bit a bit:

{{ideia}}

O programa monta a planilha e mostra quem pode usar a reunião **e** imprimir:

```c
#include <stdbool.h>
#include <stdio.h>

typedef enum { VISITANTE, MEMBRO, ADMIN, QTD_PAPEIS } Papel;

// cada permissão é um bit
#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

typedef struct {
    char nome[16];
    Papel papel;
    unsigned extra;    // concedidas além do papel
    unsigned bloqueio; // retiradas, mesmo que o papel dê
} Usuario;

// o que cada papel ganha de saída (na ordem do enum)
const unsigned base[QTD_PAPEIS] = {
    ENTRAR,                                          // visitante
    ENTRAR | REUNIAO | IMPRIMIR,                     // membro
    ENTRAR | REUNIAO | IMPRIMIR | GARAGEM | CONFIG,  // admin
};

unsigned efetivas(const Usuario *u) {
    return (base[u->papel] | u->extra) & ~u->bloqueio; // o bloqueio vence
}

bool pode(const Usuario *u, unsigned mascara) {
    return (efetivas(u) & mascara) == mascara; // tem TODAS da máscara
}

int main(void) {
    Usuario equipe[] = {
        {"Ana", ADMIN, 0, 0},
        {"Bruno", MEMBRO, GARAGEM, 0},
        {"Carla", MEMBRO, 0, IMPRIMIR}, // estourou a cota da impressora
        {"Davi", VISITANTE, REUNIAO, 0},
    };
    int n = 4; // uma variável: a matriz abaixo é um VLA
    const char *papeis[QTD_PAPEIS] = {"visitante", "membro", "admin"};

    bool acesso[n][QTD_PERMS]; // usuário x permissão
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < QTD_PERMS; b++) {
            acesso[i][b] = pode(&equipe[i], 1u << b);
        }
    }

    printf("usuario  papel      E R I G C\n");
    for (int i = 0; i < n; i++) {
        printf("%-8s %-10s", equipe[i].nome, papeis[equipe[i].papel]);
        for (int b = 0; b < QTD_PERMS; b++) {
            printf(" %c", acesso[i][b] ? 'X' : '-');
        }
        printf("\n");
    }

    printf("pode REUNIAO | IMPRIMIR:");
    for (int i = 0; i < n; i++) {
        if (pode(&equipe[i], REUNIAO | IMPRIMIR)) {
            printf(" %s", equipe[i].nome);
        }
    }
    printf("\n");
    return 0;
}
// Saída:
// usuario  papel      E R I G C
// Ana      admin      X X X X X
// Bruno    membro     X X X X -
// Carla    membro     X X - - -
// Davi     visitante  X X - - -
// pode REUNIAO | IMPRIMIR: Ana Bruno
```

O fluxograma é um laço pela equipe com uma comparação de bits por pessoa:

{{fluxograma}}

> [!WARNING]
> `efetivas(u) & mascara == mascara` é lido como `efetivas(u) & (mascara ==
> mascara)`, isto é, `efetivas(u) & 1`: só olha o bit de ENTRAR (o gcc
> avisa). E `p = p | ~IMPRIMIR` no lugar de `p = p & ~IMPRIMIR` **liga todas
> as outras** permissões, até as que não existem, e compila sem aviso.

> [!NOTE]
> **Pergunta para você:** que máscara de `extra` o Davi precisaria para poder
> imprimir? E se a Ana ganhar `bloqueio = CONFIG | GARAGEM`, como fica a linha
> dela na planilha?

{{pratique}}

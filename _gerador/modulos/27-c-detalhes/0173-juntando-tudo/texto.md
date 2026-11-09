## 0173 · Juntando tudo: o controle de acesso

O coworking do centro tem porta com crachá, sala de reunião, impressora,
garagem e painel de configuração. Cada pessoa tem um papel (visitante, membro
ou admin), e o papel dá um pacote de permissões. Mas há exceções: o Bruno,
membro, aluga uma vaga na garagem; a Carla estourou a cota da impressora.

Cada peça do módulo entra numa parte. As permissões são **bits** num
`unsigned`, e o papel é um **enum** que indexa o vetor `base` com o pacote de
cada um. A **struct** `Usuario` guarda o papel e duas máscaras de exceção:
`extra` (o que ganhou a mais) e `bloqueio` (o que perdeu). A permissão
efetiva sai de uma expressão só:

`(base[u->papel] | u->extra) & ~u->bloqueio`

Leia com a tabela de precedência na mão. O `|` junta o pacote e os extras;
os parênteses são obrigatórios, porque `&` vem antes de `|`. O `~` (nível 2)
inverte o bloqueio antes de tudo, e o `&` com ele apaga os bits bloqueados:
**o bloqueio vence**. E a pergunta "pode tudo desta máscara?" é
`(efetivas & mascara) == mascara`, de novo com parênteses, porque o `==` vem
antes do `&`.

Tudo é `unsigned`, de propósito: `~` num `int` daria um negativo, e misturar
com sinal e sem sinal abre a porta para o `-1 > 0u`. A planilha final,
usuário × permissão, é um **VLA** `bool
acesso[n][QTD_PERMS]`: o `n` é uma variável, o tamanho é decidido na hora, e
uma equipe maior não muda o código.

A Carla é membro (`00111`: imprimir, reunião, entrar),
sem extras e com a impressora bloqueada. O desenho faz a conta bit a bit:

{{ideia}}

O programa monta a planilha e responde quem pode usar a sala de reunião **e**
imprimir:

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

O fluxograma responde "pode `REUNIAO | IMPRIMIR`?" com um laço pela equipe e
uma única comparação de bits por pessoa. A máscara pode ter uma permissão ou
cinco, e o custo é o mesmo:

{{fluxograma}}

> [!WARNING]
> Duas linhas parecidas, dois programas diferentes. `efetivas(u) & mascara ==
> mascara` é lido como `efetivas(u) & (mascara == mascara)`, isto é,
> `efetivas(u) & 1`: só olha o bit de ENTRAR (o gcc avisa). E
> `p = p | ~IMPRIMIR` em vez de `p = p & ~IMPRIMIR` não tira a impressora:
> **liga todas as outras** permissões, até as que não existem. Esse erro
> compila sem aviso nenhum.

> [!TIP]
> **Por dentro do C:** um `Usuario` ocupa 28 bytes: 16 do nome, 4 do enum e 4
> de cada máscara. Cinco permissões como `bool` seriam 5 campos e cinco `if`;
> como bits, são 4 bytes para até 32 permissões, e `pode` vira três
> instruções (`or`, `and`, `cmp`). O VLA `acesso[4][5]` são 20 bytes na
> pilha; com 10 milhões de usuários, troque por `malloc`.

> [!NOTE]
> **Pergunta para você:** que máscara de `extra` o Davi precisaria para poder
> imprimir? E se a Ana ganhar `bloqueio = CONFIG | GARAGEM`, como fica a linha
> dela na planilha?

{{pratique}}

## 0173 · Juntando tudo: o controle de acesso

O coworking do bairro tem cinco recursos controlados por crachá: a porta de
entrada, a sala de reunião, a impressora, a garagem e o painel de
configuração. Cada pessoa tem um papel, visitante, membro ou admin, e o
papel dá um pacote de permissões. Só que a vida real tem exceções: o Bruno
é membro e aluga uma vaga na garagem; a Carla é membro e estourou a cota da
impressora. Você vai montar esse controle com os três temas do módulo:
precedência, sinal e VLA.

Cada permissão vira um **bit** de um `unsigned`: `ENTRAR` é `1u << 0`,
`REUNIAO` é `1u << 1`, `IMPRIMIR` é `1u << 2`, e assim por diante. Um
conjunto de permissões é um número em que cada bit ligado é uma permissão
concedida. As três operações de conjunto viram operadores bit a bit
(DEITEL; DEITEL, 2011, cap. 10). Ligar uma permissão é `p | IMPRIMIR`.
Apagar é `p & ~IMPRIMIR`: o `~` inverte todos os bits da máscara, e o `&`
mantém tudo menos o bit da impressora. Testar é `p & IMPRIMIR`, que dá
diferente de zero se o bit estiver ligado.

O papel vira um **enum**, `VISITANTE`, `MEMBRO` e `ADMIN`, que valem 0, 1
e 2. Esses números servem de índice para o vetor `base`, que guarda o
pacote de cada papel na mesma ordem do enum (KERNIGHAN; RITCHIE, 1988,
cap. 2). A struct `Usuario` guarda o papel e duas máscaras de exceção:
`extra`, o que a pessoa ganhou além do papel, e `bloqueio`, o que ela
perdeu mesmo que o papel dê.

A permissão efetiva de cada pessoa sai de uma única expressão:

`(base[u->papel] | u->extra) & ~u->bloqueio`

Leia de dentro para fora. O `|` junta o pacote do papel com os extras; os
parênteses são necessários porque o `&` tem precedência maior que o `|`, e
sem eles o `&` agarraria o `u->extra`. O `~`, do nível 2 da tabela, inverte
o bloqueio. O `&` final apaga da junção os bits bloqueados. Como o bloqueio
é aplicado por último, **o bloqueio vence**: a Carla, membro com a
impressora bloqueada, fica sem impressora mesmo que o pacote de membro a
inclua (DEITEL; DEITEL, 2011, cap. 10).

Perguntar "esta pessoa tem todas as permissões da máscara?" também pede
parênteses: `(efetivas & mascara) == mascara`. O `&` isola, das permissões
efetivas, só os bits que interessam; se o resultado é a máscara inteira,
nenhum bit falta. Os parênteses são obrigatórios porque o `==` tem
precedência maior que o `&`, a armadilha do assunto 0170 (CPPREFERENCE,
s.d.).

Todos os tipos de permissão são `unsigned`, e não por acaso. O `~` num
`int` daria um número negativo, e misturar com sinal e sem sinal numa
comparação abre a porta para o `-1 > 0u` do assunto 0171 (ISO/IEC, 2018).
Com tudo `unsigned`, os bits fazem exatamente o que parecem fazer.

Por fim, a planilha de acesso que o programa imprime, uma linha por pessoa
e uma coluna por permissão, é um **VLA** `bool acesso[n][QTD_PERMS]`, com
`n` guardado numa variável, como no assunto 0172. Cada casa recebe o
resultado de testar uma permissão de uma pessoa.

> [!WARNING]
> `efetivas(u) & mascara == mascara` é lido como
> `efetivas(u) & (mascara == mascara)`, isto é, `efetivas(u) & 1`: só olha
> o bit de ENTRAR (o gcc avisa). E `p = p | ~IMPRIMIR` no lugar de
> `p = p & ~IMPRIMIR` **liga todas as outras** permissões, sem aviso.

{{exemplo}}

Um coworking dá permissões por papel (visitante, membro, admin), com
exceções. A Carla é membro (`00111`) com a impressora bloqueada; o desenho faz
a conta bit a bit:

{{ideia}}

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

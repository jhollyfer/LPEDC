## 0179 · Sondagem quadrática e dupla

No endereçamento aberto do 0107, a tabela não tem listas: cada posição guarda
uma chave ou está livre. Quando a posição calculada já está ocupada, a chave
precisa de outro lugar, e você viu a resposta mais simples: tentar a posição
seguinte. Ela funciona, mas cria filas de chaves grudadas que deixam a tabela
lenta. A pergunta deste assunto é qual "outro lugar" tentar.

Pense num guarda-volumes com 13 armários. O funcionário escolhe o armário
pelo resto do número do cartão por 13; se estiver ocupado, segue uma regra
fixa para escolher o próximo. A lista de armários que ele tenta, em ordem, é
a **sequência de sondagem** da chave: `h(k, 0)`, `h(k, 1)`, `h(k, 2)` e assim
por diante, com `i` contando as tentativas. A inserção percorre essa
sequência e para na primeira posição livre. A busca refaz o mesmo caminho e
para quando acha a chave ou quando encontra uma posição livre, porque a chave
teria sido guardada ali (CORMEN et al., 2024, cap. 11).

A **sondagem linear** é a do 0107: `h(k, i) = (h'(k) + i) mod m`, com `h'(k)`
a posição inicial e `m` o tamanho da tabela. O defeito dela se chama
**agrupamento primário**. As posições ocupadas formam blocos contínuos, e
toda chave que cai em qualquer ponto de um bloco anda até o fim dele e o
aumenta em uma posição. Quanto maior o bloco, mais chaves ele atrai, e o
bloco cresce cada vez mais depressa (CORMEN et al., 2024, cap. 11).

A **sondagem quadrática** espalha os saltos: `h(k, i) = (h'(k) + c₁·i +
c₂·i²) mod m`, com `c₁` e `c₂` constantes. Com c₁ = 0 e c₂ = 1, a chave
tenta `h'(k)`, depois 1, 4, 9, 16 posições adiante. Uma chave que cai perto
de um bloco pula para longe dele em poucas tentativas, e os blocos se
desfazem. Sobra um defeito menor, o **agrupamento secundário**: duas chaves
com a mesma posição inicial seguem exatamente a mesma trilha. Com m = 13, os
cartões 31, 44 e 57 começam todos no armário 5 e tentam 5, 6, 9, 1, na mesma
ordem (TENENBAUM; LANGSAM; AUGENSTEIN, 1995). Com `m` primo, essa trilha
passa só por metade das posições, então a quadrática só garante achar lugar
se a tabela estiver com menos da metade ocupada.

A **dispersão dupla** (*double hashing*) resolve o secundário usando uma
segunda função hash para o tamanho do passo: `h(k, i) = (h₁(k) + i·h₂(k)) mod
m`. Duas chaves que começam no mesmo lugar quase sempre têm passos
diferentes e se separam já na segunda tentativa. De todas, é a que mais se
aproxima do hash uniforme ideal (CORMEN et al., 2024, cap. 11). No
guarda-volumes, com `h₂(k) = 1 + (k mod 12)`, o 31 anda de 8 em 8, o 44 de 9
em 9 e o 57 de 10 em 10.

O passo tem duas exigências. Ele nunca pode ser 0, senão a chave tenta a
mesma posição para sempre. E precisa ser **primo com m** (sem divisor comum
além de 1), para que a sequência passe por todas as posições antes de
repetir. Com `m` primo, a receita do Cormen é `h₁(k) = k mod m` e `h₂(k) = 1 +
(k mod (m - 1))`, que vai de 1 a m - 1. Com `m = 2^p`, basta um `h₂` que
sempre dê ímpar (CORMEN et al., 2024, cap. 11).

O custo de todas depende do **fator de carga** `α = n / m`, a fração da
tabela que está ocupada. Supondo hash uniforme, uma busca **sem sucesso** faz
em média no máximo `1 / (1 - α)` sondagens, e uma busca **com sucesso**, no
máximo `(1/α) · ln(1 / (1 - α))`. Com a tabela pela metade (α = 0,5), isso dá
2 e 1,4; com 90% ocupada (α = 0,9), dá 10 e 2,6 (CORMEN et al., 2024, cap.
11). A linear fica bem acima desses números quando a carga sobe, por causa do
agrupamento primário.

Falta a remoção, que vale para as três. Se você apaga uma chave e marca a
posição como livre, quebra a busca de quem passou por ali: uma chave que
pulou essa posição para ser guardada mais adiante deixa de ser achada, porque
a busca para na posição livre. Por isso a remoção deixa uma **lápide**
(*tombstone*), uma marca de "removido". A busca passa reto pela lápide; a
inserção pode reaproveitá-la (TENENBAUM; LANGSAM; AUGENSTEIN, 1995).

> [!WARNING]
> O passo `h₂(k)` **não pode ser 0** nem ter fator comum com `m`: com `m = 12`
> e passo 4, a chave visita só 3 posições. Na quadrática com carga acima de
> 1/2, a inserção pode falhar **com posições livres**.

{{exemplo}}

Um guarda-volumes de 13 armários usa `cartão % 13`, e os cartões 18, 31, 44,
20 e 57 entram nas três tabelas; quatro deles começam no armário 5. No
desenho, as posições que a busca do 57 olha:

{{ideia}}

A sequência de sondagem do `sondagem.c` (modo escolhido na criação):

```c
int sd_posicao(const Sondagem *t, int chave, int i) {
    int m = t->m;
    int h1 = chave % m;
    switch (t->modo) {
    case SD_LINEAR:
        return (h1 + i) % m;
    case SD_QUADRATICA:
        return (int)((h1 + (long)i * i) % m);
    default: { // dupla: o passo h2 depende da chave e nunca é 0
        int h2 = 1 + chave % (m - 1);
        return (int)((h1 + (long)i * h2) % m);
    }
    }
}
```

Inserção, busca e remoção chamam `sd_posicao(t, chave, i)`. O
guarda-volumes:

```c
#include <stdio.h>
#include "sondagem.h"

int main(void) {
    const char *nomes[] = {"linear:    ", "quadrática:", "dupla:     "};
    int cartoes[] = {18, 31, 44, 20, 57};
    printf("           ");
    for (int j = 0; j < 13; j++) {
        printf(" %3d", j);
    }
    printf("\n");
    for (int modo = 0; modo < 3; modo++) {
        Sondagem *t = sd_cria(13, (ModoSondagem)modo);
        if (t == NULL) {
            return 1;
        }
        int total = 0;
        for (int i = 0; i < 5; i++) {
            int s;
            sd_insere(t, cartoes[i], &s);
            total += s;
        }
        printf("%s", nomes[modo]);
        sd_mostra(t);
        int s;
        sd_busca(t, 57, &s);
        printf("            sondagens para guardar: %d | para achar o 57: %d\n", total, s);
        sd_libera(t);
    }
    return 0;
}
// Saída:
//               0   1   2   3   4   5   6   7   8   9  10  11  12
// linear:       .   .   .   .   .  18  31  44  20  57   .   .   .
//             sondagens para guardar: 13 | para achar o 57: 5
// quadrática:   .  57   .   .   .  18  31  20   .  44   .   .   .
//             sondagens para guardar: 11 | para achar o 57: 4
// dupla:       31  44  57   .   .  18   .  20   .   .   .   .   .
//             sondagens para guardar: 8 | para achar o 57: 2
```

Na linear, o 20 cai no meio do bloco e vai para o 8. Na quadrática, 31, 44 e
57 repetem a trilha 5, 6, 9, 1. Na dupla, cada um sai do 5 com um passo
diferente. O fluxograma é a inserção do 57 na dupla: `(5 + 10) % 13 = 2` está
livre:

{{fluxograma}}

## 0179 · Sondagem quadrática e dupla

O guarda-volumes do supermercado tem 13 armários. O armário de cada cliente
sai do número do cartão: `cartão % 13`. Se estiver ocupado, o funcionário
tenta outro. No 0107, "outro" era sempre o **seguinte** (sondagem linear). Num
sábado de movimento, cinco clientes chegam com os cartões 18, 31, 44, 20 e 57,
e quatro deles caem no armário 5. Qual é o melhor "outro"?

No endereçamento aberto, cada chave tem uma **sequência de sondagem**
`h(k, 0), h(k, 1), h(k, 2), ...`: a ordem em que ela tenta as posições. A
inserção para na primeira livre; a busca refaz o mesmo caminho até achar a
chave ou uma posição livre. O Cormen apresenta três sequências:

- **linear**: `h(k, i) = (h'(k) + i) mod m`. Simples e amiga da cache, mas
  sofre de **agrupamento primário**: as ocupadas formam blocos seguidos, e
  qualquer chave que cai **em qualquer ponto** do bloco vai para o fim dele e o
  aumenta. Quanto maior o bloco, mais chaves ele atrai;
- **quadrática**: `h(k, i) = (h'(k) + c₁·i + c₂·i²) mod m`. Aqui, com c₁ = 0
  e c₂ = 1, `(h'(k) + i²) mod m`: os saltos crescem (1, 4, 9, 16...) e os blocos
  se desfazem. Sobra o **agrupamento secundário**: duas chaves com o mesmo
  `h'(k)` seguem **a mesma trilha** inteira. E ela não visita todas as
  posições: com `m` primo, só metade. Por isso, mantenha a carga abaixo de 1/2;
- **dispersão dupla** (*double hashing*): `h(k, i) = (h₁(k) + i·h₂(k)) mod m`.
  O passo `h₂(k)` também depende da chave, então chaves que começam no mesmo
  lugar andam com passos diferentes. É a que mais se aproxima do hash
  uniforme ideal. O passo nunca pode ser 0 e tem que ser **primo com m** para
  visitar todas as posições: com `m` primo, `h₁(k) = k mod m` e
  `h₂(k) = 1 + (k mod (m - 1))`; com `m = 2^p`, um `h₂` sempre ímpar.

O **fator de carga** `α = n / m` manda no custo. Com hash uniforme, o Cormen
prova que uma busca **sem sucesso** faz no máximo `1 / (1 - α)` sondagens em
média, e uma **com sucesso**, no máximo `(1/α) · ln(1 / (1 - α))`. Com α = 0,5:
2 e 1,4. Com α = 0,9: 10 e 2,6. A linear fica bem pior que isso por causa dos
blocos (o A357 mede: 45 sondagens com α = 0,9).

A **remoção** vale para as três: a posição vira **lápide** (*tombstone*), nunca
livre. A busca passa reto pela lápide; a inserção pode reaproveitá-la. Se
virasse livre, cortaria o caminho de quem pulou por ela.

Os cinco cartões entram na mesma ordem em três tabelas,
uma de cada tipo, e depois o funcionário procura o 57. No desenho, as três
tabelas lado a lado e as posições que a busca do 57 olha:

{{ideia}}

O TAD é o `sondagem.h`, com o modo escolhido na criação. A sequência de
sondagem do `sondagem.c` é uma função só:

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

A inserção, a busca e a remoção só chamam `sd_posicao(t, chave, i)` para
`i = 0, 1, 2...`. O guarda-volumes:

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

Na linear, o 20 (que começa no 7, não no 5) cai no meio do bloco e vai para o
8: é o agrupamento primário. Na quadrática, 31, 44 e 57 repetem a trilha 5,
6, 9, 1: agrupamento secundário. Na dupla, o 31 anda de 8 em 8, o 44 de 9 em 9
e o 57 de 10 em 10: cada um sai do 5 para um lugar diferente.

O fluxograma segue a inserção do 57 na dispersão dupla. O 5 está
ocupado (não é livre nem lápide), `i` vira 1, e a posição `(5 + 10) % 13 = 2`
está livre:

{{fluxograma}}

> [!WARNING]
> Na dispersão dupla, o passo `h₂(k)` **não pode ser 0** (a sequência ficaria
> parada no mesmo lugar) nem ter fator comum com `m`. Com `m = 12` e passo 4,
> a chave só visita 3 das 12 posições e a inserção falha com a tabela quase
> vazia. Por isso o `+ 1` em `1 + k % (m - 1)` e por isso `m` primo. E na
> quadrática, com carga acima de 1/2, a inserção pode falhar **com posições
> livres na tabela** (o E1072 mostra): a sequência não passa por elas.

> [!TIP]
> **Por dentro do C:** cada `Posicao` tem 8 bytes (a chave e o estado), e a
> tabela inteira é um vetor contínuo. Na linear, as sondagens andam 8 bytes
> por vez e caem na mesma linha de cache de 64 bytes: oito sondagens custam
> uma ida à memória. Na quadrática e na dupla, cada sondagem pula para longe e
> costuma custar uma ida nova. É a troca de sempre: menos sondagens contra
> sondagens mais caras. E o `(long)i * i` tem motivo: com `m` grande, `i * i`
> em `int` pode estourar, e estouro de `int` é comportamento indefinido.

> [!NOTE]
> **Pergunta para você:** na tabela da dispersão dupla do exemplo, chega o
> cartão 70 (70 % 13 = 5, passo 1 + 70 % 12 = 11). Em que posição ele fica, e
> com quantas sondagens? E na linear?

{{pratique}}

## 0112 · Endereçamento aberto

O estacionamento de visitantes do condomínio tem 11 vagas, numeradas de 0 a
10. A regra da portaria: a vaga do carro é o número do apartamento com resto
por 11. Se a vaga estiver ocupada, você tenta a **próxima**. E a seguinte. Na
saída, o porteiro faz o mesmo caminho para achar o carro.

Essa é a segunda forma de tratar colisão: o **endereçamento aberto**. Não tem
lista nenhuma. Os itens ficam **dentro do próprio vetor**, e quem colide
procura outra posição livre na tabela, seguindo uma sequência fixa de
tentativas. Cada tentativa é uma **sondagem**.

A sequência mais simples é a **sondagem linear**: começa em `h = chave % m` e
anda uma casa por vez, dando a volta no fim: `i = (i + 1) % m`.

- **inserir**: sonda a partir de `h` até achar uma posição livre;
- **buscar**: sonda a partir de `h` até achar a chave (achou) ou uma posição
  **livre** (não está: se estivesse, teria parado ali);
- **remover**: é aqui que mora a pegadinha (o aviso abaixo explica).

Como tudo cabe no vetor, a tabela **enche**: `α = n / m` nunca passa de 1. E
fica lenta bem antes disso. Na sondagem linear, as ocupadas formam blocos
seguidos, e qualquer chave que cai num bloco vai parar no fim dele, deixando o
bloco ainda maior. Isso é o **agrupamento primário**. Com α = 0,5 uma busca
sem sucesso olha 2,5 posições em média; com α = 0,9, cerca de 50. A regra
prática: não passe de 70% a 75% de ocupação. Passou, crie uma tabela maior e
reinsira tudo.

Vamos ver na prática. Entram os carros dos apartamentos 101, 202, 301, 1104
e 504. O 101 vai para a vaga 2 e o 202 para a 4. O 301 também dá 4 (301 % 11
= 4), encontra a 4 ocupada e para na 5. O 1104 dá 4 de novo: tenta a 4, a 5,
e para na 6. O 504 vai direto para a 9. Na busca pelo 1104, o porteiro refaz
o mesmo caminho: 3 sondagens:

{{ideia}}

O TAD segue o padrão de sempre: `aberta.h` com a interface, `aberta.c` com o
vetor de vagas, cada uma com um **estado**: `LIVRE`, `OCUPADA` ou `REMOVIDA`.
A busca, dentro do `aberta.c`, é este laço:

```c
// anda a partir de chave % m até achar a chave ou uma posição LIVRE;
// passa reto pelas REMOVIDAS. Devolve a posição da chave ou -1.
static int procura(const Aberta *t, int chave, int *sondagens) {
    int i = chave % t->m;
    int olhadas = 0;
    for (int passo = 0; passo < t->m; passo++) {
        olhadas++;
        if (t->v[i].estado == LIVRE) {
            break; // a corrente de tentativas acaba aqui
        }
        if (t->v[i].estado == OCUPADA && t->v[i].chave == chave) {
            if (sondagens != NULL) {
                *sondagens = olhadas;
            }
            return i;
        }
        i = (i + 1) % t->m; // a próxima, dando a volta no fim
    }
    if (sondagens != NULL) {
        *sondagens = olhadas;
    }
    return -1;
}
```

E o programa do condomínio (exemplo A223):

```c
#include <stdio.h>
#include "aberta.h"

int main(void) {
    Aberta *vagas = aberta_cria(11);
    if (vagas == NULL) {
        return 1;
    }
    int aptos[] = {101, 202, 301, 1104, 504};
    int horas[] = {7, 8, 8, 9, 10};
    for (int i = 0; i < 5; i++) {
        int s;
        int vaga = aberta_insere(vagas, aptos[i], horas[i], &s);
        printf("apto %4d: hash %d -> vaga %d, sondagens: %d\n", aptos[i], aptos[i] % 11, vaga, s);
    }
    aberta_mostra(vagas);

    int hora, s;
    if (aberta_busca(vagas, 1104, &hora, &s)) {
        printf("1104 entrou às %dh, sondagens: %d\n", hora, s);
    }
    if (!aberta_busca(vagas, 303, &hora, &s)) {
        printf("303 não está, sondagens: %d\n", s);
    }
    aberta_libera(vagas);
    return 0;
}
// Saída:
// apto  101: hash 2 -> vaga 2, sondagens: 1
// apto  202: hash 4 -> vaga 4, sondagens: 1
// apto  301: hash 4 -> vaga 5, sondagens: 2
// apto 1104: hash 4 -> vaga 6, sondagens: 3
// apto  504: hash 9 -> vaga 9, sondagens: 1
// [ 0] -
// [ 1] -
// [ 2] 101
// [ 3] -
// [ 4] 202
// [ 5] 301
// [ 6] 1104
// [ 7] -
// [ 8] -
// [ 9] 504
// [10] -
// 1104 entrou às 9h, sondagens: 3
// 303 não está, sondagens: 2
```

Repara no fluxograma da busca: são duas perguntas por vaga. "Está livre?"
encerra a busca sem sucesso; "é o carro?" encerra com sucesso. Se nenhuma das
duas, anda uma vaga. O 1104 passa duas vezes pelo laço (vagas 4 e 5) e é
achado na 6. O 303 começa na 6, não é ele, e para na 7, livre:

{{fluxograma}}

> [!WARNING]
> Remover **não** é marcar a posição como livre. Se o carro do 301 sai e a
> vaga 5 volta a ser `LIVRE`, a busca pelo 1104 começa na 4, vê a 5 livre e
> conclui "não está", embora ele esteja na 6. A vaga livre corta o caminho de
> quem tinha pulado por ela. A solução é uma terceira marca, **removida**
> (lápide, *tombstone*): a busca passa reto por ela, e a inserção pode
> reaproveitá-la. O exemplo A224 mostra isso. O custo: com muitas remoções, as
> lápides acumulam e as buscas sem sucesso ficam longas, até você reconstruir
> a tabela.

> [!TIP]
> **Por dentro do C:** cada `Vaga` tem `chave`, `valor` e `estado`: 3 × 4 =
> 12 bytes, e as 11 vagas são **um bloco só** de 132 bytes. Sem `malloc` por
> item, sem ponteiro `prox`, sem nó espalhado pelo heap. Andar para a próxima
> vaga é andar 12 bytes na memória, e o processador já trouxe as vizinhas para
> a cache junto com a primeira. Por isso o endereçamento aberto costuma ganhar
> do encadeamento na prática, mesmo fazendo mais sondagens. O `dict` do Python
> e o `HashMap` do Rust usam endereçamento aberto (com sondagens mais
> espertas que a linear).

> [!NOTE]
> **Pergunta para você:** depois dos 5 carros, chega o do apartamento 1203
> (1203 % 11 = 4). Em qual vaga ele para, e com quantas sondagens? E quantas
> sondagens custa, depois disso, buscar um apartamento que não está e que cai
> na vaga 4?

{{pratique}}

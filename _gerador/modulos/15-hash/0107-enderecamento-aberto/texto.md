## 0107 · Endereçamento aberto

O encadeamento resolve a colisão com listas, e cada item custa um `malloc`.
Existe outro caminho: guardar tudo dentro do próprio vetor e, quando o balde
está ocupado, procurar outro.

Pense no estacionamento de um condomínio com 11 vagas. A vaga de cada carro é o
número do apartamento com resto por 11. Se a vaga está ocupada, o motorista
tenta a seguinte, e assim por diante. Na saída, o porteiro refaz o mesmo
caminho para achar o carro. Esse é o **endereçamento aberto**: não há lista, os
itens moram **dentro do vetor**, e quem colide tenta outras posições numa
sequência fixa. Cada tentativa se chama **sondagem** (CORMEN et al., 2024, cap. 11).

A sequência mais simples é a **sondagem linear**. Ela começa em
`i = chave % m` e anda uma casa por vez; ao passar da última posição, volta para
a primeira, e por isso o passo é `i = (i + 1) % m`. Na notação do Cormen, a
tentativa número `i`, contada a partir de 0, olha a posição
`h(k, i) = (h'(k) + i) mod m`, sendo `h'` a função hash comum (CORMEN et al.,
2024, cap. 11). Com `m = 11`, a chave 301 começa na posição 4; se a 4 está
ocupada, tenta a 5, depois a 6.

Trocando o passo, nascem outras sondagens. A **sondagem quadrática** pula
distâncias que crescem com o quadrado da tentativa,
`(h'(k) + c₁i + c₂i²) mod m`, com `c₁` e `c₂` constantes. A **dispersão dupla**
usa uma segunda função hash para decidir o tamanho do pulo,
`(h₁(k) + i · h₂(k)) mod m`, e fica para o assunto 0179 (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 7).

As operações seguem a sequência de sondagens. **Inserir** sonda até achar uma
posição livre e grava ali. **Buscar** sonda até achar a chave ou até cair numa
posição **livre**. Parar na livre é seguro: se a chave existisse, a inserção
teria parado nessa vaga ou antes dela (ZIVIANI, 2010, cap. 5).

**Remover** é onde mora a pegadinha. Se você esvazia a vaga, quebra a
sequência de quem passou por ela para chegar mais longe. A solução é uma
terceira marca, além de livre e ocupada: **removida**, chamada de **lápide**
(*tombstone*; no Cormen, `DELETED`). A busca passa reto pela lápide, como se a
vaga estivesse ocupada, e a inserção pode reaproveitá-la (CORMEN et al., 2024,
cap. 11). Com muitas lápides, as buscas sem sucesso ficam longas até a tabela
ser reconstruída.

Ao contrário do encadeamento, aqui a tabela **enche**: `α = n / m` nunca passa
de 1, e ela fica lenta bem antes disso. As posições ocupadas formam blocos
contínuos, e toda chave que cai num bloco vai parar no fim dele, aumentando o
bloco. É o **agrupamento primário**, e ele piora rápido. Com sondagem linear e
α = 0,5, uma busca sem sucesso olha em média 2,5 posições; com α = 0,9, cerca
de 50 (KNUTH, 1998, seção 6.4).

Por isso, quando a ocupação passa de 70% a 75%, crie uma tabela maior e
reinsira tudo nela (exemplo A213). Mesmo com esse cuidado, o endereçamento
aberto costuma ganhar do encadeamento na prática: as vagas formam um bloco só
de memória, sem `malloc` por item, e andar para a vaga seguinte aproveita a
cache do processador, a memória rápida que guarda os bytes vizinhos do que
você acabou de ler (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).

> [!WARNING]
> Remover **não** é marcar a posição como livre. Se a vaga 5 (do 301) volta a
> `LIVRE`, a busca pelo 1104 começa na 4, vê a 5 livre e conclui "não está",
> embora ele esteja na 6. Use a lápide (exemplo A214).

{{exemplo}}

O estacionamento do condomínio tem 11 vagas, e a vaga é o apartamento com
resto por 11. O 301 dá 4, ocupada, e para na 5; o 1104 tenta 4, 5 e para na
6. Buscar o 1104 custa 3 sondagens:

{{ideia}}

O TAD é `aberta.h` (interface) e `aberta.c` (vetor de vagas, cada uma com
**estado** `LIVRE`, `OCUPADA` ou `REMOVIDA`). A busca é este laço:

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

O programa do condomínio:

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

No fluxograma, "está livre?" encerra sem sucesso e "é o carro?" encerra com
sucesso; senão, anda uma vaga. O 1104 é achado na 6; o 303 para na 7, livre:

{{fluxograma}}

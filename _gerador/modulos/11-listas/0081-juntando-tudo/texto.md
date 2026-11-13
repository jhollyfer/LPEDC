## 0081 · Juntando tudo

Abra um player de música. Você pula faixas para a frente e para trás, tira
uma da fila, liga o "repetir tudo" e, depois da última, a primeira volta a
tocar. Ao fechar o app, a playlist continua lá na próxima vez. Por trás
dessas ações estão quase todas as peças deste módulo, e montar o player é o
jeito de vê-las trabalhando juntas.

A playlist é uma fila de músicas com um marcador na que está tocando, como
o dedo que acompanha a lista de um cardápio. O programa a organiza como um
**TAD**, no molde do assunto 0074, dividido em `playlist.h` e `playlist.c`.
Quem usa o TAD vê só a struct `Musica`, com título, artista e duração em
segundos, e as operações: adicionar, remover, próxima, anterior, salvar. Os
nós ficam escondidos no `.c` (CELES; CERQUEIRA; RANGEL, 2016).

Dentro do `.c`, cada nó se chama `Faixa` e guarda uma `Musica` e duas setas,
`ant` e `prox`: é a lista dupla do assunto 0079. A `struct playlist` guarda
as duas pontas, `inicio` e `fim`, o `tamanho`, um `bool repetir` e um campo
novo, `atual`, que aponta para a faixa que toca agora (CELES; RANGEL, 2002).
Esse `atual` é um **cursor**: um ponteiro que marca uma posição da lista e
anda por ela conforme o usuário pede.

Cada operação reaproveita um assunto. **Adicionar** é a inserção no fim da
lista dupla, O(1) graças ao ponteiro `fim`. **Remover pelo título** é a busca
do assunto 0077, comparando com `strcmp`, seguida da remoção dupla, que
desvia as duas setas que chegam no nó. Há um cuidado a mais: se a faixa
removida era a atual, o cursor não pode ficar apontando para memória
liberada. Ele vai para a faixa seguinte, ou para a anterior se a removida
era a última.

**Próxima** e **anterior** movem o cursor por `prox` e `ant`. Com o
"repetir" ligado, elas dão a volta nas pontas, como numa lista circular
(assunto 0080). A volta inteira mora numa função só:

```c
const Musica *playlist_proxima(Playlist *p) {
    if (p->atual == NULL) return NULL;
    if (p->atual->prox != NULL) p->atual = p->atual->prox;
    else if (p->repetir) p->atual = p->inicio;  // dá a volta
    else return NULL;                           // fim da playlist
    return &p->atual->musica;
}
```

Repare que a lista **não** é circular: o `prox` do último continua `NULL`. A
volta é uma decisão da função, que olha o `repetir`. A vantagem é que
imprimir, liberar e salvar continuam com o "for de lista" de sempre, sem o
risco de laço infinito do anel.

**Salvar** e **carregar** usam o arquivo texto do módulo 09, com uma música
por linha no formato `titulo;artista;segundos`. Carregar lê cada linha com
`fgets` e separa os campos com `sscanf`, que é o `scanf` lendo de uma string.

Por fim, **para cada** permite ao cliente fazer algo com cada música, como
contar as mais longas, sem ver os nós. A função recebe um ponteiro para
função, que ela chama uma vez por música, e um `void *` com os dados extras
dessa função, como nos assuntos 0050 e 0051 (KERNIGHAN; RITCHIE, 1989).

Os tamanhos mostram o preço da organização. A `Musica` tem 40 + 30 bytes de
texto, 2 de preenchimento e 4 do `int`, 76 bytes. A `Faixa` soma mais 4 de
preenchimento e dois ponteiros, e `sizeof(Faixa)` dá 96. O `const Musica *`
que `playlist_proxima` devolve aponta para **dentro** de uma faixa, e fica
solto se essa faixa for removida depois.

> [!WARNING]
> `playlist_proxima(p)->titulo` acessa `NULL` quando a função devolve
> `NULL`, o que ocorre na última música com repetir desligado: guarde o
> ponteiro e teste antes de usar. Copie texto com
> `snprintf(destino, sizeof destino, "%s", origem)`, que corta em vez de
> estourar o vetor como o `strcpy`.

{{exemplo}}

Uma playlist de cinco músicas, 20:01 no total. Pulando duas, toca a terceira;
a "Asa Branca" sai, a playlist chega à última e, com repetir ligado, volta
para "Aquarela":

{{ideia}}

O "repetir" mora numa função:

```c
const Musica *playlist_proxima(Playlist *p) {
    if (p->atual == NULL) return NULL;
    if (p->atual->prox != NULL) p->atual = p->atual->prox;
    else if (p->repetir) p->atual = p->inicio;  // dá a volta
    else return NULL;                           // fim da playlist
    return &p->atual->musica;
}
```

```c
#include <stdio.h>
#include "playlist.h"

int main(void) {
    Playlist *viagem = playlist_cria();
    if (viagem == NULL) return 1;
    playlist_adiciona(viagem, "Aquarela", "Toquinho", 252);
    playlist_adiciona(viagem, "Asa Branca", "Luiz Gonzaga", 186);
    playlist_adiciona(viagem, "Mas Que Nada", "Jorge Ben", 182);
    playlist_adiciona(viagem, "Evidências", "Chitãozinho e Xororó", 279);
    playlist_adiciona(viagem, "Tempo Perdido", "Legião Urbana", 302);

    int total = playlist_duracao(viagem);
    printf("%d músicas, %d:%02d no total\n", playlist_tamanho(viagem), total / 60, total % 60);

    playlist_proxima(viagem);
    playlist_proxima(viagem);   // pulou duas: agora toca a 3ª
    playlist_imprime(viagem);

    playlist_remove(viagem, "Asa Branca");
    playlist_proxima(viagem);
    playlist_proxima(viagem);   // chegou na última
    if (playlist_proxima(viagem) == NULL) printf("fim da playlist\n");

    playlist_repetir(viagem, true);
    printf("repetir ligado, próxima: %s\n", playlist_proxima(viagem)->titulo);
    printf("anterior: %s\n", playlist_anterior(viagem)->titulo);

    playlist_libera(viagem);
    return 0;
}
// Saída:
// 5 músicas, 20:01 no total
//   1. Aquarela - Toquinho (4:12)
//   2. Asa Branca - Luiz Gonzaga (3:06)
// > 3. Mas Que Nada - Jorge Ben (3:02)
//   4. Evidências - Chitãozinho e Xororó (4:39)
//   5. Tempo Perdido - Legião Urbana (5:02)
// fim da playlist
// repetir ligado, próxima: Aquarela
// anterior: Tempo Perdido
```

Em "Tempo Perdido" não há próxima: com repetir desligado a função devolve
`NULL`; ligado, o `atual` volta ao início:

{{fluxograma}}

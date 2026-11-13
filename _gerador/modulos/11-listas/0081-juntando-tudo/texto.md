## 0081 · Juntando tudo

- **TAD playlist** (`playlist.h` e `playlist.c`): quem usa vê a struct
  `Musica` (título, artista, segundos) e as operações; os nós ficam
  escondidos no `.c` (CELES; CERQUEIRA; RANGEL, 2016).
- **Nó `Faixa`**: guarda uma `Musica`, `ant` e `prox`. A `struct playlist`
  guarda `inicio`, `fim`, `atual` (a que toca), `tamanho` e o `bool repetir`
  (CELES; RANGEL, 2002).
- **Adicionar**: inserção no fim da lista dupla (0079), O(1) com `fim`.
- **Remover pelo título**: busca com `strcmp` (0077) e remoção dupla. Se era
  a atual, o `atual` vai para a seguinte, ou para a anterior se era a última.
- **Próxima e anterior**: `prox` e `ant`. Com repetir ligado, dão a volta
  nas pontas como numa lista circular (0080).
- **Salvar e carregar**: arquivo texto (módulo 09), uma música por linha,
  `titulo;artista;segundos`, com `fgets` e `sscanf`.
- **Para cada**: recebe um ponteiro para função e um `void *` (0050 e 0051),
  sem expor os nós (KERNIGHAN; RITCHIE, 1989).
- **Não é circular**: o último `prox` continua `NULL`. A volta é decisão da
  função, então imprimir, liberar e salvar seguem com o `for` de sempre.

> [!WARNING]
> `playlist_proxima(p)->titulo` acessa `NULL` quando a função devolve
> `NULL`, o que ocorre na última música com repetir desligado: guarde o
> ponteiro e teste antes de usar.

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

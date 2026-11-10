## 0081 · Juntando tudo

Num player, você pula faixas, remove uma e, no "repetir tudo", a última volta à
primeira. Ele reúne o módulo: lista dupla, busca e remoção, um cursor e a
volta da lista circular.

O **TAD playlist** (`playlist.h` e `playlist.c`) esconde os nós: quem o usa vê
a struct `Musica` (título, artista, segundos) e as operações. No `.c`, cada nó
(`Faixa`) guarda uma `Musica`, `ant` e `prox`; a `struct playlist` guarda
`inicio`, `fim`, `atual` (a música que toca), `tamanho` e o `bool repetir`.
Cada peça do módulo aparece num lugar:

- **adicionar**: inserção no fim da lista dupla (0079), O(1) com `fim`;
- **remover pelo título**: busca com `strcmp` (0077) e remoção dupla. Se era
  a atual, o `atual` vai para a seguinte (ou a anterior, se era a última);
- **próxima** e **anterior**: `prox` e `ant`; com repetir ligado, dão a volta
  nas pontas como numa lista circular (0080);
- **salvar** e **carregar**: arquivo texto (módulo 09), uma música por linha,
  `titulo;artista;segundos`, com `fgets` e `sscanf`;
- **para cada**: recebe um ponteiro para função e um `void *` (0050 e 0051),
  sem expor os nós.

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

A lista **não** é circular: o último `prox` continua `NULL`. A volta é decisão
da função, então imprimir, liberar e salvar seguem com o `for` de sempre.

A playlist do exemplo tem cinco músicas, 20:01 no total. Pulando duas, toca a
terceira. Depois a "Asa Branca" sai, a playlist chega à última e, com repetir
ligado, a próxima volta para "Aquarela":

{{ideia}}

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

No fluxograma, em "Tempo Perdido" não há próxima: com repetir desligado a
função devolve `NULL`; ligado, o `atual` volta ao início:

{{fluxograma}}

O exemplo A162 grava a playlist em `playlist.txt`, carrega numa nova e usa
`playlist_para_cada` com um callback para contar as músicas longas.

> [!WARNING]
> `playlist_proxima(viagem)->titulo` acessa `NULL` se a função devolver
> `NULL`, o que ocorre com repetir desligado na última música: guarde o
> ponteiro e teste. Copie texto com `snprintf(destino, sizeof destino, "%s",
> origem)`: um título maior que 39 caracteres é cortado, em vez de estourar o
> vetor como no `strcpy`.

> [!TIP]
> **Por dentro do C:** a `Musica` tem 40 + 30 bytes de texto, 2 de
> preenchimento e 4 do `int`: 76 bytes. A `Faixa` soma 4 de preenchimento e
> dois ponteiros: `sizeof(Faixa)` dá 96. O `const Musica *` devolvido aponta
> para **dentro** da faixa e fica solto após o `playlist_remove` dela, como no
> vetor dinâmico (0075).

> [!NOTE]
> **Pergunta para você:** se o exemplo chamasse `playlist_remove(viagem,
> "Tempo Perdido")` logo depois do "fim da playlist", qual música passaria a
> tocar? E se a playlist tivesse só essa música?

{{pratique}}

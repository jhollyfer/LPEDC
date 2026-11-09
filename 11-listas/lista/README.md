<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 11 · Listas

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/11-listas/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1101** · ★☆☆ · Encaixar uma música no meio da playlist

A playlist da festa junina é uma lista sequencial: um vetor de 8 códigos
de música e um contador n. Escreva


```text
bool seq_insere(ListaSeq *l, int pos, int codigo)
```


que põe o código na posição pos (0 <= pos <= n), empurrando uma casa para
a direita os que estavam de pos em diante, e devolve false se a lista
estiver cheia ou se pos for inválida. Conte os deslocamentos numa variável
global. Faça, nesta ordem: insere(0, 10), insere(1, 30), insere(1, 20),
insere(0, 5) e insere(9, 99).


```text
Saída esperada:
[5 10 20 30]
Inserir na posição 9: recusado
Deslocamentos: 4
```

**Dicas:**

1. Empurre de trás para a frente: for (i = n; i > pos; i--) v[i] =
   v[i - 1]. Da frente para trás, você copiaria o mesmo valor em tudo.
2. pos == n é válido: é inserir no fim, sem deslocar ninguém.
3. Inserir na posição pos custa n - pos deslocamentos: O(n) no pior caso
   (pos = 0), O(1) no fim.
4. Resposta esperada: a saída acima (0 + 0 + 1 + 3 deslocamentos).

```bash
~/LPEDC/rodar 11-listas/lista/P1101.c
```

---

**Exercício P1102** · ★☆☆ · O itinerário do ônibus, parada por parada

O itinerário da linha 640 é montado na ordem em que as paradas são
cadastradas: 101, 205, 310, 412 e 520. Sem ponteiro para o último, cada
inserção no FIM precisa andar a lista até o último nó. Escreva


```text
No *insere_fim(No *inicio, int valor, int *visitados)
```


que devolve o (possivelmente novo) início e soma em *visitados quantos nós
percorreu para achar o último. Monte o itinerário, mostre-o, mostre o
total de nós visitados e libere tudo.


```text
Saída esperada:
101 -> 205 -> 310 -> 412 -> 520 -> NULL
Nós visitados: 10
```

**Dicas:**

1. Lista vazia é caso especial: o novo nó vira o início.
2. Senão: p = inicio; while (p->prox != NULL) p = p->prox; e conte cada
   nó por onde p passou (o próprio último incluído).
3. A k-ésima inserção visita k - 1 nós: 0 + 1 + 2 + 3 + 4 = 10. Para n
   paradas, n (n - 1) / 2: montar a lista assim é O(n²). Um ponteiro para
   o último deixa cada inserção O(1).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1102.c
```

---

**Exercício P1103** · ★☆☆ · Reajuste de preço achando o nó

A lista do hortifruti guarda código e preço de cada produto. Escreva


```text
Produto *busca(Produto *inicio, int codigo)
```


que devolve o ENDEREÇO do nó com aquele código (ou NULL). Com esse
ponteiro em mãos, o main muda o preço direto no nó, sem percorrer de novo.
Monte a lista inserindo no início os produtos (40, 6.00), (30, 8.50),
(20, 3.20) e (10, 12.00); reajuste o 30 em 10% e tente reajustar o 99.


```text
Saída esperada:
Antes:  10: 12.00 | 20: 3.20 | 30: 8.50 | 40: 6.00 |
Código 30: 8.50 -> 9.35
Código 99: não encontrado
Depois: 10: 12.00 | 20: 3.20 | 30: 9.35 | 40: 6.00 |
```

**Dicas:**

1. for (Produto *p = inicio; p != NULL; p = p->prox) if (p->codigo ==
   codigo) return p;
2. Quem recebe o ponteiro pode alterar p->preco: o nó é o mesmo que está
   na lista, não uma cópia.
3. Resposta esperada: a saída acima (8.50 * 1.10 = 9.35).

```bash
~/LPEDC/rodar 11-listas/lista/P1103.c
```

---

**Exercício P1104** · ★☆☆ · Quem desistiu da fila do restaurante

A fila de espera do restaurante é uma lista encadeada de nomes. Escreva


```text
Cliente *remove_nome(Cliente *inicio, const char *nome, bool *removeu)
```


que tira da lista o primeiro cliente com aquele nome (liberando o nó),
devolve o novo início e diz em *removeu se achou. Monte a fila Ana, Bia,
Caio, Duda (nesta ordem, inserindo no fim) e remova Bia, depois Ana,
depois Zeca, mostrando a fila depois de cada tentativa.


```text
Saída esperada:
Fila: Ana Bia Caio Duda
Sem Bia: Ana Caio Duda
Sem Ana: Caio Duda
Zeca não estava: Caio Duda
```

**Dicas:**

1. Ande com dois ponteiros: ant (o anterior) e p (o atual). Compare com
   strcmp(p->nome, nome) == 0.
2. Se o removido é o primeiro (ant == NULL), o início muda para
   p->prox. Senão, ant->prox = p->prox. Só depois, free(p).
3. Resposta esperada: a saída acima, sem vazamento no sanitizer.

```bash
~/LPEDC/rodar 11-listas/lista/P1104.c
```

---

**Exercício P1105** · ★☆☆ · Engatar o trem da tarde no da manhã em O(1)

Guardando o início, o fim e o tamanho da lista numa struct, inserir no fim
e concatenar duas listas custam O(1). Escreva:


```text
void insere_fim(Lista *l, int valor)
void concatena(Lista *a, Lista *b)   // passa os nós de b para o fim de
                                     // a; b fica vazia
```


Monte a com os vagões 1, 2 e 3 e b com 4 e 5. Mostre as duas, concatene,
mostre de novo e mostre o último de a (sem percorrer). Depois concatene
a com a b vazia (nada muda) e libere tudo.


```text
Saída esperada:
a: 1 -> 2 -> 3 -> NULL (3 nós)
b: 4 -> 5 -> NULL (2 nós)
a depois: 1 -> 2 -> 3 -> 4 -> 5 -> NULL (5 nós)
b depois: NULL (0 nós)
último de a: 5
a com b vazia: 1 -> 2 -> 3 -> 4 -> 5 -> NULL (5 nós)
```

**Dicas:**

1. typedef struct { No *inicio, *fim; int n; } Lista; começa com
   {NULL, NULL, 0}.
2. Em concatena: se b está vazia, nada a fazer. Se a está vazia, a
   recebe os ponteiros de b. Senão, a->fim->prox = b->inicio e
   a->fim = b->fim. Nos dois últimos casos, some os tamanhos e zere b.
3. Resposta esperada: a saída acima. Só a lista a é liberada no fim (os
   nós de b agora são dela).

```bash
~/LPEDC/rodar 11-listas/lista/P1105.c
```

---

**Exercício P1106** · ★☆☆ · O metrô nos dois sentidos

Uma linha de metrô vai e volta pelas mesmas estações: é uma lista dupla.
Escreva insere_fim para a lista dupla com início e fim, e duas funções de
impressão: uma do início para o fim (seguindo prox) e outra do fim para o
início (seguindo ant). Cadastre as estações Sé, Luz, Tiradentes e
Armênia (nesta ordem) e mostre a ida e a volta. Libere tudo no fim.


```text
Saída esperada:
Ida:   Sé -> Luz -> Tiradentes -> Armênia
Volta: Armênia -> Tiradentes -> Luz -> Sé
```

**Dicas:**

1. Cada nó tem ant e prox. No insere_fim: novo->ant = l->fim; novo->prox
   = NULL; se a lista não estava vazia, l->fim->prox = novo; senão,
   l->inicio = novo. No fim, l->fim = novo.
2. A volta começa em l->fim e anda com p = p->ant: O(n), sem pilha e sem
   recursão, que é o que a seta extra compra.
3. Para não sobrar " -> " no fim, imprima a seta ANTES de cada estação,
   menos da primeira.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1106.c
```

---

**Exercício P1107** · ★☆☆ · A roda-gigante do parque

As 6 cabines da roda-gigante formam uma lista circular: depois da 6 vem a
1. Cada nó guarda o número da cabine e quantas pessoas estão nela. A
lista é guardada pelo ponteiro para o ÚLTIMO nó. Escreva:


```text
No *insere_fim(No *ultimo, int cabine, int pessoas)  // devolve o novo último
int total_pessoas(const No *ultimo)
void mostra_a_partir(const No *ultimo, int cabine)   // dá uma volta
                                                      // começando nela
```


Cadastre as cabines 1 a 6 com 2, 4, 0, 3, 1 e 4 pessoas, mostre o total e
a volta começando na cabine 4. Libere tudo no fim.


```text
Saída esperada:
Total: 14 pessoas
A partir da 4: [4:3] [5:1] [6:4] [1:2] [2:4] [3:0]
```

**Dicas:**

1. Inserir no fim da circular: o novo aponta para o primeiro
   (ultimo->prox) e o antigo último aponta para o novo. Com a lista vazia,
   o novo aponta para si mesmo.
2. Percorrer uma volta: do { ... p = p->prox; } while (p != comeco);.
   O do-while garante que a primeira cabine é visitada.
3. Para liberar, quebre o círculo antes (ultimo->prox = NULL, depois de
   guardar o primeiro) e libere como uma lista comum.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1107.c
```

---

**Exercício P1108** · ★☆☆ · As senhas da farmácia e a memória

O painel da farmácia guarda as senhas numa lista. O programa mostra a
lista, chama (tira do início) duas senhas e libera o resto. A saída na
tela parece certa, mas o AddressSanitizer reclama: há DOIS erros de
propósito com a memória. Rode, leia o relatório (procure
"heap-use-after-free" e "detected memory leaks") e conserte os dois.


```text
Saída esperada:
Senhas: 41 -> 42 -> 43 -> 44 -> NULL
Chamou 41
Chamou 42
Senhas: 43 -> 44 -> NULL
```


(e nenhum relatório do sanitizer depois da saída)

**Dicas:**

1. Em libera: depois do free(p), o nó não é mais seu. Dá para ler p->prox?
2. Em chama: o nó tirado da lista ainda ocupa memória. Quem devolve?
3. Resposta esperada: em libera, guarde No *seguinte = p->prox ANTES do
   free(p). Em chama, guarde o nó antigo, avance o início e dê free no
   nó antigo. A saída fica igual à de cima, sem relatório.

```bash
~/LPEDC/rodar 11-listas/lista/P1108.c
```

---

**Exercício P1109** · ★☆☆ · A chamada em ordem alfabética

Os alunos vão chegando e entrando na lista de chamada, que precisa ficar
sempre em ordem alfabética. Escreva


```text
Aluno *insere_ordenado(Aluno *inicio, const char *nome)
```


que cria o nó e o encaixa no lugar certo (comparando com strcmp),
devolvendo o novo início. Insira Marcos, Ana, Teo, Bia e Lia, nesta ordem,
mostrando a lista depois de cada inserção. Libere tudo no fim.


```text
Saída esperada:
Marcos
Ana Marcos
Ana Marcos Teo
Ana Bia Marcos Teo
Ana Bia Lia Marcos Teo
```

**Dicas:**

1. Caso especial: lista vazia, ou o novo vem antes do primeiro
   (strcmp(nome, inicio->nome) < 0). Aí o novo vira o início.
2. Senão, ande com p enquanto p->prox != NULL e strcmp(p->prox->nome,
   nome) < 0. O novo entra entre p e p->prox.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1109.c
```

---

**Exercício P1110** · ★☆☆ · A playlist de trás para frente, no lugar

A playlist do treino é uma lista sequencial (vetor + tamanho). Escreva


```text
int seq_inverte(ListaSeq *l)
```


que inverte a ordem DENTRO do próprio vetor, trocando o primeiro com o
último, o segundo com o penúltimo e assim por diante, e devolve quantas
trocas fez.
Teste com a playlist de 7 músicas 11, 22, 33, 44, 55, 66, 77 e com uma
de 4 músicas 1, 2, 3, 4.


```text
Saída esperada:
[77 66 55 44 33 22 11] em 3 trocas
[4 3 2 1] em 2 trocas
```

**Dicas:**

1. Dois índices: i = 0 e j = n - 1. Troque v[i] com v[j] enquanto i < j,
   andando i para a frente e j para trás.
2. São n / 2 trocas (divisão inteira): com n ímpar, o do meio fica onde
   está. O custo é O(n) e a memória extra é O(1).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1110.c
```

## ★★☆ Para pensar

**Exercício P1111** · ★★☆ · Juntar dois rankings já em ordem decrescente

As notas das turmas A e B estão em listas CRESCENTES:


```text
a: 2 -> 5 -> 8 -> 9 -> NULL
b: 1 -> 5 -> 7 -> 10 -> 12 -> NULL
```


O mural precisa delas juntas, em ordem DECRESCENTE. Escreva


```text
No *intercala_decrescente(No *a, No *b)
```


que faz isso numa passada só, SEM criar nem liberar nó nenhum: a cada
passo, tire da frente de a ou de b o nó de menor valor e ponha-o no
INÍCIO da lista resultado. Libere o resultado no fim.


```text
Saída esperada:
a: 2 -> 5 -> 8 -> 9 -> NULL
b: 1 -> 5 -> 7 -> 10 -> 12 -> NULL
mural: 12 -> 10 -> 9 -> 8 -> 7 -> 5 -> 5 -> 2 -> 1 -> NULL
```

**Dicas:**

1. Inserir sempre no início inverte a ordem: se você tira os nós do
   menor para o maior, eles ficam do maior para o menor.
2. No laço: escolha o nó (No *menor), avance a ou b, e faça
   menor->prox = resultado; resultado = menor.
3. Quando uma lista acaba, continue tirando da outra (não dá para só
   "pendurar" o resto, porque ele está na ordem errada).
4. Resposta esperada: a saída acima. São n + m passos: O(n + m).

```bash
~/LPEDC/rodar 11-listas/lista/P1111.c
```

---

**Exercício P1112** · ★★☆ · O leitor de código de barras que repete

O leitor do caixa às vezes registra o mesmo produto duas vezes. A lista
de códigos lidos NÃO está em ordem: 7, 3, 7, 9, 3, 3, 1, 9. Escreva


```text
int remove_repetidos(No *inicio)
```


que deixa só a PRIMEIRA ocorrência de cada código, na ordem original, e
devolve quantos nós tirou (liberando cada um). Não use vetor auxiliar.


```text
Saída esperada:
antes:  7 -> 3 -> 7 -> 9 -> 3 -> 3 -> 1 -> 9 -> NULL
depois: 7 -> 3 -> 9 -> 1 -> NULL
4 leituras repetidas removidas
```

**Dicas:**

1. Para cada nó atual, percorra o RESTO da lista com um ponteiro q que
   olha sempre q->prox: se q->prox tem o mesmo valor do atual, desligue-o
   (q->prox = q->prox->prox) e libere; senão, avance q.
2. Depois de remover, NÃO avance q: o novo q->prox ainda não foi olhado.
3. O primeiro nó nunca sai (ele é sempre a primeira ocorrência), por isso
   a função não precisa devolver um novo início.
4. Custo: O(n²) comparações. Com a lista ordenada daria para fazer em
   O(n), porque os repetidos ficariam lado a lado.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1112.c
```

---

**Exercício P1113** · ★★☆ · Desengatar o k-ésimo vagão a partir do fim

O trem é uma lista simples e você não sabe o tamanho dele. Escreva


```text
No *remove_k_do_fim(No *inicio, int k, bool *ok)
```


que tira o k-ésimo nó contando do FIM (k = 1 é o último), percorrendo a
lista UMA vez só, e devolve o novo início (*ok diz se o nó existia).
Monte o trem 10, 20, 30, 40, 50 e remova, nesta ordem, com k = 2, k = 4 e
k = 5, mostrando o trem depois de cada tentativa.


```text
Saída esperada:
trem:  10 -> 20 -> 30 -> 40 -> 50 -> NULL
k = 2: 10 -> 20 -> 30 -> 50 -> NULL
k = 4: 20 -> 30 -> 50 -> NULL
k = 5: não existe
```

**Dicas:**

1. Dois ponteiros com distância k entre eles: primeiro avance "rapido" k
   nós. Se a lista acabar antes, o k-ésimo do fim não existe.
2. Depois ande "lento" (com o anterior dele, "ant") e "rapido" juntos até
   rapido == NULL. Nesse momento, lento é o k-ésimo do fim.
3. Se ant == NULL, o removido é o primeiro (foi o que aconteceu com k = 4
   na lista de 4 vagões).
4. Resposta esperada: a saída acima. Uma passada, O(n), memória O(1).

```bash
~/LPEDC/rodar 11-listas/lista/P1113.c
```

---

**Exercício P1114** · ★★☆ · Os contatos que vêm para a frente

A agenda do celular é uma lista dupla (com início e fim) com Ana, Bia,
Caio, Duda e Edu. Quem você procura muito deveria ficar no começo. A
heurística "mover para a frente": a cada busca bem-sucedida, o nó achado
sai de onde está e vai para o início. Escreva


```text
int busca_move(Agenda *ag, const char *nome)
```


que faz a busca sequencial, move o nó para a frente (se achou) e devolve
quantas comparações fez. Faça as buscas Duda, Duda, Edu, Duda e Ana,
mostrando a agenda depois de cada uma, e compare o total com o que a
mesma sequência custaria sem mover ninguém.


```text
Saída esperada:
Duda: 4 comparações | Duda Ana Bia Caio Edu
Duda: 1 comparações | Duda Ana Bia Caio Edu
Edu: 5 comparações | Edu Duda Ana Bia Caio
Duda: 2 comparações | Duda Edu Ana Bia Caio
Ana: 3 comparações | Ana Duda Edu Bia Caio
Total movendo: 15
Total sem mover: 18
```

**Dicas:**

1. Para tirar o nó p do lugar: se p->ant existe, p->ant->prox = p->prox;
   se p->prox existe, p->prox->ant = p->ant; se p era o fim, o fim vira
   p->ant. Depois ponha p no início (p->ant = NULL, p->prox = início...).
2. Se p já é o início, não mexa em nada.
3. Sem mover, cada busca custa a posição original + 1: 4 + 4 + 5 + 4 + 1.
   Para calcular isso, use um vetor com os nomes na ordem original.
4. Resposta esperada: a saída acima. É a ideia por trás de caches como o
   LRU: o que foi usado há pouco tende a ser usado de novo.

```bash
~/LPEDC/rodar 11-listas/lista/P1114.c
```

---

**Exercício P1115** · ★★☆ · Quem lava a louça (Josefo com nomes)

Depois do almoço de domingo, seis primos fazem uma roda: Ana, Bia, Caio,
Duda, Edu e Fê. Começando em Ana, contam 1, 2, 3, e quem disser "3" sai da
roda; a contagem recomeça do seguinte. O último que sobrar lava a louça.
Monte a roda como uma lista circular de nomes guardada pelo ÚLTIMO nó e
escreva


```text
No *elimina(No *ultimo, int k)
```


que mostra quem sai, na ordem, libera cada nó que sai e devolve o nó que
sobrou. Mostre o vencedor e libere esse último nó também.


```text
Saída esperada:
Saem: Caio Fê Duda Bia Edu
Lava a louça: Ana
```

**Dicas:**

1. Guarde ant = ultimo (o anterior do primeiro). Para contar k pessoas,
   avance ant k - 1 vezes: o que sai é ant->prox.
2. Para tirar: No *sai = ant->prox; ant->prox = sai->prox; free(sai). A
   contagem recomeça em ant->prox, sem mexer em ant.
3. Pare quando sobrar um só: ant->prox == ant.
4. Resposta esperada: a saída acima. São n - 1 eliminações de k passos:
   O(n · k).

```bash
~/LPEDC/rodar 11-listas/lista/P1115.c
```

---

**Exercício P1116** · ★★☆ · A agenda do consultório em vetor ordenado

Os horários marcados do dia ficam numa lista sequencial ORDENADA (em
minutos desde a meia-noite, num vetor de 10). Escreva:


```text
int ord_busca(const Agenda *a, int x, int *pos)
  busca binária: devolve 1 se achou (e *pos é onde está) ou 0 (e *pos é
  onde x deveria entrar para manter a ordem);
bool ord_insere(Agenda *a, int x)   // recusa repetido e agenda cheia
bool ord_remove(Agenda *a, int x)
```


As duas últimas usam ord_busca para achar a posição e depois deslocam os
itens do vetor. Insira 540, 600, 480, 720 e 600 (repetido), remova o 540
e procure o 720. Mostre os horários como hh:mm.


```text
Saída esperada:
Agenda: 08:00 09:00 10:00 12:00
10:00: horário ocupado
Sem 09:00: 08:00 10:00 12:00
12:00 está na posição 2
```

**Dicas:**

1. Na busca binária, quando o laço termina sem achar, ini é exatamente a
   posição de inserção: todos antes dela são menores que x.
2. Inserir na posição p: desloque v[p..n-1] uma casa para a direita (do
   fim para o começo). Remover: desloque v[p+1..n-1] uma casa para a
   esquerda (do começo para o fim).
3. Buscar é O(log n), mas inserir e remover continuam O(n) por causa do
   deslocamento. Essa é a troca da lista sequencial ordenada.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1116.c
```

---

**Exercício P1117** · ★★☆ · Pares na frente, sem mudar a ordem

As senhas do guichê chegaram nesta ordem: 7, 2, 9, 4, 4, 1, 6. O guichê
par vai atender primeiro, então as senhas pares devem vir antes das
ímpares, mas cada grupo mantendo a ordem de chegada (uma partição
ESTÁVEL). Escreva


```text
No *pares_primeiro(No *inicio)
```


que reorganiza a lista só religando os nós (sem malloc, sem free, sem
trocar valores) e devolve o novo início.


```text
Saída esperada:
antes:  7 -> 2 -> 9 -> 4 -> 4 -> 1 -> 6 -> NULL
depois: 2 -> 4 -> 4 -> 6 -> 7 -> 9 -> 1 -> NULL
```

**Dicas:**

1. Monte duas listas enquanto percorre: a dos pares e a dos ímpares,
   cada uma com ponteiro para o início e para o fim. Cada nó vai para o
   FIM da sua lista (é isso que mantém a ordem).
2. No fim, ligue o fim dos pares no início dos ímpares e ponha NULL no
   fim dos ímpares. Cuidado com as listas que ficarem vazias.
3. Resposta esperada: a saída acima. Uma passada: O(n).

```bash
~/LPEDC/rodar 11-listas/lista/P1117.c
```

---

**Exercício P1118** · ★★☆ · Desengatar o último vagão sem quebrar o trem

Numa lista simples, tirar o ÚLTIMO nó exige achar o PENÚLTIMO. A função
remove_ultimo abaixo tem DOIS erros de propósito: com 3 vagões o
sanitizer já acusa "heap-use-after-free" na impressão, e com 1 vagão só
ela derruba o programa. Conserte os dois para a saída ficar:


```text
Saída esperada:
Trem: 1 -> 2 -> 3 -> NULL
Saiu 3: 1 -> 2 -> NULL
Saiu 2: 1 -> NULL
Saiu 1: NULL
```

**Dicas:**

1. Depois do free(p->prox), para onde aponta o p->prox do penúltimo? E
   quem imprime a lista vai seguir essa seta...
2. Com um nó só, p->prox->prox lê o prox de NULL. Esse caso precisa ser
   tratado antes do laço, e nele o início muda (vira NULL).
3. Resposta esperada: trate inicio->prox == NULL à parte (guarde o valor,
   libere o nó e devolva NULL) e, depois do free, faça p->prox = NULL.

```bash
~/LPEDC/rodar 11-listas/lista/P1118.c
```

---

**Exercício P1119** · ★★☆ · O ranking da corrida em lista dupla

Os tempos da corrida de 5 km (em minutos) chegam fora de ordem: 58, 61,
55, 70 e 60. Guarde-os numa lista DUPLA com início e fim, sempre em ordem
crescente. Escreva


```text
void insere_ordenado(Ranking *r, int tempo)
```


tratando os quatro casos: lista vazia, novo antes do primeiro, novo
depois do último e novo no meio. Mostre o ranking depois de cada
inserção, do início para o fim, e no final mostre também do fim para o
início (o que confere se todas as setas ant ficaram certas).


```text
Saída esperada:
58
58 61
55 58 61
55 58 61 70
55 58 60 61 70
De trás para frente: 70 61 60 58 55
```

**Dicas:**

1. Ache o primeiro nó p com p->tempo > tempo (ou p == NULL). O novo entra
   ANTES de p: novo->prox = p e novo->ant = (p ? p->ant : r->fim).
2. Depois acerte os vizinhos: se novo->ant existe, novo->ant->prox =
   novo, senão r->inicio = novo; se p existe, p->ant = novo, senão
   r->fim = novo. Assim os quatro casos saem do mesmo código.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1119.c
```

---

**Exercício P1120** · ★★☆ · Girar a escala de plantão

A escala de plantão da semana é a lista 1 -> 2 -> 3 -> 4 -> 5. Girar k
posições para a direita leva os k últimos para a frente: com k = 2, fica
4 -> 5 -> 1 -> 2 -> 3. Escreva


```text
No *gira(No *inicio, int k)
```


que faz isso só religando nós (sem malloc, sem trocar valores) e devolve
o novo início. k pode ser maior que o tamanho: girar 7 numa lista de 5 é
o mesmo que girar 2. Aplique, um depois do outro, k = 2, k = 7 e k = 0.


```text
Saída esperada:
escala: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
k = 2:  4 -> 5 -> 1 -> 2 -> 3 -> NULL
k = 7:  2 -> 3 -> 4 -> 5 -> 1 -> NULL
k = 0:  2 -> 3 -> 4 -> 5 -> 1 -> NULL
```

**Dicas:**

1. Primeira passada: conte n e ache o último. Faça k = k % n; se der 0,
   devolva o início sem mexer.
2. Ligue o último no primeiro (a lista vira circular por um instante).
   Ande n - k nós a partir do último: esse nó é o novo último. O seguinte
   dele é o novo início; corte o círculo com novo_ultimo->prox = NULL.
3. Resposta esperada: a saída acima. O(n) e memória O(1).

```bash
~/LPEDC/rodar 11-listas/lista/P1120.c
```

## ★★★ Desafio

**Exercício P1121** · ★★★ · A agenda que sobrevive ao desligar

Uma lista encadeada some quando o programa acaba. Junte o módulo 11 com o
09: escreva uma agenda de contatos (nome e telefone, sem espaços) numa
lista ordenada por nome, que é salva num arquivo texto e carregada de
volta. Funções:


```text
Contato *insere(Contato *inicio, const char *nome, const char *fone)
Contato *remove_nome(Contato *inicio, const char *nome)
const Contato *busca(const Contato *inicio, const char *nome)
int salva(const Contato *inicio, const char *caminho)  // quantos gravou
Contato *carrega(const char *caminho, int *n)          // lista nova
```


No main: insira Rui (92)98100-0001, Ana (92)98100-0002,
Lia (92)98100-0003 e Bia (92)98100-0004; remova Lia; salve em
/tmp/p1121_agenda.txt, uma linha "nome fone" por contato; LIBERE a lista;
carregue numa lista nova, mostre-a e procure Bia. Apague o arquivo no fim.


```text
Saída esperada:
Agenda: Ana Bia Lia Rui
Sem Lia: Ana Bia Rui
Salvos: 3 contatos
Carregados: 3 contatos
Ana (92)98100-0002
Bia (92)98100-0004
Rui (92)98100-0001
Bia: (92)98100-0004
```

**Dicas:**

1. carrega lê com fscanf(arq, "%15s %19s", nome, fone) == 2 e chama
   insere para cada linha: a lista nova já nasce ordenada.
2. Como o arquivo foi salvo em ordem, dá para inserir sempre no fim (com
   um ponteiro para o último) e carregar em O(n) em vez de O(n²). Aqui,
   com 3 contatos, tanto faz; com 1 milhão, não.
3. Nada de ponteiro no arquivo: um endereço de memória não vale nada na
   próxima execução. Grave só os dados.
4. Resposta esperada: a saída acima, sem vazamento.

```bash
~/LPEDC/rodar 11-listas/lista/P1121.c
```

---

**Exercício P1122** · ★★★ · O malloc de brinquedo (first-fit)

Por baixo do malloc existe uma LISTA DE BLOCOS LIVRES. Simule uma memória
de 100 posições (endereços 0 a 99) com uma lista encadeada de blocos
livres {inicio, tamanho}, sempre em ordem de endereço. Escreva:


```text
int aloca(Bloco **livres, int tam)
  first-fit: usa o PRIMEIRO bloco livre com tamanho >= tam, tirando tam
  posições do começo dele (se sobrar zero, o bloco sai da lista).
  Devolve o endereço, ou -1 se nenhum bloco serve;
void desaloca(Bloco **livres, int ini, int tam)
  devolve o pedaço à lista, no lugar certo pela ordem de endereço, e
  FUNDE com o vizinho da esquerda e/ou da direita se encostarem.
```


Faça, nesta ordem, mostrando a lista de livres depois de cada operação:
aloca 30, aloca 20, aloca 25, desaloca o de 20, aloca 10, desaloca o de
30, desaloca o de 25, aloca 50, aloca 40. No fim, mostre o total livre e
o maior bloco, e libere a lista.


```text
Saída esperada:
aloca 30 -> 0 | livres: [30,100)
aloca 20 -> 30 | livres: [50,100)
aloca 25 -> 50 | livres: [75,100)
desaloca 30+20 | livres: [30,50) [75,100)
aloca 10 -> 30 | livres: [40,50) [75,100)
desaloca 0+30 | livres: [0,30) [40,50) [75,100)
desaloca 50+25 | livres: [0,30) [40,100)
aloca 50 -> 40 | livres: [0,30) [90,100)
aloca 40 -> falhou | livres: [0,30) [90,100)
Livre: 40 posições, maior bloco: 30
```

**Dicas:**

1. [a,b) quer dizer "de a até b - 1": o bloco {inicio 30, tamanho 20}
   aparece como [30,50).
2. Em desaloca, ache ant (o último bloco que começa antes de ini) e p (o
   primeiro depois). Se ant termina em ini, cresça ant; se o pedaço
   termina onde p começa, junte p também (e libere o nó de p).
3. O último "aloca 40" falha com 40 posições livres: é a FRAGMENTAÇÃO
   externa. Os blocos livres existem, mas nenhum é grande o bastante.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1122.c
```

---

**Exercício P1123** · ★★★ · Turmas e alunos: uma lista de listas

O cursinho guarda uma lista de TURMAS, e cada turma guarda a sua própria
lista de ALUNOS (em ordem alfabética). Escreva:


```text
Turma *matricula(Turma *turmas, const char *turma, const char *aluno)
  acha a turma (ou cria no FIM da lista de turmas) e insere o aluno em
  ordem; devolve o início da lista de turmas;
bool cancela(Turma *turmas, const char *turma, const char *aluno)
bool transfere(Turma *turmas, const char *aluno, const char *de,
               const char *para)
  NÃO cria nem libera nó: desliga o nó do aluno de uma turma e o encaixa
  na outra.
void libera_tudo(Turma *turmas)   // cada aluno de cada turma, e as turmas
```


Faça as matrículas (C, Bia), (Python, Ana), (C, Ana), (C, Caio),
(Python, Davi); mostre; transfira Caio de C para Python, cancele Ana em
Python; mostre de novo.


```text
Saída esperada:
C (3): Ana Bia Caio
Python (2): Ana Davi
--
C (2): Ana Bia
Python (2): Caio Davi
```

**Dicas:**

1. typedef struct aluno { char nome[16]; struct aluno *prox; } Aluno;
   typedef struct turma { char nome[16]; int n; Aluno *alunos;
   struct turma *prox; } Turma;
2. Escreva uma função auxiliar que encaixa um nó de aluno JÁ CRIADO na
   posição certa de uma lista. A matrícula cria o nó e chama essa função;
   a transferência desliga o nó e chama a mesma função.
3. libera_tudo tem dois laços: para cada turma, libere os alunos dela e
   só depois a turma (guardando o prox antes de cada free).
4. Resposta esperada: a saída acima, sem vazamento.

```bash
~/LPEDC/rodar 11-listas/lista/P1123.c
```

---

**Exercício P1124** · ★★★ · Inverter só um trecho da fila

Na fila do embarque, as pessoas das posições 3 a 6 (contando de 1) são uma
família que entrou na ordem errada. Escreva


```text
No *inverte_trecho(No *inicio, int a, int b)
```


que inverte só os nós das posições a até b (1 <= a <= b <= n), numa
passada, só religando nós, e devolve o novo início (que muda quando a ==
1). Na fila 1..8, aplique, um depois do outro, os trechos (3, 6), (1, 2)
e (7, 8).


```text
Saída esperada:
fila:   1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
(3, 6): 1 -> 2 -> 6 -> 5 -> 4 -> 3 -> 7 -> 8 -> NULL
(1, 2): 2 -> 1 -> 6 -> 5 -> 4 -> 3 -> 7 -> 8 -> NULL
(7, 8): 2 -> 1 -> 6 -> 5 -> 4 -> 3 -> 8 -> 7 -> NULL
```

**Dicas:**

1. Ande até o nó ANTES do trecho (antes, que é NULL se a == 1). O primeiro
   do trecho (prim) vai virar o último dele.
2. Inverta b - a + 1 nós como na inversão comum (ant, p, seg). No fim, p
   aponta para o primeiro nó DEPOIS do trecho e ant para o novo primeiro.
3. Religue as pontas: prim->prox = p; e antes->prox = ant (ou, se antes
   é NULL, o novo início é ant).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1124.c
```

---

**Exercício P1125** · ★★★ · A lista dupla com três setas esquecidas

A lista dupla abaixo compila sem aviso, e a impressão de ida até parece
certa, mas a volta sai errada e o sanitizer acusa "heap-use-after-free".
São TRÊS erros de propósito, todos de setas que deixaram de ser
atualizadas: um em insere_inicio e dois em remove_valor. Conserte os três.


```text
Saída esperada:
Ida:   1 2 3 4
Volta: 4 3 2 1
Depois de remover 4 e 1:
Ida:   2 3
Volta: 3 2
```

**Dicas:**

1. Na lista dupla, cada inserção ou remoção mexe em até QUATRO setas
   (prox e ant dos vizinhos) e nos ponteiros inicio e fim. Faça uma
   tabela: para cada caso (primeiro, último, meio), quais mudam?
2. Depois de insere_inicio, o antigo primeiro tem que apontar (ant) para
   o novo.
3. Ao remover o último, o fim tem que mudar. Ao remover o primeiro, o novo
   primeiro não pode continuar com ant apontando para o nó liberado.
4. Resposta esperada: em insere_inicio, if (l->inicio != NULL)
   l->inicio->ant = novo; em remove_valor, l->fim = p->ant quando p é o
   último, e p->prox->ant = p->ant sempre que p->prox existe.

```bash
~/LPEDC/rodar 11-listas/lista/P1125.c
```

---

**Exercício P1126** · ★★★ · Lista encadeada sem malloc (cursores)

Em sistemas embarcados (e em muita prova antiga), a lista encadeada vive
dentro de um VETOR: cada célula tem valor e o ÍNDICE da próxima (-1 é o
"NULL"). As células sem uso formam uma segunda lista, a dos LIVRES, de
onde se tira célula para inserir e para onde ela volta ao remover.


```text
typedef struct { int valor; int prox; } Celula;
typedef struct { Celula c[6]; int inicio; int livre; } Estatica;
```


Escreva inicializa (todas livres: 0 -> 1 -> ... -> 5 -> -1, lista vazia),
bool insere_ordenado(Estatica *l, int x) (false se não há célula livre),
bool remove_valor(Estatica *l, int x) e mostra. Faça: insere 30, 10, 20;
mostre; remove 10; mostre; insere 25, 5, 40, 50; mostre; tente inserir
60; e mostre a tabela das células.


```text
Saída esperada:
lista: 10 20 30 | início 1, livre 3
lista: 20 30 | início 2, livre 1
lista: 5 20 25 30 40 50 | início 3, livre -1
60: sem célula livre
célula 0: 30 -> 4
célula 1: 25 -> 0
célula 2: 20 -> 1
célula 3: 5 -> 2
célula 4: 40 -> 5
célula 5: 50 -> -1
```

**Dicas:**

1. Pegar célula: i = l->livre; l->livre = l->c[i].prox. Devolver célula
   i: l->c[i].prox = l->livre; l->livre = i. A lista de livres funciona
   como uma pilha.
2. A inserção ordenada é a mesma da lista com ponteiros, trocando p->prox
   por l->c[p].prox e NULL por -1.
3. Repare na célula 1: o 10 saiu e o 25 reaproveitou a mesma célula.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1126.c
```

---

**Exercício P1127** · ★★★ · Dividir a ciranda em duas rodas

A ciranda da escola é uma lista circular guardada pelo ÚLTIMO nó. Ela
ficou grande demais e precisa virar duas rodas: a primeira com a metade
da frente (com n ímpar, ela fica com um a mais) e a segunda com o resto,
cada uma circular de novo. Escreva


```text
void divide(No *ultimo, No **ultimo1, No **ultimo2)
```


que faz isso numa passada, só religando nós, com a técnica do lento e do
rápido (o rápido anda dois passos por vez). Teste com as rodas 1..7 e
1..6, mostrando cada metade e confirmando que o último de cada uma aponta
para o primeiro dela.


```text
Saída esperada:
roda de 7: 1 2 3 4 5 6 7
  metade 1: 1 2 3 4 (o 4 aponta para o 1)
  metade 2: 5 6 7 (o 7 aponta para o 5)
roda de 6: 1 2 3 4 5 6
  metade 1: 1 2 3 (o 3 aponta para o 1)
  metade 2: 4 5 6 (o 6 aponta para o 4)
```

**Dicas:**

1. Comece lento e rápido no primeiro (ultimo->prox). Avance enquanto
   rapido->prox e rapido->prox->prox não forem o primeiro.
2. Com n par, o rápido para no penúltimo: dê mais um passo com ele. Agora
   lento é o último da metade 1 e rápido é o último da metade 2.
3. Religue: rapido->prox = lento->prox (fecha a metade 2) e
   lento->prox = primeiro (fecha a metade 1).
4. Resposta esperada: a saída acima. Com n = 1, a metade 2 fica vazia
   (NULL); trate esse caso também.

```bash
~/LPEDC/rodar 11-listas/lista/P1127.c
```

---

**Exercício P1128** · ★★★ · A esteira do sushi em ordem de preço

Os pratos da esteira do restaurante giram em círculo e ficam em ordem de
preço: do mais barato até o mais caro, e depois do mais caro volta o
mais barato. A esteira é uma lista circular guardada pelo ÚLTIMO nó (o
prato mais caro). Escreva


```text
No *insere_ordenado(No *ultimo, int preco)
```


que encaixa o prato no lugar certo e devolve o (possivelmente novo)
último. Ponha, nesta ordem, pratos de 30, 10, 50, 20, 40, 60 e 5 reais,
mostrando a esteira (do primeiro ao último) depois de cada um.


```text
Saída esperada:
30 | último: 30
10 30 | último: 30
10 30 50 | último: 50
10 20 30 50 | último: 50
10 20 30 40 50 | último: 50
10 20 30 40 50 60 | último: 60
5 10 20 30 40 50 60 | último: 60
```

**Dicas:**

1. Esteira vazia: o novo aponta para si mesmo e é o último.
2. Se o preço é >= ao do último, o novo entra DEPOIS do último e vira o
   novo último. Isso cobre o "mais caro de todos".
3. Senão, ande p a partir do último enquanto p->prox->preco <= preco e
   encaixe depois de p. O laço sempre para, porque o último é mais caro.
   O "mais barato de todos" cai aqui: entra logo depois do último, sem
   mudar quem é o último.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 11-listas/lista/P1128.c
```

---

**Exercício P1129** · ★★★ · Palíndromo com memória O(1)

O código do bilhete premiado da quermesse é um palíndromo (lê-se igual
nos dois sentidos). Os dígitos estão numa lista SIMPLES. Escreva


```text
bool palindromo(No *inicio)
```


sem vetor, sem pilha e sem lista nova: ache o meio (lento e rápido),
INVERTA a segunda metade, compare as duas metades andando juntas e, no
fim, desinverta a segunda metade para devolver a lista como estava.
Teste com 1 2 3 2 1, 4 7 7 4, 1 2 3 1 e 9, mostrando a lista depois do
teste (para provar que ela foi restaurada).


```text
Saída esperada:
1 2 3 2 1: sim | depois: 1 2 3 2 1
4 7 7 4: sim | depois: 4 7 7 4
1 2 3 1: não | depois: 1 2 3 1
9: sim | depois: 9
```

**Dicas:**

1. Lento e rápido começam no início; enquanto rapido->prox e
   rapido->prox->prox existirem, lento anda 1 e rápido anda 2. A segunda
   metade começa em lento->prox.
2. Inverta a partir de lento->prox (a inversão comum, que devolve o novo
   início) e guarde esse início. Compare com a primeira metade até a
   segunda acabar.
3. Restaure com lento->prox = inverte(inicio_da_segunda). Com n ímpar, o
   nó do meio fica na primeira metade e não precisa ser comparado.
4. Resposta esperada: a saída acima. O(n) de tempo, O(1) de memória.

```bash
~/LPEDC/rodar 11-listas/lista/P1129.c
```

---

**Exercício P1130** · ★★★ · Somar matrizes esparsas

A planilha de estoque de 3 lojas x 5 produtos tem quase tudo zero. Uma
MATRIZ ESPARSA guarda só o que não é zero: cada linha é uma lista
encadeada de nós {coluna, valor}, em ordem crescente de coluna. Escreva:


```text
No *insere(No *linha, int coluna, int valor)   // em ordem de coluna
No *soma_linhas(const No *a, const No *b)
  cria uma lista nova com a soma, intercalando as duas linhas por
  coluna e DESCARTANDO os resultados que derem zero;
void mostra_densa(No *m[], int linhas, int colunas)  // com os zeros
```


Monte A e B pelos termos (linha, coluna, valor) e mostre A + B na forma
densa (cada número com "%3d") e quantos não nulos ela guarda.


```text
A: (0,1,5) (0,4,2) (1,0,3) (2,2,-4) (2,3,1)
B: (0,1,-5) (0,2,7) (1,0,1) (1,4,9) (2,3,2)
```



```text
Saída esperada:
  0  0  7  0  2
  4  0  0  0  9
  0  0 -4  3  0
Não nulos: 6 de 15
```

**Dicas:**

1. A matriz é um vetor de 3 ponteiros No *, um por linha, começando NULL.
2. soma_linhas é a intercalação de duas listas ordenadas: coluna menor
   entra sozinha; colunas iguais somam (e, se der 0, nada entra, como o
   5 + (-5) da linha 0). Use um ponteiro para o fim da lista nova.
3. A soma custa O(não nulos de A + não nulos de B), não O(linhas x
   colunas): é para isso que a matriz esparsa existe.
4. Resposta esperada: a saída acima. Libere as três matrizes.

```bash
~/LPEDC/rodar 11-listas/lista/P1130.c
```

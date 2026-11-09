<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 22 · Árvores e conjuntos avançados

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/22-arvores-avancadas/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P2201** · ★☆☆ · Quantos níveis tem o organograma?

O organograma da prefeitura está numa árvore geral guardada como
filho-esquerdo/irmão-direito: cada nó aponta para o PRIMEIRO filho e para
o PRÓXIMO irmão. Complete altura(r), que devolve o número de níveis
(uma árvore só com a raiz tem 1 nível; vazia, 0). O main já monta a
árvore e mostra a resposta.


```text
Prefeito
├── Saúde
│   ├── UBS Centro
│   └── UBS Norte
│       └── Farmácia
├── Educação
│   └── Creche
└── Obras
```



```text
Saída esperada:
Níveis: 4
```

**Dicas:**

1. A altura de r é 1 + a MAIOR altura entre os filhos. Os filhos são
   r->filho, r->filho->irmao, r->filho->irmao->irmao...
2. Um jeito curto: altura(r) = max(1 + altura(r->filho), altura(r->irmao)).
   O irmão está no mesmo nível, por isso não ganha o + 1.
3. Resposta esperada: 4 níveis (Prefeito, Saúde, UBS Norte, Farmácia).

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2201.c
```

---

**Exercício P2202** · ★☆☆ · Quem tem mais filhos

A árvore genealógica da família Saraiva está em filho-esquerdo/irmão-
direito. Escreva do zero o struct, a montagem (a mesma do main da
resposta, com as funções novo e filho) e a função mais_filhos(r, &max),
que percorre a árvore toda e devolve o nó com mais filhos (no empate, o
primeiro encontrado na pré-ordem). Mostre também quantos filhos cada
pessoa tem, em pré-ordem, com recuo de 2 espaços por nível.


```text
Raimundo: filhos Joana, Pedro, Rita
Joana: filhos Ana, Bruno
Pedro: filhos Caio, Davi, Elis, Fábio
Rita: filha Gabi
Elis: filha Helena
```



```text
Saída esperada:
Raimundo (3)
  Joana (2)
    Ana (0)
    Bruno (0)
  Pedro (4)
    Caio (0)
    Davi (0)
    Elis (1)
      Helena (0)
    Fábio (0)
  Rita (1)
    Gabi (0)
Mais filhos: Pedro, com 4
```

**Dicas:**

1. O número de filhos de r é o tamanho da lista r->filho, r->filho->irmao...
2. Na pré-ordem com recuo, chame mostra(r->filho, nivel + 1) para os
   filhos e mostra(r->irmao, nivel) para os irmãos.
3. Resposta esperada: Pedro, com 4 filhos.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2202.c
```

---

**Exercício P2203** · ★☆☆ · Vermelho com filho vermelho

Na rubro-negra do Cormen (a clássica, não a esquerdista), cada NÓ é
vermelho ou preto, e uma das regras é: um nó vermelho não tem filho
vermelho. O programa abaixo monta à mão duas árvores (V é vermelho, P é
preto) e chama sem_vv(r), que devia devolver 1 se a regra vale em toda a
árvore e 0 se algum vermelho tem filho vermelho (mostrando qual). Complete
sem_vv. As árvores estão escritas como raiz(esquerda, direita), com - no
lugar de um filho vazio:


```text
Árvore 1: 20P(10V(5P, 15P), 30V(25P, -))
Árvore 2: 20P(10P, 30V(25V, 40P))
```



```text
Saída esperada:
Árvore 1:
  regra vale
Árvore 2:
  30 vermelho tem filho vermelho
  regra quebrada
```

**Dicas:**

1. Árvore vazia: 1. Se r é vermelho e algum filho existe e é vermelho,
   mostre e devolva 0.
2. Senão, a resposta é sem_vv(esq) && sem_vv(dir).
3. Resposta esperada: a árvore 1 vale; na 2, o 30 vermelho tem o filho
   25 vermelho.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2203.c
```

---

**Exercício P2204** · ★☆☆ · A altura negra de cada caminho

Outra regra da rubro-negra: todo caminho de um nó até um NULL passa pelo
MESMO número de nós pretos. Esse número, contado a partir da raiz, é a
ALTURA NEGRA. Complete altura_negra(r): ela devolve a altura negra da
árvore (NULL conta 0 aqui) ou -1 se dois caminhos discordam. O main
testa as duas árvores (V vermelho, P preto, escritas como raiz(esquerda,
direita), com - no lugar de um filho vazio) e mostra o resultado.


```text
Árvore 1: 30P(15V(8P, 20P), 45P(-, 50V))
Árvore 2: 30P(15P(8P, -), 45P(40P, 50P))
```



```text
Saída esperada:
Árvore 1: altura negra 2
Árvore 2: altura negra -1
```

**Dicas:**

1. Calcule e = altura_negra(esq) e d = altura_negra(dir). Se algum for
   -1 ou e != d, devolva -1.
2. Senão, devolva e + (r é preto ? 1 : 0).
3. Resposta esperada: 2 na árvore 1; -1 na 2 (pela esquerda do 15 são 3
   pretos; pela direita do 15, só 2).

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2204.c
```

---

**Exercício P2205** · ★☆☆ · Quantas páginas a busca lê

O cartório guarda os números de protocolo numa árvore B com grau mínimo
t = 2 (cada nó tem de 1 a 3 chaves). Num disco, cada nó é uma PÁGINA, e
ler uma página é o que custa caro. O programa abaixo já insere os
protocolos 5, 10, 15, ..., 100. Escreva busca(x, k, &paginas): ela
procura k a partir do nó x, conta cada nó visitado e devolve 1 se achou.
Procure 40, 60, 42 e 100.


```text
Saída esperada:
Protocolo 40: achado (páginas lidas: 1)
Protocolo 60: achado (páginas lidas: 2)
Protocolo 42: não existe (páginas lidas: 4)
Protocolo 100: achado (páginas lidas: 4)
```

**Dicas:**

1. Em cada nó: (*paginas)++; ache o primeiro i com k <= chave[i]. Se
   i < n e chave[i] == k, achou.
2. Se não achou e o nó é folha, k não está na árvore; senão, desça para
   filho[i].
3. Resposta esperada: o 40 está na raiz (1 página) e o 60 no nível de
   baixo (2); o 42 não existe e o 100 está numa folha: 4 páginas cada, o
   número de níveis da árvore.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2205.c
```

---

**Exercício P2206** · ★☆☆ · O começo que todas têm

O professor de português escreveu no quadro as palavras da família de
"comer": comer, comida, comilão, comedor, comestível (sem acento, para a
trie de 'a' a 'z': comer, comida, comilao, comedor, comestivel). Qual o
MAIOR PREFIXO COMUM a todas? Escreva do zero uma trie (26 filhos e um
bool fim por nó) e a função prefixo_comum(r, buf): desça a partir da
raiz enquanto o nó tem EXATAMENTE um filho e não é fim de palavra,
anotando as letras. Mostre o resultado para as duas listas do main.


```text
Saída esperada:
comer, comida, comilao, comedor, comestivel: prefixo comum "com"
solar, sol, solteiro, soldado: prefixo comum "sol"
```

**Dicas:**

1. conta_filhos(n) percorre os 26 ponteiros. Se o nó tem 1 filho, ache
   qual (a letra 'a' + i) e desça.
2. Pare se o nó é fim de palavra: "sol" e "solar" têm prefixo comum
   "sol", e não "sola".
3. Resposta esperada: "com" para a primeira lista e "sol" para a
   segunda. Libere a trie no fim.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2206.c
```

---

**Exercício P2207** · ★☆☆ · As redes da comunidade

Na comunidade ribeirinha, 10 casas (0 a 9) estão ganhando internet por
rádio, e cada enlace liga duas casas. Escreva do zero um union-find com
UNIÃO POR POSTO (rank) e COMPRESSÃO DE CAMINHO: acha(x) devolve a raiz e
pendura todo o caminho direto nela; une(a, b) liga a raiz de posto menor
embaixo da de posto maior (no empate, a de b embaixo da de a, e o posto
de a sobe 1). Processe os enlaces e mostre quantas redes separadas
sobraram e as casas de cada uma.


```text
Enlaces: 0-1  2-3  1-4  5-6  3-7  4-8  6-9  0-8
```



```text
Saída esperada:
Redes: 3
  { 0 1 4 8 }
  { 2 3 7 }
  { 5 6 9 }
```

**Dicas:**

1. pai[i] = i e posto[i] = 0 no começo. Componentes começa em 10 e cai
   1 a cada une que junta duas raízes diferentes.
2. Para listar, percorra as raízes (pai[r] == r) e, para cada uma, as
   casas x com acha(x) == r.
3. Resposta esperada: 3 redes: {0 1 4 8}, {2 3 7} e {5 6 9}.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2207.c
```

---

**Exercício P2208** · ★☆☆ · A torre que o posto não deixa crescer

O union-find abaixo é o ingênuo: une(a, b) pendura a raiz de a embaixo da
raiz de b, sempre, e acha não comprime o caminho. Com as uniões une(0,
1), une(1, 2), ..., une(14, 15), a árvore vira uma fila de 16 andares.
Estenda o programa: escreva une_posto(a, b), com união por POSTO (rank)
e o mesmo acha sem compressão, rode as mesmas 15 uniões num segundo
vetor de pais e mostre a profundidade máxima (em arestas) nas duas
versões.


```text
Saída esperada:
Sem posto: profundidade máxima 15
Com posto: profundidade máxima 1
```

**Dicas:**

1. profundidade(pai, x) conta quantos passos x dá até a raiz. A máxima
   é o maior valor entre os 16 elementos.
2. Com posto, a raiz mais "alta" fica por cima. Aqui a árvore do 0 já tem
   posto 1 depois da primeira união, e cada elemento novo (posto 0) entra
   pendurado direto nela.
3. Resposta esperada: 15 sem posto e 1 com posto. Com posto, a altura
   nunca passa de lg n, mesmo sem compressão.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2208.c
```

---

**Exercício P2209** · ★☆☆ · O trabalho escondido da rubro-negra

A rubro-negra esquerdista (assunto 0145) mantém o equilíbrio com
rotações e inversões de cor. Quanto trabalho é isso? O programa abaixo
tem a inserção completa. Instrumente-o: conte as rotações à esquerda, as
rotações à direita e as inversões de cor ao inserir os códigos de 1 a
15, em ordem crescente (o pior caso de uma árvore de busca comum), e
mostre também a altura final (em nós).


```text
Saída esperada:
Raiz: 8
Rotações à esquerda: 11
Rotações à direita: 0
Inversões de cor: 11
Altura: 4 nós
```

**Dicas:**

1. Três contadores globais, um em cada função: rot_esq, rot_dir e
   inverte.
2. altura(r) = 0 para NULL; senão 1 + o maior entre os dois lados.
3. Resposta esperada: altura 4 (uma árvore de busca comum teria 15) e os
   contadores da saída; repare que em ordem crescente nenhuma rotação à
   direita acontece.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2209.c
```

---

**Exercício P2210** · ★☆☆ · A árvore B andar por andar

O programa abaixo insere os códigos 1 a 12, em ordem, numa árvore B de
grau mínimo t = 2. Para ver a forma da árvore, escreva mostra_niveis(r):
um percurso em LARGURA com uma fila de ponteiros (um vetor basta), que
mostra cada nó como [chaves] e põe cada nível numa linha.


```text
Saída esperada:
Nível 0: [4]
Nível 1: [2] [6 8 10]
Nível 2: [1] [3] [5] [7] [9] [11 12]
```

**Dicas:**

1. Fila: NoB *fila[64]; ini e fim. Para separar os níveis, guarde também
   o nível de cada nó (outro vetor) e quebre a linha quando ele mudar.
2. Ao tirar um nó que não é folha, ponha na fila os seus n + 1 filhos.
3. Resposta esperada: 3 níveis, com [4] na raiz e [2] e [6 8 10] embaixo.
   Todas as folhas ficam no mesmo nível: é a regra da árvore B.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2210.c
```

## ★★☆ Para pensar

**Exercício P2211** · ★★☆ · O fiscal completo da rubro-negra

Escreva do zero o fiscal da rubro-negra clássica (Cormen), que confere,
nesta ordem, as regras que fazem sentido num nó com cor: (1) é árvore de
busca (cada chave entre um mínimo e um máximo herdados); (2) a raiz é
preta; (3) nenhum vermelho tem filho vermelho; (4) todo caminho até um
NULL tem o mesmo número de pretos. Ele devolve o número da primeira
regra quebrada (0 se todas valem) e, se valem, a altura negra. Teste as
quatro árvores do main (raiz(esquerda, direita), - é vazio):


```text
A: 40P(20V(10P, 30P), 60V(50P, 70P))
B: 40P(20P(10V, 30V), 60P(50V, 45V))
C: 40V(20P, 60P)
D: 40P(20P(10P, -), 60P(50V, 70P))
```



```text
Saída esperada:
A: rubro-negra válida, altura negra 2
B: quebra a regra 1
C: quebra a regra 2
D: quebra a regra 4
```

**Dicas:**

1. Regra 1: busca_ok(r, min, max), com INT_MIN e INT_MAX de <limits.h>
   no começo; cada chave tem que ficar estritamente entre os limites.
2. Regras 3 e 4 juntas numa recursão que devolve a altura negra ou -1;
   separe as duas com um flag global para saber qual quebrou.
3. Resposta esperada: A vale (altura negra 2); B quebra a regra 1 (45 à
   direita de 60); C quebra a 2; D quebra a 4.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2211.c
```

---

**Exercício P2212** · ★★☆ · A árvore 2-3 escondida na rubro-negra

Toda rubro-negra esquerdista é uma árvore 2-3 desenhada com cores: um nó
com filho esquerdo VERMELHO é, junto com esse filho, um único nó 3 com
duas chaves. O programa abaixo insere 10, 20, ..., 90 numa LLRB.
Escreva mostra23(h, nivel), que percorre a LLRB e mostra a árvore 2-3
correspondente, em pré-ordem, com 2 espaços de recuo por nível: um nó 2
sai como [k]; um nó 3, como [a b], e seus três filhos são o esquerdo e o
direito do vermelho e o direito de h.


```text
Saída esperada:
[40]
  [20]
    [10]
    [30]
  [60 80]
    [50]
    [70]
    [90]
```

**Dicas:**

1. Se verm(h->esq): mostre [h->esq->chave h->chave] e desça em
   h->esq->esq, h->esq->dir e h->dir, todos com nivel + 1.
2. Senão, mostre [h->chave] e desça em h->esq e h->dir.
3. Resposta esperada: a 2-3 de cima. Repare que todas as folhas estão no
   mesmo nível: é o equilíbrio perfeito da 2-3 que garante a altura
   O(lg n) da rubro-negra.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2212.c
```

---

**Exercício P2213** · ★★☆ · Quantas divisões custa encher a árvore B

O programa abaixo tem a árvore B do assunto 0146 com o grau mínimo t
numa variável (até 4), e insere os códigos 1 a 40, em ordem. Estenda-o:
conte as DIVISÕES de nó, conte os nós da árvore pronta e calcule a altura
(em arestas), e rode para t = 2, 3 e 4.


```text
Saída esperada:
t = 2: 31 divisões, 36 nós, altura 4
t = 3: 15 divisões, 18 nós, altura 2
t = 4: 10 divisões, 13 nós, altura 2
```

**Dicas:**

1. Um contador global divisoes++ dentro de divide().
2. nos(x) = 1 + soma de nos dos filhos; a altura é quantas vezes dá para
   descer pelo filho[0] até uma folha.
3. Resposta esperada: com t maior, menos divisões, menos nós e uma
   árvore mais baixa (veja os números). É por isso que árvores B de
   disco usam t na casa das centenas.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2213.c
```

---

**Exercício P2214** · ★★☆ · O menor apelido de cada palavra

O sistema da biblioteca quer abreviar o nome de cada sala pelo MENOR
PREFIXO que não é prefixo de nenhuma outra. As salas são: acervo,
acesso, arquivo, auditorio, biblioteca, brinquedoteca. Escreva do zero
uma trie em que cada nó guarda passam, quantas palavras passam por ele.
O menor prefixo único de uma palavra termina no primeiro nó do caminho
com passam == 1.


```text
Saída esperada:
acervo: acer
acesso: aces
arquivo: ar
auditorio: au
biblioteca: bi
brinquedoteca: br
```

**Dicas:**

1. Na inserção, some 1 em passam de cada nó do caminho (sem contar a
   raiz).
2. Para cada palavra, desça letra a letra copiando para o buffer e pare
   depois de copiar a letra do nó com passam == 1. Se nenhum tiver 1 (a
   palavra é prefixo de outra), o apelido é a palavra inteira.
3. Resposta esperada: acer, aces, ar, au, bi, br.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2214.c
```

---

**Exercício P2215** · ★★☆ · Amizades e perguntas no aplicativo

Um aplicativo de caronas de Manaus tem 8 usuários (0 a 7). Ao longo do
dia chegam operações: "U a b" quer dizer que a e b viraram contatos;
"P a b" pergunta se a e b estão ligados por alguma corrente de contatos
(amigo de amigo de amigo...). Escreva do zero o union-find (posto e
compressão) e processe as operações NA ORDEM, respondendo cada pergunta
com o que se sabe naquele momento.


```text
U 0 1   U 2 3   P 0 3   U 1 2   P 0 3   U 4 5   P 3 5
U 6 7   U 5 6   P 4 7   U 3 4   P 0 7
```



```text
Saída esperada:
0 e 3: não
0 e 3: sim
3 e 5: não
4 e 7: sim
0 e 7: sim
```

**Dicas:**

1. Guarde as operações num vetor de structs { char tipo; int a, b; }.
2. A resposta de uma pergunta depende só das uniões feitas ANTES dela:
   por isso o union-find, que responde na hora, serve (uma busca em
   largura a cada pergunta também serviria, mas custaria O(n + m) cada).
3. Resposta esperada: não, sim, não, sim, sim.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2215.c
```

---

**Exercício P2216** · ★★☆ · As ilhas que surgem na vazante

Na vazante do rio, bancos de areia vão aparecendo numa área mapeada como
uma grade 4 × 5. Cada dia surge uma casa de areia nova, nesta ordem
(linha, coluna):


```text
(0,0) (0,1) (2,2) (1,4) (2,1) (1,1) (3,4) (2,4) (0,3) (1,3)
```


Duas casas de areia vizinhas na horizontal ou na vertical são a mesma
ilha. Depois de cada dia, quantas ilhas há? Escreva do zero: cada casa
(l, c) é o elemento l * 5 + c de um union-find; ao surgir uma casa, conte
+1 ilha e una com cada vizinha que já é areia (cada união de raízes
diferentes tira 1 ilha).


```text
Saída esperada:
Dia  1, areia em (0,0): 1 ilha(s)
Dia  2, areia em (0,1): 1 ilha(s)
Dia  3, areia em (2,2): 2 ilha(s)
Dia  4, areia em (1,4): 3 ilha(s)
Dia  5, areia em (2,1): 3 ilha(s)
Dia  6, areia em (1,1): 2 ilha(s)
Dia  7, areia em (3,4): 3 ilha(s)
Dia  8, areia em (2,4): 2 ilha(s)
Dia  9, areia em (0,3): 3 ilha(s)
Dia 10, areia em (1,3): 2 ilha(s)
```

**Dicas:**

1. Um vetor areia[20] marca quais casas já surgiram; só una com vizinhas
   marcadas.
2. Faça une devolver 1 quando juntou duas raízes diferentes e 0 quando
   já estavam juntas.
3. Resposta esperada: a contagem da saída, terminando com 2 ilhas.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2216.c
```

---

**Exercício P2217** · ★★☆ · O cardápio entre parênteses

O cardápio do restaurante está numa árvore geral (filho-esquerdo/irmão-
direito). Para mandar o cardápio por mensagem, o dono quer a árvore numa
linha só, no formato raiz(filho1 filho2 ...), em que cada filho que tem
filhos sai do mesmo jeito. Complete escreve(r).


```text
Cardápio
├── Entradas
│   ├── Caldo
│   └── Bolinho
├── Pratos
│   ├── Peixe
│   │   ├── Tambaqui
│   │   └── Pirarucu
│   └── Frango
└── Bebidas
```



```text
Saída esperada:
Cardápio(Entradas(Caldo Bolinho) Pratos(Peixe(Tambaqui Pirarucu) Frango) Bebidas)
```

**Dicas:**

1. Mostre o nome; se r->filho != NULL, abra "(", escreva os filhos (o
   primeiro, depois cada irmão, com um espaço entre eles) e feche ")".
2. Os irmãos são escritos por quem chamou (o laço do pai), não pela
   própria recursão do filho: escreve(r) só cuida de r e da subárvore
   dele.
3. Resposta esperada: a linha de cima.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2217.c
```

---

**Exercício P2218** · ★★☆ · Rotações com ponteiro para o pai

No Cormen, cada nó da rubro-negra tem também um ponteiro pai, e as
rotações precisam acertar seis ponteiros. Complete rot_esq(raiz, x) e
rot_dir(raiz, y), que giram em torno de x (ou y) e devolvem a raiz da
árvore toda (que muda se o nó girado era a raiz). O main monta a árvore
de busca de cima, faz rot_esq no 10, depois rot_dir no 20, e confere
depois de cada uma que o percurso em ordem não mudou e que todo filho
aponta de volta para o pai certo.


```text
10(5, 20(15, 30))
```



```text
Saída esperada:
Início: raiz 10, em ordem 5 10 15 20 30, pais OK
rot_esq(10): raiz 20, em ordem 5 10 15 20 30, pais OK
rot_dir(20): raiz 10, em ordem 5 10 15 20 30, pais OK
```

**Dicas:**

1. rot_esq(x): y = x->dir; x->dir = y->esq (e o pai desse filho vira x,
   se ele existe); y->pai = x->pai; ligue y no lugar de x (como raiz, ou
   como filho esquerdo ou direito do pai); y->esq = x; x->pai = y.
2. rot_dir é o espelho: troque esq por dir em todo lugar.
3. Resposta esperada: depois de rot_esq(10), a raiz é 20; depois de
   rot_dir(20), volta a ser 10. Em ordem sempre 5 10 15 20 30 e pais OK.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2218.c
```

---

**Exercício P2219** · ★★☆ · A agenda de ramais consistente

Na central telefônica da universidade, o aluno digita o ramal e a
ligação completa assim que os dígitos formam um ramal cadastrado. Por
isso a lista só é CONSISTENTE se nenhum ramal é prefixo de outro (se 911
e 91125 existem, ninguém consegue ligar para o 91125). É a mesma regra do
código livre de prefixo do Huffman. Escreva do zero uma trie de dígitos
(10 filhos) que, ao inserir cada ramal, detecta o problema nos dois
sentidos: o novo passa por um nó que já é fim de ramal, ou termina num
nó que já tem filhos. Teste as duas listas.


```text
Lista 1: 4012 4078 5231 40 7766
Lista 2: 3021 3304 4471 6650 4479
```



```text
Saída esperada:
Lista 1: inconsistente (conflito ao inserir 40)
Lista 2: consistente
```

**Dicas:**

1. insere devolve 0 se achou conflito: ao descer, se o nó atual é fim,
   conflito; ao terminar, se o nó tem algum filho, conflito.
2. Libere a trie de cada lista antes de testar a próxima.
3. Resposta esperada: a lista 1 é inconsistente (40 é prefixo de 4012 e
   4078; o conflito aparece ao inserir o 40) e a lista 2 é consistente.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2219.c
```

---

**Exercício P2220** · ★★☆ · O tamanho de sapato mais próximo

A sapataria guarda os números que tem em estoque numa rubro-negra
esquerdista: 34, 35, 37, 38, 40, 41, 43 e 45. Quando o cliente pede um
número que acabou, o vendedor oferece o PISO (o maior em estoque <= ao
pedido) e o TETO (o menor em estoque >= ao pedido). Complete piso(r, x) e
teto(r, x), que devolvem -1 quando não existe, usando a ordem da árvore
de busca: no piso, se x < chave, a resposta está à esquerda; se não, a
chave é candidata e talvez haja algo melhor à direita.


```text
Saída esperada:
Pedido 36: piso 35, teto 37
Pedido 33: piso nenhum, teto 34
Pedido 46: piso 45, teto nenhum
Pedido 40: piso 40, teto 40
Pedido 42: piso 41, teto 43
```

**Dicas:**

1. piso iterativo: melhor = -1; enquanto r != NULL: se r->chave == x,
   devolva x; se r->chave < x, melhor = r->chave e vá para a direita;
   senão, para a esquerda.
2. teto é o espelho.
3. Resposta esperada: para 36, piso 35 e teto 37; para 33 não há piso;
   para 46 não há teto; 40 está em estoque.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2220.c
```

## ★★★ Desafio

**Exercício P2221** · ★★★ · A rubro-negra que se fiscaliza

Escreva do zero uma rubro-negra esquerdista completa (inserção com
rot_esq, rot_dir e inverte) e um fiscal que confere as três regras da
LLRB: (1) nenhum link vermelho à direita; (2) nunca dois links vermelhos
seguidos (um vermelho com filho esquerdo vermelho); (3) todo caminho da
raiz até um NULL tem o mesmo número de links pretos. Insira 1000 senhas
de atendimento geradas por s = (s * 41 + 11) % 1000, começando em s = 0
(essa fórmula passa por todos os números de 0 a 999), e, a cada 200
inserções, rode o fiscal e mostre a altura (em nós) e a altura preta.
Compare com 2 lg(n + 1), o limite do Cormen.


```text
Saída esperada:
n =  200: aprovada, altura 10, altura preta 6, limite 15.3
n =  400: aprovada, altura 12, altura preta 7, limite 17.3
n =  600: aprovada, altura 13, altura preta 8, limite 18.5
n =  800: aprovada, altura 13, altura preta 8, limite 19.3
n = 1000: aprovada, altura 13, altura preta 8, limite 19.9
```

**Dicas:**

1. O fiscal pode ser uma função que devolve a altura preta ou -1, com
   as regras 1 e 2 testadas em cada nó antes de descer.
2. lg vem de <math.h>: log2(n + 1.0). Altura em nós: NULL vale 0.
3. Resposta esperada: o fiscal aprova todas as vezes, e a altura fica
   bem abaixo do limite (veja os números).

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2221.c
```

---

**Exercício P2222** · ★★★ · A árvore B dos códigos de rastreio

Escreva do zero uma árvore B de grau mínimo t = 2 (de 1 a 3 chaves por
nó, até 4 filhos), com a inserção do Cormen que DIVIDE os nós cheios na
descida, a busca e um percurso por níveis. Insira os códigos de rastreio
abaixo, nesta ordem, mostre a árvore por níveis, a altura (em arestas) e
o resultado da busca de 57 e de 60, com o número de nós visitados.


```text
41 17 88 5 63 29 72 95 12 57 34 80 3 66 21 48 99 9
```



```text
Saída esperada:
Nível 0: [41]
Nível 1: [5 17] [63 72 88]
Nível 2: [3] [9 12] [21 29 34] [48 57] [66] [80] [95 99]
Altura: 2
Busca 57: achou (nós visitados: 3)
Busca 60: não achou (nós visitados: 3)
```

**Dicas:**

1. divide(x, i): o filho i de x (cheio, 3 chaves) vira dois nós de uma
   chave, e a do meio sobe para x na posição i. Na raiz cheia, crie uma
   raiz nova vazia antes.
2. Na descida, se o filho em que você vai entrar está cheio, divida
   antes e decida de novo entre os dois pedaços.
3. Resposta esperada: a árvore da saída, com todas as folhas no mesmo
   nível; o 57 está na árvore e o 60 não.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2222.c
```

---

**Exercício P2223** · ★★★ · As estradas que a cheia fecha

Seis comunidades (0 a 5) são ligadas por 7 estradas de terra. Na cheia,
a Defesa Civil já sabe a ordem em que as estradas vão ficar alagadas:


```text
ordem:   1    2    3    4    5    6    7
estrada 0-1  2-3  1-2  3-4  4-5  0-5  2-4
```


Depois de cada fechamento, quantos grupos de comunidades ainda se
alcançam? O union-find sabe UNIR, mas não sabe separar. O truque é
pensar AO CONTRÁRIO: comece com tudo fechado (6 grupos) e reabra as
estradas da última para a primeira; o número de grupos antes de reabrir
a estrada k é a resposta depois de fechar a estrada k. Escreva do zero
(union-find com posto e compressão) e mostre a resposta na ordem dos
fechamentos.


```text
Saída esperada:
Fecha 0-1: 1 grupo(s)
Fecha 2-3: 1 grupo(s)
Fecha 1-2: 2 grupo(s)
Fecha 3-4: 3 grupo(s)
Fecha 4-5: 4 grupo(s)
Fecha 0-5: 5 grupo(s)
Fecha 2-4: 6 grupo(s)
```

**Dicas:**

1. grupos[k] = número de componentes com só as estradas k + 1, ..., 7
   abertas (as que ainda não fecharam). Calcule de k = 7 até k = 1.
2. Reabrir a estrada k: une as pontas; se eram raízes diferentes, os
   componentes caem 1.
3. Resposta esperada: 1 1 2 3 4 5 6.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2223.c
```

---

**Exercício P2224** · ★★★ · Caça-palavras com trie

No caça-palavras 4 × 4 da revistinha, uma palavra se forma andando por
casas vizinhas (horizontal, vertical ou diagonal), sem repetir casa. O
dicionário tem as palavras abaixo. Escreva do zero: guarde o dicionário
numa trie e faça um backtracking (módulo 19) a partir de cada casa que
desce na trie junto com o caminho; se a letra não tem filho na trie,
CORTE o caminho na hora (nenhuma palavra começa assim). Mostre as
palavras achadas em ordem alfabética, sem repetir, e quantas casas o
backtracking visitou.


```text
Grade:  C A S A
        O R T E
        L A M O
        A P E S
```



```text
Dicionário: casa, cara, caro, arte, mar, mesa, pe, ame, rato, lago,
            cola, mel, sapo, tear, ramo
```



```text
Saída esperada:
Achadas (11): ame arte cara caro casa cola mar mesa pe ramo rato
Casas visitadas: 54
```

**Dicas:**

1. procura(l, c, no): pegue o filho da trie pela letra da casa; se é
   NULL, volte. Marque a casa, se o nó é fim de palavra anote a palavra
   (num buffer que cresce com a profundidade), tente os 8 vizinhos e
   desmarque.
2. Para não repetir, desmarque o fim na trie depois de anotar a palavra
   (ou guarde as achadas e compare).
3. Resposta esperada: as palavras da saída. Sem a trie, o backtracking
   teria que seguir todos os caminhos da grade até um tamanho máximo.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2224.c
```

---

**Exercício P2225** · ★★★ · Pintar uma árvore de busca de rubro-negra

Nem toda árvore de busca pode virar rubro-negra só escolhendo as cores:
a forma precisa deixar. Escreva do zero um backtracking (módulo 19) que
tenta pintar os nós de uma árvore de busca, um por um em pré-ordem, de
preto ou vermelho, cortando o ramo assim que um vermelho ganha um pai
vermelho; quando todos têm cor, confira a raiz preta e a altura negra
igual em todos os caminhos. Conte quantas colorações válidas cada árvore
tem e mostre a primeira (vermelho com *, em pré-ordem).


```text
A: 20(10(5, 15), 30(25, 40))
B: 20(10(5, -), 30(25, 40(-, 50)))
C: 20(10, 30(25, 40(-, 50(-, 60))))
```



```text
Saída esperada:
A: 5 coloração(ões), a primeira: 20 10 5 15 30 25 40
B: 1 coloração(ões), a primeira: 20 10 5* 30* 25 40 50*
C: 0 coloração(ões)
```

**Dicas:**

1. Guarde os nós num vetor em pré-ordem (com o índice do pai de cada
   um). Ao pintar o nó i de vermelho, corte se o pai dele é vermelho.
2. A conferência final é a altura_negra que devolve -1 quando dois
   caminhos discordam.
3. Resposta esperada: A tem 5 colorações; B, só 1; C nenhuma (o ramo da
   direita é comprido demais: numa rubro-negra, o caminho mais longo até
   um NULL não passa do dobro do mais curto).

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2225.c
```

---

**Exercício P2226** · ★★★ · Quantos metros acima?

Uma equipe de topografia mede DIFERENÇAS de altitude entre marcos (0 a
6), nunca a altitude de um marco sozinho. Cada medição "a b d" quer dizer
"b está d metros acima de a". Depois, perguntam a diferença entre dois
marcos: se eles estão ligados por medições, dá para calcular; se não,
"desconhecida". E se uma medição nova contradiz as anteriores, ela é
rejeitada. Escreva do zero um UNION-FIND COM PESOS: além de pai[x],
guarde dif[x] = altitude(x) - altitude(pai[x]). Na compressão de
caminho, some as diferenças do caminho; na união, calcule a diferença
entre as duas raízes.


```text
Medições: 0 1 5   1 2 3   3 4 -2   2 3 4   0 4 10   5 6 7   0 2 9
Perguntas: 0 3   4 1   2 5   6 5
```



```text
Saída esperada:
Medição 0 1 5: aceita
Medição 1 2 3: aceita
Medição 3 4 -2: aceita
Medição 2 3 4: aceita
Medição 0 4 10: aceita
Medição 5 6 7: aceita
Medição 0 2 9: rejeitada (contradiz)
0 -> 3: 12 m
4 -> 1: -5 m
2 -> 5: desconhecida
6 -> 5: -7 m
```

**Dicas:**

1. acha(x): se pai[x] != x, r = acha(pai[x]); dif[x] += dif[pai[x]] (já
   relativo à raiz); pai[x] = r. Assim dif[x] passa a ser altitude(x) -
   altitude(raiz).
2. Medição "a b d" com raízes ra e rb diferentes: pendure rb em ra com
   dif[rb] = dif[a] + d - dif[b]. Com raízes iguais, só confira se dif[b]
   - dif[a] == d.
3. Resposta esperada: a medição 0 4 10 confere com as anteriores (5 + 3
   + 4 - 2 = 10) e é aceita; a 0 2 9 contradiz (de 0 a 2 já dá 8 m) e é
   rejeitada. Nas perguntas: 12 m, -5 m, desconhecida e -7 m.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2226.c
```

---

**Exercício P2227** · ★★★ · A busca que desce pelo filho errado

Este programa tem um erro de propósito. A árvore B (t = 2) dos
prontuários do hospital recebe os números de 10 a 200, de 10 em 10, e
depois procura alguns. A inserção está certa; a busca tem UM erro. Ela
compila sem aviso e roda limpo, mas dos 7 prontuários que existem só
acha o 80. Conserte a busca.


```text
Saída esperada:
Prontuário 10: achado
Prontuário 30: achado
Prontuário 80: achado
Prontuário 120: achado
Prontuário 150: achado
Prontuário 190: achado
Prontuário 200: achado
Prontuário 55: não existe
Achados: 7 de 8
```

**Dicas:**

1. Instrumente: mostre as chaves de cada nó visitado. Procure 30 e
   acompanhe a descida.
2. Num nó com chaves c[0] < c[1] < ... < c[n - 1], o filho i guarda as
   chaves entre c[i - 1] e c[i]. Se o laço parou em i (o primeiro com k
   <= c[i]), k está entre c[i - 1] e c[i]: qual filho é esse?
3. Resposta esperada: desça por x->filho[i], não x->filho[i + 1]. Com
   isso, todos os prontuários de 10 a 200 são achados e o 55 não.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2227.c
```

---

**Exercício P2228** · ★★★ · O parente comum mais próximo

Na árvore genealógica da família Bezerra (uma árvore geral com filho e
irmão, e agora também um ponteiro pai em cada nó), escreva do zero:
(1) profundidade(x), contando os passos até a raiz; (2) lca(a, b), o
ANCESTRAL COMUM MAIS PRÓXIMO: suba o mais fundo até os dois ficarem na
mesma profundidade e depois suba os dois juntos até se encontrarem; (3) a
distância entre a e b na árvore, prof(a) + prof(b) - 2 · prof(lca).
Responda os pares do main.


```text
Severino
├── Antônio
│   ├── Carla
│   │   └── Igor
│   └── Diego
└── Benedita
    ├── Elaine
    │   ├── Júlia
    │   └── Kauã
    ├── Fábio
    └── Glória
        └── Hugo
```



```text
Saída esperada:
Igor e Diego: Antônio (distância 3)
Júlia e Hugo: Benedita (distância 4)
Kauã e Elaine: Elaine (distância 1)
Igor e Hugo: Severino (distância 6)
```

**Dicas:**

1. A função filho(p, f) do assunto 0144 ganha uma linha: f->pai = p.
2. Para achar um nó pelo nome, uma busca em pré-ordem (filho, depois
   irmão) com strcmp.
3. Resposta esperada: Igor e Diego têm Antônio em comum (distância 3);
   Júlia e Hugo, Benedita (distância 4); Kauã e Elaine, a própria Elaine
   (1); Igor e Hugo, Severino (6).

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2228.c
```

---

**Exercício P2229** · ★★★ · As três sugestões mais usadas

O teclado do celular aprende com o que você digita: cada palavra fica
numa trie com um contador de vezes. Ao digitar um prefixo, ele sugere
as TRÊS palavras mais usadas que começam com ele (empate: ordem
alfabética). Escreva do zero: monte a trie com as palavras do texto
abaixo (o main já separa as palavras), depois, para cada prefixo, desça
até o nó do prefixo, colete todas as palavras da subárvore com seus
contadores, ordene com qsort e mostre as três primeiras.


```text
Texto: "bom dia boa tarde bom jogo bola bonita bom dia boa noite
bolo de bolo bom bolo tarde tapioca taxi tapioca tarde bom"
```



```text
Saída esperada:
"bo": bom (5) bolo (3) boa (2)
"ta": tarde (3) tapioca (2) taxi (1)
"bol": bolo (3) bola (1)
"x": nenhuma sugestão
```

**Dicas:**

1. O nó guarda int vezes (0 se não é fim de palavra). A coleta é a do
   autocompletar do assunto 0147: um buffer que cresce com a
   profundidade e, em cada nó com vezes > 0, uma entrada { palavra,
   vezes } num vetor.
2. Na comparação do qsort: vezes maior primeiro; se empatar, strcmp.
3. Resposta esperada: para "bo", bom (5), bolo (3) e boa (2).

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2229.c
```

---

**Exercício P2230** · ★★★ · Três árvores, mil chaves

Escreva do zero, no mesmo programa, três estruturas de busca: a árvore
de busca comum (sem balanceamento), a rubro-negra esquerdista e a árvore
B com t = 2. Insira as chaves 0 a 999 em dois cenários: (a) em ordem
crescente; (b) na ordem de s = (s * 41 + 11) % 1000 a partir de s = 0
(passa por todos os números, embaralhados). Mostre a altura de cada uma
em cada cenário: para as binárias, o número de nós do caminho mais
longo; para a B, o número de níveis.


```text
Saída esperada:
Em ordem: comum 1000, rubro-negra 10, B 9 níveis
Embaralhadas: comum 24, rubro-negra 13, B 8 níveis
```

**Dicas:**

1. Com 1000 chaves em ordem, a árvore comum vira uma lista: a inserção
   recursiva desce 1000 níveis. Funciona, mas faça a inserção da árvore
   comum iterativa (com um ponteiro para ponteiro) para não depender do
   tamanho da pilha.
2. A altura da árvore comum em ordem crescente também é melhor calcular
   sem recursão profunda: como ela só tem filhos à direita, ande pelo
   dir contando; para o caso geral, a recursão desce no máximo a altura.
3. Resposta esperada: a árvore comum tem altura 1000 em ordem e 24
   embaralhada; a rubro-negra fica com 10 e 13, e a B com 9 e 8 níveis.
   Balancear é garantir o pior caso, não melhorar o caso médio.

```bash
~/LPEDC/rodar 22-arvores-avancadas/lista/P2230.c
```

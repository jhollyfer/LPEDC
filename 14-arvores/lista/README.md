<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 14 · Árvores

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/14-arvores/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P1401** · ★☆☆ · O organograma, nível por nível

O organograma de uma pequena empresa é uma árvore binária: a Diretora tem
Vendas à esquerda e TI à direita; Vendas tem Loja e Online; Online tem só
Site, à direita; TI tem só Suporte, à esquerda.

Monte a árvore com uma função No *novo(nome, esq, dir) e escreva:


```text
int altura(const No *r)          altura em ARESTAS (vazia = -1)
void mostra(const No *r, int prof)   pré-ordem com 2 espaços por nível
```


mostra imprime cada nó com a profundidade (recebida no parâmetro) e a
altura dele. No fim, mostre a altura da árvore e libere tudo.


```text
Saída esperada:
Diretora (profundidade 0, altura 3)
  Vendas (profundidade 1, altura 2)
    Loja (profundidade 2, altura 0)
    Online (profundidade 2, altura 1)
      Site (profundidade 3, altura 0)
  TI (profundidade 1, altura 1)
    Suporte (profundidade 2, altura 0)
altura da árvore: 3
```

**Dicas:**

1. Profundidade se calcula DESCENDO (o pai passa prof + 1 para os filhos);
   altura se calcula SUBINDO (1 + a maior altura dos filhos).
2. printf("%*s", 2 * prof, "") imprime 2 * prof espaços.
3. A altura da árvore é a altura da raiz, que é a maior profundidade (o
   Site, a 3 arestas da Diretora).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1401.c
```

---

**Exercício P1402** · ★☆☆ · A BST das senhas e os três percursos

Insira as senhas 50, 30, 70, 20, 40, 60, 80, 35, 65, nesta ordem, numa
árvore binária de busca vazia (menor à esquerda, maior à direita, repetida
é ignorada). Mostre os percursos pré-ordem, em ordem e pós-ordem e libere
a árvore.


```text
Saída esperada:
pré: 50 30 20 40 35 70 60 65 80
em:  20 30 35 40 50 60 65 70 80
pós: 20 35 40 30 65 60 80 70 50
```

**Dicas:**

1. A inserção recursiva devolve a raiz: r->esq = insere(r->esq, chave).
2. Desenhe a árvore antes: o 35 fica à esquerda do 40 e o 65 à direita do 60.
3. A em ordem de uma BST sai sempre crescente: se não sair, a inserção está
   errada. A raiz é a primeira da pré e a última da pós.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1402.c
```

---

**Exercício P1403** · ★☆☆ · Procurando o CEP na BST

A transportadora guarda os prefixos de CEP atendidos numa BST. O main já
insere 690, 420, 810, 150, 530, 770, 950, 480, 600. Complete:


```text
const No *busca(const No *r, int chave, int *visitados)
  busca SEM recursão (um while que desce pela árvore), contando quantos
  nós olhou;
int minimo(const No *r) e int maximo(const No *r)
  sem recursão: o menor é o nó mais à esquerda; o maior, o mais à direita.
```



```text
Saída esperada:
600: achou (visitados: 4)
950: achou (visitados: 3)
690: achou (visitados: 1)
500: não achou (visitados: 4)
menor: 150, maior: 950
```

**Dicas:**

1. No while, compare: igual, achou; menor, r = r->esq; maior, r = r->dir.
2. O 500 desce 690, 420, 530, 480 e cai num NULL: a busca sem sucesso
   também custa a altura do caminho.
3. No mínimo, ande enquanto r->esq != NULL (a árvore aqui não é vazia).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1403.c
```

---

**Exercício P1404** · ★☆☆ · A árvore genealógica, uma geração por linha

Complete por_nivel, o percurso por nível (largura), mostrando cada nível
numa linha. Use uma fila num vetor No *fila[32] com índices ini e fim. O
truque para separar os níveis: no começo de cada volta, os que estão na
fila (fim - ini) são exatamente os do nível atual. Tire esses todos,
imprimindo e enfileirando os filhos, e só então passe de linha.


```text
Saída esperada:
nível 0: Joana
nível 1: Pedro Carla
nível 2: Lara Davi Tomas
nível 3: Nina Yuri Zoe
```

**Dicas:**

1. int tamanho = fim - ini; e um for de 0 a tamanho - 1.
2. Enfileire o filho esquerdo antes do direito.
3. O percurso por nível é a BFS (módulo 16) aplicada à árvore: fila, e não
   pilha nem recursão.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1404.c
```

---

**Exercício P1405** · ★☆☆ · O heap de lances do leilão

No leilão online, o maior lance tem que estar sempre à mão. Os lances
chegam nesta ordem: 120, 340, 200, 510, 90, 450, 380. Escreva
void insere(int heap[], int *n, int x), que coloca x no fim de um heap de
MÁXIMO (raiz em heap[0], pai de i em (i - 1) / 2) e faz ele subir enquanto
for maior que o pai. Mostre o vetor depois de cada inserção.


```text
Saída esperada:
depois do 120: 120
depois do 340: 340 120
depois do 200: 340 120 200
depois do 510: 510 340 200 120
depois do 90: 510 340 200 120 90
depois do 450: 510 340 450 120 90 200
depois do 380: 510 340 450 120 90 200 380
```

**Dicas:**

1. int i = (*n)++; heap[i] = x; e depois o while (i > 0 && pai < filho).
2. O 510 entra no índice 3, troca com o 120 (índice 1) e depois com o 340
   (índice 0): sobe 2 níveis, O(log n).
3. O vetor do heap NÃO está ordenado; só a raiz é garantidamente o maior.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1405.c
```

---

**Exercício P1406** · ★☆☆ · Chamando os pacientes mais urgentes

No pronto-socorro, as urgências dos pacientes já estão num heap de máximo:
95, 80, 70, 40, 75, 30, 65, 10. A função desce está pronta. Escreva
int extrai_max(int heap[], int *n): guarda a raiz, leva o último elemento
para a raiz, diminui n e faz a raiz descer. Chame três pacientes,
mostrando o heap que sobra a cada chamada.


```text
Saída esperada:
chamou 95, sobrou: 80 75 70 40 10 30 65
chamou 80, sobrou: 75 65 70 40 10 30
chamou 75, sobrou: 70 65 30 40 10
```

**Dicas:**

1. heap[0] = heap[--(*n)]; e depois desce(heap, *n, 0).
2. Na primeira extração o 10 vai para a raiz e desce trocando com o maior
   filho: primeiro o 80, depois o 75.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1406.c
```

---

**Exercício P1407** · ★☆☆ · O fator de cada nó

Insira os pedidos 40, 20, 60, 10, 30, 25, 35, 70, 27 numa BST comum (sem
balancear). Escreva bool fatores(const No *r), que percorre a árvore EM
ORDEM mostrando o fator de balanceamento de cada nó,
altura(esq) - altura(dir), e devolve true se todos os fatores estão entre
-1 e 1. No fim, diga se a árvore poderia ser uma AVL.


```text
Saída esperada:
10: fator 0
20: fator -2
25: fator -1
27: fator 0
30: fator 1
35: fator 0
40: fator 2
60: fator -1
70: fator 0
é AVL? não
```

**Dicas:**

1. Altura em arestas, árvore vazia = -1: a folha tem fator -1 - (-1) = 0.
2. Chame fatores(r->esq) ANTES de imprimir e fatores(r->dir) depois, e
   guarde os resultados em variáveis (não use && direto, senão a recursão
   da direita pode nem rodar).
3. Sem o 27, a árvore seria AVL. Ele pendura o 25 e desequilibra o 20 e a
   raiz ao mesmo tempo.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1407.c
```

---

**Exercício P1408** · ★☆☆ · A altura que contava nós

A árvore abaixo guarda os quilômetros das paradas de uma linha de ônibus.
A função altura tem um erro de propósito: ela não segue a convenção do
módulo (altura em ARESTAS, folha com altura 0, árvore vazia com -1). Rode,
veja os números errados e conserte.


```text
Saída esperada (depois do conserto):
altura da folha: 0
altura da árvore: 3
altura da vazia: -1
```

**Dicas:**

1. Antes do conserto, tudo sai 1 a mais e a vazia sai 0.
2. Só o caso base está errado. Quanto vale 1 + max(he, hd) numa folha, se
   a altura de NULL for -1?
3. Resposta esperada: if (r == NULL) return -1; e a saída fica igual à de
   cima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1408.c
```

---

**Exercício P1409** · ★☆☆ · Contando os nós pelo número de filhos

Insira os preços 45, 22, 67, 10, 30, 55, 80, 5, 27, 90, 85 numa BST e
escreva void conta_graus(const No *r, int grau[3]), que soma em grau[g]
quantos nós têm g filhos (0, 1 ou 2). Mostre as três contagens, o total e
confira a propriedade das árvores binárias: folhas = (nós com 2 filhos) + 1.


```text
Saída esperada:
folhas (0 filhos): 4
com 1 filho: 4
com 2 filhos: 3
total: 11 nós
folhas = (2 filhos) + 1? sim
```

**Dicas:**

1. (r->esq != NULL) + (r->dir != NULL) dá o número de filhos.
2. A propriedade vale para toda árvore binária não vazia: cada nó de grau 2
   "abre" um caminho a mais, e os de grau 1 não mudam o número de folhas.
   A prova cobra isso em questões de contar nós.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1409.c
```

---

**Exercício P1410** · ★☆☆ · Montando o heap de uma vez

As quantidades de 9 produtos no estoque estão num vetor desordenado:
4, 17, 9, 23, 8, 31, 12, 2, 19. Transforme o vetor num heap de máximo com o
BUILD-MAX-HEAP: chame desce(v, n, i) para cada pai, do último
(i = n / 2 - 1) até a raiz (i = 0). Mostre o vetor depois de cada desce.
A função desce está pronta.


```text
Saída esperada:
desce(3): 4 17 9 23 8 31 12 2 19
desce(2): 4 17 31 23 8 9 12 2 19
desce(1): 4 23 31 19 8 9 12 2 17
desce(0): 31 23 12 19 8 9 4 2 17
```

**Dicas:**

1. Os índices de n / 2 até n - 1 são folhas: já são heaps de um elemento.
2. No desce(1), o 17 troca com o 23 e depois com o 19: um elemento pode
   descer vários níveis.
3. Construir assim custa O(n), menos que n inserções (O(n log n)).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1410.c
```

## ★★☆ Para pensar

**Exercício P1411** · ★★☆ · Sucessor e antecessor sem ponteiro para o pai

A agenda de um consultório guarda os horários (em minutos) numa BST cujos
nós NÃO têm ponteiro para o pai. O main insere 50, 30, 70, 20, 40, 60, 80,
35, 45, 65. Escreva, sem recursão, descendo a partir da raiz:


```text
int sucessor(const No *r, int x)     menor chave MAIOR que x, ou -1
int antecessor(const No *r, int x)   maior chave MENOR que x, ou -1
```


Mostre os dois para 40, 45, 65, 20 e 80.


```text
Saída esperada:
40: antecessor 35, sucessor 45
45: antecessor 40, sucessor 50
65: antecessor 60, sucessor 70
20: antecessor -1, sucessor 30
80: antecessor 70, sucessor -1
```

**Dicas:**

1. Para o sucessor: se x < r->chave, r é um candidato (guarde) e talvez
   exista um menor que ainda sirva, à esquerda; senão, vá para a direita.
2. O antecessor é o espelho: guarde quando x > r->chave e vá para a direita.
3. Repare no 45: ele é folha, então o sucessor é um ANCESTRAL (o 50, o
   primeiro de quem o 45 está à esquerda). É o caso que a prova adora.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1411.c
```

---

**Exercício P1412** · ★★☆ · Remoções em sequência na BST

Os armários do clube ficam numa BST montada com 50, 30, 70, 20, 40, 60, 80,
35, 45, 65. Escreva No *remove_chave(No *r, int chave) com os três casos
(folha, um filho, dois filhos) e, no caso de dois filhos, use o SUCESSOR
(o menor da subárvore direita), como no Cormen: copie a chave dele para o
nó e remova o sucessor da subárvore direita. Remova 20, 60, 30 e 50, nesta
ordem, mostrando a pré-ordem depois de cada remoção.


```text
Saída esperada:
início:    50 30 20 40 35 45 70 60 65 80
sem o 20: 50 30 40 35 45 70 60 65 80
sem o 60: 50 30 40 35 45 70 65 80
sem o 30: 50 40 35 45 70 65 80
sem o 50: 65 40 35 45 70 80
```

**Dicas:**

1. Folha e um filho se resolvem juntos: o filho (que pode ser NULL) toma o
   lugar do nó, e o nó é liberado.
2. O 30 tem dois filhos; o sucessor dele é o 35, que tem 0 filhos. Depois
   da cópia, o 35 sai da subárvore direita do 30.
3. O 50, na raiz, é trocado pelo 65 (o menor à direita depois de o 60 ter
   saído). Com o antecessor, a raiz seria o 45: as duas respostas são
   válidas, e a prova diz qual convenção usar.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1412.c
```

---

**Exercício P1413** · ★★☆ · O k-ésimo menor tempo da maratona

Os tempos (em minutos) de 11 corredores foram inseridos numa BST: 212, 185,
240, 170, 199, 228, 265, 192, 205, 251, 178. Escreva
const No *k_esimo(const No *r, int *k), que faz a em ordem e para no
k-ésimo nó visitado (o k é gasto: cada nó visitado faz (*k)--, e quem
zera o k é a resposta). Devolve NULL se a árvore tiver menos de k nós.
Mostre o 1º, o 3º, o 8º, o 11º e o 12º menores e a mediana, o
((n + 1) / 2)-ésimo.


```text
Saída esperada:
1º menor: 170 min
3º menor: 185 min
8º menor: 228 min
11º menor: 265 min
12º menor: não existe
mediana (6º de 11): 205 min
```

**Dicas:**

1. Procure à esquerda; se achou lá, devolva sem olhar mais nada.
2. Senão, (*k)--; se *k chegou a 0, o nó atual é a resposta; senão,
   procure à direita.
3. Passe uma CÓPIA de k (int k = pedido; k_esimo(raiz, &k)), porque ela é
   modificada.
4. Custa O(h + k): não precisa percorrer a árvore toda.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1413.c
```

---

**Exercício P1414** · ★★☆ · Reconstruindo a árvore pela pós-ordem

Uma árvore binária (não é BST) de números distintos foi salva em dois
percursos:


```text
em ordem:  4 2 7 5 1 3 6
pós-ordem: 4 7 5 2 6 3 1
```


Escreva No *monta(em, ini, fim, pos, &ultimo), que reconstrói a árvore de
em[ini..fim]. A raiz é o último elemento ainda não usado da pós-ordem
(pos[*ultimo], e *ultimo diminui); a posição dela na em ordem separa o lado
esquerdo do direito. Mostre a pré-ordem e a altura da árvore montada e
libere tudo.


```text
Saída esperada:
pré: 1 2 4 5 7 3 6
altura: 3
```

**Dicas:**

1. Lendo a pós-ordem de trás para frente, você encontra: raiz, depois a
   subárvore DIREITA inteira, depois a esquerda. Por isso monte o lado
   direito antes do esquerdo.
2. ini > fim é a árvore vazia: devolva NULL.
3. Com pré + em, a ideia é a mesma lendo a pré da frente para trás (raiz,
   esquerda, direita). Já pré + pós não bastam: elas não dizem se um filho
   único é esquerdo ou direito.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1414.c
```

---

**Exercício P1415** · ★★☆ · A AVL contando as rotações

Escreva uma AVL do zero (nó com chave, alt, esq e dir; altura em arestas,
vazia = -1; fator = alt(esq) - alt(dir)) e insira os pedidos 10, 30, 20, 5,
4, 40, 50, 45, 8, 9. Depois de cada inserção, mostre a pré-ordem e, se
houve rotação, qual foi. Guarde o nome numa variável global
const char *ultima_rotacao, zerada ("") antes de cada inserção:

- fator > 1 e fator(esq) >= 0: "simples à direita (LL)"
- fator > 1 e fator(esq) < 0: "dupla esquerda-direita (LR)"
- fator < -1 e fator(dir) <= 0: "simples à esquerda (RR)"
- fator < -1 e fator(dir) > 0: "dupla direita-esquerda (RL)"


```text
Saída esperada:
+10: 10
+30: 10 30
+20: 20 10 30   <- rotação dupla direita-esquerda (RL)
+5: 20 10 5 30
+4: 20 5 4 10 30   <- rotação simples à direita (LL)
+40: 20 5 4 10 30 40
+50: 20 5 4 10 40 30 50   <- rotação simples à esquerda (RR)
+45: 20 5 4 10 40 30 50 45
+8: 20 5 4 10 8 40 30 50 45
+9: 20 5 4 9 8 10 40 30 50 45   <- rotação dupla esquerda-direita (LR)
altura final: 3
```

**Dicas:**

1. Na rotação, atualize primeiro o nó que DESCEU e depois o que subiu.
2. Na volta da recursão: atualiza(r), olha o fator e gira se precisar.
3. No +4, quem desequilibra é o 10 (não a raiz): a rotação acontece no
   nó desbalanceado mais baixo, e os de cima voltam a ficar em ordem.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1415.c
```

---

**Exercício P1416** · ★★☆ · A fila de prioridade da impressora

A impressora do escritório atende por prioridade (1 é a mais urgente) e,
no empate, por ordem de chegada. Escreva um heap de MÍNIMO de structs:


```text
typedef struct { char dono[10]; int prioridade; int chegada; } Trabalho;
```



```text
int antes(const Trabalho *a, const Trabalho *b)   a sai antes de b?
void insere(Trabalho h[], int *n, Trabalho t)    sobe
Trabalho extrai(Trabalho h[], int *n)            desce
```


Chegam, nesta ordem (chegada de 1 a 6): Caixa 3, Gerente 1, RH 2, Vendas 3,
Diretor 1, Estoque 2. Insira todos e depois extraia até esvaziar.


```text
Saída esperada:
ordem de impressão:
  Gerente  prioridade 1, chegou em 2
  Diretor  prioridade 1, chegou em 5
  RH       prioridade 2, chegou em 3
  Estoque  prioridade 2, chegou em 6
  Caixa    prioridade 3, chegou em 1
  Vendas   prioridade 3, chegou em 4
```

**Dicas:**

1. Toda comparação do heap passa por antes(): é ela que define o que é
   "menor". Com chave composta, o heap não precisa mudar.
2. O heap NÃO é estável. Sem o campo chegada no desempate, Gerente e
   Diretor poderiam sair em qualquer ordem.
3. Use printf("  %-8s prioridade %d, chegou em %d\n", ...).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1416.c
```

---

**Exercício P1417** · ★★☆ · As 4 passagens mais baratas

Um site de passagens recebe os preços um de cada vez e quer, no fim, as
k = 4 MAIS BARATAS, sem guardar todos os preços. Use um heap de MÁXIMO com
no máximo 4 elementos: enquanto ele não está cheio, insira; depois, se o
preço novo for menor que a raiz (a mais cara das 4 guardadas), ele toma o
lugar da raiz e desce. No fim, tire os 4 do heap para mostrar do mais
barato para o mais caro.


```text
Preços: 780 455 920 610 390 1200 505 430 870 399 640 415
```



```text
Saída esperada:
as 4 mais baratas: 390 399 415 430
```

**Dicas:**

1. Escreva sobe(h, i) e desce(h, n, i) de um heap de máximo.
2. Parece ao contrário, mas é isso: para guardar os MENORES, o heap é de
   MÁXIMO, porque quem você precisa descartar rápido é o maior deles.
3. Custa O(n log k), com memória O(k). Com k pequeno, quase O(n).
4. Ao extrair, o primeiro que sai é o mais caro: preencha a resposta de
   trás para frente.
5. Resposta esperada: 390 399 415 430.

```bash
~/LPEDC/rodar 14-arvores/lista/P1417.c
```

---

**Exercício P1418** · ★★☆ · O heapsort passo a passo

Ordene as notas 6, 9, 2, 7, 10, 4, 8 com heapsort e mostre o estado do
vetor como a prova pede: depois de construir o heap (BUILD-MAX-HEAP) e
depois de cada passo da fase 2 (troca a raiz com o último da parte heap e
faz a nova raiz descer). Separe com " | " a parte heap da parte já
ordenada. Conte TODAS as trocas (as do desce e as da raiz com o fim) numa
global trocas.


```text
Saída esperada:
heap:      10 9 8 7 6 4 2
passo 1:   9 7 8 2 6 4 | 10
passo 2:   8 7 4 2 6 | 9 10
passo 3:   7 6 4 2 | 8 9 10
passo 4:   6 2 4 | 7 8 9 10
passo 5:   4 2 | 6 7 8 9 10
passo 6:   2 | 4 6 7 8 9 10
trocas: 15
```

**Dicas:**

1. Faça mostra(rotulo, v, n, fim): antes do índice fim, imprime " | " em
   vez de " ". Na linha do heap, passe fim = n (sem barra).
2. Ponha trocas++ dentro da função troca: assim nenhuma escapa.
3. Os rótulos são "heap:     " e "passo %d: " seguido de mostra com " ".
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1418.c
```

---

**Exercício P1419** · ★★☆ · O ancestral comum das estações

As estações de uma ferrovia foram guardadas numa BST pelo quilômetro:
60, 25, 90, 10, 40, 75, 120, 30, 50, 80. Escreva:


```text
const No *ancestral(const No *r, int a, int b)
  o ancestral comum mais baixo de a e b, sem recursão: enquanto a e b
  estão do mesmo lado de r, desça para esse lado; quando se separam (ou
  um deles é r), r é a resposta;
int profundidade(const No *r, int x)
  quantas arestas da raiz até x.
```


A distância (em arestas) entre a e b é prof(a) + prof(b) - 2 · prof(ancestral).
Mostre para os pares (30, 50), (10, 50), (80, 120), (30, 80) e (25, 30).


```text
Saída esperada:
30 e 50: ancestral 40, distância 2
10 e 50: ancestral 25, distância 3
80 e 120: ancestral 90, distância 3
30 e 80: ancestral 60, distância 6
25 e 30: ancestral 25, distância 2
```

**Dicas:**

1. Se a < r->chave e b < r->chave, os dois estão à esquerda; se os dois são
   maiores, à direita; senão, r é o ancestral.
2. No par (25, 30) o próprio 25 é o ancestral: um nó conta como ancestral
   de si mesmo.
3. Numa árvore qualquer (não BST) isso exige busca nas duas subárvores; a
   ordem da BST deixa em O(h).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1419.c
```

---

**Exercício P1420** · ★★☆ · Em ordem sem recursão

A recursão da em ordem usa a pilha de chamadas do C. Troque por uma pilha
sua: escreva void em_ordem_iterativa(const No *r) com const No *pilha[32].
O laço: desça para a esquerda empilhando cada nó; quando chegar em NULL,
desempilhe, imprima e vá para a direita do desempilhado. Repita enquanto
houver nó atual ou pilha não vazia. Mostre também o maior tamanho que a
pilha alcançou.

O main insere os códigos 41, 20, 65, 11, 29, 50, 91, 32, 72, 99.


```text
Saída esperada:
em ordem: 11 20 29 32 41 50 65 72 91 99
pilha chegou a 3 nós
```

**Dicas:**

1. while (p != NULL || topo > 0) { while (p != NULL) { empilha; p = p->esq; } ... }
2. A pilha nunca passa de altura + 1 nós. Esta árvore tem altura 3, mas
   o caminho mais fundo (41, 20, 29, 32) sobe à direita, e quem vai à
   direita é desempilhado antes: o máximo fica em 3.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1420.c
```

## ★★★ Desafio

**Exercício P1421** · ★★★ · Remoção na AVL

O assunto 0101 fez a inserção na AVL. A remoção é a da BST (com o sucessor
no caso de dois filhos) mais um detalhe: na VOLTA da recursão, cada nó do
caminho atualiza a altura e gira se ficou desbalanceado. Diferente da
inserção, uma remoção pode exigir rotação em mais de um nível.

O esqueleto traz o nó, alt, atualiza, fator e as duas rotações. Escreva:


```text
No *rebalanceia(No *r)   atualiza, olha o fator, gira e guarda o nome da
                         rotação ("LL", "LR", "RR" ou "RL") na global
                         rotacao; usada pela inserção E pela remoção
No *insere(No *r, int chave)
No *remove_chave(No *r, int chave)
```


Insira 40, 20, 60, 10, 30, 50, 70, 5, 25, 35, 45 e remova 70, 45, 60 e 5,
mostrando a pré-ordem, a rotação (se houve) e a altura depois de cada
remoção.


```text
Saída esperada:
início: 40 20 10 5 30 25 35 60 50 45 70
sem o 70: 40 20 10 5 30 25 35 50 45 60   (rotação LL)  altura 3
sem o 45: 40 20 10 5 30 25 35 50 60  altura 3
sem o 60: 20 10 5 40 30 25 35 50   (rotação LL)  altura 3
sem o 5: 30 20 10 25 40 35 50   (rotação RL)  altura 2
```

**Dicas:**

1. Os casos de fator são os mesmos da inserção: > 1 com fator(esq) < 0 é
   LR; senão LL. < -1 com fator(dir) > 0 é RL; senão RR.
2. Na remoção, o fator do filho pode ser 0 (na inserção nunca é). Com 0,
   use a rotação simples: por isso o teste é fator(esq) < 0, e não <= 0.
3. No "sem o 60", a raiz 40 fica com fator +2 e quem sobe é o 20.
4. Zere rotacao = "" antes de cada remoção. Mostre com
   printf("   (rotação %s)", rotacao) e printf("  altura %d\n", raiz->alt).
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1421.c
```

---

**Exercício P1422** · ★★★ · A BST de volta a partir da pré-ordem

Um sistema salva a BST do estoque gravando só a pré-ordem (é o jeito
clássico: a pré-ordem de uma BST basta para remontá-la). Escreva


```text
No *monta(const int pre[], int n, int *i, int min, int max)
```


que remonta a árvore em O(n): se pre[*i] cabe no intervalo ABERTO
(min, max), ele vira um nó, *i avança e os filhos são montados com
(min, chave) à esquerda e (chave, max) à direita; senão, devolve NULL.
Se, no fim, *i < n, a sequência não é pré-ordem de BST nenhuma.

Escreva testa(nome, pre, n), que monta a partir de i = 0 com INT_MIN e
INT_MAX, mostra a em ordem e a pós-ordem (ou o erro) e libera a árvore.


```text
backup 1: 45 20 10 30 25 35 70 60 90
backup 2: 45 20 50 30 60
backup 3: 8 5 1 7 10 12
```



```text
Saída esperada:
backup 1: ok
  em:  10 20 25 30 35 45 60 70 90
  pós: 10 25 35 30 20 60 90 70 45
backup 2: não é pré-ordem de BST (parou no 30, posição 3)
backup 3: ok
  em:  1 5 7 8 10 12
  pós: 1 7 5 12 10 8
```

**Dicas:**

1. Inclua <limits.h> para INT_MIN e INT_MAX.
2. Cada elemento é olhado poucas vezes: quem não cabe num intervalo é
   devolvido para o chamador, que tenta encaixá-lo mais acima.
3. No backup 2, o 50 já foi para a direita do 45; o 30 aparece depois e
   não cabe em lugar nenhum (teria que estar à esquerda do 45).
4. Mesmo no erro, a árvore parcial precisa ser liberada.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1422.c
```

---

**Exercício P1423** · ★★★ · A árvore da expressão

A calculadora da escola recebe contas em notação posfixa (operandos de um
dígito, separados por espaço) e monta a ÁRVORE DA EXPRESSÃO: as folhas
são os números, cada nó interno é um operador com seus dois operandos como
filhos. Escreva:


```text
No *monta(const char *posfixa)   com uma pilha de árvores: dígito vira
                                 folha empilhada; operador desempilha a
                                 direita, depois a esquerda, e empilha o
                                 nó novo
void infixa(const No *r)         em ordem, com parênteses em cada operador
void prefixa(const No *r)        pré-ordem
int avalia(const No *r)          pós-ordem: avalia os filhos, depois opera
int altura(const No *r)
```


Rode com "3 4 + 2 *", "9 5 - 8 2 / *" e "6 2 3 * + 8 4 - /" e libere cada
árvore.


```text
Saída esperada:
posfixa: 3 4 + 2 *
  infixa: ((3 + 4) * 2)
  prefixa: * + 3 4 2
  valor: 14, altura: 2
posfixa: 9 5 - 8 2 / *
  infixa: ((9 - 5) * (8 / 2))
  prefixa: * - 9 5 / 8 2
  valor: 16, altura: 2
posfixa: 6 2 3 * + 8 4 - /
  infixa: ((6 + (2 * 3)) / (8 - 4))
  prefixa: / + 6 * 2 3 - 8 4
  valor: 3, altura: 3
```

**Dicas:**

1. Os três percursos da mesma árvore dão as três notações: pré = prefixa,
   em = infixa, pós = posfixa (a própria entrada).
2. O primeiro desempilhado é o operando da DIREITA: em "8 4 -", o 4 sai
   primeiro, e a conta é 8 - 4.
3. Na infixa, a folha é impressa sem parênteses.
4. Use isdigit((unsigned char)c) de <ctype.h>; a folha vale c - '0'.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1423.c
```

---

**Exercício P1424** · ★★★ · O heap que escolhia o filho errado

O RH paga os bônus do maior para o menor usando um heap de máximo: monta o
heap e extrai a raiz até esvaziar. Os bônus (em reais) são 300, 1500, 800,
1200, 900, 400, 1100, 700. A função desce tem UM erro de propósito, numa
linha só. O programa não quebra, mas a ordem de pagamento sai errada.
Ache, conserte e rode até sair:


```text
Saída esperada:
ordem de pagamento: 1500 1200 1100 900 800 700 400 300
```

**Dicas:**

1. Antes do conserto, alguns valores saem fora de ordem. Faça o teste de
   mesa de um desce em que os DOIS filhos são maiores que o pai.
2. O desce tem que trocar o pai com o MAIOR dos filhos. Quem o if
   compara com o filho direito?
3. Resposta esperada: a linha certa é
   if (f + 1 < n && v[f + 1] > v[f]) f++;
   e a saída fica igual à de cima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1424.c
```

---

**Exercício P1425** · ★★★ · O paciente que piorou na fila

No pronto-socorro, a fila é um heap de máximo pela gravidade (no empate,
sai a ficha menor). Mas um paciente pode PIORAR enquanto espera, e aí ele
tem que subir na fila. Para isso, o heap precisa saber onde cada paciente
está: guarde no heap só os ids (fichas) e mantenha pos[id] = índice do
paciente no heap, atualizado em TODA troca.


```text
typedef struct {
    int heap[MAX];       // ids
    int pos[MAX];        // pos[id]
    int gravidade[MAX];  // gravidade[id]
    int n;
} Fila;
```


Escreva antes, troca (que corrige pos[] dos dois), sobe, desce,
chega(f, id, g), piorou(f, id, g) (a gravidade só aumenta, então só sobe)
e atende(f), que devolve o id atendido.

Chegam as fichas 0 a 5 com gravidades 3, 5, 2, 4, 2, 1. Atenda uma; a
ficha 5 piora para 4; a ficha 2 piora para 6; atenda todo mundo.


```text
Saída esperada:
atendido: ficha 1
ficha 5 piorou para 4
ficha 2 piorou para 6
atendido: ficha 2 (gravidade 6)
atendido: ficha 3 (gravidade 4)
atendido: ficha 5 (gravidade 4)
atendido: ficha 0 (gravidade 3)
atendido: ficha 4 (gravidade 2)
```

**Dicas:**

1. troca(f, i, j) troca heap[i] com heap[j] e depois faz
   pos[heap[i]] = i e pos[heap[j]] = j.
2. piorou: grava a gravidade nova e chama sobe(f, f->pos[id]). Sem pos[],
   achar o paciente custaria O(n); com ele, a operação toda é O(log n).
3. É a operação HEAP-INCREASE-KEY do Cormen, a mesma que o Dijkstra
   (módulo 23) usa para diminuir distâncias.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1425.c
```

---

**Exercício P1426** · ★★★ · Juntando k listas com um heap

Quatro lojas de uma rede mandam os valores das vendas do dia, cada lista
já em ordem crescente:


```text
loja 0: 12 40 77
loja 1: 5 18 19 60 95
loja 2: 33
loja 3: 7 21 50 88
```


Junte tudo numa sequência ordenada usando um heap de MÍNIMO com no máximo
k = 4 itens. Cada item guarda o valor, de qual lista veio e o índice nela:


```text
typedef struct { int valor; int lista; int indice; } Item;
```


Comece pondo a frente de cada lista no heap. Repita: a raiz é o menor de
todos; imprima; se a lista dela tem próximo, ele toma o lugar da raiz;
senão, o último do heap vai para a raiz e o heap encolhe; desça a raiz.


```text
Saída esperada:
juntas: 5 7 12 18 19 21 33 40 50 60 77 88 95
```

**Dicas:**

1. Guarde as listas num vetor de ponteiros: const int *listas[] = {loja0,
   loja1, loja2, loja3}; e os tamanhos em int tam[].
2. Um literal composto monta o item numa linha: heap[0] = (Item){v, l, i};
3. Custa O(N log k) para N valores no total: com k listas, cada valor
   entra e sai do heap uma vez. Compare com intercalar duas a duas.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1426.c
```

---

**Exercício P1427** · ★★★ · A mediana que acompanha o fluxo

O app de delivery mostra, a cada pedido entregue, a MEDIANA do tempo de
entrega do dia até agora. Os tempos chegam assim, em minutos:
35, 12, 50, 20, 41, 8, 27, 60. Ordenar tudo a cada pedido seria caro; use
DOIS heaps:

- baixo: heap de MÁXIMO com a metade menor dos tempos;
- alto: heap de MÍNIMO com a metade maior.

Para cada tempo x: se baixo está vazio ou x <= raiz de baixo, ele entra em
baixo; senão, em alto. Depois equilibre: baixo pode ter no máximo um a mais
que alto (se tiver dois a mais, passe a raiz de baixo para alto; se alto
ficar maior, passe a raiz de alto para baixo). A mediana é a raiz de
baixo (quantidade ímpar) ou a média das duas raízes (par).


```text
Saída esperada:
chegou 35: mediana 35.0
chegou 12: mediana 23.5
chegou 50: mediana 35.0
chegou 20: mediana 27.5
chegou 41: mediana 35.0
chegou  8: mediana 27.5
chegou 27: mediana 27.0
chegou 60: mediana 31.0
```

**Dicas:**

1. Um parâmetro sinal (1 ou -1) deixa um só sobe/desce servir para os dois
   heaps: compare sinal * h[i] com sinal * h[pai].
2. Escreva insere(h, &n, x, sinal) e extrai(h, &n, sinal).
3. Cada pedido custa O(log n), e a mediana sai em O(1).
4. Use printf("chegou %2d: mediana %.1f\n", ...) e divida por 2.0.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1427.c
```

---

**Exercício P1428** · ★★★ · BST comum contra AVL na planilha ordenada

A academia importou 31 alunos de uma planilha que já vinha em ordem de
matrícula (1, 2, ..., 31). Meça o estrago numa BST comum e compare com uma
AVL. O esqueleto traz o nó com alt, atualiza, fator e as rotações.
Escreva:


```text
No *insere_bst(No *r, int chave)    sem balancear
No *insere_avl(No *r, int chave)    com as rotações
int altura_real(const No *r)        percorrendo (a BST não mantém alt)
int comparacoes(const No *r, int x) nós visitados até achar x
```


Insira 1..31 nas duas e, para cada uma, procure TODAS as 31 chaves: mostre
a altura, a pior busca, o total de comparações e a média.


```text
Saída esperada:
BST: altura 30, pior busca 31, total 496, média 16.00
AVL: altura 4, pior busca 5, total 129, média 4.16
```

**Dicas:**

1. Na BST, cada matrícula nova é a maior até agora e vai sempre para a
   direita: a árvore vira uma lista. Total = 1 + 2 + ... + 31 = 496.
2. Com 31 = 2⁵ - 1 nós, a AVL fica perfeita: 1 nó a 1 comparação, 2 a 2,
   4 a 3, 8 a 4 e 16 a 5. Total = 1 + 4 + 12 + 32 + 80 = 129.
3. A insere_avl pode reaproveitar insere_bst(NULL, chave) para criar
   o nó.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1428.c
```

---

**Exercício P1429** · ★★★ · O maior caminho da rede de sensores

Os sensores de uma plantação formam uma árvore binária, com a central no
sensor 1. Uma mensagem entre dois sensores percorre o caminho da árvore, e
a engenharia quer o maior caminho possível entre DOIS sensores quaisquer
(o DIÂMETRO da árvore), em arestas, e o sensor onde esse caminho faz a
curva (o nó mais alto dele).


```text
1 tem filhos 2 e 3
2 tem filhos 4 e 5;      3 tem só o filho direito 7
4 tem filhos 8 e 9;      5 tem só o filho direito 10
8 tem só o esquerdo 12;  10 tem só o direito 13;  13 tem só o esquerdo 14
```


Escreva int altura_e_diametro(const No *r, int *diametro, int *curva), que
devolve a altura de r (vazia = -1) e, de passagem, testa o maior caminho
que faz a curva em r: (he + 1) + (hd + 1) arestas. Uma única pós-ordem
resolve tudo em O(n).


```text
Saída esperada:
altura: 5
maior caminho: 7 arestas, fazendo a curva no sensor 2
```

**Dicas:**

1. O caminho mais longo NÃO precisa passar pela raiz: aqui ele vai do 12
   ao 14 e faz a curva no 2.
2. Com altura de vazia = -1, um lado vazio soma (-1 + 1) = 0 arestas.
3. Chamar altura() dentro de uma função de diâmetro recursiva daria O(n²);
   devolver a altura e atualizar o diâmetro na mesma volta dá O(n).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1429.c
```

---

**Exercício P1430** · ★★★ · O heapsort que embaralhava os empates

O resultado da corrida de rua precisa sair por tempo e, no empate, pela
ordem de inscrição (o número de peito). Os inscritos, em ordem:


```text
#101 42 min, #102 38, #103 42, #104 35, #105 38, #106 42, #107 35
```



```text
typedef struct { int numero; int tempo; int ordem; } Corredor;
```


Escreva um heapsort de Corredor (heap de máximo, fase 1 com BUILD e fase 2
trocando a raiz com o fim). Toda comparação passa por
int maior(const Corredor *a, const Corredor *b). Com a global usa_ordem = 0,
maior compara só o tempo; com usa_ordem = 1, desempata pelo campo ordem.
Ordene duas cópias, uma de cada jeito, e mostre as duas.


```text
Saída esperada:
só o tempo  : #104(35) #107(35) #102(38) #105(38) #106(42) #103(42) #101(42)
tempo, ordem: #104(35) #107(35) #102(38) #105(38) #101(42) #103(42) #106(42)
```

**Dicas:**

1. O heapsort NÃO é estável: a troca da raiz com o fim joga elementos para
   longe, por cima dos iguais. Repare nos três de 42 minutos.
2. Com o desempate pelo campo ordem, não existem mais chaves iguais, e a
   estabilidade deixa de importar. É o mesmo truque que se usa com o qsort.
3. Use printf(" #%d(%d)", ...) para cada corredor.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 14-arvores/lista/P1430.c
```

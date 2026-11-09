# Simulados da prova do PPGI

Três simulados de 20 questões cada, no formato das provas mais recentes do PPGI: quatro alternativas (a a d), questões de conceito, de afirmações I, II e III combinadas, de simulação, de cálculo e de código C com erro. O peso de cada tema segue [o que caiu de 2016 a 2023](PPGI.md#o-que-caiu-de-2016-a-2023). As questões são originais, com cenários e valores novos.

Como usar:

- Faça um simulado por vez, cronometrando: 3 minutos por questão, 1 hora no total. Pontuação e nota mínima estão no [resumo do edital](PPGI.md).
- Resolva no papel, sem consultar o curso, e só confira o gabarito no fim, depois de marcar as 20 respostas.
- Para cada erro, abra o link da coluna Estude, releia o assunto e refaça a questão sem olhar a resposta.
- Nas questões de simulação, refaça o passo a passo à mão antes de rodar qualquer coisa.

Os gabaritos estão no fim do arquivo, um por simulado.


## Simulado 1

**01.** Em uma árvore AVL, o fator de balanceamento de um nó é altura(esquerda) - altura(direita). Depois de uma inserção, o nó P fica com fator +2 e o filho esquerdo de P fica com fator -1. Marque a alternativa CORRETA.

- a) Rotação simples à direita em P, apenas.
- b) Rotação simples à esquerda em P, apenas.
- c) Rotação dupla: primeiro uma rotação à esquerda no filho esquerdo de P, depois uma rotação à direita em P.
- d) Nenhuma rotação: basta recalcular os fatores de balanceamento dos ancestrais.

**02.** Considere as afirmações sobre árvores binárias de busca (ABB).

I. O percurso em pré-ordem de uma ABB visita as chaves em ordem crescente.  
II. Na remoção de um nó com dois filhos, ele pode ser substituído pelo sucessor em ordem, que é o menor nó da subárvore direita e não tem filho esquerdo.  
III. Inserir as mesmas n chaves em qualquer ordem produz sempre a mesma ABB.

- a) Apenas II.
- b) Apenas I e II.
- c) Apenas II e III.
- d) Apenas III.

**03.** Uma ABB inicialmente vazia recebe as chaves, nesta ordem: 44, 18, 62, 9, 27, 51, 80, 23, 33, 56. Qual é o percurso em pós-ordem da árvore resultante?

- a) 9 18 23 27 33 44 51 56 62 80
- b) 44 18 9 27 23 33 62 51 56 80
- c) 9 23 33 27 18 56 80 51 62 44
- d) 9 23 33 27 18 56 51 80 62 44

**04.** Uma AVL, inicialmente vazia, recebe as chaves 30, 10, 20, 40, 50, 25, 35, nesta ordem, com as rotações necessárias a cada inserção. Qual é o percurso em pré-ordem da árvore final?

- a) 30 10 20 25 40 35 50
- b) 30 20 10 25 40 35 50
- c) 20 10 30 25 40 35 50
- d) 40 30 20 10 25 35 50

**05.** Um heap de máximo está armazenado no vetor (índices a partir de 0) 90 70 80 40 50 60 30 10 20. Insere-se a chave 85 (no fim do vetor, subindo enquanto for maior que o pai) e em seguida remove-se o máximo (o último elemento vai para a raiz e desce, trocando com o maior filho). Qual é o vetor final?

- a) 80 70 60 40 50 20 30 10 85
- b) 50 85 80 40 70 60 30 10 20
- c) 90 85 80 40 70 60 30 10 20
- d) 85 70 80 40 50 60 30 10 20

**06.** Sobre árvores rubro-negras, marque a alternativa INCORRETA.

- a) A raiz é preta.
- b) Um nó vermelho pode ter filho vermelho, desde que o neto seja preto.
- c) Todo caminho de um nó até uma folha descendente (NIL) tem o mesmo número de nós pretos.
- d) Nenhum caminho da raiz até uma folha é mais que o dobro de outro.

**07.** Qual é a menor altura possível, em número de arestas do maior caminho da raiz a uma folha, de uma árvore binária com 200 nós?

- a) 7
- b) 6
- c) 8
- d) 100

**08.** Considere um grafo não dirigido com vértices 0 a 6 e arestas 0-3, 0-2, 3-1, 3-5, 2-4, 2-6, 5-4 e 1-6. Uma busca em largura (BFS) com fila começa no vértice 0 e visita os vizinhos de cada vértice em ordem crescente. Em que ordem os vértices saem da fila?

- a) 0 2 4 5 3 1 6
- b) 0 2 3 1 4 5 6
- c) 0 2 3 4 6 1 5
- d) 0 3 2 1 5 4 6

**09.** Considere as afirmações sobre listas encadeadas.

I. Em uma lista duplamente encadeada, remover um nó cujo endereço já se conhece é feito em tempo constante, sem percorrer a lista desde o início.  
II. Em uma lista circular simples, a busca por um valor ausente termina ao encontrar NULL.  
III. Em uma lista circular, a travessia deve parar ao voltar ao nó de partida.

- a) Apenas I.
- b) Apenas II e III.
- c) Todas as afirmações são verdadeiras.
- d) Apenas I e III.

**10.** A expressão em notação pós-fixa 6 2 3 + * 4 - 2 / é avaliada com uma pilha (divisão inteira). Qual é o resultado?

- a) 26
- b) 11
- c) 13
- d) 8

**11.** A função abaixo insere um valor no fim de uma lista simplesmente encadeada. Considere a chamada insere_fim(&lista, 5) com No *lista = NULL. Marque a alternativa CORRETA.

```c
typedef struct no { int dado; struct no *prox; } No;

void insere_fim(No **prim, int d) {
    No *novo = malloc(sizeof(No));
    novo->dado = d;
    novo->prox = NULL;
    No *p = *prim;
    while (p->prox != NULL) p = p->prox;
    p->prox = novo;
}
```

- a) A função cria o primeiro nó e a lista passa a conter o valor 5.
- b) A lista vazia não é tratada: p vale NULL, p->prox acessa memória inválida e o programa falha por violação de segmento.
- c) O código não compila, porque um ponteiro duplo não pode ser lido com *prim.
- d) A função funciona, mas vaza memória, porque o nó novo nunca é liberado.

**12.** Considere as afirmações.

I. Uma pilha resolve a verificação de parênteses e colchetes balanceados em uma única passada pela cadeia.  
II. Uma fila pode ser implementada com duas pilhas.  
III. Em uma fila, o primeiro elemento a sair é o último que entrou.

- a) Apenas I e II.
- b) Apenas I.
- c) Apenas II e III.
- d) Todas as afirmações são verdadeiras.

**13.** Um conjunto de registros é ordenado por nota e se quer manter, entre notas iguais, a ordem original de chegada. Qual dos algoritmos abaixo, em sua versão clássica, tem essa propriedade (é estável)?

- a) Selection sort.
- b) Heapsort.
- c) Insertion sort.
- d) Quicksort com partição de Hoare.

**14.** Considere as afirmações sobre ordenação.

I. O selection sort faz sempre n(n-1)/2 comparações, qualquer que seja a entrada.  
II. No melhor caso (vetor já ordenado), o insertion sort faz n-1 comparações.  
III. O merge sort para vetores usa memória auxiliar proporcional a n, enquanto o heapsort ordena no próprio vetor.

- a) Todas as afirmações são verdadeiras.
- b) Apenas I e II.
- c) Apenas II e III.
- d) Apenas I.

**15.** Considere o vetor 7 3 9 1 5 8 2 e as afirmações.

I. O vetor tem 12 inversões, que é também o total de deslocamentos feitos pelo insertion sort.  
II. O selection sort faz 21 comparações para ordená-lo.  
III. O selection sort faz exatamente 6 trocas para ordená-lo.

- a) Apenas I.
- b) Apenas II e III.
- c) Todas as afirmações são verdadeiras.
- d) Apenas I e II.

**16.** Uma tabela hash com encadeamento tem m = 7 posições e função h(k) = k mod 7. Cada chave nova entra no início da lista da sua posição. Inseridas, nesta ordem, as chaves 25, 38, 11, 52, 17, 30, 46, 9 e 60, como fica a lista da posição 4, lida do início ao fim?

- a) 25, 11, 46, 60
- b) 60, 46, 11, 25
- c) 17, 52, 38
- d) 60, 46, 25, 11

**17.** Sobre a remoção em uma tabela hash com endereçamento aberto e sondagem linear, marque a alternativa CORRETA.

- a) Esvaziar simplesmente a posição pode interromper a busca de chaves que colidiram e foram guardadas adiante; por isso se usa uma marca de posição removida.
- b) A remoção não tem problema algum, porque a busca sempre percorre a tabela inteira.
- c) O problema só existe no encadeamento, que precisa religar as listas.
- d) A remoção exige recalcular a função de hash de todas as chaves da tabela.

**18.** Uma busca binária é feita em um vetor ordenado de 5000 elementos. No pior caso, quantas comparações de chave ela faz?

- a) 12
- b) 14
- c) 13
- d) 2500

**19.** Para guardar n chaves em memória, comparam-se um vetor ordenado, uma AVL e uma tabela hash com encadeamento (inserção no início da lista, sem verificar repetição). Quais são os custos de pior caso de inserção, remoção e busca, nessa ordem? Marque a alternativa CORRETA.

- a) Vetor ordenado: O(log n) nas três. AVL: O(log n) nas três. Hash: O(1) nas três.
- b) Vetor ordenado: O(n), O(n), O(log n). AVL: O(n), O(n), O(log n). Hash: O(1), O(n), O(n).
- c) Vetor ordenado: O(n) nas três. AVL: O(log n) nas três. Hash: O(n) nas três.
- d) Vetor ordenado: O(n), O(n), O(log n). AVL: O(log n), O(log n), O(log n). Hash: O(1), O(n), O(n).

**20.** A função abaixo deve contar os bits 1 de um inteiro com sinal. Em um compilador em que o deslocamento à direita de um número negativo repete o bit de sinal (caso do gcc), o que acontece com conta_bits(-1)?

```c
int conta_bits(int x) {
    int c = 0;
    while (x != 0) {
        c += x & 1;
        x >>= 1;
    }
    return c;
}
```

- a) Devolve 32, o total de bits de um int.
- b) O laço nunca termina: x continua valendo -1 depois de cada deslocamento. A correção é usar unsigned.
- c) Devolve 31, porque o bit de sinal não é contado.
- d) Devolve 0, porque -1 é negativo.

---

## Simulado 2

**01.** O percurso em pré-ordem de uma árvore binária é M K A R T L P e o percurso em ordem é A K R T M P L (todas as chaves são distintas). Qual é o percurso em pós-ordem?

- a) A K R T P L M
- b) A T R K P L M
- c) T A R K P L M
- d) A T R K L P M

**02.** Em uma árvore rubro-negra, o nó inserido é colorido de vermelho. Por quê? Marque a alternativa CORRETA.

- a) Porque assim a raiz continua preta.
- b) Porque nós vermelhos dispensam rotações em qualquer caso.
- c) Porque a altura da árvore é medida só pelos nós vermelhos.
- d) Porque um nó vermelho não altera a altura negra de nenhum caminho; só pode violar a regra de pai e filho vermelhos, que se corrige por recoloração e rotações.

**03.** Considere as afirmações sobre árvores AVL.

I. A remoção pode exigir rotações em mais de um nó no caminho até a raiz.  
II. Toda AVL é uma ABB, mas nem toda ABB é uma AVL.  
III. Com n nós, uma AVL pode chegar a altura próxima de n/2.

- a) Apenas I e II.
- b) Apenas II e III.
- c) Todas as afirmações são verdadeiras.
- d) Apenas I.

**04.** O vetor 5 12 3 18 7 14 9 16 (índices a partir de 0) é transformado em um heap de máximo pelo método de baixo para cima: a partir do último nó interno até a raiz, cada nó desce enquanto for menor que o maior filho. Qual é o vetor resultante?

- a) 12 18 3 16 7 14 9 5
- b) 12 18 14 16 7 3 9 5
- c) 18 16 14 12 7 3 9 5
- d) 18 12 14 16 7 3 9 5

**05.** Sobre árvores B, Marque a alternativa CORRETA.

- a) Todo nó tem exatamente dois filhos.
- b) A altura aumenta toda vez que uma folha é dividida.
- c) Todas as folhas ficam no mesmo nível, e a altura só aumenta quando a raiz é dividida.
- d) É usada sobretudo em memória principal, porque as divisões são mais baratas que as rotações.

**06.** Uma árvore AVL de altura 6 (altura medida em arestas) tem, no mínimo, quantos nós?

- a) 33
- b) 21
- c) 32
- d) 64

**07.** Uma ABB recebe, nesta ordem, as chaves 55, 30, 80, 20, 45, 70, 90 e 40. Considere as afirmações.

I. O percurso em pós-ordem é 20 40 45 30 70 90 80 55.  
II. O percurso em pré-ordem é 55 30 80 20 45 70 90 40.  
III. A chave 40 é filho esquerdo de 45 e a altura da árvore, em arestas, é 3.

- a) Apenas I.
- b) Apenas II e III.
- c) Todas as afirmações são verdadeiras.
- d) Apenas I e III.

**08.** Uma fila circular em um vetor de 5 posições começa vazia, com ini = fim = 0. Enfileirar faz v[fim] = x e fim = (fim + 1) % 5; desenfileirar faz ini = (ini + 1) % 5 e não apaga o valor. Executam-se: enfileirar A, B, C, D; desenfileirar duas vezes; enfileirar E, F, G. Ao final, quais são o vetor v[0..4], ini e fim?

- a) v = A B C D E, ini = 2, fim = 0.
- b) v = F G C D E, ini = 2, fim = 2 (fila cheia).
- c) v = F G C D E, ini = 0, fim = 2.
- d) v = F G C D E, ini = 3, fim = 2.

**09.** O código abaixo insere um nó depois de p em uma lista duplamente encadeada. Antes da chamada, a lista é 1 <-> 2 <-> 3 e p aponta para o nó 1. Percorrendo a lista do início ao fim e, depois, do fim ao início, o que se obtém? Marque a alternativa CORRETA.

```c
void insere_depois(No *p, int d) {
    No *novo = malloc(sizeof(No));
    novo->dado = d;
    novo->prox = p->prox;
    novo->ant = p;
    p->prox = novo;
}
```

- a) Ida: 1 9 2 3. Volta: 3 9 2 1.
- b) O código não compila, porque falta devolver o novo nó.
- c) Ida: 1 9 2 3. Volta: 3 2 1. O campo ant do nó 2 continua apontando para o nó 1.
- d) Ida: 1 2 3 9. Volta: 9 3 2 1.

**10.** Qual estrutura permite conferir, em uma única passada de custo O(n), se uma cadeia de parênteses, colchetes e chaves está balanceada?

- a) Uma pilha: empilha cada abertura e, a cada fechamento, desempilha e compara.
- b) Uma fila: o primeiro delimitador aberto é o primeiro a ser fechado.
- c) Uma lista circular com ponteiro para o último nó.
- d) Uma tabela hash indexada pelo tipo de delimitador.

**11.** Considere as afirmações.

I. Inserir no meio de um vetor leva tempo constante, porque o acesso por índice é direto.  
II. Inserir no início de uma lista simplesmente encadeada leva tempo constante.  
III. Em uma lista simplesmente encadeada, é possível percorrer do último nó ao primeiro seguindo apenas os ponteiros prox.

- a) Apenas I e II.
- b) Apenas II.
- c) Apenas II e III.
- d) Apenas III.

**12.** Sobre filas e deques, Marque a alternativa INCORRETA.

- a) Uma fila segue a ordem FIFO.
- b) Um deque permite inserir e remover nas duas extremidades.
- c) Uma fila circular em vetor reaproveita as posições liberadas pelas remoções.
- d) Uma fila de prioridade sempre atende os elementos na ordem de chegada.

**13.** Sobre o merge sort em vetores, Marque a alternativa CORRETA.

- a) Faz Θ(n log n) comparações em qualquer entrada e precisa de memória auxiliar proporcional a n.
- b) Ordena no próprio vetor, com memória auxiliar constante.
- c) Tem pior caso quadrático quando o vetor já está ordenado.
- d) É sempre instável.

**14.** Considere as afirmações.

I. O quicksort que escolhe sempre o primeiro elemento como pivô faz O(n²) comparações em um vetor já ordenado.  
II. O heapsort tem pior caso O(n log n) e ordena no próprio vetor.  
III. O radix sort por dígito menos significativo precisa que a ordenação de cada dígito seja estável.

- a) Apenas I.
- b) Apenas I e II.
- c) Apenas II e III.
- d) Todas as afirmações são verdadeiras.

**15.** Considere o vetor 14 7 21 3 18 9 e as afirmações.

I. Depois de duas passadas do selection sort, o vetor é 3 7 9 14 18 21.  
II. Depois de inserir o quarto elemento (i = 3) com o insertion sort, o vetor é 3 7 14 18 21 9.  
III. O vetor tem 8 inversões, o mesmo número de deslocamentos do insertion sort.

- a) Apenas I.
- b) Apenas III.
- c) Apenas II e III.
- d) Apenas I e II.

**16.** Uma tabela hash com endereçamento aberto tem m = 11 posições, função h(k) = k mod 11 e sondagem linear (tenta a posição seguinte, de forma circular). Inseridas, nesta ordem, as chaves 25, 36, 22, 14, 11 e 47, em que posições ficam a chave 11 e a chave 47?

- a) 11 na posição 0 e 47 na posição 3.
- b) 11 na posição 1 e 47 na posição 5.
- c) 11 na posição 1 e 47 na posição 6.
- d) 11 na posição 2 e 47 na posição 6.

**17.** Considere as afirmações sobre tabelas hash.

I. No endereçamento aberto, o fator de carga pode ultrapassar 1.  
II. No encadeamento, com função de hash uniforme, a busca leva tempo esperado Θ(1 + α), em que α é o fator de carga.  
III. A sondagem linear sofre de agrupamento primário.

- a) Apenas I e II.
- b) Apenas II e III.
- c) Apenas III.
- d) Todas as afirmações são verdadeiras.

**18.** Sobre o custo de pior caso de busca, inserção e remoção entre n chaves, Marque a alternativa CORRETA.

- a) Em um vetor ordenado, a inserção é O(log n), porque a posição é achada por busca binária.
- b) Em uma tabela hash com encadeamento, a busca é O(1) no pior caso, qualquer que seja a função de hash.
- c) Em uma AVL, a remoção pode custar O(n), por causa das rotações em cascata.
- d) Em uma ABB comum as três operações são O(n); em uma AVL, as três são O(log n).

**19.** Em um vetor não ordenado de 999 chaves distintas, faz-se uma busca sequencial por uma chave que está presente, com todas as posições igualmente prováveis. Qual é o número médio de comparações?

- a) 999
- b) 499
- c) 500
- d) 250

**20.** Um grafo dirigido tem vértices 0 a 5 e arestas (origem → destino : peso): 0→1:7, 0→2:3, 2→1:2, 1→3:5, 2→3:9, 2→4:8, 4→3:1, 3→5:4 e 4→5:6. Pelo algoritmo de Dijkstra, qual é a menor distância de 0 a 5?

- a) 14
- b) 16
- c) 17
- d) 12

---

## Simulado 3

**01.** Uma AVL, inicialmente vazia, recebe as chaves 12, 24, 36, 48, 60, 72, 84 e 96, nesta ordem, com as rotações necessárias. Qual é o percurso em pré-ordem da árvore final?

- a) 12 24 36 48 60 72 84 96
- b) 48 24 12 36 84 72 60 96
- c) 36 24 12 72 48 60 84 96
- d) 48 24 12 36 72 60 84 96

**02.** Sobre heaps binários, Marque a alternativa CORRETA.

- a) O maior elemento de um heap de máximo fica na raiz, e removê-lo custa O(log n).
- b) Buscar uma chave qualquer custa O(log n).
- c) Todo heap de máximo é uma árvore binária de busca.
- d) Inserir um elemento custa O(n), porque todo o vetor é reordenado.

**03.** Considere as afirmações sobre árvores rubro-negras.

I. Um nó vermelho não pode ter filho vermelho.  
II. Com n nós, a árvore pode ter altura próxima de n/2.  
III. A inserção usa no máximo duas rotações.

- a) Apenas I.
- b) Apenas II e III.
- c) Apenas I e III.
- d) Todas as afirmações são verdadeiras.

**04.** Em uma árvore B de grau mínimo t = 4 (cada nó tem no máximo 7 chaves e no máximo 8 filhos), qual é o número máximo de chaves de uma árvore com três níveis (raiz mais dois níveis abaixo)?

- a) 73
- b) 511
- c) 255
- d) 21

**05.** Em uma ABB, procura-se a chave 47. Qual das sequências abaixo NÃO pode ser a das chaves visitadas até encontrá-la?

- a) 20 70 30 60 40 50 47
- b) 60 20 55 30 50 25 47
- c) 35 80 41 70 50 49 47
- d) 100 25 75 30 65 44 47

**06.** Uma ABB recebe, nesta ordem, as chaves 45, 20, 60, 10, 30, 50, 70, 25, 35 e 55. Em seguida remove-se o 20 e depois o 45; na remoção de um nó com dois filhos, usa-se o sucessor em ordem. Qual é o percurso em pré-ordem final?

- a) 50 25 10 30 35 60 55 70
- b) 35 10 30 25 60 50 55 70
- c) 50 25 10 30 35 60 70 55
- d) 45 25 10 30 35 60 50 55 70

**07.** Considere as afirmações sobre árvores B.

I. A árvore cresce pelas folhas e por isso pode ficar desbalanceada, como uma ABB.  
II. Quando um nó cheio recebe uma chave, ele é dividido e a chave mediana sobe para o pai.  
III. Com grau mínimo t, a altura é O(log_t n), o que reduz o número de acessos a disco.

- a) Apenas I.
- b) Apenas I e II.
- c) Apenas I e III.
- d) Apenas II e III.

**08.** Uma fila é feita com duas pilhas, P1 e P2. Enfileirar empilha em P1. Desenfileirar, se P2 estiver vazia, desempilha tudo de P1 para P2 e depois desempilha o topo de P2. Executam-se: enfileirar 5, 8, 2; desenfileirar; enfileirar 7, 1; desenfileirar. Ao final, quais são o conteúdo de P1 e P2 (da base ao topo) e o valor devolvido pelo último desenfileirar?

- a) P1 = [7, 1]; P2 = [8, 2]; devolveu 5.
- b) P1 = [1, 7]; P2 = [2]; devolveu 8.
- c) P1 = [7, 1]; P2 = [2]; devolveu 8.
- d) P1 = [7, 1]; P2 = [2, 8]; devolveu 5.

**09.** Considere as afirmações sobre listas encadeadas.

I. Em uma lista circular simples, a busca de um valor ausente termina ao encontrar NULL.  
II. Em uma lista duplamente encadeada, inserir no início é O(n), porque o campo ant de todos os nós precisa ser atualizado.  
III. Em uma lista com sentinela, remover o primeiro elemento dispensa um caso especial.

- a) Apenas I e II.
- b) Apenas III.
- c) Apenas II e III.
- d) Todas as afirmações são verdadeiras.

**10.** Em uma fila circular em vetor de N posições, controlada só pelos índices ini e fim (sem contador), como distinguir fila cheia de fila vazia? Marque a alternativa CORRETA.

- a) Declarando a fila cheia quando fim == ini, e vazia quando fim == ini também.
- b) Zerando ini e fim a cada enfileiramento.
- c) Incrementando fim sem usar o resto da divisão por N.
- d) Deixando sempre uma posição livre: a fila está cheia quando (fim + 1) % N == ini e vazia quando fim == ini, e a capacidade útil é N - 1.

**11.** Um grafo não dirigido tem 10.000 vértices e 30.000 arestas. Para guardá-lo, marque a alternativa CORRETA.

- a) A lista de adjacência é melhor: ocupa O(V + E), cerca de 40 mil entradas, contra 100 milhões da matriz.
- b) A matriz de adjacência é melhor, porque consultar uma aresta em O(1) compensa sempre o espaço.
- c) A matriz de adjacência ocupa O(V + E).
- d) A lista de adjacência ocupa O(V²).

**12.** O código abaixo implementa uma fila encadeada. Considere a sequência: fila vazia, enfileira(&f, 5), desenfileira(&f), enfileira(&f, 9). Marque a alternativa CORRETA.

```c
typedef struct no { int dado; struct no *prox; } No;
typedef struct { No *ini; No *fim; } Fila;

void enfileira(Fila *f, int d) {
    No *novo = malloc(sizeof(No));
    novo->dado = d;
    novo->prox = NULL;
    if (f->fim != NULL) f->fim->prox = novo;
    else f->ini = novo;
    f->fim = novo;
}

int desenfileira(Fila *f) {
    No *aux = f->ini;
    int v = aux->dado;
    f->ini = aux->prox;
    free(aux);
    return v;
}
```

- a) Não há erro: depois de desenfileirar, enfileira(&f, 9) cria o novo primeiro nó.
- b) O erro é vazamento de memória, porque desenfileira não libera o nó removido.
- c) Ao esvaziar a fila, f->fim continua apontando para o nó liberado: enfileira(&f, 9) grava nesse nó, f->ini permanece NULL e o 9 se perde.
- d) O erro é que desenfileira deveria devolver f->fim->dado.

**13.** O vetor 534 82 215 907 46 361 128 é ordenado por radix sort LSD em base 10, com ordenação estável por dígito, começando pelas unidades. Qual é o vetor ao final da segunda passada (dígito das dezenas)?

- a) 907 215 128 534 46 361 82
- b) 361 82 534 215 46 907 128
- c) 46 82 128 215 361 534 907
- d) 907 215 128 534 46 82 361

**14.** Sobre limites da ordenação, Marque a alternativa INCORRETA.

- a) Toda ordenação baseada em comparações faz Ω(n log n) comparações no pior caso.
- b) O merge sort e o heapsort são assintoticamente ótimos entre os métodos por comparação.
- c) Um quicksort com pivô aleatório garante O(n log n) no pior caso.
- d) O counting sort pode rodar em O(n + k) porque não se baseia em comparações entre chaves.

**15.** Considere o vetor 4 9 1 7 3 8 e as afirmações.

I. O insertion sort é estável.  
II. O vetor tem 7 inversões.  
III. O insertion sort faz 9 deslocamentos para ordená-lo.

- a) Apenas I.
- b) Apenas II e III.
- c) Todas as afirmações são verdadeiras.
- d) Apenas I e II.

**16.** Uma tabela hash com encadeamento tem m = 10 posições e h(k) = k mod 10. Inseridas as chaves 15, 25, 35, 20, 45, 30, 55 e 40, sempre no fim da lista da posição, quantas comparações de chave são feitas ao buscar, uma vez cada, as 8 chaves, somadas?

- a) 36
- b) 21
- c) 8
- d) 15

**17.** Sobre funções de hash por divisão, h(k) = k mod m, marque a alternativa CORRETA.

- a) Com m potência de 2, a distribuição é melhor, porque o resto vira um deslocamento.
- b) Com m par, chaves ímpares nunca colidem.
- c) A escolha de m não influencia a distribuição das chaves.
- d) Com m = 2^p, h(k) depende só dos p bits menos significativos da chave; costuma-se preferir m primo, longe de potências de 2.

**18.** Em um vetor ordenado de 15 posições (índices 0 a 14) com os valores 3 8 11 14 19 23 28 31 36 42 47 53 59 64 70, faz-se uma busca binária pela chave 36, com meio = (inicio + fim) / 2 (divisão inteira). Quais índices são examinados, na ordem?

- a) 7, 3, 5, 4
- b) 7, 11, 10, 9, 8
- c) 7, 11, 9, 8
- d) 7, 9, 8

**19.** Considere as afirmações sobre custo de pior caso.

I. Em um vetor ordenado, a inserção é O(log n), porque a posição é achada por busca binária.  
II. Em uma tabela hash com encadeamento, a busca é O(n) no pior caso.  
III. Em uma tabela hash com encadeamento e m ≥ n, a busca é O(1) no pior caso.

- a) Apenas II.
- b) Apenas I e III.
- c) Apenas II e III.
- d) Todas as afirmações são verdadeiras.

**20.** A função aloca deveria reservar um vetor de n inteiros para o ponteiro v de main. O que ocorre ao executar o programa? Marque a alternativa CORRETA.

```c
void aloca(int **p, int n) {
    p = malloc(n * sizeof(int));
}

int main(void) {
    int *v = NULL;
    aloca(&v, 5);
    v[0] = 10;
    printf("%d\n", v[0]);
    free(v);
    return 0;
}
```

- a) O programa funciona e imprime 10.
- b) A atribuição vai para o parâmetro local p; v continua NULL e v[0] = 10 falha. O correto é *p = malloc(...).
- c) O código não compila, porque malloc devolve int ** nesse caso.
- d) O programa funciona, mas vaza memória, porque falta free(p).

---

## Gabarito

Só abra depois de terminar os três simulados, ou o simulado do dia.

### Simulado 1

| Q | Letra | Por quê | Estude |
|---|---|---|---|
| 01 | C | Fator +2 com filho de sinal oposto (-1) é o caso esquerda-direita: a rotação simples à direita deixaria o desequilíbrio do outro lado, por isso o filho gira antes. | [0101](14-arvores.md) |
| 02 | A | I é falsa (a ordem crescente sai do percurso em ordem), III é falsa (a ordem de inserção muda a forma da árvore); II descreve a remoção com sucessor. | [0098](14-arvores.md), [0100](14-arvores.md) |
| 03 | D | Em pós-ordem cada nó vem depois das duas subárvores: a esquerda de 44 termina em 18, a direita em 62, e a raiz fecha a lista; conferido em C. | [0098](14-arvores.md), [0099](14-arvores.md) |
| 04 | B | A inserção do 20 faz uma rotação dupla e a do 25 outra, que leva o 30 de volta à raiz; sem balanceamento (primeira opção) a árvore seria a ABB comum. Conferido com uma AVL em C. | [0101](14-arvores.md) |
| 05 | D | O 85 sobe trocando com o 50 e com o 70 e para abaixo do 90; ao remover o 90, o último elemento (50) vai para a raiz e desce, e o 85 assume o topo. Conferido em C. | [0102](14-arvores.md), [0103](14-arvores.md) |
| 06 | B | Nó vermelho só pode ter filhos pretos; as outras três são propriedades da árvore (a terceira vem da altura negra). | [0145](22-arvores-avancadas.md), [0177](28-estruturas-complementos.md) |
| 07 | A | Altura 6 comporta no máximo 127 nós, altura 7 comporta até 255: ⌊log2 200⌋ = 7. Conferido em C. | [0097](14-arvores.md), [0098](14-arvores.md) |
| 08 | C | O 2 e o 3 entram primeiro; o 2 descobre 4 e 6, o 3 descobre 1 e 5. A primeira opção é a ordem de uma busca em profundidade (DFS). Conferido em C. | [0110](16-grafos.md), [0111](16-grafos.md) |
| 09 | D | II é falsa: na lista circular não há NULL, e o laço que o espera nunca termina. | [0079](11-listas.md), [0080](11-listas.md) |
| 10 | C | 2 3 + vira 5; 6 5 * vira 30; 30 4 - vira 26; 26 2 / vira 13. Conferido em C com uma pilha. | [0084](12-pilhas-e-filas.md), [0082](12-pilhas-e-filas.md) |
| 11 | B | Faltava o caso *prim == NULL (fazer *prim = novo). Rodando a chamada em C, o programa termina com falha de segmentação. | [0076](11-listas.md), [0077](11-listas.md) |
| 12 | A | III descreve uma pilha (LIFO), não uma fila (FIFO). | [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md), [0084](12-pilhas-e-filas.md) |
| 13 | C | O insertion sort só desloca elementos maiores que a chave, então iguais nunca se cruzam; selection, heap e quick trocam elementos distantes e quebram a ordem dos iguais. | [0093](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) |
| 14 | A | As três são resultados clássicos: o selection sort varre sempre o restante, o insertion sort para na primeira comparação quando o vetor está ordenado, e só o merge sort exige o vetor auxiliar. | [0092](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md), [0094](13-busca-e-ordenacao.md), [0103](14-arvores.md) |
| 15 | D | Contando em C: 12 inversões, 21 comparações (7·6/2) e só 4 trocas, porque o selection sort não troca quando o mínimo já está na posição. III é falsa. | [0092](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md) |
| 16 | B | Caem na posição 4 as chaves 25, 11, 46 e 60; como a inserção é no início, a última (60) fica na frente. Conferido em C. | [0106](15-hash.md) |
| 17 | A | A busca para na primeira posição vazia; se uma chave removida estava no meio de uma sequência de colisões, as seguintes ficam inalcançáveis. | [0107](15-hash.md) |
| 18 | C | ⌊log2 5000⌋ + 1 = 12 + 1 = 13. Simulando todas as chaves possíveis em C, o máximo foi 13. | [0090](13-busca-e-ordenacao.md), [0072](10-analise.md) |
| 19 | D | O vetor desloca elementos para inserir e remover, mas acha a posição por busca binária; a AVL mantém a altura logarítmica; no pior caso todas as chaves caem na mesma lista do hash. | [0071](10-analise.md), [0072](10-analise.md), [0101](14-arvores.md), [0106](15-hash.md) |
| 20 | B | Com o bit de sinal replicado, -1 vira -1 a cada >>=1 e x != 0 vale sempre. Rodei a função em C: sem o limite de 100 voltas, não para; com unsigned, devolve 32. | [0171](27-c-detalhes.md), [0170](27-c-detalhes.md) |

### Simulado 2

| Q | Letra | Por quê | Estude |
|---|---|---|---|
| 01 | B | O pré-ordem dá a raiz (M); o em ordem separa a esquerda (A K R T) da direita (P L). Repetindo em cada lado, a pós-ordem sai A T R K P L M. Reconstruí a árvore em C para conferir. | [0098](14-arvores.md) |
| 02 | D | A inserção em preto quebraria a contagem de nós pretos em todos os caminhos da subárvore; em vermelho, o pior que acontece é um pai vermelho. | [0145](22-arvores-avancadas.md), [0177](28-estruturas-complementos.md) |
| 03 | A | III é falsa: a altura de uma AVL é O(log n). I vale para a remoção, ao contrário da inserção, que corrige com no máximo uma rotação (simples ou dupla). | [0101](14-arvores.md), [0176](28-estruturas-complementos.md) |
| 04 | C | Os nós internos são os índices 3, 2, 1 e 0, nessa ordem; a terceira opção não é nem heap (o 12 tem o filho 16 maior). Conferido em C. | [0102](14-arvores.md), [0103](14-arvores.md) |
| 05 | C | A árvore B cresce pela raiz, o que mantém as folhas todas na mesma profundidade; o grau alto do nó serve para reduzir acessos a disco. | [0146](22-arvores-avancadas.md) |
| 06 | A | Com N(0) = 1 e N(1) = 2, vale N(h) = N(h-1) + N(h-2) + 1: 1, 2, 4, 7, 12, 20, 33. Conferido em C. | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) |
| 07 | D | A sequência de II é o percurso por nível, não o pré-ordem (que é 55 30 20 45 40 80 70 90). Conferido em C. | [0098](14-arvores.md), [0099](14-arvores.md) |
| 08 | B | Os dois primeiros desenfileiramentos tiram A e B; E ocupa a posição 4 e F e G voltam às posições 0 e 1. Conferido em C. | [0085](12-pilhas-e-filas.md), [0086](12-pilhas-e-filas.md) |
| 09 | C | Faltou atualizar p->prox->ant (do antigo sucessor) para o nó novo. Rodando em C, a ida mostra 1 9 2 3 e a volta pula o 9. | [0079](11-listas.md) |
| 10 | A | O delimitador aberto mais recentemente é o primeiro a precisar fechar, que é a ordem LIFO da pilha. | [0084](12-pilhas-e-filas.md), [0082](12-pilhas-e-filas.md) |
| 11 | B | I é falsa (os elementos seguintes precisam ser deslocados) e III é falsa (prox só aponta para frente). | [0075](11-listas.md), [0076](11-listas.md) |
| 12 | D | A fila de prioridade atende o de maior (ou menor) prioridade primeiro, independentemente de quando chegou. | [0085](12-pilhas-e-filas.md), [0087](12-pilhas-e-filas.md), [0102](14-arvores.md) |
| 13 | A | As divisões em metades são sempre log n níveis, e a intercalação precisa de um vetor auxiliar; tomando o elemento da esquerda nos empates, ele é estável. | [0094](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) |
| 14 | D | No vetor ordenado a partição com o primeiro elemento deixa um lado vazio a cada passo (n + (n-1) + ...); o radix depende da estabilidade para não desfazer a ordem do dígito anterior. | [0095](13-busca-e-ordenacao.md), [0103](14-arvores.md), [0121](18-ordenacao-linear.md) |
| 15 | B | Em C: após duas passadas do selection o vetor é 3 7 21 14 18 9; o insertion chega a 3 7 14 21 18 9 em i = 3; há 8 inversões e 8 deslocamentos. Só III é verdadeira. | [0092](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md) |
| 16 | C | 11 mod 11 = 0, mas o 22 ocupa a posição 0, então vai para a 1; o 47 cai em 3 e segue por 4 (36) e 5 (14) até a 6. Conferido em C. | [0107](15-hash.md) |
| 17 | B | I é falsa: no endereçamento aberto cada chave ocupa uma posição da tabela, então n ≤ m. | [0105](15-hash.md), [0106](15-hash.md), [0107](15-hash.md) |
| 18 | D | A ABB pode virar uma lista; a AVL mantém a altura logarítmica e cada rotação é O(1), com no máximo uma por nível; o vetor ainda precisa deslocar elementos. | [0071](10-analise.md), [0072](10-analise.md), [0099](14-arvores.md), [0101](14-arvores.md) |
| 19 | C | A média de 1, 2, ..., n é (n + 1) / 2 = 500. Conferido em C. | [0089](13-busca-e-ordenacao.md), [0072](10-analise.md) |
| 20 | A | O caminho 0→2→1→3→5 custa 3 + 2 + 5 + 4 = 14; os outros custam 16 ou mais. O Dijkstra extraiu os vértices na ordem 0, 2, 1, 3, 4, 5. Conferido em C. | [0112](16-grafos.md) |

### Simulado 3

| Q | Letra | Por quê | Estude |
|---|---|---|---|
| 01 | D | Chaves crescentes só provocam rotações simples à esquerda; a raiz acaba sendo o 48, com altura 3. Conferido com uma AVL em C. | [0101](14-arvores.md) |
| 02 | A | A raiz guarda o máximo e a reorganização após a remoção percorre um caminho da raiz até uma folha. O heap não ordena os irmãos, então não serve de ABB. | [0102](14-arvores.md) |
| 03 | C | II é falsa: a altura é no máximo 2 log2(n + 1). | [0145](22-arvores-avancadas.md), [0177](28-estruturas-complementos.md) |
| 04 | B | Há 1 + 8 + 64 = 73 nós de 7 chaves cada: 73 × 7 = 511 (também 8³ - 1). Conferido em C. | [0146](22-arvores-avancadas.md) |
| 05 | B | Depois de 30 (à direita de 20) e 50 (à esquerda de 55), os valores seguintes precisam ficar entre 30 e 50; o 25 está fora do intervalo. As outras três respeitam os intervalos. Verifiquei as quatro em C. | [0099](14-arvores.md) |
| 06 | A | O 20 é trocado pelo 25 (sucessor) e o 45, pelo 50, cujo filho 55 sobe para o lugar dele. A primeira opção usaria o antecessor; a última é o estado depois só da primeira remoção. Conferido em C. | [0100](14-arvores.md) |
| 07 | D | I é falsa: a árvore B cresce pela raiz, quando ela é dividida, e as folhas ficam sempre no mesmo nível. | [0146](22-arvores-avancadas.md) |
| 08 | C | A primeira transferência deixa P2 = [2, 8, 5] e o primeiro desenfileirar devolve 5; o segundo devolve 8 sem nova transferência, porque P2 não estava vazia. Conferido em C. | [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md) |
| 09 | B | I é falsa (não há NULL no meio de uma lista circular) e II é falsa (só o antigo primeiro nó muda). | [0079](11-listas.md), [0080](11-listas.md), [0174](28-estruturas-complementos.md) |
| 10 | D | Sem contador, fim == ini precisa significar só um dos estados; reservar uma posição resolve a ambiguidade. | [0085](12-pilhas-e-filas.md), [0086](12-pilhas-e-filas.md) |
| 11 | A | O grafo é esparso (E muito menor que V²); a matriz teria V² = 10⁸ posições, quase todas vazias. | [0109](16-grafos.md) |
| 12 | C | Faltou f->fim = NULL quando ini vira NULL. Rodando com o AddressSanitizer, a última chamada acusa heap-use-after-free. | [0086](12-pilhas-e-filas.md), [0057](07-memoria-dinamica.md) |
| 13 | A | A primeira passada (unidades) dá 361 82 534 215 46 907 128; a segunda reordena por dezenas, mantendo a ordem anterior entre dígitos iguais. Conferido em C. | [0121](18-ordenacao-linear.md) |
| 14 | C | O pivô aleatório só torna o pior caso improvável: ele continua O(n²) e o tempo O(n log n) é esperado. | [0095](13-busca-e-ordenacao.md), [0120](18-ordenacao-linear.md), [0096](13-busca-e-ordenacao.md) |
| 15 | D | O número de deslocamentos do insertion sort é igual ao de inversões: 7, não 9. Contado em C. | [0093](13-busca-e-ordenacao.md) |
| 16 | B | A posição 5 guarda 15, 25, 35, 45 e 55 (1+2+3+4+5 = 15) e a posição 0 guarda 20, 30 e 40 (1+2+3 = 6): 21. Conferido em C. | [0106](15-hash.md) |
| 17 | D | Chaves que diferem só nos bits altos caem na mesma posição quando m é potência de 2. | [0105](15-hash.md), [0178](28-estruturas-complementos.md) |
| 18 | C | v[7] = 31 < 36 leva a 8..14; v[11] = 53 > 36 leva a 8..10; v[9] = 42 > 36 leva a 8..8; v[8] = 36. Conferido em C. | [0090](13-busca-e-ordenacao.md) |
| 19 | A | A posição se acha em O(log n), mas deslocar os elementos custa O(n); e, mesmo com m ≥ n, todas as chaves podem cair na mesma lista. | [0071](10-analise.md), [0072](10-analise.md), [0106](15-hash.md) |
| 20 | B | p guarda uma cópia do endereço de v; mudar p não muda v. Rodando em C, o programa termina com falha de segmentação. | [0049](06-ponteiros.md), [0054](07-memoria-dinamica.md), [0057](07-memoria-dinamica.md) |

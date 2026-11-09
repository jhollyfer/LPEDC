# Provas anteriores do PPGI/UFAM (Prova de Conhecimento)

Texto dos cadernos de questões, enviado pelo dono em 2026-11-09. Serve de referência de formato,
nível e frequência de tópico, como os outros fichamentos: nada daqui é copiado para o curso
(`docs/RULES.md` §9). As folhas de gabarito vieram sem as marcações; só se sabe que houve
questões anuladas. Onde o caderno tinha uma figura que não veio no texto, aparece
`[figura ausente]`. Erros de digitação do original foram mantidos.

---

## Edital 032/2016

**01.** Suponha que você recebeu a tarefa de depurar uma implementação de Quicksort, cujo objetivo é classificar um vetor em ordem crescente. Considere que o pivô escolhido terá o valor 4 e que você executou até o momento apenas o particionamento completo gerado com o pivô, sem ter realizado ainda qualquer chamada recursiva. Vetor: `4 1 2 3 17 2 22 3`. Sobre as afirmações:
I) Dependendo da implementação da partição, a ordem dos elementos nesse momento pode ser 3, 1, 2, 3, 2, 17, 22 e 4
II) É impossível que uma implementação de Quicksort tenha escolhido o 4 como pivô
III) Dependendo da implementação da partição, a ordem dos elementos nesse momento poderia ser 3, 1, 2, 3, 2, 4, 17 e 22
IV) Dependendo da implementação da partição, a ordem dos elementos nesse momento poderia ser 4, 1, 2, 3, 2, 3, 17 e 22
a) Apenas I está correta · b) Apenas II está correta · c) Apenas I e III estão corretas · d) Apenas III e IV estão corretas · e) Apenas III está correta

**02.** Quantas vezes o símbolo '#' é impresso pela função teste quando chamada com parâmetro 5 (teste(5))?
```c
void teste (int i) {
  if (i > 1) {
    teste (i/2);
    teste (i/2);
  }
  printf("#");
}
```
a) 3 · b) 4 · c) 7 · d) 8 · e) Nenhuma das alternativas anteriores

**03.** Quando um novo nó é removido no meio de uma lista encadeada dinâmica, qual das seguintes afirmações é verdadeira:
a) Somente os nós que aparecem após o novo nó precisam ser movidos · b) Somente os nós que aparecem antes do novo nó precisam ser movidos · c) Os nós que aparecem antes do novo nó e o último nó precisam ser movidos · d) Os nós que aparecem depois do novo nó e o primeiro nó precisam ser movidos · e) Nenhuma das opções acima

**04.** Se você tem que implementar um algoritmo de ordenação que tem um tempo de execução competitivo quando comparado a outros, e que não varia muito seu desempenho em função da entrada de dados fornecida. Qual das opções é melhor?
a) Ordenação por inserção · b) Heapsort · c) Quicksort · d) Tanto Quicksort quanto Heapsort atendem aos requisitos · e) Hash

**05.** Se em uma árvore binária de pesquisa a diferença de altura entre a sub-árvore a esquerda e a sub-árvore a direita de um dos nós for maior que 1, pode-se concluir que:
a) A árvore é uma árvore AVL · b) Trata-se com certeza de uma árvore binária sem balanceamento · c) Trata-se com certeza de uma árvore vermelho e preto · d) Tal árvore não pode existir por não se tratar de uma árvore binária de pesquisa · e) Nenhuma das alternativas anteriores

**06.** Uma estrutura de dados bastante útil quando deseja-se armazenar elementos para recupera-los posteriormente em ordem reversa a de inserção:
a) A árvore é uma árvore AVL · b) Um hash · c) Uma fila de prioridades com ordenação reversa de prioridade · d) Uma pilha · e) Uma árvore vermelho e preto

**07.** Considere as afirmações sobre busca binária:
i) é utilizada apenas sobre vetores ordenados
ii) pode determinar se uma chave está ou não com um número de comparações de chave inferior a 2log2 n passos, onde n é o tamanho do vetor.
iii) Supera a busca sequencial quando o vetor é grande, por exemplo com mais que mil elementos, e está ordenado.
a) Apenas II e III · b) Apenas I e II · c) Apenas I e III · d) Todas as afirmações estão corretas · e) Nenhuma das alternativas anteriores

**08.** Considere os códigos de funções abaixo, assumindo que os mesmos são usados dentro de um programa e que todos os cabeçalhos necessários são incluídos:
```c
/* QUADRO I) Código para inserir em uma lista encadeada. Cada nó da lista tem um campo
   prox, que é usado para encadea-lo ao próximo elemento, e tem um dado do tipo int.
   prim é um ponteiro para o ponteiro ao primeiro elemento da lista */
void insere(tipoNo **prim, int d) {
  tipoNo *aux;
  aux = (tipoNo *)malloc(sizeof(tipoNo));
  if(aux) { aux->prox = *prim;
    *prim = aux;
    aux->dado = d;
  }
}
/* QUADRO II) Código para remover primeiro elemento de uma lista encadeada. */
1. void remove (tipoNo **prim){
2.   tipoNo *aux;
3.   if(*prim) { aux = *prim;
4.     *prim = aux->prox;
5.     free(*prim);
6.     *prim = aux;
7.   }
8. }
```
a) Os dois códigos executam as tarefas propostas sem gerar qualquer tipo de erro de lógica, de vazamento de memória ou falha de segmentação · b) Apenas o código I realiza sem erros a tarefa descrita nos comentários · c) Apenas o código II realiza sem erros a tarefa descrita nos comentários · d) Os dois códigos não executam suas tarefas como descrito nos comentários, mas também não geram vazamento de memória · e) O primeiro código gera vazamento de memória e o segundo não realiza a tarefa descrita nos comentários

**09.** Considere as afirmações sobre um hash por encadeamento:
I) Suas colisões secundárias podem prejudicar seu desempenho
II) Não funciona com número de chaves maior que o tamanho da tabela hash
III) O número médio de operações esperado para realizar uma inserção é constante quando computado em função do tamanho da tabela se o hash for bem projetado
a) Todas são verdadeiras · b) Todas são falsas · c) Apenas I e III · d) Apenas III · e) Apenas I e II

**10.** Considere os códigos de funções abaixo:
```c
/* QUADRO I) retorna 1 se a chave ocorre dentro de um vetor de inteiros ordenado e 0 caso
   contrário. O vetor tem tamanho determinado pelo parâmetro tm */
int buscaChave(int v[], int chave, int tm) {
  while((tm >= 0) && (v[tm] != chave)) tm--;
  if (tm >= 0) return 1;
  return 0;
}
/* QUADRO II) Conta ocorrências de uma chave na lista encadeada, retornando o total,
   zero caso a chave não ocorra */
int ContaOcorrenciasChave(tipoNo *prim, int chave) {
  tipoNo *aux = prim;
  int cont = 0;
  int x;;
  for (x = 0; aux[x] != NULL; x++){
    if(aux[x].dado == chave) cont++;
  }
  return cont;
}
```
a) Os dois códigos executam as tarefas propostas sem gerar qualquer tipo de erro de lógica ou de vazamento de memória · b) Apenas o código I executa sem erros a tarefa proposta · c) Apenas o código II executa sem erros a tarefa proposta · d) Os dois códigos geram erros de vazamento de memória ou de falha de segmentação · e) Nenhuma das alternativas anteriores

**11.** Considere as afirmações sobre um hash por encadeamento:
I) Tem como desvantagem o fato de não ordenar as chaves inseridas
II) O número médio de operações esperado para realizar uma busca é constante quando computado em função do tamanho da tabela se o hash for bem projetado
III) Mesmo quando bem implementado, ocupa mais espaço extra do que uma árvore-b em memória.
a) Todas são verdadeiras · b) Todas são falsas · c) Apenas I e III · d) Apenas III · e) Apenas I e II

**12.** Ao inserirmos as chaves 1, 2 e 3, 4, 5, 6 em uma árvore AVL, sua altura (medida como a quantidade máxima de nós em um caminho entre a raiz e uma folha da árvore, incluindo a raiz e a folha na conta) será:
a) 2 · b) 3 · c) 4 · d) 5 · e) 6

**13.** Sobre uma árvore binária de pesquisa sem balanceamento, pode-se afirmar que:
I) São estruturas de dados que, quando degeneradas, têm custo de inserção proporcional ao número de chaves inseridas
II) Não servem para armazenar dados quando deseja-se ter acesso aos mesmos de maneira ordenada
III) Têm como principal custo extra de memória os dois apontadores que indicam os nós à esquerda e à direita de cada nó criado
a) Apenas I · b) Apenas I e II · c) Todas · d) Apenas II e III · e) Nenhuma das alternativas anteriores está correta

**14.** Sobre árvores binárias de pesquisa sem balanceamento, pode-se afirmar que:
I) É uma estrutura de dados inerentemente recursiva, sendo impossível implementar uma busca em uma árvore de maneira não recursiva
II) É uma estrutura de dados inerentemente recursiva, sendo impossível implementar uma inserção em uma árvore de maneira não recursiva
III) Em muitos casos práticos, pode ter custo de busca com número de operações proporcional a log n, onde n é o número de elementos inseridos na árvore
a) Apenas I e II · b) Apenas III · c) Apenas I e III · d) Apenas II e III · e) Nenhuma das alternativas anteriores

**15.** Ao inserirmos as chaves 1, 2 e 3, 4, 5, 6 em uma árvore AVL, a diferença de altura entre as sub-árvores à esquerda e à direita do nó raiz será:
a) 0 · b) 1 · c) 2 · d) 3 · e) 4

**16.** Considere um vetor não ordenado utilizado para armazenar chaves únicas (sem repetição). Pode-se afirmar que:
I) O melhor algoritmo para busca no vetor é a busca binária mesmo que o vetor não esteja ordenado, independente do número de elementos do vetor e da quantidade de buscas a serem realizadas
II) Uma busca binária implementada no vetor não funcionaria adequadamente, fornecendo resultados errados a menos que fosse feita uma ordenação
III) Um algoritmo de busca sequencial funcionaria e daria resultados comparando a chave com todas as posições do vetor na pior das hipóteses
a) Apenas I e III · b) Apenas II e III · c) Todas corretas · d) Todas erradas · e) Nenhuma das alternativas anteriores

**17.** Considere as afirmações abaixo:
I) O RADIX sort não realiza comparação entre chaves para realizar a ordenação de um vetor
II) O número de vezes que é necessário passar por todos os elementos do vetor no RADIX sort é proporcional ao número médio de dígitos dos elementos do vetor na base utilizada pelo algoritmo para ordenação
III) O RADIX sort requer um espaço extra de armazenamento proporcional ao tamanho do vetor
a) Apenas I · b) Apenas II · c) Apenas III · d) Apenas II e III · e) Nenhuma das alternativas anteriores

**18.** Considere que o vetor abaixo será ordenado com o algoritmo de ordenação por seleção: `4 5 2 3 17 2 1 22`. Considerando-se que o vetor tem sua primeira posição contada como 0, a primeira troca de valores entre posições do vetor ocorrerá entre:
a) posição 0 e posição 2 · b) posição 0 e posição 7 · c) posição 0 e posição 6 · d) posição 1 e posição 6 · e) posição 3 e posição 5

**19.** Considere os vetores VetI = `1 2 3 4 5 6 8 7` e VetII = `7 8 8 5 4 3 2 1` e as afirmações:
I) A ordenação por inserção é melhor que a ordenação por seleção em VetI se considerarmos o número de comparações entre chaves realizadas pelos dois algoritmos
II) O RADIX sort executado em base 10 realiza um número menor de operações (instruções) nos dois casos quando comparado ao mergesort
III) O RADIX sort executado em base 10 realiza um número menor de operações apenas em VetII quando comparado ao mergesort, ocorrendo o oposto em VetI
a) Apenas I · b) Apenas II · c) Apenas III · d) Apenas I e II · e) Apenas I e III

**20.** Considere as afirmações abaixo:
I) Pode-se determinar o maior elemento de um vetor ordenado a um custo constante (realizando-se um número constante de operações)
II) Pode-se inverter a ordem de um vetor já ordenado fazendo-se um número de trocas de posições igual à metade do tamanho do vetor e sem ter que criar uma cópia do mesmo
III) O Quicksort é sempre a opção mais rápida (com menor tempo de execução) para ordenar qualquer vetor de qualquer tamanho e com qualquer ordenação inicial das chaves
a) Todas verdadeiras · b) Apenas I · c) Apenas I e III · d) Apenas I e II · e) Nenhuma das alternativas anteriores

Gabarito final: veio sem as letras; 5 questões anuladas (números não identificáveis no texto).

---

## Edital 053/2016

**01.** Seja um vetor de inteiros com 400 elementos distintos ordenados em ordem crescente. Qual é o número máximo de iterações necessárias para encontrar um elemento qualquer desse vetor, caso seja utilizado o algoritmo de busca binária?
a) 9 · b) 8 · c) 7 · d) 200 · e) 400

**02.** Sobre as funções abaixo,
```c
/* Função I */
int fatorial(int i) {
  if (i <= 1) {
    return 1;
  } else {
    fatorial(i-1);
  }
}
/* Função II */
void fatorial() {
  int fat[0] = 1;
  for (int j=1; ; j++) {
    fat[j] = j * fat[j-1];
  }
}
```
a) Somente a função I é recursiva · b) Ambas as funções são recursivas · c) Somente a função II é recursiva · d) A função I não é recursiva e a função II é orientada a objeto · e) Ambas as funções não são recursivas

**03.** As seguintes afirmações sobre árvores estão corretas, com EXCEÇÃO de:
a) É um grafo conexo que admite ciclos · b) É um grafo conexo e há exatamente um caminho entre dois vértices quaisquer · c) Uma árvore com n vértices possui n-1 arestas · d) Toda árvore é um grafo, mas nem todo grafo é uma árvore · e) Uma união disjunta de árvores forma uma floresta

**04.** Considere que o vetor `4 5 5 3 17 2 1 22` será ordenado com o algoritmo de ordenação por seleção. Primeira posição contada como 0, a segunda troca de valores entre posições do vetor ocorrerá entre:
a) Posição 0 e posição 2 · b) Posição 0 e posição 7 · c) Posição 1 e posição 5 · d) Posição 1 e posição 6 · e) Posição 3 e posição 5

**05.** Fila (FIFO) de inteiros com INSERE(n) e RETIRA(); o estado lista do mais antigo (esquerda) ao mais novo. Começando vazia: INSERE(2) → INSERE(3) → RETIRA() → INSERE(1) → RETIRA() → INSERE(4) → INSERE(5) → RETIRA() → RETIRA(). O estado final da fila será:
a) 1 2 3 4 5 · b) 2 3 1 4 5 · c) 3 1 4 · d) 4 5 · e) 5

**06.** Uma lista duplamente encadeada tem como característica ser formada por elementos que:
a) se concatenam de forma circular, de tal maneira que, ao chegar ao final da lista, o próximo elemento volta a ser o primeiro · b) contêm, além de um ou mais campos chave, mais um campo de ponteiro: o próximo · c) contêm, além de um campo chave, mais um campo de ponteiro: o próximo, de tal forma que os campos chave estão ordenados · d) contêm, além de um ou mais campos chave, dois outros campos de ponteiros: próximo e anterior, que permitem o acesso aos elementos adjacentes · e) Estão em posições adjacentes da memória, permitindo o acesso sequencial ao próximo e ao anterior de cada elemento pelo simples uso de um índice

**07.** Se inserirmos numa ABB inicialmente vazia os nós 60, 10, 20, 80, 15, 75, 12 e 77, nessa ordem, e a raiz encontra-se no nível 1, a altura da árvore e o nível do nó 15, respectivamente, serão:
a) 5 e 4 · b) 5 e 5 · c) 6 e 5 · d) 6 e 4 · e) 7 e 3

**08.** Operações:
1. Dados inseridos numa PILHA na ordem: 11, 12, 23, 14, 25, 50, 8, 18, 29, 10.
2. Repetiu-se 10 vezes: retirada da PILHA; inserção na FILA.
3. A FILA foi exibida.
4. Repetiu-se 10 vezes: retirada da FILA; inserção na PILHA.
5. A PILHA foi exibida.
I) FILA (começo) 10 - 29 - 18 - 8 - 50 - 25 - 14 - 23 - 12 - 11 (fim)
II) PILHA: (topo) 11 - 12 - 23 - 14 - 25 - 50 - 8 - 18 - 29 - 10
III) PILHA: (topo) 10 - 29 - 18 - 8 - 50 - 25 - 14 - 23 - 12 - 11
IV) FILA: (começo) 11 - 12 - 23 - 14 - 25 - 50 - 8 - 18 - 29 - 10 (fim)
V) A PILHA mostrada fica com os elementos em ordem invertida dos dados de entrada
As estruturas exibidas corretamente nas operações 3 e 5 são:
a) I e II · b) I e (incompleto no original) · c) II e III · d) III e IV · e) III e IV

**09.** Lista duplamente encadeada com 20 elementos, campos próximo, valor, anterior. "Z" é o décimo elemento; "X" e "Y" não pertencem à lista; ponteiros PZ, PX, PY.
```c
PY->próximo = PX;
PX->anterior = PY;
PX->próximo = PZ->próximo;
PZ->próximo->anterior = PX;
PZ->próximo = PY;
PY->anterior = PZ;
```
Este trecho é usado para inserir na lista os elementos:
a) Y, logo após o Z, e X, logo após o Y · b) Y, antes do Z, e X, logo após o Z · c) Y, antes do Z, e X, antes do Y · d) X, logo após o Z, e Y, logo após o X · e) X, antes do Z, e Y, logo após o Z

**10.** Considere as afirmações sobre um hash linear (sem encadeamento):
I) É obrigatório o uso de várias funções de hash
II) Não funciona com número de chaves maior que o tamanho da tabela hash
III) Quando acontece uma colisão, o valor a ser inserido é colocado no local no lugar do já existente.
a) Todas verdadeiras · b) Todas falsas · c) Apenas I e III · d) Apenas II · e) Apenas I e II

**11.** As sequências que representam os percursos da árvore da figura em pós-ordem e in-ordem são, respectivamente: `[figura ausente]`
a) P Q S T R e P Q S T R · b) S T Q P R e S T Q R P · c) S T Q R P e S Q T P R · d) R P Q T S e S T Q R P · e) P T Q R S e P Q S T R

**12.** Considere as afirmações sobre hash linear e hash encadeado:
I) Hash encadeado funciona melhor em disco, pois as chaves sempre ficam próximas uma das outras, facilitando a varredura.
II) Para uma tabela hash de tamanho M, tanto o hash linear quanto o hash encadeado podem receber uma quantidade de chaves C, onde C > M.
III) Quando acontece uma colisão no hash encadeado, a chave é inserida na posição livre mais próxima da chave original.
a) Todas verdadeiras · b) Todas falsas · c) Apenas I e III · d) Apenas II · e) Apenas I e II

**13.** Em uma árvore AVL, todos os nós têm grau
a) 0, 1 ou 2 · b) divisível por 2 · c) 2 · d) 1 e 2 · e) maior ou igual a 2

**14.** Sobre a Árvore Binária de Busca (ABB) é CORRETO afirmar:
a) Uma ABB é um conjunto finito de nós que possui um nó especial, chamado raiz, do qual partem os nós de duas árvores binárias distintas: a da esquerda e a da direita · b) Quando os elementos a serem inseridos na ABB estão em ordem crescente, resulta em uma ABB com altura mínima · c) Para se utilizar uma ABB como método de ordenação, basta fazer o percurso "em-ordem" e obter todos os elementos ordenados · d) Os nós da ABB são sempre rearranjados de forma que a árvore resultante é sempre perfeitamente balanceada · e) ABB são um caso especial de listas encadeadas em que nenhum nó aponta para mais de 2 sucessores

**15.** Afirmações sobre Quicksort, MergeSort, HeapSort e InsertionSort:
I) São algoritmos estáveis: InsertionSort, QuickSort e MergeSort
II) Pior caso tem número de operações quadrático: InsertionSort, QuickSort
III) Utiliza um espaço extra proporcional a n²: HeapSort
IV) A ordem das entradas é incapaz de influenciar o desempenho do algoritmo: InsertionSort, MergeSort
Marque a alternativa que indica TODAS as afirmações INCORRETAS:
a) I e IV · b) I, III e IV · c) I, II e III · d) I, II, III e IV · e) II e IV

**16.** Sabendo que a altura de uma folha é igual a um e que a altura de um nó pai é o máximo das alturas dos filhos mais um, qual estrutura NÃO pode representar uma árvore AVL?
a) Uma árvore com três nós e altura igual a três · b) Uma árvore com seis nós e altura igual a três · c) Uma árvore com três nós e altura igual a dois · d) Uma árvore vazia · e) Uma árvore com dois nós

**17.** Mesmo formato da questão 10 de 032/2016, com duas mudanças: no QUADRO I, `if (tm >= 0) return 0; return 1;`; no QUADRO II, `return x;` no lugar de `return cont;`.
a) Os dois códigos executam as tarefas sem erro de lógica ou de vazamento · b) Apenas o código I executa sem erros · c) Apenas o código II executa sem erros · d) Os dois códigos geram erros de vazamento de memória ou de falha de segmentação · e) Nenhuma das alternativas anteriores

**18.** Nível da raiz é 1; nível de um nó é o do pai mais 1; profundidade é o maior nível. A menor e a maior quantidade de nós, respectivamente, de uma árvore binária de profundidade 4 são:
a) 4 e 15 · b) 3 e 15 · c) 3 e 16 · d) 4 e 16 · e) 5 e 14

**19.** Uma árvore binária completa tem no 5º nível uma quantidade de nós igual a
a) 16 · b) 15 · c) 31 · d) 64 · e) 32

**20.** ABB com inteiros de 1 a 100, buscando 54. Qual sequência de busca é válida?
a) 5, 18, 34, 60, 40, 52, 54 · b) 25, 27, 28, 26, 60, 50, 58, 54 · c) 37, 70, 32, <não encontrou> · d) 40, 70, 43, 44, 73, 57, 54 · e) Nenhuma das alternativas anteriores

---

## Edital 024/2017

**01.** Sentenças sobre estrutura de dados:
I. A diferença entre árvore binária de busca e árvores AVL é o fato de que a segunda pode se reconfigurar dinamicamente, com o intuito de manter um bom nível de balanceamento.
II. Uma pilha garante que o último elemento inserido seja localizado no seu topo. Porém, do ponto de vista conceitual, qualquer elemento da pilha pode ser removido, ainda que não esteja no seu topo.
III. Do ponto de vista conceitual, não há diferença alguma entre uma estrutura de array e uma lista encadeada.
IV. Tabelas hash são indicadas para armazenar grande volume de dados. Apesar de permitirem acesso indexado, mais de um elemento pode ter o mesmo índice. Elementos com o mesmo índice podem ser armazenados em uma mesma lista encadeada.
a) apenas I e IV · b) apenas I · c) apenas III e IV · d) apenas II e III · e) apenas I, II e IV

**02.** Qual dos algoritmos apresenta o menor custo (número de comparações entre elementos) na pior disposição possível dos elementos? Vetor acima de 1 milhão de elementos.
a) Heapsort · b) Quicksort · c) Inserção · d) Seleção · e) Nenhuma das anteriores porque todos apresentam custo igual

**03.** Qual dos algoritmos apresenta o menor custo (número de movimentações de elementos) na pior disposição possível? Vetor acima de 1 milhão de elementos.
a) Heapsort · b) Quicksort · c) Inserção · d) Seleção · e) Mergesort

**04.** Sobre lista encadeada dinâmica:
I. A busca em tal estrutura realiza menos comparações do que a melhor opção de algoritmo de busca em um vetor ordenado quando se considera o pior cenário para cada estrutura.
II. É uma estrutura de dados usada para ordenar chaves por ser mais eficiente no processo de ordenação que o heapsort
III. É tipicamente utilizada como estrutura de dados básica na implementação de hash por endereçamento aberto
a) As três são falsas · b) As três são verdadeiras · c) Apenas I · d) Apenas II · e) Apenas III

**05.** Lista encadeada de nós `No` (campos `prox` e `dado`), sem nó cabeça; a função deve retornar 1 se encontra a chave e 0 caso contrário, sem alocação desnecessária nem faltante.
```c
/* versão I */
int busca(No *prim, int chave) {
  No *aux = (No *) malloc(sizeof(No));
  aux = prim;
  while(aux != NULL) {
    if(aux->dado == chave) return 1;
    aux = aux>prox;
  }
  return 0;
}
/* versão II */
int busca(No *prim, int chave) {
  while(prim != NULL) {
    if(prim->dado == chave) return 1;
    prim = prim->prox;
  }
  return 0;
}
/* versão III */
int busca(No *prim, int chave) {
  No *aux = prim;
  while(prim->prox != NULL) {
    if(prim->dado == chave) return 1;
    aux = aux->prox;
  }
  return 0;
}
/* versão IV */
int busca(No *prim, int chave) {
  No *aux = (No *) malloc(sizeof(No));
  while(aux->prox != NULL) {
    if(aux->dado == chave) return 1;
    aux = aux>prox;
  }
  return 0;
}
```
a) A versão I está correta e não apresenta problemas de alocação · b) A versão II está correta e não apresenta problemas de alocação · c) A versão III está correta e não apresenta problemas · d) A versão IV está correta e não apresenta problemas · e) Nenhuma das alternativas anteriores está correta

**06.** Após a inserção de 3, 4, 6, 8 e 9 em uma pilha, o resultado de 3 remoções sucessivas seria:
a) 3, 4 e 6 · b) 6, 3 e 4 · c) 6, 8 e 9 · d) 9, 8 e 6 · e) Nenhuma das alternativas anteriores

**07.** Considere:
I. Hash por encadeamento nunca apresenta colisões secundárias
II. Hash por encadeamento jamais permite que o número de comparações entre chaves em uma busca passe de log n, onde n é o número de chaves inseridas.
III. Hash por encadeamento realiza sempre menos comparações entre chaves do que qualquer hash por endereçamento aberto.
a) Apenas I · b) Apenas II · c) Apenas III · d) Apenas II e III · e) Nenhuma das alternativas anteriores está correta

**08.** Quatro árvores (I a IV), com as chaves, em estado final após as inserções. `[figura ausente]`
a) Apenas a árvore I poderia ser AVL · b) Todas podem ser AVL · c) Nenhuma pode ser AVL · d) Apenas I e III podem ser AVL · e) Nenhuma das alternativas anteriores

**09.** Fila (FIFO), estado listado do mais antigo ao mais novo. Começando vazia: INSERE(b) → INSERE(c) → RETIRA() → INSERE(a) → RETIRA() → INSERE(e) → INSERE(e) → RETIRA() → RETIRA(). Estado final:
a) a b c e · b) e a · c) a · d) b c a e · e) c a e

**10.** Quatro árvores (I a IV) em estado final. Quais podem ser árvores binárias de pesquisa sem balanceamento? `[figura ausente]`
a) Apenas I · b) Todas as 4 · c) Nenhuma · d) Apenas II e III · e) Nenhuma das alternativas anteriores

**11.** Uma árvore binária com 5 nós tem percursos pós-ordem e in-ordem, respectivamente, `S T Q R P` e `S Q T P R`. É CORRETO afirmar:
a) O nó raiz tem o valor P · b) Q é um nó folha · c) S é um nó interno · d) T é filho de S · e) Todas as alternativas estão corretas

**12.** Sobre as afirmações:
I. A busca sequencial só pode ser realizada corretamente em vetores que não estejam ordenados
II. A busca por uma chave em um vetor ordenado pode ser realizada corretamente com número constante de operações, não dependendo do tamanho do vetor.
III. Pode-se encontrar o maior elemento de um vetor não ordenado com um algoritmo que realiza um número de operações proporcional ao tamanho do vetor na pior situação possível.
a) Apenas I · b) Apenas II · c) Apenas III · d) Apenas II e III · e) Apenas I e III

**13.** Lista de nós `No` sem nó cabeça, sem alocação desnecessária nem faltante.
```c
/* função I */
void funcaoI(No *prim, int chave) {
  No *aux = (No *) malloc(sizeof(No));
  aux->chave = chave;
  aux->prox = prim;
  prim = aux;
}
/* função II */
void funcaoI(No **prim, int chave) {
  No *aux = (No *) malloc(sizeof(No));
  aux->chave = chave;
  aux->prox = *prim;
  *prim = aux;
}
```
a) Apenas a função I pode inserir corretamente em uma pilha · b) Apenas a função II pode inserir corretamente em uma pilha · c) Ambas podem · d) Apenas a função I serve para lista encadeada, mas não pilha · e) Apenas a função II serve para lista encadeada, mas não pilha

**14.** Afirmações sobre um hash linear (sem encadeamento):
I. No evento de uma colisão, o valor a ser inserido é sempre colocado no início do array;
II. A busca pela chave é realizada utilizando busca binária (mais eficiente)
III. É obrigatório o uso de funções diferentes para inserção e remoção de chaves
IV. É projetado para funcionar com arrays de tamanho previamente definido.
a) Todas verdadeiras · b) Todas falsas · c) Apenas II e IV · d) Apenas IV · e) Apenas I e II

**15.** Hash linear vs hash encadeado:
I. Para uma tabela de tamanho M, tanto o hash linear quanto o encadeado podem receber C chaves, C > M.
II. Quando acontece uma colisão no hash encadeado, a chave é inserida na posição livre mais próxima da chave original.
III. Hash linear funciona melhor em disco, pois as chaves obrigatoriamente ficam em espaços separados de memória, facilitando a varredura.
IV. O uso de uma segunda função de hash (no hash encadeado) garante um melhor espalhamento das chaves pela tabela
a) Todas verdadeiras · b) Todas falsas · c) Apenas I e III · d) Apenas III · e) Apenas I e II

**16.** O vetor `4 5 7 10 13 11 15 22` é uma heap mínima (índice a partir de 0). Afirmativa CORRETA:
a) Essa heap possui todos os nós folhas na mesma altura · b) Ao alterar o valor 22 por 6, 2 trocas são necessárias para corrigir a heap · c) O valor no índice 7 precisa ser necessariamente menor que o do índice 4 · d) O valor no índice 6 precisa ser obrigatoriamente maior que o do índice 1 · e) Ao alterar o valor 13 por 8, nada precisa ser feito para corrigir a heap

**17.** Relacione: I – Heap; II – Rubro-Negra; III – Árvore AVL; IV – Árvore binária de busca. W – Pode degenerar se os elementos forem inseridos de forma ordenada. X – É balanceada. Y – Têm altura sempre proporcional/próxima a O(log2 n). Z – São sempre completas.
a) I–X, IV–Z, II–Y · b) I–Z, IV–X, III–W · c) I–Z, IV–X, III–Y · d) I–Y, IV–W, III–X · e) I–X, IV–W, II–Y

**18.** Mesmo código do QUADRO II de 053/2016 Q17 (`ContaOcorrenciasChave` com `aux[x] != NULL` e `return x;`).
a) Executa a tarefa sem erro de lógica ou de vazamento · b) O código nem compila · c) Executa a tarefa sem erros de lógica · d) Não gera erro de segmentação · e) Nenhuma das alternativas anteriores

**19.** Lista encadeada simples. Alternativa CORRETA:
a) A existência de um ponteiro para o 1º elemento e outro para o fim da lista permite que a inserção ou deleção de dados de um nó que esteja nas extremidades da lista seja rapidamente executada · b) Enquanto a entrada que determina o topo da lista é mantida em um nó descritor, a entrada que marca o fim da lista é mantida em todos os nós · c) O armazenamento de uma lista requer uma área contígua de memória para otimizar a busca · d) O armazenamento de uma lista requer uma área contígua de memória... · e) Para ligar um nó já pertencente a uma lista e um novo nó, basta fazer com que o novo nó referencie no campo next o nó que anteriormente era referenciado pelo nó original, desde que esse campo não tenha o valor nulo

**20.** Uma lista duplamente encadeada é formada por elementos que: (alternativas iguais às da Q06 de 053/2016)

---

## Edital 055/2017

**01.** Função em pseudocódigo `Chamada_recursiva` `[figura ausente]`. A execução de Chamada_recursiva(1) roda indefinidamente; os cinco primeiros valores impressos são:
A) 1, 0, 3, 1 e 0 · B) 1, 0, 3, 1 e 2 · C) 1, 0, 3, 2 e 0 · D) 1, 0, 3, 2 e 3 · E) 1, 0, 3, 2 e 1

**02.** Fila é usada em várias aplicações, EXCETO:
A) Trabalhos submetidos à impressora compartilhada · B) Fila de processos de comunicação em redes · C) Estruturas hierárquicas de diretórios e subdiretórios · D) Buffer para gravação de dados em mídia · E) Atendimento de processos requisitados a um sistema operacional

**03.** ABB com números entre 1 e 1000, procurando 363. Qual NÃO poderia ser a sequência de nós examinados?
A) 2, 252, 401, 398, 330, 344, 397, 363 · B) 924, 220, 911, 244, 898, 258, 362, 363 · C) 925, 202, 911, 240, 912, 245, 363 · D) 2, 399, 387, 219, 266, 382, 381, 278, 363 · E) 935, 278, 347, 621, 299, 392, 358, 363

**04.** ABB sem balanceamento `[figura ausente]`. I. Os nós 6 e 8 são irmãos. II. O nó 4 é uma das raízes da árvore. III. O nó 3, ao ser inserido, ocuparia a posição iv. IV. O nó 1, ao ser inserido, ocuparia a posição i.
A) Apenas III · B) Apenas I e IV · C) Apenas II e III · D) Apenas I, II e IV · E) Todas

**05.** Quando um algoritmo de hash produz um endereço já ocupado, isso é chamado de:
A) Sinônimo · B) Inicial · C) Prospecção · D) Colisão · E) Overflow

**06.** Hash com encadeamento; chaves A,B,C,D,H,J,K,M,N,O,P,R,S,T,U; 11 posições (0 a 10); hash(x) = posição(x) mod 11, com posição("A") = 1 e posição("Z") = 26.
I. Nenhuma chave foi alocada à posição 6; II. A chave "K" foi alocada à posição zero; III. As chaves "B" e "N" colidiram na posição 3; IV. Apenas uma letra foi alocada à posição 9.
A) Apenas I e II · B) Apenas I e IV · C) Apenas I, II e IV · D) Apenas II e III · E) Apenas II, III e IV

**07.** ABB vazia; inserção de 30, 50, 60, 20, 40, 10 e 25, nessa ordem. Percurso em pré-ordem:
A) 30 50 60 40 20 25 10 · B) 10 25 20 40 60 50 30 · C) 10 20 25 30 40 50 60 · D) 30 20 10 25 50 40 60 · E) 60 50 40 30 25 20 10

**08.** Array R com 1.000.000 de chaves ordenadas. Número máximo de acessos a R na busca binária:
A) 10 · B) 20 · C) 40 · D) 80 · E) 160

**09.** Remoção de uma chave cuja página esteja com o número mínimo, em árvore B:
A) Deve-se fazer SPLIT sempre na página onde se encontrar a chave · B) SPLIT na página da chave, exceto quando é elemento da raiz · C) Se a página onde se encontrar a chave não é folha, deve-se fazer concatenação ou redistribuição, considerando os irmãos · D) Remove-se a chave e a substitui por uma chave do nó irmão · E) No caso de só haver uma única página, a remoção não causa a necessidade de balanceamento

**10.** Árvores B e árvores binárias:
I. Diferente das árvores binárias, cada nó de uma árvore B deverá sempre ter mais de dois filhos. II. Um nó de árvore B tem um campo ou método para indicar se é folha. Característica herdada da AVL. III. As folhas da árvore B poderão estar em níveis diferentes. IV. A árvore B tem um balanceamento muito custoso; seu uso em armazenamento secundário deve ser avaliado com cautela.
A) Todas corretas · B) Somente II e III · C) Somente I, II e IV · D) Somente I, III e IV · E) Todas incorretas

**11.** Lista encadeada dinâmica:
I. A busca nela realiza menos comparações do que a melhor busca em vetor ordenado, no pior cenário de cada uma. II. É usada unicamente no armazenamento de grandes quantidades de chaves, dado o seu dinamismo e velocidade de busca. III. É utilizada na implementação de alguns tipos de hash.
A) As três falsas · B) Apenas I · C) Apenas II · D) Apenas III · E) Apenas I e II

**12.** Menor custo (comparações) para um vetor já ordenado, exceto por duas chaves consecutivas trocadas, com mais de 1 milhão de elementos:
A) Heapsort · B) Quicksort · C) Inserção · D) Seleção · E) Todos iguais

**13.** Algoritmos com espaço extra constante no pior caso, independente de n:
A) Mergesort e Seleção · B) Quicksort e Mergesort · C) Mergesort e Heapsort · D) Inserção e Quicksort · E) Nenhuma das alternativas acima está correta

**14.** I. Pode-se buscar em vetor não ordenado a custo máximo inferior a n/2 operações, desde que a chave ocorra no vetor, não importando a posição. II. A busca em vetor ordenado pode ser feita com número de operações proporcional a log2 n. III. O número de comparações para determinar se uma chave está em um vetor não ordenado é sempre menor do que numa lista encadeada com os mesmos elementos na mesma ordem.
A) Apenas I · B) Apenas II · C) Apenas III · D) Todas · E) Nenhuma

**15.** I. Hash por encadeamento pode apresentar colisões secundárias. II. Hash por encadeamento pode permitir que o número de comparações em uma busca passe de n, onde n é o número de chaves inseridas. III. Hash por endereçamento aberto realiza sempre menos comparações do que qualquer hash por encadeamento.
A) Apenas I · B) Apenas II · C) Apenas III · D) Apenas II e III · E) Apenas I e III

**16.** Quatro árvores (I a IV) em estado final. `[figura ausente]`
A) Apenas I poderia ser AVL · B) Apenas III não poderia ser AVL · C) Nenhuma · D) Apenas I e II · E) Nenhuma das anteriores

**17.** Após inserir 10, 1, 3, 4, 6, 8 e 9 em uma pilha, o resultado de três remoções sucessivas seria:
A) 10, 1 e 3 · B) 4, 3 e 1 · C) 6, 8 e 9 · D) 3, 1 e 10 · E) Nenhuma das anteriores

**18.** Mesmas `funcaoI(No *prim, ...)` e `funcaoII(No **prim, ...)` da Q13 de 024/2017, agora para inserir em uma FILA.
A) Apenas funcaoI insere corretamente em fila · B) Apenas funcaoII insere corretamente em fila · C) Ambas · D) Apenas funcaoI serve para lista, mas não fila · E) Apenas funcaoII serve para lista, mas não fila

**19.** Quicksort para ordem decrescente; após a primeira partição o vetor está `20 22 24 18 13 9 3 10`. Sobre a partição:
A) O pivô pode ter o valor 13 ou 18 · B) Pode ser 13, mas não 18 · C) Pode ser 18, mas não 13 · D) Não pode ser 13 nem 18 · E) O vetor não pode representar o resultado da partição

**20.** Inserindo 2, 4, 6, 8, 10 e 12, nessa ordem, numa AVL vazia, a diferença de altura entre a subárvore direita e a esquerda da raiz será:
A) 0 · B) 2 · C) 4 · D) 6 · E) 8

Gabarito: veio sem as letras; 3 questões anuladas.

---

## Edital 023/2018

**01.** Dois vetores ordenados com N inteiros cada são unidos num vetor ordenado de 2N. A complexidade de tempo de melhor caso será:
a) O(1) · b) O(log N), por busca binária · c) O(N), pois se copia cada elemento numa varredura completa de cada vetor · d) O(N log N) · e) O(N²)

**02.** Árvores B:
I. Em uma árvore B de ordem m cada nó tem, no máximo, m filhos. II. Cada nó (exceto raiz e folhas) tem pelo menos m/2 filhos. III. Árvores B precisam ser rebalanceadas frequentemente. IV. Um nó não-folha com k filhos deve ter k chaves. V. Todas as folhas aparecem no mesmo nível e carregam informação.
a) I e III · b) I, III, IV e V · c) I, II e V · d) III, IV e V · e) II, III e IV

**03.** e **05.** (repetidas no caderno) Altura de folha = 1. Qual estrutura NÃO pode ser AVL?
a) Árvore vazia · b) Dois nós · c) Três nós e altura dois · d) Três nós e altura três · e) Seis nós e altura três

**04.** Heap (fila de prioridade). I. `50 40 49 39 45 46` representa um heap correto. II. Dado o heap `21 14 10 9 5`, a inserção do 12 se dá pelos passos `21 14 10 9 5 12` → `21 14 12 9 5 10`. III. Dado o heap `21 14 10 9 5`, a retirada do topo se dá pelos passos `5 14 10 9` → `14 5 12 9`(sic) → `14 9 12 5`. (Os vetores vieram soltos no fim da página; a associação é a provável.)
a) I · b) II · c) III · d) I e II · e) II e III

**06.** Lista ordenada de N números é empilhada e desempilhada; cada POP vai para uma árvore de busca binária. Tempo médio de busca nessa árvore:
a) O(1) · b) O(log N) · c) O(N) · d) O(N log N) · e) O(N²)

**07.** V ou F:
( ) Uma árvore não vazia é AVL se pelo menos uma de suas subárvores for AVL; ( ) Árvores cheias são AVL; ( ) Uma boa condição de balanceamento AVL assegura altura O(log n); ( ) AVL é balanceada pela altura; ( ) Ao inserir ou remover em uma AVL, o custo adicional de balancear é O(n/2).
a) V-V-F-V-V · b) F-V-V-V-F · c) V-F-F-V-F · d) F-V-V-F-V · e) F-F-V-V-F

**08.** Árvore binária (de busca) vazia; inserção de 2, 10, 5, 7, 1, 0 e 8. Pós-ordem:
a) 2, 1, 0, 8, 7, 5, 10 · b) 2, 1, 0, 10, 5, 7, 8 · c) 0, 1, 8, 7, 5, 10, 2 · d) 0, 1, 2, 8, 7, 5, 10 · e) 0, 1, 2, 10, 5, 7, 8

**09.** Igual à Q09 de 053/2016 (inserção de X e Y em lista dupla, com `pY↑.próximo = pX` etc.).

**10.** Árvore de pesquisa binária `[figura ausente]`. Removendo a raiz, o novo nó raiz será:
a) 11 · b) 2 · c) 17 · d) 18 · e) Nenhuma das anteriores

**11.** `f(n)`: se n = 1 retorne 0; se n = 2 retorne 1; senão retorne f(n-1) + f(n-2). Valor de f(4):
a) 0 · b) 1 · c) 2 · d) 3 · e) 4

**12.** Vetor "ordenado" `32 8 12 16 20 24 28 16 36` (assim no original; o esperado parece 4 8 12 16 20 24 28 32 36). Valores comparados com a chave 20 na busca binária (posição inicial 0):
a) 20, 12, 8 e 4 · b) 20, 28, 32 e 36 · c) 4, 8, 12, 16 e 20 · d) 36, 32, 28 e 24 · e) Apenas a chave 20

**13.** Os componentes de um vetor são, caracteristicamente:
a) heterogêneos e FIFO · b) heterogêneos e LIFO · c) heterogêneos e indexado-sequencial · d) homogêneos e acesso não indexado · e) homogêneos e de acesso aleatório por intermédio de índices

**14.** Igual à Q07 de 032/2016 (busca binária, afirmações i, ii, iii).

**15.** Igual à Q17 de 024/2017 (relacionar Heap, Rubro-Negra, AVL e ABB).

**16.** Sobre o heapsort:
a) Usa ordenação por árvore de decisão em vez de comparação · b) A heap pode ser interpretada como uma árvore binária · c) Seu pior caso é pior que o do quicksort · d) Todas corretas · e) Nenhuma correta

**17.** Quicksort, MergeSort, HeapSort e InsertionSort:
I. São estáveis: HeapSort, QuickSort e MergeSort. II. Espaço O(n²): HeapSort. III. A ordem das entradas não influencia: InsertionSort, MergeSort. IV. Melhor caso Ω(n): InsertionSort. V. Espaço O(n): MergeSort.
Marque a que indica SOMENTE afirmações INCORRETAS:
a) I, IV e V · b) I, III e IV · c) I, II, III e IV · d) I, II e III · e) II e V

**18.** Tabela hash de tamanho 11, encadeamento, h(k) = k mod 11; chaves 1, 5, 18, 20, 4, 12, 10, 34, 15, 28 e 17, nessa ordem. Quantidade de posições em que houve colisão:
a) 0 · b) 1 · c) 2 · d) 3 · e) 4

**19.** Lista encadeada simples:
a) Para ligar um nó da lista a um novo nó, basta o novo nó referenciar no campo next o nó antes referenciado pelo original, desde que esse campo não seja nulo · b) Ponteiros para o 1º e o último permitem inserção ou deleção rápida de um nó no meio da lista · c) O topo fica num nó descritor e o fim fica fora dele · d) Requer área contígua de memória · e) Não requer área contígua; como listas são dinâmicas, há procedimentos para criar e remover nós na memória

**20.** I. Uma fila é uma estrutura em que cada elemento tem um ou mais elementos associados. II. A árvore é LIFO. III. Uma lista é linear, pode ser encadeada, com nós que apontam para o próximo e o último aponta para nulo. IV. Pilhas são FIFO.
a) Somente I · b) Somente II · c) Somente III · d) Somente IV · e) Todas

---

## Edital 061/2018

**01.** Arquivo com 10.000 registros, chaves inteiras de até 8 dígitos; índice hashing com endereços de 0 a 11.999. Função mais adequada:
a) f = x mod 1000 + 12 · b) f = x mod 12000 · c) f = x / 10000 · d) f = x / 11999 · e) f = (x – 11999) / 10000

**02.** Matrizes bidimensionais de inteiros. Alternativa INCORRETA:
a) Uma matriz de m linhas e n colunas contém m·n dados · b) Pode ser representada com listas ligadas · c) A soma dos elementos pode ser feita com dois laços aninhados · d) A soma de duas matrizes m×n resulta numa matriz de 2m linhas e 2n colunas · e) O produto de duas matrizes n×n é n×n

**03.** Árvore AVL `[figura ausente]`. Qual sequência a constrói, partindo vazia?
a) 23–7–29–15–4–25–35–13–17 · b) 23–13–35–7–4–29–15–25–17 · c) 23–29–7–17–13–4–35–25–15 · d) 23–25–7–15–4–13–35–29–17 · e) 23–7–29–17–4–35–15–25–13

**04.** Métodos de ordenação, N elementos. Alternativa INCORRETA:
a) Bubble sort e Selection sort são O(N²) · b) O Selection sort é o mais rápido para qualquer N se os elementos já estão ordenados, pois seu melhor caso é O(log2 N) · c) No Quicksort o vetor é dividido em sublistas com os menores à esquerda, ordenadas recursivamente · d) O tempo dos algoritmos aumenta com o número de chaves no pior caso · e) O Quicksort é uma aplicação de dividir para conquistar

**05.** ABB com 100, 80, 25, 72, 23, 42 e 5, nessa ordem: nós folha __I__ e __II__, pai do 72 __III__.
a) 100 – 80 – 100 · b) 5 – 42 – 25 · c) 23 – 25 – 72 · d) 25 – 72 – 100 · e) 72 – 5 – 23

**06.** O QuickSort:
a) Considera em cada passo um elemento sucessor e todos os do vetor destino para achar o ponto de inserção · b) Ordena os elementos a intervalos de 4 posições · c) É baseado em inserção direta com incrementos decrescentes · d) É um algoritmo que pode usar espaço extra linear no pior caso · e) É baseado em seleção direta

**07.** I. A diferença entre árvore binária simples e AVL é que a segunda se reconfigura para manter o balanceamento. II. Uma pilha garante que o último elemento inserido fique no topo. III. Conceitualmente, array e lista encadeada não diferem. IV. Tabelas hash são indicadas para grande volume de dados.
a) I e IV · b) Apenas I · c) III e IV · d) II e III · e) Apenas I, II e IV

**08.** É INCORRETO afirmar:
a) A fila de prioridade, estrutura linear, é uma versão especial da fila · b) Uma lista linear organiza elementos do mesmo tipo em sequência · c) Na pilha, uma estrutura não linear, os elementos entram e saem pelo topo · d) No hash por endereçamento aberto a chave vira um índice inteiro · e) Um array alocado dinamicamente passa a se chamar lista ligada

**09.** Árvore B de ordem m: número mínimo de descendentes no nível d:
a) 2·(m/2)^(d-1) · b) d·m/2 · c) (m·d/2)² · d) [(m·d/2)²]/2 · e) d·(m/2)²

**10.** v1 e v2 com N inteiros, crescentes, v1[N-1] < v2[0]. Retira-se um de cada vez de cada vetor, alternadamente, para uma fila; da fila para uma ABB; percurso em ordem simétrica empilhando; desempilha e insere alternadamente nos vetores, começando por v1. Conclui-se:
a) v1[i] ≥ v2[i] para todo i · b) v1[i] ≤ v2[i] para todo i · c) v1[N-1] > v2[0] · d) As listas não estão mais ordenadas · e) Todos os elementos de v1 estão em v2 e vice-versa

**11.** Igual à Q09 de 055/2017 (remoção em árvore B).

**12.** Questão a resolver pela busca em lista circular encadeada:
a) Saber quando finalizar a busca se o elemento não estiver na lista · b) Retornar o anterior ao buscado · c) Devolver o número de elementos · d) Parar ao achar ponteiro próximo nulo · e) Devolver o ponteiro de início em nova posição

**13.** Igual à Q03 de 055/2017, com a alternativa e) `935, 278, 347, 621, 350, 392, 358, 363`.

**14.** Igual à Q10 de 055/2017 (árvores B e binárias, I a IV).

**15.** Igual à Q05 de 032/2016 (diferença de altura maior que 1 numa árvore binária de pesquisa).

**16.** Igual à Q07 de 024/2017 (hash por encadeamento, I a III).

**17.** Igual à Q17 de 032/2016 (RADIX sort), com e) "Nenhuma das afirmações é verdadeira".

**18.** Igual à Q11 de 032/2016 (hash por encadeamento, I a III).

**19.** AVL, V ou F: ( ) É balanceada quando, para cada nó, a diferença entre as alturas das subárvores não é maior que um. ( ) Com diferença maior que 1 em qualquer nó, é preciso rotacionar. ( ) Uma rotação após a inserção pode deixar a árvore ainda desbalanceada, exigindo novas rotações que, no pior caso, se propagam até a raiz.
a) F-V-V · b) F-F-V · c) V-F-F · d) V-V-F · e) V-V-V

**20.** Igual à Q08 de 053/2016 (pilha → fila → pilha), com as afirmações I a IV.

---

## Edital 033/2019

**01.** Quicksort crescente com o primeiro elemento como pivô. Qual entrada exige mais comparações?
a) 22 25 33 42 56 67 89 · b) 63 70 47 42 36 38 73 · c) 42 25 22 33 67 56 89 · d) 13 52 25 58 10 22 17 · e) 23 25 33 42 11 22 30

**02.** Heap máximo `[figura ausente]`: o nó 24 viola a propriedade. Depois do procedimento de heap aplicado a ele, em que posição ficará?
a) 4 · b) 5 · c) 8 · d) 9 · e) 6

**03.** Pilha de tamanho 5: Push(1); Pop(); Push(2); Push(3); Pop(); Push(4); Pop(); Pop(); Push(5). Número de elementos na pilha:
a) 1 · b) 2 · c) 3 · d) 4 · e) 5

**04.** Árvore B de ordem 5 (raiz `100 140 160`; folhas `88 93`, `110 130`, `144 156`, `180 200`). Resultado da remoção do 130:
a) raiz `100 140 160`; folhas `88 93`, `110`, `144 156`, `180 200` · b) raiz `110 160`; folhas `88 93 100`, `140 144 156`, `180 200` · c) raiz `100 160`; folhas `88 93`, `110 140 144 156`, `180 200` · d) raiz `110 140 160`; folhas `88 93 100`, `110`, `144 156`, `180 200` · e) Nenhuma das anteriores
(Os blocos vieram desalinhados no texto; a atribuição às letras é a provável.)

**05.** Pior caso de comparações para buscar um elemento numa lista simplesmente encadeada de comprimento n:
a) log2 n · b) n/2 · c) log2 n - 1 · d) n · e) Nenhuma das anteriores

**06.** Saída da função para a lista `1->2->3->4->5->6`:
```c
void fun(struct node* start) {
  if(start == NULL) return;
  printf("%d ", start->data);
  if(start->next != NULL) fun(start->next->next);
  printf("%d ", start->data);
}
```
a) 1 4 6 6 4 1 · b) 1 3 5 1 3 5 · c) 1 2 3 5 · d) 1 3 5 5 3 1 · e) Nenhuma das anteriores

**07.** Estrutura comumente usada para implementar recursão:
a) Fila · b) Pilha · c) Vetor · d) Lista · e) Matriz

**08.** Pior caso e caso médio de uma árvore de busca binária:
a) O(n), O(n) · b) O(log n), O(log n) · c) O(log n), O(n) · d) O(n), O(log n) · e) Nenhuma das anteriores

**09.** Árvore B de ordem 4 (máximo de filhos por nó) e altura 3: máximo de chaves:
a) 255 · b) 63 · c) 127 · d) 188 · e) 256

**10.** Tabela hash vazia, m = 17, método da divisão, endereçamento aberto. I. Após inserir 5, 10, 22, 42 e 39 com sondagem linear, houve 2 colisões no total. II. Essas chaves poderiam ser inseridas sem colisão com hash duplo. III. É possível inserir 17 chaves sem nenhuma colisão.
a) Somente I · b) I e II · c) Somente III · d) I e III · e) Todas

**11.** Código (em Java no original) que percorre uma lista circular a partir de `head.getNext()` com `while((temp != head) && !(temp.getItem() == data)) { temp = temp.getNext(); flag = 1; break; }` e imprime "success" se `flag`, senão "fail". Qual a função?
a) Imprimir success se o elemento não for encontrado · b) Imprimir fail se o elemento não for encontrado · c) Imprimir success se um elemento for igual a 1 · d) Imprimir fail se a lista estiver vazia e success caso contrário · e) Nenhuma das anteriores

**12.** Altura máxima de uma AVL com 7 nós (altura de um nó só = 0):
a) 2 · b) 3 · c) 4 · d) 5 · e) 6

**13.** I. As raízes das subárvores são menores que a raiz do heap. II. Para restaurar a AVL depois de inserir, parte-se do ponto de inserção em direção à raiz. III. Árvore B e AVL têm a mesma complexidade de pior caso para inserção e exclusão.
a) Somente I · b) II e III · c) Somente III · d) I e III · e) Somente II

**14.** Entrada (34, 8, 64, 51, 32, 21), Insertion Sort. Array após a segunda rodada:
a) 8, 21, 32, 34, 51, 64 · b) 8, 32, 34, 51, 64, 21 · c) 8, 34, 51, 64, 32, 21 · d) 8, 34, 64, 51, 32, 21 · e) 8, 51, 64, 34, 32, 21

**15.** Vantagem do Bubble Sort em relação aos outros:
a) É o mais rápido · b) Consome menos memória · c) Pode detectar se a entrada já está ordenada · d) É o mais complexo de implementar · e) Não possui vantagens

**16.** Heap máximo em árvore: nível 0 `88`; nível 1 `66 77`; nível 2 `33 44 55 75`; nível 3 `30 22 5`. Ordem no array:
a) 88 66 33 44 30 22 5 77 55 75 · b) 86 77 55 75 66 33 44 30 22 5 · c) 86 77 75 66 55 44 33 30 22 5 · d) 5 22 30 75 55 44 33 77 66 86 · e) 88 66 77 33 44 55 75 30 22 5

**17.** Quantas pilhas são necessárias para implementar uma fila, sem nenhuma outra estrutura?
a) 0 · b) 1 · c) 2 · d) 3 · e) 4

**18.** Sobre o Insertion Sort, CORRETA:
a) Existem arrays de tamanhos variados N em que roda em Θ(N) · b) ... em Θ(1) · c) ... em Θ(N³) · d) ... em Θ(2N) · e) Nenhuma

**19.** AVL vazia com 2, 3, 5, 6, 9, 8, 7, 4, 1, nessa ordem. Árvore final:
a) raiz 6; 3 e 8; 2, 5, 7, 9; 1, 4 · b) raiz 2; 3 e 6; 1, 5, 8, 9; 4, 7 · c) raiz 9; 8 e 7; ... · d) raiz 5; 2 e 7; 1, 4, 8, 9; 3, 6 · e) Nenhuma das anteriores
(Desenhos reconstruídos pelos níveis que vieram no texto.)

**20.** I. A subárvore da raiz de uma rubro-negra é sempre uma rubro-negra. II. O irmão de uma referência de filho nulo numa rubro-negra é outra referência nula ou um nó vermelho. III. O pior caso da inserção numa AVL é O(log n).
a) Somente I · b) II e III · c) Somente III · d) I e III · e) Somente II

Gabarito parcial: veio sem as letras; 4 questões anuladas.

---

## Edital 060/2019

**01.** Hash com endereçamento aberto e sondagem linear, h(x) = x mod 9. Tabela final: posições 0 a 8 = `9 18 12 3 14 4 21 _ _`. Qual pode ser a ordem de inserção? (sem redimensionar nem remover)
a) 9, 14, 4, 18, 21, 3, 12 · b) 12, 3, 14, 18, 4, 9, 21 · c) 12, 14, 3, 9, 4, 18, 21 · d) 9, 12, 14, 3, 21, 18, 4 · e) 18, 9, 12, 3, 14, 4, 21

**02.** Elementos 10, 20, 15, 25, 30, 16, 18, 19 inseridos numa AVL vazia. Qual desenho é a AVL final? `[figura ausente; os níveis vieram embaralhados no texto]`
a) 1 · b) 2 · c) 3 · d) 4 · e) Nenhuma

**03.** Um algoritmo com número de operações ______ em função de n é linear.
a) n³ + 9 · b) 3n² + 3n + 2 · c) 6 · d) 2n + 1 · e) n² + 1

**04.** Vetor com os 25 primos de 2 a 97 (posições 0 a 24). Pesquisa binária: quantos itens são examinados antes de concluir que 52 não está no vetor?
a) 12 · b) 7 · c) 5 · d) 1 · e) 4

**05.** O que faz a função?
```c
void fun1(struct node* head) {
  if(head == NULL) return;
  fun1(head->next);
  printf("%d ", head->data);
}
```
a) Imprime todos os nós a partir do primeiro · b) Imprime todos os nós a partir do último · c) Só posições pares · d) Só posições ímpares · e) Nenhuma

**06.** Hash com encadeamento e tabela de tamanho 100; inserindo um número n muito grande de chaves:
a) O caso médio de busca será O(1) · b) O pior caso será O(1) · c) O caso médio será O(n) · d) O pior caso será O(log n) · e) Nenhuma

**07.** Completar a função que move o último nó para a frente da lista simplesmente encadeada:
```c
typedef struct node { int value; struct node *next; } Node;
Node *move_to_front(Node *head) {
  Node *p, *q;
  if ((head == NULL || (head->next == NULL)) return head;
  q = NULL; p = head;
  while (p->next != NULL) { q = p; p = p->next; }
  ______________
  return head;
}
```
a) q = NULL; p->next = head; head = p; · b) q->next = NULL; head = p; p->next = head; · c) head = p; p->next = q; q->next = NULL; · d) q->next = NULL; p->next = head; head = p; · e) Não precisa ser complementada

**08.** Algoritmo com tempo O(n) ao ordenar n elementos idênticos:
a) Heapsort · b) Insertion sort · c) Mergesort · d) Quicksort · e) Nenhum

**09.** Rubro-negra, VERDADEIRA:
a) O caminho da raiz até a folha mais distante não é maior que o dobro do caminho até a folha mais próxima · b) Todo caminho da raiz até folha ou nulo tem o mesmo número de nós pretos e vermelhos · c) A raiz pode ser vermelha · d) Filhos de vermelho são pretos e filhos de preto são vermelhos · e) Nenhuma

**10.** Estrutura mais usada para implementar recursão:
a) Heap binário · b) Hash table · c) Fila · d) Árvore de busca · e) Pilha

**11.** Árvores B e B+, FALSA:
a) B e B+ crescem criando nova raiz; ABB cresce pelas folhas · b) O tempo de busca no pior caso é diferente do das rubro-negras · c) Num nó de árvore B, o número de filhos é sempre o de chaves mais um · d) B+ de ordem n: folhas na mesma profundidade; todas as chaves nas folhas · e) B de ordem n: folhas na mesma profundidade; nós não raiz com n-1 a 2n-1 chaves; raiz com no máximo 2n-1

**12.** Quais respeitam o balanceamento AVL? (A) 100; 50, 200; 10 (filho de 50), 300. (B) 100; 50, 200; 5? 150, 300; 10. (C) 100; 50, 200; 5, 60, 150, 300; 10, 180, 400. `[figura parcialmente ausente]`
a) Somente B · b) A, B e C · c) B e C · d) A e C · e) Nenhuma

**13.** Sobre árvores, INCORRETA:
a) Pior caso de busca em AVL é O(log n) · b) No pior caso, uma inserção em rubro-negra requer O(1) rotações · c) B+ tem todas as chaves nas folhas · d) A busca numa ABB sem balanceamento com n nós leva O(log n) no pior caso · e) Uma árvore B é balanceada

**14.** Número mínimo de comparações para saber se um inteiro aparece mais de n/2 vezes num vetor ordenado de n inteiros:
a) Θ(n) · b) Θ(log n) · c) Θ(log* n) · d) Θ(1) · e) Θ(n/2)

**15.** AVL × rubro-negra, VERDADEIRA:
a) AVL tende a ter altura menor, mas pode causar mais rotações em inserção e exclusão · b) Mesma altura, AVL com mais rotações · c) Rubro-negra com altura menor e mais rotações · d) Mesma altura, rubro-negra com mais rotações · e) Todas falsas

**16.** ABB `[figura ausente]`; operações: adicionar 5, adicionar 17, remover 23, remover 9. Pré-ordem e pós-ordem:
a) 3, 9, 10, 12, 15, 19, 21, 23 e 23, 21, 19, 15, 12, 10, 9, 3 · b) 15, 9, 23, 3, 12, 19, 10, 21 e 21, 10, 19, 12, 3, 23, 9, 15 · c) 15, 10, 21, 3, 12, 19, 9, 23 e 15, 21, 10, 19, 12, 3, 23, 9 · d) 10, 12, 9, 3, 15, 23, 19, 21 e 21, 19, 23, 15, 9, 3, 12, 10 · e) 15, 10, 3, 5, 12, 21, 19, 17 e 5, 3, 12, 10, 17, 19, 21, 15

**17.** Merge Sort leva 30 s no pior caso para n = 64. Tamanho máximo resolvido em 6 minutos, aproximadamente:
a) 256 · b) 1024 · c) 512 · d) 2048 · e) 4096

**18.** {5,4,3,2,1} com Insertion Sort. Sequência de passos:
a) 4 5 3 2 1 / 3 4 5 2 1 / 2 3 4 5 1 / 1 2 3 4 5 · b) 5 4 3 1 2 / 5 4 1 2 3 / 5 1 2 3 4 / 1 2 3 4 5 · c) 4 3 2 1 5 / 3 2 1 5 4 / 2 1 5 4 3 / 1 5 4 3 2 · d) 4 5 3 2 1 / 2 3 4 5 1 / 3 4 5 2 1 / 1 2 3 4 5 · e) 4 5 3 1 2 / 2 3 4 5 1 / 3 4 5 2 1 / 1 2 3 4 5

**19.** Lista duplamente encadeada não ordenada, com ponteiros de início e fim. Operações em O(1): I. Inserção na frente. II. Inserção no final. III. Exclusão do nó da frente. IV. Exclusão do último nó.
a) I e II · b) I e III · c) I, II e III · d) I, II e IV · e) Todas

**20.** Fila circular com capacidade n-1 num vetor de n; REAR e FRONT como índices; inicialmente REAR = FRONT = 0. Condições de cheia e vazia:
a) Full: (REAR+1) mod n == FRONT; empty: (FRONT+1) mod n == REAR · b) Full: REAR == FRONT; empty: (REAR+1) mod n == FRONT · c) Full: (FRONT+1) mod n == REAR; empty: REAR == FRONT · d) Full: REAR == FRONT; empty: (FRONT+1) mod n == REAR · e) Full: (REAR+1) mod n == FRONT; empty: REAR == FRONT

Folha de respostas: veio sem as letras; 4 questões anuladas.

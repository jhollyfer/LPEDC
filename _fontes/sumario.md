# Sumário do LPEDC

Numeração única no curso todo. Assunto `NNNN` tem os exemplos `A(2N-1)` e `A(2N)` e os
exercícios `E(6N-5)` a `E(6N)`. Ex.: assunto 0002 → A003, A004, E007 a E012.

## 01-fundamentos · Fundamentos de C (algoritmo, entrada → processamento → saída, estrutura sequencial)
- 0001-primeiro-programa · esqueleto, #include, main, printf, return 0, comentários; do .c ao executável e os tipos de erro
- 0002-variaveis · variável: um pedaço de memória com nome e tipo; int, float, double, char; sizeof
- 0003-tipos-e-limites · short, long, unsigned, limits.h, overflow, stdint.h
- 0004-constantes · literais, #define, const, sequências de escape
- 0005-printf · %d %f %c %s %x %p, largura e precisão
- 0006-scanf · leitura com scanf, o &, retorno do scanf, sobra no buffer
- 0007-aritmetica · + - * / %, divisão inteira, precedência
- 0008-conversao · conversão automática e cast
- 0009-atribuicao · += -= *= /= %=, ++ e -- (pré e pós)
- 0010-math · math.h (-lm): pow, sqrt, round, floor, ceil, fabs
- 0011-juntando-tudo · programa do módulo

## 02-condicionais · Decisões
- 0012-relacionais · > < >= <= == != e a verdade em C (0 e não-zero), stdbool.h
- 0013-logicos · && || !, tabela-verdade, curto-circuito
- 0014-if · if
- 0015-if-else · if/else e a pegadinha do = no lugar do ==
- 0016-else-if · else if, if aninhado e o else "pendurado"
- 0017-ternario · condição ? a : b
- 0018-switch · switch, case, break e fall-through
- 0019-juntando-tudo · programa do módulo

## 03-repeticoes · Laços
- 0020-while · while
- 0021-do-while · do...while: validação e menu
- 0022-for · for com contador
- 0023-break-continue · break e continue
- 0024-lacos-aninhados · laço dentro de laço (tabuada, desenhos com *)
- 0025-padroes-de-laco · contador, acumulador, maior/menor, flag, sentinela
- 0026-aleatorios · rand, srand e time
- 0027-juntando-tudo · programa do módulo

## 04-funcoes · Funções e modularização
- 0028-funcoes · definir, chamar, retornar, protótipo
- 0029-parametros · passagem por valor, void
- 0030-escopo · local, global, static e tempo de vida
- 0031-pilha-de-chamadas · a pilha de execução (frames)
- 0032-recursao · recursão: caso base e caso recursivo
- 0033-recursao-na-pratica · Fibonacci (e seu custo), Hanói, Euclides
- 0034-modulos · .h e .c, include guards, compilação separada
- 0035-preprocessador · macros, #ifdef, armadilhas de macro
- 0036-juntando-tudo · programa do módulo

## 05-vetores-e-strings · Vetores, matrizes e strings
- 0037-vetores · declarar, inicializar, índice, C não confere limites
- 0038-vetores-e-funcoes · passar vetor + tamanho, a função altera o original
- 0039-matrizes · matriz 2D, linhas e colunas, memória contínua
- 0040-caracteres · char é número, tabela ASCII, ctype.h
- 0041-strings · o '\0', string.h (strlen, strcpy, strcmp, strcat)
- 0042-lendo-strings · fgets, tirar o '\n', estouro de buffer, por que nunca gets
- 0043-juntando-tudo · programa do módulo

## 06-ponteiros · Ponteiros
- 0044-memoria · endereço, &, %p: a memória como gaveteiro numerado
- 0045-ponteiros · declarar, *, NULL
- 0046-passagem-por-referencia · troca (swap) e o & do scanf explicado
- 0047-ponteiros-e-vetores · aritmética de ponteiros, a[i] == *(a + i)
- 0048-ponteiros-e-strings · char * vs char [], literal só de leitura
- 0049-ponteiro-para-ponteiro · **
- 0050-ponteiro-para-funcao · callbacks e qsort
- 0051-void-generico · void * e cast
- 0052-juntando-tudo · programa do módulo

## 07-memoria-dinamica · Memória dinâmica
- 0053-pilha-e-heap · stack, heap, dados e código
- 0054-malloc-free · malloc e free
- 0055-calloc-realloc · calloc, realloc: o vetor que cresce
- 0056-matriz-dinamica · matriz alocada dinamicamente
- 0057-erros-de-memoria · vazamento, ponteiro solto, free duplo, estouro; valgrind e ASan
- 0058-juntando-tudo · programa do módulo

## 08-structs · Tipos compostos
- 0059-struct · struct
- 0060-typedef · typedef
- 0061-vetor-de-structs · vetor de structs
- 0062-ponteiro-para-struct · ->, struct em função, struct com malloc
- 0063-enum · enum
- 0064-union · union
- 0065-bits · operadores bit a bit, máscaras e flags
- 0066-juntando-tudo · programa do módulo

## 09-arquivos · Arquivos e linha de comando
- 0067-arquivos-texto · fopen, fprintf, fgets, fclose
- 0068-arquivos-binarios · fwrite, fread, fseek
- 0069-argumentos · argc e argv
- 0070-juntando-tudo · programa do módulo

## 10-analise · Pensar como cientista da computação
- 0071-eficiencia · contar passos
- 0072-big-o · O(1), O(log n), O(n), O(n log n), O(n²)
- 0073-invariantes · invariantes de laço e corretude
- 0074-tad · tipo abstrato de dado: interface (.h) e implementação (.c)

## 11-listas · Listas
- 0075-vetor-dinamico · lista sequencial (TAD sobre vetor que cresce)
- 0076-lista-encadeada · nó, inserir no início, percorrer, liberar
- 0077-lista-busca-remocao · busca e remoção
- 0078-lista-ordenada · inserção ordenada
- 0079-lista-dupla · lista duplamente encadeada
- 0080-lista-circular · lista circular
- 0081-juntando-tudo · programa do módulo

## 12-pilhas-e-filas · Pilhas e filas
- 0082-pilha · TAD pilha sobre vetor
- 0083-pilha-encadeada · pilha sobre lista
- 0084-pilha-aplicacoes · parênteses balanceados, notação pós-fixa
- 0085-fila · fila circular sobre vetor
- 0086-fila-encadeada · fila sobre lista
- 0087-deque · fila dupla
- 0088-juntando-tudo · programa do módulo

## 13-busca-e-ordenacao · Busca e ordenação
- 0089-busca-sequencial
- 0090-busca-binaria
- 0091-bubble-sort
- 0092-selection-sort
- 0093-insertion-sort
- 0094-merge-sort
- 0095-quick-sort
- 0096-comparando · estabilidade, custo, qsort da biblioteca

## 14-arvores · Árvores
- 0097-arvores · raiz, filho, folha, altura, profundidade
- 0098-arvore-binaria · representação e percursos (pré, em, pós, por nível)
- 0099-bst-busca-insercao · árvore binária de busca: busca e inserção
- 0100-bst-remocao · remoção na BST
- 0101-avl · balanceamento e rotações
- 0102-heap · heap e fila de prioridade
- 0103-heapsort · heapsort
- 0104-juntando-tudo · programa do módulo

## 15-hash · Tabelas hash
- 0105-hashing · a ideia e a função hash
- 0106-encadeamento · colisão resolvida com listas
- 0107-enderecamento-aberto · sondagem linear
- 0108-juntando-tudo · programa do módulo

## 16-grafos · Grafos
- 0109-grafos · vértices, arestas, matriz e lista de adjacência
- 0110-bfs · busca em largura
- 0111-dfs · busca em profundidade
- 0112-dijkstra · caminho mínimo
- 0113-juntando-tudo · programa do módulo

## 17-analise-avancada · Medindo algoritmos recursivos
- 0114-recorrencias · recorrência a partir do código e árvore de recursão
- 0115-teorema-mestre · os três casos e quando não se aplica
- 0116-amortizada · vetor que dobra, contador binário, pilha com multipop
- 0117-limite-inferior · árvore de decisão e o Ω(n log n) da ordenação por comparação
- 0118-juntando-tudo · medir e prever o tempo de quatro ordenações reais

## 18-ordenacao-linear · Ordenação além da comparação e seleção
- 0119-shell-sort · insertion sort com saltos (Knuth 3h+1)
- 0120-counting-sort · contagem, somas acumuladas e estabilidade
- 0121-radix-sort · dígito a dígito (LSD) com base 10 e base 256
- 0122-bucket-sort · baldes com listas encadeadas
- 0123-quickselect · k-ésimo menor e mediana pelo particionamento
- 0124-juntando-tudo · ordenar 1 milhão de registros e comparar com qsort

## 19-backtracking · Enumeração e backtracking
- 0125-subconjuntos · enumeração recursiva e por bits
- 0126-permutacoes · troca, recursão e desfazer
- 0127-backtracking · poda; soma de subconjuntos
- 0128-n-rainhas · N-rainhas com vetores de colunas e diagonais
- 0129-labirinto · caminho em matriz e flood fill
- 0130-juntando-tudo · resolvedor de sudoku

## 20-dc-e-gulosos · Divisão e conquista e algoritmos gulosos
- 0131-divisao-e-conquista · a técnica; potência rápida
- 0132-inversoes-e-subvetor · contar inversões e subvetor de soma máxima
- 0133-gulosos · a ideia, troco canônico e o contraexemplo {1,3,4}
- 0134-intervalos · seleção de atividades
- 0135-mochila-fracionaria · ordenar por valor/peso
- 0136-huffman · árvore de Huffman com heap
- 0137-juntando-tudo · compactador/descompactador Huffman de arquivos

## 21-programacao-dinamica · Programação dinâmica
- 0138-memoizacao · Fibonacci memoizado e de baixo para cima; escadas e grade
- 0139-troco-pd · mínimo de moedas e número de formas
- 0140-mochila-01 · tabela n×W e recuperação dos itens
- 0141-lcs · maior subsequência comum
- 0142-distancia-de-edicao · Levenshtein
- 0143-juntando-tudo · mini-diff entre dois arquivos de texto

## 22-arvores-avancadas · Árvores e conjuntos avançados
- 0144-arvores-gerais · filho-esquerdo/irmão-direito
- 0145-rubro-negra · rubro-negra esquerdista (LLRB): inserção
- 0146-arvore-b · árvore B: busca, divisão e inserção
- 0147-trie · árvore de prefixos e autocompletar
- 0148-union-find · conjuntos disjuntos com compressão e união por tamanho
- 0149-juntando-tudo · corretor ortográfico com trie (e comparação com hash e BST)

## 23-grafos-avancados · Grafos: estrutura e caminhos
- 0150-componentes-e-ciclos · componentes conexos e detecção de ciclo (3 cores)
- 0151-ordenacao-topologica · Kahn e DFS
- 0152-kruskal · MST com ordenação e union-find
- 0153-prim · MST com heap; comparação com Dijkstra
- 0154-bellman-ford · pesos negativos e ciclo negativo
- 0155-floyd-warshall · todos os pares
- 0156-juntando-tudo · planejador de rotas e de pré-requisitos

## 24-busca-de-padroes · Busca de padrões em texto
- 0157-forca-bruta · busca ingênua e strstr
- 0158-kmp · tabela de bordas (π) e busca linear
- 0159-horspool · Boyer-Moore-Horspool e tabela de saltos
- 0160-rabin-karp · hash rolante e falsos positivos
- 0161-juntando-tudo · mini-grep com os quatro algoritmos e cronômetro

## 25-estruturas-extras · Estruturas especiais
- 0162-matriz-esparsa · triplas e listas por linha
- 0163-skip-list · lista com andares aleatórios
- 0164-listas-autoajustaveis · mover para a frente, transposição, contagem
- 0165-juntando-tudo · comparar BST, AVL, skip list e lista autoajustável no mesmo teste

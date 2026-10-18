# Sumário do LPEDC

Numeração única no curso todo. Assunto `NNNN` tem os exemplos `A(2N-1)` e `A(2N)` e os
exercícios `E(2N-1)` e `E(2N)`. Ex.: assunto 0007 → A013, A014, E013, E014.

## 00-logica · Lógica antes do código
- 0001-algoritmo · algoritmo: a receita passo a passo
- 0002-pseudocodigo · pseudocódigo (Portugol) e teste de mesa
- 0003-fluxograma · fluxograma
- 0004-binario · binário, hexadecimal, bit e byte
- 0005-compilacao · do .c ao executável (pré-processador, compilador, ligador, gcc)

## 01-fundamentos · Fundamentos de C
- 0006-primeiro-programa · esqueleto, #include, main, printf, return 0, comentários
- 0007-variaveis · variável: um pedaço de memória com nome e tipo; int, float, double, char; sizeof
- 0008-tipos-e-limites · short, long, unsigned, limits.h, overflow, stdint.h
- 0009-constantes · literais, #define, const, sequências de escape
- 0010-printf · %d %f %c %s %x %p, largura e precisão
- 0011-scanf · leitura com scanf, o &, retorno do scanf, sobra no buffer
- 0012-aritmetica · + - * / %, divisão inteira, precedência
- 0013-conversao · conversão automática e cast
- 0014-atribuicao · += -= *= /= %=, ++ e -- (pré e pós)
- 0015-math · math.h (-lm): pow, sqrt, round, floor, ceil, fabs
- 0016-juntando-tudo · programa do módulo

## 02-condicionais · Decisões
- 0017-relacionais · > < >= <= == != e a verdade em C (0 e não-zero), stdbool.h
- 0018-logicos · && || !, tabela-verdade, curto-circuito
- 0019-if · if
- 0020-if-else · if/else e a pegadinha do = no lugar do ==
- 0021-else-if · else if, if aninhado e o else "pendurado"
- 0022-ternario · condição ? a : b
- 0023-switch · switch, case, break e fall-through
- 0024-juntando-tudo · programa do módulo

## 03-repeticoes · Laços
- 0025-while · while
- 0026-do-while · do...while: validação e menu
- 0027-for · for com contador
- 0028-break-continue · break e continue
- 0029-lacos-aninhados · laço dentro de laço (tabuada, desenhos com *)
- 0030-padroes-de-laco · contador, acumulador, maior/menor, flag, sentinela
- 0031-aleatorios · rand, srand e time
- 0032-juntando-tudo · programa do módulo

## 04-funcoes · Funções e modularização
- 0033-funcoes · definir, chamar, retornar, protótipo
- 0034-parametros · passagem por valor, void
- 0035-escopo · local, global, static e tempo de vida
- 0036-pilha-de-chamadas · a pilha de execução (frames)
- 0037-recursao · recursão: caso base e caso recursivo
- 0038-recursao-na-pratica · Fibonacci (e seu custo), Hanói, Euclides
- 0039-modulos · .h e .c, include guards, compilação separada
- 0040-preprocessador · macros, #ifdef, armadilhas de macro
- 0041-juntando-tudo · programa do módulo

## 05-vetores-e-strings · Vetores, matrizes e strings
- 0042-vetores · declarar, inicializar, índice, C não confere limites
- 0043-vetores-e-funcoes · passar vetor + tamanho, a função altera o original
- 0044-matrizes · matriz 2D, linhas e colunas, memória contínua
- 0045-caracteres · char é número, tabela ASCII, ctype.h
- 0046-strings · o '\0', string.h (strlen, strcpy, strcmp, strcat)
- 0047-lendo-strings · fgets, tirar o '\n', estouro de buffer, por que nunca gets
- 0048-juntando-tudo · programa do módulo

## 06-ponteiros · Ponteiros
- 0049-memoria · endereço, &, %p: a memória como gaveteiro numerado
- 0050-ponteiros · declarar, *, NULL
- 0051-passagem-por-referencia · troca (swap) e o & do scanf explicado
- 0052-ponteiros-e-vetores · aritmética de ponteiros, a[i] == *(a + i)
- 0053-ponteiros-e-strings · char * vs char [], literal só de leitura
- 0054-ponteiro-para-ponteiro · **
- 0055-ponteiro-para-funcao · callbacks e qsort
- 0056-void-generico · void * e cast
- 0057-juntando-tudo · programa do módulo

## 07-memoria-dinamica · Memória dinâmica
- 0058-pilha-e-heap · stack, heap, dados e código
- 0059-malloc-free · malloc e free
- 0060-calloc-realloc · calloc, realloc: o vetor que cresce
- 0061-matriz-dinamica · matriz alocada dinamicamente
- 0062-erros-de-memoria · vazamento, ponteiro solto, free duplo, estouro; valgrind e ASan
- 0063-juntando-tudo · programa do módulo

## 08-structs · Tipos compostos
- 0064-struct · struct
- 0065-typedef · typedef
- 0066-vetor-de-structs · vetor de structs
- 0067-ponteiro-para-struct · ->, struct em função, struct com malloc
- 0068-enum · enum
- 0069-union · union
- 0070-bits · operadores bit a bit, máscaras e flags
- 0071-juntando-tudo · programa do módulo

## 09-arquivos · Arquivos e linha de comando
- 0072-arquivos-texto · fopen, fprintf, fgets, fclose
- 0073-arquivos-binarios · fwrite, fread, fseek
- 0074-argumentos · argc e argv
- 0075-juntando-tudo · programa do módulo

## 10-analise · Pensar como cientista da computação
- 0076-eficiencia · contar passos
- 0077-big-o · O(1), O(log n), O(n), O(n log n), O(n²)
- 0078-invariantes · invariantes de laço e corretude
- 0079-tad · tipo abstrato de dado: interface (.h) e implementação (.c)

## 11-listas · Listas
- 0080-vetor-dinamico · lista sequencial (TAD sobre vetor que cresce)
- 0081-lista-encadeada · nó, inserir no início, percorrer, liberar
- 0082-lista-busca-remocao · busca e remoção
- 0083-lista-ordenada · inserção ordenada
- 0084-lista-dupla · lista duplamente encadeada
- 0085-lista-circular · lista circular
- 0086-juntando-tudo · programa do módulo

## 12-pilhas-e-filas · Pilhas e filas
- 0087-pilha · TAD pilha sobre vetor
- 0088-pilha-encadeada · pilha sobre lista
- 0089-pilha-aplicacoes · parênteses balanceados, notação pós-fixa
- 0090-fila · fila circular sobre vetor
- 0091-fila-encadeada · fila sobre lista
- 0092-deque · fila dupla
- 0093-juntando-tudo · programa do módulo

## 13-busca-e-ordenacao · Busca e ordenação
- 0094-busca-sequencial
- 0095-busca-binaria
- 0096-bubble-sort
- 0097-selection-sort
- 0098-insertion-sort
- 0099-merge-sort
- 0100-quick-sort
- 0101-comparando · estabilidade, custo, qsort da biblioteca

## 14-arvores · Árvores
- 0102-arvores · raiz, filho, folha, altura, profundidade
- 0103-arvore-binaria · representação e percursos (pré, em, pós, por nível)
- 0104-bst-busca-insercao · árvore binária de busca: busca e inserção
- 0105-bst-remocao · remoção na BST
- 0106-avl · balanceamento e rotações
- 0107-heap · heap e fila de prioridade
- 0108-heapsort · heapsort
- 0109-juntando-tudo · programa do módulo

## 15-hash · Tabelas hash
- 0110-hashing · a ideia e a função hash
- 0111-encadeamento · colisão resolvida com listas
- 0112-enderecamento-aberto · sondagem linear
- 0113-juntando-tudo · programa do módulo

## 16-grafos · Grafos
- 0114-grafos · vértices, arestas, matriz e lista de adjacência
- 0115-bfs · busca em largura
- 0116-dfs · busca em profundidade
- 0117-dijkstra · caminho mínimo
- 0118-juntando-tudo · programa do módulo

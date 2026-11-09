# Rumo ao PPGI/UFAM · o curso alinhado ao edital

Este guia liga o **Edital n.º 070/2026-PROPESP/UFAM** (Mestrado em Informática,
ingresso 2027/1) e o **cursinho preparatório do PPGI** (Colabweb) aos assuntos do
LPEDC. Para cada tópico da prova você encontra onde estudar. O plano de estudo dia a dia
está em [Comece aqui](#comece-aqui).

## O que o edital pede

| Item | O que diz |
| --- | --- |
| Inscrição | 05/11/2026 a 11/11/2026, on-line, com GRU de R$ 100,00 (vencimento 11/11) |
| Documento | um **único PDF** com o Lattes e todos os comprovantes (o que não tiver comprovante não conta) |
| Etapa I | **Prova de Conhecimentos** em 27/11/2026: 20 questões objetivas, 0,5 cada; **nota mínima 7,0** (14 acertos) |
| Etapa II | Prova de Títulos (Lattes): `NPT = 7 + 3 × pontos / 100` |
| Nota final | `NF = (2 × NPC + NPT) / 3`; empate: maior NPC, depois maior NPT, depois o mais velho |
| Vagas | 40 regulares + 8 suplementares + 2 para servidor da UFAM |

Pela conta, a prova de conhecimentos vale o dobro e é eliminatória. Mesmo com
o Lattes zerado, a NPT é 7: quem tira 9 na prova fica com
`NF = (18 + 7) / 3 = 8,33`.

A prova usa **pseudocódigo, Python 3 e C**. Os conceitos de C listados no
edital: seleção (`if`, `else`, `switch`), leitura e escrita na tela e em
arquivos, `while` e `do while`, operadores aritméticos, lógicos e bit a bit,
`int`, `char`, `float`, `double`, tipos com e sem sinal, ponteiros, vetores,
matrizes, structs, uniões, enumerações, funções, **VLA**, `#include` e
`#define`. Tudo isso está no curso. O LPEDC é todo em C; o trecho de Python da
prova fica fora daqui (veja o fim deste guia).

## Tópico por tópico

### 1. Fundamentos de algoritmos

| Edital | Onde estudar |
| --- | --- |
| sequência | [01 · Fundamentos](01-fundamentos.md) (0001–0011) |
| seleção: `if`/`else`, `switch` | [02 · Decisões](02-condicionais.md) (0012–0019) |
| repetição: `while`, `do/while` | [03 · Laços](03-repeticoes.md) (0020–0027) |
| modularização, procedimentos, funções | [04 · Funções](04-funcoes.md) 0028–0031, 0034 |
| recursão | 0032, 0033 e [19 · Backtracking](19-backtracking.md) |
| expressões, operadores, **precedência** | 0007, 0009, 0013 e **0170** ([27 · Detalhes de C](27-c-detalhes.md)) |

### 2. Eficiência computacional

| Edital | Onde estudar |
| --- | --- |
| função de custo, contar passos | 0071 ([10 · Análise](10-analise.md)) |
| complexidade assintótica, O | 0072 |
| **O, Ω e Θ** (definições formais) | **0166** ([26 · Análise formal](26-analise-formal.md)), 0117 |
| somatórios (cursinho, aula 3) | **0167** |
| complexidade **espacial** | **0168** |
| algoritmos recursivos: recorrências, teorema mestre | [17 · Análise avançada](17-analise-avancada.md) (0114–0118) |
| precisão e boas práticas | 0008, 0057, 0073 |

### 3. Estruturas de dados elementares

| Edital | Onde estudar |
| --- | --- |
| tipos definidos pelo programador, struct, union, enum | [08 · Tipos compostos](08-structs.md) (0059–0065) |
| TAD | 0074 e todo módulo a partir do 11 |
| vetores, matrizes | [05 · Vetores](05-vetores-e-strings.md) (0037–0039), 0056 |
| **VLA** | **0172** |
| tipos com e sem sinal, bits | 0003, 0065 e **0171** |
| lista em vetor | 0075 |
| lista ligada, circular, dupla | [11 · Listas](11-listas.md) (0076–0080) |
| lista **com sentinela** | **0174** ([28 · Complementos](28-estruturas-complementos.md)) |
| pilhas, filas, filas circulares, deques | [12 · Pilhas e filas](12-pilhas-e-filas.md) (0082–0087) |
| fila de prioridade | 0102 |
| arquivos texto e binários | [09 · Arquivos](09-arquivos.md) (0067–0068) |

### 4. Árvores

| Edital | Onde estudar |
| --- | --- |
| altura, profundidade, raiz, pai, filho | 0097, 0098 ([14 · Árvores](14-arvores.md)) |
| **nível, grau, fator de balanceamento, sucessor, antecessor** | **0175** |
| árvore binária de busca: busca, inserção, remoção | 0099, 0100 |
| AVL | 0101 e **0176** (remoção) |
| rubro-negra | **0177** (versão clássica do Cormen) e 0145 (esquerdista) |
| árvore B | 0146 ([22 · Árvores avançadas](22-arvores-avancadas.md)) |
| heap binário | 0102, 0103 |

### 5. Tabelas de espalhamento

| Edital | Onde estudar |
| --- | --- |
| conceito e função hash | 0105 ([15 · Hash](15-hash.md)) |
| método da divisão e **da multiplicação** | **0178** |
| encadeamento | 0106 |
| endereçamento aberto: sondagem linear | 0107 |
| **sondagem quadrática e dispersão dupla** | **0179** |

### 6. Busca

| Edital | Onde estudar |
| --- | --- |
| busca sequencial e binária | 0089, 0090 ([13 · Busca e ordenação](13-busca-e-ordenacao.md)) |
| busca em árvores | 0099, 0146, 0147 |

### 7. Ordenação

| Edital | Onde estudar |
| --- | --- |
| bubble, insertion, selection | 0091–0093 |
| merge, quick, heap | 0094, 0095, 0103 |
| estável e não estável | 0096, 0120 |
| **chave simples e composta, pigeonhole sort** | **0180** |
| counting, bucket, radix | [18 · Ordenação linear](18-ordenacao-linear.md) (0120–0122) |

### 8. Grafos

| Edital | Onde estudar |
| --- | --- |
| vértice, aresta, dirigido, com peso | 0109 ([16 · Grafos](16-grafos.md)) |
| matriz e lista de adjacências | 0109 |
| **grau, caminho, trajeto, circuito, ciclo, euleriano** | **0182** ([29 · Grafos e NP](29-grafos-e-np.md)) |
| **hamiltoniano** | **0183** |
| conectividade | 0150 ([23 · Grafos avançados](23-grafos-avancados.md)) |
| **ponte e vértice de articulação** | **0184** |
| busca em largura e em profundidade | 0110, 0111 |
| caminhos mínimos | 0112 (Dijkstra), 0154 (Bellman-Ford), 0155 (Floyd-Warshall) |
| árvore geradora mínima | 0152 (Kruskal), 0153 (Prim) |

### O que o cursinho acrescenta

O cursinho do PPGI tem um bloco de **Análise de Algoritmos** que vai além do
edital. Ele está coberto assim:

| Aula do cursinho | Onde estudar |
| --- | --- |
| 1–3 · problemas, notação assintótica, somatórios | 0071, 0072, 0166, 0167 |
| 4 · divisão e conquista, recorrências | 0114, 0115, 0131, 0132 |
| 5 · ordenação | módulos 13 e 18 |
| 6 · método guloso | 0133–0136 |
| 7–8 · Prim e Kruskal | 0152, 0153 |
| 9–11 · Dijkstra e Bellman-Ford | 0112, 0154 |
| 12, 14, 15 · programação dinâmica, mochila, LCS | 0138–0142 |
| 13 · multiplicação de cadeias de matrizes | **0185** |
| 16 · caixeiro viajante | 0183, **0188** |
| 17–22 · P, NP, NP-completo, SAT, clique, reduções, verificação | **0186**, **0187** |
| 23–24 · algoritmos aproximados, bin packing | **0188** |

E as vídeo-aulas de AED (parte 1 e 2) seguem, quase na mesma ordem, os módulos
04 a 16 do curso: structs, funções, escopo, passagem de parâmetros, busca
sequencial e binária, seleção, inserção, recursão, quicksort, merge, matrizes,
`math.h`, cast, ponteiros, alocação dinâmica, listas (simples, com ponteiro para
o último, circular, dupla), filas, pilhas, arquivos texto e binários (inclusive
busca binária em arquivo, que junta o `fseek` do 0068 com o 0090), BST com ponteiro para o pai (0175),
rubro-negra (0177) e hash por encadeamento (0106).

## O que caiu de 2016 a 2023

As 11 provas de 2016 a 2023 somam 210 questões. O gabarito comentado de cada uma, com o link
para o módulo, está em [`PROVAS.md`](PROVAS.md); só a de 2023 (edital 071/2023) tem gabarito
oficial. Uma questão pode tocar dois tópicos, por isso a soma passa de 210.

| Tópico do edital | Questões | Parte da prova |
| --- | --- | --- |
| 4 · Árvores (ABB, AVL, heap, árvore B, rubro-negra) | 70 | 33% |
| 3 · Estruturas elementares (lista, pilha, fila) | 54 | 26% |
| 7 · Ordenação | 34 | 16% |
| 5 · Hash | 22 | 10% |
| 6 · Busca | 19 | 9% |
| 1, 2 e 8 · Fundamentos, eficiência e grafos | 18 | 9% |

Os assuntos que mais aparecem: AVL (0101, em 33 questões), busca e inserção em ABB (0099, 22),
busca binária (0090, 20), lista encadeada (0076, 17), hash por encadeamento (0106, 16), pilha
(0082, 15), insertion sort (0093, 13) e quick sort (0095, 12).

O formato mudou em 2022. Até 2019 eram 5 alternativas; em 2022 e 2023 são 4, com trechos em
Python e mais questões de custo (pior caso de inserir, remover e buscar em vetor ordenado, lista,
árvore balanceada e hash) e de grafos (BFS com fila, Dijkstra, matriz x lista de adjacência).
Grafo, que quase não caía, voltou: não pule o módulo 16.

| Formato | Questões | Como treinar |
| --- | --- | --- |
| conceito (definição direta) | 57 | os `[!WARNING]` de cada assunto |
| afirmações I, II, III combinadas | 55 | julgue cada afirmação sozinha antes de olhar as letras |
| simulação (pilha, fila, hash, ABB, AVL, heap, ordenação passo a passo) | 48 | refaça no papel o fluxograma e o `### Passo a passo` |
| código (ler, achar o erro, prever a saída; em C ou Python) | 26 | a lista prática de 11, 12 e 14 |
| cálculo (altura, comparações da busca binária, complexidade) | 24 | conte à mão e confira rodando o exemplo |

Várias questões voltam quase iguais em anos diferentes: a pilha que vira fila e volta a ser
pilha, a inserção de X e Y numa lista dupla, as afirmações sobre hash por encadeamento, o
"qual sequência de busca não pode ser de uma ABB", a AVL montada com chaves em ordem crescente
e a busca binária contando comparações.

## Comece aqui

Plano de hoje, 09/11, até a prova, em 27/11. A ordem segue o peso de cada tópico nas
provas de 2016 a 2023 ([o que caiu](#o-que-caiu-de-2016-a-2023)): árvores primeiro, depois
listas, pilhas e filas, busca, ordenação e hash. Cada dia tem um bloco de assuntos e um
treino no formato da prova.

Como estudar cada assunto do dia: leia o texto, refaça a **Pergunta para você** e faça os
exercícios ★★☆ e ★★★. Feche o dia com as **Questões no estilo da prova** do módulo,
cronometrando (3 minutos por questão), e os ★★☆ da lista prática. Para cada questão errada,
volte ao assunto indicado no gabarito.

| Dia | Foco | Assuntos | Treino no formato da prova |
| --- | --- | --- | --- |
| seg 09/11 | diagnóstico | nenhum | a prova 071/2023 inteira, a única com gabarito oficial; confira em [`PROVAS.md`](PROVAS.md) e anote os tópicos que errou. Inscrição até 11/11 |
| ter 10/11 | ABB | 0097–0100 | questões do módulo 14 |
| qua 11/11 | AVL, o assunto que mais cai | 0101, 0176 | prova 032/2016 |
| qui 12/11 | heap, heapsort, árvore B, rubro-negra | 0102, 0103, 0146, 0145, 0175, 0177 | questões dos módulos 22 e 28 |
| sex 13/11 | listas encadeadas e `**prim` | 0075–0081, 0174 | questões do módulo 11; prova 053/2016 |
| sáb 14/11 | pilha e fila, fila circular | 0082–0087 | questões do módulo 12; prova 024/2017 |
| dom 15/11 | busca e custo | 0071, 0072, 0089, 0090 | questões do módulo 10 |
| seg 16/11 | ordenação passo a passo | 0091–0093 | prova 055/2017 |
| ter 17/11 | merge, quick (partição), radix; estabilidade e espaço | 0094–0096, 0119–0121 | questões dos módulos 13 e 18 |
| qua 18/11 | hash | 0105–0107, 0178, 0179 | questões do módulo 15; prova 023/2018 |
| qui 19/11 | grafos | 0109–0112 | questões do módulo 16 |
| sex 20/11 | C que vira pegadinha | 0007, 0008, 0030, 0046, 0047, 0170–0173 | prova 061/2018 |
| sáb 21/11 | simulado | erros dos dias anteriores | simulado 1 de [`SIMULADOS.md`](SIMULADOS.md) |
| dom 22/11 | provas antigas | erros do simulado | provas 033/2019 e 060/2019 |
| seg 23/11 | simulado | erros das provas | simulado 2 |
| ter 24/11 | Python e provas recentes | [Python 3](#python-3) | provas 057/2022 e 020/2023; confira o local da prova |
| qua 25/11 | simulado | erros das provas | simulado 3 |
| qui 26/11 | descanso | só os `[!WARNING]` de 0090, 0095, 0099, 0101, 0102 e 0106 | nenhum |
| sex 27/11 | **prova** | | |

Se um dia atrasar, corte o treino, não o assunto: árvores, listas e busca somam mais da
metade das questões.

Outras datas: homologação preliminar em 18/11, local da prova em 24/11 e
gabarito preliminar no dia da prova. Leve caneta azul ou preta e documento com
foto; não entra depois do horário.

## Python 3

A prova também traz trechos em Python 3 (listas, tuplas, dicionários, fatiamento,
`while`, funções, classes). O LPEDC não cobre Python de propósito: o curso
explica tudo em termos de C. Se precisar desse pedaço, use o livro do edital
(Menezes, *Introdução à Programação com Python*) e foque em ler código: o que é
fatia, o que é referência para lista, o que uma função devolve.

## Referências do edital e do cursinho

- CORMEN, T. H.; LEISERSON, C. E.; RIVEST, R. L.; STEIN, C. *Algoritmos: teoria e prática*. 4. ed. Rio de Janeiro: GEN LTC, 2024.
- ZIVIANI, N. *Projeto de algoritmos com implementações em Pascal e C*. 3. ed. São Paulo: Cengage Learning, 2010.
- MENEZES, N. N. C. *Introdução à programação com Python*. 4. ed. São Paulo: Novatec, 2024.
- DEITEL, H. M.; DEITEL, P. J. *C: como programar*. 6. ed. São Paulo: Pearson, 2011.
- CELES, W.; CERQUEIRA, R.; RANGEL, J. L. *Introdução a estruturas de dados: com técnicas de programação em C*. 2. ed. Rio de Janeiro: Elsevier, 2016.
- TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. *Estruturas de dados usando C*. São Paulo: Makron Books, 1995.
- EDELWEISS, N.; GALANTE, R. *Estruturas de dados*. Porto Alegre: Bookman, 2009.

# Provas anteriores do PPGI/UFAM · gabarito comentado

As 11 provas de conhecimento de 2016 a 2023, resolvidas questão por questão: editais 032/2016,
053/2016, 024/2017, 055/2017, 023/2018, 061/2018, 033/2019, 060/2019, 057/2022, 020/2023 e
071/2023. O enunciado de cada uma está em [`_fontes/provas-ppgi.md`](_fontes/provas-ppgi.md):
abra a prova lá, resolva cronometrando e só depois confira aqui. Para fazer as provas em formato de quiz, com
o porquê de cada alternativa, use [jhollyfer.github.io/LPEDC](https://jhollyfer.github.io/LPEDC/).

> [!IMPORTANT]
> Os editais de 2016 a 2019 e o 071/2023 têm gabarito oficial: as letras são da banca (as de 2016
> a 2019 foram lidas nas folhas de resposta; as questões anuladas aparecem como "anulada"). Só os
> editais 057/2022 e 020/2023 não têm letra oficial; as letras deles são do curso. Onde o curso
> tinha chegado a outra letra, a coluna "Por quê" avisa. As questões de código e de simulação
> foram conferidas rodando o programa. As provas completas, com as figuras, estão em
> [`_fontes/provas-ppgi.md`](_fontes/provas-ppgi.md) e cada módulo traz as questões reais do seu
> tema.

Desde 2022 as provas têm **4 alternativas** (de 2016 a 2019 eram 5) e trazem trechos em
Python. Aqui cada trecho em Python aponta para o assunto de C que treina a mesma ideia.

Na coluna **Assuntos**, o link leva ao módulo onde aquilo se estuda. **Tópico** é o número do
tópico do edital em [`PPGI.md`](PPGI.md#tópico-por-tópico); o resumo do que mais cai está em
[`PPGI.md`](PPGI.md#o-que-caiu-de-2016-a-2023). **Formato** diz que tipo de questão é:
`afirmações` (I, II, III combinadas), `código` (ler ou achar o erro), `simulação` (executar à
mão), `conceito` (definição) e `cálculo` (altura, comparações, complexidade).

## Edital 032/2016

| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | anulada | afirmações | 7 | [0095](13-busca-e-ordenacao.md) | Anulada pela banca. I é o resultado do particionamento de Hoare (3 1 2 3 2 17 22 4) e III é o de Lomuto; IV deixa o pivô na frente com menores depois dele. |
| 02 | C | cálculo | 1 | [0032](04-funcoes.md), [0114](17-analise-avancada.md) | T(1)=1, T(2)=3, T(3)=3 (3/2=1), T(5)=2·T(2)+1=7; conferido em C. |
| 03 | E | conceito | 3 | [0076](11-listas.md), [0077](11-listas.md) | Remover no meio de lista encadeada só religa ponteiros, nenhum nó é movido. |
| 04 | B | conceito | 7 | [0096](13-busca-e-ordenacao.md), [0103](14-arvores.md) | Heapsort faz O(n log n) em qualquer entrada; o Quicksort varia (pior caso O(n²)). |
| 05 | anulada | conceito | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Anulada pela banca. Diferença maior que 1 só diz que não é AVL; pode ser rubro-negra, então nenhuma afirmação é certa. |
| 06 | D | conceito | 3 | [0082](12-pilhas-e-filas.md) | Pilha é LIFO. |
| 07 | anulada | afirmações | 6 | [0090](13-busca-e-ordenacao.md), [0072](10-analise.md) | Anulada pela banca. I, II (no máximo ⌊log2 n⌋+1 comparações) e III são verdadeiras. |
| 08 | B | código | 3 | [0076](11-listas.md), [0077](11-listas.md), [0054](07-memoria-dinamica.md) | O insere está certo; o remove dá free no novo início (*prim) e depois faz *prim = aux, apontando para nó já removido. |
| 09 | D | afirmações | 5 | [0105](15-hash.md), [0106](15-hash.md) | I é falsa (colisão secundária é do endereçamento aberto), II é falsa (encadeamento aceita mais chaves que a tabela), III é verdadeira. |
| 10 | B | código | 6 | [0089](13-busca-e-ordenacao.md), [0076](11-listas.md), [0057](07-memoria-dinamica.md) | Gabarito oficial B. O curso tinha chegado em D: I lê v[tm] fora do vetor se tm for o tamanho; II usa aux[x] num ponteiro de nó (não compila e, se compilasse, falharia). |
| 11 | anulada | afirmações | 5 | [0106](15-hash.md), [0146](22-arvores-avancadas.md) | Anulada pela banca. I verdadeira (não ordena), II verdadeira (busca esperada O(1+α)), III falsa (a árvore B também gasta ponteiros e nós semicheios). |
| 12 | B | simulação | 4 | [0101](14-arvores.md) | Inserir 1..6 dá raiz 4, esquerda 2(1,3), direita 5(-,6): 3 nós no maior caminho. |
| 13 | E | afirmações | 4 | [0099](14-arvores.md), [0098](14-arvores.md) | I e III são verdadeiras, II é falsa, e "I e III" não está entre as letras. |
| 14 | B | afirmações | 4 | [0099](14-arvores.md) | I e II são falsas (busca e inserção têm versão iterativa); III é verdadeira (árvore razoavelmente balanceada). |
| 15 | A | simulação | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Mesma árvore da Q12: subárvore esquerda 2(1,3) e direita 5(-,6) têm altura 2, diferença 0. |
| 16 | B | afirmações | 6 | [0089](13-busca-e-ordenacao.md), [0090](13-busca-e-ordenacao.md) | I é falsa (a binária exige vetor ordenado), II e III são verdadeiras. |
| 17 | anulada | afirmações | 7 | [0121](18-ordenacao-linear.md), [0120](18-ordenacao-linear.md) | Anulada pela banca. I verdadeira, III verdadeira (vetor auxiliar), II imprecisa (passadas = dígitos do maior, não a média); "I e III" não existe, logo nenhuma. |
| 18 | C | simulação | 7 | [0092](13-busca-e-ordenacao.md) | O menor é 1, na posição 6, que troca com a posição 0. |
| 19 | D | afirmações | 7 | [0093](13-busca-e-ordenacao.md), [0092](13-busca-e-ordenacao.md), [0121](18-ordenacao-linear.md), [0094](13-busca-e-ordenacao.md) | I verdadeira (inserção faz ~n comparações em quase ordenado, seleção sempre n(n-1)/2); II verdadeira (radix de 1 dígito, ~n+10 passos contra ~n log n); III falsa. |
| 20 | D | afirmações | 7 | [0038](05-vetores-e-strings.md), [0095](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | I (último elemento) e II (n/2 trocas) verdadeiras; III falsa (Quicksort tem pior caso quadrático). |


**Observações**
- Q01: IV poderia ser aceita se "particionamento completo" admitir pivô ainda não posicionado; nesse caso a letra seria D. Escolhi C.
- Q09: "colisões secundárias" é termo do endereçamento aberto. Se o autor leu como "cadeias longas prejudicam", a letra seria C.
- Q10: dois erros distintos (leitura fora do vetor e `aux[x]` em ponteiro). D é a mais próxima; E também é defensável. Provável anulada ou resposta frouxa.
- Q13: com I e III verdadeiras não há letra certa. A letra A só vale se o autor considerou III falsa. Provável anulada.
- Q17: sem "I e III" entre as letras; E por exclusão. Se o autor tratou III como falsa (radix in-place), seria A.
- Q11: depende do autor ter considerado III falsa (árvore B ocupa mais espaço por nó semicheio e ponteiros).
- O caderno diz 5 questões anuladas; prováveis: 05, 10, 13, 17 e uma de 09/11.

## Edital 053/2016

| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | A | cálculo | 6 | [0090](13-busca-e-ordenacao.md), [0072](10-analise.md) | ⌊log2 400⌋+1 = 9; conferido em C (máximo de 9 iterações). |
| 02 | A | conceito | 1 | [0032](04-funcoes.md) | A função I chama a si mesma (mesmo sem return); a II só tem laço. |
| 03 | A | conceito | 8 | [0097](14-arvores.md), [0109](16-grafos.md), [0150](23-grafos-avancados.md) | Árvore é grafo conexo e acíclico; "admite ciclos" é a exceção. |
| 04 | C | simulação | 7 | [0092](13-busca-e-ordenacao.md) | 1ª troca 0 e 6 (vira 1 5 5 3 17 2 4 22); 2ª troca 1 e 5 (o 2). Conferido em C. |
| 05 | E | simulação | 3 | [0085](12-pilhas-e-filas.md), [0086](12-pilhas-e-filas.md) | Fila: [3], [3 1], [1], [1 4 5], [4 5], [5]. |
| 06 | D | conceito | 3 | [0079](11-listas.md) | Dois ponteiros por nó: próximo e anterior. |
| 07 | A | simulação | 4 | [0099](14-arvores.md), [0097](14-arvores.md), [0175](28-estruturas-complementos.md) | Com raiz no nível 1: altura 5 (caminho 60-10-20-15-12), nível do 15 é 4; conferido em C. |
| 08 | A | simulação | 3 | [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md) | Pilha → fila: 10 29 18 8 50 25 14 23 12 11 (I). Fila → pilha: topo 11 12 23 ... 10 (II). |
| 09 | A | código | 3 | [0079](11-listas.md), [0062](08-structs.md) | As linhas ligam Z → Y → X → antigo próximo de Z. |
| 10 | D | afirmações | 5 | [0107](15-hash.md) | I falsa, II verdadeira (endereçamento aberto não passa de M chaves), III falsa (vai para a próxima posição livre). |
| 11 | C | simulação | 4 | [0098](14-arvores.md) | Figura ausente. Só C e D (e A, B) são árvores consistentes; C é a árvore natural: raiz P, esquerda Q(S,T), direita R. |
| 12 | B | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md) | I falsa (disco), II falsa (o linear não aceita C>M), III falsa (colisão no encadeado entra na lista). |
| 13 | A | conceito | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Nó de AVL é binário: grau 0, 1 ou 2. |
| 14 | A | conceito | 4 | [0099](14-arvores.md), [0098](14-arvores.md) | Gabarito oficial A. O curso tinha chegado em C: Em ordem na ABB dá chaves ordenadas. |
| 15 | B | afirmações | 7 | [0096](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md), [0094](13-busca-e-ordenacao.md), [0095](13-busca-e-ordenacao.md), [0103](14-arvores.md), [0168](26-analise-formal.md) | Incorretas: I (Quick não é estável), III (Heap usa O(1) extra), IV (Insertion depende da ordem). |
| 16 | A | cálculo | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Três nós em altura 3 é cadeia, fator de balanceamento 2: não é AVL. |
| 17 | E | código | 6 | [0089](13-busca-e-ordenacao.md), [0076](11-listas.md), [0057](07-memoria-dinamica.md) | Gabarito oficial E. O curso tinha chegado em D: I inverte o retorno e lê v[tm] fora; II usa aux[x] e retorna x em vez da contagem. |
| 18 | A | cálculo | 4 | [0097](14-arvores.md), [0175](28-estruturas-complementos.md) | Mínimo é 1 nó por nível (4), máximo é 2^4-1 = 15. |
| 19 | A | cálculo | 4 | [0097](14-arvores.md) | Nível 5 tem 2^(5-1) = 16 nós. |
| 20 | A | simulação | 4 | [0099](14-arvores.md) | Só a sequência A respeita os limites da ABB em todos os passos (B, C e D violam). |


**Observações**
- Q11: figura ausente. A letra C é inferência (única com árvore "equilibrada" de 5 nós); A, B e D também formam árvores válidas (cadeias). Confiança média.
- Q14: A também é defensável (definição de árvore binária). Escolhi C por ser a propriedade característica da ABB.
- Q10 (hash linear): II é verdadeira, contrariando a mesma afirmação nas questões de encadeamento; aqui a resposta é D.
- Q17: mesma ambiguidade da Q10 de 032 (ver lá); D por coerência.
- Q08: o texto original da letra B está truncado; as letras D e E repetem o texto. A resposta A não depende disso.
- Q01: se o autor contou comparações e não iterações do laço, a conta é a mesma (9).
- Q07: a altura em arestas (Cormen) seria 4; o enunciado define raiz no nível 1, então vale 5.
## Edital 024/2017
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | A | afirmações | 3 | [0101](14-arvores.md), [0082](12-pilhas-e-filas.md), [0076](11-listas.md), [0106](15-hash.md) | I e IV verdadeiras; II falsa (pilha só remove do topo), III falsa (array é contíguo, lista não) |
| 02 | A | conceito | 7 | [0103](14-arvores.md), [0095](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md), [0092](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | pior caso: heapsort O(n log n); quicksort, inserção e seleção O(n²) |
| 03 | D | conceito | 7 | [0092](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | seleção faz no máximo n-1 trocas; heap e merge movem O(n log n) |
| 04 | A | afirmações | 3 | [0076](11-listas.md), [0090](13-busca-e-ordenacao.md), [0107](15-hash.md) | busca em lista é O(n) contra O(log n) no vetor; lista não ordena melhor que heapsort; endereçamento aberto usa vetor |
| 05 | B | código | 3 | [0076](11-listas.md), [0077](11-listas.md), [0054](07-memoria-dinamica.md) | só a versão II percorre sem malloc e sem erro; I vaza memória e tem `aux>prox`, III e IV têm laço errado |
| 06 | D | simulação | 3 | [0082](12-pilhas-e-filas.md) | LIFO: sai 9, 8, 6 |
| 07 | A | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md) | colisão secundária é de endereçamento aberto, então I é verdadeira; II e III falsas (pior caso é n, e aberto pode ganhar do encadeado) |
| 08 | E | afirmações | 4 | [0101](14-arvores.md) | Gabarito oficial E. A figura não veio no texto, então o curso não tinha letra. |
| 09 | anulada | simulação | 3 | [0085](12-pilhas-e-filas.md) | Anulada pela banca. a simulação dá estado final `e`, que não está em nenhuma alternativa |
| 10 | E | afirmações | 4 | [0099](14-arvores.md) | Gabarito oficial E. A figura não veio no texto, então o curso não tinha letra. |
| 11 | A | simulação | 4 | [0098](14-arvores.md) | pós-ordem dá raiz P; Q tem filhos S e T; S e T são folhas |
| 12 | C | afirmações | 6 | [0089](13-busca-e-ordenacao.md), [0090](13-busca-e-ordenacao.md) | I falsa (sequencial vale em ordenado), II falsa (busca em vetor ordenado é O(log n)), III verdadeira (varredura O(n)) |
| 13 | B | código | 3 | [0083](12-pilhas-e-filas.md), [0049](06-ponteiros.md), [0062](08-structs.md) | a função I altera cópia de `prim`; a II usa `No **` e empilha certo |
| 14 | D | afirmações | 5 | [0107](15-hash.md) | só IV: tamanho fixo; sondagem linear não usa busca binária nem coloca no início |
| 15 | B | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md), [0179](28-estruturas-complementos.md) | I falsa (linear não passa de M), II descreve o linear, III sem sentido, IV é dispersão dupla, não encadeamento |
| 16 | E | cálculo | 4 | [0102](14-arvores.md) | índice 4 (13) é folha com pai 5; trocar por 8 mantém a heap; em b só há 1 troca (6 sobe de 10, para abaixo de 5) |
| 17 | anulada | conceito | 4 | [0099](14-arvores.md), [0101](14-arvores.md), [0102](14-arvores.md), [0177](28-estruturas-complementos.md) | Anulada pela banca. ABB degenera (W), AVL é balanceada (X), heap tem altura O(log n) (Y); ver observações |
| 18 | E | código | 3 | [0076](11-listas.md), [0077](11-listas.md) | Gabarito oficial E. O curso tinha chegado em B: `aux[x] != NULL` compara struct com NULL e não compila (além de `return x`) |
| 19 | A | conceito | 3 | [0076](11-listas.md) | ponteiros para início e fim dão acesso rápido às extremidades; as outras são falsas ou truncadas |
| 20 | D | conceito | 3 | [0079](11-listas.md) | lista dupla tem próximo e anterior (mesmas alternativas da 053/2016 Q06) |


**Observações**
- Q08 e Q10: figuras ausentes, sem como resolver.
- Q09: o estado final correto é só `e` (b, c, RETIRA, a, RETIRA, e, e, RETIRA, RETIRA), e nenhuma alternativa traz isso. Provável anulada.
- Q17: D e E são ambas defensáveis (heap pode ser dita balanceada ou de altura O(log n); falta o par I-Z que seria o canônico). Provável anulada. D escolhida por AVL ser a "balanceada" clássica.
- Q19: a letra e está truncada no original; a escolhida é a única inteira correta.
- Q20: alternativas dependem da 053/2016 Q06; a certa é a que cita próximo e anterior.

## Edital 055/2017
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | E | simulação | 1 | [0032](04-funcoes.md) | Gabarito oficial E. A figura não veio no texto, então o curso não tinha letra. pseudocódigo em figura ausente |
| 02 | C | conceito | 3 | [0085](12-pilhas-e-filas.md), [0086](12-pilhas-e-filas.md), [0097](14-arvores.md) | hierarquia de diretórios é árvore, não fila |
| 03 | anulada | simulação | 4 | [0099](14-arvores.md) | Anulada pela banca. na alternativa C, 912 aparece depois de ir à esquerda de 911; ver observações |
| 04 | B | afirmações | 4 | [0099](14-arvores.md) | Gabarito oficial B. A figura não veio no texto, então o curso não tinha letra. |
| 05 | D | conceito | 5 | [0105](15-hash.md) | endereço já ocupado é colisão |
| 06 | C | cálculo | 5 | [0106](15-hash.md) | posições: K=0, N=3 (não B), T=9 sozinho, nada em 6; I, II e IV verdadeiras, III falsa |
| 07 | D | simulação | 4 | [0098](14-arvores.md), [0099](14-arvores.md) | raiz 30, esquerda 20 (10, 25), direita 50 (40, 60); pré-ordem 30 20 10 25 50 40 60 |
| 08 | B | cálculo | 6 | [0090](13-busca-e-ordenacao.md) | floor(log2 1.000.000)+1 = 20 |
| 09 | anulada | conceito | 4 | [0146](22-arvores-avancadas.md) | Anulada pela banca. só com uma página (a raiz) a remoção não exige rebalanceamento, pois a raiz pode ter menos que o mínimo |
| 10 | anulada | afirmações | 4 | [0146](22-arvores-avancadas.md) | Anulada pela banca. I falsa (pode ter 2 filhos), II falsa, III falsa (folhas no mesmo nível), IV falsa (árvore B serve a disco) |
| 11 | D | afirmações | 3 | [0076](11-listas.md), [0090](13-busca-e-ordenacao.md), [0106](15-hash.md) | I falsa (lista é O(n)), II falsa ("unicamente"), III verdadeira (encadeamento) |
| 12 | C | cálculo | 7 | [0093](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | inserção faz cerca de n comparações; heap e quick fazem n log n ou pior; seleção n² |
| 13 | E | conceito | 7 | [0168](26-analise-formal.md), [0092](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md), [0103](14-arvores.md), [0094](13-busca-e-ordenacao.md), [0095](13-busca-e-ordenacao.md) | O(1) de espaço no pior caso: seleção, inserção, heap; merge usa O(n) e quick usa pilha de recursão (O(n) no pior caso) |
| 14 | B | afirmações | 6 | [0089](13-busca-e-ordenacao.md), [0090](13-busca-e-ordenacao.md) | I falsa (pior caso n), II verdadeira, III falsa (mesma contagem) |
| 15 | B | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md) | Gabarito oficial B. A figura não veio no texto, então o curso não tinha letra. nenhuma afirmação é verdadeira pelas definições; ver observações |
| 16 | B | afirmações | 4 | [0101](14-arvores.md) | Gabarito oficial B. A figura não veio no texto, então o curso não tinha letra. |
| 17 | E | simulação | 3 | [0082](12-pilhas-e-filas.md) | Gabarito oficial E. O curso tinha chegado em C: LIFO: sai 9, 8, 6 |
| 18 | E | código | 3 | [0086](12-pilhas-e-filas.md), [0083](12-pilhas-e-filas.md), [0049](06-ponteiros.md) | a funcaoII (`No **`) insere no início, serve para lista e pilha, mas fila insere no fim |
| 19 | A | simulação | 7 | [0095](13-busca-e-ordenacao.md) | 18 (índice 3) e 13 (índice 4) separam maiores à esquerda e menores à direita |
| 20 | A | simulação | 4 | [0101](14-arvores.md) | rodando AVL (programa em C): raiz 8, esquerda 4 (2, 6), direita 10 (12); diferença 0 |


**Observações**
- Q01, Q04, Q16: figuras ou pseudocódigo ausentes.
- Q03: C (912 na subárvore esquerda de 911) e E (299 abaixo de 347 vai à direita, mas 299 < 347) são ambas impossíveis. É o exercício 12.2-1 do Cormen, que também tem as duas. Provável anulada.
- Q15: pelas definições, encadeamento não tem colisão secundária (I falsa) e busca nunca passa de n comparações (II falsa); III falsa. Nenhuma alternativa certa. Se o autor tratou I como verdadeira, seria A. Provável anulada.
- Q13: E depende de contar a pilha de recursão do quicksort como espaço extra, o que é o padrão do Cormen.
- Q18: gabarito defensável é E; C só serviria se fila inserisse no início e retirasse no fim.
- Gabarito original diz que 3 foram anuladas; candidatas: Q03, Q15 e uma das que dependem de figura (01, 04, 16).
## Edital 023/2018
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | C | cálculo | 2, 7 | [0094](13-busca-e-ordenacao.md), [0072](10-analise.md) | Intercalar dois vetores ordenados copia 2N elementos, então O(N) mesmo no melhor caso. |
| 02 | C | afirmações | 4 | [0146](22-arvores-avancadas.md) | I, II e V são as propriedades da árvore B; III é falsa (balanceia pouco) e IV é falsa (k filhos têm k-1 chaves). |
| 03 | D | conceito | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Com folha de altura 1, três nós em altura três é uma cadeia, com fator de balanceamento 2 na raiz. |
| 04 | B | afirmações | 4 | [0102](14-arvores.md) | Gabarito oficial B. O curso tinha chegado em D: I é max-heap válido; II confere (12 sobe e troca com 10); III é falsa (o 12 não existe no heap, o certo é `14 9 10 5`). |
| 05 | anulada | conceito | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Anulada pela banca. Repetida da 03, mesma resposta. |
| 06 | C | conceito | 4, 6 | [0099](14-arvores.md), [0082](12-pilhas-e-filas.md) | Lista ordenada pela pilha sai ordenada ao contrário e a ABB degenera em lista: busca O(N). |
| 07 | B | afirmações | 4 | [0101](14-arvores.md), [0176](28-estruturas-complementos.md) | F-V-V-V-F: AVL exige as duas subárvores AVL, cheias são AVL e o custo de balancear é O(log n), não O(n/2). |
| 08 | C | simulação | 4 | [0098](14-arvores.md), [0099](14-arvores.md) | Rodado em C: pós-ordem `0 1 8 7 5 10 2`. |
| 09 | A | código | 3 | [0079](11-listas.md) | Ficam Z, Y, X, antigo próximo de Z: Y logo após Z e X logo após Y. |
| 10 | D | simulação | 4 | [0100](14-arvores.md) | Gabarito oficial D. A figura não veio no texto, então o curso não tinha letra. |
| 11 | C | simulação | 1 | [0032](04-funcoes.md), [0033](04-funcoes.md) | f(4)=f(3)+f(2)=(1+0)+1=2. |
| 12 | E | simulação | 6 | [0090](13-busca-e-ordenacao.md) | A posição do meio (índice 4) já vale 20: uma única comparação. |
| 13 | E | conceito | 3 | [0037](05-vetores-e-strings.md) | Vetor: homogêneo e acesso aleatório por índice. |
| 14 | D | afirmações | 6 | [0090](13-busca-e-ordenacao.md) | As três são verdadeiras (ordenado, no máximo log2 n + 1 comparações, supera a sequencial em n grande). |
| 15 | D | conceito | 4 | [0101](14-arvores.md), [0102](14-arvores.md), [0145](22-arvores-avancadas.md) | Heap com altura log n, ABB que degenera, AVL balanceada. Ver observação. |
| 16 | B | conceito | 7 | [0103](14-arvores.md) | O heap é uma árvore binária em vetor; o pior caso do heapsort é O(n log n), melhor que o do quicksort. |
| 17 | D | afirmações | 7 | [0096](13-busca-e-ordenacao.md), [0103](14-arvores.md), [0093](13-busca-e-ordenacao.md) | I, II e III são falsas; IV e V são verdadeiras. A alternativa D lista só as incorretas. |
| 18 | D | simulação | 5 | [0105](15-hash.md), [0106](15-hash.md) | Rodado em C: colidem as posições 1 (1, 12, 34), 4 (4, 15) e 6 (28, 17): três posições. |
| 19 | E | conceito | 3 | [0076](11-listas.md), [0077](11-listas.md) | Lista encadeada não exige área contígua e cria e remove nós dinamicamente. |
| 20 | C | afirmações | 3, 4 | [0076](11-listas.md), [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md), [0097](14-arvores.md) | Só a III é correta: fila não tem associação a vários elementos, árvore não é LIFO e pilha é LIFO. |


**Observações**
- Q10: depende da figura da árvore. Sem como inferir.
- Q03 e Q05 são a mesma questão repetida no caderno.
- Q15: D (I-Y, IV-W, III-X) e E (I-X, IV-W, II-Y) são defensáveis, e nenhuma associa o heap a "sempre completa" (Z). Provável anulada. Fica D.
- Q04: o vetor do item III veio embaralhado no original, mas o 12 não pertence a esse heap, então III é falsa de qualquer jeito.
- Q12: o vetor veio com erros (`32 8 12 16 20 ...`). Nas duas versões o índice 4 vale 20, então E vale.
- Q17: a pergunta pede a alternativa que lista só as afirmações incorretas.

## Edital 061/2018
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | B | cálculo | 5 | [0105](15-hash.md), [0178](28-estruturas-complementos.md) | `x mod 12000` cobre exatamente 0 a 11.999; a A só gera 1000 endereços. |
| 02 | D | conceito | 3 | [0039](05-vetores-e-strings.md) | Soma de matrizes m×n dá m×n, não 2m×2n. |
| 03 | anulada | simulação | 4 | [0101](14-arvores.md) | Anulada pela banca. Figura ausente. Rodado em C: A, B e E geram a mesma árvore (raiz 23); C gera raiz 13 e D, raiz 15. |
| 04 | anulada | conceito | 7, 2 | [0092](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | Anulada pela banca. O melhor caso do selection sort é O(N²), não O(log N). |
| 05 | B | simulação | 4 | [0099](14-arvores.md) | Folhas 5 e 42, pai do 72 é o 25. |
| 06 | D | conceito | 7 | [0095](13-busca-e-ordenacao.md), [0168](26-analise-formal.md) | No pior caso a pilha de recursão do quicksort chega a O(n). |
| 07 | E | afirmações | 3, 4, 5 | [0082](12-pilhas-e-filas.md), [0101](14-arvores.md), [0105](15-hash.md) | I, II e IV verdadeiras; III falsa (acesso por índice contra encadeamento). |
| 08 | anulada | conceito | 3 | [0082](12-pilhas-e-filas.md), [0054](07-memoria-dinamica.md) | Anulada pela banca. Pilha é linear. Ver observação. |
| 09 | anulada | cálculo | 4 | [0146](22-arvores-avancadas.md) | Anulada pela banca. Raiz com 2 filhos e demais com pelo menos m/2: 2·(m/2)^(d-1) no nível d (raiz = nível 1). |
| 10 | A | simulação | 3, 4 | [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md), [0098](14-arvores.md) | A ABB em ordem dá v1 e v2 crescentes. Empilhar e desempilhar inverte; alternando começando por v1, v1[i] fica com a posição 2i e v2[i] com a 2i+1 da sequência decrescente: v1[i] ≥ v2[i]. |
| 11 | E | afirmações | 4 | [0146](22-arvores-avancadas.md) | Com uma só página (raiz folha), remover não pede balanceamento. As outras confundem split com remoção. |
| 12 | A | conceito | 3 | [0080](11-listas.md) | Na circular não há nulo: é preciso marcar o ponto de parada quando o elemento não existe. |
| 13 | C | simulação | 4 | [0099](14-arvores.md) | Só a C é impossível: após 911 vem 240 (à direita de 202, esquerda de 911), e o 912 sairia do intervalo (240, 911). A nova E é válida (350, 392, 358 cabem). |
| 14 | E | afirmações | 4 | [0146](22-arvores-avancadas.md), [0101](14-arvores.md) | I, II, III e IV são falsas: nó com 2 filhos é possível, não vem da AVL, folhas no mesmo nível, árvore B serve justamente para armazenamento secundário. |
| 15 | E | conceito | 4 | [0101](14-arvores.md), [0145](22-arvores-avancadas.md) | A ABB com diferença maior que 1 não é AVL, mas pode ser rubro-negra: nada se conclui com certeza. |
| 16 | A | afirmações | 5 | [0106](15-hash.md) | Só a I é verdadeira (colisão secundária é conceito de endereçamento aberto); II e III são falsas. |
| 17 | anulada | afirmações | 7 | [0121](18-ordenacao-linear.md) | Anulada pela banca. I e III são verdadeiras; com a nova E ("nenhuma verdadeira"), nenhuma alternativa serve. Ver observação. |
| 18 | E | afirmações | 5 | [0106](15-hash.md) | I e II são verdadeiras; a III é duvidosa. Ver observação. |
| 19 | D | afirmações | 4 | [0101](14-arvores.md), [0176](28-estruturas-complementos.md) | V-V-F: após inserção uma rotação (simples ou dupla) basta; a propagação até a raiz é da remoção. |
| 20 | A | simulação | 3 | [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md) | Fila exibida: 10-29-...-11 (I). Pilha final: topo 11-12-...-10 (II). III e IV são falsas. |


**Observações**
- Q03: figura ausente e três alternativas (A, B, E) dão a mesma árvore. Se a figura for a delas, a questão tem três certas (anulada). Se for a da C ou da D, a resposta é única.
- Q08: C e E estão incorretas (pilha é linear, e array dinâmico não vira lista ligada). Duas alternativas erradas: provável anulada. Fica C.
- Q17: a E original era "Nenhuma das alternativas anteriores" (certa, com I, II e III verdadeiras). Aqui foi trocada por "nenhuma das afirmações é verdadeira", o que deixa a questão sem resposta. Provável anulada.
- Q18: a III é discutível (hash encadeado ocupa mais espaço que árvore B em memória?). Fica E (I e II); a alternativa A só vale se a III for aceita.
- Q20: o texto de 061 não traz as alternativas. As afirmações corretas são I e II; a letra A é a mesma da Q08 de 053/2016 (I e II), então é inferência.
## Edital 033/2019

| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | A | simulação | 7 | [0095](13-busca-e-ordenacao.md) | Com pivô no primeiro, a entrada já ordenada é o pior caso: 21 comparações contra 11 a 12 nas outras (rodado em C). |
| 02 | D | simulação | 4 | [0102](14-arvores.md) | Gabarito oficial D. A figura não veio no texto, então o curso não tinha letra. |
| 03 | A | simulação | 3 | [0082](12-pilhas-e-filas.md) | 5 push menos 4 pop deixa 1 elemento (o 1). |
| 04 | C | simulação | 4 | [0097](14-arvores.md) | Folha `110` fica com 1 chave; irmãos têm o mínimo (2) e não emprestam, então funde com a direita: `110 140 144 156`, raiz `100 160`. |
| 05 | anulada | conceito | 3 | [0076](11-listas.md), [0077](11-listas.md) | Anulada pela banca. Pior caso da busca sequencial em lista é n comparações. |
| 06 | D | código | 3 | [0076](11-listas.md), [0032](04-funcoes.md) | Imprime 1, 3, 5, chama com NULL e volta imprimindo 5, 3, 1: `1 3 5 5 3 1`. |
| 07 | B | conceito | 3 | [0031](04-funcoes.md), [0032](04-funcoes.md) | Recursão usa a pilha de chamadas. |
| 08 | D | conceito | 4 | [0099](14-arvores.md) | ABB sem balanceamento: pior caso O(n), caso médio O(log n). |
| 09 | A | cálculo | 4 | [0097](14-arvores.md) | Ordem 4 (4 filhos, 3 chaves), altura 3 em arestas (Cormen): 1+4+16+64 = 85 nós, 85 x 3 = 255 chaves. |
| 10 | anulada | afirmações | 5 | [0105](15-hash.md), [0107](15-hash.md) | Anulada pela banca. I: 22 colide uma vez e 39 duas (3 colisões, não 2); II: 5, 22 e 39 têm o mesmo h1, então colidem também em hash duplo; III: 17 chaves 0 a 16 não colidem. |
| 11 | B | código | 3 | [0080](11-listas.md) | Gabarito oficial B. O curso tinha chegado em E: O `break` incondicional faz o laço rodar no máximo uma vez, então o código não busca nada de forma coerente; nenhuma das opções descreve isso. |
| 12 | B | cálculo | 4 | [0101](14-arvores.md) | Mínimo de nós por altura em AVL: 1, 2, 4, 7; 7 nós cabem em altura 3 (nó único = 0). |
| 13 | anulada | afirmações | 4 | [0101](14-arvores.md), [0102](14-arvores.md) | Anulada pela banca. II e III são verdadeiras; I só vale para heap máximo e o enunciado não diz qual. |
| 14 | D | simulação | 7 | [0093](13-busca-e-ordenacao.md) | Após a 1ª rodada: 8 34 64 51 32 21; a 2ª insere o 64 sem mover nada. |
| 15 | anulada | conceito | 7 | [0091](13-busca-e-ordenacao.md) | Anulada pela banca. Com a troca de parada antecipada, o bubble detecta vetor já ordenado. |
| 16 | E | conceito | 4 | [0102](14-arvores.md) | Array por níveis: 88 66 77 33 44 55 75 30 22 5. |
| 17 | C | conceito | 3 | [0085](12-pilhas-e-filas.md), [0082](12-pilhas-e-filas.md) | Fila com duas pilhas. |
| 18 | A | conceito | 7 | [0093](13-busca-e-ordenacao.md) | Insertion sort em vetor já ordenado roda em Θ(N). |
| 19 | A | simulação | 4 | [0101](14-arvores.md) | Rodado em C: raiz 6; 3 e 8; 2, 5, 7, 9; 1, 4. |
| 20 | B | afirmações | 4 | [0101](14-arvores.md) | I falsa (a raiz de uma subárvore pode ser vermelha); II e III verdadeiras. |


**Observações**
- Q02 depende de figura ausente.
- Q04: os blocos vieram desalinhados. A letra C é a única que bate com a fusão padrão, mas B também é um B-tree válido; a leitura das letras é provável.
- Q09: se "altura 3" contasse níveis, daria 21 x 3 = 63 (letra B). Pelo Cormen (arestas) é 255.
- Q10: depende de como se conta colisão. Contando chaves que colidiram (22 e 39) a afirmação I vira verdadeira e a resposta passa a D. Provável anulada.
- Q11: código em Java e truncado, enunciado confuso. Provável anulada.
- Q13: I só é verdadeira em heap máximo (e com "menor ou igual"). Se valesse, as três seriam verdadeiras e nenhuma opção bateria, o que faz dela candidata a anulada. B vale se I for tomada como falsa.
- Q20: I é falsa porque a raiz de uma subárvore pode ser vermelha; só B bate com II e III verdadeiras.
- Anuladas (4, não identificadas no original): candidatas Q02, Q10, Q11, Q13.

## Edital 060/2019

| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | C | simulação | 5 | [0107](15-hash.md) | Rodado em C: só a ordem de C gera 9 18 _ 12 3 14 4 21 (as de b e e trocam 9 e 18). |
| 02 | A | simulação | 4 | [0101](14-arvores.md) | Gabarito oficial A. A figura não veio no texto, então o curso não tinha letra. O programa dá: raiz 20; 15 e 25; 10, 18, 30; 16 e 19 (filhos de 18). |
| 03 | D | conceito | 2 | [0071](10-analise.md), [0072](10-analise.md) | 2n+1 é linear. |
| 04 | C | cálculo | 6 | [0090](13-busca-e-ordenacao.md) | Posições examinadas: 12, 18, 15, 13, 14 = 5. |
| 05 | B | código | 3 | [0076](11-listas.md), [0032](04-funcoes.md) | Recursão antes do printf imprime do último ao primeiro. |
| 06 | C | conceito | 5 | [0106](15-hash.md) | Com m fixo, a cadeia média tem n/100 nós, que é O(n). |
| 07 | D | código | 3 | [0076](11-listas.md) | `q->next = NULL; p->next = head; head = p;` tira o último e o põe na frente. |
| 08 | B | conceito | 7 | [0093](13-busca-e-ordenacao.md) | Insertion sort faz n-1 comparações em entrada ordenada ou igual. |
| 09 | A | conceito | 4 | [0101](14-arvores.md) | Propriedade da rubro-negra: caminho mais longo no máximo o dobro do mais curto. |
| 10 | E | conceito | 3 | [0031](04-funcoes.md), [0032](04-funcoes.md) | Recursão usa a pilha. |
| 11 | anulada | conceito | 4 | [0097](14-arvores.md) | Anulada pela banca. B e rubro-negra têm busca O(log n) no pior caso, então "diferente" é falsa. |
| 12 | D | simulação | 4 | [0101](14-arvores.md) | A e C respeitam o fator de balanceamento; em B, o 50 fica com subárvore esquerda de altura 2 e direita vazia. |
| 13 | anulada | afirmações | 4 | [0099](14-arvores.md), [0101](14-arvores.md) | Anulada pela banca. ABB sem balanceamento tem pior caso O(n), não O(log n). |
| 14 | anulada | cálculo | 6 | [0090](13-busca-e-ordenacao.md), [0072](10-analise.md) | Anulada pela banca. O candidato é a[n/2]; achar o início do bloco por busca binária custa Θ(log n). |
| 15 | A | conceito | 4 | [0101](14-arvores.md) | AVL é mais rígida (altura menor) e rotaciona mais. |
| 16 | anulada | simulação | 4 | [0099](14-arvores.md), [0100](14-arvores.md), [0098](14-arvores.md) | Anulada pela banca. Figura ausente, mas só a E não tem 9 nem 23 (removidos) e tem 5 e 17 (inseridos); pré e pós-ordem conferem com a árvore reconstruída. |
| 17 | C | cálculo | 7 | [0094](13-busca-e-ordenacao.md), [0072](10-analise.md) | c·n·log n: 64 x 6 = 384 ↔ 30 s; 360 s dá n·log n = 4608, que é 512 x 9. |
| 18 | A | simulação | 7 | [0093](13-busca-e-ordenacao.md) | Cada rodada insere o próximo elemento: 4 5 3 2 1, 3 4 5 2 1, 2 3 4 5 1, 1 2 3 4 5. |
| 19 | E | conceito | 3 | [0079](11-listas.md) | Com ponteiros de início e fim e elo anterior, as quatro operações são O(1). |
| 20 | E | conceito | 3 | [0085](12-pilhas-e-filas.md) | Vazia: REAR == FRONT; cheia: (REAR+1) mod n == FRONT. |


**Observações**
- Q01: a tabela do enunciado põe 12 na posição 2, mas 12 mod 9 = 3 e a sondagem só chegaria lá dando a volta. A transcrição perdeu um vazio: o recorte da prova (`provas-ppgi-ufam/2019-060/figuras/q01-tabela-hash.png`) mostra `9 18 _ 12 3 14 4 21 _`, com o 12 na posição 3. A letra C vale.
- Q02 e Q16 dependem de figura ausente. Q16 foi inferida por exclusão.
- Q08: heapsort com elementos todos iguais também é O(n) (o max-heapify para na hora). A e B são defensáveis; B é a esperada.
- Q11: C também é questionável (folha não tem filhos, então "sempre chaves + 1" só vale em nó interno). B é a mais provável.
- Q12: figura parcial; B reconstruída com a interrogação no texto. D se a reconstrução estiver certa.
- Anuladas (4, não identificadas): candidatas Q02, Q08, Q11, Q12.
## Edital 057/2022
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | d | código | 3 | [0039](05-vetores-e-strings.md) | (Python) produto escalar 0·1+2·0+0·3+0·4+5·0 = 0; rodado. |
| 02 | c | afirmações | 4 | [0099](14-arvores.md), [0175](28-estruturas-complementos.md) | 1 e 2 valem; 3 é falsa: com subárvore direita, o sucessor está abaixo de x. |
| 03 | b | afirmações | 7 | [0094](13-busca-e-ordenacao.md), [0095](13-busca-e-ordenacao.md), [0092](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | Quicksort é O(n²) no pior caso; merge é Θ(n log n); seleção é sempre Θ(n²). F, V, V, F. |
| 04 | c | simulação | 4 | [0099](14-arvores.md) | O primeiro inserido (8) é a raiz. |
| 05 | b | conceito | 3 | [0083](12-pilhas-e-filas.md) | Inserir e remover na cabeça da lista simples é O(1). |
| 06 | d | código | 3 | [0044](06-ponteiros.md), [0062](08-structs.md) | (Python) `vec_2 = vec_1` é alias; a lista muda nas duas: [1, 2, 15, 4, 5]. Rodado. Em C: 0045. |
| 07 | d | conceito | 2 | [0072](10-analise.md), [0166](26-analise-formal.md) | f = n²−1 é quadrática, g é logarítmica; log n = O(n²), então g = O(f). b erra por chamar g de linear. |
| 08 | d | código | 1 | [0032](04-funcoes.md), [0033](04-funcoes.md) | (Python) fibonacci(7) com f(1)=0, f(2)=1 dá 0,1,1,2,3,5,8; rodado. |
| 09 | b | conceito | 8 | [0109](16-grafos.md), [0150](23-grafos-avancados.md) | Árvore é grafo conexo, não direcionado e sem ciclos. |
| 10 | a | conceito | 3 | [0039](05-vetores-e-strings.md) | m×n por n×y dá m linhas e y colunas, não "n linhas". |
| 11 | d | afirmações | 6 | [0090](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md) | Busca binária faz O(log n) comparações contra O(n) da inserção; os deslocamentos são os mesmos. Vale 1 e 3. |
| 12 | d | conceito | 7 | [0095](13-busca-e-ordenacao.md) | Pior caso do Quicksort é O(n²). |
| 13 | a | código | 3 | [0039](05-vetores-e-strings.md), [0024](03-repeticoes.md) | O laço interno começa em j = i: elementos na diagonal e acima. |
| 14 | a | código | 1 | [0029](04-funcoes.md), [0038](05-vetores-e-strings.md) | x passa por valor (222); vetor passa por endereço: v[0] = 3·333 = 999. |
| 15 | a | código | 3 | [0079](11-listas.md) | Novo nó com prox = l, ant = NULL e l->ant = novo: inserção no início de lista dupla. |
| 16 | c | simulação | 5 | [0107](15-hash.md) | 73→1, 24→6, 16→7, 46→1 colide→2, 28→1 colide→3. Tabela: ø 73 46 28 ø ø 24 16 ø. |
| 17 | b | conceito | 4 | [0177](28-estruturas-complementos.md) | As três são propriedades da rubro-negra do Cormen (raiz preta, folhas nulas pretas, vermelho tem filhos pretos). |
| 18 | a | afirmações | 8 | [0110](16-grafos.md), [0112](16-grafos.md), [0109](16-grafos.md) | 1 falsa (Dijkstra é polinomial); 2 e 3 verdadeiras. |
| 19 | b | cálculo | 4 | [0176](28-estruturas-complementos.md), [0101](14-arvores.md) | Melhor caso O(1) (sem rebalancear), pior O(log n) (rotações até a raiz). |
| 20 | b | cálculo | 3 | [0075](11-listas.md), [0072](10-analise.md) | Busca O(n), índice O(1), início O(n), fim O(1), remoção por índice O(n). |


**Observações**
- Q16: a alternativa c vem com 8 células no texto (falta o ø final da posição 8); tratada como erro de transcrição.
- Q19: depende do que se conta. Se a remoção do nó com dois filhos precisar achar o sucessor, o melhor caso também seria O(log n) (alternativa a). Fico com b.
- Q11: o `for (k = N+1; k == i; k--)` está assim no original; se for erro de enunciado, a questão pode ter sido anulada.
- Q06 e Q08 são Python mas o conteúdo é de C (alias de ponteiro, Fibonacci recursivo). Q01 também.

## Edital 020/2023
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | C | cálculo | 6 | [0090](13-busca-e-ordenacao.md) | 10 elementos: ⌊log2 10⌋ + 1 = 4 comparações no pior caso. |
| 02 | A | conceito | 7 | [0093](13-busca-e-ordenacao.md) | Inserção é O(n) quase ordenada e O(n²) invertida. |
| 03 | D | simulação | 3 | [0082](12-pilhas-e-filas.md) | Pop 3 vezes deixa [7, 8, 13]; push 5 e 2 dá [2, 5, 7, 8, 13]. |
| 04 | D | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md) | Encadeamento não tem agrupamento secundário, pior caso O(n) e aceita mais chaves que a tabela. |
| 05 | B | afirmações | 4 | [0090](13-busca-e-ordenacao.md), [0099](14-arvores.md), [0101](14-arvores.md) | I falsa: vetor ordenado insere em O(n). II verdadeira: busca O(log n) nos dois. |
| 06 | B | conceito | 4 | [0099](14-arvores.md), [0101](14-arvores.md), [0102](14-arvores.md) | Figura ausente. Três nós com raiz 5 é o caso mais geral para ABB; as outras dependem dos valores e cores. Inferida. |
| 07 | B | conceito | 2 | [0072](10-analise.md), [0076](11-listas.md) | Inserir no início de lista encadeada é O(1). Busca binária é O(log n); vetor e ABB são piores. |
| 08 | C | código | 7 | [0094](13-busca-e-ordenacao.md) | Divide ao meio, recursão nas duas metades e intercalação com vetor auxiliar: Merge Sort. |
| 09 | sem resposta | código | 1 | [0032](04-funcoes.md) | Figura ausente, o pseudocódigo recursivo não veio. |
| 10 | D | simulação | 3 | [0039](05-vetores-e-strings.md) | Figura ausente. m=2 e p=2 pedem resultado 2×2; só A e D têm essa forma. Palpite com baixa confiança. |


**Observações**
- Q09: figura ausente, sem como resolver.
- Q10: figura ausente. D só por forma 2×2; A (todos zeros) também é possível.
- Q06: figura ausente; B é inferência.
- Q08: o código não veio na íntegra no resumo; assumi que está correto.

## Edital 071/2023 (gabarito oficial)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | anulada | código | 7 | [0092](13-busca-e-ordenacao.md) | O laço interno começa em j = 0 em vez de i+1 (rodado: {5,3,4,1,2} sai 3 4 5 1 2), faltam `;` e `}`. Provavelmente anulada por não compilar e ter mais de um erro. |
| 02 | A | afirmações | 7 | [0103](14-arvores.md) | Heapsort é O(n log n) no pior caso, em duas etapas (construir heap, extrair); III é falsa. |
| 03 | B | cálculo | 4 | [0102](14-arvores.md) | Troca a raiz com o último e desce: O(log N), sem deslocar o vetor. |
| 04 | C | cálculo | 2 | [0072](10-analise.md), [0166](26-analise-formal.md) | (300/100)³ = 27, logo 27 minutos. |
| 05 | B | afirmações | 2 | [0166](26-analise-formal.md) | I e III valem para algoritmo não vazio; II é falsa na prática, pois há custos acima de nⁿ (os símbolos vieram ilegíveis, conferir). |
| 06 | B | simulação | 6 | [0090](13-busca-e-ordenacao.md) | meio=4 (10), depois 1 (4), 2 (6), 3 (8): compara com 10, 4, 6 e 8. |
| 07 | anulada | afirmações | 4 | [0177](28-estruturas-complementos.md), [0101](14-arvores.md) | Altura máxima é 2·log(n+1), não log n (I falsa); II é defensável e III falsa; texto ambíguo. Provavelmente anulada por ambiguidade. |
| 08 | D | afirmações | 3 | [0083](12-pilhas-e-filas.md) | Pilha retira o último inserido (10), em custo constante na cabeça da lista. |
| 09 | B | conceito | 6 | [0090](13-busca-e-ordenacao.md), [0075](11-listas.md) | Vetor ordenado: busca binária O(log n); inserir e remover deslocam elementos, O(n). |
| 10 | anulada | afirmações | 7 | [0093](13-busca-e-ordenacao.md), [0094](13-busca-e-ordenacao.md), [0095](13-busca-e-ordenacao.md) | I falsa (quicksort tem pior pior caso); III é confusa por "menor custo" empatar com o heap/merge e II usa "um décimo de log N". Provavelmente anulada por redação. |
| 11 | D | cálculo | 3 | [0075](11-listas.md), [0090](13-busca-e-ordenacao.md) | Inserir e remover deslocam elementos O(n); busca binária O(log n). |
| 12 | B | simulação | 7 | [0095](13-busca-e-ordenacao.md) | Só o 9 da última posição tem tudo à esquerda menor ou igual. Os outros candidatos violam a partição. |
| 13 | C | simulação | 5 | [0106](15-hash.md) | 2→2, 5→0, 9→4, 20→0 (colide), 7→2 (colide): duas colisões. |
| 14 | D | simulação | 4 | [0099](14-arvores.md) | Caminhos 10-5-7 e 10-20-30 têm 3 nós; altura máxima 3 comparações. |
| 15 | B | código | 6 | [0090](13-busca-e-ordenacao.md) | (Python) busca binária em vetor desordenado procurando 100: sempre vai para a direita (30, 50, 60, 70) e devolve -1; rodado. |
| 16 | A | cálculo | 5 | [0106](15-hash.md), [0101](14-arvores.md) | Sem chave repetida, inserir exige varrer a lista, O(n), e buscar O(n); com rubro-negra, ambos O(log n). |
| 17 | C | simulação | 6 | [0090](13-busca-e-ordenacao.md) | (Python) busca de 70: 4 chamadas, rodado. |
| 18 | D | código | 3 | [0039](05-vetores-e-strings.md) | (Python) produto: [[11, 20], [7, 0]], rodado. |
| 19 | B | código | 3 | [0082](12-pilhas-e-filas.md) | (Python) pop vazio imprime "empty stack" e a pilha final é [2]; rodado. |
| 20 | B | código | 1 | [0029](04-funcoes.md), [0050](06-ponteiros.md) | (Python) fechamento: 5·3 = 15; rodado. Em C, o equivalente é ponteiro para função (0050), sem closure. |


**Observações**
- Q01 anulada: o código tem erro de sintaxe e de lógica; não vejo discordância da anulação.
- Q05: os símbolos de I vieram ilegíveis; conferir no PDF.
- Q07 e Q10: motivos de anulação são conjectura minha.
- Q12: concordo com B; confere com as quatro alternativas.
- Q15, Q17 a Q20 rodadas com `python3 -I`; todas batem com o gabarito oficial. Sem discordância das letras oficiais.

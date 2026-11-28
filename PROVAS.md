# Provas anteriores do PPGI/UFAM · gabarito comentado

As 17 provas de conhecimento de 2016 a 2026, resolvidas questão por questão. Os cadernos estão em
[`provas-ppgi-ufam/`](provas-ppgi-ufam/); o quiz, com o porquê de cada alternativa, em
[jhollyfer.github.io/LPEDC](https://jhollyfer.github.io/LPEDC/).

## 1. Conceitos gerais

- **Gabarito oficial**: as letras das 17 provas são da banca. As de 2016 a 2019 vêm das folhas de
  resposta, a 071/2023 do gabarito definitivo, a 057/2022 e a 020/2023 da marcação do caderno de
  respostas, as de 031/2024 a 014/2026 dos gabaritos finais e a 070/2026 do gabarito preliminar. Onde o curso chegou a outra letra, a coluna "Por quê" avisa.
- **Formato**: até 2019, 5 alternativas; desde 2022, **4 alternativas** e trechos em Python (cada
  trecho aponta para o assunto de C com a mesma ideia).
- **Colunas da tabela**:
  - **Letra**: a resposta oficial, ou "anulada";
  - **Formato**: `afirmações` (I, II, III combinadas), `código` (ler ou achar o erro), `simulação`
    (executar à mão), `conceito` (definição) ou `cálculo` (altura, comparações, complexidade);
  - **Tópico**: número do tópico do edital em [`PPGI.md`](PPGI.md#tópico-por-tópico);
  - **Assuntos**: o link leva ao módulo onde aquilo se estuda;
  - **Por quê**: a justificativa em uma ou duas frases. Questões de código e simulação foram
    conferidas rodando o programa.
- O resumo do que mais cai está em [`PPGI.md`](PPGI.md#o-que-caiu-de-2016-a-2026).

## 2. Exemplos de uso

Como corrigir uma questão, com a Q12 do edital 032/2016 (AVL):

1. Resolva no caderno, cronometrando 3 minutos.
2. Confira a linha: `| 12 | B | simulação | 4 | [0101](14-arvores.md) | Inserir 1..6 dá raiz 4, ... |`.
3. Errou? O formato `simulação` pede refazer à mão; o assunto 0101 do módulo 14 tem o exemplo e o
   passo a passo das rotações. Refaça a questão sem olhar a resposta.

## 3. Exercícios práticos

Resolva cada prova inteira no caderno e só depois confira a tabela.

### Edital 032/2016

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

#### Observações
- Anuladas pela banca (folha oficial): 01, 05, 07, 11 e 17. A Q09 (D), a Q10 (B) e a Q13 (E) foram mantidas.
- Q01: I é o particionamento de Hoare e III o de Lomuto; a anulação vem de IV, que pode ser aceita se "particionamento completo" admitir o pivô ainda fora do lugar.
- Q09: "colisões secundárias" é termo do endereçamento aberto; a banca leu I e II como falsas (D).
- Q10: a banca tratou `tm` como índice do último elemento, e não como tamanho; com essa leitura, só II erra (B).
- Q13: I e III verdadeiras, e "I e III" não existe entre as letras; a banca marcou E (nenhuma das anteriores).
- Q11 e Q17: dependem de considerar a III falsa (árvore B ocupa espaço com nós semicheios; radix in-place); anuladas.

### Edital 053/2016

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
| 11 | C | simulação | 4 | [0098](14-arvores.md) | A figura do caderno é P com Q(S, T) à esquerda e R à direita: pós-ordem S T Q R P e in-ordem S Q T P R. |
| 12 | B | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md) | I falsa (disco), II falsa (o linear não aceita C>M), III falsa (colisão no encadeado entra na lista). |
| 13 | A | conceito | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Nó de AVL é binário: grau 0, 1 ou 2. |
| 14 | A | conceito | 4 | [0099](14-arvores.md), [0098](14-arvores.md) | Gabarito oficial A. O curso tinha chegado em C: Em ordem na ABB dá chaves ordenadas. |
| 15 | B | afirmações | 7 | [0096](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md), [0094](13-busca-e-ordenacao.md), [0095](13-busca-e-ordenacao.md), [0103](14-arvores.md), [0168](26-analise-formal.md) | Incorretas: I (Quick não é estável), III (Heap usa O(1) extra), IV (Insertion depende da ordem). |
| 16 | A | cálculo | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Três nós em altura 3 é cadeia, fator de balanceamento 2: não é AVL. |
| 17 | E | código | 6 | [0089](13-busca-e-ordenacao.md), [0076](11-listas.md), [0057](07-memoria-dinamica.md) | Gabarito oficial E. O curso tinha chegado em D: I inverte o retorno e lê v[tm] fora; II usa aux[x] e retorna x em vez da contagem. |
| 18 | A | cálculo | 4 | [0097](14-arvores.md), [0175](28-estruturas-complementos.md) | Mínimo é 1 nó por nível (4), máximo é 2^4-1 = 15. |
| 19 | A | cálculo | 4 | [0097](14-arvores.md) | Nível 5 tem 2^(5-1) = 16 nós. |
| 20 | A | simulação | 4 | [0099](14-arvores.md) | Só a sequência A respeita os limites da ABB em todos os passos (B, C e D violam). |

#### Observações
- Nenhuma questão anulada; as 20 letras conferem com a folha oficial.
- Q11: a figura está no caderno: P com filhos Q (S, T) e R. Pós-ordem S T Q R P, in-ordem S Q T P R: C.
- Q14: o gabarito oficial é A (definição de árvore binária); a C (percurso em ordem) também é verdadeira.
- Q10 (hash linear): II é verdadeira, contrariando a mesma afirmação nas questões de encadeamento; aqui a resposta é D.
- Q17: mesma leitura de `tm` da Q10 de 032/2016: a banca o trata como índice do último elemento.
- Q08: a letra B está cortada e D e E repetem o texto no próprio caderno. A resposta A não depende disso.
- Q01: se o autor contou comparações e não iterações do laço, a conta é a mesma (9).
- Q07: a altura em arestas (Cormen) seria 4; o enunciado define raiz no nível 1, então vale 5.
### Edital 024/2017
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | A | afirmações | 3 | [0101](14-arvores.md), [0082](12-pilhas-e-filas.md), [0076](11-listas.md), [0106](15-hash.md) | I e IV verdadeiras; II falsa (pilha só remove do topo), III falsa (array é contíguo, lista não) |
| 02 | A | conceito | 7 | [0103](14-arvores.md), [0095](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md), [0092](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | pior caso: heapsort O(n log n); quicksort, inserção e seleção O(n²) |
| 03 | D | conceito | 7 | [0092](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | seleção faz no máximo n-1 trocas; heap e merge movem O(n log n) |
| 04 | A | afirmações | 3 | [0076](11-listas.md), [0090](13-busca-e-ordenacao.md), [0107](15-hash.md) | busca em lista é O(n) contra O(log n) no vetor; lista não ordena melhor que heapsort; endereçamento aberto usa vetor |
| 05 | B | código | 3 | [0076](11-listas.md), [0077](11-listas.md), [0054](07-memoria-dinamica.md) | só a versão II percorre sem malloc e sem erro; I vaza memória e tem `aux>prox`, III e IV têm laço errado |
| 06 | D | simulação | 3 | [0082](12-pilhas-e-filas.md) | LIFO: sai 9, 8, 6 |
| 07 | A | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md) | colisão secundária é de endereçamento aberto, então I é verdadeira; II e III falsas (pior caso é n, e aberto pode ganhar do encadeado) |
| 08 | E | afirmações | 4 | [0101](14-arvores.md) | Gabarito oficial E. Letra conferida com o recorte da prova em `provas-ppgi-ufam/`; o porquê de cada alternativa está no quiz. |
| 09 | anulada | simulação | 3 | [0085](12-pilhas-e-filas.md) | Anulada pela banca. a simulação dá estado final `e`, que não está em nenhuma alternativa |
| 10 | E | afirmações | 4 | [0099](14-arvores.md) | Gabarito oficial E. Letra conferida com o recorte da prova em `provas-ppgi-ufam/`; o porquê de cada alternativa está no quiz. |
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

#### Observações
- Q08 e Q10: as figuras estão no caderno (árvores I a IV); a letra E confere nas duas.
- Q09: anulada pela banca. O estado final correto é só `e` (b, c, RETIRA, a, RETIRA, e, e, RETIRA, RETIRA), e nenhuma alternativa traz isso.
- Q17: anulada pela banca. D e E são ambas defensáveis (falta o par I-Z, que seria o canônico).
- Q19: a letra e está completa no caderno; a única correta continua sendo a A.
- Q20: alternativas iguais às da 053/2016 Q06; a certa é a que cita próximo e anterior.

### Edital 055/2017
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | E | simulação | 1 | [0032](04-funcoes.md) | Gabarito oficial E. Letra conferida com o recorte da prova em `provas-ppgi-ufam/`; o porquê de cada alternativa está no quiz. |
| 02 | C | conceito | 3 | [0085](12-pilhas-e-filas.md), [0086](12-pilhas-e-filas.md), [0097](14-arvores.md) | hierarquia de diretórios é árvore, não fila |
| 03 | anulada | simulação | 4 | [0099](14-arvores.md) | Anulada pela banca. na alternativa C, 912 aparece depois de ir à esquerda de 911; ver observações |
| 04 | B | afirmações | 4 | [0099](14-arvores.md) | Gabarito oficial B. Letra conferida com o recorte da prova em `provas-ppgi-ufam/`; o porquê de cada alternativa está no quiz. |
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
| 15 | B | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md) | Gabarito oficial B. I falsa (colisão secundária é do endereçamento aberto), II verdadeira (no pior caso as n chaves caem na mesma lista, e n passa de √n), III falsa. |
| 16 | B | afirmações | 4 | [0101](14-arvores.md) | Gabarito oficial B. Letra conferida com o recorte da prova em `provas-ppgi-ufam/`; o porquê de cada alternativa está no quiz. |
| 17 | E | simulação | 3 | [0082](12-pilhas-e-filas.md) | Gabarito oficial E. O curso tinha chegado em C: LIFO: sai 9, 8, 6 |
| 18 | E | código | 3 | [0086](12-pilhas-e-filas.md), [0083](12-pilhas-e-filas.md), [0049](06-ponteiros.md) | a funcaoII (`No **`) insere no início, serve para lista e pilha, mas fila insere no fim |
| 19 | A | simulação | 7 | [0095](13-busca-e-ordenacao.md) | 18 (índice 3) e 13 (índice 4) separam maiores à esquerda e menores à direita |
| 20 | A | simulação | 4 | [0101](14-arvores.md) | rodando AVL (programa em C): raiz 8, esquerda 4 (2, 6), direita 10 (12); diferença 0 |

#### Observações
- Anuladas pela banca: 03, 09 e 10. O pseudocódigo da Q01 e as árvores da Q04 e da Q16 estão no caderno.
- Q03: C (912 na subárvore esquerda de 911) e E (299 abaixo de 347 vai à direita, mas 299 < 347) são ambas impossíveis. É o exercício 12.2-1 do Cormen, que também tem as duas.
- Q15: a II pede mais que √n comparações, não mais que n. Com todas as chaves na mesma lista a busca faz até n comparações, que passa de √n; por isso a II é verdadeira e a letra B da banca está certa.
- Q13: E depende de contar a pilha de recursão do quicksort como espaço extra, o que é o padrão do Cormen.
- Q18: gabarito defensável é E; C só serviria se fila inserisse no início e retirasse no fim.
### Edital 023/2018
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | C | cálculo | 2, 7 | [0094](13-busca-e-ordenacao.md), [0072](10-analise.md) | Intercalar dois vetores ordenados copia 2N elementos, então O(N) mesmo no melhor caso. |
| 02 | C | afirmações | 4 | [0146](22-arvores-avancadas.md) | I, II e V são as propriedades da árvore B; III é falsa (balanceia pouco) e IV é falsa (k filhos têm k-1 chaves). |
| 03 | D | conceito | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Com folha de altura 1, três nós em altura três é uma cadeia, com fator de balanceamento 2 na raiz. |
| 04 | B | afirmações | 4 | [0102](14-arvores.md) | Gabarito oficial B. I é falsa: o 45 (posição 4) é filho do 40 (posição 1) e é maior; II confere (12 sobe e troca com 10); III é falsa (o 12 não existe no heap, o certo é `14 9 10 5`). Só a II: B. |
| 05 | anulada | conceito | 4 | [0101](14-arvores.md), [0175](28-estruturas-complementos.md) | Anulada pela banca. Repetida da 03, mesma resposta. |
| 06 | C | conceito | 4, 6 | [0099](14-arvores.md), [0082](12-pilhas-e-filas.md) | Lista ordenada pela pilha sai ordenada ao contrário e a ABB degenera em lista: busca O(N). |
| 07 | B | afirmações | 4 | [0101](14-arvores.md), [0176](28-estruturas-complementos.md) | F-V-V-V-F: AVL exige as duas subárvores AVL, cheias são AVL e o custo de balancear é O(log n), não O(n/2). |
| 08 | C | simulação | 4 | [0098](14-arvores.md), [0099](14-arvores.md) | Rodado em C: pós-ordem `0 1 8 7 5 10 2`. |
| 09 | A | código | 3 | [0079](11-listas.md) | Ficam Z, Y, X, antigo próximo de Z: Y logo após Z e X logo após Y. |
| 10 | D | simulação | 4 | [0100](14-arvores.md) | Gabarito oficial D. Letra conferida com o recorte da prova em `provas-ppgi-ufam/`; o porquê de cada alternativa está no quiz. |
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

#### Observações
- Anulada pela banca: Q05, que repete o enunciado da Q03 no próprio caderno.
- Q10: a figura está no caderno; a remoção pelo antecessor dá 18 (D). O curso (0100) remove pelo sucessor, que daria 21.
- Q15: gabarito oficial D, apesar de E também ser defensável; nenhuma alternativa associa o heap a "sempre completa" (Z).
- Q04: o 12 não pertence ao heap do item III, então III é falsa de qualquer jeito.
- Q12: o vetor `32 8 12 16 20 24 28 16 36` é assim no caderno. O índice 4 vale 20, então E vale.
- Q17: a pergunta pede a alternativa que lista só as afirmações incorretas.

### Edital 061/2018
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | B | cálculo | 5 | [0105](15-hash.md), [0178](28-estruturas-complementos.md) | `x mod 12000` cobre exatamente 0 a 11.999; a A só gera 1000 endereços. |
| 02 | D | conceito | 3 | [0039](05-vetores-e-strings.md) | Soma de matrizes m×n dá m×n, não 2m×2n. |
| 03 | anulada | simulação | 4 | [0101](14-arvores.md) | Anulada pela banca. A figura do caderno é a AVL de raiz 23. Rodado em C: A, B e E geram a mesma árvore (raiz 23); C gera raiz 13 e D, raiz 15. |
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

#### Observações
- Anuladas pela banca: 03, 04, 08, 09 e 17.
- Q03: a figura existe no caderno (árvore AVL de raiz 23). A, B e E dão a mesma árvore: três certas, anulada.
- Q08: C e E estão incorretas (pilha é linear, e array dinâmico não vira lista ligada). Duas alternativas erradas: anulada.
- Q09: os expoentes estão no caderno; na A o sobrescrito fica só no 2 de `m/2`, o que deixa a fórmula ambígua.
- Q17: com I, II e III verdadeiras, nenhuma alternativa serve (a E diz que nenhuma é verdadeira). Anulada.
- Q18: a III é discutível (hash encadeado ocupa mais espaço que árvore B em memória?). Fica E (I e II); a alternativa A só vale se a III for aceita.
- Q20: o caderno traz as alternativas (D e E repetidas, ambas "III e IV"). A letra A é a da folha oficial.
### Edital 033/2019

| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | A | simulação | 7 | [0095](13-busca-e-ordenacao.md) | Com pivô no primeiro, a entrada já ordenada é o pior caso: 21 comparações contra 10 a 13 nas outras (rodado em C). |
| 02 | D | simulação | 4 | [0102](14-arvores.md) | Gabarito oficial D. Letra conferida com o recorte da prova em `provas-ppgi-ufam/`; o porquê de cada alternativa está no quiz. |
| 03 | A | simulação | 3 | [0082](12-pilhas-e-filas.md) | 5 push menos 4 pop deixa 1 elemento (o 5). |
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

#### Observações
- Anuladas pela banca: 05, 10, 13 e 15. As figuras da Q02, Q04, Q16 e Q19 estão no caderno.
- Q04: só C sai da fusão padrão; B é uma árvore B válida, mas não sai de remoção padrão.
- Q09: se "altura 3" contasse níveis, daria 21 x 3 = 63 (letra B). Pelo Cormen (arestas) é 255.
- Q10: depende de como se conta colisão. Contando chaves que colidiram (22 e 39) a afirmação I vira verdadeira e a resposta passa a D.
- Q11: o gabarito oficial é B; o curso chegaria em E (código em Java e truncado, enunciado confuso).
- Q13: I só é verdadeira em heap máximo (e com "menor ou igual"). Se valesse, as três seriam verdadeiras e nenhuma opção bateria.
- Q20: I é falsa porque a raiz de uma subárvore pode ser vermelha; só B bate com II e III verdadeiras.

### Edital 060/2019

| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | C | simulação | 5 | [0107](15-hash.md) | Rodado em C: só a ordem de C gera 9 18 _ 12 3 14 4 21 (as de b e e trocam 9 e 18). |
| 02 | A | simulação | 4 | [0101](14-arvores.md) | Gabarito oficial A. Letra conferida com o recorte da prova em `provas-ppgi-ufam/`; o porquê de cada alternativa está no quiz. O programa dá: raiz 20; 15 e 25; 10, 18, 30; 16 e 19 (filhos de 18). |
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

#### Observações
- Q01: a tabela do enunciado põe 12 na posição 2, mas 12 mod 9 = 3 e a sondagem só chegaria lá dando a volta. A transcrição perdeu um vazio: o recorte da prova (`provas-ppgi-ufam/2019-060/figuras/q01-tabela-hash.png`) mostra `9 18 _ 12 3 14 4 21 _`, com o 12 na posição 3. A letra C vale.
- Anuladas pela banca: 11, 13, 14 e 16. A figura da Q02 existe; a da Q16 não está no caderno ("figura abaixo" sem figura), o que explica a anulação.
- Q08: heapsort com elementos todos iguais também é O(n) (o max-heapify para na hora). A e B são defensáveis; B é a esperada.
- Q11: C também é questionável (folha não tem filhos, então "sempre chaves + 1" só vale em nó interno).
- Q12: figura completa no caderno: A e C são AVL, B não é (50 com esquerda de altura 2 e direita vazia).
### Edital 057/2022 (gabarito oficial)
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

#### Observações
- As 20 letras em negrito do caderno oficial batem com as que o curso tinha chegado.
- Q16: a alternativa c tem 8 células no próprio caderno (falta o ø final da posição 8); a banca marcou c mesmo assim.
- Q19: depende do que se conta. Se a remoção do nó com dois filhos precisar achar o sucessor, o melhor caso também seria O(log n) (alternativa a). A banca marcou b.
- Q11: o `for (k = N+1; k == i; k--)` está assim no original e só roda se `novo` for o maior; a banca não anulou e marcou d.
- Q15: falta o `;` depois de `l->ant = novo` no caderno (não compila como está); a banca marcou a.
- Q06 e Q08 são Python mas o conteúdo é de C (alias de ponteiro, Fibonacci recursivo). Q01 também.

### Edital 020/2023 (gabarito oficial)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | C | cálculo | 6 | [0090](13-busca-e-ordenacao.md) | 10 elementos: ⌊log2 10⌋ + 1 = 4 comparações no pior caso. |
| 02 | A | conceito | 7 | [0093](13-busca-e-ordenacao.md) | Inserção é O(n) quase ordenada e O(n²) invertida. |
| 03 | D | simulação | 3 | [0082](12-pilhas-e-filas.md) | Pop 3 vezes deixa [7, 8, 13]; push 5 e 2 dá [2, 5, 7, 8, 13]. |
| 04 | D | afirmações | 5 | [0106](15-hash.md), [0107](15-hash.md) | Encadeamento não tem agrupamento secundário, pior caso O(n) e aceita mais chaves que a tabela. |
| 05 | B | afirmações | 4 | [0090](13-busca-e-ordenacao.md), [0099](14-arvores.md), [0101](14-arvores.md) | I falsa: vetor ordenado insere em O(n). II verdadeira: busca O(log n) nos dois. |
| 06 | C | conceito | 4 | [0099](14-arvores.md), [0101](14-arvores.md), [0102](14-arvores.md) | Gabarito oficial C. O curso tinha inferido B sem a figura: a árvore é 5 com filhos 7 (esquerda) e 6 (direita). Não é ABB (7 > 5 à esquerda), logo nem AVL nem rubro-negra; 5 ≤ 7 e 5 ≤ 6 fazem dela uma heap mínima. |
| 07 | B | conceito | 2 | [0072](10-analise.md), [0076](11-listas.md) | Inserir no início de lista encadeada é O(1). Busca binária é O(log n); vetor e ABB são piores. |
| 08 | C | código | 7 | [0094](13-busca-e-ordenacao.md) | Divide ao meio, recursão nas duas metades e intercalação com vetor auxiliar: Merge Sort. |
| 09 | A | código | 1 | [0032](04-funcoes.md) | Gabarito oficial A. O pseudocódigo devolve recursivamente o maior elemento da lista: 13; rodado em Python. |
| 10 | D | simulação | 3 | [0039](05-vetores-e-strings.md) | Gabarito oficial D. Produto de matrizes 2×3 por 3×2 rodado em Python: {{0, 30}, {45, 0}}. |

#### Observações
- O caderno com a marcação oficial trouxe as figuras e o código que faltavam no texto (Q06, Q08, Q09, Q10).
- Q04 e Q05: o caderno numera os itens como a, b, c, mas as alternativas falam em I, II, III.

### Edital 071/2023 (gabarito oficial)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | anulada | código | 7 | [0092](13-busca-e-ordenacao.md) | O laço interno começa em j = 0 em vez de i+1 (rodado: {5,3,4,1,2} sai 3 4 5 1 2), faltam `;` e `}`. Provavelmente anulada por não compilar e ter mais de um erro. |
| 02 | A | afirmações | 7 | [0103](14-arvores.md) | Heapsort é O(n log n) no pior caso, em duas etapas (construir heap, extrair); III é falsa. |
| 03 | B | cálculo | 4 | [0102](14-arvores.md) | Troca a raiz com o último e desce: O(log N), sem deslocar o vetor. |
| 04 | C | cálculo | 2 | [0072](10-analise.md), [0166](26-analise-formal.md) | (300/100)³ = 27, logo 27 minutos. |
| 05 | B | afirmações | 2 | [0166](26-analise-formal.md) | No caderno os símbolos são Ω(1), O(nⁿ) e o(2): I e III valem; II é falsa, pois há custos acima de nⁿ. |
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

#### Observações
- Q01 anulada: o código tem erro de sintaxe e de lógica; não vejo discordância da anulação.
- Q07 e Q10: motivos de anulação são conjectura minha.
- Q12: concordo com B; confere com as quatro alternativas.
- Q15, Q17 a Q20 rodadas com `python3 -I`; todas batem com o gabarito oficial. Sem discordância das letras oficiais.

### Edital 031/2024 (gabarito oficial)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | anulada | código | 7 | [0093](13-busca-e-ordenacao.md), [0092](13-busca-e-ordenacao.md) | Insertion sort com `v[j] = k` no lugar de `v[j+1] = k`; trocando essa linha ordena (rodado em C). A C parece a pretendida. |
| 02 | C | cálculo | 2 | [0072](10-analise.md) | O(n²): (2000/1000)² = 4, logo 4 minutos. |
| 03 | A | afirmações | 2 | [0166](26-analise-formal.md), [0072](10-analise.md) | Base do log é constante (I) e O é teto (II); Ω só dá piso, T1 = n³ e T2 = n² quebram a III. |
| 04 | D | simulação | 6 | [0090](13-busca-e-ordenacao.md), [0089](13-busca-e-ordenacao.md) | Meios 4, 6 e 5: compara com 10, 14 e 12 e para; rodado. |
| 05 | A | simulação | 4 | [0098](14-arvores.md) | Em-ordem (4 15 8) 42 (23 16); a árvore não é BST. |
| 06 | A | afirmações | 4 | [0177](28-estruturas-complementos.md), [0099](14-arvores.md) | 2 log₂(n+1) < 3 log₂ n para n ≥ 128; II e III descrevem a BST sem balanceamento. |
| 07 | anulada | afirmações | 6 | [0090](13-busca-e-ordenacao.md), [0089](13-busca-e-ordenacao.md) | I falsa (busca binária funciona com repetidas), II verdadeira, III discutível; D seria a mais provável. |
| 08 | A | conceito | 4 | [0101](14-arvores.md), [0099](14-arvores.md) | Definição de AVL: diferença de altura até 1, valendo em toda subárvore. |
| 09 | C | código | 3.1 | [0049](06-ponteiros.md), [0076](11-listas.md) | Inserir no início pede `Lista **`: `novo->prox = *lista; *lista = novo;`. |
| 10 | C | afirmações | 7 | [0093](13-busca-e-ordenacao.md), [0095](13-busca-e-ordenacao.md), [0094](13-busca-e-ordenacao.md) | I e III valem; II é falsa pelo "sempre" (pior caso O(n²) do quick sort). |
| 11 | C | código | 1 | [0032](04-funcoes.md), [0033](04-funcoes.md) | (Python) C(4) = 1 + C(3) + C(2) = 9 chamadas, cada uma imprime; rodado. |
| 12 | A | código | 1 | [0033](04-funcoes.md), [0032](04-funcoes.md) | (Python) Fibonacci com fib(0) = 0: chamada(4) = 3; rodado. |
| 13 | B | afirmações | 4 | [0177](28-estruturas-complementos.md), [0145](22-arvores-avancadas.md) | Raiz e nulos pretos são regras; preto pode ter filho preto (III falsa). |
| 14 | A | conceito | 4 | [0177](28-estruturas-complementos.md), [0101](14-arvores.md) | Vermelho não tem filho vermelho e nulos são pretos: todo vermelho tem dois filhos pretos. |
| 15 | B | conceito | 4 | [0177](28-estruturas-complementos.md), [0072](10-analise.md) | Altura da rubro-negra ≤ 2 log₂(n + 1). |
| 16 | anulada | código | 1 | [0054](07-memoria-dinamica.md), [0045](06-ponteiros.md) | Aloca um int no heap, grava 10, imprime e libera (C). Faltam os `#include` e a B é quase igual. |
| 17 | B | conceito | 3.2, 3.3 | [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md) | Pilha LIFO, fila FIFO. |
| 18 | A | conceito | 3.4 | [0038](05-vetores-e-strings.md), [0045](06-ponteiros.md) | Vetor como argumento vira o endereço do primeiro elemento. |
| 19 | C | código | 1 | [0022](03-repeticoes.md), [0028](04-funcoes.md) | subrotina(x) = x(x - 1)/2: 36, 21, 15, 45; rodado. |
| 20 | C | código | 1 | [0007](01-fundamentos.md) | Total = valor + valor · 0,18; com 100 dá 118. |

#### Observações
- Letras do gabarito final da banca (folha marcada com X). O curso resolveu as 17 não anuladas antes de ver o gabarito e chegou às mesmas letras.
- Q01, Q07 e Q16 anuladas; os motivos não foram publicados, e os sugeridos na tabela são conjectura minha.
- Q11 e Q12 usam a mesma função; Q12 é o valor, Q11 o número de chamadas.
- Q20: no caderno as aspas dos `printf` e `scanf` são tipográficas (“ ”) nas quatro alternativas; no `.md` foram trocadas por aspas retas.

### Edital 092/2024 (gabarito oficial)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | A | código | 1 | [0022](03-repeticoes.md), [0024](03-repeticoes.md) | 3 voltas fora (i = 2, 3, 4) × 2 dentro (j = 1, 2) = 6; compilado com gcc. |
| 02 | anulada | afirmações | 7 | [0093](13-busca-e-ordenacao.md) | Anulada pela banca. A I depende da versão: deslocando aparece (4, 4, 2, 1), trocando não; II e III valem nas duas. Com deslocamento seria B. |
| 03 | A | código | 1 | [0007](01-fundamentos.md), [0025](03-repeticoes.md) | Conta os divisores de 18: 1, 2, 3, 6, 9, 18; compilado com gcc. |
| 04 | E | simulação | 3.3 | [0082](12-pilhas-e-filas.md) | 6 pushes − 4 pops = 2 (sobram 6 e 7). |
| 05 | anulada | afirmações | 3.2, 3.3 | [0075](11-listas.md), [0086](12-pilhas-e-filas.md), [0079](11-listas.md) | Anulada pela banca. I e II valem; a III só vale se a lista dupla guardar ponteiro para o fim, o que o enunciado não diz. |
| 06 | anulada | afirmações | 4 | [0101](14-arvores.md) | Anulada pela banca. Pela análise do curso seria D: árvore válida (I falsa), inserir 7 sem rotação (II vale), o 4 desbalanceia o nó 5 e não a raiz (III falsa). |
| 07 | C | cálculo | 4 | [0101](14-arvores.md), [0098](14-arvores.md) | Mínimo de nós por altura 1, 2, 4, 7, 12: com 9 nós cabe altura 3. |
| 08 | C | simulação | 7 | [0095](13-busca-e-ordenacao.md) | Só o 7 da posição 5 e os dois 8 têm tudo antes ≤ e tudo depois ≥; rodado. |
| 09 | B | conceito | 7, 2 | [0094](13-busca-e-ordenacao.md), [0095](13-busca-e-ordenacao.md), [0072](10-analise.md) | No pior caso só o Mergesort é n log n; Quicksort, inserção e seleção são quadráticos. |
| 10 | D | código | 3.1 | [0054](07-memoria-dinamica.md), [0076](11-listas.md) | malloc, inserção na cabeça, lista como ponteiro para o primeiro nó e nenhum free. |
| 11 | B | código | 3.1 | [0020](03-repeticoes.md), [0076](11-listas.md) | Com 10 → 20, o while testa no 10 e no 20: 2 avaliações; contado em C. |
| 12 | C | código | 6 | [0090](13-busca-e-ordenacao.md), [0037](05-vetores-e-strings.md) | meio 4 (9) e meio 7 (15): 2 testes do while, imprime o índice 7; rodado. |
| 13 | B | código | 1 | [0032](04-funcoes.md), [0007](01-fundamentos.md) | (Python) soma dos dígitos: 2 + 4 = 6; rodado. |
| 14 | D | código | 1 | [0033](04-funcoes.md), [0007](01-fundamentos.md) | (Python) acumulador inverte o número: 24; rodado. |
| 15 | anulada | simulação | 8 | [0112](16-grafos.md), [0109](16-grafos.md) | Anulada pela banca. Distâncias A 0, B 2, E 4, G 5, F 6, H 8, C 9, D 10 dão a ordem da E; rodado com heap. |
| 16 | E | código | 1 | [0007](01-fundamentos.md), [0012](02-condicionais.md) | 15% de desconto é multiplicar por 0,85; A não compila, B tira 85%, C dá negativo, D tira ~13%. |
| 17 | C | afirmações | 5 | [0107](15-hash.md), [0179](28-estruturas-complementos.md) | I aglomeração primária; II falsa (uma vaga só basta na linear); III quadrática com m = 8 só gera 0, 1, 4. |
| 18 | C | código | 3.1 | [0076](11-listas.md), [0062](08-structs.md) | Lista 8 → 6 → 4 → 2 e eb é o segundo nó: imprime 6 4 2; compilado com gcc. |
| 19 | E | código | 1 | [0032](04-funcoes.md), [0033](04-funcoes.md) | `n <= 1` devolve f(0) = 0 e f(1) = 1; as outras não terminam ou erram valores; rodado. |
| 20 | D | afirmações | 4 | [0099](14-arvores.md), [0101](14-arvores.md) | Busca custa a altura em qualquer BST, a BST comum pode sair tão baixa quanto a AVL, e a busca é a mesma. |

#### Observações
- Gabarito final de 30/01/2025, publicado na página da Seleção 2025/01. As letras das 16 questões não anuladas batem com a resolução do curso.
- Prova com 5 alternativas (a a e), como as de 2016 a 2019.
- Q02, Q05, Q06 e Q15 anuladas; os motivos não foram publicados. Q02 e Q05 têm ambiguidade de enunciado; na Q06 e na Q15 o curso chega a D e E.
- Q11 e Q12: "a linha em negrito" é a do `while`; o curso conta avaliações da condição.

### Edital 048/2025 (gabarito oficial)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | B | simulação | 3.3 | [0082](12-pilhas-e-filas.md) | Quatro Visitar e dois Voltar: sobram UFAM e PPGI. |
| 02 | A | simulação | 3.1 | [0076](11-listas.md), [0085](12-pilhas-e-filas.md) | Remover no início tira Ana e João; Carla e Lucas entram no fim. |
| 03 | A | simulação | 3.2 | [0085](12-pilhas-e-filas.md), [0086](12-pilhas-e-filas.md) | Dois Atender tiram 101 e 102: [103, 104, 105, 106]. |
| 04 | C | simulação | 4 | [0099](14-arvores.md), [0098](14-arvores.md) | Árvore 50 (30 (20, 40), 70 (60, 80)); pré-ordem 50, 30, 20, 40, 70, 60, 80. |
| 05 | anulada | simulação | 5 | [0107](15-hash.md), [0105](15-hash.md) | 18 e 25 colidem; são 2 chaves ou 3 sondagens ocupadas, conforme o que se conta. Provavelmente anulada pela ambiguidade. |
| 06 | anulada | simulação | 7 | [0095](13-busca-e-ordenacao.md) | Com Lomuto só o 14 serve; com Hoare o 12 também (corte entre 10 e 14). Provavelmente anulada por isso. |
| 07 | A | simulação | 7 | [0094](13-busca-e-ordenacao.md) | Meio (0 + 8) / 2 = 4: posições 0 a 4 ordenadas, 5 a 8 intactas. |
| 08 | A | simulação | 4 | [0177](28-estruturas-complementos.md) | Raiz 38 preta, 19 vermelho com 12 e 31 pretos, 8 vermelho; rodado em Python. |
| 09 | C | simulação | 5 | [0179](28-estruturas-complementos.md), [0105](15-hash.md) | 11 → 4 e 24 → 3; o 33 testa 0, 1, 4 e fica na 9; rodado. |
| 10 | B | simulação | 4 | [0101](14-arvores.md) | Duas rotações duplas: raiz 10 depois do 10, raiz 15 depois do 20; rodado. |
| 11 | B | simulação | 3.3 | [0082](12-pilhas-e-filas.md) | Quatro Aplicar e três Desfazer: sobra o Brilho+10. |
| 12 | D | simulação | 6 | [0090](13-busca-e-ordenacao.md) | Meios 3, 5 e 4: Interestelar, Oppenheimer, Matrix. |
| 13 | C | simulação | 4 | [0100](14-arvores.md), [0098](14-arvores.md) | O sucessor 35 sobe no lugar do 30. |
| 14 | B | simulação | 5 | [0107](15-hash.md) | Remover 24 deixa marca na 4; o 38 (h = 3) a reaproveita. |
| 15 | D | código | 1 | [0032](04-funcoes.md) | (Python) só a D é recursiva e correta; B e C comparam número com lista (TypeError, rodado). |
| 16 | A | simulação | 6 | [0090](13-busca-e-ordenacao.md) | Meios 4, 7 e 8: 615, 720, 735; índice 8; rodado. |
| 17 | D | conceito | 4 | [0099](14-arvores.md) | t fica entre y e 7; com y = 5, só t = 6. |
| 18 | D | conceito | 7 | [0093](13-busca-e-ordenacao.md), [0096](13-busca-e-ordenacao.md) | Parte inicial ordenada e deslocamento dos maiores: insertion sort. |
| 19 | anulada | código | 4 | [0177](28-estruturas-complementos.md) | Caso interno (tio preto): a B é só o primeiro passo, e a árvore dada já tinha altura negra desigual. Provavelmente anulada por isso. |
| 20 | A | código | 3.1 | [0079](11-listas.md), [0057](07-memoria-dinamica.md) | Religa prev->next e next->prev antes do free. |

#### Observações
- Caderno da seleção 2025/2, aplicado em 15/08/2025; letras do gabarito final. O curso chegou às mesmas letras nas 17 questões válidas.
- Q05, Q06 e Q19: os motivos de anulação são conjectura minha.
- Q13: a D também é uma BST válida (o 40 sobe e o 20 desce para baixo do 35), mas não sai da remoção por sucessor ou predecessor; concordo com a C.
- Q06: o caderno traz "pode pode ter sido".

### Edital 098/2025 (gabarito oficial)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | C | cálculo | 2 | [0071](10-analise.md), [0024](03-repeticoes.md) | 10 · n · n incrementos; conferido em C. |
| 02 | D | simulação | 5 | [0106](15-hash.md), [0105](15-hash.md) | k mod 10 é o último dígito: 22, 42, 52, 62 e 72 caem na posição 2. |
| 03 | A | simulação | 8 | [0112](16-grafos.md), [0102](14-arvores.md) | Distâncias A 0, C 15, B 25, E 30, D 55; saem nessa ordem. Rodado em Python. |
| 04 | C | simulação | 4 | [0099](14-arvores.md), [0098](14-arvores.md) | 37 à esquerda de 41, 67 à esquerda de 73; pós-ordem 19, 37, 47, 41, 31, 67, 89, 73, 53. |
| 05 | anulada | afirmações | 3.1, 4, 5, 6 | [0076](11-listas.md), [0106](15-hash.md), [0099](14-arvores.md), [0101](14-arvores.md) | Pelo curso, B (II, III e IV): lista encadeada não tem busca binária. A II ("mais memória") é a provável causa da anulação. |
| 06 | B | conceito | 3.1, 3.2, 3.3 | [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md), [0076](11-listas.md) | Desfazer é pilha, impressora é fila, inserir e remover no meio é lista encadeada. |
| 07 | anulada | simulação | 7 | [0095](13-busca-e-ordenacao.md) | Hoare com pivô central 42 dá D (16, 18, 23, 42, 54, 67, 42, 45, 58), rodado nas versões do Cormen e de Ziviani. Motivo da anulação não publicado. |
| 08 | C | código | 6 | [0090](13-busca-e-ordenacao.md) | Intervalo fechado: j = tamanho - 1, j >= i, i = meio + 1, j = meio - 1. A entra em laço, B lê fora, D anda ao contrário. |
| 09 | anulada | simulação | 5 | [0179](28-estruturas-complementos.md), [0105](15-hash.md) | Com h(k) + i² dá A; com c₁ = c₂ = 1/2 (Cormen) dá outra tabela, e D se defende. Coeficientes não fixados no enunciado. |
| 10 | anulada | código | 1 | [0065](08-structs.md) | ~42 + 1 = -42 em complemento de dois (A), compilado com gcc. Até o C17 o padrão admitia outras representações de negativos. |
| 11 | anulada | simulação | 4 | [0146](22-arvores-avancadas.md) | Ordem 3, divisão pela mediana: 4 / 2 (1, 3) / 6 (5, 7), a C. "Ordem" tem mais de uma definição nos livros. |
| 12 | anulada | código | 1 | [0032](04-funcoes.md), [0007](01-fundamentos.md) | Para B > 0 é a divisão inteira (C); com B = 0 a recursão não termina, o que sustenta D. |
| 13 | C | código | 3.2 | [0085](12-pilhas-e-filas.md), [0075](11-listas.md) | (Python) append no fim e pop(0) no início: FIFO. A e D dão erro, B insere antes do último. |
| 14 | C | código | 3.4 | [0039](05-vetores-e-strings.md), [0024](03-repeticoes.md) | Só a C testa a diagonal e os dois lados fora dela sem desfazer o flag; as quatro rodadas em C. |
| 15 | anulada | afirmações | 3.2, 3.3 | [0082](12-pilhas-e-filas.md), [0083](12-pilhas-e-filas.md), [0086](12-pilhas-e-filas.md), [0080](11-listas.md) | Pelo curso, as quatro valem (D). A IV pede ponteiro para o fim, que o enunciado não menciona. |
| 16 | B | conceito | 3.1 | [0079](11-listas.md), [0054](07-memoria-dinamica.md) | Tirar B de A ⇄ B ⇄ C: A->prox = C e C->ant = A. |
| 17 | B | conceito | 3.3 | [0082](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md) | Insere no fim e remove o último: a mesma ponta, pilha. |
| 18 | A | conceito | 4 | [0099](14-arvores.md), [0098](14-arvores.md) | Em-ordem 1, z, y, t, 7, 9, x, s, 13, 15: x ∈ {10, 11}; s ≥ 11; t ∈ {4, 5, 6}. |
| 19 | B | simulação | 4 | [0176](28-estruturas-complementos.md), [0101](14-arvores.md) | Sem o 9, rotação à esquerda no 10 (sobe o 11); o 8 fica +2 com o 3 em -1: rotação dupla, o 5 vira raiz. |
| 20 | C | código | 1 | [0032](04-funcoes.md), [0031](04-funcoes.md) | Fatorial: 4 · 3 · 2 · 1 = 24; compilado com gcc. |

#### Observações
- Prova aplicada em 05/02/2026 (seleção de mestrado 2026/1). Letras do gabarito final; sete questões anuladas (05, 07, 09, 10, 11, 12 e 15), sem motivo publicado. As letras que o curso indica para as anuladas e os motivos são conjectura.
- Nas 13 questões válidas, a resolução do curso bate com o gabarito final.
- Q07: as duas variantes clássicas do Hoare (Cormen e Ziviani) dão a alternativa D; não há defeito visível no enunciado.
- Q03 tem grafo, que o quiz mostra só no recorte original (o gerador não desenha grafo).

### Edital 014/2026 (gabarito oficial)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | B | cálculo | 2 | [0071](10-analise.md), [0072](10-analise.md) | Externo dobra i, interno roda i vezes: 1 + 2 + 4 + ... ≤ 2n, tempo Θ(n); só variáveis simples, espaço Θ(1). Rodado. |
| 02 | B | afirmações | 4 | [0102](14-arvores.md), [0103](14-arvores.md) | Heap de máximo: maior na raiz, menor numa folha (II falsa); base do Heapsort e da fila de prioridade. |
| 03 | C | cálculo | 2 | [0114](17-analise-avancada.md), [0032](04-funcoes.md) | Duas chamadas com e/2: T(e) = 2T(e/2) + Θ(1) = Θ(e) em qualquer caso. Rodado: e = 16 faz 31 chamadas. |
| 04 | B | afirmações | 7 | [0096](13-busca-e-ordenacao.md), [0094](13-busca-e-ordenacao.md) | Quicksort e Heapsort não são estáveis; o Merge Sort depende do desempate na intercalação (II falsa). |
| 05 | D | afirmações | 7 | [0094](13-busca-e-ordenacao.md) | Olhando as frentes de cada intercalação, I, II e III valem; conferido simulando as 120 permutações. |
| 06 | D | afirmações | 6 | [0090](13-busca-e-ordenacao.md), [0089](13-busca-e-ordenacao.md) | Busca binária falha com um elemento fora do lugar para qualquer n (I e II falsas); só a III vale, e não há "apenas III". |
| 07 | C | código | 7 | [0092](13-busca-e-ordenacao.md), [0093](13-busca-e-ordenacao.md) | Índice do menor e uma troca por volta: selection sort; a opção I deixa crescente. |
| 08 | A | afirmações | 4 | [0101](14-arvores.md) | I e II são rotações simples no 30; com o 25, o 20 fica -2 e o 40 +1, rotação dupla (III falsa). |
| 09 | D | código | 1 | [0065](08-structs.md), [0045](06-ponteiros.md) | *v2 é o próprio v1: 16, 8, 4, 2, 1, 0, cinco voltas; compilado com gcc. |
| 10 | C | conceito | 3.1, 4 | [0079](11-listas.md), [0099](14-arvores.md) | Uma chave e dois ponteiros: lista dupla (circular) e BST; lista simples tem um ponteiro, árvore B tem vários. |
| 11 | anulada | afirmações | 7 | [0121](18-ordenacao-linear.md), [0120](18-ordenacao-linear.md) | Pela análise, I, II e IV valem (A); III falsa (Counting Sort direto é Θ(n + n³)). Provável motivo: a IV diz "no máximo log(n) dígitos", quando são cerca de 3 log₁₀ n. |
| 12 | D | simulação | 5 | [0107](15-hash.md), [0179](28-estruturas-complementos.md) | Só o 9 colidiu (início 2); com + 3i tenta 5 e cai em 1. As outras fórmulas passam pela posição 3, vazia. |
| 13 | anulada | simulação | 7 | [0095](13-busca-e-ordenacao.md) | Rodado: Lomuto com pivô 4 gera o vetor dado; Hoare com pivô 2 não. Só a III vale, e nenhuma alternativa diz "apenas III". |
| 14 | C | código | 3.3 | [0082](12-pilhas-e-filas.md) | Elementos em vet[0..n-1]; o topo é vet[n - 1], com push e pop em O(1). |
| 15 | D | código | 1 | [0012](02-condicionais.md), [0024](03-repeticoes.md) | (Python) sinais opostos dão passo = -1; 200 · 50 voltas: -10.000. Rodado. |
| 16 | A | código | 3.2 | [0086](12-pilhas-e-filas.md) | Fila vazia: fim == NULL, então ini = n; depois fim = n sempre. |
| 17 | A | simulação | 4 | [0099](14-arvores.md), [0098](14-arvores.md) | x > 9 e x ≠ 10, então o 10 desce pela esquerda e vira filho direito do 9. C e D são pós-ordens. |
| 18 | D | conceito | 8 | [0155](23-grafos-avancados.md), [0112](16-grafos.md), [0110](16-grafos.md) | A incorreta é a D: Floyd-Warshall não vale com ciclo negativo, então não funciona "para quaisquer pesos". |
| 19 | C | simulação | 8 | [0153](23-grafos-avancados.md) | Árvore mínima A-C, C-D, B-D (peso 3); o Prim nunca tem pedaços soltos (B) e não usaria A-B (A e D). |
| 20 | anulada | conceito | 8 | [0150](23-grafos-avancados.md), [0109](16-grafos.md) | A construção é o grafo transposto, e a A descreve o uso clássico (conexidade forte). O gabarito final não diz o motivo da anulação. |

#### Observações
- O caderno publicado é escaneado; o texto foi transcrito à mão das imagens das páginas, sem trecho ilegível.
- Letras do gabarito final de 05/06/2026. O curso resolveu as 17 não anuladas e chegou às mesmas letras.
- Q11, Q13 e Q20: os motivos das anulações são conjectura minha; nas três, a análise indica A, só a III e A, respectivamente.
- Q05: conferida simulando o Merge Sort (intercalação com `<=`) nas 120 permutações dos múltiplos de 3.

### Edital 070/2026 (gabarito preliminar)
| Q | Letra | Formato | Tópico | Assuntos | Por quê |
|---|---|---|---|---|---|
| 01 | C | simulação | 4 | [0098](14-arvores.md), [0100](14-arvores.md) | Em-ordem de BST é a lista crescente das chaves; sem o 13: 2, 3, 7, 8, 12, 17, 19, 20, 21. |
| 02 | B | simulação | 4 | [0176](28-estruturas-complementos.md), [0101](14-arvores.md) | Sem o 1, a raiz 3 fica com fator -2 e o filho 5 com -1: rotação simples à esquerda, 5 vira raiz. |
| 03 | C | simulação | 5 | [0107](15-hash.md), [0105](15-hash.md) | Só o 2 está na posição inicial; 23 colidiu com o 2, o 1 com o 23 e o 3 com o 1: 2, 23, 1, 3. |
| 04 | A | afirmações | 7 | [0092](13-busca-e-ordenacao.md), [0095](13-busca-e-ordenacao.md), [0103](14-arvores.md) | Seleção faz no máximo n - 1 trocas (I vale); no pior caso o Quicksort é n² e o Heapsort n log n (II falsa). |
| 05 | B | afirmações | 5 | [0106](15-hash.md), [0105](15-hash.md) | Pior caso do encadeamento é O(n) (I falsa); fator de carga pode passar de 1; função ruim degenera a busca. |
| 06 | A | afirmações | 4 | [0099](14-arvores.md), [0101](14-arvores.md) | BST degenerada pede n comparações; AVL mantém fator em -1, 0 ou 1; 1..n em ordem dá altura n - 1 (III falsa). |
| 07 | B | código | 1 | [0007](01-fundamentos.md), [0012](02-condicionais.md) | (Python) 25 - abs(ano - 2739): 0 em 2714, 25 em 2739, 24 em 2740, 0 em 2764; rodado ano a ano. |
| 08 | C | código | 1 | [0007](01-fundamentos.md) | (Python) minutos × 13 // 720; B divide cedo e zera, D arredonda e chega a 13; rodado nos 720 horários. |
| 09 | A | simulação | 4 | [0146](22-arvores-avancadas.md) | Top-down, t = 2: o [P] pega emprestado do [B D] pela raiz, depois o [M] pega do [R S]; fica D / B / J R. |
| 10 | A | simulação | 4 | [0101](14-arvores.md) | O 22 deixa o 30 com +2 e o 20 com -1: rotação dupla, o 25 vira raiz. |
| 11 | C | conceito | 8 | [0112](16-grafos.md), [0154](23-grafos-avancados.md) | Dijkstra fecha a distância quando o vértice sai da fila; com aresta negativa ela pode melhorar depois. |
| 12 | C | afirmações | 3.1, 4 | [0076](11-listas.md), [0101](14-arvores.md) | Lista encadeada não tem busca binária (II falsa); chaves crescentes degeneram a BST sem balanceamento (IV falsa). |
| 13 | D | simulação | 4 | [0102](14-arvores.md) | Floyd de i = 5 até 0; o empate no índice 2 vai para a posição 5 e o 3 da raiz desce até a 9; rodado. |
| 14 | D | simulação | 3.2, 4 | [0102](14-arvores.md), [0103](14-arvores.md) | A Esmeralda vai para a raiz quando o Dourado sai e o Ciano só empata: heap não é estável; rodado. |
| 15 | A | afirmações | 3.2 | [0087](12-pilhas-e-filas.md), [0085](12-pilhas-e-filas.md) | No vetor circular as pontas mudam em Θ(1) e a posição k está em (início + k) % CAP (III falsa). |
| 16 | D | código | 3.2 | [0086](12-pilhas-e-filas.md), [0076](11-listas.md) | Se ini ficou NULL a fila esvaziou; fim apontaria para o nó liberado. |
| 17 | B | código | 3.3 | [0082](12-pilhas-e-filas.md), [0045](06-ponteiros.md) | n é a quantidade e a próxima posição livre; o topo está em n - 1. |
| 18 | C | código | 1 | [0065](08-structs.md) | sizeof(x)*8 voltas, teste com x & mask e mask >> 1; imprime 0b01100011, compilado com gcc. |
| 19 | D | código | 1 | [0045](06-ponteiros.md) | pti guarda o endereço de i; quem vale 10 é *pti. |
| 20 | B | código | 1 | [0032](04-funcoes.md), [0007](01-fundamentos.md) | conta soma 1 por dígito zero: 2040 e 20 terminam em 0; compilado com gcc. |

#### Observações
- Letras do gabarito preliminar de 27/11/2026. O curso resolveu as 20 antes de recebê-lo e chegou às mesmas letras.
- O mesmo caderno vale para o edital 071/2026, do doutorado.
- Q09: "grau mínimo 2 e máximo 4" conta filhos (t = 2, de 1 a 3 chaves). C e D passariam por um nó de 4 chaves; B deixa o [P] com um filho só.
- Q17: A ("o vetor começa no zero") é parte da explicação, mas a B é a que justifica a ordem das linhas.

// Gerado por _gerador/quiz.mjs a partir de _gerador/provas/. Não edite à mão.
window.PROVAS = [
 {
  "edital": "032/2016",
  "slug": "2016-032",
  "ano": 2016,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Suponha que você recebeu a tarefa de depurar uma implementação de Quicksort, cujo objetivo é para classificar um vetor em ordem crescente. Considere que o pivô escolhido terá o valor 4 e que você executou até o momento apenas o particionamento completo gerado com o pivô, sem ter realizado ainda qualquer chamada recursiva. Sobre as afirmações:\n\n`4 1 2 3 17 2 22 3`\n\nI) Dependendo da implementação da partição, a ordem dos elementos nesse momento pode ser 3, 1, 2, 3, 2, 17, 22 e 4\nII) É impossível que uma implementação de Quicksort tenha escolhido o 4 como pivô\nIII) Dependendo da implementação da partição, a ordem dos elementos nesse momento poderia ser 3, 1, 2, 3, 2, 4, 17 e 22\nIV) Dependendo da implementação da partição, a ordem dos elementos nesse momento poderia ser 4, 1, 2, 3, 2, 3, 17 e 22",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas I está correta",
      "porque": "Só I não basta. I é possível (pivô levado ao fim, menores e maiores separados e a troca final ainda por fazer), mas III e IV também descrevem resultados que alguma implementação produz."
     },
     {
      "letra": "B",
      "texto": "Apenas II está correta",
      "porque": "II é falsa. O 4 é o primeiro elemento do vetor, e escolher o primeiro elemento como pivô é a versão mais simples do Quicksort."
     },
     {
      "letra": "C",
      "texto": "Apenas I e III estão corretas",
      "porque": "Propõe I e III e deixa IV de fora. I e III são possíveis, mas IV também é, dependendo de onde o pivô fica durante a partição. Como a conta depende da implementação, a banca anulou."
     },
     {
      "letra": "D",
      "texto": "Apenas III e IV estão corretas",
      "porque": "Propõe III e IV e deixa I de fora. Só que I é um estado válido: separando os menores e os maiores com o pivô no fim, sai exatamente 3 1 2 3 2 17 22 4."
     },
     {
      "letra": "E",
      "texto": "Apenas III está correta",
      "porque": "Deixa I e IV de fora. Os três resultados (I, III e IV) são separações em que todo elemento menor ou igual a 4 vem antes dos maiores, então não dá para escolher só um."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada pela banca. II é falsa. I, III e IV são todas estados possíveis de um particionamento, conforme onde o pivô fica: I é o pivô no fim antes da troca final, IV é o pivô ainda na frente com os menores depois dele, III é o pivô já na posição final (5). Como mais de uma combinação é defensável, não há letra única. Na prova, desconfie de questão que pergunta 'dependendo da implementação'.",
    "assuntos": [
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 1,
    "formato": "cálculo",
    "enunciado": "Quantas vezes o símbolo '#' é impresso pela função teste quando chamada com parâmetro 5 (teste(5))?\n\n```c\nvoid teste (int i) {\n  if (i > 1) {\n    teste (i/2);\n    teste (i/2);\n  }\n  printf( \"#\"); /*imprime símbolo # na tela */\n}\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "3",
      "porque": "Seria o resultado de só uma chamada filha e só o último nível. Cada chamada com i > 1 faz duas chamadas, então o total cresce bem mais."
     },
     {
      "letra": "B",
      "texto": "4",
      "porque": "Não bate com a recorrência. T(5) = 2·T(2) + 1, e T(2) já vale 3."
     },
     {
      "letra": "C",
      "texto": "7",
      "porque": "T(1) = 1 (só imprime). T(2) = 2·T(1) + 1 = 3. T(5) chama teste(2) duas vezes (5/2 = 2 em divisão inteira): 2·3 + 1 = 7."
     },
     {
      "letra": "D",
      "texto": "8",
      "porque": "Seria o caso de uma chamada com i = 4 ou i = 8 tratado como potência de 2 exata. Aqui 5/2 é 2, não 2,5, e o total é 7."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Existe alternativa certa: o valor 7 está na letra C."
     }
    ],
    "gabarito": "C",
    "resumo": "Monte a recorrência: cada chamada com i > 1 faz duas chamadas com i/2 e imprime um '#'. Lembre que a divisão de inteiros em C trunca: 5/2 = 2 e 3/2 = 1. Dica de prova: desenhe a árvore de chamadas e conte os nós. Conferido rodando em C: sai ####### (7).",
    "assuntos": [
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     },
     {
      "num": "0114",
      "modulo": "17-analise-avancada.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Quando um novo nó é removido no meio de uma lista encadeada dinâmica, qual das seguintes afirmações é verdadeira:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Somente os nós que aparecem após o novo nó precisam ser movidos",
      "porque": "Isso vale para vetor (deslocar os elementos seguintes), não para lista encadeada. Os nós ficam onde estão na memória."
     },
     {
      "letra": "B",
      "texto": "Somente os nós que aparecem antes do novo nó precisam ser movidos",
      "porque": "Nenhum nó anterior é movido. Só o anterior ao removido muda o ponteiro `prox`."
     },
     {
      "letra": "C",
      "texto": "Os nós que aparecem antes do novo nó e o último nó precisam ser movidos",
      "porque": "Nó de lista não é movido em operação nenhuma. O último nem é tocado, salvo se for o removido."
     },
     {
      "letra": "D",
      "texto": "Os nós que aparecem depois do novo nó e o primeiro nó precisam ser movidos",
      "porque": "Nenhum nó é copiado ou deslocado. A remoção troca um ponteiro e libera o nó removido."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das opções acima",
      "porque": "Correta. Na lista encadeada, remover no meio é religar o `prox` do anterior ao seguinte e dar `free` no nó. Nenhum outro nó se mexe, e é essa a vantagem sobre o vetor."
     }
    ],
    "gabarito": "E",
    "resumo": "A vantagem da lista encadeada sobre o vetor é inserir e remover sem deslocar elementos: o custo é achar a posição e trocar um ou dois ponteiros. O enunciado diz 'novo nó' mas fala de remoção. Dica: alternativa que fala em mover nós descreve vetor.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0077",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Se você tem que implementar um algoritmo de ordenação que tem um tempo de execução competitivo quando comparado a outros, e que não varia muito seu desempenho em função da entrada de dados fornecida. Qual das opções é melhor?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Ordenação por inserção",
      "porque": "Faz n-1 comparações em vetor já ordenado e cerca de n²/2 em vetor invertido. Varia muito com a entrada."
     },
     {
      "letra": "B",
      "texto": "Heapsort",
      "porque": "Correta. Faz O(n log n) no melhor, no médio e no pior caso, e é competitivo. Não depende de como a entrada vem."
     },
     {
      "letra": "C",
      "texto": "Quicksort",
      "porque": "É muito rápido na média, mas no pior caso (pivô ruim, como vetor já ordenado com pivô na ponta) cai para O(n²). Varia com a entrada."
     },
     {
      "letra": "D",
      "texto": "Tanto Quicksort quanto Heapsort atendem aos requisitos",
      "porque": "O Quicksort não atende ao requisito de desempenho estável."
     },
     {
      "letra": "E",
      "texto": "Hash",
      "porque": "Hash é estrutura de busca, não algoritmo de ordenação."
     }
    ],
    "gabarito": "B",
    "resumo": "Quando a pergunta pede desempenho que 'não varia com a entrada', a resposta é um algoritmo com mesmo custo no pior e no melhor caso: Heapsort e Mergesort (O(n log n)). Quicksort tem pior caso O(n²).",
    "assuntos": [
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0103",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 5,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Se em uma árvore binária de pesquisa a diferença de altura entre a sub-árvore a esquerda e a sub-árvore a direita de um dos nós for maior que 1, pode-se concluir que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "A árvore é uma árvore AVL",
      "porque": "Na AVL a diferença de altura entre as subárvores de todo nó é no máximo 1. Diferença maior que 1 em algum nó é exatamente o que a AVL proíbe."
     },
     {
      "letra": "B",
      "texto": "Trata-se com certeza de uma árvore binária sem balanceamento",
      "porque": "A árvore pode ser de outro tipo balanceado, como a rubro-negra, que tolera diferença maior que 1 e mesmo assim mantém altura O(log n). Por isso o 'com certeza' falha."
     },
     {
      "letra": "C",
      "texto": "Trata-se com certeza de uma árvore vermelho e preto",
      "porque": "Também não é certeza. Pode ser uma ABB comum, sem nenhum balanceamento."
     },
     {
      "letra": "D",
      "texto": "Tal árvore não pode existir por não se tratar de uma árvore binária de pesquisa",
      "porque": "Pode existir. A ABB comum não impõe limite de diferença de altura."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Pelo conteúdo é a mais defensável: da diferença maior que 1 só se conclui que a árvore não é AVL. A banca, mesmo assim, anulou a questão."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada pela banca. A única conclusão segura é 'não é AVL'; ela pode ser uma ABB sem balanceamento ou uma rubro-negra. Por isso as letras B e C, que dizem 'com certeza', ficam erradas. Dica: o fator de balanceamento fora de -1, 0, 1 elimina só a AVL.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Uma estrutura de dados bastante útil quando deseja-se armazenar elementos para recupera-los posteriormente em ordem reversa a de inserção:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "A árvore é uma árvore AVL",
      "porque": "Árvore AVL guarda chaves ordenadas por valor, não pela ordem de chegada."
     },
     {
      "letra": "B",
      "texto": "Um hash",
      "porque": "Hash espalha as chaves por uma função e não guarda a ordem de inserção."
     },
     {
      "letra": "C",
      "texto": "Uma fila de prioridades com ordenação reversa de prioridade",
      "porque": "Fila de prioridades sai por prioridade, não pela ordem de inserção. Só reproduziria a ordem inversa se a prioridade fosse o instante de chegada, o que não é o enunciado."
     },
     {
      "letra": "D",
      "texto": "Uma pilha",
      "porque": "Correta. Pilha é LIFO: o último a entrar é o primeiro a sair, então os elementos voltam na ordem contrária à de inserção."
     },
     {
      "letra": "E",
      "texto": "Uma árvore vermelho e preto",
      "porque": "Árvore balanceada ordena pela chave, não pela ordem de inserção."
     }
    ],
    "gabarito": "D",
    "resumo": "LIFO (last in, first out) é a definição de pilha. A fila é FIFO e devolve na mesma ordem. Dica: 'ordem reversa' é sempre pilha.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 6,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre busca binária:\n\ni) é utilizada apenas sobre vetores ordenados\nii) pode determinar se uma chave está ou não com um número de comparações de chave inferior a 2log2 n passos, onde n é o tamanho do vetor.\niii) Supera a busca sequencial quando o vetor é grande, por exemplo com mais que mil elementos, e está ordenado.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas as afirmações II e III estão corretas",
      "porque": "Deixa I de fora, mas I é verdadeira: a busca binária só funciona em vetor ordenado."
     },
     {
      "letra": "B",
      "texto": "Apenas as afirmações I e II estão corretas",
      "porque": "Deixa III de fora, mas III é verdadeira: com mais de mil elementos ordenados, cerca de 10 comparações contra até 1000 na sequencial."
     },
     {
      "letra": "C",
      "texto": "Apenas as afirmações I e III estão corretas",
      "porque": "Deixa II de fora. II é verdadeira para vetores de tamanho razoável: a busca binária faz no máximo ⌊log2 n⌋ + 1 comparações, abaixo de 2·log2 n."
     },
     {
      "letra": "D",
      "texto": "Todas as afirmações estão corretas",
      "porque": "É o que o conteúdo diz: I, II e III são verdadeiras. A banca anulou, provavelmente porque II falha em vetores minúsculos (n = 1 ou 2) e abre dúvida."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "As três afirmações são verdadeiras, então 'nenhuma' não serve."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada pela banca. I (precisa estar ordenado), II (no máximo ⌊log2 n⌋ + 1 comparações, menor que 2·log2 n) e III (muito mais rápida que a sequencial em vetor grande ordenado) são verdadeiras. Na prova de busca binária, guarde: ordenado, O(log n), pior caso ⌊log2 n⌋ + 1.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0072",
      "modulo": "10-analise.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 3,
    "formato": "código",
    "enunciado": "Considere os códigos de funções abaixo, assumindo que os mesmos são usados dentro de um programa e que os todos os cabeçalhos necessários são incluídos:\n\n```c\n/*QUADRO I) Código para inserir em uma lista\nencadeada. Cada nó da lista tem um campo\nprox, que é usado para encadea-lo ao próximo\nelemento, e tem um dado do tipo int. */\n/* prim é um ponteiro para o ponteiro ao\nprimeiro elemento da lista */\nvoid insere(tipoNo **prim, int d) {\n  tipoNo *aux;\n  aux = (tipoNo *)malloc(sizeof(tipoNo));\n  if(aux) { aux ->prox = *prim;\n    *prim = aux;\n    aux -> dado = d;\n  }\n}\n```\n\n```c\n/*QUADRO II) Código para remover primeiro\nelemento de uma lista encadeada. Cada nó da\nlista tem um campo prox, que é usado para\nencadea-lo ao próximo elemento, e tem um\ndado do tipo int. */\n/* prim é um ponteiro para o ponteiro ao\nprimeiro elemento da lista */\n1. void remove (tipoNo **prim){\n2.   tipoNo *aux;\n3.   if(*prim) { aux = *prim;\n4.     *prim = aux->prox;\n5.     free(*prim);\n6.     *prim = aux;\n7.   }\n8. }\n```\n\nMarque a alternativa correta dentre as afirmações abaixo:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Os dois códigos executam as tarefas propostas sem gerar qualquer tipo de erro de lógica, de vazamento de memória ou falha de segmentação",
      "porque": "O código II tem erro: a linha 5 dá `free` no novo início e a linha 6 manda `*prim` de volta para o nó antigo."
     },
     {
      "letra": "B",
      "texto": "Apenas os código I realiza sem erros a tarefa descrita nos comentários",
      "porque": "Correta. `insere` aloca, liga o novo nó ao antigo início e atualiza `*prim`: inserção no início certa. `remove` quebra a lista (veja a alternativa C)."
     },
     {
      "letra": "C",
      "texto": "Apenas os código II realiza sem erros a tarefa descrita nos comentários",
      "porque": "O II guarda o nó removido em `aux`, avança `*prim` para o segundo nó, mas aí libera o segundo nó (`free(*prim)`) e faz `*prim = aux`. O primeiro nó continua na lista, apontando para memória já liberada."
     },
     {
      "letra": "D",
      "texto": "Os dois códigos não executam suas tarefas como descrito nos comentários, mas também não geram vazamento de memória",
      "porque": "O I faz o que diz. E o II ainda vaza memória: o terceiro nó em diante fica inalcançável."
     },
     {
      "letra": "E",
      "texto": "O primeiro código gera vazamento de memória e o segundo não realiza a tarefa descrita nos comentários",
      "porque": "O I não vaza: cada `malloc` vira um nó ligado à lista. Só a segunda metade da frase (II falha) está certa."
     }
    ],
    "gabarito": "B",
    "resumo": "Para remover o primeiro nó: guarde o endereço dele, avance `*prim` e só então dê `free` no nó guardado. O código II libera o nó errado (o segundo) e deixa `*prim` apontando para o primeiro, que agora tem um `prox` pendurado. Conferido em C com AddressSanitizer: o nó do início continua na lista e há vazamento.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0077",
      "modulo": "11-listas.md"
     },
     {
      "num": "0054",
      "modulo": "07-memoria-dinamica.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre um hash por encadeamento:\n\nI) Suas colisões secundárias podem prejudicar seu desempenho\nII) Não funciona com número de chaves maior que o tamanho da tabela hash\nIII) O número médio de operações esperado para realizar uma inserção é constante quando computado em função do tamanho da tabela se o hash for bem projetado\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas são verdadeiras",
      "porque": "Propõe I, II e III verdadeiras. Falha em I e II."
     },
     {
      "letra": "B",
      "texto": "Todas são falsas",
      "porque": "Propõe todas falsas. Falha em III: com boa função e fator de carga limitado, a inserção é O(1) em média."
     },
     {
      "letra": "C",
      "texto": "Apenas I e III são verdadeiras",
      "porque": "Propõe I e III. Falha em I: colisão secundária (aglomerados de posições ocupadas) é problema do endereçamento aberto. No encadeamento a colisão só aumenta a lista de um balde."
     },
     {
      "letra": "D",
      "texto": "Apenas III é verdadeira",
      "porque": "Correta. III é verdadeira (inserir no início da lista do balde é O(1) com boa função de hash). I é falsa e II é falsa."
     },
     {
      "letra": "E",
      "texto": "Apenas I e II são verdadeiras",
      "porque": "Propõe I e II e nega III. As três coisas estão trocadas: I e II são falsas e III é verdadeira."
     }
    ],
    "gabarito": "D",
    "resumo": "I falsa (colisão secundária é termo de endereçamento aberto), II falsa (no encadeamento cada balde é lista e aceita mais chaves que M), III verdadeira (inserção O(1) em média com boa função). Atenção: se o autor leu I como 'listas longas atrapalham', a letra seria C; o gabarito oficial é D.",
    "assuntos": [
     {
      "num": "0105",
      "modulo": "15-hash.md"
     },
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 6,
    "formato": "código",
    "enunciado": "Considere os códigos de funções abaixo, assumindo que os mesmos são usados dentro de um programa e que os todos os cabeçalhos necessários são incluídos:\n\n```c\n/*QUADRO I) função que retorna 1 se a chave\nde busca chave, passada como parâmetro, ocorre\ndentro de um vetor de inteiros ordenado e\nretorna 0 caso a chave não ocorra no vetor. O\nvetor tem tamanho determinado pelo parâmetro\ntm */\nint buscaChave(int v[], int chave, int tm) {\n  while((tm>= 0) && (v[tm]!= chave)) tm --;\n  if (tm >= 0) return 1;\n  return 0;\n}\n```\n\n```c\n/* QUADRO II) Conta ocorrências de uma\nchave na lista encadeada, retornando o total de\nocorrências , zero caso a chave não ocorra\n*/\nint ContaOcorrenciasChave(tipoNo *prim, int\nchave) {\n  tipoNo *aux = prim;\n  int cont = 0;\n  int x;;\n  for (x = 0; aux[x] != NULL; x++){\n    if(aux[x]. dado == chave) cont++;\n  }\n  return cont;\n}\n```\n\nMarque a alternativa correta dentre as afirmações abaixo:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Os dois códigos executam as tarefas propostas sem gerar qualquer tipo de erro de lógica ou de vazamento de memória",
      "porque": "O código II não executa: trata a lista encadeada como vetor (`aux[x]`) e compara uma struct com `NULL`."
     },
     {
      "letra": "B",
      "texto": "Apenas os código I executa sem erros a tarefa proposta",
      "porque": "Correta pelo gabarito. O I varre de trás para a frente e devolve 1 se achou e 0 se não achou, como pede. A banca considera `tm` o último índice válido."
     },
     {
      "letra": "C",
      "texto": "Apenas o código II executa sem erros a tarefa proposta",
      "porque": "O II percorre lista com índice de vetor. Nó de lista não fica em posições contíguas: o certo é `aux = aux->prox`. `aux[x] != NULL` compara struct com ponteiro e nem compila."
     },
     {
      "letra": "D",
      "texto": "Os dois códigos geram erros de vazamento de memória ou falha de segmentação",
      "porque": "Nenhum dos dois aloca memória, então não há vazamento. O I é correto na leitura da banca."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Existe alternativa certa (B). Se `tm` fosse o tamanho, o I leria `v[tm]` fora do vetor e a resposta mudaria, mas a banca leu `tm` como último índice."
     }
    ],
    "gabarito": "B",
    "resumo": "Gabarito oficial B. Atenção à divergência: lendo `tm` como tamanho, `v[tm]` já seria acesso fora do vetor e o I também estaria errado (o curso tinha chegado em D). A banca tratou `tm` como índice do último elemento. O II é erro certo: lista encadeada se percorre por `prox`, nunca por índice.",
    "assuntos": [
     {
      "num": "0089",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0057",
      "modulo": "07-memoria-dinamica.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 11,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre um hash por encadeamento:\n\nI) Tem como desvantagem o fato de não ordenar as chaves inseridas\nII) O número médio de operações esperado para realizar uma busca é constante quando computado em função do tamanho da tabela se o hash for bem projetado\nIII) Mesmo quando bem implementado, ocupa mais espaço extra do que uma árvore-b em memória.\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas são verdadeiras",
      "porque": "Depende de III. A árvore B também gasta ponteiros e nós semicheios, então não dá para afirmar que o hash ocupa sempre mais."
     },
     {
      "letra": "B",
      "texto": "Todas são falsas",
      "porque": "I e II são verdadeiras: o hash não guarda ordem e a busca média é O(1+α)."
     },
     {
      "letra": "C",
      "texto": "Apenas I e III são verdadeiras",
      "porque": "Deixa II de fora, mas II é verdadeira."
     },
     {
      "letra": "D",
      "texto": "Apenas III é verdadeira",
      "porque": "Nega I e II, que são verdadeiras."
     },
     {
      "letra": "E",
      "texto": "Apenas I e II são verdadeiras",
      "porque": "É o que o conteúdo sustenta: I e II verdadeiras e III falsa. A banca anulou, pela dúvida sobre III."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada pela banca. I verdadeira (hash não mantém ordem). II verdadeira (busca esperada O(1 + α) com boa função). III é a duvidosa: a árvore B também usa ponteiros e nós semicheios, então 'ocupa mais espaço' não vale sempre, e por isso a questão não tem letra única.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     },
     {
      "num": "0146",
      "modulo": "22-arvores-avancadas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Marque a resposta correta. Ao inserirmos as chaves 1, 2 e 3, 4, 5, 6 em uma árvore AVL, sua altura (medida como a quantidade máxima de nós em um caminho entre a raiz e uma folha da árvore, incluindo a raiz e a folha na conta) será:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "2",
      "porque": "Seria uma árvore com só uma raiz e duas folhas, 3 nós. Aqui são 6 nós."
     },
     {
      "letra": "B",
      "texto": "3",
      "porque": "Correta. Inserindo 1..6: 1, 2 e 3 giram e viram 2(1,3). O 4 entra sem girar. O 5 desbalanceia o nó 3 e gira à esquerda. O 6 desbalanceia a raiz 2 e gira à esquerda. Fica 4(2(1,3), 5(-,6)): o maior caminho tem 3 nós."
     },
     {
      "letra": "C",
      "texto": "4",
      "porque": "Exigiria um caminho de 4 nós, e a AVL com 6 nós cabe em altura 3 porque rotaciona a cada desbalanceamento."
     },
     {
      "letra": "D",
      "texto": "5",
      "porque": "Não sai de cenário nenhum: AVL com 6 nós não passa de altura 3."
     },
     {
      "letra": "E",
      "texto": "6",
      "porque": "Seria o caso da ABB sem balanceamento: 1, 2, 3, 4, 5, 6 em ordem viram uma cadeia de 6 nós."
     }
    ],
    "gabarito": "B",
    "resumo": "Inserir em ordem crescente é o pior caso da ABB (vira lista) e o caso de ensino da AVL: cada desbalanceamento à direita pede uma rotação à esquerda. Árvore final: raiz 4, esquerda 2(1,3), direita 5 com filho direito 6. Dica: a altura de uma AVL com 6 nós nunca passa de 3.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Sobre uma árvore binária de pesquisa sem balanceamento, pode-se afirmar que:\n\nI) São estruturas de dados que, quando degeneradas, têm custo de inserção proporcional ao número de chaves inseridas\nII) Não servem para armazenar dados quando deseja-se ter acesso aos mesmos de maneira ordenada\nIII) Têm como principal custo extra de memória os dois apontadores que indicam os nós à esquerda e à direita de cada nó criado\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas I é verdadeira",
      "porque": "Deixa III de fora, mas III é verdadeira: cada nó carrega dois ponteiros, que são o custo extra."
     },
     {
      "letra": "B",
      "texto": "Apenas I e II são verdadeiras",
      "porque": "II é falsa. O percurso em ordem entrega as chaves ordenadas, então a ABB serve muito bem para acesso ordenado."
     },
     {
      "letra": "C",
      "texto": "Todas as afirmações são verdadeiras",
      "porque": "II é falsa, então 'todas' não vale."
     },
     {
      "letra": "D",
      "texto": "Apenas II e III são verdadeiras",
      "porque": "II é falsa e I é verdadeira. Esta troca os valores."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Correta. I e III são verdadeiras, II é falsa, e a combinação 'I e III' não está entre as letras. Sobra E por exclusão."
     }
    ],
    "gabarito": "E",
    "resumo": "I verdadeira (ABB degenerada vira lista e a inserção custa O(n)). II falsa (percurso em ordem dá as chaves ordenadas). III verdadeira (dois ponteiros por nó). Como 'apenas I e III' não existe, a resposta é 'nenhuma'. Dica: quando a combinação certa não aparece, volte e confira se a letra E é a que sobra.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0098",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Sobre árvores binárias de pesquisa sem balanceamento, pode-se afirmar que:\n\nI) É uma estrutura de dados inerentemente recursiva, sendo impossível implementar uma busca em uma árvore de maneira não recursiva\nII) É uma estrutura de dados inerentemente recursiva, sendo impossível implementar uma inserção em uma árvore de maneira não recursiva\nIII) Em muitos casos práticos, pode ter custo de busca com número de operações proporcional a log n, onde n é o número de elementos inseridos na árvore\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas I e II estão corretas",
      "porque": "Falha: I e II dizem 'impossível' fazer de forma não recursiva, e é possível. Basta um laço com ponteiro descendo."
     },
     {
      "letra": "B",
      "texto": "Apenas III está correta",
      "porque": "Correta. I e II são falsas (busca e inserção têm versão iterativa). III é verdadeira: com chaves bem distribuídas a árvore fica razoavelmente balanceada e a busca custa O(log n)."
     },
     {
      "letra": "C",
      "texto": "Apenas I e III estão corretas",
      "porque": "Falha em I: a busca iterativa desce com um ponteiro que avança para a esquerda ou a direita."
     },
     {
      "letra": "D",
      "texto": "Apenas II e III estão corretas",
      "porque": "Falha em II: a inserção iterativa guarda o pai e liga o novo nó no fim da descida."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "III é verdadeira, então há alternativa certa."
     }
    ],
    "gabarito": "B",
    "resumo": "Toda recursão pode virar laço, e a ABB não é exceção: guarde um ponteiro e desça. 'É impossível' costuma ser pista de afirmação falsa. III é verdadeira no caso médio, não no pior caso.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Marque a resposta correta. Ao inserirmos as chaves 1, 2 e 3, 4, 5, 6 em uma árvore AVL, a diferença de altura entre as sub-árvores à esquerda e à direita do nó raiz será:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "0",
      "porque": "Correta. A árvore final é 4(2(1,3), 5(-,6)). A subárvore esquerda tem altura 2 e a direita também (5 e 6), então a diferença é 0."
     },
     {
      "letra": "B",
      "texto": "1",
      "porque": "Aconteceria se uma das subárvores tivesse 3 nós em cadeia, o que a AVL não deixa."
     },
     {
      "letra": "C",
      "texto": "2",
      "porque": "Já seria desbalanceamento, que a AVL corrige com rotação."
     },
     {
      "letra": "D",
      "texto": "3",
      "porque": "Impossível em AVL: o fator de balanceamento fica em -1, 0 ou 1."
     },
     {
      "letra": "E",
      "texto": "4",
      "porque": "Impossível em AVL com 6 nós, que só tem altura 3."
     }
    ],
    "gabarito": "A",
    "resumo": "É a mesma árvore da questão 12. Depois da última rotação, raiz 4 com 2(1,3) à esquerda e 5(-,6) à direita: alturas 2 e 2. Dica: refaça a árvore uma vez e responda as duas questões juntas.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 6,
    "formato": "afirmações",
    "enunciado": "Considere um vetor não ordenado utilizado para armazenar chaves únicas (sem repetição). Pode-se afirmar que:\n\nI) O melhor algoritmo para busca no vetor é a busca binária mesmo que o vetor não esteja ordenado, independente do número de elementos do vetor e da quantidade de buscas a serem realizadas\nII) Uma busca binária implementada no vetor não funcionaria adequadamente, fornecendo resultados errados a menos que fosse feita uma ordenação\nIII) Um algoritmo de busca sequencial funcionaria e daria resultados comparando a chave com todas as posições do vetor na pior das hipóteses",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas as afirmações I e III estão corretas",
      "porque": "Falha em I: a busca binária só vale em vetor ordenado. Sem ordenação ela descarta metades erradas."
     },
     {
      "letra": "B",
      "texto": "Apenas as afirmações II e III estão corretas",
      "porque": "Correta. I é falsa. II é verdadeira (sem ordenação o resultado pode ser errado). III é verdadeira (a sequencial compara com todas as posições no pior caso)."
     },
     {
      "letra": "C",
      "texto": "Todas as afirmações estão corretas",
      "porque": "Falha em I."
     },
     {
      "letra": "D",
      "texto": "Todas as afirmações estão erradas",
      "porque": "II e III são verdadeiras."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Existe alternativa certa (B)."
     }
    ],
    "gabarito": "B",
    "resumo": "Busca binária exige vetor ordenado; a sequencial funciona em qualquer vetor e, no pior caso, compara com as n posições. Palavras como 'o melhor ... independente' costumam denunciar afirmação falsa.",
    "assuntos": [
     {
      "num": "0089",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 17,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações abaixo:\n\nI) O RADIX sort não realiza comparação entre chaves para realizar a ordenação de um vetor\nII) O número de vezes que é necessário passar por todos os elementos do vetor no RADIX sort é proporcional ao número médio de dígitos dos elementos do vetor na base utilizada pelo algoritmo para ordenação\nIII) O RADIX sort requer um espaço extra de armazenamento proporcional ao tamanho do vetor\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a afirmação I é verdadeira",
      "porque": "Deixa III de fora, mas III é verdadeira: o Radix com contagem usa um vetor auxiliar do tamanho de n."
     },
     {
      "letra": "B",
      "texto": "Apenas a afirmação II é verdadeira",
      "porque": "II é imprecisa: o número de passadas é o número de dígitos do maior valor, não a média."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmação III é verdadeira",
      "porque": "Deixa I de fora, mas I é verdadeira: o Radix distribui por dígito, sem comparar chaves."
     },
     {
      "letra": "D",
      "texto": "Apenas as afirmações II e III são verdadeiras",
      "porque": "Inclui II, que é imprecisa, e deixa I de fora."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "I e III são verdadeiras, e 'I e III' não é uma das letras. Por isso a banca anulou."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada pela banca. I verdadeira, III verdadeira, II imprecisa (as passadas dependem do maior número de dígitos, não da média). A combinação certa, 'I e III', não existe nas letras.",
    "assuntos": [
     {
      "num": "0121",
      "modulo": "18-ordenacao-linear.md"
     },
     {
      "num": "0120",
      "modulo": "18-ordenacao-linear.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 7,
    "formato": "simulação",
    "enunciado": "Considere que o vetor abaixo será ordenado com o algoritmo de ordenação por seleção\n\n`4 5 2 3 17 2 1 22`\n\nConsiderando-se que o vetor tem sua primeira posição contada como 0 (zero), a primeira troca de valores entre posições do vetor ocorrerá entre:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "posição 0 e posição 2",
      "porque": "Seria o caso se o menor da vez fosse o 2 da posição 2, mas o menor valor do vetor todo é o 1."
     },
     {
      "letra": "B",
      "texto": "posição 0 e posição 7",
      "porque": "O 22 é o maior valor. A seleção crescente leva o menor para a frente."
     },
     {
      "letra": "C",
      "texto": "Posição 0 e posição 6",
      "porque": "Correta. A seleção procura o menor de todos: é o 1, na posição 6. Ele troca com o que está na posição 0 (o 4). O vetor vira 1 5 2 3 17 2 4 22."
     },
     {
      "letra": "D",
      "texto": "Posição 1 e posição 6",
      "porque": "Seria a segunda passada, e não a primeira."
     },
     {
      "letra": "E",
      "texto": "Posição 3 e posição 5",
      "porque": "São posições que nem têm o menor elemento."
     }
    ],
    "gabarito": "C",
    "resumo": "Seleção: na passada i, ache o menor de v[i..n-1] e troque com v[i]. Na passada 0 o menor é o 1 (posição 6), que troca com a posição 0. Confirmado em C.",
    "assuntos": [
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Considere os vetores abaixo\n\nVetI: `1 2 3 4 5 6 8 7`\nVetII: `7 8 8 5 4 3 2 1`\n\nE considere as afirmações a seguir:\n\nI) A ordenação por inserção é melhor que a ordenação por seleção em VetI se considerarmos o número de comparações entre chaves realizadas pelos dois algoritmos\nII) O RADIX sort executado em base 10 realiza um número menor de operações (instruções) nos dois casos quando comparado ao mergesort\nIII) O RADIX sort executado em base 10 realiza um número menor de operações apenas em VetII quando comparado ao mergesort, ocorrendo o oposto em VetI\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a afirmação I é verdadeira",
      "porque": "Deixa II de fora. II é verdadeira: todos os valores têm 1 dígito, então o Radix faz uma passada só, que custa cerca de n + 10 operações, contra cerca de n log n do mergesort."
     },
     {
      "letra": "B",
      "texto": "Apenas a afirmação II é verdadeira",
      "porque": "Deixa I de fora. I é verdadeira: em VetI (quase ordenado) a inserção faz cerca de n comparações, a seleção sempre n(n-1)/2 = 28."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmação III é verdadeira",
      "porque": "III é falsa: o Radix não depende da ordem inicial, ele ganha nos dois vetores, não só no VetII."
     },
     {
      "letra": "D",
      "texto": "Apenas as afirmações I e II são verdadeiras",
      "porque": "Correta. I e II são verdadeiras; III é falsa."
     },
     {
      "letra": "E",
      "texto": "Apenas as afirmações I e III são verdadeiras",
      "porque": "Inclui III, que é falsa, e deixa II de fora."
     }
    ],
    "gabarito": "D",
    "resumo": "I verdadeira (inserção em vetor quase ordenado faz perto de n comparações; seleção sempre n(n-1)/2). II verdadeira (valores de um dígito, o Radix faz uma passada). III falsa (a vantagem não depende da ordem). Dica: Radix não compara, então a ordem inicial não muda o custo.",
    "assuntos": [
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0121",
      "modulo": "18-ordenacao-linear.md"
     },
     {
      "num": "0094",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações abaixo:\n\nI) Pode-se determinar o maior elemento de um vetor ordenado a um custo constante (realizando-se um número constante de operações)\nII) Pode-se inverter a ordem de um vetor já ordenado fazendo-se um número de trocas de posições igual à metade do tamanho do tamanho do vetor e sem ter que criar uma cópia do mesmo\nIII) O Quicksort é sempre a opção mais rápida (com menor tempo de execução) para ordenar qualquer vetor de qualquer tamanho e com qualquer ordenação inicial das chaves\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas as afirmações são verdadeiras",
      "porque": "III é falsa: o Quicksort tem pior caso O(n²) e, em vetores pequenos ou quase ordenados, a inserção pode ganhar."
     },
     {
      "letra": "B",
      "texto": "Apenas I é verdadeira",
      "porque": "Deixa II de fora, mas II é verdadeira."
     },
     {
      "letra": "C",
      "texto": "Apenas I e III são verdadeiras",
      "porque": "Inclui III, que é falsa, e deixa II de fora."
     },
     {
      "letra": "D",
      "texto": "Apenas I e II são verdadeiras",
      "porque": "Correta. I é verdadeira (o maior está na última posição). II é verdadeira (trocar v[i] com v[n-1-i] faz n/2 trocas, sem cópia). III é falsa."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "I e II são verdadeiras, e 'I e II' está na letra D."
     }
    ],
    "gabarito": "D",
    "resumo": "Em vetor ordenado crescente o maior é o último, acesso O(1). Inverter troca os extremos até o meio: n/2 trocas. 'Sempre a mais rápida' é afirmação absoluta falsa em ordenação.",
    "assuntos": [
     {
      "num": "0038",
      "modulo": "05-vetores-e-strings.md"
     },
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "053/2016",
  "slug": "2016-053",
  "ano": 2016,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": 6,
    "formato": "cálculo",
    "enunciado": "Seja um vetor de inteiros com 400 elementos distintos ordenados em ordem crescente. Qual é o número máximo de iterações necessárias para encontrar um elemento qualquer desse vetor, caso seja utilizado o algoritmo de busca binária?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "9",
      "porque": "Correta. O máximo é ⌊log2 400⌋ + 1. Como 2^8 = 256 e 2^9 = 512, log2 400 está entre 8 e 9, então 8 + 1 = 9 iterações."
     },
     {
      "letra": "B",
      "texto": "8",
      "porque": "É só ⌊log2 400⌋ e esquece a última comparação. Com 8 iterações você cobre 255 elementos (2^8 - 1), e o vetor tem 400."
     },
     {
      "letra": "C",
      "texto": "7",
      "porque": "Cobre só 127 elementos (2^7 - 1). Não chega a 400."
     },
     {
      "letra": "D",
      "texto": "200",
      "porque": "É o custo médio da busca sequencial, cerca de n/2, não da binária."
     },
     {
      "letra": "E",
      "texto": "400",
      "porque": "É o pior caso da busca sequencial. A binária descarta metade do vetor a cada passo."
     }
    ],
    "gabarito": "A",
    "resumo": "Cada iteração da busca binária corta o intervalo ao meio, então o pior caso é ⌊log2 n⌋ + 1. Para 400 elementos são 9 iterações. Conferido em C: o máximo medido, testando todos os 400 alvos, foi 9.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0072",
      "modulo": "10-analise.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 1,
    "formato": "conceito",
    "enunciado": "Sobre as funções abaixo,\n\n```c\nFunção I\nint fatorial(int i) {\n  if (i <= 1) {\n    return 1;\n  } else {\n    fatorial(i-1);\n  }\n}\n\nFunção II\nvoid fatorial() {\n  int fat[0] = 1;\n  for (int j=1; ; j++) {\n    fat[j] = j * fat[j-1];\n  }\n}\n```\n\nAssinale a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Somente a função I é recursiva.",
      "porque": "Correta. Recursiva é a função que chama a si mesma, e a I chama `fatorial(i-1)`. Mesmo sem `return` no `else` (o fatorial dela está errado), ela é recursiva."
     },
     {
      "letra": "B",
      "texto": "Ambas as funções são recursivas.",
      "porque": "A II só tem um laço `for`, e nenhuma chamada a si mesma."
     },
     {
      "letra": "C",
      "texto": "Somente a função II é recursiva.",
      "porque": "É o contrário: a II é iterativa (usa laço)."
     },
     {
      "letra": "D",
      "texto": "A função I não é recursivo e a função II é orientada a objeto.",
      "porque": "A I é recursiva, e C não é orientada a objeto. A frase é absurda de propósito."
     },
     {
      "letra": "E",
      "texto": "Ambas as funções não são recursivas.",
      "porque": "A I chama a si mesma, então é recursiva."
     }
    ],
    "gabarito": "A",
    "resumo": "O que define recursão é a função chamar a si mesma. Isso vale mesmo que a lógica esteja errada: a função I não devolve valor no `else`, mas continua recursiva. Dica: não deixe os erros do código desviarem da pergunta.",
    "assuntos": [
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 8,
    "formato": "conceito",
    "enunciado": "As seguintes afirmações sobre árvores estão corretas, com EXCEÇÃO de:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "É um grafo conexo que admite ciclos.",
      "porque": "Correta (é a exceção). Árvore é grafo conexo e acíclico: se tivesse ciclo, deixaria de ser árvore."
     },
     {
      "letra": "B",
      "texto": "É um grafo conexo e há exatamente um caminho entre dois vértices quaisquer.",
      "porque": "Verdadeira. Sem ciclos e conexa, existe um único caminho entre quaisquer dois vértices."
     },
     {
      "letra": "C",
      "texto": "Uma árvore com n vértices possui n-1 arestas.",
      "porque": "Verdadeira. É uma propriedade da árvore."
     },
     {
      "letra": "D",
      "texto": "Toda árvore é um grafo, mas nem todo grafo é uma árvore.",
      "porque": "Verdadeira. Árvore é um tipo particular de grafo."
     },
     {
      "letra": "E",
      "texto": "Uma união disjunta de árvores forma uma floresta",
      "porque": "Verdadeira. É a definição de floresta."
     }
    ],
    "gabarito": "A",
    "resumo": "Questão de 'EXCEÇÃO': procure a afirmação falsa. Árvore é grafo conexo e sem ciclos, com n-1 arestas e caminho único entre dois vértices. 'Admite ciclos' é o que ela não faz.",
    "assuntos": [
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0109",
      "modulo": "16-grafos.md"
     },
     {
      "num": "0150",
      "modulo": "23-grafos-avancados.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 7,
    "formato": "simulação",
    "enunciado": "Considere que o vetor abaixo será ordenado com o algoritmo de ordenação por seleção.\n\n`4 5 5 3 17 2 1 22`\n\nConsiderando-se que o vetor tem sua primeira posição contada como 0 (zero), a segunda troca de valores entre posições do vetor ocorrerá entre:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Posição 0 e posição 2",
      "porque": "O menor da primeira passada é o 1 (posição 6), não o 5 da posição 2."
     },
     {
      "letra": "B",
      "texto": "Posição 0 e posição 7",
      "porque": "O 22 é o maior valor, e a seleção leva o menor para a frente."
     },
     {
      "letra": "C",
      "texto": "Posição 1 e posição 5",
      "porque": "Correta. 1ª troca: posições 0 e 6, e o vetor vira 1 5 5 3 17 2 4 22. 2ª passada: o menor de v[1..7] é o 2 (posição 5), que troca com a posição 1."
     },
     {
      "letra": "D",
      "texto": "Posição 1 e posição 6",
      "porque": "Na segunda passada o 1 já está na frente. O 4 que foi parar na posição 6 não é o menor de v[1..7]."
     },
     {
      "letra": "E",
      "texto": "Posição 3 e posição 5",
      "porque": "A troca entre 3 e 5 seria só da quarta passada em diante."
     }
    ],
    "gabarito": "C",
    "resumo": "Simule passada por passada: a seleção acha o menor de v[i..n-1] e troca com v[i]. Passada 0: o menor é 1 (posição 6). Passada 1: o menor de 5 5 3 17 2 4 22 é o 2, na posição 5. Conferido em C: trocas (0,6) e (1,5).",
    "assuntos": [
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 5,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "Considere uma estrutura de fila (disciplina FIFO) de números inteiros com duas operações: INSERE(n) e RETIRA( ). Considere, também, que a representação do estado da fila em um instante qualquer é realizada listando os elementos, de forma que o primeiro elemento, da esquerda para a direita, é o mais antigo presente na fila.\n\nSe a fila começa vazia, a sequência:\n\nINSERE(2) → INSERE(3) → RETIRA() → INSERE(1) → RETIRA() → INSERE(4) → INSERE(5) → RETIRA() → RETIRA()\n\nO estado final da fila será:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "1 2 3 4 5",
      "porque": "Seria a fila sem nenhuma retirada. Foram 4 retiradas."
     },
     {
      "letra": "B",
      "texto": "2 3 1 4 5",
      "porque": "Também ignora as retiradas. A RETIRA tira o mais antigo, o da esquerda."
     },
     {
      "letra": "C",
      "texto": "3 1 4",
      "porque": "Seria o estado depois de só uma retirada a menos. Faltam duas retiradas (do 1 e do 4)."
     },
     {
      "letra": "D",
      "texto": "4 5",
      "porque": "É o estado antes da última RETIRA. Falta tirar o 4."
     },
     {
      "letra": "E",
      "texto": "5",
      "porque": "Correta. Estados: [2], [2 3], [3], [3 1], [1], [1 4], [1 4 5], [4 5], [5]. Tirou 2, 3, 1 e 4, nessa ordem."
     }
    ],
    "gabarito": "E",
    "resumo": "Na fila sai o mais antigo, o da esquerda. Escreva o estado depois de cada operação e não pule nenhuma: 4 inserções antes de [1 4 5] e 4 retiradas no total, sobra só o 5.",
    "assuntos": [
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0086",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Marque a alternativa CORRETA.\nUma lista duplamente encadeada tem como característica ser formada por elementos que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "se concatenam de forma circular, de tal maneira que, ao chegar ao final da lista, o próximo elemento volta a ser o primeiro.",
      "porque": "Descreve lista circular, não duplamente encadeada."
     },
     {
      "letra": "B",
      "texto": "contêm, além de um ou mais campos chave, mais um campo de ponteiro: o próximo, que permite o acesso ao elemento que sucede o atual (o próximo) presente na mesma lista.",
      "porque": "Descreve lista simplesmente encadeada, com um só ponteiro por nó."
     },
     {
      "letra": "C",
      "texto": "contêm, além de um campo chave, mais um campo de ponteiro: o próximo, que permite o acesso ao elemento que sucede o atual (o próximo) presente na mesma lista, de tal forma que os campos chave estão ordenados, ou seja, a chave do próximo é sempre maior ou igual à chave do atual elemento.",
      "porque": "Descreve lista simples e ordenada. Ordem das chaves não tem relação com ser dupla."
     },
     {
      "letra": "D",
      "texto": "contêm, além de um ou mais campos chave, dois outros campos de ponteiros: próximo e anterior, que permitem o acesso aos elementos adjacentes (próximo e anterior) presentes na mesma lista.",
      "porque": "Correta. É a definição: dois ponteiros por nó, `prox` e `ant`, o que permite andar nos dois sentidos."
     },
     {
      "letra": "E",
      "texto": "Estão em posições adjacentes da memória, permitindo o acesso sequencial ao próximo e ao anterior de cada elemento pelo simples uso de um índice.",
      "porque": "Descreve vetor. Nó de lista não fica em posições contíguas e não se acessa por índice."
     }
    ],
    "gabarito": "D",
    "resumo": "O que faz a lista ser dupla é o par de ponteiros `prox` e `ant` em cada nó. Circular, ordenada e contígua são outras características, que podem ou não aparecer junto.",
    "assuntos": [
     {
      "num": "0079",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Considere a estrutura de dados Árvore Binária de Busca (ABB). Se inserirmos numa ABB inicialmente vazia os nós: 60, 10, 20, 80, 15, 75, 12 e 77, nessa ordem. Dado que a raiz encontra-se no nível 1, a altura da árvore e o nível do nó 15, respectivamente, serão:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "5 e 4",
      "porque": "Correta. A árvore: 60 raiz; 10 à esquerda; 20 à direita de 10; 15 à esquerda de 20; 12 à esquerda de 15; 80 à direita de 60; 75 à esquerda de 80; 77 à direita de 75. O caminho 60-10-20-15-12 tem 5 níveis, e o 15 está no nível 4."
     },
     {
      "letra": "B",
      "texto": "5 e 5",
      "porque": "A altura está certa, mas o 15 está no nível 4 (60, 10, 20, 15), e não no 5."
     },
     {
      "letra": "C",
      "texto": "6 e 5",
      "porque": "Contaria um nível a mais nos dois valores."
     },
     {
      "letra": "D",
      "texto": "6 e 4",
      "porque": "O nível do 15 está certo, mas a altura é 5: o caminho mais longo tem 5 nós."
     },
     {
      "letra": "E",
      "texto": "7 e 3",
      "porque": "Nem a altura nem o nível batem com a árvore montada."
     }
    ],
    "gabarito": "A",
    "resumo": "Monte a árvore na ordem dada, sempre comparando com a raiz e descendo. O enunciado define raiz no nível 1, então a altura é a quantidade de nós no maior caminho: 5. Se contasse arestas, como no Cormen, daria 4. Conferido em C: altura 5.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "Sabendo que as seguintes operações foram realizadas:\n\n1. Dados foram inseridos numa PILHA na seguinte ordem: 11, 12, 23, 14, 25, 50, 8, 18, 29, 10.\n2. Repetiu-se 10 vezes o par de operações: retirada da PILHA; inserção na FILA.\n3. A FILA foi exibida (impressa).\n4. Repetiu-se 10 vezes o par de operações: retirada da FILA; inserção na PILHA.\n5. A PILHA foi exibida (impressa).\n\nAs possíveis estruturas exibidas nas operações 3 e 5 são:\n\nI) FILA (começo) 10 - 29 - 18 - 8 - 50 - 25 - 14 - 23 - 12 - 11 (fim)\nII) PILHA: (topo) 11 - 12 - 23 - 14 - 25 - 50 - 8 - 18 - 29 - 10\nIII) PILHA: (topo) 10 - 29 - 18 - 8 - 50 - 25 - 14 - 23 - 12 - 11\nIV) FILA: (começo) 11 - 12 - 23 - 14 - 25 - 50 - 8 - 18 - 29 – 10 (fim)\nV) A PILHA mostrada fica com os elementos em ordem invertida dos dados de entrada\n\nAs estruturas exibidas CORRETAMENTE nas operações 3 e 5 são:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I e II",
      "porque": "Correta. Tirar da pilha entrega 10 primeiro: a fila fica 10 29 18 ... 12 11 (I). Tirar da fila e empilhar põe o 10 no fundo e o 11 no topo: topo 11, 12, 23 ... 29, 10 (II)."
     },
     {
      "letra": "B",
      "texto": "I e",
      "porque": "Texto truncado no caderno. Ele parece repetir I, e a combinação certa (I e II) está na letra A."
     },
     {
      "letra": "C",
      "texto": "II e III",
      "porque": "II está certa, mas III está errada: a pilha final tem o 11 no topo, e não o 10. Essa letra também deixa de fora a fila certa (I)."
     },
     {
      "letra": "D",
      "texto": "III e IV",
      "porque": "IV está errada: a fila impressa começa pelo 10 (o último a entrar na pilha), e não pelo 11."
     },
     {
      "letra": "E",
      "texto": "III e IV",
      "porque": "É idêntica à D no caderno. Mesmo erro: III e IV estão ambas erradas."
     }
    ],
    "gabarito": "A",
    "resumo": "Passar uma pilha para uma fila inverte a ordem, e passar a fila de volta para uma pilha inverte de novo. Então a fila sai 10 ... 11 e a pilha final tem topo 11, a mesma ordem em que os dados entraram. No caderno as letras D e E são iguais e a B está cortada, mas a resposta A não depende disso.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 3,
    "formato": "código",
    "enunciado": "Os registros em uma lista duplamente encadeada com 20 elementos possuem, cada um, três campos:\n\n1. próximo: um ponteiro para o próximo elemento da lista;\n2. valor: informação armazenada pelo elemento;\n3. anterior: um ponteiro para o elemento anterior da lista.\n\nSendo \"Z\" o décimo elemento desta lista e \"X\" e \"Y\" dois outros elementos que não pertencem à lista, sendo apontados, respectivamente, pelos seguintes ponteiros \"PZ\", \"PX\" e \"PY\", considere o trecho de código abaixo.\n\n```\nPY->próximo = PX;\nPX->anterior = PY;\nPX->próximo = PZ->próximo;\nPZ->próximo->anterior = PX;\nPZ->próximo = PY;\nPY->anterior = PZ;\n```\n\nEste trecho de código é usado para inserir na lista os elementos:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Y, logo após o Z, e X, logo após o Y.",
      "porque": "Correta. `PZ->próximo = PY` e `PY->anterior = PZ` colocam o Y logo depois do Z. `PY->próximo = PX` e `PX->anterior = PY` colocam o X logo depois do Y. O X ainda herda o antigo próximo do Z. Ordem final: Z, Y, X, resto."
     },
     {
      "letra": "B",
      "texto": "Y, antes do Z, e X, logo após o Z",
      "porque": "O Y fica depois do Z, e não antes. O `PY->anterior = PZ` mostra isso."
     },
     {
      "letra": "C",
      "texto": "Y, antes do Z, e X, antes do Y.",
      "porque": "Nenhuma das ligações põe elementos antes do Z."
     },
     {
      "letra": "D",
      "texto": "X, logo após o Z, e Y, logo após o X.",
      "porque": "Inverte a ordem. O Z aponta para o Y (`PZ->próximo = PY`), e não para o X."
     },
     {
      "letra": "E",
      "texto": "X, antes do Z, e Y, logo após o Z.",
      "porque": "O X não vai antes do Z: ele aponta para o antigo seguinte do Z."
     }
    ],
    "gabarito": "A",
    "resumo": "Em inserção em lista dupla, siga os ponteiros: o primeiro que muda em `PZ` diz quem fica logo depois dele. Aqui `PZ->próximo = PY`, então o Y vem logo após o Z, e o X vem depois do Y e antes do antigo seguinte. Dica: desenhe quatro caixinhas e as setas das seis linhas.",
    "assuntos": [
     {
      "num": "0079",
      "modulo": "11-listas.md"
     },
     {
      "num": "0062",
      "modulo": "08-structs.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre um hash linear (sem encadeamento):\n\nI) É obrigatório o uso de várias funções de hash\nII) Não funciona com número de chaves maior que o tamanho da tabela hash\nIII) Quando acontece uma colisão, o valor a ser inserido é colocado no local no lugar do já existente.\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas são verdadeiras",
      "porque": "I e III são falsas."
     },
     {
      "letra": "B",
      "texto": "Todas são falsas",
      "porque": "II é verdadeira: sem encadeamento a tabela é um vetor de tamanho M e não guarda mais do que M chaves."
     },
     {
      "letra": "C",
      "texto": "Apenas I e III são verdadeiras",
      "porque": "Os dois erram. I é falsa (uma função basta, a sondagem linear só anda para a posição seguinte). III é falsa (colisão não sobrescreve)."
     },
     {
      "letra": "D",
      "texto": "Apenas II é verdadeira",
      "porque": "Correta. II é verdadeira (endereçamento aberto não passa de M chaves). I é falsa e III é falsa: em colisão a chave vai para a próxima posição livre."
     },
     {
      "letra": "E",
      "texto": "Apenas I e II são verdadeiras",
      "porque": "I é falsa: o hash linear usa uma função, e a sondagem linear resolve as colisões."
     }
    ],
    "gabarito": "D",
    "resumo": "No hash linear (endereçamento aberto com sondagem linear) tudo mora no vetor de M posições, então C > M é impossível. Colisão manda a chave para a próxima posição livre, e uma função de hash basta. Cuidado: a mesma afirmação II sobre o hash encadeado seria falsa.",
    "assuntos": [
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 11,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "As sequências que representam os percursos da árvore da figura em pós-ordem e in-ordem são, respectivamente:",
    "figuras": [
     "2016-053-q11"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "P Q S T R e P Q S T R",
      "porque": "As duas sequências são iguais e começam por P, que é o percurso em pré-ordem. Pós-ordem termina na raiz, e a in-ordem tem a raiz no meio."
     },
     {
      "letra": "B",
      "texto": "S T Q P R e S T Q R P",
      "porque": "Em pós-ordem a raiz P é a última, e aqui ela é a quarta. A segunda (S T Q R P) é a própria pós-ordem, e não a in-ordem."
     },
     {
      "letra": "C",
      "texto": "S T Q R P e S Q T P R",
      "porque": "Correta. Pós-ordem (esquerda, direita, raiz): subárvore de Q dá S T Q, depois R, depois P. In-ordem (esquerda, raiz, direita): S Q T, depois P, depois R."
     },
     {
      "letra": "D",
      "texto": "R P Q T S e S T Q R P",
      "porque": "A primeira sequência não é pós-ordem (a raiz P deveria ser a última). A segunda (S T Q R P) é a pós-ordem, e não a in-ordem."
     },
     {
      "letra": "E",
      "texto": "P T Q R S e P Q S T R",
      "porque": "Nenhuma das duas começa certo: pós-ordem não pode começar pela raiz P."
     }
    ],
    "gabarito": "C",
    "resumo": "Memorize: pré-ordem visita a raiz primeiro, in-ordem no meio, pós-ordem por último. A figura é a árvore P com filhos Q e R, e Q com filhos S e T. Pós-ordem: S T Q R P. In-ordem: S Q T P R. O gabarito é C. Atenção: o curso antes tratava a figura como ausente, mas ela está no caderno e confirma a letra C.",
    "assuntos": [
     {
      "num": "0098",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2016-053/figuras/q11-arvore.png"
    ]
   },
   {
    "numero": 12,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre hash linear e hash encadeado\n\nI) Hash encadeado funciona melhor em disco, pois as chaves sempre ficam próximas uma das outras, facilitando a varredura.\nII) Para uma tabela hash de tamanho M, tanto o hash linear quanto o hash encadeado podem receber uma quantidade de chaves C, onde C > M.\nIII) Quanto acontece uma colisão no hash encadeado, a chave é inserida na posição livre mais próxima da chave original.\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas são verdadeiras",
      "porque": "As três são falsas."
     },
     {
      "letra": "B",
      "texto": "Todas são falsas",
      "porque": "Correta. I é falsa: listas encadeadas ficam espalhadas pela memória, e o que vai melhor em disco é o acesso contíguo. II é falsa: o linear não aceita C > M. III é falsa: no encadeado a chave entra na lista do balde, e não numa posição livre."
     },
     {
      "letra": "C",
      "texto": "Apenas I e III são verdadeiras",
      "porque": "Os dois erram: o encadeado não é 'próximo' em disco, e a colisão não procura posição livre."
     },
     {
      "letra": "D",
      "texto": "Apenas II é verdadeira",
      "porque": "II só vale para o encadeado. O linear (aberto) tem no máximo M chaves."
     },
     {
      "letra": "E",
      "texto": "Apenas I e II são verdadeiras",
      "porque": "I é falsa, e II também."
     }
    ],
    "gabarito": "B",
    "resumo": "Hash linear (aberto): tudo no vetor, no máximo M chaves, colisão procura a próxima posição livre. Hash encadeado: cada balde é uma lista, aceita C > M e a colisão só aumenta a lista. Nenhuma das três afirmações é verdadeira.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     },
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Em uma árvore AVL, todos os nós têm grau",
    "alternativas": [
     {
      "letra": "A",
      "texto": "0, 1 ou 2.",
      "porque": "Correta. A AVL é uma árvore binária de busca: cada nó tem no máximo dois filhos. Grau é a quantidade de filhos: 0 (folha), 1 ou 2."
     },
     {
      "letra": "B",
      "texto": "divisível por 2.",
      "porque": "Grau 1 existe na AVL (um nó com um filho só), e 1 não é divisível por 2."
     },
     {
      "letra": "C",
      "texto": "2",
      "porque": "Só os nós internos com dois filhos teriam grau 2. Folhas têm 0."
     },
     {
      "letra": "D",
      "texto": "1 e 2",
      "porque": "Esquece as folhas, que têm grau 0."
     },
     {
      "letra": "E",
      "texto": "maior ou igual a 2.",
      "porque": "Isso valeria para árvore com ramificação mínima (como a B). Na AVL as folhas têm 0."
     }
    ],
    "gabarito": "A",
    "resumo": "Grau de um nó é o número de filhos. Em árvore binária o grau vai de 0 a 2. Não confunda grau com altura nem com fator de balanceamento.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "A estrutura de dados conhecida como Árvore Binária de Busca (ABB) encontra diversas aplicações em soluções práticas. Sobre esta estrutura é CORRETO afirmar:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Uma ABB é um conjunto finito de nós que possui um nó especial, chamado raiz, do qual partem os nós de duas árvores binárias distintas: a da esquerda e a da direita.",
      "porque": "Correta pelo gabarito. É a definição recursiva de árvore binária: raiz mais duas subárvores binárias, esquerda e direita."
     },
     {
      "letra": "B",
      "texto": "Quando os elementos a serem inseridos na ABB estão em ordem crescente, resulta em uma ABB com altura mínima.",
      "porque": "Falso. Em ordem crescente a ABB degenera em lista e tem a altura máxima, n."
     },
     {
      "letra": "C",
      "texto": "Para se utilizar uma ABB como método de ordenação, basta fazer o caminhamento ou percurso \"em-ordem\" e obter todos os elementos ordenados.",
      "porque": "É uma ideia verdadeira (o percurso em ordem entrega as chaves ordenadas) e foi a escolha do curso. A banca preferiu A, talvez porque 'basta' ignora o custo de montar a árvore antes."
     },
     {
      "letra": "D",
      "texto": "Uma característica que confere à ABB grande agilidade na pesquisa e recuperação de elementos é que seus nós são sempre rearranjados de forma que a árvore resultante é sempre perfeitamente balanceada.",
      "porque": "Falso. A ABB comum não rearranja nada. Quem se rebalanceia é a AVL."
     },
     {
      "letra": "E",
      "texto": "ABB são um caso especial de listas encadeadas em que nenhum nó aponta para mais de 2 sucessores.",
      "porque": "Falso. Lista tem um único sucessor por nó. Árvore é outra estrutura, não caso especial de lista."
     }
    ],
    "gabarito": "A",
    "resumo": "Gabarito oficial A. Atenção à divergência: o curso tinha chegado na C (percurso em ordem dá as chaves ordenadas, o que é verdade). A banca marcou A, a definição de árvore binária. Em prova, se duas alternativas parecem certas, a que é definição formal tende a ser a preferida.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0098",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações a seguir sobre os algoritmos de ordenação Quicksort, MergeSort, HeapSort e InsertionSort\n\nI) São algoritmos estáveis: InsertionSort, QuickSort e MergeSorte\nII) Pior caso tem número de operações quadrático (proporcional a uma constante vezes n²): InsertionSort, QuickSort\nIII) Utiliza um espaço extra proporcional a n² (proporcional ao quadrado do número de elementos): HeapSort,\nIV) A ordem das entradas é incapaz de influenciar o desempenho do algoritmo: InsertionSort, MergeSort\n\nMarque a alternativa que indica TODAS as afirmações INCORRETAS feitas:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I e IV",
      "porque": "Falta o III, que também é incorreta."
     },
     {
      "letra": "B",
      "texto": "I , III e IV",
      "porque": "Correta. I é incorreta (o Quicksort usual não é estável). II é correta (inserção e Quicksort têm pior caso O(n²)). III é incorreta (o Heapsort usa O(1) de espaço extra). IV é incorreta (a inserção depende muito da ordem de entrada)."
     },
     {
      "letra": "C",
      "texto": "I, II e III",
      "porque": "II é correta, então não entra na lista de incorretas. Falta o IV."
     },
     {
      "letra": "D",
      "texto": "I, II, III e IV",
      "porque": "II é correta. Só três das quatro estão incorretas."
     },
     {
      "letra": "E",
      "texto": "II e IV",
      "porque": "II é correta. Falta incluir I e III."
     }
    ],
    "gabarito": "B",
    "resumo": "A pergunta pede as INCORRETAS. I incorreta (Quicksort não é estável), II correta (pior caso quadrático da inserção e do Quicksort), III incorreta (Heapsort é in-place, O(1) extra), IV incorreta (a inserção faz n-1 comparações em vetor ordenado e n²/2 em invertido). Leia o comando: 'incorretas'.",
    "assuntos": [
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0094",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0103",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0168",
      "modulo": "26-analise-formal.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Uma árvore AVL é uma árvore binária de busca com balanceamento automático que respeita algumas propriedades fundamentais. Como todas as árvores, ela tem uma propriedade chamada altura. Sabendo que a altura de uma folha é igual a um e que a altura de um nó pai é igual ao máximo das alturas de seus filhos mais um, qual estrutura NÃO pode representar uma árvore AVL?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Uma árvore com três nós e altura igual a três",
      "porque": "Correta. Três nós em altura 3 formam uma cadeia (um nó por nível). A raiz teria subárvores de alturas 2 e 0, fator de balanceamento 2: não é AVL."
     },
     {
      "letra": "B",
      "texto": "Uma árvore com seis nós e altura igual a três",
      "porque": "Pode ser AVL. Por exemplo, raiz com 3 nós de um lado e 2 do outro, todos com diferença de altura até 1."
     },
     {
      "letra": "C",
      "texto": "Uma árvore com três nós e altura igual a dois",
      "porque": "É a árvore completa: raiz com duas folhas. É AVL."
     },
     {
      "letra": "D",
      "texto": "Uma árvore vazia",
      "porque": "A árvore vazia é AVL por vacuidade."
     },
     {
      "letra": "E",
      "texto": "Uma árvore com dois nós",
      "porque": "Uma raiz com um filho tem fator 1. É AVL."
     }
    ],
    "gabarito": "A",
    "resumo": "AVL exige diferença de altura de no máximo 1 entre as subárvores de cada nó. Com 3 nós, só a árvore completa (altura 2) cumpre. Cadeia de 3 nós (altura 3) quebra a regra na raiz.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 17,
    "topico": 6,
    "formato": "código",
    "enunciado": "Considere os códigos de funções abaixo, assumindo que os mesmos são usados dentro de um programa e que os todos os cabeçalhos necessários são incluídos:\n\n```c\n/*QUADRO I) função que retorna 1 se a chave\nde busca chave, passada como parâmetro, ocorre\ndentro de um vetor de inteiros ordenado e\nretorna 0 caso a chave não ocorra no vetor. O\nvetor tem tamanho determinado pelo parâmetro\ntm */\nint buscaChave(int v[],int chave,int tm) {\n  while((tm>= 0) && (v[tm]!= chave)) tm--;\n  if (tm >= 0) return 0;\n  return 1;\n}\n```\n\n```c\n/* QUADRO II) Conta ocorrências de uma\nchave na lista encadeada, retornando o total de\nocorrências , zero caso a chave não ocorra\n*/\nint ContaOcorrenciasChave(tipoNo *prim, int\nchave) {\n  tipoNo *aux = prim;\n  int cont = 0;\n  int x;\n  for (x = 0; aux[x] != NULL; x++){\n    if(aux[x]. dado == chave) cont++;\n  }\n  return x;\n}\n```\n\nMarque a alternativa correta dentre as afirmações abaixo:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Os dois códigos executam as tarefas propostas sem gerar qualquer tipo de erro de lógica ou de vazamento de memória",
      "porque": "Nenhum acerta: o I devolve 0 quando acha e 1 quando não acha, e o II devolve `x`, e não `cont`."
     },
     {
      "letra": "B",
      "texto": "Apenas o código I executa sem erros a tarefa proposta",
      "porque": "O I tem a lógica de retorno invertida. Se `tm >= 0` a chave foi achada, e o código devolve 0."
     },
     {
      "letra": "C",
      "texto": "Apenas o código II executa sem erros a tarefa proposta",
      "porque": "O II percorre lista como se fosse vetor (`aux[x]`), compara struct com `NULL` e devolve `x` em vez de `cont`."
     },
     {
      "letra": "D",
      "texto": "Os dois códigos geram erros de vazamento de memória ou falha de segmentação",
      "porque": "Nenhum aloca memória, então não há vazamento. Os erros são de lógica (retorno invertido, retorno de `x`) e, no II, de compilação. Não é isso que a alternativa afirma."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Correta. Ambos têm erro (I: retorno invertido; II: `aux[x]` em lista e `return x`), mas nenhum dos erros é o que A a D descrevem."
     }
    ],
    "gabarito": "E",
    "resumo": "Gabarito oficial E. Atenção à divergência: o curso tinha chegado em D. O D diz que os dois geram vazamento ou falha de segmentação, mas os erros reais são outros: retorno invertido no I, e no II a lista tratada como vetor (a struct comparada com `NULL` nem compila) e retorno de `x` no lugar de `cont`. Nenhuma das letras A a D descreve isso.",
    "assuntos": [
     {
      "num": "0089",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0057",
      "modulo": "07-memoria-dinamica.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Considere as definições a seguir.\n\nI) O nível do nó raiz de uma árvore é 1.\nII) O nível de qualquer nó subsequente é igual ao nível do seu nó pai mais 1.\nIII) A profundidade de uma árvore é igual ao maior nível encontrado dentre todos os seus nós\n\nPartindo-se das premissas acima, a menor e a maior quantidade de nós, respectivamente, que poderiam existir em uma árvore binária de profundidade 4 são:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "4 e 15",
      "porque": "Correta. Mínimo: um nó por nível, 4 nós. Máximo: 1 + 2 + 4 + 8 = 15 = 2^4 - 1."
     },
     {
      "letra": "B",
      "texto": "3 e 15",
      "porque": "Com profundidade 4 você precisa de pelo menos um nó em cada um dos 4 níveis, então o mínimo é 4."
     },
     {
      "letra": "C",
      "texto": "3 e 16",
      "porque": "Os dois valores estão errados."
     },
     {
      "letra": "D",
      "texto": "4 e 16",
      "porque": "O máximo de 4 níveis é 2^4 - 1 = 15, e não 16."
     },
     {
      "letra": "E",
      "texto": "5 e 14",
      "porque": "O mínimo é 4, e o máximo é 15."
     }
    ],
    "gabarito": "A",
    "resumo": "Com a raiz no nível 1: o mínimo de nós para ter profundidade d é d (uma cadeia), e o máximo é 2^d - 1 (árvore cheia). Para d = 4 são 4 e 15.",
    "assuntos": [
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Uma árvore binária completa tem no 5º nível uma quantidade de nós igual a",
    "alternativas": [
     {
      "letra": "A",
      "texto": "16",
      "porque": "Correta. O nível k tem 2^(k-1) nós, com a raiz no nível 1. No nível 5: 2^4 = 16."
     },
     {
      "letra": "B",
      "texto": "15",
      "porque": "É o total de nós até o nível 4 (1 + 2 + 4 + 8), e não o número de nós do nível 5."
     },
     {
      "letra": "C",
      "texto": "31",
      "porque": "É o total de nós até o nível 5 (2^5 - 1)."
     },
     {
      "letra": "D",
      "texto": "64",
      "porque": "Seria o nível 7."
     },
     {
      "letra": "E",
      "texto": "32",
      "porque": "Seria o nível 6, ou 2^5. O nível 5 tem 2^4."
     }
    ],
    "gabarito": "A",
    "resumo": "Nível k de uma árvore binária completa tem 2^(k-1) nós (raiz no nível 1). Não confunda com o total acumulado até o nível k, que é 2^k - 1.",
    "assuntos": [
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Considere uma árvore binária de busca cujos nós armazenam números inteiros variando de 1 a 100, na qual se quer buscar o número 54. Qual das seguintes sequências representa uma sequência de busca válida dentro desta árvore?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "5, 18, 34, 60, 40, 52, 54",
      "porque": "Correta. 54 > 5, 18 e 34: vai sempre para a direita. 54 < 60: esquerda. 54 > 40 e 54 > 52: direita, chega no 54. Todos os nós estão dentro dos limites que a ABB impõe."
     },
     {
      "letra": "B",
      "texto": "25, 27, 28, 26, 60, 50, 58, 54",
      "porque": "Depois do 28, o 54 vai para a direita (54 > 28), e o 26 não pode estar lá, porque 26 < 28."
     },
     {
      "letra": "C",
      "texto": "37, 70, 32, <não encontrou>",
      "porque": "O 54 é maior que 37 e vai para a direita, e então o 70 vai para a esquerda. O 32 é menor que 37, e não pode estar na subárvore direita do 37."
     },
     {
      "letra": "D",
      "texto": "40, 70, 43, 44, 73, 57, 54",
      "porque": "O 73 é maior que 70, então não pode estar na subárvore esquerda do 70, por onde a busca passa."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Existe sequência válida (A)."
     }
    ],
    "gabarito": "A",
    "resumo": "Na busca, cada nó visitado limita os valores possíveis dos nós seguintes: ao ir para a esquerda de x, tudo o que vem depois é menor que x, e ao ir para a direita, maior. Teste cada sequência com os limites (mínimo, máximo) atualizados. Só A cumpre todos os limites.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "024/2017",
  "slug": "2017-024",
  "ano": 2017,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": 3,
    "formato": "afirmações",
    "enunciado": "Avaliando as seguintes sentenças a respeito de estrutura de dados:\n\nI. A diferença entre árvore binária de busca e árvores AVL é o fato de que a segunda pode se reconfigurar dinamicamente, com o intuito de manter um bom nível de balanceamento.\nII. Uma pilha garante que o último elemento inserido seja localizado no seu topo. Porém, do ponto de vista conceitual, qualquer elemento da pilha pode ser removido, ainda que não esteja no seu topo.\nIII. Do ponto de vista conceitual, não há diferença alguma entre uma estrutura de array e uma lista encadeada.\nIV. Tabelas hash são estruturas de dados indicadas para armazenar grande volume de dados. Apesar dessas estruturas permitirem acesso indexado, mais de um elemento pode ter o mesmo índice. Elementos com o mesmo índice podem ser armazenados em uma mesma lista encadeada.\n\nÉ CORRETO afirmar que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "apenas I e IV são verdadeiras.",
      "porque": "Correta. I é verdadeira (a AVL rotaciona para se manter balanceada) e IV é verdadeira (colisões no encadeamento ficam numa lista no mesmo balde). II e III são falsas."
     },
     {
      "letra": "B",
      "texto": "apenas I é verdadeira.",
      "porque": "Deixa IV de fora, mas IV descreve o hash com encadeamento corretamente."
     },
     {
      "letra": "C",
      "texto": "apenas III e IV são verdadeiras.",
      "porque": "III é falsa: array é contíguo e acessado por índice, a lista é encadeada por ponteiros, com custos diferentes."
     },
     {
      "letra": "D",
      "texto": "apenas II e III são verdadeiras.",
      "porque": "As duas são falsas. Pilha só remove do topo, e array e lista são diferentes."
     },
     {
      "letra": "E",
      "texto": "apenas I, II e IV são verdadeiras.",
      "porque": "Inclui II, que é falsa: remover do meio da pilha contradiz a definição de pilha, que só retira do topo."
     }
    ],
    "gabarito": "A",
    "resumo": "I verdadeira, II falsa (pilha só remove do topo, LIFO), III falsa (array é contíguo e acessa por índice; lista usa ponteiros e não é contígua), IV verdadeira (hash com encadeamento guarda as colisões numa lista). Dica: 'qualquer elemento ... ainda que não esteja no topo' desmente a pilha.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Marque a alternativa CORRETA.\nQual dos algoritmos abaixo apresenta o menor custo (em termos de número comparações entre elementos) ao considerar-se, para cada algoritmo, a pior disposição possível para os elementos do vetor a ser ordenado. Considere que o vetor a ser ordenado é muito grande, acima de 1 milhão de elementos.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Heapsort",
      "porque": "Correta. O pior caso do Heapsort é O(n log n). Para 1 milhão de elementos isso é da ordem de 20 milhões de comparações, contra cerca de 10^12 dos quadráticos."
     },
     {
      "letra": "B",
      "texto": "Quicksort",
      "porque": "O pior caso (pivô ruim, como vetor ordenado com pivô na ponta) é O(n²). Na média é rápido, mas a pergunta é sobre o pior caso."
     },
     {
      "letra": "C",
      "texto": "Inserção",
      "porque": "O pior caso (vetor invertido) é O(n²)."
     },
     {
      "letra": "D",
      "texto": "Seleção",
      "porque": "Faz n(n-1)/2 comparações sempre, ou seja, O(n²)."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das anteriores porque todos apresentam custo igual",
      "porque": "Os custos são bem diferentes para n grande: O(n log n) no Heapsort contra O(n²) nos outros."
     }
    ],
    "gabarito": "A",
    "resumo": "A pergunta é pelo pior caso, não pelo caso médio. Dos quatro, só o Heapsort mantém O(n log n) nessa situação. O Quicksort é o que mais confunde, porque na média costuma ganhar.",
    "assuntos": [
     {
      "num": "0103",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Marque a alternativa CORRETA.\nQual dos algoritmos abaixo apresenta o menor custo (em termos de número movimentações de elementos realizadas) ao considerar-se, para cada algoritmo, a pior disposição possível para os elementos do vetor a ser ordenado. Considere que o vetor a ser ordenado é muito grande, acima de 1 milhão de elementos.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Heapsort",
      "porque": "Move elementos a cada descida na heap, algo como O(n log n) movimentações."
     },
     {
      "letra": "B",
      "texto": "Quicksort",
      "porque": "No pior caso faz O(n²) comparações e muitas movimentações, mais que a seleção."
     },
     {
      "letra": "C",
      "texto": "Inserção",
      "porque": "No pior caso (vetor invertido) desloca elementos O(n²) vezes."
     },
     {
      "letra": "D",
      "texto": "Seleção",
      "porque": "Correta. A seleção faz no máximo n-1 trocas, uma por passada. Para ordenar 1 milhão de elementos são no máximo 1 milhão de trocas."
     },
     {
      "letra": "E",
      "texto": "Mergesort",
      "porque": "Copia elementos para o vetor auxiliar a cada nível, O(n log n) movimentações."
     }
    ],
    "gabarito": "D",
    "resumo": "Aqui a conta é de movimentações, não de comparações. A seleção compara muito (n²/2), mas troca pouco: no máximo n-1 vezes. É o algoritmo indicado quando mover registro é caro.",
    "assuntos": [
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 3,
    "formato": "afirmações",
    "enunciado": "Considere as seguintes afirmações sobre a estrutura lista encadeada dinâmica e marque a alternativa CORRETA.\n\nI. A busca em tal estrutura realiza menos comparações do que a melhor opção de algoritmo de busca em um vetor ordenado quando se considera o pior cenário para cada estrutura.\nII. É uma estrutura de dados usada para ordenar chaves por ser mais eficiente no processo de ordenação que o heapsort\nIII. É tipicamente utilizada como estrutura de dados básica na implementação de hash por endereçamento aberto",
    "alternativas": [
     {
      "letra": "A",
      "texto": "As três afirmações são falsas",
      "porque": "Correta. I é falsa: a lista exige O(n) no pior caso, e a busca binária no vetor ordenado faz O(log n). II é falsa: lista não ordena nada, e o Heapsort é O(n log n). III é falsa: endereçamento aberto usa vetor."
     },
     {
      "letra": "B",
      "texto": "As três afirmações são verdadeiras",
      "porque": "Nenhuma é verdadeira."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmação I é verdadeira",
      "porque": "I é falsa: a lista não aceita busca binária, e a busca sequencial faz até n comparações."
     },
     {
      "letra": "D",
      "texto": "Apenas a afirmação II é verdadeira",
      "porque": "Lista encadeada é estrutura de armazenamento, não de ordenação. Ordenar uma lista custa pelo menos O(n log n)."
     },
     {
      "letra": "E",
      "texto": "Apenas a afirmação III é verdadeira",
      "porque": "O hash por endereçamento aberto usa um vetor. A lista encadeada aparece no hash com encadeamento."
     }
    ],
    "gabarito": "A",
    "resumo": "I falsa (busca em lista é O(n), em vetor ordenado é O(log n)), II falsa (lista não 'ordena'), III falsa (endereçamento aberto trabalha em vetor). Quando todas as afirmações fazem uma comparação favorável à lista, desconfie.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 5,
    "topico": 3,
    "formato": "código",
    "enunciado": "Dada uma lista encadeada onde cada nó da lista é do tipo No, cujos campos são um ponteiro para o próximo elemento (campo prox) e um dado do tipo inteiro (campo dado). Dado também quatro (4) opções (versões) de funções para realizar a busca por um elemento em uma lista encadeada, onde recebe-se um ponteiro para o primeiro elemento da lista e uma chave. A função de busca deve retornar 1 (um) caso encontre o elemento buscado e 0 (zero) em caso contrário.\n\nCom base nas informações anteriores, considere que: (1) a lista encadeada não possui um nó cabeça de lista, portanto todos os nós contém valores presentes na lista; (2) todos os tipos de dados foram previamente declarados no programa; (3) a função não deve ter problemas de alocação de memória, seja por deixar de alocar dinamicamente dados necessários ou por causar alocação dinâmica de dados desnecessária.\n\nAnalise as funções abaixo e marque a alternativa CORRETA\n\n```c\n/* versão I */\nint busca(No *prim, int chave) {\n  No *aux = (No *) malloc(sizeof(No));\n  aux = prim;\n  while(aux!= NULL) {\n    if(aux->dado == chave) return 1;\n    aux = aux>prox;\n  }\n  return 0;\n}\n\n/* versão II */\nint busca(No *prim, int chave) {\n  while(prim!= NULL) {\n    if(prim->dado == chave) return 1;\n    prim = prim->prox;\n  }\n  return 0;\n}\n\n/* versão III */\nint busca(No *prim, int chave) {\n  No * aux = prim;\n  while(prim->prox!= NULL) {\n    if(prim->dado == chave) return 1;\n    aux = aux->prox;\n  }\n  return 0;\n}\n\n/* versão IV */\nint busca(No *prim, int chave) {\n  No *aux = (No *) malloc(sizeof(No));\n  while(aux->prox!= NULL) {\n    if(aux->dado == chave) return 1;\n    aux = aux>prox;\n  }\n  return 0;\n}\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "A versão I está correta e não apresenta problemas de alocação de memória.",
      "porque": "A I faz `malloc` e logo sobrescreve `aux` com `prim`, perdendo o bloco alocado (vazamento). E `aux>prox` é erro de digitação: o certo é `aux->prox`."
     },
     {
      "letra": "B",
      "texto": "A versão II está correta e não apresenta problemas de alocação de memória.",
      "porque": "Correta. Não aloca nada e anda com o próprio parâmetro `prim` (que é uma cópia local do ponteiro), comparando até `NULL`. Devolve 1 se achou e 0 se acabou a lista."
     },
     {
      "letra": "C",
      "texto": "A versão III está correta e não apresenta problemas de alocação de memória.",
      "porque": "O laço testa `prim->prox`, mas avança `aux`. Como `prim` nunca muda, o laço não termina (ou roda sem avançar), e o último nó nunca é comparado."
     },
     {
      "letra": "D",
      "texto": "A versão IV está correta e não apresenta problemas de alocação de memória.",
      "porque": "Aloca um nó sem necessidade (vazamento) e percorre esse nó novo com campos sem valor, e não a lista. Também tem `aux>prox`."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores está correta",
      "porque": "A versão II está correta."
     }
    ],
    "gabarito": "B",
    "resumo": "Busca em lista sem nó cabeça: percorra com o ponteiro recebido (`while (p != NULL) { ...; p = p->prox; }`). Não precisa de `malloc`: alocar só serve para criar nó novo. Dica: procure `malloc` sobrando, laço que não avança e teste de `->prox` no lugar do próprio nó.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0077",
      "modulo": "11-listas.md"
     },
     {
      "num": "0054",
      "modulo": "07-memoria-dinamica.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "Após a inserção da sequencia de números 3, 4, 6, 8 e 9 em uma pilha, o resultado CORRETO de 3 remoções sucessivas seria:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "3, 4 e 6, nesta ordem",
      "porque": "Seria a saída de uma fila (FIFO). Pilha tira o último que entrou."
     },
     {
      "letra": "B",
      "texto": "6, 3 e 4, nesta ordem",
      "porque": "Não segue nenhuma disciplina de pilha ou de fila."
     },
     {
      "letra": "C",
      "texto": "6, 8 e 9, nesta ordem",
      "porque": "Está na ordem contrária da pilha: o 9 sai primeiro."
     },
     {
      "letra": "D",
      "texto": "9, 8 e 6, nesta ordem",
      "porque": "Correta. LIFO: o último a entrar (9) é o primeiro a sair, depois 8 e depois 6."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "A letra D descreve a saída certa."
     }
    ],
    "gabarito": "D",
    "resumo": "Pilha é LIFO. Depois de empilhar 3, 4, 6, 8, 9, o topo é o 9, e as três remoções devolvem 9, 8, 6.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as seguintes afirmações:\n\nI. Hash por encadeamento nunca apresenta colisões secundárias\nII. Hash por encadeamento jamais permite que o número de comparações entre chaves em uma operação de busca passe de log n, onde n é o número de chaves inseridas no hash.\nIII. Hash por encadeamento realiza sempre menos comparações entre chaves do que qualquer hash por endereçamento aberto.\n\nMarque a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a afirmação I é verdadeira",
      "porque": "Correta. Colisão secundária (aglomerado de posições) é problema do endereçamento aberto. No encadeamento as colisões ficam na lista do balde. II e III são falsas."
     },
     {
      "letra": "B",
      "texto": "Apenas a afirmação II é verdadeira",
      "porque": "II é falsa: no pior caso todas as chaves caem no mesmo balde e a busca compara n chaves."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmação III é verdadeira",
      "porque": "III é falsa: com tabela folgada, o endereçamento aberto pode fazer menos comparações que o encadeamento. 'Sempre' e 'qualquer' denunciam a falsidade."
     },
     {
      "letra": "D",
      "texto": "Apenas as afirmações II e III são verdadeiras",
      "porque": "Ambas são falsas."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores está correta",
      "porque": "I é verdadeira, então A está certa."
     }
    ],
    "gabarito": "A",
    "resumo": "I verdadeira (colisão secundária é de endereçamento aberto). II falsa (o pior caso do encadeamento é n comparações, não log n). III falsa ('sempre menos' que 'qualquer' outro). Dica: 'nunca', 'jamais', 'sempre' e 'qualquer' pedem desconfiança.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     },
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Considere as seguintes árvores onde são apresentados apenas os valores das chaves em cada nó, sem mostrar o valor de outros campos eventualmente existentes. Considerando em todos os casos que as árvores não estão em processo de rotação por inserção de chaves, estando portanto em seu estado final após a inserção do conjunto de chaves mostrado.\n\nÉ CORRETO afirmar que:",
    "figuras": [
     "2017-024-q08-i",
     "2017-024-q08-ii",
     "2017-024-q08-iii",
     "2017-024-q08-iv"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a árvore do quadro I poderia ser uma árvore AVL",
      "porque": "Não só a I. A II (pelo formato) e a IV também são AVL: em todos os nós a diferença de altura é no máximo 1."
     },
     {
      "letra": "B",
      "texto": "Todas as opções apresentadas nos quadros de I a IV podem ser exemplos de árvores AVL",
      "porque": "A III não é AVL: o nó 10 tem subárvore esquerda vazia (altura 0) e subárvore direita com altura 2, diferença 2."
     },
     {
      "letra": "C",
      "texto": "Nenhuma das 4 opções apresentadas podem ser exemplos de árvores AVL",
      "porque": "I, II e IV podem ser AVL."
     },
     {
      "letra": "D",
      "texto": "Apenas as opções I e III podem ser exemplos de árvores AVL",
      "porque": "A III não pode, por causa do nó 10, e a IV pode. Falta incluir II e IV e tirar a III."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores (de A até D) está correta",
      "porque": "Correta. Os quadros I, II e IV podem ser AVL, e só o III não pode. Nenhuma das letras A a D diz isso."
     }
    ],
    "gabarito": "E",
    "resumo": "Confira o fator de balanceamento (altura da esquerda menos a da direita) de cada nó. I: árvore cheia, tudo 0. II: B tem só filho direito e E só filho esquerdo, mas as diferenças são 1; A tem alturas 2 e 3. IV: 4 (2 e 2), 12 (2 e 1), 8 (3 e 3). III: o nó 10 tem esquerda vazia e direita de altura 2, então quebra a AVL. Resultado: I, II e IV podem ser AVL.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2017-024/figuras/q08-arvores.png"
    ]
   },
   {
    "numero": 9,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "Marque a alternativa CORRETA:\nConsidere uma estrutura de fila (disciplina FIFO) de números inteiros com duas operações: INSERE (n) e RETIRA ( ). Considere, também, que a representação do estado da fila em um instante qualquer é realizada listando os elementos, de forma que o primeiro elemento, da esquerda para a direita, é o mais antigo presente na fila.\n\nSe a fila começa vazia, a sequência:\n\nINSERE (b) → INSERE (c) → RETIRA ( ) → INSERE (a) → RETIRA ( ) → INSERE (e) → INSERE (e) → RETIRA ( ) → RETIRA ( )\n\nlevará a uma fila no estado:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "a b c e",
      "porque": "Não é alcançável: o b e o c entraram primeiro e já foram retirados nas operações 3 e 5."
     },
     {
      "letra": "B",
      "texto": "e a",
      "porque": "O a entrou antes dos dois e, então a ordem 'e a' é impossível. Além disso o a sai na 8ª operação."
     },
     {
      "letra": "C",
      "texto": "a",
      "porque": "O a é retirado na 8ª operação, então ele não está na fila no final. O que sobra é um e."
     },
     {
      "letra": "D",
      "texto": "b c a e",
      "porque": "O b e o c são retirados nas operações 3 e 5, então não estão no final."
     },
     {
      "letra": "E",
      "texto": "c a e",
      "porque": "O c sai na operação 5 e o a na operação 8, então não restam no final."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada pela banca. A simulação dá: [b], [b c], [c], [c a], [a], [a e], [a e e], [e e], [e]. O estado final é só 'e', que não aparece em nenhuma alternativa. Questão de fila: anote o estado depois de cada operação.",
    "assuntos": [
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Considere as seguintes árvores onde são apresentados apenas os valores das chaves em cada nó, sem mostrar o valor de outros campos eventualmente existentes. Considerando em todos os casos que as árvores não estão em processo de rotação por inserção de chaves, estando portanto em seu estado final após a inserção do conjunto de chaves mostrado.\n\nÉ CORRETO afirmar que:",
    "figuras": [
     "2017-024-q10-i",
     "2017-024-q10-ii",
     "2017-024-q10-iii",
     "2017-024-q10-iv"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a árvore do quadro I poderia ser uma árvore binária de pesquisa sem balanceamento",
      "porque": "Não só a I. A III e a IV também respeitam a regra da ABB em todos os nós (esquerda menor, direita maior)."
     },
     {
      "letra": "B",
      "texto": "Todas as 4 opções podem ser exemplos de árvores binárias de pesquisa sem balanceamento",
      "porque": "A II não é ABB: com as letras em ordem alfabética, B está à esquerda de A, mas o D (filho direito de B) fica na subárvore esquerda e D > A. O E, na subárvore esquerda de C, também é maior que C."
     },
     {
      "letra": "C",
      "texto": "Nenhuma das 4 opções pode ser uma árvore binária de pesquisa sem balanceamento",
      "porque": "I, III e IV são ABB válidas."
     },
     {
      "letra": "D",
      "texto": "Apenas as opções II e III podem de árvores binárias de pesquisa sem balanceamento",
      "porque": "A II não é ABB e a I e a IV são. A combinação está trocada."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores (de A até D) está correta",
      "porque": "Correta. I, III e IV são ABB, e a II (letras fora de ordem) não é. Isso não coincide com nenhuma das letras A a D."
     }
    ],
    "gabarito": "E",
    "resumo": "Gabarito oficial E. Teste a regra em todos os nós: tudo à esquerda é menor e tudo à direita é maior. I, III (o 13 fica à direita do 10 e à esquerda do 14) e IV passam. Na II, a árvore só seria ABB se as letras estivessem em ordem de percurso; com ordem alfabética, D (filho de B, à esquerda de A) é maior que A. Dica: verifique a subárvore inteira, não só pai e filho.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2017-024/figuras/q10-arvores.png"
    ]
   },
   {
    "numero": 11,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Sabendo que um arvore binária com 5 nós tem como resultados dos seus percursos pós-ordem e in-ordem, respectivamente S T Q R P e S Q T P R.\nÉ CORRETO afirmar:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O nó raiz tem o valor P",
      "porque": "Correta. A pós-ordem termina na raiz: o último é P. Na in-ordem, S Q T ficam à esquerda de P, e R à direita. Q tem S e T como filhos, e R é folha."
     },
     {
      "letra": "B",
      "texto": "Q é um nó folha",
      "porque": "Falso. Q tem filhos: S à esquerda e T à direita."
     },
     {
      "letra": "C",
      "texto": "S é um nó interno",
      "porque": "Falso. S é folha (não tem filhos)."
     },
     {
      "letra": "D",
      "texto": "T é filho de S",
      "porque": "Falso. T é filho de Q, irmão de S."
     },
     {
      "letra": "E",
      "texto": "Todas as alternativas estão corretas",
      "porque": "Só A está correta."
     }
    ],
    "gabarito": "A",
    "resumo": "Para reconstruir: o último da pós-ordem é a raiz (P). Na in-ordem, o que fica à esquerda de P forma a subárvore esquerda (S Q T) e à direita a subárvore direita (R). Repita: na pós-ordem S T Q, a raiz é Q, com S à esquerda e T à direita. Árvore: P(Q(S,T), R).",
    "assuntos": [
     {
      "num": "0098",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 6,
    "formato": "afirmações",
    "enunciado": "Sobre as afirmações abaixo:\n\nI. A busca sequencial só pode ser realizada corretamente em vetores que não estejam ordenados\nII. A busca por uma chave em um vetor ordenado pode ser realizada corretamente com número constante de operações, não dependendo do tamanho do vetor.\nIII. Pode-se encontrar o maior elemento de um vetor não ordenado com um algoritmo que realiza um número de operações proporcional ao tamanho do vetor na pior das situação possível para o algoritmo.\n\nPode-se dizer que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas I está correta",
      "porque": "I é falsa: a busca sequencial funciona em qualquer vetor, ordenado ou não."
     },
     {
      "letra": "B",
      "texto": "Apenas II está correta",
      "porque": "II é falsa: a busca binária faz O(log n), e o custo depende do tamanho, mesmo que cresça devagar."
     },
     {
      "letra": "C",
      "texto": "Apenas III está correta",
      "porque": "Correta. I falsa, II falsa. III é verdadeira: achar o maior de um vetor sem ordem exige varrer tudo, O(n)."
     },
     {
      "letra": "D",
      "texto": "Apenas II e III estão corretas",
      "porque": "II é falsa."
     },
     {
      "letra": "E",
      "texto": "Apenas I e III estão corretas",
      "porque": "I é falsa."
     }
    ],
    "gabarito": "C",
    "resumo": "I falsa (a sequencial vale em qualquer vetor), II falsa (busca em vetor ordenado é O(log n), não constante), III verdadeira (varredura linear para achar o máximo). 'Só pode' e 'constante' são pistas de afirmação falsa.",
    "assuntos": [
     {
      "num": "0089",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 3,
    "formato": "código",
    "enunciado": "Dada uma lista encadeada onde cada nó da lista é do tipo No, cujos campos são um ponteiro para o próximo elemento (campo prox) e um dado do tipo inteiro (campo dado). Considere que: (1) a lista encadeada não possui um nó cabeça de lista, portanto todos os nós contém valores presentes na lista; (2) todos os tipos de dados foram previamente declarados no programa; (3) a função não deve ter problemas de alocação de memória, seja por deixar de alocar dinamicamente dados necessários ou por causar alocação dinâmica de dados desnecessária.\n\nMarque a alternativa CORRETA sobre as funções função I e função II\n\n```c\n/* função I */\nvoid funcaoI(No *prim, int chave) {\n  No *aux = (No *) malloc(sizeof(No));\n  aux ->chave = chave;\n  aux->prox = prim;\n  prim = aux;\n}\n\n/* função II */\nvoid funcaoI(No **prim, int chave) {\n  No *aux = (No *) malloc(sizeof(No));\n  aux ->chave = chave;\n  aux->prox = *prim;\n  *prim = aux;\n}\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a função função I pode ser usada para inserir corretamente elementos em uma pilha sem gerar qualquer problema de alocação de memória ou erro na pilha.",
      "porque": "A I recebe `prim` por valor: a atribuição `prim = aux` muda só a cópia local. O topo da pilha não se altera fora da função, e o nó alocado vaza."
     },
     {
      "letra": "B",
      "texto": "Apenas a função função II pode ser usada para inserir corretamente elementos em uma pilha sem gerar qualquer problema de alocação de memória ou erro na pilha.",
      "porque": "Correta. A II recebe o endereço do ponteiro (`No **`) e atualiza `*prim`, então a mudança aparece para quem chamou. Empilhar é inserir no início da lista."
     },
     {
      "letra": "C",
      "texto": "Ambas as funções podem ser usadas para inserir elementos em uma pilha sem gerar qualquer problema de alocação de memória ou erro na pilha.",
      "porque": "A I não atualiza o topo de quem chamou e vaza memória."
     },
     {
      "letra": "D",
      "texto": "Apenas a função função I serve para inserir corretamente elementos em uma lista encadeada sem gerar erros, mas não em uma pilha.",
      "porque": "A I falha também para lista: inserir no início também precisa mudar o ponteiro de quem chamou."
     },
     {
      "letra": "E",
      "texto": "Apenas a função função II serve para inserir corretamente elementos em uma lista encadeada sem gerar erros, mas não em uma pilha.",
      "porque": "A II serve para a pilha também: push é inserção no início da lista."
     }
    ],
    "gabarito": "B",
    "resumo": "Em C, parâmetro é passado por valor. Para uma função mudar o ponteiro do início da lista, ela precisa receber o endereço dele (`No **`) e escrever em `*prim`. É o mesmo erro clássico do `remove` e do `insere`. Ignore o nome do campo (`chave` no código, `dado` no texto).",
    "assuntos": [
     {
      "num": "0083",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0049",
      "modulo": "06-ponteiros.md"
     },
     {
      "num": "0062",
      "modulo": "08-structs.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre um hash linear (sem encadeamento):\n\nI. No evento de uma colisão, o valor a ser inserido é sempre colocado no início do array;\nII. A busca pela chave é realizada utilizando busca binária (mais eficiente)\nIII. É obrigatório o uso de funções diferentes para inserção e remoção de chaves\nIV. É projetado para funcionar com arrays de tamanho previamente definido.\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas são verdadeiras",
      "porque": "Só a IV é verdadeira."
     },
     {
      "letra": "B",
      "texto": "Todas são falsas",
      "porque": "IV é verdadeira: o hash linear trabalha com um vetor de tamanho fixo definido de antemão."
     },
     {
      "letra": "C",
      "texto": "Apenas II e IV são verdadeiras",
      "porque": "II é falsa: a busca recalcula a posição pelo hash e sonda as seguintes, sem busca binária (a tabela nem fica ordenada)."
     },
     {
      "letra": "D",
      "texto": "Apenas IV é verdadeira",
      "porque": "Correta. I é falsa (a chave vai para a próxima posição livre, não para o início). II é falsa. III é falsa (a mesma função de hash serve para inserir e remover). IV é verdadeira."
     },
     {
      "letra": "E",
      "texto": "Apenas I e II são verdadeiras",
      "porque": "As duas são falsas."
     }
    ],
    "gabarito": "D",
    "resumo": "No hash linear, a colisão manda a chave para a próxima posição livre (sondagem), a busca recalcula o hash e sonda do mesmo jeito, e o vetor tem tamanho fixo. Isso torna IV a única verdadeira.",
    "assuntos": [
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre hash linear vs hash encadeado\n\nI. Para uma tabela hash de tamanho M, tanto o hash linear quanto o hash encadeado podem receber uma quantidade de chaves C, onde C > M.\nII. Quanto acontece uma colisão no hash encadeado, a chave é inserida na posição livre mais próxima da chave original.\nIII. Hash linear funciona melhor em disco, pois as chaves obrigatoriamente ficam em espaços separados de memória, facilitando a varredura.\nIV. O uso de uma segunda função de hash (no hash encadeado), garante um melhor espalhamento das chaves pela tabela hash\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas são verdadeiras",
      "porque": "As quatro são falsas."
     },
     {
      "letra": "B",
      "texto": "Todas são falsas",
      "porque": "Correta. I é falsa (o linear não aceita C > M). II descreve o hash linear, e não o encadeado. III é uma frase sem sentido (chaves 'obrigatoriamente em espaços separados' não ajuda varredura). IV descreve dispersão dupla, que é do endereçamento aberto, e não do encadeado."
     },
     {
      "letra": "C",
      "texto": "Apenas I e III são verdadeiras",
      "porque": "I é falsa para o linear, e III não faz sentido."
     },
     {
      "letra": "D",
      "texto": "Apenas III é verdadeira",
      "porque": "III é falsa."
     },
     {
      "letra": "E",
      "texto": "Apenas I e II são verdadeiras",
      "porque": "I é falsa para o linear, e II descreve o linear, não o encadeado."
     }
    ],
    "gabarito": "B",
    "resumo": "I falsa, II falsa (a 'posição livre mais próxima' é o linear), III sem sentido, IV falsa (segunda função de hash é a dispersão dupla, do endereçamento aberto). Em afirmações trocadas entre as duas técnicas, confira a que técnica cada propriedade pertence.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     },
     {
      "num": "0107",
      "modulo": "15-hash.md"
     },
     {
      "num": "0179",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Considere que o vetor a seguir é uma heap mínima (assuma índice do array iniciando em zero)\n\n`4 5 7 10 13 11 15 22`\n\nMarque a alternativa que contem a afirmativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Essa heap possui todos os nós folhas na mesma altura",
      "porque": "Falso. Os índices 4, 5, 6 são folhas no nível 2, e o índice 7 (22) é folha no nível 3."
     },
     {
      "letra": "B",
      "texto": "Ao alterar o valor 22 por 6, 2 trocas são necessárias para corrigir a heap",
      "porque": "Falso. O 6 no índice 7 tem pai 10 (índice 3): troca. Agora o pai é 5 (índice 1), e 6 > 5, então para. É uma troca só."
     },
     {
      "letra": "C",
      "texto": "O valor no índice 7 precisa ser necessariamente menor que o do índice 4",
      "porque": "Falso. Os índices 7 e 4 estão em ramos diferentes (7 desce de 3, e 4 é irmão de 3). Heap mínima só compara pai e filho."
     },
     {
      "letra": "D",
      "texto": "O valor no índice 6 precisa ser obrigatoriamente maior que o do índice 1",
      "porque": "Falso. O índice 6 é descendente do índice 2, e não do 1. Sem relação direta."
     },
     {
      "letra": "E",
      "texto": "Ao alterar o valor 13 por 8, nada precisa ser feito para corrigir a heap",
      "porque": "Correta. O índice 4 é folha e seu pai (índice 1) vale 5. Como 8 > 5, a regra da heap mínima continua valendo."
     }
    ],
    "gabarito": "E",
    "resumo": "Em heap mínima (índices de 0): o pai de i é (i-1)/2, e a única regra é pai menor ou igual aos filhos. Mudou um valor: compare só com o pai (e com os filhos, se houver). Troca de 13 por 8: folha, pai 5, 8 > 5, nada a fazer.",
    "assuntos": [
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 17,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "As árvores são estruturas de dados poderosas e se subdividem em vários tipos, cada um dos quais com suas características próprias. Relacione os tipos de árvores, apresentados na coluna da esquerda, com as suas respectivas características, indicadas na coluna da direita:\n\n| Tipo de árvore | Característica |\n|---|---|\n| I – Heap | W – Pode degenerar se os elementos forem inseridos de forma ordenada. |\n| II – Rubro-Negra | X – É balanceada. |\n| III – Avore AVL | Y – Têm altura sempre proporcional/próxima a O(log2 n), onde n é o número de nós que contém. |\n| IV – Árvores binária de busca | Z – São sempre completas. |\n\nEstão CORRETAS as associações:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I –X, IV – Z , II – Y",
      "porque": "IV (ABB) – Z está errada: a ABB comum pode degenerar e não é sempre completa."
     },
     {
      "letra": "B",
      "texto": "I – Z , IV– X , III – W",
      "porque": "IV – X e III – W estão trocadas: a ABB é quem degenera (W), e a AVL é balanceada."
     },
     {
      "letra": "C",
      "texto": "I – Z , IV– X , III – Y",
      "porque": "IV – X está errada: a ABB sem balanceamento não é balanceada."
     },
     {
      "letra": "D",
      "texto": "I –Y , IV– W , III – X",
      "porque": "Defensável: heap tem altura O(log n), ABB degenera e AVL é balanceada. Falta só o par canônico I – Z (heap é completa)."
     },
     {
      "letra": "E",
      "texto": "I –X , IV– W , II – Y",
      "porque": "Também defensável: heap é balanceada, ABB degenera, rubro-negra tem altura O(log n). Como D e E se sustentam, a banca anulou."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada pela banca. W é da ABB (degenera com chaves em ordem), Z é da heap (árvore completa), e X e Y servem para AVL e rubro-negra. Como o par canônico I – Z não aparece junto com IV – W, as letras D e E ficam ambas defensáveis.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0177",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2017-024/figuras/q17-quadro.png"
    ]
   },
   {
    "numero": 18,
    "topico": 3,
    "formato": "código",
    "enunciado": "Considere o código abaixo, assumindo que o mesmo é usado dentro de um programa e que os todos os cabeçalhos necessários são incluídos:\n\n```c\n// Conta ocorrências de uma chave na lista encadeada, retornando o total de ocorrências , zero caso a chave não ocorra\nint ContaOcorrenciasChave(tipoNo *prim, int chave) {\n  tipoNo *aux = prim;\n  int cont = 0;\n  int x;\n  for (x = 0; aux[x] != NULL; x++){\n    if(aux[x].dado == chave)\n      cont++;\n  }\n  return x;\n}\n```\n\nMarque a alternativa CORRETA dentre as afirmações abaixo:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O código executa a tarefas proposta sem gerar qualquer tipo de erro de lógica ou de vazamento de memória",
      "porque": "O código percorre lista como vetor e devolve `x` (posições percorridas) no lugar de `cont`."
     },
     {
      "letra": "B",
      "texto": "O código nem compila",
      "porque": "Na prática o compilador rejeita `aux[x] != NULL` (struct comparada com ponteiro). A banca, porém, tratou o erro como de lógica e execução, e marcou E."
     },
     {
      "letra": "C",
      "texto": "O código executa a tarefa proposta sem erros de lógica",
      "porque": "Há erros: o retorno é `x` e não `cont`, e a lista é percorrida por índice em vez de `prox`."
     },
     {
      "letra": "D",
      "texto": "O código não gera erro de segmentação",
      "porque": "Ler `aux[x]` além do primeiro nó acessa memória que não é da lista, e pode derrubar o programa."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Correta pelo gabarito: nenhuma das letras A a D descreve o código de forma aceita pela banca."
     }
    ],
    "gabarito": "E",
    "resumo": "Gabarito oficial E. Divergência: o curso tinha chegado em B, e de fato o gcc recusa `aux[x] != NULL` (struct contra ponteiro). A banca preferiu E, lendo o código como uma lista tratada como vetor, com retorno `x` em vez de `cont`. Em prova, o essencial: lista encadeada se percorre por `prox`, nunca por índice.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0077",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Uma lista encadeada simples é uma estrutura que corresponde a uma sequência lógica de entradas ou nós. Cada nó armazena a localização do próximo elemento na sequência, ou seja, de seu nó sucessor.\n\nMarque a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "A existência de um ponteiro apontando para o 1º elemento e outro para o fim da lista permite que a inserção ou deleção de dados de um nó que esteja nas extremidades da lista seja rapidamente executada",
      "porque": "Correta. Com ponteiros para o início e para o fim, inserir nas pontas é O(1), sem percorrer a lista. É essa a vantagem que a alternativa descreve. Remover do fim, na lista simples, ainda exige achar o penúltimo nó."
     },
     {
      "letra": "B",
      "texto": "Enquanto a entrada que determina o topo da lista é mantida em um nó descritor dessa lista, a entrada que marca o fim da lista é mantida em todos os nós da lista.",
      "porque": "O fim não é guardado em todos os nós. Cada nó guarda só o ponteiro para o próximo."
     },
     {
      "letra": "C",
      "texto": "O armazenamento de uma lista requer uma área contígua de memória para permitir a otimização no processamento de busca de valores chaves na lista",
      "porque": "Lista encadeada não é contígua. Quem usa memória contígua é o vetor."
     },
     {
      "letra": "D",
      "texto": "O armazenamento de uma lista requer uma área contígua de memória. Como listas são estruturas previamente projetadas e definidas, normalmente são definidos procedimentos que permitem inserir e remover valores com eficiência.",
      "porque": "Mesmo erro: lista encadeada dinâmica não precisa de área contígua."
     },
     {
      "letra": "E",
      "texto": "Para estabelecer a ligação entre um nó já pertencente a uma lista e um novo nó, basta fazer com que o novo nó referencie no campo next, o nó que anteriormente era referenciado pelo nó original, desde que esse campo não tenha o valor nulo",
      "porque": "Está incompleta: também é preciso fazer o nó original apontar para o novo. O 'desde que não seja nulo' também não é condição: inserir no fim (campo nulo) funciona."
     }
    ],
    "gabarito": "A",
    "resumo": "Guardar o ponteiro do início e do fim da lista dá inserção em O(1) nas duas pontas (e remoção no início). As demais letras mentem sobre memória contígua, que é característica de vetor, não de lista encadeada.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Marque a alternativa CORRETA. Uma lista duplamente encadeada tem como característica ser formada por elementos que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Se concatenam de forma circular, de tal maneira que, ao chegar ao final da lista, o próximo elemento volta a ser o primeiro.",
      "porque": "Descreve lista circular."
     },
     {
      "letra": "B",
      "texto": "Contêm, além de um ou mais campos chave, mais um campo de ponteiro: o próximo, que permite o acesso ao elemento que sucede o atual (o próximo) presente na mesma lista.",
      "porque": "Descreve lista simplesmente encadeada (um só ponteiro)."
     },
     {
      "letra": "C",
      "texto": "Contêm, além de um campo chave, mais um campo de ponteiro: o próximo, que permite o acesso ao elemento que sucede o atual (o próximo) presente na mesma lista, de tal forma que os campos chave estão ordenados, ou seja, a chave do próximo é sempre maior ou igual à chave do atual elemento.",
      "porque": "Descreve lista simples e ordenada."
     },
     {
      "letra": "D",
      "texto": "Contêm, além de um ou mais campos chave, dois outros campos de ponteiros: próximo e anterior, que permitem o acesso aos elementos adjacentes (próximo e anterior) presentes na mesma lista.",
      "porque": "Correta. Dois ponteiros por nó, `prox` e `ant`, e o percurso nos dois sentidos."
     },
     {
      "letra": "E",
      "texto": "Estão em posições adjacentes da memória, permitindo o acesso sequencial ao próximo e ao anterior de cada elemento pelo simples uso de um índice.",
      "porque": "Descreve vetor, não lista encadeada."
     }
    ],
    "gabarito": "D",
    "resumo": "Mesma questão da prova 053/2016 (Q06). Lista dupla = `prox` e `ant` em cada nó. Alternativas que falam em circular, ordenada ou memória contígua descrevem outras coisas.",
    "assuntos": [
     {
      "num": "0079",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "055/2017",
  "slug": "2017-055",
  "ano": 2017,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": 1,
    "formato": "simulação",
    "enunciado": "Considere a função em pseudocódigo a seguir:\n\n```\n1 Função Chamada_recursiva (inteiro k)\n2   Imprimir k;\n3   Se (k > 0)\n4     Retornar Chamada_recursiva (k - Chamada_recursiva (Chamada_recursiva (k - 1)));\n5   Senão\n6     Retornar 3;\n```\n\nMarque a alternativa CORRETA.\nA execução da função Chamada_recursiva(1) faz com que o algoritmo execute indefinidamente. Para este caso, os cinco primeiros valores impressos são:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "1, 0, 3, 1 e 0.",
      "porque": "O quarto valor impresso é 2, não 1. Depois do 3, a chamada Chamada_recursiva(3) imprime 3 e entra em Chamada_recursiva(2), que imprime 2."
     },
     {
      "letra": "B",
      "texto": "1, 0, 3, 1 e 2.",
      "porque": "O quarto valor é 2 e o quinto é 1. Você inverteu a ordem: Chamada_recursiva(2) imprime 2 ao entrar e só depois chama Chamada_recursiva(1), que imprime 1."
     },
     {
      "letra": "C",
      "texto": "1, 0, 3, 2 e 0.",
      "porque": "Os quatro primeiros batem, mas o quinto é 1. Chamada_recursiva(2) chama Chamada_recursiva(1) antes de qualquer Chamada_recursiva(0), e essa chamada imprime 1."
     },
     {
      "letra": "D",
      "texto": "1, 0, 3, 2 e 3.",
      "porque": "O quinto valor não é 3. O 3 só reaparece depois, quando uma chamada com k = 0 retornar. Antes disso a recursão desce por k = 1 e imprime 1."
     },
     {
      "letra": "E",
      "texto": "1, 0, 3, 2 e 1.",
      "porque": "Correta. Chamada_recursiva(1) imprime 1 e avalia o argumento mais interno, Chamada_recursiva(0): imprime 0 e retorna 3. Depois vem Chamada_recursiva(3): imprime 3 e avalia Chamada_recursiva(2): imprime 2 e avalia Chamada_recursiva(1): imprime 1. A partir daí o padrão recomeça, por isso nunca termina."
     }
    ],
    "gabarito": "E",
    "resumo": "Em recursão aninhada, resolva os argumentos de dentro para fora e anote cada impressão na ordem em que a função é chamada, porque o `Imprimir k` vem antes do teste. Rodei a função e a saída é 1, 0, 3, 2, 1. A figura do caderno não veio no texto extraído, mas o PNG confirma o pseudocódigo.",
    "assuntos": [
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2017-055/figuras/q01-pseudocodigo.png"
    ]
   },
   {
    "numero": 2,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Marque a alternativa INCORRETA.\nEstrutura de Dados básicas como Fila são tipicamente usadas em uma gama variada de aplicações computacionais, EXCETO:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Sequência de trabalhos submetidas à impressora compartilhada em rede de computadores, onde o primeiro trabalho recebido será o primeiro trabalho a ter sua solicitação atendida.",
      "porque": "É o exemplo clássico de fila: o primeiro a chegar é o primeiro a sair (FIFO)."
     },
     {
      "letra": "B",
      "texto": "Fila de processos de comunicação em redes de computadores.",
      "porque": "Pacotes e processos esperam sua vez por ordem de chegada, então é uso típico de fila."
     },
     {
      "letra": "C",
      "texto": "Estruturas hierárquicas de diretórios e subdiretórios.",
      "porque": "Esta é a exceção, logo é a resposta. Diretórios dentro de diretórios formam uma hierarquia com pai e filhos, que é uma árvore. Fila é linear e não representa hierarquia."
     },
     {
      "letra": "D",
      "texto": "Buffer para gravação de dados em mídia.",
      "porque": "O buffer guarda os dados na ordem em que chegaram e grava na mesma ordem, o que é uma fila."
     },
     {
      "letra": "E",
      "texto": "Atendimento de processos requisitados ao um sistema operacional.",
      "porque": "O escalonador mantém filas de processos prontos ou esperando recursos, então é uso típico de fila."
     }
    ],
    "gabarito": "C",
    "resumo": "O enunciado mistura 'INCORRETA' com 'EXCETO', mas o que se pede é o item que não é aplicação de fila. Associe fila a 'esperar a vez' (impressora, buffer, escalonador) e hierarquia a árvore. Nas provas da banca esse par fila x árvore se repete.",
    "assuntos": [
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0086",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Suponha que se tem números entre 1 e 1000 em uma Árvore Binária de Busca e se quer procurar pelo número 363. Qual das afirmativas a seguir não poderia ser a sequência de nós examinados?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "2, 252, 401, 398, 330, 344, 397, 363.",
      "porque": "Possível. Após o 401 vai à esquerda (intervalo 252 a 401), após o 398 à esquerda, após o 330 à direita, após o 344 à direita (intervalo 344 a 398), e o 397 cabe nele. Depois à esquerda até o 363."
     },
     {
      "letra": "B",
      "texto": "924, 220, 911, 244, 898, 258, 362, 363.",
      "porque": "Possível. Todos os nós cabem no intervalo aberto pelos anteriores: 911 em (220, 924), 244 em (220, 911), 898 em (244, 911), 258 em (244, 898) e 362 em (258, 898)."
     },
     {
      "letra": "C",
      "texto": "925, 202, 911, 240, 912, 245, 363.",
      "porque": "Impossível. Depois de 911, o 363 vai à esquerda, então tudo o que vem depois está abaixo de 911. O 912 é maior que 911 e não pode aparecer no caminho. Por isso a banca teve duas impossíveis e anulou."
     },
     {
      "letra": "D",
      "texto": "2, 399, 387, 219, 266, 382, 381, 278, 363.",
      "porque": "Possível. Cada nó respeita o intervalo: 219 em (2, 387), 266 em (219, 387), 382 em (266, 387), 381 em (266, 382) e 278 em (266, 381)."
     },
     {
      "letra": "E",
      "texto": "935, 278, 347, 621, 299, 392, 358, 363.",
      "porque": "Também impossível. O 363 é maior que 347, então a busca vai à direita e todos os próximos nós são maiores que 347. O 299 viola isso. É o mesmo problema da C, por isso a questão foi anulada."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Para validar um caminho de busca em ABB, mantenha o intervalo (mínimo, máximo) que cada decisão impõe: ao ir à esquerda de x, o máximo vira x, e ao ir à direita, o mínimo vira x. Um nó fora do intervalo invalida a sequência. A banca anulou porque C e E são ambas impossíveis (é o exercício 12.2-1 do Cormen, que também tem as duas). Na 061/2018 a questão volta com a E corrigida e a resposta é C.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Observe a árvore binária de pesquisa sem balanceamento:\n\nConsidere as afirmativas a seguir.\n\nI. Os nós 6 e 8 são irmãos.\nII. O nó 4 é uma das raízes da árvore.\nIII. O nó com valor 3, ao ser inserido, ocuparia a posição iv.\nIV. O nó com valor 1, ao ser inserido, ocuparia a posição i.\n\nMarque a alternativa CORRETA:",
    "figuras": [
     "2017-055-q04"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a afirmativa III está correta.",
      "porque": "Propõe só a III, mas ela é falsa: o 3 vai à direita do 2, à esquerda do 4, e fica na posição ii, não na iv. Além disso I e IV são verdadeiras e ficaram de fora."
     },
     {
      "letra": "B",
      "texto": "Apenas as afirmativas I e IV estão corretas.",
      "porque": "Correta. I: 6 e 8 são filhos do 7, logo irmãos. IV: o 1 é menor que 5 e que 2, então ocupa a posição i. II e III são falsas."
     },
     {
      "letra": "C",
      "texto": "Apenas as afirmativas II e III estão corretas.",
      "porque": "As duas são falsas. Uma árvore tem uma única raiz (o 5), e o 4 é só a raiz de uma subárvore. O 3 ocuparia a posição ii."
     },
     {
      "letra": "D",
      "texto": "Apenas as afirmativas I, II e IV estão corretas.",
      "porque": "Acerta I e IV, mas inclui a II, que é falsa: só existe uma raiz."
     },
     {
      "letra": "E",
      "texto": "Todas as afirmativas estão corretas.",
      "porque": "II e III são falsas, então não são todas."
     }
    ],
    "gabarito": "B",
    "resumo": "Valores: I verdadeira, II falsa, III falsa, IV verdadeira. Para achar a posição de uma chave nova, desça comparando: o 3 vai 5 (esquerda), 2 (direita), 4 (esquerda), caindo em ii. Os pontos i a vii são só lugares vazios; a árvore tem uma raiz só.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2017-055/figuras/q04-arvore.png"
    ]
   },
   {
    "numero": 5,
    "topico": 5,
    "formato": "conceito",
    "enunciado": "Quando um algoritmo de hash produz um endereço para uma chave e esse endereço já está ocupado, isso é chamado de __________.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Sinônimo",
      "porque": "Sinônimos são as chaves distintas que a função leva ao mesmo endereço. O nome descreve as chaves, não o evento de achar o endereço ocupado."
     },
     {
      "letra": "B",
      "texto": "Inicial",
      "porque": "Não é um termo de hashing."
     },
     {
      "letra": "C",
      "texto": "Prospecção",
      "porque": "Prospecção (sondagem) é a busca por outro endereço livre, que é a resposta à colisão, e não a colisão em si."
     },
     {
      "letra": "D",
      "texto": "Colisão",
      "porque": "Correta. Colisão é duas chaves diferentes caírem no mesmo endereço, ou seja, o endereço calculado já está ocupado."
     },
     {
      "letra": "E",
      "texto": "Overflow",
      "porque": "Overflow é estouro de capacidade (tabela ou balde cheio). Uma colisão pode acontecer com a tabela quase vazia."
     }
    ],
    "gabarito": "D",
    "resumo": "Colisão é o evento: a função de hash devolve um endereço já usado. O que você faz depois (sondagem, encadeamento) é o tratamento de colisão. Questão de vocabulário, cai sempre.",
    "assuntos": [
     {
      "num": "0105",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 5,
    "formato": "cálculo",
    "enunciado": "Considere uma tabela hash com resolução de colisões por encadeamento com as seguintes características:\n\n- As chaves são as letras A,B,C,D,H,J,K,M,N,O,P,R,S,T,U;\n- A tabela possui 11 posições, referenciadas pelos índices de 0 até 10;\n- A função de hash é definida como hash(x)=posição(x) mod 11, onde x é a chave, e posição(x) é a posição da chave no alfabeto ABCDEFGHIJKLMNOPQRSTUVWXYZ, tal que posição(\"A\") retorna 1 e posição(\"Z\") retorna 26.\n\nAnalise as afirmativas sobre a tabela após seu preenchimento com as chaves listadas acima.\n\nI. Nenhuma chave foi alocada à posição 6;\nII. A chave \"K\" foi alocada à posição zero;\nIII. As chaves \"B\" e \"N\" colidiram na posição 3;\nIV. Apenas uma letra foi alocada à posição 9.\n\nCom base nessas afirmativas, marque a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas as afirmativas I e II estão corretas.",
      "porque": "Omite a IV, que também é verdadeira: só o T (posição 20, 20 mod 11 = 9) vai para a posição 9."
     },
     {
      "letra": "B",
      "texto": "Apenas as afirmativas I e IV estão corretas.",
      "porque": "Omite a II, que é verdadeira: K é a 11ª letra e 11 mod 11 = 0."
     },
     {
      "letra": "C",
      "texto": "Apenas as afirmativas I, II e IV estão corretas.",
      "porque": "Correta. I, II e IV são verdadeiras e a III é falsa."
     },
     {
      "letra": "D",
      "texto": "Apenas as afirmativas II e III.",
      "porque": "A III é falsa e ainda faltam a I e a IV, que são verdadeiras."
     },
     {
      "letra": "E",
      "texto": "Apenas as afirmativas II, III e IV estão corretas.",
      "porque": "Inclui a III, que é falsa, e omite a I."
     }
    ],
    "gabarito": "C",
    "resumo": "Calcule posição mod 11 para cada letra: A1, B2, C3, D4, H8, J10, K0, M2, N3, O4, P5, R7, S8, T9, U10. Nada cai em 6 (I verdadeira), K vai a 0 (II verdadeira), T está sozinho no 9 (IV verdadeira). III é falsa: B vai a 2 (com M) e N vai a 3 (com C), então B e N não colidem. Em afirmações assim, tabele tudo antes de julgar.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Marque a alternativa CORRETA.\nSuponha que T seja uma árvore binária de pesquisa sem balanceamento inicialmente vazia, e considere a inserção dos elementos 30, 50, 60, 20, 40, 10 e 25 em T, exatamente nessa ordem. Qual das sequências abaixo corresponde a um percurso de T em pré-ordem?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "30 50 60 40 20 25 10",
      "porque": "Começa pela raiz certa, mas visita a subárvore direita (50) antes da esquerda (20). A pré-ordem visita a esquerda primeiro."
     },
     {
      "letra": "B",
      "texto": "10 25 20 40 60 50 30",
      "porque": "É a pós-ordem: esquerda, direita, raiz. Termina na raiz 30."
     },
     {
      "letra": "C",
      "texto": "10 20 25 30 40 50 60",
      "porque": "É a ordem simétrica (em ordem): sai crescente, porque a árvore é de busca."
     },
     {
      "letra": "D",
      "texto": "30 20 10 25 50 40 60",
      "porque": "Correta. A árvore fica com raiz 30, esquerda 20 (filhos 10 e 25) e direita 50 (filhos 40 e 60). Pré-ordem: raiz, esquerda inteira, direita inteira."
     },
     {
      "letra": "E",
      "texto": "60 50 40 30 25 20 10",
      "porque": "É a ordem simétrica invertida (decrescente), não uma pré-ordem."
     }
    ],
    "gabarito": "D",
    "resumo": "Monte a árvore inserindo na ordem dada e só depois escolha o percurso. Pré-ordem começa pela raiz; pós-ordem termina nela; em ordem devolve as chaves ordenadas. Identificar cada sequência pelo formato elimina as alternativas sem desenhar nada.",
    "assuntos": [
     {
      "num": "0098",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 6,
    "formato": "cálculo",
    "enunciado": "Marque a alternativa CORRETA.\nConsiderando um array R que contém 1.000.000 de chaves ordenadas, assinale o número máximo de acessos a R necessários para encontrar uma determinada chave ao se utilizar o algoritmo de busca binária.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "10",
      "porque": "Isso serve para cerca de 1.000 elementos (2^10 = 1024), não para um milhão."
     },
     {
      "letra": "B",
      "texto": "20",
      "porque": "Correta. A busca binária faz no máximo floor(log2 n) + 1 acessos. Como 2^19 = 524.288 e 2^20 = 1.048.576, log2 de 1.000.000 está entre 19 e 20, e o máximo é 19 + 1 = 20."
     },
     {
      "letra": "C",
      "texto": "40",
      "porque": "É o dobro do necessário. Cada acesso corta o intervalo pela metade, então 20 bastam."
     },
     {
      "letra": "D",
      "texto": "80",
      "porque": "Muito acima do limite: a busca binária nunca precisa de tantos acessos para um milhão de chaves."
     },
     {
      "letra": "E",
      "texto": "160",
      "porque": "Também muito acima. O limite é logarítmico, não proporcional a n."
     }
    ],
    "gabarito": "B",
    "resumo": "Máximo de comparações da busca binária em n elementos: floor(log2 n) + 1. Decore as potências: 2^10 ≈ mil, 2^20 ≈ um milhão. Daí um milhão dá 20.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Para remoção de uma chave cuja página esteja com o número mínimo, em árvore B, é CORRETO afirmar que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Deve-se fazer o processo de SPLIT sempre na página onde se encontrar a chave.",
      "porque": "Split é da inserção (página cheia que se divide). Na remoção o processo é de redistribuição ou concatenação."
     },
     {
      "letra": "B",
      "texto": "Deve-se fazer o processo de SPLIT na página onde se encontrar a chave, exceto quanto é um elemento da raiz da árvore.",
      "porque": "Mesmo erro da A: remoção não usa split, nem fora da raiz."
     },
     {
      "letra": "C",
      "texto": "Se a página onde se encontrar a chave não é folha, deve-se fazer procedimento de concatenação ou redistribuição, considerando os irmãos.",
      "porque": "Em nó interno, a chave é trocada pela sucessora (ou antecessora) de uma folha, e a redistribuição ou concatenação acontece depois, na folha que ficou abaixo do mínimo. Dizer que o procedimento é feito na página não folha é impreciso."
     },
     {
      "letra": "D",
      "texto": "Remove-se a chave, e a substitui por uma chave do nó irmão.",
      "porque": "A redistribuição passa pelo nó pai: a chave do pai desce e uma chave do irmão sobe. Trocar direto pela do irmão quebra a ordem das chaves."
     },
     {
      "letra": "E",
      "texto": "No caso de só haver uma única página, a remoção não causa a necessidade de balanceamento.",
      "porque": "É a afirmação correta na teoria: a raiz é a única página que pode ter menos que o mínimo de chaves, então remover dela não exige redistribuir nem concatenar. A banca anulou a questão mesmo assim."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Remoção em árvore B: tirar a chave; se a página cair abaixo do mínimo, redistribua com um irmão ou concatene; split é coisa da inserção; a raiz pode ter menos que o mínimo. A banca anulou, então não conte com ela, mas a E é a que a teoria sustenta. A mesma questão volta na 061/2018 (Q11) com gabarito E.",
    "assuntos": [
     {
      "num": "0146",
      "modulo": "22-arvores-avancadas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Sobre árvores B e árvores binárias, analise as afirmativas e assinale a alternativa CORRETA.\n\nI. De forma diferente das árvores binárias, cada nó de uma árvore B deverá sempre ter mais de dois filhos.\nII. Um nó de árvore B tem um campo ou um método para indicar se é um nó folha ou não. Característica esta herdada da AVL.\nIII. As folhas da árvore B são dispostas mais flexivelmente que as da árvore binária: suas folhas poderão estar em níveis diferentes, desde zero até o valor da altura da árvore.\nIV. A árvore B tem um método de balanceamento muito custoso, por isso, sua indicação para trabalhar com dispositivos de armazenamento secundário deve ser avaliada com muita cautela.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas as afirmativas estão corretas.",
      "porque": "As quatro são falsas."
     },
     {
      "letra": "B",
      "texto": "Somente as afirmativas II e III estão corretas",
      "porque": "II e III são falsas: o campo de folha não vem da AVL, e as folhas da árvore B ficam todas no mesmo nível."
     },
     {
      "letra": "C",
      "texto": "Somente as afirmativas I, II e IV estão corretas.",
      "porque": "Todas as três são falsas, e é a combinação que a banca esperava descartar."
     },
     {
      "letra": "D",
      "texto": "Somente as afirmativas I, III e IV estão corretas.",
      "porque": "Mesmo caso: I, III e IV são falsas."
     },
     {
      "letra": "E",
      "texto": "Todas as afirmativas estão incorretas",
      "porque": "Coerente com a teoria: I falsa (um nó pode ter 2 filhos, e a raiz sempre pode), II falsa (a AVL não tem esse campo), III falsa (todas as folhas ficam no mesmo nível), IV falsa (o balanceamento é barato, só split e concatenação locais, e árvore B existe justamente para disco). A banca anulou mesmo assim."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Valores: I falsa, II falsa, III falsa, IV falsa. A ideia: árvore B tem folhas todas no mesmo nível, nós com entre ⌈m/2⌉ e m filhos (a raiz pode ter 2) e balanceamento local; foi feita para armazenamento secundário. A banca anulou, e na 061/2018 (Q14) a mesma questão tem gabarito E, 'todas incorretas'.",
    "assuntos": [
     {
      "num": "0146",
      "modulo": "22-arvores-avancadas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 11,
    "topico": 3,
    "formato": "afirmações",
    "enunciado": "Considere as seguintes afirmações sobre a estrutura lista encadeada dinâmica\n\nI. A busca em tal estrutura realiza menos comparações do que a melhor opção de algoritmo de busca em um vetor ordenado quando se considera o pior cenário para cada estrutura.\nII. É uma estrutura de dados usada unicamente no armazenamento de grandes quantidades de chaves por lista, dado o seu dinamismo e velocidade de busca quando comparada a outras estruturas de dados.\nIII. É utilizada como estrutura de dados na implementação de alguns tipos de hash.\n\nMarque a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "As três afirmações são falsas",
      "porque": "A III é verdadeira: o hash por encadeamento guarda uma lista em cada posição."
     },
     {
      "letra": "B",
      "texto": "Apenas a afirmação I é verdadeira",
      "porque": "A I é falsa. A lista encadeada precisa de até n comparações no pior caso; a busca binária num vetor ordenado faz no máximo cerca de log2 n."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmação II é verdadeira",
      "porque": "A II é falsa: 'unicamente' é exagero, e a lista não é rápida na busca (é O(n))."
     },
     {
      "letra": "D",
      "texto": "Apenas a afirmação III é verdadeira",
      "porque": "Correta. I e II são falsas e a III vale: o encadeamento do hash usa listas para guardar as chaves que colidem."
     },
     {
      "letra": "E",
      "texto": "Apenas as afirmações I e II são verdadeiras",
      "porque": "Ambas são falsas pelos motivos acima."
     }
    ],
    "gabarito": "D",
    "resumo": "Valores: I falsa (lista é O(n), vetor ordenado com busca binária é O(log n)), II falsa ('unicamente' e 'velocidade de busca'), III verdadeira. Palavras absolutas como 'unicamente', 'sempre' e 'nunca' costumam denunciar a afirmação falsa.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 7,
    "formato": "cálculo",
    "enunciado": "Qual dos algoritmos abaixo apresenta o menor custo (em termos de número comparações entre elementos) ao considerar-se que o vetor passado está previamente ordenado, a menos da ocorrência de duas chaves consecutivas que estão com posições trocadas. Considere que o vetor a ser ordenado é muito grande, com mais de 1 milhão de elementos.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Heapsort.",
      "porque": "Heapsort faz da ordem de n log n comparações mesmo com o vetor quase ordenado: ele não aproveita a ordem existente."
     },
     {
      "letra": "B",
      "texto": "Quicksort.",
      "porque": "Costuma fazer cerca de n log n comparações e, com pivô ruim num vetor quase ordenado (por exemplo, o primeiro elemento), degenera para n²."
     },
     {
      "letra": "C",
      "texto": "Inserção.",
      "porque": "Correta. A inserção só anda para trás enquanto o elemento é menor que o anterior. Num vetor quase ordenado cada elemento faz uma comparação, e só o par trocado faz uma a mais: cerca de n comparações."
     },
     {
      "letra": "D",
      "texto": "Seleção.",
      "porque": "Sempre faz da ordem de n² comparações para achar o menor de cada rodada, ordenado ou não."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das anteriores, pois todos apresentam custo igual.",
      "porque": "Os custos são bem diferentes: n para a inserção contra n log n ou n²."
     }
    ],
    "gabarito": "C",
    "resumo": "Vetor quase ordenado é o melhor caso da inserção (O(n)). Heapsort e seleção não dependem da ordem inicial; o quicksort depende e pode até piorar. Palavra-chave do enunciado: 'previamente ordenado, a menos de'.",
    "assuntos": [
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Marque a alternativa CORRETA.\nConsiderando-se para cada algoritmo o pior cenário possível em termos de uso de espaço, são algoritmos que utilizam espaço extra constante, independentemente do número de elementos do vetor de entrada a ser ordenado:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Mergesort e Seleção.",
      "porque": "A seleção é in-place (espaço O(1)), mas o mergesort precisa de um vetor auxiliar de tamanho n."
     },
     {
      "letra": "B",
      "texto": "Quicksort e Mergesort.",
      "porque": "Nenhum dos dois é O(1): o mergesort usa vetor auxiliar e o quicksort usa pilha de recursão, que no pior caso chega a n."
     },
     {
      "letra": "C",
      "texto": "Mergesort e Heapsort.",
      "porque": "O heapsort é O(1) de espaço, mas o mergesort não."
     },
     {
      "letra": "D",
      "texto": "Inserção e Quicksort.",
      "porque": "A inserção é O(1), mas o quicksort, no pior caso de espaço, empilha até n chamadas."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas acima está correta.",
      "porque": "Correta. Os algoritmos com espaço extra constante são seleção, inserção e heapsort, e as alternativas A a D sempre misturam um deles com mergesort ou quicksort. O quicksort conta como não constante por causa da pilha de recursão (padrão do Cormen)."
     }
    ],
    "gabarito": "E",
    "resumo": "Espaço extra O(1) no pior caso: seleção, inserção, heapsort (todos in-place sem recursão). Mergesort usa O(n) de vetor auxiliar; quicksort usa pilha de recursão que chega a O(n) no pior caso. Cada alternativa mistura um bom com um ruim, e sobra a E.",
    "assuntos": [
     {
      "num": "0168",
      "modulo": "26-analise-formal.md"
     },
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0103",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0094",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 6,
    "formato": "afirmações",
    "enunciado": "Sobre as afirmações abaixo:\n\nI. Pode-se implementar uma busca em um vetor não ordenado a custo máximo inferior a n/2 operações, onde n é o número de elementos do vetor, desde que a chave buscada ocorra no vetor, não importando qual a posição em que a mesma ocorre.\nII. A busca por uma chave em um vetor ordenado pode ser realizada corretamente com um número de operações proporcional a log2 n, onde n é o número de elementos do vetor.\nIII. O número de comparações realizadas para determinar se uma chave de busca está ou não em um vetor não ordenado é sempre menor do que o número de comparações envolvendo a mesma chave de busca em uma lista encadeada dinâmica, desde que a quantidade e a ordem dos elementos inseridos nas duas estruturas seja a mesma.\n\nMarque a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a afirmativa I está correta.",
      "porque": "A I é falsa. Sem ordem, a chave pode estar na última posição, e o pior caso é n comparações, não menos que n/2."
     },
     {
      "letra": "B",
      "texto": "Apenas a afirmativa II está correta.",
      "porque": "Correta. Em vetor ordenado a busca binária faz da ordem de log2 n operações. I e III são falsas."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmativa III está correta.",
      "porque": "A III é falsa: com os mesmos elementos na mesma ordem, a busca sequencial faz exatamente as mesmas comparações no vetor e na lista."
     },
     {
      "letra": "D",
      "texto": "Todas as afirmativas estão corretas.",
      "porque": "I e III são falsas."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das afirmativas está corretas.",
      "porque": "A II é verdadeira."
     }
    ],
    "gabarito": "B",
    "resumo": "Valores: I falsa (pior caso n), II verdadeira, III falsa (mesma ordem, mesma varredura, mesmo número de comparações). Busca em estrutura sem ordem é sempre O(n) no pior caso, seja vetor ou lista.",
    "assuntos": [
     {
      "num": "0089",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as seguintes afirmações:\n\nI. Hash por encadeamento pode apresentar colisões secundárias.\nII. Hash por encadeamento pode permitir que o número de comparações entre chaves em uma operação de busca passe de √n, onde n é o número de chaves inseridas no hash.\nIII. Hash por endereçamento aberto realiza sempre menos comparações entre chaves do que qualquer hash por encadeamento.\n\nMarque a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a afirmação I é verdadeira.",
      "porque": "A I é falsa: colisão secundária (chaves de endereços iniciais diferentes disputando o mesmo lugar) é característica do endereçamento aberto. No encadeamento só entram na mesma lista as chaves com o mesmo endereço."
     },
     {
      "letra": "B",
      "texto": "Apenas a afirmação II é verdadeira.",
      "porque": "Correta. Com uma função ruim ou muitas chaves no mesmo endereço, a lista pode ter até n nós, e n é maior que √n. Então o número de comparações pode passar de √n. I e III são falsas."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmação III é verdadeira.",
      "porque": "A III é falsa: 'sempre' e 'qualquer' não se sustentam, e o endereçamento aberto costuma fazer mais comparações com a tabela cheia."
     },
     {
      "letra": "D",
      "texto": "Apenas as afirmações II e III são verdadeiras.",
      "porque": "A II vale, mas a III é falsa."
     },
     {
      "letra": "E",
      "texto": "Apenas as afirmações I e III são verdadeiras.",
      "porque": "As duas são falsas."
     }
    ],
    "gabarito": "B",
    "resumo": "Valores: I falsa, II verdadeira, III falsa. Na II, o 'pode' basta: no pior caso todas as n chaves caem na mesma lista e a busca faz n comparações. Há quem leia que a busca nunca passa de n e conclua que nenhuma é verdadeira, mas o pior caso (todas as chaves numa lista) confirma a II e a letra B da banca.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     },
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Considere as seguintes árvores onde são apresentados apenas os valores das chaves em cada nó, sem mostrar o valor de outros campos eventualmente existentes. Além disso, note que em todos os casos, as árvores não estão em processo de rotação por inserção de chaves, estando portanto em seu estado final após a inserção do conjunto de chaves mostrado.\n\nÉ CORRETO afirmar que:",
    "figuras": [
     "2017-055-q16-i",
     "2017-055-q16-ii",
     "2017-055-q16-iii",
     "2017-055-q16-iv"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a árvore do quadro I poderia ser uma árvore AVL.",
      "porque": "As árvores II e IV também respeitam a regra do balanceamento em todos os nós."
     },
     {
      "letra": "B",
      "texto": "Apenas a árvore III não poderia ser uma árvore AVL.",
      "porque": "Correta. No nó 10 da árvore III, a subárvore esquerda é vazia (altura 0) e a direita (14 com filho 13) tem altura 2: diferença 2. As outras três têm diferença máxima 1 em todos os nós."
     },
     {
      "letra": "C",
      "texto": "Nenhuma das 4 opções apresentadas poderiam ser exemplos de árvores AVL.",
      "porque": "I, II e IV são AVL."
     },
     {
      "letra": "D",
      "texto": "Apenas as opções I e II podem ser exemplos de árvores AVL.",
      "porque": "Deixa de fora a IV, que também é AVL (alturas 3 e 3 na raiz, e cada nó com diferença de no máximo 1)."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores (de A, B, C ou D) está correta.",
      "porque": "A B está correta."
     }
    ],
    "gabarito": "B",
    "resumo": "Para testar AVL, calcule a altura de cada subárvore e confira se a diferença é no máximo 1 em todos os nós, não só na raiz. I: AVL. II: alturas 3 e 3 sob a raiz 50, e todos os nós com diferença até 1, é AVL. III: não, o nó 10 tem diferença 2. IV: AVL.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2017-055/figuras/q16-arvores.png"
    ]
   },
   {
    "numero": 17,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "Após a inserção da sequencia de números 10, 1, 3, 4, 6, 8 e 9 em uma pilha, o resultado de três (3) remoções sucessivas seria:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "10, 1 e 3 nessa ordem",
      "porque": "Seria o resultado de uma fila (primeiro a entrar, primeiro a sair). Pilha é LIFO."
     },
     {
      "letra": "B",
      "texto": "4, 3 e 1 nessa ordem",
      "porque": "Não corresponde a nenhuma regra: o topo é o 9."
     },
     {
      "letra": "C",
      "texto": "6, 8 e 9 nessa ordem",
      "porque": "São os três últimos, mas em ordem inversa à de saída: o 9 sai primeiro."
     },
     {
      "letra": "D",
      "texto": "3, 1 e 10 nessa ordem",
      "porque": "Seria remover a partir do meio da pilha, o que ela não permite."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores (A, B, C ou D) está correta.",
      "porque": "Correta. A pilha é LIFO: o último a entrar é o primeiro a sair. As três remoções devolvem 9, 8 e 6, nessa ordem, e nenhuma alternativa traz isso."
     }
    ],
    "gabarito": "E",
    "resumo": "Pilha: sai o topo, que é o último inserido. A sequência de saída é 9, 8, 6. A pegadinha é que a C tem os mesmos números em ordem invertida, e é o que faz a E ser a resposta.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 3,
    "formato": "código",
    "enunciado": "Considere uma lista encadeada onde cada nó da lista é do tipo No, cujos campos são um ponteiro para o próximo elemento (campo prox) e um dado do tipo inteiro (campo dado). Considere que a lista encadeada não possui um nó cabeça de lista, portanto todos os nós contém valores presentes na lista. Considere que todos os tipos de dados foram previamente declarados no programa. Considere que a função não deve ter problemas de alocação de memória, seja por deixar de alocar dinamicamente dados necessários ou por causar alocação dinâmica de dados desnecessária.\n\n```c\n/* funcaoI */\nvoid funcaoI(No *prim, int chave) {\n  No *aux = (No *) malloc(sizeof(No));\n  aux->chave = chave;\n  aux->prox = prim;\n  prim = aux;\n}\n\n/* funcaoII */\nvoid funcaoII(No **prim, int chave) {\n  No *aux = (No *) malloc(sizeof(No));\n  aux->chave = chave;\n  aux->prox = *prim;\n  *prim = aux;\n}\n```\n\nDadas as considerações, pode-se dizer sobre as funções funcaoI e funcaoII que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a função funcaoI pode ser usada para inserir corretamente elementos em uma fila sem gerar qualquer problema de alocação de memória ou erro na fila.",
      "porque": "A funcaoI recebe o ponteiro por valor: `prim = aux` muda só a cópia local. A lista original não enxerga o novo nó, que fica perdido (vazamento de memória)."
     },
     {
      "letra": "B",
      "texto": "Apenas a função funcaoII pode ser usada para inserir corretamente elementos em uma fila sem gerar qualquer problema de alocação de memória ou erro na fila.",
      "porque": "A funcaoII acerta a passagem do ponteiro, mas insere sempre no início. A fila é FIFO: o novo elemento entra no fim, então essa inserção não serve."
     },
     {
      "letra": "C",
      "texto": "Ambas as funções podem ser usadas para inserir elementos em uma fila sem gerar qualquer problema de alocação de memória ou erro na fila.",
      "porque": "A funcaoI tem o erro da passagem por valor, e nenhuma das duas insere no fim."
     },
     {
      "letra": "D",
      "texto": "Apenas a função funcaoI serve para inserir corretamente elementos em uma lista encadeada sem gerar erros, mas não em uma fila.",
      "porque": "Inverte os papéis: é a funcaoI que está errada (não altera o `prim` do chamador)."
     },
     {
      "letra": "E",
      "texto": "Apenas a função funcaoII serve para inserir corretamente elementos em uma lista encadeada sem gerar erros, mas não em uma fila.",
      "porque": "Correta. Com `No **prim`, a funcaoII atualiza o ponteiro do chamador, então insere certo no início de uma lista (e de uma pilha). Fila exigiria inserir no fim."
     }
    ],
    "gabarito": "E",
    "resumo": "Em C, passar `No *prim` por valor não altera o ponteiro de quem chamou; para mudar a cabeça da lista você precisa de `No **prim`. Inserir no início serve para lista e pilha, mas fila insere no fim. O código usa `chave` e o texto fala em `dado`: trate como o mesmo campo.",
    "assuntos": [
     {
      "num": "0086",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0083",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0049",
      "modulo": "06-ponteiros.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 7,
    "formato": "simulação",
    "enunciado": "Suponha que você recebeu a tarefa de depurar uma implementação de Quicksort, cujo objetivo é classificar um vetor em ordem decrescente. Após a primeira etapa da partição ser concluída, o conteúdo do vetor está na seguinte ordem:\n\n`20 22 24 18 13 9 3 10`\n\nQual das seguintes afirmações está CORRETA sobre a fase de partição?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O pivô que gerou a partição pode ter o valor 13 ou 18.",
      "porque": "Correta. Para ordem decrescente, o pivô fica numa posição com tudo à esquerda maior ou igual e tudo à direita menor ou igual. O 18 (índice 3): 20, 22, 24 à esquerda e 13, 9, 3, 10 à direita servem. O 13 (índice 4): 20, 22, 24, 18 à esquerda e 9, 3, 10 à direita também servem."
     },
     {
      "letra": "B",
      "texto": "O pivô que gerou a partição pode ter o valor 13, mas não pode ter o valor 18.",
      "porque": "O 18 também separa corretamente: os três da esquerda são maiores e os quatro da direita são menores."
     },
     {
      "letra": "C",
      "texto": "O pivô que gerou a partição pode ter o valor 18, mas não pode ter o valor 13.",
      "porque": "O 13 também separa corretamente: 20, 22, 24, 18 à esquerda e 9, 3, 10 à direita."
     },
     {
      "letra": "D",
      "texto": "O pivô que gerou a partição não pode ter o valor 13 nem 18.",
      "porque": "Os dois são pivôs possíveis."
     },
     {
      "letra": "E",
      "texto": "O conteúdo do vetor não pode representar o resultado da etapa partição.",
      "porque": "Pode: a partição não ordena os lados, só garante a separação em torno do pivô."
     }
    ],
    "gabarito": "A",
    "resumo": "Depois de uma partição, o pivô está na posição final: todos à esquerda cumprem a ordem (aqui, maiores ou iguais) e todos à direita, a ordem oposta. Teste cada candidato posição por posição. Aqui os dois testes passam, e o enunciado só exige 'pode ser'.",
    "assuntos": [
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Ao inserirmos as chaves 2, 4, 6, 8, 10 e 12, nessa ordem, em uma árvore AVL que estava originalmente vazia, a diferença de altura entre a sub-árvores que está à direita da raiz e a sub-árvore que está à esquerda da raiz será:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "0.",
      "porque": "Correta. Passo a passo: o 6 dispara rotação e a árvore fica 4(2, 6); o 8 e o 10 levam a nova rotação e dão 4(2, 8(6, 10)); o 12 desbalanceia o 4 e uma rotação à esquerda dá raiz 8, esquerda 4 (2, 6), direita 10 (12). As duas subárvores têm altura 2: diferença 0."
     },
     {
      "letra": "B",
      "texto": "2.",
      "porque": "Numa AVL a diferença entre as subárvores de qualquer nó é no máximo 1, então 2 é impossível."
     },
     {
      "letra": "C",
      "texto": "4.",
      "porque": "Impossível numa AVL, que limita a diferença a 1."
     },
     {
      "letra": "D",
      "texto": "6.",
      "porque": "Impossível numa AVL."
     },
     {
      "letra": "E",
      "texto": "8.",
      "porque": "Impossível numa AVL."
     }
    ],
    "gabarito": "A",
    "resumo": "Em AVL a diferença de alturas de qualquer nó fica em {-1, 0, 1}, então B, C, D e E caem sem conta. Simulei as inserções em Python: raiz 8, esquerda 4 (2, 6), direita 10 (com 12), alturas 2 e 2. Inserção em ordem crescente é o caso clássico de rotações simples à esquerda.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "023/2018",
  "slug": "2018-023",
  "ano": 2018,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": [
     2,
     7
    ],
    "formato": "cálculo",
    "enunciado": "Dois vetores ordenados, contendo, cada um deles, N números inteiros, precisam ser unidos em outro vetor maior, que conterá os 2N números, que também serão armazenados de forma ordenada. A complexidade de tempo de melhor caso desse processo será, então,",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O(1), pois se precisa fazer apenas uma cópia simples de cada um dos elementos originais.",
      "porque": "Copiar 2N elementos custa proporcional a N, não constante. Uma cópia por elemento ainda é N cópias."
     },
     {
      "letra": "B",
      "texto": "O(log N), pois se usa a busca binária para determinar qual será o próximo elemento copiado para o vetor de destino.",
      "porque": "A intercalação não usa busca binária: ela compara os dois elementos da frente de cada vetor. E, de qualquer jeito, nenhum algoritmo copia 2N elementos em tempo logarítmico."
     },
     {
      "letra": "C",
      "texto": "O(N), pois se precisa fazer uma cópia de cada um dos elementos originais, o que implica uma varredura completa de cada vetor de origem.",
      "porque": "Correta. Os dois vetores precisam ser percorridos por inteiro e cada elemento é copiado uma vez: 2N cópias, que é O(N), mesmo no melhor caso."
     },
     {
      "letra": "D",
      "texto": "O(Nlog N), pois se precisa fazer uma busca de cada elemento para depois inseri-lo no vetor de destino.",
      "porque": "Não há busca por elemento. Com dois índices avançando em um único laço, o custo é linear."
     },
     {
      "letra": "E",
      "texto": "O(N²), pois, como há dois vetores, precisam-se fazer dois laços de forma aninhada (um dentro do outro), gerando uma multiplicação das quantidades de elementos.",
      "porque": "Os laços não são aninhados: cada passo avança um dos dois índices e o total de passos é 2N."
     }
    ],
    "gabarito": "C",
    "resumo": "Intercalar dois vetores ordenados (o merge do mergesort) é linear: um laço, dois índices, 2N cópias. Mesmo no melhor caso (um vetor inteiro menor que o outro) você ainda copia todo mundo. Todo algoritmo que produz uma saída de tamanho 2N custa pelo menos O(N).",
    "assuntos": [
     {
      "num": "0094",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0072",
      "modulo": "10-analise.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Dadas as seguintes afirmações a respeito de árvores B,\n\nI. Em uma árvore B de ordem \"m\" cada nó tem, no máximo, \"m\" filhos.\nII. Em uma árvore B de ordem \"m\" cada nó (exceto a raíz e as folhas) tem pelo menos \"m/2\" filhos.\nIII. Árvores B precisam ser rebalanceadas frequentemente.\nIV. Um nó não-folha com \"k\" filhos deve ter k chaves.\nV. Todas as folhas aparecem no mesmo nível e carregam informação.\n\nestão CORRETOS os itens",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I e III, apenas.",
      "porque": "I é verdadeira, mas III é falsa e a II e a V ficaram de fora."
     },
     {
      "letra": "B",
      "texto": "I, III, IV e V.",
      "porque": "III e IV são falsas."
     },
     {
      "letra": "C",
      "texto": "I, II e V, apenas.",
      "porque": "Correta. I, II e V são propriedades da árvore B. III e IV são falsas."
     },
     {
      "letra": "D",
      "texto": "III, IV e V.",
      "porque": "III e IV são falsas."
     },
     {
      "letra": "E",
      "texto": "II, III e IV, apenas.",
      "porque": "III e IV são falsas."
     }
    ],
    "gabarito": "C",
    "resumo": "Valores: I V, II V, III F, IV F, V V. Propriedades da árvore B: no máximo m filhos, pelo menos ⌈m/2⌉ (menos raiz e folhas), um nó com k filhos tem k-1 chaves, e todas as folhas no mesmo nível. O rebalanceamento só acontece quando a página estoura ou fica abaixo do mínimo, e isso é raro, não frequente.",
    "assuntos": [
     {
      "num": "0146",
      "modulo": "22-arvores-avancadas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Analise as duas afirmativas a seguir, relacionadas a árvores de busca:\n\nI. Uma árvore AVL é uma árvore binária de busca autobalanceada que respeita algumas propriedades fundamentais.\nII. Como todas as árvores, ela tem uma propriedade chamada altura, que é igual ao valor da altura de sua raiz.\n\nSabendo que a altura de uma folha é igual a um (01) e que a altura de um nó pai é igual ao máximo das alturas de seus filhos mais um, qual estrutura NÃO pode representar uma árvore AVL?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Uma árvore vazia",
      "porque": "A árvore vazia é AVL (não há nó para violar a regra)."
     },
     {
      "letra": "B",
      "texto": "Uma árvore com dois nós",
      "porque": "Raiz com um filho: alturas 0 e 1, diferença 1. É AVL."
     },
     {
      "letra": "C",
      "texto": "Uma árvore com três nós e altura igual a dois",
      "porque": "Raiz com dois filhos: diferença 0. É AVL."
     },
     {
      "letra": "D",
      "texto": "Uma árvore com três nós e altura igual a três",
      "porque": "Correta. Com três nós e altura 3 a árvore é uma cadeia: a raiz tem uma subárvore de altura 2 e outra vazia (altura 0). A diferença é 2, o que viola a regra."
     },
     {
      "letra": "E",
      "texto": "Uma árvore com seis nós e altura igual a três",
      "porque": "É possível montar: por exemplo, raiz com dois filhos e mais três nós distribuídos nos netos. Todos os nós ficam com diferença até 1. É AVL."
     }
    ],
    "gabarito": "D",
    "resumo": "Numa AVL, em todo nó a diferença de altura entre as subárvores é no máximo 1. Altura 3 com só 3 nós obriga uma cadeia, então não existe AVL assim. Uma AVL de altura h precisa de um número mínimo de nós (h=3 pede pelo menos 4).",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Um heap (fila de prioridade) é uma estrutura de dados muito importante, que tem duas utilidades principais: organizar acesso a um recurso com base na prioridade dos requerentes (processos, impressões, etc.) ou servir como base a um algoritmo de ordenação muito eficiente denominado heapsort. Para poder servir a esses propósitos, um heap possui uma série de propriedades especiais que têm que ser mantidas por todas as operações nelas realizadas. Levando em consideração estas propriedades, analise as afirmativas abaixo.\n\nI. `50 40 49 39 45 46` representa um heap sintaticamente correto\nII. Dado o heap `21 14 10 9 5`, a inserção do elemento 12 se dá através dos passos `21 14 10 9 5 12` ⇒ `21 14 12 9 5 10`\nIII. Dado o heap `21 14 10 9 5`, a retirada do elemento do topo se dá através dos passos `5 14 10 9` ⇒ `14 5 12 9` ⇒ `14 9 12 5`\n\nÉ CORRETO APENAS o que se afirma em:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I.",
      "porque": "A I é falsa: no vetor, o 45 (índice 4) é filho do 40 (índice 1) e é maior que ele, o que quebra a regra de max-heap."
     },
     {
      "letra": "B",
      "texto": "II.",
      "porque": "Correta. O 12 entra no fim (índice 5), seu pai é o 10 (índice 2) e 12 > 10, então eles trocam: `21 14 12 9 5 10`. Passos corretos. I e III são falsas."
     },
     {
      "letra": "C",
      "texto": "III.",
      "porque": "A III é falsa. O último elemento (5) vai para a raiz: `5 14 10 9`. Aí o 5 desce trocando com o maior filho (14): `14 5 10 9`. O vetor da prova traz um 12 que não existe no heap."
     },
     {
      "letra": "D",
      "texto": "I e II.",
      "porque": "A II vale, mas a I é falsa (45 maior que o pai 40)."
     },
     {
      "letra": "E",
      "texto": "II e III.",
      "porque": "A II vale, mas a III é falsa (aparece um 12 do nada no segundo passo)."
     }
    ],
    "gabarito": "B",
    "resumo": "Valores: I falsa, II verdadeira, III falsa. No vetor de um max-heap, os filhos de i estão em 2i+1 e 2i+2 e nunca podem ser maiores que o pai. Inserção: entra no fim e sobe trocando com o pai. Remoção do topo: o último vai para a raiz e desce trocando com o maior filho. Cuidado com a I: o 45 é filho do 40 e é maior, então ela é falsa.",
    "assuntos": [
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2018-023/figuras/q04-heaps.png"
    ]
   },
   {
    "numero": 5,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Analise as duas afirmativas a seguir, relacionadas a árvores de busca:\n\nI. Uma árvore AVL é uma árvore binária de busca autobalanceada que respeita algumas propriedades fundamentais.\nII. Como todas as árvores, ela tem uma propriedade chamada altura, que é igual ao valor da altura de sua raiz.\n\nSabendo que a altura de uma folha é igual a um (01) e que a altura de um nó pai é igual ao máximo das alturas de seus filhos mais um, qual estrutura NÃO pode representar uma árvore AVL?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Uma árvore vazia",
      "porque": "É AVL: sem nós, nada viola a regra."
     },
     {
      "letra": "B",
      "texto": "Uma árvore com dois nós",
      "porque": "É AVL: raiz com um filho, diferença 1."
     },
     {
      "letra": "C",
      "texto": "Uma árvore com três nós e altura igual a dois",
      "porque": "É AVL: raiz com dois filhos, diferença 0."
     },
     {
      "letra": "D",
      "texto": "Uma árvore com três nós e altura igual a três",
      "porque": "É a que não pode ser AVL (é uma cadeia, com diferença 2 na raiz), por isso seria a resposta. A banca anulou por ser repetição da questão 3."
     },
     {
      "letra": "E",
      "texto": "Uma árvore com seis nós e altura igual a três",
      "porque": "É possível e balanceada: é AVL."
     }
    ],
    "gabarito": "anulada",
    "resumo": "É a mesma questão da 3, repetida no caderno, e a resposta continua sendo a D (cadeia de três nós, diferença 2). A banca anulou.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": [
     4,
     6
    ],
    "formato": "conceito",
    "enunciado": "Uma lista ordenada de N números é inserida em uma pilha e depois retirada, sendo que, a cada POP, o elemento retirado é inserido em uma árvore de busca binária. Após a completa inserção de todos os elementos nesta árvore, são feitas buscas de números na mesma. O tempo médio de busca de um número nesta árvore é",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O(1)",
      "porque": "Busca em árvore de busca não é constante. Isso seria o caso médio de um hash."
     },
     {
      "letra": "B",
      "texto": "O(log N)",
      "porque": "É o tempo de uma árvore balanceada. Aqui a árvore sai degenerada."
     },
     {
      "letra": "C",
      "texto": "O(N)",
      "porque": "Correta. A pilha inverte a ordem: a lista ordenada sai em ordem decrescente. Inserir chaves em ordem decrescente faz cada uma ir à esquerda da anterior, e a árvore vira uma lista. A busca percorre em média cerca de N/2 nós, que é O(N)."
     },
     {
      "letra": "D",
      "texto": "O(Nlog N)",
      "porque": "É o custo de construir ou ordenar, não o de uma busca."
     },
     {
      "letra": "E",
      "texto": "O(N2)",
      "porque": "N² (soma de 1 até N) é o custo total das N inserções na árvore degenerada, não o de uma busca."
     }
    ],
    "gabarito": "C",
    "resumo": "Entrada ordenada (crescente ou decrescente) numa ABB sem balanceamento gera uma árvore degenerada, igual a uma lista: a busca vira O(N). Pilha só inverte a ordem, não embaralha. Para ter O(log N) seria preciso AVL ou outra árvore balanceada.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Assinale cada afirmativa abaixo como verdadeira (V) ou falsa (F). Em seguida, marque a opção que corresponde à sequência CORRETA.\n\n( ) Uma árvore não-vazia é balanceada AVL se, pelo menos, uma de suas árvores, esquerda ou direita, for balanceada AVL;\n( ) As árvores cheias são árvores balanceadas AVL;\n( ) Uma boa condição de balanceamento AVL deve assegurar que a altura de uma árvore com n nós é da ordem de O(log n);\n( ) Uma árvore AVL é uma árvore balanceada pela altura;\n( ) Ao inserir ou remover um item em uma árvore AVL, o custo adicional para balancear esta árvore é da ordem de O(n/2).",
    "alternativas": [
     {
      "letra": "A",
      "texto": "V - V - F - V - V",
      "porque": "Erra a 1ª (é F), a 3ª (é V) e a 5ª (é F)."
     },
     {
      "letra": "B",
      "texto": "F - V - V - V - F",
      "porque": "Correta. 1ª F: as duas subárvores precisam ser AVL, não só uma. 2ª V: árvore cheia tem diferença zero em todos os nós. 3ª V: a altura é O(log n). 4ª V: o balanceamento é pela altura. 5ª F: o custo extra é O(log n)."
     },
     {
      "letra": "C",
      "texto": "V - F - F - V - F",
      "porque": "Erra a 1ª, a 2ª e a 3ª."
     },
     {
      "letra": "D",
      "texto": "F - V - V - F - V",
      "porque": "Erra a 4ª (é V) e a 5ª (é F)."
     },
     {
      "letra": "E",
      "texto": "F - F - V - V - F",
      "porque": "Erra a 2ª: árvore cheia é AVL, então a afirmação é V."
     }
    ],
    "gabarito": "B",
    "resumo": "Sequência: F, V, V, V, F. A AVL exige que as duas subárvores sejam AVL e que a diferença de altura no nó seja no máximo 1. Disso sai altura O(log n), e o custo de balancear uma inserção ou remoção é O(log n) (rotações no caminho), não O(n/2).",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0176",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Considere uma estrutura do tipo árvore binária que começa vazia. Nela são introduzidos os números 2, 10, 5, 7, 1, 0 e 8, exatamente nessa ordem. Se essa árvore for lida em pós-ordem, que sequência de números será impressa?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "2, 1, 0, 8, 7, 5, 10",
      "porque": "Começa pela raiz (2), o que é característica da pré-ordem, não da pós-ordem."
     },
     {
      "letra": "B",
      "texto": "2, 1, 0, 10, 5, 7, 8",
      "porque": "Também começa pela raiz e não corresponde a nenhum percurso desta árvore."
     },
     {
      "letra": "C",
      "texto": "0, 1, 8, 7, 5, 10, 2",
      "porque": "Correta. A árvore: raiz 2, esquerda 1 (com 0 à esquerda), direita 10 (com 5 à esquerda, que tem 7 à direita, que tem 8 à direita). Pós-ordem: subárvore esquerda (0, 1), depois a direita (8, 7, 5, 10) e por último a raiz (2)."
     },
     {
      "letra": "D",
      "texto": "0, 1, 2, 8, 7, 5, 10",
      "porque": "A raiz 2 não pode vir no meio na pós-ordem: ela é a última."
     },
     {
      "letra": "E",
      "texto": "0, 1, 2, 10, 5, 7, 8",
      "porque": "Não corresponde ao percurso: a raiz tem de ser a última."
     }
    ],
    "gabarito": "C",
    "resumo": "Monte a árvore na ordem de inserção e leia filhos antes do pai (esquerda, direita, raiz). Rodei o programa em C e confirmei: 0 1 8 7 5 10 2. Na pós-ordem a última chave é sempre a raiz, o que já elimina A, B, D e E.",
    "assuntos": [
     {
      "num": "0098",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 3,
    "formato": "código",
    "enunciado": "Os registros em uma lista, duplamente encadeada com 20 elementos possuem cada um três campos:\n\n- próximo: um ponteiro para o próximo elemento da lista;\n- valor: informação armazenada pelo elemento;\n- anterior: um ponteiro para o elemento anterior da lista.\n\nSendo \"Z\" o décimo elemento desta lista e \"X\" e \"Y\" dois outros elementos que não pertencem à lista, com seus respectivos ponteiros \"pZ\", \"pX\" e \"pY\", considere o trecho de código abaixo.\n\n```\npY↑.próximo = pX;\npX↑.anterior = pY;\npX↑.próximo = pZ↑.próximo;\npZ↑.próximo↑.anterior = pX;\npZ↑.próximo = pY;\npY↑.anterior = pZ;\n```\n\nEste trecho de código é usado para inserir na lista os elementos:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Y, logo após o Z, e X, logo após o Y.",
      "porque": "Correta. Chame de W o antigo sucessor de Z. As linhas ligam Y ao X, X ao W, W de volta ao X, Z ao Y e Y de volta ao Z. O resultado é Z, Y, X, W."
     },
     {
      "letra": "B",
      "texto": "Y, antes do Z, e X, logo após o Z.",
      "porque": "Z.próximo passa a ser Y, então o Y fica depois de Z, não antes."
     },
     {
      "letra": "C",
      "texto": "Y, antes do Z, e X, antes do Y.",
      "porque": "Nada no código liga elementos antes do Z: só o `próximo` de Z muda."
     },
     {
      "letra": "D",
      "texto": "X, logo após o Z, e Y, logo após o X.",
      "porque": "Ordem trocada: logo após o Z vem o Y (`pZ↑.próximo = pY`), e o X vem depois do Y."
     },
     {
      "letra": "E",
      "texto": "X, antes do Z, e Y, logo após o Z.",
      "porque": "O X fica depois do Y, entre o Y e o antigo sucessor de Z, e não antes do Z."
     }
    ],
    "gabarito": "A",
    "resumo": "Em inserção em lista dupla, desenhe os quatro elos: Z, novo, novo, antigo sucessor, e confira os dois sentidos (próximo e anterior). Aqui Z.próximo vira Y, Y.próximo vira X e X.próximo vira o antigo sucessor de Z, com os `anterior` espelhando isso.",
    "assuntos": [
     {
      "num": "0079",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Considere a seguinte árvore de pesquisa binária:\n\nAo executarmos o procedimento de remoção da raiz, na nova árvore binária de busca, teremos como novo nó raiz:",
    "figuras": [
     "2018-023-q10"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "11",
      "porque": "O 11 é filho da raiz. Se ele subisse, os valores 17 e 18 (maiores que 11) ficariam à esquerda dele, o que quebra a ordem de uma ABB."
     },
     {
      "letra": "B",
      "texto": "2",
      "porque": "É o menor valor da árvore. Como raiz, deixaria quase tudo à direita e desrespeitaria a ordem."
     },
     {
      "letra": "C",
      "texto": "17",
      "porque": "O 17 não é o maior da subárvore esquerda: ele tem o 18 à direita, que é maior."
     },
     {
      "letra": "D",
      "texto": "18",
      "porque": "Correta. Raiz com dois filhos: assume o antecessor, que é o maior da subárvore esquerda (desce uma vez à esquerda, até 11, e depois sempre à direita: 17, 18)."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das anteriores",
      "porque": "A D está correta: o novo raiz é o 18."
     }
    ],
    "gabarito": "D",
    "resumo": "Remoção de nó com dois filhos: troca pelo antecessor (maior da esquerda) ou pelo sucessor (menor da direita). Aqui o antecessor é 18 e o sucessor seria 21. Como o 21 não está nas alternativas, a banca usou o antecessor. Atenção: o curso (assunto 0100) usa o sucessor, e com ele a resposta seria 21; na prova, confira qual dos dois candidatos aparece nas alternativas. A figura não veio no texto, mas o PNG confirma a árvore.",
    "assuntos": [
     {
      "num": "0100",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2018-023/figuras/q10-arvore.png"
    ]
   },
   {
    "numero": 11,
    "topico": 1,
    "formato": "simulação",
    "enunciado": "Considere o algoritmo a seguir que define a função recursiva \"f\".\n\n```\nfunção f(n){\n  se n igual a 1 então retorne 0\n  se n igual a 2 então retorne 1\n  setorne f(n-1) + f(n-2)\n}\n```\n\nQual o valor retornado pela função \"f\" ao ser invocada passando o valor 4 como argumento?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "0",
      "porque": "É o valor de f(1), o caso base mais baixo."
     },
     {
      "letra": "B",
      "texto": "1",
      "porque": "É o valor de f(2). Para n = 4 há duas somas."
     },
     {
      "letra": "C",
      "texto": "2",
      "porque": "Correta. f(4) = f(3) + f(2). f(3) = f(2) + f(1) = 1 + 0 = 1. Então f(4) = 1 + 1 = 2."
     },
     {
      "letra": "D",
      "texto": "3",
      "porque": "É o valor de f(5): f(4) + f(3) = 2 + 1. Você andou um passo a mais na sequência."
     },
     {
      "letra": "E",
      "texto": "4",
      "porque": "Não corresponde a nenhum termo da sequência até f(5). A conta de f(4) dá 2."
     }
    ],
    "gabarito": "C",
    "resumo": "Isso é Fibonacci deslocado: f(1)=0, f(2)=1, f(3)=1, f(4)=2, f(5)=3. Na recursão, desça até os casos base e some de baixo para cima.",
    "assuntos": [
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     },
     {
      "num": "0033",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 6,
    "formato": "simulação",
    "enunciado": "Considere o vetor ordenado abaixo e indique quais os valores serão comparados com a chave de busca de valor 20 se for realizada uma busca binária no vetor. Considere que a primeira posição do vetor é a posição 0.\n\n`32 | 8 | 12 | 16 | 20 | 24 | 28 | 16 | 36`",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Chaves 20, 12, 8 e 4, nessa ordem",
      "porque": "Não é uma sequência de busca binária: o primeiro valor comparado é o do meio, e se ele é 20 a busca acaba."
     },
     {
      "letra": "B",
      "texto": "Chaves 20, 28,32 e 36, nessa ordem",
      "porque": "Só o primeiro (20) é comparado, e é nele que a busca termina."
     },
     {
      "letra": "C",
      "texto": "Chaves 4, 8, 12, 16 e 20, nessa ordem",
      "porque": "Isso lembra uma busca sequencial, não a binária."
     },
     {
      "letra": "D",
      "texto": "Chaves 36, 32, 28 e 24, nessa ordem",
      "porque": "Também não segue a busca binária."
     },
     {
      "letra": "E",
      "texto": "Apenas a chave 20",
      "porque": "Correta. O vetor tem 9 posições (0 a 8) e o meio é a posição 4, que vale 20. Uma comparação só e a busca termina."
     }
    ],
    "gabarito": "E",
    "resumo": "Busca binária: compare com o elemento do meio ((0+8)/2 = 4). Se for a chave, acabou. O vetor veio com erros no caderno (`32 8 12 16 20 24 28 16 36`), mas nas duas versões a posição 4 vale 20, então a resposta E não muda.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Considere uma estrutura de dados do tipo vetor. Com respeito a tal estrutura, é CORRETO que seus componentes são, caracteristicamente:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "heterogêneos e com acesso FIFO.",
      "porque": "Os elementos de um vetor são do mesmo tipo (homogêneos), e FIFO é regra de fila."
     },
     {
      "letra": "B",
      "texto": "heterogêneos e com acesso LIFO.",
      "porque": "Homogêneos, não heterogêneos, e LIFO é regra de pilha."
     },
     {
      "letra": "C",
      "texto": "heterogêneos e com acesso indexado-sequencial.",
      "porque": "Heterogêneos é o termo de struct. Vetor é homogêneo."
     },
     {
      "letra": "D",
      "texto": "homogêneos e acesso não indexado.",
      "porque": "Homogêneos está certo, mas o acesso é por índice."
     },
     {
      "letra": "E",
      "texto": "homogêneos e de acesso aleatório por intermédio de índices.",
      "porque": "Correta. Todos os elementos têm o mesmo tipo e qualquer posição é acessada direto pelo índice, em tempo constante."
     }
    ],
    "gabarito": "E",
    "resumo": "Vetor: homogêneo e acesso direto por índice. Struct é o heterogêneo. FIFO e LIFO são políticas de fila e pilha, não de vetor.",
    "assuntos": [
     {
      "num": "0037",
      "modulo": "05-vetores-e-strings.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 6,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre busca binária:\n\nI) é utilizada apenas sobre vetores ordenados\nII) pode determinar se uma chave está ou não com um número de comparações de chave inferior a 2log2 n passos, onde n é o tamanho do vetor.\nIII) Supera a busca sequencial quando o vetor é grande, por exemplo com mais que mil elementos, e está ordenado.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas as afirmações II e III estão corretas",
      "porque": "A I também é verdadeira: a busca binária só funciona com o vetor ordenado."
     },
     {
      "letra": "B",
      "texto": "Apenas as afirmações I e II estão corretas",
      "porque": "A III também é verdadeira."
     },
     {
      "letra": "C",
      "texto": "Apenas as afirmações I e III estão corretas",
      "porque": "A II também é verdadeira."
     },
     {
      "letra": "D",
      "texto": "Todas as afirmações estão corretas",
      "porque": "Correta. I: exige ordem. II: o máximo é cerca de log2 n + 1 comparações, que fica abaixo de 2 log2 n quando n cresce. III: com mais de mil elementos ordenados, cerca de 10 comparações contra até mil."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "As três afirmações são verdadeiras, então D vale."
     }
    ],
    "gabarito": "D",
    "resumo": "Valores: I V, II V, III V. A busca binária exige vetor ordenado, faz no máximo cerca de log2 n + 1 comparações e ganha da sequencial em vetores grandes. Quando todas as afirmações parecem boas, desconfie dos exageros (aqui nenhum falha).",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "As árvores são estruturas de dados poderosas e se subdividem em vários tipos, cada um dos quais com suas características próprias. Relacione os tipos de árvores, apresentados na coluna da esquerda, com as suas respectivas características, indicadas na coluna da direita:\n\n| Tipo de árvore | Característica |\n|---|---|\n| I – Heap | W – Pode degenerar se os elementos forem inseridos de forma ordenada. |\n| II – Rubro-Negra | X – É balanceada. |\n| III – Avore AVL | Y – Têm altura sempre proporcional/próxima a O(log2 n), onde n é o número de nós que contém. |\n| IV – Árvores binária de busca | Z – São sempre completas. |\n\nEstão CORRETAS as associações:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I–X, IV–Z, II–Y",
      "porque": "IV–Z é falsa: uma ABB comum não é completa."
     },
     {
      "letra": "B",
      "texto": "I–Z, IV–X, III–W",
      "porque": "IV–X é falsa (ABB não é balanceada) e III–W é falsa (AVL não degenera)."
     },
     {
      "letra": "C",
      "texto": "I–Z, IV–X, III–Y",
      "porque": "IV–X é falsa: a ABB simples não garante balanceamento."
     },
     {
      "letra": "D",
      "texto": "I–Y, IV–W, III–X",
      "porque": "Correta pela banca. Heap tem altura O(log n), ABB pode degenerar com entrada ordenada e AVL é balanceada."
     },
     {
      "letra": "E",
      "texto": "I–X, IV–W, II–Y",
      "porque": "Também é defensável: heap é balanceado, ABB degenera, rubro-negra tem altura O(log n). A banca marcou D."
     }
    ],
    "gabarito": "D",
    "resumo": "Heap: sempre completa (Z) e altura O(log n). ABB comum: pode degenerar (W). AVL e rubro-negra: balanceadas, altura O(log n). Aqui D e E se sustentam, e nenhuma alternativa usa o 'sempre completa' do heap. O curso teria ficado com o heap em Z, mas na prova vale a letra D da banca. Em questão de associar, marque as certezas e descarte alternativas com um erro.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0145",
      "modulo": "22-arvores-avancadas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Sobre o algoritmo de ordenação heapsort, marque a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Utiliza ordenação por árvore de decisão, ao invés de ordenação por comparação",
      "porque": "Heapsort é um algoritmo de ordenação por comparação. A árvore de decisão é um modelo usado para provar o limite Ω(n log n), não um algoritmo."
     },
     {
      "letra": "B",
      "texto": "A estrutura de dados que utiliza, chamada heap, pode ser interpretada como uma árvore binária",
      "porque": "Correta. O heap é guardado em vetor, mas se interpreta como árvore binária quase completa (filhos de i em 2i+1 e 2i+2)."
     },
     {
      "letra": "C",
      "texto": "Seu desempenho de pior caso é pior do que o do algoritmo quicksort",
      "porque": "O pior caso do heapsort é O(n log n), melhor que o O(n²) do quicksort."
     },
     {
      "letra": "D",
      "texto": "Todas as alternativas estão corretas",
      "porque": "A e C são falsas."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas está correta",
      "porque": "A B está correta."
     }
    ],
    "gabarito": "B",
    "resumo": "Heapsort: constrói um max-heap no vetor (árvore binária implícita) e extrai o maior repetidamente. É por comparação e tem O(n log n) no pior caso, melhor que o quicksort nesse quesito.",
    "assuntos": [
     {
      "num": "0103",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 17,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Considerando os algoritmos de ordenação Quicksort, MergeSort, HeapSort e InsertionSort\n\nI. São algoritmos estáveis: HeapSort, QuickSort e MergeSort\nII. A complexidade de uso de espaço é O(n²): HeapSort,\nIII. A ordem das entradas é incapaz de influenciar o desempenho do algoritmo: InsertionSort, MergeSort\nIV. Melhor caso da complexidade de tempo em Ω(n) : InsertionSort\nV. A complexidade de uso de espaço é O(n): MergeSort\n\nMarque a alternativa que indica SOMENTE afirmações INCORRETAS feitas:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I IV e V",
      "porque": "IV e V são verdadeiras, então não são afirmações incorretas."
     },
     {
      "letra": "B",
      "texto": "I , III e IV",
      "porque": "A IV é verdadeira."
     },
     {
      "letra": "C",
      "texto": "I, II, III e IV",
      "porque": "A IV é verdadeira."
     },
     {
      "letra": "D",
      "texto": "I, II e III",
      "porque": "Correta. A lista só com as incorretas: I é falsa (heapsort e quicksort não são estáveis), II é falsa (heapsort usa O(1) de espaço extra) e III é falsa (a ordem de entrada muda o desempenho da inserção: O(n) ordenado contra O(n²) invertido)."
     },
     {
      "letra": "E",
      "texto": "II e V",
      "porque": "A V é verdadeira (o merge usa vetor auxiliar de tamanho n)."
     }
    ],
    "gabarito": "D",
    "resumo": "Valores: I F, II F, III F, IV V, V V. A pergunta pede as incorretas, então a resposta é a lista I, II, III. Resumo útil: estáveis são inserção e mergesort; heapsort é in-place; inserção vai de n a n².",
    "assuntos": [
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0103",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 5,
    "formato": "simulação",
    "enunciado": "Considere uma tabela de espalhamento (hash table) de comprimento igual a 11, na qual a técnica de resolução de colisões utilizada é a de encadeamento. Nessa tabela, as posições são numeradas (indexadas) com os valores 0, 1, 2, ..., 10, o mapeamento de chaves para posições usa a função hash definida por h(k) = k mod 11, onde k é o valor da chave, e mod é o operador de módulo, e os números 1, 5, 18, 20, 4, 12, 10, 34, 15, 28 e 17 foram as chaves inseridas, nessa ordem, nessa tabela de espalhamento que estava inicialmente vazia. Qual a quantidade de posições em que houve colisão durante as inserções das chaves?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "0",
      "porque": "Há colisões, por exemplo 1, 12 e 34 caem todos na posição 1."
     },
     {
      "letra": "B",
      "texto": "1",
      "porque": "Só a posição 1 ficou na conta. Faltam as posições 4 e 6."
     },
     {
      "letra": "C",
      "texto": "2",
      "porque": "Falta uma posição: além da 1 e da 4, a 6 recebe 28 e 17."
     },
     {
      "letra": "D",
      "texto": "3",
      "porque": "Correta. Posição 1: 1, 12 e 34. Posição 4: 4 e 15. Posição 6: 28 e 17. As demais (5, 7, 9, 10) têm uma chave só."
     },
     {
      "letra": "E",
      "texto": "4",
      "porque": "Só existem três posições com mais de uma chave."
     }
    ],
    "gabarito": "D",
    "resumo": "Calcule k mod 11: 1→1, 5→5, 18→7, 20→9, 4→4, 12→1, 10→10, 34→1, 15→4, 28→6, 17→6. Conte posições com mais de uma chave, não colisões individuais: 1, 4 e 6. Rodei em C e deu 3.",
    "assuntos": [
     {
      "num": "0105",
      "modulo": "15-hash.md"
     },
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Marque a alternativa CORRETA. Uma lista encadeada simples é uma estrutura que corresponde a uma sequência lógica de entradas ou nós. Cada nó armazena a localização do próximo elemento na sequência, ou seja, de seu nó sucessor. Nessa estrutura:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Para estabelecer a ligação entre um nó já pertencente a uma lista e um novo nó, basta fazer com que o novo nó referencie no, campo next, o nó que anteriormente era referenciado pelo nó original, desde que esse campo não tenha o valor nulo.",
      "porque": "Incompleta e com condição errada: falta fazer o nó original apontar para o novo, e a ligação também funciona quando o próximo é nulo (inserção no fim)."
     },
     {
      "letra": "B",
      "texto": "A existência de um ponteiro apontando para o 1º elemento e outro para o fim da lista permite que a inserção ou deleção de dados de um nó que esteja no meio da lista seja rapidamente executada.",
      "porque": "Os ponteiros de início e fim só aceleram as pontas. Para chegar ao meio você percorre a lista, e na simples ainda precisa do nó anterior."
     },
     {
      "letra": "C",
      "texto": "Enquanto a entrada que determina o topo da lista é mantida em um nó descritor dessa lista, a entrada que marca o fim da lista é mantida fora do descritor.",
      "porque": "Sem base: um descritor guarda os dois, início e fim."
     },
     {
      "letra": "D",
      "texto": "O armazenamento de uma lista requer uma área contígua de memória para permitir a otimização no processamento de criação e remoção de nós da lista.",
      "porque": "Memória contígua é exigência do vetor. A lista justamente dispensa isso."
     },
     {
      "letra": "E",
      "texto": "O armazenamento de uma lista não requer uma área contígua de memória. Como listas são estruturas dinâmicas, normalmente são definidos procedimentos que permitem criar e remover nós na memória.",
      "porque": "Correta. Cada nó pode estar em qualquer lugar da memória, ligado pelo ponteiro, e a lista cresce ou encolhe criando e removendo nós em tempo de execução."
     }
    ],
    "gabarito": "E",
    "resumo": "Lista encadeada: nós alocados dinamicamente, espalhados na memória e ligados por ponteiro. Isso dá inserção e remoção baratas, mas acesso ao meio é O(n). Contígua é característica de vetor.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0077",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": [
     3,
     4
    ],
    "formato": "afirmações",
    "enunciado": "A estrutura de dados é um modo de armazenamento e organização de dados para que possam ser usados eficientemente. Dentre as alternativas abaixo, sobre as afirmações de estrutura de dados, escolha a CORRETA:\n\nI. Uma fila é uma estrutura de dados em que cada elemento tem um ou mais elementos associados.\nII. A árvore é uma estrutura de dados baseada no princípio Last-in, First-out (LIFO), na qual os dados que foram inseridos primeiro serão os últimos a serem removidos.\nIII. Uma lista é uma estrutura de dados linear, que pode ser encadeada, a qual é composta por nós que apontam para o próximo elemento e o último elemento apontará para nulo.\nIV. As pilhas são estruturas baseadas no princípio First-in, First-out (FIFO), em que os elementos que foram inseridos no início são os primeiros a serem removidos.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Somente a afirmação I é verdadeira.",
      "porque": "A I descreve uma estrutura em que um elemento se relaciona com vários (árvore ou grafo). Fila é linear e segue FIFO."
     },
     {
      "letra": "B",
      "texto": "Somente a afirmação II é verdadeira.",
      "porque": "LIFO é regra da pilha. A árvore é hierárquica e não tem essa política."
     },
     {
      "letra": "C",
      "texto": "Somente a afirmação III é verdadeira.",
      "porque": "Correta. Lista linear encadeada: cada nó aponta para o próximo e o último aponta para nulo. I, II e IV trocam as definições."
     },
     {
      "letra": "D",
      "texto": "Somente a afirmação IV é verdadeira.",
      "porque": "A pilha é LIFO: o último a entrar é o primeiro a sair."
     },
     {
      "letra": "E",
      "texto": "Todas as afirmativas são verdadeiras.",
      "porque": "I, II e IV são falsas."
     }
    ],
    "gabarito": "C",
    "resumo": "Valores: I falsa (fila é linear, FIFO), II falsa (árvore não é LIFO, pilha é), III verdadeira, IV falsa (pilha é LIFO, não FIFO). Questões desse tipo trocam as definições entre estruturas: decore a política de cada uma.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "061/2018",
  "slug": "2018-061",
  "ano": 2018,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": 5,
    "formato": "cálculo",
    "enunciado": "Considere um arquivo sequencial com 10.000 registros, cujas chaves identificadoras são números inteiros de até 8 dígitos. Para criar um índice tipo hashing para esse arquivo, contendo endereços de 0 até 11.999, a mais adequada definição para uma função de hashing f(x), onde x é uma chave e (a mod b) é o resto da divisão de a por b, seria:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "f = x mod 1000 + 12",
      "porque": "Gera endereços de 12 a 1011: só 1000 endereços para 10.000 registros, com muitas colisões, e a faixa 0 a 11.999 fica quase toda sem uso."
     },
     {
      "letra": "B",
      "texto": "f = x mod 12000",
      "porque": "Correta. O resto da divisão por 12000 vai de 0 a 11.999, exatamente a faixa pedida, e espalha as chaves por ela."
     },
     {
      "letra": "C",
      "texto": "f = x / 10000",
      "porque": "Com chaves de até 8 dígitos, a divisão inteira dá no máximo 9999 e agrupa 10.000 chaves consecutivas no mesmo endereço. Não cobre até 11.999 e concentra chaves."
     },
     {
      "letra": "D",
      "texto": "f = x / 11999",
      "porque": "Dá endereços de 0 a cerca de 8333, não cobre a faixa e junta milhares de chaves seguidas no mesmo endereço."
     },
     {
      "letra": "E",
      "texto": "f = (x – 11999) /10000",
      "porque": "Dá valores negativos para chaves pequenas e, de resto, só chega até cerca de 9999. Não é uma função de hash válida para essa faixa."
     }
    ],
    "gabarito": "B",
    "resumo": "Função de hash por divisão: x mod M devolve sempre um valor de 0 a M-1, então para a faixa 0 a 11.999 use M = 12000. Divisão simples (x / k) agrupa chaves vizinhas e não cobre a faixa. Em projeto real se prefere M primo, mas aqui só a B cobre exatamente os endereços pedidos.",
    "assuntos": [
     {
      "num": "0105",
      "modulo": "15-hash.md"
     },
     {
      "num": "0178",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Matrizes são estruturas de dados de n-dimensões. Por simplicidade, chamaremos de matrizes as matrizes bidimensionais numéricas (que armazenam números inteiros). Sendo assim, marque a alternativa INCORRETA.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Uma matriz de m linhas e n colunas contêm (m * n) dados.",
      "porque": "Verdadeira: m linhas vezes n colunas dá m·n elementos."
     },
     {
      "letra": "B",
      "texto": "Uma matriz pode ser representada utilizando listas ligadas.",
      "porque": "Verdadeira: dá para usar lista de listas, ou lista só dos elementos não nulos (matriz esparsa)."
     },
     {
      "letra": "C",
      "texto": "A soma dos elementos de uma matriz pode ser calculada fazendo dois laços aninhados, um sobre as linhas e o outro sobre as colunas.",
      "porque": "Verdadeira: é a varredura padrão de matriz."
     },
     {
      "letra": "D",
      "texto": "A soma de duas matrizes de m linhas e n colunas resulta em uma matriz de 2*m linhas e 2*n colunas.",
      "porque": "Correta (é a incorreta pedida). A soma é elemento a elemento, então o resultado tem as mesmas m linhas e n colunas, não o dobro."
     },
     {
      "letra": "E",
      "texto": "O produto de duas matrizes de n linhas e n colunas resulta em uma matriz de n linhas e n colunas.",
      "porque": "Verdadeira: (n×n)·(n×n) dá n×n."
     }
    ],
    "gabarito": "D",
    "resumo": "Soma de matrizes é elemento a elemento: o tamanho do resultado é o mesmo das parcelas. O produto de (m×p) por (p×n) dá (m×n). A questão pede a incorreta, então atenção ao sentido do enunciado.",
    "assuntos": [
     {
      "num": "0039",
      "modulo": "05-vetores-e-strings.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Considere a árvore AVL abaixo para responder à questão.\n\nQual é a sequência de chaves que constrói a referida árvore AVL, inicialmente vazia?",
    "figuras": [
     "2018-061-q03"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "23 – 7 – 29 – 15 – 4 – 25 – 35 – 13 – 17",
      "porque": "Constrói a árvore da figura (raiz 23, esquerda 7 com 4 e 15, direita 29 com 25 e 35, e o 15 com 13 e 17)."
     },
     {
      "letra": "B",
      "texto": "23 – 13 – 35 – 7 – 4 – 29 – 15 – 25 – 17",
      "porque": "Também constrói a árvore da figura, depois das rotações."
     },
     {
      "letra": "C",
      "texto": "23 – 29 – 7 – 17 – 13 – 4 – 35 – 25 – 15",
      "porque": "Gera outra árvore: uma rotação com 13 e 17 leva o 13 à raiz."
     },
     {
      "letra": "D",
      "texto": "23 – 25 – 7 – 15 – 4 – 13 – 35 – 29 – 17",
      "porque": "Gera outra árvore, com raiz 15."
     },
     {
      "letra": "E",
      "texto": "23 – 7 – 29 – 17 – 4 – 35 -15 – 25 – 13",
      "porque": "Também constrói a árvore da figura."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Para achar a sequência que gera uma AVL, simule as inserções com as rotações. Simulei em Python: A, B e E geram exatamente a árvore da figura; C gera raiz 13 e D, raiz 15. Com três respostas possíveis, a banca anulou. Na prova, desconfie quando a raiz da figura aparece como primeira chave de todas as opções.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2018-061/figuras/q03-arvore-avl.png"
    ]
   },
   {
    "numero": 4,
    "topico": [
     7,
     2
    ],
    "formato": "conceito",
    "enunciado": "Considere as afirmativas sobre métodos de ordenação. Sabendo que N se refere ao número de elementos do conjunto, a alternativa INCORRETA é:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Os algoritmos Bubble sort e Selection sort são ambos O(N²).",
      "porque": "Verdadeira: os dois têm laços aninhados e custo quadrático."
     },
     {
      "letra": "B",
      "texto": "O Selection sort é o método mais rápido para qualquer tamanho de N se os elementos já estão ordenados, pois este é o seu melhor caso, que é O(Log2 N).",
      "porque": "É a incorreta. O selection sort faz da ordem de N² comparações em qualquer caso, ordenado ou não: o melhor caso também é O(N²). Nenhuma ordenação por comparação é O(log N), porque nem para ler a entrada ela basta."
     },
     {
      "letra": "C",
      "texto": "No método Quicksort, inicialmente o vetor é dividido em uma sublista da direita e uma da esquerda, de modo que todo elemento da sublista da esquerda seja menor que os da direita. Em seguida, ordenam-se, pelo mesmo processo, as duas sublistas de forma recursiva.",
      "porque": "Verdadeira: descreve a partição em torno do pivô seguida de recursão."
     },
     {
      "letra": "D",
      "texto": "O tempo de execução dos algoritmos de ordenação aumenta na medida em que aumentamos o número de chaves se considerarmos o pior caso.",
      "porque": "Verdadeira: mais chaves, mais trabalho."
     },
     {
      "letra": "E",
      "texto": "O método Quicksort é, essencialmente, uma aplicação do princípio \"dividir para conquistar\".",
      "porque": "Verdadeira: divide em partes pela partição e resolve cada uma recursivamente."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Valores: A V, B F, C V, D V, E V. A incorreta é a B, porque o selection sort é O(N²) sempre, até com o vetor ordenado (ele não aproveita a ordem). A banca anulou a questão. Lembre: quem ganha no vetor já ordenado é a inserção (O(N)), não a seleção.",
    "assuntos": [
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 5,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "A árvore binária de busca, formada pela inserção dos números 100, 80, 25, 72, 23, 42 e 5, nesta ordem, terá como nós folha os números __I__ e __II__, e como pai do nó 72 o número __III__. As lacunas I, II e III são preenchidas CORRETAMENTE e, respectivamente, por:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "100 – 80 – 100",
      "porque": "100 e 80 são nós internos: o 100 é a raiz e o 80 tem o 25 como filho."
     },
     {
      "letra": "B",
      "texto": "5 – 42 – 25",
      "porque": "Correta. A árvore: 100 → 80 (esquerda) → 25 (esquerda) → 72 (direita) e 23 (esquerda); 42 fica à esquerda do 72 e 5 à esquerda do 23. As folhas são 5 e 42, e o pai do 72 é o 25."
     },
     {
      "letra": "C",
      "texto": "23 – 25 – 72",
      "porque": "23 tem o filho 5, 25 tem filhos e 72 tem o filho 42: nenhum é folha."
     },
     {
      "letra": "D",
      "texto": "25 – 72 – 100",
      "porque": "Nenhum desses é folha, e o pai do 72 é o 25."
     },
     {
      "letra": "E",
      "texto": "72 – 5 – 23",
      "porque": "O 72 tem o filho 42, então não é folha, e o pai do 72 é o 25, não o 23."
     }
    ],
    "gabarito": "B",
    "resumo": "Insira na ordem dada: cada número vai à esquerda se menor e à direita se maior que o nó atual. Folha é nó sem filhos. O 42 é maior que 25 (vai à direita, para o 72) e menor que 72 (vai à esquerda do 72).",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Marque a alternativa CORRETA. O método de ordenação QuickSort (ordenação rápida) é um método sofisticado de ordenação de vetores que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Considera em cada passo somente um único elemento sucessor na sequência fonte e todos os elementos do vetor destino para encontrar o ponto correto da inserção.",
      "porque": "Descreve a inserção direta, não o quicksort."
     },
     {
      "letra": "B",
      "texto": "Ordena todos os elementos que estiverem a intervalos de 4 posições entre si na sequência corrente.",
      "porque": "Descreve uma passada do Shellsort com incremento 4."
     },
     {
      "letra": "C",
      "texto": "É baseado nos princípios de ordenação por inserção direta através de incrementos decrescentes.",
      "porque": "É a definição do Shellsort."
     },
     {
      "letra": "D",
      "texto": "O Quicksort é um algoritmo que pode usar espaço extra linear no pior caso.",
      "porque": "Correta. O quicksort ordena no próprio vetor, mas a recursão usa pilha. No pior caso (partições muito desiguais) a profundidade chega a n, e o espaço extra a O(n)."
     },
     {
      "letra": "E",
      "texto": "É baseado nos princípios de ordenação por seleção direta que consiste na seleção repetitiva da menor dentre as chaves de n elementos, e depois dentre os n-1 elementos restantes, e assim por diante.",
      "porque": "Descreve a seleção direta."
     }
    ],
    "gabarito": "D",
    "resumo": "O quicksort faz partição e recursão. Como cada chamada recursiva ocupa pilha, o espaço extra é O(log n) em média e O(n) no pior caso. As outras alternativas descrevem outros métodos (inserção, Shellsort, seleção): identifique pela descrição.",
    "assuntos": [
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0168",
      "modulo": "26-analise-formal.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": [
     3,
     4,
     5
    ],
    "formato": "afirmações",
    "enunciado": "Avaliando as sentenças seguintes a respeito de estrutura de dados,\n\nI. A diferença entre árvore binária simples e árvores AVL é o fato de que a segunda pode se reconfigurar dinamicamente, com o intuito de manter um bom nível de balanceamento.\nII. Uma pilha garante que o último elemento inserido seja localizado no seu topo.\nIII. Do ponto de vista conceitual, não há diferença alguma entre uma estrutura de array e uma lista encadeada.\nIV. Tabelas hash são estruturas de dados indicadas para armazenar grande volume de dados.\n\nVerifica-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "As sentenças I e IV são verdadeiras.",
      "porque": "A II também é verdadeira: pilha é LIFO."
     },
     {
      "letra": "B",
      "texto": "Apenas a sentença I é verdadeira.",
      "porque": "II e IV também são verdadeiras."
     },
     {
      "letra": "C",
      "texto": "As sentenças III e IV são verdadeiras",
      "porque": "A III é falsa: array é contíguo com acesso por índice, e lista encadeada tem nós ligados por ponteiros, com acesso sequencial."
     },
     {
      "letra": "D",
      "texto": "As sentenças II e III são verdadeiras.",
      "porque": "A III é falsa."
     },
     {
      "letra": "E",
      "texto": "Apenas I, II e IV são verdadeiras.",
      "porque": "Correta. I: a AVL se rebalanceia com rotações. II: na pilha, o último inserido fica no topo. IV: hash dá acesso rápido mesmo com muitos dados. III é falsa."
     }
    ],
    "gabarito": "E",
    "resumo": "Valores: I V, II V, III F, IV V. Array e lista encadeada diferem em acesso (índice contra sequencial), em memória (contígua contra nós espalhados) e no custo de inserir e remover.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0105",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "É INCORRETO afirmar que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "A fila de prioridade, uma estrutura de dados linear, é uma versão especial da fila.",
      "porque": "Aceitável como definição conceitual (ela é uma fila em que a ordem de saída vem da prioridade), embora a implementação em heap seja uma árvore."
     },
     {
      "letra": "B",
      "texto": "Uma lista linear é uma estrutura de dados onde elementos do mesmo tipo são organizados de forma sequencial.",
      "porque": "Verdadeira."
     },
     {
      "letra": "C",
      "texto": "Na pilha, uma estrutura não linear, os elementos são colocados e retirados por um único lado da lista, ou seja, pelo topo.",
      "porque": "Incorreta: a pilha é uma estrutura linear (elementos em sequência), e o acesso só pelo topo é o que a caracteriza."
     },
     {
      "letra": "D",
      "texto": "Na tabela de Hash por endereçamento aberto, a chave é transformada num índice inteiro que é usado para acessar os dados.",
      "porque": "Verdadeira: a função de hash converte a chave em índice."
     },
     {
      "letra": "E",
      "texto": "Um array pode ser alocado dinamicamente, situação na qual ele passa a ser denominado lista ligada ou lista encadeada.",
      "porque": "Também incorreta: um array alocado dinamicamente continua sendo um array (bloco contíguo), e não vira lista ligada."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Duas alternativas são incorretas, a C (pilha é linear) e a E (array dinâmico não é lista ligada), e a A é discutível. Por isso a banca anulou. Lembre: pilha, fila e lista são lineares; árvore e grafo, não.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0054",
      "modulo": "07-memoria-dinamica.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Para uma árvore B, de ordem \"m\", o número mínimo de descendentes para um nível \"d\" da árvore é de:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "2 * (m/2)^(d-1)",
      "porque": "É a única fórmula que cresce exponencialmente com o nível. A raiz tem pelo menos 2 filhos e cada outro nó, pelo menos m/2, então a cada nível o mínimo é multiplicado por m/2."
     },
     {
      "letra": "B",
      "texto": "d * m/2",
      "porque": "Cresce linearmente com d, mas o mínimo se multiplica por m/2 a cada nível, não se soma."
     },
     {
      "letra": "C",
      "texto": "(m*d/2)^2",
      "porque": "Não tem a estrutura da contagem por nível: o expoente 2 é fixo e não depende de d como expoente."
     },
     {
      "letra": "D",
      "texto": "[(m*d/2)^2]/2",
      "porque": "Mesmo problema da C, só dividida por 2."
     },
     {
      "letra": "E",
      "texto": "d*(m/2)^2",
      "porque": "O expoente deveria depender de d, não ser fixo em 2."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Pela regra da árvore B, a raiz tem pelo menos 2 filhos e os demais nós pelo menos ⌈m/2⌉, então o número mínimo de nós por nível cresce como uma potência de m/2: a fórmula da A. A banca anulou, provavelmente porque os expoentes se perderam na impressão do caderno (as alternativas aqui foram reconstruídas com `^`). O padrão para lembrar: mínimo por nível = 2 · (m/2) elevado a (nível menos 1).",
    "assuntos": [
     {
      "num": "0146",
      "modulo": "22-arvores-avancadas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": [
     3,
     4
    ],
    "formato": "simulação",
    "enunciado": "Dois vetores, v1 e v2, capazes de armazenar N inteiros cada um, estão ordenados de forma crescente e têm a propriedade de que o último elemento de v1 (v1[N-1]) é menor que o primeiro elemento de v2 (v2[0]). É retirado um elemento de cada vez de cada um desses vetores alternadamente, e cada elemento retirado é colocado em uma fila. Posteriormente, os elementos são retirados da fila e inseridos em uma árvore binária de busca. A árvore é percorrida em ordem simétrica, e os elementos são inseridos, assim que retirados, em uma pilha. Depois, cada elemento é retirado da pilha e inserido alternadamente em um dos vetores, começando por v1. Diante do exposto, conclui-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "v1[i] ≥ v2[i], ∀ i = 0,1,...,N-1",
      "porque": "Correta. A ordem simétrica da ABB devolve tudo crescente: v1 inteiro e depois v2 inteiro. Empilhar e desempilhar inverte: sai decrescente. Alternando começando por v1, v1[i] recebe a posição 2i e v2[i] a posição 2i+1 dessa sequência decrescente, logo v1[i] > v2[i]."
     },
     {
      "letra": "B",
      "texto": "v1[i] ≤ v2[i], ∀ i = 0,1,...,N-1",
      "porque": "É o contrário: como a sequência sai decrescente, o elemento da posição 2i é maior que o da posição 2i+1."
     },
     {
      "letra": "C",
      "texto": "v1[N-1] > v2[0]",
      "porque": "Em v1[N-1] cai um dos menores valores e em v2[0], um dos maiores: v1[N-1] é menor que v2[0]."
     },
     {
      "letra": "D",
      "texto": "As listas não estão mais ordenadas.",
      "porque": "Estão ordenadas, só que agora em ordem decrescente."
     },
     {
      "letra": "E",
      "texto": "Todos os elementos de v1 estão armazenados em v2 e vice-versa.",
      "porque": "Não: v1 fica com os elementos das posições pares da sequência e v2 com os das ímpares. Eles se misturam, mas não se trocam por inteiro."
     }
    ],
    "gabarito": "A",
    "resumo": "Acompanhe cada estrutura: a fila preserva a ordem de entrada; a ABB percorrida em ordem simétrica devolve tudo crescente; a pilha inverte, ficando decrescente; ao distribuir alternando, v1 pega as posições pares e v2 as ímpares. Logo cada v1[i] vem imediatamente antes de v2[i] numa sequência decrescente, então v1[i] ≥ v2[i]. Dica: transforme em exemplo com N = 2.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0098",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 11,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Para remoção de uma chave cuja página esteja com o número mínimo, em árvore B, é CORRETO afirmar que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Deve-se fazer o processo de SPLIT sempre na página onde se encontrar a chave.",
      "porque": "Split é da inserção (página cheia), não da remoção."
     },
     {
      "letra": "B",
      "texto": "Deve-se fazer o processo de SPLIT na página onde se encontrar a chave, exceto quanto é um elemento da raiz da árvore.",
      "porque": "Mesmo erro: remoção não usa split."
     },
     {
      "letra": "C",
      "texto": "Se a página onde se encontrar a chave não é folha, deve-se fazer procedimento de concatenação ou redistribuição, considerando os irmãos.",
      "porque": "Impreciso: em nó interno a chave é substituída pela sucessora ou antecessora da folha, e a redistribuição ou concatenação ocorre depois, na folha."
     },
     {
      "letra": "D",
      "texto": "Remove-se a chave, e a substitui por uma chave do nó irmão.",
      "porque": "A redistribuição passa pelo pai: a chave do pai desce e a do irmão sobe. Trocar direto com o irmão quebra a ordem."
     },
     {
      "letra": "E",
      "texto": "No caso de só haver uma única página, a remoção não causa a necessidade de balanceamento.",
      "porque": "Correta. Com uma única página (a raiz, que é folha) não há mínimo a respeitar, então a remoção não exige redistribuir nem concatenar."
     }
    ],
    "gabarito": "E",
    "resumo": "Remoção em árvore B: se a página fica abaixo do mínimo, redistribua com o irmão ou concatene; split é da inserção; a raiz é a exceção ao mínimo. Aqui a questão não foi anulada e a letra é E (na 055/2017 a mesma questão foi anulada).",
    "assuntos": [
     {
      "num": "0146",
      "modulo": "22-arvores-avancadas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Lista circular encadeada é uma das estruturas de dados dinâmicas básicas. Uma questão que deve ser resolvida pelo algoritmo de busca em lista circular encadeada é:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Saber quando finalizar a busca, se o elemento procurado não estiver na lista circular.",
      "porque": "Correta. Na lista circular o último nó aponta para o primeiro e não existe ponteiro nulo. Se o elemento não está na lista, a busca daria voltas sem fim, então é preciso marcar o ponto de parada (voltar ao nó inicial)."
     },
     {
      "letra": "B",
      "texto": "Retornar o elemento anterior ao buscado, dada a propriedade de circularidade da lista.",
      "porque": "Não é um problema da busca. A circularidade não força devolver o anterior."
     },
     {
      "letra": "C",
      "texto": "Devolver o número de elementos constantes na lista.",
      "porque": "Contar elementos é outra operação, não a questão específica da busca."
     },
     {
      "letra": "D",
      "texto": "Parar a busca assim que encontrar um elemento cujo ponteiro para o próximo elemento tenha valor nulo, o que indica o fim da lista.",
      "porque": "Numa lista circular não há ponteiro nulo (o último aponta para o primeiro), então essa condição nunca ocorre."
     },
     {
      "letra": "E",
      "texto": "Devolver o ponteiro de marcação de início, em sua nova posição",
      "porque": "Não faz parte do problema de buscar um elemento."
     }
    ],
    "gabarito": "A",
    "resumo": "Em lista simples o fim é o ponteiro nulo; na circular não há nulo, então a busca precisa de outra condição de parada (voltar ao ponto de partida), senão entra em laço infinito quando o elemento não existe.",
    "assuntos": [
     {
      "num": "0080",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Suponha que uma Árvore Binária de Busca possui números entre 1 e 1000 e que se quer procurar pelo número 363. Qual sequência abaixo NÃO poderia ser a sequência de nós examinados?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "2, 252, 401, 398, 330, 344, 397, 363.",
      "porque": "Possível: cada nó cabe no intervalo aberto pelas decisões anteriores (397 em (344, 398))."
     },
     {
      "letra": "B",
      "texto": "924, 220, 911, 244, 898, 258, 362, 363.",
      "porque": "Possível: 911 em (220, 924), 244 em (220, 911), 898 em (244, 911), 258 em (244, 898) e 362 em (258, 898)."
     },
     {
      "letra": "C",
      "texto": "925, 202, 911, 240, 912, 245, 363.",
      "porque": "Correta (é a que não pode ocorrer). Depois do 911 a busca vai à esquerda, então os nós seguintes estão abaixo de 911; o 240 está à direita de 202 e o 912 sairia do intervalo (240, 911)."
     },
     {
      "letra": "D",
      "texto": "2, 399, 387, 219, 266, 382, 381, 278, 363.",
      "porque": "Possível: 219 em (2, 387), 266 em (219, 387), 382 em (266, 387), 381 em (266, 382) e 278 em (266, 381)."
     },
     {
      "letra": "E",
      "texto": "935, 278, 347, 621, 350, 392, 358, 363.",
      "porque": "Possível: 350 em (347, 621), 392 em (350, 621) e 358 em (350, 392). Esta versão corrige a da prova de 055/2017, que trazia 299."
     }
    ],
    "gabarito": "C",
    "resumo": "Para validar a sequência, mantenha o intervalo (mínimo, máximo): ao ir à esquerda de x, o máximo vira x; à direita, o mínimo vira x. Todo nó seguinte precisa caber nele. Só a C viola isso (912 > 911, no ramo à esquerda de 911). É a mesma questão da 055/2017, lá anulada por ter duas impossíveis.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Analise as afirmativas a seguir sobre árvores B e árvores binárias\n\nI. Diferente das árvores binárias, cada nó de uma árvore B deverá sempre ter mais de dois filhos.\nII. Um nó de árvore B tem um campo ou um método para indicar se é um nó folha ou não. Característica esta herdada da AVL.\nIII. As folhas da árvore B são dispostas mais flexivelmente que as da árvore binária: suas folhas poderão estar em níveis diferentes, desde zero até o valor da altura da árvore.\nIV. A árvore B tem um método de balanceamento muito custoso, por isso, sua indicação para trabalhar com dispositivos de armazenamento secundário, deve ser avaliada com muita cautela.\n\ne assinale a alternativa CORRETA.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas as afirmativas estão corretas.",
      "porque": "As quatro são falsas."
     },
     {
      "letra": "B",
      "texto": "Somente as afirmativas II e III estão corretas",
      "porque": "II e III são falsas."
     },
     {
      "letra": "C",
      "texto": "Somente as afirmativas I, II e IV estão corretas.",
      "porque": "I, II e IV são falsas."
     },
     {
      "letra": "D",
      "texto": "Somente as afirmativas I, III e IV estão corretas.",
      "porque": "I, III e IV são falsas."
     },
     {
      "letra": "E",
      "texto": "Todas as afirmativas estão incorretas",
      "porque": "Correta. I falsa: um nó pode ter só 2 filhos (a raiz sempre pode). II falsa: a AVL não tem campo de folha. III falsa: todas as folhas ficam no mesmo nível. IV falsa: o balanceamento é barato e a árvore B foi feita para armazenamento secundário."
     }
    ],
    "gabarito": "E",
    "resumo": "Valores: I F, II F, III F, IV F. Árvore B: folhas todas no mesmo nível, nós com entre ⌈m/2⌉ e m filhos (raiz com pelo menos 2) e balanceamento local por split e concatenação. É a estrutura típica de disco.",
    "assuntos": [
     {
      "num": "0146",
      "modulo": "22-arvores-avancadas.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Se em uma árvore binária de pesquisa a diferença de altura entre a subárvore à esquerda e a subarvore à direita de um dos nós for maior que 1, pode-se concluir que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "A árvore é uma árvore AVL.",
      "porque": "É o contrário: diferença maior que 1 num nó viola a regra, então não é AVL."
     },
     {
      "letra": "B",
      "texto": "Trata-se com certeza de uma árvore binária sem balanceamento.",
      "porque": "Não há certeza: a rubro-negra é uma árvore balanceada e admite essa diferença em alguns nós. Só dá para dizer que não é AVL."
     },
     {
      "letra": "C",
      "texto": "Trata-se com certeza de uma árvore vermelho e preto.",
      "porque": "Também sem certeza: pode ser uma ABB comum."
     },
     {
      "letra": "D",
      "texto": "Tal árvore não pode existir por não se tratar de uma árvore binária de pesquisa.",
      "porque": "Pode existir: ABB não restringe as alturas."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores está correta.",
      "porque": "Correta. Com a informação dada você só descarta a AVL; não dá para afirmar com certeza se é rubro-negra ou ABB sem balanceamento."
     }
    ],
    "gabarito": "E",
    "resumo": "Diferença de altura maior que 1 num nó exclui AVL, mas nada mais. A rubro-negra é balanceada de outro jeito e admite essa diferença, e uma ABB comum também. Cuidado com as palavras 'com certeza'.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0145",
      "modulo": "22-arvores-avancadas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as seguintes afirmações:\n\nI. Hash por encadeamento nunca apresenta colisões secundárias\nII. Hash por encadeamento jamais permite que o número de comparações entre chaves em uma operação de busca passe de log n, onde n é o número de chaves inseridas no hash.\nIII. Hash por encadeamento realiza sempre menos comparações entre chaves do que qualquer hash por endereçamento aberto.\n\nAgora marque a alternativa CORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a afirmação I é verdadeira",
      "porque": "Correta. Colisão secundária (chaves de endereços diferentes disputando posições) é fenômeno do endereçamento aberto; no encadeamento só dividem lista as chaves com o mesmo endereço. II e III são falsas."
     },
     {
      "letra": "B",
      "texto": "Apenas a afirmação II é verdadeira",
      "porque": "A II é falsa: no pior caso todas as n chaves caem numa só lista e a busca faz n comparações, mais que log n."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmação III é verdadeira",
      "porque": "A III é falsa: 'sempre' e 'qualquer' são exagero, e com poucas chaves e tabela esparsa o endereçamento aberto pode fazer menos."
     },
     {
      "letra": "D",
      "texto": "Apenas as afirmações II e III são verdadeiras",
      "porque": "As duas são falsas."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores está correta",
      "porque": "A A está correta."
     }
    ],
    "gabarito": "A",
    "resumo": "Valores: I V, II F, III F. Palavras absolutas ('nunca', 'jamais', 'sempre') pedem um contraexemplo: na II, a lista única com n chaves; na III, uma tabela aberta pouco ocupada. A I é verdadeira porque colisão secundária é conceito de endereçamento aberto.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 17,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações abaixo:\n\nI. O RADIX sort não realiza comparação entre chaves para realizar a ordenação de um vetor\nII. O número de vezes que é necessário passar por todos os elementos do vetor no RADIX sort é proporcional ao número médio de dígitos dos elementos do vetor na base utilizada pelo algoritmo para ordenação\nIII. O RADIX sort requer um espaço extra de armazenamento proporcional ao tamanho do vetor\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas a afirmação I é verdadeira",
      "porque": "A III também é verdadeira (vetor auxiliar de tamanho n)."
     },
     {
      "letra": "B",
      "texto": "Apenas a afirmação II é verdadeira",
      "porque": "A II não é a única, e é falsa como escrita: o número de passadas é o de dígitos da maior chave, não a média."
     },
     {
      "letra": "C",
      "texto": "Apenas a afirmação III é verdadeira",
      "porque": "A I também é verdadeira."
     },
     {
      "letra": "D",
      "texto": "Apenas as afirmações II e III são verdadeiras",
      "porque": "A I é verdadeira e a II, como escrita, é falsa."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das afirmações é verdadeira",
      "porque": "I e III são verdadeiras, então não é o caso."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Valores: I V (radix distribui por dígito, sem comparar chaves), II F (as passadas seguem os dígitos da maior chave, não a média), III V (vetor auxiliar proporcional a n). Como I e III são verdadeiras, nenhuma alternativa serve, e a banca anulou. Para radix: O(d·(n+k)) tempo e O(n+k) espaço.",
    "assuntos": [
     {
      "num": "0121",
      "modulo": "18-ordenacao-linear.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Considere as afirmações sobre um hash por encadeamento:\n\nI. Tem como desvantagem o fato de não ordenar as chaves inseridas\nII. O número médio de operações esperado para realizar uma busca é constante se o hash for bem projetado\nIII. Mesmo quando bem implementado, ocupa mais espaço extra do que uma árvore B em memória.\n\nSobre as afirmações, sabe-se que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Todas as afirmações são verdadeiras",
      "porque": "A III é discutível, e a banca não a aceitou como verdadeira."
     },
     {
      "letra": "B",
      "texto": "Todas as afirmações são falsas",
      "porque": "I e II são verdadeiras."
     },
     {
      "letra": "C",
      "texto": "Apenas as afirmações I e III são verdadeiras",
      "porque": "A II também é verdadeira e a III é discutível."
     },
     {
      "letra": "D",
      "texto": "Apenas a afirmação III é verdadeira",
      "porque": "I e II são verdadeiras."
     },
     {
      "letra": "E",
      "texto": "Apenas as afirmações I e II são verdadeiras",
      "porque": "Correta pela banca. I: hash não mantém ordem. II: com boa função e fator de carga controlado a busca média é O(1). III é duvidosa: depende da comparação de espaço entre ponteiros de listas e páginas parcialmente vazias da árvore B."
     }
    ],
    "gabarito": "E",
    "resumo": "Hash: busca média O(1) se bem projetado, mas sem ordem entre as chaves (sem percurso ordenado, sem busca por intervalo). A III é discutível e a banca a tratou como falsa; fique com E nesta questão.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Quanto ao algoritmo e estrutura de dados no caso de árvore AVL, analise as afirmativas abaixo como verdadeiras (V) ou falsas (F) e assinale a alternativa que apresenta a sequência CORRETA de cima para baixo:\n\n( ) Uma árvore AVL é dita balanceada quando, para cada nó da árvore, a diferença entre as alturas das suas sub-árvores (direita e esquerda) não é maior do que um.\n( ) Caso haja diferença de altura maior que 1 ente as sub-árvores à direita e à esquerda de qualquer nó, é necessário que se realizem rotações com o objetivo de reduzir tal diferença.\n( ) A operação de rotação realizada em um ponto da árvore, após a inserção, pode resultar em uma árvore ainda desbalanceada, podendo ser necessária a realização de novas rotações que, na pior das hipóteses, podem ser propagadas até a raiz.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "F-V-V",
      "porque": "A 1ª é V (é a definição) e a 3ª é F."
     },
     {
      "letra": "B",
      "texto": "F-F-V",
      "porque": "A 1ª é V e a 2ª também."
     },
     {
      "letra": "C",
      "texto": "V-F-F",
      "porque": "A 2ª é V: diferença maior que 1 exige rotação."
     },
     {
      "letra": "D",
      "texto": "V-V-F",
      "porque": "Correta. 1ª V: é a definição de AVL. 2ª V: diferença maior que 1 pede rotação. 3ª F: depois de uma inserção, uma rotação (simples ou dupla) restaura o balanceamento; a propagação até a raiz é característica da remoção."
     },
     {
      "letra": "E",
      "texto": "V-V-V",
      "porque": "A 3ª é falsa para a inserção."
     }
    ],
    "gabarito": "D",
    "resumo": "Sequência V, V, F. Inserção em AVL: no máximo uma rotação (simples ou dupla) conserta a árvore. Remoção: pode exigir rotações em vários níveis, subindo até a raiz. Essa diferença é pergunta recorrente.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0176",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "Dados os seguinte valores de entrada - 11, 12, 23, 14, 25, 50, 8, 18, 29, 10 -, insira-os em uma PILHA. Em seguida retire cada um dos valores da PILHA e insira numa FILA. Mostre a FILA. Depois retire os dados da FILA e insira na PILHA. Mostre a PILHA.\n\nAs valores MOSTRADOS ficam\n\nI. FILA (começo) 10 - 29 - 18 - 8 - 50 - 25 - 14 - 23 - 12 - 11 (fim)\nII. PILHA: (topo) 11 - 12 - 23 - 14 - 25 - 50 - 8 - 18 - 29 - 10\nIII. PILHA: (topo) 10 - 29 - 18 - 8 - 50 - 25 - 14 - 23 - 12 - 11\nIV. FILA: (começo) 11 - 12 - 23 - 14 - 25 - 50 - 8 - 18 - 29 – 10 (fim)\n\nEstá CORRETO o que se afirma APENAS em:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I e II",
      "porque": "Correta. Pilha com topo 10: ao desempilhar, sai 10, 29, 18, ..., 11, e a fila fica com 10 no começo e 11 no fim (I). Retirando da fila e empilhando de novo, o 10 entra primeiro e o 11 por último, então o topo é 11 (II)."
     },
     {
      "letra": "B",
      "texto": "I e IV",
      "porque": "A I é verdadeira, mas a IV é falsa: a fila começa em 10, não em 11."
     },
     {
      "letra": "C",
      "texto": "II e III",
      "porque": "A II é verdadeira, mas a III é falsa: o topo da pilha final é 11, não 10."
     },
     {
      "letra": "D",
      "texto": "III e IV",
      "porque": "As duas são falsas."
     },
     {
      "letra": "E",
      "texto": "III e IV",
      "porque": "Repetida da D (as duas são falsas)."
     }
    ],
    "gabarito": "A",
    "resumo": "Duas inversões voltam à ordem original: empilhar inverte, a fila preserva a ordem de saída da pilha, e empilhar de novo inverte outra vez. A fila tem 10 no começo (I) e a pilha final tem o 11 no topo (II). Atenção: as alternativas D e E do caderno são iguais, e a letra A é inferência a partir da conta.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "033/2019",
  "slug": "2019-033",
  "ano": 2019,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": 7,
    "formato": "simulação",
    "enunciado": "Sabendo que o algoritmo Quick Sort classifica os elementos em ordem crescente usando o primeiro elemento como pivô, qual das seguintes sequências de entrada irá requerer o maior número de comparações quando o algoritmo for aplicado?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "22 25 33 42 56 67 89",
      "porque": "A sequência já está em ordem crescente. O pivô (primeiro elemento) é sempre o menor, então cada partição deixa 0 elementos de um lado e todo o resto do outro: 6+5+4+3+2+1 = 21 comparações. É o pior caso, Θ(n²)."
     },
     {
      "letra": "B",
      "texto": "63 70 47 42 36 38 73",
      "porque": "O pivô 63 separa 4 menores de 2 maiores, e as partições seguintes também ficam razoavelmente equilibradas. Contando n-1 por partição, dá 13 comparações, bem abaixo de 21."
     },
     {
      "letra": "C",
      "texto": "42 25 22 33 67 56 89",
      "porque": "O pivô 42 cai quase no meio (3 menores, 3 maiores) e os subproblemas também se dividem bem. Dá 10 comparações, o melhor caso das cinco."
     },
     {
      "letra": "D",
      "texto": "13 52 25 58 10 22 17",
      "porque": "O pivô 13 deixa só o 10 à esquerda, mas o resto se divide de forma desigual sem chegar à degeneração total. Dá 13 comparações."
     },
     {
      "letra": "E",
      "texto": "23 25 33 42 11 22 30",
      "porque": "O pivô 23 separa 2 menores de 4 maiores e as partições seguintes ficam curtas. Dá 12 comparações."
     }
    ],
    "gabarito": "A",
    "resumo": "Com o pivô no primeiro elemento, a entrada já ordenada (crescente ou decrescente) é o pior caso do Quick Sort: cada partição tira só 1 elemento e o total vai a n(n-1)/2 comparações. Contei n-1 comparações por partição; outras variantes do particionamento mudam um pouco os números das outras alternativas, mas a ordenada continua sendo a pior. Na prova, procure primeiro a sequência já ordenada.",
    "assuntos": [
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "A parte essencial do Heap Sort é a construção do heap máximo. Considerando a árvore mostrada abaixo, o nó 24 viola a propriedade do heap máximo. Uma vez que o procedimento de heap é aplicado a ele, em que posição ele estará?",
    "figuras": [
     "2019-033-q02"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "4",
      "porque": "A posição 4 é onde o 24 chega depois da primeira troca (com o 44, o maior filho). Mas ali os filhos são 5 e 28, e 28 > 24, então ele ainda desce mais uma vez."
     },
     {
      "letra": "B",
      "texto": "5",
      "porque": "A posição 5 guarda o 7, que é o filho menor do 24. O sift-down sempre troca com o maior filho (44), nunca com o menor."
     },
     {
      "letra": "C",
      "texto": "8",
      "porque": "A posição 8 guarda o 5, que é menor que 28. Dos dois filhos da posição 4 (5 e 28), o maior é o 28, que está na posição 9."
     },
     {
      "letra": "D",
      "texto": "9",
      "porque": "Correta. O 24 troca com o maior filho, o 44 (posição 4). Aí seus filhos são 5 e 28; troca com o 28 (posição 9). A posição 9 é folha, então o 24 para ali."
     },
     {
      "letra": "E",
      "texto": "6",
      "porque": "A posição 6 guarda o 11, que fica na subárvore direita (sob o 30). O 24 só desce pela subárvore onde está, a esquerda."
     }
    ],
    "gabarito": "D",
    "resumo": "O sift-down (heapify) compara o nó com seus dois filhos e troca com o maior, repetindo até o nó ser maior que os filhos ou virar folha. Aqui: 24 troca com 44 (posição 4) e depois com 28 (posição 9). Em questões assim, acompanhe a posição a cada troca e confira se o novo nó ainda tem filho maior.",
    "assuntos": [
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2019-033/figuras/q02-heap.png"
    ]
   },
   {
    "numero": 3,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "Considere a seguinte operação em uma pilha de tamanho 5:\nPush(1); Pop(); Push(2); Push(3); Pop(); Push(4); Pop(); Pop(); Push(5);\nApós a todos as operações serem realizadas, o número de elementos presentes na pilha é:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "1",
      "porque": "Correta. São 5 push e 4 pop, e nenhum pop acontece com a pilha vazia. 5 - 4 = 1 elemento: o 5. Passo a passo: [1] → [] → [2] → [2 3] → [2] → [2 4] → [2] → [] → [5]."
     },
     {
      "letra": "B",
      "texto": "2",
      "porque": "Daria 2 se um dos pops tivesse sido ignorado. Os quatro pops removem elementos reais, então sobra 5 - 4 = 1."
     },
     {
      "letra": "C",
      "texto": "3",
      "porque": "Não bate com a conta: 5 inserções menos 4 remoções dão 1, não 3."
     },
     {
      "letra": "D",
      "texto": "4",
      "porque": "Quatro é o número de pops, não o de elementos que sobram."
     },
     {
      "letra": "E",
      "texto": "5",
      "porque": "Cinco é o número de push. Você precisa descontar os pops."
     }
    ],
    "gabarito": "A",
    "resumo": "Em pilha, o tamanho final é pushes menos pops, desde que nunca haja pop em pilha vazia nem push em pilha cheia. Faça a trilha passo a passo, que leva menos de um minuto. A capacidade 5 não é atingida em nenhum momento.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "A figura abaixo mostra uma árvore B de ordem 5. Qual é o resultado da remoção do nó 130 dessa árvore?",
    "figuras": [
     "2019-033-q04"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "árvore da figura a)",
      "porque": "Deixa a folha com só o 110 e o resto da árvore igual. Com ordem 5, cada nó (fora a raiz) precisa de no mínimo 2 chaves, então um nó com 1 chave viola a regra. O correto é tratar o underflow.",
      "figura": "2019-033-q04-a"
     },
     {
      "letra": "B",
      "texto": "árvore da figura b)",
      "porque": "É uma árvore ordenada, mas não sai de nenhuma operação padrão de remoção: aqui o 100 desceu para a folha da esquerda e o 110 subiu para a raiz. A remoção padrão funde a folha com um irmão, desce o separador e não sobe chave de folha.",
      "figura": "2019-033-q04-b"
     },
     {
      "letra": "C",
      "texto": "árvore da figura c)",
      "porque": "Correta. Ao tirar o 130, a folha fica com só o 110 (mínimo é 2). Os dois irmãos vizinhos têm exatamente 2 chaves e não podem emprestar. Então funde com o da direita, descendo o separador 140: folha `110 140 144 156` (4 chaves, o máximo). A raiz perde o 140 e fica `100 160`.",
      "figura": "2019-033-q04-c"
     },
     {
      "letra": "D",
      "texto": "árvore da figura d)",
      "porque": "Tem o 110 repetido (na raiz e na folha) e o 140 aparece na raiz sem ser separador de nada coerente. Chave duplicada não existe em árvore B.",
      "figura": "2019-033-q04-d"
     },
     {
      "letra": "E",
      "texto": "Nenhuma das anteriores",
      "porque": "Existe a alternativa c) que é o resultado correto."
     }
    ],
    "gabarito": "C",
    "resumo": "Na remoção em árvore B: se a folha fica abaixo do mínimo, tente emprestar de um irmão que tenha mais que o mínimo (rotação pelo pai). Se os irmãos estão no mínimo, funda com um irmão e desça o separador do pai. Na ordem 5 o mínimo é 2 chaves e o máximo 4. O enunciado original tem as figuras desalinhadas, e b) também é um B-tree válido, mas só c) sai da fusão padrão.",
    "assuntos": [
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2019-033/figuras/q04-arvore-b.png",
     "provas-ppgi-ufam/2019-033/figuras/q04-opcoes-ab.png",
     "provas-ppgi-ufam/2019-033/figuras/q04-opcoes-cd.png"
    ]
   },
   {
    "numero": 5,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "No pior dos casos, o número de comparações necessárias para pesquisar uma lista simplesmente encadeada de comprimento n para um dado elemento é",
    "alternativas": [
     {
      "letra": "A",
      "texto": "log2 n",
      "porque": "Esse é o custo da busca binária em vetor ordenado. Lista encadeada não tem acesso direto ao meio, então não dá para dividir ao meio em O(1)."
     },
     {
      "letra": "B",
      "texto": "n/2",
      "porque": "Seria o número médio se o elemento estivesse em posição uniformemente aleatória. O pior caso (último elemento ou ausente) é maior."
     },
     {
      "letra": "C",
      "texto": "log2 n - 1",
      "porque": "Não corresponde a nenhuma busca em lista encadeada."
     },
     {
      "letra": "D",
      "texto": "n",
      "porque": "Vale: no pior caso o elemento é o último ou não existe, e você percorre os n nós. A banca anulou a questão, mas esse é o resultado conceitual."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das anteriores",
      "porque": "Falsa, porque a alternativa d) descreve o pior caso corretamente."
     }
    ],
    "gabarito": "anulada",
    "resumo": "A banca anulou. Conceitualmente, a busca sequencial em lista simplesmente encadeada faz n comparações no pior caso, Θ(n), e n/2 em média. Lista não permite busca binária.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0077",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 3,
    "formato": "código",
    "enunciado": "Qual é a saída da seguinte função que inicia apontando para o primeiro nó da seguinte lista encadeada?\n\n`1->2->3->4->5->6`\n\n```c\nvoid fun(struct node* start)\n{\n  if(start == NULL)\n    return;\n  printf(\"%d \", start->data);\n  if(start->next != NULL )\n    fun(start->next->next);\n  printf(\"%d \", start->data);\n}\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "1 4 6 6 4 1",
      "porque": "A função pula de dois em dois (`next->next`): visita 1, 3, 5, não 1, 4, 6."
     },
     {
      "letra": "B",
      "texto": "1 3 5 1 3 5",
      "porque": "Os nós certos, mas a ordem da volta está errada. O segundo printf roda depois da chamada recursiva, então imprime na ordem inversa: 5 3 1."
     },
     {
      "letra": "C",
      "texto": "1 2 3 5",
      "porque": "Não tem relação com o código: a função nunca imprime o 2."
     },
     {
      "letra": "D",
      "texto": "1 3 5 5 3 1",
      "porque": "Correta. Na ida imprime 1, 3, 5. No 5, `next` é o 6 (não nulo), então chama `fun(NULL)`, que retorna. Na volta, cada chamada imprime de novo: 5, 3, 1."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das anteriores",
      "porque": "Existe a d), que bate com o resultado."
     }
    ],
    "gabarito": "D",
    "resumo": "Recursão com print antes e depois da chamada produz um espelho: ida na ordem, volta ao contrário. Aqui o passo é de 2 em 2 nós, e o 5 ainda imprime duas vezes porque seu `next` (o 6) não é nulo. Rodei em C para conferir.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Qual estrutura de dados é comumente usada para implementar recursão?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Queue (fila)",
      "porque": "Fila é FIFO. A última chamada feita precisa ser a primeira a terminar (LIFO), o oposto."
     },
     {
      "letra": "B",
      "texto": "Stack (pilha)",
      "porque": "Correta. Cada chamada empilha um registro de ativação (parâmetros, variáveis locais, endereço de retorno) e, ao retornar, desempilha. LIFO é exatamente a ordem das chamadas aninhadas."
     },
     {
      "letra": "C",
      "texto": "Array (vetor)",
      "porque": "Vetor é a estrutura de armazenamento, mas não define o comportamento de empilhar e desempilhar chamadas."
     },
     {
      "letra": "D",
      "texto": "Lista",
      "porque": "Lista encadeada genérica não impõe a ordem LIFO que a recursão exige."
     },
     {
      "letra": "E",
      "texto": "Matriz",
      "porque": "Estrutura bidimensional sem relação com o controle de chamadas."
     }
    ],
    "gabarito": "B",
    "resumo": "Recursão usa a pilha de chamadas (call stack). Por isso recursão muito funda estoura a pilha (stack overflow), e por isso toda recursão pode virar iteração com uma pilha explícita.",
    "assuntos": [
     {
      "num": "0031",
      "modulo": "04-funcoes.md"
     },
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Quais são, respectivamente, o pior caso e o caso médio de uma árvore de busca binária em termos de complexidade?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O(n), O(n)",
      "porque": "O pior caso é O(n), mas o caso médio (inserções em ordem aleatória) tem altura esperada O(log n), não O(n)."
     },
     {
      "letra": "B",
      "texto": "O(logn), O(logn)",
      "porque": "O pior caso não é O(log n): inserir chaves em ordem crescente faz a árvore virar uma lista, com altura n."
     },
     {
      "letra": "C",
      "texto": "O(logn), O(n)",
      "porque": "Está invertida: o pior caso é o O(n), e o médio é o O(log n)."
     },
     {
      "letra": "D",
      "texto": "O(n), O(logn)",
      "porque": "Correta. Sem balanceamento, chaves ordenadas degeneram a árvore em lista (altura n, pior caso O(n)). Com chaves aleatórias a altura esperada é O(log n)."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das respostas anteriores.",
      "porque": "Existe a d)."
     }
    ],
    "gabarito": "D",
    "resumo": "ABB comum: pior caso O(n) (árvore degenerada), médio O(log n). Para garantir O(log n) no pior caso você precisa de balanceamento (AVL, rubro-negra).",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Uma árvore B de ordem 4 e de altura 3, onde ordem é o número máximo de filhos em cada nó, terá um máximo de chaves igual a?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "255",
      "porque": "Correta. Ordem 4: cada nó tem até 4 filhos e 3 chaves. Altura 3 (em arestas) dá 4 níveis: 1 + 4 + 16 + 64 = 85 nós, e 85 × 3 = 255 chaves."
     },
     {
      "letra": "B",
      "texto": "63",
      "porque": "Resulta de contar 'altura 3' como 3 níveis: 1 + 4 + 16 = 21 nós × 3 = 63. Mas a convenção do Cormen (altura em arestas) dá 4 níveis."
     },
     {
      "letra": "C",
      "texto": "127",
      "porque": "É 2^7 - 1, número de nós de uma árvore binária cheia com 7 níveis. Não vale para ordem 4."
     },
     {
      "letra": "D",
      "texto": "188",
      "porque": "Não vem de nenhuma fórmula coerente com ordem 4 e altura 3."
     },
     {
      "letra": "E",
      "texto": "256",
      "porque": "É 4^4. Seria 255 + 1, mas o máximo de chaves é nós × 3, sem 'chave extra'."
     }
    ],
    "gabarito": "A",
    "resumo": "Máximo de chaves = (nós de uma árvore completa) × (ordem - 1). Com ordem m e altura h em arestas, os nós são (m^(h+1) - 1)/(m - 1). Aqui (4^4 - 1)/3 = 85. Se a banca contasse altura em níveis, a resposta seria a B (63); o gabarito oficial é a A, que bate com a convenção das arestas.",
    "assuntos": [
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Suponha uma tabela hash vazia com tamanho m = 17, utilizando o método da divisão para chaves de valores naturais e endereçamento aberto. Considere as sentenças abaixo:\n\nI. Após inserir as chaves 5, 10, 22, 42 e 39, utilizando sondagem linear, terá havido um total de 2 colisões\nII. As chaves 5, 10, 22, 42 e 39 poderiam ser inseridas sem colisão se utilizássemos uma função dispersão dupla (double hash)\nIII. É possível inserir 17 chaves nessa tabela sem que ocorra nenhuma colisão.\n\nMarque a alternativa CORRETA",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Somente a sentença I está correta",
      "porque": "Propõe só I verdadeira. Mas I depende de como contar: os endereços são 5, 10, 5, 8, 5. O 22 colide uma vez e o 39 colide duas (com 5 e 22 nas posições 5 e 6), total de 3 colisões. Além disso III é verdadeira."
     },
     {
      "letra": "B",
      "texto": "As sentenças I e II estão correta",
      "porque": "Propõe I e II. II é falsa: 5, 22 e 39 têm o mesmo h1 (= 5), e a primeira tentativa do hash duplo é sempre h1, então 22 e 39 colidem de qualquer jeito."
     },
     {
      "letra": "C",
      "texto": "Somente a sentença III está correta",
      "porque": "Contando eventos de colisão (3), I é falsa; II é falsa; III é verdadeira (as chaves 0 a 16 caem em endereços todos diferentes). Essa é a leitura mais natural, mas a banca anulou."
     },
     {
      "letra": "D",
      "texto": "As sentenças I e III estão correta",
      "porque": "Só funciona se 'colisões' contar as chaves que colidiram (22 e 39, ou seja, 2). Aí I vira verdadeira, junto com III."
     },
     {
      "letra": "E",
      "texto": "Todas as sentenças estão corretas",
      "porque": "Exige II verdadeira, que falha: 22 e 39 colidem já na primeira sondagem."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Valores: I depende de como contar (3 colisões se cada passo em posição ocupada conta; 2 se contar chaves que colidiram). II é falsa, porque a 1ª posição do hash duplo é a mesma do linear. III é verdadeira. Contando eventos, a resposta é C; contando chaves, é D. Essa ambiguidade é o provável motivo da anulação.",
    "assuntos": [
     {
      "num": "0105",
      "modulo": "15-hash.md"
     },
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 11,
    "topico": 3,
    "formato": "código",
    "enunciado": "Qual a função do seguinte trecho de código?\n\n```java\npublic void function(int data)\n{\n  int flag = 0;\n  if( head != null)\n  {\n    Node temp = head.getNext();\n    while((temp != head) && (!(temp.getItem() == data)))\n    {\n      temp = temp.getNext();\n      flag = 1;\n      break;\n    }\n  }\n  if(flag)\n    System.out.println(\"success\");\n  else\n    System.out.println(\"fail\");\n}\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Imprimir sucess se um determinado elemento não for encontrado",
      "porque": "O código imprime success quando `flag` vale 1, e isso acontece quando o laço entra uma vez, sem relação direta com 'não encontrado'."
     },
     {
      "letra": "B",
      "texto": "Imprimir fail se um determinado elemento não for encontrado",
      "porque": "Gabarito oficial. A intenção é uma busca em lista circular que imprime fail quando não acha. O código real está truncado e com `break` incondicional, então a leitura é a mais próxima do que a banca quis."
     },
     {
      "letra": "C",
      "texto": "Imprimir sucess se um elemento em particular for igual a 1",
      "porque": "O 1 é o valor da `flag`, não do dado buscado."
     },
     {
      "letra": "D",
      "texto": "Imprimir fail se a lista estiver vazia e success caso contrário",
      "porque": "Lista vazia imprime fail, mas lista não vazia também pode imprimir fail (se o segundo nó for a cabeça ou o dado)."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das respostas anteriores.",
      "porque": "Era a leitura do curso: o `break` incondicional faz o laço rodar no máximo uma vez, então o código não busca de forma coerente. A banca preferiu a B."
     }
    ],
    "gabarito": "B",
    "resumo": "O gabarito oficial é B, mas o código é estranho: é Java misturado com C (`if(flag)` com inteiro não compila em Java) e o `break` incondicional impede a busca de verdade. Na análise do curso, a resposta seria E. Em prova, quando o código é torto assim, escolha a alternativa que descreve a intenção (buscar em lista circular e imprimir fail se não achar).",
    "assuntos": [
     {
      "num": "0080",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Qual é a altura máxima de qualquer árvore AVL com 7 nós? Assuma que a altura de uma árvore com um único nó seja 0.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "2",
      "porque": "Altura 2 é a altura mínima possível: uma árvore perfeita de altura 2 tem exatamente 7 nós. Mas a pergunta é a altura máxima."
     },
     {
      "letra": "B",
      "texto": "3",
      "porque": "Correta. O mínimo de nós para uma AVL de altura h é N(h) = N(h-1) + N(h-2) + 1, com N(0) = 1 e N(1) = 2: dá 1, 2, 4, 7. Com 7 nós cabe altura 3, e para altura 4 você precisaria de 12."
     },
     {
      "letra": "C",
      "texto": "4",
      "porque": "Uma AVL de altura 4 exige no mínimo 12 nós."
     },
     {
      "letra": "D",
      "texto": "5",
      "porque": "Altura 5 exige no mínimo 20 nós."
     },
     {
      "letra": "E",
      "texto": "6",
      "porque": "Altura 6 exige no mínimo 33 nós."
     }
    ],
    "gabarito": "B",
    "resumo": "Para altura máxima com n nós, use a recorrência da AVL mais esparsa (árvore de Fibonacci): N(h) = N(h-1) + N(h-2) + 1. Os valores 1, 2, 4, 7, 12, 20, 33 valem a pena decorar. Veja o maior h com N(h) ≤ n.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Dadas as sentenças abaixo, marque a alternativa CORRETA.\n\nI. As raízes dos elementos das subárvores são menores que a raiz do heap.\nII. Para restaurar a propriedade AVL depois de inserir um elemento, começamos no ponto de inserção e nos movemos em direção a raiz dessa árvore.\nIII. A árvore B e a árvore AVL têm a mesma complexidade de tempo do pior caso para inserção e exclusão.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Somente a sentença I está correta",
      "porque": "I só vale para heap máximo (e com 'menor ou igual'), e o enunciado não diz qual. II e III também são verdadeiras, então 'somente I' não fecha."
     },
     {
      "letra": "B",
      "texto": "As sentenças II e III estão correta",
      "porque": "Seria a combinação certa se I fosse tomada como falsa. II é verdadeira (retrocede do ponto de inserção até a raiz atualizando fatores e rotacionando). III é verdadeira (ambas O(log n) no pior caso)."
     },
     {
      "letra": "C",
      "texto": "Somente a sentença III está correta",
      "porque": "III é verdadeira, mas II também, então 'somente III' fica incompleta."
     },
     {
      "letra": "D",
      "texto": "As sentenças I e III estão correta",
      "porque": "Depende de I, que só vale em heap máximo, e ignora que II é verdadeira."
     },
     {
      "letra": "E",
      "texto": "Somente a sentença II está correta",
      "porque": "II é verdadeira, mas III também."
     }
    ],
    "gabarito": "anulada",
    "resumo": "II e III são verdadeiras. I só vale para heap máximo (no mínimo, a raiz é a menor) e com 'menor ou igual' se houver chaves repetidas; o enunciado não diz qual. Se I fosse considerada falsa, B seria a resposta. Por essa ambiguidade a banca anulou.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 7,
    "formato": "simulação",
    "enunciado": "Dada a seguinte entrada (34, 8, 64, 51, 32, 21) e empregando o algoritmo Insertion Sort, qual será a aparência do array de elementos após a segunda rodada de ordenação?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "8, 21, 32, 34, 51, 64",
      "porque": "É o vetor final, depois de todas as rodadas. Após a segunda, só os dois ou três primeiros elementos foram tratados."
     },
     {
      "letra": "B",
      "texto": "8, 32, 34, 51, 64, 21",
      "porque": "Não é produzido por insertion sort: o 32 ainda nem foi processado nesse ponto."
     },
     {
      "letra": "C",
      "texto": "8, 34, 51, 64, 32, 21",
      "porque": "Aqui o 51 foi colocado antes do 64, o que corresponde a uma rodada além da segunda."
     },
     {
      "letra": "D",
      "texto": "8, 34, 64, 51, 32, 21",
      "porque": "Correta. Rodada 1: insere o 8 antes do 34 (8 34 64 51 32 21). Rodada 2: insere o 64, que já está no lugar certo, e nada se move."
     },
     {
      "letra": "E",
      "texto": "8, 51, 64, 34, 32, 21",
      "porque": "Não vem do insertion sort: o 51 pularia o 34 sem ter sido processado."
     }
    ],
    "gabarito": "D",
    "resumo": "Insertion sort mantém um prefixo ordenado e a cada rodada insere o próximo elemento nele. Em 2 rodadas, só os 3 primeiros ficam ordenados, e o resto do vetor continua como estava. Confira que os elementos após o prefixo não mudaram.",
    "assuntos": [
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Qual é a vantagem do Bubble Sort em relação aos outros algoritmos de ordenação?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "É o mais rápido",
      "porque": "O bubble sort é O(n²) no pior e no médio caso, mais lento que merge, quick e heap sort."
     },
     {
      "letra": "B",
      "texto": "Consome menos memória",
      "porque": "Consome O(1) extra, mas insertion e selection sort também, e o heap sort é in-place também. Não é uma vantagem exclusiva."
     },
     {
      "letra": "C",
      "texto": "Pode detectar se a entrada já está ordenada",
      "porque": "É a resposta esperada. Com uma flag de troca, se uma passada inteira não trocar nada, o vetor já está ordenado e o laço para: O(n) no melhor caso. A banca anulou a questão."
     },
     {
      "letra": "D",
      "texto": "É o mais complexo em termos de implementação",
      "porque": "É um dos mais simples, o oposto da afirmação."
     },
     {
      "letra": "E",
      "texto": "Não possui vantagens",
      "porque": "Tem alguma: simplicidade e a parada antecipada."
     }
    ],
    "gabarito": "anulada",
    "resumo": "A banca anulou. Conceitualmente, a única 'vantagem' razoável do bubble sort é a versão com flag, que detecta vetor ordenado e termina em O(n). Em prova de múltipla escolha, essa costuma ser a resposta esperada.",
    "assuntos": [
     {
      "num": "0091",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Ao se representar a heap máxima da figura abaixo em um array, a ordem dos elementos no array será a seguinte:",
    "figuras": [
     "2019-033-q16"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "88 66 33 44 30 22 5 77 55 75",
      "porque": "Põe a subárvore esquerda inteira antes da direita (em profundidade). O vetor de heap usa ordem por níveis."
     },
     {
      "letra": "B",
      "texto": "86 77 55 75 66 33 44 30 22 5",
      "porque": "Começa em 86, que não é a raiz (88)."
     },
     {
      "letra": "C",
      "texto": "86 77 75 66 55 44 33 30 22 5",
      "porque": "Começa em 86 e é só a lista em ordem decrescente, que não respeita a posição dos nós."
     },
     {
      "letra": "D",
      "texto": "5 22 30 75 55 44 33 77 66 86",
      "porque": "Está invertida e com o 86, que não existe na figura."
     },
     {
      "letra": "E",
      "texto": "88 66 77 33 44 55 75 30 22 5",
      "porque": "Correta. A ordem por níveis (esquerda para direita) fica: nível 0: 88; nível 1: 66, 77; nível 2: 33, 44, 55, 75; nível 3: 30, 22, 5."
     }
    ],
    "gabarito": "E",
    "resumo": "Heap em vetor é a leitura da árvore por níveis, da esquerda para a direita. O nó i tem filhos em 2i e 2i+1 (base 1). Descarte logo as alternativas que citam valores inexistentes (86).",
    "assuntos": [
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2019-033/figuras/q16-heap-maxima.png"
    ]
   },
   {
    "numero": 17,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Quantas pilhas são necessárias para implementar uma fila. Considere a situação em que nenhuma outra estrutura de dados, como matrizes, lista encadeada está disponível.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "0",
      "porque": "Sem nenhuma estrutura de apoio não há onde guardar os elementos."
     },
     {
      "letra": "B",
      "texto": "1",
      "porque": "Uma pilha só inverte a ordem (LIFO) e não consegue entregar o mais antigo primeiro sem uma segunda estrutura."
     },
     {
      "letra": "C",
      "texto": "2",
      "porque": "Correta. Uma pilha de entrada recebe os enfileirar. Ao desenfileirar, se a de saída estiver vazia, você move tudo da entrada para a saída (invertendo a ordem) e desempilha dela. A inversão dupla restaura a ordem FIFO."
     },
     {
      "letra": "D",
      "texto": "3",
      "porque": "Funciona, mas não é o mínimo."
     },
     {
      "letra": "E",
      "texto": "4",
      "porque": "Funciona, mas não é o mínimo."
     }
    ],
    "gabarito": "C",
    "resumo": "Fila com duas pilhas é clássica: enfileirar empilha na pilha A; desenfileirar desempilha de B, e se B estiver vazia, despeja A em B antes. O custo amortizado de cada operação é O(1).",
    "assuntos": [
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     },
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Qual das afirmações abaixo sobre Insertion Sort está CORRETA?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Existem arrays de tamanhos variados N tais que o Insertion Sort é executado em Θ(N).",
      "porque": "Correta. Em um vetor já ordenado, cada inserção faz uma comparação só, o que dá N-1 comparações e Θ(N) no total. É o melhor caso."
     },
     {
      "letra": "B",
      "texto": "Existem arrays de tamanhos variados N tais que o Insertion Sort é executado em Θ(1).",
      "porque": "Você precisa ler os N elementos pelo menos uma vez, então o custo cresce com N."
     },
     {
      "letra": "C",
      "texto": "Existem arrays de tamanhos variados N tais que o Insertion Sort é executado em Θ(N³).",
      "porque": "O pior caso é Θ(N²) (vetor invertido). Nunca chega a N³."
     },
     {
      "letra": "D",
      "texto": "Existem arrays de tamanhos variados N tais que o Insertion Sort é executado em Θ(2^N).",
      "porque": "Exponencial não ocorre: o máximo de movimentos é N(N-1)/2."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das sentenças anteriores está correta.",
      "porque": "Existe a A."
     }
    ],
    "gabarito": "A",
    "resumo": "Insertion sort: melhor caso Θ(N) (já ordenado), pior e médio Θ(N²). Ele é adaptativo, o que o torna bom para entradas quase ordenadas.",
    "assuntos": [
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Ao se construir uma árvore AVL, inicialmente vazia, com as seguintes chaves na ordem indicada - 2, 3, 5, 6, 9, 8, 7, 4, 1 – e sabendo que que se uma inserção fizer com que a árvore fique desequilibrada, é necessário executar as rotações para manter o equilíbrio, o resultado final da árvore AVL é:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "árvore da figura a)",
      "porque": "Correta. Inserindo e rotacionando a cada desequilíbrio, a árvore final tem raiz 6; filhos 3 e 8; netos 2, 5 (sob o 3) e 7, 9 (sob o 8); o 1 sob o 2 e o 4 sob o 5. Conferi rodando uma AVL em código.",
      "figura": "2019-033-q19-a"
     },
     {
      "letra": "B",
      "texto": "árvore da figura b)",
      "porque": "Não é uma ABB: a raiz 2 tem o 3 à esquerda, e 3 > 2. Qualquer filho esquerdo precisa ser menor que o pai.",
      "figura": "2019-033-q19-b"
     },
     {
      "letra": "C",
      "texto": "árvore da figura c)",
      "porque": "Não é uma ABB: a raiz 9 tem o 7 à direita, e 7 < 9. Parece uma árvore espelhada.",
      "figura": "2019-033-q19-c"
     },
     {
      "letra": "D",
      "texto": "árvore da figura d)",
      "porque": "Não é uma ABB (o 6 está à esquerda da raiz 5, mas 6 > 5), e o 2 está desbalanceado (esquerda altura 0, direita altura 2).",
      "figura": "2019-033-q19-d"
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Existe a a)."
     }
    ],
    "gabarito": "A",
    "resumo": "Para AVL passo a passo: insira como numa ABB, suba atualizando fatores de balanceamento e, no primeiro nó com fator 2 ou -2, aplique a rotação (simples ou dupla) conforme o caso. Antes de simular, elimine as figuras que nem são ABB (esquerdo maior ou direito menor que o pai): sobra só a a).",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2019-033/figuras/q19-arvores.png"
    ]
   },
   {
    "numero": 20,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Sobre as afirmações abaixo, marque a alternativa CORRETA\n\nI. A subárvore da raiz de um árvore vermelho e preto é sempre uma árvore vermelha e preta.\nII. O irmão de uma referência de filho nulo em uma árvore vermelha e preta é outra referência de filho nulo ou um nó vermelho.\nIII. A pior complexidade de tempo da operação de inserção em uma árvore AVL é O(log n), onde n é o número de nós na árvore.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Somente a sentença I está correta",
      "porque": "I é falsa: a raiz de uma subárvore pode ser vermelha, e uma árvore rubro-negra exige raiz preta. II e III são verdadeiras."
     },
     {
      "letra": "B",
      "texto": "As sentenças II e III estão correta",
      "porque": "Correta. II vale: se um filho é nulo (conta como preto), o irmão precisa manter a mesma altura negra, então só pode ser nulo ou um vermelho com filhos nulos. III vale: a AVL tem altura O(log n) e a inserção faz uma descida mais no máximo uma rotação (simples ou dupla)."
     },
     {
      "letra": "C",
      "texto": "Somente a sentença III está correta",
      "porque": "III é verdadeira, mas II também."
     },
     {
      "letra": "D",
      "texto": "As sentenças I e III estão correta",
      "porque": "Depende de I, que é falsa."
     },
     {
      "letra": "E",
      "texto": "Somente a sentença II está correta",
      "porque": "II é verdadeira, mas III também."
     }
    ],
    "gabarito": "B",
    "resumo": "I é falsa (subárvore com raiz vermelha não é rubro-negra, pois a raiz precisa ser preta). II é verdadeira pela igualdade de altura negra. III é verdadeira. Em afirmações sobre rubro-negra, desconfie de 'sempre' e de regras que mencionam a raiz.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "060/2019",
  "slug": "2019-060",
  "ano": 2019,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": 5,
    "formato": "simulação",
    "enunciado": "Suponha que você tenha a seguinte tabela hash implementada utilizando endereçamento aberto com sondagem linear (linear probing). A função hash que você está usando é uma função modular, h(x) = x MOD 9.\n\nQual das ordens abaixo pode ser a ordem em que os elementos foram adicionados à hash? Assuma que a hash nunca tenha sido redimensionada e que nenhum elemento tenha sido excluído ainda.",
    "figuras": [
     "2019-060-q01"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "9, 14, 4, 18, 21, 3, 12",
      "porque": "Simulando: 9 vai para 0, 14 para 5, 4 para 4, 18 para 1, 21 (hash 3) para 3, 3 (hash 3) vai para 6, 12 (hash 3) vai para 7. Resulta em 9 18 _ 21 4 14 3 12 _, diferente da figura."
     },
     {
      "letra": "B",
      "texto": "12, 3, 14, 18, 4, 9, 21",
      "porque": "12 vai para 3 e 3 para 4. Mas 18 e 9 têm hash 0: o primeiro a chegar (18) fica no 0 e o 9 vai para o 1, o contrário da figura (9 no 0, 18 no 1)."
     },
     {
      "letra": "C",
      "texto": "12, 14, 3, 9, 4, 18, 21",
      "porque": "Correta. 12 vai para 3; 14 para 5; 3 colide no 3 e vai para 4; 9 vai para 0; 4 colide no 4 e no 5 e vai para 6; 18 colide no 0 e vai para 1; 21 colide em 3, 4, 5, 6 e vai para 7. Resulta em 9 18 _ 12 3 14 4 21 _."
     },
     {
      "letra": "D",
      "texto": "9, 12, 14, 3, 21, 18, 4",
      "porque": "Na simulação o 18 ainda chega ao 1, mas o 4 e o 21 trocam de lugar: 21 ocuparia o 6 e o 4 o 7, contra a figura (4 no 6, 21 no 7)."
     },
     {
      "letra": "E",
      "texto": "18, 9, 12, 3, 14, 4, 21",
      "porque": "O 18 entra primeiro no 0 e o 9 vai para o 1, o contrário da figura."
     }
    ],
    "gabarito": "C",
    "resumo": "Em hash com sondagem linear, quem chega primeiro fica na posição própria e quem chega depois anda para a frente. Daí, pares com mesmo hash (9 e 18; 3, 12, 21) fixam a ordem relativa: 9 antes de 18; 12 antes de 3 antes de 4 antes de 21 na ordem de chegada ao grupo. Rodei as cinco ordens em código e só a C dá a tabela da figura (12 está na posição 3).",
    "assuntos": [
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2019-060/figuras/q01-tabela-hash.png"
    ]
   },
   {
    "numero": 2,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Dado os seguintes elementos (10, 20, 15, 25, 30, 16, 18, 19), qual desenho representa uma árvore AVL, inicialmente vazia, que é preenchida com esses elementos, na ordem apresentada, e que tem as devidas rotações efetuadas?",
    "figuras": [
     "2019-060-q02-1",
     "2019-060-q02-2",
     "2019-060-q02-3",
     "2019-060-q02-4"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "1",
      "porque": "Correta. 10, 20, 15: rotação dupla, raiz 15 (10 e 20). 25 e 30: rotação simples no 20, e o 25 sobe (20 e 30). 16: rotação dupla na raiz, que vira 20 (15 com 10 e 16; 25 com 30 à direita). 18 entra sem rotação. 19: rotação simples no 16, o 18 sobe com 16 e 19. Resultado: raiz 20; 15 e 25; 10, 18 e 30; 16 e 19 sob o 18. É a figura 1.",
      "figura": "2019-060-q02-1"
     },
     {
      "letra": "B",
      "texto": "2",
      "porque": "Não é nem ABB: o 15 está na subárvore direita do 18 (sob o 16), mas 15 < 18 e devia ficar à esquerda.",
      "figura": "2019-060-q02-2"
     },
     {
      "letra": "C",
      "texto": "3",
      "porque": "É ABB, mas o 18 tem só filho esquerdo (o 15 com dois filhos): subárvore esquerda de altura 2 e direita vazia, diferença 3. Não é AVL.",
      "figura": "2019-060-q02-3"
     },
     {
      "letra": "D",
      "texto": "4",
      "porque": "É ABB, mas na raiz 20 a subárvore esquerda tem altura 3 e a direita altura 1, diferença 2. Não é AVL.",
      "figura": "2019-060-q02-4"
     },
     {
      "letra": "E",
      "texto": "Nenhuma das árvores desenhadas representa uma AVL",
      "porque": "Existe a figura 1, que corresponde à simulação."
     }
    ],
    "gabarito": "A",
    "resumo": "Simule inserindo uma a uma, calculando o fator de balanceamento no caminho de volta e rotacionando no primeiro nó com fator ±2. O gabarito oficial é A, e o programa que escrevi confirma: raiz 20; 15 e 25; 10, 18, 30; 16 e 19 (filhos do 18). Dica: antes de simular tudo, descarte figuras desbalanceadas.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2019-060/figuras/q02-arvores.png"
    ]
   },
   {
    "numero": 3,
    "topico": 2,
    "formato": "conceito",
    "enunciado": "Qual a alternativa que completa corretamente a seguinte frase: Um algoritmo que possui número de operações _______________ em função de uma entrada de tamanho n é linear.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "n³ + 9",
      "porque": "É cúbico, O(n³): o termo dominante é n³."
     },
     {
      "letra": "B",
      "texto": "3n² + 3n + 2",
      "porque": "É quadrático, O(n²): o termo dominante é n²."
     },
     {
      "letra": "C",
      "texto": "6",
      "porque": "É constante, O(1): não depende de n."
     },
     {
      "letra": "D",
      "texto": "2n + 1",
      "porque": "Correta. O termo dominante é n com coeficiente constante, então é Θ(n), linear."
     },
     {
      "letra": "E",
      "texto": "n² + 1",
      "porque": "É quadrático, O(n²)."
     }
    ],
    "gabarito": "D",
    "resumo": "Para classificar, olhe o termo de maior grau e ignore coeficientes e constantes: 2n + 1 → n. Polinômio de grau 1 é linear.",
    "assuntos": [
     {
      "num": "0071",
      "modulo": "10-analise.md"
     },
     {
      "num": "0072",
      "modulo": "10-analise.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 6,
    "formato": "cálculo",
    "enunciado": "Considere um vetor com 25 elementos (posição 0 até a posição 24) que representam os números primos entre 1 a 100, em ordem crescente (Ex: [2, 3, 5, 7, 11, 13, ..., 89, 97]). Empregando pesquisa binária, quantos itens do vetor precisam ser examinados antes de se concluir que o número 52 não está no vetor e, portanto, não é primo?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "12",
      "porque": "Doze é a posição do primeiro elemento examinado, não a quantidade de itens."
     },
     {
      "letra": "B",
      "texto": "7",
      "porque": "É a ordem de grandeza do pior caso para outros tamanhos, mas aqui a busca termina antes."
     },
     {
      "letra": "C",
      "texto": "5",
      "porque": "Correta. Intervalo 0 a 24: examina a posição 12 (41 < 52), depois 18 (67 > 52), 15 (53 > 52), 13 (43 < 52) e 14 (47 < 52). O intervalo fica vazio: 5 itens examinados."
     },
     {
      "letra": "D",
      "texto": "1",
      "porque": "Um só item examinado só se a busca acertasse de primeira."
     },
     {
      "letra": "E",
      "texto": "4",
      "porque": "Faltou o último exame (a posição 14, valor 47), que ainda é feito antes de o intervalo ficar vazio."
     }
    ],
    "gabarito": "C",
    "resumo": "Busca binária faz no máximo ⌊log2 n⌋ + 1 comparações: com 25 elementos, 5. Aqui o 52 é ausente, então ela usa o máximo. Conte cada posição do meio, inclusive a última que esvazia o intervalo.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 5,
    "topico": 3,
    "formato": "código",
    "enunciado": "Considere o código da função abaixo:\n\n```c\nvoid fun1(struct node* head)\n{\n  if(head == NULL)\n    return;\n  fun1(head->next);\n  printf(\"%d \", head->data);\n}\n```\n\nO que essa função faz, dada uma lista encadeada de valores inteiros como entrada?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Imprime todos os nós da lista encadeada, começando com primeiro o nó da lista",
      "porque": "Só imprimiria na ordem se o printf viesse antes da chamada recursiva. Aqui vem depois."
     },
     {
      "letra": "B",
      "texto": "Imprime todos os nós da lista encadeada, começando com o último nó da lista",
      "porque": "Correta. A função desce até o NULL sem imprimir nada e, ao voltar, imprime cada nó, do último para o primeiro."
     },
     {
      "letra": "C",
      "texto": "Imprime apenas os nós de posições pares da lista encadeada",
      "porque": "Não tem salto: toda chamada avança um nó e todo nó é impresso."
     },
     {
      "letra": "D",
      "texto": "Imprime apenas os nós de posições impares da lista encadeada",
      "porque": "Idem: nenhum nó é pulado."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Existe a B."
     }
    ],
    "gabarito": "B",
    "resumo": "Printf depois da chamada recursiva imprime na ordem inversa (na volta); printf antes imprime na ordem direta (na ida). Padrão clássico para imprimir lista ao contrário.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     },
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 5,
    "formato": "conceito",
    "enunciado": "Marque a alternativa CORRETA. Sobre um hash com encadeamento e com tabela de tamanho 100, pode-se dizer que:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Para casos em que se insere um número n muito grande de chaves, o tempo no caso médio de busca será O(1)",
      "porque": "Só valeria se a tabela crescesse junto com n (fator de carga constante). Com m fixo em 100, cada cadeia tem n/100 nós, então não é O(1)."
     },
     {
      "letra": "B",
      "texto": "Para casos em que se insere um número n muito grande de chaves, o tempo de busca no pior caso será O(1)",
      "porque": "No pior caso todas as chaves caem na mesma cadeia e a busca percorre n nós, O(n)."
     },
     {
      "letra": "C",
      "texto": "Para casos em que se insere um número n muito grande de chaves, o tempo no caso médio de busca será O(n)",
      "porque": "Correta. Com m = 100 fixo, o fator de carga é n/100 e a cadeia média tem n/100 nós. Como 1/100 é constante, o custo é O(n)."
     },
     {
      "letra": "D",
      "texto": "Para casos em que se insere um número n muito grande de chaves, o tempo de busca no pior caso será O(log n)",
      "porque": "Cadeia é lista encadeada: o pior caso é O(n), não O(log n)."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das alternativas anteriores",
      "porque": "Existe a C."
     }
    ],
    "gabarito": "C",
    "resumo": "No encadeamento, o custo médio de busca é Θ(1 + α), com α = n/m. O(1) exige α limitado, o que significa redimensionar a tabela. Com m fixo e n crescendo, o tempo vira linear (embora com constante pequena).",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 3,
    "formato": "código",
    "enunciado": "A seguinte função em C usa uma lista simplesmente encadeada como argumento de entrada. Ela modifica a lista, movendo o último elemento para a frente da lista e retorna a lista modificada.\n\n```c\ntypedef struct node {\n  int value;\n  struct node *next;\n}Node;\n\nNode *move_to_front(Node *head) {\n  Node *p, *q;\n  if ((head == NULL || (head->next == NULL))\n    return head;\n  q = NULL; p = head;\n  while (p-> next !=NULL)\n  {\n    q = p;\n    p = p->next;\n  }\n  _ _ _ _ _ _ _ _ _ _ _ _ _ _\n  return head;\n}\n```\n\nCerta parte do código foi deixada em branco (linha tracejada). Escolha a alternativa CORRETA para substituir a linha em branco.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "q = NULL; p->next = head; head = p;",
      "porque": "`q = NULL` só perde a referência ao penúltimo. O penúltimo continua apontando para o último, formando um ciclo."
     },
     {
      "letra": "B",
      "texto": "q->next = NULL; head = p; p->next = head;",
      "porque": "Atualizar `head = p` antes de `p->next = head` faz p apontar para si mesmo e perde a lista antiga."
     },
     {
      "letra": "C",
      "texto": "head = p; p->next = q; q->next = NULL;",
      "porque": "Inverte a ligação do último com o penúltimo e perde o resto da lista (o antigo `head` fica órfão)."
     },
     {
      "letra": "D",
      "texto": "q->next = NULL; p->next = head; head = p;",
      "porque": "Correta. Ao sair do laço, p é o último e q o penúltimo. `q->next = NULL` corta o último da cauda, `p->next = head` liga o último ao antigo primeiro e `head = p` o torna o novo início. A ordem importa."
     },
     {
      "letra": "E",
      "texto": "A função não precisa ser complementada.",
      "porque": "Sem o trecho, a função não move nada: só retorna o head original."
     }
    ],
    "gabarito": "D",
    "resumo": "Em manipulação de ponteiros em lista, a ordem das atribuições decide tudo. Primeiro desligue o último (q->next = NULL), depois ligue-o na frente (p->next = head) e só então atualize head. Desenhe os nós e as setas antes de escolher.",
    "assuntos": [
     {
      "num": "0076",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Qual dos seguintes algoritmos apresenta tempo O(n) quando ordenando um vetor com n elementos idênticos de texto?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Heapsort",
      "porque": "Também pode ser O(n) com elementos iguais (o max-heapify para na hora, pois a comparação é estrita), por isso é defensável. A banca esperava a B."
     },
     {
      "letra": "B",
      "texto": "Insertion sort",
      "porque": "Correta. Com todos os elementos iguais, cada inserção compara uma vez com o anterior e para (não é maior), então são n-1 comparações e nenhuma movimentação: Θ(n)."
     },
     {
      "letra": "C",
      "texto": "Mergesort",
      "porque": "Divide e intercala sempre, sem atalho para entradas iguais: Θ(n log n) em qualquer entrada."
     },
     {
      "letra": "D",
      "texto": "Quicksort",
      "porque": "Com particionamento que manda os iguais para um lado, degenera em O(n²). Só variantes com partição em três vias ficam O(n)."
     },
     {
      "letra": "E",
      "texto": "Nenhum dos algoritmos apresenta tempo O(n) para essa entrada",
      "porque": "Falso: pelo menos o insertion sort faz n-1 comparações."
     }
    ],
    "gabarito": "B",
    "resumo": "Algoritmos adaptativos como o insertion sort ficam O(n) em entradas já ordenadas ou com todos os elementos iguais. Merge sort não é adaptativo. Heap sort com chaves iguais também tende a O(n), então A e B são defensáveis, mas o gabarito é B.",
    "assuntos": [
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Qual das afirmações a seguir é VERDADEIRA sobre árvores rubro-negra (vermelho e preto)?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O caminho do nó raiz até o nó folha mais distante não é maior que o dobro do número de nós do caminho da raiz para a folha mais próxima",
      "porque": "Correta. Todos os caminhos têm o mesmo número de nós pretos, e vermelhos não são consecutivos, então o caminho mais longo tem no máximo o dobro do mais curto. Isso garante a altura O(log n)."
     },
     {
      "letra": "B",
      "texto": "O caminho do nó raiz para um nó folha ou para um nó nulo deve conter o mesmo número de nós pretos e vermelhos.",
      "porque": "É o mesmo número de nós pretos (altura negra) em todos os caminhos, não igual quantidade de pretos e vermelhos."
     },
     {
      "letra": "C",
      "texto": "A raiz pode ser vermelha",
      "porque": "Pela definição, a raiz é sempre preta."
     },
     {
      "letra": "D",
      "texto": "Se um nó for vermelho, os nós filhos somente serão pretos. O inverso também acontece, ou seja, se um nó for preto, seus nós filhos somente serão vermelhos.",
      "porque": "A primeira parte vale, mas o inverso não: um nó preto pode ter filhos pretos."
     },
     {
      "letra": "E",
      "texto": "Nenhumas das afirmações é verdadeira",
      "porque": "A afirmação A é verdadeira."
     }
    ],
    "gabarito": "A",
    "resumo": "As cinco regras da rubro-negra: nó vermelho ou preto; raiz preta; folhas (nulos) pretas; vermelho tem filhos pretos; todo caminho tem a mesma quantidade de pretos. Disso sai que o maior caminho é no máximo 2 vezes o menor.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Qual das seguintes estruturas de dados é mais usada para implementar recursão?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Heap binário",
      "porque": "Estrutura de prioridade; não controla o fluxo das chamadas."
     },
     {
      "letra": "B",
      "texto": "Hash table",
      "porque": "Estrutura de busca por chave, sem ordem LIFO."
     },
     {
      "letra": "C",
      "texto": "Fila",
      "porque": "FIFO: a ordem de retorno das chamadas é LIFO, o oposto."
     },
     {
      "letra": "D",
      "texto": "Árvore de busca",
      "porque": "Organiza chaves ordenadas, não o fluxo de execução."
     },
     {
      "letra": "E",
      "texto": "Pilha",
      "porque": "Correta. Cada chamada empilha seu registro de ativação e o retorno o desempilha: é LIFO."
     }
    ],
    "gabarito": "E",
    "resumo": "Recursão usa a pilha de chamadas. Recursão muito funda estoura a pilha, e toda recursão pode ser trocada por laço com pilha explícita.",
    "assuntos": [
     {
      "num": "0031",
      "modulo": "04-funcoes.md"
     },
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 11,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Qual das alternativas a seguir é FALSA sobre a árvores B e B+",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Árvores B e B+ criando um novo nível raiz (crescem para cima) sempre que sua altura muda, enquanto as árvores de pesquisa binária crescem adicionando novos nós folhas (para baixo) sempre que sua altura muda.",
      "porque": "Verdadeira: a altura da árvore B só aumenta quando a raiz se divide, criando uma nova raiz acima; a ABB cresce por baixo."
     },
     {
      "letra": "B",
      "texto": "A complexidade de tempo para busca por uma chave é diferente das árvores rubro-negras, se considerarmos o pior caso",
      "porque": "É a mais provável da banca para a FALSA: a busca em B/B+ é O(log n) no pior caso, igual à rubro-negra. Então a afirmação de que é diferente é falsa."
     },
     {
      "letra": "C",
      "texto": "O número de ponteiros filhos em um nó da árvore B é sempre igual ao número de chaves nele mais uma.",
      "porque": "Vale para nó interno. Em folha não há filhos, então 'sempre' é questionável, o que torna a C uma segunda candidata a falsa."
     },
     {
      "letra": "D",
      "texto": "Uma árvore B+, de ordem n, é uma árvore com as seguintes propriedades: (i) todos os nós das folhas são armazenados na mesma profundidade; (ii) todos as chaves são armazenadas em nós folha.",
      "porque": "Verdadeira para a B+: todas as folhas no mesmo nível, e as chaves de dados ficam nas folhas (os nós internos têm só cópias para guiar)."
     },
     {
      "letra": "E",
      "texto": "Uma árvore B, de ordem n, é uma árvore com as seguintes propriedades: (i) todos os nós das folhas são armazenados na mesma profundidade; (ii) todos os nós não raiz têm entre n - 1 e 2n – 1 chaves; (iii) a raiz tem no máximo 2n – 1 chaves.",
      "porque": "Verdadeira na definição de grau mínimo n (Cormen): não raiz entre n-1 e 2n-1 chaves, raiz até 2n-1."
     }
    ],
    "gabarito": "anulada",
    "resumo": "A banca anulou. B é a mais provável de ser a 'falsa' (a busca em B e em rubro-negra é O(log n) nos dois casos), mas C também se contesta: folhas não têm filhos. Em questões de 'FALSA', leia cada alternativa e marque a única com erro claro.",
    "assuntos": [
     {
      "num": "0097",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Quais das seguintes árvores abaixo respeita as regras básicas de balanceamento de árvores AVL?",
    "figuras": [
     "2019-060-q12-a",
     "2019-060-q12-b",
     "2019-060-q12-c"
    ],
    "alternativas": [
     {
      "letra": "A",
      "texto": "Somente B",
      "porque": "Em B, o 50 tem subárvore esquerda de altura 2 (10 → 5) e direita vazia (-1): diferença 3 em módulo, desbalanceada. B não é AVL."
     },
     {
      "letra": "B",
      "texto": "A, B e C",
      "porque": "Inclui a B, que viola a regra."
     },
     {
      "letra": "C",
      "texto": "B e C",
      "porque": "Inclui a B, que viola a regra."
     },
     {
      "letra": "D",
      "texto": "A e C",
      "porque": "Correta. Em A, todos os nós têm diferença de alturas até 1 (o 50 com esquerda 10 e direita vazia: diferença 1; o 200 com só o 300: diferença 1). Em C, a raiz tem alturas 3 e 2, o 50 tem 2 e 1, o 200 tem 2 e 2, o 10 tem 1 e vazio, o 150 e o 300 têm 1 e vazio, tudo dentro de 1."
     },
     {
      "letra": "E",
      "texto": "Nenhuma das árvores é AVL",
      "porque": "A e C respeitam a regra."
     }
    ],
    "gabarito": "D",
    "resumo": "AVL exige que, em todo nó, as alturas das duas subárvores difiram em no máximo 1. Procure o nó mais alto onde isso falha: em B é o 50, com esquerda de altura 2 (10 → 5) e direita vazia. Basta achar um nó violando e eliminar a árvore.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": [
     "provas-ppgi-ufam/2019-060/figuras/q12-arvores.png"
    ]
   },
   {
    "numero": 13,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Quais das seguintes afirmações sobre árvores é INCORRETA?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O tempo de busca, no pior caso, para uma árvore AVL é O(log n)",
      "porque": "Correta como afirmação: a altura da AVL é O(log n)."
     },
     {
      "letra": "B",
      "texto": "No pior caso, uma inserção de árvore rubro-negra requer O(1) rotações",
      "porque": "Correta como afirmação: a inserção faz no máximo 2 rotações (o resto são recolorações)."
     },
     {
      "letra": "C",
      "texto": "Uma árvore B+ tem todos as chaves armazenadas em nós folha",
      "porque": "Correta como afirmação: é a definição da B+."
     },
     {
      "letra": "D",
      "texto": "A busca por uma chave em uma árvore de pesquisa binária sem balanceamento com n nós leva tempo O(log n) no pior caso.",
      "porque": "É a única incorreta: sem balanceamento o pior caso é O(n), com a árvore degenerada em lista. A banca anulou mesmo assim."
     },
     {
      "letra": "E",
      "texto": "Pode-se dizer que uma árvore B é uma árvore balanceada",
      "porque": "Correta como afirmação: todas as folhas ficam à mesma profundidade."
     }
    ],
    "gabarito": "anulada",
    "resumo": "A única alternativa claramente incorreta é a D (ABB sem balanceamento tem pior caso O(n)). A banca anulou assim mesmo. Em perguntas com 'INCORRETA', troque o sinal: ache a que contradiz a teoria.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 6,
    "formato": "cálculo",
    "enunciado": "O número mínimo de comparações necessárias para determinar se um número inteiro aparece mais de n/2 vezes em um vetor ordenado de n números inteiros é:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Θ(n)",
      "porque": "Percorrer tudo é suficiente mas não é o mínimo, pois o vetor está ordenado."
     },
     {
      "letra": "B",
      "texto": "Θ(log n)",
      "porque": "É a resposta esperada: se um valor aparece mais de n/2 vezes, ele ocupa a posição a[n/2]. Você acha o início do bloco por busca binária e confere se o bloco passa de n/2. Isso custa Θ(log n)."
     },
     {
      "letra": "C",
      "texto": "Θ(log *n)",
      "porque": "Logaritmo iterado, que não corresponde ao problema."
     },
     {
      "letra": "D",
      "texto": "Θ(1)",
      "porque": "Um número constante de comparações não basta para localizar o bloco do candidato."
     },
     {
      "letra": "E",
      "texto": "Θ(n/2)",
      "porque": "É linear, igual a Θ(n)."
     }
    ],
    "gabarito": "anulada",
    "resumo": "A banca anulou. O candidato a maioria é sempre a[n/2], e a verificação (achar o primeiro e o último índice do bloco) usa busca binária, Θ(log n). A ideia útil: vetor ordenado permite usar busca binária em vez de varredura.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0072",
      "modulo": "10-analise.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Comparando árvores AVL e rubro-negras, qual das seguintes afirmações é VERDADEIRA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "As árvores AVL tendem a ter altura menor em comparação com as árvores rubro-negras, mas podem causar mais rotações durante operações de inserção e exclusão.",
      "porque": "Correta. A AVL é mais rígida (diferença de altura ≤ 1), então fica mais baixa e a busca é um pouco mais rápida, mas rotaciona mais ao inserir e remover."
     },
     {
      "letra": "B",
      "texto": "As alturas das árvores AVL e rubro-negras são as mesmas, mas as árvores AVL podem causar mais rotações durante a inserção e exclusão.",
      "porque": "As alturas não são as mesmas: a rubro-negra pode chegar a 2 log n, enquanto a AVL fica em cerca de 1,44 log n."
     },
     {
      "letra": "C",
      "texto": "As árvores rubro-negras tendem a ter altura menor em comparação com as árvores AVL, mas podem causar mais rotações durante a inserção e exclusão.",
      "porque": "Está invertida: a AVL é a mais baixa e a rubro-negra rotaciona menos."
     },
     {
      "letra": "D",
      "texto": "As alturas das árvores AVL e rubro-negras são as mesmas, mas as árvores rubro-negras podem causar mais rotações durante a inserção e exclusão.",
      "porque": "Erra nas duas partes: alturas diferentes e a rubro-negra faz menos rotações."
     },
     {
      "letra": "E",
      "texto": "Todas as afirmações anteriores são falsas",
      "porque": "A A é verdadeira."
     }
    ],
    "gabarito": "A",
    "resumo": "AVL: balanceamento rígido, altura menor, mais rotações. Rubro-negra: balanceamento mais frouxo, altura até 2 log n, no máximo 2 rotações por inserção. Escolha AVL para muita busca e rubro-negra para muita escrita.",
    "assuntos": [
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Dada a seguinte árvore binária de busca (figura abaixo) e ao se realizar as seguintes operações em sequência - adicionar o nó 5, adicionar o nó 17, remover o nó 23 e remover o nó 9. Qual das alternativas representa a lista de nós desta árvore em pré-ordem e pós-ordem, respectivamente?\n\n(a figura não veio no caderno)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "3, 9, 10, 12, 15, 19, 21, 23 e 23, 21, 19, 15, 12, 10, 9, 3",
      "porque": "É uma lista ordenada e sua inversa, o que não é pré nem pós-ordem. Ainda inclui o 9 e o 23, que foram removidos, e não tem o 5 nem o 17, que foram inseridos."
     },
     {
      "letra": "B",
      "texto": "15, 9, 23, 3, 12, 19, 10, 21 e 21, 10, 19, 12, 3, 23, 9, 15",
      "porque": "Contém o 9 e o 23 (removidos) e não tem o 5 e o 17 (inseridos)."
     },
     {
      "letra": "C",
      "texto": "15, 10, 21, 3, 12, 19, 9, 23 e 15, 21, 10, 19, 12, 3, 23, 9",
      "porque": "Contém o 9 e o 23 (removidos) e não tem o 5 e o 17."
     },
     {
      "letra": "D",
      "texto": "10, 12, 9, 3, 15, 23, 19, 21 e 21, 19, 23, 15, 9, 3, 12, 10",
      "porque": "Contém o 9 e o 23 e não tem o 5 e o 17."
     },
     {
      "letra": "E",
      "texto": "15, 10, 3, 5, 12, 21, 19, 17 e 5, 3, 12, 10, 17, 19, 21, 15",
      "porque": "É a única sem 9 e 23 e com 5 e 17. Pré e pós-ordem batem com a mesma árvore (15; 10 com 3 e 12; 3 com filho direito 5; 21 com filho 19; 19 com filho 17)."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Sem a figura, dá para resolver por exclusão: as operações tiram o 9 e o 23 e põem o 5 e o 17, então só a E tem essa combinação de nós. A banca anulou, provavelmente por causa da figura ausente. Pré-ordem: raiz, esquerda, direita. Pós-ordem: esquerda, direita, raiz.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0100",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0098",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 17,
    "topico": 7,
    "formato": "cálculo",
    "enunciado": "Suponha que, no pior caso, um algoritmo Merge Sort leve 30 segundos para ordenar uma entrada de tamanho 64. Qual das opções a seguir se aproxima mais do tamanho máximo de entrada de um problema que pode ser resolvido em 6 minutos?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "256",
      "porque": "256 × log2(256) = 2048, que dá 30 × 2048/384 = 160 s, abaixo de 360 s. Dá para resolver mais que isso."
     },
     {
      "letra": "B",
      "texto": "1024",
      "porque": "1024 × 10 = 10240 unidades, o que levaria cerca de 800 s, mais que 6 minutos."
     },
     {
      "letra": "C",
      "texto": "512",
      "porque": "Correta. T = c × n log n. Com n = 64: 64 × 6 = 384 unidades ↔ 30 s. Em 360 s cabem 12 vezes mais: 4608 unidades. E 512 × 9 = 4608."
     },
     {
      "letra": "D",
      "texto": "2048",
      "porque": "2048 × 11 = 22528 unidades, cerca de 1760 s."
     },
     {
      "letra": "E",
      "texto": "4096",
      "porque": "4096 × 12 = 49152 unidades, cerca de 3840 s."
     }
    ],
    "gabarito": "C",
    "resumo": "Se o tempo é c·n·log n, calcule c com o dado (30 s para 64 × 6 = 384) e resolva n·log n = 360/30 × 384 = 4608. Teste potências de 2: 512 × 9 = 4608. Em prova, vale testar as alternativas em vez de resolver a equação.",
    "assuntos": [
     {
      "num": "0094",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0072",
      "modulo": "10-analise.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 7,
    "formato": "simulação",
    "enunciado": "Considere que os seguintes elementos {5,4,3,2,1} foram inseridos nesta ordem em um vetor. Em seguida, você aplicou o algoritmo Insertion Sort nele. Qual é a sequência de passos feitos durante o uso do Insertion Sort neste vetor?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "4 5 3 2 1 / 3 4 5 2 1 / 2 3 4 5 1 / 1 2 3 4 5",
      "porque": "Correta. A cada rodada, o próximo elemento é inserido no prefixo ordenado: insere o 4 (4 5 3 2 1), o 3 (3 4 5 2 1), o 2 (2 3 4 5 1) e o 1 (1 2 3 4 5)."
     },
     {
      "letra": "B",
      "texto": "5 4 3 1 2 / 5 4 1 2 3 / 5 1 2 3 4 / 1 2 3 4 5",
      "porque": "Parece um insertion sort que processa o final do vetor para o começo, o que não é o algoritmo."
     },
     {
      "letra": "C",
      "texto": "4 3 2 1 5 / 3 2 1 5 4 / 2 1 5 4 3 / 1 5 4 3 2",
      "porque": "É uma rotação do vetor, não uma inserção ordenada."
     },
     {
      "letra": "D",
      "texto": "4 5 3 2 1 / 2 3 4 5 1 / 3 4 5 2 1 / 1 2 3 4 5",
      "porque": "Troca a ordem das rodadas: o 2 não pode ser inserido antes do 3."
     },
     {
      "letra": "E",
      "texto": "4 5 3 1 2 / 2 3 4 5 1 / 3 4 5 2 1 / 1 2 3 4 5",
      "porque": "Mistura posições aleatórias (4 5 3 1 2) que não aparecem em nenhuma rodada do insertion sort."
     }
    ],
    "gabarito": "A",
    "resumo": "Insertion sort processa da esquerda para a direita e deixa o prefixo ordenado. A cada rodada o prefixo cresce em um elemento. Confira o segundo passo: o prefixo precisa ter 3 elementos ordenados (3 4 5) e o resto intacto (2 1).",
    "assuntos": [
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 3,
    "formato": "afirmações",
    "enunciado": "Considere uma lista duplamente encadeada não ordenada (com ponteiros na início e final da lista). Qual das seguintes operações a seguir pode ser implementada no tempo O(1)? Marque a alternativa CORRETA.\n\nI. Inserção na frente da lista encadeada\nII. Inserção no final da lista encadeada\nIII. Exclusão do nó frontal da lista encadeada\nIV. Exclusão do último nó da lista encadeada",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I e II",
      "porque": "Verdadeiras, mas incompletas: III e IV também são O(1)."
     },
     {
      "letra": "B",
      "texto": "I e III",
      "porque": "Verdadeiras, mas incompletas."
     },
     {
      "letra": "C",
      "texto": "I, II e III",
      "porque": "Faltam a IV, que também é O(1)."
     },
     {
      "letra": "D",
      "texto": "I, II e IV",
      "porque": "Falta a III, que também é O(1)."
     },
     {
      "letra": "E",
      "texto": "Todas as afirmativa estão corretas",
      "porque": "Correta. Com ponteiros para o início e para o fim e elo para o anterior em cada nó, as quatro operações são O(1). A exclusão do último nó é O(1) porque o penúltimo vem do campo `prev`, sem percorrer a lista."
     }
    ],
    "gabarito": "E",
    "resumo": "Numa lista duplamente encadeada com início e fim, todas as inserções e exclusões nas pontas são O(1). Em lista simples, só a exclusão do último nó é O(n), porque precisa achar o penúltimo.",
    "assuntos": [
     {
      "num": "0079",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Suponha que uma fila circular de elementos com capacidade (n - 1) seja implementada com um vetor de n elementos. Suponha que a operação de inserção e exclusão seja realizada usando REAR (último elemento da fila) e FRONT (primeiro elemento da fila) como variáveis de índice do vetor, respectivamente. Inicialmente, REAR = FRONT = 0. As condições para detectar a fila cheia e a fila vazia são:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Full: (REAR+1) mod n == FRONT, empty: (FRONT+1) mod n == REAR",
      "porque": "A condição de cheia está certa, mas a de vazia não: o teste de vazia é REAR == FRONT."
     },
     {
      "letra": "B",
      "texto": "Full: REAR == FRONT, empty: (REAR+1) mod n == FRONT",
      "porque": "Trocou as duas condições."
     },
     {
      "letra": "C",
      "texto": "Full: (FRONT+1) mod n == REAR, empty: REAR == FRONT",
      "porque": "A de vazia está certa, mas a de cheia está com os índices trocados: é (REAR+1) mod n == FRONT."
     },
     {
      "letra": "D",
      "texto": "Full: REAR == FRONT, empty: (FRONT+1) mod n == REAR",
      "porque": "Trocou as duas e ainda inverteu os índices."
     },
     {
      "letra": "E",
      "texto": "Full: (REAR+1) mod n == FRONT, empty: REAR == FRONT",
      "porque": "Correta. Inicialmente REAR = FRONT = 0 e isso significa fila vazia. Para distinguir de fila cheia, sacrifica-se uma posição (capacidade n-1): a fila está cheia quando avançar REAR um passo alcançaria FRONT, isto é, (REAR+1) mod n == FRONT."
     }
    ],
    "gabarito": "E",
    "resumo": "Em fila circular com um vetor de n posições, REAR == FRONT quer dizer vazia. Para não confundir com cheia, uma posição fica sempre livre, daí a capacidade n-1 e o teste (REAR+1) mod n == FRONT para cheia.",
    "assuntos": [
     {
      "num": "0085",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "057/2022",
  "slug": "2022-057",
  "ano": 2022,
  "oficial": false,
  "questoes": [
   {
    "numero": 1,
    "topico": 3,
    "formato": "código",
    "enunciado": "(Python) Qual a saída do código abaixo?\n\n```python\nclass Vector():\n    def __init__(self, row: list()):\n        self.row = row\n    def dot_product(self, column):\n        return sum(self.row[i] * column.row[i] for i in range(len(self.row)))\n```\n```python\nvec_1 = Vector([0,2,0,0,5])\nvec_2 = Vector([1,0,3,4,0])\nprint(vec_1.dot_product(vec_2))\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "15",
      "porque": "Seria o resultado se alguém somasse os elementos de um só vetor (0+2+0+0+5 = 7) ou trocasse o produto por soma. O método multiplica posição a posição e depois soma, e nenhum par dá 15."
     },
     {
      "letra": "B",
      "texto": "[0, 0, 0, 0, 0]",
      "porque": "`sum` devolve um número, não uma lista. O método nunca monta um vetor de produtos para imprimir; ele já soma tudo dentro do `sum`."
     },
     {
      "letra": "C",
      "texto": "[1, 2, 3, 4, 5]",
      "porque": "Isso seria imprimir `range(1, 6)` ou um vetor qualquer. O código só imprime o valor devolvido por `dot_product`, que é um inteiro."
     },
     {
      "letra": "D",
      "texto": "0",
      "porque": "O produto escalar é 0·1 + 2·0 + 0·3 + 0·4 + 5·0 = 0. Em cada posição um dos dois fatores é zero, então toda parcela é zero. Rodado em Python: imprime 0."
     }
    ],
    "gabarito": "D",
    "resumo": "Produto escalar é a soma dos produtos posição a posição. Quando os zeros de um vetor caem onde o outro tem valor, tudo se anula. Na prova, monte a tabela de parcelas antes de somar, em vez de adivinhar pelo formato.",
    "assuntos": [
     {
      "num": "0039",
      "modulo": "05-vetores-e-strings.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Sobre árvores de pesquisa binária, considere:\n\n1. TODOS os nós da subárvore à esquerda são menores que o pai.\n2. O nó mais à esquerda é o menor de TODOS os nós, e o mais à direita é o maior.\n3. O sucessor de x (menor chave maior que a de x) está SEMPRE em um nível acima de x, mais próximo da raiz.\n\nQuais são verdadeiras?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas 2 e 3",
      "porque": "Propõe 2 e 3 como verdadeiras e deixa a 1 de fora. A 1 é verdadeira, e a 3 é falsa, então essa combinação falha nos dois pontos."
     },
     {
      "letra": "B",
      "texto": "Todas",
      "porque": "Inclui a 3, que é falsa. Se x tem subárvore direita, o sucessor é o nó mais à esquerda dessa subárvore, que fica abaixo de x."
     },
     {
      "letra": "C",
      "texto": "Apenas 1 e 2",
      "porque": "A 1 é a propriedade que define a ABB. A 2 decorre dela: descendo sempre à esquerda você chega ao mínimo, e sempre à direita ao máximo. A 3 é falsa, então só 1 e 2 valem."
     },
     {
      "letra": "D",
      "texto": "Apenas 1",
      "porque": "Deixa a 2 de fora, mas ela é verdadeira: o mínimo está no fim do caminho pela esquerda e o máximo no fim do caminho pela direita."
     }
    ],
    "gabarito": "C",
    "resumo": "1 verdadeira (definição da ABB). 2 verdadeira (mínimo e máximo ficam nas pontas). 3 falsa: o sucessor só sobe até um ancestral quando x não tem filho direito; com filho direito, ele desce. Dica: palavras como SEMPRE e TODOS pedem que você procure um contraexemplo.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0175",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Sobre algoritmos de ordenação, considere:\n\n1. O Quicksort tem complexidade de pior caso O(n log n).\n2. Quicksort e Mergesort usam divisão e conquista.\n3. O Mergesort é Θ(n log n) no caso médio.\n4. Com a lista já ordenada, o Selectionsort é O(n).\n\nAs afirmações são, respectivamente:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "V, V, V, V",
      "porque": "Marca a 1 e a 4 como verdadeiras, e as duas são falsas. O pior caso do Quicksort é O(n²), e a seleção sempre faz Θ(n²) comparações."
     },
     {
      "letra": "B",
      "texto": "F, V, V, F",
      "porque": "1 falsa: com pivô ruim (lista já ordenada e pivô no extremo) o Quicksort chega a O(n²). 2 verdadeira: os dois dividem o problema e resolvem as partes. 3 verdadeira: o Mergesort é Θ(n log n) em qualquer caso. 4 falsa: a seleção varre o resto do vetor a cada passo, mesmo ordenado, e fica em Θ(n²)."
     },
     {
      "letra": "C",
      "texto": "V, F, F, V",
      "porque": "É o oposto do certo nas quatro. O Quicksort é O(n²) no pior caso, os dois usam divisão e conquista, o Mergesort é Θ(n log n) e a seleção não melhora com a entrada ordenada."
     },
     {
      "letra": "D",
      "texto": "F, F, F, F",
      "porque": "Acerta a 1 e a 4, mas erra a 2 e a 3: Quicksort e Mergesort são de divisão e conquista, e o Mergesort é Θ(n log n)."
     }
    ],
    "gabarito": "B",
    "resumo": "Decore a tabela: Quicksort O(n log n) médio e O(n²) pior; Mergesort Θ(n log n) sempre; seleção Θ(n²) sempre; inserção O(n) no melhor caso (quase ordenada). A seleção é o algoritmo que não ganha nada com entrada ordenada, e a pegadinha da 4 é confundi-la com a inserção.",
    "assuntos": [
     {
      "num": "0094",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0096",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Os itens 8, 3, 4, 9, 5, 6, 2, 1, 7 são inseridos, nessa ordem, numa árvore binária de busca. Qual item fica na raiz?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "1",
      "porque": "O 1 é o penúltimo a entrar e vira folha (filho esquerdo do 2). Numa ABB sem balanceamento, ninguém sobe para a raiz depois."
     },
     {
      "letra": "B",
      "texto": "4",
      "porque": "O 4 entra como filho direito do 3 e fica abaixo da raiz. Seria raiz se a árvore fosse reorganizada pela mediana, o que não acontece aqui."
     },
     {
      "letra": "C",
      "texto": "8",
      "porque": "O primeiro inserido é a raiz, e a ABB comum não faz rotações. Todo o resto desce: 3 e 4 à esquerda, 9 à direita, e assim por diante."
     },
     {
      "letra": "D",
      "texto": "9",
      "porque": "O 9 é filho direito do 8. Ele só seria raiz numa árvore em que fosse o primeiro a entrar."
     }
    ],
    "gabarito": "C",
    "resumo": "Em ABB sem balanceamento, a raiz é sempre o primeiro valor inserido. Não precisa desenhar a árvore inteira. Isso muda em AVL ou rubro-negra, onde rotações podem trocar a raiz.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 5,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Para implementar uma pilha com operações de custo O(1) usando uma lista simplesmente encadeada, onde devem ficar as operações push e pop?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "push depois do último, pop no último",
      "porque": "Remover o último exige achar o penúltimo, e numa lista simples isso é percorrer tudo: O(n). Só o push seria constante, e ainda assim com ponteiro para o fim."
     },
     {
      "letra": "B",
      "texto": "push antes do primeiro, pop no primeiro",
      "porque": "Inserir e remover na cabeça só mexe no ponteiro inicial, sem percorrer nada: O(1) nas duas. Além disso, quem entra por último sai primeiro, que é o LIFO da pilha."
     },
     {
      "letra": "C",
      "texto": "push antes do primeiro, pop no último",
      "porque": "O pop no último é O(n) numa lista simples, pelo motivo da primeira alternativa. Além disso, entrar na cabeça e sair pela cauda é comportamento de fila, não de pilha."
     },
     {
      "letra": "D",
      "texto": "push depois do último, pop no primeiro",
      "porque": "Inserir no fim exige ponteiro para a cauda ou percurso, e retirar do começo é o contrário do LIFO. Isso é uma fila (FIFO), não uma pilha."
     }
    ],
    "gabarito": "B",
    "resumo": "Lista simples só tem acesso O(1) à cabeça. Por isso a pilha usa a cabeça para push e pop. Se a prova pedir uma fila O(1), a resposta muda: precisa de ponteiro para a cauda e se insere por ali.",
    "assuntos": [
     {
      "num": "0083",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 3,
    "formato": "código",
    "enunciado": "(Python) Considere a classe `Vector` da questão 1. Qual a saída?\n\n```python\nvec_1 = Vector([1,2,3,4,5])\nvec_2 = vec_1\nvec_2.row[2] = 15\nprint(vec_1.row)\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "[ 2 15 4 5]",
      "porque": "Faltam o 1 e o formato de lista com vírgulas. Nada remove elementos: a atribuição só troca o valor da posição 2."
     },
     {
      "letra": "B",
      "texto": "[ 0 1 2 15 4 5]",
      "porque": "Tem seis elementos e um 0 que nunca existiu. A lista original tem cinco posições e só a de índice 2 muda."
     },
     {
      "letra": "C",
      "texto": "[ 1 2 15 4 15]",
      "porque": "Mudaria a última posição também, mas o código altera só `row[2]`. O outro 15 não tem de onde vir."
     },
     {
      "letra": "D",
      "texto": "[ 1 2 15 4 5]",
      "porque": "`vec_2 = vec_1` não copia: as duas variáveis apontam para o mesmo objeto. Mudar `row[2]` por uma aparece na outra. A posição 2 (o 3) vira 15 e o resto fica igual."
     }
    ],
    "gabarito": "D",
    "resumo": "Atribuição de objeto em Python copia a referência, não o conteúdo. É o mesmo efeito de dois ponteiros para o mesmo bloco em C. Para ter cópia independente, use `list(...)` ou `copy`.",
    "assuntos": [
     {
      "num": "0044",
      "modulo": "06-ponteiros.md"
     },
     {
      "num": "0062",
      "modulo": "08-structs.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 2,
    "formato": "conceito",
    "enunciado": "Sejam f(n) = (n+1)(n−1) e g(n) = 8·log2(n) + 1, com n > 0. Assinale a alternativa correta:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "f e g são exponenciais",
      "porque": "Nenhuma das duas é: f(n) = n² − 1 é polinomial e g cresce com o logaritmo. Exponencial seria algo como 2ⁿ."
     },
     {
      "letra": "B",
      "texto": "f é quadrática e g é linear",
      "porque": "Acerta f (n² − 1), mas g não é linear: 8·log2(n) + 1 é logarítmica, que cresce bem mais devagar que n."
     },
     {
      "letra": "C",
      "texto": "g(n) = Ω(f(n))",
      "porque": "Ω é limite inferior. Dizer isso é afirmar que g cresce pelo menos como n², e o logaritmo cresce muito menos. A relação é a inversa."
     },
     {
      "letra": "D",
      "texto": "g(n) = O(f(n))",
      "porque": "Como log n cresce mais devagar que n², existe constante c tal que 8·log2(n) + 1 ≤ c·(n² − 1) para n grande. Logo g = O(f)."
     }
    ],
    "gabarito": "D",
    "resumo": "Expanda f: (n+1)(n−1) = n² − 1, quadrática. g é logarítmica. Ordem de crescimento: log n, n, n log n, n², 2ⁿ. O de cima é limite superior; o que cresce mais devagar é O do que cresce mais rápido.",
    "assuntos": [
     {
      "num": "0072",
      "modulo": "10-analise.md"
     },
     {
      "num": "0166",
      "modulo": "26-analise-formal.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 1,
    "formato": "código",
    "enunciado": "(Python) Considere `fibonacci(n)`: se n == 1 devolve 0; se n == 2 devolve 1; senão devolve fibonacci(n-1) + fibonacci(n-2). Qual a saída de `print(fibonacci(7))`?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "13",
      "porque": "É o oitavo termo (0, 1, 1, 2, 3, 5, 8, 13). Aqui a sequência começa com f(1) = 0, então f(7) é o sétimo."
     },
     {
      "letra": "B",
      "texto": "5",
      "porque": "É f(6). Quem conta a partir do 1 como primeiro termo, em vez do 0, erra por uma posição."
     },
     {
      "letra": "C",
      "texto": "0",
      "porque": "É o caso base de n = 1. A chamada com 7 passa pela recursão e soma os dois anteriores."
     },
     {
      "letra": "D",
      "texto": "8",
      "porque": "A sequência com f(1) = 0 e f(2) = 1 é 0, 1, 1, 2, 3, 5, 8. O sétimo termo é 8. Rodado em Python: imprime 8."
     }
    ],
    "gabarito": "D",
    "resumo": "Escreva a sequência com os casos base do enunciado e conte as posições. Atenção ao ponto de partida: aqui f(1) = 0, e não f(0) = 0, o que desloca tudo uma casa.",
    "assuntos": [
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     },
     {
      "num": "0033",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 8,
    "formato": "conceito",
    "enunciado": "Um grafo é uma árvore se e somente se:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "é planar",
      "porque": "Planar é poder desenhar sem cruzar arestas. Toda árvore é planar, mas muito grafo planar tem ciclos e não é árvore."
     },
     {
      "letra": "B",
      "texto": "é conexo, não direcionado e não contém ciclos",
      "porque": "Essa é a definição: conexo (um caminho entre quaisquer dois vértices), não direcionado e acíclico. Resulta em n − 1 arestas para n vértices."
     },
     {
      "letra": "C",
      "texto": "é completamente conectado",
      "porque": "Grafo completo tem aresta entre todo par de vértices e, com três ou mais vértices, tem ciclos. É o oposto de uma árvore."
     },
     {
      "letra": "D",
      "texto": "todo grafo é uma árvore",
      "porque": "Falso: grafos com ciclos, desconexos ou com arestas demais não são árvore. A árvore é um caso particular."
     }
    ],
    "gabarito": "B",
    "resumo": "Árvore = conexo + sem ciclos (+ não direcionado). Se faltar qualquer uma das três condições, não é árvore. Grafo com ciclo ou desconexo é a pegadinha clássica.",
    "assuntos": [
     {
      "num": "0109",
      "modulo": "16-grafos.md"
     },
     {
      "num": "0150",
      "modulo": "23-grafos-avancados.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 3,
    "formato": "conceito",
    "enunciado": "Sobre matrizes bidimensionais de inteiros, assinale a alternativa INCORRETA:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O produto de uma matriz m×n por uma matriz x×y resulta numa matriz de n linhas e y colunas",
      "porque": "É a incorreta. Para o produto existir, n deve ser igual a x, e o resultado tem m linhas (da primeira) e y colunas (da segunda), não n linhas."
     },
     {
      "letra": "B",
      "texto": "A soma dos elementos pode ser feita com dois laços aninhados e um acumulador",
      "porque": "Correta. Um laço percorre as linhas, outro as colunas, e o acumulador soma cada elemento."
     },
     {
      "letra": "C",
      "texto": "Uma matriz pode ser representada com listas encadeadas",
      "porque": "Correta. É possível usar lista de listas ou nós com ponteiros para o vizinho de baixo e da direita, útil em matrizes esparsas."
     },
     {
      "letra": "D",
      "texto": "Uma matriz m×n tem m·n espaços para inteiros",
      "porque": "Correta. São m linhas de n colunas, ou seja, m·n posições."
     }
    ],
    "gabarito": "A",
    "resumo": "Em questão de INCORRETA, ache a única afirmação falsa. Produto de matrizes: (m×n)·(n×y) = m×y. Guarde isso e a questão fecha em segundos.",
    "assuntos": [
     {
      "num": "0039",
      "modulo": "05-vetores-e-strings.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 11,
    "topico": 6,
    "formato": "afirmações",
    "enunciado": "O pseudocódigo abaixo insere `novo` num vetor ordenado `vetor[1..N]`. Primeiro uma busca binária acha a posição `i`; depois `vetor[N+1] = novo` e um laço desloca os elementos.\n\n```\ni = 1; j = N\nenquanto (i <= j):\n  meio = floor((i + j) / 2)\n  se vetor[meio] > novo: j = meio - 1\n  senão: i = meio + 1\nvetor[N+1] = novo\nfor (k = N+1; k == i; k--)\n  trocar(vetor, k, k-1);\n```\n\n(O laço está assim no original. O texto do pseudocódigo veio resumido, com a mesma estrutura.)\n\nCompare com a ordenação por inserção:\n\n1. Insere com menos comparações que a ordenação por inserção.\n2. Insere com o mesmo número de comparações.\n3. Insere com o mesmo número de movimentações.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Somente 1",
      "porque": "Está certa quanto às comparações, mas deixa de fora a 3: as movimentações são as mesmas nos dois."
     },
     {
      "letra": "B",
      "texto": "2 e 3",
      "porque": "A 2 é falsa. A busca binária faz cerca de log n comparações, e a inserção sequencial pode fazer até n."
     },
     {
      "letra": "C",
      "texto": "Somente 3",
      "porque": "A 3 é verdadeira, mas a 1 também. Faltou ela."
     },
     {
      "letra": "D",
      "texto": "1 e 3",
      "porque": "Busca binária reduz as comparações a O(log n) contra O(n) da inserção (1 verdadeira). Os elementos maiores que `novo` precisam ser deslocados do mesmo jeito (3 verdadeira). A 2 é falsa."
     }
    ],
    "gabarito": "D",
    "resumo": "1 verdadeira: busca binária é O(log n) em comparações. 2 falsa. 3 verdadeira: o deslocamento continua O(n). O `for (...; k == i; ...)` está estranho no original (executaria no máximo uma vez), e a banca pode ter tratado como erro de digitação. Dica: busca binária corta as comparações, não as movimentações.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Qual o limite superior assintótico do Quick Sort no pior caso?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O(n)",
      "porque": "Seria o custo de uma passada só. O Quicksort particiona em O(n), mas faz isso em muitos níveis."
     },
     {
      "letra": "B",
      "texto": "O(n log n)",
      "porque": "É o caso médio e o melhor caso, com partições equilibradas. No pior caso a partição é desbalanceada e a recursão tem n níveis."
     },
     {
      "letra": "C",
      "texto": "O(n!)",
      "porque": "Cresce muito além do que o Quicksort faz. Nenhum caso dele chega perto de fatorial."
     },
     {
      "letra": "D",
      "texto": "O(n²)",
      "porque": "Se o pivô é sempre o menor ou o maior (por exemplo, vetor já ordenado com pivô nas pontas), a recursão tem n níveis de custo até n cada: O(n²)."
     }
    ],
    "gabarito": "D",
    "resumo": "Quicksort: O(n log n) médio, O(n²) pior. A banca repete esse fato em várias provas. Mergesort e Heapsort são os que garantem O(n log n) no pior caso.",
    "assuntos": [
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 3,
    "formato": "código",
    "enunciado": "O que faz o código C abaixo?\n\n```c\n#include <stdio.h>\n#define MAX 50\nint main() {\n  int m, soma=0;\n  int mat[MAX][MAX];\n  scanf(\"%d\", &m);\n  for (int i=0; i<m; i++)\n    for (int j=0; j<m; j++)\n      scanf(\"%d\", &mat[i][j]);\n  for (int i=0; i<m; i++)\n    for (int j=i; j<m; j++)\n      soma += mat[i][j];\n  printf(\"%d\\n\", soma);\n}\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Soma dos elementos iguais ou acima da diagonal principal",
      "porque": "O segundo laço roda j de i até m−1, ou seja, colunas iguais ou à direita da diagonal, o que fica na diagonal e acima dela."
     },
     {
      "letra": "B",
      "texto": "Soma de todos os elementos",
      "porque": "Somaria tudo se `j` começasse em 0. Como começa em `i`, os elementos abaixo da diagonal ficam de fora."
     },
     {
      "letra": "C",
      "texto": "Imprime só mat[m][m]",
      "porque": "Nenhum índice é fixo em m, e `mat[m][m]` está fora da matriz (os índices vão até m−1). O código soma muitos elementos."
     },
     {
      "letra": "D",
      "texto": "Soma dos elementos iguais ou abaixo da diagonal principal",
      "porque": "Para somar a parte de baixo, o laço interno iria de 0 até `i`. Aqui `j` parte de `i` e vai até `m`, a parte de cima."
     }
    ],
    "gabarito": "A",
    "resumo": "Em laço duplo sobre matriz, olhe o início e o fim do laço interno: j de i até m é a diagonal e acima; j de 0 até i é a diagonal e abaixo. Teste com uma matriz 2x2 se tiver dúvida.",
    "assuntos": [
     {
      "num": "0039",
      "modulo": "05-vetores-e-strings.md"
     },
     {
      "num": "0024",
      "modulo": "03-repeticoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 1,
    "formato": "código",
    "enunciado": "Qual a saída do programa C?\n\n```c\nvoid func1 (int x) { x = 9 * x; }\nvoid func2 (int v[]) { v[0] = 3 * v[0]; }\nvoid main (void) {\n  int x, v[2];\n  x = 222;\n  func1(x);\n  printf(\"x: %d\\n\", x);\n  v[0] = 333;\n  func2(v);\n  printf(\"v[0]: %d\\n\", v[0]);\n}\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "x: 222 e v[0]: 999",
      "porque": "`func1` recebe cópia de x, então o x do `main` continua 222. `func2` recebe o endereço do vetor e altera o original: 3·333 = 999. Rodado em C."
     },
     {
      "letra": "B",
      "texto": "x: 222 e v[0]: 222",
      "porque": "Acerta o x, mas o vetor muda. Vetor em C passa como ponteiro, então a função altera o v[0] original."
     },
     {
      "letra": "C",
      "texto": "x: 222 e v[0]: 666",
      "porque": "666 seria 2·333. O código multiplica por 3, e 3·333 = 999."
     },
     {
      "letra": "D",
      "texto": "x: 222 e v[0]: 333",
      "porque": "Essa seria a saída se o vetor também fosse passado por valor. Em C não é: o parâmetro `int v[]` vira `int *v`."
     }
    ],
    "gabarito": "A",
    "resumo": "Escalar passa por valor (cópia), vetor passa por endereço. Mudança em escalar dentro da função some; em vetor, aparece fora. Isso cai em toda prova de C.",
    "assuntos": [
     {
      "num": "0029",
      "modulo": "04-funcoes.md"
     },
     {
      "num": "0038",
      "modulo": "05-vetores-e-strings.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 3,
    "formato": "código",
    "enunciado": "O que faz a função abaixo?\n\n```c\nLista* abracadabra (Lista* l, int v) {\n  Lista* novo = (Lista*) malloc(sizeof(Lista));\n  novo->info = v;\n  novo->prox = l;\n  novo->ant = NULL;\n  if (l) { l->ant = novo };\n  return novo;\n}\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Insere no início de uma lista duplamente encadeada",
      "porque": "O nó novo aponta `prox` para a antiga cabeça, tem `ant = NULL` e a antiga cabeça passa a ter `ant = novo`. Isso é inserção na cabeça de uma lista dupla."
     },
     {
      "letra": "B",
      "texto": "Insere no final de uma lista duplamente encadeada",
      "porque": "Para inserir no final, o `prox` do novo seria NULL e o antigo último apontaria para ele. Aqui o `prox` do novo é a lista inteira."
     },
     {
      "letra": "C",
      "texto": "Insere no início de uma lista simples",
      "porque": "Lista simples não tem o campo `ant`. O código ajusta `ant` nos dois nós, logo a lista é dupla."
     },
     {
      "letra": "D",
      "texto": "Insere no fim de uma lista simples",
      "porque": "Além de usar `ant`, o novo nó vira a cabeça (é o valor devolvido) e não o último."
     }
    ],
    "gabarito": "A",
    "resumo": "Leia os ponteiros: `novo->prox = l` coloca o novo na frente; `ant` mostra que é lista dupla. O `l->ant = novo` fecha a ligação de volta. Devolver `novo` indica que a cabeça mudou.",
    "assuntos": [
     {
      "num": "0079",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 5,
    "formato": "simulação",
    "enunciado": "Tabela hash com m = 9, endereçamento aberto com sondagem linear e h(k) = k mod 9. Inserindo as chaves 73, 24, 16, 46, 28, nessa ordem, qual a tabela final (posições 0 a 8)?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "ø 73 16 ø ø 28 24 46 ø",
      "porque": "O 46 não pode estar na 7: ela já é do 16. Pela sondagem linear, o 46 (h = 1) colide com o 73 e vai para a posição 2, e o 28 (h = 1) vai para a 3."
     },
     {
      "letra": "B",
      "texto": "28 46 73 ø ø ø ø 24 16",
      "porque": "73 mod 9 é 1, e não 2. A tabela não confere com os restos das divisões."
     },
     {
      "letra": "C",
      "texto": "ø 73 46 28 ø ø 24 16 ø",
      "porque": "73 mod 9 = 1, 24 mod 9 = 6, 16 mod 9 = 7. O 46 também dá 1, colide e vai para 2; o 28 dá 1, colide com 73 e 46 e vai para 3. Tabela: ø 73 46 28 ø ø 24 16 ø."
     },
     {
      "letra": "D",
      "texto": "73 46 ø ø ø ø 28 24 16",
      "porque": "Põe 73 na posição 0, mas 73 mod 9 = 1. Todos os valores estão deslocados."
     }
    ],
    "gabarito": "C",
    "resumo": "Calcule o resto de cada chave e, havendo colisão, ande uma casa para a direita até achar vazio. Inserir na ordem do enunciado importa: quem chega primeiro fica com a posição natural. Observação: a alternativa C aparece no texto com 8 células (falta o ø final); tratei como erro de extração.",
    "assuntos": [
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 17,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Sobre árvores vermelho-preto, considere:\n\n1. A raiz é preta.\n2. Toda subárvore nula é preta.\n3. Se um nó é vermelho, os filhos são pretos.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas 2 e 3",
      "porque": "Deixa a 1 de fora, mas ela também é propriedade da árvore rubro-negra: a raiz é sempre preta."
     },
     {
      "letra": "B",
      "texto": "Todas",
      "porque": "As três são propriedades da árvore vermelho-preto (a versão do Cormen): raiz preta, folhas nulas pretas e nenhum vermelho com filho vermelho."
     },
     {
      "letra": "C",
      "texto": "Apenas 1 e 2",
      "porque": "Deixa a 3 de fora. A regra de que o filho de um nó vermelho é preto é justamente o que limita a altura."
     },
     {
      "letra": "D",
      "texto": "Apenas 1",
      "porque": "As propriedades 2 e 3 também valem, então a 1 sozinha é incompleta."
     }
    ],
    "gabarito": "B",
    "resumo": "São as propriedades da definição do Cormen: nó vermelho ou preto, raiz preta, folha nula preta, vermelho só tem filho preto, e mesmo número de nós pretos em todo caminho. Quando a banca lista propriedades assim, geralmente são todas verdadeiras.",
    "assuntos": [
     {
      "num": "0177",
      "modulo": "28-estruturas-complementos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 8,
    "formato": "afirmações",
    "enunciado": "Sobre grafos, considere:\n\n1. O algoritmo de Dijkstra encontra o menor caminho, mas só serve para casos pequenos ou médios por ter complexidade exponencial.\n2. A busca em largura normalmente usa uma fila.\n3. Em grafos esparsos, a matriz de adjacências consome mais memória do que a lista de adjacências.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas 2 e 3",
      "porque": "A 1 é falsa: Dijkstra é polinomial, O((V+E) log V) com heap. A 2 é verdadeira (BFS usa fila). A 3 é verdadeira: a matriz gasta V² mesmo com poucas arestas, e a lista gasta V + E."
     },
     {
      "letra": "B",
      "texto": "Apenas 1 e 2",
      "porque": "Inclui a 1 (falsa) e exclui a 3 (verdadeira)."
     },
     {
      "letra": "C",
      "texto": "Apenas 1",
      "porque": "Só a 1 é falsa, então essa alternativa marca exatamente a errada como certa."
     },
     {
      "letra": "D",
      "texto": "Nenhuma",
      "porque": "As afirmações 2 e 3 são verdadeiras, então não é verdade que nenhuma vale."
     }
    ],
    "gabarito": "A",
    "resumo": "1 falsa: Dijkstra é eficiente (polinomial), o que não funciona é com pesos negativos. 2 e 3 verdadeiras. Grafo esparso: use lista de adjacências. Grafo denso: matriz.",
    "assuntos": [
     {
      "num": "0110",
      "modulo": "16-grafos.md"
     },
     {
      "num": "0112",
      "modulo": "16-grafos.md"
     },
     {
      "num": "0109",
      "modulo": "16-grafos.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Em uma árvore AVL, já tendo a referência para o nó a ser removido (sem fazer busca), quais são o melhor e o pior caso da remoção?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O(log n), O(log n)",
      "porque": "Supõe que o melhor caso também gasta log n. Mas se a remoção não desbalanceia nenhum nó, o trabalho é constante."
     },
     {
      "letra": "B",
      "texto": "O(1), O(log n)",
      "porque": "No melhor caso, remover um nó sem filhos não desbalanceia nada: O(1). No pior caso, o rebalanceamento sobe até a raiz com rotações, e a altura é O(log n)."
     },
     {
      "letra": "C",
      "texto": "O(1), O(n)",
      "porque": "O pior caso não passa de O(log n), porque a AVL tem altura logarítmica e o rebalanceamento só percorre um caminho."
     },
     {
      "letra": "D",
      "texto": "O(log n), O(n)",
      "porque": "Nenhum dos dois: o pior caso é logarítmico (a árvore é balanceada) e o melhor é constante."
     }
    ],
    "gabarito": "B",
    "resumo": "Banca aponta B. Observação: se a remoção de um nó com dois filhos exigir achar o sucessor, o melhor caso também seria O(log n) (alternativa A). Fique com B e saiba que depende do que se conta. Altura da AVL é O(log n), e isso limita o pior caso.",
    "assuntos": [
     {
      "num": "0176",
      "modulo": "28-estruturas-complementos.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": 3,
    "formato": "cálculo",
    "enunciado": "Numa lista implementada com vetor, qual o pior caso de: busca por um elemento, acesso por índice, inserção no início, inserção no final e remoção por índice, nessa ordem?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O(n), O(1), O(1), O(n), O(n)",
      "porque": "Erra a inserção no início e no final. Inserir no início desloca todos os elementos (O(n)), e no final basta escrever na próxima posição livre (O(1))."
     },
     {
      "letra": "B",
      "texto": "O(n), O(1), O(n), O(1), O(n)",
      "porque": "Busca varre o vetor: O(n). Índice vai direto: O(1). Início desloca tudo: O(n). Final escreve na posição livre: O(1). Remoção por índice fecha o buraco deslocando: O(n)."
     },
     {
      "letra": "C",
      "texto": "O(1), O(n), O(n), O(n), O(1)",
      "porque": "Inverte quase tudo: busca não é O(1) num vetor sem ordem, e acesso por índice não é O(n)."
     },
     {
      "letra": "D",
      "texto": "O(n), O(n), O(1), O(n), O(1)",
      "porque": "O acesso por índice é O(1), e a inserção no início é O(n). Aqui estão trocados."
     }
    ],
    "gabarito": "B",
    "resumo": "Vetor: acesso por índice O(1), final O(1) (se houver espaço), todo o resto que desloca ou varre é O(n). Memorize esse quadro, ele aparece de várias formas.",
    "assuntos": [
     {
      "num": "0075",
      "modulo": "11-listas.md"
     },
     {
      "num": "0072",
      "modulo": "10-analise.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "020/2023",
  "slug": "2023-020",
  "ano": 2023,
  "oficial": false,
  "questoes": [
   {
    "numero": 1,
    "topico": 6,
    "formato": "cálculo",
    "enunciado": "Dado o vetor ordenado `10 30 50 60 70 80 90 100 120 130` (posições 0 a 9), quantas comparações a busca binária faz no pior caso?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "6",
      "porque": "Seis comparações é mais do que a busca binária precisa para 10 elementos. A cada passo o intervalo cai pela metade: 10, 5, 2, 1."
     },
     {
      "letra": "B",
      "texto": "10",
      "porque": "É o pior caso da busca sequencial, que pode olhar todos os elementos. A binária descarta metade a cada comparação."
     },
     {
      "letra": "C",
      "texto": "4",
      "porque": "O pior caso é ⌊log2 10⌋ + 1 = 3 + 1 = 4 comparações: o intervalo vai de 10 para 5, 2, 1 e depois para vazio."
     },
     {
      "letra": "D",
      "texto": "1",
      "porque": "É o melhor caso, quando a chave está exatamente no meio na primeira tentativa. A pergunta é o pior caso."
     }
    ],
    "gabarito": "C",
    "resumo": "Busca binária faz no máximo ⌊log2 n⌋ + 1 comparações. Para 10 elementos, ⌊3,32⌋ + 1 = 4. Decore a fórmula e a conta sai sem simular.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 7,
    "formato": "conceito",
    "enunciado": "Sobre a ordenação por inserção, assinale a correta:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Fica mais rápida com o vetor quase ordenado e é mais lenta com o vetor invertido",
      "porque": "Cada elemento só anda até achar seu lugar. Quase ordenado, quase não anda nada: O(n). Invertido, cada um percorre tudo à esquerda: O(n²)."
     },
     {
      "letra": "B",
      "texto": "O tempo independe da ordem inicial, sempre quadrático",
      "porque": "Isso vale para a seleção, não para a inserção. Na inserção a quantidade de deslocamentos depende de quantos elementos estão fora de ordem."
     },
     {
      "letra": "C",
      "texto": "O tempo independe da ordem, sempre linear",
      "porque": "No pior caso (invertido) é quadrático. Linear só no melhor caso."
     },
     {
      "letra": "D",
      "texto": "Não ordena chaves negativas",
      "porque": "Ordena normalmente: só usa comparação entre chaves, e o sinal não importa."
     }
    ],
    "gabarito": "A",
    "resumo": "Inserção é adaptativa: custo de O(n + inversões). Melhor caso O(n) (ordenado), pior O(n²) (invertido). É a diferença chave em relação à seleção, que é sempre O(n²).",
    "assuntos": [
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "Uma pilha contém `[4, 16, 1, 7, 8, 13]`, com o topo à esquerda. Três desempilhamentos são feitos, depois empilha-se 5 e depois 2. Como fica a pilha?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "[7, 8, 13, 5, 2]",
      "porque": "Colocou o 5 e o 2 no fundo da pilha. O topo é a esquerda, então os novos entram na frente."
     },
     {
      "letra": "B",
      "texto": "[4, 16, 2, 5, 2]",
      "porque": "Não é possível: os elementos 4 e 16 já saíram nos desempilhamentos, e há dois 2."
     },
     {
      "letra": "C",
      "texto": "[5, 2, 7, 8, 13]",
      "porque": "Deixou o 5 na frente do 2. O último a entrar (2) fica no topo, antes do 5."
     },
     {
      "letra": "D",
      "texto": "[2, 5, 7, 8, 13]",
      "porque": "Três pops tiram 4, 16 e 1, sobrando [7, 8, 13]. Push 5 dá [5, 7, 8, 13]; push 2 dá [2, 5, 7, 8, 13]."
     }
    ],
    "gabarito": "D",
    "resumo": "LIFO: o último a entrar é o primeiro a sair. Faça um passo por vez: pop, pop, pop, push, push. Atenção a qual lado é o topo.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 5,
    "formato": "afirmações",
    "enunciado": "Sobre tabela hash com encadeamento, considere:\n\nI. Não gera colisões secundárias.\nII. Tem custo O(n) no pior caso.\nIII. Ao contrário do endereçamento aberto, aceita mais chaves que o tamanho da tabela.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Nenhuma",
      "porque": "As três são verdadeiras, então não é o caso."
     },
     {
      "letra": "B",
      "texto": "Apenas II",
      "porque": "Deixa de fora a I e a III, que também são verdadeiras."
     },
     {
      "letra": "C",
      "texto": "Apenas I e II",
      "porque": "Falta a III: cada posição guarda uma lista, então dá para ter mais chaves que posições."
     },
     {
      "letra": "D",
      "texto": "Todas",
      "porque": "I: colisão secundária (agrupamento) é problema de endereçamento aberto; no encadeamento, quem colide só entra na lista do balde. II: se todas as chaves caírem no mesmo balde, a busca varre uma lista de n itens. III: cada balde é uma lista, sem limite de tamanho."
     }
    ],
    "gabarito": "D",
    "resumo": "Encadeamento: sem agrupamento, fator de carga pode passar de 1, pior caso O(n) se tudo cair no mesmo balde. Endereçamento aberto exige n ≤ m. Esta é uma das provas sem gabarito oficial, então a letra é conferida pelo conteúdo do curso.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     },
     {
      "num": "0107",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 5,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Compare um vetor mantido ordenado com uma árvore binária de pesquisa balanceada:\n\nI. O vetor tem inserção e remoção mais baratas por não alocar nós.\nII. No pior caso, a busca custa assintoticamente o mesmo nos dois.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas I",
      "porque": "A I é falsa e a II é verdadeira, então essa combinação erra nas duas."
     },
     {
      "letra": "B",
      "texto": "Apenas II",
      "porque": "I falsa: inserir ou remover no vetor ordenado desloca elementos, O(n), enquanto na árvore balanceada é O(log n). Alocar nó custa pouco perto disso. II verdadeira: busca binária no vetor e busca na árvore balanceada são O(log n)."
     },
     {
      "letra": "C",
      "texto": "As duas",
      "porque": "Aceita a I, que é falsa: o custo do deslocamento no vetor é maior que o da alocação do nó."
     },
     {
      "letra": "D",
      "texto": "Nenhuma",
      "porque": "A II é verdadeira: os dois têm busca O(log n)."
     }
    ],
    "gabarito": "B",
    "resumo": "Vetor ordenado: busca O(log n), inserção e remoção O(n). ABB balanceada: tudo O(log n). O que o vetor ganha é localidade de memória, não o custo assintótico.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 4,
    "formato": "conceito",
    "enunciado": "Considere uma árvore com três nós e raiz 5 (a figura não veio no caderno). Assinale a alternativa correta:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Pode ser rubro-negra, pois está balanceada",
      "porque": "Estar balanceada não basta: rubro-negra depende das cores dos nós e das regras de coloração. Sem a figura, não dá para afirmar."
     },
     {
      "letra": "B",
      "texto": "Pode representar uma árvore binária de pesquisa, com ou sem balanceamento",
      "porque": "Três nós com raiz 5 cabem numa ABB de várias formas, balanceada ou não. É a afirmação mais geral e a que sempre pode valer."
     },
     {
      "letra": "C",
      "texto": "Pode representar uma heap mínima",
      "porque": "Heap mínima pede raiz menor ou igual aos filhos. Se a raiz 5 tiver filho menor, não é. A afirmação depende dos valores, que estão na figura ausente."
     },
     {
      "letra": "D",
      "texto": "É AVL, pois está balanceada",
      "porque": "Dizer que É AVL exige que a diferença de altura seja no máximo 1 e que seja ABB. Sem a figura não se prova."
     }
    ],
    "gabarito": "B",
    "resumo": "A figura não veio, então a letra B foi inferida (as outras exigem informação que só a figura traria). Quando a figura some, a alternativa mais geral e com 'pode' costuma ser a segura. Sem gabarito oficial desta prova.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     },
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 2,
    "formato": "conceito",
    "enunciado": "Sobre complexidade, assinale a alternativa correta:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "A busca binária é O(N/2) no pior caso",
      "porque": "N/2 é linear, equivale a O(N). A busca binária é O(log N)."
     },
     {
      "letra": "B",
      "texto": "Inserir sem ordem numa lista encadeada custa constante no pior caso",
      "porque": "Inserindo na cabeça (ou na cauda com ponteiro para o fim), só se ajustam ponteiros, sem percorrer nada: O(1)."
     },
     {
      "letra": "C",
      "texto": "Inserir no início de um vetor custa constante no pior caso",
      "porque": "É preciso deslocar todos os elementos uma casa: O(n)."
     },
     {
      "letra": "D",
      "texto": "Inserir numa árvore binária de pesquisa custa constante no pior caso",
      "porque": "Tem que descer até a posição certa: O(log n) balanceada, O(n) degenerada."
     }
    ],
    "gabarito": "B",
    "resumo": "Lista encadeada: inserção na cabeça é O(1). Vetor: início é O(n). ABB: depende da altura. Busca binária é O(log n); cuidado com 'N/2', que parece logarítmico mas é linear.",
    "assuntos": [
     {
      "num": "0072",
      "modulo": "10-analise.md"
     },
     {
      "num": "0076",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 7,
    "formato": "código",
    "enunciado": "Considere o código (resumido): `par` intercala `v[inicio..meio]` e `v[meio+1..fim]`, ambas ordenadas, usando o vetor auxiliar `vaux`; `sortR` calcula o meio, chama a si mesma nas duas metades e depois chama `par`; `sort` aloca `vaux`, chama `sortR` e libera `vaux`. Que algoritmo é esse?\n\n(O código completo não veio no texto; vale esta descrição.)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Quick Sort",
      "porque": "O Quick Sort escolhe um pivô e particiona antes de recursar, sem vetor auxiliar para intercalar."
     },
     {
      "letra": "B",
      "texto": "Radix Sort",
      "porque": "O Radix ordena por dígito, sem comparação entre elementos nem recursão em metades."
     },
     {
      "letra": "C",
      "texto": "Merge Sort",
      "porque": "Divide o vetor ao meio, ordena cada metade recursivamente e intercala as duas com um vetor auxiliar. É o Merge Sort."
     },
     {
      "letra": "D",
      "texto": "Não ordena o vetor",
      "porque": "Se a intercalação está correta, o vetor sai ordenado. A banca trata o código como correto."
     }
    ],
    "gabarito": "C",
    "resumo": "Divisão ao meio + recursão nas duas partes + intercalação com vetor auxiliar = Merge Sort. A letra assume que o código está correto, e o resumo do enunciado não permite conferir linha a linha.",
    "assuntos": [
     {
      "num": "0094",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 1,
    "formato": "código",
    "enunciado": "O pseudocódigo recursivo (com `len`, `max` e `lista[1:]`) aparecia como imagem, que não veio no caderno. Qual a saída?\n\n(a figura não veio no caderno)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "13",
      "porque": "Sem o pseudocódigo não dá para conferir este valor."
     },
     {
      "letra": "B",
      "texto": "3",
      "porque": "Sem o pseudocódigo não dá para conferir este valor."
     },
     {
      "letra": "C",
      "texto": "11",
      "porque": "Sem o pseudocódigo não dá para conferir este valor."
     },
     {
      "letra": "D",
      "texto": "2",
      "porque": "Sem o pseudocódigo não dá para conferir este valor."
     }
    ],
    "gabarito": null,
    "resumo": "Questão sem resposta: a figura não veio, e a letra não foi definida. Em recursão com fatia `lista[1:]`, o caso base é lista vazia ou de um elemento e cada chamada trata o primeiro elemento. Na prova, desenhe a pilha de chamadas.",
    "assuntos": [
     {
      "num": "0032",
      "modulo": "04-funcoes.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 3,
    "formato": "simulação",
    "enunciado": "O pseudocódigo (que não veio no caderno) calcula o produto de uma matriz m×n por uma n×p, com m = 2, n = 3 e p = 2. Qual o valor de `resultMatrix`?\n\n(a figura não veio no caderno)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "{{0, 0}, {0, 0}}",
      "porque": "Tem a forma certa (2×2), mas todos zeros só ocorre se os produtos se anularem. Sem o código, é possível, não confirmado."
     },
     {
      "letra": "B",
      "texto": "{{0, 30, 0}, {45, 0, 0}}",
      "porque": "Tem 2 linhas e 3 colunas. O produto de uma 2×3 por uma 3×2 é 2×2."
     },
     {
      "letra": "C",
      "texto": "{{0, 30}, {45, 0}, {9, 8}}",
      "porque": "Tem 3 linhas e 2 colunas. O resultado deveria ter m = 2 linhas."
     },
     {
      "letra": "D",
      "texto": "{{0, 30}, {45, 0}}",
      "porque": "É 2×2, a forma que m = 2 e p = 2 impõem. A letra D é um palpite: só A e D têm essa forma e as matrizes não estão no texto."
     }
    ],
    "gabarito": "D",
    "resumo": "Antes de simular, confira a forma do resultado: (m×n)·(n×p) é m×p, e aqui 2×2. Isso descarta B e C. A letra D tem confiança baixa, sem a figura, e a prova não tem gabarito oficial.",
    "assuntos": [
     {
      "num": "0039",
      "modulo": "05-vetores-e-strings.md"
     }
    ],
    "originais": []
   }
  ]
 },
 {
  "edital": "071/2023",
  "slug": "2023-071",
  "ano": 2023,
  "oficial": true,
  "questoes": [
   {
    "numero": 1,
    "topico": 7,
    "formato": "código",
    "enunciado": "Considere o código que deveria ordenar por seleção, de forma crescente:\n\n```c\nvoid algoritmo(int v[], int n) {\n  int i,j,k, tmp;\n  for(i = 0; i < n-1; i++) {\n    k = i;\n    for(j = 0; j < n; j++) {\n      if(v[k] > v[j]) { k = j }\n    }\n    tmp = v[k];\n    v[k] = v[i];\n    v[i] = tmp;\n  }\n```",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Ordena por seleção de forma crescente",
      "porque": "Não ordena: o laço interno começa em `j = 0`, e não em `i+1`, então acha o mínimo do vetor inteiro a cada passo e o troca com a posição `i`. Além disso, faltam `;` depois de `k = j` e a chave `}` final."
     },
     {
      "letra": "B",
      "texto": "Não ordena e não se corrige mudando uma linha",
      "porque": "Há dois erros de sintaxe (o `;` e o `}`) além do `j = 0`, então corrigir exigiria mexer em mais de uma linha."
     },
     {
      "letra": "C",
      "texto": "Pode ser corrigido em uma única linha",
      "porque": "O erro lógico se corrige trocando `j = 0` por `j = i + 1`, mas os erros de sintaxe ficam em outras linhas. Daí a ambiguidade."
     },
     {
      "letra": "D",
      "texto": "Ordena, mas não usa seleção",
      "porque": "Procura o mínimo e troca, que é seleção. O que falha é o início do laço interno."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada pela banca. Rodando com {5,3,4,1,2}, o código (já com `;` e `}`) devolve 3 4 5 1 2, ou seja, não ordena. Há erro de lógica e de sintaxe, então B e C ficam ambíguas. Moral: na seleção, o laço interno começa em i+1.",
    "assuntos": [
     {
      "num": "0092",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 2,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Sobre o Heapsort, considere:\n\nI. Tem custo O(n log n) no pior caso.\nII. Tem duas etapas: construir o heap e usá-lo para uma seleção eficiente.\nIII. Tem custo máximo quadrático no pior caso.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas I e II",
      "porque": "I verdadeira: construir o heap é O(n) e cada uma das n extrações custa O(log n). II verdadeira: monta o heap e depois extrai o máximo ou mínimo repetidamente. III falsa: o pior caso não passa de O(n log n)."
     },
     {
      "letra": "B",
      "texto": "Apenas II e III",
      "porque": "Inclui a III, que é falsa, e deixa de fora a I, que é verdadeira."
     },
     {
      "letra": "C",
      "texto": "Apenas I",
      "porque": "I é verdadeira, mas a II também. Falta ela."
     },
     {
      "letra": "D",
      "texto": "Apenas III",
      "porque": "A III é falsa: o Heapsort garante O(n log n), nunca quadrático."
     }
    ],
    "gabarito": "A",
    "resumo": "I e II verdadeiras; III falsa. Heapsort = construir heap + extrair, O(n log n) sempre. Isso o diferencia do Quicksort, que tem pior caso quadrático.",
    "assuntos": [
     {
      "num": "0103",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 3,
    "topico": 4,
    "formato": "cálculo",
    "enunciado": "Um heap binário de mínimo com N elementos está num vetor, com o mínimo na posição zero. Remover a raiz e deixar o heap correto custa, da melhor forma:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "N log N no pior caso",
      "porque": "É o custo de remover os N elementos, não de remover um só."
     },
     {
      "letra": "B",
      "texto": "log N no pior caso, mesmo sabendo que deslocar todo o vetor custa N",
      "porque": "Troca-se a raiz com o último elemento, diminui-se o tamanho e desce-se o novo topo (heapify). Isso percorre no máximo a altura, O(log N), sem deslocar o vetor."
     },
     {
      "letra": "C",
      "texto": "N no pior caso",
      "porque": "Só seria N se todo o vetor fosse deslocado ou reconstruído. O heap permite reorganizar em O(log N)."
     },
     {
      "letra": "D",
      "texto": "O(1), pois o elemento está na posição zero",
      "porque": "Ler o mínimo é O(1), mas remover exige restaurar a propriedade do heap, que custa O(log N)."
     }
    ],
    "gabarito": "B",
    "resumo": "Ler o mínimo é O(1). Remover e consertar é O(log N): troca com o último e desce. Inserir também é O(log N), subindo.",
    "assuntos": [
     {
      "num": "0102",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 4,
    "topico": 2,
    "formato": "cálculo",
    "enunciado": "Um programa de complexidade Θ(n³) leva 1 minuto com n = 100. Quanto leva com n = 300?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "3 min",
      "porque": "Seria o caso linear: n triplicou, o tempo triplicou. O programa é cúbico."
     },
     {
      "letra": "B",
      "texto": "9 min",
      "porque": "Seria o caso quadrático (3² = 9)."
     },
     {
      "letra": "C",
      "texto": "27 min",
      "porque": "Triplicar n multiplica o tempo por 3³ = 27, logo 27 minutos."
     },
     {
      "letra": "D",
      "texto": "300 min",
      "porque": "Não tem relação com a razão 3³; seria multiplicar por 300."
     }
    ],
    "gabarito": "C",
    "resumo": "Para Θ(nᵏ), se n é multiplicado por c, o tempo vai por cᵏ. Aqui c = 3 e k = 3, então 27. Conta de cabeça, sem fórmula complicada.",
    "assuntos": [
     {
      "num": "0072",
      "modulo": "10-analise.md"
     },
     {
      "num": "0166",
      "modulo": "26-analise-formal.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 5,
    "topico": 2,
    "formato": "afirmações",
    "enunciado": "Considere:\n\nI. Todo algoritmo não vazio tem custo Ω(1).\nII. Todo algoritmo tem custo O(nⁿ).\nIII. Nenhum algoritmo não vazio tem custo o(2), \"ó pequeno de 2\".\n\n(Os símbolos de I vieram ilegíveis no texto do caderno.)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I e II",
      "porque": "Inclui a II, que é falsa, e deixa de fora a III, que é verdadeira."
     },
     {
      "letra": "B",
      "texto": "I e III",
      "porque": "I verdadeira: qualquer algoritmo não vazio executa ao menos uma operação, custo mínimo constante. III verdadeira: o(2) é o mesmo que o(1), e um algoritmo com ao menos um passo não cresce mais devagar que uma constante. II falsa: existem algoritmos que custam mais que nⁿ, como 2^(n²)."
     },
     {
      "letra": "C",
      "texto": "II e III",
      "porque": "II falsa. Não há limite superior que valha para todos os algoritmos."
     },
     {
      "letra": "D",
      "texto": "Todas",
      "porque": "A II é falsa, então não valem as três."
     }
    ],
    "gabarito": "B",
    "resumo": "Cuidado com 'todo' e 'nenhum' em notação assintótica. Ω(1) vale sempre para algoritmo não vazio, e não existe limite O universal. Como os símbolos de I vieram ilegíveis, a conferência de I foi pelo gabarito oficial.",
    "assuntos": [
     {
      "num": "0166",
      "modulo": "26-analise-formal.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 6,
    "topico": 6,
    "formato": "simulação",
    "enunciado": "Dado o vetor `2 4 6 8 10 12 14 16 18` (posições 0 a 8), uma busca binária pela chave 9 compara com quais valores?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "2, 6, 10, 14 e 18",
      "porque": "Seria uma busca que anda de dois em dois. A binária pula para o meio e descarta metade."
     },
     {
      "letra": "B",
      "texto": "10, 4, 6 e 8",
      "porque": "meio = 4 (valor 10) e 9 < 10, vai para a esquerda; meio = 1 (valor 4), 9 > 4, direita; meio = 2 (valor 6), direita; meio = 3 (valor 8), direita; acaba. Compara com 10, 4, 6 e 8. Rodado em Python."
     },
     {
      "letra": "C",
      "texto": "nenhum, porque a chave não existe",
      "porque": "A busca precisa comparar para descobrir que a chave não existe."
     },
     {
      "letra": "D",
      "texto": "10, 14 e 18",
      "porque": "Seria a busca indo sempre para a direita, e 9 é menor que 10."
     }
    ],
    "gabarito": "B",
    "resumo": "Simule: meio = (i + j) / 2, compare e corte. Anote os valores visitados e os novos extremos a cada passo. Chave inexistente só para quando o intervalo esvazia.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 7,
    "topico": 4,
    "formato": "afirmações",
    "enunciado": "Sobre a busca em árvore vermelho e preto, considere:\n\nI. A altura máxima é log n.\nII. A altura máxima é inferior a 3 log n.\nIII. Pode degenerar no pior caso, com busca linear, em situações raras.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas I",
      "porque": "A I é falsa: a altura máxima da rubro-negra é 2·log2(n+1), o dobro do ideal, e não log n."
     },
     {
      "letra": "B",
      "texto": "Apenas II",
      "porque": "Tecnicamente 2·log2(n+1) fica abaixo de 3 log n para n razoável, então II é defensável. A banca anulou a questão por ambiguidade."
     },
     {
      "letra": "C",
      "texto": "Apenas III",
      "porque": "A III é falsa: a rubro-negra nunca degenera em lista, as regras de coloração garantem altura logarítmica."
     },
     {
      "letra": "D",
      "texto": "Apenas I e II",
      "porque": "A I é falsa, então essa combinação falha."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada. I falsa (altura até 2·log2(n+1)). II é defensável (a altura é limitada por 2 log(n+1), que é menor que 3 log n). III falsa (a rubro-negra não degenera). Pelo conteúdo, a resposta seria B, mas o texto é ambíguo, o que explica a anulação (conjectura).",
    "assuntos": [
     {
      "num": "0177",
      "modulo": "28-estruturas-complementos.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 8,
    "topico": 3,
    "formato": "afirmações",
    "enunciado": "Uma pilha em lista encadeada recebe 2, 4, 6, 8 e 10, nessa ordem. Sobre uma remoção, considere:\n\nI. Retira o 2.\nII. Retira o 10.\nIII. Tem custo proporcional ao tamanho.\nIV. Tem custo constante.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "I e III",
      "porque": "Retirar o 2 é o comportamento de fila. Pilha é LIFO, e o custo proporcional ao tamanho seria de uma implementação ruim."
     },
     {
      "letra": "B",
      "texto": "I e IV",
      "porque": "O custo constante está certo, mas pilha não retira o primeiro inserido."
     },
     {
      "letra": "C",
      "texto": "II e III",
      "porque": "O elemento removido está certo (10), mas o custo não é proporcional ao tamanho: remover na cabeça só mexe no ponteiro inicial."
     },
     {
      "letra": "D",
      "texto": "II e IV",
      "porque": "Pilha retira o último inserido, o 10 (II). Na lista encadeada, a cabeça é o topo, então a remoção é O(1) (IV)."
     }
    ],
    "gabarito": "D",
    "resumo": "Pilha: LIFO, remoção na cabeça, O(1). Elimine primeiro pela ordem (qual sai), depois pelo custo.",
    "assuntos": [
     {
      "num": "0083",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 9,
    "topico": 6,
    "formato": "conceito",
    "enunciado": "Sobre um vetor mantido ordenado, com os melhores algoritmos:",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Inserção, remoção e busca lineares",
      "porque": "A busca pode ser logarítmica (binária), então não é linear."
     },
     {
      "letra": "B",
      "texto": "Inserção e remoção lineares, busca logarítmica",
      "porque": "Inserir e remover deslocam elementos, O(n). A busca binária aproveita a ordem: O(log n)."
     },
     {
      "letra": "C",
      "texto": "Inserção e remoção logarítmicas, busca constante",
      "porque": "Nem a busca é O(1) nem as mudanças são O(log n), por causa dos deslocamentos."
     },
     {
      "letra": "D",
      "texto": "Inserção linear, remoção logarítmica, busca logarítmica",
      "porque": "A remoção também desloca elementos, O(n). Inserção e remoção têm o mesmo custo."
     }
    ],
    "gabarito": "B",
    "resumo": "Vetor ordenado: busca O(log n), inserção e remoção O(n). Para tudo em O(log n), use árvore balanceada.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0075",
      "modulo": "11-listas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 10,
    "topico": 7,
    "formato": "afirmações",
    "enunciado": "Sobre quicksort, mergesort e ordenação por inserção, considere:\n\nI. O quicksort tem o melhor pior caso dos três.\nII. A inserção tende a ser a mais rápida quando os elementos fora de ordem são menos de um décimo de log N.\nIII. O mergesort tem o menor custo assintótico de pior caso dos três.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Apenas I",
      "porque": "A I é falsa: o quicksort tem pior caso O(n²), pior que o O(n log n) do mergesort."
     },
     {
      "letra": "B",
      "texto": "Apenas II",
      "porque": "Depende de uma condição confusa sobre log N e do que significa 'fora de ordem'."
     },
     {
      "letra": "C",
      "texto": "Apenas III",
      "porque": "Entre os três, o mergesort é O(n log n) no pior caso, e os outros são O(n²). Mas a banca anulou a questão."
     },
     {
      "letra": "D",
      "texto": "Nenhuma das anteriores",
      "porque": "Se a III é verdadeira, essa não vale."
     }
    ],
    "gabarito": "anulada",
    "resumo": "Anulada. I falsa (quicksort é O(n²) no pior caso). III parece verdadeira (mergesort é o único O(n log n) dos três). II usa 'um décimo de log N', redação duvidosa. O motivo da anulação é conjectura: a redação confusa de II e III.",
    "assuntos": [
     {
      "num": "0093",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0094",
      "modulo": "13-busca-e-ordenacao.md"
     },
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 11,
    "topico": 3,
    "formato": "cálculo",
    "enunciado": "Num vetor sempre ordenado com n elementos, quais os piores casos de inserção, remoção e busca pelo campo de ordenação?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O(n log n), O(n log n), O(log n)",
      "porque": "Inserir e remover custam O(n) (deslocamento), e não n log n."
     },
     {
      "letra": "B",
      "texto": "O(n log n), O(n log n), O(n)",
      "porque": "Erra os três: nem n log n nas mudanças, nem O(n) na busca."
     },
     {
      "letra": "C",
      "texto": "O(n), O(n), O(n)",
      "porque": "A busca é O(log n) porque o vetor está ordenado."
     },
     {
      "letra": "D",
      "texto": "O(n), O(n), O(log n)",
      "porque": "Inserção e remoção deslocam elementos (O(n)); a busca binária usa a ordem (O(log n))."
     }
    ],
    "gabarito": "D",
    "resumo": "Vetor ordenado: mudança O(n), busca O(log n). É a mesma ideia da questão 9, agora em notação de pior caso.",
    "assuntos": [
     {
      "num": "0075",
      "modulo": "11-listas.md"
     },
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 12,
    "topico": 7,
    "formato": "simulação",
    "enunciado": "Um quicksort crescente tem, depois do primeiro particionamento, o vetor `2 5 9 1 7 2 1 9`. Qual pode ter sido o pivô?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "2",
      "porque": "Um pivô 2 na posição 0 exigiria tudo à direita maior ou igual a 2, mas há 1 depois dele."
     },
     {
      "letra": "B",
      "texto": "9",
      "porque": "O 9 da última posição tem todos os elementos à esquerda menores ou iguais. É compatível com um particionamento em que o pivô vai para o fim ou nele fica."
     },
     {
      "letra": "C",
      "texto": "1",
      "porque": "Um pivô 1 na posição 3 exigiria esquerda menor ou igual a 1, mas há 2, 5 e 9 antes."
     },
     {
      "letra": "D",
      "texto": "7",
      "porque": "O 7 na posição 4 exigiria esquerda menor ou igual a 7, mas há 9 à esquerda."
     }
    ],
    "gabarito": "B",
    "resumo": "Depois do particionamento, o pivô tem tudo à esquerda menor ou igual e tudo à direita maior ou igual. Teste cada candidato. Só o 9 da última posição serve. Verificado com um script que testa cada valor.",
    "assuntos": [
     {
      "num": "0095",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 13,
    "topico": 5,
    "formato": "simulação",
    "enunciado": "Uma tabela hash com encadeamento, tamanho 5 e h(k) = k mod 5 recebe as chaves 2, 5, 9, 20 e 7. Quantas colisões ocorrem?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Nenhuma",
      "porque": "O 20 cai na posição 0, que já tem o 5; o 7 cai na 2, que já tem o 2."
     },
     {
      "letra": "B",
      "texto": "Uma",
      "porque": "Há duas colisões, não uma."
     },
     {
      "letra": "C",
      "texto": "Duas",
      "porque": "2 vai para 2, 5 para 0, 9 para 4, 20 para 0 (colide com o 5) e 7 para 2 (colide com o 2). Duas colisões."
     },
     {
      "letra": "D",
      "texto": "Três",
      "porque": "O 9 vai sozinho para a posição 4. Só o 20 e o 7 colidem."
     }
    ],
    "gabarito": "C",
    "resumo": "Calcule o resto de cada chave e conte quantas caem num balde já ocupado. Confira: baldes 0 = [5, 20], 2 = [2, 7], 4 = [9]. Rodado em Python.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 14,
    "topico": 4,
    "formato": "simulação",
    "enunciado": "Numa árvore binária de pesquisa sem balanceamento, inserem-se 10, 5, 20, 1, 30, 7 e 15, nessa ordem. No pior caso, uma busca compara a chave com quantos nós?",
    "alternativas": [
     {
      "letra": "A",
      "texto": "7 nós",
      "porque": "Seria a árvore degenerada em lista. Aqui a altura é menor."
     },
     {
      "letra": "B",
      "texto": "6 nós",
      "porque": "Não há caminho com 6 nós: o mais longo tem 3."
     },
     {
      "letra": "C",
      "texto": "2 nós",
      "porque": "Há caminhos de 3 nós (10-5-7 e 10-20-30)."
     },
     {
      "letra": "D",
      "texto": "3 nós",
      "porque": "A raiz é 10, com 5 e 20. Os caminhos mais longos são 10-5-7 e 10-20-30, com 3 nós. A altura é 3."
     }
    ],
    "gabarito": "D",
    "resumo": "Pior caso de busca = altura da árvore (em nós no caminho). Monte a árvore com as inserções na ordem dada e conte o caminho mais longo. Rodado em Python: altura 3.",
    "assuntos": [
     {
      "num": "0099",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 15,
    "topico": 6,
    "formato": "código",
    "enunciado": "(Python) Uma busca binária recursiva é executada no vetor fora de ordem `A = [0, 100, 20, 30, 40, 50, 60, 70]`, procurando 100, com `meio = (esquerda + direita) // 2`. Qual a saída de `print(\"Pesquisa com sucesso:\", ...)`?\n\n```python\ndef pesquisa_binaria_recursiva(A, x, esquerda, direita):\n    if esquerda > direita:\n        return -1\n    meio = (esquerda + direita) // 2\n    if A[meio] == x:\n        return meio\n    if A[meio] < x:\n        return pesquisa_binaria_recursiva(A, x, meio + 1, direita)\n    return pesquisa_binaria_recursiva(A, x, esquerda, meio - 1)\n\nA = [0, 100, 20, 30, 40, 50, 60, 70]\n```\n\n(O texto do código não veio por extenso no caderno; esta é a busca binária recursiva padrão descrita no enunciado.)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "100",
      "porque": "100 é a chave, não a posição devolvida."
     },
     {
      "letra": "B",
      "texto": "-1",
      "porque": "Meio = 3 (30), menor que 100, vai para a direita; 5 (50), 6 (60), 7 (70), e depois para. O 100 está na posição 1, que a busca nunca visita porque o vetor está fora de ordem. Devolve -1."
     },
     {
      "letra": "C",
      "texto": "1",
      "porque": "Seria a posição correta do 100, mas a busca binária não chega lá num vetor desordenado."
     },
     {
      "letra": "D",
      "texto": "2",
      "porque": "Não há razão para devolver 2: nenhum passo para nessa posição."
     }
    ],
    "gabarito": "B",
    "resumo": "Busca binária só funciona em vetor ordenado. Em vetor desordenado, ela pode falhar mesmo com a chave presente. Simule os passos: o valor 100 está na posição 1, mas a busca vai sempre para a direita. (Código reconstruído da descrição, rodado em Python.)",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 16,
    "topico": 5,
    "formato": "cálculo",
    "enunciado": "Numa tabela hash com encadeamento por lista, sem chave repetida, o pior caso de inserção é __ e o de busca é __. Trocando a lista por árvore rubro-negra, a inserção passa a __ e a busca a __.",
    "alternativas": [
     {
      "letra": "A",
      "texto": "O(n), O(n), O(log n), O(log n)",
      "porque": "Sem chave repetida, inserir exige verificar se a chave já existe, então varre a lista: O(n), igual à busca. Com árvore rubro-negra no balde, ambas viram O(log n)."
     },
     {
      "letra": "B",
      "texto": "O(1), O(n), O(1), O(log n)",
      "porque": "Inserção O(1) só valeria se pudesse repetir chave. Aqui precisa verificar, o que custa o mesmo que a busca."
     },
     {
      "letra": "C",
      "texto": "O(n), O(1), O(log n), O(1)",
      "porque": "A busca não é O(1) no pior caso: se todas as chaves caem no mesmo balde, percorre n itens."
     },
     {
      "letra": "D",
      "texto": "O(1), O(1), O(1), O(1)",
      "porque": "Isso é o caso médio com boa função hash, não o pior caso."
     }
    ],
    "gabarito": "A",
    "resumo": "Pior caso de hash = tudo no mesmo balde. Lista: O(n). Árvore balanceada: O(log n). Sem chave repetida, a inserção inclui uma busca.",
    "assuntos": [
     {
      "num": "0106",
      "modulo": "15-hash.md"
     },
     {
      "num": "0101",
      "modulo": "14-arvores.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 17,
    "topico": 6,
    "formato": "simulação",
    "enunciado": "(Python) Com a mesma busca binária recursiva e o mesmo vetor da questão anterior, agora procurando 70, quantas vezes `pesquisa_binaria_recursiva()` é chamada?\n\n(O texto do código não veio por extenso no caderno; esta é a busca binária recursiva padrão descrita no enunciado.)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "0",
      "porque": "A função é chamada ao menos uma vez, na chamada inicial."
     },
     {
      "letra": "B",
      "texto": "3",
      "porque": "Faltou contar uma chamada."
     },
     {
      "letra": "C",
      "texto": "4",
      "porque": "Chamadas: [0..7] meio 3 (30), [4..7] meio 5 (50), [6..7] meio 6 (60), [7..7] meio 7 (70) achou. Quatro chamadas. Rodado em Python."
     },
     {
      "letra": "D",
      "texto": "5",
      "porque": "São 5 chamadas só se o 70 não estivesse no vetor (caso 100). Aqui acha na quarta."
     }
    ],
    "gabarito": "C",
    "resumo": "Conte as chamadas com os extremos de cada uma. A chave 70 está na última posição, então a busca desce quatro vezes até achá-la.",
    "assuntos": [
     {
      "num": "0090",
      "modulo": "13-busca-e-ordenacao.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 18,
    "topico": 3,
    "formato": "código",
    "enunciado": "(Python) Produto de A = [[0, 2, 1], [1, 0, 0]] por B = [[7, 0], [0, 10], [11, 0]] com três laços. Qual o resultado?\n\n(O código dos três laços não veio por extenso; é o produto de matrizes padrão.)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "[[0. 2. 1.] [1. 0. 0.]]",
      "porque": "É a própria matriz A, não o produto."
     },
     {
      "letra": "B",
      "texto": "[[7. 0.] [0. 10.] [11. 0.]]",
      "porque": "É a própria B. O produto de uma 2×3 por uma 3×2 é 2×2."
     },
     {
      "letra": "C",
      "texto": "[[7. 0.] [11. 20.]]",
      "porque": "Linhas trocadas e valores errados. Linha 0 = [0·7+2·0+1·11, 0·0+2·10+1·0] = [11, 20]."
     },
     {
      "letra": "D",
      "texto": "[[11. 20.] [7. 0.]]",
      "porque": "Linha 0: [0·7+2·0+1·11, 0·0+2·10+1·0] = [11, 20]. Linha 1: [1·7+0+0, 0+0+0] = [7, 0]. Rodado em Python."
     }
    ],
    "gabarito": "D",
    "resumo": "Forma do resultado: 2×3 por 3×2 = 2×2. Depois calcule cada célula como linha de A vezes coluna de B. Cuidado com a ordem das linhas na hora de montar.",
    "assuntos": [
     {
      "num": "0039",
      "modulo": "05-vetores-e-strings.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 19,
    "topico": 3,
    "formato": "código",
    "enunciado": "(Python) Uma classe `Stack` guarda os itens numa lista; `popit` numa pilha vazia imprime \"empty stack\". Os comandos são: push 1, push 3, pop, pop, pop, push 2, push 1, pop, e por fim `print(stack.stack)`. Qual o resultado?\n\n(O código da classe não veio por extenso.)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "[2, 1]",
      "porque": "Esqueceu o último pop, que tira o 1."
     },
     {
      "letra": "B",
      "texto": "\"empty stack\" e [2]",
      "porque": "Os dois primeiros pops tiram 3 e 1. O terceiro pop, em pilha vazia, imprime \"empty stack\". Depois entram 2 e 1, o pop tira o 1, e a pilha termina [2]."
     },
     {
      "letra": "C",
      "texto": "\"empty stack\" e []",
      "porque": "A pilha não termina vazia: depois do aviso entram 2 e 1, e só o 1 sai."
     },
     {
      "letra": "D",
      "texto": "[]",
      "porque": "Também falta o aviso, e a pilha não fica vazia: sobra o 2."
     }
    ],
    "gabarito": "B",
    "resumo": "Simule com uma lista, pop tira o último. O terceiro pop acontece com a pilha vazia. Rodado em Python.",
    "assuntos": [
     {
      "num": "0082",
      "modulo": "12-pilhas-e-filas.md"
     }
    ],
    "originais": []
   },
   {
    "numero": 20,
    "topico": 1,
    "formato": "código",
    "enunciado": "(Python) `func1(fator)` devolve `func2`, que recebe `x` e retorna `x * fator`. Com `funcao = func1(3)`, qual a saída de `print(funcao(5))`?\n\n(O código não veio por extenso.)",
    "alternativas": [
     {
      "letra": "A",
      "texto": "Erro, porque não passou `fator`",
      "porque": "`fator` foi passado em `func1(3)` e fica guardado no fechamento de `func2`."
     },
     {
      "letra": "B",
      "texto": "15",
      "porque": "`func1(3)` devolve uma função que lembra `fator = 3`. Chamar `funcao(5)` calcula 5 * 3 = 15. Rodado em Python."
     },
     {
      "letra": "C",
      "texto": "3",
      "porque": "3 é só o fator. A função multiplica por x, que vale 5."
     },
     {
      "letra": "D",
      "texto": "0",
      "porque": "Não há operação que gere zero."
     }
    ],
    "gabarito": "B",
    "resumo": "Isso é um fechamento (closure): a função interna guarda o valor do escopo externo. Em C, o equivalente é ponteiro para função, mas sem closure.",
    "assuntos": [
     {
      "num": "0029",
      "modulo": "04-funcoes.md"
     },
     {
      "num": "0050",
      "modulo": "06-ponteiros.md"
     }
    ],
    "originais": []
   }
  ]
 }
]

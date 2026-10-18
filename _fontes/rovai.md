# Fichamento — Algoritmos e Estrutura de Dados (Kleber Ricardi Rovai)

- **Autor:** Kleber Ricardi Rovai
- **Edição:** Editora e Distribuidora Educacional (Kroton), Londrina, 2018, 216 p., ISBN 978-85-522-0660-6
- **Lido:** 5533 linhas, por completo (4 unidades × 3 seções: listas ligadas/duplas; pilhas e filas;
  tabelas de espalhamento; armazenamento associativo/mapas)
- **Formato:** livro didático Kroton em seções padronizadas ("Diálogo aberto", "Não pode faltar",
  "Assimile", "Reflita", "Sem medo de errar", "Avançando na prática", "Faça valer a pena" com múltipla
  escolha). Fontes principais: Celes, Cerqueira & Rangel (2004), Tenenbaum, Silva (2007), Drozdek
  (2016), Goodrich & Tamassia.

## Avaliação geral

Livro de **baixa densidade técnica** e **alta densidade de erros**. Boa parte do texto são narrativas de
"situação-problema" (autopeças, notebooks, biblioteca, restaurante da sra. Fátima) que pedem um
"relatório" e quase não ensinam. Diz que o código é "C++", mas as unidades 1–3 são C com `printf`/`malloc`
e a unidade 4 usa `std::map` de C++, fora do escopo do LPEDC. Quase todo trecho de código tem defeito:
não compila, vaza memória, desreferencia NULL ou tem laço infinito. Muitos são **trechos de Celes et al.
copiados com erros**.

Mesmo assim há o que aproveitar: (1) o **exemplo do RA** em hash, com a conta de memória do
endereçamento direto (1,27 GB → vetor de ponteiros → hash), que é uma motivação excelente; (2) os
exemplos numéricos de **sondagem linear e dupla** com m = 8 e a chave 27 (contas corretas); (3) a
**tabela que dobra** quando passa de metade, gancho para análise amortizada; (4) a função de hash
**multiplicativa de Knuth** (2654435761), que aparece sem explicação; (5) o labirinto como semente de
**backtracking**; (6) a função "cálculo de endereço" por faixas, que na verdade é **bucket sort**; (7) a
fila circular para **round-robin** de processos. E o principal: os bugs dão um banco de exercícios "ache
o erro" muito realista.

---

### 0081-lista-encadeada

**Conceitos-chave**
- Vetor: contíguo, acesso aleatório, tamanho fixo (sala com 25 carteiras e 30 alunos). Lista ligada:
  sequência **lógica** por ponteiros, cresce e encolhe.
- Nó = informação + ponteiro para o próximo. Lista vazia = NULL. `inicializa()` retorna NULL.
- Lista **com cabeçalho** (nó-sentinela cujo conteúdo é ignorado; vazia ⇔ `start->prox == NULL`) vs.
  **sem cabeçalho** (vazia ⇔ `start == NULL`). Distinção útil e pouco explicada em outros livros.
- Inserir no início retornando a nova cabeça: `l = inserir(l, 13)`. É o padrão correto, em contraste com
  a passagem por valor.

**Explicações boas**
- Aplicações do dia a dia: lista de tarefas por prioridade, lista de compras, checklist de viagem,
  convidados/presentes de casamento, pontos de parada de uma linha de ônibus.
- Rota de ônibus como lista ligada: cada ponto leva ao seguinte. Bom enunciado para exercício.

**Pegadinhas**
- O livro afirma que "os elementos de uma lista são armazenados em posições sequenciais de memória
  sempre que possível" e que "permitem que a lista seja percorrida em qualquer direção". As duas coisas
  são falsas para a lista simples.
- "O ponteiro é um campo de valor inteiro." Errado: ponteiro não é `int` (em 64 bits nem cabe).
- `char[15] parada;` (sintaxe de Java/C#). Em C é `char parada[15];`.
- O "Reflita" sugere que a lista ligada "tem desempenho melhor que o vetor". Depende da operação: acesso
  por índice e localidade de cache favorecem o vetor.

**Ideias de exercícios**
- Rota de ônibus: inserir parada no fim, remover parada por nome, imprimir a rota. → Testar remover a 1ª,
  a última e uma inexistente.

### 0082-lista-busca-remocao

**Conceitos-chave**
- Inserir no início, numa posição e no fim. Remover com `ant` e `p` num único laço (1º elemento vs.
  meio/fim). Percorrer com `for (p = l; p != NULL; p = p->prox)`. Buscar retornando o nó ou NULL.

**Explicações boas**
- O `remove` com `anterior = NULL` + `while (p != NULL && p->info != v)` é o padrão correto (de Celes), e
  o próprio texto explica que ele também cobre a remoção do último.
- O `&&` com curto-circuito protege `p->info` quando `p` é NULL. Vale destacar (liga com 0018).

**Pegadinhas** (todas no livro)
- `inserirPosicao(l, 1, 30)` insere **depois** do 1º nó, ou seja, na posição 2, embora o texto diga
  "primeira posição". Quebra com lista vazia e com `pos` maior que o tamanho (desreferencia NULL).
- `inserirFim` quebra com lista vazia (`p->prox` com `p == NULL`) e usa `cont` não declarado.
- O `remove`/`retira` **nunca chama `free`**: vazamento a cada remoção. O exercício "Faça valer a pena 2"
  diz que é preciso liberar, mas o código não libera.
- A função se chama `remove` na definição e `retira` na chamada. Além disso, `remove` já existe em
  `<stdio.h>` (apaga arquivo!), o que gera conflito de nome.
- No sistema de produtos: `novo->produto = nprod;` (atribuir a vetor de `char` não compila; é `strcpy`),
  `scanf("%d", &nprod)` para ler string, `&codpro` (variável inexistente), `system("PAUSE")` (só Windows).

**Ideias de exercícios**
- "Ache os 3 bugs" no `inserirFim` do livro. → `cont` não declarado; lista vazia quebra; não valida
  `malloc`. Correção: se `l == NULL` retornar `novo`.
- Qual a posição final de 30 após `l = [13]; l = inserir(l, 56); l = inserirPosicao(l, 1, 30)`? →
  Lista [56, 13] vira **[56, 30, 13]**: o 30 fica na 2ª posição, não na 1ª.
- Rodar o `retira` do livro no valgrind removendo 3 elementos. → "definitely lost: 3 blocks" (vazamento
  sem `free`).

### 0084-lista-dupla

**Conceitos-chave**
- Nó com `ant` e `prox`. O primeiro tem `ant = NULL` e o último tem `prox = NULL`. Permite percorrer de
  trás para frente e remover conhecendo só o ponteiro do nó.
- Inserir no início: `novo->prox = l; novo->ant = NULL; if (l) l->ant = novo;`. É o trecho correto.
- Remoção: `if (p->ant == NULL) l = p->prox; else p->ant->prox = p->prox; if (p->prox) p->prox->ant = p->ant;`.

**Explicações boas**
- Uso como lista de processos do SO (anterior e próximo processo).
- "Reflita": como imprimir em ordem inversa? → Ir até o último e voltar por `ant`.

**Pegadinhas**
- `inserirPosicao` da dupla faz `malloc` de um `temp` e logo o sobrescreve (vazamento), e ao inserir após
  o último faz `temp->ant` com `temp == NULL` (falha).
- A remoção da dupla também não dá `free`. O código testa `ant == NULL` mas a variável `ant` não existe
  (deveria ser `p->ant`).
- `struct Pessoa {...}; typedef struct pessoas Pessoa;`: nome da `struct` diferente no `typedef`.
- No problema da pesquisa de mercado, `char[25] produto` de novo.

**Ideias de exercícios**
- Escrever `imprimir_reverso` em O(n) sem recursão. → Avançar até `p->prox == NULL` e voltar por `p->ant`.
- Remoção correta com `free` e teste de remover o único elemento. → A lista deve ficar NULL.

### 0083-lista-ordenada

**Conceitos-chave**
- O livro **não** ensina inserção ordenada. Para manter a lista ordenada, chama `Ordena()` após cada
  inserção ou remoção, uma ordenação por trocas de `info` com dois laços aninhados (seleção/bolha
  disfarçada).

**Pegadinhas**
- Ordenar a lista inteira a cada inserção custa O(n²) por operação. A inserção ordenada custa O(n).
  Contraexemplo perfeito para este assunto.
- `Ordena` troca os **dados** (`info`), não os nós. Funciona para `int`, mas com `struct` grande é caro e
  invalida ponteiros externos que apontavam para "o produto X".
- A alternativa (b) do exercício 3 (`p->info = aux->info; aux->info = p->info;`) é a troca errada sem
  temporária. Bom item de 0051.

**Ideias de exercícios**
- Quantas comparações o `Ordena` faz numa lista de n elementos? → n(n−1)/2 sempre (os dois laços não
  dependem dos dados). Para n = 10, **45**. Inserção ordenada de 1 elemento faz no máximo **10**.

### 0087-pilha

**Conceitos-chave**
- LIFO/FILO, topo, push/pop, vazia, cheia, liberar. Analogias: pratos no restaurante, caixas no
  supermercado, cestas de compras, caminhão-cegonha.
- Pilha sobre vetor alocado: `struct Pilha { int topo; int capacidade; float *proxElem; }`,
  `cria_pilha(p, c)` com `topo = -1`. `pilha_vazia`: `topo == -1`. `pilha_cheia`: `topo == capacidade-1`.

**Explicações boas**
- Sequência push 36, push 7, pop, push 12, push 23, pop (de Drozdek). Exercício de rastreio pronto:
  o estado final é [36, 12].
- Caminhão-cegonha: para tirar o primeiro carro colocado, é preciso tirar os de trás.

**Pegadinhas**
- `push_pilha` não verifica se está cheia e `pop_pilha` não verifica se está vazia.
- O campo do vetor se chama `proxElem` ("próximo elemento"), um nome enganoso para o vetor de dados.
- O texto diz que "o vetor tem tamanho fixo e a pilha tem tamanho dinâmico". A pilha **sobre vetor** tem
  capacidade fixa. Só a encadeada (ou o vetor que cresce) é dinâmica.
- A Fig. 2.15 diz que "a função pop() insere o elemento".
- O comentário de `pilha_vazia` diz "caso contrário, retorna verdadeiro" para o `return 0`.
- "Torre de Hanói representa uma pilha": cada pino é uma pilha, mas a solução recursiva apresentada **não
  usa pilha nenhuma** (usa a pilha de chamadas, implicitamente).

**Ideias de exercícios**
- Rastreio: pilha vazia; push 36; push 7; pop; push 12; push 23; pop. Estado final e valores retirados?
  → Retirados **7, 23**. Pilha (base→topo) **[36, 12]**.
- No sistema de teste de notebook: `note_completo` usa `p->capa` (campo inexistente; o campo é `qtd`),
  `criarteste` usa `q` não declarado e o `case 2` imprime `num` em vez do valor removido. Achar e
  corrigir os 4 bugs.

### 0089-pilha-aplicacoes

**Conceitos-chave**
- Labirinto com pilha: em cada bifurcação, empilha a posição e o caminho escolhido. Num beco sem saída,
  desempilha e tenta outro caminho. É a ideia do backtracking.
- Desfazer (undo): empilhar ações e desempilhar para restaurar.

**Pegadinhas**
- "Backtracking tem como meta resolver o problema **no menor intervalo de tempo possível**, sem levar em
  conta o esforço." Errado: backtracking é busca exaustiva com poda e frequentemente exponencial. Não
  garante o menor tempo nem o menor caminho (para menor caminho em labirinto use BFS, 0115).
- "GPS que recalcula rota usa backtracking": analogia falsa (é caminho mínimo, 0117).
- O trecho `inicLabirinto` só marca a origem e empilha. Não resolve nada.

**Ideias de exemplos**
- Labirinto em matriz `char lab[L][C]` resolvido com pilha explícita de `(x, y)` e matriz `visitado`.
  Depois a mesma coisa recursiva, para mostrar que a recursão é a pilha (liga com 0036).

**Ideias de exercícios**
- Labirinto 4×4 com `#` parede, `S` saída, partindo de (0,0). O algoritmo com pilha (vizinhos na ordem
  baixo, direita, cima, esquerda) acha **um** caminho. É o mais curto? → Não necessariamente. Comparar
  com BFS.

### 0038-recursao-na-pratica (Hanói)

**Conceitos-chave**
- Hanói recursiva `hanoi(n, a, b, c)` com contador global de movimentos (o pedido da professora
  Fernanda: informar o total de movimentos).

**Pegadinhas**
- O contador só incrementa no ramo `else` e o caso base (n == 1) **não conta**. O programa conta
  2^(n−1) − 1 em vez de 2ⁿ − 1 movimentos. O `printf` do caso base está truncado.

**Ideias de exercícios**
- Com n = 3, quanto o programa do livro imprime e quanto deveria imprimir? → Imprime **3**, deveria ser
  **7**. Correção: `contador++` também no caso base (ou contar junto de cada `printf`).
- Para n = 64, quantos movimentos? → 2⁶⁴ − 1 ≈ 1,8·10¹⁹. Não cabe em `int`: usar `unsigned long long` (0008).

### 0090-fila

**Conceitos-chave**
- FIFO, início e fim, filas de supermercado/banco/aeroporto, senha dos Correios, fila de impressão.
- Implementação com `n` (quantidade) e `ini` e cálculo do fim: `fim = (ini + n) % N`. Remover:
  `ini = (ini + 1) % N; n--`. É a versão **mais limpa** de fila circular (de Celes), embora o livro a
  apresente como "fila comum".
- A seguir, uma "fila circular" com `tam`, `ini = 1`, `fim = 0` e `% (N-1) + 1`.

**Explicações boas**
- Drive-thru com senhas de 000 a 999 que voltam a 000: boa imagem de aritmética modular.
- "São os índices, e não os elementos, que se movem": frase boa para fixar.

**Pegadinhas**
- A primeira fila **já é circular** (usa `% N`), mas o texto diz que "chegando ao fim do vetor a fila
  pode parecer cheia" e apresenta a "circular" como outra coisa. Confusão conceitual.
- A "fila circular" do livro usa índices 1..N−1 (desperdiça `vet[0]` **e** uma posição: cabem só N−1
  elementos), não inicializa nada no `main` (`FilaCirc* f` sem `malloc`) e `remove_fila` não retorna o
  elemento.
- `remove_fila` declarada `float` devolvendo `char`; `exit(1)` ao remover de fila vazia mata o programa.
- "A fila circular utiliza menos instruções" é afirmação sem base.
- `libera_fila` com um só `free(f)` está certo **só** porque o vetor é interno à `struct`. Bom ponto de
  contraste com a fila encadeada.

**Ideias de exercícios**
- Fila de Celes com N = 4: insere A, B, C; remove; insere D, E. Valores de `ini`, `n` e vetor? →
  Após A, B, C: ini = 0, n = 3. Remove A: ini = 1, n = 2. D vai para (1+2)%4 = 3, E para (1+3)%4 = 0 →
  **vet = [E, B, C, D], ini = 1, n = 4** (cheia).
- Por que a "circular" do livro com N = 10 aceita só 9 elementos? → `tam == N-1` é o teste de cheia e os
  índices andam em 1..9.

### 0091-fila-encadeada
- O livro **não** implementa fila encadeada (só menciona "alocação dinâmica"). Não aproveitar para este
  assunto.

### 0093-juntando-tudo (filas): round-robin

**Conceitos-chave**
- Fila circular de processos: cada processo roda por um quantum. Se não terminou, **volta para o fim da
  fila**.

**Pegadinhas**
- O código do livro usa `FilaCirc* f` sem alocar, insere sempre a mesma string num vetor de `int`,
  compara `clock()` (em *ticks*) com segundos e **nunca reinsere** o processo. Não é round-robin.

**Ideias de exemplos / exercícios**
- Round-robin simulado (sem relógio real): processos P1 = 5, P2 = 2, P3 = 4 unidades, quantum 2. Ordem de
  execução e instante de término? → P1(2) P2(2, termina t = 4) P3(2) P1(2) P3(2, termina t = 10)
  P1(1, termina t = 11). **Términos: P2 = 4, P3 = 10, P1 = 11**.

### 0110-hashing

**Conceitos-chave**
- Nomes: tabela de espalhamento, dispersão, hash, "escrutínio", "cálculo de endereço". Função de
  espalhamento transforma a chave em índice e a tabela guarda subconjuntos.
- A busca "elimina" todos os outros subconjuntos de uma vez (filtro). Troca memória por tempo.
- Função de **divisão**: h(k) = k mod m (a mais usada). Exemplo: m = 10, chaves 16, 65, 248, 189, 74 →
  6, 5, 8, 9, 4.
- Função perfeita: sem colisões, possível quando se conhecem todas as chaves de antemão.
- Desempenho piora com colisões. Pior caso: todas as chaves no mesmo índice (vira lista, O(n)).

**Explicações boas**
- **RA da faculdade** (de Celes): endereçamento direto `vet[RA]` com RA de 7 dígitos = 10⁷ posições ×
  127 bytes ≈ **1,27 GB**. Vetor de ponteiros (4 bytes) ≈ 40 MB. Hash ≈ só o necessário. É a melhor
  motivação de hash do livro.
- Agenda telefônica por inicial do nome = função hash por letra, com colisões evidentes.

**Pegadinhas**
- "Usar só os 4 últimos dígitos do RA" como chave **não** elimina colisões: alunos de anos/semestres
  diferentes com o mesmo sequencial colidem. O livro diz que o acesso "permanece imediato".
- Em máquinas de 64 bits o ponteiro tem **8 bytes**: o vetor de ponteiros dá ~80 MB, não 40.
- "13 servidores guardam a tabela de todos os sites do mundo" (DNS raiz): falso. Os servidores raiz só
  apontam para os servidores de TLD. A hierarquia do DNS é que resolve, não uma tabela gigante.
- "Função perfeita = bijetora": basta **injetora** (sem colisões). A bijetora é a "mínima perfeita".
- O enunciado PROB(Fh(x) = I) = 1/26 descreve **distribuição uniforme**, não "ausência de colisões".
- A "cifra de César" da urna eletrônica é apresentada como aplicação de hash. Não é hash (é reversível
  por definição) e não é segura (é a criptografia mais fraca possível). O código usa `gets`/`conio.h` e a
  volta de x, y, z → a, b, c não é desfeita na descriptografia (`'c' − 3 = '`'`).

**Ideias de exercícios**
- m = 10, divisão, inserir 16, 65, 248, 189, 74 e depois 36. → 36 % 10 = 6 colide com 16. Com sondagem
  linear vai para **7**.
- Conta de memória: 10⁷ posições × 8 bytes de ponteiro? → **80 MB**. E uma tabela hash com m = 2003
  ponteiros para 1500 alunos? → ≈ 16 KB de tabela + 1500 × 127 B ≈ 190 KB de registros.

### 0111-encadeamento

**Conceitos-chave**
- Cada posição da tabela guarda uma lista ligada dos elementos que colidiram (encadeamento separado). O
  comparativo hash × lista ligada (acesso direto × sequencial; hash não preserva ordem) é útil.

**Pegadinhas**
- O livro lista **três** técnicas, "endereçamento fechado, endereçamento aberto, encadeamento separado",
  mas define o fechado como "lista ligada em cada índice", que é o próprio encadeamento separado. São
  duas técnicas, não três. A questão 2 do "Faça valer a pena" cobra essa confusão.
- "Mapa com espalhamento permite chaves e valores nulos" é detalhe do `HashMap` de Java, irrelevante em C.

**Ideias de exercícios**
- Implementar `Hash` com encadeamento (`No *tab[M]`): inserir no início da lista do balde, buscar,
  remover com `free` e contar elementos com um campo `n` mantido a cada operação. → `tamanho()` em O(1)
  (o próprio livro recomenda o contador).

### 0112-enderecamento-aberto

**Conceitos-chave**
- Sondagem **linear** ("overflow progressivo"): tenta h, h+1, h+2… e causa **agrupamento primário**
  (clustering).
- **Dispersão dupla** ("re-hash"): h₁(k) = k mod N, h₂(k) = 1 + (k mod (N−1)), próximo índice
  (i + h₂(k)) mod N.
- **Tabela dinâmica**: quando passa de N/2 elementos, dobra e reinsere tudo, para manter o fator de carga
  < 1/2.

**Explicações boas**
- Exemplo m = 8 com 0, 3, 4, 7 ocupados: chave 27 → 27 % 8 = 3 ocupado → 4 ocupado → **5** (linear).
  Com dispersão dupla: h₂ = 1 + 27 % 7 = 7 → (3 + 7) % 8 = **2**. Contas corretas e reaproveitáveis.
- O comentário "na linear, pouco espaço entre itens; na dupla, saltos mais espalhados" é a intuição certa.

**Pegadinhas** (código do livro)
- `insere` linear: **falta `i = (i + 1) % n` dentro do laço**, o que dá laço infinito quando há colisão.
  Além disso, `espalha` usa `% 10` com uma tabela de tamanho 8.
- `busca_espalha` da dupla usa `n` não declarado (o parâmetro é `N`) e o sinal `–` tipográfico em
  `return –1` (não compila se copiado).
- `remove_Esp` põe NULL **na posição h(k)**, sem sondar (se a chave foi deslocada, não acha), sem `free`
  e **quebrando a cadeia de sondagem**: depois disso, buscas por chaves que passaram por ali param no
  NULL e retornam "não encontrado". Precisa de **lápide**.
- `remove_Esp` também desreferencia `tab[h]` sem testar NULL.
- `insere_Esp`: `(MatAluno)* malloc(...)` (cast errado, não compila) e `tab[h]->turma, turma;` (operador
  vírgula: não atribui nada).
- `insere_Esp` do acervo sobrescreve a posição sem tratar colisão (perde o livro antigo e vaza memória).
- `tamanho_Esp` declara retorno `MatAluno*` mas devolve `int`, usa `contador` sem inicializar e o laço é
  `while (contador >= tam)` (condição invertida: nunca roda).
- `expande`/`insere_nova`: `NN` é local em `expande` mas usado em `insere_nova`, e `q` vs. `p` se
  confundem. A ideia está certa, a implementação não.
- Dispersão dupla com N = 8 (potência de 2) só funciona porque h₂ = 7 é ímpar. Regra: N **primo** (ou
  h₂ sempre coprimo de N) para a sondagem visitar todas as posições.
- "A linear tem acesso mais rápido; a dupla usa melhor a memória" é generalização duvidosa: as duas
  ocupam a mesma tabela.

**Ideias de exercícios**
- "Por que a busca falha?": m = 7, h(k) = k % 7, sondagem linear. Insere 10 (→3), 17 (→3 ocupado → 4).
  Remove 10 com o `remove_Esp` do livro (põe NULL em 3). Busca 17. → Começa em 3, vê NULL e devolve
  **"não encontrado"**, embora 17 esteja em 4. Correção: marcar a posição 3 como REMOVIDO (lápide),
  que a busca pula e a inserção reaproveita.
- Dispersão dupla, m = 11, h₁ = k % 11, h₂ = 1 + k % 10, inserir 22, 33, 44. → 22→0. 33→0 ocupado,
  h₂ = 4 → **4**. 44→0 ocupado, h₂ = 5 → **5**.
- Tabela dinâmica: começa com N = 4 e dobra quando M ≥ N/2 antes de inserir. Quantas expansões para
  inserir 10 chaves e qual o N final? → Antes da 3ª inserção (M = 2) dobra para 8; antes da 5ª (M = 4)
  dobra para 16; antes da 9ª (M = 8) dobra para 32. **3 expansões, N = 32**.

---

### NOVO: TAD dicionário / mapa (armazenamento associativo)

**Conceitos-chave**
- Armazenamento associativo: acessar pelo **valor da chave**, não pela posição. Exemplos: localizador de
  passagem aérea, placa de veículo, CPF, código de barras, número da nota fiscal, código Morse, tabela
  de símbolos do compilador, tabelas de arquivos/processos do SO.
- Operações do TAD mapa: inserir associação, consultar valor da chave, remover associação, testar se a
  chave existe, informar o tamanho. **Chaves únicas**: inserir chave existente substitui o valor.
- Implementações: lista de pares (simples, O(n) por operação) vs. hash (O(1) em média), com a observação
  de que a lista degrada com muitos dados.

**Explicações boas**
- A lista de exemplos do mundo real é boa para abrir o tema. A motivação "nomes iguais → CPF" explica
  por que a chave precisa ser única.

**Pegadinhas**
- Toda a unidade 4 usa `std::map` de **C++**, que é uma **árvore rubro-negra** (ordenada, O(log n)), e não
  uma lista. O livro chama isso de "mapa com lista". O "mapa com espalhamento" usa `<hash_map>`, cabeçalho
  não padrão e obsoleto (o padrão é `unordered_map`).
- Em `std::map`, `mapa[1]` depois de `erase(1)` **recria** a chave com valor vazio. O exemplo do livro faz
  exatamente isso "para verificar se foi removida".
- Chave gerada por `size() + 1`: depois de uma remoção, a próxima inserção **sobrescreve** um prato
  existente. O laço `for (i = 1; i <= size(); i++)` deixa de listar os itens de chave maior que `size()`.
- O "Hashmap em C" do fim é um mosaico quebrado: `malloc` seguido de `= NULL` (vazamento), função que
  retorna `HashmapNo*` devolvendo string, `insere` que nunca liga o nó na tabela, `remove` que mexe em
  campos inexistentes (`values`) e desreferencia NULL, `expand` com `free` da variável errada e colisões
  sobrescritas, `scanf("%s", &chave)` com `int`, `gets`.
- `hash = (hash >> 3) * 2654435761` com `int`: estouro de inteiro **com sinal** é comportamento
  indefinido. Use `uint32_t`.

**Ideias de exemplos (em C, para o curso)**
- TAD `Dicionario` com `dic_cria`, `dic_poe`, `dic_pega`, `dic_tem`, `dic_remove`, `dic_tamanho`,
  `dic_libera`, implementado duas vezes (lista de pares e hash com encadeamento) com a **mesma interface
  `.h`**. Mostra independência de representação (0079).
- Contador de frequência de palavras de um texto (chave string → int).
- Cardápio da sra. Fátima: número do prato → nome + ingredientes.

**Ideias de exercícios**
- Implementar `dic_poe` que substitui o valor se a chave existe. Teste: poe(101, "Parmegiana"),
  poe(101, "Bisteca"), pega(101). → **"Bisteca"**, tamanho 1.
- Votação de síndico (do livro), refeita em C com dicionário número → {nome, votos}. Empate? → Decidir
  e documentar a regra (ex.: menor número vence).

### NOVO: backtracking
- **Semente no livro:** labirinto com pilha de bifurcações ("marcações para onde o algoritmo pode
  retornar") e undo.
- **Conceitos a ensinar (corrigindo o livro):** busca exaustiva que constrói a solução passo a passo e
  **desfaz** a última escolha quando ela leva a beco sem saída. A poda corta ramos inviáveis. O custo
  costuma ser exponencial. Clássicos: labirinto, N rainhas, subconjuntos, permutações, sudoku.
- **Ideia de exercício:** labirinto 5×5 em arquivo texto, imprimir o caminho encontrado com `*`. →
  Comparar o número de células visitadas com e sem marcação de visitado (sem marcação: laço infinito
  em ciclos).

### NOVO: ordenações lineares (bucket sort, a partir do "cálculo de endereço")
- **Semente no livro:** a "função de cálculo de endereço" com faixas (< 30 → 1; 30–49 → 2; ≥ 50 → 3)
  aplicada a {75, 46, 7, 34, 13}, cada faixa numa lista ordenada, unindo as listas no fim. O livro
  chama isso de função de espalhamento, mas é **bucket sort** (hash que **preserva ordem**, o oposto do
  hash usual).
- **Ideia de exercício:** com as faixas do livro, quais elementos vão para cada balde e qual a lista
  final? → Balde 1: [7, 13]; balde 2: [34, 46]; balde 3: [75] → **7, 13, 34, 46, 75**. Discutir quando o
  bucket sort é O(n): chaves uniformes e nº de baldes proporcional a n.

### NOVO: análise amortizada (tabela que dobra)
- **Semente no livro:** "quando a tabela passa de N/2 elementos, dobramos o seu tamanho". O livro chama
  a reinserção de "operação ineficiente", sem mostrar que o custo **amortizado** é O(1).
- **Ideia de exercício:** com dobra a partir de N = 1, quantas reinserções no total para chegar a 1024
  elementos? → 1 + 2 + 4 + … + 512 = **1023** < 2·1024, logo O(1) amortizado por inserção.

### NOVO: funções de hash para inteiros e strings
- **Conceitos-chave a partir do livro:** divisão (k mod m, m primo longe de potências de 2); método
  multiplicativo de Knuth (`k * 2654435761u`, constante ≈ 2³²/φ); hash de strings (o "Reflita": dá para
  usar strings como chave? quantos caracteres usar?).
- **Ideia de exercício:** hash de string "soma dos caracteres" vs. polinomial (h = h·31 + c). Mostrar
  que "amor" e "roma" colidem na soma e não na polinomial. → Soma igual (anagramas); polinomial difere.

### NOVO: árvore rubro-negra (só gancho)
- O livro não fala nela, mas toda a unidade 4 roda sobre `std::map`, que é uma rubro-negra. Bom gancho
  para explicar por que o "mapa ordenado" das bibliotecas é O(log n) e mantém ordem, ao contrário do hash.

---

## Obsoleto / evitar

- **Unidade 4 inteira como código**: C++ (`iostream`, `map`, `string`, `cout`) fora do escopo; `<hash_map>`
  não padrão; mistura `printf`/`cout`; `scanf("%s", &int)`.
- `gets` (removida do C11), `conio.h`, `system("PAUSE")`/`system("cls")` (só Windows), aspas tipográficas
  “ ” e travessão – no código (não compila se copiado).
- Funções de remoção sem `free` (listas simples e duplas, hash): vazamento sistemático.
- `exit(1)` dentro de TAD para sinalizar fila vazia/cheia. Prefira código de retorno.
- "Ordenar a lista inteira após cada inserção" como forma de manter ordem.
- Afirmações falsas: lista simples percorrível nos dois sentidos; ponteiro "inteiro"; backtracking "no
  menor tempo"; GPS = backtracking; DNS raiz com "todos os sites"; função perfeita = bijetora; César
  como hash/criptografia segura; três técnicas de colisão (fechado = encadeamento); "fila circular usa
  menos instruções"; chamar C de "C++".
- Exercícios "Faça valer a pena" de completar lacunas com palavras ("FILO, FOLO, FILI…"): baixo valor.
- Narrativas de "entregue um relatório" sem conteúdo técnico.

## Recomendações

1. **Não usar como fonte de código.** Usar como **banco de "ache o erro"**, que é onde ele brilha.
   Seleção pronta: `inserirFim` com lista vazia (0082); `retira` sem `free` + valgrind (0062/0082);
   `inserirPosicao` fora por um (0082); `Ordena` O(n²) por inserção (0083); `pilha` sem checar
   cheia/vazia (0087); contador da Hanói (0038, resposta 3 vs 7); laço infinito do `insere` linear
   (0112); `remove_Esp` que quebra a sondagem (0112, exige lápide); `tab[h]->turma, turma;` (operador
   vírgula, 0014); `int` com sinal estourando no hash multiplicativo (0008).
2. **0110-hashing:** adotar o **exemplo do RA** (endereçamento direto 1,27 GB → ponteiros → hash),
   corrigindo para 8 bytes por ponteiro e trocando "4 últimos dígitos" por `RA % m` com m primo.
3. **0112:** reaproveitar os números do exemplo m = 8 / chave 27 (linear → 5; dupla → 2) e as fórmulas
   h₂(k) = 1 + k mod (N−1). Acrescentar a regra de N primo e a remoção com lápide.
4. **0090:** usar a fila de Celes (`ini` + `n`, `fim = (ini+n) % N`) como **a** fila circular do curso.
   Descartar a "circular" de índices 1..N−1.
5. **0081:** aproveitar a distinção lista **com cabeçalho** (sentinela) × **sem cabeçalho** e o padrão
   `l = inserir(l, x)`.
6. **NOVOS sugeridos:** TAD dicionário (interface única com duas implementações), backtracking
   (labirinto, corrigindo a definição), bucket sort a partir do "cálculo de endereço", análise amortizada
   via tabela que dobra, funções de hash (Knuth multiplicativa, polinomial para strings). Round-robin
   como projeto do módulo de filas (0093).
7. Para teoria de qualquer assunto aqui, preferir Celes et al., Tenenbaum ou Cortés. Rovai não traz
   análise de complexidade em nenhum capítulo.

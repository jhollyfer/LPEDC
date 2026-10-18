# Fichamento — Estrutura de Dados (Mariela Inés Cortés)

- **Autora:** Mariela Inés Cortés (UECE; doutora pela PUC-Rio, área de Engenharia de Software)
- **Edição:** 3ª ed., EdUECE / UAB, Fortaleza, 2015 (arquivo rotulado 2014), 126 p., Licenciatura em Informática a distância
- **Lido:** 2936 linhas, por completo (Apresentação + 7 capítulos: complexidade, representação de dados/TAD, listas, pilhas, filas, árvores/BST/AVL, busca avançada: hash, árvore digital, autoajustáveis)

## Avaliação geral

Apostila de EaD curta e **conceitual**. O texto explica bem o *porquê* das decisões de projeto:
onde pôr o topo da pilha (no fim do vetor, mas na cabeça da lista encadeada), por que a fila insere
no fim e remove no início, por que a fila sobre vetor precisa ser circular, e o custo de cada
operação em O(·). Também traz um exemplo completo e correto de construção de AVL (1, 4, 7, 9, 8, 12, 10).
Os pontos fortes são os capítulos 1, 2 e 6 e a seção de **estruturas autoajustáveis**, que é rara em
material brasileiro e serve de semente para os NOVOS "listas autoajustáveis" e "análise amortizada".

O ponto fraco é grave: o **código é pseudo-C cheio de bugs** e, na extração, muitos corpos de função
vieram vazios (as figuras se perderam). Há passagem de cabeça de lista por valor (as alterações se
perdem), `&` no lugar de `&&`, `pos++` devolvendo o valor antigo, `Vazia` que testa `topo == 0` quando o
topo começa em -1, `:=` de Pascal misturado com C, `printf(Conteudo(a))` sem formato e a fila encadeada
que esquece de zerar `fim`. Também há afirmações teóricas erradas: a sondagem quadrática descrita como
10, 100, 1000, `n log n` chamada de "logarítmica", busca digital em "O(log n)" e o fator de
balanceamento sem valor absoluto. **Use as ideias e as figuras mentais; não copie código.** Os bugs viram
ótimos exercícios de "ache o erro" (lista na seção final).

---

### 0076-eficiencia

**Conceitos-chave**
- Qualidade de programa depende do ponto de vista. Para o usuário contam interface, compatibilidade,
  velocidade e memória. Para a organização contam portabilidade, documentação, manutenção e reuso.
  Velocidade e memória são os dois critérios que **crescem com o tamanho da entrada**.
- Fatores **acidentais** (hardware, SO, compilador) versus **essenciais** (tempo e espaço inerentes ao
  algoritmo). Medir com cronômetro mistura os dois, por isso se conta operações.
- Complexidade temporal = nº aproximado de instruções. Espacial = memória usada. As duas são funções de n.
- Além do tamanho, a **organização** da entrada importa (vetor quase ordenado vs. embaralhado).
- Três cenários: pior caso (pessimista, dá cota superior e é o mais usado), melhor caso (otimista) e
  caso médio (média sobre todas as entradas de tamanho n).

**Explicações boas**
- Busca de um elemento num conjunto de 100: achar na 1ª comparação ou comparar com os 100 e não achar.
  É a entrada natural para melhor e pior caso.
- Regras de contagem por estrutura de controle: sequência → soma (fica o maior); `if` → condição O(1)
  mais o ramo **mais caro**; laço → custo do corpo × nº de iterações, analisando **de dentro para fora**;
  atribuição → O(1).
- Análise linha a linha do `Maximo(v, n)`: corpo do laço O(1), n−1 iterações → O(n).

**Pegadinhas**
- O texto diz que um programa sem laço nem recursão tem custo constante, mas uma chamada a `strlen` ou
  `printf("%s")` esconde um laço. "Sem laço visível" não quer dizer O(1).
- No exemplo do `Maximo` aparece `if (n = 0)`, que é atribuição. Ótimo para lembrar a pegadinha do
  módulo 02.

**Ideia de exemplo:** instrumentar o `Max` com contador e testar vetores crescente, decrescente e aleatório.

**Ideias de exercícios**
- Quantas comparações entre elementos o `Max` faz em um vetor de n elementos? → **n−1, sempre** (melhor =
  pior = médio). O que varia é o número de **atribuições** `Temp = A[i]`: 0 se o máximo está em A[0], n−1
  se o vetor é crescente.
- Melhor e pior caso de "remover um elemento dado de um vetor desordenado". → Se a ordem tem de ser
  preservada, busca + deslocamento somam sempre cerca de n passos (achar no início = 1 comparação + n−1
  deslocamentos; achar no fim = n comparações + 0 deslocamentos): **Θ(n) em todos os casos**. Se a ordem
  não importa (vetor desordenado!), dá para copiar o último para o buraco. Aí o melhor caso é **O(1)**
  (elemento em v[0]) e o pior é O(n) (ausente). Bom para mostrar que a especificação muda a complexidade.

### 0077-big-o

**Conceitos-chave**
- Interessa o comportamento para **n grande** (assintótico). Para entradas pequenas até algoritmo ruim é rápido.
- f domina g se, a partir de um ponto m, f fica sempre acima. Os casos são: f sempre abaixo (escolha
  óbvia), as curvas se cruzam infinitas vezes (empate, ex. funções oscilantes) e as curvas se cruzam um
  número finito de vezes (vence a que fica embaixo no fim).
- Definição: C(n) = O(F(n)) se existem c > 0 e m tais que C(n) ≤ c·F(n) para todo n ≥ m.
- Teste do limite: lim f/g = 0 → g é cota superior de f; = constante → mesma ordem; = ∞ → f domina.
- Ω (cota inferior), Θ (exata), o (estritamente menor). Só cita, sem definir formalmente.
- Álgebra do O: c·O(f) = O(f); O(f)+O(g) = O(max); O(f)·O(g) = O(f·g); O(O(f)) = O(f).
- Notação atribuída a Knuth (1968), com box biográfico.

**Explicações boas**
- (n+1)² = O(n²) com c = 4 e m = 1. Exemplo pequeno e verificável à mão.
- "2n² é O(n⁴), O(n³) e O(n²): todas corretas, mas a menor é a resposta útil". Boa para separar
  "verdadeiro" de "informativo".
- Tabela de funções comuns: constante, linear, n log n, quadrática, cúbica, polinomial, exponencial.

**Pegadinhas**
- A tabela do livro rotula `n · log n` como **"Logarítmica"**. Está errado: log n é logarítmica e
  n log n é "linearítmica" (ou "n log n").
- O livro diz que "o algoritmo assintoticamente mais eficiente é o melhor para todas as entradas".
  Falso: é o melhor para n **grande**. 1000·n² ganha de 0,1·n³ até n = 10 000.
- Confusão comum que o texto alimenta: O é cota superior e não sinônimo de "pior caso". Dá para falar
  em O do melhor caso.

**Ideia de exemplo:** programa C que imprime a tabela de log n, n, n log n, n², 2ⁿ para n = 1, 2, 4, …, 64.

**Ideias de exercícios**
- C_A(n) = 1000n² e C_B(n) = 0,1n³. A partir de que n o B fica pior? → 0,1n³ > 1000n² ⇔ n > **10 000**.
- Ordene do melhor ao pior para n grande: 100·n log n, 1000·n, 4n², 10⁻⁵·eⁿ. → **1000n < 100 n log n <
  4n² < 10⁻⁵eⁿ**. As constantes não salvam a exponencial.
- Mostre que 3n³+2n²+n = O(n³). → Para n ≥ 1, 2n² ≤ 2n³ e n ≤ n³, então a soma ≤ 6n³. Basta **c = 6, m = 1**.
- g(n) = n e f(n) = n²: qual vale, f = O(g) ou g = O(f)? → **g = O(f)** (c = 1, m = 1). f = O(g) é falso
  porque n²/n → ∞.

### 0095-busca-binaria

**Conceito-chave:** aparece como exercício do cap. 1 (`inf`, `sup`, `meio`, `while (inf <= sup)`).

**Pegadinha:** `(inf+sup)/2` pode estourar `int` em vetores enormes. Use `inf + (sup-inf)/2`.

**Ideias de exercícios**
- Quantas iterações, no máximo, para concluir que a chave não está num vetor de 15 elementos? → **4**
  (15 → 7 → 3 → 1 → 0; ⌊log₂15⌋+1).
- Melhor caso? → a chave está no meio: **1** iteração. Pior → ausente: ⌊log₂n⌋+1, ou seja, O(log n).

### 0079-tad

**Conceitos-chave**
- Abstração: o modelo guarda só o relevante. O "fosso semântico" é a distância entre a descrição de alto
  nível (domínio do problema) e a de baixo nível (bits).
- Tipo de dado = conjunto de valores + quantos bits reservar + como interpretar o padrão de bits.
- Primitivos vêm com operações prontas. Tipos estruturados definidos pelo usuário (`struct`) **só trazem
  o armazenamento, sem operações**. TAD = tipo + operações + **ocultamento** (interface separada da
  implementação).
- Estrutura homogênea (vetor, lista) vs. heterogênea (registro).
- Bom TAD: operações coesas e de propósito único, e conjunto **completo** (toda propriedade acessível pela
  interface).
- Independência de representação: troca-se vetor por lista sem afetar o cliente.

**Explicações boas**
- TAD Retângulo (altura, largura, área, perímetro), mínimo e simpático. Lista de entidades para modelar como `struct` e depois como TAD: Livro, Círculo, Filme, Pessoa, Aluno,
  Item de estoque, Conta bancária.

**Pegadinhas**
- O Retângulo do livro usa variáveis **globais** `altura` e `largura` (ao estilo de um objeto), então só
  existe um retângulo no programa. Em C o certo é passar `Retangulo *r`. Bom contraexemplo.
- O livro chama TAD de "conceito central da orientação a objetos". Em C não há classes: o ocultamento é
  feito com ponteiro opaco no `.h`.

**Ideias de exercícios**
- Reescrever o TAD Retângulo com tipo opaco (`typedef struct retangulo Retangulo;` no `.h`) e funções
  `ret_cria`, `ret_area`, `ret_libera`. → O cliente não consegue fazer `r->altura`: o compilador acusa
  "incomplete type".

### 0058-pilha-e-heap

**Conceitos-chave**
- Três jeitos de reservar memória: global/estática (vive o programa inteiro), local (vive enquanto a
  função roda, na pilha de execução) e dinâmica (até o `free`).
- Desenho clássico: código, globais, pilha crescendo de um lado e heap do outro. Pilha que encontra o
  limite "estoura" e o programa aborta. `malloc` sem memória retorna NULL, que deve ser tratado.
- Estática/contígua: acesso direto O(1) por aritmética de endereço, mas tamanho fixo e
  inserção/remoção O(n) por deslocamento. Dinâmica/encadeada: cresce sob demanda e insere/remove só
  ajustando ponteiros, mas acesso ao i-ésimo é O(n) e o código é mais propenso a erro.

**Explicações boas**
- Tabela "endereço | conteúdo | ponteiro" mostrando nós espalhados (3FFB → 1D34 → BD2F … → null). Ótima
  para desenhar a lista encadeada como gaveteiro numerado.

**Pegadinha:** "Se não liberar, o SO libera ao terminar." É verdade, mas não desculpa vazamento.

### 0080-vetor-dinamico

**Conceitos-chave**
- TAD Lista com interface mínima: Criar, Inserir(pos), consultaElemento(pos), Remover(pos), Vazia, Cheia,
  Tamanho, proximoElemento, Busca. O tipo `corrente` abstrai a "posição" (índice no vetor e ponteiro na
  versão encadeada). É uma boa ideia de projeto de interface.
- Implementação com `tipo_base v[tamanho]` + `quant_Elem`. Inserir na posição p desloca para a direita
  do fim até p (pior caso: p = 0, O(n)). Remover desloca para a esquerda (O(n)). Consulta por posição é O(1).
  Busca por conteúdo é O(n).

**Explicações boas**
- Desenho de inserir na posição 3 de uma lista de 5: os 3 últimos andam uma casa.

**Pegadinhas** (do código do livro)
- `Busca` usa `for (i = 0; i <= tamanho(l); i++)`. O `<=` lê uma posição além do último elemento.
- `Consulta` devolve `v[pos-1]` enquanto o resto da interface usa posições a partir de 0 (inconsistência
  de base).
- A descrição de `validaPos` diz "posição maior que a quantidade − 1". A condição está invertida.
- O loop do deslocamento precisa começar em `quant_elem` e ir **até `> pos`** (`v[i] = v[i-1]`). Com
  `>= pos` lê-se `v[pos-1]`, que para pos = 0 é `v[-1]`.

**Ideias de exercícios**
- Implemente `Tamanho` nas duas versões. → Vetor com contador: **O(1)**. Lista encadeada sem contador:
  **O(n)**.

### 0081-lista-encadeada

**Conceitos-chave**
- Nó autorreferenciado `{ elemento; prox; }`. A lista é um ponteiro para o primeiro nó, e a lista vazia é NULL.
- Usar um ponteiro auxiliar (`corrente`) para percorrer evita "perder a cabeça" da lista.
- Exercícios clássicos: intercalar duas listas, liberar a lista toda, união/interseção, gerar lista
  ordenada a partir de outra, concatenar e inverter.

**Pegadinhas**
- `Inserir(Lista l, …)` faz `l = novo` **dentro da função**, mas `l` é cópia, então a cabeça não muda no
  chamador. Soluções: retornar a nova cabeça ou receber `Lista *l`. É o bug nº 1 de lista em C e o livro o
  comete em Inserir, Remover, Push e Pop.
- Cast de `malloc` para `Lista` quando o tipo certo é ponteiro para nó: só funciona porque
  `Lista == no_ptr`. Vale explicar.

**Ideias de exercícios**
- "Ache o erro": mostrar o `Push` do livro (`p = novo;`) e perguntar por que, após 3 pushes, a pilha
  continua vazia no `main`. → Passagem por valor do ponteiro: alterar a cópia não altera o original.
  Correção: `Pilha *p` e `*p = novo`, ou retornar `novo`.

### 0082-lista-busca-remocao

**Conceitos-chave**
- Remover tem dois casos: o 1º nó (atualiza a cabeça) ou um nó do meio/fim (o anterior "pula" o removido:
  *by-pass*). Depois sempre `free`.
- A função `Anterior` custa O(n). Por isso remoção em lista simples é O(n), embora o religamento em si
  seja O(1).

**Pegadinhas** (código do livro)
- `Anterior` usa `&` (bit a bit) no lugar de `&&` e **retorna 1** em vez de `ant`. A segunda versão tem
  chave sem fechar.
- `while (atual != NULL & atual->prox != pos)`: com `&` não há curto-circuito, então quando `atual` é
  NULL ainda se avalia `atual->prox` e o programa quebra. É exemplo perfeito para o módulo 02 (curto-circuito).

**Ideias de exercícios**
- Escreva `remover(Lista *l, int x)` sem função `Anterior`, guardando `ant` durante a busca. → Um único
  percurso O(n). Casos testados: lista vazia, remover o 1º, o último, um do meio e valor ausente.

### 0083-lista-ordenada
- **Conceitos-chave:** a inserção acontece "no lugar certo" pelo campo-chave, e a busca pode **parar cedo**
  (ao passar do valor procurado).
- **Ideia de exercício:** busca em lista ordenada que para ao encontrar elemento maior. Quantas comparações
  para buscar 15 em 2, 5, 9, 20, 31? → **4** (para no 20, sem ir até o fim).

### 0084-lista-dupla
- **Conceitos-chave:** ponteiro extra para o anterior. Custa espaço e mais ponteiros para ajustar, mas a
  remoção dado o nó vira O(1) (não precisa procurar o anterior) e dá para percorrer de trás para frente.
- **Ideia de exercício:** quantas atribuições de ponteiro para remover um nó do meio de uma lista dupla?
  → **2** (`p->ant->prox = p->prox; p->prox->ant = p->ant;`) + `free`.

### 0085-lista-circular
- **Conceitos-chave:** o último nó aponta para o primeiro, então "prox == NULL" nunca acontece. O critério
  de parada é voltar ao nó inicial ou contar elementos.
- **Pegadinha:** percorrer com `while (p != NULL)` vira laço infinito. **Exemplo:** Josephus (de k em k numa roda).

### 0087-pilha

**Conceitos-chave**
- Pilha = lista com inserção e remoção **num só extremo** (topo), LIFO. Busca no meio não faz parte do TAD.
- Interface: Criar, Push, Top, Pop, Vazia, Cheia, Tamanho.
- No vetor o topo fica no **fim** (índice `topo`): push e pop O(1). Pôr o topo em `v[0]` exigiria
  deslocar tudo, O(n).
- Comentário bom: depois do vetor, a pilha é a abstração mais fundamental, a ponto de existir nas
  instruções de máquina (pilha de chamadas).

**Explicações boas**
- Pilha de **livros pesados**: só o de cima é visível. Para pegar um do meio, tira os de cima um a um.

**Pegadinhas** (código do livro)
- `Criar` faz `topo = -1`, mas `Vazia` testa `topo == 0`. Com um elemento a pilha "está vazia", e vazia
  de verdade (−1) "não está". **Ótimo exercício.**
- `Pop` não verifica pilha vazia antes de ler `elementos[topo]`.

**Ideias de exercícios**
- Por que o topo no fim do vetor e no início da lista encadeada? → No vetor o fim é acessível por índice
  em O(1) sem deslocar. Na lista simples o início é O(1) e o fim exigiria achar o penúltimo, O(n).
- Inverter uma lista usando pilha; maior, menor e média de uma pilha usando só a interface (desempilhar
  numa auxiliar e reempilhar para não destruir).

### 0088-pilha-encadeada
- **Conceitos-chave:** o topo é a cabeça da lista. Push = inserir no início; Pop = remover o primeiro,
  guardar o valor, `free` e devolver.
- **Pegadinha:** o `Push` do livro testa `no_tmp == NULL`, mas a variável alocada se chama `novo` (não
  compila). O `Pop` devolve 0 quando a pilha está vazia, valor indistinguível de um 0 empilhado. Melhor
  devolver status e o valor por ponteiro.
- **Exercício:** liberar a pilha. → Pop até vazia: **O(n)**.

### 0090-fila

**Conceitos-chave**
- FIFO: insere num extremo (fim) e remove no outro (início). Fila de banco.
- Sobre vetor, guardar `ini`, `fim` e `quant`. Sem circularidade, a fila "parece cheia" com espaço livre
  no começo. Solução: **incremento circular** (ao chegar no fim do vetor, volta a 0), com o fim lógico
  dado pela quantidade de elementos.

**Pegadinhas** (código do livro)
- `incrementar` termina com `return (pos++)`: o pós-incremento **devolve o valor antigo**, então a função
  não avança. O certo é `return pos + 1;` ou `(pos + 1) % N`. Liga direto com o assunto 0014.
- O texto diz que manter os índices dá acesso direto "O(n)" (quis dizer O(1)).
- O livro usa `ini = fim = -1` como sentinela de vazia **e** um contador. Redundante e fonte de bug.
  Basta `ini`, `quant` e `fim = (ini + quant) % N`.

**Ideias de exercícios**
- Mostre o estado de `ini`, `fim` e `quant` numa fila circular de tamanho 5 após: insere a, b, c, d;
  remove; remove; insere e, f, g. → Resposta com ini = 0 inicial e fim = próxima livre: depois de
  a,b,c,d: ini = 0, quant = 4. Duas remoções: ini = 2, quant = 2. Inserir e, f, g ocupa as posições 4, 0, 1:
  **ini = 2, quant = 5, vetor = [f, g, c, d, e]** (cheia).
- Por que remover no início e inserir no fim (e não o contrário)? → Na versão encadeada, remover o último
  exige achar o penúltimo, O(n). Inserir no fim com ponteiro `fim` é O(1).

### 0091-fila-encadeada
- **Conceitos-chave:** um "nó cabeçalho" com `ini` e `fim`. Inserir no fim (atualiza `fim->prox` e `fim`;
  se estava vazia, também `ini`). Remover do início (se ficou vazia, zera também `fim`).
- **Pegadinha (bug clássico no livro):** no `remover`, quando a fila esvazia, o livro escreve
  `f->ini == NULL` (comparação, não atribuição) onde deveria ser `f->fim = NULL`. Resultado: `fim` fica
  apontando para nó liberado e a próxima inserção escreve em memória solta. Excelente para mostrar no
  valgrind (0062).
- **Ideia de exercício:** filas PAR e ÍMPAR + PILHA (exercício 5 do cap. 5): ler inteiros até 0,
  separar por paridade, retirar alternando (começando pela ímpar), empilhar positivos e desempilhar nos
  negativos. Ex.: entrada 3, −4, 6, −1, 8, 0. Ímpar = [3, −1], par = [−4, 6, 8]. Ordem de retirada:
  3, −4, −1, 6, 8. Pilha: push 3 → [3]; −4 → pop (sai o 3) → []; −1 → pop em pilha vazia (tem de
  ser tratado: é o ponto do exercício); push 6; push 8. **Saída (topo→base): 8, 6**.

### 0102-arvores

**Conceitos-chave**
- Definição recursiva: vazia, ou raiz + subárvores disjuntas que também são árvores.
- Grau de um nó (nº de filhos), grau da árvore (maior grau), folha, caminho, comprimento, nível,
  altura. Só existe **um** caminho da raiz a cada nó.
- Árvore binária vs. genérica (nº de filhos indefinido).

**Explicações boas**
- Conjuntos aninhados (diagrama de Venn) ↔ árvore. Diretórios como exemplo de hierarquia.

**Pegadinhas**
- O livro dá **duas definições incompatíveis de altura**: altura da árvore com só a raiz = 0 (contando
  arestas) e depois "folhas têm altura 1" (contando nós). O nível da raiz é 0 "por definição", mas o
  nível foi definido como nº de nós no caminho. **Fixe uma convenção no curso** (sugestão: arestas;
  folha = 0; árvore vazia = −1) e avise que os livros divergem.

**Ideias de exercícios**
- Para uma árvore desenhada, dar grau de cada nó, grau da árvore, folhas, nível e altura de cada nó.

### 0103-arvore-binaria

**Conceitos-chave**
- Estritamente binária (0 ou 2 filhos), completa (nós com subárvore vazia só nos dois últimos níveis),
  cheia (todos os vazios no último nível).
- Altura h ⇒ no máximo 2^(h+1) − 1 nós, logo altura mínima ~ log₂ n. Altura máxima = n − 1 (degenerada).
- Percursos pré, em (simétrica) e pós-ordem, recursivos.
- Árvore de expressão: folhas operandos, nós internos operadores.

**Explicações boas**
- Árvore de (5 + 9) * (3 − 7) + 7 com os três percursos: pré `+ * + 5 9 − 3 7 7`, pós `5 9 + 3 7 − * 7 +`.
- Função `cheia(a)` recursiva (exercício resolvido): vazia → 1; um filho só → 0; senão
  cheia(esq) && cheia(dir).

**Pegadinhas**
- O livro afirma que o percurso em ordem dá "5 + 9 * 3 − 7 + 7" e que isso "é uma expressão válida".
  Válida sintaticamente, mas **com outro valor** (sem parênteses a precedência muda: 5 + 27 − 7 + 7 = 32,
  quando o certo é 14 · (−4) + 7 = −49). Em ordem precisa repor parênteses. Pré e pós-ordem dispensam
  parênteses, ao contrário do que o livro sugere ao chamá-las de "não válidas".
- `printf(Conteudo(a))` sem string de formato. Correto: `printf("%d ", a->info)`.

**Ideias de exercícios**
- Avalie a árvore da expressão acima recursivamente. → **−49**.
- Nº máximo de nós com altura 3 (arestas). → **15**.

### 0104-bst-busca-insercao

**Conceitos-chave**
- Propriedade: tudo à esquerda < nó < tudo à direita, valendo recursivamente.
- Busca desce à esquerda ou à direita. Inserção segue a busca e sempre cria uma **folha**.
- Duplicatas: em vez de repetir o nó, manter um **contador de frequência** no nó (árvore menos funda).
- Custo proporcional à altura: O(log n) em média para inserções aleatórias e O(n) no pior caso.

**Pegadinhas**
- O livro define a BST com "≤ à esquerda e ≥ à direita" e logo diz que não há repetidas. Escolha uma
  regra estrita (<, >) e trate repetidas à parte.
- "Como a profundidade média é O(log n), as operações também" esconde que inserir já ordenado dá lista
  (o livro mostra no exercício 1, 2, …, 7).
- A inserção do livro não fecha o `else` com a chamada recursiva (corpo perdido). Lembre que a versão
  recursiva precisa de `T->esq = Inserir(x, T->esq)`.

**Ideias de exercícios**
- Insira 20, 5, 12, 36, 27, 45, 9, 2, 6, 17, 40. → Raiz 20. Esq: 5 (esq 2; dir 12 (esq 9 (esq 6); dir 17)).
  Dir: 36 (esq 27; dir 45 (esq 40)). Em ordem: 2 5 6 9 12 17 20 27 36 40 45.
- Insira 1..7 em ordem. → Degenerada (só filhos à direita), **altura 6**: buscar 7 custa 7 comparações,
  igual a uma lista.
- Contar nós com valor em [x1, x2] podando subárvores fora do intervalo.

### 0105-bst-remocao

**Conceitos-chave**
- Folha: remove direto. Um filho: o pai passa a apontar para o neto (by-pass). Dois filhos: copia o
  **sucessor** (menor da direita) ou o antecessor (maior da esquerda) e remove esse nó, que tem no máximo
  um filho.
- `buscaMin` recursivo e iterativo. O iterativo economiza pilha.
- Remoções repetidas usando sempre o sucessor desequilibram a árvore para um lado.

**Pegadinha:**
- O `Remover` do livro mistura nomes (`v`, `T`, `tmp_cell`), compara `pai->dir == T` e não trata a raiz
  (pai NULL). Versão limpa: `No *remover(No *r, int x)` recursiva, que devolve a nova raiz da subárvore.

**Ideias de exercícios**
- Na BST de 20, 5, 12, …, 40, remova 9, depois 5, depois 20 (sucessor). → Remove 9 (um filho): 12 fica
  com esq 6. Remove 5 (dois filhos): o sucessor é 6, o 5 vira 6 e o 6 antigo some. Remove 20: o sucessor
  é 27, a raiz vira 27 e o 36 fica sem esq. **Final: 27 (esq 6 (esq 2; dir 12 (dir 17)); dir 36 (dir 45 (esq 40)))**.
  Em ordem: 2 6 12 17 27 36 40 45.

### 0106-avl

**Conceitos-chave**
- AVL (Adel'son-Vel'skii e Landis): em todo nó, |altura(esq) − altura(dir)| ≤ 1, o que garante altura
  O(log n).
- Fator de balanceamento FB = h(esq) − h(dir), com folha FB = 0. Na inserção, só os nós do caminho de
  volta à raiz podem desregular.
- Quatro casos: FB > 1 com filho esquerdo pendendo à esquerda → rotação simples à direita; FB > 1 com
  filho pendendo à direita → dupla à direita; espelhos com FB < −1.
- Função `Altura` recursiva (vazia = −1).

**Explicações boas**
- **Exemplo passo a passo correto**: inserir 1, 4, 7, 9, 8, 12, 10 → rotação simples esq. em 1; dupla esq.
  em 7; simples esq. na raiz 4; dupla esq. em 9. Final **8 (4 (1, 7), 10 (9, 12))**, altura 2. Sem
  balancear, a BST teria altura 5 (caminho 1→4→7→9→12→10, em arestas), como o livro diz.

**Pegadinhas**
- O livro diz "se FB ≤ 1 está balanceado". Falta o **módulo**: FB = −5 também é ≤ 1. Correto: |FB| ≤ 1.
- Também afirma que "todas as operações são O(log n), exceto possivelmente a inserção". Errado: inserção
  e remoção são O(log n). A inserção faz no máximo uma rotação (simples ou dupla). A remoção pode fazer
  O(log n) rotações.
- Tipos II/III usam rotação dupla quando o filho tem FB **"menor ou igual"**. Na inserção o caso "igual"
  não ocorre. Na **remoção**, filho com FB = 0 pede rotação **simples**. Regra correta: dupla só quando o
  sinal do FB do filho é oposto ao do nó.
- `Altura` do livro usa `:=` (Pascal), `if (no = NULL)` e troca SAD/SAE nos nomes. Recalcular altura
  recursivamente a cada inserção dá O(n): guarde a altura no nó.

**Ideias de exercícios**
- Construa a AVL com 50, 20, 30, 25, 10, 15, remove 20, insere 20, insere 40 (ex. 5 do livro). →
  50, 20, 30: LR em 50 → 30 (20, 50). +25, +10: 30 (20 (10, 25), 50). +15: desregula 30 (esq h2, dir h0),
  filho 20 com FB +1 → simples à direita → **20 (10 (−, 15), 30 (25, 50))**. −20 (sucessor 25) →
  25 (10 (−, 15), 30 (−, 50)). +20: desregula 10 (RR) → rotação esq. → 25 (15 (10, 20), 30 (−, 50)).
  +40: desregula 30 (RL) → **25 (15 (10, 20), 40 (30, 50))**, árvore perfeita.
- Sequência de letras A, Z, B, Y, C, X, D, P, E, V, F (ex. 4 do livro), boa para treinar dupla rotação
  (zigue-zague).

### 0110-hashing

**Conceitos-chave**
- Busca sequencial O(n) e BST O(log n) comparam chaves. Hashing **calcula** o endereço a partir da chave
  e tem custo médio O(1).
- Duas etapas: escolher a função de dispersão e tratar colisões.
- Endereçamento direto (n = m e chaves 0..m−1) é o caso ideal raro.
- Hash não preserva ordem: listar em ordem exige outra estrutura.
- Usos citados: índices de bancos de dados e tabela de transposição em xadrez.

**Explicações boas**
- Arquivo de pastas por inicial do sobrenome (chave = sobrenome, endereço = inicial). Analogia intuitiva
  e já com colisões embutidas.
- `hashExemplo(chave) = chave[0] − 65`: função ruim de propósito, boa para discutir distribuição.

**Pegadinhas**
- Rodapé: "com 50 pessoas, **pelo menos duas** fazem aniversário no mesmo dia". Falso como certeza: a
  probabilidade é cerca de 97%. Com 23 pessoas já passa de 50%. A certeza só vem com 367 pessoas (casa dos
  pombos).
- `chave[0] − 65` dá negativo para minúsculas e dígitos, e índice negativo corrompe memória. Use
  `(unsigned char)` e `% m`.
- "Funções perfeitas só em criptografia" confunde hash criptográfico com hash perfeito. São conceitos
  diferentes.

**Ideias de exercícios**
- Probabilidade de colisão com 23 chaves em 365 posições. → ≈ **50,7%**. Programa em C que calcula
  1 − Π(365−i)/365.

### 0111-encadeamento
- **Conceitos-chave:** cada posição aponta para uma lista dos elementos que colidiram. Inserir/remover =
  operar na lista daquela posição. Trocar a lista por AVL baixa o pior caso por posição para O(log n).
- **Pegadinha:** o texto diz que a AVL melhora o "tempo médio" de O(n) para O(log n). Com boa função e
  fator de carga baixo o tempo médio já é O(1). A AVL melhora o **pior caso**.
- **Ideia de exercício:** m = 7, h(k) = k % 7, inserir 10, 17, 24, 3, 5 com encadeamento. → Posição 3:
  [10, 17, 24, 3] (inserindo no fim); posição 5: [5]. Discutir por que m primo e chaves "de 7 em 7" são
  um par ruim.

### 0112-enderecamento-aberto
- **Conceitos-chave:** sem estrutura auxiliar, o elemento que colide vai para outra posição da própria
  tabela segundo uma sequência de sondagem: linear, quadrática ou dispersão dupla.
- **Pegadinhas (erros do livro):**
  - Sondagem quadrática descrita como "posição 10, depois 100, 1000…". Errado: é h(k) + i² (h, h+1, h+4,
    h+9…) módulo m. 10, 100, 1000 nem é quadrático.
  - Dispersão dupla descrita como "aplicar uma nova função ao valor gerado pela anterior". Errado: a
    segunda função é aplicada à **chave** e dá o **passo**: (h₁(k) + i·h₂(k)) mod m, com h₂(k) ≠ 0.
  - Não fala de remoção. No endereçamento aberto é preciso marcar **lápide** (removido), senão buscas
    posteriores param cedo demais.
- **Ideia de exercício:** m = 11, h(k) = k % 11, sondagem linear, inserir 22, 1, 13, 11, 24, 33. → 22→0;
  1→1; 13→2; 11→0 ocupado → 1 → 2 → **3**; 24→2 → 3 → **4**; 33→0 → 1 → 2 → 3 → 4 → **5**. Mostra o
  agrupamento primário.

---

### NOVO: trie (árvore digital / busca digital)

**Conceitos-chave**
- Busca digital compara a chave **dígito a dígito** (caractere a caractere), não chave inteira contra
  chave inteira. Boa para chaves longas e de tamanho variável.
- Árvore digital m-ária: o j-ésimo filho corresponde ao j-ésimo símbolo do alfabeto e o caminho da raiz
  até um nó é um **prefixo** de alguma chave. Nó marcado (ponteiro para a informação, ou flag) indica fim
  de chave válida.
- Caso binário (alfabeto {0,1}): esquerda = 0 e direita = 1.
- Busca por prefixo sai de graça (autocompletar, linguística).
- Contexto: processamento de cadeias = casamento de padrões (achar P de tamanho m em T de tamanho n) +
  compressão.

**Explicações boas**
- Dicionário de papel: a primeira letra leva à "página" das palavras com aquela letra.
- Chaves binárias 00, 0010, 010, 010111, 010110, 00100, 11, 110, 1101: 010 é prefixo de 010110 e
  010111, e por isso o nó de 010 precisa de marca.

**Pegadinhas**
- O livro diz que a busca digital acha ocorrências "em O(log n) em relação ao tamanho do texto". Para
  trie de palavras o custo é **O(comprimento da chave)**, independente de n. O "O(log n)" não se sustenta.
- Trie com vetor de 26 filhos por nó gasta muita memória. Alternativas: lista de filhos ou árvore ternária.

**Ideia de exemplo:** trie de minúsculas em C (`struct no { struct no *filho[26]; bool fim; }`).

**Ideias de exercícios**
- Construa a trie binária de 00, 0000, 00010, 00011, 0101100, 0101101, 10, 101, 1010 (ex. do livro).
  Quantos nós marcados? → **9** (um por chave). Quais chaves são prefixo de outras? → 00 (de 0000, 00010,
  00011), 10 (de 101, 1010), 101 (de 1010).

### NOVO: listas autoajustáveis

**Conceitos-chave**
- Em estrutura autoajustável, a **busca também altera a forma** para acelerar buscas futuras dos itens
  mais procurados.
- Três políticas para lista: **mover para frente** (o acessado vai para a cabeça), **transposição**
  (troca com o anterior, sobe uma casa por acesso) e **contador de frequência** (campo extra; mantém a
  lista em ordem decrescente de acessos). Há também híbridos.
- Trade-offs: mover-para-frente reage rápido, mas um acesso raro joga lixo no topo. Transposição é
  conservadora. Contador gasta memória e mantém ordem.
- Em vetor, mover para frente custa O(n) de deslocamento. Na lista encadeada custa O(1) depois de achar.

**Ideia de exemplo:** simular as três políticas sobre os acessos A A B A C A A D A, contando comparações.

**Ideias de exercícios**
- Lista inicial [A, B, C, D], acessos D, D, D, A. Custo (comparações) com mover-para-frente vs.
  transposição. → MTF: D custa 4 → [D, A, B, C]; D custa 1; D custa 1; A custa 2. **Total 8**.
  Transposição: D custa 4 → [A, B, D, C]; D custa 3 → [A, D, B, C]; D custa 2 → [D, A, B, C]; A custa 2.
  **Total 11**.
- Que adaptação o TAD Lista precisa para virar autoajustável (ex. 2 do livro)? → `Busca` passa a receber
  `Lista *` (porque muda a cabeça). Com contador: campo `freq` no nó e reposicionamento após incrementar.

### NOVO: análise amortizada

**Conceitos-chave**
- O livro introduz o termo no contexto de autoajuste: quando uma operação muda a estrutura para o futuro,
  analisar o pior caso de **uma** operação isolada engana. A complexidade amortizada olha o custo
  **acumulado de uma sequência** de operações.
- Gancho no curso: vetor que dobra (0060, 0080) e tabela hash que dobra. Uma inserção ocasional custa
  O(n), mas n inserções custam O(n) no total, ou seja, O(1) amortizado.

**Ideias de exercícios**
- Vetor que começa com capacidade 1 e dobra quando enche: quantas cópias de elementos em 16 inserções?
  → 1 + 2 + 4 + 8 = **15** (< 2·16). Generalizando: < 2n, logo O(1) amortizado por inserção.

### NOVO: árvores gerais, recorrências, Huffman (só sementes)
- **Árvores gerais:** o livro só define (nº de filhos indefinido; grau). Completar com
  filho-esquerdo/irmão-direito, de outra fonte.
- **Recorrências:** o rodapé do cap. 1 manda contar chamadas × custo de cada uma. Exercício: busca
  binária recursiva → T(n) = T(n/2) + O(1) ⇒ **O(log n)**.
- **Huffman/compressão:** só citado como "representar o texto com menos bits". Sem algoritmo.

---

## Obsoleto / evitar

- **Todo o código do livro como modelo.** É pseudo-C não compilável, com blocos perdidos na extração.
  Lista de bugs aproveitáveis como "ache o erro":
  1. Cabeça de lista/pilha alterada dentro da função por valor (`l = novo`, `p = novo`, `l = l->prox`).
  2. `&` em vez de `&&` em `Anterior` (sem curto-circuito → desreferencia NULL).
  3. `Anterior` retorna `1` em vez do ponteiro.
  4. `Vazia` da pilha testa `topo == 0` com topo iniciado em −1.
  5. `incrementar` devolve `pos++` (valor antigo).
  6. Fila encadeada: `f->ini == NULL` onde deveria ser `f->fim = NULL` (ponteiro solto).
  7. `Busca` com `i <= tamanho` (lê além do fim); `Consulta` com `pos-1` (base inconsistente).
  8. `if (n = 0)` no `Maximo`; `if (no = NULL)` e `:=` na `Altura`.
  9. `printf(Conteudo(a))` sem formato.
  10. `main()` sem tipo e `Printf (Hello Word!\n")` no "Hello World" (maiúscula, aspas faltando).
- Funções que imprimem erro e fazem `return;` sem valor em função não-void (`Criar`).
- `Malloc` com maiúscula, `struct no dl`, `typedef no_PTR`, mistura de `next`/`prox` e `and`.
- Afirmações teóricas erradas: sondagem quadrática "10, 100, 1000"; dispersão dupla "hash do hash";
  `n log n` = "logarítmica"; FB sem módulo; inserção AVL como exceção ao O(log n); busca digital
  O(log n); paradoxo do aniversário como certeza; AVL melhorando o "tempo médio" do hash encadeado.
- Duas convenções de altura/nível no mesmo capítulo.
- TAD com estado global (Retângulo), apresentado como "objeto".

## Recomendações

1. **Usar para teoria de 0076/0077:** regras de contagem por estrutura de controle, os três casos, a
   definição formal com c e m, o teste do limite e os exercícios numéricos (10 000; ranking de 4 funções;
   c = 6). Corrigir "n log n = logarítmica".
2. **0079-tad:** reaproveitar a lista de entidades (Livro, Círculo, Conta…) como banco de exercícios e o
   Retângulo como contraexemplo de estado global, convertido para tipo opaco.
3. **Listas, pilhas e filas:** aproveitar as **justificativas de projeto** (topo no fim do vetor e na
   cabeça da lista; inserir no fim/remover no início; fila circular) e a interface com tipo `corrente`.
   Transformar os bugs 1, 4, 5 e 6 em exercícios "ache o erro" (o 6 é ótimo para valgrind/ASan no 0062).
4. **0102–0106:** usar o exemplo AVL 1, 4, 7, 9, 8, 12, 10 (correto e completo) e os exercícios de
   construção (BST 20, 5, 12, …; AVL 50, 20, 30, …; letras A, Z, B…), com os gabaritos acima. Fixar uma
   convenção de altura e corrigir FB com módulo.
5. **0103:** árvore de expressão (5 + 9)·(3 − 7) + 7 para os percursos, com o alerta de que em ordem sem
   parênteses muda o valor.
6. **Hash (0110–0112):** usar a analogia das pastas por inicial e o `hashExemplo` como função ruim. Não
   usar as descrições de sondagem quadrática e dupla (erradas) e acrescentar remoção com lápide (ausente).
7. **NOVOS sugeridos por esta fonte:** *trie* (com o exercício binário e o gabarito), *listas
   autoajustáveis* (MTF/transposição/contador, com o exercício de custo 8 vs 11) e *análise amortizada*
   (gancho do vetor que dobra). Huffman, casamento de padrões e árvores gerais aparecem só como menção:
   buscar em outras fontes.

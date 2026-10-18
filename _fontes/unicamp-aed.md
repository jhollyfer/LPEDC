# Fichamento — Algoritmos e Estruturas de Dados: conceitos e aplicações (Hélio Pedrini — Editora da Unicamp)

- **Autor:** Hélio Pedrini (IC/Unicamp).
- **Edição:** Editora da Unicamp, Campinas, 2024. ISBN 978-85-268-1626-8. Direitos reservados (não reproduzir texto).
- **Linguagem:** C.
- **Lido:** 525 linhas (integral do arquivo). **Atenção:** o arquivo é só uma **amostra de ~20 páginas**: ficha
  catalográfica, sumário completo, prefácio e o começo do cap. 1 (1.1 a 1.3, interrompido no meio da explicação do
  ligador). Nenhum código, exemplo ou exercício do livro está no arquivo.

## Avaliação geral

Livro recente (2024), em C, que cobre **todo** o arco do LPEDC num só volume: Parte I (fundamentos de C: variáveis,
E/S, operadores, condicionais, laços, vetores/matrizes, strings, funções e modificadores `auto/extern/register/static/
volatile`, ponteiros, enum/struct/union, arquivos), Parte II (recursão e **retrocesso** — n damas, passeio do cavalo,
labirinto, soma de subconjuntos —, análise assintótica com O, Ω, Θ, o, ω, listas de vários tipos, pilhas, filas e filas de
prioridade, ordenação incluindo shellsort e ordenação linear, hashing com vários métodos, árvores até AVL, rubro-negra,
splay e B/B*/B+, grafos até Kruskal, Prim, Dijkstra e Bellman-Ford) e Parte III (apêndices de matemática: piso/teto,
somatórios, logaritmos, bases, complemento de 2, IEEE 754, indução, ASCII/EBCDIC/Unicode). Estilo do trecho lido: denso,
definicional, pouco didático (sem analogias). Útil como **referência de escopo e de terminologia** e, se o volume completo
for obtido, como fonte para os módulos 10–16.

---

### 0001-algoritmo

**Conceitos-chave**
- Algoritmo: ações em ordem lógica, **sem ambiguidade**, independentes da máquina; programa: o algoritmo codificado numa
  linguagem e sujeito aos limites físicos do computador (memória, velocidade).
- Desenvolvimento em 10 etapas: entender o problema → entradas e saídas → passos da transformação → projetar algoritmos →
  projetar estruturas de dados → analisar → implementar → executar → avaliar resultados → documentar.

**Ideias de exercícios**
- Dado um enunciado (ex.: "média de N notas"), listar entradas, saídas e passos antes de codificar. Resposta esperada:
  entradas N e notas; saída a média; passos com acumulador e divisão no fim (tratar N = 0).

### 0002-pseudocodigo

**Conceitos-chave**
- Pseudocódigo: linguagem livre, para humanos, que omite detalhes de sintaxe. (Só a definição; sem convenção própria.)

### 0004-binario

**Conceitos-chave**
- Bit (contração de *binary digit*) = menor unidade; **palavra** = grupo de bits transferido entre memória e processador
  (8, 16, 32, 64); byte = 8 bits; célula típica = 8 bits, então palavra de 32 bits = 4 células.
- Endereço = identificador único de uma posição; **espaço de endereçamento** = total de endereços; com endereços de 32
  bits, 2³² = 4.294.967.296 bytes (4 GB).
- Tabela de unidades por potências de 2 (KB = 2¹⁰ = 1024 ... EB = 2⁶⁰).

**Pegadinhas**
- O livro usa KB/MB/GB como potências de 2; o padrão SI/IEC distingue kB = 1000 e KiB = 1024 (fabricantes de disco usam
  1000). Vale uma nota no 0004.
- "Palavra de 8 bits é chamada de byte" mistura palavra e byte; no curso, manter byte = 8 bits e palavra = tamanho natural
  do processador.

**Ideias de exercícios**
- Quantos bytes endereça um processador com endereços de 16 bits? **Resposta:** 2¹⁶ = 65.536 (64 KiB). E 64 bits?
  2⁶⁴ ≈ 1,8·10¹⁹ (16 EiB).

### 0005-compilacao

**Conceitos-chave**
- Cadeia completa: **pré-processador** (diretivas `#`: macros, inclusão, compilação condicional) → **compilador** (gera
  código de montagem; pode otimizar) → **montador** (código-objeto, resolve símbolos) → **ligador** (junta objetos e
  bibliotecas) → **carregador** → executável. Várias fontes viram vários objetos, ligados num executável.
- Fases do compilador: análise **léxica** (tokens; remove espaços e comentários), **sintática** (a sequência de tokens
  obedece à gramática?), **semântica** (tipos etc.), geração de código (depende da arquitetura).

**Explicações boas**
- A figura do fluxo "código-fonte 1..n → alterado → montagem → objeto → ligador → executável" é bom modelo para o diagrama
  do 0005 (com `gcc -E`, `-S`, `-c` e a ligação final).

**Pegadinhas**
- O texto afirma que erros semânticos "se manifestam em tempo de execução" e que o depurador ajuda a achar erros
  **sintáticos** — impreciso: erros de tipo são pegos na compilação; erros de lógica aparecem na execução; o depurador
  serve para estes últimos. Não reproduzir.

### 0049-memoria

**Conceitos-chave**
- Memória principal: cada posição tem endereço único; memória **lógica** (endereços que as instruções usam) × **física**
  (circuitos); endereços lógicos são traduzidos para físicos durante a execução — base para explicar por que `%p` mostra
  endereços "estranhos" e diferentes a cada execução.

### NOVO: organização básica do computador

**Conceitos-chave**
- Quatro blocos: unidade de processamento (ULA + unidade de controle), armazenamento (registradores, cache, memória
  principal, memória secundária — do mais rápido/caro ao mais lento/barato), E/S, e barramento (dados, endereços,
  controle). Dado da memória secundária precisa ir para a principal antes de ser usado.
- Sistema operacional como gerente de recursos e mediador entre programas e hardware.

**Ideias de exemplos**
- Pirâmide da hierarquia de memória com ordens de grandeza de tempo de acesso (registrador < cache < RAM < SSD/disco).

### NOVO: retrocesso (backtracking)

Só aparece no sumário (13.3: n damas, passeio do cavalo, labirinto, soma de subconjuntos; 13.2 enumeração exaustiva).
Não existe no sumário do LPEDC; candidato a assunto extra depois de 0038 ou como "juntando tudo" do módulo 04.

---

## Obsoleto / evitar

- Nada obsoleto no trecho (livro de 2024), exceto citar EBCDIC (só curiosidade histórica) e "C padronizada em 1989/1990"
  sem mencionar C99/C11/C17/C23 — o curso deve usar C11 ou C17.
- As duas afirmações imprecisas sobre erros semânticos/depurador (ver 0005).

## Recomendações

1. Usar o **sumário** como checagem de escopo dos módulos 10–16 (o livro inclui shellsort, ordenação linear, métodos de
   hashing — divisão, meio do quadrado, multiplicação, particionamento —, rubro-negra, splay, B-trees e Bellman-Ford, que o
   LPEDC não tem; decidir conscientemente o que fica fora).
2. Aproveitar a lista de **modificadores de armazenamento** (`auto`, `extern`, `register`, `static`, `volatile`) para
   o 0035 e os apêndices (complemento de 2, IEEE 754, ASCII/Unicode) para 0004/0008/0045.
3. O diagrama do pipeline de compilação serve para o 0005.
4. Se o curso quiser este livro como fonte de verdade para estruturas de dados, **obter o volume completo**: a amostra não
   tem nenhum código nem exercício.

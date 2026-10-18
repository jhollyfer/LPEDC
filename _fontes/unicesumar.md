# Fichamento — Algoritmos e Lógica de Programação II (Unicesumar)

- **Autora:** Gislaine Camila Lapasini Leal (revisão técnica: Rogério de Leon Pereira)
- **Editora/ano:** UniCesumar (NEAD), Maringá, reimpressão 2018, 203 p.
- **Lido:** 4437 linhas (texto integral, incluindo gabaritos das 5 unidades).

## Avaliação geral

Livro-texto de EaD que leva o aluno do "hello world" até funções e arquivos em C, em 5
unidades (I conceitos iniciais; II condicionais; III repetição; IV vetores, strings,
matrizes, structs; V funções, recursão, arquivos). Cada unidade tem atividades de
autoestudo **com gabarito** e "exercícios de fixação" resolvidos — o maior valor do
material para o LPEDC é esse banco de enunciados com cenário do cotidiano (plano de saúde
por faixa etária, classe eleitoral, carga de caminhão, calorias de prato e bebida,
fechamento de notas de turma, pesquisa de opinião).

O ponto fraco é sério: o C ensinado é de **Turbo C / C++ dos anos 90** (`main()` sem tipo,
`conio.h`, `clrscr`, `iostream.h`, `cin`, `gets`, `fflush(stdin)`, struct usada sem a
palavra `struct`, funções aninhadas). Os **gabaritos têm muitos bugs** (variável não
inicializada, `!=` no lugar de `=`, índice fora do vetor, enunciado e resposta trocados).
Isso, curiosamente, vira matéria-prima excelente para exercícios do tipo "ache o erro".
Use os enunciados; **nunca copie o código**.

---

### 0001-algoritmo

**Conceitos-chave**
- O livro já parte da disciplina anterior (Algoritmos I) e trata algoritmo como a
  sequência que vira programa. Usa sempre a decomposição **Entrada → Processamento →
  Saída** antes de codificar (ex.: ler nome, idade e altura; calcular ano de nascimento;
  mostrar tudo).
- Na unidade V retoma a ideia de **refinamento sucessivo / top-down**: quebrar um problema
  grande em subproblemas menores (gancho para funções).

**Ideias de exemplos**
- Tabelinha E/P/S preenchida para cada problema antes do código: "Entrada: nome, idade,
  altura | Processamento: ano = ano_atual − idade | Saída: os quatro dados".

**Ideias de exercícios**
- Para cada enunciado do módulo, pedir só a tabela E/P/S (sem código). Bom aquecimento.

### 0005-compilacao

**Conceitos-chave**
- Fluxo descrito: código-fonte (editor) → **compilador** gera código-objeto (linguagem de
  máquina) → **ligador** junta o objeto com as bibliotecas usadas → executável.
- Compilação é o momento em que a sintaxe é verificada.

**Pegadinhas e erros comuns**
- O livro não menciona o pré-processador como etapa (só o `#include` "inclui o conteúdo
  do arquivo stdio.h"). No LPEDC, explicitar as 4 etapas com `gcc -E`, `-c`, ligação.
- Atalhos de IDE (Alt+F9, Ctrl+F9 do Turbo C) são obsoletos; ensinar `gcc arquivo.c -o prog`.

### 0006-primeiro-programa

**Conceitos-chave**
- Todo programa tem uma função principal; o conteúdo entre chaves é executado em
  sequência; cada instrução termina com `;`; `return 0` sinaliza "terminou sem erro".
- `#include <stdio.h>` traz as declarações de entrada e saída.
- Comentários `/* ... */` podem ocupar várias linhas; a autora adota comentar tudo.
- Analogia boa: as chaves de `main` fazem o papel do "início" e "fim" do algoritmo.

**Pegadinhas e erros comuns**
- O livro escreve `main()` sem `int` e `return (0)` com parênteses — mostrar que o certo
  hoje é `int main(void)` e que os parênteses no `return` são opcionais.
- Comentário de bloco não fechado engole o resto do código (aparece no exercício "ache os
  erros" da unidade I: o `/*` da primeira linha nunca é fechado).
- O texto até grafa `stdhio.h` por engano: bom lembrete de que um erro de digitação no
  include quebra a compilação.

**Ideias de exercícios**
- **Ache os erros (reescrito do exercício 6 da unidade I)**: programa que lê dois inteiros
  e mostra a soma, com 5 defeitos plantados. Gabarito esperado: (1) comentário `/*` sem
  `*/`; (2) falta `;` após a declaração `int num1, num2, total`; (3) `scanf("%d", num1)`
  sem `&`; (4) falta `;` depois de `total = num1 + num2`; (5) `printf` usa a variável
  `soma`, que não existe (deveria ser `total`). Excelente exercício de compilação guiada.

### 0007-variaveis

**Conceitos-chave**
- Variável = espaço na memória principal que guarda valores diferentes ao longo do tempo;
  declarada como `tipo nome;`, várias do mesmo tipo na mesma linha.
- Regras de identificador: letras, dígitos e sublinha, começando por letra ou sublinha;
  evitar começar com `_` (reservado ao compilador). C diferencia maiúsculas: `A` ≠ `a`.
- Não existe tipo booleano no C ensinado (qualquer não-zero é verdadeiro) nem tipo string
  (usa-se vetor de `char`).

**Pegadinhas e erros comuns**
- Palavra reservada não pode ser identificador.
- A lista de palavras reservadas do livro mistura C++ e extensões do Turbo C (`class`,
  `template`, `far`, `huge`, `near`, `asm`, `interrupt`...). Não reaproveitar: usar a lista
  do padrão C.

**Ideias de exercícios**
- **Marque os identificadores inválidos** (gabarito do livro, conferido): inválidos =
  `media idade` (espaço), `2nome` (começa com dígito), `nome*r`, `012`, `media_peso%`,
  `endereco+cep`, `/fone`, `1234P`; válidos = `idade`, `x2`, `aluno_nota`, `A`.
- Tabela "válido/inválido" própria: `A`, `a`, `media`, `altura2`, `media_idade`, `x36`
  (válidos) vs `2a`, `b@`, `media idade`, `x*y`, `#media`, `idade!` (inválidos).

### 0008-tipos-e-limites

**Conceitos-chave**
- Modificadores `unsigned` (sem sinal: dobra a faixa positiva), `short` (reduz),
  `long` (aumenta). A faixa depende do compilador.

**Pegadinhas e erros comuns**
- A tabela do livro é de compilador 16 bits: `int` de 16 bits (−32.768 a 32.767) e ainda
  traz erro de digitação no máximo do `long` (2.147.489.647). Hoje `int` costuma ter 32
  bits. Ótimo gancho para ensinar `sizeof`, `limits.h` e `stdint.h` em vez de decorar
  tabela.
- Lista "sete tipos básicos" incluindo `enum` e `pointer` como se fossem tipos básicos —
  não seguir essa classificação.

### 0009-constantes

**Conceitos-chave**
- `#define NOME valor`, sem `;` no final.
- Caracteres entre apóstrofos (`'M'`), cadeias entre aspas (`"Maria"`).
- Sequências especiais de saída: `\n`, `\t`, `\b`, `\"`, `\\`, `\0`, `\f`.

**Pegadinhas e erros comuns**
- `#define pi 3.141593` em minúsculas no gabarito: convenção é maiúsculas.
- Pôr `;` no `#define` faz o `;` ser colado onde a constante for usada.

### 0010-printf

**Conceitos-chave**
- `printf("controle", argumentos)`: o texto de controle mistura mensagem e
  especificadores. Mostra a diferença entre imprimir tudo grudado e usar `\n`.
- `%f` mostra 6 casas por padrão; `%.2f` limita a duas (exemplo: altura).

**Ideias de exemplos**
- Mesmo programa impresso duas vezes: com `%f` (1.750000) e com `%.2f` (1.75).
- Três `printf` sem `\n` saindo numa linha só, depois com `\n`.

### 0011-scanf

**Conceitos-chave**
- `scanf("%d", &idade)`: as variáveis vão precedidas de `&` (o endereço); para string não
  se usa `&` porque o nome do vetor já é endereço.
- Tabela de especificadores de leitura: `%c %d %i %u %e %f %g %o %s %x %p`.

**Pegadinhas e erros comuns**
- O livro lista `cin`, `gets` e um `scanf(&x)` (sem formato!) como entradas válidas —
  `cin` é C++, `gets` foi removido do C, e `scanf(&x)` não compila.
- O gabarito usa `scanf("%s", &nome)` com `&` num vetor (tipo errado; funciona por acaso).
- `scanf("%s")` para no primeiro espaço; o livro "resolve" com `fflush(stdin)` + `gets`,
  ambos a evitar (comportamento indefinido / função removida). Ensinar `fgets`.
- Ler `%c` depois de um `%d` pega o `\n` que sobrou no buffer (o exercício do peso ideal
  lê o sexo primeiro justamente por isso, sem explicar). Bom caso para "sobra no buffer".

### 0012-aritmetica

**Conceitos-chave**
- Operadores `+ - * / %`; expressão aritmética como fórmula matemática.
- `%` dá o resto: com A=3 e B=2, A%B = 1. Divisão por zero não existe.

**Pegadinhas e erros comuns**
- A tabela de precedência do livro está errada (põe `*`, `/` e `%` em níveis diferentes e
  diz que atribuição associa à esquerda). Não reaproveitar.
- **Divisão inteira** escondida no gabarito: `media = soma / quantidade` com dois `int`
  descarta os decimais mesmo guardando em `float`. O exercício da série harmônica acerta
  ao usar `float divisor = i; 1/divisor` — contraste perfeito para a aula.

**Ideias de exercícios** (com resposta)
- Antecessor e sucessor de um inteiro (fixação 1): para 10 → 9 e 11. Duas versões:
  com variáveis `ant`/`suc` e calculando direto no `printf`.
- Média de 4 notas com 2 casas (8, 7, 6, 9 → 7.50).
- Rendimento de depósito: depósito 1000, taxa 5 (%) → rendimento 50.00, total 1050.00
  (fórmula `deposito * taxa/100`).
- Área do trapézio: bases 10 e 6, altura 4 → 32.00.

### 0014-atribuicao

**Conceitos-chave**
- `=` atribui: o lado esquerdo é a variável, o direito uma expressão (`x = x + 5`).
- Abreviações `+= -= *= /= %=` e a tabela clara de `++`/`--`: `y = ++x` incrementa
  primeiro e depois copia; `y = x++` copia primeiro e incrementa depois.

**Pegadinhas e erros comuns**
- O livro mostra `nome = "Maria";` como atribuição a string — **isso não compila em C**
  para vetor de `char`. Ótimo para a seção de pegadinhas (usar `strcpy`).

**Ideias de exercícios**
- Tabela de rastreio: x=5; y=x++; z=++x; → y=5, x=7, z=7.

### 0015-math

**Conceitos-chave**
- Funções prontas: `ceil` (arredonda para cima, 2.3→3), `floor` (para baixo, 2.3→2),
  `pow`, `sqrt`, `log`, `log10`, `exp`, `sin/cos/tan`, `modf`.

**Pegadinhas e erros comuns**
- O livro coloca `abs` em math.h (é `stdlib.h`; em math.h existe `fabs`) e apresenta
  `M_PI` como padrão (não é garantido pelo C padrão). Não menciona o `-lm` do gcc.
- Descreve `modf` com os papéis invertidos (diz que y recebe a parte fracionária e z a
  inteira; é o contrário: o retorno é a fração e o ponteiro recebe a parte inteira).
- O gabarito do exercício "quadrado e raiz" imprime a raiz com o rótulo "A potencia de".

**Ideias de exercícios** (com resposta)
- Quadrado e raiz de um inteiro positivo: 16 → 256.00 e 4.00.
- Raio → área e perímetro: r=2 → área ≈ 12.566371, perímetro ≈ 12.566371 (bom caso
  curioso: para r=2 os dois valores coincidem).
- `pow(num1, num2)`: 2 e 10 → 1024.00.

### 0016-juntando-tudo

- Programa-modelo do livro: ler nome, idade e altura; calcular ano de nascimento
  (ano atual − idade); imprimir tudo com altura em `%.2f`. Atualizar o ano (o livro usa
  2012 fixo — pegadinha de "número mágico"; usar constante ou ler o ano).

---

### 0017-relacionais

**Conceitos-chave**
- Operadores `== != > < >= <=`; condição é comparação com só dois resultados possíveis.
- Em C não há booleano: zero é falso, qualquer outro valor é verdadeiro.

### 0018-logicos

**Conceitos-chave**
- `&&` só é verdadeiro se ambos forem; `||` se pelo menos um for; `!` inverte.

**Ideias de exercícios** (com resposta)
- **Classe eleitoral** (fixação 3): idade < 16 → não eleitor; 16–17 ou > 65 → facultativo;
  18–65 → obrigatório. Teste: 15, 16, 17, 18, 65, 66 → não, fac., fac., obrig., obrig.,
  fac. Usa `||` de forma natural.
- **Divisível por 3 E por 7** (atividade 2): o gabarito testa as duas divisibilidades
  separadamente (imprime "divisível por 3" e/ou "por 7"). Reescrever pedindo o "e" de
  verdade: 21 → sim; 9 → não; 14 → não; 42 → sim.

### 0019-if

**Conceitos-chave**
- Se a condição é verdadeira, executa o bloco entre chaves; senão pula para depois dele.
- Chaves obrigatórias quando há mais de um comando.

**Ideias de exemplos**
- Ler inteiro; se for par, mostrar a raiz com 3 casas: 18 → 4.243; 15 → nada.

### 0020-if-else

**Conceitos-chave**
- Uma única expressão, dois caminhos mutuamente exclusivos.

**Ideias de exemplos**
- Par → raiz; ímpar → quadrado: 16 → par, raiz 4.000; 15 → ímpar, quadrado 225.
- Divisível por 5 (fixação 1): 25 → sim; 12 → não.
- **Peso ideal** (fixação 4): homem `72.7*h − 58`, mulher `62.1*h − 44.7`. Testes:
  homem 1.80 → 72.86; mulher 1.60 → 54.66. Aceitar 'F' ou 'f' com `||`.

**Pegadinhas e erros comuns**
- `if (op = 1)` no lugar de `==` (o livro não destaca; acrescentar).

### 0021-else-if

**Conceitos-chave**
- Ifs aninhados ("se não, se...") para várias faixas. Um mesmo problema pode ser resolvido
  com ifs independentes, ifs aninhados ou switch; a diferença é **eficiência** (quantos
  testes são feitos) e **clareza**.
- Analogia boa da autora: com ifs soltos, mesmo depois de achar a operação certa o
  programa continua perguntando as outras; com if/else ou switch ele para de testar.

**Ideias de exercícios** (com resposta)
- **Plano de saúde por idade** (fixação 2): até 18 → R$ 50; 19–29 → 70; 30–45 → 90;
  46–65 → 130; acima de 65 → 170. Testes de fronteira: 18, 19, 29, 30, 45, 46, 65, 66.
  O gabarito repete nome/idade em todos os ramos — bom para refatorar (imprimir uma vez,
  só o valor muda).
- Maior e menor de 5 números (atividade 1): o gabarito usa vetor e laço antes de esses
  conteúdos aparecerem. Reescrever só com ifs (ou adiar para o módulo de laços).

### 0023-switch

**Conceitos-chave**
- Compara uma variável inteira/caractere com constantes; `break` impede de cair nos casos
  seguintes; `default` trata o "nenhum dos anteriores". Indicado para menus e situações
  mutuamente exclusivas com poucos valores discretos.
- Quadro-resumo útil: `if` quando há um bloco opcional; `if/else` para dois caminhos
  exclusivos; `switch` para muitos valores discretos e finitos.

**Ideias de exercícios** (com resposta)
- Calculadora de 4 operações com menu 1–4 (exemplo do livro) + versão com if/else.
- Número → nome do mês (atividade 3), com "mês inválido" no default: 13 → inválido.
- **Aumento por cargo** (atividade 4): 1 servente 40%, 2 pedreiro 35%, 3 mestre de obras
  20%, 4 técnico de segurança 10%. Salário 1000, cargo 2 → aumento 350.00, novo 1350.00.
- **Calorias** (fixação 5): prato (italiano 750, japonês 324, salvadorenho 545) + bebida
  (chá 30, suco 80, refrigerante 90) com dois switches acumulando num total. Italiano +
  suco → 830.

### 0024-juntando-tudo

- **Carga de caminhão** (atividade 5): código do estado → % de imposto (1:20, 2:15, 3:10,
  4:5); código da carga → preço/kg (10–20: 180; 21–30: 120; 31–40: 230); peso em
  toneladas. Saídas: peso em kg, preço, imposto, total. Exemplo: estado 2, 3 t, carga 25 →
  3000 kg, preço 360000.00, imposto 54000.00, total 414000.00. O gabarito repete o bloco
  inteiro 4 vezes dentro do switch — perfeito para mostrar que basta o switch escolher o
  percentual e um if/else escolher o preço.

---

### 0025-while

**Conceitos-chave**
- Laço condicional com teste **no início**: pode não executar nenhuma vez.
- A variável de controle precisa ser inicializada **antes** e alterada **dentro**; sem
  isso, laço infinito.

**Pegadinhas e erros comuns**
- `i = 0; while (i != 10)` imprime 10 vezes; começar em 1 com a mesma condição imprime só
  9 — o livro explora isso bem (para começar em 1, condição `i != 11`). Preferir `<`.
- **Leitura antes e dentro do laço** (padrão "leitura-prévia"): se esquecer a leitura de
  dentro, a condição nunca muda → laço infinito.

### 0026-do-while

**Conceitos-chave**
- Teste no fim: o corpo roda pelo menos uma vez.

**Pegadinhas e erros comuns**
- **Ótimo contraste do livro:** contar pares e ímpares até digitar 0. Com while e
  leitura-prévia, o 0 não é contado; com do-while ingênuo, o **0 é contado como par**
  (resultado errado: uma unidade a mais em pares). Precisa de um `if (num != 0)` interno.
- No fechamento de notas com do-while, também é preciso um `if (cod != 0)` para não pedir
  notas do aluno "0".

**Ideias de exercícios**
- **Validação de entrada** (fixação 6): repetir a leitura da opinião enquanto não for 1, 2
  ou 3 (`while (op != 1 && op != 2 && op != 3)`). Uso canônico do do-while.

### 0027-for

**Conceitos-chave**
- Laço contado: inicialização (uma vez), condição (antes de cada volta), atualização (fim
  de cada volta). Usar quando se sabe quantas repetições.
- Sem chaves, o corpo é só o próximo comando.
- Todo for pode ser reescrito como while/do-while e vice-versa.

**Pegadinhas e erros comuns**
- Condição escrita como `i == 10` com `i` começando em 1: o laço **nunca executa** — a
  condição é "continue enquanto", não "pare quando". O livro sugere testar isso: aproveitar.

**Ideias de exercícios** (com resposta)
- Imprimir um nome 10 vezes (exemplo base, refeito com while e do-while).
- Múltiplos de 3 menores que 100 com passo 3 (`i = i + 3`): 3, 6, ..., 99 (33 números).
- Fatorial (fixação 1): 5 → 120. Discutir limite do `int` (13! estoura 32 bits).
- Soma dos ímpares entre 200 e 500: **52500** (são 150 ímpares). O gabarito esquece de
  zerar `soma` — usar como "ache o erro".
- Números < 30 divisíveis por 3 e por 7 (atividade 5): com "e" verdadeiro → só 21.
- **Série harmônica** (atividade 2): S = 1 + 1/2 + ... + 1/n; n=4 → 2.083333.

### 0028-break-continue

- Não aborda break/continue em laços (só o break do switch). Sem material aqui.

### 0029-lacos-aninhados

**Conceitos-chave**
- "Encadeamento" de laços: a estrutura interna tem de estar inteira dentro da externa.

**Ideias de exercícios** (com resposta)
- Tabuada de 1 a 10 com dois for (atividade 3).
- **Fechamento de notas** (problema 2): ler o número de notas da disciplina; para cada
  aluno (até código 0) ler as notas com um for interno, calcular a média e contar
  aprovados (média ≥ 6) e reprovados. Ex.: 2 notas; aluno 1: 7 e 8 (aprova); aluno 2: 4 e
  5 (reprova); código 0 → 1 aprovado, 1 reprovado. Feito com do-while+for e while+for.

### 0030-padroes-de-laco

**Conceitos-chave** (o livro usa todos, sem nomeá-los — nomear no LPEDC)
- **Contador** (`par++`), **acumulador** (`soma = soma + nota`), **sentinela** (0 ou −1
  encerra), **maior** (`if (salario > msalario)`), **flag** (`acha = 0/1`).

**Pegadinhas e erros comuns** (todas tiradas dos gabaritos)
- Acumulador sem zerar (soma dos ímpares).
- Maior inicializado com 0: falha se todos os valores forem negativos.
- `menor != 0;` escrito no lugar de `menor = 0;` (compara e descarta — o compilador
  aceita!). E mesmo `menor = 0` estaria errado: o certo é iniciar com o primeiro valor lido.
- Teste de ímpar com `numero % 2 == 1` falha para negativos (−3 % 2 == −1). Usar `!= 0`.
- Sentinela lida junto com outro dado: no exercício do salário −1 o programa ainda pede o
  número de filhos depois de digitar −1.
- Média de grupo vazio: se a primeira entrada for o sentinela, divide por zero.
- `strcmp(comodo, "FIM")` testado antes de `comodo` receber valor (lixo na memória).

**Ideias de exercícios** (com resposta)
- **Prefeitura** (fixação 4): salário e nº de filhos até salário −1; média salarial, média
  de filhos e maior salário. Entradas (1000,2), (3000,0), (2000,1), −1 → médias 2000.00 e
  1.00; maior 3000.00.
- **Idade e altura** até idade 0 → médias (fixação 5).
- **Pesquisa de opinião** (fixação 6): idade e opinião (1 satisfeito, 2 indiferente,
  3 insatisfeito) até idade 0; contar satisfeitos, média de idade deles, contar
  insatisfeitos.
- **Área da casa** (atividade 9): nome do cômodo, largura, comprimento até "FIM"; somar
  áreas. Sala 4×5, cozinha 3×3, FIM → 29 m².
- Pedidos até número 0 (atividade 7): total = Σ preço × quantidade.
- Estado civil de várias pessoas com contadores por categoria via switch (atividade 8).
- **Primo** (fixação 3): contar divisores de 1 a n; primo se tiver exatamente 2.
  7 → primo; 9 → não. (Discutir que dá para parar antes / testar só até √n.)

---

### 0033-funcoes / 0034-parametros / 0035-escopo / 0037-recursao (resumo)

**Conceitos-chave**
- Função = sub-rotina para uma tarefa específica; `tipo nome(parâmetros) { corpo }`;
  `return` encerra e devolve valor compatível com o tipo; `void` = não devolve.
- Parâmetros **formais** (na definição) × **reais** (na chamada); por valor a função
  recebe cópia.
- Locais morrem ao fim da função; globais vivem o programa todo e devem ser evitadas.
- Protótipo permite escrever a função depois do `main`.
- Recursão exige critério de parada; exemplos fatorial e Fibonacci recursivo.

**Pegadinhas e erros comuns**
- O texto diz que, por referência, x passou de 5 para **25** ao dobrar — o correto é 10
  (erro do livro; ótimo para "confira o livro").
- Gabaritos declaram funções **dentro** do `main` (extensão do GCC, não é C padrão).
- Conversão kg → libras com fator 2.68 (o certo é ≈ 2,2046).
- Enunciado pede "1 se consoante, 0 se vogal" e o gabarito devolve o contrário.
- Fibonacci recursivo apresentado sem falar do custo exponencial (gancho para 0038).

**Ideias de exercícios**
- Celsius → Fahrenheit (`c*1.8 + 32`): 100 → 212.00. Positivo/negativo/zero. Soma dos
  inteiros entre dois números. Somatório dos N primeiros pares (N=4 → 2+4+6+8 = 20).
  Contar vogais/consoantes de um nome. Reais → dólares dada a cotação.

### 0042-vetores / 0044-matrizes / 0046-strings / 0064-struct (resumo)

**Conceitos-chave**
- Vetor: elementos do mesmo tipo em sequência, índice de 0 a tamanho−1; **o compilador
  não confere limites** (o livro mostra de propósito um laço até 15 num vetor de 10).
- Matriz: um laço por dimensão. String: vetor de `char` terminado em `'\0'`, declarar com
  uma posição a mais. Struct agrupa campos de tipos diferentes, acesso com `.`.

**Pegadinhas e erros comuns**
- Gabarito percorre `vetor[3]` com índices 1..3 (escreve fora do vetor).
- Imprimir palavra de trás para frente começando em `strlen` imprime o `'\0'` primeiro.
- Funções `strlwr`, `strupr`, `strlcpy`, `stricmp` não são padrão.
- `strstr(...) == 0` testado ao contrário no exemplo.
- `produto ficha;` sem `struct` só compila em C++ (em C, `struct produto ficha;` ou typedef).

**Ideias de exercícios**
- Ler 30 números e imprimir na ordem inversa; soma de dois vetores; tabela de notas 20×4
  com média por aluno e da turma; cadastro de livros/funcionários com busca por código.

### 0072-arquivos-texto (resumo)

- `FILE *`, `fopen` (modos r, w, a, r+, w+, a+), checar `NULL`, `fputc/fgetc`,
  `fputs/fgets`, `fclose`, `feof`, `rewind`, `remove`, `rename`.
- Pegadinha: laço `while (!feof(arq))` lê uma vez a mais; o gabarito do exercício 7 usa o
  padrão certo `while (fgets(...) != NULL)` — contrastar os dois.

### 0094-busca-sequencial / 0096-bubble-sort (resumo)

- Busca sequencial com flag `acha` e `while (acha == 0 && i < 10)`.
- O "método da bolha" apresentado compara `v[i]` com todos os `v[j]` seguintes — isso é
  **ordenação por troca/seleção ingênua**, não a bolha (que compara vizinhos). Pegadinha
  de nomenclatura a corrigir no módulo 13.

---

## Obsoleto / evitar

- Turbo C, Dev-C++ antigo, atalhos Alt+F9/Ctrl+F9.
- `main()` sem tipo; `void main()`.
- `conio.h`, `clrscr()`, `getch()`, `system("pause")`.
- `iostream.h`, `cin >>`, `using namespace std` (C++ dentro de "programa em C").
- `gets()` (removida no C11) e `fflush(stdin)` (comportamento indefinido).
- Tabela de tipos de 16 bits; lista de palavras reservadas do Turbo C++.
- Atribuir string com `=` fora da declaração.
- Funções aninhadas; `struct` sem a palavra-chave em C.
- Caminho fixo `C:\\arquivo.txt`.

## Extras que não cabem no sumário

- Comparação de eficiência entre if solto × if/else × switch contando comparações — pode
  virar um "box" em 0023 ou preparar 0076 (contar passos).
- Problema do cadastro de 20 livros com menu (cadastrar, listar, buscar, ordenar por ano):
  bom "juntando tudo" para o módulo 08 (vetor de structs) ou 13.
- `setlocale(LC_ALL, "Portuguese")` aparece nos gabaritos para acentuação no Windows —
  pode virar nota de rodapé sobre acentos no terminal.

# Fichamento — Lógica de Programação (IFES / e-Tec Brasil)

- **Autor:** Victorio Albani de Carvalho
- **Edição:** IFES / CEAD Colatina, e-Tec Brasil, 2010, 104 p. (Curso Técnico em Informática)
- **Lido:** 2951 linhas (texto integral).

## Avaliação geral

O melhor dos três materiais para os módulos **00 a 03**. Aulas 1–4 são lógica pura em
**Portugol** (algoritmos do cotidiano, variáveis, tipos, constantes, atribuição com seta,
leia/escreva, operadores, tabelas-verdade, precedência, `se...então...senão`,
`para...faça`, `enquanto...faça`); aulas 5–8 fazem a ponte para C (Dev-C++, printf,
scanf, if/else, switch, for, while, do-while, vetores e strings). A progressão da
**troca de lâmpada** (sequência → decisão → repetição) é o achado didático mais valioso de
todo o conjunto. Tom acolhedor, frases curtas, "papel e lápis são os melhores amigos do
programador".

Limitações: muitos algoritmos em Portugol e todos os programas das aulas 5–8 estão em
**figuras** que não vieram no texto (só a explicação linha a linha sobreviveu). Não há
gabarito. Não trata fluxograma, binário, break/continue, funções. Ferramentas e alguns
conselhos de C estão datados (Dev-C++, `system("PAUSE")`, `gets`). Para os exercícios
abaixo, as respostas foram calculadas por mim.

---

### 0001-algoritmo

**Conceitos-chave**
- Lógica como "arte de pensar corretamente", colocar ordem no pensamento. Começa com
  deduções do dia a dia: o livro está no armário, o armário está fechado → preciso abrir o
  armário; sou mais velho que João, João é mais velho que José → sou mais velho que José.
- Lógica de programação = técnicas para encadear pensamentos rumo a um objetivo.
- Algoritmo = sequência **finita** de passos que executa uma tarefa; como uma receita.
- Um mesmo problema admite **várias soluções**; algumas ordens de passos podem ser
  trocadas sem prejuízo (pegar a lâmpada antes ou depois da escada), outras não.

**Analogias/explicações boas (parafraseadas)**
- **Trocar uma lâmpada — a progressão em três atos** (usar como fio condutor do módulo 00):
  1. *Sequência pura:* pegar escada, posicionar, pegar lâmpada nova, subir, tirar a velha,
     colocar a nova. Funciona, mas troca a lâmpada mesmo se ela estiver boa.
  2. *Com decisão:* ligar o interruptor; **se** a lâmpada não acender, executar os passos.
     Agora só troca quando precisa.
  3. *Com repetição:* e se a lâmpada nova também estiver queimada? Encadear "se não
     acender, troque de novo; se ainda não acender..." não tem fim — "até quando ficaremos
     nesses testes?". Solução: **enquanto** a lâmpada não acender, retire e coloque outra.
  Mostra por que existem as três estruturas (sequencial, seleção, repetição) a partir de
  um único problema. Também ilustra **abstração**: o algoritmo ignora descer e subir a
  escada a cada nova lâmpada.

**Pegadinhas e erros comuns**
- Esquecer o teste antes de agir (trocar lâmpada boa).
- Repetição "na mão" com ifs encadeados em vez de laço.
- Passos ambíguos ou que dependem de algo ainda não feito (subir antes de posicionar a
  escada).

**Ideias de exemplos**
- Bolo, ovo frito, troca de pneu (descrição livre).
- Fazer uma prova: enquanto houver questão em branco **e** houver tempo; se souber,
  resolve, senão pula para a próxima.

**Ideias de exercícios**
- **Dedução** (Ativ. 1.1): todos os filhos de João são mais altos que Maria; Antônio é
  filho de João → *Antônio é mais alto que Maria*.
- **Dedução** (Ativ. 1.2): aprovação exige nota ≥ 60 **e** frequência > 75%; José teve 80
  e 100% → *José foi aprovado*. (Prepara o operador E.)
- Algoritmo da prova (Ativ. 1, aula 1), com as duas condições do laço e a decisão interna.
- **Separar bolas** (Ativ. 2): caixa 1 com bolas azuis e vermelhas; enquanto a caixa 1
  tiver bolas, pegue uma; se azul, caixa 2, senão caixa 3. Resposta esperada: um laço com
  um se/senão dentro.
- **Reajuste salarial** (Ativ. 3): para cada funcionário da lista, se salário < 1000,
  aumento de 10%, senão 8%. Ex.: 900 → 990; 1000 → 1080; 2000 → 2160 (atenção ao caso
  exatamente 1000, que recebe 8%).
- **Missionários e canibais** (Ativ. 4): 3 e 3, bote para 1 ou 2, nunca menos missionários
  que canibais numa margem com missionários. Uma solução em 11 travessias (M=missionário,
  C=canibal, → ida, ← volta): →CC, ←C, →CC, ←C, →MM, ←MC, →MM, ←C, →CC, ←C, →CC.
  Desafio opcional ótimo para mostrar que algoritmo também é "planejar estados".

### 0002-pseudocodigo

**Conceitos-chave**
- Computador não entende linguagem natural: precisamos de uma linguagem formal. O Portugol
  une o formalismo das linguagens de programação à facilidade do português, mas não é
  compilado.
- **Memória:** todo programa e seus dados precisam estar na memória; declarar variável é
  pedir ao computador que reserve um pedaço dela, com **nome** (para nos referirmos a ele)
  e **tipo** (para saber quanto espaço reservar).
- Estrutura do algoritmo: `algoritmo nome` / `const` (opcional) / `var` / `inicio` ... `fim`.
- Declaração: `var nome : tipo` (vários nomes separados por vírgula). Tipos: **inteiro**,
  **real**, **caractere** (um símbolo, ex. 'F'), **cadeia** (texto), **lógico** (V/F).
- Constante: `const NOME ← valor`, em maiúsculas por convenção (ex.: taxa de FGTS 8%).
- Atribuição com seta `←` (`identificador ← expressão`); entrada `leia(variavel)`;
  saída `escreva("texto", variavel)`.
- Comentários `/* */` e `//`. **Endentação** para mostrar o que está dentro de cada bloco.
- Regras de nome: começar por letra, sem espaço, hífen ou símbolos; usar `_`; nomes
  sugestivos (salário → `salario`).
- Operadores aritméticos `+ - * / %` e precedência: primeiro `* / %`, depois `+ -`;
  parênteses resolvem do mais interno para o mais externo; só parênteses (não colchetes
  nem chaves) em expressões.

**Analogias/explicações boas**
- Comparação lado a lado Portugol × C, linha a linha, do algoritmo "multiplicação" (ler
  dois inteiros, multiplicar, mostrar). Ótimo para a transição do módulo 00 para o 01.
- Dica: testar parênteses numa planilha (Excel) — boa ferramenta de conferência.
- "Guarde esses algoritmos, você vai usá-los depois": reaproveitar em vez de reinventar.

**Pegadinhas e erros comuns**
- Tipo errado para o dado: idade como real, altura 1.80 como inteiro, nota 7.5 como inteiro.
- Confundir caractere ('F') com cadeia ("Jose").
- Atribuir valor de tipo diferente (`inteiro ALTURA ← 1.80`).
- No exemplo do livro, peso foi declarado inteiro — discutir se faz sentido.

**Ideias de exercícios** (respostas calculadas)
- **Nomes válidos** (Ativ. 2.1): válidos `nome`, `telefone_celular`, `conta1`; inválidos
  `telefone-celular`, `nome+sobrenome`, `2taxa`.
- **Valor × tipo** (Ativ. 2.2): corretos a (2.5 real), c (−2 inteiro), d ('M' caractere),
  f (−10.35 real), h ('Jose' cadeia — com a ressalva das aspas), i (135 inteiro); errados
  b ('F' inteiro), e (5 cadeia), g (38 real — aceitável, mas não ideal), j (7.5 inteiro).
- Declarar notas inteiras 0–10 e média real com nomes sugestivos (Ativ. 2.3):
  `var nota1, nota2 : inteiro; media : real`.
- Algoritmo nome e idade → "Seu nome é Pedro" / "Você tem 32 anos" (Ativ. 2.6).
- **Expressões com A=2, B=5, C=10** (Ativ. 1 da aula 2), lembrando divisão inteira:
  a) `A+B*C/A` = 2 + 50/2 = **27**;
  b) `B+C%A*(B-A/2)` = 5 + 0×4 = **5**;
  c) `(B+C)%2+A*(B+(C*4))` = 1 + 2×45 = **91**.
- Antecessor e sucessor; soma e média de dois reais; hipotenusa e área do triângulo
  retângulo (catetos 3 e 4 → 5 e 6).
- Completar lacunas de algoritmo (média de duas notas; aumento de 8% sobre o salário).
- **Teste de mesa** (o livro não usa o termo, mas a explicação "linha 1... linha 11" do
  algoritmo de multiplicação é exatamente isso): pedir a tabela de valores das variáveis
  linha a linha para num1=3, num2=4.

### 0005-compilacao

**Conceitos-chave**
- Linguagem de programação = forma padronizada de dar instruções ao computador.
- **Compilador** traduz o programa da linguagem para linguagem de máquina; o arquivo que
  escrevemos é a **fonte**.
- Mensagens de erro de compilação apontam linha e motivo; ler com atenção. Exemplo do livro:
  variável declarada `mult` e usada como `Mult` → "'Mult' undeclared (first use in this
  function)".

**Pegadinhas e erros comuns**
- Maiúscula/minúscula em nome de variável gera "undeclared".
- Salvar com extensão errada (.cpp em vez de .c) muda o compilador usado no Dev-C++.

**Ideias de exercícios**
- Dar o programa com `Mult` e pedir para interpretar a mensagem do gcc e corrigir.

### 0006-primeiro-programa

**Conceitos-chave**
- Explicação linha a linha do programa de multiplicação: `#include`, `int main()`, chaves
  abrindo e fechando bloco, declaração, `printf`, `scanf`, atribuição, `return 0`.
- "Toda instrução em C termina com ponto e vírgula"; C diferencia maiúsculas; comandos são
  todos minúsculos; por padrão, nomes de variáveis em minúsculas.
- Comentários de linha `//` e de bloco `/* */`; não aparecem na execução.

**Ideias de exercícios**
- **V ou F** (Ativ. 5.2): (a) toda instrução termina com `;` → V (com a ressalva de
  diretivas e blocos); (b) C não diferencia maiúsculas → F; (c) todo programa tem `main`,
  a primeira função executada → V.

### 0007-variaveis

**Conceitos-chave**
- Em C escreve-se o tipo antes do nome; não há a palavra `var`.
- Tamanhos em arquitetura de 32 bits: `char` 1 byte, `int` 4, `float` 4. Tipo define o que
  cabe e quanto espaço é reservado.
- Pode-se declarar e atribuir na mesma linha (`float salario = 552.35;`).
- **Variável não inicializada contém lixo**: ao declarar, a memória não vem limpa; por
  isso o acumulador `soma` começa em 0 (explicação muito clara na aula 7).

**Pegadinhas e erros comuns**
- **Separador decimal é o ponto**: 552,35 vira `552.35` (vírgula é erro clássico de
  brasileiro).
- `char` usa aspas simples.

### 0010-printf / 0011-scanf

**Conceitos-chave**
- `printf` ≈ `escreva`; `scanf` ≈ `leia`. Códigos `%c %f %s %d` em ambos.
- `scanf("%d", &num1)` guarda no **endereço** da variável.
- `%.2f` para duas casas.

**Pegadinhas e erros comuns**
- Esquecer `\n` junta as mensagens numa linha.
- Para string o livro manda usar `gets` — substituir por `fgets` no LPEDC.

### 0012-aritmetica / 0014-atribuicao

**Conceitos-chave**
- Mesmos operadores do Portugol mais `++` e `--`; precedência igual à da matemática.
- `=` em C é atribuição (era `←`).
- Conselho do autor: usar `++`/`--` só sozinhos numa linha, nunca no meio de expressões,
  porque prejudica a leitura. Boa regra de estilo para iniciantes.

### 0017-relacionais

**Conceitos-chave**
- Relação = comparação com operador relacional; o resultado é sempre V ou F.
- Em Portugol igualdade é `=`; em C é `==`, para não confundir com a atribuição `=`.

**Ideias de exemplos**
- Quadro com A=5 e B=8: A=B F; A<B V; A>=B F; B≠6 V; A>=5 V.

**Ideias de exercícios** (com num1=10, num2=2, num3=200, num4=200; respostas calculadas)
- Ativ. 3.1: a) 10>2 **V**; b) 10<200 **V**; c) 10<200 **V**; d) 200=200 **V**.
- Ativ. 3.2: a) 12>200 **F**; b) 20<200 **V**; c) 0≠200 **V**; d) 200/10=20<200 **V**.

### 0018-logicos

**Conceitos-chave**
- Operadores lógicos E, OU, NÃO ("conectivos": juntam proposições). Em C: `&&`, `||`, `!`.
- Tabelas-verdade completas de E, OU, NÃO (P, Q com V/F).
- Regras-resumo: E só é V se ambos forem V; OU basta um V; OU só é F se ambos forem F.
- **Precedência em expressões lógicas (Portugol):** 1º aritméticos, 2º relacionais, 3º NÃO,
  4º E, 5º OU. Na dúvida, parênteses.
- Exemplo resolvido passo a passo: NUM1=10, NUM2=5, NUM3=200, NUM4=200;
  (NUM1+NUM2 > 10 E NUM1+NUM3 > NUM4) → (15>10) V e (210>200) V → V E V → **V**.

**Pegadinhas e erros comuns**
- **E antes de OU**: `A ou B e C` é `A ou (B e C)`.
- **Diferença Portugol × C no NÃO:** no livro o NÃO vem *depois* dos relacionais; em C o
  `!` tem precedência *maior* que os relacionais (`!a > b` é `(!a) > b`). Ponto a
  destacar no LPEDC quando a turma passar do Portugol para C.
- Intervalo "entre 20 e 90" exige E: `n >= 20 && n <= 90` (e não `20 <= n <= 90`).

**Ideias de exercícios** (mesmas variáveis: 10, 2, 200, 200; respostas calculadas)
- Ativ. 3.3 (E): a) 5>0 e 210>200 → **V**; b) 20>40 e ... → **F**; c) 8=10 e ... → **F**;
  d) 12<10 e ... → **F**.
- Ativ. 3.4 (OU): a) 100>0 ou ... → **V**; b) 20=50 ou 190>200 → **F**;
  c) 8>10 ou 202>200 → **V**; d) 12>10 ou ... → **V**.
- Ativ. 3.5 (E e OU juntos, E primeiro): a) (V e V) ou F → **V**; b) (V e F) ou F → **F**;
  c) F ou (F e F) → **F**; d) V ou (...) → **V**.
- Sexo válido se 'M' ou 'F' (Ativ. 6.2); número na faixa de 20 a 90 (Ativ. 6.3).

### 0019-if / 0020-if-else

**Conceitos-chave**
- Portugol: `SE <expressão lógica> ENTÃO ... SENÃO ... FIM SE`; o SENÃO é opcional.
- C: `if (cond) instrução;` ou com bloco `{ }`; chaves obrigatórias para mais de uma
  instrução; `else` para o caminho falso.
- Exemplo-guia: média de duas notas; se ≥ 60, "aprovado"; depois acrescenta o senão
  "reprovado". Mostra a diferença entre "nada acontece" e "outra mensagem".

**Ideias de exercícios** (com respostas)
- Soma de dois números maior que 2 (exemplo): 1+3 → mensagem; 1+1 → nada (com if) ou
  "não é maior" (com if/else).
- Aumento: salário ≤ 1500 → 10%, senão 8%. 1320 → 1452.00; 1600 → 1728.00.
- Salário ≤ 500 → +10%, senão +5% (Ativ. 6.4/6.8): 500 → 550; 600 → 630.
- Divisível por 5 com `%` (Ativ. 6.9).
- **Salário líquido** (aula 3 Ativ. 1 / aula 6 Ativ. 6.13): bruto < 1500 → só INSS 8%;
  ≥ 1500 → IR 5% + INSS 11%. 1000 → 920.00; 2000 → 1680.00 (fronteira: 1500 → 1260.00).
- **Triângulo** (Ativ. 2 aula 3 / 6.11): cada lado menor que a soma dos outros dois.
  3,4,5 → sim; 1,2,3 → não (1+2 não é maior que 3); 2,2,3 → sim.
- Par/ímpar e positivo/negativo/nulo (Ativ. 3 aula 3).

### 0021-else-if

**Conceitos-chave**
- `if...else` aninhados: um if dentro do bloco de outro.
- Exemplo: aumento por faixa + gratificação se tem filhos (até 1500: 10% + R$ 80 com
  filho; acima: 8% + R$ 50). 1300 com filho → 1300 + 130 + 80 = **1510.00**. Um único
  `printf` no fim, fora dos ifs — bom hábito.
- Conselho: testar sempre com vários valores e situações diferentes.

**Ideias de exercícios** (com respostas)
- **Categoria de atleta** (Ativ. 4 aula 3): 5–10 infantil; 11–17 juvenil; 18–30
  profissional; acima de 30 sênior. Testes: 4 (fora da tabela — o que fazer?), 5, 10, 11,
  17, 18, 30, 31.
- Menor de três valores distintos (Ativ. 6.10): 7, 3, 9 → 3.

### 0023-switch

**Conceitos-chave**
- `switch` escolhe entre vários valores de uma expressão; `break` sai; `default` quando
  nenhum caso casa. Tudo que se faz com switch dá para fazer com if/else; switch é
  preferível quando há um conjunto determinado de valores.
- Exemplo: calculadora lendo `num1`, operador (+ − * /) e `num2`: 20.5 * 3 → 61.5.

**Ideias de exercícios** (com respostas)
- **Aumento por classe** (Ativ. 1 aula 6): A 10%, B 15%, C 20%. 1000 classe B → 1150.00.
- **Biblioteca** (Ativ. 2 aula 6): usuário 'A' (aluno) ou 'P' (professor); livro A ou B;
  livro A qualquer um loca, livro B só professor. Aluno+B → não pode; professor+B → pode;
  aluno+A → pode. Bom para combinar switch com &&.

### 0025-while

**Conceitos-chave**
- Portugol `enquanto <condição> faca ... fim enquanto`; C `while (cond) { }`.
- Testa antes de cada execução; serve quando não se sabe quantas vezes repetir.
- Contador de 1 a 10 com while precisa inicializar fora (`contador ← 1`) e incrementar
  dentro — no `para` isso era automático; por isso o while ficou maior.
- Padrão "**deseja continuar? (S/N)**": iniciar `resposta ← 'S'` para entrar no laço na
  primeira vez; ao fim de cada volta perguntar de novo.

**Pegadinhas e erros comuns**
- Variável de controle não inicializada → laço não executa (ou executa com lixo).
- Só o "S" maiúsculo continua; qualquer outra tecla (inclusive "s") encerra — discutir
  aceitar as duas.

**Ideias de exercícios** (com respostas)
- **Completar lacunas** (Ativ. 1 aula 4): ler até 0, contar quantos (incluindo o zero!) e
  média. Lacunas: `numero != 0`; `leia(numero)`; `quantidade ← quantidade + 1`;
  `soma ← soma + numero`; `media ← soma / quantidade`. Ex.: 4, 6, 0 → quantidade 3, média
  3.33. Ótimo para discutir **se o sentinela deve entrar na conta** (normalmente não).
- Idade e sexo de várias pessoas até não querer mais; contar M e F e médias de idade por
  sexo (Ativ. 2).
- Estado civil (S, C, V, D) e idade até estado inválido **ou** idade < 0; quantidade e
  média de idade por estado civil (Ativ. 3) — condição de parada composta.
- Fatorial com while (Ativ. 7.12).

### 0026-do-while

**Conceitos-chave**
- Executa o bloco antes de testar: garante pelo menos uma execução. Por isso, no exemplo
  das notas, a variável `resp` **não** precisa ser inicializada com 1 (com while,
  precisava). Essa comparação é a melhor explicação curta da diferença.

**Ideias de exercícios**
- Refazer o reajuste salarial com do-while (Ativ. 2 aula 7).
- Ler números até aparecer um entre 1 e 5; mostrar quantidade, soma e média (Ativ. 1).

### 0027-for

**Conceitos-chave**
- Portugol `para <var> de <ini> ate <fim> passo <inc> faca ... fim para`: a variável de
  controle deve ser inteira e declarada; repete enquanto ≤ valor final.
- C: `for (inicialização; teste; incremento)` — inicialização uma vez, teste antes de cada
  volta, incremento ao fim de cada volta.
- Exemplo: média de 10 notas com `for (conta = 0; conta <= 9; conta++)`; ao sair, `conta`
  vale 10 e é usada como divisor (cuidado: só funciona porque começa em 0).
- Motivação: sem laço, calcular média de 20 alunos exigiria copiar o bloco 20 vezes.

**Pegadinhas e erros comuns**
- O livro mostra a saída de 1 a 10 como "12345678910" (sem separador) — usar como alerta
  de formatação.
- Usar a variável de controle depois do laço exige saber exatamente o valor final dela.

**Ideias de exercícios** (respostas calculadas)
- **O que é exibido?** (Ativ. 4.1): `para c de 0 ate 10 passo 2` → 0 2 4 6 8 10
  (no livro sairia "0246810" sem espaços).
- Ímpares entre 100 e 200 (Ativ. 4.2): 101, 103, ..., 199 (50 números).
- Para 15 números: antecessor, sucessor, dobro, triplo (Ativ. 4.3).
- Tabuada do 6 (Ativ. 4.4): "6 x 1 = 6" até "6 x 10 = 60".
- **População** (Ativ. 4.5): 20.000 hab. em 2010, crescendo 5% ao ano; imprimir de 2011 a
  2030. 2011 → 21.000; 2030 → ≈ 53.066. Ótimo para acumulador multiplicativo.
- **Celsius → Fahrenheit em faixa** (Ativ. 7.4): F = 1,8C + 32; de 8 a 10 → 46.4, 48.2,
  50.0.
- Quadrado de 5 reais e somatório; média de 5 inteiros; pares de 1 a 100; fatorial
  (5! = 120).

### 0030-padroes-de-laco

**Conceitos-chave** (aparecem nos exemplos)
- **Acumulador** zerado antes (`soma = 0`) e o porquê (lixo na memória).
- **Contador** de quantas notas foram digitadas (`contador++`), usado depois na média.
- **Sentinela** (0) e **pergunta S/N** como formas de parar.
- Contadores por categoria (aprovados/reprovados; M/F; estado civil).

**Ideias de exercícios**
- Ler números até 0; mostrar quantidade, pares, ímpares e média (Ativ. 7.11).
- Média de 20 alunos → só contar aprovados e reprovados (Ativ. 4.6).

### 0042-vetores / 0046-strings (resumo)

**Conceitos-chave**
- Motivação excelente: no programa da média, cada nota nova apaga a anterior; para
  mostrar todas no fim, ou se cria uma variável por aluno (pouco inteligente) ou um vetor.
- **Analogia: vetor é uma fileira de caixinhas numeradas**; cada caixinha guarda um valor
  e tem seu "endereço" (o índice), de 0 a n−1. Tabela visual com 10 notas.
- `scanf("%f", &notas[i])` dentro de um for; C não confere se o índice é válido.
- String = vetor de `char` terminado pelo caractere nulo; para 8 letras, 9 posições
  (exemplo "EDUCACAO" em `char NOME[9]`).

**Pegadinhas e erros comuns**
- O livro grafa o nulo como `'/0'` (barra errada); o certo é `'\0'`.
- Recomenda `gets` para ler string — evitar.

**Ideias de exercícios**
- Soma posição a posição de dois vetores de 5 (Ativ. 1 aula 8).
- Guardar 20 reais e consultar por índice até digitar índice inválido (fora de 0–19).
- Listar múltiplos de 2, de 3 e de 5 de um vetor de 10.
- Vetor de 10: maior, menor, média, quantos acima e abaixo da média (precisa guardar os
  valores — justificativa perfeita para vetor).

---

## Obsoleto / evitar

- Bloodshed Dev-C++ e link do superdownloads; F9 para compilar.
- `system("PAUSE")` e `#include <stdlib.h>` "para evitar problemas" (incluir só o que usa).
- `gets()` para ler strings.
- `main()` sem `int` em alguns exemplos; `int` de 4 bytes apresentado como regra fixa.

## Extras que não cabem no sumário

- Deduções lógicas em linguagem natural (silogismos do armário e das idades) — podem abrir
  o módulo 00 como "aquecimento" antes de 0001.
- Missionários e canibais e separação de bolas: desafios de "pensar em estados" que
  servem de bônus no módulo 00.
- Conselho de método: resolver no papel antes de digitar; testar com vários valores;
  reaproveitar algoritmos antigos.

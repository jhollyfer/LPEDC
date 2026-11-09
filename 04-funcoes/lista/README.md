<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 04 · Funções e modularização

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/04-funcoes/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0401** · ★☆☆ · O desconto do Pix

A loja dá 10% de desconto para quem paga no Pix. Escreva a função
"double preco_pix(double preco)", que devolve o preço com o desconto, e use
no main para três produtos: tênis de R$ 299.90, mochila de R$ 159.00 e boné
de R$ 59.90:


```text
Saída esperada:
Tênis: R$ 299.90 -> R$ 269.91 no Pix
Mochila: R$ 159.00 -> R$ 143.10 no Pix
Boné: R$ 59.90 -> R$ 53.91 no Pix
```

**Dicas:**

1. A função recebe o preço, calcula preco * 0.90 e devolve com return.
2. Defina a função antes do main (ou escreva o protótipo antes do main).
3. Resposta esperada: R$ 269.91, R$ 143.10 e R$ 53.91.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0401.c
```

---

**Exercício P0402** · ★☆☆ · O artilheiro do campeonato

Três atacantes disputam a artilharia: Duda com 12 gols, Léo com 17 e Bia com
15. Escreva a função "int maior(int a, int b)" e, sem escrever outra função,
use maior duas vezes, uma dentro da outra, para achar o maior dos três:


```text
Saída esperada:
Gols: 12, 17 e 15
Artilheiro com 17 gols
```

**Dicas:**

1. maior(a, b) devolve a se a > b, senão b.
2. maior(maior(duda, leo), bia): o valor que uma chamada devolve vira o
   argumento da outra.
3. Resposta esperada: Artilheiro com 17 gols.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0402.c
```

---

**Exercício P0403** · ★☆☆ · As ordens de largada

De quantas maneiras os carros podem se alinhar no grid de largada? Com n
carros, são n! maneiras. Escreva a função recursiva "long long
fatorial(int n)" (0! = 1 é o caso base; n! = n × (n − 1)! é o caso recursivo)
e mostre o resultado para 5, 10 e 15 carros:


```text
Saída esperada:
5 carros: 120 maneiras
10 carros: 3628800 maneiras
15 carros: 1307674368000 maneiras
```

**Dicas:**

1. if (n == 0) return 1; return n * fatorial(n - 1);
2. Use long long e %lld: 15! não cabe num int.
3. Resposta esperada: 120, 3628800 e 1307674368000.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0403.c
```

---

**Exercício P0404** · ★☆☆ · O reajuste que não chegou

O programa abaixo chama aplicar_reajuste para dar 5% de aumento ao salário
de R$ 2400.00, mas o salário continua igual depois da chamada. O erro está
lá de propósito: a função recebe uma cópia. Conserte trocando a função por
"double com_reajuste(double salario)", que devolve o novo valor, e guarde o
retorno no main:


```text
Saída esperada:
Antes: R$ 2400.00
Depois: R$ 2520.00
```

**Dicas:**

1. Em C, o parâmetro é uma variável nova, que recebe uma cópia do argumento.
   Mudar a cópia não muda o original.
2. salario = com_reajuste(salario); no main.
3. Resposta esperada: Depois: R$ 2520.00.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0404.c
```

---

**Exercício P0405** · ★☆☆ · O protótipo esquecido

O programa abaixo não compila, de propósito: o main chama area_terreno antes
de o compilador saber que ela existe. Conserte sem mudar a ordem das funções,
só acrescentando o protótipo no lugar certo. O terreno tem 12.5 m por 30 m:


```text
Saída esperada:
Área do terreno: 375.0 m2
```

**Dicas:**

1. O protótipo é a primeira linha da função terminada em ponto e vírgula.
2. Ele vai antes do main, depois dos #include.
3. Resposta esperada: Área do terreno: 375.0 m2.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0405.c
```

---

**Exercício P0406** · ★☆☆ · O recorde do fliperama

O fliperama guarda o recorde da máquina. Escreva "int recorde(int pontos)",
que recebe os pontos de uma partida e devolve o maior valor visto até agora,
guardado numa variável static local (sem global). Chame com as partidas de
1200, 3400, 2100 e 5000 pontos:


```text
Saída esperada:
Partida com 1200 -> recorde 1200
Partida com 3400 -> recorde 3400
Partida com 2100 -> recorde 3400
Partida com 5000 -> recorde 5000
```

**Dicas:**

1. static int melhor = 0; dentro da função: ela é criada uma vez só e
   lembra o valor entre as chamadas.
2. Se pontos > melhor, atualize; depois devolva melhor.
3. Resposta esperada: 1200, 3400, 3400 e 5000.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0406.c
```

---

**Exercício P0407** · ★☆☆ · A pirâmide de latas

O repositor do mercado monta uma pirâmide de latas: a base tem n latas, a
fileira de cima tem n − 1, e assim até 1 lata no topo. Escreva a função
recursiva "int latas(int n)", que devolve o total de latas de uma pirâmide
com base n, e mostre para bases de 1, 4 e 10:


```text
Saída esperada:
Base 1: 1 lata(s)
Base 4: 10 lata(s)
Base 10: 55 lata(s)
```

**Dicas:**

1. Caso base: uma pirâmide de base 1 tem 1 lata.
2. Caso recursivo: a base tem n latas, e em cima dela está uma pirâmide de
   base n - 1.
3. Resposta esperada: 1, 10 e 55.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0407.c
```

---

**Exercício P0408** · ★☆☆ · Quantos dígitos tem

Escreva a função recursiva "int digitos(int n)", que conta quantos dígitos
tem um número positivo, sem laço: um número menor que 10 tem 1 dígito; os
outros têm 1 dígito a mais que n / 10. Teste com 7, 2026 e 1000000:


```text
Saída esperada:
7 tem 1 dígito(s)
2026 tem 4 dígito(s)
1000000 tem 7 dígito(s)
```

**Dicas:**

1. if (n < 10) return 1;
2. return 1 + digitos(n / 10);
3. Resposta esperada: 1, 4 e 7.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0408.c
```

---

**Exercício P0409** · ★☆☆ · Qual pizza compensa?

A pizza broto tem 25 cm de diâmetro e custa R$ 30.00; a grande tem 35 cm e
custa R$ 50.00. Escreva as macros "#define PI 3.14159265" e
"#define AREA_CIRCULO(r) (PI * (r) * (r))" e mostre o preço por cm² de cada
uma (o raio é o diâmetro / 2), com 4 casas, e qual compensa mais:


```text
Saída esperada:
Broto: R$ 0.0611 por cm2
Grande: R$ 0.0520 por cm2
Compensa mais: grande
```

**Dicas:**

1. Os parênteses em volta de r importam: AREA_CIRCULO(35 / 2.0) tem que
   virar PI * (35 / 2.0) * (35 / 2.0).
2. Preço por cm² é preço / área. Quem tem o menor valor compensa mais.
3. Resposta esperada: R$ 0.0611 e R$ 0.0520; compensa a grande.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0409.c
```

---

**Exercício P0410** · ★☆☆ · A barra de progresso do download

Escreva a função "void barra(int percentual)", que desenha uma barra de 10
posições: cada 10% vira um '#', o resto vira '.', e no fim vem o percentual.
Chame com 0, 30, 75 e 100:


```text
Saída esperada:
[..........] 0%
[###.......] 30%
[#######...] 75%
[##########] 100%
```

**Dicas:**

1. cheios = percentual / 10 (divisão inteira: 75 dá 7).
2. Um for de 1 a 10: se i <= cheios mostra '#', senão '.'.
3. Resposta esperada: as quatro barras acima.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0410.c
```

## ★★☆ Para pensar

**Exercício P0411** · ★★☆ · O número do pedido ao contrário

Escreva a função recursiva "int inverte(int n, int acumulado)", que devolve
n com os dígitos ao contrário, sem laço. A ideia é carregar o resultado
parcial num parâmetro: a cada chamada, o último dígito de n passa para o fim
de acumulado. O main chama inverte(n, 0). Teste com 12345, 1200 e 7:


```text
Saída esperada:
12345 -> 54321
1200 -> 21
7 -> 7
```

**Dicas:**

1. Caso base: if (n == 0) return acumulado;
2. Caso recursivo: return inverte(n / 10, acumulado * 10 + n % 10);
3. Os zeros do fim de 1200 viram zeros à esquerda, que não aparecem: 21.
4. Resposta esperada: 54321, 21 e 7.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0411.c
```

---

**Exercício P0412** · ★★☆ · Três linhas de ônibus no terminal

No terminal, a linha 300 sai a cada 12 minutos, a 450 a cada 18 e a 640 a
cada 30. As três saíram juntas às 06:00. Escreva o "int mdc(int a, int b)"
recursivo de Euclides, o "int mmc(int a, int b)" que usa o mdc, e descubra
quando as três saem juntas de novo:


```text
Saída esperada:
mdc(12, 18) = 6
mmc(12, 18) = 36
As três saem juntas a cada 180 minutos
Próxima saída juntas: 09:00
```

**Dicas:**

1. mdc(a, 0) = a; mdc(a, b) = mdc(b, a % b).
2. mmc(a, b) = a / mdc(a, b) * b. Dividir antes de multiplicar evita
   estourar o int.
3. Para três números: mmc(mmc(12, 18), 30).
4. Resposta esperada: a cada 180 minutos, às 09:00.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0412.c
```

---

**Exercício P0413** · ★★☆ · Quantas chamadas custa uma combinação

De quantas formas dá para escolher k pessoas de um grupo de n? É a
combinação C(n, k), e ela tem uma definição recursiva: C(n, 0) = C(n, n) = 1
e C(n, k) = C(n − 1, k − 1) + C(n − 1, k). Escreva essa função recursiva e
conte, com uma variável global, quantas chamadas ela faz para C(5, 2),
C(10, 5) e C(20, 10) (zere o contador antes de cada uma):


```text
Saída esperada:
C(5, 2) = 10 com 19 chamadas
C(10, 5) = 252 com 503 chamadas
C(20, 10) = 184756 com 369511 chamadas
```

**Dicas:**

1. A primeira linha da função é chamadas++;.
2. Repare no padrão: as chamadas são sempre 2 × C(n, k) − 1, porque cada
   folha da recursão devolve 1.
3. Para C(60, 6), a combinação da Mega-Sena, seriam mais de 100 milhões de
   chamadas: não rode.
4. Resposta esperada: 19, 503 e 369511 chamadas.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0413.c
```

---

**Exercício P0414** · ★★☆ · Subindo a escada da arquibancada

Na arquibancada, você sobe 1, 2 ou 3 degraus por passo. De quantas formas
diferentes dá para subir uma escada de n degraus? Escreva a função recursiva
"int formas(int n)": para chegar ao degrau n, o último passo saiu de n − 1,
n − 2 ou n − 3. Mostre o resultado para 1 a 10 degraus:


```text
Saída esperada:
1 degrau(s): 1 forma(s)
2 degrau(s): 2 forma(s)
3 degrau(s): 4 forma(s)
4 degrau(s): 7 forma(s)
5 degrau(s): 13 forma(s)
6 degrau(s): 24 forma(s)
7 degrau(s): 44 forma(s)
8 degrau(s): 81 forma(s)
9 degrau(s): 149 forma(s)
10 degrau(s): 274 forma(s)
```

**Dicas:**

1. Dois casos base: formas(0) = 1 (já chegou: um jeito, ficar parado) e
   formas de número negativo = 0 (passou da escada).
2. Caso recursivo: formas(n - 1) + formas(n - 2) + formas(n - 3).
3. Resposta esperada: 274 formas para 10 degraus.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0414.c
```

---

**Exercício P0415** · ★★☆ · O app de treinos refatorado

O programa abaixo mostra a duração de três treinos, mas repete a mesma conta
três vezes. Refatore: escreva "int minutos(int hora, int minuto)", que
converte um horário em minutos desde a meia-noite, e "void mostrar(int
duracao)", que mostra a duração em h e min. O main deve ficar curto, e a
saída tem que continuar a mesma:


```text
Saída esperada:
Treino 1: 1 h 15 min
Treino 2: 0 h 50 min
Treino 3: 2 h 5 min
Total: 4 h 10 min
```

**Dicas:**

1. A duração de um treino é minutos(fim) - minutos(início).
2. mostrar recebe a duração e faz o / 60 e o % 60.
3. Resposta esperada: a mesma saída do programa original.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0415.c
```

---

**Exercício P0416** · ★★☆ · A média da temperatura ao longo do dia

A estação meteorológica manda uma leitura de cada vez. Escreva "double
media_ate_agora(double leitura)", que devolve a média de todas as leituras
recebidas até aquela chamada, guardando a soma e a contagem em variáveis
static locais. Chame com 30.0, 32.0, 28.0 e 34.0 graus:


```text
Saída esperada:
Leitura 30.0 -> média 30.0
Leitura 32.0 -> média 31.0
Leitura 28.0 -> média 30.0
Leitura 34.0 -> média 31.0
```

**Dicas:**

1. static double soma = 0.0; static int quantas = 0; dentro da função.
2. A cada chamada: some, conte, e devolva soma / quantas.
3. Resposta esperada: 30.0, 31.0, 30.0 e 31.0.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0416.c
```

---

**Exercício P0417** · ★★☆ · A pilha da potência na tela

Escreva a potência recursiva "int potencia(int base, int exp, int nivel)"
(base^0 = 1; base^exp = base × base^(exp − 1)) que mostra a pilha de
chamadas: ao entrar, mostra a chamada com 2 espaços por nível; ao voltar,
mostra o resultado no mesmo recuo. O main chama potencia(2, 4, 0):


```text
Saída esperada:
potencia(2, 4)
  potencia(2, 3)
    potencia(2, 2)
      potencia(2, 1)
        potencia(2, 0) = 1
      = 2
    = 4
  = 8
= 16
Resultado: 16
```

**Dicas:**

1. Uma função auxiliar "void recuo(int nivel)" mostra 2 * nivel espaços com
   um for.
2. No caso base, mostre a chamada já com o "= 1" na mesma linha.
3. Cada chamada recursiva vai com nivel + 1. Depois que ela volta, mostre
   "= resultado".
4. Resposta esperada: o desenho acima, Resultado: 16.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0417.c
```

---

**Exercício P0418** · ★★☆ · O imposto de cada estado

A mesma loja virtual compila uma versão do sistema para cada estado. Escreva
o programa com "#define ESTADO 1" no topo e, com #if, #elif e #else, defina
ICMS como 0.20 para o Amazonas (1), 0.18 para São Paulo (2) e 0.17 para os
outros, e NOME_ESTADO com o nome. Escreva também a macro MOSTRAR(expr), que
mostra o texto da expressão (com #expr) e o valor dela. Para um produto de
R$ 100.00:


```text
Saída esperada:
Estado: Amazonas
preco * (1 + ICMS) = 120.00
preco * ICMS = 20.00
```

**Dicas:**

1. #if ESTADO == 1 ... #define ICMS 0.20 ... #elif ESTADO == 2 ... #else
   ... #endif.
2. #define MOSTRAR(expr) printf("%s = %.2f\n", #expr, (expr)). O #expr vira
   o texto da expressão, entre aspas.
3. Troque ESTADO para 2 e a saída vira 118.00 e 18.00, sem mexer em mais
   nada.
4. Resposta esperada: 120.00 e 20.00 com ESTADO 1.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0418.c
```

---

**Exercício P0419** · ★★☆ · O número da numerologia

A numerologia soma os dígitos da data de nascimento até sobrar um dígito só:
27111990 → 30 → 3. Escreva "int soma_digitos(int n)", recursiva, e "int
reduz(int n)", também recursiva, que mostra cada passo e devolve o dígito
final: se n já tem um dígito, ele é a resposta; senão, reduz a soma dos
dígitos. Teste com 27111990 e com 2026:


```text
Saída esperada:
27111990 -> 30 -> 3
2026 -> 10 -> 1
```

**Dicas:**

1. soma_digitos(n): se n < 10 devolve n; senão n % 10 + soma_digitos(n /
   10).
2. reduz(n): mostra n; se n < 10, quebra a linha e devolve n; senão mostra
   " -> " e devolve reduz(soma_digitos(n)).
3. Resposta esperada: 3 e 1.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0419.c
```

---

**Exercício P0420** · ★★☆ · O maior dígito que sumiu

A função recursiva abaixo deveria devolver o maior dígito de um número, mas
para 9123 devolve 3. O erro está no caso base, de propósito. Conserte só o
caso base e confira com os três testes:


```text
Saída esperada:
Maior dígito de 9123: 9
Maior dígito de 4718: 8
Maior dígito de 5: 5
```

**Dicas:**

1. Siga a recursão na mão para 9123: quem é o último a responder, e o que
   ele responde?
2. Um número de um dígito só é o seu próprio maior dígito.
3. Resposta esperada: 9, 8 e 5.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0420.c
```

## ★★★ Desafio

**Exercício P0421** · ★★★ · Hanói com 4 discos e a conta de cada disco

Resolva a Torre de Hanói com 4 discos, das hastes A para C, usando B de
apoio. Escreva "void hanoi(int n, char origem, char destino, char apoio)",
recursiva, e "void mover(int disco, char de, char para)", que numera e mostra
cada movimento e conta quantas vezes cada disco se moveu (sem vetor: quatro
contadores e um switch). No fim, mostre o total e a conta de cada disco:


```text
Saída esperada:
 1: disco 1 de A para B
 2: disco 2 de A para C
 3: disco 1 de B para C
 4: disco 3 de A para B
 5: disco 1 de C para A
 6: disco 2 de C para B
 7: disco 1 de A para B
 8: disco 4 de A para C
 9: disco 1 de B para C
10: disco 2 de B para A
11: disco 1 de C para A
12: disco 3 de B para C
13: disco 1 de A para B
14: disco 2 de A para C
15: disco 1 de B para C
Total: 15 movimentos
Disco 1: 8, disco 2: 4, disco 3: 2, disco 4: 1
```

**Dicas:**

1. hanoi(n): se n == 0, nada; senão hanoi(n - 1, origem, apoio, destino),
   mover(n, origem, destino), hanoi(n - 1, apoio, destino, origem).
2. Os contadores podem ser globais ou static dentro de mover; o total é a
   soma deles.
3. Repare: o disco k se move 2^(4 - k) vezes, e o total é 2^4 - 1.
4. Resposta esperada: 15 movimentos; 8, 4, 2 e 1.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0421.c
```

---

**Exercício P0422** · ★★★ · De volta para a base 10

O sistema antigo grava números em outras bases, escritos com os dígitos de 0
a 9 como se fossem decimais (2026 na base 8 vem como 3752). Escreva a função
recursiva "long long para_decimal(long long digitos, int base)", que
converte para a base 10 olhando o último dígito e o resto do número, e
devolve -1 se algum dígito não existir naquela base. Teste com os quatro
casos abaixo:


```text
Saída esperada:
11111101010 na base 2 = 2026
3752 na base 8 = 2026
2210001 na base 3 = 2026
1289 na base 8 = inválido
```

**Dicas:**

1. O último dígito é digitos % 10; o resto do número é digitos / 10, que
   vale (resto convertido) × base.
2. Caso base: digitos == 0 devolve 0. Se o último dígito for >= base,
   devolva -1; se a chamada para o resto devolver -1, devolva -1 também.
3. 11111101010 não cabe num int: use long long e o sufixo LL.
4. Resposta esperada: 2026 nos três primeiros; inválido no último.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0422.c
```

---

**Exercício P0423** · ★★★ · Os verificadores do CNPJ

O CNPJ tem 12 dígitos e 2 verificadores, com uma regra parecida com a do CPF.
Para cada verificador, multiplique os dígitos, da DIREITA para a esquerda,
pelos pesos 2, 3, 4, ..., 9, voltando a 2 depois do 9; com r = soma % 11, o
dígito é 0 se r < 2, senão 11 − r. O 1º usa os 12 primeiros dígitos; o 2º
usa os 12 mais o 1º verificador. Escreva "int verificador(long long n)",
"bool todos_iguais(long long cnpj)" e "bool cnpj_valido(long long cnpj)", e
teste três CNPJs de 14 dígitos:


```text
Saída esperada:
11222333000181: válido
11222333000182: inválido
11111111111111: inválido
```

**Dicas:**

1. Em verificador, ande de n % 10 para a esquerda com n /= 10, e o peso faz
   peso = peso == 9 ? 2 : peso + 1.
2. Em cnpj_valido: base = cnpj / 100; dv1 = verificador(base); dv2 =
   verificador(base * 10 + dv1); confira com cnpj % 100.
3. todos_iguais compara cada dígito com o último.
4. Resposta esperada: válido, inválido, inválido.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0423.c
```

---

**Exercício P0424** · ★★★ · Goldbach nos anos pares

A conjectura de Goldbach diz que todo par maior que 2 é a soma de dois
primos. Ninguém provou, mas ninguém achou exceção. Escreva "bool
eh_primo(int n)", "int menor_parcela(int n)" (o menor primo p tal que n − p
também é primo) e "int formas(int n)" (quantos pares p ≤ q de primos somam
n). Mostre a decomposição com a menor parcela para os anos pares de 2020 a
2030 e de quantas formas dá para escrever 2026:


```text
Saída esperada:
2020 = 3 + 2017
2022 = 5 + 2017
2024 = 7 + 2017
2026 = 23 + 2003
2028 = 11 + 2017
2030 = 3 + 2027
2026 pode ser escrito de 32 formas
```

**Dicas:**

1. eh_primo: menor que 2 não é; teste divisores d com d * d <= n.
2. menor_parcela: para p de 2 em diante, devolva o primeiro p com eh_primo(p)
   && eh_primo(n - p).
3. formas: conte os p de 2 até n / 2 que funcionam.
4. Resposta esperada: as sete linhas acima.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0424.c
```

---

**Exercício P0425** · ★★★ · O prazo de 10 dias úteis

O protocolo foi aberto numa quinta, 19/11/2026, e o prazo é de 10 dias úteis,
contados a partir do dia seguinte. Não contam sábados, domingos nem os
feriados nacionais fixos (01/01, 21/04, 01/05, 07/09, 12/10, 02/11, 15/11,
20/11 e 25/12). Sem vetor e sem struct, guarde cada data num int no formato
aaaammdd (20261119). Escreva "int proximo_dia(int data)", "int
dia_semana(int data)" (0 = domingo), "bool feriado(int data)" e mostre o
prazo final e quantos dias foram pulados:


```text
Saída esperada:
Protocolo: 19/11/2026
Prazo final: 04/12/2026
Pulados: 4 dia(s) de fim de semana e 1 feriado(s)
```

**Dicas:**

1. Para desmontar: ano = data / 10000, mes = data / 100 % 100, dia = data %
   100. Para montar: ano * 10000 + mes * 100 + dia.
2. proximo_dia precisa de "int dias_no_mes(int mes, int ano)", com
   bissexto. Quando o dia passa do fim do mês, vira 1 e o mês avança (e o
   ano, em dezembro).
3. Para o dia da semana: a = (14 − mês) / 12, y = ano − a, m = mês + 12a − 2
   e (dia + y + y/4 − y/100 + y/400 + 31m/12) % 7.
4. O feriado só olha mes * 100 + dia: 1120 é 20/11.
5. Resposta esperada: Prazo final: 04/12/2026; 4 dias de fim de semana e 1
   feriado.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0425.c
```

---

**Exercício P0426** · ★★★ · De quantas formas dar o troco

O caixa tem moedas de 1, 5, 10, 25 e 50 centavos e de R$ 1. De quantas
formas diferentes dá para formar R$ 1,00 (100 centavos)? Escreva "int
moeda(int i)", que devolve o valor da moeda i (0 é a de 100, 5 é a de 1), e a
função recursiva "int formas(int valor, int i)", que conta as formas usando
só as moedas de i em diante: ou você usa a moeda i (e continua podendo usar),
ou desiste dela de vez. Conte também as chamadas:


```text
Saída esperada:
R$ 0,10: 4 forma(s), 43 chamada(s)
R$ 0,25: 13 forma(s), 251 chamada(s)
R$ 1,00: 293 forma(s), 15501 chamada(s)
```

**Dicas:**

1. Casos base: valor == 0 é 1 forma (deu certo); valor < 0, ou acabaram as
   moedas (i == 6), é 0.
2. Caso recursivo: formas(valor - moeda(i), i) + formas(valor, i + 1).
3. Zere o contador global antes de cada valor.
4. Resposta esperada: 4, 13 e 293 formas.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0426.c
```

---

**Exercício P0427** · ★★★ · As marcas da régua

Uma régua tem marcas de tamanhos diferentes: a do meio é a maior, as do meio
de cada metade são um pouco menores, e assim por diante. Isso é recursão
pura: a régua de ordem n é uma régua de ordem n − 1, uma marca de tamanho n e
outra régua de ordem n − 1. Escreva "void regua(int n)" e "void marca(int
tamanho)", e mostre a régua de ordem 4 (uma marca por linha) e quantas vezes
regua foi chamada:


```text
Saída esperada:
-
--
-
---
-
--
-
----
-
--
-
---
-
--
-
Chamadas de regua: 31
```

**Dicas:**

1. Caso base: regua(0) não faz nada.
2. Caso recursivo: regua(n - 1); marca(n); regua(n - 1);.
3. A estrutura é a mesma da Torre de Hanói: as marcas são 2^n − 1 e as
   chamadas são 2^(n + 1) − 1.
4. Resposta esperada: 15 marcas e 31 chamadas.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0427.c
```

---

**Exercício P0428** · ★★★ · O cheque por extenso

O cheque precisa do valor por extenso. Escreva "void extenso(int n)", para
números de 0 a 999999, dividida em funções menores: uma para as unidades,
uma para 10 a 19, uma para as dezenas, uma para "até 99" e outra para "até
999". Cuidado com as regras do português: 100 é "cem", mas 101 é "cento e
um"; 1000 é "mil", não "um mil"; e entre o milhar e o resto vai " e " quando
o resto é menor que 100 ou é uma centena redonda (2026, 2100), e só espaço
nos outros casos (2150). Teste com estes valores:


```text
Saída esperada:
0: zero
15: quinze
100: cem
101: cento e um
1000: mil
2026: dois mil e vinte e seis
2100: dois mil e cem
2150: dois mil cento e cinquenta
123456: cento e vinte e três mil quatrocentos e cinquenta e seis
999999: novecentos e noventa e nove mil novecentos e noventa e nove
```

**Dicas:**

1. Cada função de nomes é um switch que só faz printf("um"), printf("dois")...
2. ate_99(n): se n < 10, unidade; se n < 20, de 10 a 19; senão, a dezena
   e, se n % 10 > 0, " e " e a unidade.
3. ate_999(n): se n == 100, "cem"; senão a centena (cento, duzentos...) e,
   se sobrar algo, " e " e ate_99 do resto.
4. extenso(n): milhar = n / 1000 e resto = n % 1000; milhar 1 é só "mil".
5. Resposta esperada: as dez linhas acima.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0428.c
```

---

**Exercício P0429** · ★★★ · Os números felizes

Troque um número pela soma dos quadrados dos seus dígitos e repita: 2026 →
4 + 0 + 4 + 36 = 44 → 32 → 13 → 10 → 1. Quem chega em 1 é um número feliz.
Quem não é feliz cai, mais cedo ou mais tarde, no ciclo que passa pelo 4 (4
→ 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4). Escreva "int
soma_quadrados(int n)", recursiva, e "bool feliz(int n)", também recursiva
(sem laço). Mostre o caminho de 2026, os números felizes de 1 a 50 e quantos
são:


```text
Saída esperada:
2026 -> 44 -> 32 -> 13 -> 10 -> 1
Felizes até 50: 1 7 10 13 19 23 28 31 32 44 49
Total: 11
```

**Dicas:**

1. soma_quadrados(0) = 0; senão (n % 10)² + soma_quadrados(n / 10).
2. feliz(n): se n == 1, true; se n == 4, false; senão feliz(soma_quadrados(n)).
3. Para o caminho, escreva "void caminho(int n)", que mostra n e, se não
   for 1 nem 4, mostra " -> " e chama caminho(soma_quadrados(n)).
4. Resposta esperada: 11 números felizes até 50.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0429.c
```

---

**Exercício P0430** · ★★★ · A fatoração em primos

Todo inteiro maior que 1 se escreve de um jeito só como produto de primos:
360 = 2³ × 3² × 5. Escreva, sem laço, três funções recursivas: "int
expoente(int n, int d)" (quantas vezes d divide n), "int sem_fator(int n,
int d)" (n depois de tirar todos os fatores d) e "void fatorar(int n, int
d)", que mostra a fatoração tentando os divisores d = 2, 3, 4, ... Fatore
360, 2026, 1024 e 9973:


```text
Saída esperada:
360 = 2^3 x 3^2 x 5
2026 = 2 x 1013
1024 = 2^10
9973 = 9973
```

**Dicas:**

1. expoente(n, d): se n % d != 0, devolve 0; senão 1 + expoente(n / d, d).
   sem_fator é parecida, devolvendo o n que sobrou.
2. fatorar(n, d): se n == 1, acabou. Se d * d > n, o que sobrou é primo:
   mostre n. Se d não divide n, tente d + 1. Se divide, mostre d (com ^e se
   e > 1) e continue com sem_fator(n, d) e d + 1.
3. O " x " entre os fatores aparece antes de cada fator que não é o
   primeiro: passe essa informação num parâmetro a mais, ou mostre o " x "
   antes da chamada recursiva quando ainda sobrar algo.
4. Resposta esperada: as quatro linhas acima.

```bash
~/LPEDC/rodar 04-funcoes/lista/P0430.c
```

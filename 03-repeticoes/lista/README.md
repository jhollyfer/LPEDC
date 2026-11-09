<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 03 · Laços

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/03-repeticoes/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0301** · ★☆☆ · A tabela do pão francês

A padaria quer colar no balcão uma tabela com o preço de 1 a 8 pães, a
R$ 0.85 cada. Escreva um programa com um for que mostre a tabela, com a
quantidade em 2 colunas e o preço em 5:


```text
Saída esperada:
 1 pão(es): R$  0.85
 2 pão(es): R$  1.70
 3 pão(es): R$  2.55
 4 pão(es): R$  3.40
 5 pão(es): R$  4.25
 6 pão(es): R$  5.10
 7 pão(es): R$  5.95
 8 pão(es): R$  6.80
```

**Dicas:**

1. for (int qtd = 1; qtd <= 8; qtd++).
2. O preço é qtd * 0.85, mostrado com %5.2f.
3. Resposta esperada: de R$ 0.85 a R$ 6.80.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0301.c
```

---

**Exercício P0302** · ★☆☆ · O desafio do cofrinho

No desafio do cofrinho, você guarda R$ 1 no dia 1, R$ 2 no dia 2, e assim
por diante, um real a mais por dia. Escreva um programa com while que mostre
quanto há no cofrinho ao fim dos dias 10, 20 e 30, e o total final:


```text
Saída esperada:
Dia 10: R$ 55
Dia 20: R$ 210
Dia 30: R$ 465
Total em 30 dias: R$ 465
```

**Dicas:**

1. Um acumulador: total começa em 0 e recebe total += dia a cada volta.
2. Dentro do laço, mostre só quando dia % 10 == 0.
3. Resposta esperada: Total em 30 dias: R$ 465.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0302.c
```

---

**Exercício P0303** · ★☆☆ · As filas possíveis no banco

De quantas maneiras 10 pessoas podem formar uma fila? É 10! (10 × 9 × ... ×
1). Escreva um programa com for que calcule 10! e 20!, num unsigned long long
(o 20! já não cabe num int de jeito nenhum):


```text
Saída esperada:
10! = 3628800
20! = 2432902008176640000
```

**Dicas:**

1. O acumulador da multiplicação começa em 1, não em 0.
2. unsigned long long se mostra com %llu.
3. Resposta esperada: 3628800 e 2432902008176640000.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0303.c
```

---

**Exercício P0304** · ★☆☆ · Os dígitos do protocolo

O atendimento deu o protocolo 2026110903. Escreva um programa com while que
conte quantos dígitos ele tem e some esses dígitos, tirando um por vez com %
e / por 10. O número não cabe num int: use long long.


```text
Saída esperada:
Protocolo: 2026110903
Dígitos: 10
Soma dos dígitos: 24
```

**Dicas:**

1. Enquanto n > 0: some n % 10, conte mais um, faça n /= 10.
2. Trabalhe numa cópia, para ainda poder mostrar o número original.
3. Resposta esperada: 10 dígitos, soma 24.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0304.c
```

---

**Exercício P0305** · ★☆☆ · O tamanho do açaí

A tela do quiosque pede o tamanho do açaí: 1 (300 ml, R$ 12.00), 2 (500 ml,
R$ 18.00) ou 3 (700 ml, R$ 24.00). Escreva um programa com do...while que
repita a pergunta até a pessoa digitar 1, 2 ou 3, e depois mostre o preço.
Um exemplo de interação, em que a pessoa errou duas vezes:


```text
Saída esperada:
Tamanho (1, 2 ou 3): 0
Opção inválida.
Tamanho (1, 2 ou 3): 5
Opção inválida.
Tamanho (1, 2 ou 3): 2
Açaí de 500 ml: R$ 18.00
```

**Dicas:**

1. O do...while roda o corpo pelo menos uma vez: perfeito para perguntar.
2. Confira o retorno do scanf: se não leu número, termine com return 1.
3. Resposta esperada: com 0, 5 e 2, Açaí de 500 ml: R$ 18.00.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0305.c
```

---

**Exercício P0306** · ★☆☆ · Os números da sorte da promoção

Na promoção do mercado, ganham brinde os cupons cujo número, de 1 a 99, é
múltiplo de 3 ou de 5. Escreva um programa que conte quantos números de 1 a
99 ganham brinde e some esses números:


```text
Saída esperada:
Cupons premiados: 46
Soma dos números: 2318
```

**Dicas:**

1. Um contador e um acumulador, os dois começando em 0.
2. A condição é n % 3 == 0 || n % 5 == 0: o 15 conta uma vez só.
3. Resposta esperada: 46 cupons, soma 2318.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0306.c
```

---

**Exercício P0307** · ★☆☆ · A fofoca no grupo da família

Uma fofoca começa com 1 pessoa. A cada rodada, cada pessoa que sabe conta
para outras 2, então quem sabe triplica (1, 3, 9, 27...). Escreva um programa
com while que mostre cada rodada e pare na primeira em que mais de 1 milhão
de pessoas já saibam:


```text
Saída esperada:
Rodada 1: 3 pessoas
Rodada 2: 9 pessoas
Rodada 3: 27 pessoas
Rodada 4: 81 pessoas
Rodada 5: 243 pessoas
Rodada 6: 729 pessoas
Rodada 7: 2187 pessoas
Rodada 8: 6561 pessoas
Rodada 9: 19683 pessoas
Rodada 10: 59049 pessoas
Rodada 11: 177147 pessoas
Rodada 12: 531441 pessoas
Rodada 13: 1594323 pessoas
Passou de 1 milhão na rodada 13
```

**Dicas:**

1. while (sabem <= 1000000) { sabem *= 3; rodada++; ... }.
2. Mostre dentro do laço, depois de multiplicar.
3. Resposta esperada: Passou de 1 milhão na rodada 13.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0307.c
```

---

**Exercício P0308** · ★☆☆ · O jogo do PIM

No jogo do PIM, a turma conta de 1 em diante, mas todo múltiplo de 4, e todo
número que termina em 4, vira "PIM". Escreva um programa que mostre a
contagem de 1 a 20, um número por linha, trocando esses números por PIM:


```text
Saída esperada:
1
2
3
PIM
5
6
7
PIM
9
10
11
PIM
13
PIM
15
PIM
17
18
19
PIM
```

**Dicas:**

1. A condição é n % 4 == 0 || n % 10 == 4.
2. Um if/else dentro do for: ou mostra PIM, ou mostra o número.
3. Resposta esperada: PIM no 4, 8, 12, 14, 16 e 20.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0308.c
```

---

**Exercício P0309** · ★☆☆ · O mapa da sala de cinema

A sala pequena do cinema tem as fileiras A a E e 6 cadeiras em cada. Escreva
um programa com dois for, um dentro do outro, que mostre o mapa dos
assentos. Use um char para a fileira: 'A' + 1 é 'B', porque char é número.


```text
Saída esperada:
A1 A2 A3 A4 A5 A6
B1 B2 B3 B4 B5 B6
C1 C2 C3 C4 C5 C6
D1 D2 D3 D4 D5 D6
E1 E2 E3 E4 E5 E6
```

**Dicas:**

1. for (char fila = 'A'; fila <= 'E'; fila++) por fora; as cadeiras de 1 a
   6 por dentro.
2. Separe com espaço e quebre a linha depois do laço de dentro. Cuidado com
   o espaço sobrando no fim da linha: mostre o espaço antes de cada cadeira,
   menos da primeira.
3. Resposta esperada: 5 linhas de 6 assentos, de A1 a E6.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0309.c
```

---

**Exercício P0310** · ★☆☆ · A parcela que sobrou

A geladeira foi parcelada em 10 vezes de R$ 189.90, mas o programa abaixo
mostra 11 parcelas e um total errado. O erro está no for, de propósito.
Conserte o laço para mostrar as 10 parcelas e o total certo:


```text
Saída esperada:
Parcela 1: R$ 189.90
Parcela 2: R$ 189.90
Parcela 3: R$ 189.90
Parcela 4: R$ 189.90
Parcela 5: R$ 189.90
Parcela 6: R$ 189.90
Parcela 7: R$ 189.90
Parcela 8: R$ 189.90
Parcela 9: R$ 189.90
Parcela 10: R$ 189.90
Total: R$ 1899.00
```

**Dicas:**

1. Conte quantas voltas o for dá começando em 0 e indo até <= 10.
2. Ou começa em 1 e vai até <= 10, ou começa em 0 e vai até < 10. Repare que
   o número mostrado tem que ir de 1 a 10.
3. Resposta esperada: 10 parcelas, Total: R$ 1899.00.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0310.c
```

## ★★☆ Para pensar

**Exercício P0311** · ★★☆ · O pedido de trás para frente

O sistema da loja grava o número do pedido invertido para embaralhar a
etiqueta. Escreva um programa com while que inverta o pedido 120345 (o
resultado é 543021) e confira se o número é igual ao seu inverso (capicua).
Faça o mesmo com 12321:


```text
Saída esperada:
120345 invertido: 543021 (não é capicua)
12321 invertido: 12321 (é capicua)
```

**Dicas:**

1. invertido = invertido * 10 + n % 10; depois n /= 10. Repita enquanto n >
   0.
2. Guarde o original numa variável antes do laço, porque n vai virando 0.
3. Para o segundo número, zere o invertido antes de começar de novo.
4. Resposta esperada: 543021 e 12321.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0311.c
```

---

**Exercício P0312** · ★★☆ · Os dois ônibus no mesmo ponto

No terminal, o ônibus 101 sai a cada 12 minutos e o 202 a cada 18. Os dois
saíram juntos às 06:00. Escreva um programa que descubra, com um laço, daqui
a quantos minutos eles saem juntos de novo (o MMC de 12 e 18), e mostre os
três próximos horários em que isso acontece:


```text
Saída esperada:
Saem juntos a cada 36 minutos
06:36
07:12
07:48
```

**Dicas:**

1. Comece com t = 12 e vá somando 12 enquanto t % 18 != 0: o primeiro t que
   for múltiplo dos dois é o MMC.
2. Os horários são 6 * 60 + k * mmc, para k de 1 a 3, mostrados com %02d.
3. Resposta esperada: 36 minutos; 06:36, 07:12 e 07:48.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0312.c
```

---

**Exercício P0313** · ★★☆ · Os números amigos

Dois números são amigos quando a soma dos divisores próprios de um (os
divisores menores que ele) dá o outro, e vice-versa. Escreva um programa que
some os divisores próprios de 220 e de 284 com um laço e diga se eles são
amigos:


```text
Saída esperada:
Divisores de 220 somam 284
Divisores de 284 somam 220
220 e 284 são amigos
```

**Dicas:**

1. Para cada d de 1 a n - 1, se n % d == 0, some d.
2. Faça um laço para cada número (ou um laço de fora que rode duas vezes).
3. Resposta esperada: 284 e 220, são amigos.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0313.c
```

---

**Exercício P0314** · ★★☆ · O próximo ano primo

2026 não é primo (é par). Escreva um programa que ache o primeiro ano primo
depois de 2026 e o último ano primo antes de 2026. Para testar se n é primo,
basta tentar os divisores d com d * d <= n, e dá para parar no primeiro que
dividir (break):


```text
Saída esperada:
Próximo ano primo: 2027
Último ano primo antes de 2026: 2017
```

**Dicas:**

1. Um laço de fora anda pelos anos; um de dentro testa os divisores de 2 até
   d * d <= ano.
2. Use uma flag (bool primo = true) que vira false quando achar um divisor.
3. Para o anterior, o laço de fora anda para trás a partir de 2025.
4. Resposta esperada: 2027 e 2017.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0314.c
```

---

**Exercício P0315** · ★★☆ · A dívida do rotativo

Uma dívida de R$ 1000.00 no rotativo do cartão cresce 14% ao mês (juros sobre
juros). Escreva um programa com while que mostre o saldo mês a mês até a
dívida passar do dobro, e diga em quantos meses isso aconteceu:


```text
Saída esperada:
Mês 1: R$ 1140.00
Mês 2: R$ 1299.60
Mês 3: R$ 1481.54
Mês 4: R$ 1688.96
Mês 5: R$ 1925.41
Mês 6: R$ 2194.97
A dívida dobrou em 6 meses
```

**Dicas:**

1. while (divida <= 2 * inicial) { divida *= 1.14; mes++; ... }.
2. Não use pow aqui: o laço já multiplica um mês por vez.
3. Resposta esperada: A dívida dobrou em 6 meses.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0315.c
```

---

**Exercício P0316** · ★★☆ · O triângulo de Floyd

No triângulo de Floyd, os números naturais vão enchendo as linhas: a linha 1
tem um número, a linha 2 tem dois, e assim por diante. Escreva um programa
com laços aninhados que mostre as 5 primeiras linhas, cada número com %3d, e
a soma da última linha:


```text
Saída esperada:
  1
  2  3
  4  5  6
  7  8  9 10
 11 12 13 14 15
Soma da linha 5: 65
```

**Dicas:**

1. Um contador n começa em 1 e só cresce, fora dos dois laços.
2. O laço de dentro roda "linha" vezes: for (int col = 1; col <= linha;
   col++).
3. Zere a soma no começo de cada linha; no fim, ela tem a soma da última.
4. Resposta esperada: Soma da linha 5: 65.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0316.c
```

---

**Exercício P0317** · ★★☆ · A eleição do síndico

Na assembleia, cada morador digita o voto: 1 para a Marta, 2 para o Jorge e
qualquer outro número positivo é nulo. O 0 encerra a votação (sentinela).
Escreva um programa que conte os votos e mostre o resultado, o percentual de
nulos e quem venceu (ou se deu empate). Um exemplo de interação, com os
votos 1 2 1 7 1 2 0:


```text
Saída esperada:
Voto (0 encerra): Voto (0 encerra): Voto (0 encerra): Voto (0 encerra): Voto (0 encerra): Voto (0 encerra): Voto (0 encerra):
Marta: 3
Jorge: 2
Nulos: 1 (16.7%)
Vencedor: Marta
```

**Dicas:**

1. while (true): leia o voto; if (voto == 0) break; depois conte.
2. O percentual é nulos * 100.0 / total; cuidado com total 0.
3. Para testar sem digitar: printf '1\n2\n1\n7\n1\n2\n0\n' | ./rodar
   arquivo.c (as perguntas saem todas na mesma linha, porque o pipe não
   mostra o que foi digitado).
4. Resposta esperada: Marta 3, Jorge 2, Nulos 1 (16.7%), Vencedor: Marta.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0317.c
```

---

**Exercício P0318** · ★★☆ · A soma que demora a crescer

A soma 1 + 1/2 + 1/3 + 1/4 + ... cresce para sempre, mas bem devagar.
Escreva um programa com while que descubra quantos termos são precisos para
a soma passar de 3, e depois de 5, e mostre a soma em cada caso:


```text
Saída esperada:
Passa de 3 com 11 termos (soma 3.0199)
Passa de 5 com 83 termos (soma 5.0021)
```

**Dicas:**

1. soma += 1.0 / n; o 1.0 é o que faz a divisão ser real.
2. Dá para fazer um laço só: continue somando depois de passar de 3, e
   guarde o momento em que passou com uma flag.
3. Resposta esperada: 11 termos e 83 termos.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0318.c
```

---

**Exercício P0319** · ★★☆ · O desconto por quantidade

A distribuidora de água dá 2% de desconto por galão comprado, até o máximo de
15%. O galão custa R$ 12.00. Escreva um programa que mostre a tabela de 1 a
10 galões, com o desconto e o total de cada linha:


```text
Saída esperada:
 1 galão(ões):  2% -> R$  11.76
 2 galão(ões):  4% -> R$  23.04
 3 galão(ões):  6% -> R$  33.84
 4 galão(ões):  8% -> R$  44.16
 5 galão(ões): 10% -> R$  54.00
 6 galão(ões): 12% -> R$  63.36
 7 galão(ões): 14% -> R$  72.24
 8 galão(ões): 15% -> R$  81.60
 9 galão(ões): 15% -> R$  91.80
10 galão(ões): 15% -> R$ 102.00
```

**Dicas:**

1. O desconto da linha é 2 * qtd, mas se passar de 15 vira 15: um ternário
   resolve.
2. Total = qtd * 12.00 * (100 - desconto) / 100.0.
3. Resposta esperada: a tabela acima, terminando em R$ 102.00.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0319.c
```

---

**Exercício P0320** · ★★☆ · A média da turma que dá errado

O programa abaixo deveria somar as 5 notas do simulado (7, 9, 6, 8 e 10) e
mostrar a média 8.0, mas mostra 2.0. São dois erros de acumulador, de
propósito: um zera a soma no lugar errado e o outro faz a divisão inteira.
Conserte os dois:


```text
Saída esperada:
Soma: 40
Média: 8.0
```

**Dicas:**

1. Uma variável zerada dentro do laço é zerada em toda volta.
2. soma / 5 entre dois int corta a parte decimal. Use 5.0 ou um cast.
3. Resposta esperada: Soma: 40, Média: 8.0.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0320.c
```

## ★★★ Desafio

**Exercício P0321** · ★★★ · O calendário de qualquer mês

Escreva um programa que leia o mês e o ano e mostre o calendário daquele mês,
com a semana começando no domingo e cada dia em 3 posições (%3d). O programa
descobre sozinho em que dia da semana cai o dia 1, com a fórmula (a = (14 −
mês) / 12, y = ano − a, m = mês + 12a − 2, semana = (1 + y + y/4 − y/100 +
y/400 + 31m/12) % 7), e quantos dias o mês tem, com bissexto para fevereiro.
Repita a leitura até o mês valer de 1 a 12. No fim, mostre quantos sábados e
domingos o mês tem:


```text
Saída esperada:
Mês e ano: 2 2028
  D  S  T  Q  Q  S  S
          1  2  3  4  5
  6  7  8  9 10 11 12
 13 14 15 16 17 18 19
 20 21 22 23 24 25 26
 27 28 29
Fins de semana: 8 dias
```

**Dicas:**

1. Dias do mês: 31 por padrão; 30 em abril, junho, setembro e novembro;
   fevereiro tem 28 ou 29. Um switch com case empilhados resolve.
2. Antes do dia 1, um laço mostra "primeiro" vezes três espaços. Depois, um
   for nos dias; quebre a linha quando (primeiro + dia) % 7 == 0, e no fim só
   se a última linha não terminou num sábado.
3. O dia da semana de cada dia é (primeiro + dia - 1) % 7: 0 é domingo, 6 é
   sábado.
4. Resposta esperada: fevereiro de 2028 começa na terça e tem 29 dias; 8 dias
   de fim de semana.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0321.c
```

---

**Exercício P0322** · ★★★ · De decimal para qualquer base

Escreva um programa que leia um número inteiro positivo e uma base de 2 a 16
e mostre o número naquela base, com os dígitos de 10 a 15 como A a F. Ainda
não há vetores, então você não pode guardar os restos para mostrar ao
contrário: em vez disso, ache a maior potência da base que cabe no número e
vá descendo, mostrando um dígito por potência. Repita a pergunta da base até
ela valer de 2 a 16. Duas interações:


```text
Saída esperada:
Número e base: 2026 16
2026 na base 16: 7EA
```



```text
Número e base: 2026 2
2026 na base 2: 11111101010
```

**Dicas:**

1. potencia = 1; while (potencia <= n / base) potencia *= base; (dividir
   antes evita estourar o int).
2. Depois: while (potencia > 0) { digito = n / potencia; n %= potencia;
   potencia /= base; ... }.
3. Para mostrar o dígito: se for menor que 10, '0' + digito; senão, 'A' +
   digito - 10, com %c.
4. Resposta esperada: 7EA na base 16; 11111101010 na base 2; 2026 na base 8
   é 3752.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0322.c
```

---

**Exercício P0323** · ★★★ · Validação de CPF com laço

Escreva um programa que leia um CPF de 11 dígitos, só números, num long long,
e diga se ele é válido. Separe os dígitos com um laço. Regras: CPF com os 11
dígitos iguais é inválido; o 1º verificador vem dos 9 primeiros dígitos com
pesos de 10 a 2; o 2º vem dos 10 primeiros com pesos de 11 a 2; em cada um,
r = soma % 11 e o dígito é 0 se r < 2, senão 11 − r. Três interações:


```text
Saída esperada:
CPF (11 dígitos): 11144477735
CPF válido
```



```text
CPF (11 dígitos): 11144477734
CPF inválido: o 2º dígito deveria ser 5
```



```text
CPF (11 dígitos): 22222222222
CPF inválido: dígitos todos iguais
```

**Dicas:**

1. O dígito na posição p (1 é o mais à esquerda) é cpf / 10^(11 - p) % 10.
   Num laço, vá dividindo uma potência de 10 que começa em 10000000000.
2. Some soma1 nas posições 1 a 9 e soma2 nas posições 1 a 10, com os pesos
   11 - p e 12 - p.
3. Para os dígitos iguais, compare cada dígito com o primeiro e use uma flag.
4. Resposta esperada: as três saídas acima.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0323.c
```

---

**Exercício P0324** · ★★★ · Os primos até 10 000

Sem vetor, não dá para montar o crivo de Eratóstenes, mas dá para testar cada
número com a versão econômica: descarte os pares (fora o 2) e tente só os
divisores ímpares d com d * d <= n. Escreva um programa que conte os primos
até 10 000, mostre o maior deles e o maior buraco entre dois primos
seguidos (e quais são eles):


```text
Saída esperada:
Primos até 10000: 1229
Maior primo: 9973
Maior buraco: 36, entre 9551 e 9587
```

**Dicas:**

1. Comece contando o 2 e ande de n = 3 em n += 2.
2. Guarde o último primo encontrado (anterior). A cada novo primo, compare
   n - anterior com o maior buraco até agora.
3. Use break no laço dos divisores assim que achar um.
4. Resposta esperada: 1229 primos, maior 9973, buraco de 36 entre 9551 e
   9587.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0324.c
```

---

**Exercício P0325** · ★★★ · A rotina de Kaprekar

Pegue um número de 4 dígitos que não tenha os quatro iguais. Ordene os
dígitos do maior para o menor e do menor para o maior, e subtraia. Repita com
o resultado (mantendo zeros à esquerda, como em 0378). Em no máximo 7 passos
você chega em 6174 e fica lá para sempre. Escreva um programa que mostre os
passos a partir de 3524. Ainda sem vetor, para ordenar os dígitos, ande pelos
valores de 9 a 0 e, para cada valor, conte quantas vezes ele aparece:


```text
Saída esperada:
5432 - 2345 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174
Chegou em 6174 em 3 passos
```

**Dicas:**

1. Para montar o maior: para v de 9 a 0, para cada um dos 4 dígitos de n (n
   % 10, n / 10 % 10, ...), se o dígito for v, maior = maior * 10 + v.
2. O menor é o mesmo laço com v de 0 a 9.
3. Mostre com %04d para manter os zeros à esquerda.
4. Resposta esperada: 3 passos até 6174.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0325.c
```

---

**Exercício P0326** · ★★★ · A tabela do empréstimo

Você pegou R$ 1200.00 emprestado em 6 parcelas iguais, com juros de 2% ao
mês (tabela Price). A parcela é P = V · i / (1 − (1 + i)^−n). Todo mês, os
juros são i vezes o saldo devedor, e o resto da parcela amortiza a dívida.
Escreva um programa que mostre a tabela mês a mês e, no fim, o total pago e
o total de juros:


```text
Saída esperada:
Parcela: R$ 214.23
Mês  Juros   Amortização  Saldo
 1   24.00      190.23   1009.77
 2   20.20      194.04    815.73
 3   16.31      197.92    617.82
 4   12.36      201.87    415.94
 5    8.32      205.91    210.03
 6    4.20      210.03      0.00
Total pago: R$ 1285.39
Total de juros: R$ 85.39
```

**Dicas:**

1. pow(1 + i, -n) faz o (1 + i) elevado a −n.
2. Dentro do laço: juros = saldo * i; amortizacao = parcela - juros; saldo
   -= amortizacao; some os juros num acumulador.
3. No último mês, o saldo pode dar -0.00 por causa do arredondamento: use
   fabs(saldo) < 0.005 para mostrar 0.00.
4. Resposta esperada: Total de juros: R$ 85.39.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0326.c
```

---

**Exercício P0327** · ★★★ · O juro escondido no parcelamento

A loja anuncia uma TV de R$ 1000.00 "em 10 vezes de R$ 120.00". Qual é o juro
mensal escondido? Não há fórmula direta, mas dá para achar por bissecção: a
parcela P(i) = V · i / (1 − (1 + i)^−n) cresce com i. Comece com a taxa entre
0.0001 e 1 (0,01% e 100%), teste o meio, e jogue fora a metade em que a
resposta não está, até o intervalo ficar menor que 0.0000001. Mostre a taxa
e quantas voltas foram precisas:


```text
Saída esperada:
Taxa mensal: 3.46%
Voltas da bissecção: 24
Conferindo: parcela de R$ 120.00
```

**Dicas:**

1. while (alto - baixo > 0.0000001) { meio = (baixo + alto) / 2; ... }.
2. Se a parcela com a taxa do meio passa de 120, a taxa certa é menor: alto
   = meio. Senão, baixo = meio.
3. Para conferir, calcule a parcela de novo com a taxa achada.
4. Resposta esperada: Taxa mensal: 3.46%.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0327.c
```

---

**Exercício P0328** · ★★★ · As datas palíndromas do século

A data 12/02/2021, escrita como 12022021, se lê igual de trás para frente.
Escreva um programa que ache todas as datas palíndromas (ddmmaaaa) de 2000 a
2099. Para cada ano, inverta os 4 dígitos: os dois primeiros do inverso são o
dia, os dois últimos são o mês. Mostre só as datas que existem de verdade
(mês de 1 a 12, dia dentro do mês, fevereiro com bissexto) e quantas são:


```text
Saída esperada:
10/02/2001
20/02/2002
01/02/2010
11/02/2011
21/02/2012
02/02/2020
12/02/2021
22/02/2022
03/02/2030
13/02/2031
23/02/2032
04/02/2040
14/02/2041
24/02/2042
05/02/2050
15/02/2051
25/02/2052
06/02/2060
16/02/2061
26/02/2062
07/02/2070
17/02/2071
27/02/2072
08/02/2080
18/02/2081
28/02/2082
09/02/2090
19/02/2091
29/02/2092
Datas palíndromas no século: 29
```

**Dicas:**

1. O inverso de 2021 é 1202: dia = inverso / 100 = 12, mês = inverso % 100 =
   02.
2. Em 2000 a 2099 o mês sai sempre 02 (fevereiro), mas o programa tem que
   conferir mesmo assim.
3. 29/02/2092 só vale porque 2092 é bissexto.
4. Resposta esperada: 29 datas, de 10/02/2001 a 29/02/2092.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0328.c
```

---

**Exercício P0329** · ★★★ · Monty Hall no programa de auditório

No programa de auditório, há 3 portas e um carro atrás de uma delas. Você
escolhe uma porta; o apresentador, que sabe onde está o carro, abre outra
porta com um bode; e pergunta se você quer trocar. Escreva uma simulação com
rand de 1 000 000 de rodadas que conte quantas vezes você ganharia ficando e
quantas ganharia trocando, e mostre os percentuais sem casas decimais:


```text
Saída esperada:
Rodadas: 1000000
Ficando: 33% de vitórias
Trocando: 67% de vitórias
```

**Dicas:**

1. Sorteie o carro e a escolha com rand() % 3. Quem fica ganha quando
   escolha == carro.
2. Quem troca ganha exatamente quando quem fica perde: o apresentador sempre
   tira o outro bode. Não precisa simular a porta aberta.
3. srand((unsigned) time(NULL)) antes do laço. Com um milhão de rodadas, os
   percentuais arredondados saem sempre os mesmos.
4. Resposta esperada: 33% ficando, 67% trocando.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0329.c
```

---

**Exercício P0330** · ★★★ · O triângulo de Pascal

No triângulo de Pascal, cada número é a soma dos dois de cima. Sem vetor, dá
para calcular cada linha da esquerda para a direita: o primeiro é 1, e o
próximo é c = c * (n − k) / (k + 1), onde n é o número da linha (começando
em 0) e k a posição. Escreva um programa que mostre as 7 primeiras linhas,
centralizadas (2 espaços por linha que falta), cada número com %4d, e a soma
de cada linha:


```text
Saída esperada:
               1   (soma 1)
             1   1   (soma 2)
           1   2   1   (soma 4)
         1   3   3   1   (soma 8)
       1   4   6   4   1   (soma 16)
     1   5  10  10   5   1   (soma 32)
   1   6  15  20  15   6   1   (soma 64)
```

**Dicas:**

1. Antes dos números, a linha n tem (6 - n) * 2 espaços.
2. Faça a multiplicação antes da divisão: c * (n - k) / (k + 1) sempre dá
   exato nessa ordem.
3. A soma da linha n é 2 elevado a n: confira com a sua.
4. Resposta esperada: a última linha é 1 6 15 20 15 6 1, soma 64.

```bash
~/LPEDC/rodar 03-repeticoes/lista/P0330.c
```

<!-- Gerado por _gerador a partir dos arquivos P????.c desta pasta. -->

# Lista prática · Módulo 02 · Decisões

30 exercícios de codificar que treinam o módulo inteiro, misturando os assuntos, no ritmo da prova do PPGI (veja [PPGI.md](../../PPGI.md)). Cada arquivo `P????.c` desta pasta é um exercício: a resposta vai dentro dele, embaixo de `// Escreva sua resposta abaixo:`. Uma resolução de cada um está em `_respostas/02-condicionais/lista/`. Só olhe depois de tentar.

[Voltar ao módulo](../README.md)

## ★☆☆ Aquecimento

**Exercício P0201** · ★☆☆ · O rodízio de placas

No rodízio de carros, o último dígito da placa decide o dia em que o carro não
roda: 1 e 2 na segunda, 3 e 4 na terça, 5 e 6 na quarta, 7 e 8 na quinta, 9
e 0 na sexta. A placa do seu carro termina em 4827. Escreva um programa que
pegue o último dígito com % e use um switch com case empilhados para mostrar
o dia:


```text
Saída esperada:
Final da placa: 7
Rodízio na quinta-feira
```

**Dicas:**

1. O último dígito é numero % 10.
2. Empilhe os case sem break entre eles: case 7: case 8: printf(...);
   break;
3. Resposta esperada: Rodízio na quinta-feira.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0201.c
```

---

**Exercício P0202** · ★☆☆ · A multa da biblioteca

A biblioteca cobra R$ 1.50 por dia de atraso na devolução. Escreva um
programa que leia quantos dias o livro atrasou e mostre a multa; se não
atrasou (0 dias), mostre "Sem multa." Um exemplo de interação:


```text
Saída esperada:
Dias de atraso: 4
Multa: R$ 6.00
```

**Dicas:**

1. Um if com a condição dias > 0 e um else.
2. A multa é dias * 1.50.
3. Resposta esperada: com 4 dias, Multa: R$ 6.00; com 0, Sem multa.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0202.c
```

---

**Exercício P0203** · ★☆☆ · O ingresso do sócio-torcedor

No jogo do Manaus FC, o ingresso custa R$ 60.00, e sócio-torcedor paga
metade. Escreva um programa com duas variáveis bool, carla_socia = true e
beto_socio = false, e calcule o preço de cada um com o operador ternário
(nenhum if):


```text
Saída esperada:
Carla paga R$ 30.00
Beto paga R$ 60.00
```

**Dicas:**

1. bool, true e false vêm de stdbool.h.
2. double preco = socio ? 60.00 / 2 : 60.00;
3. Resposta esperada: R$ 30.00 e R$ 60.00.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0203.c
```

---

**Exercício P0204** · ★☆☆ · A bandeira da conta de luz

A conta de luz custa R$ 0.80 por kWh, mais um adicional por bandeira a cada
100 kWh: verde ('V') R$ 0.00, amarela ('A') R$ 1.885, vermelha 1 ('R')
R$ 4.463 e vermelha 2 ('P') R$ 7.877. Neste mês a casa gastou 220 kWh com
bandeira amarela. Escreva um programa com char bandeira = 'A'; que escolha o
adicional com um switch e mostre a conta:


```text
Saída esperada:
Consumo: 220 kWh
Adicional da bandeira: R$ 4.15
Total: R$ 180.15
```

**Dicas:**

1. Os case de um switch em char usam aspas simples: case 'A':.
2. O adicional é consumo / 100.0 * valor_da_bandeira.
3. Resposta esperada: Total: R$ 180.15.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0204.c
```

---

**Exercício P0205** · ★☆☆ · Pode doar sangue?

Para doar sangue, a pessoa precisa ter de 16 a 69 anos e pesar pelo menos
50 kg. Escreva um programa com os dados de duas pessoas, Ana (17 anos, 52 kg)
e Rui (72 anos, 80 kg), que guarde a resposta de cada uma numa variável bool
e mostre "sim" ou "não":


```text
Saída esperada:
Ana pode doar? sim
Rui pode doar? não
```

**Dicas:**

1. bool ana_pode = idade >= 16 && idade <= 69 && peso >= 50;
2. Para mostrar, use o ternário: ana_pode ? "sim" : "não", com %s.
3. Resposta esperada: Ana sim, Rui não.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0205.c
```

---

**Exercício P0206** · ★☆☆ · O Pix que passou do saldo

Você tem R$ 150.00 na conta e mandou um Pix de R$ 200.00 usando o cheque
especial. Escreva um programa que desconte o Pix do saldo e, se o saldo
ficou negativo, mostre o saldo e os juros de 8% sobre o que ficou devendo;
senão, mostre só o saldo:


```text
Saída esperada:
Saldo: R$ -50.00
Você entrou no cheque especial.
Juros do mês: R$ 4.00
```

**Dicas:**

1. saldo = saldo - pix; depois, if (saldo < 0).
2. O que a pessoa deve é -saldo. Os juros são -saldo * 0.08.
3. Resposta esperada: Juros do mês: R$ 4.00.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0206.c
```

---

**Exercício P0207** · ★☆☆ · O radar da avenida

O radar da avenida marca 60 km/h. Até 60, nada acontece. Acima de 60 até 72
(20% a mais), a infração é média: R$ 130.16. Acima de 72 até 90 (50% a mais),
é grave: R$ 195.23. Acima de 90, gravíssima: R$ 880.41. Escreva um programa
que leia a velocidade (inteira) e mostre a infração com else if:


```text
Saída esperada:
Velocidade (km/h): 75
Infração grave: R$ 195.23
```

**Dicas:**

1. Teste do menor para o maior: if (v <= 60) ... else if (v <= 72) ...
2. Num else if, você já sabe que as condições de cima falharam: não precisa
   repetir v > 60.
3. Resposta esperada: com 75, Infração grave: R$ 195.23.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0207.c
```

---

**Exercício P0208** · ★☆☆ · A recarga do cartão do ônibus

A máquina de recarga pede quantas passagens de R$ 4.50 você quer. Se a
pessoa digitar algo que não é número, o scanf não lê nada. Escreva um
programa que confira o retorno do scanf: se não for 1, mostre "Entrada
inválida." e termine com return 1; se for, mostre o valor da recarga.
Duas interações:


```text
Saída esperada:
Quantas passagens? abc
Entrada inválida.
```



```text
Quantas passagens? 10
Recarga: R$ 45.00
```

**Dicas:**

1. if (scanf("%d", &passagens) != 1) { ... return 1; }
2. Para testar: printf 'abc\n' | ./rodar arquivo.c e depois com 10.
3. Resposta esperada: "Entrada inválida." com abc; R$ 45.00 com 10.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0208.c
```

---

**Exercício P0209** · ★☆☆ · O troco que não bate

O caixa somou duas moedas de R$ 0.10 e R$ 0.20 e comparou com R$ 0.30 usando
==. O programa abaixo diz que o troco está errado, mas a conta está certa: o
problema é a comparação de double, e ela está assim de propósito. Conserte o
if: considere iguais os valores que diferem menos de 0.000001 (use fabs):


```text
Saída esperada:
Soma: 0.30000000000000004
Troco certo.
```

**Dicas:**

1. 0.1 e 0.2 não cabem exatos em binário: a soma fica um pouquinho acima de
   0.3. Por isso o == falha.
2. if (fabs(soma - esperado) < 0.000001), com math.h.
3. Resposta esperada: Troco certo.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0209.c
```

---

**Exercício P0210** · ★☆☆ · O drone na área liberada

O drone de filmagem só pode voar no retângulo liberado pela prefeitura, que
vai de x = 0 a x = 200 e de y = 0 a y = 120 (metros), bordas incluídas.
Escreva um programa que diga, para o drone em (150, 130) e depois em
(200, 45), se ele está dentro ou fora da área:


```text
Saída esperada:
Drone em (150, 130): fora da área
Drone em (200, 45): dentro da área
```

**Dicas:**

1. Dentro quer dizer x >= 0 && x <= 200 && y >= 0 && y <= 120.
2. Repita o teste para a segunda posição, ou reaproveite as variáveis x e y.
3. Resposta esperada: fora, depois dentro (200 está na borda, e a borda vale).

```bash
~/LPEDC/rodar 02-condicionais/lista/P0210.c
```

## ★★☆ Para pensar

**Exercício P0211** · ★★☆ · A nota do jurado do meio

No festival de quadrilha, três jurados dão notas e vale a nota do meio (a
mediana): nem a maior, nem a menor. Os jurados deram 7.5, 9.0 e 8.0.
Escreva um programa que descubra a nota do meio com if e else if, sem
ordenar nada:


```text
Saída esperada:
Notas: 7.5 9.0 8.0
Nota do meio: 8.0
```

**Dicas:**

1. a é a do meio quando (a >= b && a <= c) || (a <= b && a >= c).
2. Teste a, depois b; se nenhum dos dois for o do meio, é c.
3. Resposta esperada: Nota do meio: 8.0.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0211.c
```

---

**Exercício P0212** · ★★☆ · A integração do ônibus

A passagem custa R$ 4.50, e a segunda viagem é de graça se começar até 120
minutos depois da primeira. Você embarcou às 07:40 e pegou o segundo ônibus
às 09:25. Escreva um programa que converta os dois horários para minutos
desde a meia-noite, calcule o intervalo e mostre quanto a segunda viagem
custa:


```text
Saída esperada:
Intervalo: 105 min
Integração: a segunda viagem sai por R$ 0.00
```

**Dicas:**

1. minutos = hora * 60 + minuto, para cada embarque.
2. if (intervalo <= 120) a viagem é grátis; senão, paga R$ 4.50.
3. Resposta esperada: 105 min, R$ 0.00.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0212.c
```

---

**Exercício P0213** · ★★☆ · A divisão por zero do estoque

A loja quer avisar quando o pedido é maior que o dobro do estoque. O programa
abaixo testa pedido / estoque >= 2 e, com estoque zerado, divide por zero e
quebra. O bug está lá de propósito. Conserte só a condição, usando o
curto-circuito do &&, para que a divisão nunca aconteça com estoque 0:


```text
Saída esperada:
Estoque: 0, pedido: 5
Sem estoque: avise o cliente.
```

**Dicas:**

1. Em a && b, se a for falso, o C nem calcula b.
2. Ponha estoque > 0 ANTES da divisão: estoque > 0 && pedido / estoque >= 2.
3. Resposta esperada: Sem estoque: avise o cliente.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0213.c
```

---

**Exercício P0214** · ★★☆ · O financiamento aprovado

O programa abaixo aprova o financiamento com três if aninhados: renda de pelo
menos R$ 3000, idade de 18 a 65 anos e nome limpo. Ele funciona, mas é
difícil de ler. Refatore: troque os três if por um if só, com && e ||, e um
else. A saída tem que continuar a mesma:


```text
Saída esperada:
Renda: R$ 4200.00, idade: 34, nome limpo: 1
Financiamento aprovado.
```

**Dicas:**

1. As três condições têm que valer ao mesmo tempo: junte com &&.
2. Os três else do original mostram a mesma mensagem: no novo, um else só.
3. Resposta esperada: Financiamento aprovado.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0214.c
```

---

**Exercício P0215** · ★★☆ · Que horas são em Manaus?

O Brasil tem quatro fusos: Fernando de Noronha ('F', uma hora a mais que
Brasília), Brasília ('B'), Manaus ('M', uma a menos) e Acre ('A', duas a
menos). O jogo começa às 23:30 de Brasília. Escreva um programa que leia a
letra do fuso e mostre a hora local, com um switch para achar a diferença e
% 24 para a hora não passar de 23 nem ficar negativa:


```text
Saída esperada:
Fuso (F, B, M ou A): F
Hora local: 00:30
```

**Dicas:**

1. Leia a letra com scanf(" %c", &fuso). O espaço antes do %c pula o Enter
   e os espaços que sobraram.
2. hora_local = (23 + diferenca + 24) % 24. O + 24 evita resto negativo.
3. Resposta esperada: F dá 00:30; M dá 22:30; A dá 21:30.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0215.c
```

---

**Exercício P0216** · ★★☆ · O cupom da loja virtual

A regra da promoção é: o cupom vale para cliente VIP ou para compra acima de
R$ 100, mas em qualquer caso só se o cupom não estiver vencido. O programa
abaixo dá desconto para um VIP com cupom vencido, porque o && é feito antes
do ||. O erro está lá de propósito: conserte a condição com parênteses:


```text
Saída esperada:
Compra: R$ 80.00, VIP: 1, cupom vencido: 1
Cupom recusado.
```

**Dicas:**

1. vip || compra > 100 && !vencido é lido como vip || (compra > 100 &&
   !vencido).
2. Agrupe o que vem antes do "mas": (vip || compra > 100) && !vencido.
3. Resposta esperada: Cupom recusado.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0216.c
```

---

**Exercício P0217** · ★★☆ · A bandeira 2 do táxi

O táxi cobra R$ 5.50 de bandeirada mais o km rodado: R$ 3.20 na bandeira 1 e
R$ 3.84 na bandeira 2. A bandeira 2 vale aos domingos (dia 0) e, em qualquer
dia, das 20h às 6h (hora >= 20 ou hora < 6). Escreva um programa para uma
corrida de 8.5 km numa quarta-feira (dia 3) às 21h:


```text
Saída esperada:
Bandeira 2
Corrida de 8.5 km: R$ 38.14
```

**Dicas:**

1. int bandeira = (dia == 0 || hora >= 20 || hora < 6) ? 2 : 1;
2. Depois, o preço por km sai de outro ternário (ou de um if).
3. Resposta esperada: Bandeira 2, R$ 38.14.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0217.c
```

---

**Exercício P0218** · ★★☆ · O ícone da bateria

O celular mostra a bateria como "cheia" (80% ou mais), "ok" (de 20% a 79%) ou
"baixa" (menos de 20%). Escreva um programa que classifique 95, 47 e 12 por
cento usando um ternário encadeado (um ternário dentro do outro), sem if:


```text
Saída esperada:
95%: cheia
47%: ok
12%: baixa
```

**Dicas:**

1. nivel >= 80 ? "cheia" : (nivel >= 20 ? "ok" : "baixa").
2. Guarde cada resultado num const char *, ou ponha o ternário direto no
   printf com %s.
3. Resposta esperada: cheia, ok e baixa.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0218.c
```

---

**Exercício P0219** · ★★☆ · Pedra, papel, tesoura, lagarto, Spock

Numere as jogadas assim: 0 pedra, 1 Spock, 2 papel, 3 lagarto, 4 tesoura.
Nessa ordem, cada jogada vence as duas que vêm antes dela, dando a volta: se
d = (a − b + 5) % 5, então d = 0 é empate, d = 1 ou 2 o jogador A vence, e
d = 3 ou 4 o B vence. Escreva um programa que leia as duas jogadas e mostre
o resultado com um switch em d:


```text
Saída esperada:
Jogada de A (0 a 4): 4
Jogada de B (0 a 4): 3
A vence!
```

**Dicas:**

1. O + 5 evita resto negativo quando b é maior que a.
2. No switch, empilhe case 1: case 2: para A e case 3: case 4: para B.
3. Confira antes se as jogadas estão entre 0 e 4.
4. Resposta esperada: 4 (tesoura) contra 3 (lagarto): A vence!

```bash
~/LPEDC/rodar 02-condicionais/lista/P0219.c
```

---

**Exercício P0220** · ★★☆ · Poupança ou CDB?

Você tem R$ 5000.00 para guardar por 6 meses. A poupança rende 0.5% ao mês e
não paga imposto. O CDB rende 0.9% ao mês, mas paga 22.5% de imposto sobre o
rendimento. Escreva um programa que calcule o rendimento líquido de cada um
(juros compostos com pow) e diga qual vale mais:


```text
Saída esperada:
Poupança: R$ 151.89
CDB: R$ 214.02
Melhor opção: CDB
```

**Dicas:**

1. Rendimento bruto = valor * pow(1 + taxa, meses) - valor.
2. No CDB, o líquido é bruto * (1 - 0.225).
3. Resposta esperada: Melhor opção: CDB.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0220.c
```

## ★★★ Desafio

**Exercício P0221** · ★★★ · Que dia do ano é a prova

A prova do PPGI é em 27/11/2026. Escreva um programa que descubra que dia do
ano é essa data (1º de janeiro é o dia 1) com um switch no mês que usa o
fall-through de propósito: comece no case do mês anterior ao da data e vá
somando os dias de cada mês até janeiro. Mostre também quantos dias faltam
para o ano acabar:


```text
Saída esperada:
27/11/2026 é o dia 331 do ano
Faltam 34 dias para o ano acabar
```

**Dicas:**

1. Comece com total = dia. Faça switch (mes - 1): case 11: total += 30;
   case 10: total += 31; ... case 1: total += 31; sem break, com o
   comentário // fall through para o gcc não avisar.
2. Fevereiro soma 28, ou 29 se o ano for bissexto (ano % 4 == 0 && ano % 100
   != 0) || ano % 400 == 0.
3. Faltam (dias do ano) - total, e o ano tem 365 ou 366 dias.
4. Resposta esperada: dia 331, faltam 34 dias.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0221.c
```

---

**Exercício P0222** · ★★★ · A data por extenso

O sistema da secretaria quer a data por extenso, com o dia da semana. Escreva
um programa que leia uma data no formato dd/mm/aaaa, confira se o scanf leu
os três números e se o mês vai de 1 a 12, descubra o dia da semana com a
fórmula (a = (14 − mês) / 12, y = ano − a, m = mês + 12a − 2, semana = (dia
+ y + y/4 − y/100 + y/400 + 31m/12) % 7, com 0 = domingo) e mostre tudo por
extenso, com um switch para o mês e outro para o dia da semana:


```text
Saída esperada:
Data (dd/mm/aaaa): 27/11/2026
27 de novembro de 2026, sexta-feira
```

**Dicas:**

1. scanf("%d/%d/%d", &dia, &mes, &ano) devolve 3 quando deu tudo certo.
2. Cada switch só faz printf("janeiro"), printf("fevereiro")... e break.
3. Com 07/09/2026: 7 de setembro de 2026, segunda-feira.
4. Resposta esperada: 27 de novembro de 2026, sexta-feira.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0222.c
```

---

**Exercício P0223** · ★★★ · O placar do set de vôlei

Um set de vôlei acaba quando um time chega a 25 pontos com pelo menos 2 de
vantagem; se empatar em 24, o jogo segue até alguém abrir 2 (26 × 24, 27 ×
25...). Escreva um programa que leia o placar dos times A e B e diga se o set
está em andamento, quem venceu, ou se o placar é impossível (negativo, ou
acima de 25 com mais de 2 de diferença, como 27 × 20, porque o set teria
acabado antes). Três interações:


```text
Saída esperada:
Placar (A B): 25 23
Set do time A (25 x 23)
```



```text
Placar (A B): 25 24
Set em andamento
```



```text
Placar (A B): 27 20
Placar impossível
```

**Dicas:**

1. Calcule o maior, o menor e a diferença com ternários; depois decida só
   olhando para eles.
2. Ordem dos testes: negativo → impossível; maior < 25 ou diferença < 2 →
   em andamento; maior > 25 e diferença > 2 → impossível; senão, acabou.
3. O vencedor é A se a > b, senão B.
4. Resposta esperada: as três saídas acima.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0223.c
```

---

**Exercício P0224** · ★★★ · O desempate do campeonato

No campeonato, a classificação desempata nesta ordem: pontos, vitórias, saldo
de gols (gols pró − gols contra) e gols pró. Se tudo empatar, vale o sorteio.
O Manaus FC fez 58 pontos, 17 vitórias, 50 gols pró e 31 contra. O Amazonas
FC fez 58 pontos, 17 vitórias, 54 gols pró e 35 contra. Escreva um programa
que diga quem fica na frente e qual critério decidiu:


```text
Saída esperada:
Manaus FC: 58 pts, 17 V, saldo 19, 50 GP
Amazonas FC: 58 pts, 17 V, saldo 19, 54 GP
Na frente: Amazonas FC (critério: gols pró)
```

**Dicas:**

1. Uma cadeia de else if: primeiro if (p1 != p2), depois if (v1 != v2), e
   assim por diante. Cada ramo diz quem ganhou com um ternário.
2. Calcule o saldo antes da cadeia.
3. Resposta esperada: Na frente: Amazonas FC (critério: gols pró).

```bash
~/LPEDC/rodar 02-condicionais/lista/P0224.c
```

---

**Exercício P0225** · ★★★ · Choque de horários na agenda

A agenda precisa avisar quando dois compromissos se sobrepõem. Escreva um
programa que leia o início e o fim de dois compromissos no formato hh:mm e
mostre se há conflito e de quantos minutos. Encostar (um acaba às 10:00 e o
outro começa às 10:00) não é conflito. Duas interações:


```text
Saída esperada:
Compromisso 1 (início fim): 14:00 15:30
Compromisso 2 (início fim): 15:00 16:00
Conflito de 30 minutos
```



```text
Compromisso 1 (início fim): 09:00 10:00
Compromisso 2 (início fim): 10:00 11:00
Sem conflito
```

**Dicas:**

1. Leia com scanf("%d:%d %d:%d", ...) e passe tudo para minutos.
2. A sobreposição começa no maior dos inícios e termina no menor dos fins.
   Use ternários para achar os dois.
3. Se fim_comum > inicio_comum, há conflito de (fim_comum - inicio_comum)
   minutos.
4. Resposta esperada: 30 minutos no primeiro caso; sem conflito no segundo.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0225.c
```

---

**Exercício P0226** · ★★★ · O caixa eletrônico com poucas notas

O caixa eletrônico tem só 2 notas de R$ 50, 10 de R$ 20 e 3 de R$ 10.
Escreva um programa que leia o valor do saque e pague com as notas maiores
primeiro, sem passar do que existe de cada uma. Se não der para pagar o
valor exato, mostre "Sem notas para esse valor." Sem laço: para cada nota,
use = menor entre (resto / nota) e as notas que existem. Duas interações:


```text
Saída esperada:
Saque: 290
2 x R$ 50
9 x R$ 20
1 x R$ 10
```



```text
Saque: 380
Sem notas para esse valor.
```

**Dicas:**

1. int usa50 = resto / 50 < 2 ? resto / 50 : 2; e depois resto -= usa50 * 50.
2. No fim, se o resto não for 0, faltaram notas.
3. Mostre só as notas que forem usadas (quantidade maior que 0).
4. Resposta esperada: 2 x 50, 9 x 20 e 1 x 10 para 290; sem notas para 380.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0226.c
```

---

**Exercício P0227** · ★★★ · O ano em algarismos romanos

A placa da praça mostra o ano da fundação em algarismos romanos. Escreva um
programa que leia um ano de 1 a 3999 e mostre em romanos. Sem laço: separe
milhar, centena, dezena e unidade com / e %, e use um switch para cada casa
(as centenas usam C, D e M; as dezenas, X, L e C; as unidades, I, V e X):


```text
Saída esperada:
Ano (1 a 3999): 2026
MMXXVI
```

**Dicas:**

1. O milhar só vai de 0 a 3: M, MM ou MMM.
2. Em cada casa os 10 casos seguem o mesmo molde: 4 é IV, 9 é IX; com as
   letras da casa: 40 é XL, 900 é CM.
3. Confira o retorno do scanf e a faixa de 1 a 3999.
4. Com 1999: MCMXCIX. Resposta esperada para 2026: MMXXVI.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0227.c
```

---

**Exercício P0228** · ★★★ · O saque-aniversário do FGTS

No saque-aniversário, o valor liberado depende do saldo, numa tabela de
alíquota mais parcela fixa:


```text
até R$ 500.00             50%  + R$ 0.00
de 500.01 a 1000.00       40%  + R$ 50.00
de 1000.01 a 5000.00      30%  + R$ 150.00
de 5000.01 a 10000.00     20%  + R$ 650.00
de 10000.01 a 15000.00    15%  + R$ 1150.00
de 15000.01 a 20000.00    10%  + R$ 1900.00
acima de 20000.00          5%  + R$ 2900.00
```


Escreva um programa que leia o saldo, confira a leitura e se o saldo não é
negativo, e mostre a faixa, a alíquota e o valor do saque:


```text
Saída esperada:
Saldo do FGTS: 3200.00
Faixa 3: 30% + R$ 150.00
Saque liberado: R$ 1110.00
```

**Dicas:**

1. Uma cadeia de else if, do menor limite para o maior, guardando faixa,
   aliquota e parcela em variáveis.
2. Faça a conta só uma vez, depois da cadeia: saldo * aliquota + parcela.
3. Para mostrar o %, use %% no printf.
4. Resposta esperada: com 3200.00, Saque liberado: R$ 1110.00.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0228.c
```

---

**Exercício P0229** · ★★★ · A tarifa do aplicativo de corrida

O aplicativo de corrida calcula assim: R$ 4.00 fixos, mais R$ 1.80 por km e
R$ 0.35 por minuto. A tarifa dinâmica multiplica tudo por 1.5 quando está
chovendo ou quando é sexta (5) ou sábado (6) a partir das 22h. A corrida
nunca sai por menos de R$ 9.00. Por fim, o cupom dá 10% de desconto, mas no
máximo R$ 8.00. Escreva o programa para uma corrida de 10 km e 20 minutos,
num sábado às 23h, sem chuva, com cupom:


```text
Saída esperada:
Preço base: R$ 29.00
Dinâmica: sim (x1.5)
Antes do cupom: R$ 43.50
Desconto do cupom: R$ 4.35
Total: R$ 39.15
```

**Dicas:**

1. bool dinamica = chovendo || ((dia == 5 || dia == 6) && hora >= 22); os
   parênteses importam.
2. Aplique na ordem: dinâmica, mínimo de R$ 9.00, cupom.
3. O desconto é preco * 0.10, mas se passar de 8.00 vira 8.00 (um ternário
   resolve).
4. Resposta esperada: Total: R$ 39.15.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0229.c
```

---

**Exercício P0230** · ★★★ · A senha de 4 dígitos do app

O app do banco recusa senhas fracas de 4 dígitos (0000 a 9999). A senha é
fraca se tiver os quatro dígitos iguais (7777), se for uma sequência
crescente (1234, 3456) ou decrescente (9876), ou se parecer um ano entre
1950 e 2026. Escreva um programa que leia a senha como int, separe os
dígitos com / e % e diga se ela é aceita ou qual regra ela quebrou (a
primeira que falhar, nessa ordem). Três interações:


```text
Saída esperada:
Senha: 1234
Senha fraca: sequência crescente
```



```text
Senha: 1987
Senha fraca: parece um ano
```



```text
Senha: 4071
Senha aceita
```

**Dicas:**

1. d1 = s / 1000, d2 = s / 100 % 10, d3 = s / 10 % 10, d4 = s % 10.
2. Crescente: d2 == d1 + 1 && d3 == d2 + 1 && d4 == d3 + 1.
3. Confira primeiro se o scanf leu e se a senha está entre 0 e 9999.
4. Resposta esperada: as três saídas acima.

```bash
~/LPEDC/rodar 02-condicionais/lista/P0230.c
```

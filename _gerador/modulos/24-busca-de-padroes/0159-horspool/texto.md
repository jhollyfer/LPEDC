## 0159 · Horspool

Na feira, você passa os olhos pelas placas procurando "MANGA". Ninguém lê letra
por letra: você bate o olho numa placa, vê que ela termina com uma letra que
nem existe em "MANGA" e já pula para a próxima. A força bruta e o KMP leem
todas as letras do texto. Dá para ler **menos**?

Dá, e o truque é comparar o padrão **da direita para a esquerda**. Encoste o
padrão no texto e olhe primeiro a letra que está sob a **última** casa dele. Se
essa letra nem aparece no padrão, nenhum alinhamento que a cubra pode dar
certo, e o padrão inteiro pula para depois dela: `m` casas de uma vez.

Se a letra aparece no padrão, o salto é menor: o suficiente para levar a
ocorrência **mais à direita** dela no padrão até ficar embaixo dessa mesma
letra do texto. Esse é o algoritmo de **Horspool** (1980), a versão simplificada
do **Boyer-Moore** (1977) usada em editores e no `grep`.

Os saltos dependem só do padrão, então vão para uma **tabela de saltos** feita
antes da busca, com uma casa para cada valor de byte (256):

- toda letra começa com `salto = m`;
- para cada `j` de 0 até `m - 2`, `salto[padrao[j]] = m - 1 - j`, a distância
  de `j` até a última casa. Como `j` cresce, uma letra repetida fica com a
  ocorrência mais à direita.

A última letra do padrão fica de fora de propósito: se entrasse, o salto dela
seria 0, e a busca ficaria parada no mesmo lugar para sempre.

Na busca, cada alinhamento `i` compara de `j = m - 1` para trás. Achando ou
não, o próximo alinhamento é `i + salto[texto[i + m - 1]]`: a letra que
decide é sempre a que está sob a última casa da janela.

Vamos ver na prática. A placa é "A BANCA VENDE MANGA" (19 letras) e o padrão é
"MANGA" (`m = 5`). Os saltos são M = 4, A = 3, N = 2, G = 1 e 5 para as outras.
No alinhamento 0, sob a última casa está o `N`: salta 2. No 2, o `A` bate, o `C`
não, e o `A` manda saltar 3. No 5, o `E` não está em "MANGA": salta 5. No 10,
o `M` manda saltar 4. No 14, as cinco letras batem:

{{ideia}}

O mesmo exemplo em C:

```c
#include <stdio.h>
#include <string.h>

#define ALFABETO 256

// salto[c]: quanto andar quando a letra c está sob a última casa do padrão
void monta_saltos(const char *p, int m, int salto[]) {
    for (int c = 0; c < ALFABETO; c++) {
        salto[c] = m;                     // letra fora do padrão: pula tudo
    }
    for (int j = 0; j < m - 1; j++) {     // a última letra fica de fora
        salto[(unsigned char) p[j]] = m - 1 - j;
    }
}

int horspool(const char *texto, const char *padrao) {
    int n = (int) strlen(texto);
    int m = (int) strlen(padrao);
    int salto[ALFABETO];
    int achados = 0, alinhamentos = 0;
    monta_saltos(padrao, m, salto);

    int i = 0;
    while (i <= n - m) {
        alinhamentos++;
        int j = m - 1;                    // compara da direita para a esquerda
        while (j >= 0 && texto[i + j] == padrao[j]) {
            j--;
        }
        unsigned char ultima = (unsigned char) texto[i + m - 1];
        if (j < 0) {
            printf("i = %2d: achou!\n", i);
            achados++;
        } else {
            printf("i = %2d: falhou; sob a última casa está '%c', salta %d\n",
                   i, ultima, salto[ultima]);
        }
        i += salto[ultima];
    }
    printf("%d alinhamentos (a força bruta faria %d)\n", alinhamentos, n - m + 1);
    return achados;
}

int main(void) {
    const char *placa = "A BANCA VENDE MANGA";
    int salto[ALFABETO];
    monta_saltos("MANGA", 5, salto);
    printf("saltos: M=%d A=%d N=%d G=%d outras=%d\n",
           salto['M'], salto['A'], salto['N'], salto['G'], salto['Z']);
    horspool(placa, "MANGA");
    return 0;
}
// Saída:
// saltos: M=4 A=3 N=2 G=1 outras=5
// i =  0: falhou; sob a última casa está 'N', salta 2
// i =  2: falhou; sob a última casa está 'A', salta 3
// i =  5: falhou; sob a última casa está 'E', salta 5
// i = 10: falhou; sob a última casa está 'M', salta 4
// i = 14: achou!
// 5 alinhamentos (a força bruta faria 15)
```

### Passo a passo

Os cinco alinhamentos. A janela é `texto[i..i+4]` e a letra que decide o salto
é a última dela:

| i | janela | comparações (da direita) | última letra | salto |
| --- | --- | --- | --- | --- |
| 0 | `A BAN` | 1 (`N` ≠ `A`) | `N` | 2 |
| 2 | `BANCA` | 2 (`A` = `A`, `C` ≠ `G`) | `A` | 3 |
| 5 | `CA VE` | 1 | `E` | 5 |
| 10 | `NDE M` | 1 | `M` | 4 |
| 14 | `MANGA` | 5: **achou** | `A` | 3 (passa do fim) |

Foram 10 comparações de letra. A força bruta faz 19 no mesmo texto e passa por
todas as letras; aqui, 10 das 19 letras da placa nunca foram olhadas.

Repara no fluxograma: diferente da força bruta, o `i` não anda de 1 em 1. O
quanto ele anda vem da tabela, e quem decide é a última letra da janela, tenha
o alinhamento dado certo ou não:

{{fluxograma}}

O custo depende do texto. No caso comum, com alfabeto grande e padrão
comprido, muitas letras não aparecem no padrão e o salto fica perto de `m`:
a busca olha umas `n / m` letras, menos que o tamanho do texto. Quanto **maior**
o padrão, **mais rápida** a busca (o exemplo A317 mede isso). O pior caso
continua O(n·m): procurar "baaa" num texto só de `a` compara 4 letras e salta 1
em cada alinhamento (é o exercício E952).

> [!WARNING]
> O índice da tabela tem que ser `unsigned char`. Em UTF-8, letras acentuadas
> viram dois bytes acima de 127, e no gcc para x86 o `char` tem sinal: o `ã`
> começa com o byte 0xC3, que num `char` vale **-61**. `salto[-61]` escreve
> fora do vetor, em memória de outra variável, sem erro de compilação nenhum
> (o E953 mostra o estrago). Converta sempre: `salto[(unsigned char) c]`. E não
> ponha a última letra do padrão na tabela, ou o salto dela vira 0.

> [!TIP]
> **Por dentro do C:** a tabela é `int salto[256]`, 1 KB na pilha, não importa o
> tamanho do padrão nem do texto. Montar custa O(256 + m). O Boyer-Moore
> completo acrescenta uma segunda tabela, a do **bom sufixo**, que olha também
> as letras que já bateram e garante busca linear; o Horspool troca essa
> garantia por um código de dez linhas que, em texto comum, é tão rápido quanto.
> Ferramentas como o GNU `grep` usam variações do Boyer-Moore para procurar
> palavras fixas, e por isso ficam mais rápidas com padrões compridos.

> [!NOTE]
> **Pergunta para você:** qual é a tabela de saltos de "BANANA"? E quantos
> alinhamentos o Horspool testa para procurar "BANANA" em "BANDANA BANANA"?
> Faça no papel e depois troque os valores no código para conferir.

{{pratique}}

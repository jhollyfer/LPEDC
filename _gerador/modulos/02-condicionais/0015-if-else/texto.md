## 0015 · if/else e o = no lugar do ==

O `if` do 0014 fazia um passo a mais ou nada. Muitas situações, porém, têm
dois desfechos, e um deles **sempre** acontece: o aluno passa ou fica de
recuperação, o pagamento é aprovado ou recusado. Com um `if` só, você teria
de escrever a pergunta duas vezes, uma afirmando e outra negando. O C
oferece um jeito direto de dizer "se não, faça isto".

Pense na catraca do metrô. Você encosta o cartão, e ela faz uma pergunta:
há saldo para a tarifa de R$ 5,00? Se há, ela libera a passagem e
desconta. Se não há, ela barra e mostra quanto falta. Não existe terceira
saída, e as duas nunca acontecem juntas.

Esse segundo caminho é o **`else`**, "senão" em inglês. Junto com o `if`,
ele forma a **seleção dupla**: exatamente um dos dois blocos roda, nunca os
dois e nunca nenhum (DEITEL; DEITEL, 2011, cap. 3). Com a condição
verdadeira, roda o bloco do `if`; com ela falsa, roda o bloco do `else`.
Depois, os dois caminhos se reencontram na linha seguinte.

```c
if (condição) {
    // caminho do Sim
} else {
    // caminho do Não
}
```

O `else` **não tem condição**. Ele significa "todo o resto", tudo o que não
satisfez o `if`. Por isso `else (saldo < 5)` é erro de compilação: se você
precisa de outra pergunta, ela vira um novo `if`, assunto do 0016 (BACKES,
2013, cap. 4).

As regras de chaves do 0014 continuam valendo. Sem chaves, o `else`
controla uma instrução só, e o curso usa chaves sempre. O `;` depois do
`if`, que no 0014 compilava e errava em silêncio, agora costuma ser pego:
em `if (c); { ... } else { ... }`, o `;` encerra o `if`, o bloco fica solto
e o `else` aparece sem nenhum `if` antes dele. O compilador recusa (DEITEL;
DEITEL, 2011, cap. 3).

Agora a pegadinha mais famosa do C, que o compilador **não** recusa: o `=`
no lugar do `==`. Ela funciona assim. No 0009 você viu que a atribuição é
uma expressão e vale o valor que acabou de guardar. Então `if (saldo = 0)`
não compara nada: ele **guarda 0** em `saldo` e depois testa esse 0, que é
falso (DEITEL; DEITEL, 2011, cap. 4). O saldo some e o `else` roda sempre.
Do mesmo jeito, `if (opcao = 1)` guarda 1 e é sempre verdade, qualquer que
fosse a opção digitada.

Na execução, nada denuncia o erro; o único alerta vem do compilador.
Com `-Wall`, o gcc acusa "suggest parentheses around assignment
used as truth value" na linha do `if` (GNU, s.d.). Trate todo aviso como
erro: código bom compila com zero avisos. Há também um truque de escrita:
pôr a constante à esquerda, `if (0 == saldo)`. Se faltar um `=`, a linha
vira `0 = saldo`, que não compila, porque 0 não é um lugar da memória.

> [!WARNING]
> **`=` no lugar de `==`** compila e erra em silêncio: com
> `if (saldo = 0)`, o saldo vira zero e o `else` roda sempre. Compile com
> `-Wall` ou escreva a constante à esquerda: `0 = saldo` não compila.

{{exemplo}}

Na catraca do metrô, o cartão tem R$ 3,50 e a tarifa é R$ 5,00. A resposta é
Não, e o caminho de baixo é o que vale:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double saldo = 3.50;
    double tarifa = 5.00;

    if (saldo >= tarifa) {
        saldo = saldo - tarifa;
        printf("Catraca liberada. Saldo: R$ %.2f\n", saldo);
    } else {
        printf("Saldo insuficiente.\n");
        printf("Faltam R$ %.2f\n", tarifa - saldo);
    }
    return 0;
}
// Saída:
// Saldo insuficiente.
// Faltam R$ 1.50
```

Cada lado do losango tem seu bloco, e os dois se reencontram no Fim:

{{fluxograma}}

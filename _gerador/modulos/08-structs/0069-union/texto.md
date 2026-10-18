## 0069 · Union

No coworking, a mesma mesa é usada de manhã por uma designer e à tarde por um
programador. O espaço é um só. Quem chega usa a mesa inteira, e o que estava
em cima dela antes some (ou fica bagunçado).

Uma **union** é isso na memória. Ela se declara igual a uma struct, mas com
uma diferença radical: na struct, cada campo tem o seu pedaço de memória, um
depois do outro; na union, **todos os campos começam no mesmo endereço** e
dividem os mesmos bytes. O tamanho da union é o do maior campo (arredondado
para o alinhamento), e só um campo "vale" de cada vez.

```c
typedef union {
    uint32_t numero;        // 4 bytes
    unsigned char bytes[4]; // os MESMOS 4 bytes
} Endereco;
```

Para que serve? Para dois usos bem diferentes. O primeiro é **economizar
espaço** quando um dado pode ser uma coisa **ou** outra, nunca as duas: um
pagamento é Pix **ou** cartão **ou** boleto. O segundo é **olhar os mesmos
bytes de dois jeitos**: escrever um número de 4 bytes e ler byte a byte, sem
fazer conta nenhuma.

Vamos ver na prática com o segundo uso. Um endereço IP como 192.168.0.10 é,
por baixo, um número de 32 bits: `0xC0A8000A` (C0 = 192, A8 = 168, 00 = 0,
0A = 10). O programa grava o número em `ip.numero` e lê os bytes por
`ip.bytes`. Repare na ordem em que eles aparecem na memória:

{{ideia}}

Os bytes saem **ao contrário** do que você escreveu:

```c
#include <stdint.h>
#include <stdio.h>

// os dois campos começam no MESMO endereço: são dois jeitos de ler 4 bytes
typedef union {
    uint32_t numero;
    unsigned char bytes[4];
} Endereco;

int main(void) {
    Endereco ip;
    ip.numero = 0xC0A8000A; // 192.168.0.10, escrito como um número só

    printf("sizeof: %zu bytes\n", sizeof ip);
    printf("numero: 0x%08X\n", (unsigned)ip.numero);
    printf("bytes na memória:");
    for (int i = 0; i < 4; i++) {
        printf(" %02X", ip.bytes[i]); // lê os mesmos 4 bytes, um por um
    }
    printf("\n");

    if (ip.bytes[0] == 0x0A) {
        printf("little-endian: o byte menos significativo vem primeiro\n");
    } else {
        printf("big-endian: o byte mais significativo vem primeiro\n");
    }

    ip.bytes[3] = 10; // muda um byte: o número inteiro muda junto
    printf("depois de bytes[3] = 10: 0x%08X\n", (unsigned)ip.numero);
    return 0;
}
// Saída (num PC Intel/AMD ou ARM):
// sizeof: 4 bytes
// numero: 0xC0A8000A
// bytes na memória: 0A 00 A8 C0
// little-endian: o byte menos significativo vem primeiro
// depois de bytes[3] = 10: 0x0AA8000A
```

Essa ordem tem nome: **endianness**. Num processador **little-endian**
(Intel, AMD e praticamente todo ARM de celular), o byte **menos**
significativo fica no endereço menor: o `0A` do final do número vem primeiro.
Num **big-endian**, a ordem é a de leitura humana: `C0 A8 00 0A`. Nenhum é
"certo"; é uma escolha de quem projetou o processador. A union deixa você
**ver** essa escolha.

Repara no fluxograma: a pergunta sobre o primeiro byte é um detector de
endianness. O mesmo programa, compilado numa máquina big-endian, seguiria pelo
outro lado:

{{fluxograma}}

> [!WARNING]
> Numa union, escrever num campo **estraga** os outros. Se você grava
> `ip.numero` e depois lê `ip.bytes`, tudo bem: era essa a intenção. Mas numa
> union usada para economizar espaço, ler um campo diferente do último que
> você gravou dá lixo, e o C não avisa: ele não sabe qual campo está valendo.
> Por isso a union quase sempre vem acompanhada de um **enum** que diz qual
> campo vale agora (a union "etiquetada" do A138). É exatamente a *discriminated
> union* do TypeScript (`{ tipo: 'pix', chave } | { tipo: 'cartao', final }`),
> só que no C quem confere a etiqueta é você, não o compilador. E lembre: o
> resultado de ler os bytes depende da endianness, então esse código não dá a
> mesma saída em todas as máquinas.

> [!TIP]
> **Por dentro do C:** uma union não gera código nenhum. `ip.numero` e
> `ip.bytes[0]` são o mesmo endereço; muda só o tipo com que o compilador lê o
> que está lá. Em C (diferente do C++), ler um campo diferente do último
> gravado é permitido: os bytes são reinterpretados no tipo novo. É assim que
> se inspeciona um `float` bit a bit, por exemplo. Na rede, a convenção é
> big-endian (a "ordem de rede"); por isso programas de rede usam `htonl` e
> `ntohl`, de `<arpa/inet.h>`, para converter números antes de enviar e depois
> de receber.

> [!NOTE]
> **Pergunta para você:** se a union tivesse um terceiro campo,
> `uint16_t metades[2]`, quanto valeria `ip.metades[0]` logo depois de
> `ip.numero = 0xC0A8000A`? E `sizeof ip` mudaria?

{{pratique}}

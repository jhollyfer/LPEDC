## 0064 · Union

No coworking, a mesma mesa serve a uma designer de manhã e a um programador à
tarde. O espaço é um só, e o que estava em cima some (ou fica bagunçado).

A **union** (união) é isso na memória. Declara-se como a struct, com uma
diferença: na struct, cada campo tem seu pedaço, um depois do outro; na union,
**todos os campos começam no mesmo endereço** e dividem os mesmos bytes. O
tamanho é o do maior campo (arredondado ao alinhamento), e só um campo "vale"
por vez.

```c
typedef union {
    uint32_t numero;        // 4 bytes
    unsigned char bytes[4]; // os MESMOS 4 bytes
} Endereco;
```

A union tem dois usos. O primeiro é **economizar espaço** quando o dado é uma
coisa **ou** outra: um pagamento é Pix **ou** cartão **ou** boleto. O segundo
é **olhar os mesmos bytes de dois jeitos**: escrever um número de 4 bytes e
lê-lo byte a byte, sem conta.

O exemplo mostra o segundo. O IP 192.168.0.10 é, por baixo, um número de 32
bits: `0xC0A8000A` (C0 = 192, A8 = 168, 00 = 0, 0A = 10). O programa grava em
`ip.numero` e lê por `ip.bytes`. Observe a ordem dos bytes na memória:

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

Essa ordem é a **endianness**. No **little-endian** (Intel, AMD e quase todo
ARM de celular), o byte **menos** significativo fica no endereço menor: o `0A`
do final vem primeiro. No **big-endian**, a ordem é a de leitura humana:
`C0 A8 00 0A`. Nenhum é "certo": é escolha de quem projetou o processador, e a
union deixa você vê-la.

A pergunta sobre o primeiro byte detecta a endianness. Numa máquina
big-endian, o mesmo programa seguiria pelo outro lado:

{{fluxograma}}

> [!WARNING]
> Numa union, escrever num campo **estraga** os outros. Gravar `ip.numero` e
> ler `ip.bytes` é a intenção. Mas numa union para economizar espaço, ler um
> campo diferente do último gravado dá lixo, e o C não avisa. Por isso a union
> costuma vir com um **enum** que diz qual campo vale (a union "etiquetada" do
> A128); quem confere a etiqueta é você. E ler os bytes depende da
> endianness: a saída muda entre máquinas.

> [!TIP]
> A union não gera código: `ip.numero` e `ip.bytes[0]` são o mesmo endereço, e
> muda só o tipo de leitura. Em C, ler outro campo reinterpreta os bytes (é
> como se inspeciona um `float` bit a bit). Na rede a ordem é big-endian;
> `htonl` e `ntohl`, de `<arpa/inet.h>`, convertem os números.

> [!NOTE]
> **Pergunta para você:** se a union tivesse um terceiro campo,
> `uint16_t metades[2]`, quanto valeria `ip.metades[0]` logo depois de
> `ip.numero = 0xC0A8000A`? E `sizeof ip` mudaria?

{{pratique}}

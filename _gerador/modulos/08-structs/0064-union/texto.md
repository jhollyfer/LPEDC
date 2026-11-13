## 0064 · Union

Um pagamento numa loja é feito por Pix, **ou** por cartão, **ou** por boleto.
Nunca pelos três ao mesmo tempo. Se você guardar isso numa struct com os
dados dos três meios, cada pagamento carrega dois terços de espaço que nunca
vai usar. Às vezes o problema é o contrário: você quer pegar os mesmos bytes
da memória e lê-los de dois jeitos, como um número inteiro e como uma
sequência de bytes soltos.

Pense numa mesa de coworking. De manhã ela serve a uma designer; à tarde, a um
programador. O espaço é um só, e quando um chega, o que o outro deixou em cima
sai do lugar. A **union** (união) faz isso com a memória. Ela se declara
igual à struct, mas **todos os campos começam no mesmo endereço** e dividem
os mesmos bytes, então só um campo guarda um valor com sentido por vez
(BACKES, 2013, cap. 8).

```c
typedef union {
    uint32_t numero;        // 4 bytes
    unsigned char bytes[4]; // os MESMOS 4 bytes
} Endereco;
```

Compare com a struct. Na struct, cada campo tem o seu pedaço, um depois do
outro, e o tamanho é a soma (mais o preenchimento). Na union, os campos se
sobrepõem, e o tamanho é o do **maior campo**, arredondado ao alinhamento
(DEITEL; DEITEL, 2011, cap. 10). Em `Endereco`, os dois campos têm 4 bytes, e
`sizeof(Endereco)` dá 4, não 8.

Daí saem os dois usos da union (KERNIGHAN; RITCHIE, 1988, cap. 6). O
primeiro é **economizar espaço** quando o dado é uma coisa ou outra, como o
pagamento. O segundo é **olhar os mesmos bytes de dois jeitos**: você grava
`numero` e lê `bytes[0]`, `bytes[1]`... sem fazer conta de divisão e resto. A
union não gera código para isso. `ip.numero` e `ip.bytes[0]` estão no mesmo
endereço; o que muda é só o tipo com que o programa lê aqueles bytes.

No primeiro uso aparece uma dificuldade: olhando a union, como saber qual
campo foi gravado por último? A união sozinha não guarda essa informação.
A solução é a **union etiquetada**: uma struct com um **enum** que diz qual
campo vale (a etiqueta) e, ao lado, a union com os dados. Antes de ler, o
programa olha a etiqueta. Quem confere é você; o compilador não verifica
nada (KERNIGHAN; RITCHIE, 1988, cap. 6).

O segundo uso revela um detalhe da máquina. O IP 192.168.0.10 é, por baixo,
um número de 32 bits: `0xC0A8000A` (C0 = 192, A8 = 168, 00 = 0, 0A = 10).
Grave esse número em `ip.numero` e leia `ip.bytes` num PC comum: os bytes
saem `0A 00 A8 C0`, de trás para frente. A ordem em que os bytes de um número
ficam na memória se chama **endianness**. No **little-endian** (Intel, AMD e
quase todo ARM), o byte **menos** significativo fica no endereço menor, por
isso o `0A` do final vem primeiro. No **big-endian**, a ordem é a mesma da
leitura humana, `C0 A8 00 0A` (LINUX MAN PAGES, s.d.). Nenhuma das duas é a
certa: é uma escolha de quem projetou o processador.

A diferença importa quando dois computadores trocam números. A rede usa
big-endian, e as funções `htonl` e `ntohl`, de `<arpa/inet.h>`, convertem um
número de 32 bits da ordem da máquina para a da rede e de volta (LINUX MAN
PAGES, s.d.). Numa máquina big-endian elas não fazem nada; numa
little-endian, invertem os bytes.

> [!WARNING]
> Numa union, escrever num campo **estraga** os outros. Numa union para
> economizar espaço, ler um campo diferente do último gravado dá lixo, e o C
> não avisa: guarde um enum com a etiqueta e confira antes de ler. E ler os
> bytes de um número depende da endianness: a saída muda entre máquinas.

{{exemplo}}

O IP 192.168.0.10 é um número de 32 bits, `0xC0A8000A`. O programa grava em
`ip.numero` e lê por `ip.bytes`; repare na ordem dos bytes na memória:

{{ideia}}

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

A pergunta sobre o primeiro byte detecta a endianness. Numa máquina big-endian,
o mesmo programa seguiria pelo outro lado:

{{fluxograma}}

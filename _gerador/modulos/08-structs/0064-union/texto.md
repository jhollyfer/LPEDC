## 0064 · Union

- **Union** (união): declara-se como a struct, mas **todos os campos começam no
  mesmo endereço** e dividem os mesmos bytes. Só um campo vale por vez
  (BACKES, 2013, cap. 8).
- **Tamanho**: o do maior campo, arredondado ao alinhamento
  (DEITEL; DEITEL, 2011, cap. 10).

```c
typedef union {
    uint32_t numero;        // 4 bytes
    unsigned char bytes[4]; // os MESMOS 4 bytes
} Endereco;
```

- **Dois usos**: economizar espaço quando o dado é uma coisa **ou** outra (Pix
  ou cartão ou boleto) e olhar os mesmos bytes de dois jeitos
  (KERNIGHAN; RITCHIE, 1988, cap. 6).
- **Union etiquetada**: um **enum** ao lado diz qual campo vale; quem confere
  a etiqueta é você (KERNIGHAN; RITCHIE, 1988, cap. 6).
- **Endianness**: a ordem dos bytes na memória. No **little-endian** (Intel,
  AMD e quase todo ARM), o byte menos significativo fica no endereço menor; no
  **big-endian**, a ordem é a de leitura humana (LINUX MAN PAGES, s.d.).
- **Rede**: a ordem é big-endian; `htonl` e `ntohl`, de `<arpa/inet.h>`,
  convertem os números (LINUX MAN PAGES, s.d.).

> [!WARNING]
> Escrever num campo **estraga** os outros. Numa union para economizar espaço,
> ler um campo diferente do último gravado dá lixo, sem aviso. E ler os bytes
> depende da endianness: a saída muda entre máquinas.

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

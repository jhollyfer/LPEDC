## 0068 · Arquivos binários

O arquivo texto tem um limite. Cada linha tem um tamanho diferente: "Luz
98.75" tem 9 caracteres, "Internet 99.90" tem 14. Para chegar à linha 500, o
programa precisa ler as 499 anteriores, contando os `\n`, porque não há como
saber em que byte ela começa. E cada número passa por uma conversão na ida
(`double` para texto) e outra na volta (texto para `double`).

Pense no estoque do mercadinho guardado em fichas todas do mesmo tamanho,
numa gaveta. Para pegar a terceira ficha, ninguém lê as duas primeiras: mede
com o dedo e puxa. O **arquivo binário** permite isso. Ele grava os bytes
**exatamente como estão na memória**, sem converter nada em texto, e por
isso um `int` ocupa sempre 4 bytes no disco, e uma struct ocupa sempre o seu
`sizeof` (BACKES, 2013, cap. 12).

Quando todos os registros têm o mesmo tamanho, a posição de cada um vira uma
conta. Um **registro** aqui é uma struct gravada no arquivo, como um
`Produto` de 32 bytes. O registro 0 começa no byte 0, o registro 1 no byte
32, e o registro `i` começa no byte `i * sizeof(Produto)` (DEITEL; DEITEL,
2011, cap. 11). Com essa conta, o programa vai direto ao registro que quer.

Para abrir um arquivo binário, acrescente um `b` ao modo: `"wb"`, `"rb"`,
`"ab"`, `"rb+"`. No Linux e no Mac, o `b` não muda nada. No Windows, sem ele,
a biblioteca troca cada `\n` por `\r\n` ao gravar, e qualquer byte de valor
10 no meio de um número sai estragado (BACKES, 2013, cap. 12). Escreva o `b`
sempre, e o programa funciona nos dois sistemas.

Para gravar, use `fwrite(endereco, tamanho, quantidade, arq)`. Ele copia
`tamanho * quantidade` bytes a partir do endereço que você deu. Uma variável
ou uma struct vai com `&` (`fwrite(&p, sizeof p, 1, arq)`); um vetor já é
endereço e vai sem `&` (`fwrite(estoque, sizeof(Produto), 3, arq)` grava os
três produtos de uma vez). O `fread`, com os mesmos argumentos, faz o caminho
de volta. Os dois devolvem **quantos itens** processaram, e não quantos
bytes. Se o `fread` devolver menos que o pedido, o arquivo acabou ou deu erro,
e é esse retorno que vai na condição do `while` (BACKES, 2013, cap. 12).

Para pular até um registro, use `fseek(arq, deslocamento, origem)`. A origem
diz de onde contar: `SEEK_SET` é o começo do arquivo, `SEEK_CUR` é a posição
atual e `SEEK_END` é o fim. O deslocamento é um `long` e pode ser negativo.
`fseek(arq, 2 * sizeof(Produto), SEEK_SET)` põe a posição no byte 64, e o
próximo `fread` traz o registro 2. O `fseek` não lê nada: ele só troca um
número guardado no `FILE`. Pular para o registro 2 custa o mesmo que pular
para o registro 2 milhões (DEITEL; DEITEL, 2011, cap. 11).

Duas funções completam o conjunto. `ftell(arq)` devolve a posição atual em
bytes, e `rewind(arq)` volta ao byte 0. Juntando `fseek(arq, 0, SEEK_END)` e
`ftell(arq)`, você mede o arquivo; dividindo pelo `sizeof` do registro,
descobre quantos registros ele tem (BACKES, 2013, cap. 12).

O acesso direto abre uma possibilidade grande. Com os registros gravados em
ordem de código, dá para fazer **busca binária direto no arquivo**: `fseek`
no registro do meio, `fread`, compara, descarta a metade que não serve e
repete. Uns 20 `fread` acham um registro entre 1 milhão, sem carregar o
arquivo na RAM (ZIVIANI, 2010). A busca binária é o assunto 0090.

A tabela resume o que muda entre os dois tipos de arquivo:

| | texto (`fprintf`) | binário (`fwrite`) |
| --- | --- | --- |
| o `int` 12345678 | 8 bytes: `'1' '2' ... '8'` | 4 bytes: `4E 61 BC 00` |
| abre no editor? | sim | vira lixo na tela |
| converte na ida e na volta? | sim (mais lento) | não, só copia bytes |
| acesso direto ao registro `i`? | não | sim, com `fseek` |
| lê em outra máquina? | sim | só se `int`, alinhamento e ordem dos bytes forem iguais |

> [!WARNING]
> `fwrite` copia bytes, não dados. Struct com ponteiro (`char *nome`) grava o
> **endereço**, que não aponta para nada na próxima execução: use
> `char nome[20]`. E um `.bin` pode não ser lido igual em outra máquina
> (tamanho do `int`, alinhamento, ordem dos bytes): para trocar dados, use texto.

{{exemplo}}

O estoque do mercadinho tem três produtos de 32 bytes cada. Um `fwrite` grava
os três (96 bytes). Para ler o café, o programa pula 2 × 32 = 64 bytes e faz um
`fread` de um registro:

{{ideia}}

```c
#include <stdio.h>

typedef struct {
    char nome[20];
    int qtd;
    double preco;
} Produto;

int main(void) {
    const char *caminho = "/tmp/estoque.bin";
    Produto estoque[3] = {
        {"Arroz", 12, 25.90},
        {"Feijão", 7, 8.75},
        {"Café", 4, 18.50},
    };

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    size_t gravados = fwrite(estoque, sizeof(Produto), 3, arq); // vetor: sem &
    fclose(arq);
    printf("Cada registro: %zu bytes\n", sizeof(Produto));
    printf("Gravados: %zu registros\n", gravados);

    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fseek(arq, 0, SEEK_END);                    // vai para o fim...
    printf("Arquivo: %ld bytes\n", ftell(arq)); // ...e pergunta a posição

    Produto p;
    fseek(arq, 2 * sizeof(Produto), SEEK_SET);  // byte 64: começo do registro 2
    if (fread(&p, sizeof(Produto), 1, arq) == 1) {
        printf("Registro 2: %s, %d un., R$ %.2f\n", p.nome, p.qtd, p.preco);
    }
    fclose(arq);
    remove(caminho);
    return 0;
}
// Saída:
// Cada registro: 32 bytes
// Gravados: 3 registros
// Arquivo: 96 bytes
// Registro 2: Café, 4 un., R$ 18.50
```

Não há laço até o café: são dois `fseek` e um `fread`, com 3 registros ou 3
milhões:

{{fluxograma}}

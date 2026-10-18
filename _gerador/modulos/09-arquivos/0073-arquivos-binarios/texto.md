## 0073 · Arquivos binários

O mercadinho do bairro guarda o estoque em fichas de papel, todas do mesmo
tamanho, numa caixa. Para achar a terceira ficha, ninguém lê as duas
primeiras: mede com o dedo e puxa. Arquivo texto não deixa fazer isso, porque
cada linha tem um tamanho ("Luz 98.75" tem 9 caracteres, "Internet 99.90" tem
14). Para cair na linha 500, você precisa ler as 499 antes.

Um **arquivo binário** resolve isso. Em vez de converter os dados em texto,
ele grava os bytes **exatamente como estão na memória**. Um `int` sempre ocupa
4 bytes no arquivo, uma struct sempre ocupa `sizeof` da struct. Com
**registros de tamanho fixo**, a posição de qualquer um vira conta: o
registro `i` começa no byte `i * sizeof(registro)`.

Em resumo: texto é legível e maior; binário é compacto e ilegível.

| | texto (`fprintf`) | binário (`fwrite`) |
| --- | --- | --- |
| o `int` 12345678 | 8 bytes: `'1' '2' ... '8'` | 4 bytes: `4E 61 BC 00` |
| abre no editor? | sim | vira lixo na tela |
| converte na ida e na volta? | sim (mais lento) | não, só copia bytes |
| acesso direto ao registro `i`? | não | sim, com `fseek` |
| lê em outra máquina? | sim | só se `int`, alinhamento e ordem dos bytes forem iguais |

As ferramentas:

- **Modo com `b`**: `"wb"`, `"rb"`, `"ab"`, `"rb+"`. No Linux e no Mac o `b`
  não muda nada; no Windows, sem ele, a biblioteca troca `\n` por `\r\n` e
  estraga os bytes. Escreva sempre.
- **`fwrite(endereco, tamanho, quantidade, arq)`** copia `tamanho *
  quantidade` bytes a partir do endereço. Variável e struct vão com `&`; vetor
  já é endereço. Devolve **quantos itens** gravou.
- **`fread(endereco, tamanho, quantidade, arq)`** faz o caminho de volta e
  também devolve quantos itens leu. Menos que o pedido quer dizer fim do
  arquivo ou erro. É esse retorno que vai no `while`.
- **`fseek(arq, deslocamento, origem)`** muda a posição de leitura e escrita.
  A origem é `SEEK_SET` (do começo), `SEEK_CUR` (de onde está) ou `SEEK_END`
  (do fim). O deslocamento é `long` e pode ser negativo.
- **`ftell(arq)`** diz a posição atual em bytes e **`rewind(arq)`** volta ao
  byte 0. `fseek` até o fim seguido de `ftell` é o jeito clássico de medir o
  arquivo.

Vamos ver na prática. O estoque tem três produtos, e cada `Produto` ocupa 32
bytes. Um `fwrite` grava os três em sequência: 96 bytes. Para ler o café, o
programa pula 2 × 32 = 64 bytes desde o começo e faz um `fread` de um
registro só:

{{ideia}}

O arquivo fica em `/tmp/estoque.bin` e é apagado no fim:

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

Repara no fluxograma: não tem laço nenhum para chegar ao café. São duas
chamadas de `fseek` e um `fread`, quer o arquivo tenha 3 registros, quer tenha
3 milhões:

{{fluxograma}}

> [!WARNING]
> `fwrite` copia bytes, não "dados". Se a struct tiver um ponteiro
> (`char *nome` em vez de `char nome[20]`), o arquivo guarda o **endereço**,
> não o texto. Na próxima execução esse endereço não aponta para nada. Para
> gravar em binário, use vetores de tamanho fixo dentro da struct. E não
> confie que um `.bin` gravado num PC vai ser lido igual num celular ou num
> microcontrolador: tamanho do `int`, alinhamento e ordem dos bytes podem
> mudar. Para trocar dados entre máquinas, prefira texto (CSV, JSON).

> [!TIP]
> **Por dentro do C:** tire o `remove` do A145, rode e depois
> `od -A d -t x1 /tmp/estoque.bin` (ou `xxd`, se tiver). Cada linha mostra 16
> bytes, então cada produto ocupa duas linhas.
> Você vai ver `Arroz` seguido de zeros: o `fwrite` grava os 20 bytes do vetor
> `nome`, usados ou não. Logo depois vem `0c 00 00 00`, o 12 da `qtd` em
> little-endian, e os 8 bytes do `double`. Aqui 20 + 4 + 8 dá exatamente 32,
> sem enchimento, porque o `double` já cai num endereço múltiplo de 8. E o
> `fseek` não lê nada: só troca um número dentro do `FILE` (e no sistema
> operacional). Por isso pular para o registro 2 custa o mesmo que pular para
> o registro 2 milhões.

> [!NOTE]
> **Pergunta para você:** se `nome` fosse `char nome[21]`, quanto daria
> `sizeof(Produto)`? Lembre que o `int` gosta de começar em múltiplo de 4 e o
> `double` em múltiplo de 8. Responda e depois confira com um `printf`.

{{pratique}}

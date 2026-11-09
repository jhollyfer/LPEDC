// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0926 · ★★★ · Compactar a leitura do sensor (RLE)
//
// O sensor da estufa manda uma letra por minuto (A = ok, B = quente,
// C = seco, D = desligado) e repete muito: "AAAAABBBCCCCCCCCDAA". A
// codificação RLE guarda cada SEQUÊNCIA como um par (quantidade, letra):
// 5A 3B 8C 1D 2A. Escreva:
//
//   int compacta(const char *texto, const char *caminho)
//     grava os pares em binário (struct Par com unsigned char qtd e char c)
//     e devolve quantos pares gravou (-1 se não abriu o arquivo);
//   int descompacta(const char *caminho, char *saida, int max)
//     lê os pares e remonta o texto em saida (no máximo max - 1 letras,
//     mais o '\0'), devolvendo o tamanho remontado.
//
// Use /tmp/p0926_sensor.rle, mostre os tamanhos, os pares, o texto
// remontado e se ele confere com o original. Apague o arquivo no fim.
//
//   Saída esperada:
//   Original: 19 bytes
//   Compactado: 10 bytes (5 pares)
//   5xA 3xB 8xC 1xD 2xA
//   Descompactado: AAAAABBBCCCCCCCCDAA
//   Confere: sim
//
// Dicas:
// 1. Para compactar, ande com i pelo texto; conte quantas letras iguais a
//    texto[i] vêm seguidas (no máximo 255, que é o limite do unsigned char)
//    e grave o par. Depois pule essa sequência.
// 2. O tamanho do arquivo vem de fseek até o fim e ftell. Cada Par ocupa
//    2 bytes (dois campos de 1 byte, sem preenchimento).
// 3. Resposta esperada: a saída acima. RLE compensa com muita repetição; com
//    "ABCD" o arquivo ficaria com o DOBRO do tamanho.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char qtd;
    char c;
} Par;

int main(void) {

    return 0;
}

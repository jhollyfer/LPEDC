// compactador.h · compacta e descompacta arquivos com o código de Huffman
#ifndef COMPACTADOR_H
#define COMPACTADOR_H

// Formato do arquivo compactado (.huf):
//   4 bytes     "HUF1" (assinatura)
//   8 bytes     tamanho do arquivo original, em bytes (uint64_t)
//   1024 bytes  frequência de cada um dos 256 bytes (256 x uint32_t)
//   o resto     os códigos, bit a bit, 8 bits por byte (o último completado com 0)

// compacta entrada em saida; devolve o tamanho de saida em bytes, ou -1 se der erro
long huf_compacta(const char *entrada, const char *saida);

// descompacta entrada em saida; devolve o tamanho de saida em bytes, ou -1 se der erro
long huf_descompacta(const char *entrada, const char *saida);

// tamanho de um arquivo em bytes, ou -1 se não abrir
long arq_tamanho(const char *nome);

#endif

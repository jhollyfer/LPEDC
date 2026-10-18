// huffman.h · interface do TAD árvore de Huffman
#ifndef HUFFMAN_H
#define HUFFMAN_H

// um nó da árvore: as folhas guardam um símbolo (um byte); os nós internos
// só somam as frequências dos filhos
typedef struct NoHuf {
    unsigned char simbolo; // só vale nas folhas
    long freq;             // quantas vezes o símbolo (ou a subárvore) aparece
    int ordem;             // desempate: folhas pelo símbolo, internos pela criação
    struct NoHuf *esq;     // aresta 0
    struct NoHuf *dir;     // aresta 1
} NoHuf;

// monta a árvore a partir das frequências dos 256 bytes possíveis
// (freq[c] == 0: o byte c não aparece); NULL se nenhum aparece
NoHuf *huf_constroi(const long freq[256]);

// preenche codigos[c] com a string de '0' e '1' do byte c ("" se não aparece).
// Com um símbolo só, o código dele é "0".
void huf_codigos(const NoHuf *raiz, char codigos[256][256]);

int huf_folha(const NoHuf *no); // 1 se o nó é folha
void huf_libera(NoHuf *raiz);

#endif

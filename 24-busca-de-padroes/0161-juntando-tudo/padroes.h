// padroes.h · os quatro algoritmos de busca de padrões com a mesma assinatura
#ifndef PADROES_H
#define PADROES_H

#define PB_MAX_PADRAO 256 // maior padrão aceito (por causa da tabela pi do KMP)

// Todas as buscas procuram padrao (m letras) em texto (n letras) e:
// - guardam em pos[] as posições das primeiras 'max' ocorrências (pos pode
//   ser NULL quando só interessa contar);
// - SOMAM em *comparacoes as comparações de letra que fizeram (o Rabin-Karp
//   conta só as da conferência; as contas do hash não entram);
// - devolvem o total de ocorrências (sobrepostas contam).
// Padrão vazio ou maior que o texto: 0 ocorrências.
typedef int (*Busca)(const char *texto, int n, const char *padrao, int m,
                     int pos[], int max, long *comparacoes);

int pb_forca_bruta(const char *texto, int n, const char *padrao, int m,
                   int pos[], int max, long *comparacoes);
int pb_kmp(const char *texto, int n, const char *padrao, int m,
           int pos[], int max, long *comparacoes);
int pb_horspool(const char *texto, int n, const char *padrao, int m,
                int pos[], int max, long *comparacoes);
int pb_rabin_karp(const char *texto, int n, const char *padrao, int m,
                  int pos[], int max, long *comparacoes);

#endif

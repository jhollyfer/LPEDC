// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E572 · ★☆☆
//
// Resposta:
// a) insertion sort: 20 elementos é pouco e ele é adaptativo; com o vetor
//    quase em ordem, faz pouco mais que n comparações.
// b) merge sort (ou qualquer estável): os empates por nota têm de manter a
//    ordem alfabética que já existe.
// c) selection sort: faz no máximo n - 1 trocas, e cada troca aqui é cara.
// d) merge sort: O(n log n) garantido, sem o pior caso O(n²) do quick sort.
// e) qsort: genérico, já testado, e com desempate na compara não depende de
//    estabilidade.
// f) bubble sort: nenhuma situação real; ele perde para o insertion em tudo.

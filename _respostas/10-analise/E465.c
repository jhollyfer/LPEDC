// 0078 · Invariantes de laço e corretude
// Exercício E465 · ★★☆
//
// Resposta: 1) início: k = n - 1 e v[n..n-1] é vazio, então x não está nele;
// 2) manutenção: a volta só roda se v[k] != x; depois do k--, o pedaço
// v[k+1..n-1] ganhou só esse elemento, que não é x; 3) término: se parou com
// k >= 0, então v[k] == x e ninguém em v[k+1..n-1] é x, logo k é a última
// ocorrência; se parou com k == -1, x não está em v[0..n-1] e -1 é o certo;
// 4) parada: k diminui 1 por volta e o laço para em -1, no máximo. O k >= 0
// vem primeiro no && para que v[-1] nunca seja lido (curto-circuito).

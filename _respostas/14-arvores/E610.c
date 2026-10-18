// 0102 · Árvores
// Exercício E610 · ★★☆
//
// Resposta: a saída é
//
//   300 MB  praia
//   120 MB  natal
//   430 MB  fotos
//   5 MB  agua
//   8 MB  luz
//   15 MB  contas
//   450 MB  casa
//
// O printf vem depois do laço dos filhos: cada pasta só é impressa quando
// todas as subpastas já foram somadas (e impressas). É a ordem "filhos
// primeiro, depois o pai", que o próximo assunto chama de pós-ordem.
// fotos = 10 + 300 + 120 = 430; contas = 2 + 5 + 8 = 15;
// casa = 5 + 430 + 15 = 450.

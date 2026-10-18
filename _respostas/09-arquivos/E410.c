// 0069 · Argumentos da linha de comando
// Exercício E410 · ★☆☆
//
// Resposta (rodar E410.c 7 + 3a):
//   argc = 4                 o nome do programa conta
//   argv[2] = +
//   tamanho de argv[3] = 2   "3a" tem 2 caracteres
//   7 + 3 = 10               ('7' - '0') + ('3' - '0')
//   atoi("3a") = 3           para no 'a' sem avisar
//   atoi("+") = 0            nenhum dígito: devolve 0, sem erro nenhum

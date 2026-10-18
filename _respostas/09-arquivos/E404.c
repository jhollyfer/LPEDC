// 0068 · Arquivos binários
// Exercício E404 · ★☆☆
//
// Resposta:
//   a) 30          fseek para o byte 8 = começo do 3º int
//   b) posição 12  o fread andou 4 bytes
//   c) 20          voltou 8 bytes (12 - 8 = 4) = começo do 2º int
//   d) 40          4 bytes antes do fim (16 - 4 = 12) = último int
//   e) posição 16  o fread andou até o fim

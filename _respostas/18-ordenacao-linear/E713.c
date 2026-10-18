// 0119 · Shell sort
// Exercício E713 · ★★★

#include <stdio.h>

void shell_sort(int v[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {                    // a rodada h = 1 tem que acontecer
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {  // j == h ainda compara com v[0]
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
        h /= 3;
    }
}

int main(void) {
    int senhas[] = {29, 8, 35, 14, 2, 23, 38, 11, 20, 5, 32, 17, 26};
    int n = 13;

    shell_sort(senhas, n);
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", senhas[i]);
    }
    printf("\n");
    return 0;
}

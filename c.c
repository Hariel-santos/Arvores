#include <stdio.h>

int main() {
    int base[100];
    int tamanho = 0;   
    int numAdd;

    while (1) {
        scanf("%d", &numAdd);

        int i = tamanho - 1;

        
        while (i >= 0 && numAdd < base[i]) {
            base[i + 1] = base[i];
            i--;
        }

        base[i + 1] = numAdd;
        tamanho++;

        for (int j = 0; j < tamanho; j++) {
            printf("%d ", base[j]);
        }
    }

    return 0;
}

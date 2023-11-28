#include <stdio.h>

int main() {
    int numero;

    // Solicita ao usuário um número positivo
    printf("Digite um número positivo: ");
    scanf("%d", &numero);

    // Verifica se o número fornecido é positivo
    if (numero <= 0) {
        printf("Por favor, insira um número positivo.\n");
        return 1; // Retorna 1 indicando erro
    }

    // Imprime os divisores do número
    printf("Os divisores do número %d são: ", numero);
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            printf("%d", i);

            // Se não for o último divisor, imprime a vírgula
            if (i < numero) {
                printf(", ");
            }
        }
    }

    printf("\n");

    return 0;
}

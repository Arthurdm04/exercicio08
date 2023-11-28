#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Solicita ao usuário um número inteiro não negativo
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &n);

    // Verifica se o número fornecido é não negativo
    if (n < 0) {
        printf("Por favor, insira um número inteiro não negativo.\n");
        return 1; // Retorna 1 indicando erro
    }

    // Calcula e imprime o enésimo termo da sequência de Fibonacci
    int resultado = fibonacci(n);
    printf("O %dº termo da sequência de Fibonacci é: %d\n", n, resultado);

    return 0;
}

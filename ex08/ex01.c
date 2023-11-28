#include <stdio.h>


int main() {
    int capacidade = 100;
    int idade, totalRespostas = 0, totalOtimo = 0, totalBom = 0, totalRegular = 0, totalRuim = 0, totalPessimo = 0;
    int maiorIdadeOtimo = 0, maiorIdadeRuim = 0;
    float mediaIdadeRuim = 0;

    for (int i = 0; i < capacidade; i++) {
        char opiniao;

        // Leitura da idade
        printf("Digite a idade do espectador %d: ", i + 1);
        scanf("%d", &idade);

        // Leitura da opinião
        printf("Digite a opiniao (A, B, C, D ou E) do espectador %d: ", i + 1);
        scanf(" %c", &opiniao);

        // Contagem das respostas
        if (opiniao == 'A') {
            totalOtimo++;
            if (idade > maiorIdadeOtimo) {
                maiorIdadeOtimo = idade;
            }
        } else if (opiniao == 'B') {
            totalBom++;
        } else if (opiniao == 'C') {
            totalRegular++;
        } else if (opiniao == 'D') {
            totalRuim++;
            mediaIdadeRuim += idade;
            if (idade > maiorIdadeRuim) {
                maiorIdadeRuim = idade;
            }
        } else if (opiniao == 'E') {
            totalPessimo++;
        } else {
            printf("Opinião invalida. Tente novamente.\n");
            i--;  // Para repetir a iteração se a opinião for inválida
        }

        totalRespostas++;
    }

    // Cálculos
    float difPercentual = ((float)totalBom / totalRespostas - (float)totalRegular / totalRespostas) * 100;
    float percentualPessimo = ((float)totalPessimo / totalRespostas) * 100;
    mediaIdadeRuim /= totalRuim;
    int difIdadeMax = maiorIdadeOtimo - maiorIdadeRuim;

    // Impressão dos resultados
    printf("\nResultados:\n");
    printf("Quantidade de respostas otimo: %d\n", totalOtimo);
    printf("Diferença percentual entre Bom e Regular: %.2f%%\n", difPercentual);
    printf("Media de idade das pessoas que responderam Ruim: %.2f\n", mediaIdadeRuim);
    printf("Percentagem de respostas Pessimo: %.2f%%\n", percentualPessimo);
    printf("Maior idade que respondeu Pessimo: %d\n", maiorIdadeRuim);
    printf("Diferença de idade entre a maior idade que respondeu otimo e a maior idade que respondeu Ruim: %d\n", difIdadeMax);

    return 0;
}

#include <stdio.h>

#define NUM_PESSOAS 10

int main() {
    // Definindo arrays para armazenar informações sobre as pessoas
    char nomes[NUM_PESSOAS][50];
    char sexos[NUM_PESSOAS];
    float alturas[NUM_PESSOAS];
    float pesos[NUM_PESSOAS];

    // Variáveis para armazenar as estatísticas
    int numHomens = 0, numMulheres = 0;
    float alturaMediaHomens = 0, alturaMediaMulheres = 0, alturaMediaGrupo = 0;
    float pesoMediaHomens = 0, pesoMediaMulheres = 0, pesoMediaGrupo = 0;

    // Lendo as informações sobre as pessoas
    for (int i = 0; i < NUM_PESSOAS; i++) {
        printf("\nInforme os dados da pessoa %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", nomes[i]);

        printf("Sexo (M/F): ");
        scanf(" %c", &sexos[i]);

        printf("Altura (em metros): ");
        scanf("%f", &alturas[i]);

        printf("Peso (em quilogramas): ");
        scanf("%f", &pesos[i]);

        // Atualizando estatísticas com base no sexo da pessoa
        if (sexos[i] == 'M' || sexos[i] == 'm') {
            numHomens++;
            alturaMediaHomens += alturas[i];
            pesoMediaHomens += pesos[i];
        } else if (sexos[i] == 'F' || sexos[i] == 'f') {
            numMulheres++;
            alturaMediaMulheres += alturas[i];
            pesoMediaMulheres += pesos[i];
        } else {
            printf("Sexo inválido. Tente novamente.\n");
            i--;  // Para repetir a iteração se o sexo for inválido
        }

        // Atualizando estatísticas do grupo
        alturaMediaGrupo += alturas[i];
        pesoMediaGrupo += pesos[i];
    }

    // Calculando médias
    if (numHomens > 0) {
        alturaMediaHomens /= numHomens;
        pesoMediaHomens /= numHomens;
    }

    if (numMulheres > 0) {
        alturaMediaMulheres /= numMulheres;
        pesoMediaMulheres /= numMulheres;
    }

    if (NUM_PESSOAS > 0) {
        alturaMediaGrupo /= NUM_PESSOAS;
        pesoMediaGrupo /= NUM_PESSOAS;
    }

    // Exibindo resultados
    printf("\nResultados:\n");
    printf("Número de homens: %d\n", numHomens);
    printf("Número de mulheres: %d\n", numMulheres);
    printf("Altura média dos homens: %.2f metros\n", alturaMediaHomens);
    printf("Altura média das mulheres: %.2f metros\n", alturaMediaMulheres);
    printf("Altura média do grupo: %.2f metros\n", alturaMediaGrupo);
    printf("Peso médio dos homens: %.2f quilogramas\n", pesoMediaHomens);
    printf("Peso médio das mulheres: %.2f quilogramas\n", pesoMediaMulheres);
    printf("Peso médio do grupo: %.2f quilogramas\n", pesoMediaGrupo);

    return 0;
}

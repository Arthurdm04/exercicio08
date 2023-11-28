#include <stdio.h>

#define NUM_MORADORES 50

int main() {
    // Inicializando contadores para os elevadores e períodos
    int contadorElevadorA_M = 0, contadorElevadorA_V = 0, contadorElevadorA_N = 0;
    int contadorElevadorB_M = 0, contadorElevadorB_V = 0, contadorElevadorB_N = 0;
    int contadorElevadorC_M = 0, contadorElevadorC_V = 0, contadorElevadorC_N = 0;

    // Variáveis para armazenar a contagem total de cada período
    int totalMatutino = 0, totalVespertino = 0, totalNoturno = 0;

    // Variáveis para armazenar o elevador mais frequentado e o período mais usado
    char elevadorMaisFrequentado;
    char periodoMaisUsado;

    // Leitura dos dados
    for (int i = 0; i < NUM_MORADORES; i++) {
        char elevador, periodo;

        printf("Digite o elevador mais utilizado (A, B ou C) para o morador %d: ", i + 1);
        scanf(" %c", &elevador);

        printf("Digite o período mais utilizado (M, V ou N) para o morador %d: ", i + 1);
        scanf(" %c", &periodo);

        // Atualizando contadores para elevadores e períodos
        switch (elevador) {
            case 'A':
                if (periodo == 'M') contadorElevadorA_M++;
                else if (periodo == 'V') contadorElevadorA_V++;
                else if (periodo == 'N') contadorElevadorA_N++;
                break;

            case 'B':
                if (periodo == 'M') contadorElevadorB_M++;
                else if (periodo == 'V') contadorElevadorB_V++;
                else if (periodo == 'N') contadorElevadorB_N++;
                break;

            case 'C':
                if (periodo == 'M') contadorElevadorC_M++;
                else if (periodo == 'V') contadorElevadorC_V++;
                else if (periodo == 'N') contadorElevadorC_N++;
                break;

            default:
                printf("Elevador inválido. Tente novamente.\n");
                i--;  // Para repetir a iteração se o elevador for inválido
        }

        // Atualizando contadores para períodos
        if (periodo == 'M') totalMatutino++;
        else if (periodo == 'V') totalVespertino++;
        else if (periodo == 'N') totalNoturno++;
    }

    // Encontrando o elevador mais frequentado
    char elevadorMaisFrequente;
    int maxFrequencia = 0;

    if (contadorElevadorA_M + contadorElevadorA_V + contadorElevadorA_N > maxFrequencia) {
        maxFrequencia = contadorElevadorA_M + contadorElevadorA_V + contadorElevadorA_N;
        elevadorMaisFrequente = 'A';
    }
    if (contadorElevadorB_M + contadorElevadorB_V + contadorElevadorB_N > maxFrequencia) {
        maxFrequencia = contadorElevadorB_M + contadorElevadorB_V + contadorElevadorB_N;
        elevadorMaisFrequente = 'B';
    }
    if (contadorElevadorC_M + contadorElevadorC_V + contadorElevadorC_N > maxFrequencia) {
        maxFrequencia = contadorElevadorC_M + contadorElevadorC_V + contadorElevadorC_N;
        elevadorMaisFrequente = 'C';
    }

    // Encontrando o período mais usado
    char periodoMaisUtilizado;

    if (totalMatutino > totalVespertino && totalMatutino > totalNoturno) {
        periodoMaisUtilizado = 'M';
    } else if (totalVespertino > totalMatutino && totalVespertino > totalNoturno) {
        periodoMaisUtilizado = 'V';
    } else {
        periodoMaisUtilizado = 'N';
    }

    // Calculando a diferença percentual entre o mais usado e o menos usado
    float diferencaPercentual = ((float)(totalMatutino - totalNoturno) / totalNoturno) * 100;

    // Calculando a percentagem sobre o total de serviços prestados do elevador de média utilização
    int totalServicosElevadorMedio = contadorElevadorB_M + contadorElevadorB_V + contadorElevadorB_N;
    float percentagemElevadorMedio = ((float)totalServicosElevadorMedio / (NUM_MORADORES * 2)) * 100;  // Dividido por 2, pois são dois períodos por morador

    // Imprimindo os resultados
    printf("\nResultados:\n");
    printf("Período mais usado de todos e o elevador: %c%c\n", periodoMaisUtilizado, elevadorMaisFrequente);
    printf("Elevador mais frequentado e período de maior fluxo: %c%c\n", elevadorMaisFrequente, periodoMaisUtilizado);
    printf("Diferença percentual entre o mais usado e o menos usado: %.2f%%\n", diferencaPercentual);
    printf("Percentagem sobre o total de serviços do elevador de média utilização: %.2f%%\n", percentagemElevadorMedio);

    return 0;
}

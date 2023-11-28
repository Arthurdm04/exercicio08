#include <stdio.h>

int main() {
    char resposta;
    do {
        int mes, ano, diasNoMes;

        // Solicita ao usuário o mês e o ano
        printf("Digite o mês (1-12): ");
        scanf("%d", &mes);

        printf("Digite o ano: ");
        scanf("%d", &ano);

        // Verifica se o mês está no intervalo válido
        if (mes < 1 || mes > 12) {
            printf("Mês inválido. Tente novamente.\n");
            continue;  // Reinicia o loop
        }

        // Determina o número de dias no mês
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                diasNoMes = 31;
                break;

            case 4: case 6: case 9: case 11:
                diasNoMes = 30;
                break;

            case 2:
                // Verifica se o ano é bissexto
                if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
                    diasNoMes = 29;
                } else {
                    diasNoMes = 28;
                }
                break;

            default:
                printf("Mês inválido. Tente novamente.\n");
                continue;  // Reinicia o loop
        }

        // Exibe o número de dias no mês/ano
        printf("O mês %d/%d possui %d dias.\n", mes, ano, diasNoMes);

        // Pergunta ao usuário se deseja fazer outra consulta
        printf("\nVOCÊ DESEJA OUTRAS ENTRADAS (S/?)? ");
        scanf(" %c", &resposta);

    } while (resposta == 'S' || resposta == 's');

    return 0;
}

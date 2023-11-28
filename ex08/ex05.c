#include <stdio.h>
#include <string.h>

#define MAX_ENTREVISTADOS 300
#define MIN_ENTREVISTADOS 50
#define MAX_NOME 50

// Estrutura para armazenar informações sobre a jogadora e os entrevistados
struct Jogadora {
    char nome[MAX_NOME];
    int votos;
};

struct Entrevistado {
    char nome[MAX_NOME];
    int idade;
    char sexo;
    char voto[MAX_NOME];
};

int main() {
    // Inicializando a lista de jogadoras e entrevistados
    struct Jogadora jogadoras[] = {{"Marta Vieira", 0}, {"Cristiane Rozeira", 0}, {"Sam Kerr", 0}, {"Alex Morgan", 0}, {"Ada Hegerberg", 0}};

    struct Entrevistado entrevistados[MAX_ENTREVISTADOS];
    int totalEntrevistados = 0;

    // Solicitando o número de entrevistados
    printf("Digite o número de entrevistados (entre %d e %d): ", MIN_ENTREVISTADOS, MAX_ENTREVISTADOS);
    scanf("%d", &totalEntrevistados);

    // Verificando se o número de entrevistados está dentro do intervalo permitido
    if (totalEntrevistados < MIN_ENTREVISTADOS || totalEntrevistados > MAX_ENTREVISTADOS) {
        printf("Número de entrevistados fora do intervalo permitido. O programa será encerrado.\n");
        return 1; // Retorna 1 indicando erro
    }

    // Realizando a pesquisa
    for (int i = 0; i < totalEntrevistados; i++) {
        printf("\nEntrevistado %d:\n", i + 1);

        // Solicitando informações do entrevistado
        printf("Nome: ");
        scanf("%s", entrevistados[i].nome);

        printf("Idade: ");
        scanf("%d", &entrevistados[i].idade);

        // Verificando se a idade é maior que 12 anos
        if (entrevistados[i].idade <= 12) {
            printf("A idade deve ser maior que 12 anos. O programa será encerrado.\n");
            return 1; // Retorna 1 indicando erro
        }

        printf("Sexo (M/F): ");
        scanf(" %c", &entrevistados[i].sexo);

        // Verificando se o sexo é válido
        if (entrevistados[i].sexo != 'M' && entrevistados[i].sexo != 'F') {
            printf("Sexo inválido. O programa será encerrado.\n");
            return 1; // Retorna 1 indicando erro
        }

        printf("Voto (Marta Vieira, Cristiane Rozeira, Sam Kerr, Alex Morgan, Ada Hegerberg): ");
        scanf("%s", entrevistados[i].voto);

        // Verificando se o voto é válido
        int votoValido = 0;
        for (int j = 0; j < sizeof(jogadoras) / sizeof(jogadoras[0]); j++) {
            if (strcmp(entrevistados[i].voto, jogadoras[j].nome) == 0) {
                votoValido = 1;
                jogadoras[j].votos++;
                break;
            }
        }

        if (!votoValido) {
            printf("Voto inválido. O programa será encerrado.\n");
            return 1; // Retorna 1 indicando erro
        }
    }

    // Exibindo relatórios
    printf("\nRelatórios:\n");

    // Exibindo a quantidade de votos que cada jogadora recebeu
    printf("\nQuantidade de votos para cada jogadora:\n");
    for (int i = 0; i < sizeof(jogadoras) / sizeof(jogadoras[0]); i++) {
        printf("%s: %d votos\n", jogadoras[i].nome, jogadoras[i].votos);
    }

    // Exibindo a jogadora mais votada (ou empate)
    printf("\nJogadora(s) mais votada(s):\n");
    int maxVotos = 0;
    for (int i = 0; i < sizeof(jogadoras) / sizeof(jogadoras[0]); i++) {
        if (jogadoras[i].votos > maxVotos) {
            maxVotos = jogadoras[i].votos;
        }
    }

    for (int i = 0; i < sizeof(jogadoras) / sizeof(jogadoras[0]); i++) {
        if (jogadoras[i].votos == maxVotos) {
            printf("%s\n", jogadoras[i].nome);
        }
    }

    // Exibindo informações sobre os entrevistados (separando por sexo, maior de idade e menor de idade)
    printf("\nInformações sobre os entrevistados:\n");
    printf("\nMulheres:\n");
    for (int i = 0; i < totalEntrevistados; i++) {
        if (entrevistados[i].sexo == 'F') {
            printf("Nome: %s, Idade: %d\n", entrevistados[i].nome, entrevistados[i].idade);
        }
    }

    printf("\nHomens:\n");
    for (int i = 0; i < totalEntrevistados; i++) {
        if (entrevistados[i].sexo == 'M') {
            printf("Nome: %s, Idade: %d\n", entrevistados[i].nome, entrevistados[i].idade);
        }
    }

    printf("\nMaiores de idade:\n");
    for (int i = 0; i < totalEntrevistados; i++) {
        if (entrevistados[i].idade >= 18) {
            printf("Nome: %s, Sexo: %c\n", entrevistados[i].nome, entrevistados[i].sexo);
        }
    }

    printf("\nMenores de idade:\n");
    for (int i = 0; i < totalEntrevistados; i++) {
        if (entrevistados[i].idade < 18) {
            printf("Nome: %s, Sexo: %c\n", entrevistados[i].nome, entrevistados[i].sexo);
        }
    }

    // Exibindo o nome das pessoas maior de idade que votaram na Marta Vieira
    printf("\nPessoas maior de idade que votaram na Marta Vieira:\n");
    for (int i = 0; i < totalEntrevistados; i++) {
        if (entrevistados[i].idade >= 18 && strcmp(entrevistados[i].voto, "Marta Vieira") == 0) {
            printf("Nome: %s\n", entrevistados[i].nome);
        }
    }

    // Exibindo a quantidade de mulheres que participaram da pesquisa
    int mulheresParticipantes = 0;
    for (int i = 0; i < totalEntrevistados; i++) {
        if (entrevistados[i].sexo == 'F') {
            mulheresParticipantes++;
        }
    }
    printf("\nQuantidade de mulheres que participaram da pesquisa: %d\n", mulheresParticipantes);

    return 0;
}

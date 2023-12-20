#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numerodequestoes = 0;
    int nota = 0;
    printf("Quantas questoes tera a prova:\n");
    scanf("%d", &numerodequestoes);
    
    char **gabarito = (char **)malloc(numerodequestoes * sizeof(char *));
    
    for (int numerodaquestao = 0; numerodaquestao < numerodequestoes; numerodaquestao++) {
        gabarito[numerodaquestao] = (char *)malloc(2 * sizeof(char));
        printf("Digite a resposta para a questao %d:\n", numerodaquestao + 1);
        scanf("%s", gabarito[numerodaquestao]);
    }

    char **provaaluno = (char **)malloc(numerodequestoes * sizeof(char *));
    
    for (int questao = 0; questao < numerodequestoes; questao++) {
        provaaluno[questao] = (char *)malloc(2 * sizeof(char));
        printf("Digite a resposta para a questao %d:\n", questao + 1);
        scanf("%s", provaaluno[questao]);

        if (strcmp(provaaluno[questao], gabarito[questao]) == 0) {
            printf("Resposta correta\n");
            nota ++     ;
        } else {
            printf("Resposta errada\n");
        }
    }
    printf("Nota final do aluno: %d", nota);
    // Liberar memória alocada
    for (int i = 0; i < numerodeque     stoes; i++) {
        free(gabarito[i]);
        free(provaaluno[i]);
    }
    free(gabarito);
    free(provaaluno);

    return 0;
}

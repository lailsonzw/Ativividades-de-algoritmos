#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;


    printf("Digite o numero de pessoas a serem entrevistadas: ");
    scanf("%d", &N);


    char *sexo = (char *)malloc(N * sizeof(char));
    char *opiniao = (char *)malloc(N * sizeof(char));

    
    if (sexo == NULL || opiniao == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    
    for (int i = 0; i < N; i++) {
        printf("Entrevistado %d:\n", i + 1);


        printf("Sexo (M/F): ");
        scanf(" %c", &sexo[i]);

        
        printf("Opiniao sobre o produto (gostou/não gostou): ");
        scanf(" %c", &opiniao[i]);
    }

    
    int mulheresGostaram = 0;
    for (int i = 0; i < N; i++) {
        if (sexo[i] == 'F' && opiniao[i] == 'g') {
            mulheresGostaram++;
        }
    }
    float percentualMulheresGostaram = (float)mulheresGostaram / N * 100;

    printf("\nPorcentagem de mulheres que gostaram do produto: %.2f%%\n", percentualMulheresGostaram);

    int homensNaoGostaram = 0;
    for (int i = 0; i < N; i++) {
        if (sexo[i] == 'M' && opiniao[i] == 'n') {
            homensNaoGostaram++;
        }
    }
    float percentualHomensNaoGostaram = (float)homensNaoGostaram / N * 100;

    printf("Porcentagem de homens que não gostaram do produto: %.2f%%\n", percentualHomensNaoGostaram);

    
    free(sexo);
    free(opiniao);

    return 0;
}

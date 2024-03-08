#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Escreva um programa em C que leia de um arquivo as notas dos alunos de uma
//turma e escreva em outro arquivo o nome e a média de cada aluno, bem como a sua situação
//(aprovado (média >= 7.0) ou reprovado). Tanto no arquivo de entrada quanto no de saída,
//considere que os dados em cada linha estão separados por um caractere de tabulação ‘\t’. Para a
//execução do programa com o arquivo de entrada “entrada_q3.txt”, deverá ser criado o arquivo
//de saída “saída_q3.txt”, como ilustrado a seguir.

int main(void){

//1 - desafio, criar as variaves necessarias para armazenar os dados;

    FILE *entrada, *saida;
    char nome[30], linha[100];
    float nota1, nota2, nota3;
    float media = 0.0;

//2 - desafio, abrir o arquivo de entrada;

    entrada = fopen("entrada_q3.txt", "r");
    if(entrada == NULL)
    {
        printf("Erro ao abrir o aquivo.\n");
        exit(1);
    }

//3 - desafio, abrir/criar o arquivo de saida;

    saida = fopen("saida_q3.txt", "w");
    if(saida == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

//4 - desafio, passar os arquivos.txt para as variaves;

    while (!feof(entrada))
    {
        fgets(linha,100,entrada);

        sscanf(linha, "%s %f %f %f", nome, &nota1, &nota2, &nota3);
        media = (nota1 + nota2 + nota3)/3;
       
        if(saida)
        {
            
            printf("NOME: %s, primeira nota: %.2f, segunda nota: %.2f, terceira nota: %.2f\n",nome, nota1, nota2, nota3);
            printf("Media = %.2f\n\n", media);
        }

        fprintf(saida,"%s %f %f %f media: %f\n Situacao: %s\n\n",nome, nota1, nota2, nota3, media, (media >= 7)?"aprovado":"reprovado");

    }
    
}
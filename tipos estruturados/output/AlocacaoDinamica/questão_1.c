#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//criando uma funçao para verificar quantas pessoas vão participar da entrevista;
void verificar_quantidade(int *quantidade)
{
    *quantidade = 0;
    printf("Digite quantas pessoas vão fazer a entrevista:\n");
    scanf("%d", &*quantidade);
}

//funcao para calcular a porcentagem das mulheres que gostaram do produto;
void porcentagemF(int *valor_total, int *valor_da_porcentagem, int *resultado)
{
    *resultado = ((*valor_da_porcentagem) * 100) / *valor_total;  
    printf("A porcentagem das mulheres que gostaram do produto foi de: %d por cento\n",*resultado);
}

void porcentagemH(int *valor_total, int *valor_da_porcentagem, int *resultado)
{
    *resultado = ((*valor_da_porcentagem) * 100) / *valor_total;  
    printf("A porcentagem dos homens que nao gostaram do produto foi de: %d por cento\n",*resultado);
}

int  main()
{
    //Q1-a 
    int quantidade = 0;
    int numero = 0;
    verificar_quantidade(&quantidade);

    //Espaços alocados para receber o sexo e a opiniao do cliente;
    char **sexo = (char**)malloc(quantidade * sizeof(char*));
    char **opiniao = (char**)malloc(quantidade * sizeof(char*));

    // funcao que irar alocar 2 caracter em cada casa do vetor principal;
    for(numero = 0; numero < quantidade; numero++)
    {
        sexo [numero] = (char*)malloc(2 * sizeof(char));
        opiniao [numero] = (char*)malloc(2 * sizeof(char));

        if( sexo[numero] == NULL || opiniao[numero] == NULL)
        {
            exit(1);
        }
    }    

    //funcao que irar preencher o dado de cada usuario;
    for(numero = 0; numero < quantidade; numero++)
    {
        printf("Digite seu sexo [M/F]:\n");
        scanf("%s",sexo[numero]);

        printf("Diga sua opiniao em relacao ao produto[G/N]:\n");
        scanf("%s",opiniao[numero]);
    }
   

    printf("lista\n");
    //funcao que irar mostra o perfil de cada pessoa;
    for (numero = 0; numero < quantidade; numero++) {
        printf("Pessoa %d: Sexo: %s, Opiniao: %s\n", numero + 1, sexo[numero], opiniao[numero]);
    }

    //Q1-b;
    int mulheres_gostaram = 0;
    int resultadoo;
    int totalf = 0;
    
    //Algoritmo que irar procurar quantas mulheres gostaram do produto;
    for (numero = 0; numero < quantidade; numero++) {
        
        if (sexo[numero][0] == 'F' && opiniao[numero][0] == 'G') {
            
            mulheres_gostaram++;
        }
        if (sexo[numero][0] == 'F')
        {
            totalf ++;
        }
    }
    printf("quantas mulheres gostaram: %d\n", mulheres_gostaram);
    
    //chamando a funcao para calcular a porcentagem feminina;
    porcentagemF(&totalf, &mulheres_gostaram, &resultadoo);
    resultadoo = 0;
    
    //Q1-c;
    int homens_naogostaram= 0;
    int totalm = 0;
    
    //Algoritmo que irar procurar quantas mulheres gostaram do produto;
    for (numero = 0; numero < quantidade; numero++) {
        
        if (sexo[numero][0] == 'M' && opiniao[numero][0] == 'N') 
        {
            homens_naogostaram++;
        }
        if(sexo[numero][0] == 'M')
        {
            totalm++;
        }
        
    }
    printf("quantos homens nao gostaram: %d\n", homens_naogostaram);
    
    //chamando a funcao para calcular a porcentagem feminina;
    porcentagemH(&totalm, &homens_naogostaram, &resultadoo);
   
    //comando para limpar a memoria alocada
    for (numero = 0; numero < quantidade; numero++) 
    {
    free(sexo[numero]);
    free(opiniao[numero]);
    }

    free(sexo);
    free(opiniao);
    return 0;
}

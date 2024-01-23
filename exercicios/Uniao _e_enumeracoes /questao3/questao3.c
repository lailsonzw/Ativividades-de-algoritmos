//META: Escreva um programa que implementa uma struct Data com os campos dia, mˆes e ano. O mˆes deve
//ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARC ̧ O, ABRIL, MAIO,
//JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
//deve ler a data e imprimir a data no formato dd/mm/aaaa.
//A pr ́atica leva ao aprimoramento.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

  typedef enum meses_do_ano {Janeiro = 1, Fevereiro =2, Marco = 3, Abril = 4, Maio = 5, Junho =6,
  Julho = 7, Agosto = 8, Setembro = 9, Outubro = 10, Novembro = 11, Dezembro = 12}meses;

  typedef struct data{
    int dia;
    int ano;
    meses mes;
  }datas;
int main(void)
{
  datas tempo;

  printf("Digite o dia:\n");
  scanf("%d",&tempo.dia);
  printf("Digite o numero do mes:\n");
  scanf("%d",&tempo.mes);
  printf("Digite o ano em que estamos:\n");
  scanf("%d",&tempo.ano);
  
  //Testando se o valor está na faixa válida usando os valores da enum
  if(tempo.mes > 0 && tempo.mes <= Dezembro)
  {
  
    //switch que determina qual mes será impresso na tela
    switch(tempo.mes)
    {
    
    case Janeiro:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);
    break;
    
    case Fevereiro:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);
    break;
    
    case Marco:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);   
    break;
    
    case Abril:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);
    break;
    
    case Maio:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);
    break;
    
    case Junho:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);   
    break;
    
    case Julho:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);
    break;
    
    case Agosto:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);  
    break;
    
    case Setembro:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);   
    break;
    
    case Outubro:
      printf("data atual: %d/0%d/%d",tempo.dia, tempo.mes, tempo.ano);   
    break;
      printf("data atual: %d/%d/%d",tempo.dia, tempo.mes, tempo.ano);
    
    case Novembro:
      printf("data atual: %d/%d/%d",tempo.dia, tempo.mes, tempo.ano);
    break;
  
    case Dezembro:
      printf("data atual: %d/%d/%d",tempo.dia, tempo.mes, tempo.ano);
    break;
    }
  }
  else //senão estiver na faixa válida exibe mensagem
  {
    printf("Valor INVALIDO!!!\n");
  }
  
  return 0;
}
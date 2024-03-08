#Escreva um programa em Python que leia de um arquivo as notas dos alunos de uma
#turma e escreva em outro arquivo o nome e a média de cada aluno, bem como a sua situação
#(aprovado (média >= 7.0) ou reprovado). Tanto no arquivo de entrada quanto no de saída,
#considere que os dados em cada linha estão separados por um caractere de tabulação ‘\t’. Para a
#execução do programa com o arquivo de entrada “entrada_q3.txt”, deverá ser criado o arquivo
#de saída “saída_q3.txt”, como ilustrado a seguir.

#1 desafio abrir o arquivo de entrada para leitura de dados;

entrada = open("entrada_q3.txt", "r")

#2 desafio abrir o criar o arquivo de saida para receber os dados do arquivo de entrada;

saida = open("saida_q3.txt", "w")

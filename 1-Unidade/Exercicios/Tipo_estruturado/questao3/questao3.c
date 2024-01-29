#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Meta: Defina estruturas para representar retângulos (dadas a base e a altura) e círculos (dado o raio), e implemente as funções a seguir;
typedef struct retangulo {
    float base;
    float altura;
} Retangulo;

typedef struct circulo {
    float raio;
} Circulo;

//1 desafio: Dado um círculo, crie e retorne o maior retângulo circunscrito de altura h. Considere que h é menor doque o diâmetro do círculo;
Retangulo* ret_circunscrito(Circulo* circ, float h) {
    Retangulo* ret = (Retangulo*)malloc(sizeof(Retangulo));

    // Calcula o lado do retângulo circunscrito
    float lado = sqrt(pow(2 * circ->raio, 2) - pow(h, 2));

    ret->base = lado;
    ret->altura = h;

    return ret;
}

Circulo* circ_interno(Retangulo* ret) {
    Circulo* circ = (Circulo*)malloc(sizeof(Circulo));

    // Calcula o raio do círculo interno
    circ->raio = (ret->base < ret->altura) ? ret->base / 2 : ret->altura / 2;

    return circ;
}

void Preenchercirculo(Circulo *CirculoRaio)
{
    printf("Digite o raio do círculo: ");
    scanf("%f", &CirculoRaio->raio);
}

void preencherRetangulo(float h)
{
    printf("Coloque a altura do retângulo circunscrito: ");
    scanf("%f", &h);
}

int main() {
    Retangulo* retangulo;
    Circulo* circulo;

    circulo = (Circulo*)malloc(sizeof(Circulo));
    retangulo = (Retangulo*)malloc(sizeof(Retangulo));

    // Verifica se a alocação de memória foi bem-sucedida
    if (circulo == NULL || retangulo == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    float h = 0.0;

    // Preencher os dados do círculo
    Preenchercirculo(&circulo);

    // Preencher os dados do retângulo
    preencherRetangulo(h);

    retangulo = ret_circunscrito(circulo, h);

    printf("O maior retângulo circunscrito tem uma base de %.2f e altura %.2f.\n", retangulo->base, retangulo->altura);

    circulo = circ_interno(retangulo);

    printf("O maior círculo interno tem raio de %.2f.\n", circulo->raio);

    free(circulo);
    free(retangulo);

    return 0;
}
#include <stdio.h>

int main(){
    
    int x,y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    //valor de x vai ser igual a 3, pois na linha 11 x = x-1;
    //y vai ser igual a 4 pois na linha 10 o ponteiro aponta o valor 1 para y, e logo em seguida é incrementado +3 para y;
    //o valor do ponteiro vai ser o endereço de y;
    


    return 0;
}
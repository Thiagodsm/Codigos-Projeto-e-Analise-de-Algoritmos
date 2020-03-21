/// Thiago da Silva Moreira RA: 114834
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int conta_bit (long int x){
    x +=1;
    long int n_bits = x/2;
    long int pot2 = 2;
    long int grupos = 0 ,cont=1;
    while (pow(2,cont) <= x) {
        grupos = x/pot2;
        n_bits += (grupos/2)*pot2;
        if(grupos%2 == 1)
            n_bits += x%pot2;
        cont++;
        pot2 = pow(2,cont);
    }
    return n_bits;
}

int main(int argc, char const *argv[]) {

    long int n1, n2;
    long int resultado;
    scanf("%li",&n1);
    scanf("%li",&n2);

    resultado = conta_bit(n2) - conta_bit(n1-1);
    printf("%li\n",resultado);
    return 0;
}

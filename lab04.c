# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }

int MochilaSemLimites(int capacidade, int itens, int *valores, int *pesos){

    int *max_valor = calloc((capacidade+1), sizeof(int));
    int ans = 0;

    for(int i = 0; i <= capacidade; i++)
        for(int j = 0; j < itens; j++)
            if(pesos[j] <= i)
                max_valor[i] = max(max_valor[i], max_valor[i - pesos[j]] + valores[j]);
    return max_valor[capacidade];
}

int main(int argc, char const *argv[]) {
    int P, N, i;

    scanf("%d",&P);
    scanf("%d",&N);

    int *t_i = malloc(N * sizeof(int));
    int *v_i = malloc(N * sizeof(int));

    for(i = 0; i <  N; i++)
        scanf("%d %d", &t_i[i], &v_i[i]);

    printf("%d\n",MochilaSemLimites(P, N, v_i, t_i));

    return 0;
}

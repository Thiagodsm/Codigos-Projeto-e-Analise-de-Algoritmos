#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void imprime(int *vetor, int tmh){
    int i;
    for (i = 0; i < tmh; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

}
int is_a_solution(int *vetor, int tmh){
    int i;
    for(i = 0; i < tmh; i++){
        if(vetor[i] != -1)
            return 0;
    }
    return 1;
}

// n2 = n - m
void backtrack(int *vetor, int k, int n, int n2, int *aux, int *posicao)
{
    //int c[MAXCANDIDATES]; // candidates for next position 
    //int ncandidates; // next position candidate count 
    int i; // counter
    int temporario; 

    if (is_a_solution(aux, n2)){
        imprime(vetor, n);
        return;  
    }

    for(i = 0; i < n2; i++){
        if(aux[i] != -1){
            vetor[posicao[k]-1] = aux[i];
            temporario = aux[i];
            aux[i] = -1;
            backtrack(vetor, k+1, n, n2, aux, posicao);
            aux[i] = temporario;
            //printf("passou por aqui %d vez(es)\n", i);
        }
    }
}
   
int main(int argc, char const *argv[]) {
    int n, m, i, j = 0, x1, y1, k = 0;
    scanf("%d %d", &n ,&m);

    int *vetor = calloc(n, sizeof(int));
    int *temp = calloc(n, sizeof(int));
    int *aux = malloc((n - m) * sizeof(int));
    int *posicao = malloc((n - m) * sizeof(int));
   

    for(i = 0; i < m; i++){
        scanf("%d %d",&x1, &y1);
        vetor[y1 - 1] = x1;
        temp[x1 - 1] = -1;
    }
    for(i = 0; i < n; i++){
        if(vetor[i] == 0){
            posicao[k] = i+1;
            k++;
        }
        if(temp[i] == 0){
            aux[j] = i + 1;
            j++;
        }
    }
    /*
    for(i = 0; i < n; i++){
        if(temp[i] == 0){
            aux[j] = i + 1;
            j += 1;
        }
    }
    */
    // Quantidade de combinacoes (n-m)!
    /*
    printf("\nValores que nao se alteram: ");
    for(i = 0; i < n; i++)
        printf("%d ",vetor[i]);

    printf("\nVetor temporario: ");
    for(i = 0; i < n; i++)
        printf("%d ",temp[i]);

    printf("\nValores que serao permutados: ");
    for(i = 0; i < n - m; i++)
        printf("%d ",aux[i]);
    
    printf("\nPosicoes: ");
    for(i = 0; i < n-m; i++)
        printf("%d ",posicao[i]);
    printf("\n");
    */
    free(temp);

    //printf("\nVai comecar o backtrack\n");
    backtrack(vetor, 0, n, n-m, aux, posicao);

    printf("\n");
    return 0;
}

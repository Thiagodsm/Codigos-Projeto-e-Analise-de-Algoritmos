# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
// Intercala == Merge
// first subarray is A[low_1...high_1]
// second subarray is A[low_2...high_2]

void Merge(long int* A,long int low,long int high,long int mid){
    // A[low...mid] and A[mid+1 ... high]
    long int i, j, k;
    long int size_1 = mid - low + 1;
    long int size_2 = high - mid;
    // auxiliar arrays
    long int L[size_1 + 1];
    long int R[size_2 + 1];
    L[size_1+1] = INT_MAX; R[size_2+1] = INT_MAX;

    // copying the left anda right subarrays´s
    for(i = 1; i<= size_1; i++)
        L[i] = A[low + i - 1];
    for(j = 1; j<= size_2; j++)
        R[j] = A[mid + j];

    i = 1; j = 1;
    for(k = low; k <= high; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
// Ordena == MergeSort
void MergeSort(long int* A,long int low,long int high,long int fixed_size){
    long int mid, i;

    if(low < high){
        mid = (low + high)/2;
        MergeSort(A, low, mid, fixed_size);
        MergeSort(A, mid+1, high, fixed_size);
        Merge(A, low, high, mid);
        // for(i = 0; i < fixed_size; i++)
        //     printf("%li " , A[i]);
        // printf("\n");
    }
}

long int somaMaior(long int* S, long int n, long int m){
    long int i = 0, j = n, soma = 0;
    while (i != j || soma == m){
        if(S[i] + S[j] > m)
            j--;
        else{
            if(S[i] + S[j] > m){
                soma = S[i] + S[j];
                printf("%li\n",soma);
            }
            i++;
        }
    }
    return soma;
}

int main(int argc, char const *argv[]) {

        long int n_musicas, tempo;
        scanf("%li",&n_musicas);
        scanf("%li",&tempo);
        long int *playlist = malloc(n_musicas * sizeof(long int));

        for(long int i = 0; i < n_musicas; i++)
            scanf("%li", &playlist[i]);

        MergeSort(playlist, 0, n_musicas-1, n_musicas);

        // playlist ordenada
        for(long int i = 0; i < n_musicas; i++)
            printf("%li " , playlist[i]);

        printf("ordenado\n");

        long int maior = somaMaior(playlist, n_musicas, tempo);
        printf("\n%li\n",maior);

    return 0;
    }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 999999
#define ARRAY_SIZE 100000 

void ler_arquivo(int *arr, int tam, const char *arq_ref) {
    FILE *file = fopen(arq_ref, "r");
    if (file == NULL) {
        printf("Erro: %s\n", arq_ref);
        exit(1);
    }

    for (int i = 0; i < tam; ++i) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void arquivo_de_saida(int *arr, int tam, int trocas, double tempo_passado, const char *arq_ref, const char *algorithm_name) {
    char output_arq_ref[100];
    snprintf(output_arq_ref, sizeof(output_arq_ref), "%s_%s_resultado_%d.txt", algorithm_name, arq_ref, tam);

    FILE *file = fopen(output_arq_ref, "w");
    if (file == NULL) {
        printf("Erro: %s\n", output_arq_ref);
        exit(1);
    }

    fprintf(file, "Vetor Ordenado:\n");
    for (int i = 0; i < tam; ++i) {
        fprintf(file, "%d\n", arr[i]);
    }

    fprintf(file, "\nNúmero de trocas: %d\n", trocas);
    fprintf(file, "Tempo de execução: %.6f segundos\n", tempo_passado);

    fclose(file);
}

void merge(int *arr, int esquerda, int meio, int direita, int *trocas) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*trocas)++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int esquerda, int direita, int *trocas) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        merge_sort(arr, esquerda, meio, trocas);
        merge_sort(arr, meio + 1, direita, trocas);

        merge(arr, esquerda, meio, direita, trocas);
    }
}

int main() {
    const char *arq_refs[15] = {
        "1000-arq1.txt",
        "1000-arq2.txt",
        "1000-arq3.txt",
        "1000-arq4.txt",
        "1000-arq5.txt", // 1000
        "10000-arq1.txt",
        "10000-arq2.txt",
        "10000-arq3.txt",
        "10000-arq4.txt",
        "10000-arq5.txt", //10.000
        "100000-arq1.txt",
        "100000-arq2.txt",
        "100000-arq3.txt",
        "100000-arq4.txt",
        "100000-arq5.txt" //100.000
    };

    for (int file_index = 0; file_index < 15; ++file_index) {
        int arr[ARRAY_SIZE];
        int trocas = 0;
        const int tam = 1000;  

        ler_arquivo(arr, tam, arq_refs[file_index]);

        clock_t start_time = clock();
        merge_sort(arr, 0, tam - 1, &trocas);
        clock_t end_time = clock();

        double tempo_passado = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        char output_arq_ref[100];
        snprintf(output_arq_ref, sizeof(output_arq_ref), "merge_sort_resultado_%d.txt", file_index + 1);

        arquivo_de_saida(arr, tam, trocas, tempo_passado, output_arq_ref, "merge_sort");
    }

    return 0;
}

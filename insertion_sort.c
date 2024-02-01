#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 999999
#define ARRAY_SIZE 100000 // Defina o tamanho máximo do array conforme necessário

void read_input_file(int *arr, int size, const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }

    for (int i = 0; i < size; ++i) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void write_output_file(int *arr, int size, int swaps, double elapsed_time, const char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }

    fprintf(file, "Sorted Array:\n");
    for (int i = 0; i < size; ++i) {
        fprintf(file, "%d\n", arr[i]);
    }

    fprintf(file, "\nNumber of swaps: %d\n", swaps);
    fprintf(file, "Elapsed time: %.6f seconds\n", elapsed_time);

    fclose(file);
}

void insertion_sort(int *arr, int size, int *swaps) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*swaps)++;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int swaps = 0;

    // Exemplo para 1.000 valores (altere conforme necessário)
    const char *file_name = "1000-arq1.txt";
    const int size = 1000;

    read_input_file(arr, size, file_name);

    clock_t start_time = clock();
    insertion_sort(arr, size, &swaps);
    clock_t end_time = clock();

    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Salvando resultados em um arquivo de saída
    write_output_file(arr, size, swaps, elapsed_time, "insertion_sort_resultado.txt");

    return 0;
}

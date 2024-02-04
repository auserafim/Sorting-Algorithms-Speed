#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 999999
#define ARRAY_SIZE 100000 

void read_input_file(int *arr, int tam, const char *arq_ref) {
    FILE *file = fopen(arq_ref, "r");
    if (file == NULL) {
        printf("Error: %s\n", arq_ref);
        exit(1);
    }

    for (int i = 0; i < tam; ++i) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void write_output_file(int *arr, int tam, int trocas, double tempo_passado, const char *arq_ref) {
    FILE *file = fopen(arq_ref, "w");
    if (file == NULL) {
        printf("Error: %s\n", arq_ref);
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

void insertion_sort(int *arr, int tam, int *trocas) {
    for (int i = 1; i < tam; ++i) {
        int corte = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > corte) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*trocas)++;
        }

        arr[j + 1] = corte;
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
        // Add files for 100000
        "100000-arq1.txt",
        "100000-arq2.txt",
        "100000-arq3.txt",
        "100000-arq4.txt",
        "100000-arq5.txt" //100.000
    };

    for (int file_index = 0; file_index < 15; ++file_index) {
        int arr[ARRAY_SIZE];
        int trocas = 0;
        const int tam = 1000;  // Adjust tam as needed

        read_input_file(arr, tam, arq_refs[file_index]);

        clock_t start_time = clock();
        insertion_sort(arr, tam, &trocas);
        clock_t end_time = clock();

        double tempo_passado = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        // Generating output file name dynamically based on input file name
        char output_arq_ref[100];
        snprintf(output_arq_ref, sizeof(output_arq_ref), "insertion_sort_resultado_%d.txt", file_index + 1);

        // Saving results in an output file
        write_output_file(arr, tam, trocas, tempo_passado, output_arq_ref);
    }

    return 0;
}

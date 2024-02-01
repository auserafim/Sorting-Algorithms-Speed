#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 999999

// Protótipos das funções 
int valor_duplicado(int *, int, int); 
void gerador_de_arquivo(int , int );


void gerador_de_arquivo(int qtd_valores, int numero_de_arquivo) {
    char nome_arquivo[20];
    sprintf(nome_arquivo, "%d-arquivo%d.txt", qtd_valores, numero_de_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Error opening arquivo: %s\n", nome_arquivo);
        exit(1);
    }

    srand(time(NULL));

    int *valores_unicos = malloc(qtd_valores * sizeof(int));

    for (int i = 0; i < qtd_valores; ++i) {
        int valor;
        do {
            valor = rand() % MAX_VALUE + 1;
        } while (valor_duplicado(valores_unicos, i, valor));

        valores_unicos[i] = valor;
        fprintf(arquivo, "%d\n", valor);
    }

    fclose(arquivo);
    free(valores_unicos);
}


int valor_duplicado(int *array, int size, int valor) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == valor) {
            return 1;
        }
    }
    return 0;
}

int main() {
    
    for (int i = 1; i <= 5; ++i) {
        gerador_de_arquivo(1000, i);
    }

    for (int i = 1; i <= 5; ++i) {
        gerador_de_arquivo(10000, i);
    }

    for (int i = 1; i <= 5; ++i) {
        gerador_de_arquivo(100000, i);
    }

    return 0;
}

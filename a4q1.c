#include "header.h"

int main() {
    Row *rows[ROWNUM];

    importData(rows);
    buildHeap(rows);
    displayData(rows);
    freeHeap(rows);

    return 0;
}

bool importData(Row *rows[ROWNUM]) {
    FILE* file;
    char str[256];
    char *tokens;
    int index;
    int rowCount;
    
    file = fopen("f.dat", "r");
    index = 0;
    rowCount = 0;

    if(file == NULL) {
        fprintf(stderr, "%s", "Error opening file in \"importData\".");
        return false;
    }

    while(fgets(str, 100, file) != NULL) {
        Row *newRow = malloc(sizeof(Row));

        tokens = strtok(str, " ");
        newRow->key = 0;

        while(tokens != NULL) {
            if(strcmp(tokens, "\n") == 0) 
                break;

            if(index < 3) 
                newRow->key += atoi(tokens);

            newRow->content[index] = atoi(tokens);
            index++;
            tokens = strtok(NULL, DELIM);
        }

        index = 0;
        rows[rowCount] = newRow;
        rowCount++;
    }

    fclose(file);

    return true;
}

void displayData(Row *rows[ROWNUM]) {
    for(int i = 0; i < ROWNUM; i++) {
        for(int j = 0; j < COLNUM; j++) {
            if(rows[i]->content[j] < 10) 
                printf("0%d ", rows[i]->content[j]);
            else 
                printf("%d ", rows[i]->content[j]);
        }
        printf("\n");
    }
}

void buildHeap(Row *rows[ROWNUM]) {
    int startIndex = (ROWNUM / 2) - 1;

    for(int i = startIndex; i >= 0; i--) {
        heapify(rows, i);
    }
}

void heapify(Row *rows[ROWNUM], int i) {
    int min;
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    if(L >= ROWNUM || L < 0) 
        L = -1; 
    
    if(R >= ROWNUM || R < 0)
        R = -1;

    if(L != -1 && rows[L]->key < rows[i]->key)
        min = L;
    else   
        min = i;

    if(R != -1 && rows[R]->key < rows[min]->key)
        min = R;

    if(min != i) {
        swap(rows[min], rows[i]);

        heapify(rows, min);
    }
}

void swap(Row *rowA, Row *rowB) {
    int temp = rowA->key;
    int tempArr[COLNUM];

    rowA->key = rowB->key;
    rowB->key = temp;

    for(int i = 0; i < COLNUM; i++) {
        tempArr[i] = rowA->content[i];
    }
    for(int i = 0; i < COLNUM; i++) {
        rowA->content[i] = rowB->content[i];
    }
    for(int i = 0; i < COLNUM; i++) {
        rowB->content[i] = tempArr[i];
    }
}

void freeHeap(Row *rows[ROWNUM]) {
    for(int i = 0; i < ROWNUM; i++) {
        free(rows[i]);
    }
}
// Includes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Macros
#define ROWNUM 20
#define COLNUM 10
#define DELIM " "

// Struct
typedef struct Row {
    int key;
    int content[10];
} Row;

// Functions
bool importData(Row *rows[ROWNUM]);
void displayData(Row *rows[ROWNUM]);
void buildHeap(Row *rows[ROWNUM]);
void heapify(Row *rows[ROWNUM], int i);
void swap(Row *rowA, Row *rowB);
void freeHeap(Row *rows[ROWNUM]);
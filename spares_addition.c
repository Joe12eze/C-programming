#include <stdio.h>

int main() {
    int m, n, a[10][3], b[10][3], result[20][3];
    int i, j, k;
    int t1, t2;

    printf("Enter number of rows and columns of the matrices: ");
    scanf("%d %d", &m, &n);

    // Input for matrix A
    printf("Enter number of non-zero elements in Matrix A: ");
    scanf("%d", &t1);
    printf("Enter triplets (row column value) for Matrix A (in row-major sorted order):\n");
    for (i = 0; i < t1; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    // Input for matrix B
    printf("Enter number of non-zero elements in Matrix B: ");
    scanf("%d", &t2);
    printf("Enter triplets (row column value) for Matrix B (in row-major sorted order):\n");
    for (i = 0; i < t2; i++) {
        scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
    }

    // Matrix addition logic
    i = j = k = 0;
    while (i < t1 && j < t2) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            // Same position, add values
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        } else if (a[i][0] < b[j][0] || 
                  (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            // Take from A
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++; k++;
        } else {
            // Take from B
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++; k++;
        }
    }

    // Remaining elements from A
    while (i < t1) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }

    // Remaining elements from B
    while (j < t2) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }

    // Print result
    printf("\nResultant Sparse Matrix (Triplet Form):\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}


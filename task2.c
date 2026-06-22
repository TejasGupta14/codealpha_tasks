#include <stdio.h>

void inputMatrix(int r, int c, int a[r][c]);
void displayMatrix(int r, int c, int a[r][c]);
void addMatrix(int r, int c, int a[r][c], int b[r][c]);
void multiplyMatrix(int r1, int c1, int a[r1][c1],
                    int r2, int c2, int b[r2][c2]);
void transposeMatrix(int r, int c, int a[r][c]);

int main()
{
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);

    int a[r1][c1];

    printf("Enter elements of first matrix:\n");
    inputMatrix(r1, c1, a);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);

    int b[r2][c2];

    printf("Enter elements of second matrix:\n");
    inputMatrix(r2, c2, b);

    printf("\nFirst Matrix:\n");
    displayMatrix(r1, c1, a);

    printf("\nSecond Matrix:\n");
    displayMatrix(r2, c2, b);

    // Matrix Addition
    if (r1 == r2 && c1 == c2)
    {
        printf("\nAddition of Matrices:\n");
        addMatrix(r1, c1, a, b);
    }
    else
    {
        printf("\nAddition not possible.\n");
    }

    // Matrix Multiplication
    if (c1 == r2)
    {
        printf("\nMultiplication of Matrices:\n");
        multiplyMatrix(r1, c1, a, r2, c2, b);
    }
    else
    {
        printf("\nMultiplication not possible.\n");
    }

    // Transpose of First Matrix
    printf("\nTranspose of First Matrix:\n");
    transposeMatrix(r1, c1, a);

    return 0;
}

// Function to input matrix
void inputMatrix(int r, int c, int a[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int r, int c, int a[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrix(int r, int c, int a[r][c], int b[r][c])
{
    int sum[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix multiplication
void multiplyMatrix(int r1, int c1, int a[r1][c1],
                    int r2, int c2, int b[r2][c2])
{
    int mul[r1][c2];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            mul[i][j] = 0;

            for (int k = 0; k < c1; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }

            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
}

// Function for transpose
void transposeMatrix(int r, int c, int a[r][c])
{
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

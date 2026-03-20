#include <stdio.h>
#include <stdlib.h>

/*
 * Custom Matrix type.
 */
typedef struct
{
    int row;
    int col;
    int **matrix;
} Matrix;

/*
 * Creates a new Matrix of a size (r x c)
 * and returns a pointer to it.
 */
Matrix *NewMatrix(int r, int c)
{
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->row = r;
    matrix->col = c;

    matrix->matrix = malloc(matrix->row * sizeof(int *));
    for (int i = 0; i < matrix->row; i++)
    {
        matrix->matrix[i] = malloc(matrix->col * sizeof(int));
    }

    return matrix;
}

/*
 * Sets the given value at the given row and col
 * in the Matrix.
 */
void Set(Matrix *matrix, int r, int c, int value)
{
    if (r >= matrix->row || c >= matrix->col)
    {
        puts("Index out of bound");
        return;
    }

    matrix->matrix[r][c] = value;
}

/*
 * Returns the value at the given
 * row, col in the Matrix, if value
 * does not exits it returns -1.
 */
int Get(Matrix *matrix, int r, int c)
{
    if (r >= matrix->row || c >= matrix->col)
    {
        puts("Index out of bound");
        return -1;
    }

    return matrix->matrix[r][c];
}

/*
 * Searchs the give value in the Matrix.
 * Returns 1 if the value is present else
 * returns 0.
 */
int Search(Matrix *matrix, int value)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            if (matrix->matrix[i][j] == value)
            {
                return 1;
            }
        }
    }
    return 0;
}

/*
 * Prints the elements of the given Matrix.
 */
void Print(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

/*
 * Deallocates the memory used by the given Matrix.
 */
void Destroy(Matrix *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

/*
 * Returns a Transposed Matrix of the given Matrix.
 */
Matrix *Transpose(Matrix *matrix)
{
    Matrix *new_matrix = NewMatrix(matrix->col, matrix->row);

    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            new_matrix->matrix[i][j] = matrix->matrix[j][i];
        }
    }

    Destroy(matrix);
    return new_matrix;
}

int main()
{
    Matrix *matrix = NewMatrix(5, 5);

    int x = 1;
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->col; j++)
        {
            Set(matrix, i, j, x++);
        }
    }

    Print(matrix);

    int value = Get(matrix, 1, 1);
    printf("Value at (1,1) : %d\n", value);

    value = 3;
    int found = Search(matrix, value);
    if (found)
    {
        printf("Value %d exists in the Matrix\n", value);
    }
    else
    {
        printf("Value %d does not exists in the Matrix\n", value);
    }

    matrix = Transpose(matrix);
    Print(matrix);

    Destroy(matrix);

    return 0;
}

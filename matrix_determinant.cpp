#include <iostream>
#include <limits>

float at(float *A, int i, int j, int cols)
{
    return A[i * cols + j];
}

void at(float *A, int i, int j, int cols, float aij)
{
    A[i * cols + j] = aij;
}

// void display_matrix(float *A, int rows, int cols)
// {
//     std::cout << std::endl;
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             std::cout << at(A, i, j, cols) << ' ';
//         }
//         std::cout << std::endl;
//     }
// }

void display_matrix(float *A, int rows, int cols)
{

    if (rows <= 0 || cols <= 0)
    {
        std::cout << "Error: Either rows or cols was 0 or negative. Exitting...\n"
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << at(A, i, j, cols) << ' ';
        }
        std::cout << std::endl;
    }
}

void extract_cofactor(float *cofactor, float *A, int row_i, int col_j, int A_rows)
{
    int cofact_rows = A_rows - 1, ii = 0;
    for (int i = 0; i < A_rows; i++)
    {
        int jj = 0;
        if (i == row_i)
            continue;
        for (int j = 0; j < A_rows; j++)
        {
            if (j == col_j)
                continue;
            at(cofactor, ii, jj, cofact_rows, at(A, i, j, A_rows));
            jj++;
        }
        ii++;
    }
}

float determinant(float *A, int rows)
{
    float det = 0;
    if (rows == 1)
        return at(A, 0, 0, 1);
    // if (rows == 2)
    //     return at(A, 0, 0, 2) * at(A, 1, 1, 2) - at(A, 0, 1, 2) * at(A, 1, 0, 2);
    int c = 1, cofact_rows = rows - 1;
    float cofact_det, Aij;
    float *cofactor = new float[cofact_rows * cofact_rows];
    int i = 0;
    std::cout << "For the matrix" << std::endl;
    display_matrix(A, rows, rows);
    std::cout << "Co-factors:"<<std::endl;
    for (int j = 0; j < rows; j++)
    {
        extract_cofactor(cofactor, A, i, j, rows);
        cofact_det = determinant(cofactor, cofact_rows);
        Aij = at(A, i, j, rows);
        det += c * Aij * cofact_det;
        c *= -1;
        display_matrix(cofactor, cofact_rows, cofact_rows);
        std::cout<<"Determinant = "<<det<<" + "<<c<<"*"<<Aij<<"*"<<cofact_det<<std::endl;
    }

    delete[] cofactor;
    return det;
}

void initialize_matrix(float *A, int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        std::cout << "Error: Either rows or cols was 0 or negative. Exitting...\n"
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    float aij{};
    for (size_t i = 0; i < (size_t)rows; i++)
    {
        for (int j = 0; j < (size_t)cols; j++)
        {
            std::cout << "A(" << i + 1 << ',' << j + 1 << ") = ";

            std::cin >> aij;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            A[(int)i * (cols) + (int)j] = aij;
        }
    }
}

int main()
{
    int rows, cols;
    std::cin >> rows;
    cols = rows;
    float *A = new float[rows * cols];
    // float inA[rows * cols] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // initialize_matrix(A, inA, rows, cols);
    initialize_matrix(A, rows, cols);
    display_matrix(A, rows, cols);
    float det = determinant(A, rows);
    std::cout << "|A| = " << det << std::endl;
    delete[] A;
}
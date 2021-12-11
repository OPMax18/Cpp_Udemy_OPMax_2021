#include "exercise.h"


namespace matrix
{

// Aufgabe 1
void print_double_2d_vector(const std::vector<std::vector<double>>& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        for (std::size_t j = 0; j < vec[0].size(); ++j)
        {
            std::cout << "Vec[" << i << "][" << j << "] = " << vec[i][j] << "\n";
        }
    }
    std::cout << "\n";
}

void initialize_matrix(matrix::Matrix& matrix, const int& num_rows, const int& num_cols)
{
    Matrix MyTempMatrix(num_rows, std::vector<double>(num_cols, 5));

    for (std::size_t i = 0; i < MyTempMatrix.size(); ++i)
    {
        for (std::size_t j = 0; j < MyTempMatrix[0].size(); ++j)
        {
            MyTempMatrix[i][j] = i + j;
        }
    }
    matrix = MyTempMatrix;
}


// Aufgabe 2
vector<double> max_row_values(Matrix& matrix)
{
    std::vector<double> rowMaxVec{};
    for (auto& row : matrix)
    {
        rowMaxVec.push_back(*std::max_element(row.begin(), row.end()));
    }
    return rowMaxVec;
}


// Aufgabe 3
double sort_and_max(vector<double>& vec)
{
    std::sort(vec.begin(), vec.end());
    //return *std::max_element(vec.begin(), vec.end());
    return vec.back(); // ist schon aufsteigend sortiert!!!
}

} // namespace matrix

#include "exercise.h"


// In eurem Programm bitte:
// your_main zu main ändern
int main()
{
    // Aufgabe 1
    auto num_rows = 3U;
    auto num_cols = 3U;
    matrix::Matrix myMatrix;

    matrix::initialize_matrix(myMatrix, num_rows, num_cols);
    matrix::print_double_2d_vector(myMatrix);

    // Aufgabe 2
    vector<double> row_max_vec = matrix::max_row_values(myMatrix);

    for (std::size_t i = 0; i != row_max_vec.size(); ++i)
    {
        cout << "Maximum of row " << i << " = " << row_max_vec[i] << endl;
    }
    cout << "\n";

    // Aufgabe 3
    double temp = row_max_vec[2];
    row_max_vec[2] = row_max_vec[1];
    row_max_vec[1] = temp;

    for (std::size_t i = 0; i != row_max_vec.size(); ++i)
    {
        cout << "Vector[" << i << "] = " << row_max_vec[i] << endl;
    }

    double max = matrix::sort_and_max(row_max_vec);

    for (std::size_t i = 0; i != row_max_vec.size(); ++i)
    {
        cout << "Sorted vector[" << i << "] = " << row_max_vec[i] << endl;
    }

    cout << "Vector max: " << max << endl;

    return 0;
}

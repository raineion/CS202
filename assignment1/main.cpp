/*
* Name: Daniel Martinez Julio, CS 202 - Summer II, Assignment 1
* Description: This program reads a file containing numerical data,
* calculates statistical properties (mean and standard deviation),
* and computes a histogram with a specified bin width.
* Input: File name containing the
         data and optional bin width for the histogram.
* Output: Mean, standard deviation, and 
         histogram details (bin numbers, edges, and counts).
*/

#include <iostream> // `cout`, `cin`, `cerr`
#include <iomanip> // `setw`, `fixed`, `setprecision`
#include <fstream> // `ifstream`
#include <cmath> // `pow`, `sqrt`, `ceil`, `floor`
#include <cstdio> // `sprintf`

using namespace std; // avoid using `std::`

/*
* calculate_statistics: Computes the mean and 
* standard deviation of the data, 
* rounded to two decimal places.
* parameters:
*   - const double* data: pointer to the array containing data
*   - int size: size of the array
*   - double& mean: reference to store the 
      computed mean (rounded to two decimal places)
*   - double& std_dev: reference to store the 
      computed standard deviation (rounded to two decimal places)
* return value: None (results are stored in the referenced parameters)
*/
void calculate_statistics(const double* data, int size, 
                         double& mean, double& std_dev) {
    double sum = 0.0;
    double sum_squared_diff = 0.0;
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (!isnan(data[i])) {
            sum += data[i];
            ++count;
        }
    }

    if (count == 0) {
        mean = 0;
        std_dev = 0;
        return;
    }

    mean = sum / count;

    for (int i = 0; i < size; ++i) {
        if (!isnan(data[i])) {
            sum_squared_diff += pow(data[i] - mean, 2);
        }
    }

    std_dev = sqrt(sum_squared_diff / count);

    mean = round(mean * 100) / 100;
    std_dev = round(std_dev * 100) / 100;
}

/*
* compute_histogram: Computes the histogram of the 
*                    data with the specified bin width.
* parameters:
*   - const double* data: pointer to the array containing data
*   - int size: size of the array
*   - int bin_width: the width of each bin in the histogram
* return value: None (results are printed directly)
*/
void compute_histogram(const double* data, int size, int bin_width) {
    if (size == 0) {
        return;
    }

    double min_value = data[0];
    double max_value = data[0];

    for (int i = 1; i < size; ++i) {
        if (data[i] < min_value) min_value = data[i];
        if (data[i] > max_value) max_value = data[i];
    }

    int bin_count = static_cast<int>(ceil(
                    (max_value - min_value) / bin_width)) + 1;
    int* bins = new int[bin_count]();

    for (int i = 0; i < size; ++i) {
        if (!isnan(data[i])) {
            int bin_index = static_cast<int>
            (floor((data[i] - min_value) / bin_width));
            if (bin_index >= bin_count) {
                bin_index = bin_count - 1;
            }
            ++bins[bin_index];
        }
    }

    cout << "bin number, left edge, right edge, count:\n";
    for (int i = 0; i < bin_count; ++i) {
        int left_edge = static_cast<int>(min_value) + i * bin_width;
        int right_edge = left_edge + bin_width;
        if (bins[i] != 0) {
            cout << setw(2) << i << " " 
                 << setw(5) << left_edge << " " 
                 << setw(6) << right_edge << " " 
                 << setw(6) << bins[i] << endl;
        }
    }

    delete[] bins;
}

/*
* main: Entry point of the program. 
*       Handles input arguments, reads data from the file,
* computes statistics and histogram, and prints the results.
* parameters:
*   - int argc: number of command-line arguments
*   - char* argv[]: array of command-line arguments
* return value (int): 0 if the program exits normally, 1 otherwise
*/
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "need the file name as input!\n";
        return 0; // exit normally
    }

    string filename = argv[1];
    int bin_width = (argc >= 3) ? atoi(argv[2]) : 1;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << '\n';
        return 1;
    }

    int capacity = 1000;
    double* data = new double[capacity];
    int size = 0;

    char line[256];
    while (infile.getline(line, 256)) {
        if (size >= capacity) {
            capacity *= 2;
            double* new_data = new double[capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        string lineStr(line);
        if (lineStr == "nan") {
            data[size++] = NAN;
        } else {
            data[size++] = atof(line);
        }
    }
    infile.close();

    if (size == 0) {
        cerr << "No valid data found in file.\n";
        delete[] data;
        return 1;
    }

    double mean = 0.0, std_dev = 0.0;
    calculate_statistics(data, size, mean, std_dev);

    cout << "avg: " << fixed << setprecision(2) << mean << '\n';
    cout << "std: " << fixed << setprecision(2) << std_dev << '\n';

    compute_histogram(data, size, bin_width);

    delete[] data;
    return 0;
}

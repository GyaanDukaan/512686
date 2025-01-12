#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include <iterator>
#include <algorithm>

// Using std::vector for 2D matrix
typedef std::vector<std::vector<int>> Vector2D;

// Using std::array for 2D matrix
typedef std::array<std::array<int, 1000>, 1000> Array2D;


// Function to sum the matrix using iterators
template <typename T>
int sumMatrixIterators(const T& matrix) {
    auto start = std::chrono::high_resolution_clock::now();
    int sum = 0;

    // Use iterators to traverse the matrix
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            sum += element;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> elapsed_time = end - start;
    double time_taken_ns = elapsed_time.count();
    std::cout << "Time taken with Iterators: " << time_taken_ns << " ns\n";

    return sum;
}

// Function to sum the matrix using traditional loops
template <typename T>
int sumMatrixLoops(const T& matrix)
{
    auto start = std::chrono::high_resolution_clock::now();
    int sum = 0;
    
    // Using traditional loop to traverse the matrix
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> elapsed_time = end - start;
    double time_taken_ns = elapsed_time.count();
    std::cout << "Time taken with Loops: " << time_taken_ns << " ns\n";
    return sum;
}

int main() {
    // Create 2D matrices using vector and array
    Vector2D vectorMatrix(1000, std::vector<int>(1000, 1));
    Array2D arrayMatrix(std::array<int, 1000>(std::fill_n(std::array<int, 1000>().data(), 1000, 1)));

    std::cout << "**Summing Matrix using Vector2D:**\n";
    int vectorSumIterators = sumMatrixIterators(vectorMatrix);
    int vectorSumLoops = sumMatrixLoops(vectorMatrix);
    std::cout << "Sum using Iterators: " << vectorSumIterators << "\n";
    std::cout << "Sum using Loops: " << vectorSumLoops << "\n";
    
    std::cout << "\n**Summing Matrix using Array2D:**\n";
    int arraySumIterators = sumMatrixIterators(arrayMatrix);
    int arraySumLoops = sumMatrixLoops(arrayMatrix);
    std::cout << "Sum using Iterators: " << arraySumIterators << "\n";
    std::cout << "Sum using Loops: " << arraySumLoops << "\n";

    return 0;
}

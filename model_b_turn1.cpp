

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <chrono>
#include <algorithm>

constexpr int MATRIX_SIZE = 10000;

template<typename Container>
double sumMatrixUsingIterators(const Container& matrix) {
    double sum = 0.0;
    
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            sum += element;
        }
    }
    return sum;
}
template<typename Container>
double sumMatrixUsingLoops(const Container& matrix) {
    double sum = 0.0;
    
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

template<typename Container>
void createMatrix(Container& matrix)
{
    for (size_t i = 0; i < MATRIX_SIZE; ++i) {
        matrix.emplace_back(MATRIX_SIZE);
        for (size_t j = 0; j < MATRIX_SIZE; ++j) {
            matrix[i][j] = static_cast<double>(i * MATRIX_SIZE + j) + 1.0;
        }
    }
}

int main() {
    // Temporary storage for matrix
    std::vector<std::vector<double>> matrix_vector;
    std::list<std::list<double>> matrix_list;
    std::array<std::array<double, MATRIX_SIZE>, MATRIX_SIZE> matrix_array;
    
 
    // Create matrices
    createMatrix(matrix_vector);
    createMatrix(matrix_list);
    /* Note: For std::array, 2D array is created directly*/

    
    {  // Vector with iterators
        std::cout << "\nVector with iterators:" << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        double sumIter = sumMatrixUsingIterators(matrix_vector);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time taken using iterators: " << duration.count() << " microseconds" << std::endl;
        std::cout << "Sum: " << sumIter << std::endl;
    }
 
    { // Vector with loops
        std::cout << "\nVector with loops:" << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        double sumLoop = sumMatrixUsingLoops(matrix_vector);
        auto end = std::chrono::high_resolution_clock::now();        
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time taken using loops: " << duration.count() << " microseconds" << std::endl;  
        std::cout << "Sum: " << sumLoop << std::endl;
    }
 
    { // List with iterators
        std::cout << "\nList with iterators:" << std::endl; 
        auto start = std::chrono::high_resolution_clock::now();        
        double sumIter = sumMatrixUsingIterators(matrix_list);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time taken using iterators: " << duration.count() << " microseconds" << std::endl;
        std::cout << "Sum: " << sumIter << std::endl;

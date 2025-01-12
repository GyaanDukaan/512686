#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <chrono>

constexpr std::size_t SIZE = 10000;

void testVector() {
    // Create a 2D matrix using vector
    std::vector<std::vector<int>> matrix(SIZE, std::vector<int>(SIZE));
    
    // Fill the matrix with values
    for (std::size_t i = 0; i < SIZE; ++i) {
        for (std::size_t j = 0; j < SIZE; ++j) {
            matrix[i][j] = i * SIZE + j;
        }
    }

    // Measure performance of traversal using iterators
    auto start = std::chrono::high_resolution_clock::now();
    
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            volatile int tmp = elem; // Using volatile to avoid optimization
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Vector elapsed time: " << elapsed.count() << " seconds.\n";
}

void testList() {
    // Create a 2D matrix using list
    std::list<std::list<int>> matrix;
    for (std::size_t i = 0; i < SIZE; ++i) {
        std::list<int> row;
        for (std::size_t j = 0; j < SIZE; ++j) {
            row.push_back(i * SIZE + j);
        }
        matrix.push_back(row);
    }
    
    // Measure performance of traversal using iterators
    auto start = std::chrono::high_resolution_clock::now();
    
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            volatile int tmp = elem; // Using volatile to avoid optimization
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "List elapsed time: " << elapsed.count() << " seconds.\n";
}

void testArray() {
    // Create a 2D matrix using array
    std::array<std::array<int, SIZE>, SIZE> matrix;

    // Fill the matrix with values
    for (std::size_t i = 0; i < SIZE; ++i) {
        for (std::size_t j = 0; j < SIZE; ++j) {
            matrix[i][j] = i * SIZE + j;
        }
    }

    // Measure performance of traversal using iterators
    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            volatile int tmp = elem; // Using volatile to avoid optimization
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Array elapsed time: " << elapsed.count() << " seconds.\n";
}

int main() {
    std::cout << "Testing performance of 2D matrix techniques:\n";
    
    testVector(); // Test with std::vector
    testList();   // Test with std::list
    testArray();  // Test with std::array

    return 0;
}

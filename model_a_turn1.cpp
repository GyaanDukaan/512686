#include <iostream>
#include <vector>
#include <array>
#include <chrono>

const int SIZE = 1000;

void initialize_matrix(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            matrix[i][j] = i + j; // or any arbitrary value
}

void initialize_matrix(std::array<std::array<int, SIZE>, SIZE>& matrix) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            matrix[i][j] = i + j; // or any arbitrary value
}

long long sum_with_loops(const std::vector<std::vector<int>>& matrix) {
    long long sum = 0;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            sum += matrix[i][j];
    return sum;
}

long long sum_with_iterators(const std::vector<std::vector<int>>& matrix) {
    long long sum = 0;
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        for (auto jt = it->begin(); jt != it->end(); ++jt) {
            sum += *jt;
        }
    }
    return sum;
}

long long sum_with_loops_array(const std::array<std::array<int, SIZE>, SIZE>& matrix) {
    long long sum = 0;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            sum += matrix[i][j];
    return sum;
}

long long sum_with_iterators_array(const std::array<std::array<int, SIZE>, SIZE>& matrix) {
    long long sum = 0;
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        for (auto jt = it->begin(); jt != it->end(); ++jt) {
            sum += *jt;
        }
    }
    return sum;
}

int main() {
    // Using std::vector
    std::vector<std::vector<int>> vector_matrix(SIZE, std::vector<int>(SIZE));
    initialize_matrix(vector_matrix);

    auto start = std::chrono::high_resolution_clock::now();
    long long sum_loops_vector = sum_with_loops(vector_matrix);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_loops_vector = end - start;

    start = std::chrono::high_resolution_clock::now();
    long long sum_iterators_vector = sum_with_iterators(vector_matrix);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_iterators_vector = end - start;

    std::cout << "Vector Matrix Sum using loops: " << sum_loops_vector << " (Time: " << duration_loops_vector.count() << " seconds)\n";
    std::cout << "Vector Matrix Sum using iterators: " << sum_iterators_vector << " (Time: " << duration_iterators_vector.count() << " seconds)\n";

    // Using std::array
    std::array<std::array<int, SIZE>, SIZE> array_matrix;
    initialize_matrix(array_matrix);

    start = std::chrono::high_resolution_clock::now();
    long long sum_loops_array = sum_with_loops_array(array_matrix);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_loops_array = end - start;

    start = std::chrono::high_resolution_clock::now();
    long long sum_iterators_array = sum_with_iterators_array(array_matrix);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_iterators_array = end - start;

    std::cout << "Array Matrix Sum using loops: " << sum_loops_array << " (Time: " << duration_loops_array.count() << " seconds)\n";
    std::cout << "Array Matrix Sum using iterators: " << sum_iterators_array << " (Time: " << duration_iterators_array.count() << " seconds)\n";

    return 0;
}

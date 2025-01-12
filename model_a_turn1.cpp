#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <chrono>

const int SIZE = 10000;

// Function to sum using traditional for loops
template<typename T>
long long sumTraditional(const T& matrix) {
    long long sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Function to sum using iterators
template<typename T>
long long sumIterators(const T& matrix) {
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
    std::vector<std::vector<int>> matrixVector(SIZE, std::vector<int>(SIZE, 1)); // Initialize to 1

    auto start = std::chrono::high_resolution_clock::now();
    long long sumVectorTraditional = sumTraditional(matrixVector);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationVectorTraditional = end - start;

    start = std::chrono::high_resolution_clock::now();
    long long sumVectorIterators = sumIterators(matrixVector);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationVectorIterators = end - start;

    std::cout << "Vector traditional sum: " << sumVectorTraditional << ", Duration: " << durationVectorTraditional.count() << " seconds\n";
    std::cout << "Vector iterator sum: " << sumVectorIterators << ", Duration: " << durationVectorIterators.count() << " seconds\n";

    // Using std::list
    std::list<std::list<int>> matrixList(SIZE, std::list<int>(SIZE, 1)); // Initialize to 1

    start = std::chrono::high_resolution_clock::now();
    long long sumListTraditional = sumTraditional(matrixList);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationListTraditional = end - start;

    start = std::chrono::high_resolution_clock::now();
    long long sumListIterators = sumIterators(matrixList);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationListIterators = end - start;

    std::cout << "List traditional sum: " << sumListTraditional << ", Duration: " << durationListTraditional.count() << " seconds\n";
    std::cout << "List iterator sum: " << sumListIterators << ", Duration: " << durationListIterators.count() << " seconds\n";

    // Using std::array
    std::array<std::array<int, SIZE>, SIZE> matrixArray; // Needs to be initialized
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrixArray[i][j] = 1; // Initialize to 1
        }
    }

    start = std::chrono::high_resolution_clock::now();
    long long sumArrayTraditional = sumTraditional(matrixArray);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationArrayTraditional = end - start;

    start = std::chrono::high_resolution_clock::now();
    long long sumArrayIterators = sumIterators(matrixArray);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationArrayIterators = end - start;

    std::cout << "Array traditional sum: " << sumArrayTraditional << ", Duration: " << durationArrayTraditional.count() << " seconds\n";
    std::cout << "Array iterator sum: " << sumArrayIterators << ", Duration: " << durationArrayIterators.count() << " seconds\n";

    return 0;
}

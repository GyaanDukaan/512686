#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <chrono>
#include <random>
#include <cstdlib>

// Function to generate a random double
double random_double()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

// templated function to create 2D matrix and measure time using iterators
template <typename Container>
void create_matrix_and_time(const size_t rows, const size_t cols)
{
    using Row = Container;
    using Matrix = std::vector<Row>;
    Matrix matrix(rows);
    for (size_t i = 0; i < rows; ++i) {
        matrix[i].reserve(cols);
    }

    {
        // Measure time to fill the matrix
        auto start = std::chrono::high_resolution_clock::now();
        for (auto& row : matrix) {
            for (auto& element : row) {
                element = random_double();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time to fill the matrix with " << Container::name() << ": " << duration.count() << " microseconds" << std::endl;
    }
    {
        // Measure time to traverse the matrix with iterators
        auto start = std::chrono::high_resolution_clock::now();
        int sum = 0;
        for (const auto& row : matrix) {
            for (const auto& element : row) {
                sum += static_cast<int>(element * 1000);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "Time to traverse the matrix with iterators and " << Container::name() << ": " << duration.count() << " microseconds" << std::endl;
        std::cout << "Sum of elements: " << sum << std::endl;
    }
}
 
 // Base class to provide a name() method for each container
 class ContainerBase {
  public:
    virtual std::string name() const = 0;
    virtual ~ContainerBase() = default;
 };
 
 // Specialization for std::vector
 template<typename T>
 class VectorContainer : public ContainerBase {
  public:
     std::string name() const override {
         return "std::vector";
     }
 };

// Specialization for std::list
template<typename T>
class ListContainer : public ContainerBase
{
public:
    std::string name() const override {
        return "std::list";
    }
};

// Specialization for std::array
template <typename T, size_t S>
class ArrayContainer : public ContainerBase
{
public:
    std::string name() const override {
        return "std::array";
    }
};


int main() {
    const size_t rows = 10000;
    const size_t cols = 10000;

    {
        std::vector<std::vector<double>> vec_matrix(rows);
        for (size_t i = 0; i < rows; ++i) {
            vec_matrix[i].resize(cols);
        }
        
        auto start = std::chrono::high_resolution_clock::now();
        // --- Dummy Fill to simulate memory access -----
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                vec_matrix[i][j] = random_double();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Time to fill the 2D std::vector: " << duration.count() << " microseconds" << std::endl;
    }

    create_matrix_and_time<VectorContainer<double>>(rows, cols);
    create_matrix_and_time<ListContainer<double>>(rows, cols);

    //std::array cannot be used for 2D since it requires a fixed size at compile-time
    //create_matrix_and_time<ArrayContainer<double, cols>>(rows, cols);

    return 0;
}

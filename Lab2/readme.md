# 1-Magic Square Generation Benchmarking and Plotting

This C++ code benchmarks the generation of magic squares and plots the average time taken for different orders.

## Description

The code performs the following tasks:

1. **Magic Square Generation**: It generates magic squares of different orders using an algorithmic approach.
2. **Benchmarking**: It measures the average time taken for generating magic squares of each order over multiple iterations.
3. **Data Logging**: It writes the order of the magic square and corresponding average time to a file named `data.txt`.
4. **Plotting**: It plots the data stored in `data.txt` using Gnuplot.

## Time Complexity

The time complexity of generating a magic square of order n using the algorithm employed in this code is O(n^2). This arises because the algorithm involves iterating over each cell of the square exactly once to fill it with the appropriate value. As the order of the magic square increases, the number of cells (n^2) increases quadratically, leading to a quadratic time complexity.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/1a36cb46-39d0-4634-b316-4231b06614ea)


## Functions

### `void WriteDataToFile(int i, double avgTime)`

This function writes the order of the magic square `i` and the corresponding average time `avgTime` to a file named `data.txt`.

### `void generateMagicSquare(int n)`

This function generates a magic square of order `n` using an algorithmic approach.

### `int main()`

The main function executes the benchmarking process. It generates magic squares of different orders and records the average time taken for each order.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the order of the magic square and corresponding average generation times.
4. Plot the data using Gnuplot by opening the `data.txt` file.

# 2-Merge Operation Benchmarking

This C++ code benchmarks the merge operation of two arrays and plots the average time taken for different array sizes.

## Description

The code performs the following tasks:

1. **Array Generation**: It generates two integer arrays of varying sizes.
2. **Merge Operation**: It performs the merge operation on the two arrays.
3. **Benchmarking**: It measures the average time taken for the merge operation for each array size over multiple iterations.
4. **Data Logging**: It writes the average time taken for each array size to a file named `data6.txt`.

## Time Complexity

The time complexity of the merge operation algorithm used in this code is O(n + m), where n and m are the sizes of the two arrays being merged. This is because the algorithm iterates through each element of both arrays once and compares them to merge them into a single sorted array. As the size of the arrays increases linearly, the time taken for the merge operation also increases linearly.


## Functions

### `void Generate(int a[], int b[], int i, int k)`

This function generates two integer arrays `a` and `b` of sizes `i` and `k` respectively.

### `void merge(int a[], int b[], int n, int m)`

This function performs the merge operation on two arrays `a` and `b` of sizes `n` and `m` respectively.

### `int main()`

The main function executes the benchmarking process. It generates arrays of varying sizes, performs the merge operation, records the average time taken for each array size, and writes the data to `data6.txt`.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the array sizes and corresponding average merge operation times.
4. Plot the data using Gnuplot by opening the `data6.txt` file.

# 3-Positioning Benchmarking

This C++ code benchmarks the positioning of elements in an array and plots the average time taken for different array sizes.

## Description

The code performs the following tasks:

1. **Array Generation**: It generates an integer array of varying sizes.
2. **Positioning Operation**: It positions the elements in the array based on a pivot element.
3. **Benchmarking**: It measures the average time taken for positioning the elements in the array for each array size over multiple iterations.
4. **Data Logging**: It writes the array size and corresponding average time taken to a file named `data4.txt`.

## Time Complexity

The time complexity of the positioning algorithm used in this code is O(n), where n is the size of the array. This is because the algorithm iterates through each element of the array once to position them based on the pivot element. As the size of the array increases linearly, the time taken for the positioning operation also increases linearly.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/74f248fe-f524-4071-8643-b2c078fdc9bb)

## Functions

### `void random_generator(int a[], int n)`

This function generates random integer values and assigns them to the elements of the array `a` of size `n`.

### `void position(int a[], int n)`

This function positions the elements in the array `a` based on a pivot element. It moves elements smaller than the pivot to the left and elements larger than the pivot to the right.

### `int main()`

The main function executes the benchmarking process. It generates arrays of varying sizes, positions the elements in the array, records the average time taken for each array size, and writes the data to `data4.txt`.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the array sizes and corresponding average positioning operation times.
4. Plot the data using Gnuplot by opening the `data4.txt` file.

# 4-Power Function Benchmarking

This C++ code benchmarks the power function and plots the average time taken for different exponents.

## Description

The code performs the following tasks:

1. **Power Calculation**: It calculates the power of a number using recursion and measures the time taken for the calculation.
2. **Benchmarking**: It measures the average time taken for calculating the power for each exponent over multiple iterations.
3. **Data Logging**: It writes the exponent and corresponding average time taken to a file named `data5.txt`.

## Time Complexity

The time complexity of the power calculation algorithm used in this code is O(log n), where n is the exponent. This is because the algorithm employs a recursive approach that divides the exponent by 2 in each recursive call. As a result, the number of recursive calls is proportional to the logarithm of the exponent. Therefore, the time taken to calculate the power increases logarithmically with the size of the exponent.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/74ece4af-1952-4e0f-9638-2cbf4199d396)


## Functions

### `int power(int x, int n)`

This function calculates the power of a number `x` raised to the exponent `n` using recursion.

### `int main()`

The main function executes the benchmarking process. It calculates the power of a fixed number (10000) for different exponents, records the average time taken for each exponent, and writes the data to `data5.txt`.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the exponents and corresponding average power calculation times.
4. Plot the data using Gnuplot by opening the `data5.txt` file.


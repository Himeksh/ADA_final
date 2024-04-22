# 1-Horner's Rule Benchmarking and Plotting

This C++ code benchmarks the Horner's rule for polynomial evaluation and plots the average time taken for different array sizes.

## Description

The code performs the following tasks:

1. **Data Generation**: It generates random integer arrays of increasing sizes.
2. **Horner's Rule Evaluation**: It applies Horner's rule for polynomial evaluation on the generated arrays.
3. **Benchmarking**: It measures the average time taken for each array size over multiple iterations.
4. **Data Logging**: It writes the array size and corresponding average time to a file named `data4.txt`.
5. **Plotting**: It plots the data stored in `data4.txt` using Gnuplot.

## Time Complexity
The time complexity of evaluating a polynomial of degree n using Horner's Rule is O(n). This is because it involves n additions and 
n multiplications, making it a linear time algorithm in terms of the degree of the polynomial.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/432bc6f4-85a1-4f27-a89f-8d6c45fa7532)

## Functions

### `void WriteDataToFile(long int i, double avgtime)`

This function writes the array size `i` and the corresponding average time `avgtime` to a file named `data4.txt`.

### `void PlotChart()`

This function utilizes Gnuplot to plot the data stored in `data4.txt`, representing the relationship between array size and average time.

### `void Generate(int a[], int i)`

This function generates random integer arrays of size `i`.

### `int HornerRule(int arr[], int n, int m, int x)`

This function implements Horner's rule for polynomial evaluation recursively.

### `void Algorithm()`

This is the main algorithm function that performs benchmarking by evaluating Horner's rule for polynomial evaluation on arrays of increasing sizes.

### `int main()`

The main function calls the `Algorithm()` function to execute the benchmarking process.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for array sizes and corresponding average times.
4. Plot the data using Gnuplot by opening the `data4.txt` file.

# 2- Selection Sort Benchmarking and Plotting

This C++ code benchmarks the selection sort algorithm and plots the average time taken for sorting arrays of different sizes.

## Description

The code performs the following tasks:

1. **Data Generation**: It generates random integer arrays of increasing sizes.
2. **Selection Sort**: It applies the selection sort algorithm to sort the generated arrays.
3. **Benchmarking**: It measures the average time taken for sorting each array size over multiple iterations.
4. **Data Logging**: It writes the array size and corresponding average time to a file named `data.txt`.
5. **Plotting**: It plots the data stored in `data.txt` using Gnuplot.

## Time Complexity

Selection sort has a time complexity of O(n^2), where n is the number of elements in the array. This arises from the nested loops used in the algorithm:

- Outer Loop: n iterations
- Inner Loop: n - i iterations, where i is the current index of the outer loop.

Since there are nested loops, the time complexity is proportional to the square of the number of elements in the array. This makes selection sort inefficient for large datasets compared to more efficient sorting algorithms like quicksort or mergesort. However, selection sort is easy to implement and performs well on small datasets or nearly sorted arrays.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/2b131232-9f22-44d7-be51-808d1f32ca07)


## Functions

### `void WriteDataToFile(int i, double avgtime)`

This function writes the array size `i` and the corresponding average time `avgtime` to a file named `data.txt`.

### `void PlotChart()`

This function utilizes Gnuplot to plot the data stored in `data.txt`, representing the relationship between array size and average time.

### `void Generate(int a[], int i)`

This function generates random integer arrays of size `i`.

### `void selection_sort(int a[], int n)`

This function implements the selection sort algorithm to sort integer arrays of size `n`.

### `void Algorithm()`

This is the main algorithm function that performs benchmarking by sorting arrays of increasing sizes using selection sort and recording the average time taken.

### `int main()`

The main function calls the `Algorithm()` function to execute the benchmarking process.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for array sizes and corresponding average sorting times.
4. Plot the data using Gnuplot by opening

# 3-Array Summation Benchmarking and Plotting

This C++ code benchmarks the summation of array elements and plots the average time taken for different array sizes.

## Description

The code performs the following tasks:

1. **Data Generation**: It generates random integer arrays of increasing sizes.
2. **Array Summation**: It calculates the sum of all elements in the generated arrays.
3. **Benchmarking**: It measures the average time taken for summation for each array size over multiple iterations.
4. **Data Logging**: It writes the array size and corresponding average time to a file named `data1.txt`.
5. **Plotting**: It plots the data stored in `data1.txt` using Gnuplot.

## Time Complexity

The time complexity of the algorithm for calculating the sum of array elements is O(n), where n is the size of the array. This is because the algorithm iterates through each element of the array once to calculate the sum. As the size of the array increases linearly, the time taken to compute the sum also increases linearly.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/21a2422e-7926-4411-bb3f-f67ca7d49955)


## Functions

### `void WriteDataToFile(long int i, double avgtime)`

This function writes the array size `i` and the corresponding average time `avgtime` to a file named `data1.txt`.

### `void PlotChart()`

This function utilizes Gnuplot to plot the data stored in `data1.txt`, representing the relationship between array size and average time.

### `void Generate(int a[], int i)`

This function generates random integer arrays of size `i`.

### `void Sum(int arr[], int size)`

This function calculates the sum of all elements in the array `arr` of size `size`.

### `void Algorithm()`

This is the main algorithm function that performs benchmarking by summing arrays of increasing sizes and recording the average time taken.

### `int main()`

The main function calls the `Algorithm()` function to execute the benchmarking process.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for array sizes and corresponding average summation times.
4. Plot the data using Gnuplot by opening the `data1.txt` file.

# 4-Combination of Truth False Generation Benchmarking and Plotting

This C++ code benchmarks the generation of strings containing combinations of 'T' and 'F' and plots the average time taken for different string lengths.

## Description

The code performs the following tasks:

1. **String Generation**: It generates strings containing combinations of 'T' and 'F' of increasing lengths using a recursive approach.
2. **Benchmarking**: It measures the average time taken for generating strings of each length over multiple iterations.
3. **Data Logging**: It writes the string length and corresponding average time to a file named `data6.txt`.
4. **Plotting**: It plots the data stored in `data6.txt` using Gnuplot.

## Time Complexity

The time complexity of the algorithm for generating strings containing combinations of 'T' and 'F' is O(2^n), where n is the length of the string. This is because the algorithm generates all possible combinations of 'T' and 'F' for each length recursively. As the length of the string increases, the number of possible combinations grows exponentially. Therefore, the time taken to generate strings also increases exponentially with the length of the string.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/6e35e7c9-e2ba-4b0b-8ac8-c72310884fc8)

## Functions

### `void WriteDataToFile(int i, double avgtime)`

This function writes the string length `i` and the corresponding average time `avgtime` to a file named `data6.txt`.

### `void PlotChart()`

This function utilizes Gnuplot to plot the data stored in `data6.txt`, representing the relationship between string length and average time.

### `void tt(int n, string s)`

This function recursively generates strings containing combinations of 'T' and 'F' of length `n`.

### `void Algorithm()`

This is the main algorithm function that performs benchmarking by generating strings of increasing lengths and recording the average time taken.

### `int main()`

The main function calls the `Algorithm()` function to execute the benchmarking process.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for string lengths and corresponding average generation times.
4. Plot the data using Gnuplot by opening the `data6.txt` file.

# 5-Tower of Hanoi Benchmarking and Plotting

This C++ code benchmarks the Tower of Hanoi problem solution and plots the average time taken for different numbers of disks.

## Description

The code performs the following tasks:

1. **Tower of Hanoi Solution**: It recursively solves the Tower of Hanoi problem for different numbers of disks.
2. **Benchmarking**: It measures the average time taken for solving the Tower of Hanoi problem for each number of disks over multiple iterations.
3. **Data Logging**: It writes the number of disks and corresponding average time to a file named `data3.txt`.
4. **Plotting**: It plots the data stored in `data3.txt` using Gnuplot.

## Time Complexity

The time complexity of the Tower of Hanoi algorithm is O(2^n), where n is the number of disks. This exponential time complexity arises because, with each additional disk, the number of moves required to solve the problem doubles. As a result, the time taken to solve the Tower of Hanoi problem increases exponentially with the number of disks.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/81d3aa2b-5a13-413d-8c25-731c493e73f3)


## Functions

### `void WriteDataToFile(int i, double avgtime)`

This function writes the number of disks `i` and the corresponding average time `avgtime` to a file named `data3.txt`.

### `void PlotChart()`

This function utilizes Gnuplot to plot the data stored in `data3.txt`, representing the relationship between the number of disks and average time.

### `void toh(int n, char source, char helper, char destination)`

This function recursively solves the Tower of Hanoi problem for `n` disks, using the source (`source`), helper (`helper`), and destination (`destination`) pegs.

### `void Algorithm()`

This is the main algorithm function that performs benchmarking by solving the Tower of Hanoi problem for different numbers of disks and recording the average time taken.

### `int main()`

The main function calls the `Algorithm()` function to execute the benchmarking process.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the number of disks and corresponding average solution times.
4. Plot the data using Gnuplot by opening the `data3.txt` file.


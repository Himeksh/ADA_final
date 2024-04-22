# 1-Maximum and Minimum Calculation Benchmarking

This C++ code benchmarks the calculation of maximum and minimum elements in an array using both iterative and recursive approaches. It plots the average time taken for different array sizes.

## Description

The code performs the following tasks:

1. **Array Generation**: It generates an integer array of varying sizes with random values.
2. **Maximum and Minimum Calculation**: It calculates the maximum and minimum elements in the array using both iterative and recursive approaches.
3. **Benchmarking**: It measures the average time taken for calculating the maximum and minimum elements for each array size over multiple iterations.
4. **Data Logging**: It writes the array size, average time taken for iterative calculation, and average time taken for recursive calculation to a file named `data.txt`.

## Time Complexity

The time complexity of the recursive maximum and minimum calculation algorithm used in this code is O(n), where n is the size of the array. This is because the algorithm recursively divides the array into halves until it reaches base cases, and each recursive call processes a constant number of elements. Therefore, the time complexity is linear with respect to the size of the array.

The time complexity of the iterative maximum and minimum calculation algorithm used in this code is also O(n^2), where n is the size of the array. This is because the algorithm iterates through each element of the array and compares it with every other element to find the maximum and minimum. As the size of the array increases, the number of comparisons increases quadratically.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/471bba27-6b53-4b6f-bd5d-e7f24bec5e0a)

## Functions

### `void WriteDataToFile(int i, double avgtime_iter, double avgtime_rec)`

This function writes the array size, average time taken for iterative calculation, and average time taken for recursive calculation to the file `data.txt`.

### `void MaxMinIterative(int *a, int low, int high)`

This function calculates the maximum and minimum elements in the array `a` using an iterative approach within the specified range `[low, high]`.

### `void MaxMin(int* a, int low, int high)`

This function calculates the maximum and minimum elements in the array `a` using a recursive approach within the specified range `[low, high]`.

### `int main()`

The main function executes the benchmarking process. It generates arrays of varying sizes, calculates the maximum and minimum elements using both iterative and recursive approaches, records the average time taken for each approach, and writes the data to `data.txt`.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the array sizes and corresponding average calculation times.
4. Plot the data using Gnuplot by opening the `data.txt` file.

# 2-Merge Sort Benchmarking

This C++ code benchmarks the merge sort algorithm and plots the average time taken for sorting arrays of different sizes.

## Description

The code performs the following tasks:

1. **Array Generation**: It generates an integer array of varying sizes with random values.
2. **Merge Sort Algorithm**: It implements the merge sort algorithm to sort the generated arrays.
3. **Benchmarking**: It measures the average time taken for sorting each array size over multiple iterations.
4. **Data Logging**: It writes the array size and corresponding average sorting time to a file named `data.txt`.
5. **Plotting**: It plots the data using Gnuplot to visualize the time complexity.

## Time Complexity

The time complexity of the merge sort algorithm used in this code is O(n log n), where n is the size of the array. This is because merge sort recursively divides the array into halves and then merges them back together, and the merge operation takes linear time. Therefore, the overall time complexity is dominated by the merge operation, resulting in O(n log n) time complexity.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/9348f081-031c-432a-ac1e-207bca1404b4)

## Functions

### `void WriteDataToFile(int i, double avgtime)`

This function writes the array size and corresponding average sorting time to the file `data.txt`.

### `void PlotChart()`

This function plots the data stored in `data.txt` using Gnuplot.

### `void Generate(int a[], int i)`

This function generates an integer array of size `i` with random values.

### `void merge(int *arr, int left, int mid, int right)`

This function merges two subarrays of `arr[]` into a single sorted array.

### `void mergeSort(int *arr, int left, int right)`

This function recursively sorts the array `arr[]` using the merge sort algorithm.

### `void Algorithm()`

This function executes the benchmarking process. It generates arrays of varying sizes, sorts them using merge sort, records the average sorting time for each array size, and writes the data to `data.txt`.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the array sizes and corresponding average sorting times.
4. Plot the data using Gnuplot by opening the `data.txt` file.

# 3-Quick Sort Benchmarking

This C++ code benchmarks the Quick Sort algorithm and plots the average time taken for sorting arrays of different sizes.

## Description

The code performs the following tasks:

1. **Array Generation**: It generates an integer array of varying sizes with random values.
2. **Quick Sort Algorithm**: It implements the Quick Sort algorithm to sort the generated arrays.
3. **Benchmarking**: It measures the average time taken for sorting each array size over multiple iterations.
4. **Data Logging**: It writes the array size and corresponding average sorting time to a file named `data.txt`.
5. **Plotting**: It plots the data using Gnuplot to visualize the time complexity.

## Time Complexity

The time complexity of the Quick Sort algorithm used in this code is O(n log n) on average and O(n^2) in the worst case, where n is the size of the array. Quick Sort generally exhibits efficient performance due to its average-case time complexity being O(n log n). However, it can degrade to O(n^2) if the chosen pivot element is consistently one of the smallest or largest elements in the array.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/285f45d1-176a-4d47-b6b2-495e31dccb9f)

## Functions

### `void WriteDataToFile(int i, double avgtime)`

This function writes the array size and corresponding average sorting time to the file `data.txt`.

### `void PlotChart()`

This function plots the data stored in `data.txt` using Gnuplot.

### `void Generate(int a[], int i)`

This function generates an integer array of size `i` with random values.

### `int partion(int arr[],int s,int e)`

This function partitions the array around a pivot element and returns the index of the pivot element.

### `void quick_srt(int arr[],int s,int e)`

This function recursively sorts the array `arr[]` using the Quick Sort algorithm.

### `void Algorithm()`

This function executes the benchmarking process. It generates arrays of varying sizes, sorts them using Quick Sort, records the average sorting time for each array size, and writes the data to `data.txt`.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the array sizes and corresponding average sorting times.
4. Plot the data using Gnuplot by opening the `data.txt` file.

# 1-Activity Selection Algorithm Benchmarking

This C++ code benchmarks the Activity Selection algorithm for sorting activities based on start time, finish time, and duration.

## Description

The code performs the following tasks:

1. **Activity Selection**: It sorts activities based on start time, finish time, and duration using the Activity Selection algorithm.
2. **Benchmarking**: It measures the average time taken to sort activities for each sorting criteria (start time, finish time, and duration) over multiple iterations.
3. **Data Logging**: It writes the array size and corresponding average sorting time for each sorting criteria to a file named `data.txt`.

## Time Complexity

The time complexity of the Activity Selection algorithm is O(n log n), where n is the number of activities. The sorting operations (sorting by start time, finish time, and duration) contribute to the overall time complexity of the algorithm.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/8c808532-1e50-4930-9693-e3c4fa96a61b)

## Functions

### `void WriteDataToFile(int i, double avgtime_profit, double avgtime_weight, double avgtime_profitbyweight)`

This function writes the array size and corresponding average sorting times for start time, finish time, and duration to the file `data.txt`.

### `void sort_by_start(int *start, int *finish, int n)`

This function sorts activities based on start time.

### `void sort_by_end(int *start, int *finish, int n)`

This function sorts activities based on finish time.

### `void sort_by_duration(int *start, int *finish, int n)`

This function sorts activities based on duration (finish time - start time).

### `int *Activity_Selector(int *start, int *finish, int n)`

This function implements the Activity Selection algorithm to select a maximum set of mutually compatible activities.

### `void Algorithm()`

This function executes the benchmarking process. It generates random start and finish times for activities, sorts them based on start time, finish time, and duration, records the average sorting time for each criteria, and writes the data to `data.txt`.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the array sizes and corresponding average sorting times for start time, finish time, and duration.
4. View the data and analyze the results in `data.txt`.

# 2-Binary Search Algorithm Benchmarking

This C++ code benchmarks the binary search algorithm implemented recursively.

## Description

The code performs the following tasks:

1. **Binary Search**: It performs binary search recursively on a sorted array to find a randomly generated key.
2. **Benchmarking**: It measures the average time taken to perform binary search on arrays of increasing sizes over multiple iterations.
3. **Data Logging**: It writes the array size and corresponding average search time to a file named `binary_rec_data.txt`.
4. **Plotting**: It plots the data using Gnuplot to visualize the trend of search time with increasing array size.

## Time Complexity

The time complexity of the binary search algorithm implemented recursively is O(log n), where n is the size of the array. Sorting the array initially using `std::sort` contributes O(n log n) to the overall time complexity.

![image](https://github.com/HarshitUIET/ADA/assets/140891146/a1c11343-a166-4fb4-83e9-ad21ab7ce0eb)

## Functions

### `void WriteDataToFile(int i, double avgtime)`

This function writes the array size and corresponding average search time to the file `binary_rec_data.txt`.

### `void PlotChart()`

This function plots the data using Gnuplot to visualize the trend of search time with increasing array size.

### `void Generate(int a[], int i)`

This function generates random integers and populates an array of size `i` with them.

### `int Binary_recursive(int arr[], int key, int l, int h)`

This function implements binary search recursively to find the index of the key in the array within the given range `[l, h]`.

### `void Algorithm()`

This function executes the benchmarking process. It generates arrays of increasing sizes, sorts them, performs binary search on them, records the average search time, and writes the data to `binary_rec_data.txt`. It also plots the data using Gnuplot.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the array sizes and corresponding average search times.
4. View the data and analyze the results in `binary_rec_data.txt`.
5. Use Gnuplot to plot the data and visualize the trend.

# 3-Knapsack Problem Algorithm Benchmarking

This C++ code benchmarks the knapsack problem algorithm for various sorting criteria.

## Description

The code performs the following tasks:

1. **Knapsack Algorithm**: It implements the knapsack problem algorithm to find the maximum profit that can be achieved given a set of items with their weights and profits, and a maximum weight capacity.
2. **Sorting Criteria**: It sorts the items based on different criteria such as profit, weight, and profit-to-weight ratio before applying the knapsack algorithm.
3. **Benchmarking**: It measures the average time taken to solve the knapsack problem for different array sizes and sorting criteria over multiple iterations.
4. **Data Logging**: It writes the array size and corresponding average times for each sorting criterion to a file named `knapsack.txt`.

## Time Complexity

The time complexity of the knapsack algorithm depends on the sorting criteria used:
- Sorting by profit: O(n^2)
- Sorting by weight: O(n^2)
- Sorting by profit-to-weight ratio: O(n^2)

![image](https://github.com/HarshitUIET/ADA/assets/140891146/f01d674a-f758-4d3d-868c-299aab587f0c)

## Functions

### `void WriteDataToFile(int i, double avgtime_profit, double avgtime_weight, double avgtime_profitbyweight)`

This function writes the array size and corresponding average times for sorting by profit, weight, and profit-to-weight ratio to the file `knapsack.txt`.

### Sorting Functions
- `void sort_by_profit(int profit[], int weight[], int n)`: Sorts the items by profit.
- `void sort_by_weight(int profit[], int weight[], int n)`: Sorts the items by weight.
- `void sort_profitbyweight(int profit[], int weight[], int n)`: Sorts the items by profit-to-weight ratio.

### `void knapsack(int n, int Weight, int *profit, int *weight_item)`

Implements the knapsack algorithm to find the maximum profit given the number of items, maximum weight capacity, profits, and weights of items.

### `void Algorithm()`

Executes the benchmarking process. It generates arrays of items with random profits and weights, sorts them based on different criteria, applies the knapsack algorithm, records the average execution times, and writes the data to `knapsack.txt`.

The overall time complexity of the knapsack algorithm with sorting is O(n^2), where n is the number of items.

## Instructions

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Check the output in the console for the array sizes and corresponding average execution times.
4. View the data and analyze the results in `knapsack.txt`.

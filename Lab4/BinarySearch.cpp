#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include<algorithm>
using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("binary_rec_data.txt", ios::app);
    if (fout.is_open()) {
        fout<< i << " " << avgtime << endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void PlotChart() {
    FILE *gnuplotPipe = _popen("gnuplot -persist", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set yrange [0:*]\n"); // Set y-axis range from 0 to auto
        fprintf(gnuplotPipe, "plot 'data.txt' with linespoints title 'Average Time'\n");
        _pclose(gnuplotPipe);
    } else {
        cerr << "Gnuplot not found. Please install Gnuplot." << endl;
    }
}


void Generate(int a[], int i) {
    for (int j = 0; j <= i; j++) {
        a[j] = rand();
    }
}
int Binary_recursive(int arr[], int key, int l, int h) {
    if (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            return Binary_recursive(arr, key, l, mid - 1);
        } else {
            return Binary_recursive(arr, key, mid + 1, h);
        }
    }
    return -1; 
}

void Algorithm() {
    double time1, time2, avgtime;
    for (int i = 100000; i <= 1000000; i += 50000) {
        int a[i];
        Generate(a, i);
        std::sort(a,a+i-1);
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            Binary_recursive(a,rand(),0,i-1);
        }

        time2 = (double)clock();
        avgtime = (time2 - time1) / 10.0;
        cout << i << "-" << avgtime << endl;
        WriteDataToFile(i, avgtime);
    }
    PlotChart();
}

int main() {
    Algorithm();
    return 0;
}
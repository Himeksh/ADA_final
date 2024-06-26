#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
void WriteDataToFile(long int i, double avgtime) {
    ofstream fout("data1.txt", ios::app);
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
        fprintf(gnuplotPipe, "plot 'data1.txt' with linespoints title 'Average Time'\n");
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

void Sum(int arr[],int size){
    int s=0;
   for(int i=0;i<size;i++){
    s+=arr[i];
   }
}

void Algorithm() {
    double time1, time2;
    for (int i = 100; i <= 30000; i += 100) {
        int a[i];
        Generate(a, i);
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            Sum(a,i);
        }

        time2 = (double)clock();
         double avgtime = double(time2 - time1)*(1000.0)/double(CLOCKS_PER_SEC);
        cout << i << "-" << avgtime << endl;
        WriteDataToFile(i, avgtime);
    }
    PlotChart();
}

int main() {
    Algorithm();
  return 0;
}
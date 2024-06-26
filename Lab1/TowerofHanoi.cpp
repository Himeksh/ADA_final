#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;


void WriteDataToFile(int i, double avgtime) {
    ofstream fout("data3.txt", ios::app);
    if (fout.is_open()) {
        fout<< i << " " << avgtime<< endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void PlotChart() {
    FILE *gnuplotPipe = _popen("gnuplot -persist", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "plot 'data3.txt' with linespoints title 'Average Time'\n");
        _pclose(gnuplotPipe);
    } else {
        cerr << "Gnuplot not found. Please install Gnuplot." << endl;
    }
}


void toh(int n,char s,char h,char d) {
  if(n==0) return;
  toh(n-1,s,d,h);
  toh(n-1,h,s,d);
}


void Algorithm() {
    double time1, time2;
    for (int i = 3; i <= 30; i += 1) {
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            toh(i,'s','h','d');
        }

        time2 = (double)clock();
        double avgtime = double(time2 - time1)*(1000.0)/double(CLOCKS_PER_SEC);
        cout << i << "-" <<(avgtime/1000)<< endl;
        WriteDataToFile(i, avgtime);
    }
    PlotChart();
}

int main() {
    Algorithm();
   return 0;
}
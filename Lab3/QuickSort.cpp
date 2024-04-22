#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << " " << avgtime << endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void PlotChart() {
    FILE *gnuplotPipe = _popen("gnuplot -persist", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "plot 'data.txt' with linespoints title 'Average Time'\n");
        _pclose(gnuplotPipe);
    } else {
        cerr << "Gnuplot not found. Please install Gnuplot." << endl;
    }
}

void Generate(int a[], int i) {
    for (int j = 0; j < i; j++) {
        a[j] = rand();
    }
}

int partion(int arr[],int s,int e){
     int pivot=arr[s];

     int count=0;
     for(int i=s+1;i<=e;i++){         //take care of i=s+1 here
         if(arr[i]<=pivot){
          count++;
         }
         }
         int par=s+count; // take care to make s+count
     swap(arr[par],arr[s]);
     
     int i=s;
   int j=e;
     while (i<par && j>par)
     {
          while(arr[i]<arr[par]){
               i++;
          }
          while(arr[j]>arr[par]){
               j--;
          }
          if(i<par && j>par){
               swap(arr[i++],arr[j++]);
          }
     }
     return par;
     
}
void quick_srt(int arr[],int s,int e){
     if(s>=e){
          return;}
          
     
     int p=partion(arr,s,e);
 
     quick_srt(arr,s,p-1);
     
     quick_srt(arr,p+1,e);
     
}
void Algorithm() {
    double time1, time2, avgtime;
    for (int i = 500; i <= 4500; i = i+500) {
        int *a = new int[i];
        Generate(a, i);
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
           quick_srt(a, 0, i - 1);
        }
        time2 = (double)clock();
        avgtime = (time2 - time1) / 10.0;
        cout << i << "-" << avgtime << endl;
        WriteDataToFile(i, avgtime);
        delete[] a;
    }
    PlotChart();
}

int main() {
    Algorithm();
    return 0;
}
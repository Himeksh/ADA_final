#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;
void WriteDataToFile(int i, double avgtime_iter , double avgtime_rec) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << " " << avgtime_iter << " " << avgtime_rec << endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void MaxMinIterative(int* a, int low, int high, int& max, int& min) {
    max = INT_MIN;
    min = INT_MAX;
    
    for (int i = low; i <= high; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
}
void MaxMin(int* a, int low, int high, int& max, int& min) {
    if (low == high) {
        max = a[low];
        min = a[low];
        return;
    }
    if (high - low == 1) {
        if (a[low] < a[high]) {
            max = a[high];
            min = a[low];
        } else {
            max = a[low];
            min = a[high];
        }
        return;
    }

    int mid = (low + high) / 2;
    int max1, min1;
    MaxMin(a, low, mid, max, min);
    MaxMin(a, mid + 1, high, max1, min1);

    if (max < max1) {
        max = max1;
    }
    if (min > min1) {
        min = min1;
    }
}
int main(){
    double avgtime_itr,avgtime_rec,time1,time2;
    int max,min;
    for(int i=100;i<1000;i+=100){
        int *a = new int [i];
        for(int j=0;j<i;j++){
            a[j]=rand();
        }
        time1 =(double)clock();
        for(int k=0;k<10;k++){
            MaxMin(a,1,i,max,min);
        }
        time2=(double)clock();
        avgtime_rec=(double)(time2-time1)/10;
        
        int *b = new int [i];
        for(int j=0;j<i;j++){
            b[j]=rand();
        }
        time1 =(double)clock();
        for(int k=0;k<10;k++){
            MaxMinIterative(b,0,i-1,max,min);
        }
        time2=(double)clock();
        avgtime_itr=(double)(time2-time1)/10;
        cout<<i<<" "<<avgtime_itr<<" "<<avgtime_rec*100<<endl;
        WriteDataToFile(i,avgtime_itr,avgtime_rec*100);
    }

    return 0;
}




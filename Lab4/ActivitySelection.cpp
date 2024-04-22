#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime_profit,double avgtime_weight, double avgtime_profitbyweight) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout<<i << "-" <<avgtime_profit<<"-"<<avgtime_weight<<"-"<<avgtime_profitbyweight<< endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void sort_by_start(int *start, int *finish, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (start[j] < start[min_idx]) {
                min_idx = j;
            }
        }
        int temp_start = start[min_idx];
        start[min_idx] = start[i];
        start[i] = temp_start;
        int temp_finish = finish[min_idx];
        finish[min_idx] = finish[i];
        finish[i] = temp_finish;
    }
}

void sort_by_end(int *start, int *finish, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (finish[j] < finish[min_idx]) {
                min_idx = j;
            }
        }
        int temp_start = start[min_idx];
        start[min_idx] = start[i];
        start[i] = temp_start;
        int temp_finish = finish[min_idx];
        finish[min_idx] = finish[i];
        finish[i] = temp_finish;
    }
}

void sort_by_duration(int *start, int *finish, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            int duration1=finish[j]-start[j];
            int duration2=finish[min_idx]-start[min_idx];
            if (duration1< duration2) {
                min_idx = j;
            }
        }
        int temp_start = start[min_idx];
        start[min_idx] = start[i];
        start[i] = temp_start;
        int temp_finish = finish[min_idx];
        finish[min_idx] = finish[i];
        finish[i] = temp_finish;
    }
}

int * Activity_Selector(int *start,int*finish,int n){
    int *solution=new int[n];
    for(int i=0;i<n;i++){
        solution[i]=0;
    }
    solution[0]=1;
    int i=0;
    for(int j=2;j<n;j++){
        if(start[j]>=finish[i]){
            solution[j]=1;
            i=j;
        }
    }
    return solution;
}


void Algorithm() {
    double time1, time2, time3,time4,time5,time6,avgtime_start,avgtime_finish,avgtime_duration;
    for (int i = 1000; i <= 100000; i += 50) {
        int *start=new int[i];
        int *finish=new int[i];
        for(int k=0;k<i;k++){
            start[k]=rand()%24;
            finish[k]=rand()%24;
        }
        int *Solution=new int[i];
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            sort_by_start(start,finish,i);
            Solution=Activity_Selector(start,finish,i);
        }
        time2 = (double)clock();
        avgtime_start= (time2 - time1) / 10.0;
        time3 = (double)clock();
        for (int k = 0; k < 10; k++) {
            sort_by_end(start,finish,i);
            Solution=Activity_Selector(start,finish,i);
        }
        time4 = (double)clock();
        avgtime_finish= (time4 - time3) / 10.0;
        time5 = (double)clock();
        for (int k = 0; k < 10; k++) {
            sort_by_duration(start,finish,i);
            Solution=Activity_Selector(start,finish,i);
        }
        time6 = (double)clock();
        avgtime_duration= (time6 - time5) / 10.0;
        cout << i << "-" <<avgtime_start<<"-"<<avgtime_finish<<"-"<<avgtime_duration<< endl;
        WriteDataToFile(i, avgtime_start,avgtime_finish,avgtime_duration);
    }
}


int main() {
    Algorithm();
    return 0;
}
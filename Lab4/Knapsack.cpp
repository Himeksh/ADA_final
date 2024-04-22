#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime_profit,double avgtime_weight, double avgtime_profitbyweight) {
    ofstream fout("knapsack.txt", ios::app);
    if (fout.is_open()) {
        fout<<i << "-" <<avgtime_profit<<"-"<<avgtime_weight<<"-"<<avgtime_profitbyweight<< endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void sort_by_profit(int profit[], int weight[], int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (profit[j] < profit[min_idx]) {
                min_idx = j;
            }
        }
        // Swap profit values
        int temp_profit = profit[min_idx];
        profit[min_idx] = profit[i];
        profit[i] = temp_profit;
        // Swap weight values
        int temp_weight = weight[min_idx];
        weight[min_idx] = weight[i];
        weight[i] = temp_weight;
    }
}

void sort_by_weight(int profit[], int weight[], int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (weight[j] < weight[min_idx]) {
                min_idx = j;
            }
        }
        // Swap profit values
        int temp_profit = profit[min_idx];
        profit[min_idx] = profit[i];
        profit[i] = temp_profit;
        // Swap weight values
        int temp_weight = weight[min_idx];
        weight[min_idx] = weight[i];
        weight[i] = temp_weight;
    }
}

void sort_profitbyweight(int profit[], int weight[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio_i = (double)profit[i] / weight[i];
            double ratio_j = (double)profit[j] / weight[j];
            if (ratio_i > ratio_j) {
                // Swap profit values
                int temp_profit = profit[j];
                profit[j] = profit[i];
                profit[i] = temp_profit;
                // Swap weight values
                int temp_weight = weight[j];
                weight[j] = weight[i];
                weight[i] = temp_weight;
            }
        }
    }
}


void knapsack(int n, int Weight, int *profit,int *weight_item){
    int maximum_profit=Weight;
    int *Solution=new int[n];
    int i;
    for (i=0;i<n;i++){
        Solution[i]=0;
    }
    for(i=0;i<n;i++){
        if(weight_item[i]<maximum_profit){
            Solution[i]=1;
            maximum_profit=maximum_profit-weight_item[i];
        }
        else{
            break;
        }
    }
    if(i<n){
        Solution[i]=maximum_profit/weight_item[i];
    }
};

void Algorithm() {
    double time1, time2, time3,time4,time5,time6,avgtime_profit,avgtime_weight,avgtime_profitbyweight;
    for (int i = 1000; i <= 100000; i += 50) {
        int *w=new int[i];
        int *p=new int[i];
        for(int k=0;k<i;k++){
            w[k]=rand()%100+1;
            p[k]=rand()%1000+1;
        }
        int Weight;
        Weight=rand()%100*i;
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            sort_by_profit(p,w,i);
            knapsack(i,Weight,p,w);
        }
        time2 = (double)clock();
        avgtime_profit = (time2 - time1) / 10.0;
        time3 = (double)clock();
        for (int k = 0; k < 10; k++) {
            sort_by_weight(p,w,i);
            knapsack(i,Weight,p,w);
        }
        time4 = (double)clock();
        avgtime_weight = (time4 - time3) / 10.0;
        time5 = (double)clock();
        for (int k = 0; k < 10; k++) {
            sort_profitbyweight(p,w,i);
            knapsack(i,Weight,p,w);
        }
        time6 = (double)clock();
        avgtime_profitbyweight= (time6 - time5) / 10.0;
        cout << i << "-" <<avgtime_profit<<"-"<<avgtime_weight<<"-"<<avgtime_profitbyweight<< endl;
        WriteDataToFile(i, avgtime_profit,avgtime_weight,avgtime_profitbyweight);
    }
}


int main() {
    Algorithm();
    return 0;
}
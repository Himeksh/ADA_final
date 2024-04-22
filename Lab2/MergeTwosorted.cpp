#include<bits/stdc++.h>
using namespace std;

void Generate(int a[], int b[],int i,int k) {
    for (int j = 0; j <= i; j++) {
        a[j] = rand();
    }
    for (int j = 0; j <= k; j++) {
        b[j] = rand();
    }
}

void merge(int a[], int b[],int n,int m) {
    int c[n+m];
    int i=0,j=0,k=0;
    while(i<=n && j<=m){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
        }
        else{
            c[k]=b[j];
            j++;
        }
        k++;
    }
    if(i==n+1){
        while(j<=m){
            c[k]=b[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=n){
            c[k]=a[i];
            k++;
            i++;
        }
    }
}

int main() {
      for (int i = 500; i <= 20000; i += 500) {
         ofstream file("data6.txt", ios::app);
        int a[i];
        int b[20000-i];
        double total_time = 0;
        Generate(a, b,i,20000-i);
        for (int k = 0; k < 10; k++) {
            clock_t start = clock();
            merge(a,b,i,20000-i);
            clock_t end  = clock();
            total_time+=end-start;
        }
        double duration = double(total_time)*(1000000)/double(CLOCKS_PER_SEC);
        if(file.is_open()){
            file<<duration/10<<endl;
        }
    }
      return 0;
}

#include <bits/stdc++.h>
using namespace std;

void random_generator(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
}

void position(int a[], int n)
{
    int pivot = a[0];
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < pivot)
        {
            ct++;
        }
    }
    int pivotIndex = ct;
    swap(a[0], a[pivotIndex]);

    int i = 0;
    int j = n - 1;
    while (i < pivotIndex && j > pivotIndex)
    {
        if (a[i] < pivot)
            i++;
        if (a[j] > pivot)
            j--;
        if (a[i] > pivot && a[j] < pivot)
        {
            swap(a[i], a[j]);
        }
    }
}

int main()
{
    for (int i = 1000; i <= 20000; i = i + 500)
    {
    ofstream file("data4.txt", ios::app);
        int a[i];
        double total_time = 0;
        random_generator(a, i);
        for (int m = 0; m < 10; m++)
        {
            clock_t start = clock();
            position(a, i);
            clock_t end  = clock();
            total_time+=end-start;
        }
        double duration = double(total_time)*(1000000)/double(CLOCKS_PER_SEC);
        if(file.is_open()){
            file<<i<<" "<<duration/10<<endl;
        }
    }
     return 0;
}

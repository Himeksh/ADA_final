#include <iostream>
#include <vector>
#include<fstream>
#include<time.h>


using namespace std;

void WriteDataToFile(int i, double avgTime){
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}


void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n)
                j = 0;

            if (i < 0)
                i = n - 1;
        }

        if (magicSquare[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else
            magicSquare[i][j] = num++;

        j++;
        i--;
    }

    cout << "The Magic Square for n=" << n << ":\nSum of each row or column "
            "is " << n * (n * n + 1) / 2 << ":\n\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << magicSquare[i][j] << "\t ";
        cout << endl;
    }
}

int main() {
    double time1,time2,avgtime;
    for(int i=3;i<=16;i=i+2){
        time1=(double)clock();
        for(int k = 0; k < 10; k++){
            if (i % 2 == 0) {
            cout << "Order must be odd for magic square." << endl;
            }
            generateMagicSquare(i);
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10.0;
        cout<<i<<"-"<<avgtime<<endl;
    }
    cout<<endl;
    return 0;
}

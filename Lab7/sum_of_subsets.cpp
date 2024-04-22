#include<iostream>
using namespace std;


int w[100];
int x[100];
int m;
int n;
int r;

void sumofsubsets(int s, int k, int sum) {
    x[k] = 1;

    if (s + w[k] == m) {
        for (int i = 0; i < n; i++) {
            if (x[i] == 1)
                cout << w[i] << " ";
        }
        cout << endl;
    }
    else if (s + w[k] + w[k + 1] <= m) {
        sumofsubsets(s + w[k], k + 1, sum - w[k]);
    }

    x[k] = 0;

    if (s + sum - w[k] >= m && s + w[k + 1] <= m) {
        sumofsubsets(s, k + 1, sum - w[k]);
    }
}

int main() {
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the target sum: ";
    cin >> m;

    r = 0;
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        r += w[i];
    }

    sumofsubsets(0, 0, r);
    return 0;
}

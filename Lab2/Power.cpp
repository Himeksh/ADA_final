#include<bits/stdc++.h>
using namespace std;



int power(int x,int n) {
  if(n==1) return x;
  int ans= power(x,n/2);
  if(n%2==0) return ans*ans;
  else return x*ans*ans;
}


int main() {
      for (int i = 8; i <= 30; i += 1) {
        int a[i];
        ofstream file("data5.txt", ios::app);
          double totaltime=0;
        for (int k = 0; k < 10; k++) {
             clock_t start=clock();
            int f_ans=power(10000,i);
            clock_t end=clock();
            totaltime+=end-start;
        }

        double duration = double(totaltime)*(1000000)/double(CLOCKS_PER_SEC);
        if(file.is_open()){
            file<<i<<" "<<duration/10<<endl;
        }
       
    }
   return 0;
}

#include <iostream>
#include <string>
#define NUM 3
using namespace std;

void fastestWay(int a[][NUM], int t[][NUM-1], int e[], int x[], int n){
    int f1[n], f2[n];
    string r1, r2;
    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];
    r1 = "0,0;";
    r2 = "1,0;";
    for(int j = 1; j < n; j++){
        if(f1[j-1]+a[0][j] <= f2[j-1]+t[1][j-1]+a[0][j]){
            f1[j] = f1[j-1]+a[0][j];
            r1 += "0,"+ to_string(j) + ";";
        }
        else{
            f1[j] = f2[j-1]+t[1][j-1]+a[0][j];
            r1 += "1," + to_string(j) + ";";
        };
        if(f2[j-1]+a[1][j] <= f1[j-1]+t[0][j-1]+a[1][j]){
            f2[j] = f2[j-1]+a[1][j];
            r2 += "1," + to_string(j) + ";";
        }
        else{
            f2[j] = f1[j-1]+t[0][j-1]+a[1][j];
            r2 += "0," + to_string(j) + ";";
        }
    }
    if(f1[n-1]+x[0] <= f2[n-1]+x[1]){
        cout << r1 << endl;
        cout << f1[n-1]+x[0];
    }
    else{
        cout << r2 << endl;
        cout << f2[n-1]+x[1];
    }
}

int main(){
    int a[2][NUM] = {{8,5,10},{4,2,3}};
    int t[2][NUM-1] = {{2,6},{1,1}};
    int e[2] = {7,2};
    int x[2] = {5,2};
    fastestWay(a, t, e, x, NUM);
    return 0;
}

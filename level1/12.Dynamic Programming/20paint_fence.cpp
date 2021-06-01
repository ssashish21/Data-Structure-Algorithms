#include<iostream>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;

    int ss = k * 1;
    int sd = k * (k - 1);
    int tt = ss + sd;

    for(int i = 3 ; i <= n ; i++){
        ss = sd * 1;
        sd = tt * (k - 1);
        tt = ss + sd;
    }
    cout<<tt<<endl;
}

/*
Q . You are given a number n and a number k in separate lines,
    representing the number of fences and number of colors.
    You are required to calculate and print the number of ways
    in which the fences could be painted so that not more than
    two fences have same colors.

ss - same same color
sd - same diff color
tt - total

   1
ss []
sd []
tt []
*/
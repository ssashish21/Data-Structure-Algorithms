#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ar[n];
    for(int i = 0 ; i < n ; i++)
    	cin >> ar[i];

    int lsf = ar[0]; // least so far
    int bpst = 0;    // best profit sell today
    int *dpl = new int[n];// profit if buy sell before or ==today

    for(int i = 1 ; i < n ; i++){
        lsf = min(lsf , ar[i]);
        bpst = ar[i] - lsf;
        dpl[i] = max(dpl[i - 1] , bpst);
    }

    int msf = ar[n - 1]; // max so far
    int bpbt = 0; // best profit buy today
    int *dpr = new int[n]; // profit if buy sell after or == today

    for(int i = n - 2 ; i >= 0 ; i--){
        msf = max(msf , ar[i]);
        bpbt = msf - ar[i];
        dpr[i] = max(dpr[i + 1] , bpbt); 
    }

    int op = INT_MIN; // overall profit
    for(int i = 0 ; i < n ; i++){
        op = max(op , dpr[i] + dpl[i]);
    }

    cout<<op;
}
// https://www.codechef.com/JUNE20B/problems/PRICECON

#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        int price;
        int sum = 0;
        int changesum = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>price;
            sum += price;
            if(price > k) changesum +=k;
            else changesum+=price;
        }
        cout<<sum - changesum<<"\n";
    }
    return 0;
}
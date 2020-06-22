// https://www.codechef.com/JUNE20B/problems/CHFICRM

#include <bits/stdc++.h>
using namespace std;
string solve(int n,int coin[]){
    int coin5 = 0 , coin10 = 0, coin15 = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(coin[i] == 5)
        {
            coin5++;
        }
         else if(coin[i] ==10)
            {
                if(coin5 < 1)
                {
                   return "NO";
                }
                coin10++;
                coin5--;
            }
         else if(coin[i] ==15)
            {
                if(coin5 < 2 && coin10 < 1)
                {
                    return "NO";
                }
                coin15++;
                if(coin10 >= 1) coin10--;
                else coin5-=2;
            }    
    }
    return "YES";
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        cout<<solve(n,arr)<<'\n';
    }
    
    return 0;
}


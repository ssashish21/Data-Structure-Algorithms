// https://www.spoj.com/problems/BUSYMAN

//ACTIVITY SELECTION

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        for(int i=0,x,y;i<n;i++){
            cin>>x>>y;
            v[i].first = y;
            v[i].second = x;
        }
        sort(v.begin(),v.end());
        int count=1;
        for(int i=0,j=1;j<n;j++){
            if(v[i].first<=v[j].second){
              count++;
              i=j;
            } 
        } 
        cout<<count<<'\n';  
    }

    return 0;
}

// https://www.codechef.com/JUNE20B/problems/XYSTR

#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int count = 0;
        for(int i = 0 ; i < s.length() - 1 ; i++){
            if((s[i] == 'x' && s[i+1] == 'y') || (s[i] == 'y' && s[i+1] == 'x') )
            {
                count++;
                i++;
            } else {
                continue;
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}
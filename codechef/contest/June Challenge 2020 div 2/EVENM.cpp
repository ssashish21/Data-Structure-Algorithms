// https://www.codechef.com/JUNE20B/problems/EVENM

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n&1)
        {
           int c = 1;
            for(int i = 0 ; i < n ; i++){
                 for(int j = 0 ; j < n ; j++)
                    cout<<c++<<" ";
                    cout<<'\n';
            }
        } else {
            int c = 1;
            for(int i = 0 ; i < n ; i++ )
            {
                if(!(i&1))
                {
                    for(int j = 0 ; j < n ; j++) cout<<c++<<" ";
                }
                else
                {
                    int rc = c + n -1;
                    for(int j = 0 ; j <  n ; j++) {
                        cout<<rc--<<" ";
                        c++;
                    }
                }
                cout<<'\n';
            }
        }
    }

    return 0;
}

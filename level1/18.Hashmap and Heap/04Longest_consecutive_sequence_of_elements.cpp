#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0 ; i < n ; i++)
        cin >> ar[i];

    unordered_map<int, bool> mp;

    //now all elements are starting of any sequence
    for(int i = 0 ; i < n ; i++) 
        mp[ar[i]] = true;

    //discard all elements which can
    //not be starting of a sequence
    for(int i = 0 ; i < n ; i++)
        if(mp.count(ar[i] - 1) > 0)
            mp[ar[i]] = false;

    int ansstart = 0;
    int anslength = 0;

    for(int i = 0 ; i < n ; i++){
        if(mp[ar[i]] == true){
            int tempstart = ar[i];
            int templength = 1;

            while(mp.count(tempstart + templength) > 0){
                templength++;
            }

            if(templength > anslength){
                anslength = templength;
                ansstart = tempstart;
            }
        }
    } 

    //printing ans 
    for(int i = 0 ; i < anslength ; i++){
        cout<<i + ansstart<<endl;
    } 
}
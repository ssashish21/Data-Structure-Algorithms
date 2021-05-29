#include<bits/stdc++.h>
using namespace std;

void print(int *ans, int size){
    for(int i = 0 ; i < size ; i++){
        if(floor(log10(ans[i])) + 1 != 8) cout<<'0'; 
        cout<<ans[i]<<endl;
    } 
}

void countSort(int *ar, int div, int mod, int range, int size){
    int *ans = new int[size];
    int *freq = new int[range];

    for(int i = 0 ; i < size ; i++)
        freq[(ar[i] / div) % mod]++;

    for(int i = 1 ; i < range ; i++)
         freq[i] += freq[i - 1];

    for(int i = size - 1 ; i >= 0 ; i--){
        int pos = freq[(ar[i] / div) % mod] -1;
        ans[pos] = ar[i];
        freq[(ar[i]/div) % mod]--; 
    }

    for(int i = 0 ; i < size ; i++)
        ar[i] = ans[i];
    delete [] ans;
}
void sortDate(int *date , int size){
    countSort(date , 1000000, 100 , 32 , size); // day
    countSort(date , 10000 , 100 , 13 , size); // month
    countSort(date , 1 , 10000 , 2501 , size); // Year
}
int main(){
    int n;
    cin>>n;

    int *date = new int[n];

    for(int i = 0 ; i < n ; i++)
        cin>>date[i];

    sortDate(date, n);
    print(date , n);
    delete [] date;
    return 0;
}
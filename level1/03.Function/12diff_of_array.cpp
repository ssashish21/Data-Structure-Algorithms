#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    cin>>n1;
    int* a1 = new int[n1];
    for(int i = 0 ; i < n1; i++){
        cin>>a1[i];
    }
    
    cin>>n2;
    int* a2 = new int[n2];
    for(int i = 0 ; i < n2; i++){
        cin>>a2[i];
    }
    
    int a[n2];
    int i = n1 - 1;
    int j = n2 - 1;
    int k = n2 - 1;
    int c = 0;

    while(k>=0){
      int d = 0;
      int a1v = i >= 0 ? a1[i]:0;

      if(a2[j] + c >= a1v){
          d = a2[j] + c - a1v;
          c = 0;
      } else {
          d = a2[j] + c + 10 - a1v;
          c = -1;
      }

      a[k] = d;

      i--;
      j--;
      k--;
    }
      
    i = 0;
    for( ;i < n2 ; i++){
        if(a[i] != 0)
          break;
    }

    for( ; i <n2 ; i++){
      cout << a[i]<<endl;
    }
}
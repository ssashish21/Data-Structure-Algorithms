#include<iostream>
using namespace std;

void toh(int n, int src, int des, int aux){
    if(n == 0) return;
    toh(n-1, src , aux , des);
    cout << n << "["<<src<<" -> "<<des<<"]"<<endl;
    toh(n-1, aux , des , src);
    
}

int  main() {

    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
  }

#include<iostream>
#include<stack>
using namespace std;

int* nextGreaterInRight(int* ar, int size){
    int* nge = new int[size];
    stack<int> st;

    for(int i = size - 1; i >= 0; i--){
        while(st.size() > 0 && ar[i] >= ar[st.top()])
            st.pop();

        nge[i] = st.empty() ? size : st.top();

        st.push(i);
    }
    return nge;
}

void slidingWindowMaximum(int* ar , int size , int k){
    int* nge = nextGreaterInRight(ar , size);

    for(int i = 0 ; i <= size - k ; i++){
        int j = i;
        while(nge[j] < i + k){
            j = nge[j];
        }
        cout<<ar[j]<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    
    int* ar = new int[n];
    for(int i = 0 ; i < n ; i++)
        cin>>ar[i];
    
    int k;
    cin>>k;

    slidingWindowMaximum(ar , n , k);
}
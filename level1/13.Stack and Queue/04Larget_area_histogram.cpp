#include<iostream>
#include<stack>
using namespace std;

int* nextSmallerInLeft(int* height , int size){
    int* nsl = new int[size];
    stack<int> st;

    for(int i = 0 ; i < size ; i++){
        while(st.size() && height[i] <= height[st.top()])
            st.pop();
        
        nsl[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return nsl;
}

int* nextSmallerInRight(int* height , int size){
    int* nsr = new int[size];
    stack<int> st;

    for(int i  = size - 1 ; i >= 0 ; i--){
        while(st.size() && height[i] <= height[st.top()])
            st.pop();

        nsr[i] = st.empty() ? size : st.top();
        
        st.push(i);
    }
    return nsr;
}


int largestRectangleInHistogram(int* height , int size){
    int* nsl = nextSmallerInLeft(height , size);
    int* nsr = nextSmallerInRight(height , size);

    int area = 0;
    for(int i = 0  ; i < size ; i++){
        area = max(area , height[i] * (nsr[i] - nsl[i] - 1));
    }
    return area;
}

int main(){
    int n;
    cin >> n;

    int* height = new int[n];
    for(int i = 0 ; i < n ; i++)
        cin>>height[i];

    cout<<largestRectangleInHistogram(height , n)<<endl;

    delete [] height;
    return 0;
}
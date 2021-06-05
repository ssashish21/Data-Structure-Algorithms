#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

void celebrityProblem(vvi &arr){
    stack<int> st;

    for(int i = 0 ; i < arr.size() ; i++){
        st.push(i);
    }

    while(st.size() >= 2){
        int i = st.top(); st.pop();
        int j = st.top(); st.pop();

        if(arr[i][j] == 1){
            st.push(j);
        } else {
            st.push(i);
        }
    }

    int pot = st.top(); // potential candidate

    for(int i = 0 ; i < arr.size() ; i++){
        if(i != pot){
            if(arr[i][pot] == 0 || arr[pot][i]){
                cout<<"none"<<endl;
                return;
            }
        }
    }

    cout<<pot<<endl;
}

int main(){
    int n;
    cin>>n;

    char c;

    vvi arr(n , vi (n, 0));
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ; j++){
            cin >> c;
            arr[i][j] = (c - '0');
        }
    }
    celebrityProblem(arr);
}
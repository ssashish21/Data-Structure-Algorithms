#include <bits/stdc++.h> 
using namespace std;

class Item {
public:
    int value, weight;
};
 
bool cmp(Item a, Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
 
double fractionalKnapsack(int W, vector<Item> arr, int n){
    sort(arr.begin(), arr.end(), cmp);
 
    int curWeight = 0; // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)
 
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalvalue += arr[i].value
                          * ((double)remain
                             / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
 
int main(){
    int n , W;
    cin >> n;

    vector<Item> arr(n);
    for(int i = 0 ; i < n ; i++) 
        cin >> arr[i].value;
    for(int i = 0 ; i < n ; i++) 
        cin >> arr[i].weight;

    cin >> W;
    
    double res = fractionalKnapsack(W, arr, n) * 1.0;
    cout <<fixed << setprecision(1)<<res;
}
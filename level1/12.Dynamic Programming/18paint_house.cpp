#include<iostream>
#include<vector>
using namespace std;

class Color{
    public:
        int rc;
        int gc;
        int bc;
    
    Color(int rc , int gc , int bc){
        this->rc = rc;
        this->gc = gc;
        this->bc = bc;
    }
};

int min1(int a , int b , int c = 0){
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int main(){
    int n;
    cin >> n;

    vector<Color> house;

    for(int i = 0 ; i < n ; i++){
        int r , g ,b;
        cin >> r >> g >> b;
        
        house.push_back(Color(r , g , b));
    }

    int end_rc = house[0].rc;
    int end_gc = house[0].gc;
    int end_bc = house[0].bc;

    for(int i = 1 ; i < house.size() ; i++){
        int tempr = end_rc;
        int tempg = end_gc;
        int tempb = end_bc;

        end_rc = house[i].rc + min(tempg , tempb);
        end_gc = house[i].gc + min(tempr , tempb);
        end_bc = house[i].bc + min(tempr , tempg);
    }

    cout<<min1(end_rc , end_gc , end_bc)<<endl;
}

//can also be done using 3 * n dimensional array
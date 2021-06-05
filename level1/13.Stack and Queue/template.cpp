#include<bits/stdc++.h>
using namespace std;

template <typename T , typename U , typename V>

class Pair{
	public:
	T x;
	U y;
	V z;

	Pair(T x , U y , V z){
		this -> x = x;
		this -> y = y;
		this -> z = z;
	}

	void make_pair(T x , U y , V z){
		this -> x = x;
		this -> y = y;
		this -> z = z;
	}

	Pair get_pair(){
		Pair p(x , y , z);
		return p;
	}
};


int main(){
	Pair<string, char , int> p1("Ashish" , 'A' , 40);
	Pair p = p1.get_pair();

	cout << p.x << " " << p.y << " " << p.z << endl;
}
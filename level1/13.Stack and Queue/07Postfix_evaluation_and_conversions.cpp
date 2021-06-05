#include<iostream>
#include<stack>
using namespace std;

int operation(int v1 , int v2 , char op){
    if(op == '+') return v1 + v2;
    else if(op == '-') return v1 - v2;
    else if(op == '*') return v1 * v2;
    else return v1 / v2;
}

void postfixEvolution(string exp){
    stack<int> vs;
    stack<string> infs;
    stack<string> pres;

    for(int i = 0 ; i < exp.size() ; i++){
        char ch = exp[i];
        
        if(isdigit(ch)){
            vs.push(ch - '0');
            string s(1 , ch);
            infs.push(s);
            pres.push(s);
        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int v2 = vs.top(); vs.pop();
            int v1 = vs.top(); vs.pop();
            int val = operation(v1 , v2 , ch);
            vs.push(val);

            string infv2 = infs.top(); infs.pop();
            string infv1 = infs.top(); infs.pop();
            string infv = "(" + infv1 + ch + infv2 + ")";
            infs.push(infv);

            string prev2 = pres.top(); pres.pop();
            string prev1 = pres.top(); pres.pop();
            string prev =  ch + prev1 + prev2;
            pres.push(prev);   
        }
    }

    cout<<vs.top()<<endl;
    cout<<infs.top()<<endl;
    cout<<pres.top()<<endl;
}

int main(){
    string exp;
    cin>>exp;

    postfixEvolution(exp);
}
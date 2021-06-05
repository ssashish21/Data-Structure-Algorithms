#include<iostream>
#include<stack>
using namespace std;

int calc(int v1 , int v2 , char op){
    if(op == '+') return v1 + v2;
    else if(op == '-') return v1 - v2;
    else if(op == '*') return v1 * v2;
    else return v1 / v2;
}

void prefixEvolution(string exp){
    stack<int> vs; // value stack
    stack<string> is; // infix stack
    stack<string> ps; // postfix stack

    for(int i = exp.size() - 1 ; i >= 0 ; i--){
        char ch = exp[i];
        
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int vsval1 = vs.top(); vs.pop();
            int vsval2 = vs.top(); vs.pop();
            int vsval = calc(vsval1 , vsval2 , ch);
            vs.push(vsval);

            string isval1 = is.top(); is.pop();
            string isval2 = is.top(); is.pop();
            string isval = "(" + isval1 + ch + isval2 + ")";
            is.push(isval);

            string psval1 = ps.top(); ps.pop();
            string psval2 = ps.top(); ps.pop();
            string psval = psval1 + psval2 + ch;
            ps.push(psval);

        } else {

            vs.push(ch - '0');
            string s(1 , ch);
            is.push(s);
            ps.push(s);
            
        }
    }
    cout<<vs.top()<<endl;
    cout<<is.top()<<endl;
    cout<<ps.top()<<endl;
}

int main(){
    string exp;
    cin >> exp;

    prefixEvolution(exp);
}
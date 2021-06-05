#include<iostream>
#include<stack>
using namespace std;

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    else return 2;
}

int operation(int v1 , int v2 , char op){
    if     (op == '+') return v1 + v2;
    else if(op == '-') return v1 - v2;
    else if(op == '*') return v1 * v2;
    else return v1 / v2;
}

int infixEvolution(string expression){
    stack<int> oprnd;
    stack<char> optors;

    for(int i = 0 ; i < expression.size() ; i++){
        char ch = expression[i];

        if(ch == '('){
            optors.push(ch);
        } else if(isdigit(ch)){
            oprnd.push(ch - '0');
        } else if(ch == ')'){

            while(optors.top() != '('){
                char op = optors.top();
                optors.pop();

                int v2 = oprnd.top();
                oprnd.pop();

                int v1 = oprnd.top();
                oprnd.pop();

                int opv = operation(v1 , v2 , op);
                oprnd.push(opv);
            }

            optors.pop();

        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){

            while(optors.size() > 0 && optors.top() != '(' && precedence(ch) <= precedence(optors.top())){
                char op = optors.top();
                optors.pop();

                int v2 = oprnd.top();
                oprnd.pop();

                int v1 = oprnd.top();
                oprnd.pop();
                
                int opv = operation(v1 , v2 , op);
                oprnd.push(opv);
            }

            optors.push(ch);

        }   
    }

    while(optors.size() != 0){
        char op = optors.top();
        optors.pop();
        int v2 = oprnd.top();
        oprnd.pop();
        int v1 = oprnd.top();
        oprnd.pop();
        int opv = operation(v1 , v2 , op);
        oprnd.push(opv);
    }
    
    return oprnd.top();
}
int main(){
    string exp;
    getline(cin , exp);

    cout<<infixEvolution(exp);  
}
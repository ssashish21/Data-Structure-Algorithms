#include<iostream>
#include<vector>
using namespace std;
vector<string> mazejump(int sr,int sc,int r,int c){
    if((sr==r && sc==c)|| r == -1 || c == -1 || sr > r || sc > c){
        vector<string> res;
        res.push_back("");
        return res;
    }
    
    vector<string> paths;
    
    
    for(auto mj=1;mj<=c-sc;mj++){
        vector<string> hpaths = mazejump(sr,sc+mj,r,c);
        for(auto hpath : hpaths){
            char p=mj+'0';
            string s(1,p);
        paths.push_back("h"+s+hpath);
        }
    }
    
    for(auto mj=1;mj<=r-sr;mj++){
        vector<string> vpaths = mazejump(sr+mj,sc,r,c);
        for(auto vpath : vpaths){
             char p=mj+'0';
             string s(1,p);
        paths.push_back("v"+s+vpath);
        }
    }
    for(auto mj=1;mj<=r-sr && mj<=c-sc;mj++){
        vector<string> dpaths =mazejump(sr+mj,sc+mj,r,c);
        for(auto dpath : dpaths){
             char p=mj+'0';
             string s(1,p);
        paths.push_back("d"+s+dpath);
        }
    }
   
    return paths;
}
int main(){
   int r ,c;
    cin>>r>>c;
   vector<string> op = mazejump(0,0,r-1,c-1);
   cout<<"[";
   for(auto i=0;i<op.size() - 1;++i)
   cout<<op[i]<<", ";
   cout<<op[op.size()-1];
   cout<<"]";
   
   return 0;
    
}
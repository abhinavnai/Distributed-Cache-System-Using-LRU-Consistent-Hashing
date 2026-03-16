#include<iostream>
#include<vector>
#include "header.hpp"

using namespace std;
int main(){
    lru l(10,10);
    int k,v;
    cin>>k>>v;
    while(k>=0){
        l.add(k,v);
        cin>>k>>v;
    }
    l.display();
    cout<<"\n";
    l.con.display();
}



#include<iostream>
#include<vector>
#include "header.hpp"

using namespace std;
int main(){
    fi syst;
    cout << "=============================================\n";
cout << " DISTRIBUTED CACHE SYSTEM SIMULATOR\n";
cout << "=============================================\n";
cout << "Features:\n";
cout << " - Consistent Hashing for Load Distribution\n";
cout << " - LRU Cache for Efficient Memory Management\n";
cout << " - Dynamic Server Addition & Removal\n";
cout << " - Cache Miss Handling & Data Migration\n";
cout << "---------------------------------------------\n";
cout << "Commands Available:\n";
cout << " 1. add_server PRESS [1]\n";
cout << " 2. remove_server[2] \n";
cout << " 3. add/update a data point[3]\n";
cout << " 4. remove[4] \n";
cout << " 5. find[5] \n";
cout << " 6. status[6]\n";
cout << " 7. exit[7]\n";
cout << "=============================================\n\n";
while(true){
    int funt;
    cin>>funt;
    if(funt==1){
        string id;
        int size;
        cout<<"Please enter name and size\n";
        cin>>id;
        cin>>size;
        syst.add_server(id,size);
    }
    else if(funt==2){
        string id;
        cout<<"Please enter name and size\n";
        cin>>id;
        syst.remove_server(id);
    }
    else if(funt==3){
        int k,v;
        cout <<"Please enter key and its value respectivity";
        cin>>k>>v;
        syst.add(k,v);
    }
    else if(funt ==4){
        int k;
        cout<<"Please enter key u want to remove\n";
        cin>>k;
        syst.remove(k);
    }
    else if(funt ==5){
        int k;
        cout<<"Please enter key u want to find\n";
        cin>>k;
        syst.find(k);
    }
    else if(funt ==6){
        syst.status();
    }
    else if(funt ==7){
        cout<<"Exiting...\n";
        break;
        
    }
}


return 0;
}



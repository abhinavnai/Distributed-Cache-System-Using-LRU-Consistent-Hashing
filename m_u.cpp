#include "header.hpp"
#include<iostream>
int hash_(int key,int no){
    return key%no;
}
ll::ll(int k,int d,dll* v){
    key=k;
    value=v;
    d_p=d;
    next=nullptr;
}
hash_table::hash_table(int no){
    is_altered=0;
    no_bucket=no;
    store.resize(no,nullptr);
    tail.resize(no,nullptr);
}
hash_table::hash_table(){
    is_altered=0;
    no_bucket=100;
    store.resize(100,nullptr);
    tail.resize(100,nullptr);
}
void hash_table::resize(int no){
    if(is_altered==1){
        cout<<"cannot change hash_map length as it is altered";
        return;
    }
    no_bucket=no;
    store.resize(no,nullptr);
    tail.resize(no,nullptr);
}
void hash_table:: add(int k,int d,dll* v){
    is_altered=1;
    ll* e=find(k);
    if(e){
        e->d_p = d;
        e->value = v;
        return;
    }
    ll* temp=new ll(k,d,v);
    int h=hash_(k,no_bucket);
    if(!tail[h]){
        store[h]=temp;
        tail[h]=temp;}
    else{
        tail[h]->next=temp;
        tail[h]=temp;
    }
}
bool hash_table::remove(int k){
    int h=hash_(k,no_bucket);
    ll* temp=store[h];
    if(temp==nullptr){
        return false;
    }
    if(temp->key==k){
        store[h]=temp->next;
        delete(temp);
        return true;
    }
    while(temp->next!=nullptr&&temp->next->key!=k)temp=temp->next;
    if(temp->next==nullptr){
        return false;
    }
    ll* j=temp->next;
    temp->next=j->next;
    if(j==tail[h])tail[h]=temp;
    delete(j);
    return true;
}
ll* hash_table::find(int key){
    int h= hash_(key,no_bucket);
    ll*temp=store[h];
    while(temp&&temp->key!=key)temp=temp->next;
    // if(temp==nullptr)cout<<"no such key exist";
    return temp;
}
void hash_table::display(){
    for(int i=0;i<no_bucket;i++){
        ll* temp=store[i];
        cout<<i<<"-->{";
        while(temp){
            cout<<temp->d_p;
            temp=temp->next;}
        cout<<"}\n";
    }
}
dll::dll(int k){
    key=k;
    prev=next=nullptr;
}
lru::lru(int m,int no){
    curr=0;
    max=m;
    con.resize(no);
    head=tail=nullptr;
}
void lru::remove_last(){
    if(head==nullptr)return;
    curr=curr-1;
    dll*temp =head;
    head=head->next;
    if(head==nullptr){
        tail=nullptr;
    }
    else head->prev=nullptr;
    con.remove(temp->key);
    delete(temp);
}
void lru::add(int key,int value){
    while(curr>=max)remove_last();
    ll *check=find(key);
    if(check){
        check->d_p=value;
        return;
    }
    dll *temp=new dll(key);
    con.add(key,value,temp);
    if(head==nullptr){
        head=tail=temp;
    }
    else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    curr=curr+1;
    cout<<"key "<<key<<" with value "<<value<<" is added \n";
}
ll* lru::find(int key){
    ll *t=con.find(key);
    if(!t)return nullptr;
    dll* d=t->value;
    if(d == tail) return t;
    if(d == head){
    head = d->next;
    if(head) head->prev = nullptr;
    }
    else{
        d->prev->next = d->next;
        d->next->prev = d->prev;
    }
    tail->next=d;
    d->prev=tail;
    d->next=nullptr;
    tail=d;
    return t;
}
void lru::remove(int key){
    ll *t=con.find(key);
    if(!t)return;
    dll *d=t->value;
    if(head==tail){
        head=tail=nullptr;
    }
    else if(d==head){
        head=head->next;
        if(head) head->prev = nullptr;
    }
    else if(d==tail){
        tail=tail->prev;
        tail->next=nullptr;
    }
    else{
        d->prev->next=d->next;
        d->next->prev=d->prev;
    }
    delete(d);
    con.remove(key);
    curr--;
}
void lru::display(){
    dll* t=head;
    while(t){
        cout<<t->key<<","<<con.find(t->key)->d_p<<"<->";
        t=t->next;
}}
int consistent_hash:: string_hash(const string &s) {
    std::hash<std::string> hasher;
    size_t hash = hasher(s);
    return hash%1000; // Modulo to fit within a range (e.g., 0-999)
}
int consistent_hash::hash_fn(int key) {
    return key%1500; // Modulo to fit within the same range as string_hash
}
void consistent_hash::add_s(string &s){
    int h=string_hash(s);
    servers[h]=s;
}
void consistent_hash::remove_s(string &s){
    int h=string_hash(s);
    servers.erase(h);
}
string consistent_hash::getServer(const int &key) {
    if (servers.empty()) return "No server available";
        int h = hash_fn(key);
        auto it = servers.lower_bound(h);
        if (it == servers.end()) {
            it = servers.begin();
        }
    return it->second;
}
void fi::add_server(string name, int size){
    int h = ring.string_hash(name);

    if(ring.servers.find(h) != ring.servers.end()){
        cout << "Server already exists\n";
        return;
    }

    ring.add_s(name);
    lru* newServer = new lru(size, 100);
    servers[name] = newServer;

    cout << "[ADD SERVER] " << name << endl;

    for(auto &entry : database){
        int key = entry.first;
        int val = entry.second;

        string correct = ring.getServer(key);

        if(correct == name){
            cout << "Moving key " << key << " → " << name << endl;
            newServer->add(key, val);
        }
    }
}
void fi::remove_server(string name){

    if(servers.find(name) == servers.end()){
        cout << "Server not found\n";
        return;
    }

    cout << "[REMOVE SERVER] " << name << endl;

    ring.remove_s(name);
    lru* removedServer = servers[name];

    for(auto &entry : database){
        int key = entry.first;
        int val = entry.second;

        string newServer = ring.getServer(key);

        cout << "Moving key " << key << " → " << newServer << endl;

        if(servers.find(newServer) != servers.end()){
            servers[newServer]->add(key, val);
        }
    }

    delete removedServer;
    servers.erase(name);
}
void fi::add(int k ,int v){
    string s=ring.getServer(k);
    if(servers.find(s) == servers.end()){
        cout << "Server not found\n";
        return;
    }
    database[k]=v;
    lru* temp=servers[s];
    (*temp).add(k,v);
    cout<<"KEY--->["<<k<<"]  IS ADDED OR UPDATED\n";
}
void fi::remove(int k){
    string s=ring.getServer(k);
    if(servers.find(s) == servers.end()){
    cout << "Server not found\n";
    return;
    }
    database.erase(k);
    lru *temp=servers[s];
    temp->remove(k);
    cout<<"KEY--->["<<k<<"]  IS REMOVED\n";
}
int fi ::find(int k){
    string s=ring.getServer(k);
    if(servers.find(s) == servers.end()){
    cout << "Server not found\n";
    return -1;
    }
    lru *temp=servers[s];
    ll* l=temp->find(k);
    if(l){
        cout<<"PRESENT IN SERVER ["<<s<<"] WITH VALUE"<<l->d_p<<endl;
        return l->d_p;
    }
    temp->add(k,database[k]);
    cout<<"PRESENT IN DATABASE WITH VALUE ["<<database[k]<<"]\n";
    return database[k];

}
void fi::status(){
    cout << "\n========== SYSTEM STATUS ==========\n";
    cout << "Total Servers: " << servers.size() << "\n\n";
    // Loop over each server
    for(auto &s : servers){
        cout << "Server: [" << s.first << "]\n";
        lru* cache = s.second;
        cout << "LRU State (LRU → MRU): ";
        dll* temp = cache->head;
        if(!temp){
            cout << "EMPTY";
        }
        while(temp){
            ll* node = cache->con.find(temp->key);
            if(node){
                cout << "(" << temp->key << "," << node->d_p << ")";
            } else {
                cout << "(" << temp->key << ",?)"; // safety
            }

            if(temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << "\n-----------------------------------\n";
    }
    cout << "===================================\n";
}

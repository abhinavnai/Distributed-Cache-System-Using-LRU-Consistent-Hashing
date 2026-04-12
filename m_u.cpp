#include "header.hpp"
#include<iostream>
int hash_(int key,int no){
    return key%no;
}
ll::ll(int k,dll* v){
    key=k;
    value=v;
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
void hash_table:: add(int k,dll* v){
    is_altered=1;
    ll* temp=new ll(k,v);
    int h=hash_(k,no_bucket);
    if(!tail[h]){
        store[h]=temp;
        tail[h]=temp;}
    else{
        tail[h]->next=temp;
        tail[h]=temp;
    }
}
void hash_table::remove(int k){
    int h=hash_(k,no_bucket);
    ll* temp=store[h];
    if(temp==nullptr){
        cout<<"not such key exsit";
        return;
    }
    if(temp->key=k){
        store[h]=temp->next;
        delete(temp);
        return;
    }
    while(temp->next!=nullptr&&temp->next->key!=k)temp=temp->next;
    if(temp->next=nullptr){
        cout<<"not such key exsit";
        return;
    }
    ll* j=temp->next;
    temp->next=j->next;
    delete(j);
    return;
}
ll* hash_table::find(int key){
    int h= hash_(key,no_bucket);
    ll*temp=store[h];
    while(temp&&temp->key!=key)temp=temp->next;
    if(temp==nullptr)cout<<"no such key exist";
    return temp;
}
void hash_table::display(){
    for(int i=0;i<no_bucket;i++){
        ll* temp=store[i];
        cout<<i<<"-->{";
        while(temp){
            cout<<temp->value->value;
            temp=temp->next;}
        cout<<"}\n";
    }
}
dll::dll(int k,int v){
    key=k;
    value=v;
    prev=next=nullptr;
}
lru::lru(int m,int no){
    curr=0;
    max=m;
    con.resize(no);
    head=tail=nullptr;
}
void lru::remove_last(){
    curr=curr-1;
    dll*temp =head;
    head=head->next;
    head->prev=nullptr;
    con.remove(temp->key);
    delete(temp);
}
void lru::add(int key,int value){
    while(curr>=max)remove_last();
    dll* temp=new dll(key,value);
    con.add(key,temp);
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
dll* lru::find(int key){
    ll *t=con.find(key);
    if(!t)return nullptr;
    cout<<t->value->value;
    return t->value;
}
void lru::remove(int key){
    dll *t=find(key);
    if(!t)return;
    t->prev->next=t->next;
    t->next->prev=t->prev;
    delete(t);
    con.remove(key);
    curr--;
}
void lru::display(){
    dll* t=head;
    while(t){
        cout<<t->key<<","<<t->value<<"<->";
        t=t->next;
}}

#ifndef MATH_UN
#define MATH_UN
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int hash_(int key,int no);
class dll;
class ll{
    public:
    int key;
    int d_p;
    dll* value;
    ll *next;
    ll(int k,int d,dll* v);
};
class hash_table{
    public:
    int no_bucket;
    vector<ll*> store;
    vector<ll*> tail;
    int is_altered;
    public:
    hash_table();
    hash_table(int no);
    void resize(int no);
    void add(int k,int d,dll* v);
    bool remove(int k);
    ll* find(int key);
    //int key_data(int key);
    void display();
};
class dll{
    public:
    int key;
    dll*next;
    dll*prev;
    dll(int k);
};
class lru{
    private:
    int max;
    public:
    hash_table con;
    int curr;
    dll* head; //the new values are stored at tail,LRU(most recently used) at head
    dll* tail;//and MRU(most recently used) at tail.
    lru(int m,int no);
    void add(int key,int nd);
    void remove(int key);
    void remove_last();
    ll* find(int key); //ll because the value is stored in it;
    void display();
};
class consistent_hash{
    public:
    map<int,string> servers;
    int string_hash(const string &s);
    int hash_fn(int key) ;
    void add_s(string &s);
    void remove_s(string &s);
    string getServer(const int &key);

};
class fi{
    public:
    unordered_map<int,int>database;
    consistent_hash ring;
    unordered_map<string,lru*> servers;
    void add_server(string name,int size);
    void remove_server(string name);
    void add(int k,int v);
    void remove(int k);
    int find(int k);
    void status();
};
#endif
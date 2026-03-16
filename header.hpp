#ifndef MATH_UN
#define MATH_UN
#include <vector>
using namespace std;
int hash_(int key,int no);
class dll;
class ll{
    public:
    int key;
    dll* value;
    ll *next;
    ll(int k,dll* v);
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
    void add(int k,dll* v);
    void remove(int k);
    ll* find(int key);
    void display();
};
class dll{
    public:
    int key;
    int value;
    dll*next;
    dll*prev;
    dll(int k,int v);
};
class lru{
    private:
    int max;
    public:
    hash_table con;
    int curr;
    dll* head;
    dll* tail;
    lru(int m,int no);
    void add(int key,int value);
    void remove(int key);
    void remove_last();
    dll* find(int key);
    void display();
};
#endif
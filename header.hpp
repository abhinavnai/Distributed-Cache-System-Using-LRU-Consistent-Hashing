#ifndef MATH_UN
#define MATH_UN
#include <vector>
using namespace std;
int hash(int key,int no);
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
    public:
    hash_table(int no);
    void add(int k,dll* v);
    void remove(int k);
    hash_table* find(int key);
};
class dll{
    public:
    int key;
    int value;
    dll*next;
    dll*prev;
    dll(int k,dll* prev);
};
class lru{
    public:
    int max;
    dll* head;
    dll* tail;
    void add(int key,int value);
    void remove(int key);
    void find(int key);
};
#endif
#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    int cap;
    
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        if(m.find[key]!=m.end()) {
            int val = m[key]->second;
            l.erase(m[key]);
            l.push_front({key, val});
            m[key] = l.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.size()==cap) {
            m.erase(l.back().first);
            l.pop_back();
        }
        l.push_front({key,value});
        m.insert({key,l.begin()});
    }
};
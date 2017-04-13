class LFUCache {
    int cap;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> m; //key to {value,freq};
    unordered_map<int, list<int>::iterator> pt; //key to list iterator;
    unordered_map<int, list<int>> sameFreqList;  //freq to key list;
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    int get(int key) {
        if (m.count(key) == 0) return -1;
        int f = m[key].second++;  //freq++
        sameFreqList[f].erase(pt[key]);  //put to higher freq list
        sameFreqList[++f].push_back(key);
        pt[key] = sameFreqList[f].end();  //update the iterator
        pt[key]--;  
        if (sameFreqList[minFreq].empty()) minFreq++; //check minFreq
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        if (get(key) != -1){  //put also increase frequency
            m[key].first = value;
        }
        else{
            if (size == cap){  //if max cap, delete minFreq's list's front(least recent)
                int k = sameFreqList[minFreq].front();
                sameFreqList[minFreq].pop_front();
                pt.erase(k);
                m.erase(k);
                size--;
            }
            minFreq = 1;  //insert new ele
            m[key] = {value, 1};
            sameFreqList[1].push_back(key);
            pt[key] = sameFreqList[1].end();
            pt[key]--;
            size++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
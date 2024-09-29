class DLL{
public:
    int cnt;
    DLL* next;
    DLL* prev;
    unordered_set<string> st;

    DLL(int cnt){
        this->cnt = cnt;
        this->next = NULL;
        this->prev = NULL;
    }
};
class AllOne {
    DLL* head;
    DLL* tail;
    unordered_map<string, DLL*> mp;

    void removeNode(DLL* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
public:
    AllOne() {
        head = new DLL(-1);
        tail = new DLL(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if(mp.count(key)){
            DLL* node = mp[key];
            int freq = node->cnt;
            node->st.erase(key);

            DLL* nextNode = node->next;
            if(nextNode->cnt == freq + 1){
                nextNode->st.insert(key);
                mp[key] = nextNode;
            }else{
                DLL* newNode = new DLL(freq + 1);
                newNode->st.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next = newNode;
                nextNode->prev = newNode;
                mp[key] = newNode;
            }
            if(node->st.empty()) removeNode(node);
        }else{
            DLL* firstNode = head->next;
            if(firstNode->cnt == 1){
                head->next->st.insert(key);
                mp[key] = firstNode;
            }else{
                DLL* newNode = new DLL(1);
                newNode->st.insert(key);
                newNode->prev = head;
                newNode->next = firstNode;
                head->next = newNode;
                firstNode->prev = newNode;
                mp[key] = newNode;
            }
        }
    }
    
    void dec(string key) {
        DLL* node = mp[key];
        node->st.erase(key);
        int freq = node->cnt;

        if(freq == 1){
            mp.erase(key);
        }else{
            DLL* prevNode = node->prev;
            if(prevNode->cnt != freq - 1){
                DLL* newNode = new DLL(freq - 1);
                newNode->st.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                node->prev = newNode;
                prevNode->next = newNode;
                mp[key] = newNode;
            }else{
                prevNode->st.insert(key);
                mp[key] = prevNode;
            }
        }
        if(node->st.empty()) removeNode(node);
    }
    
    string getMaxKey() {
        return tail->prev == head ? "" : *(tail->prev->st.begin());
    }
    
    string getMinKey() {
        return head->next == tail ? "" : *(head->next->st.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

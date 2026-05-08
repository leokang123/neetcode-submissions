class MyHashMap {
private:
    struct Node {
        int key{};
        int value{};
        Node* next{};
    };
    vector<Node*> _map{};
public:
    MyHashMap(): _map(1000) {}
    void put(int key, int value) {
        auto hash {key%_map.size()};
        if (_map[hash]) {
            auto* cur = _map[hash];
            if (cur->key == key) {
                cur->value = value;
                return;
            }
            while(cur->next) {
                if (cur->next->key == key) {
                    cur->next->value = value;
                    return;
                }
                cur = cur->next;
            }
            cur->next = new Node(key, value);
        } else {
            _map[hash] = new Node(key, value);
        }
    }
    
    int get(int key) {
        // if empty return -1 
        auto hash{key%_map.size()};
        if (!_map[hash]) return -1;
        auto* cur = _map[hash];
        while(cur) {
            if (cur->key == key) {
                return cur->value;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        auto hash{key%_map.size()};
        if (!_map[hash]) return ;
        auto* cur = _map[hash];
        if (cur->key == key) {
            _map[hash] = cur->next;
            return;
        }
        while(cur->next) {
            if (cur->next->key == key) {
                cur->next = cur->next->next;
                return;
            }
            cur = cur->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
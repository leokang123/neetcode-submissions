class MyHashSet {
private:
    struct Node {
        int key{};
        Node* next{};
    };
    vector<Node*> _set{};
public:
    MyHashSet(): _set(1000) {}
    
    void add(int key) {
        auto hash{key%_set.size()};
        if (_set[hash]) {
            auto* cur = _set[hash];
            if (cur->key == key) return;
            while(cur->next) {
                if (cur->next->key == key) return;
                cur = cur->next;
            }
            cur->next = new Node(key);

        } else {
            _set[hash] = new Node(key);
        }
    }
    
    void remove(int key) {
        auto hash{key%_set.size()};
        if (!_set[hash]) return;

        auto* cur = _set[hash];
        if (cur->key == key) {
            _set[hash] = cur->next;
            delete cur;
            return;
        }
        while(cur->next) {
            if (cur->next->key == key) {
                auto* nodeToDelete = cur->next;
                cur->next = cur->next->next;
                delete nodeToDelete;
                return;
            }
            cur = cur->next;
        }
        return;
    }
    
    bool contains(int key) {
        auto hash{key%_set.size()};
        if (!_set[hash]) return false;
        auto* cur = _set[hash];
        if (cur->key == key) return true;
        while(cur->next){
            if (cur->next->key == key) return true;
            cur = cur->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
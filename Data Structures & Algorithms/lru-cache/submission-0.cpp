class LRUCache {
    struct Node {
        int key , value;
        Node* prev , *
        next;
        Node(int k , int v ) : key(k),value(v) , prev(nullptr) , next(nullptr) {}
    };

    int cap;
    unordered_map<int,Node*> cache;
    Node *head , *tail;

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;

        Node* node = cache[key];
        removeNode(node);
        insertFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            insertFront(node);
        }else{
            if(cache.size() == cap){
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete(lru);
            }
            Node* newnode = new Node(key,value);
            insertFront(newnode);
            cache[key] = newnode;
        }
    }
};

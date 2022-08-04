class LRUCache {
    
public:
    class Node{
        public:
            int key,value;
            Node* next;
            Node* prev;
            Node(int k,int v)
            {
                key = k;
                value = v;
            }
    };
    unordered_map<int,Node*> m;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int size;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void add_node(Node* cache)
    {
        Node* temp = head->next;
        head->next = cache;
        cache->next = temp;
        temp->prev = cache;
        cache->prev = head;
    }
    
    void delete_node(Node* delete_node)
    {
        Node* del_next = delete_node->next;
        Node* del_prev = delete_node ->prev;
        del_next->prev = del_prev;
        del_prev ->next = del_next;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            Node* temp = m[key];
            int ans = temp->value;
            m.erase(key);
            delete_node(temp);
            add_node(temp);
            m[key] = head->next;
            return ans;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end())
        {
            Node* temp = m[key];
            m.erase(key);
            delete_node(temp);
        }
        if(m.size()==size)
        {
            m.erase(tail->prev->key);
            delete_node(tail->prev);
        }
        Node* cache = new Node(key,value);
        add_node(cache);
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
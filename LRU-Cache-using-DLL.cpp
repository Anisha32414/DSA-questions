class LRUCache {
public:
   
    struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key1,int val1): val(val1),key(key1),prev(NULL),next(NULL){}
    };

    unordered_map<int,Node*>mp;
    int cap;
    Node* head;
    Node* tail;

    void deleteNode(Node* node){
        Node* nextNode=node->next;
        Node* prevNode=node->prev;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void addNode(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node=mp[key];
        deleteNode(node);
        addNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val=value;
            deleteNode(node);
            addNode(node);
        }
        else{
            if(mp.size()==cap){
                Node* lru=tail->prev;
                deleteNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node=new Node(key,value);
            addNode(node);
            mp[key]=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

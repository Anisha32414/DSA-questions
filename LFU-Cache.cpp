struct Node{
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;
    Node(int key1,int val1){
        key=key1;
        val=val1;
        next=NULL;
        prev=NULL;
        cnt=1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void addNodeFront(Node* node){
        Node* temp=head->next;
        node->next=temp;
        temp->prev=node;
        head->next=node;
        node->prev=head;
        size++;
    }

    void deleteNode(Node* node){
        Node* nodePrev=node->prev;
        Node* nodeNext=node->next;
        nodePrev->next=nodeNext;
        nodeNext->prev=nodePrev;
        size--;
    }
};

class LFUCache {
public:
    
    map<int,Node*>keyNodes;
    map<int,List*>freqNodes;
    int cap;
    int minFreq;
    int currSize;

    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
        currSize=0;
    }


    void updateFreqList(Node* node) {
        int freq = node->cnt;
        freqNodes[freq]->deleteNode(node);

       
        if (freq == minFreq && freqNodes[freq]->size == 0) {
            minFreq++;
        }

        node->cnt++;
        int newFreq = node->cnt;

        if (freqNodes.find(newFreq) == freqNodes.end()) {
            freqNodes[newFreq] = new List();
        }

        freqNodes[newFreq]->addNodeFront(node);
    }

    int get(int key) {
        if (keyNodes.find(key) == keyNodes.end()) return -1;

        Node* node = keyNodes[key];
        updateFreqList(node);
        return node->val;
    } 
    
    void put(int key, int value) {
        if (cap == 0) return;

        if (keyNodes.find(key) != keyNodes.end()) {
            Node* node = keyNodes[key];
            node->val = value;
            updateFreqList(node);
            return;
        }

        if (currSize == cap) {
           
            List* list = freqNodes[minFreq];
            Node* toDelete = list->tail->prev;
            keyNodes.erase(toDelete->key);
            list->deleteNode(toDelete);
            currSize--;
        }

        Node* newNode = new Node(key, value);
        minFreq = 1;

        if (freqNodes.find(minFreq) == freqNodes.end()) {
            freqNodes[minFreq] = new List();
        }

        freqNodes[minFreq]->addNodeFront(newNode);
        keyNodes[key] = newNode;
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

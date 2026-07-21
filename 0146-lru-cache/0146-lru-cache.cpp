class DLLNode {
public:
    int data;
    int key;
    DLLNode* next;
    DLLNode* prev;

    DLLNode(int k,int x) {
        key =k;
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
class DLL {
public:
    DLLNode* Head;
    DLLNode* Tail;

    DLL() {
        Head = new DLLNode(-1,-1);
        Tail = new DLLNode(-2,-2);
        Head->next = Tail;
        Tail->prev = Head;
    }
    void del(DLLNode* temp) {

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    
        delete temp;
    }
    void push(int key,int val) {
        DLLNode* temp = new DLLNode(key,val);
        temp->next = Head->next;
        Head->next = temp;
        temp->next->prev = temp;
        temp->prev = Head;
    }
};

class LRUCache {
public:
    DLLNode* negga = new DLLNode(-3,-1);
    unordered_map<int, DLLNode*> M;
    int limit;
    int elements = 0;
    DLL list ;
    LRUCache(int capacity) {

        limit = capacity;
        list = DLL();
    }

    int get(int key) {
        if (!M[key] || M[key] == negga)
            return -1;
        
        list.push(key,M[key]->data);
        list.del(M[key]);
        M[key]=list.Head->next;
        return M[key]->data;
    }

    void put(int key, int value) {
        if (M[key]==nullptr || M[key] == negga) {
            if (elements == limit) {
                list.push(key,value);
                M[key]=list.Head->next;
                M[list.Tail->prev->key]= negga;
                list.del(list.Tail->prev);
            }
            else
            {
                list.push(key,value);
                M[key]=list.Head->next;
                elements++;
            }
        }
        else
        {
            list.del(M[key]);
            list.push(key,value);
            M[key]=list.Head->next;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
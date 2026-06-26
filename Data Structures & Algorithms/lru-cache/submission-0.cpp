class LRUCache {
private:
    class Node{
        public:
            int key;
            int value;
            Node* next=NULL,*prev=NULL;
            Node(int k,int v){
                key=k;value=v;
                next=nullptr;prev=nullptr;
            }
    };
    int cap;
    unordered_map<int,Node*>mpp;
    Node* head;
    Node* tail;
public:
    LRUCache(int cap) {
        this->cap=cap;
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* req=mpp[key];
            req->prev->next=req->next;
            req->next->prev=req->prev;
            req->next=head->next;
            req->prev=head;
            head->next->prev=req;
            head->next=req;
            return req->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            mpp[key]->value=value;
            get(key);
        }else{
            if(mpp.size()==cap){
                Node* req=tail->prev;
                tail->prev=req->prev;
                req->prev->next=tail;
                mpp.erase(req->key);
                delete req;
            }
            Node* temp = new Node(key,value);
            head->next->prev=temp;
            temp->next=head->next;
            temp->prev=head;
            head->next=temp;
            mpp[key]=temp;
        }
    }
};

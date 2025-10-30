class LRUCache {
public:
class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int _key, int _val){
        key=_key;
        val=_val;
    }
};
int cap;
unordered_map<int,Node*>mp;
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
       cap=capacity;
       head->next=tail;
       tail->prev=head;
    }
 void insertAfterHead(Node *node){
    Node* temp=head->next;
    node->next=temp;
    temp->prev=node;
    node->prev=head;
    head->next=node;

 }

 void deleteNode(Node* node){
    Node* delPrev=node->prev;
    Node* delNext=node->next;
    delPrev->next=delNext;
    delNext->prev=delPrev;
   
 }

    
    int get(int key) {
       if(mp.find(key)!=mp.end()){
          Node* node=mp[key];
          deleteNode(node);
          insertAfterHead(node);
          return node->val;
       } 
       return -1;
    }
    
    void put(int key, int value) {
         if(mp.find(key)!=mp.end()){
          Node* node=mp[key];
          node->val=value;
          deleteNode(node);
          insertAfterHead(node);
        
       } 
       else{
          if(mp.size()==cap){
            Node* LRU=tail->prev;
            mp.erase(LRU->key);
            deleteNode(LRU);
            delete(LRU);
          }
          Node* node=new Node(key,value);
          insertAfterHead(node);
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
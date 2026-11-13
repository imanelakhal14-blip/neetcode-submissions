class LinkedList {
private : 
    struct Node {
        int data ; 
        struct Node *next ;
    };
    struct Node *head ;
public:
    LinkedList() {
        head = nullptr ; // head pointe vers NULL 
    }   

    int get(int index) {
        struct Node *current = head ;
        int k = 0 ; 
        //on va parcourir toute la liste et comparer chaque element 
        while(current!=nullptr){
            if(k==index){
                return current->data ; 
            }
            current=current->next ; 
            k++;
        }
        return -1;
    }

    void insertHead(int val) {
        struct Node *newNode = new Node(); //sans malloc comme c 
        newNode->data = val ; 
        newNode->next = head ;
        head = newNode ; 
    }
    
    void insertTail(int val) {
        struct Node *newNode = new Node(); 
        newNode->data = val ; 
        struct Node *current = head ; 
        if(head==nullptr){
            head = newNode ; 
            newNode->next = nullptr ; 
            return ; 
        }
        while(current->next != nullptr){
            current = current->next;
        }
        //dernier element 
        current->next  = newNode ; 
        newNode -> next = nullptr ; 
    }

    bool remove(int index) {
        Node *todelete ; 
        int k = 0 ;
        //si la liste est vide 
        if(head == nullptr ){
            return false ; 
        }
        struct Node *current = head ;
        //suppression au debut  
        if(index==0){
            todelete = head ; 
            head=head->next ; 
            delete todelete ; 
            return true ; 
        }
        while((current->next!=nullptr)&&(k<(index-1))){ // on est sure qu'on s'arrette au pire des cas dans l'element avant dernier ; 
            k++ ;
            current = current->next ;
        }
        if ((k<index-1)||(current->next==nullptr)){
            return false ; 
        }
        todelete = current->next ; 
        current->next = todelete -> next ; 
        delete todelete ; 
        return true ;
    }

    vector<int> getValues() {
        vector<int> values ; 
        Node *current = head ; 
        while(current!=nullptr){
            values.push_back(current->data);
            current = current -> next ; 
        }
        return values ; 
    }
};
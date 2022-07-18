class MyLinkedList {
    int val;
    MyLinkedList* next;
public:
    MyLinkedList* head;
    MyLinkedList() {
        val = 0;
        next = NULL;
        head = NULL;
    }
    
    int get(int index) {
        MyLinkedList* ptr = head;
        int i = 0;
        while(ptr != NULL && i != index){
            ptr = ptr->next;
            i++;
        }
        return ptr != NULL?ptr->val:-1;
    }
    
    void addAtHead(int val) {
        MyLinkedList* ptr = head;
        head = new MyLinkedList();
        head->next = ptr;
        head->val = val;
    }
    
    void addAtTail(int val) {
        MyLinkedList* temp = new MyLinkedList();
        temp->val = val;
        temp->next = NULL;
        MyLinkedList* ptr = head;
        if(head == NULL ) head = temp;
        else{
            while(ptr->next != NULL){ ptr = ptr->next; }
            ptr->next = temp;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) addAtHead(val);
        else{
            MyLinkedList* temp = new MyLinkedList();
            temp->val = val;
            MyLinkedList* ptr = head;
            while(ptr != NULL && index != 1){
                ptr = ptr->next;
                index--;
            }
            if(ptr != NULL){
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index == 0 &&  head != NULL) head = head->next;
        MyLinkedList* ptr = head;
        int i = 1;
        while(ptr != NULL && i != index) {
            ptr = ptr->next;
            i++;
        }
        if(ptr!= NULL && ptr->next != NULL) {
            ptr->next = ptr->next->next;
        }
    }
};
#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode *next;
};

struct ListNode* CreateNode(struct ListNode *head , int data ){
    struct ListNode *newnode;
    newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(newnode == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    if(head == NULL){
        newnode->data = data;
        newnode->next = head;
        head = newnode;
    }
    else{
        struct ListNode *current;
        current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newnode;
        newnode->data = data;
        newnode->next = NULL;
    }
    return head;
}

struct ListNode* InsertNode(struct ListNode *head , int data , int position){
    struct ListNode *newnode;
    newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(newnode == NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    newnode->data = data;
    if(position == 1){
        newnode->next = head;
        head = newnode;
        return head;
    }
    else{
        struct ListNode *current = head;
        struct ListNode *nextnode;

        int pos = 1;
        nextnode=current->next;
        while(pos<position-1){
            current = current->next;
            nextnode=nextnode->next;
            pos++;
        }
        current->next = newnode;
        newnode->next = nextnode;
    }
    return head;
}

struct ListNode* DeleteNode(struct ListNode *head , int position){
    struct ListNode *current = head;
    if(position==1){
        current = current->next;
        head->next = NULL;
        head = current;
    }
    else{
        current = head;
        struct ListNode *nextnode;
        struct ListNode *del;
        int pos=1;
        nextnode=current->next;
        del = current->next;
        while(pos<position-1){
            current = current->next;
            nextnode=nextnode->next;
            del = del->next;
            pos++;
        }
        nextnode = nextnode->next;
        del->next=NULL;
        current->next = nextnode;
    }
    return head;
}

struct ListNode* ReverseList(struct ListNode *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode *previous = NULL;
    struct ListNode *current = head;
    struct ListNode *nextnode = NULL;
    while(current != NULL){
        nextnode = current->next;
        current->next = previous;
        previous = current;
        current = nextnode;
    }
    head = previous;
    return head;
}

int SearchList(struct ListNode* head , int data){
    struct ListNode* curr = head;
    int i=1;
    while(curr != NULL){

        if(curr->data == data){
            return i;
        }
        i++;
        curr = curr->next;
    }
    return -1;
}

struct ListNode* UpdateList(struct ListNode* head , int data , int pos){
    struct ListNode* curr = head;
    int i=1;
    while(curr !=NULL){
        if(i==pos){
            curr->data = data;
            break;
        }
        i++;
        curr = curr->next;
    }
    return head;
}

int Len(struct ListNode* head){
    struct ListNode* curr = head;
    int i=1;
    while(curr->next != NULL){
        i++;
        curr = curr->next;
    }
    return i;

}

struct ListNode* MergeList(struct ListNode* head1 , struct ListNode* head2){
    struct ListNode* curr = head1;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = head2;
    return head1;
}

struct ListNode* SplitList(struct ListNode* head1 , struct ListNode* head2 , int position){
    struct ListNode* curr = head1;
    int pos =1;
    while(pos < position){
        curr = curr->next;
        pos++;
    }
    head2 = curr->next;
    curr->next = NULL;
    return head2;
}

struct ListNode* MergeSortedList(struct ListNode* p , struct ListNode* q , struct ListNode* s){
    struct ListNode* newhead = NULL;
    if(p == NULL){
        return q;
    }
    if(q == NULL){
        return p;
    }
    if(p && q){
        if(p->data <= q->data){
            s = p;
            p = s->next;
        }
        else{
            s = q;
            q = s->next;
        }
    }
    newhead = s;
    while(p && q){
        if(p->data <= q->data){
            s->next = p;
            s = p;
            p = s->next;
        }else{
            s->next = q;
            s = q;
            q = s->next;
        }
    }
    if(p == NULL){
        s->next = q;
    }
    if(q == NULL){
        s->next = p;
    }
    return newhead;
}

struct ListNode * RotateList(struct ListNode *head , int k){
    int len = Len(head);
    for(int i=0;i<k%len;i++){
        struct ListNode *curr  = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = NULL;
    }
    return head;
}

void ClearMemory(struct ListNode *head){
    struct ListNode *curr = head;
    struct ListNode *nextnode;

    while (curr != NULL) {
        nextnode = curr->next;
        free(curr);
        curr = nextnode;
    }
    printf("\nSuccessfully cleared the memory of all the nodes in the linked list\n");
}

void Display(struct ListNode *head){
    struct ListNode *current;
    current = head;
    while(current!=NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL");
}
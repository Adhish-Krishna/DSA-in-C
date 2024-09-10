#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.c"
int main(){
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head = NULL;
    int arr[] = {5,3,1,2,5,1,2,1,3,6,8,9,10,11};
    int len = 14;
    for(int i=0;i<len;i++){
        head = CreateNode(head,arr[i]);
    }
    /*
    struct ListNode *head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head2 = NULL;
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int len1 = 10;
    for(int i=0;i<len1;i++){
        head2 = CreateNode(head2,arr1[i]);
    }

    head = MergeList(head , head2);\
    */

    Display(head);

    // int index = SearchList(head , 9);
    // printf("\n%d",index);

    // UpdateList(head , 10 , 7);
    // printf("\n");
    // Display(head);

    
// Freeing the allocated memory
    int len2 = Len(head);
    printf("\n%d",len2);
    struct ListNode* curr = head;
    struct ListNode* nextnode;
    while(curr!=NULL){
        nextnode = curr->next;
        free(curr);
        curr = nextnode;
    }
/*
    //finding critical points in a linked list
    int *dis = (int*)malloc(2*sizeof(int));
    if(len>=3){
        struct ListNode *prev = head;
        struct ListNode *current = prev->next;
        struct ListNode *nextnode = current->next;
        int count =2;
        int c=0;
        int c1=0;
        int c2=0;
        int c4=0;

        while(nextnode!= NULL){

            if(current->data>prev->data && current->data>nextnode->data){
                printf("\nNode at position %d is a local maxima",count);
                c4=count;
                c++;
            }

            if(current->data<prev->data && current->data<nextnode->data){
                printf("\nNode at position %d is a local minima",count);
                c4=count;
                c++;
            }

            if(c==1){
                c1 = c4;
            }
            if(c==2){
                c2 = c4;
            }

            prev = prev->next;
            current = current->next;
            nextnode = nextnode->next;

            count++;
        }
        dis[0] = c2-c1;
        dis[1] = c4-c1;
        printf("\n%d %d",dis[0],dis[1]);
    }
    free(dis);
*/



    return 0;
}

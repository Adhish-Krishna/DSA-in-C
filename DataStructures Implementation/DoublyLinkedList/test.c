#include<stdio.h>
#include<stdlib.h>
#include"DoublyLinkedList.c"
int main(){

    int choice, value, position;
    Listnode *head = NULL, *tail = NULL;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Create Node\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Update Node\n");
        printf("5. Get Length\n");
        printf("6. Display List\n");
        printf("7. Display List in Reverse\n");
        printf("8. Search Eelement\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                  int data;
                  printf("Enter value to insert: ");
                  scanf("%d", &data);
                  head = CreateNode(head, data);
                  tail = ReturnTail(head);
                }
                break;
            case 2:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = InsertNode(head, position, value);
                tail = ReturnTail(head);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = Delete(head, position);
                tail = ReturnTail(head);
                break;
            case 4:
                printf("Enter position to update: ");
                scanf("%d", &position);
                printf("Enter value to update: ");
                scanf("%d", &value);
                head = UpdateNode(head, position, value);
                break;
            case 5:
                printf("Length of the list: %d\n", Len(head));
                break;
            case 6:
                DisplayList(head);
                break;
            case 7:
                DisplayListReverse(tail);
                break;
            case 8:
                {
                    int target;
                    printf("Enter target element to search:");
                    scanf("%d",&target);
                    int pos = BinarySearch(head , target);
                    if(pos == -1){
                        printf("\nThe element is not found!!");
                    }
                    else{
                    printf("\nTh element is found at position %d",pos);
                    }
                }
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

return 0;
}
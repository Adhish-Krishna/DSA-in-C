#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.c"
int main(){

    int choice, value, position;
    struct ListNode *head = NULL, *head2 = NULL;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Create Node\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Update Node\n");
        printf("5. Get Length\n");
        printf("6. Merge Lists\n");
        printf("7. Merge Sorted Lists\n");
        printf("8. Rotate List\n");
        printf("9. Split List\n");
        printf("10. Display List\n");
        printf("11. Clear Memory\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to create node: ");
                scanf("%d", &value);
                head = CreateNode(head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = InsertNode(head, value, position);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = DeleteNode(head, position);
                break;
            case 4:
                printf("Enter position to update: ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                head = UpdateList(head, value, position);
                break;
            case 5:
                printf("Length of the list: %d\n", Len(head));
                break;
            case 6:
                printf("Creating second list to merge...\n");
                head2 = NULL;
                printf("Enter values for second list (end with -1): ");
                while(1) {
                    scanf("%d", &value);
                    if(value == -1) break;
                    head2 = CreateNode(head2, value);
                }
                head = MergeList(head, head2);
                break;
            case 7:
                printf("Creating second sorted list to merge...\n");
                head2 = NULL;
                printf("Enter values for second sorted list (end with -1): ");
                while(1) {
                    scanf("%d", &value);
                    if(value == -1) break;
                    head2 = CreateNode(head2, value);
                }
                struct ListNode *s;
                head = MergeSortedList(head, head2 , s);
                break;
            case 8:
                printf("Enter number of positions to rotate: ");
                scanf("%d", &position);
                head = RotateList(head, position);
                break;
            case 9:
                {
                int pos;
                printf("Enter position to split: ");
                scanf("%d", &pos);
                printf("Splitting the list...\n");
                struct ListNode *head2;
                head2 = SplitList(head , head2 , pos);
                printf("First half: ");
                Display(head);
                printf("Second half: ");
                Display(head2);
                }
                break;
            case 10:
                Display(head);
                break;
            case 11:
                ClearMemory(head);
                head = NULL;
                printf("Memory cleared.\n");
                break;
            case 12:
                ClearMemory(head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

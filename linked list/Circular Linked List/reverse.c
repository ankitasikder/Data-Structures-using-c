/**
 * C program to reverse a Circular Linked List
 */

#include <stdio.h>
#include <stdlib.h>


/* Basic node structure */
struct node {
    int data;
    struct node * next;
};


/* Function declaration */
void createList(struct node **head, int n);
void displayList(struct node *head);
void reverseList(struct node **head);


int main()
{
    int n, choice;

    struct node *head = NULL;

    /*
     * Run forever until user chooses 0
     */
    while(choice != 0)
    {
        printf("--------------------------------------------\n");
        printf("        CIRCULAR LINKED LIST PROGRAM        \n");
        printf("--------------------------------------------\n");
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Reverse list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter total node to create: ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            
            case 2:
                displayList(head);
                getchar(); // Hold screen
                getchar(); // Hold screen
                break;
            
            case 3:
                reverseList(&head);
                printf("List reversed.\n");
				getchar(); // Hold screen
                getchar(); // Hold screen
                break;

            case 0:
                printf("Exiting from application");
                exit(0);
                break;

            default:
                printf("Error! Invalid choice. Please choose between 0-3");
        }

        printf("\n\n");
    }

    return 0;
}



/**
 * Reverses a circular linked list.
 */
void reverseList(struct node **head) 
{
    // Temporary helper variables
    struct node *prev, *cur, *next, *last;

    // Cannot reverse empty list
    if (*head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }


    // Head is going to be our last node after reversing list
    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

    // Iterate till you reach the initial node in circular list
    while (*head != last)
    {
        *head = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }

    cur->next = prev;
    *head = prev;       // Make last node as head
}



/**
 * Creates a circular linked list of n nodes.
 */
void createList(struct node **head, int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    prevNode = NULL;
    newNode  = NULL;


    /* Creates and links rest of the n-1 nodes */
    for(i=1; i<=n; i++)
    {
        // Create a new node
        newNode = (struct node *) malloc(sizeof(struct node));

        printf("Enter data of %d node: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        // Link the previous node with newly created node
        if (prevNode != NULL)
            prevNode->next = newNode;

        // Move the previous node ahead
        prevNode = newNode;

        // Link head node if not linked
        if (*head == NULL)
            *head = newNode;
    }

    // Link last node with first node
    prevNode->next = *head;

    printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
}


/**
 * Display node content of circular linked list
 */
void displayList(struct node *head)
{
    struct node *current;
    int n = 1;

    // Nothing to print in list
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }


    current = head;
    printf("DATA IN THE LIST:\n");

    do 
    {
        // Print current node
        printf("Data %d = %d\n", n++, current->data);

        // Move to next node
        current = current->next;
    } while (current != head);
}

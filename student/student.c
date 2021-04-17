#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    char name[50];
    int id;
    int birthdate[3];
    int score;
};

struct Node
{
    struct Student* data;
    struct Node* next;
};

struct Student* readStudent(int i)
{
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    printf("\nPlease Insert Student %d\n", i + 1);

    printf("Enter name: ");
    scanf("%s", student->name);

    printf("Enter ID: ");
    scanf("%d", &student->id);

    printf("Enter Birthday: ");
    scanf("%d/%d/%d", &student->birthdate[0], &student->birthdate[1], &student->birthdate[2]);

    printf("Enter Score: ");
    scanf("%d", &student->score);

    return student;
};

void insertBeginningLinkedList(struct Node** head, struct Student* student)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = student;
    newNode->next = *head;
    *head = newNode;
}

void insertEndLinkedList(struct Node** tail, struct Student* student)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = student;
    newNode->next = NULL;
    (*tail)->next = newNode;
    *tail = newNode;
}

void insertPosLinkedList(struct Node* head, struct Student* student, int pos)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = student;

    struct Node* current = head;
    int currentPos = 0;
    while(current->next && currentPos < pos - 1)
    {
        current = current->next;
        currentPos++;
    }

    if(currentPos < pos -1) {
        printf("\nThe position you entered doesn't exist.\nInserting at the end...\n\n");
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printListLinkedList(struct Node* head)
{
    struct Node* current = head;
    printf("\nList of Students: \n");
    while(current)
    {
        printf("%d", current->data->id);
        printf(" %s", current->data->name);
        printf(" %d/%d/%d", current->data->birthdate[0], current->data->birthdate[1], current->data->birthdate[2]);
        printf(" %d\n", current->data->score);
        current = current->next;
    }
    printf("\n");
}

void startLinkedList() {

    int N;
    printf("Enter Number of students: ");
    scanf("%d", &N);

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = head;
    struct Student* student = readStudent(0);
    head->data = student;
    head->next = NULL;

    int i = 1;
    while(i < N)
    {
        struct Student* student = NULL;
        char choice;
        int pos;
        printf("\nChoose Where you want to insert student %d: \na. At the beginning\nb. At position i\nc. At the end\n", i + 1 );
        printf("Enter Choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            student = readStudent(i);
            insertBeginningLinkedList(&head, student);
            break;
        case 'b':
            printf("Enter Position: ");
            scanf("%d", &pos);
            student = readStudent(i);
            insertPosLinkedList(head, student, pos);
            break;
        case 'c':
            student = readStudent(i);
            insertEndLinkedList(&tail, student);
            break;
        default:
            printf("Invalid choice\n");
            i--;
        }
        i++;
        printListLinkedList(head);
    }
}

int main()
{
    printf(" Welcome \n");

    startLinkedList();

    return 0;
}


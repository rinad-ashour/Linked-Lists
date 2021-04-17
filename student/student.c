#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[50];
    int id;
    int birthdate[3];
    int score;
};

struct student* readStudent(int i)
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
}

void insertBeginningDynamicArray(struct Student* ptr, struct Student* newStud, int N)
{
    int k;
    for(k=N-1; k>=0; k--)
    {
        *(ptr+k+1)= *(ptr+k);
    }
    *(ptr + 0) = *newStud;
}

void insertEndDynamicArray(struct Student* ptr, struct Student* newStud, int lastIndex)
{
    *(ptr+lastIndex) = *newStud;
}

void insertPosDynamicArray(struct Student* ptr, struct Student* newStud, int N,int i)
{
    int k;
    for(k=N-1; k>=i; k--)
    {
        *(ptr+k+1)= *(ptr+k);
    }
    *(ptr + i) = *newStud;
}

void printListDynamicArray(struct Student* ptr,int N)
{
    struct Student* current = NULL;
    printf("\nList of Students: \n");
    int i=0;
    while(i<N)
    {
        current = (ptr + i);
        printf("%d", current->id);
        printf(" %s", current->name);
        printf(" %d/%d/%d", current->birthdate[0], current->birthdate[1], current->birthdate[2]);
        printf(" %d\n", current->score);
        i++;
    }
    printf("\n");
}

void startDynamicArray() {
    int N,i;
    printf(" Enter Number of students: ");
    scanf("%d", &N);
    struct Student* ptr=(struct Student*)calloc(N, sizeof(struct Student));
    for (i=0; i<N; i++)
    {
        struct Student* newStud;
        if(i == 0)
        {
            newStud = readStudent(i);
            *(ptr+i) = *newStud;
        }
        else
        {
            char choice;
            int pos;
            printf("Choose Where you want to insert: \na. At the beginning\nb. At position i\nc. At the end\n");
            printf("Enter Choice: ");
            scanf(" %c", &choice);
            switch (choice)
            {
            case 'a':
                newStud = readStudent(i);
                insertBeginningDynamicArray(ptr, newStud, N);
                break;
            case 'b':
                printf("Enter Position: ");
                scanf("%d", &pos);
                newStud = readStudent(i);
                insertPosDynamicArray(ptr, newStud, N, pos);
                break;
            case 'c':
                newStud = readStudent(i);
                insertEndDynamicArray(ptr, newStud, i);
                break;
            default:
                printf("Invalid choice\n");
            }
        }
        printListDynamicArray(ptr, i+1);
    }
    free(ptr);
}

int main()
{
    printf(" Welcome \n");

    startDynamicArray();

    return 0;
}



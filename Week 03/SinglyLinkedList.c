#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Student {
    char name[3000];
    int ID;
    float CGPA;
    struct Student *next;
} Student;

Student *head = NULL;

void insert(int position, char *name, int ID, float CGPA) {
    Student *newStudent = (Student *)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->ID = ID;
    newStudent->CGPA = CGPA;

    if (position == 1 || head == NULL) {
        newStudent->next = head;
        head = newStudent;
    }
    
    else {
        Student *temp = head;
        for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        newStudent->next = temp->next;
        temp->next = newStudent;
    }
}

int find(char *name) {
    Student *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    
    return -1;
}

int delete(char *name) {
    int position = find(name);
    if (position == -1) {
        return -1;
    }

    Student *temp = head;
    if (position == 1) {
        head = head->next;
        free(temp);
        }
        
    else {
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        Student *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
    
    return 0;
}

Student* get(int position) {
    if (position < 1) {
        return NULL;
    }
    
    Student *temp = head;
    
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    return temp;
}

void display() {
    Student *temp = head;
    
    while (temp != NULL) {
        printf("Name: %s, ID: %d, CGPA: %.2f\n", temp->name, temp->ID, temp->CGPA);
        temp = temp->next;
    }
}

int size() {
    int count = 0;
    Student *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int isEmpty() {
    return head == NULL ? 1 : 0;
}

bool menu() {
    printf("\n\t\tMain Menu\n1. Insert records\n2. Display all Records\n3. Delete Records\n4. Size\n5. Check if list = empty\n6. Exit\nEnter your choice: ");
    int user_option = 0;
    scanf("%d", &user_option);

    if (user_option == 1) {
        int x;

        printf("Enter the number of students: ");
        scanf("%d", &x);
        getchar(); 

        for (int i = size(); i < x + size(); i++) {
            int idno;
            float cgpa;
            char name[3000];

            printf("Enter the name of the student: ");
            getchar(); 
            fgets(name, sizeof(name), stdin);

            printf("Enter the roll number: ");
            scanf("%d", &idno);
            getchar(); 

            printf("Enter the CGPA for the student: ");
            scanf("%f", &cgpa);

            insert(i, name, idno, cgpa);
        }
        return true;
    }

    else if (user_option == 2) {
        display();
        return true;
    }

    else if (user_option == 3) {
        printf("Enter the name of the student whose records should be deleted: ");
        char stu_name[3000];
        getchar(); 
        fgets(stu_name, sizeof(stu_name), stdin);
        delete(stu_name);
        return true;
    }

    else if (user_option == 4) {
        printf("The number of records is: %d", size());
        return true;
    }

    else if (user_option == 5) {
        printf("Is list empty? %s\n", isEmpty() ? "Yes" : "No");
        return true;
    }

    else if (user_option == 6) {
        return false;
    }
}

int main() {
    int x;
    printf("Enter the number of students: ");
    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        int idno;
        float cgpa;
        char name[3000];
        
        printf("\nEnter the name of the student: ");
        getchar(); 
        fgets(name, sizeof(name), stdin);

        printf("\nEnter the roll number: ");
        scanf("%d", &idno);
        getchar(); 

        printf("\nEnter the CGPA for the student: ");
        scanf("%f", &cgpa);

        insert(i, name, idno, cgpa);
    }

    bool var = true;
    while (var) {
        var = menu();
    }

    return 0;
}

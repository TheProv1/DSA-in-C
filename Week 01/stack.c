#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RECORDS 5
#define MAX_LENGTH_ID 20
#define MAX_LENGTH_NAME 50
#define MAX_LENGTH_DOB 20

char id[MAX_RECORDS][MAX_LENGTH_ID];
char name[MAX_RECORDS][MAX_LENGTH_NAME];
char dob[MAX_RECORDS][MAX_LENGTH_DOB];
float cgpa[MAX_RECORDS];
int top = -1;

bool underflow() {
    return top == -1;
}

bool overflow() {
    return top == MAX_RECORDS - 1;
}

void PUSH_operation(char new_id[], char new_name[], char new_dob[], float new_cgpa) {
    if (!overflow()) {
        top++;
        strcpy(id[top], new_id);
        strcpy(name[top], new_name);
        strcpy(dob[top], new_dob);
        cgpa[top] = new_cgpa;
    } else {
        printf("Cannot PUSH element, OVERFLOW condition\n");
    }
}

void POP_operation() {
    if (!underflow()) {
        top--;
    } else {
        printf("Cannot POP element, UNDERFLOW condition\n");
    }
}

void DISPLAY() {
    printf("Test Output:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s %s %s %.2f\n", id[i], name[i], dob[i], cgpa[i]);
    }
}

int main() {
    FILE *rP = fopen("studentin.dat", "r");
    FILE *wP = fopen("studentout.dat", "w");

    if (rP == NULL) {
        printf("File does not exist\n");
        return 1;
    }

    char new_id[MAX_LENGTH_ID], new_name[MAX_LENGTH_NAME], new_dob[MAX_LENGTH_DOB];
    float new_cgpa;

    while (fscanf(rP, "%s %s %s %f", new_id, new_name, new_dob, &new_cgpa) == 4) {
        PUSH_operation(new_id, new_name, new_dob, new_cgpa);
    }

    DISPLAY();

    fclose(rP);
    fclose(wP);
    return 0;
}

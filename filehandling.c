#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main(){

    /*Create a file studentout1.dat and write user input data
    "Implementing DS would be fun"
    into this file*/

    FILE *wF = fopen64("studentout1.dat", "w");
    
    fprintf(wF, "Implementing DS would be fun");
    fprintf(wF, "\n");
        
    fclose(wF);

    /*Read the contents of the file studentout1.dat and display it on the console*/

    FILE *rP = fopen64("studentout1.dat", "r");
    char buffer[2000];

    if (rP == NULL){
        printf("File does not exist");
    }

    else{
        while (fgets(buffer, 2000, rP) != NULL){
            printf("%s", buffer);
        }
    }

    fclose(rP);

    /*Append atleast 3 more user input lines into studentout1.dat*/

    FILE *aF = fopen64("studentout1.dat", "a");

    char input_string_1[3000];
    char input_string_2[3000];
    char input_string_3[3000];

    printf("Enter the first line of text: ");
    scanf("%s", input_string_1);

    printf("Enter the second line of text: ");
    scanf("%s", input_string_2);

    printf("Enter the last line of text: ");
    scanf("%s", input_string_3);

    fprintf(aF, input_string_1);
    fprintf(aF, "\n");

    fprintf(aF, input_string_2);
    fprintf(aF, "\n");
    
    fprintf(aF, input_string_3);
    fprintf(aF, "\n");
    
    fclose(aF);
    
    /*Copy the content from studentout1.dat to studentout2.dat*/

    FILE *rfP = fopen64("studentout1.dat", "r");
    FILE *wfP = fopen64("studentout2.dat", "w");
    
    char readfilecontents[10000];

    while(fgets(readfilecontents, 10000, rfP) != NULL){
        fprintf(wfP, readfilecontents);
    }
    
    fclose(rfP);
    fclose(wfP);

    /*Count characters, words and lines in the studentout2.dat*/

    FILE *crfP = fopen64("studentout2.dat","r");

    int countlines = 0, countwords = 0, countcharacters = 0;
    char storedfilecontent[10000];

    while(fgets(storedfilecontent, 10000, crfP) != NULL){
        countlines += 1;
        countcharacters += strlen(storedfilecontent);
        
        bool isword = false;
        for (int i = 0; storedfilecontent[i] != '\0'; i++){
            if (storedfilecontent[i] == ' ' || storedfilecontent[i] == '\t' || storedfilecontent[i] == '\n'){
                isword = false;
            }
            else{
                if (!isword){
                    countwords += 1;
                    isword = true;
                }
            }
        }
    }

    printf("\nThe number of lines are: %d\nThe number of words are: %d\nThe number of characters are: %d", countlines, countwords, countcharacters);

    fclose(crfP);
}
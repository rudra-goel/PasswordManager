#include <stdio.h>
#include <stdbool.h>  
#include <string.h>


void accessReccords();
void enterReccord();


int main(){

    bool condition = true;
    printf("\nWelcome to Password Manager.");
    while(condition){
        char answer[50];
        printf("\n----------------------------------------------------------------\n");
        printf("|\t\t   Choose an option below.\t\t       |");
        printf("\n----------------------------------------------------------------\n");
        printf("\n\nAccess your stored passwords (a)\nEnter new password (e)\nQuit program (q)\n>>> ");
        scanf("%s", answer);
        // printf("\n\n%s", answer);

        if(strcmp(answer, "a") == 0){
            accessReccords();
        } else if(strcmp(answer, "e") == 0){
            enterReccord();
        } else if (strcmp(answer, "q") == 0){
            condition = false;
        }
    }

    return 0;
}

void accessReccords(){
    FILE *fptr;
    fptr = fopen("/Users/rgoel/downloads/c-code/pass-mgr/passwords.txt","r");
    if (fptr == NULL){
        printf("\n**Could not access passwords**\n");
    } else {
        printf("\n----------------------------------------------------------------\n");
        printf("|\t\t\tStored Reccords\t\t\t       |");
        printf("\n----------------------------------------------------------------\n");
        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];
        while (fgets(buffer, MAX_LENGTH, fptr)){
            printf("\n");
            printf("--> %s", buffer);
            
        }
    }
    fclose(fptr);
}

void enterReccord(){
    FILE *fptr;
    fptr = fopen("/Users/rgoel/downloads/c-code/pass-mgr/passwords.txt","a");
    if (fptr == NULL){
        printf("\n**Could not access passwords**\n");
    } else {
        char reccordName[50];
        char userName[50];
        char password[50];
        char buffer[256];

        printf("\nEnter the name of this reccord >>> ");
        scanf("%s", reccordName);
        
        printf("Username >>> ");
        scanf("%s", userName);
        
        printf("Password >>> ");
        scanf("%s", password);

        sprintf(buffer, "%s: username=%s | password=\"%s\"", reccordName, userName, password);
        fprintf(fptr, "\n");
        fprintf(fptr, buffer);

        printf("\nEntered reccord %s ", buffer);

    }
    fclose(fptr);
}
#include <stdio.h>
#include <stdbool.h>  
#include <string.h>
#include <stdlib.h>


void accessReccords(char path[256]);
void enterReccord(char path[256]);
void encryptReccord(char reccorc[256]);
void decryptReccord(char reccorc[256]);
bool checkEntry(char buffer[256]);


int main(){

    bool condition = true;
    system("clear");
    printf("\n----------------------------------------------------------------");
    printf("\n|                                                              |");
    printf("\n|\t\tWelcome to Password Manager\t\t       |\n");
    printf("|                                                              |");
    char path[] = "/Users/rgoel/desktop/passwords.txt";
    while(condition){
        char answer[50];
        printf("\n----------------------------------------------------------------\n");
        printf("|\t\t   Choose an Option Below\t\t       |");
        printf("\n----------------------------------------------------------------\n");
        printf("|  Access your stored passwords (a)");
        printf("\n|  Enter new password (e)");
        printf("\n|  Quit program (q)");
        printf("\n\n>>> ");
        scanf("%s", answer);
        // printf("\n\n%s", answer);

        if(strcmp(answer, "a") == 0){
            accessReccords(path);
        } else if(strcmp(answer, "e") == 0){
            enterReccord(path);
        } else if (strcmp(answer, "q") == 0){
            system("clear");
            condition = false;
        }
    }

    return 0;
}

void accessReccords(char path[256]){
    FILE *fptr;
    fptr = fopen(path,"r");
    if (fptr == NULL){
        printf("\n**Could not access passwords**\n");
    } else {
        printf("\n*********************** Stored Reccords ***********************\n");
        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];
        while (fgets(buffer, MAX_LENGTH, fptr)){
            decryptReccord(buffer);
            printf("\n");
            printf("--> %s", buffer);
            
        }
    }
    printf("\n");
    fclose(fptr);
}

void enterReccord(char path[256]){
    FILE *fptr;
    fptr = fopen(path,"a");
    if (fptr == NULL){
        printf("\n**Could not access passwords**\n");
    } else {
        char reccordName[50];
        char userName[50];
        char password[50];
        char buffer[256];
        char confirm[50];

        printf("\nEnter the name of this reccord >>> ");
        scanf("%s", reccordName);
        
        printf("Username >>> ");
        scanf("%s", userName);
        
        printf("Password >>> ");
        scanf("%s", password);

        sprintf(buffer, "%s: username=\"%s\" | password=\"%s\"", reccordName, userName, password);

        while(checkEntry(buffer) == false){
            printf("\nEnter the name of this reccord >>> ");
            scanf("%s", reccordName);
            
            printf("Username >>> ");
            scanf("%s", userName);
            
            printf("Password >>> ");
            scanf("%s", password);

            sprintf(buffer, "%s: username=\"%s\" | password=\"%s\"", reccordName, userName, password);
        }

        encryptReccord(buffer);

        fprintf(fptr, "\n");
        fprintf(fptr, buffer);
        decryptReccord(buffer);
        printf("\nEntered reccord %s ", buffer);

    }
    printf("\n");
    fclose(fptr);
}

void encryptReccord(char reccord[256]){
    
    for(int i = 0; i < strlen(reccord); i++){
        reccord[i] = reccord[i]+100;
    }

}
void decryptReccord(char reccord[256]){
    
    for(int i = 0; i < strlen(reccord); i++){
        reccord[i] = reccord[i]-100;
    }

}

bool checkEntry(char buffer[256]){
    char confirm[50];
    printf("Correct (enter)/Incorrect (q)? %s\n>>> ", buffer);
    scanf("%s", confirm);

    if(strcmp(confirm, "q") == 0){
        return false;
    }
    return true;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX_USERS 5 
#define MAX_FILES 5 
#define MAX_NAME_LEN 20 
 
// Structure for a file 
typedef struct { 
    char name[MAX_NAME_LEN]; 
    int size; // Size of the file in bytes 
} File; 
 
// Structure for a user directory 
typedef struct { 
    char userName[MAX_NAME_LEN]; 
    File files[MAX_FILES]; 
    int fileCount; 
} UserDirectory; 
 
// Root directory containing user directories 
UserDirectory rootDir[MAX_USERS]; 
int userCount = 0; 
 
// Function to create a new user directory 
void createUserDirectory(char *userName) { 
    if (userCount < MAX_USERS) { 
        strcpy(rootDir[userCount].userName, userName); 
        rootDir[userCount].fileCount = 0; 
        userCount++; 
        printf("User directory '%s' created.\n", userName); 
    } else { 
        printf("Cannot create user directory. Max limit reached.\n"); 
    } 
} 
 
// Function to create a file in a user's directory 
void createFile(char *userName, char *fileName, int size) { 
    for (int i = 0; i < userCount; i++) { 
        if (strcmp(rootDir[i].userName, userName) == 0) { 
            if (rootDir[i].fileCount < MAX_FILES) { 
                File *newFile = &rootDir[i].files[rootDir[i].fileCount++]; 
                strcpy(newFile->name, fileName); 
                newFile->size = size; 
                printf("File '%s' created in user directory '%s'.\n", fileName, userName); 
                return; 
            } else { 
                printf("Cannot create file. Max files limit reached in '%s' directory.\n", userName); 
                return; 
            } 
        } 
    } 
    printf("User directory '%s' not found.\n", userName); 
} 
 
// Function to display all files in a user's directory 
void displayFiles(char *userName) { 
    for (int i = 0; i < userCount; i++) { 
        if (strcmp(rootDir[i].userName, userName) == 0) { 
            printf("Files in user directory '%s':\n", userName); 
            for (int j = 0; j < rootDir[i].fileCount; j++) { 
                printf("  %s (%d bytes)\n", rootDir[i].files[j].name, rootDir[i].files[j].size); 
            } 
            return; 
        } 
    } 
    printf("User directory '%s' not found.\n", userName); 
} 
 
// Function to display all user directories and files 
void displayAll() { 
    printf("Root Directory:\n"); 
    for (int i = 0; i < userCount; i++) { 
        printf("User Directory: %s\n", rootDir[i].userName); 
        for (int j = 0; j < rootDir[i].fileCount; j++) { 
            printf("  File: %s (%d bytes)\n", rootDir[i].files[j].name, rootDir[i].files[j].size); 
        } 
    } 
} 
 
int main() { 
    createUserDirectory("user1"); 
    createUserDirectory("user2"); 
 
    createFile("user1", "file1.txt", 100); 
    createFile("user1", "file2.txt", 200); 
    createFile("user2", "fileA.txt", 150); 
 
    printf("\nDisplaying files in user1's directory:\n"); 
    displayFiles("user1"); 
 
    printf("\nDisplaying all directories and files:\n"); 
    displayAll(); 
 
    return 0; 
} 
 


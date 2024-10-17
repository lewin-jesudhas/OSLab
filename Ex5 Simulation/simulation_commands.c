#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int choice;
    char str1[50], str2[50], str3[50];

    printf("\nEnter your choice:\n");
    printf("1. ls\n");
    printf("2. cat\n");
    printf("3. cp\n");
    printf("4. grep\n");
    printf("5. stat\n");
    printf("6. ps\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // ls command
            printf("\nEnter your option (e.g., directory name or option):\n");
            scanf("%s", str1);
            execlp("ls", "ls", str1, NULL);
            perror("execlp failed"); // Will execute if execlp fails
            break;

        case 2: // cat command
            printf("Enter name of file 1:\n");
            scanf("%s", str1);
            printf("Enter name of file 2:\n");
            scanf("%s", str2);
            printf("Enter name of file 3 (optional):\n");
            scanf("%s", str3);
            execlp("cat", "cat", str1, str2, str3, NULL);
            perror("execlp failed"); // Will execute if execlp fails
            break;

        case 3: // cp command
            printf("\nEnter the source filename:\n");
            scanf("%s", str1);
            printf("\nEnter the destination filename:\n");
            scanf("%s", str2);
            execlp("cp", "cp", str1, str2, NULL); // Using cp to copy files
            perror("execlp failed"); // Will execute if execlp fails
            break;

        case 4: // grep command
            printf("\nEnter the pattern to search:\n");
            scanf("%s", str1);
            printf("\nEnter the filename to search in:\n");
            scanf("%s", str2);
            execlp("grep", "grep", str1, str2, NULL); // Using grep to search for a pattern
            perror("execlp failed"); // Will execute if execlp fails
            break;

        case 5: // stat command
            printf("\nEnter the filename to get statistics:\n");
            scanf("%s", str1);
            execlp("stat", "stat", str1, NULL); // Using stat to display file information
            perror("execlp failed"); // Will execute if execlp fails
            break;

        case 6: // ps command
            execlp("ps", "ps", NULL); // Using ps to list processes
            perror("execlp failed"); // Will execute if execlp fails
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

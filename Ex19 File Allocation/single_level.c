#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h> 
#include <sys/stat.h> 
#include <string.h> 
 
void list_directory(const char *path) { 
 struct dirent *entry; 
 DIR *dir = opendir(path); 
 
 // Return if directory cannot be opened 
 if (!dir) { 
     perror("Unable to open directory"); 
     return; 
 } 
 
 printf("Contents of directory: %s\n", path); 
 
 // Iterate through each entry in the directory 
 while ((entry = readdir(dir)) != NULL) { 
     // Skip "." and ".." directories 
     if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) { 
         continue; 
     } 
 
     // Print entry name 
     printf("|-- %s\n", entry->d_name); 
 } 
 
 closedir(dir); 
} 
 
int main(int argc, char *argv[]) { 
 const char *path; 
 
 // Check if directory path is provided as an argument 
 if (argc < 2) { 
     path = ".";  // Default to current directory 
 } else { 
     path = argv[1]; 
 } 
 
 list_directory(path); 
 
 return 0; 
}

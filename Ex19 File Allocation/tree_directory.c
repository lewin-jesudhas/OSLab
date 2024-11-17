#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <dirent.h> 
#include <sys/stat.h> 
 
void print_directory_tree(const char *base_path, int depth) { 
 struct dirent *entry; 
 DIR *dir = opendir(base_path); 
 
 // Return if directory cannot be opened 
 if (!dir) { 
     return; 
 } 
 
 while ((entry = readdir(dir)) != NULL) { 
     // Skip "." and ".." directories 
     if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) { 
         continue; 
     } 
 
     // Print indentation based on depth level 
     for (int i = 0; i < depth; i++) { 
         printf("  "); 
     } 
 
     printf("|-- %s\n", entry->d_name); 
 
     // Check if entry is a directory 
     char path[1024]; 
     struct stat statbuf; 
     snprintf(path, sizeof(path), "%s/%s", base_path, entry->d_name); 
     if (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) { 
         // Recursive call with increased depth 
         print_directory_tree(path, depth + 1); 
     } 
 } 
 closedir(dir); 
} 
 
int main(int argc, char *argv[]) { 
 // Check if directory path is provided as an argument 
 const char *path; 
 if (argc < 2) { 
     path = ".";  // Default to current directory 
 } else { 
     path = argv[1]; 
 } 
 
 printf("%s\n", path); 
 print_directory_tree(path, 0); 
 
 return 0; 
}

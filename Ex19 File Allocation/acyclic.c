#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX_NAME_LEN 50 
#define MAX_CHILDREN 10 
 
typedef enum { FILE_TYPE, DIRECTORY_TYPE } NodeType; 
 
typedef struct Node { 
    char name[MAX_NAME_LEN]; 
    NodeType type; 
    struct Node *children[MAX_CHILDREN]; 
    int childCount; 
} Node; 
 
// Root directory 
Node *root; 
 
// Function to create a new node (file or directory) 
Node* createNode(const char *name, NodeType type) { 
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    strcpy(newNode->name, name); 
    newNode->type = type; 
    newNode->childCount = 0; 
    return newNode; 
} 
 
// Function to add a child to a directory node 
void addChild(Node *parent, Node *child) { 
    if (parent->type != DIRECTORY_TYPE) { 
        printf("Error: Cannot add a child to a file.\n"); 
        return; 
    } 
    if (parent->childCount < MAX_CHILDREN) { 
        parent->children[parent->childCount++] = child; 
        printf("Added '%s' to directory '%s'.\n", child->name, parent->name); 
    } else { 
        printf("Error: Maximum children limit reached for '%s'.\n", parent->name); 
    } 
} 
 
// Function to create a link to an existing node (like a shortcut) 
void createLink(Node *parent, Node *existingNode) { 
    addChild(parent, existingNode); 
} 
 
// Function to print the directory structure 
void printStructure(Node *node, int level) { 
    for (int i = 0; i < level; i++) printf("  "); 
    printf("|-- %s\n", node->name); 
    if (node->type == DIRECTORY_TYPE) { 
        for (int i = 0; i < node->childCount; i++) { 
            printStructure(node->children[i], level + 1); 
        } 
    } 
} 
 
int main() { 
    // Initialize root directory 
    root = createNode("root", DIRECTORY_TYPE); 
 
    // Create directories and files 
    Node *home = createNode("home", DIRECTORY_TYPE); 
    Node *user = createNode("user", DIRECTORY_TYPE); 
    Node *docs = createNode("docs", DIRECTORY_TYPE); 
    Node *file1 = createNode("file1.txt", FILE_TYPE); 
    Node *file2 = createNode("file2.txt", FILE_TYPE); 
 
    // Build the structure 
    addChild(root, home); 
    addChild(home, user); 
    addChild(user, docs); 
    addChild(docs, file1); 
    addChild(docs, file2); 
 
    // Create a link to 'docs' from 'home' (creates acyclic graph) 
    createLink(home, docs); 
 
    // Print the file system structure 
    printf("File System Structure:\n"); 
    printStructure(root, 0); 
 
    return 0; 
} 

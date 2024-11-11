#include <stdio.h> 
#include <string.h> 
 
// Structure to represent a process 
typedef struct { 
    int id;         // Process ID 
    int size;       // Size of the process 
} Process; 
 
// Function to allocate memory to blocks as per first fit algorithm 
void firstFit(int blockSize[], int m, Process processes[], int n) { 
    int allocation[n]; // Stores block id of the block allocated to a process 
    memset(allocation, -1, sizeof(allocation)); // Initially, no block is assigned to any process 
 
    // Pick each process and find the first suitable block according to its size 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (blockSize[j] >= processes[i].size) { 
                allocation[i] = j; // Allocate block to process 
                blockSize[j] -= processes[i].size; // Reduce available memory in this block 
                break; // Move to the next process 
            } 
        } 
    } 
 
    // Print the allocation results 
    printf("\nProcess ID\tProcess Size\tBlock No.\n"); 
    for (int i = 0; i < n; i++) { 
        printf(" %d\t\t%d\t\t", processes[i].id, processes[i].size); 
        if (allocation[i] != -1) { 
            printf("%d", allocation[i] + 1); // Print block number (1-indexed) 
        } else { 
            printf("Not Allocated"); 
        } 
        printf("\n"); 
    } 
} 
 
// Driver code 
int main() { 
    int blockSize[] = {100, 500, 200, 300, 600}; // Sizes of memory blocks 
    Process processes[] = {{1, 212}, {2, 417}, {3, 112}, {4, 426}}; // Processes with sizes 
    int m = sizeof(blockSize) / sizeof(blockSize[0]); 
    int n = sizeof(processes) / sizeof(processes[0]); 
 
    firstFit(blockSize, m, processes, n); 
 
    return 0; 
} 
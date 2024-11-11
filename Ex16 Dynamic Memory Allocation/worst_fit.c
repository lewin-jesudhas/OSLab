#include <stdio.h> 
#include <stdlib.h> 
#define MAX_BLOCKS 10 // Maximum number of memory blocks 

// Structure to represent a memory block 
struct MemoryBlock { 
    int size; 
    int originalSize; // To store the initial size of the block 
    int isAllocated; 
}; 

void worstFitAllocate(int processSize, struct MemoryBlock blocks[], int n) { 
    int worstIndex = -1; 
    // Find the index of the worst (largest) block that can fit the process 
    for (int i = 0; i < n; i++) { 
        if (!blocks[i].isAllocated && blocks[i].size >= processSize) { 
            if (worstIndex == -1 || blocks[i].size > blocks[worstIndex].size) { 
                worstIndex = i; 
            } 
        }
    }  // Close the loop here

    // If a suitable block was found, allocate it 
    if (worstIndex != -1) { 
        blocks[worstIndex].isAllocated = 1; 
        printf("Process of size %d allocated to block %d with size %d\n", 
               processSize, worstIndex + 1, blocks[worstIndex].originalSize); 
        blocks[worstIndex].size -= processSize; // Reduce block size by allocated process size 
    } else { 
        printf("No suitable block found for process of size %d\n", processSize); 
    } 
}

int main() { 
    int n, m; 

    printf("Enter the number of memory blocks: "); 
    scanf("%d", &n); 
    struct MemoryBlock blocks[MAX_BLOCKS]; 

    // Input block sizes 
    for (int i = 0; i < n; i++) { 
        printf("Enter size of block %d: ", i + 1); 
        scanf("%d", &blocks[i].size); 
        blocks[i].originalSize = blocks[i].size; // Store the original size of the block 
        blocks[i].isAllocated = 0; // Initially, no blocks are allocated 
    } 

    printf("Enter the number of processes: "); 
    scanf("%d", &m); 
    int processSizes[m]; 

    // Input process sizes 
    for (int i = 0; i < m; i++) { 
        printf("Enter size of process %d: ", i + 1); 
        scanf("%d", &processSizes[i]); 
    } 

    // Allocate memory to processes using the Worst Fit algorithm 
    for (int i = 0; i < m; i++) { 
        worstFitAllocate(processSizes[i], blocks, n); 
    } 

    // Display remaining block sizes 
    printf("\nRemaining block sizes:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Block %d: %d\n", i + 1, blocks[i].size); 
    } 

    return 0; 
}

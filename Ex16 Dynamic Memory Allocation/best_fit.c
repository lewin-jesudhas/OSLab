#include <stdio.h> 
#define MAX_BLOCKS 100 
  
typedef struct { 
    int size;   // Size of the memory block 
    int isFree; // 1 if free, 0 if allocated 
} MemoryBlock; 
  
MemoryBlock blocks[MAX_BLOCKS]; // Array to hold memory blocks 
int blockCount;                  // Number of memory blocks 
  
// Function to allocate memory using the best fit algorithm 
void bestFitAllocate(int requestSize) { 
    int bestIndex = -1; // Index of the best block found 
    int minSize = 9999; // A large number to compare 
  
    printf("\nRequesting %d KB of memory...\n", requestSize); 
    printf("Available Memory Blocks:\n"); 
    for (int i = 0; i < blockCount; i++) { 
        printf("Block %d: Size = %d KB, Status = %s\n",  
               i,  
               blocks[i].size,  
               blocks[i].isFree ? "Free" : "Allocated"); 
    } 
  
    // Iterate through the blocks to find the best fit 
    for (int i = 0; i < blockCount; i++) { 
        // Check if the block is free and large enough 
        if (blocks[i].isFree && blocks[i].size >= requestSize) { 
            if (blocks[i].size < minSize) { 
                minSize = blocks[i].size; // Update minSize 
                bestIndex = i;            // Update bestIndex 
            } 
        } 
    } 
  
    // Allocate if a suitable block was found 
    if (bestIndex != -1) { 
        blocks[bestIndex].isFree = 0; // Mark as allocated 
        printf("Best fit found at Block %d (Size = %d KB)\n", bestIndex, 
blocks[bestIndex].size); 
  
        // If the block is larger than requested, split it 
        if (blocks[bestIndex].size > requestSize) { 
            printf("Allocating %d KB from Block %d, remaining size will be %d KB\n",  
                   requestSize,  
                   bestIndex,  
                   blocks[bestIndex].size - requestSize); 
            blocks[bestIndex].size -= requestSize; // Reduce size of the block 
        } else { 
            printf("Allocating entire Block %d (Size = %d KB)\n",  
                   bestIndex,  
                   blocks[bestIndex].size); 
            blocks[bestIndex].size = 0; // Block is fully allocated 
        } 
    } else { 
        printf("No suitable block found for %d KB request\n", requestSize); 
    } 
} 
// Example usage 
int main() { 
    // Initialize blocks 
    blockCount = 5; 
    blocks[0] = (MemoryBlock){100, 1}; // Block 1 
    blocks[1] = (MemoryBlock){500, 1}; // Block 2 
    blocks[2] = (MemoryBlock){200, 1}; // Block 3 
    blocks[3] = (MemoryBlock){300, 1}; // Block 4 
    blocks[4] = (MemoryBlock){600, 1}; // Block 5 
    // Request memory allocations 
    bestFitAllocate(212); // Allocate 212 KB 
    bestFitAllocate(100);  // Allocate 100 KB 
    bestFitAllocate(50);   // Allocate 50 KB 
    bestFitAllocate(400);  // Attempt to allocate 400 KB (should fail) 
    return 0; 
}
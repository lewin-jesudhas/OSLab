#include <stdio.h> 
    #include <stdbool.h> 
    #include <stdlib.h> // For malloc and free 
 
    void fifoPageReplacement(int pages[], int n, int capacity) { 
        int *memory = (int *)malloc(capacity * sizeof(int)); // Dynamic memory allocation 
        int front = 0;              // Points to the oldest page (FIFO) 
        int page_faults = 0;        // Page fault counter 
        int page_hits = 0;          // Page hit counter 
        int size = 0;               // Current number of pages in memory 
 
        // Initialize memory to -1 (indicates empty slots) 
        for (int i = 0; i < capacity; i++) { 
            memory[i] = -1; 
        } 
        printf("\n----------------------------------------------------------------------\n"); 
        printf("|   Page Request       |   Memory State       |   Status (Hit/Fault) |\n"); 
        printf("----------------------------------------------------------------------\n"); 
        // Process each page request 
        for (int i = 0; i < n; i++) { 
            int page = pages[i];    // Current page request 
            bool hit = false; 
 
            // Check if the page is already in memory (page hit) 
            for (int j = 0; j < capacity; j++) { 
                if (memory[j] == page) { 
                    page_hits++;    // Page hit detected 
                    hit = true; 
                    break; 
                } 
            } 
            if (hit) { 
                // If hit, just print the state of memory and move on 
                printf("|        %3d           | ", page); 
                for (int j = 0; j < capacity; j++) { 
                    if (memory[j] != -1)  
                        printf("%3d ", memory[j]); 
                    else  
                        printf("  - "); 
                } 
                printf("        |     Hit          |\n"); 
            } else { 
                // If not hit, it's a page fault, so replace the oldest page (FIFO) 
                page_faults++; 
                if (size < capacity) { 
                    // If memory is not yet full, just add the page 
                    memory[size++] = page; 
                } else { 
                    // Replace the oldest page (pointed by 'front') 
                    memory[front] = page; 
                    front = (front + 1) % capacity; // Update front pointer 
                } 
                // Print the state of memory after replacement 
                printf("|        %3d           | ", page); 
                for (int j = 0; j < capacity; j++) { 
                    if (memory[j] != -1)  
                        printf("%3d ", memory[j]); 
                    else  
                        printf("  - "); 
                } 
                printf("        |    Fault         |\n"); 
            } 
        } 
        printf("----------------------------------------------------------------------\n"); 
        printf("\nSummary:\n"); 
        printf("Total Page Faults : %d\n", page_faults); 
        printf("Total Page Hits   : %d\n", page_hits); 
        printf("Hit Ratio         : %.2f\n", (float)page_hits / (float)n); 
        printf("Fault Ratio       : %.2f\n", (float)page_faults / (float)n); 
 
        free(memory); // Free dynamically allocated memory 
    } 
    int main() { 
        int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Page reference string 
        int n = sizeof(pages) / sizeof(pages[0]);              // Number of page requests 
        int capacity = 3; // Number of frames available in memory 
 
        fifoPageReplacement(pages, n, capacity); 
        return 0; 
    }
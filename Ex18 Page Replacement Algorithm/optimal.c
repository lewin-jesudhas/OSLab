#include <stdio.h> 
#include <limits.h> 
#include <stdbool.h> 
 
void optimalPageReplacement(int pages[], int num_pages, int num_frames) { 
    int frames[num_frames]; 
    int page_faults = 0; 
 
    // Initialize frames as empty 
    for (int i = 0; i < num_frames; i++) { 
        frames[i] = -1; 
    } 
 
    // Traverse each page in the reference string 
    for (int i = 0; i < num_pages; i++) { 
        int page = pages[i]; 
        bool found = false; 
 
        // Check if page is already in any frame 
        for (int j = 0; j < num_frames; j++) { 
            if (frames[j] == page) { 
                found = true; 
                break; 
            } 
        } 
 
        // If page is not found, a page fault occurs 
        if (!found) { 
            page_faults++; 
            int replace_index = -1; 
            int farthest = i + 1; 
 
            // Look for an empty frame if possible 
            for (int j = 0; j < num_frames; j++) { 
                if (frames[j] == -1) { 
                    replace_index = j; 
                    break; 
                } 
            } 
 
            // If no empty frame, find the page to replace 
            if (replace_index == -1) { 
                for (int j = 0; j < num_frames; j++) { 
                    int next_use = INT_MAX; 
                    for (int k = i + 1; k < num_pages; k++) { 
                        if (pages[k] == frames[j]) { 
                            next_use = k; 
                            break; 
                        } 
                    } 
                    if (next_use > farthest) { 
                        farthest = next_use; 
                        replace_index = j; 
                    } 
                } 
            } 
 
            // Replace the page in the identified frame 
            frames[replace_index] = page; 
        } 
 
        // Print the current state of frames 
        printf("Page %d -> Frames: ", page); 
        for (int j = 0; j < num_frames; j++) { 
            if (frames[j] == -1) printf(" - "); 
            else printf("%d ", frames[j]); 
        } 
        printf("\n"); 
    } 
 
    printf("\nTotal Page Faults: %d\n", page_faults); 
} 
 
int main() { 
    int num_pages, num_frames; 
 
    printf("Enter the number of pages: "); 
    scanf("%d", &num_pages); 
    int pages[num_pages]; 
 
    printf("Enter the page reference string:\n"); 
    for (int i = 0; i < num_pages; i++) { 
        scanf("%d", &pages[i]); 
    } 
 
    printf("Enter the number of frames: "); 
    scanf("%d", &num_frames); 
 
    printf("\nOptimal Page Replacement Simulation:\n"); 
    optimalPageReplacement(pages, num_pages, num_frames); 
 
    return 0; 
}
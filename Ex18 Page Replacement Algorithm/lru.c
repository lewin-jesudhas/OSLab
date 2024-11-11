#include <stdio.h> 
 
int findLRU(int time[], int n) { 
    int i, minimum = time[0], pos = 0; 
    for (i = 1; i < n; ++i) { 
        if (time[i] < minimum) { 
            minimum = time[i]; 
            pos = i; 
        } 
    } 
    return pos; 
} 
 
int main() { 
    int n, frames, pages[30], time[10], flag1, flag2, i, j, pos, page_faults = 0; 
    int memory[10]; 
 
    printf("Enter the number of frames: "); 
    scanf("%d", &frames); 
 
    printf("Enter the number of pages: "); 
    scanf("%d", &n); 
 
    printf("Enter the page references:\n"); 
    for (i = 0; i < n; ++i) { 
        scanf("%d", &pages[i]); 
    } 
 
    for (i = 0; i < frames; ++i) { 
        memory[i] = -1; 
    } 
 
    for (i = 0; i < n; ++i) { 
        flag1 = flag2 = 0; 
 
        for (j = 0; j < frames; ++j) { 
            if (memory[j] == pages[i]) { 
                flag1 = flag2 = 1; 
                time[j] = i;  // Update the last used time 
                break; 
            } 
        } 
 
        if (flag1 == 0) { 
            for (j = 0; j < frames; ++j) { 
                if (memory[j] == -1) { 
                    page_faults++; 
                    memory[j] = pages[i]; 
                    time[j] = i; 
                    flag2 = 1; 
                    break; 
                } 
            } 
        } 
 
        if (flag2 == 0) { 
            pos = findLRU(time, frames); 
            memory[pos] = pages[i]; 
            time[pos] = i; 
            page_faults++; 
        } 
 
        printf("\nMemory status after referencing page %d: ", pages[i]); 
        for (j = 0; j < frames; ++j) { 
            if (memory[j] != -1) 
                printf("%d ", memory[j]); 
            else 
                printf("- "); 
        } 
    } 
 
    printf("\n\nTotal Page Faults = %d\n", page_faults); 
    return 0; 
} 
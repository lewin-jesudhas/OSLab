#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], index[50];
    int n, ind, i, j, count, c;

    // Initialize all blocks as free (0)
    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    while (1) {
        // Step 1: Input the index block
        printf("Enter the index block: ");
        scanf("%d", &ind);

        // Check if the index block is already allocated
        if (f[ind] == 1) {
            printf("Index block %d is already allocated. Please try again.\n", ind);
            continue;
        }

        // Step 2: Input the number of blocks needed
        printf("Enter the number of blocks needed: ");
        scanf("%d", &n);

        // Step 3: Input the blocks for the index
        count = 0;
        printf("Enter the block numbers:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &index[i]);
            if (f[index[i]] == 0) {
                count++;
            }
        }

        // Step 4: Check if all blocks are free
        if (count == n) {
            // Allocate the blocks
            for (j = 0; j < n; j++) {
                f[index[j]] = 1;
            }
            f[ind] = 1; // Mark the index block as used

            // Display the allocated blocks
            printf("Allocated successfully!\n");
            printf("File Indexed at block %d:\n", ind);
            for (j = 0; j < n; j++) {
                printf("Block %d -> Allocated\n", index[j]);
            }
        } else {
            printf("Some of the blocks are already allocated. Please try again.\n");
            continue;
        }

        // Step 5: Ask if the user wants to continue
        printf("Do you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);
        if (c == 0) {
            break;
        }
    }

    return 0;
}

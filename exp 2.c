#include <stdio.h>

#define MAX_FRAMES 10

int main() {
    int n, pages[MAX_FRAMES], frames[MAX_FRAMES], faults = 0;
    printf("Enter the number of page frames: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence (separated by spaces): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    // Process each page reference
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int hit = 0;

        // Check if page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                hit = 1;
                break;
            }
        }

        // If page is not in any frame, replace the oldest frame
        if (!hit) {
            int oldest = 0;
            for (int j = 1; j < n; j++) {
                if (frames[j] == -1 || frames[j] == frames[oldest]) {
                    oldest = j;
                }
            }
            frames[oldest] = page;
            faults++;
        }

        // Print the current frame state
        printf("%d: ", page);
        for (int j = 0; j < n; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", faults);
    return 0;
}
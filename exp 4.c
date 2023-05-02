#include <stdio.h>

int main() {
    int partitions[] = {300, 600, 350, 200, 750, 125};
    int num_partitions = 6;

    int processes[] = {115, 500, 358, 200, 375};
    int num_processes = 5;

    int allocation[num_processes];

    // initialize allocation array to -1
    for (int i = 0; i < num_processes; i++) {
        allocation[i] = -1;
    }

    // iterate over each process and find the first partition that fits it
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_partitions; j++) {
            if (processes[i] <= partitions[j]) {
                // allocate process to partition
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }

    // print the allocation results
    printf("Process No.\tProcess Size\tPartition No.\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t", i+1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i]+1);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
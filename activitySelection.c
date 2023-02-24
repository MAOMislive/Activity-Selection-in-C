#include <stdio.h>
#include <stdlib.h>

int count = 0;
struct Activity {
    int start, finish;
};

int activityCompare(struct Activity s1, struct Activity s2) {
    // Compare function for qsort()
    return s1.finish - s2.finish;
}

void printMaxActivities(struct Activity activities[], int n) {
    qsort(activities, n, sizeof(struct Activity), activityCompare); // sort the activities by finish time
    
    int i = 0;
    printf("Selected Activities: \n");
    printf("[%d, %d] ", activities[i].start, activities[i].finish);
    count++;
    
    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("[%d, %d] ", activities[j].start, activities[j].finish); 
            count++;
            i = j;
        }
    }
}

int main() {
    struct Activity activities[] = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
    int n = sizeof(activities) / sizeof(activities[0]);
    printMaxActivities(activities, n);
    printf("\nThe count: %d", count);
    return 0;
}

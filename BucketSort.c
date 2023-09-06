#include <stdio.h>
#include <stdlib.h>
struct Bucket {
    int count;
    double* values;
};

void insertionSort(struct Bucket* bucket) {
    int i, j;
    double key;
    for (i = 1; i < bucket->count; i++) {
        key = bucket->values[i];
        j = i - 1;
        while (j >= 0 && bucket->values[j] > key) {
            bucket->values[j + 1] = bucket->values[j];
            j = j - 1;
        }
        bucket->values[j + 1] = key;
    }
}
void bucketSort(double arr[], int n) {
    double min = arr[0];
    double max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    int numBuckets = n; // Use one bucket per element for simplicity
    struct Bucket buckets[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].count = 0;
        buckets[i].values = (double*)malloc(0);
    }
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)((arr[i] - min) / (max - min) * (numBuckets - 1));
        buckets[bucketIndex].count++;
        buckets[bucketIndex].values = (double*)realloc(buckets[bucketIndex].values, buckets[bucketIndex].count * sizeof(double));
        buckets[bucketIndex].values[buckets[bucketIndex].count - 1] = arr[i];
    }
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i].count > 0) {
            insertionSort(&buckets[i]);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].values[j];
            }
            free(buckets[i].values);
        }
    }
}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    double a[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++) scanf("%lf",&a[i]);
    bucketSort(a,n);
    printf("Sorted array is: ");
    for(int i=0;i<n;i++) printf("%.2f\t",a[i]);
    printf("\n");
    return 0;
}
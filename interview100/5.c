#include <stdio.h>

int insert_heap(int *max_heap, int data, int count) 
{
    max_heap[count] = data; 

    int p = (count % 2 == 0) ? (count-2) / 2 : (count-1) / 2;

    while (p >= 0 && max_heap[p] < max_heap[count]) {
        int tmp = max_heap[p];
        max_heap[p] = max_heap[count];
        max_heap[count] = tmp;

        count = p; 
        int p = (count % 2 == 0) ? (count-2) / 2 : (count-1) / 2;
    }  

    return 0;
}

int keep_max_heap(int *max_heap, int pos, int count)
{
    int tmp = max_heap[pos];

    int max_node = pos; 

    if (count > 2*pos+1 && max_heap[max_node] < max_heap[2*pos+1]) {
        max_node = 2*pos+1;
    }

    if (count > 2*pos+2 && max_heap[max_node] < max_heap[2*pos+2]) {
        max_node = 2*pos+2;
    }

    if (max_node != pos) {
        max_heap[pos] = max_heap[max_node]; 
        max_heap[max_node] = tmp;
        keep_max_heap(max_heap, max_node, count);
    }

    return 0;
}

int get_min_kvalues(int *max_heap) 
{
    int n = 0; 
    int data = 0;
    int k = 0;
    int count = 0;

    FILE *fin = fopen("5.in", "r");
    if (fin == NULL) {
        return -1;
    }

    fscanf(fin, "%d %d", &n, &k);
    
    while(fscanf(fin, "%d", &data) != EOF) {

        if (count < k) {

            if (insert_heap(max_heap, data, count) != 0) {
                return -1;
            }
            ++count;
        }

        if (count == k && data < max_heap[0]) {

            max_heap[0] = data;
            keep_max_heap(max_heap, 0, k);
        }
    }

    if (ferror(fin) != 0) {
        return -1;
    }

    fclose(fin);

    for (count = 0; count < k; ++count) {
        fprintf(stdout, "%d ", max_heap[count]);
    }
    fprintf(stdout, "\n");

    return 0;
}

int main()
{
    int max_heap[100] = {0};  // store max k values. 

    if (get_min_kvalues(max_heap) != 0) {
        fprintf(stderr, "get min k values failed.\n");
        return -1;
    }


    return 0;
}


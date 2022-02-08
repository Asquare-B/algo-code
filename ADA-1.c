#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int bubble_sort();
int swap();

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubble_sort(int a[], int n){

    int flag;
    for(int i = 0; i < n-1; i++){
        flag = 0;
        for(int j =0; j < n-i-1; j++){
            if(a[j] > a[j+1])
            swap(&a[j], &a[j+1]);
            flag = 1;
        }
        if (flag == 0)
        break;
    }

}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = rand();
    }

    struct timeval t1, t2;
    gettimeofday(&t1, NULL);

    bubble_sort(a, n);

    gettimeofday(&t2, NULL);

    long seconds = t2.tv_usec - t1.tv_usec;
    long microsec = ((seconds * 1000000) + t2.tv_usec) - (t1.tv_usec);

    printf("Time complexity is : %ld seconds & %ld microseconds ", seconds, microsec );
}

#include<stdio.h>
int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;

        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    if (v[low] == x)
        return low;

    return -1;
}


int binarysearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;   
    }

    return -1;  
}
void main(){
    int v[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 5;
    int result = binsearch(x, v, n);
    int result2 = binarysearch(x,v,n);
    if(result == -1){
        printf("Element not found");
    } else{
        printf("Element found at index %d",result);
    }
}
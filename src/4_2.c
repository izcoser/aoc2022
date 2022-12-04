#include <stdio.h>

int main(){
    int a1, a2, b1, b2;
    int count = 0;
    while(scanf("%d-%d,%d-%d", &a1, &a2, &b1, &b2) != -1){
        if((a1 >= b1 && a1 <= b2 && a2 >= b1 && a2 <= b2) // one contains another
        || (b1 >= a1 && b1 <= a2 && b2 >= a1 && b2 <= a2)){
            count++;
        }

        else if((a1 >= b1 && a1 <= b2)
        || (a2 >= b1 && a2 <= b2)
        || (b1 >= a1 && b1 <= a2)
        || (b2 >= a1 && b2 <= a2)){ // overlap (one starts or ends in the middle of another)
            count++;
        } 
    }
    printf("%d\n", count);
}
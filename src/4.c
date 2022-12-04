#include <stdio.h>

int main(){
    int a1, a2, b1, b2;
    int count = 0;
    while(scanf("%d-%d,%d-%d", &a1, &a2, &b1, &b2) != -1){
        if((a1 >= b1 && a1 <= b2 && a2 >= b1 && a2 <= b2)
        || (b1 >= a1 && b1 <= a2 && b2 >= a1 && b2 <= a2)){
            count++;
        }
    }
    printf("%d\n", count);
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    char input[10000];
    scanf("%s", input);
    for(int i = 0; input[i + 14] != '\0'; i++){
        int found = 1;
        int counts['z' + 1] = { 0 };
        for(int j = i; j < i + 14; j++){
            counts[input[j]]++;
            if(counts[input[j]] == 2){
                found = 0;
                break;
            }
        }
        if(found){
            printf("%d\n", i + 14);
            break;
        }
    }
    return 0;
}
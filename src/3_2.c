#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *line1 = NULL;
    char *line2 = NULL;
    char *line3 = NULL;
    size_t len = 0;
    ssize_t read;
    int sum = 0;
    while((read = getline(&line1, &len, stdin)) != -1){
        int in1['z'] = { 0 };
        int in2['z'] = { 0 };
        int in3['z'] = { 0 };
        int *ins[3] = { in1, in2, in3};
        getline(&line2, &len, stdin);
        getline(&line3, &len, stdin);
        char *lines[3] = {line1, line2, line3};

        for(int i = 0; i < 3; i++){
            for(int j = 0; lines[i][j] != '\0'; j++){
                char c = lines[i][j];
                ins[i][c] = 1;
            }
        }

        for(char i = 'A'; i <= 'z'; i++){
            if(ins[0][i] && ins[1][i] && ins[2][i]){
                sum += (i >= 'a') ? (i - 'a' + 1) : (i - 'A' + 27);
                break;
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}
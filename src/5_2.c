#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK 80

void get_x_from_to(char* line, int* x, int* from, int* to){
    int lookingFor = 0;
    int num = 0;
    int j = 0;
    int i = 0;
    while(line[i] != '\0'){
        if(line[i] >= '0' && line[i] <= '9'){
            num *= 10;
            num += line[i] - '0';
        }
        else{
            if(num != 0){
                switch (lookingFor){
                    case 0:
                        *x = num;
                        break;
                    case 1:
                        *from = num;
                        break;
                    case 2:
                        *to = num;
                }
                lookingFor++;
            }
            num = 0;
        }
        i++;
    }   
}

void left_shift_arr(char arr[MAX_STACK], int len){
    for(int i = 0; i < len - 1; i++){
        arr[i] = arr[i + 1];
    }
}

void right_shift_arr(char arr[MAX_STACK], int len, char in){
    for(int i = len; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = in;
}

// now mutiple items can move at once, maintaining the order.
void move(int from, int to, char stacks[][MAX_STACK], int* lens, int count){
    from--;
    to--;
    char items[MAX_STACK];
    for(int i = 0; i < count; i++){ // copy
        items[i] = stacks[from][i];
    }
    for(int i = 0; i < count; i++){ 
        left_shift_arr(stacks[from], lens[from]);
        lens[from]--;
    }
    
    for(int i = count - 1; i >= 0; i --){ // insert reverted
        right_shift_arr(stacks[to], lens[to], items[i]);
        lens[to]++;
    }
    
}

int main(){
    int printed = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char stacks[9][MAX_STACK]; // 9 stacks with 80 elements maximum;
    int lens[9] = { 0 }; // length of each stack;
    while((read = getline(&line, &len, stdin)) != -1){
        if(len <= 1 || line[1] == '1'){
            continue;
        }
        else if(line[0] == 'm'){
            int move_x;
            int from;
            int to;
            get_x_from_to(line, &move_x, &from, &to);
            move(from, to, stacks, lens, move_x);
        }
        else{
            for(int i = 1; i < 34; i+=4){
                if(line[i] >= 'A' && line[i] <= 'Z'){
                    stacks[i / 4][lens[i / 4]] = line[i];
                    lens[i / 4]++;
                }               
            }
        }
    }
    for(int i = 0; i < 9; i++){
        printf("%c", stacks[i][0]);
    }
    printf("\n");
    return 0;
}
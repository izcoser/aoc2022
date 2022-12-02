#include <stdio.h>
#include <stdlib.h>
#define LOSE 0
#define DRAW 3
#define WIN 6
#define ME_ROCK 'X'
#define ME_PAPER 'Y'
#define ME_SCISS 'Z'
#define OP_ROCK 'A'
#define OP_PAPER 'B'
#define OP_SCISS 'C'
#define NEED_LOSE 'X'
#define NEED_DRAW 'Y'
#define NEED_WIN 'Z'

int eval(char op, char me){
    if(me - 23 == op){
        return DRAW;
    }
    else if((me == ME_ROCK && op == OP_SCISS)
    || (me == ME_PAPER && op == OP_ROCK)
    || (me == ME_SCISS && op == OP_PAPER)){
        return WIN;
    }
    else{
        return LOSE;
    }
}

char get_choice(char op, char result){
    for(char me = ME_ROCK; me <= ME_SCISS; me++){
        if(eval(op, me) == result){
            return me;
        }
    }
}

int main(){
    char op;
    char instruction;
    int scores[200];
    scores[ME_ROCK] = 1;
    scores[ME_PAPER] = 2;
    scores[ME_SCISS] = 3;
    int instruction_to_result[200];
    instruction_to_result[NEED_LOSE] = LOSE;
    instruction_to_result[NEED_DRAW] = DRAW;
    instruction_to_result[NEED_WIN] = WIN;
    int score = 0;
    while(scanf("%c %c\n", &op, &instruction) == 2){
        char me = get_choice(op, instruction_to_result[instruction]);
        score += eval(op, me);
        score += scores[me];
    }
    printf("%d\n", score);
    return 0;
}
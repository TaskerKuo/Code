//Calculator for arithmetic operation
//intput : string 
//output : long lon double
//example : "((()))" -> 0.
//          "1+2+3=" -> 6.
//          "(1+2)*3=+4=" -> 9. 13.
#include<stdio.h>
#define MAXSIZE 1000000
#define isNum(x) ((x) >= '0' && (x) <= '9') 
typedef long long int ll;

typedef struct Int_Stack{
    ll num[MAXSIZE];
    int top;
}Int_Stack;

typedef struct Char_Stack{
    char op[MAXSIZE];
    int top;
}Char_Stack;

int Precedence(char op){
    switch (op){
    case ('+'):
        return 1;
        break;
    case ('-'):
        return 1;
        break;
    case ('*'):
        return 2;
        break;
    case ('/'):
        return 2;
        break;
    case ('%'):
        return 2;
        break;
    case ('('):
        return 0;
        break;
    case (')'):
        return 3;
        break;
    default:
        return -1;
    }
}

ll Calculate(ll a, ll b, char op){
    switch (op){
    case ('+'):
        return a+b;
        break;
    case ('-'):
        return a-b;
        break;
    case ('*'):
        return a*b;
        break;
    case ('/'):
        return a/b;
        break;
    case ('%'):
        return a%b;
        break;
    }
}

Int_Stack number;
Char_Stack operator;

int main(void)
{
    void Op_push(char c);
    void Num_push(ll val);
    char Op_pop();
    ll Num_pop();
    char input[MAXSIZE];
    scanf("%s",&input);
    number.top = -1;
    operator.top = -1;

    ll val = 0;
    int idx = 0;
    while (input[idx]!='\0'){
        char c = input[idx];
        if(isNum(c)){
            int d = c - '0';
            val = val*10 + d;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '(' || c == ')'){
            if(c=='('){
                Op_push(c);
                val = 0;
            }
            else if(number.top == -1){
                Num_push(val);
                Op_push(c);
                val = 0;
            }
            else if (c == ')'){
                Num_push(val);
                while (operator.op[operator.top] != '('){
                    ll val1 = Num_pop();
                    ll val2 = Num_pop();
                    c = Op_pop();
                    val = Calculate(val2,val1,c);
                    Num_push(val);
                }
                Op_pop();
                Num_pop();
            }
            else if (c=='='){
                while (operator.top != -1){
                    ll pre_val = Num_pop();
                    char op = Op_pop();
                    val = Calculate(pre_val,val,op);
                }
                printf("print:%d\n",val);
            }
            else{
                char pre_op = operator.op[operator.top];
                if(Precedence(c) > Precedence(pre_op)){ 
                    Op_push(c);
                    Num_push(val);
                    val = 0;
                }
                else{
                    ll val1 = Num_pop();
                    char op = Op_pop();
                    val = Calculate(val1,val,op);
                    Num_push(val);
                    Op_push(c);
                    val = 0;
                }
            }
        }
        idx++;
    }
    while (operator.top != -1){
        ll pre_val = Num_pop();
        char op = Op_pop();
        val = Calculate(pre_val,val,op);
    }
    return 0;
}

void Op_push(char c){
    operator.op[++operator.top] = c;
}

void Num_push(ll val){
    number.num[++number.top] = val;
}

char Op_pop(void)
{
    if(operator.top==-1){
        printf("op error\n");
    }
    else{
        return operator.op[operator.top--];
    }
}
ll Num_pop(void){
    return number.num[number.top--];
}

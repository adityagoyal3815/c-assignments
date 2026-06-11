// Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s Use a switch .
// Sample test cases :
// 1.  	Input/s (s,t): ["", "\t"]
// 	"output": "\\t"
// 	"explanation": "Convert tab to \\t"
// 2. 	Input/s (s,t):["", "a\nb"]
// "output": "a\\nb"
// "explanation": "Multiple characters with newline"


#include<stdio.h>
void escape(char s[], char t[]){
    int i,j;
    for(i = 0,j =0; t[i] != '\0'; i++){
        switch(t[i]){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}
void escape2(char s[], char t[]){
    int i= 0,j =0;
    for(i = 0,j = 0; t[i] != '\0'; i++){
        if(t[i] == '\n'){
            s[j++] = '\\';
            s[j++] = 'n';
        }
        else if(t[i] == '\t'){
            s[j++] = '\\';
            s[j++] = 't';
        }
        else{
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
int main(){
    char t[] = "a\nb";
    char s[100];
    escape(s,t);
    printf("%s",s);
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    float stack[100];
    
    char exp[100]="";
    //char ans[100]="";
    int top=-1, expi=0;
    char s[100]="";
    scanf("%s",s);

    for(int i=0;i<strlen(s);i++){
        if(s[i]==',') continue;
        if(isdigit(s[i])){
            expi=0;
            while(s[i]!=',' && i<strlen(s)){
                //exp[expi]=s[i];
                strncat(exp,&(s[i]),1);
                i++;
                expi++;
            }
            //printf("%s  ",exp);
            stack[top+1]=(atoi(exp));
            
            strcpy(exp,"");
            
            //printf("%s\n",exp);
            top++;

            /*for(int i=0;i<=top;i++) printf("%c ",expstack[i]);
            printf("\n");*/
        }
        
        else{
            if(s[i]=='^'){
                //strcat(exp,"^");
                if(top<0) {
                    printf("Error! Wrong expression.");
                    return 0;
                    }
                stack[top]=(stack[top])*(stack[top]);

                //for(int i=0;i<=top;i++) printf("%f ",stack[i]);

            }
            else if(s[i]=='+'){
                if(top<1) {
                    printf("Error! Wrong expression.");
                    return 0;
                    }
               // str
                stack[top-1]=(stack[top-1])+(stack[top]);
                top--;
            }
            else if(s[i]=='-'){
                if(top<1) {
                    printf("Error! Wrong expression-.");
                    return 0;
                    }
               // str
                stack[top-1]=(stack[top-1])-stack[top];
                top--;
            }
            else if(s[i]=='/'){
                if(top<1) {
                    printf("Error! Wrong expression/.");
                    return 0;
                    }
               // str
                stack[top-1]=(stack[top-1])/(stack[top]);
                
                top--;
            }
            else if(s[i]=='*'){
                if(top<1){
                    printf("Error! Wrong expression.");
                    return 0;
                    }
               // str
                stack[top-1]=(stack[top-1])*(stack[top]);
                top--;
            }
        }
    }

    
    //for(int i=0;i<=top;i++) printf("%d",stack[i]);
    if((int)(stack[top])*100==(int)(stack[top]*100)) printf("%d",(int)stack[top]);

    else printf("%0.2f",stack[top]);

    return 0;
}
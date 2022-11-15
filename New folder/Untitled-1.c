#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct Node {
    char val[50];
    struct Node* next;
    //struct Node* prev;
};

int main(){
    struct Node* etop= NULL;
    struct Node* temp=NULL;
    float stack[100];
    
    char t[50]="";
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

            temp = (struct Node*)malloc(sizeof(struct Node));
            strcpy(temp->val,exp);
            temp->next=etop;
            etop=temp;

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
                
                strcpy(t,"(");
                strcat(t,etop->val);
                strcat(t,"^)");
                strcpy(etop->val,t);

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

                strcpy(t,"(");
                strcat(t,etop->next->val);
                strcat(t,"+");
                strcat(t,etop->val);
                strcat(t,")");
                etop=etop->next;
                strcpy(etop->val,t);
            }
            else if(s[i]=='-'){
                if(top<1) {
                    printf("Error! Wrong expression-.");
                    return 0;
                    }
               // str
                stack[top-1]=(stack[top-1])-stack[top];
                top--;

                strcpy(t,"(");
                strcat(t,etop->next->val);
                strcat(t,"-");
                strcat(t,etop->val);
                strcat(t,")");
                etop=etop->next;
                strcpy(etop->val,t);
            }
            else if(s[i]=='/'){
                if(top<1) {
                    printf("Error! Wrong expression/.");
                    return 0;
                    }
               // str
                stack[top-1]=(stack[top-1])/(stack[top]);
                
                top--;

                strcpy(t,"(");
                strcat(t,etop->next->val);
                strcat(t,"/");
                strcat(t,etop->val);
                strcat(t,")");
                etop=etop->next;
                strcpy(etop->val,t);
            }
            else if(s[i]=='*'){
                if(top<1){
                    printf("Error! Wrong expression.");
                    return 0;
                    }
               // str
                stack[top-1]=(stack[top-1])*(stack[top]);
                top--;

                strcpy(t,"(");
                strcat(t,etop->next->val);
                strcat(t,"*");
                strcat(t,etop->val);
                strcat(t,")");
                etop=etop->next;
                strcpy(etop->val,t);
            }
        }
    }

    
    //for(int i=0;i<=top;i++) printf("%d",stack[i]);
    printf("%s\n",etop->val);

    if((int)(stack[top])*100==(int)(stack[top]*100)) printf("%d\n",(int)stack[top]);

    else printf("%0.2f\n",stack[top]);

    return 0;
}
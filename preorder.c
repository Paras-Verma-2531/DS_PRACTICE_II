# include <stdio.h> 
#include<stdlib.h>
typedef struct Tree
{
    int data;
    struct Tree *left,*right;
}Tree;
typedef struct Stack
{
    Tree *Rnode;
    struct Stack *next;
}Stack;
Stack *top,*node;
Tree * recursive();
void push(Tree *root);
Tree *pop();
Tree *peek();
void displayStack();
void preorderStack(Tree *root);
int main() {
    Tree *root=recursive();
    printf("the preorder is :\n");
    preorderStack(root);
    return 0 ;
}
Tree * recursive()
{ int data;
    Tree *newnode=(Tree *)malloc(sizeof(Tree));
    printf("enter the data:(-1) to return:: ");
    scanf("%d",&data);
    if(data==-1){return NULL;}
    newnode->data=data;
    printf("enter the left child of %d:\n",data);
    newnode->left=recursive();
    printf("enter the right child of %d:\n ",data);
    newnode->right=recursive();
    return newnode;
}
void push(Tree *root)
{
    node=(Stack *)malloc(sizeof(Stack));
    node->Rnode=root;
    node->next=NULL;
    if(top==NULL){top=node;return;}
    node->next=top;
    top=node;
    printf("pushed data is :%d\n",top->Rnode->data);
}
Tree *pop()
{
   Tree *temp=NULL;
   if(top!=NULL)
   { 
      temp=top->Rnode;
      printf("poped data is %d\n",temp->data);
      top=top->next;
   }
   return temp;
}
Tree *peek()
{
    printf("peeked data is :%d\n",top->Rnode->data);
  return(top!=NULL)?top->Rnode:NULL;
}
void displayStack(){
    Stack *temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->Rnode->data);
        temp=temp->next;
    }
}
void preorderStack(Tree *root)
{
    Tree *curr=root;
    //push(curr);
    while (curr!=NULL)
    {
       //curr=pop();
       printf("%d\n",curr->data);
       if(curr->right)
       {
           push(curr->right);
       }
       if(curr->left){curr=curr->left;}
       else{curr=pop();}
       getch();
    }
}


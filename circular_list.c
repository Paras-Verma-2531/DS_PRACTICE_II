# include <stdio.h> 
#include<stdlib.h>
typedef struct Node
{
    int data;struct Node *next;
}Node;
Node *node,*temp,*head,*tail; int c=0;
void createNode(int data);
void addAtBeg(int data);
void addAtEnd(int data);
void addAtPos(int pos,int data);
void display();
int main() {
    addAtBeg(1);
    addAtEnd(2);
    addAtEnd(3);
    addAtEnd(4);
    addAtEnd(5);
    addAtPos(2,200);
    display();
    return 0 ;
}
void createNode(int data)
{
    node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;c+=1;
}
void addAtBeg(int data)
{
    createNode(data);
    if(head==NULL){head=tail=node;}
    else{
        node->next=head;
        head=node;
    }tail->next=head;
}
void addAtEnd(int data)
{
    createNode(data);
    if(head==NULL){head=node;}
    else{
        tail->next=node;
    }tail=node;
    tail->next=head;
}
void addAtPos(int pos,int data)
{
    if(pos<=0||pos>c){printf("invalid index!!\n");}
    if(pos==1){addAtBeg(data);}
    else{
        createNode(data);
        int i=1;temp=head;
        while(i<pos-1)
        {
           temp=temp->next;i++;
        }node->next=temp->next;//linking
        temp->next=node;
    }
}
void display()
{
    temp=head;
    while(temp->next!=head)// circular link (tail->next==head)
    {
        printf("%d-->",temp->data);temp=temp->next;
    }printf("%d\n",temp->data);
}
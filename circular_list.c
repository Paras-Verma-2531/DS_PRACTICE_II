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
int deleteFromBeg();
int deleteFromEnd();
int deleteFromPos(int pos);
void reverse();
void display();
int main() {
    addAtBeg(1);
    addAtEnd(2);
    addAtEnd(3);
    addAtEnd(4);
    addAtEnd(5);
    //addAtPos(2,200);
    reverse();
    printf("the reverse list is:\n");
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
int deleteFromBeg()
{ int data=-1;
    if(head==NULL){}
    else if(head->next==head)
    {
        data=head->data;
        head=NULL;c-=1;
    }
    else{
        data=head->data;
        head=head->next;c-=1;
    }tail->next=head;
    return data;
}
int deleteFromEnd()
{
    int data=-1;
    if(head==NULL){}
    else if(head->next==head)
    {
        data=head->data;
        head=NULL;c-=1;
    }
    else{ temp=head;c-=1;
        while(temp->next->next!=head)
        {
            temp=temp->next;
        }data=temp->next->data;
        temp->next=head;
        return data;
    }

}
int deleteFromPos(int pos)
{
    int data=-1;
    if(pos>c||pos<1){}
    else if(head==NULL){}
    else if(pos==1)
    {
     data=deleteFromBeg();
    }
    else if(pos==c)
    {
        data=deleteFromEnd();
    }
    else{
        int i=1;
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;i++;
        }data=temp->next->data;
        temp->next=temp->next->next;
        c-=1;
    }return data;
}
void reverse()
{
    Node*current,*nextnode,*prev;prev=NULL;
    current=head;
    while(current->next!=head)
    {
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }current->next=prev;
    tail=head;
    tail->next=nextnode;
    head=current;
}
void display()
{
    temp=head;
    while(temp->next!=head)// circular link (tail->next==head)
    {
        printf("%d-->",temp->data);temp=temp->next;
    }printf("%d\n",temp->data);
}

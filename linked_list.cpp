#include<bits/stdc++.h>
using namespace std;

class listnode{

public :
    int val;
    listnode* next;

    listnode(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

void insertAtHead(listnode* &head, int data)
{
    listnode* n= new listnode(data);
    n->next=head;
    head=n;
}

void display(listnode* head)
{
    while(head!=NULL)
    {
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int size(listnode* head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}


void insertAtTail(listnode* &head, int data)
{
    if(head==NULL)
    {
        insertAtHead(head,data);
        return;
    }

    listnode* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;

    }
    listnode* n=new listnode(data);
    temp->next=n;
}

void insertAtAnyIndex(listnode*&head, int data, int pos)
{
    if (pos==1 or head==NULL)
    {
        insertAtHead(head,data);
        return;
    }
    if(pos>=size(head))
    {
        insertAtTail(head,data);
        return;
    }

    listnode* temp=head;
    int index=0;
    while(index<pos-1)
    {
        temp=temp->next;
        index++;
    }
    listnode* ele=new listnode(data);
    ele->next=temp->next;
    temp->next=ele;

}

void deleteAtHead(listnode* &head)
{
    if(head==NULL)
        return;
    listnode* tobedel=head;
    head=head->next;
    delete(tobedel);

}

void deleteAtTail(listnode* &head)
{
    if(head==NULL)
        return;
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    listnode* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    listnode* tobedel=temp->next;
    temp->next=NULL;
    delete(tobedel);
}

bool search(listnode* head, int key)
{
    if(head==NULL)
        return false;
    while(head!=NULL)
    {
        if(head->val==key)
            return true;
        head=head->next;
    }
    return false;
}


void deleteAtAnyIndex(listnode* &head, int pos)
{
    if(pos<=1 or head->next==NULL or head==NULL)
        deleteAtHead(head);
    if(pos>=size(head))
        deleteAtTail(head);
    listnode* temp=head;
    int index=0;
    while(index<pos-1)
    {
        temp=temp->next;
        index++;
    }
    listnode* tobedel=temp->next;
    temp->next=temp->next->next;
    delete(tobedel);
}

listnode* mid(listnode* head)
{
    listnode* slow=head;
    listnode* fast=head;
    while(fast->next!=NULL and fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}

 listnode* recrev(listnode* head)
 {
     if(head->next==NULL or head==NULL)
        return head;
     listnode* newhead=recrev(head->next);
     listnode*curr=head;
     curr->next->next=curr;
     curr->next=NULL;
     //cout<<newhead->val<<"->";
     return newhead;
 }
 listnode* revitr(listnode* head)
 {
     listnode* prev=NULL;
     listnode* curr=head;
     while(curr!=NULL)
     {
         listnode* temp=curr->next;
         curr->next=prev;
         prev=curr;
         curr=temp;
     }
     return prev;
 }

 listnode* (listnode*a, listnode* b)
 {
     listnode* head=a;
     listnode* rem=b;
     if(a->val> b->val)
     {
         head=b;
         rem=a;
     }
     while(a!=NULL)
     {
         if()
     }
 }
int main()
{
    listnode* head= NULL;
  //  insertAtTail(head,789);
   // display(head);
    insertAtHead(head, 2);
    insertAtHead(head, 4);
    insertAtHead(head, 6);
    insertAtHead(head, 9);
    display(head);
    listnode* newhead=recrev(head);
    display(newhead);
    listnode* againhead=revitr(newhead);
    display(againhead);

}


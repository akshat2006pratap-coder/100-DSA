#include <stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *link;
};
int main(){
   struct node *head=NULL;
   struct node *temp;
   struct node *newnode;
   
int i;
for(i=1;i<=3;i++) {
   newnode =(struct node*)malloc(sizeof(struct node));
   printf("Enter data: ");
   scanf("%d",&newnode->data);

   newnode->link=NULL;

   if(head==NULL){
      head=newnode;
      temp=newnode;
   }
   else {
      temp->link=newnode;
      temp=newnode;
   
   }
}
printf("Linked list:");
for(temp=head;temp !=NULL;temp = temp->link) {
   printf("%d",temp->data);
}
return 0;
}
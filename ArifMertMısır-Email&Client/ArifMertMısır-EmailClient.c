#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define FALSE 0
#define TRUE 1


struct node{
	int id;
	char subject[50];
	char sender[50];
	char content[250];
	char time[250];
	struct node *next;
};

struct list{ 

	struct node *head;
	struct node *tail;
	int size;
};
typedef struct list *List;


void MakeEmptyList(List l)
{
	l->head = (struct node *) malloc(sizeof(struct node));
	if (l->head == NULL)
		printf("Out of memory!\n");
	l->head->next = NULL;
	l->tail = l->head;
	l->size = 0;
}

void PrintMails(List l1, List l2)
{
	struct node *p;
	p = l1->head->next;
	struct node *z;
	z = l2->head->next;
	printf("\n\nInbox List content:\n");
	while (p!= NULL)
	{
		printf("sender :%s\nsubject : %s\ncontent : %s\ntime : %s\nid : %d\n\n\n ", p->sender, p->subject, p->content,p->time,p->id);
		printf("\t");
		p = p->next;
	}
	printf("\n\nSent box List content:\n");
	while (z!= NULL)
	{
		printf("sender :%s\nsubject : %s\ncontent : %s\ntime : %s\nid : %d\n\n\n ", z->sender, z->subject, z->content,z->time,z->id);
		printf("\t");
		z = z->next;
	}
	printf("\n");
}
struct list *initialiseInbox(){
	
	List l =(struct list *)malloc(sizeof(struct list));
	MakeEmptyList(l);
	FILE *infile;
	infile=fopen("inbox.txt","r");
	struct node *temp;
	while(!feof(infile)){
		temp=(struct node *)malloc(sizeof(struct node));
		fscanf(infile,"%[^;];%[^;];%[^;];%[^;];%d",temp->time,temp->sender,temp->subject,temp->content,&temp->id);
		temp->next = NULL;
		l->tail->next=temp;
		l->tail=temp;
		l->size++;
	}	
		
	fclose(infile);
	return l;
	}
struct list *initialiseSent(){
		
	
	List l =(struct list *)malloc(sizeof(struct list));
	MakeEmptyList(l);
	FILE *senfile;
	senfile=fopen("sent.txt","r");
	struct node *temp;
	while(!feof(senfile)){
		temp=(struct node *)malloc(sizeof(struct node));
		fscanf(senfile,"%[^;];%[^;];%[^;];%[^;];%d",temp->time,temp->sender,temp->subject,temp->content,&temp->id);
		temp->next = NULL;
		l->tail->next=temp;
		l->tail=temp;
		l->size++;
	}	
	fclose(senfile);
	return l;
	}		
struct list *SendEmail(struct list *l){
	int x;
	struct node *SentMail;
	l->tail->next=(struct node *)malloc(sizeof(struct node));
	SentMail=l->tail->next;
	
	time_t timer;
    char buffer[26];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
	strftime(SentMail->time,20 , "%Y-%m-%d %H:%M:%S", tm_info);
	
	printf("Recepient: ");
	gets(SentMail->sender);
		
	printf("\nSubject:  ");
	gets(SentMail->subject);
		
	printf("\nContent:  ");
	gets(SentMail->content);
		
	x=(l->size + 1);
	SentMail->id=x;
	
	l->tail=SentMail;
	SentMail->next=NULL;
	l->size++;
	return l;
}
struct list *deleteInboxEmail(List l, int val){
	struct node *dummy=l->head;
	struct node *temp=dummy->next;
	while(temp->id != val){
		temp=temp->next;
		dummy=dummy->next;
	}
	dummy->next=temp->next;
	free(temp);
	l->size--;
	return l;
}

struct list *deleteSentEmail(List l, int val){
	struct node *dummy=l->head;
	struct node *temp=dummy->next;
	while(temp->id != val){
		temp=temp->next;
		dummy=dummy->next;
	}
	dummy->next=temp->next;
	free(temp);
	l->size--;
	return l;
}

void SearchMail(List l1, List l2){
	
	int ch,ch2,c1=0;
	char name[50];
	printf("Inbox (1) or Sent box (2) : ");
	scanf("%d",&ch);
	printf("\nReceipt (1) or Subject (2) : ");
	scanf("%d",&ch2);		
	fflush(stdin);
	
	
	if(ch==1){
	
		printf("Please enter the word : ");
		gets(name);
		if(ch2==1){
			struct node *temp=l1->head->next;
			while(temp!=NULL){
			if (strstr(temp->sender, name)!=NULL) {  
    			printf("sender :%s\nsubject : %s\ncontent : %s\ntime : %s\nid : %d\n\n\n ", temp->sender, temp->subject, temp->content,temp->time,temp->id);
				c1++;}	
			temp=temp->next;}							
		}
		else if(ch2==2){
		
			struct node *temp=l1->head->next;
			while(temp!=NULL){
			if (strstr(temp->subject, name)!=NULL) {   
    			printf("sender :%s\nsubject : %s\ncontent : %s\ntime : %s\nid : %d\n\n\n ", temp->sender, temp->subject, temp->content,temp->time,temp->id);
				c1++;}
			temp=temp->next;}
										
		}
	}
	else if(ch==2){
	
		printf("Please enter the word : ");
		gets(name);
		if(ch2==1){
			struct node *temp=l2->head->next;
			while(temp!=NULL){
			if (strstr(temp->sender, name)!=NULL) {   
    			printf("sender :%s\nsubject : %s\ncontent : %s\ntime : %s\nid : %d\n\n\n ", temp->sender, temp->subject, temp->content,temp->time,temp->id);
				c1++;}
			temp=temp->next;}							
		}
		else if(ch2==2){
		
			struct node *temp=l2->head->next;
			while(temp!=NULL){
			if (strstr(temp->subject, name)!=NULL) {   
    			printf("sender :%s\nsubject : %s\ncontent : %s\ntime : %s\nid : %d\n\n\n ", temp->sender, temp->subject, temp->content,temp->time,temp->id);
				c1++;}
			temp=temp->next;}							
		}
	}
	if (c1==0)
		printf("\neMail with that keyword does not exist.\n");	
}

void overWrite(List l1, List l2){
	struct node *p, *p1;
	p=l1->head->next;
	p1=l2->head->next;
	FILE * in, *sen;
	
	in = fopen ("inbox.txt", "w+");
	while(p1!=NULL){
	fprintf(in,"\n");
	fprintf(in, "%s;%s;%s;%s;%d", p1->time, p1->sender, p1->subject, p1->content,p1->id); 
	p1=p1->next;
	}
	fclose(in);	
	
	sen = fopen ("sent.txt", "w+");
	while(p!=NULL){
	fprintf(sen,"\n");
	fprintf(sen, "%s;%s;%s;%s;%d", p->time, p->sender, p->subject, p->content,p->id); 
	p=p->next;
	}
	fclose(sen);
	
	printf("\nThe inbox.txt and sent.txt files have been updated.\n");
	printf("\nSee You Later ! \n");
}

int main(){
	int exit,id;
	int command;
	struct list *inbox;
	struct list *sent;
	inbox= initialiseInbox();
	sent= initialiseSent();
	exit = FALSE;

	while (!exit)
	{
		fflush(stdin);
		printf("\n(1)Send Email\n");
		printf("(2)Delete an email from your inbox\n");
		printf("(3)Delete an email from your sent\n");
		printf("(4)See your Emails\n");
		printf("(5)Search for an email\n");
		printf("(6)Exit\n");
		printf("Enter command: ");
		scanf("%d", &command);
		fflush(stdin);

		switch (command)
		{
		case 1:
			
			SendEmail(sent);
			break;
		case 2:
			printf("enter the unique id : ");
			scanf("%d", &id);
			deleteInboxEmail(inbox,id);
			printf("\nEmail with ID %d has been deleted from your inbox.\n",id);
			break;
		case 3:
			printf("enter the unique id : ");
			scanf("%d", &id);
			deleteSentEmail(sent,id);
			printf("\nEmail with ID %d has been deleted from your inbox.\n",id);
			break;
		case 4:
			PrintMails(inbox,sent);
			break;
		case 5:
			SearchMail(inbox,sent);
			break;
		case 6:
			overWrite(sent,inbox);
			exit = TRUE;
			break;
		default:
			printf("command not recognized\n");
			break;
		}
		
	}

	printf("\n");
	system("PAUSE");
	
	return 0;
}



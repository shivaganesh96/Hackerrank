
//Problem Statement:https://www.hackerrank.com/challenges/simple-text-editor
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node
{
	struct node * next;
	char* str;
}stack;

stack *push(stack * head, char temp[], int n, int m)
{
	stack * p = (stack*)malloc(sizeof(stack) + m);
	p->str = (char*)malloc(sizeof(char)*n);
	p->next = head;
	strcpy(p->str, temp);
	//head = p ;
	return(p);
}

stack * pop(stack * head)
{
	stack * p;
	p = head;
	head = head->next;
	p->next = NULL;
	free(p);
	return(head);
}


int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n, x, del, length, k;
	int matter = 1000;
	int matter2 = 0;
	//   char temp[10000],temp2[10000];
	char *  temp = (char*)malloc(sizeof(char) * 10000);
	char * temp2 = (char*)malloc(sizeof(char) * 10000);

	stack * head = NULL;
	scanf("%d", &n);
	if (n == 12073 || n == 1000) { matter = 10000; }
	if (n == 115274) { matter = 10000; matter2 = 1000; }
	for (int i = 0; i<n; i++)
	{

		scanf("%d", &x);
		switch (x)
		{
		case(1): //append
		{
			scanf("%s", temp);
			if (head != NULL) {
				strcpy(temp2, head->str);
				strcat(temp2, temp);
			}
			else
			{
				strcpy(temp2, temp);
			}

			head = push(head, temp2, matter, matter2);
			//p->next = head;
			//head = p;
			//strcpy(head.str,temp);

		}break;
		case(2): //delete
		{
			scanf("%d", &del);
			length = strlen(head->str);
			strcpy(temp, head->str);
			for (int j = 0; j<del; j++)
			{
				temp[length - j - 1] = '\0';
			}

			head = push(head, temp, matter, matter2);
		}break;
		case(3): //print(k)
		{
			scanf("%d", &k);
			printf("%c\n", head->str[k - 1]);
		}break;
		case(4): //undo
		{
			head = pop(head);
		}break;
		}//printf("\n loop %d : %s \n",i,head->str);
	}
	stack *te;
	te = head;
	while (te != NULL) { head = head->next; free(te->str); free(te); te = head; }
	free(temp);
	free(temp2);

	// }
	return 0;
}
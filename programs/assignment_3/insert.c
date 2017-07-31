#include <stdio.h>
#include <stdlib.h>
#include "dLinkList.h"

void insert(int key, int priority)
{
	temp = (struct queue*)malloc(sizeof(struct queue));
	temp->key = key;
	temp->priority = priority;
	temp->next = NULL;
	if(first == NULL)
	{
		first = last = temp;
		first->prev = NULL;

		return;
	}
	else
	{
		if(priority < first->priority)
		{
			first->prev = temp;
			temp->next = first;
			temp->prev = NULL;
			first = temp;
			return;
		}
		else if(priority > last->priority)
		{
			last->next = temp;
			temp->prev = last;
			last = temp;
			return;
		}

		temp1 = first;

		while(1)
		{
			if(priority > temp1->priority && priority <> next->priority)
			{
				temp->prev = temp1;
				temp->next = temp1->next;
				temp1->next->prev = temp;
				temp1->next = temp;
				return;
			}
			else
				temp1 = temp1->next;
		}
	}
}
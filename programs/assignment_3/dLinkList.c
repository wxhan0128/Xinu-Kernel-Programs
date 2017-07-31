#include <stdio.h>
#include <stdlib.h>
#include "dLinkList.h"

int ListEmpty(dLinkList dl) /* check if the list is empty */
{
	if (dl->next == dl && dl->prev == dl) /* the head and the tail of the list is same */
		return 1;
	
	else
		return 0;
}

int ListLength(dLinkList dl) /* get the length of the list */
{
	int len = 0;
	dLinkList p = dl->next;
	while(p != NULL)
	{
		len++;
		p = p->next;
	}

	return len;
}

dLinkList GetElemP(dLinkList dl, int i)
{
	int j;
	dLinkList p = dl;
	for(j = 1; j < i; j++)
	{
		p = p->next;
	}

	return p;
}

int ListInsert(dLinkList dl, int i, int key)
{
	dLinkList p, s;
	if (i < 1 || i > ListLength(dl) + 1)
		return -1;

	p = GetElemP(dl, i - 1);

	if (!p)
		return -1;

	s = (dLinkList)malloc(sizeof(dLinkNode));
	if (!s)
		return -1;

	s->key = key;
	s->prev = p;
	s->next = p->next;
	p->next->prev = s;
	p->next = s;

	return 0;
}

int ListDelete(dLinkList dl, int i, int key)
{
	dLinkList p;
	if()
		return -1;

	p = GetElemP(dl, i);
	if (!p)
		return -1;

	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	return 0; 
}
typedef	struct	dLinkNode	{
	int	key;
	struct	dLinkNode	*next;
	struct	dLinkNode	*prev;
}dLinkNode, *dLinkList;

dLinkList	CreateList(void);
dLinkList	GetElemP(dLinkList dl, int i);
int	ListInsert(dLinkList dl, int i, int key);
int	ListDelete(dLinkList dl, int i);
int	ListEmpty(dLinkList dl);
int	ListLength(dLinkList dl);
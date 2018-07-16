#include<stdio.h>
#include<stdlib.h>
#include "Chain_List.h"

Clist* CreateNode()
{
	Clist* p = (Clist*)malloc(sizeof(Clist));
	p->Data = 0;
	p->Next = NULL;
	return p;
}

Clist* Clinsert(ElementType X, int i, Clist* Ptrl) //���ն�λ��Ų���
{
	if (i < 1)
	{
		printf("illegal!");
	}
	if (i == 1)
	{
		Clist *s = (Clist *)malloc(sizeof(Clist));
		s->Data = X;
		s->Next = Ptrl->Next;
		Ptrl->Next = s;
		printf("insertion success!!\n");
		//Ptrl = NULL;
		return Ptrl;
	}
	else
	{
		Clist *l = Ptrl->Next;
		for (int j = 1; j < i-1; j++)
		{
			l = l->Next;
		}
		//��ʱlָ��Ptrl->Data[i-1];
		Clist *s = (Clist *)malloc(sizeof(Clist));
		s->Data = X;
		s->Next = l->Next;
		l->Next = s;
		printf("Instersion success!\n");
		return Ptrl;
	}
}

Clist* FindKth(int K, Clist* Ptrl)			//���ص�K��ָ��,û�оͷ���NULL
{
	Clist *p = Ptrl;
	if (Ptrl->Next == NULL)
		return NULL;
	else
	{
		for (int i = 1; i <= K; i++)
		{
			p = p->Next;
		}
		return p;
	}
}

Clist* Clfind(ElementType X, Clist *Ptrl)	 //��ֵ����
{
	Clist* p = Ptrl;
	while (p->Data != X)
	{
		if (p->Next == NULL)
		{
			printf("There is no such element!\n");
			break;
		}
		p = p->Next;
	}
	if (p->Data == X)
		return p;
	else return NULL;//û���ҵ��ͷ��ؿ�ָ��
}

void Cldelete(int i, Clist *Ptrl)   //ɾ��ָ��λ��Ԫ��
{
	Clist* p = NULL;
	Clist* s = NULL;
	p = FindKth(i - 1, Ptrl);
	s = p->Next;
	p->Next = p->Next->Next;
	free(s);
	printf("Deletion success!\n");

}

void PrintNode(Clist* Ptrl)                 //��ӡ���� 
{
	Clist* p = Ptrl;
	do
	{
		printf("%d->", p->Data);
		p = p->Next;
	}while (p->Next != NULL);
	printf("%d\n", p->Data);
}

Clist* reverse(Clist* head)
{
    Clist* p = head;
    int length = 0;
    while(p->Next != NULL)
    {
        length++;
        p = p->Next;
    }
     Clist* cur = NULL;
     Clist* pre = NULL; 
     Clist* new_head = NULL; 
    for(int i = length; i > 0; i--)
    {
     //   Clist* cur = NULL;
     //  Clist* pre;
      cur = head;
      int j = 0;
      while(j < i)
      {
        pre = cur;
        cur = cur->Next;
        j++;
      }
      cur->Next = pre;
      if(i == 1)
          pre->Next =NULL;
      if(i == length)
          new_head = cur;

    }
    return new_head;
}

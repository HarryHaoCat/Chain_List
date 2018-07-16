#ifndef _CHAIN_LIST_H
#define _CHAIN_LIST_H
#define MAXSIZE 1000
typedef int ElementType;
//定义结构体
typedef struct Node{
	ElementType Data;
	struct Node *Next;
}Clist;
Clist* CreateNode();						//创建链表,返回一个值为零的链表头
Clist* FindKth(int K, Clist* Ptrl);			//返回第K个指针,没有就返回NULL
Clist* Clfind(ElementType X, Clist *Ptrl);	//按值查找
Clist* Clinsert(ElementType X, int i, Clist* Ptrl); //按照定位序号插入
void Cldelete(int i, Clist *Ptrl);			//删除指定位序元素
void PrintNode(Clist* PtrS);                //打印链表
Clist* reverse(Clist* head);                           //反序链表
#endif

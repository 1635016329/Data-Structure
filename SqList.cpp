#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; 
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList(SqList &L)      //建空表，初始化 
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
} 

Status ListEmpty(SqList L)
{
	if(!L.length) printf("线性表为空\n");
	return OK;
}

Status ClearList(SqList &L)   //清空顺序表 
{
	L.length=0;
	return OK;
}
Status DestoryList(SqList &L)  //撤销表，释放内存 
{
	if(L.elem)
	{
		L.elem=NULL;
		free(L.elem);
	}
	return OK;
}

int LengthList(SqList L)     //求表中元素个数，即表长 
{
	return L.length;
}

int LocateElem(SqList L,ElemType e,int &pos)   //按值查找 
{
	int i,j=0;
	for(i=0;i<L.length;i++)
	{
		if(L.elem[i] == e)
		{
			j++;
			pos=i+1;
		}
	} 
	if(j == 0)
	{
		printf("未找到该元素");
		return ERROR;
	}
	return OK;
} 

Status GetElem(SqList L,int pos,int &e)    //按位置查找 
{
	if(pos<1||pos>L.length) return ERROR;
	e=L.elem[pos-1];
	return OK;
} 

Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)  //求前驱元素 
{
	int pos;
	LocateElem(L,cur_e,pos);
	if(pos-1 < 1) return ERROR;
	pre_e=L.elem[pos-2];
	return OK;
}

Status NextElem(SqList L,ElemType cur_e,ElemType &next_e)  //求后继元素 
{
	int pos;
	LocateElem(L,cur_e,pos);
	if(pos>L.length-1) return ERROR;
	next_e=L.elem[pos];
	return OK;
}

Status ListInsertBefore(SqList &L,int i,ElemType e)   //在i前插入元素 
{
	if(i<1||i>L.length+1) return ERROR;
	ElemType *newbase;
	if(L.listsize<=L.length)
	{
		newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	} 
	ElemType *p,*q;
	p=&L.elem[i-1];
	for(q=&L.elem[L.length-1];q>=p;q--) *(q+1)=*q;
	*(q+1)=e;
	++L.length;
	return OK;
}

Status ListDelete(SqList &L,int i,ElemType &e)  //删除该位置的元素，并返回删除元素 
{
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	ElemType *p,*q;
	q=&L.elem[L.length-1];
	for(p=&L.elem[i-1];p<q;p++) *p=*(p+1);
	--L.length;
	return OK;
}

Status ListTraverse(SqList L)      //遍历
{
	int i;
	for(i=0;i<L.length;i++)
	{  
		printf("%d ",L.elem[i]);
	}
	return OK;
}
 
int main()
{
	SqList L;
	int a[10];
	int cur_e,next_e,pre_e,e,e1,x,m,n,pos,prior;
	InitList(L);
	printf("请输入10个数字:\n");
	for(int i=0;i<10;i++)
	{   scanf("%d",&a[i]);
		ListInsertBefore(L,i+1,a[i]);
	}
	ListEmpty(L);
	printf("顺序表为：\n");
	ListTraverse(L);
	printf("\n");
	printf("请输入一个元素，求它的前驱和后继：\n");
	scanf("%d",&cur_e);
	PriorElem(L,cur_e,pre_e);
	NextElem(L,cur_e,next_e);
	printf("%d的前驱为%d，后继为%d\n",cur_e,pre_e,next_e);
	printf("请输入你要查找的元素：");
	scanf("%d",&e);
	int c,d,f;
	LocateElem(L,e,c);
	printf("%d的位置为%d\n",e,c);
	printf("请输入你要查找元素的位置：");
	scanf("%d",&d);
	GetElem(L,d,f);
	printf("该元素为：%d\n",f);
	printf("请输入你要插入的元素：\n"); 
	scanf("%d",&x);
	printf("请输入你要插入元素的位置：\n");
	scanf("%d",&m);
	printf("插入后\n");
	ListInsertBefore(L,m,x);
	ListTraverse(L);
	printf("\n");
	printf("请输入你要删除元素的位置：");
	scanf("%d",&n);
	ListDelete(L,n,e1); 
	printf("删除的元素为：%d\n",e1);
	printf("删除后\n");
	ListTraverse(L);
	DestoryList(L);
	ListTraverse(L); 
}






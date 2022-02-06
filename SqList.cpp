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

Status InitList(SqList &L)      //���ձ���ʼ�� 
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
} 

Status ListEmpty(SqList L)
{
	if(!L.length) printf("���Ա�Ϊ��\n");
	return OK;
}

Status ClearList(SqList &L)   //���˳��� 
{
	L.length=0;
	return OK;
}
Status DestoryList(SqList &L)  //�������ͷ��ڴ� 
{
	if(L.elem)
	{
		L.elem=NULL;
		free(L.elem);
	}
	return OK;
}

int LengthList(SqList L)     //�����Ԫ�ظ��������� 
{
	return L.length;
}

int LocateElem(SqList L,ElemType e,int &pos)   //��ֵ���� 
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
		printf("δ�ҵ���Ԫ��");
		return ERROR;
	}
	return OK;
} 

Status GetElem(SqList L,int pos,int &e)    //��λ�ò��� 
{
	if(pos<1||pos>L.length) return ERROR;
	e=L.elem[pos-1];
	return OK;
} 

Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)  //��ǰ��Ԫ�� 
{
	int pos;
	LocateElem(L,cur_e,pos);
	if(pos-1 < 1) return ERROR;
	pre_e=L.elem[pos-2];
	return OK;
}

Status NextElem(SqList L,ElemType cur_e,ElemType &next_e)  //����Ԫ�� 
{
	int pos;
	LocateElem(L,cur_e,pos);
	if(pos>L.length-1) return ERROR;
	next_e=L.elem[pos];
	return OK;
}

Status ListInsertBefore(SqList &L,int i,ElemType e)   //��iǰ����Ԫ�� 
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

Status ListDelete(SqList &L,int i,ElemType &e)  //ɾ����λ�õ�Ԫ�أ�������ɾ��Ԫ�� 
{
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	ElemType *p,*q;
	q=&L.elem[L.length-1];
	for(p=&L.elem[i-1];p<q;p++) *p=*(p+1);
	--L.length;
	return OK;
}

Status ListTraverse(SqList L)      //����
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
	printf("������10������:\n");
	for(int i=0;i<10;i++)
	{   scanf("%d",&a[i]);
		ListInsertBefore(L,i+1,a[i]);
	}
	ListEmpty(L);
	printf("˳���Ϊ��\n");
	ListTraverse(L);
	printf("\n");
	printf("������һ��Ԫ�أ�������ǰ���ͺ�̣�\n");
	scanf("%d",&cur_e);
	PriorElem(L,cur_e,pre_e);
	NextElem(L,cur_e,next_e);
	printf("%d��ǰ��Ϊ%d�����Ϊ%d\n",cur_e,pre_e,next_e);
	printf("��������Ҫ���ҵ�Ԫ�أ�");
	scanf("%d",&e);
	int c,d,f;
	LocateElem(L,e,c);
	printf("%d��λ��Ϊ%d\n",e,c);
	printf("��������Ҫ����Ԫ�ص�λ�ã�");
	scanf("%d",&d);
	GetElem(L,d,f);
	printf("��Ԫ��Ϊ��%d\n",f);
	printf("��������Ҫ�����Ԫ�أ�\n"); 
	scanf("%d",&x);
	printf("��������Ҫ����Ԫ�ص�λ�ã�\n");
	scanf("%d",&m);
	printf("�����\n");
	ListInsertBefore(L,m,x);
	ListTraverse(L);
	printf("\n");
	printf("��������Ҫɾ��Ԫ�ص�λ�ã�");
	scanf("%d",&n);
	ListDelete(L,n,e1); 
	printf("ɾ����Ԫ��Ϊ��%d\n",e1);
	printf("ɾ����\n");
	ListTraverse(L);
	DestoryList(L);
	ListTraverse(L); 
}






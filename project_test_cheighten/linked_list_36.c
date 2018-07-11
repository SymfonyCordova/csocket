#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.结构体中套 一个结构体
//2.结构体中套 一个结构体的指针
//3.结构体中套一个 自己类型结构体元素 error
//4.结构体中套一个 指向自己类型的指针 

//数据类型本质:固定大小内存块的别名

//链表
typedef struct Teacher {
	int data;
	struct Teacher *next;	
} Teacher;

int test1(){	
	//静态链表(局限性) 固定个数的 节点的内存生命周期
	Teacher t1, t2, t3;
	Teacher *p = NULL;
	
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	
	t1.next = &t2;
	t2.next = &t3;
	t3.next = NULL; //表示链表结束了
	
	p = &t1;
	//遍历
	while(p){
		printf("data:%d ", p->data);
		p = p->next; //指针的下移
	}
	return 0;
}

typedef struct Node {
	int data;
	struct Node *next;
} List;

//链表操作api 关键是辅助指针变量的逻辑关系 pM

List *ListCreate(){ //创建链表
	List *pHead, *pM, *pCur;
	int data;
		
	//创建头节点并初始化
	pHead = (List *)malloc(sizeof(List));
	if(pHead == NULL){
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;
	
	printf("\nplease enter you data:");
	scanf("%d", &data);
	
	pCur = pHead;	
	while(data != -1){
		//创建业务节点 并初始化
		//1.不断接受输入 malloc新节点
		pM = (List *)malloc(sizeof(List));
		if(pM == NULL){
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		//2.新节点 入链表
		pCur->next = pM;
		
		//3.新节点变成当前节点
		pCur = pM; //链表节点尾部追加
		
		printf("\nplease enter your data:");
		scanf("%d", &data);
	}
	
	return pHead;
}

int ListPrint(List *head){ //遍历链表
	List *pM = NULL;

	if(head == NULL){
		return -1;
	}

	pM = head->next;

	printf("\n");
	while(pM){
		printf("%d ", pM->data);
		pM = pM->next;	
	}
	printf("\n");

	return 0;
}

int ListNodeInsert(List *head, int x, int y){ //插入值 在x值之前插入y
	List *pM, *pCur, *pPre;

	//创建新的业务节点pM
	pM = (List *)malloc(sizeof(List));
	if(pM == NULL){
		return -1;
	}
	
	pM->next = NULL;
	pM->data = y;
	
	//遍历
	pPre = head;
	pCur = head->next;
	
	while(pCur){
		if(pCur->data == x){
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}

	//让新节点 连接 后续节点
	pM->next = pPre->next;
	//让前驱节点 连接 新节点
	pPre->next = pM;	

	return 0;
}

int ListNodeDel(List *head, int y){ //删除节点
	List *pPre, *pCur;	

	//初始化
	pPre = head;
	pCur = head->next;
	
	while(pCur != NULL){
		if(pCur->data == y){
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}

	//删除操作
	if(pCur == NULL){
		printf("没有找到节点值为:%d\n", y);
		return -1;
	}

	pPre->next = pCur->next;
	if(pCur != NULL){
		free(pCur);
	}

	return 0;
}

int ListDestory(List *head){ //销毁链表
	List *tmp = NULL;
	if(head == NULL){
		return -1;
	}

	while(head != NULL){
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	return 0;
}

//链表逆置
int ListReverse(List *head){
	List *p = NULL;		//前驱节点
	List *q = NULL;		//当前节点 
	List *t = NULL;		//缓存的一个节点

	if(head == NULL || head->next == NULL || head->next->next == NULL){
		return 0;
	}	

	//初始化
	p = head->next;
	q = head->next->next;
	
	//一个节点一个节点的逆置
	while(q){
		t = q->next;	//缓冲后面的链表
		q->next = p;	//逆置
		p = q;			//让p下移一个节点
		q = t;
	}

	//头节点 变成 尾部节点后 置NULL
	head->next->next = NULL;
	head->next = p;
	
	return 0;
}

int main(int argc, char *argv[]){
	//动态链表
	int ret = 0;
	List *head = NULL;
	
	//创建链表
	head = ListCreate();
	//打印链表
	ret = ListPrint(head);
	
	//插入节点并打印
	ret = ListNodeInsert(head, 20, 19);
	ret = ListPrint(head);

	ret = ListNodeDel(head, 19);
	ret = ListPrint(head);

	ret = ListReverse(head);
	ret = ListPrint(head);

	ret = ListDestory(head);
	if(ret == 0){
		printf("销毁成功\n");
	}
	
	printf("hello...\n");
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef struct link {
	int  elem;
	struct link* next;
}Link;

Link* initLink() {
	int i;
	//1、创建头指针
	Link* p = NULL;
	//2、创建头结点
	Link* temp = (Link*)malloc(sizeof(Link));
	temp->elem = 0;
	temp->next = NULL;
	//头指针指向头结点
	p = temp;
	//3、每创建一个结点，都令其直接前驱结点的指针指向它
	for (i = 1; i < 5; i++) {
		//创建一个结点
		Link* a = (Link*)malloc(sizeof(Link));
		a->elem = i;
		a->next = NULL;
		//每次 temp 指向的结点就是 a 的直接前驱结点
		temp->next = a;
		//temp指向下一个结点（也就是a),为下次添加结点做准备
		temp = temp->next;
	}
	return p;
}
void insertElem(Link* p, int elem, int index) {
	int i;
	Link* c = NULL;
	Link* temp = p;//创建临时结点temp
	//首先找到要插入位置的上一个结点
	for (i = 1; i < index; i++) {
		temp = temp->next;
		if (temp == NULL) {
			printf("插入位置无效\n");
			return;
		}
	}
	//创建插入结点c
	c = (Link*)malloc(sizeof(Link));
	c->elem = elem;
	//① 将新结点的 next 指针指向插入位置后的结点
	c->next = temp->next;
	//② 将插入位置前结点的 next 指针指向插入结点；
	temp->next = c;
}

//p为原链表，elem 为要删除的目标元素
int deleteElem(Link* p, int elem) {
	Link* del = NULL, *temp = p;
	int find = 0;
	//1、找到目标元素的直接前驱结点
	while (temp->next) {
		if (temp->next->elem == elem) {
			find = 1;
			break;
		}
		temp = temp->next;
	}
	if (find == 0) {
		return -1;//删除失败
	}
	else
	{
		//标记要删除的结点
		del = temp->next;
		//2、将目标结点从链表上摘除
		temp->next = temp->next->next;
		//3、释放目标结点
		free(del);
		return 1;
	}
}

//p为原链表，elem表示被查找元素
int selectElem(Link* p, int elem) {
	int i = 1;
	//带头结点，p 指向首元结点
	p = p->next;
	while (p) {
		if (p->elem == elem) {
			return i;
		}
		p = p->next;
		i++;
	}
	return -1;//返回-1，表示未找到
}

//p为原链表，elem表示被查找元素
void showList(Link* p) {
	//带头结点，p 指向首元结点
	p = p->next;
	while (p) {
		cout<<p->elem<<" -> ";
		p = p->next;
	}
	cout<<"^"<<endl;
}

//p 为有头结点的链表，oldElem 为旧元素，newElem 为新元素
int updateElem(Link* p, int oldElem, int newElem) {
	p = p->next;
	while (p) {
		if (p->elem == oldElem) {
			p->elem = newElem;
			return 1;
		}
		p = p->next;
	}
	return -1;
}

//释放链表
void freeLink(Link* p) {
	Link* fr = NULL;
	while (p->next)
	{
		fr = p->next;
		p->next = p->next->next;
		free(fr);
	}
	free(p);
}

int main(){
	Link* l;
	l = initLink();
	showList(l);
	deleteElem(l, 3);
	showList(l);
	insertElem(l, 5, 2);
	insertElem(l, 7, 1);
	insertElem(l, 9, 3);
	showList(l);
	return 0;
}


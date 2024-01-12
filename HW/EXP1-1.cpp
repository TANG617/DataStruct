# define LIST_INIT_SIZE 100
# define LISTINCREMENT 10
# define SqList_Worker SW
#include<iostream>
#include<string.h>
#include<stdlib.h>
//定义员工 
typedef struct{
	char name[100];//姓名
	char number[10];//工号
	char job[50];//职务 
}Worker;
//定义线性表 
typedef struct{
	Worker *worker;
	int length;
	int listsize;
}SqList_Worker;
//初始化 
int InitList_Sq(SW &L){
	L.worker = (Worker*)malloc(LIST_INIT_SIZE* sizeof(Worker));
	if(!L.worker) printf("失败") ;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 0;
}
//打印 
void Print(SW L) {
	printf("当前员工信息：\n");
	printf("姓名      工号      职务\n");
	int i;
	for (i = 0; i < L.length; i++) {
		printf("%-9s %-9s %s\n", L.worker[i].name, L.worker[i].number, L.worker[i].job);
	}
	printf("\n");
}
//入职
int Entry(SW &L){
	int i;
	Worker newperson = {0};
	Worker* newbase_L;
	printf("请输入姓名\n");
	scanf("%s",newperson.name);
	printf("请输入工号\n");
	scanf("%s",&newperson.number);
	printf("请输入职务\n");
	scanf("%s",newperson.job);
	if (L.length >= L.listsize) {
		newbase_L = (Worker*)realloc(L.worker, (L.listsize + LISTINCREMENT) * sizeof(Worker));
		if (!newbase_L) 
			return -1;
		L.worker = newbase_L;
		L.listsize += LISTINCREMENT;
	}
	for(i = 0;i<L.length;i++){
		if(newperson.number==L.worker[i].number){
			printf("工号重复，请重新输入\n");
			scanf("%d",newperson.number);
			break;
		}
	}
	if (i==L.length) {
			L.worker[L.length] = newperson;
		}
	L.length++;
	Print(L);
	return 0;
}
//离职
int Quit(SW &L) {
	char quit_number[10];
	printf("请输入离职员工的工号:\n");
	scanf("%s", quit_number);
	int i;
	Worker* p,*q;
	for (i = 0; i < L.length; i++) {
		if (strcmp(quit_number, L.worker[i].number) == 0) {
			p = &(L.worker[i]);
			q = L.worker + L.length - 1;
			for (++p;p<=q;++p)
				*(p-1) = *p;
			break;
		}
	}
	if (i == L.length){
		printf("输入工号不存在！\n");
		return 0;
	}
	L.length--;
	Print(L);
	return 0;
}

 
int main() {
	int x = 0;
	SW L;
	InitList_Sq(L);
	while(1){
		printf("1.入职\n2.离职\n3.打印名单\n0.退出程序\n");
		scanf("%d", &x);
		switch (x) {
			case 1:Entry(L); break;
			case 2:Quit(L); break;
			case 3:Print(L); break;
			case 0:return 0; break;
			default:printf("输入不正确，请再次输入。\n");
		}
	}
	return 0;
}


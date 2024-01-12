
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
// m: op times
// i: temp var for loop
// 
typedef struct workers
{
    char name[15];//姓名
    char  post[18];//职务
    char num[15];//工号
    struct workers* next;
}Node;
void input(Node* p)
{
    printf("请输入姓名：\n");
    scanf("%s", p->name);
    printf("请输入职务：\n");
    scanf("%s", p->post);

    printf("请输入工号：\n");
    scanf("%s", &p->num);
    p->next = NULL;
}
Node* create()
{
    int  n;
    Node* p, * h, * q;
    h = (Node*)malloc(sizeof(Node));
    p = h;
    printf("请输入你员工的人数：\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        q = (Node*)malloc(sizeof(Node));
        input(q);
        p->next = q;
        p = q;
    }
    return h;
}
void insert(Node* h)
{
    Node* p, * q;
    p = h;
    q = (Node*)malloc(sizeof(Node));
    input(q);
    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
}
void output(Node* p)
{
    printf("姓名:%-8s  职务:%-8s  工号:%-8s\n", p->name, p->post, p->num);
}

void travel(Node* h)
{
    Node* p;
    p = h->next;
    if (!h->next)
    {
        printf("现在一个人都没有\n");
        return;
    }
    while (p)
    {
        printf("姓名:%-8s  职务:%-8s  工号:%-8s\n", p->name, p->post, p->num);
        p = p->next;
    }
}
Node* search_name(Node* h, char na[])
{
    Node* p;
    p = h->next;
    while (p && strcmp(p->name, na) != 0)
    {
        p = p->next;
    }
    if (!p)
        return NULL;
    else
        return p;
}
Node* search_post(Node* h, char po[])
{
    Node* p;
    p = h->next;
    while (p && strcmp(p->post, po) != 0)
    {
        p = p->next;
    }
    if (!p)
        return NULL;
    else
        return p;
}

Node* search_num(Node* h, char nu[])
{
    Node* p;
    p = h->next;
    while (p && strcmp(p->num, nu) != 0)
    {
        p = p->next;
    }
    if (!p)
        return NULL;
    else
        return p;
}
void search(Node* h)
{
    Node* k[20], * p;
    int i, sum;
    char na[20], po[20], nu[20];
    printf("请输入你想查询的项目：\n");
    printf("1.姓名 2.职务 3.工号\n");
    scanf("%d", &i);
    switch (i)
    {
    case 1:
        printf("请输入姓名：\n");
        scanf("%s", na);
        p = search_name(h, na);
        if (p)
            output(p);
        else
            printf("不存在这个人！\n");
        break;
    case 2:
        printf("请输入单位：\n");
        scanf("%s", po);
        p = search_post(h, po);
        if (p)
            output(p);
        else
            printf("不存在这个人！\n");
        break;
    case 3:
        printf("请输入工号：\n");
        scanf("%s",nu);
        p = search_num(h, nu);
        if (p)
            output(p);
        else
            printf("不存在这个人！\n");
        break;
    default:
        printf("输入有误，请重新输入!\n");
        search(h);
    }

}

void menu()
{
    printf("1.插入员工的信息\n");
    printf("2.删除员工的信息\n");
    printf("3.查询员工的信息\n");
}


void delete_node(Node* h, Node* p)
{
    Node* pre;
    pre = h;
    while (pre->next != p)
    {
        pre = pre->next;
    }
    pre->next = p->next;
    free(p);
}

int delete_info(Node* h)
{
    Node* p, * k[20];
    int i, j, sum;
    char na[20], po[20], nu[20];
    printf("你想以何种形式查询你想删除的项目：\n");
    printf("1.姓名 2.职务 3.工号\n");
    scanf("%d", &i);
    switch (i)
    {
    case 1:
        printf("请输入姓名：\n");
        scanf("%s", &na);
        p = search_name(h, na);
        if (p)
        {
            delete_node(h, p);
            /*travel(h);*/
            return 1;
        }
        else
        {
            printf("不存在这个人！\n");
            return 0;
        }
        break;
    case 2:
        printf("请输入单位：\n");
        scanf("%s", &po);
        p = search_post(h, po);
        if (p)
        {
            delete_node(h, p);
            /*travel(h);*/
            return 1;
        }
        else
        {
            printf("不存在这个人！\n");
            return 0;
        }
        break;
    case 3:
        printf("请输入工号：\n");
        scanf("%s", &nu);
        p = search_num(h, nu);
        if (p)
        {
            delete_node(h, p);
           /* travel(h);*/
            return 1;
        }
        else
        {
            printf("不存在这个人！\n");
            return 0;
        }
        break;
    default:
        printf("输入有误，请重新输入！\n");
        delete(h);
        break;
    }
}

int main()

{

    int i, j, n, ret, m;
    unsigned long nu;
    Node* h;
    printf("建立员工信息链表\n");
    h = create();
    printf("请输入操作的次数\n");
    scanf("%d", &m);
    printf("欢迎来到员工信息管理系统！\n");
    for (int a = 1; a <= m; a++)
    {
        menu();
        printf("请选择你的操作：\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("请输入你想插入员工信息的数量：\n");
            scanf("%d", &n);
            for (j = 0; j < n; j++)insert(h);
            travel(h);
            break;
        case 2:
            printf("请输入你想删除员工信息的数量：\n");
            scanf("%d", &n);
            for (j = 0; j < n; j++) delete_info(h);
            travel(h);
            break;
        case 3:
            printf("请输入你想查询员工信息的数量：\n");
            scanf("%d",&n);
            for (j = 0; j < n; j++) search(h);
            break;
        default:
            printf("你的输入有误，请重新输入！\n");
        }
    }
}



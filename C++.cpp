#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10000
int time=1;
struct node
{
    char ID[15];
    char name[10];
    char sex[10];
    char class[10];
    char riqi[10];
} stu[M];
int n=0;
void input();
void dele();
void zm();
void list();
void gai();
int main()
{
    char c;
    while(1)
    {
        system("cls");
        zm();
        c=getchar();
        switch(c)
        {
        case '1':
            input();
            break;
        case '2':
            dele();
            break;
        case '3':
            list();
            break;
        case '4':
            gai();
            break;
        case '0':
            exit(0);
        default:
            printf("输入错误，请重新输入\n");
        }
    }
}
void zm()
{
    printf("       ****************哈理工新生档案管理系统****************\n");
    printf("       *                     1.新建信息                     *\n");
    printf("       *                     2.删除信息                     *\n");
    printf("       *                     3.显示信息                     *\n");
    printf("       *                     4.修改信息                     *\n");
    printf("       *                     0.QUIT                     *\n");
    printf("       ****************哈理工新生档案管理系统****************\n");
    printf("                            输入序号");
}
void input()
{
    while(1)
    {
        system("cls");
        printf("\n\n\n********** 输 入 信 息 **********\n");
        printf("\n           请输入学生档案信息\n");
        printf("学号:");
        scanf("%s",stu[time].ID);
        printf("姓名:");
        scanf("%s",stu[time].name);
        printf("性别:");
        scanf("%s",stu[time].sex);
        printf("班级:");
        scanf("%s",stu[time].class);
        printf("建档日期:");
        scanf("%s",stu[time].riqi);
        time++;
        printf("是否重新输入（Y/N）?");
        getchar();
        char counfirm[10];
        gets(counfirm);
        if (strcmp(counfirm,"Y")!=0)
        {
            system("cls");
            printf("\n\n\n\n\n                         ");
            printf("   【数据已添加】\n\n按回车键进入主菜单");
            getchar();
            break;
        }
    }
}
void list()
{
    int i;
    system("cls");
    printf("\n\n\n********显示所有个人信息********\n");
    printf("#Record 学号    姓名    性别 班级    建档日期\n");
    for(i=1; i<time; i++)
    {
        printf("%7d %-8s%-8s%-6s%-8s%-8s\n",i,stu[i].ID,stu[i].name,stu[i].sex,stu[i].class,stu[i].riqi);
    }
    printf("press any key continue\n ");
    fflush(stdin);
    getchar();
}
void dele()			/*按学号删除学生信息*/
{
    char str[100];
    system("cls");
    printf("\n\n\n********** 删 除 信 息 **********\n");
    printf("\n\n    请输入要删除的学生学号\n");
    scanf("%s",str);
    int mark=0;
    int i;
    for( i=1; i<time; i++)
    {
        if(strcmp(str,stu[i].ID)==0)
        {

            printf("#Record 学号    姓名    性别 班级    建档日期\n");
            printf("%7d %-8s%-8s%-6s%-8s%-8s\n",i,stu[i].ID,stu[i].name,stu[i].sex,stu[i].class,stu[i].riqi);
            mark=i;
            break;
        }
        else
        {
            mark=0;
        }
    }
    if(!mark)
    {
        printf("\t不存在该学生的信息,按ESC键返回！");
        fflush(stdin);
        getchar();
        return;
    }
    else
    {
        printf("\t确认删除学生信息吗？(Y/N):");
        fflush(stdin);
        char ch;
        ch=getchar();
        if(ch=='y'||ch=='Y')
        {
            for( i=mark; i<time-1; i++)
            {
                strcpy(stu[i].ID,stu[i+1].ID);
                strcpy(stu[i].name,stu[i+1].name);
                strcpy(stu[i].class,stu[i+1].class);
                strcpy(stu[i].sex,stu[i+1].sex);
                strcpy(stu[i].riqi,stu[i+1].riqi);
            }
            time--;
            printf("\t学生信息已删除，按任意键返回！");
        }
        else
            printf("\t按任意键返回！");
        fflush(stdin);
        getchar();
    }
    return;
}
void gai()
{

    char str[100];
    system("cls");
    printf("\n\n\n********** 修 改 信 息 **********\n");
    printf("\n\n    请输入要修改的学生学号\n");
    scanf("%s",str);
    int mark=0;
    int i;
    for( i=1; i<time; i++)
    {
        if(strcmp(str,stu[i].ID)==0)
        {

            printf("#Record 学号    姓名    性别 班级    建档日期\n");
            printf("%7d %-8s%-8s%-6s%-8s%-8s\n",i,stu[i].ID,stu[i].name,stu[i].sex,stu[i].class,stu[i].riqi);
            mark=i;
            break;
        }
        else
        {
            mark=0;
        }
    }
    if(!mark)
    {
        printf("\t不存在该学生的信息,按任意键返回！");
        fflush(stdin);
        getchar();
        return;
    }
    else
    {
        printf("\n           请重新输入该学生信息\n");
        printf("学号:");
        scanf("%s",stu[mark].ID);
        printf("性别:");
        scanf("%s",stu[mark].sex);
        printf("班级:");
        scanf("%s",stu[mark].class);
        printf("建档日期:");
        scanf("%s",stu[mark].riqi);
        printf("\n\t\t学生信息已修改，按任意键返回！");
        fflush(stdin);
        getchar();
    }
}

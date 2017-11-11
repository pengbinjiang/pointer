#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct equipment{
    int num;   //编号
    char name[20];  //名称
    char model[20];     //型号
    char factory[20];   //厂家
    char buy_date[20];  //购买日期
    struct equipment *next;
    char repair_time[20];
}Equipment;

void fprintE(Equipment *head);  //将设备信息输出到文件
void addEquipment(Equipment *head);     //添加设备
void deleteEquipment(Equipment *head,int num);  //删除设备
void changeEquipment(Equipment *head,int num);  //更新设备
void findEquipment();   //设备查找
Equipment* fscanE();  //从文件读取设备信息
void repairEquipment();     // 维修管理
void printList(Equipment *head);   //输出设备信息列表
int checkNum(Equipment *head, int num);

//将设备信息输出到文件
void addEquipment(Equipment *head){
    Equipment *tail = head;
    while(tail->next!=NULL) tail = tail->next;
    Equipment *newnode = (Equipment*)malloc(sizeof(Equipment));
    printf("请输入设备编号：");
    scanf("%d",&newnode->num);
    if(checkNum(head,newnode->num)){
        printf("输入编号已有，输入失败！");
        return;
    }
    printf("请输入设备名称：");
    scanf("%s",&newnode->name);
    printf("请输入设备型号：");
    scanf("%s",&newnode->model);
    printf("请输入设备厂家：");
    scanf("%s",&newnode->factory);
    printf("请输入设备购买日期：");
    scanf("%s",&newnode->buy_date);
    tail->next = newnode;
    newnode->next = NULL;
    fprintE(head);
    printf("录入成功！");
}

//将链表输入到文件
void fprintE(Equipment *head){
    FILE *fp=fopen("data.txt","w");
    Equipment *current = head->next;
    while(current){
        fprintf(fp,"%d\n",current->num);
        fprintf(fp,"%s\n",current->name);
        fprintf(fp,"%s\n",current->model);
        fprintf(fp,"%s\n",current->factory);
        fprintf(fp,"%s\n",current->buy_date);
        //printf("%d %s %s %s %s ",current->num,current->name,current->model,current->factory,current->buy_date);
        current = current->next;
    }
    fclose(fp);
}

//删除设备
void deleteEquipment(Equipment *head,int num){
    if(head->next==NULL){
        printf("没有设备！请先录入设备！");
        return;
    }
    Equipment *current = head;
    Equipment *current_next = current->next;
    while(current_next){
        if(current_next->num==num){
            current->next = current_next->next;
            printf("删除成功！");
            fprintE(head);
            return;
        }
        current = current->next;
        current_next = current_next->next;
    }
    printf("删除失败，没有找到设备编号！");
}

//设备更新
void changeEquipment(Equipment *head,int num){
    if(head->next==NULL){
        printf("没有设备！请先录入设备！");
        return;
    }
    Equipment *current = head->next;
    while(current && (current->num!=num)){
        current = current->next;
    }
    if(current!=NULL){
        printf("请输入更新后的数据：\n");
        printf("请输入设备编号：");
        scanf("%d",current->num);
        printf("请输入设备名称：");
        scanf("%s",current->name);
        printf("请输入设备型号：");
        scanf("%s",current->model);
        printf("请输入设备厂家：");
        scanf("%s",current->factory);
        printf("请输入设备购买日期：");
        scanf("%s",current->buy_date);
        fprintE(head);
    }else{
        printf("操作失败，没有找到设备编号！");
    }
}

//设备查找
void findEquipment(){
    Equipment *head = fscanE();
    if(head->next==NULL){
        printf("没有设备！请先录入设备！");
        return;
    }
    int num;
    printf("请输入查找设备的编号：");
    scanf("%d",&num);
    while(head){
        if(head->num==num){
            printf("编号为%d的信息为：\n",num);
            printf("编号：%d\n",head->num);
            printf("名称：%s\n",head->name);
            printf("型号：%s\n",head->model);
            printf("厂家：%s\n",head->factory);
            printf("生产日期：%s\n",head->buy_date);
            return;
        }
        head = head->next;
    }
    printf("查找失败，没有找到设备编号！");

}

//从文件读取设备信息
Equipment* fscanE(){
    Equipment *head1 = (Equipment*)malloc(sizeof(Equipment));
    head1->next = NULL;
    Equipment *current = head1;
    FILE *fp = fopen("data.txt","r");
    while(!feof(fp)){
        Equipment *newnode = (Equipment*)malloc(sizeof(Equipment));
        fscanf(fp,"%d\n",&newnode->num);
        fscanf(fp,"%s\n",newnode->name);
        fscanf(fp,"%s\n",newnode->model);
        fscanf(fp,"%s\n",newnode->factory);
        fscanf(fp,"%s\n",newnode->buy_date);
        current->next = newnode;
        newnode->next = NULL;
        current = current->next;
    }
    close(fp);
    return head1;
}

//维修信息管理
void repairEquipment(){
    int num;
    int oper;
    char time[16];
    printf("请输入维修操作（1~2）：\n1.记录\t2.查找\n");
    scanf("%d",&oper);
    getchar();
    switch(oper){
        case 1:{
            FILE *fp = fopen("myfile.txt","a");
            printf("请输入维修编号：");
            scanf("%d",&num);
            printf("请输入维修时间（xxxx-xx-xx）:");
            scanf("%s",&time);
            fprintf(fp,"%d\n",num);
            fprintf(fp,"%s\n",time);
            fflush(fp);
            close(fp);
            printf("记录成功！");
            break;
        }case 2:{
            int t = 0;
            printf("请输入查找编号：");
            scanf("%d",&num);
            int rnum;
            FILE *fp = fopen("myfile.txt","r");
            while(!feof(fp)){
                fscanf(fp,"%d\n",&rnum);
                fscanf(fp,"%s\n",&time);
                if(rnum==num){
                    printf("编号：%d，维修时间：%s\n",rnum,time);
                    t = 1;
                }
            }
            if(t==0){
                printf("查询错误，没有找到维修记录！");
            }
            close(fp);
            break;
        }
        default:{
            printf("输入有误，操作失败！");
        }
    }
}

//输出设备信息列表
void printList(Equipment *head){
    if(head->next==NULL){
        printf("没有设备，请先录入设备！");
        return;
    }
    Equipment *current = head->next;
    printf("=====================================================\n");
    printf("    编号  名称  型号      厂家      生产日期  \n");
    while(current){
        printf("\t%d\t%s\t%s\t%s\t%s\n",current->num,current->name,current->model,current->factory,current->buy_date);
        current = current->next;
    }
    printf("===================================================\n");
}

//检查设备编号是否相同
int checkNum(Equipment *head, int num){
    if(head->next==NULL) return 0;
    Equipment *current = head->next;
    while(current){
        if(current->num == num){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main(){
    Equipment *head = (Equipment*)malloc(sizeof(Equipment));
    head->next = NULL;
    int num = -1;
    while(num!=0){
        printf("~~~~~~~~~~~~~欢迎进入实验室设备管理系统！~~~~~~~~~~~\n");
        printf("\n~~~~~~~~~~请输入您选择的操作（0~7）：~~~~~~~~~~~~~~\n");
        printf("1.设备信息录入\t2.设备信息更改\t");
        printf("3.设备信息删除\n4.设备查找\t5.维修记录管理\t6.显示所有设备\n\t7.关于\t\t\t0.退出\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        scanf("%d",&num);
        int num1;
        system("cls");
        switch(num){
            case 0:{break;}
            case 1:{
                addEquipment(head);
                break;
            }
            case 2:{
                printf("请输入更改信息的设备编号：");
                scanf("%d",&num1);
                getchar();
                changeEquipment(head,num1);
                break;
            }
            case 3:{
                printf("请输入需要删除的设备编号：");
                scanf("%d",&num1);
                getchar();
                deleteEquipment(head,num1);
                break;
            }
            case 4:{
                findEquipment();
                break;
            }
            case 5:{
                repairEquipment();
                break;
            }case 6:{
                printList(head);
                break;
            }case 7:{
                printf("*************************************\n");
                printf("\t实验名称：实验室设备管理系统\n");
                printf("\t系统版本：2.0\n");
                printf("\t系统作者：pisces_hao\n");
                printf("*************************************\n");
                break;
            }
            default:{
                printf("输入有误，操作失败！");
            }
        }
        system("Pause");
        system("cls");

    }

    return 0;
}


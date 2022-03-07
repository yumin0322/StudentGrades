#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>
#define MAX_SIZE 100 //�ִ� �л���
#define SUBJECT 3 //�����


struct info
{
    char name[10];
    int id, gender, korean, math, english, total;
    double avr;
    char grade;

};

typedef struct info ST;

void input_info(ST *stu); //���� �Է¹޴� �Լ�
char check_grade(double avr); // ��� ���� �ռ�
void print_info(ST *stu, int count); // ���� ��� �Լ�
void searching(ST *stu); //�˻���� �Լ�
void remove_info(ST *stu); // ���� ���� �Լ�
void rewrite(ST *stu);// �����Լ�
void ranking(ST *stu); //���� ��������or�������� ���� �Լ�
void new_info(ST *stu);//���ο� �л� ����, ���� �Է�

int i=0, count=0;

int main()
{
    ST stu[MAX_SIZE];

    int menu=0;
    int flag=0;

    printf("\t+++++++++++++++++++++++++++++");
    printf("\n\t����� �л����� �Է��Ͻÿ�.\n");
    printf("\t+++++++++++++++++++++++++++++");
    printf("\n\t>> ");
    scanf("%d", &count);

    while(!flag)
    {
        printf("\n\t===========================================\n");
        printf("\t1. �����Է� \t");
        printf("2. ������� \t");
        printf("3. �����˻� \n\n");
        printf("\t4. �������� \t");
        printf("5. �������� \t");
        printf("6. ���Ȯ�� \n\n");
        printf("\t7. �������� \t");
        printf("8. ���� \n");
        printf("\t===========================================");
        printf("\n\t>> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1 : input_info(stu);getchar();getchar();system("cls");break;
            case 2 : print_info(stu, count);getchar();getchar();system("cls");break;
            case 3 : searching(stu);getchar();getchar();system("cls");break;
            case 4 : remove_info(stu);getchar();getchar();system("cls");break;
            case 5 : rewrite(stu);getchar();getchar();system("cls");break;
            case 6 : ranking(stu);getchar();getchar();system("cls");break;
            case 7 : new_info(stu);getchar();getchar();system("cls");break;
            case 8 : flag=1;
        }
    }


    return 0;
}
void input_info(ST *stu)
{
    for(i=0;i<count;i++)
    {
        stu[i].name[0]=rand()%26+'A';
        stu[i].name[1]=rand()%26+'A';
        stu[i].name[2]=rand()%26+'A';
        stu[i].name[3]=NULL;

        stu[i].id=rand()%(9999-1000+1)+1000;
        stu[i].gender=rand()%2;
        stu[i].korean=rand()%101;
        stu[i].math=rand()%101;
        stu[i].english=rand()%101; //������ �̿�

        stu[i].total=stu[i].korean+stu[i].math+stu[i].english;
        stu[i].avr=stu[i].total/SUBJECT;
        stu[i].grade=check_grade(stu[i].avr);
    }

    printf("\n\t���� �Է� �Ϸ�.\n");

    return;

}
char check_grade(double avr)
{
    char grade = 0;

    if(avr>=90.0)
    {
        grade='A';
    }else if(avr>=80.0)
    {
        grade='B';
    }else if(avr>=70.0)
    {
        grade='C';
    }else if(avr>=60.0)
    {
        grade='D';
    }else
    {
        grade='F';
    }


    return grade;
}
void print_info(ST *stu, int count)
{
    for(i=0;i<count;i++)
    {
        printf("\n\t%d. [�̸�]%s [�й�]%d [����]%s [����]%d [����]%d [����]%d [����]%d [���]%.2lf [���]%c\n", i+1, stu[i].name, stu[i].id, (stu[i].gender==1)?"��":"��", stu[i].korean, stu[i].math, stu[i].english, stu[i].total, stu[i].avr, stu[i].grade);
        printf("\t-----------------------------------------------------------------------------------------");
    }
    return;
}
void searching(ST *stu)
{
    char name[10]="";
    int flag=0;
    printf("\n\t*************************");
    printf("\n\t�˻��� �̸��� �Է��Ͻÿ�.\n");
    printf("\n\t>> ");
    scanf("%s", &name);
    printf("\t-----------------------------------------------------------------------------------------");

    for(i=0;i<count;i++)
    {
        if(!strnicmp(&stu[i].name[0], &name[0], 3)) //���ڿ��� ��Ҹ� ���Ͽ� �˻����
        {

            print_info(&stu[i],1);
            printf("\n\t �˻��� �Ϸ��߽��ϴ�.");
            flag=1;break;
        }
    }
    if(!flag)
    {
        printf("\n\t�ش�Ǵ� �̸��� �����ϴ�.");
    }





    return;
}
void remove_info(ST *stu)
{
    char name[10]="";
    int flag=0;
    printf("\n\t*************************");
    printf("\n\t������ �̸��� �Է��Ͻÿ�.\n");
    printf("\n\t>> ");
    scanf("%s", &name);

    for(i=0;i<count;i++)
    {
        if(!strnicmp(&stu[i].name[0], &name[0], 3))
        {
            strcpy(&stu[i].name,"");
            stu[i].id=0;
            stu[i].gender=0;
            stu[i].korean=0;
            stu[i].math=0;
            stu[i].english=0;
            stu[i].total=stu[i].korean+stu[i].math+stu[i].english;
            stu[i].avr=stu[i].total/SUBJECT;
            stu[i].grade=check_grade(stu[i].avr);


            printf("\n\t������ �Ϸ��߽��ϴ�.");
            flag=1;
        }

    }
    if(!flag)
    {
        printf("\n\t�ش�Ǵ� �̸��� �����ϴ�.");
    }


    return;
}
void rewrite(ST *stu)
{
    char name[10]="";
    int flag=0;
    printf("\n\t*************************");
    printf("\n\t������ �̸��� �Է��Ͻÿ�.\n");
    printf("\n\t>> ");
    scanf("%s", &name);

    for(i=0;i<count;i++)
    {
        if(!strnicmp(&stu[i].name[0], &name[0], 3))
        {
            printf("\n\t--------------------------------");
            printf("\n\t%s �� ������ ����(%d) ���� : ", stu[i].name, stu[i].korean);
            scanf("%d", &stu[i].korean);
            printf("\n\t%s �� ������ ����(%d) ���� : ", stu[i].name, stu[i].math);
            scanf("%d", &stu[i].math);
            printf("\n\t%s �� ������ ����(%d) ���� : ", stu[i].name, stu[i].english);
            scanf("%d", &stu[i].english);

            stu[i].total=stu[i].korean+stu[i].math+stu[i].english;
            stu[i].avr=stu[i].total/SUBJECT;
            stu[i].grade=check_grade(stu[i].avr);

            printf("\n\t--------------------------------\n");
            printf("\n\t������ �Ϸ��߽��ϴ�.");

            flag=1;break;

        }
    }
    if(!flag)
    {
        printf("�ش�Ǵ� �̸��� �����ϴ�.");
    }



    return;

}
void ranking(ST *stu)
{
    ST stu_v[MAX_SIZE];
    ST stu_copy[MAX_SIZE];
    int j =0, sort=0;

    for(i=0;i<count;i++)
    {
        memcpy(&stu_copy[i], &stu[i], sizeof(stu[i])); //��� ������ �����Ͽ� ���纻 ����, ������ �����ϱ� ����
    }

    for(i=0;i<count-1;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(stu_copy[i].total<stu_copy[j].total)
            {
                memcpy(&stu_v, &stu_copy[i], sizeof(stu[i]));
                memcpy(&stu_copy[i], &stu_copy[j], sizeof(stu[i]));
                memcpy(&stu_copy[j], &stu_v, sizeof(stu[i]));
            }

        }
    }

    print_info(stu_copy, count);

    return;
}
void new_info(ST *stu)
{

    if(count+1>=MAX_SIZE)
    {
        printf("\n\t�Է¼��� �ʰ��߽��ϴ�.");
    }

    count++; //�Է��� �л� �� �ϳ��� ���ϰ�

    printf("\n\t-----------------------------------------");
    printf("\n\t�߰��� �л��� �̸��� �Է��Ͻÿ�. : "); //count-1�ڸ��� �߰� �Է�
    scanf("%s", &stu[count-1].name);
    printf("\n\t�߰��� �л��� �й��� �Է��Ͻÿ�. : ");
    scanf("%d", &stu[count-1].id);
    printf("\n\t�߰��� �л��� ������ �Է��Ͻÿ�. : ");
    scanf("%d", &stu[count-1].gender);
    printf("\n\t�߰��� �л��� ���� ������ �Է��Ͻÿ�. : ");
    scanf("%d", &stu[count-1].korean);
    printf("\n\t�߰��� �л��� ���� ���� �Է��Ͻÿ�. : ");
    scanf("%d", &stu[count-1].math);
    printf("\n\t�߰��� �л��� ���� ���� �Է��Ͻÿ�. : ");
    scanf("%d", &stu[count-1].english);
    printf("\n\t-----------------------------------------");

    stu[count-1].total=stu[count-1].korean+stu[count-1].math+stu[count-1].english;
    stu[count-1].avr=stu[count-1].total/SUBJECT;
    stu[count-1].grade=check_grade(stu[count-1].avr);

    printf("\n\t�߰� �Է��� ���ƽ��ϴ�.");


    return;
}

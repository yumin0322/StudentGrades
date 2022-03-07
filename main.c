#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>
#define MAX_SIZE 100 //최대 학생수
#define SUBJECT 3 //과목수


struct info
{
    char name[10];
    int id, gender, korean, math, english, total;
    double avr;
    char grade;

};

typedef struct info ST;

void input_info(ST *stu); //성적 입력받는 함수
char check_grade(double avr); // 등급 지정 합수
void print_info(ST *stu, int count); // 성적 출력 함수
void searching(ST *stu); //검색기능 함수
void remove_info(ST *stu); // 정보 삭제 함수
void rewrite(ST *stu);// 수정함수
void ranking(ST *stu); //성적 오름차순or내림차순 정렬 함수
void new_info(ST *stu);//새로운 학생 정보, 성적 입력

int i=0, count=0;

int main()
{
    ST stu[MAX_SIZE];

    int menu=0;
    int flag=0;

    printf("\t+++++++++++++++++++++++++++++");
    printf("\n\t등록할 학생수를 입력하시오.\n");
    printf("\t+++++++++++++++++++++++++++++");
    printf("\n\t>> ");
    scanf("%d", &count);

    while(!flag)
    {
        printf("\n\t===========================================\n");
        printf("\t1. 성적입력 \t");
        printf("2. 성적출력 \t");
        printf("3. 성적검색 \n\n");
        printf("\t4. 성적삭제 \t");
        printf("5. 성적수정 \t");
        printf("6. 등수확인 \n\n");
        printf("\t7. 성적삽입 \t");
        printf("8. 종료 \n");
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
        stu[i].english=rand()%101; //랜덤값 이용

        stu[i].total=stu[i].korean+stu[i].math+stu[i].english;
        stu[i].avr=stu[i].total/SUBJECT;
        stu[i].grade=check_grade(stu[i].avr);
    }

    printf("\n\t성적 입력 완료.\n");

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
        printf("\n\t%d. [이름]%s [학번]%d [성별]%s [국어]%d [수학]%d [영어]%d [총점]%d [평균]%.2lf [등급]%c\n", i+1, stu[i].name, stu[i].id, (stu[i].gender==1)?"남":"여", stu[i].korean, stu[i].math, stu[i].english, stu[i].total, stu[i].avr, stu[i].grade);
        printf("\t-----------------------------------------------------------------------------------------");
    }
    return;
}
void searching(ST *stu)
{
    char name[10]="";
    int flag=0;
    printf("\n\t*************************");
    printf("\n\t검색할 이름을 입력하시오.\n");
    printf("\n\t>> ");
    scanf("%s", &name);
    printf("\t-----------------------------------------------------------------------------------------");

    for(i=0;i<count;i++)
    {
        if(!strnicmp(&stu[i].name[0], &name[0], 3)) //문자열의 대소를 비교하여 검색기능
        {

            print_info(&stu[i],1);
            printf("\n\t 검색을 완료했습니다.");
            flag=1;break;
        }
    }
    if(!flag)
    {
        printf("\n\t해당되는 이름이 없습니다.");
    }





    return;
}
void remove_info(ST *stu)
{
    char name[10]="";
    int flag=0;
    printf("\n\t*************************");
    printf("\n\t삭제할 이름을 입력하시오.\n");
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


            printf("\n\t삭제를 완료했습니다.");
            flag=1;
        }

    }
    if(!flag)
    {
        printf("\n\t해당되는 이름이 없습니다.");
    }


    return;
}
void rewrite(ST *stu)
{
    char name[10]="";
    int flag=0;
    printf("\n\t*************************");
    printf("\n\t수정할 이름을 입력하시오.\n");
    printf("\n\t>> ");
    scanf("%s", &name);

    for(i=0;i<count;i++)
    {
        if(!strnicmp(&stu[i].name[0], &name[0], 3))
        {
            printf("\n\t--------------------------------");
            printf("\n\t%s 의 수정할 국어(%d) 점수 : ", stu[i].name, stu[i].korean);
            scanf("%d", &stu[i].korean);
            printf("\n\t%s 의 수정할 수학(%d) 점수 : ", stu[i].name, stu[i].math);
            scanf("%d", &stu[i].math);
            printf("\n\t%s 의 수정할 영어(%d) 점수 : ", stu[i].name, stu[i].english);
            scanf("%d", &stu[i].english);

            stu[i].total=stu[i].korean+stu[i].math+stu[i].english;
            stu[i].avr=stu[i].total/SUBJECT;
            stu[i].grade=check_grade(stu[i].avr);

            printf("\n\t--------------------------------\n");
            printf("\n\t수정을 완료했습니다.");

            flag=1;break;

        }
    }
    if(!flag)
    {
        printf("해당되는 이름이 없습니다.");
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
        memcpy(&stu_copy[i], &stu[i], sizeof(stu[i])); //모든 정보를 복사하여 복사본 정렬, 원본을 보존하기 위해
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
        printf("\n\t입력수를 초과했습니다.");
    }

    count++; //입력할 학생 수 하나를 더하고

    printf("\n\t-----------------------------------------");
    printf("\n\t추가할 학생의 이름을 입력하시오. : "); //count-1자리에 추가 입력
    scanf("%s", &stu[count-1].name);
    printf("\n\t추가할 학생의 학번을 입력하시오. : ");
    scanf("%d", &stu[count-1].id);
    printf("\n\t추가할 학생의 성별을 입력하시오. : ");
    scanf("%d", &stu[count-1].gender);
    printf("\n\t추가할 학생의 국어 점수를 입력하시오. : ");
    scanf("%d", &stu[count-1].korean);
    printf("\n\t추가할 학생의 수학 점수 입력하시오. : ");
    scanf("%d", &stu[count-1].math);
    printf("\n\t추가할 학생의 영어 점수 입력하시오. : ");
    scanf("%d", &stu[count-1].english);
    printf("\n\t-----------------------------------------");

    stu[count-1].total=stu[count-1].korean+stu[count-1].math+stu[count-1].english;
    stu[count-1].avr=stu[count-1].total/SUBJECT;
    stu[count-1].grade=check_grade(stu[count-1].avr);

    printf("\n\t추가 입력을 마쳤습니다.");


    return;
}

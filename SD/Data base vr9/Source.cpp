#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

const int N = 10;

struct EM
{
    char name[256];
    int work;
    char address[256];
    int num;
    int id;
} EM_list[N];

struct WK
{
    char name[256];
    int work;
    char address[256];
    int num;
    int id;
} WK_list[N];

enum Job
{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
};

void init_list();
void init_listW();
int find_free(void);
int find_freeW(void);
int menu_select(void);
int menu_search(void);
int menu_delete(void);
void enter();
void enterW();
void delet();
void deletW();
void list();
void listW();
void search();
void searchW();
void sort�hoice();
void sort�hoiceW();
void searchName();
void searchNameW();
//

void init_list()
{
    register int t;

    for (t = 0; t < N; ++t)
    {
        EM_list[t].id = 0;
    }
}

void init_listW()
{
    register int t;

    for (t = 0; t < N; ++t)
    {
        WK_list[t].id = 0;
    }
}

int find_free(void)
{
    register int t;

    for (t = 0; EM_list[t].id && t < N; ++t);

 //   for (t = 0; t < N; t++);
 //   {
 //           if (EM_list[t].id == 0)
 //           {
 //               cout << "�������� ������ �����:" << t << endl;
 //           }
 //   }

    if (t == N) {
        return -1;
    }
    /* ��������� �������� ��� */
    return t;
}

int find_freeW(void)
{
    register int t;

    for (t = 0; t < N; t++);
    {
        if (WK_list[t].id != t)
        {
            cout << "�������� ������ �����:" << t << endl;
        }
    }

    if (t == N) {
        cout << "���� ���������" << endl;
        return -1;
    }
    /* ��������� �������� ��� */
    return t;
}

int menu_select(void)
{
    setlocale(LC_ALL, "ru");
    char s[80];
    int c;

    printf("1. �������� ��������\n");
    printf("2. �������� ����������\n");
    printf("3. ����������� ��������\n");
    printf("4. ����������� �����������\n");
    printf("5. �����\n");
    printf("6. �������\n");
    printf("7. ����������� ��������\n");
    printf("8. ����������� �����������\n");
    printf("9.  �����\n");
//    printf("10. �������� ���� ������\n");
//    printf("11. �����\n");

    do
    {
        printf("\n������� ����� ������� ������: ");
        gets_s(s);
        c = atoi(s);
    } while (c < 0 || c>8);

    return c;
}

int menu_search(void)
{
    setlocale(LC_ALL, "ru");
    char s[80];
    int c;
    printf("1. ����� �������� �� ID\n");
    printf("2. ����� ���������� �� ID\n");
    printf("3. ����� �������� �� ���\n");
    printf("4. ����� ���������� �� ���\n");
    printf("5. ����� �� ...\n");
    do
    {
        printf("\n������� ����� ������� ������: ");
        gets_s(s);
        c = atoi(s);
    } while (c < 0 || c>2);

    if (c == 1)
        search();
    if (c == 2)
        searchW();
    if (c == 3)
        searchName();
    if (c == 4)
        searchNameW();
    return c;
}

int menu_delete(void)
{
    setlocale(LC_ALL, "ru");
    char s[80];
    int c;
    printf("1. ������� �������� �� ID\n");
    printf("2. ������� ���������� �� ID\n");
    printf("3. ������� ��\n");
    do
    {
        printf("\n������� ����� ������� ������: ");
        gets_s(s);
        c = atoi(s);
    } while (c < 0 || c>1);

    if (c == 1)
        delet();
    if (c == 2)
        deletW();
    if (c == 3);
    return c;
}

void enter()
{
    setlocale(LC_ALL, "ru");
    int t, c, f;
    char s[80], a[80];

    t = find_free();
    if (t == -1) {
        printf("\n������ ��������\n");
        return;
    }

    printf("������� �������� �����������: ");
    gets_s(EM_list[t].name);

    printf("������� ��� ������: \n1. a\n2. b\n 3. c\n4.a\n5.b\n 6. c\n7. c\n");
    gets_s(a);
    f = atoi(a);
    EM_list[t].work = f-1;

    printf("������� �����: ");
    gets_s(EM_list[t].address);

    printf("������� �������: ");
    gets_s(s);
    c = atoi(s);
    EM_list[t].num = c;
    EM_list[t].id = t;
}

void enterW()
{
    setlocale(LC_ALL, "ru");
    int t, c, f;
    char s[80], a[1];

    t = find_freeW();
    if (t == -1) {
        printf("\n������ ��������");
        return;
    }

    printf("������� �������� �����������: ");
    gets_s(WK_list[t].name);

    printf("������� ��� ������:  \n1. a\n2. b\n 3. c\n4.a\n5.b\n 6. c\n7. c\n");
    gets_s(a);
    f = atoi(a);
    WK_list[t].work = f -1;

    printf("������� �����: ");
    gets_s(WK_list[t].address);

    printf("������� �������: ");
    gets_s(s);
    c = atoi(s);
    WK_list[t].num = c;
    WK_list[t].id = t;
}

void delet()
{
    setlocale(LC_ALL, "ru");
    register int t;
    char s[80];

    printf("������� � ������: ");
    gets_s(s);
    t = atoi(s);
    if (t >= 0 && t < N)
        EM_list[t].id = 0;
}

void deletW()
{
    setlocale(LC_ALL, "ru");
    register int t;
    char s[80];

    printf("������� � ������: ");
    gets_s(s);
    t = atoi(s);
    if (t >= 0 && t < N)
        WK_list[t].id = 0;
}

void list()
{
    register int t;

    for (t = 0; t < N; t++) {
  
            printf("�������� �����������: ");
            printf("%s\n", EM_list[t].name);
            printf("��� ������:");
            Job stat = static_cast<Job>(EM_list[t].work);
            if (stat == a)
                cout << "..1.." << endl;
            if (stat == b)
                cout << "..2.." << endl;
            if (stat == c)
                cout << "..3.." << endl;
            if (stat == d)
                cout << "..4.." << endl;
            if (stat == e)
                cout << "..5.." << endl;
            if (stat == f)
                cout << "..6.." << endl;
            if (stat == g)
                cout << "..7.." << endl;
            printf("�����: ");
            printf("%s\n", EM_list[t].address);
            printf("�������: ");
            printf("%lu\n\n", EM_list[t].num);
            printf("����� ������: ");
            printf("%lu\n\n", EM_list[t].id);
        
    }
    printf("\n\n");
}

void listW()
{
    register int t;

    for (t = 0; t < N; t++) {
        if (WK_list[t].id == t) {
            printf("�������� �����������: ");
            printf("%s\n", WK_list[t].name);
            printf("��� ������: \n1. a\n2. b\n 3. c\n4.a\n5.b\n 6. c\n7. c\n");
            Job stat = static_cast<Job>(WK_list[t].work);
            if (stat == a)
                cout << "..1.." << endl;
            if (stat == b)
                cout << "..2.." << endl;
            if (stat == c)
                cout << "..3.." << endl;
            if (stat == d)
                cout << "..4.." << endl;
            if (stat == e)
                cout << "..5.." << endl;
            if (stat == f)
                cout << "..6.." << endl;
            if (stat == g)
                cout << "..7.." << endl;
            printf("�����: ");
            printf("%s\n", WK_list[t].address);
            printf("�������: ");
            printf("%lu\n\n", WK_list[t].num);
            printf("����� ������: ");
            printf("%lu\n\n", WK_list[t].id);
        }
    }
    printf("\n\n");
}

void search()
{
    register int t;
    char s[10];
    printf("������� � ������: ");
    gets_s(s);
    t = atoi(s);

    if (EM_list[t].id == t) {
        printf("�������� �����������: ");
        printf("%s\n", EM_list[t].name);
        printf("��� ������: \n1. a\n2. b\n 3. c\n4.a\n5.b\n 6. c\n7. c\n");
        Job stat = static_cast<Job>(EM_list[t].work);
        if (stat == a)
            cout << "..1.." << endl;
        if (stat == b)
            cout << "..2.." << endl;
        if (stat == c)
            cout << "..3.." << endl;
        if (stat == d)
            cout << "..4.." << endl;
        if (stat == e)
            cout << "..5.." << endl;
        if (stat == f)
            cout << "..6.." << endl;
        if (stat == g)
            cout << "..7.." << endl;
        printf("�����: ");
        printf("%s\n", EM_list[t].address);
        printf("�������: ");
        printf("%lu\n\n", EM_list[t].num);
        printf("����� ������: ");
        printf("%lu\n\n", EM_list[t].id);
    }
}

void searchW()
{
    register int t;
    char s[10];
    printf("������� � ������: ");
    gets_s(s);
    t = atoi(s);

    if (WK_list[t].id == t) {
        printf("�������� �����������: ");
        printf("%s\n", WK_list[t].name);
        printf("��� ������: \n1. a\n2. b\n 3. c\n4.a\n5.b\n 6. c\n7. c\n");
        Job stat = static_cast<Job>(WK_list[t].work);
        if (stat == a)
            cout << "..1.." << endl;
        if (stat == b)
            cout << "..2.." << endl;
        if (stat == c)
            cout << "..3.." << endl;
        if (stat == d)
            cout << "..4.." << endl;
        if (stat == e)
            cout << "..5.." << endl;
        if (stat == f)
            cout << "..6.." << endl;
        if (stat == g)
            cout << "..7.." << endl;
        printf("�����: ");
        printf("%s\n", WK_list[t].address);
        printf("�������: ");
        printf("%lu\n\n", WK_list[t].num);
        printf("����� ������: ");
        printf("%lu\n\n", WK_list[t].id);
    }
}

void sort�hoice()
{
    int smallest_id;

    for (int i = 0; i < N; i++) {
        smallest_id = i;
        for (int j = i + 1; j < N; j++) {
            if (EM_list[j].id < EM_list[smallest_id].id)
                smallest_id = j;
        }

        swap(EM_list[smallest_id].num, EM_list[i].num);
        swap(EM_list[smallest_id].name, EM_list[i].name);
        swap(EM_list[smallest_id].work, EM_list[i].work);
        swap(EM_list[smallest_id].address, EM_list[i].address);
        swap(EM_list[smallest_id].id, EM_list[i].id);
    }
}

void sort�hoiceW()
{
    int smallest_id;

    for (int i = 0; i < N; i++) {
        smallest_id = i;
        for (int j = i + 1; j < N; j++) {
            if (WK_list[j].id < WK_list[smallest_id].id)
                smallest_id = j;
        }

        swap(WK_list[smallest_id].num, WK_list[i].num);
        swap(WK_list[smallest_id].name, WK_list[i].name);
        swap(WK_list[smallest_id].work, WK_list[i].work);
        swap(WK_list[smallest_id].address, WK_list[i].address);
        swap(WK_list[smallest_id].id, WK_list[i].id);
    }
}

void searchName()
{
    char v[256];
    printf("������� �/�/�: ");
    gets_s(v);

    for (int j = 0; j < N; j++)
    {
        string s = EM_list[j].name;
        int i = 0;
        for (i = s.find(v, i++); i != string::npos; i = s.find(v, i + 1))
        {
            printf("%s\n", EM_list[j].name);
            printf("%lu\n", EM_list[j].work);
            printf("%s\n", EM_list[j].address);
            printf("%lu\n\n", EM_list[j].num);
            printf("%lu\n\n", EM_list[j].id);
        }
    }
}

void searchNameW()
{
    char v[256];
    printf("������� �/�/�: ");
    gets_s(v);

    for (int j = 0; j < N; j++)
    {
        string s = WK_list[j].name;
        int i = 0;
        for (i = s.find(v, i++); i != string::npos; i = s.find(v, i + 1))
        {
            printf("%s\n", WK_list[j].name);
            printf("%lu\n", WK_list[j].work);
            printf("%s\n", WK_list[j].address);
            printf("%lu\n\n", WK_list[j].num);
            printf("%lu\n\n", WK_list[j].id);
        }
    }
}


int main()
{
    char choice, count, count1;

    init_list();
    init_listW();/* ������������� ������� �������� */

    for (;;) {
        choice = menu_select();
        switch (choice) {
        case 1: system("cls"), enter(),system("pause"), system("cls"); break;
        case 2: system("cls"), enterW(), system("pause"), system("cls"); break;
        case 3: system("cls"), list(), system("pause"), system("cls"); break;
        case 4: system("cls"), listW(), system("pause"), system("cls"); break;
        case 5: system("cls"), menu_search(), system("pause"), system("cls"); break;
        case 6: system("cls"), menu_delete(), system("pause"), system("cls"); break;
        case 7: system("cls"), sort�hoice(), system("pause"), system("cls"); break;
        case 8: system("cls"), sort�hoiceW(), system("pause"), system("cls"); break;
        case 9: exit(0); break;
//        case 10: list(); break;
//        case 11: exit(0); break;
//        case 6: deletall(); break;
//        case 7: exit(0);
        }
    }
}
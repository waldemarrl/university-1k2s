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

struct addr {
    char name[256];
    char work[256];
    char address[256];
    int num;
    int id;
} addr_list[N];


void init_list()
{
    register int t;

    for (t = 0; t < N; ++t)
    {
        addr_list[t].name[0] = 0;
    }
}

int find_free(void)
{
    register int t;

    for (t = 0; addr_list[t].name[0] && t < N; ++t);

    if (t == N)
        return -1; /* ��������� �������� ��� */
    return t;
}

int menu_select(void)
{
    setlocale(LC_ALL, "ru");
    char s[80];
    int c;

    printf("1. ������� ���\n");
    printf("2. ������� ���\n");
    printf("3. �������� ������\n");
    printf("4. �������� 1\n");
    printf("5. ����� �� ID\n");
    printf("6. �������� ���� ������\n");
    printf("6. �����\n");

    do
    {
        printf("\n������� ����� ������� ������: ");
        gets_s(s);
        c = atoi(s);
    } while (c < 0 || c>6);

    return c;
}


void enter()
{
    setlocale(LC_ALL, "ru");
    int t, c;
    char s[80];

    t = find_free();
    if (t == -1) {
        printf("\n������ ��������");
        return;
    }

    printf("������� ��� ������������: ");
    gets_s(addr_list[t].name);

    printf("������� ��� ������: ");
    gets_s(addr_list[t].work);

    printf("������� �����: ");
    gets_s(addr_list[t].address);

    printf("������� �������: ");
    gets_s(s);
    c = atoi(s);
    addr_list[t].num = c;
    addr_list[t].id = t;
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
        addr_list[t].name[0] = 0;
}

void list()
{
    register int t;

    for (t = 0; t < N; t++) {
        if (addr_list[t].name[0]) {
            printf("%s\n", addr_list[t].name);
            printf("%s\n", addr_list[t].work);
            printf("%s\n", addr_list[t].address);
            printf("%lu\n\n", addr_list[t].num);
        }
    }
    printf("\n\n");
}

void listone()
{
    register int t;
    char s[10];
    printf("������� � ������: ");
    gets_s(s);
    t = atoi(s);

    if (addr_list[t].name[0]) {
        printf("%s\n", addr_list[t].name);
        printf("%s\n", addr_list[t].work);
        printf("%s\n", addr_list[t].address);
        printf("%lu\n\n", addr_list[t].num);
    }
}

void searchId()
{
    register int t;
    char s[10];
    printf("������� � ������: ");
    gets_s(s);
    t = atoi(s);

    if (addr_list[t].id == t)
    {
        printf("%s\n", addr_list[t].name);
        printf("%s\n", addr_list[t].work);
        printf("%s\n", addr_list[t].address);
        printf("%lu\n\n", addr_list[t].num);
    }

}

void deletall()
{
    setlocale(LC_ALL, "ru");
    register int t;
    t = 0;
    for (int i = 0; i < N; i++)
    {
        if (t >= 0 && t < N)
            addr_list[t].name[0] = 0;
        t++;
    }
}



int main()
{
    char choice;

    init_list(); /* ������������� ������� �������� */

    for (;;) {
        choice = menu_select();
        switch (choice) {
        case 1: enter(); break;
        case 2: delet(); break;
        case 3: list(); break;
        case 4: listone(); break;
        case 5: searchId(); break;
        case 6: deletall(); break;
        case 7: exit(0);
        }
    }
}
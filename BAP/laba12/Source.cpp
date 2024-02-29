#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stdio.h>
#include <malloc.h>


typedef struct 
{
    int  key;
} ITEM;

class HEAP 
{
public:
    ITEM* h;
    int  size;

    HEAP(unsigned int n) 
    {
        size = 0;
        h = (ITEM*)malloc(sizeof(ITEM) * n);
    }

    ~HEAP() 
    {
        if (h) free(h);
    }

    int add(ITEM x)
    {
        h[++size] = x;
        checkup(size);
        return 1;
    }

    int extract_min(ITEM* x)
    {
        if (size == 0) 
            return 0;

        *x = h[1];
        h[1] = h[size--];
        checkdown(1);
        return 1;
    }

    int getmin(ITEM* x)
    {
        if (size == 0) 
            return 0;

        *x = h[1 + 1];
        h[1 + 1] = h[size--];
        checkdown(1 + 1);
        return 2;
    }


private:
    void checkup(int c) 
    {
        int p;
        p = c / 2;

        if (p == 0)
            return;

        if (h[p].key > h[c].key) 
        {
            ITEM tmp;
            tmp = h[p]; h[p] = h[c]; h[c] = tmp;
            checkup(p);
        }
    }

    void checkdown(int p) 
    {
        int c;
        c = 2 * p;

        if (c > size) 
            return;

        if (c + 1 <= size && h[c + 1].key < h[c].key)
            c++;

        if (h[c].key < h[p].key) 
        {
            ITEM tmp;
            tmp = h[c]; h[c] = h[p]; h[p] = tmp;
            checkdown(c);
        }
    }
};

int main()
{
    HEAP heap(1000);
    int n, i;
    ITEM x;

    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        scanf("%d", &x.key);
        heap.add(x);
    }

    while (heap.extract_min(&x)) 
    {
        printf("%d ", x.key);
    }

    system("pause");

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x.key);
        heap.add(x);
    }
    
    while (heap.getmin(&x))
    {
            printf("%d ", x.key);
    }

    return 0;
}
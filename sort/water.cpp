#include <iostream>
#include <algorithm>

using namespace std;

struct bucket
{
    int left;
    int right;

    int top;
    int bottom;
}

struct bucketEvent
{
    bool starts;

    int height;
    int width;
}

bool comp(bucketEvent a , bucketEvent b)
{
    return a.height > b.height;
}

int count_buckets(bucket T[] , int N , int A)
{
    bucketEvent TE[2*N];

    for(int i =0; i<N ; i++)
    {
        TE[2*i].starts = true;
        TE[2*i].height = T[i].bottom;
        TE[2*i].width = T[i].right - T[i].left;

        TE[2*i+1].starts = false;
        TE[2*i+1].height = T[i].top;
        TE[2*i+1].width = T[i].right - T[i].left;
    }

    sort(TE , comp);

    int count = 0;
    int curWidth = 0;
    int lastHeight = 0;
    int i=0;
    while(A>=0)
    {
        if(TE[i].starts)
        {
            A-= curWidth*(TE[i].height - lastHeight);
            curWidth+= TE[i].width;
        }else
        {
            A-= curWidth*(TE[i].height - lastHeight);
            curWidth-= TE[i].width;

            if(A>=0)
                count++;
        }

        lastHeight = TE[i].height;
        i++;
    }

    return count;
}
//graph node definition()
#include <bits/stdc++.h>

using namespace std;
struct node
  {
    int pos;
    struct node *next;
  };

void linkedListDefine(const int n,const int m,const vector<vector<int> > &v)
  {
    struct node *first[n+1],*p;
    for (int i=1;i<=n;i++)
      {
        first[i]=NULL;
      }
    for (int i=1;i<=m;i++)
      {
        p=(struct node *)malloc(sizeof(struct node));
        p->pos=i;
        p->next=first[v[i][0]];
        first[v[i][0]]=p;
      }
    for (int i=1;i<=n;i++)
      {
        cout<<i<<":";
        if (first[i]==NULL) 
          {
            cout<<"null"<<endl;
            continue;
          }
        for (p=first[i];p!=NULL;p=p->next)
          {
            cout<<v[p->pos][1]<<" ";
          }
        cout<<endl;
      }
  }

void arrayDefine(int n,int m,vector<vector<int> > &v)
  {
    vector<int> first(n+1,-1);
    vector<int> next(m+1,-1);

    for (int i=1;i<=m;i++)
      {
        next[i]=first[v[i][0]];
        first[v[i][0]]=i;
      }

    for (int i=1;i<=n;i++)
      {
        cout<<i<<":";
        if (first[i]==-1) 
          {
            cout<<"null"<<endl;
            continue;
          }
        for (int pos=first[i];pos!=-1;pos=next[pos])
          {
            cout<<v[pos][1]<<" ";
          }
        cout<<endl;
      }
  }

int main(void)
  {
    vector<vector<int> > v={{0,0,0},{1,4,9},{4,3,8},{1,2,5},{2,4,6},{1,3,7}}; //{0,0,0}占位元素
    int n=4,m=5;
    //链表表示
    linkedListDefine(n,m,v);
    cout<<endl;
    //数组表示
    arrayDefine(n,m,v);

    return 0;
  }
//Bellman-Ford Algorithm
#include <bits/stdc++.h>

using namespace std;
int inf=INT16_MAX;
void printMap(const vector<vector<int>> map,int n,int m)
  {
    for (int i=1;i<=n;i++)
      {
        for (int j=1;j<=n;j++)
          {
            if (map[i][j]==inf)
              {
                printf("%2d ",0);
                continue;
              }
            printf("%2d ",map[i][j]);
          }
        cout<<endl;
      }
    cout<<endl;
  }

int main(void)
  {
    vector<vector<int> > v={{0,0,0},{2,3,2},{1,2,-3},{1,5,5},{4,5,2},{3,4,3},{4,3,5},{5,1,3}}; //{0,0,0}占位元素
    //vector<vector<int> > v={{0,0,0},{2,3,2},{1,2,-3},{1,5,5},{4,5,2},{3,4,3},{4,3,5},{5,1,3},{2,1,-1}}; //有负权回路
    int n=5,m=v.size()-1;
    vector<vector<int> > map(n+1,vector<int>(n+1,inf));
    for (int i=1;i<n;i++)
      {
        map[i][i]=0;
      }
    for (int i=1;i<=m;i++)
      {
        map[v[i][0]][v[i][1]]=v[i][2];
      }
    printMap(map,n,m);
    
    for (int i=1;i<=n;i++)
      {
        vector<int> dis(n+1,inf);
        dis[i]=0;
        
        for (int j=1;j<=n-1;j++)
          {
            bool check=false;
            for (int k=1;k<=m;k++)
              {
                if (dis[v[k][0]]!=inf&&dis[v[k][1]]>dis[v[k][0]]+v[k][2])
                  {
                    dis[v[k][1]]=dis[v[k][0]]+v[k][2];
                    check=true;
                  }
              }
            if (check==false) break;
          }
        bool flag=false;
        for (int k=1;k<=m;k++)
          {
            if (dis[v[k][0]]!=inf&&dis[v[k][1]]>dis[v[k][0]]+v[k][2])
              {
                flag=true;
                break;
              }
          }
        if (flag==true)
          {
            cout<<"Detect Negative Cycle!"<<endl; //存在负权回路
            return 0;
          }
        map[i]=dis;
      }

    printMap(map,n,m);
    return 0;
  }
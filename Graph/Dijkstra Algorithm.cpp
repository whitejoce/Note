//Dijkstra algorithm
#include <bits/stdc++.h>

using namespace std;
int inf=INT16_MAX;
void printMap(const vector<vector<int> > &map)
  {
    int n=map.size(),m=map[0].size();
    for (int i=0;i<n;i++)
      {
        for (int j=0;j<m;j++)
          {
            if (map[i][j]==inf)
              {
                printf("%d ",0);
                continue;
              }
            printf("%d ",map[i][j]);
          }
        cout<<endl;
      }
    cout<<endl;
  }

int main(void)
  {
    vector<vector<int>> map={{0,1,inf,inf,2},
                             {3,0,3,4,inf},
                             {inf,inf,0,7,6},
                             {inf,2,1,0,inf},
                             {3,inf,5,inf,0}};

    int n=map.size(),m=map[0].size();
    printMap(map);
    
    for (int i=0;i<n;i++)
      {
        vector<int> dis(n,inf);
        vector<bool> vis(n,false);
        dis[i]=0;
        for (int j=0;j<n;j++)
          {
            int u=-1,minDis=inf;
            for (int k=0;k<n;k++)
              {
                if (vis[k]==false&&dis[k]<minDis)
                  {
                    u=k;
                    minDis=dis[k];
                  }
              }
            if (u==-1)
              {
                break;
              }
            vis[u]=true;
            for (int v=0;v<n;v++)
              {
                if (vis[v]==false&&map[u][v]!=inf&&dis[v]>dis[u]+map[u][v])
                  {
                    dis[v]=dis[u]+map[u][v];
                  }
              }
          }
        map[i]=dis;
      }

    printMap(map);
    return 0;
  }
//Floyd-Warshall algorithm
#include <bits/stdc++.h>

using namespace std;
int main(void)
  {
    int inf=INT16_MAX;
    vector<vector<int>> map={{0,1,inf,inf,2},
                             {3,0,3,4,inf},
                             {inf,inf,0,7,6},
                             {inf,2,1,0,inf},
                             {3,inf,5,inf,0}};

    int n=5,m=5;
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
    for (int i=0;i<n;i++)
      {
        for (int j=0;j<m;j++)
          {
            for (int k=0;k<n;k++)
              {
                //避免inf相加溢出
                if (map[i][k]<inf&&map[k][j]<inf&&map[i][j]>map[i][k]+map[k][j])
                  {
                    map[i][j]=map[i][k]+map[k][j];
                  }
                //map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
              }
          }
      }
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
    return 0;
  }
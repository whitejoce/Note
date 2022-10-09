//Bellman-Ford Algorithm
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
    vector<vector<int> > map={{0,-3,inf,inf,5},
                              {inf,0,2,inf,inf},
                              {inf,inf,0,3,inf},
                              {inf,inf,5,0,2},
                              {3,inf,inf,inf,inf}};   
    /*
    //有负权回路
    vector<vector<int> > map={{0,-3,inf,inf,5},
                              {-1,0,2,inf,inf},
                              {inf,inf,0,3,inf},
                              {inf,inf,5,0,2},
                              {3,inf,inf,inf,inf}}; 
    */
    int n=map.size(),m=map[0].size();    
    printMap(map);
    
    for (int i=0;i<n;i++)
      {
        vector<int> dis(n,inf);
        dis[i]=0;
        
        for (int j=0;j<n-1;j++)
          {
            bool check=false;
            for (int u=0;u<n;u++)
              {
                for (int v=0;v<n;v++)
                  {
                    if (dis[u]!=inf&&dis[v]>dis[u]+map[u][v])
                      {
                        dis[v]=dis[u]+map[u][v];
                        check=true;
                      }
                  }
              }
            if (check==false) break;
          }
        bool flag=false;
        for (int u=0;u<n;u++)
          {
            for (int v=0;v<n;v++)
              {
                if (dis[u]!=inf&&dis[v]>dis[u]+map[u][v])
                  {
                    flag=true;
                    break;
                  }
              }
          }
        if (flag==true)
          {
            cout<<"Detect Negative Cycle!"<<endl; //存在负权回路
            return 0;
          }
        map[i]=dis;
      }

    printMap(map);
    return 0;
  }
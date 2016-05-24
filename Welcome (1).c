#include "simpletools.h"  
#include "abdrive.h"    
#include "ping.h" 
#include "q.h" 

int ok=0;
int a[17][17],n=16,facing=1,visited[16],path_io[20];
//1-down  2-right 3-left 4-up


int Epath(int i1,int j1,int i2,int j2)
{   
    int p=0;
    
    cout<<'\n'<<i1<<','<<j1<<' '<<i2<<','<<j2<<'\n';
    cout<<"Is path between "<<(i1-2)*4+j1<<" and "<<(i2-2)*4+j2<<' ';
    cin>>p;

    if(p==1)
    {
     a[(i1-2)*4+j1][(i2-2)*4+j2]=1;
     a[(i2-2)*4+j2][(i1-2)*4+j1]=1;
    }   
    return p;
}


void DFS(int x,int y)
{
 int i,j;
 visited[(x-2)*4+y]=1;
 //(x-2)*4+y
 //  4
 //3   2
 //  1
if(facing==1) //DOWN
{
    if(visited[(x-1)*4+y]==0 && x+1>=2 && x+1<=5 && y>= 1 && y<=4 && Epath(x,y,x+1,y)==1)   //DOWN
    {
        facing=1;
        DFS(x+1,y);
        DFS(x,y);
    }
    else if(visited[(x-2)*4+y+1]==0 && x>=2 && x<=5 && y+1>= 1 && y+1<=4 && Epath(x,y,x,y+1)==1)    //RIGHT
    {
        facing=2;
        DFS(x,y+1);
        DFS(x,y);
    }
    else if(visited[(x-2)*4+y-1]==0 && x>=2 && x<=5 && y-1>= 1 && y-1<=4 && Epath(x,y,x,y-1)==1)    //LEFT
    {
        facing=3;
        DFS(x,y-1);
        DFS(x,y);
    }
}   
else if(facing==2)  //RIGHT
{
    if(visited[(x-2)*4+y+1]==0 && x>=2 && x<=5 && y+1>= 1 && y+1<=4 && Epath(x,y,x,y+1)==1)     //RIGHT
    {
        facing=2;
        DFS(x,y+1);
        DFS(x,y);
    } 
    else if(visited[(x-3)*4+y]==0 && x-1>=2 && x-1<=5 && y>= 1 && y<=4 && Epath(x,y,x-1,y)==1)      //UP
    {
        facing=4;
         DFS(x-1,y);
         DFS(x,y);

    }
    else if(visited[(x-1)*4+y]==0 && x+1>=2 && x+1<=5 && y>= 1 && y<=4 && Epath(x,y,x+1,y)==1)      //DOWN
    {
        facing=1;
        DFS(x+1,y);
        DFS(x,y);
    }
}
else if(facing==3)  //LEFT
{
    if(visited[(x-2)*4+y-1]==0 && x>=2 && x<=5 && y-1>= 1 && y-1<=4 && Epath(x,y,x,y-1)==1)     //LEFT
    {
        facing=3;
        DFS(x,y-1);
        DFS(x,y);
    }
    else if(visited[(x-3)*4+y]==0 && x-1>=2 && x-1<=5 && y>= 1 && y<=4 && Epath(x,y,x-1,y)==1)      //UP
    {
        facing=4;
         DFS(x-1,y);
         DFS(x,y);
    }
    else if(visited[(x-1)*4+y]==0 && x+1>=2 && x+1<=5 && y>= 1 && y<=4 && Epath(x,y,x+1,y)==1)      //DOWN
    {
        facing=1;
        DFS(x+1,y);
        DFS(x,y);
    }
}
else if(facing==4)      //UP
{   
    if(visited[(x-3)*4+y]==0 && x-1>=2 && x-1<=5 && y>= 1 && y<=4 && Epath(x,y,x-1,y)==1)       //UP
    {
        facing=4;
         DFS(x-1,y);
         DFS(x,y);

    }
    else if(visited[(x-2)*4+y-1]==0 && x>=2 && x<=5 && y-1>= 1 && y-1<=4 && Epath(x,y,x,y-1)==1)        //LEFT
    {
        facing=3;
        DFS(x,y-1);
        DFS(x,y);
    }
    else if(visited[(x-2)*4+y+1]==0 && x>=2 && x<=5 && y+1>= 1 && y+1<=4 && Epath(x,y,x,y+1)==1)        //RIGHT
    {
        facing=2;
        DFS(x,y+1);
        DFS(x,y);
    }

}   
}

void dij()
{
 int infinity = 999;
 int distance[17];
 int visit[17];
 int path[17];
 int min;
 int nextNode = 0;

    for (int i = 1; i <= n; i++)
    {
     visit[i] = 0;
     path[i] = 0;
        
     for (int j = 1; j <= n; j++) 
     if (a[i][j] == 0) 
         a[i][j] = 999;
    }

    for (int i = 1; i <= n; i ++) 
    distance[i] = a[1][i];


    distance[1] = 0;
    visit[1] = 1;


    // START
    for (int i = 1; i <= n; i++) 
    {
    min = infinity;
    for (int j = 1 ; j <= n; j++) 
    if (min > distance[j] && visit[j] != 1) 
    {
        min = distance[j];
        nextNode = j;
    }
    
    visit[nextNode] = 1;
    


    for (int c = 1; c <= n; c++) 
    if (visit[c] != 1) 
    if (min + a[nextNode][c] < distance[c]) 
    {
        distance[c] = min + a[nextNode][c];
        path[c] = nextNode;
    }                
}

// printing the paths
// shortest path from 0 to j

int j = 16,contor=0;
printf("distance = %d\n", distance[j]);
printf("path = %d" , j);
path_io[contor++] =j;

do {
    j = path[j];
    path_io[contor++]=j;
    } while (j != 0);

path_io[contor-1]=1;

for(j=contor-1;j>=0;j--)
cout<<path_io[j]<<' '; 
cout<<'\n';


}

int main()                                      
{
  
 low(26);                                      
 low(27);
 DFS(2,1);
 dij();
 move(1);

 for(int i=contor-2;i>=0;i--)
 if(path_io[i]==path_io[i-1]+4)
 goDown(facing,1);
 else if(path_io[i]==path_io[i-1]+1)
 goRight(facing,1);
 else if(path_io[i]==path_io[i-1]-1)
 goLeft(facing,1);
 else if(path_io[i]==path_io[i-1]-4)
 goUp(facing,1);
 // 1.1 visit all the maze
 // 2.3 drive to finish


}



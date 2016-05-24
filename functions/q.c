#include "q.h"
#include "simpletools.h"
#include "abdrive.h"
#include "ping.h" 





// 1.1 visit all the maze
// 2.3 drive to finish





float calc_irLeft()         //calculating the distances
{
  float irLeft=0;
  
     for(int dacVal = 0; dacVal <   320; dacVal += 16)   
    { 
      dac_ctr(26, 0, dacVal);
      freqout(11, 1, 38000); 
      irLeft += input(10); 
      
    }
    
  return irLeft;
}

float calc_irRight()        //calculating the distances
{
  float irRight=0;
  
     for(int dacVal = 0; dacVal <   320; dacVal += 16)   
    { 
     dac_ctr(27, 1, dacVal);
      freqout(1, 1, 38000);
      irRight += input(2);  
      
    }
    
  return irRight;
}


void turnRight()
{
    drive_goto(26,-25);
}

void turnLeft()
{
    drive_goto(-26,25);
}

void turnAround()
{
    drive_goto(51,-51); 
}


void goDown(int facing,int distance)
{
 if (facing==2)
 turnRight();
 else if (facing==3)
 turnLeft();
 else if (facing==4)
  turnAround();
 move(distance);

}

void goUp(int facing,int distance)
{
 if (facing==1)
 turnAround();
 else if (facing==2)
 turnLeft();
 else if (facing==3)
 turnRight();
 move(distance);
}

void goLeft(int facing,int distance)
{
 if (facing==1)
 turnRight();  
 else if (facing==2)
 turnAround();
 else if (facing==4)
 turnLeft();
  move(distance)
}

void goRight(int facing,int distance)
{
 if (facing==1)
 turnLeft();
 else if (facing==3) 
 turnAround();
 else if (facing==4)
 turnLeft();
 move(distance)
}

void move (int x) // 1 for move forward, -1 for move backwards etc.
{
    if(x>0) for(int count=1; count <=x; count++)
    {
      drive_speed(41, 41);
      pause(100);
      if( getleftdistance() < 7 ) drive_speed(43, 41);
      if( getrightdistance() < 7) drive_speed(41, 43);
      pause(100);
      if( getleftdistance() < 7 ) drive_speed(43, 41);
      else if( getrightdistance() < 7) drive_speed(41, 43);
      else drive_speed(41, 41);
      pause(100);
    }
    else for(int count=-1; count >=x; count--)
    {
      drive_speed(-41, -41);
      pause(100);
      if( getleftdistance() < 7) drive_speed(-43, -41);
      if( getrightdistance() < 7) drive_speed(-41, -43);
      pause(100);
      if( getleftdistance() < 7) drive_speed(-43, -41);
      else if( getrightdistance() < 7) drive_speed(-41, -43);
      else drive_speed(-41, -41);
      pause(100);
    }
    drive_speed(0,0);
}





/*

int walk_back()
{
 if(list == NULL)      // if the stack is empty stop the robot
 {
   drive_speed(0,0); 
   return 1;
  }
 else          //otherwise set speed
 {
  int val=pop_node(&list);
  setSpeed(val); 
  return 0;    
 }                    
 pause(148); 
  
}



int CheckObstacle()
{
  return ping_cm(8);
}  





/////////linked list///////////

struct node{
    int val;
    struct node *next;
}*list=NULL;


void push_node(struct node** list, int val)
{
  struct node *new_node = (struct node*) malloc(sizeof(struct node));

  new_node->val = val;
  new_node->next = *list;
  *list = new_node;
}

int pop_node(struct node** list){
  int val = 0;
  struct node* next = NULL;
  
  next = (*list)-> next;
  val = (*list)-> val;
  free (*list);
  *list = next;
  return val;
}




/////////Calculating the speed ///////////

void setSpeed (int q)     
{                         
 int ls=35,rs=35,cons=5;     
   
       
 if(q<0)     
 {  
  rs = rs - (cons * q);
  drive_speed(ls,rs);
 }
 else
 {
  ls = ls + (cons * q);              
  drive_speed(ls,rs);
 }
}  




void turn_around()
{
  drive_goto(((52.9/3.25) * 3.14) +0.5, (((52.9/3.25) * 3.14) +0.5) * -1);
}




void calc_distances()
{
  int dif = 0,ndif=0;
  double desiredValue = 10; 

  dif = desiredValue - calc_irLeft(); 
  ndif = dif*-1;
  add_p(ndif);
  setSpeed(dif); 
}




void add_p(int val)
{
  push_node(&list, val); 
}
*/
#include "q.h"
#include "simpletools.h"
#include "abdrive.h"
#include "ping.h" 





// 1.1 visit all the maze
// 1.2 store data 
// 2.1 make the tree
// 2.2 find the opposite corner
// 2.3 drive to finish
















/*
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
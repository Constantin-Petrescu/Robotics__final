#ifndef _Q_H_
#define _Q_H_



// 1.1 visit all the maze
// 1.2 store data 
// 2.1 make the tree
// 2.2 find the opposite corner
// 2.3 drive to finish



float calc_irLeft();
float calc_irRight();
void turnRight();
void turnLeft();
void turnAround();
void goDown(int facing,int distance);
void goUp(int facing,int distance);
void goLeft(int facing,int distance);
void goRight(int facing,int distance);
void move (int x);

/*
float calc_irLeft();
float calc_irRight();

int CheckObstacle();
int walk_back();

void setSpeed(int val);
void turn_around();
void calc_distances();
void add_p(int val);
*/
#endif
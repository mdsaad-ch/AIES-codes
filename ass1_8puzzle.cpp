
#include <iostream>
using namespace std;
struct Node{
    int puzzle[3][3];
    int x,y;
    int g,h,f;
};

int calculate(int puzzle[3][3],int goal[3][3]){
    int h=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(puzzle[i][j]!=0 && puzzle[i][j]!=goal[i][j]){
                h++;
            }
        }
    }
    return h;
}
void printpuzzle(int puzzle[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(puzzle[i][j]==0)
                cout<<"_ ";
            else
                cout<<puzzle[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void copypuzzle(int source[3][3], int dest[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dest[i][j] = source[i][j];
        }
    }
}
int main(){
    Node current;
    int goal[3][3];
    cout<<"Enter the initial state(for blank type 0):"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>> current.puzzle[i][j];
            if(current.puzzle[i][j]==0){
                current.x=i;
                current.y=j;
            }
        }
    }
    cout<<"Enter the goal state(0 for blank tile):"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> goal[i][j];
        }
    }
    current.g=0;
    current.h=calculate(current.puzzle,goal);
    current.f=current.g+current.h;
    while(true){
        cout<<"Current State:"<<endl;
        printpuzzle(current.puzzle);
        cout << "g = " << current.g << endl;
        cout << "h = " << current.h << endl;
        cout << "f = " << current.f << endl << endl;
         if(current.h == 0)
        {
            cout << "Goal Reached!" << endl;
            break;
        }
     Node best;
     best.f=999;
     if(current.x - 1 >= 0) //for moving up
        {
            Node child;
            copypuzzle(current.puzzle, child.puzzle);
            swap(child.puzzle[current.x][current.y], child.puzzle[current.x - 1][current.y]);
            child.x = current.x - 1;
            child.y = current.y;
            child.g = current.g + 1;
            child.h = calculate(child.puzzle, goal);
            child.f = child.g + child.h;

            if(child.f < best.f)
                best = child;
        }
        if(current.x+1<3){ //for moving down
            Node child;
            copypuzzle(current.puzzle,child.puzzle);
            swap(child.puzzle[current.x][current.y], child.puzzle[current.x+1][current.y]);
            child.x=current.x+1;
            child.y=current.y;
            child.g=current.g+1;
            child.h=calculate(child.puzzle,goal);
            child.f=child.g+child.h;
            if(child.f<best.f)  best=child;
        }
        if(current.y-1>=0){  //moving left
            Node child;
         copypuzzle(current.puzzle,child.puzzle);
            swap(child.puzzle[current.x][current.y], child.puzzle[current.x][current.y-1]);
            child.x=current.x;
            child.y=current.y-1;
            child.g=current.g+1;
            child.h=calculate(child.puzzle,goal);
            child.f=child.g+child.h;
            if(child.f<best.f)  best=child;
        }
         if(current.y+1<3){  //moving right
         Node child;
         copypuzzle(current.puzzle,child.puzzle);
            swap(child.puzzle[current.x][current.y], child.puzzle[current.x][current.y+1]);
            child.x=current.x;
            child.y=current.y+1;
            child.g=current.g+1;
            child.h=calculate(child.puzzle,goal);
            child.f=child.g+child.h;
            if(child.f<best.f)  best=child;
        }
        current =best;
        }
    }
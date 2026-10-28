#include <iostream>
using namespace std;

int graph[10][10];
int tour[10];
int visited[10];
int n;

int minDistance = 9999;
int bestTour[10];

void calculateDistance()
{
    int distance = 0;

    for(int i = 0; i < n - 1; i++)
    {
        distance += graph[tour[i]][tour[i + 1]];
    }

    distance += graph[tour[n - 1]][tour[0]];

    if(distance < minDistance)
    {
        minDistance = distance;

        for(int i = 0; i < n; i++)
        {
            bestTour[i] = tour[i];
        }
    }
}

void generateTour(int position)
{
    if(position == n)
    {
        calculateDistance();
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            tour[position] = i;

            generateTour(position + 1);

            visited[i] = 0;
        }
    }
}

int main()
{
   
     cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter distance matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    /*n = 4;
        int temp[4][4] = {
         {0, 400, 200, 300},
            {400, 0, 300, 500},
         {200, 300, 0, 400},
            {300, 500, 400, 0}
        };

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = temp[i][j];
        }
    }
*/
    generateTour(0);

    cout << "Best Tour: ";

    for(int i = 0; i < n; i++)
    {
        cout << bestTour[i] << " ";
    }

    cout << bestTour[0];

    cout << "\nMinimum Distance = " << minDistance;

    return 0;
}
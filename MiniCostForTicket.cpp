#include <bits/stdc++.h>
using namespace std;

// infinite value
#define INF INT_MAX

// Number of statioin
#define N 4

// return minimum cost for shortest path from source 's' to destination 'd'
int minCostRec(int cost[][N], int s, int d)
{
    // base case
    // if source is same as destination or destination is next to source
    if (s == d || s + 1 == d)
        return cost[s][d];

    // initialize min cost as direct ticket from source to destinatioin
    int min = cost[s][d];

    // try every intermediate vertex to find minimum
    for (int i = s + 1; i < d; i++)
    {
        int c = minCostRec(cost, s, i) +
                minCostRec(cost, i, d);
        if (c < min)
            min = c;
    }
    return min;
}
// this funct. return the smallest possible cost to reach station
//  N-1 from station 0. This function mainly uses minCostRec().
int minCost(int cost[][N])
{
    return minCostRec(cost, 0, N - 1);
}
int main()
{
    int cost[N][N] = {{0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}};

    cout << "The Minimum cost to reach station "
         << N << " is " << minCost(cost);
    return 0;
}
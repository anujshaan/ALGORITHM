//C++ code for krushkal's algorithm
#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int source;
    int destination;
    int weight;
};
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int v, int *parent)
{
    if(parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}
void kruskals(Edge *arr, int v, int e)
{
    // sort the array into ascending order
    sort(arr, arr+e, compare);

    Edge *ans = new Edge[v-1];

    int *parent = new int[v];
    for(int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while(count != v-1) {
        Edge current = arr[i];



        //Check if we can add current edge in MST

        int sourceParent = findParent(current.source, parent);
        int destParent = findParent(current.destination, parent);

        if(sourceParent != destParent)
        {
            ans[count] = current;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    for(int i = 0; i < v-1; i++)
    {   if(ans[i].source < ans[i].destination){
            cout <<"\n" << ans[i].source << " " << ans[i].destination << " " << ans[i].weight;
    }

    else
            cout <<"\n" << ans[i].destination << " " << ans[i].source << " " << ans[i].weight;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    Edge *arr = new Edge[e];
    for(int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        arr[i].source = s;
        arr[i].destination = d;
        arr[i].weight = w;

    }
    cout << "MST will be: \ns,d,e:";

    kruskals(arr, v, e);

}

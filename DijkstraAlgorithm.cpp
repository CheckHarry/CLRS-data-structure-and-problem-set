#include <vector>
#include "heap.h"
using namespace std;



struct node{
    int index;
    vector<int> *D;
    bool operator<(node& y){
        return (*D)[(*this).index] > (*D)[y.index];
    };
    bool operator>(node& y){
        return (*D)[(*this).index] < (*D)[y.index];
    };
};


vector<int> DijkstraAlgorithm(vector<vector<vector<int>>>& adj_list , int s){
    vector<int> D(adj_list.size() , 21000000);
    vector<node> vec;
    D[s] = 0;
    for (int i = 0 ; i < adj_list.size() ; i ++){
        node x;
        x.index = i;
        x.D = &D;
        vec.push_back(x);
    }
    heap H(vec);
    while(H.size() != 0){
        node u = H.extract_max();
        for (vector<int>& v : adj_list[u.index]){
            if (D[v[0]] > D[u.index] + v[1]) D[v[0]] = D[u.index] + v[1];
            H.build_heap();
        }
    }
    return D;
}

vector<vector<vector<int>>> convert(vector<vector<int>>& edges){
    int Max = 0;
    for (vector<int>& v : edges){
        Max = max(v[0] , Max);
        Max = max(v[1] , Max);
    }
    vector<vector<vector<int>>> to_return(Max + 1 , vector<vector<int>> {});
    for (vector<int>& edge : edges) to_return[edge[0]].push_back({edge[1] , edge[2]});
    return to_return;
}

/*
int main(){
    vector<vector<int>> edges{
        {0 , 1 , 10},
        {0 , 2 , 5},
        {1 , 2 , 2},
        {1 , 3 , 1},
        {2 , 1 , 3},
        {2 , 3 , 9},
        {2 , 4 , 2},
        {3 , 4 , 4},
        {4 , 3 , 6},
        {4 , 0 , 7}
    };
    vector<vector<vector<int>>> x = convert(edges);
    vector<int> v = DijkstraAlgorithm( x , 0);
    for (int a : v) cout << a << ',';
}
*/
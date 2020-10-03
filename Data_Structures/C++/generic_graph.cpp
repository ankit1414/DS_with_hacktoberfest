#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class Graph{
    unordered_map<string,list<pair<string,int>>>m;
    public:
    Graph(){

    }
    void insert(string a,string b,int weig,bool direc=true){
        m[a].push_back(make_pair(b,weig));
        if(direc){
            m[b].push_back(make_pair(a,weig));
        }
    }
    void print(){
        for(auto &i: m){
            cout<<i.first<<"-> ";
            for(auto &j: i.second){
                cout<<"("<<j.first<<" "<<j.second<<") ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g;
    g.insert("a","b",100);
    g.insert("a","c",20,false);
    g.insert("b","d",10,false);
    g.insert("c","d",40);
    g.print();
    return 0;
}
#ifndef WN_H_
#define WN_H_

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <fstream>
#include <istream>
#include <algorithm>
#include "tree.hpp"


using namespace std;

class WordNet{
private:
    Tree* root;
public:
    WordNet(){root = NULL;}
    void BuildWordNet(string);
    void HandleTask(string);
    void PrintSuperClasses(Tree*);
    void PrintIntermediateClasses(string ,string);
    void BFS(Tree* tree);//PrintLeveOrder
    void traverse(Tree* );
    int countSpace(string );
    void findParent(Tree* , string , Tree*& );
    

};



#endif

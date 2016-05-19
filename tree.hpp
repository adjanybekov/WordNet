#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Tree {
private:
    Tree* root;

public:
    Tree(){root = NULL;//ChildOf=NULL;
        data = "";}
    Tree* ChildOf;
    int depth;
    vector<Tree*> children;
    string data;
};
#endif


#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <fstream>
#include <istream>
#include <algorithm>
#include "tree.hpp"
#include "wordnet.hpp"

void WordNet::findParent(Tree* t, string ParentData, Tree*& temp  ){ //Tree
   if(t == NULL)
        return ;
    //cout<<temp->data<<"  find  "<<ParentData<<endl;




     if(t->data == ParentData)
            {// cout<<"findParen$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
           temp = t;  return;}

    else{//cout<<"findParen$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
   // cout<<t->data<<"  find  "<<ParentData<<endl;
    for(int i = 0 ; i< t->children.size(); i++){
           findParent(t->children[i], ParentData, temp);
    }

    }}
//////////////////////////////////////////////////////////////
void WordNet::PrintSuperClasses(Tree*  tree){
	if(tree !=NULL){
		cout<<tree->data;
		if(tree->ChildOf!=NULL){
			cout<<" < ";//+ tree->data<<endl;
		}
		PrintSuperClasses(tree->ChildOf);
	}
}
////////////////////////////////////////////////////////////////////////////////////
void WordNet::PrintIntermediateClasses(string  fromTree, string untilTree){
Tree* first;
Tree* second;
 findParent(root, fromTree, first);
 findParent(root, untilTree, second);
while(1){
    if(first==NULL)break;
    if(first->data==second->data){
    cout<<first->data;
    break;
    }
    cout<< first->data;
    if(first->ChildOf!=NULL){
      cout<<" < ";//+ tree->data<<endl;
    }
    first = first->ChildOf;
}

}
//////////////////////////////////////////////////////////////////
void  WordNet::traverse(Tree* tree){

std::string tabulation = "";
if(tree!=NULL){

    for(int j = 0; j <tree->depth;j++)
       tabulation.insert(j, "  ");

    cout<<tabulation+tree->data<<endl;
}
     //tree->data = tree->ChildOf->data ;
   /* for(int j = 0; j <i;j++)
       tabulation.insert(j, " ");*/

  if (tree->children.size()==0){//cout<<"findParen$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
         return;
    }

else
    for(int i =0 ; i< tree->children.size(); i++){

        traverse(tree->children[i]);
    }
}
///////////////////////////////////////////////////////
void WordNet::BFS(Tree* tree){
queue<Tree*> q;
Tree* temp = tree;
q.push(tree);
while(!q.empty()){
        cout<<temp->data<<endl;
        for(int i =0;i<temp->children.size();i++)q.push(temp->children[i]);
        q.pop();
        temp = q.front();

}
}
////////////////////////////////////////////////////
int WordNet::countSpace(string line){
   int n = std::count(line.begin(), line.end(), ' ');
   return n;
}
//////////////////////////////////////////////////////////////////////////////////////////
void WordNet::HandleTask(string task){

    int space = countSpace(task);
    Tree* temp= NULL;
    Tree* temp2= NULL;

if(space==0){traverse(root);}

else if(space==1){
        string command = task.substr(0,task.find(" "));
        string fromTree = task.substr(task.find(" ")+1);
        //cout<<"\n";
    if(command=="PrintSuperclasses"){
        findParent(root, fromTree,temp);
    	PrintSuperClasses(temp);cout<<"\n";} 
    else
    { findParent(root, fromTree,temp);

        BFS(temp);
       // cout<<"\n";
    }
    }
else if(space==2){
        string fromTree = task.substr(task.find(" ")+1,task.rfind(" ")-task.find(" ")-1);
        string untilTree = task.substr(task.rfind(" ")+1);
        PrintIntermediateClasses(fromTree, untilTree);cout<<"\n";
        }
    }


///////////////////////////////////////////////////////////////////////////////////
void WordNet::BuildWordNet(string filename){
    ifstream myReadFile;
    const    char * cname = filename.c_str();
    myReadFile.open(cname);
    char output[100];

    if (myReadFile.is_open()) {
    std::string str;
    std::string ParentData;
    std::string ChildData;
    root = new Tree();
    root->depth = 0;
    getline(myReadFile, root->data);
    Tree* temp= NULL;// new Tree();



    while (std::getline(myReadFile, str))
        {
             //cout<<"****************************************"<<endl;


            Tree* child = new Tree();//coin isa tree
            ChildData = str.substr(0,str.find(' '));
            ParentData = str.substr(str.find("is_a")+5);
            child->data = ChildData;
           //cout<<"Parent is" + ParentData<<' '<< "Child is"+child->data<<root->data<<endl;
            temp= NULL;
            findParent(root,ParentData, temp);
          // cout<<"TEMP"+temp->data<<endl;
            Tree* parent = temp;
            child->ChildOf = parent;
            child->depth = child->ChildOf->depth+1;
            parent->children.push_back(child);

        }
        //traverse(root);
       // cout<<"Parent is" + ParentData<<' '<< "Child is"+ChildData<<endl;
     }
     myReadFile.close();
}



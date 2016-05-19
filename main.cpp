#include "wordnet.hpp"

using namespace std;

int main(){
	WordNet wn;
	wn.BuildWordNet("relations.txt");
	wn.HandleTask("PrintIntermediateClasses money medium_of_exchange");
	return 0;
}
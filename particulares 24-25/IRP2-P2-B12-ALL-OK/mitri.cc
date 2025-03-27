#include "tree.h"
#include <iostream>
using namespace std;
/*
		M
	     /     \
            C       T
           / \     / \
          A   D   O   U
           \       \   \
            B       P   V
*/

int main(){
	string iker_lladre = "MCTADOUBPV";
	
	TreePtr t = treeCreate();
	TreePtr tiker = treeCreate();
	
	treeInsert(t, 'c');
	treeInsert(t, 'd');
	treeInsert(t, 'b');
	cout << treePreOrder(t, '#') << endl;

	
	for(char c : iker_lladre){
		treeInsert(tiker, c);
		cout << "heil iker: " << treeHeight(tiker) << endl;
	}
	cout << treePreOrder(tiker, '#') << endl;
	cout << treePostOrder(tiker, '#') << endl;
	cout << treeInOrder(tiker, '#') << endl;
	cout << treeByLevels(tiker, '#') << endl;

	for(char c : iker_lladre){
		TreeNodePtr parent = treeParent(tiker, c);
		if(parent){
			cout << parent->key << endl;
		}
		else{
			cout << "sense pare" << endl;
		}
	}
	cout << treeParent(tiker, 'v') << endl;

	cout << treeParent(tiker, treeSearch(tiker, 'V'))->key << endl;

	treeDestroy(t);
	treeDestroy(tiker);
	
	return 0;
}

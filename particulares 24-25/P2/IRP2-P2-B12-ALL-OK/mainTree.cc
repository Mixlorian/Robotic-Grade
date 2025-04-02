#include "tree.h"
#include <iostream>
using namespace std;

int main(){
	TreePtr pt = treeCreate();
	
	
	cout << treeInsert(pt, 'd');
	cout << treeInsert(pt, 'c');
	cout << treeInsert(pt, 'g');
	cout << treeInsert(pt, 'a');
	cout << treeInsert(pt, 'f');
	cout << treeInsert(pt, 'h');
	cout << treeInsert(pt, 'b');
	cout << treeInsert(pt, 'e');

	cout << treeInOrder(pt, '#') << endl;
	cout << treePreOrder(pt, '#') << endl;
	cout << treePostOrder(pt, '#') << endl;

	
	return 0;
}

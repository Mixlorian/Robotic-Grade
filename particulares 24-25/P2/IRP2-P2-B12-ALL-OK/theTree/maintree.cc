#include "tree.h"

int main(){
	TreePtr arbol;

	arbol = treeCreate();
	treeInsert(arbol, 'c');
	treeInsert(arbol, 'a');
	treeInsert(arbol, 'b');
	return 0;
}

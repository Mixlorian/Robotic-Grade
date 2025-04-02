/*
	prueba treeInsert y treeRemove
*/
#include "tree.h"
#include <iostream>
using namespace std;

	
int main(){
	TreePtr t = treeCreate();
	auto r = treeInsert(t, 't');
	r = r && treeInsert(t, 'd');
	r = r && treeInsert(t, 'f');
	r = r && treeInsert(t, 'e');
	r = r && treeInsert(t, 'b');
	r = r && treeInsert(t, 'a');
	r = r && treeInsert(t, 'u');
	r = r && treeInsert(t, 'w');
	r = r && treeInsert(t, 'v');
	r = r && treeInsert(t, 'm');

	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "postorden: " << treePostOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;
	cout << "niveles: " << treeByLevels(t, '/') << endl;
	cout << "hojas: " << treeLeafTreeNodes(t) << endl;
	cout << "altura: " << treeHeight(t) << endl;
	cout << "nodos: " << treeSize(t) << endl;
	cout << "raiz: " << treeRoot(t)->key << endl;

	TreeNodePtr n = treeSearch(t, 't');
	cout << "es hoja 't': " << treeNodeIsLeaf(n) << endl;
	cout << "es hoja 'a': " << treeNodeIsLeaf(treeSearch(t, 'a')) << endl;	
	cout << "el maximo es: " << treeMaximum(t)->key << endl;

	cout << "el padre de f es: " << treeParent(t, 'f')->key << endl;
	cout << "el padre de w es: " << treeParent(t, 'w')->key << endl;

	cout << "el padre de t es: " << treeParent(t, 't') << endl;

	cout << "el padre nazi es: " << treeParent(t, treeParent(t, 'f'))->key << endl;


	cout << "borrando j: " << treeRemove(t, 'j') << endl;
	
	cout << "borrando b: " << treeRemove(t, 'b') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;


	cout << "borrando t: " << treeRemove(t, 't') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando w: " << treeRemove(t, 'w') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando f: " << treeRemove(t, 'f') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando m: " << treeRemove(t, 'm') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando u: " << treeRemove(t, 'u') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando v: " << treeRemove(t, 'v') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando d: " << treeRemove(t, 'd') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando e: " << treeRemove(t, 'e') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando a: " << treeRemove(t, 'a') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	cout << "borrando g: " << treeRemove(t, 'g') << endl;
	cout << "preorden: " << treePreOrder(t, '/') << endl;
	cout << "inorden: " << treeInOrder(t, '/') << endl;

	treeDestroy(t);

	return 0;
}


#include "tree.h"
using namespace std;


int main(){
	TreePtr t = treeCreate();

	treeInsert(t, 'f');
	treeInsert(t, 'a');
	treeInsert(t, 'b');

	NodePtr ptr = treeParent(t, nullptr);
	
	auto r = ptr == nullptr;

	ptr = treeParent(t, t->_root);
	
	r = r && ptr == nullptr;

	ptr = treeParent(t, 'f');

	r = r && ptr == nullptr;

	ptr = treeParent(t, 'x');
	
	r = r && ptr == nullptr;

	return !r;
}

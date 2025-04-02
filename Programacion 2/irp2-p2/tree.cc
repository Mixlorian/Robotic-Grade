// NIF: 07053314-L
// NOMBRE: PASCUAL CORCHERO, BORJA

#include "tree.h"
#include <queue>
using namespace std;

TreePtr      treeCreate        (){
	TreePtr pt = new Tree;
	pt->root = nullptr;
	return pt;
}

void         treeDestroy       (TreePtr t){
	if(t){
		treeMakeNull(t);
		delete t;
	}		
}

TreeNodePtr& treeRoot          (TreePtr t){
	return t->root;
}

bool         treeEmpty         (TreePtr t){
	bool empty;
	
	if(t && t->root){
		empty = false;
	}
	else{
		empty = true;
	}
	return empty;
}

bool         treeInsert        (TreePtr t, Element x){
	bool inserted = false;
	
	if(t){
		if(t->root == nullptr){
			inserted = true;
			t->root = treeNodeCreate(x);
			/*t->root = new TreeNode;
			t->root->key = x;
			t->root->lefts.root = nullptr;
			t->root->rights.root = nullptr;*/
		}
		else{
			if(x == t->root->key){
				inserted = false;
			}
			else{
				if(x < t->root->key){
					inserted = treeInsert(&(t->root->lefts), x);
				}
				else{
					inserted = treeInsert(&(t->root->rights), x);
				}
			}
		}
	}	
	return inserted;
}

Element searchAux(TreePtr t){
	Element e;
	if(t->root->lefts.root == nullptr){
		e = t->root->key;
	}
	else{
		e = searchAux(&t->root->lefts);
	}
	return e;
}

bool         treeRemove        (TreePtr t, Element x){
	bool removed = false;
	TreeNodePtr ptb;
	Element minor;
	if(t && t->root){
		if(x < t->root->key){
			removed = treeRemove(treeNodeLeftSibling(t->root), x);
		}
		else{
			if(x > t->root->key){
				removed = treeRemove(treeNodeRightSibling(t->root), x);
			}
			else{
				removed = true;
				if(treeNodeIsLeaf(t->root)){
					delete t->root;
					t->root = nullptr;
				}
				else{
					if(t->root->lefts.root && !t->root->rights.root){
						// solo hijo izquierda
						ptb = t->root;
						t->root = t->root->lefts.root;	
					}
					else{
						if(!t->root->lefts.root && t->root->rights.root){
							ptb = t->root;
							t->root = t->root->rights.root;
						}
						else{
							// has 2 childs
							minor = searchAux(&t->root->rights);
							t->root->key = minor;
							treeRemove(&t->root->rights, minor);
						}
					}
				}
			}
		}
	}
	
	return removed;
}

void         treeMakeNull      (TreePtr t){
	if(t && t->root){
		treeMakeNull(&t->root->lefts);
		treeMakeNull(&t->root->rights);
		delete t->root;
		t->root = nullptr;
	}
}

uint32_t     treeSize          (TreePtr t){
	uint32_t n = 0;
	if(t && t->root){
		n = 1 + treeSize(&t->root->lefts) + treeSize(&t->root->rights);
	}
	return n;
}

uint32_t     treeHeight        (TreePtr t){
	uint32_t h = 0, hiz, hde;
	if(t && t->root){
		if(treeNodeIsLeaf(t->root)){
			h = 0;
		}
		else{
			hde = treeHeight(&t->root->rights);
			hiz = treeHeight(&t->root->lefts);
			if(hde > hiz){
				h = 1 + hde;
			}
			else{
				h = 1 + hiz;
			}
		}
	}
	return h;	
}

uint32_t     treeLeafTreeNodes (TreePtr t){
	uint32_t nodes = 0;

	if(t && t->root){
		if(!t->root->lefts.root && !t->root->rights.root){
			nodes = 1;
		} 
		else{
			nodes = treeLeafTreeNodes(&t->root->lefts) +
			treeLeafTreeNodes(&t->root->rights);
		}
	}
	return nodes;
}

TreeNodePtr  treeSearch        (TreePtr t, Element x){
	TreeNodePtr res = nullptr;
	
	if(t && t->root){
		if(t->root->key == x){
			res = t->root;
		}
		else{
			if(x < t->root->key){
				res = treeSearch(&t->root->lefts, x);
			}
			else{
				res = treeSearch(&t->root->rights, x);
			}
		}
	}
	return res;
}

TreeNodePtr  treeParent        (TreePtr t, Element x){
	TreeNodePtr tp = nullptr;
	
	if(t && t->root){
		if(t->root->lefts.root != nullptr && t->root->lefts.root->key == x){
			tp = t->root;
		}
		else{
			if(t->root->rights.root != nullptr && t->root->rights.root->key == x){
				tp = t->root;
			}
			else{
				if(x < t->root->key){
					tp = treeParent(&t->root->lefts, x);
				}
				else{
					tp = treeParent(&t->root->rights, x);
				}
			}
		}
	}
	return tp;
}

TreeNodePtr  treeParent        (TreePtr t, TreeNodePtr p){
	TreeNodePtr tp = nullptr;
	
	if(t && t->root && p){
		if(t->root->lefts.root != nullptr && t->root->lefts.root == p){
			tp = t->root;
		}
		else{
			if(t->root->rights.root != nullptr && t->root->rights.root == p){
				tp = t->root;
			}
			else{
				if(p->key < t->root->key){
					tp = treeParent(&t->root->lefts, p);
				}
				else{
					tp = treeParent(&t->root->rights, p);
				}
			}
		}
	}
	return tp;	
}

TreeNodePtr  treeMaximum       (TreePtr t){
	TreeNodePtr p;
	
	if(t && t->root){
		if(t->root->rights.root){
			p = treeMaximum(&t->root->rights);
		}
		else{
			p = t->root;
		}
	}
	return p;	
}

std::string  treePreOrder      (TreePtr t, char c){
	std::string cad = "";
	if(t && t->root){
		cad = c + treeNodeToString(t->root) + treePreOrder(treeNodeLeftSibling(t->root), c) + treePreOrder(treeNodeRightSibling(t->root), c);
	}
	return cad;
}

std::string  treePostOrder     (TreePtr t, char c){
	std::string cad = "";
	if(t && t->root){
		cad =  treePostOrder(treeNodeLeftSibling(t->root), c) + treePostOrder(treeNodeRightSibling(t->root), c) + c + treeNodeToString(t->root);
	}
	return cad;
}

std::string  treeInOrder       (TreePtr t, char c){
	std::string cad = "";
	if(t && t->root){
		cad = treeInOrder(treeNodeLeftSibling(t->root), c) +
		c + treeNodeToString(t->root) 
		+ treeInOrder(treeNodeRightSibling(t->root), c);
	}
	return cad;
}

std::string  treeByLevels      (TreePtr t, char c){
	std::string r = "";
	queue<TreeNodePtr> q;
	TreeNodePtr p;
	if(t){
		q.push(t->root);
		while(!q.empty()){
			p = q.front();
			q.pop();
			if(p){
				r = r + c + p->key;
				q.push(p->lefts.root);
				q.push(p->rights.root);	
			}
		}
	}
	return r;
}

TreeNodePtr  treeNodeCreate        (Element e){
	TreeNodePtr p = new TreeNode;
	p->key = e;
	p->lefts.root = nullptr;
	p->rights.root = nullptr;
	return p;
}

TreePtr      treeNodeLeftSibling   (TreeNodePtr p){
	TreePtr t = nullptr;
	if(p){
		t = &(p->lefts);
	}
	return t;
}

TreePtr      treeNodeRightSibling  (TreeNodePtr p){
	if(p){
		return &(p->rights);
	}
	return nullptr;
}

Element&     treeNodeKey           (TreeNodePtr p){
	return p->key;
}

bool         treeNodeIsLeaf        (TreeNodePtr p){
	if(p){
		return !p->lefts.root && !p->rights.root;
	}
	return false;
}
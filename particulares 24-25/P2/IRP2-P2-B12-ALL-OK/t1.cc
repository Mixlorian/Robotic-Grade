
#include "list.h"

// Creamos la lista

int main(int argc, char *argv[]){
	ListPtr l = listCreate();
	int rc = l != nullptr ? 0 : 1;
	delete l;
	return rc;
}


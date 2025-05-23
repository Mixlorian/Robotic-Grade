#include "p1.h"


std::vector<int> diagonal(const TMatrix& a){
	std::vector<int> ds(a.size() + a[0].size() - 1, 0);
	int n = a.size()-1;
	int d;
	
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[i].size(); j++){
			d = i-j;
			ds[n - d] += a[i][j];		
		}
	}
	return ds;	

}
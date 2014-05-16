//csopa.h

#ifndef _csopa_h_
#define _csopa_h_
#include <iostream>

using namespace std;

class Sopa{
	private:
		int nf, nc;
		char ** m;
	public:
		Sopa();
		Sopa(int nf, int nc);
		Sopa(const Sopa &S);
		~Sopa();
		void Set(int i, int j, int v){ m[i][j] = v;}	//Inline
		char Get(int i, int j)const{return m[i][j];}	//Inline
		int GetFilas()const{return nf;}			//Inline
		int GetCols()const{return nc;}			//Inline
		void LeerSopa();
		Sopa & operator=(const Sopa &S);
		const char * operator[](int i)const;
		char operator()(int i, int j)const;
		friend istream & operator>>(istream &is, Sopa &S);//Para el cin >> M;
		friend ostream & operator<<(ostream &os,const Sopa &S);//Para el cout << M;
};

#endif
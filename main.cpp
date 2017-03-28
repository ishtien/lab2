#ifndef _FILECLASS_H
#include<iostream>
#include "fileclass.h"
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;
/*class fileclass{
public:
	int calR(float S,float E){
		int r;
//		cout<<"S="<<S<<" E="<<E<<" ";
//		cout<<"S-E="<<S-E<<" "; 
		r=R+K*(S-E);
		return r;
	}
	void setK(float k){
		K=k;
	}
	float getK(){
		return K;
	}
	void setR(float r){
		R=r;
	}
	float getR(){
		return R;
	}
private:
	float K,R;
};
*/
#endif
int main(){
	cout.unsetf(ios::scientific);
	cout.setf(ios::fixed);
	ifstream filein("file.in",ios::in);
	ofstream fileout("file.out",ios::out);
	if(!filein){
		cerr<<"failed opening"<<endl;
		exit(1);
	}
	if(!fileout){
		cerr<<"failed opening"<<endl;
		exit(1);
	}
	float K;
	float Ra,Rb;
	float Sa[7];
	float Sb[7];
	float Ea[7];
	float Eb[7];
	int Eaa[7];
	int Ebb[7];
	filein>>K>>Ra>>Rb>>Sa[1]>>Sa[2]>>Sa[3]>>Sa[4]>>Sa[5]>>Sa[6];
	for(int i=1;i<7;i++){
		Sb[i]=1-Sa[i];

	}


	fileclass A;
	fileclass B;
	A.setR(Ra);
	B.setR(Rb);

	A.setK(K);
	B.setK(K);
	fileout<<Ra<<" "<<Rb;
	fileout<<"\n";
	for(int i=1;i<7;i++){
		float x;
		Ra=A.getR();
		Rb=B.getR();
		Ea[i]=1/(1+pow(10,((Rb-Ra)/400)));
		Eb[i]=1/(1+pow(10,((Ra-Rb)/400)));

//		cout<<"Ea[i]="<<Ea[i]<<" ";
//		cout<<"Eb[i]="<<Eb[i]<<" ";

		A.setR(A.calR(Sa[i],Ea[i]));
		B.setR(B.calR(Sb[i],Eb[i]));
		
//		cout<<"Ra="<<A.getR()<<" ";
//		cout<<"Rb="<<B.getR()<<" ";

		fileout<<A.getR()<<" ";
		fileout<<B.getR()<<"\n";
	}
	return 0;
}

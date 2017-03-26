class fileclass{
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


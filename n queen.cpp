#include <iostream>
using namespace std;

bool napadajuLiSe(int ploca[][10], int red,int stupac, int n){
	for (int i=0;i<=red;i++){
		if(ploca[i][stupac]==1){
			return false;
		}
	}
	int x=red;
	int y=stupac;
	while(x>=0&&y>=0){
		if (ploca[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	x=red;
	y=stupac;
	while(x>=0&&y<n){
		if (ploca[x][y]==1){
			return false;
		}
		x--;
		y++;
}return true;}

bool rjesenje(int ploca[][10], int red, int n, int* pbrojac){
	if(red==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ploca[i][j]==1){
					cout<<"Q ";
				}else{
					cout<<"_ ";
				}
			}cout<<endl;
		}
		cout<<"---------------------------"<<endl;
		cout<<*pbrojac<<". rjesenje"<<endl;
		*pbrojac+=1;
		return false;
	}
	for(int j=0;j<n;j++){
		if(napadajuLiSe(ploca,red,j,n)){
			ploca[red][j]=1;
			
			if(rjesenje(ploca,red+1,n, pbrojac)){
				return true;
			}
		}ploca[red][j]=0;
	}return false;
}

int main(){
	int n;
	cout<<"Unesite broj n: ";
	cin>>n;
	int ploca[10][10]={0};
	int brojac = 1;
	int* pbrojac = &brojac;
	rjesenje(ploca,0,n, pbrojac);
}

#include<iostream>
using namespace std;
int main(){
	int inputer;
	cin>>inputer;
	int count=1;
	int receive=0;
	int convert_to;
	cin>>convert_to;
	int middle=0;
	while(inputer!=0){
		middle=inputer%convert_to;
		receive+=middle*count;
		count*=10;
		inputer/=convert_to;	
	}cout<<receive;
	return 0;
}

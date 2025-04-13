#include<iostream>
#include<vector>
using namespace std;
int main(){
	int give=1000000;
	int count=0;
	int middle=0;
	vector<int>list;
	while(give!=0){//该部分为10进制转7进制
		middle=give%7;
		list.push_back(middle);
		give/=7;
		count++;
	}
	int j=0,jiegguo=0;
	while(j<=count){
		jiegguo+=list[j];
		j++;
	}
	cout<<jiegguo;
	return 0;
}

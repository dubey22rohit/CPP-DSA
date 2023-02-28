#include<iostream>
using namespace std;

int length(char s[]){
	if(s[0] == '\0'){
		return 0;
	}
	int smallAns = length(s + 1);
	return smallAns + 1;
}

void removeX(char s[]){
	if(s[0] == '\0'){
		return;
	}
	if(s[0] != 'x'){
		removeX(s + 1);
	}else{
		int i = 1;
		for (; s[i] != '\0'; i++){
			s[i - 1] = s[i];
		}
		s[i - 1] = s[i];
		removeX(s);//Not calling on s +  1 because we've already shortened the string.
	}
}
int main(){
	char str[100];
	cin >> str;
	cout<<length(str)<<endl;
	removeX(str);
	cout << str << endl;
	cout<<length(str)<<endl;
	
}
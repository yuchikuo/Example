#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> top10(10);

void insert(int n)
{
	int pos;		// current position of smallest seen value
	for(int i = 0; i < top10.size(); i++)
	{
		pos = (top10[i] < top10[pos]) ? i : pos;
	}
	if(top10[pos] < n)
	{
		cout<<"Throw out " + to_string(top10[pos])<<endl;
		top10[pos] = n;	
	}
	return;
}

void findTop10(void)
{
	for(int i = 0; i < top10.size(); i++)
	{
		cout<< to_string(top10[i]) + " "; 
	}
	return;
}

int main(){
	
	string command;
	int n;
	for(int i =0;i<top10.size();i++)
	{
		top10[i] = 0;
	}
	cout<<"start"<<endl;

	while(cin>>command){
		if(command.compare("insert") == 0)
		{
			cin>>n;
			insert(n);
		}
		else if(command.compare("query") == 0)
		{
			findTop10();
		}
		else{
			cout<<"exit"<<endl;
			break;
		}
	}
	cout<<"end"<<endl;
	return 0;
}
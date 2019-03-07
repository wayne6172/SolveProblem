#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct club{
	string name;
	int size;
	vector<string> set;
}clubs[10000];

int find(char t,int size){
	int i;
	for(i = 0; i < size; i++)
		if(clubs[i].name[0] == t)
			break;
	return i;
}

vector<string> Union(int i,int j){
	vector<string> ans(clubs[i].set.size() + clubs[j].set.size());
	vector<string>::iterator it;
	
	it = set_union(clubs[i].set.begin(),clubs[i].set.end(),
		clubs[j].set.begin(),clubs[j].set.end(),ans.begin());
	
	ans.resize(it-ans.begin());
	
	return ans;
}

vector<string> intersection(int i,int j){
	vector<string> ans(clubs[i].set.size() + clubs[j].set.size());
	vector<string>::iterator it;
	
	it = set_intersection(clubs[i].set.begin(),clubs[i].set.end(),
		clubs[j].set.begin(),clubs[j].set.end(),ans.begin());
	
	ans.resize(it-ans.begin());
	
	return ans;
}


int main()
{
    int size;
    string name,command;
    
    cin >> size;
    for(int i = 0;i < size; i++){
    	cin >> clubs[i].name >> clubs[i].size;
    	for(int j = 0; j < clubs[i].size; j++){
    		cin >> name;
    		clubs[i].set.push_back(name);
    	}
    	sort(clubs[i].set.begin(),clubs[i].set.end());
    }
    
   	while(true){
   		getline(cin,command);
   		if(cin.eof())break;
   		if(command.length() == 0)continue;
   		
		//cout << command;
		
		char input[1000] = {0};
		vector<string> ans;
		
		strcpy(input,command.c_str());
		
		if(input[0] == '1'){
			ans = intersection(find(input[2],size),find(input[4],size));
			
			for(int i = 6; input[i]; i+= 2){
				int target = find(input[i],size);
				vector<string> ans2(ans.size() + clubs[target].set.size());
				vector<string>::iterator it;
				
				it = set_intersection(ans.begin(),ans.end(),clubs[target].set.begin(),clubs[target].set.end(),
					ans2.begin());
				
				ans2.resize(it-ans2.begin());
				
				ans = ans2;
			}
			
			cout << ans.size() << endl;
		}
		else {
			ans = Union(find(input[2],size),find(input[4],size));
			
			for(int i = 6; input[i]; i+= 2){
				int target = find(input[i],size);
				vector<string> ans2(ans.size() + clubs[target].set.size());
				vector<string>::iterator it;
				
				it = set_union(ans.begin(),ans.end(),clubs[target].set.begin(),clubs[target].set.end(),
					ans2.begin());
				
				ans2.resize(it-ans2.begin());
				
				ans = ans2;
			}
			
			cout << ans.size() << endl;
		}
   	}

    
    return 0;
}

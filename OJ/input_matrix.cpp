#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	int T = 3;
	while(T--)
	{
	    vector<int> input;
	    string temp;
	    vector<vector<int>> matrix;
	    while ((getline(cin, temp))&&temp!=""){
	    	for (int i=0;i<temp.size();++i){
	    		int num=0;
	    		while (temp[i]!=' '&&temp[i]!='\0'){
	    			num=num*10+(temp[i]-'0');
	    			++i;
	    		}
	    		input.push_back(num);
	    	}
	    	matrix.push_back(input);
	    	input.clear(); //每次循环需要将input数组清空
	    }
	    cout << "matrix:"<<endl;
	    for (int i=0;i<matrix.size();++i){
	    	for (int j=0;j<matrix[i].size();++j){
	    		cout<<matrix[i][j]<<' ';
	    	}
	    	cout<<endl;
	    }
	}
    return 0;
}

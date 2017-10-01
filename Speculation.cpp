//works in both Linux and Windows OS
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int max(int a,int b)  					//function which returns the greater of the two inputs a or b
{
	if(a>b)
		return a;
	else
		return b;
}

int main(int argc,char *argv[])
{
	int maxVisits,noOfDays,x;
	int answer;
	vector<int> input;					//This vector "input" stores the input of prices
	ifstream in;				
	if(argc==2)							//Checking if the program has to read a File for inputs or scan it from the command prompt
	{
		in.open(argv[1]);
		in>>noOfDays;
		in>>maxVisits;
	}
	else							
	{
		cin>>noOfDays;
		cin>>maxVisits;
		maxVisits = maxVisits+1;
	}
	for( int i=0;i<noOfDays;i++)
	{
		if(argc==2)
			in>>x;
		else
			cin>>x;
		input.push_back(x);
	}
	if(argc==2)
		in.close();
	int OPT[noOfDays][maxVisits][2];	//OPT is the 3-DIMENSIONAL Matrix

	for(int i=0;i<maxVisits;i++)		//Initializing
	{
		OPT[noOfDays-1][i][0]=0;
		OPT[noOfDays-1][i][1]=input[noOfDays-1];
	}
	for(int i=0;i<noOfDays;i++)
	{
		OPT[i][0][0]=0;
		OPT[i][0][1]=0;
	}
	for(int i=noOfDays-2;i>=0;i--)		//Using Dynamic approach and Memoization
	{
		for(int j=1;j<maxVisits;j++)
		{
			OPT[i][j][0]=max(OPT[i+1][j-1][1]-input[i],OPT[i+1][j][0]);
			OPT[i][j][1]=max(OPT[i+1][j-1][0]+input[i],OPT[i+1][j][1]);
		}
	}
	answer=OPT[0][maxVisits-1][0]; 		//answer is the maximum profit
	cout<<answer<<endl;
}
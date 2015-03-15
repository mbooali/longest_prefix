#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string sub(int i,int j);
int f(int n);
vector<string> p;
vector<char> s;
int* x;

int main()
{
	fstream in,out;
	string myword;

	int i,n;
	
	vector<string>::iterator it;
	in.open("prefix.in", fstream::in);

	if(!in.is_open())
	{
		cout << "can't open input \"prefix.in\" file!" << endl;
		return 0;
	}
	while(true)
	{
		in >> myword;
		if(myword == ".")
			break;
		else
			p.push_back(myword);
	}
	
	while(!in.eof())
	{
		in >> myword;
		for(i = 0; i < (signed)myword.length(); i++)
			s.push_back(myword[i]);
	}

	n = s.size();
	x = new int[n+1];

	for(i = 0; i < n; i++)
		x[i] = -1;
	x[n] = 0; 
	

	int max_tool = f(0);
	cout << "Check the output file please!" << endl;

	out.open("prefix.out",fstream::out);

	out << max_tool << endl;

//	cout << sub(0,tedad) << endl;

	return 0;
}

string sub(int i,int j)
{
	int k;
	string ret = "";
	if(j > (signed)s.size()-1)
		return "";
	for(k = i; k <= j; k++)
		ret += s[k];

	return ret;
}



int f(int n)
{
	int i,Maziar,maxx = 0;
	string substr = "";
	if(x[n] != -1)
		return x[n];

	for(i = 0; i < (signed)p.size(); i++)
	{
		substr = sub(n,n+p[i].size()-1);
		if(substr == p[i])
		{
			if(maxx < (Maziar = p[i].size() + f(p[i].size()+n)) )
			{
				maxx = Maziar;
			}
		}
	}

	x[n] = maxx;
	return x[n];

}
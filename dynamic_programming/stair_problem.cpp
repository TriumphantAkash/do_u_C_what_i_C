//Source	:	https://www.youtube.com/watch?v=sF7hzgUW5uY
//a recursive stair function T(n) = T(n-1) + T(n-2)

#include <iostream>
using namespace std;
int M[100] = {0};

int stair(int n)
{
	if (n <= 1)
		return 1;
	else if(M[n] != 0)	//check if we already have stair(n) solution, if so then return it
		return M[n];
	else {	//if none of the above is the case then we need to compute this case and make use of dynamic programming i.e. store this in the memory
		int ret = stair(n-1) + stair(n-2);
		M[n] = ret;
		return ret;
	}
}

int main()
{
	cout<<"solution to the problem for n = 5 is : "<<stair(10)<<endl;	
	return 0;
}

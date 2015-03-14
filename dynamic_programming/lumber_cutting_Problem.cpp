//We are to cut a lumber of size n into k cuts so as to maximize the profit
//input is the total size of the lumber that u need to cut into pieces
/* The maximum revenue that I can get by dividing an n size lumber into k pieces
 * such that Best(n) = max {summation<from 1 to n>(P(k)+Best(n-k))}
 *
 */
#include <iostream>
using namespace std;
int price[11] = {0,1,5,8,9,10,17,17,20,24,30};
int M[100] = {0};

int best(int n)
{
	if(n <= 0)
		return 0;
	if(M[n] != 0)
		return M[n];

	int ret = 0;
	int i = 0;
	int max = 0;

	for(i = n; i >= 1; i--){
		ret = price[i] + best(n-i);
		if(ret>max)
			max = ret;
	}
	M[n] = max;
	return M[n];
}

int main()
{
	cout<<"the value for best 4 is: "<<best(4)<<endl;
}



#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
static unsigned long next = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void) 
{
    next = next * 1103515245 + 12345;
    return((unsigned)(next/65536) % 32768);
} 
int main(void)
{
	//神经元：按照一定的公式更新内部状态，接受脉冲并可以发放脉冲
	//脉冲源：在特定的时间发放脉冲
	//突触：连接神经元-神经元或者脉冲源-神经元，负责传递脉冲
	int N,S,P,T;
	double st;
	cin>>N>>S>>D>>T;
	cin>>st;
	
	 

}



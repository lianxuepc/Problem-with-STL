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
	//��Ԫ������һ���Ĺ�ʽ�����ڲ�״̬���������岢���Է�������
	//����Դ�����ض���ʱ�䷢������
	//ͻ����������Ԫ-��Ԫ��������Դ-��Ԫ�����𴫵�����
	int N,S,P,T;
	double st;
	cin>>N>>S>>D>>T;
	cin>>st;
	
	 

}



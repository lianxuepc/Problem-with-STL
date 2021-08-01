#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int hah=0;

bool runnian(int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)
		return true;
	else
		return false;
}

int month_num(int index,int flag)
{
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(flag)
	{
		month[2]=29;
	}
	return month[index];
}

int getallday(int year,int a,int b,int c)
{
	int num=0;
	bool flag=runnian(year);
	for(int i=1850;i<year;i++)
	{
		if(runnian(i))
			num+=366;
		else
			num+=365;
	}
	for(int i=1;i<a;i++)
	{
		num+=month_num(i,flag);
	}
//	num+=(b-1)*7+c;
	num=num%7;
	return num+2;
}

int getday(int year,int a,int b,int c,int xinqi)
{
	int num=0;
	bool flag=runnian(year);
	int mday;
	mday=month_num(a,flag);
	num+=(b-1)*7+c;
	return num-xinqi+1;
}

int ans(int begin,int b,int c)
{
	int ansnum=0,hh=0;
	for(int i=begin;i<31;i++)
	{
		if((i%7+1)==c)
		{
			hh++;
		}
		ansnum++;
		if(hh==b)
		{
			
			return ansnum+1;
		}
		
	}
	
	return 99;
}

int main(void)
{
	
	int a,b,c,y1,y2;
	cin>>a>>b>>c>>y1>>y2;
	for(int i=y1;i<=y2;i++)
	{
		int allday=getallday(i,a,b,c),day=getday(i,a,b,c,allday);
		day=ans(allday,b,c);
		
		if(b<10&&day>=10)
		{
			if(day>month_num(a,runnian(i)))
				printf("none\n");
			else
				printf("%d/0%d/%d\n",i,a,day);
		}
		else if(day<10&&b>=10)
		{
			if(day>month_num(a,runnian(i)))
				printf("none\n");
			else
				printf("%d/%d/0%d\n",i,a,day);
		}
		else if(day<10&&b<10)
		{
			if(day>month_num(a,runnian(i)))
				printf("none\n");
			else
				printf("%d/0%d/0%d\n",i,a,day);
		}
		else
		{
			if(day>month_num(a,runnian(i)))
				printf("none\n");
			else
				printf("%d/%d/%d\n",i,a,day);
		}
		
		
	}


	
}



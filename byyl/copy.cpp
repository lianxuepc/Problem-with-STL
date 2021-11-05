#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

#define CODE "code.txt"
#define RESULT "ans.txt"

//token数组用来接收关键字，变量，运算符和界符
//这里限制变量名的长度最多为99
//prog数组存储的是源代码字符串长度
char *prog, token[100];
char ch;
string errorCause;
//syn是各个单词符号对应的数字
int syn, p, m = 0, n, line, sum = 0;
//rwtab数组存储的是关键字
char *rwtab1[10] = {"begin", "if", "then", "while", "do", "end"};
char *rwtab2[4] = {"const", "var", "procedure", "call"};

bool isLetter(char ch)
{
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		return true;
	else
		return false;
}

bool isDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}
//+  -  *  /  = <  >  :=  (  )  ,  .  ;
bool isSign(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='<'||ch=='>'||ch==':'||ch=='('||ch==')'||ch==','||ch=='.'||ch==';')
		return true;
	else return false;
	
}

bool isBlank(char ch)
{
	if(ch==' '||ch=='\n'||ch=='\r'||ch=='\t')
		return true;
	else
		return false;
}

bool isLegal(char ch)
{
	if (isLetter(ch) || isDigit(ch)||isBlank(ch)||isSign(ch))
		return true;
	else
		return false;
}



void scaner()
{
	//规定，标识符只能由字母或数字构成

	/*
	共分为三大块，分别是标示符、数字、符号，对应下面的 if   else if  和 else
	*/

	//将全部置空
	for (n = 0; n < 100; n++)
		//token为已捕获的字符数
		token[n] = NULL;
	ch = prog[p++];

	//这样处理，可以去除空格
	while (ch == ' ' || ch == '\r' || ch == '\t')
	{
		ch = prog[p++];
	}
	//在这个if判断中，范围是a-z或者A-Z，因为规定变量只能以字母开头
	if (isLetter(ch)) //可能是标示符或者变量名
	{
		m = 0;
		//这里，是变量的第一个字符以后，可以是字母，数字
		while (isLetter(ch) || isDigit(ch))
		{
			token[m++] = ch;
			ch = prog[p++];
		}
		//变量的字符串结束标志
		token[m++] = '\0';
		p--;
		syn = 10;

		//将识别出来的字符和已定义的标示符作比较， 判断是否是关键字，所有关键字都是小写
		for (n = 0; n < 6; n++)
			if (strcmp(token, rwtab1[n]) == 0)
			{
				syn = n + 1;
				break;
			}
		for (n = 0; n < 4; n++)
		{
			if (strcmp(token, rwtab2[n]) == 0)
			{
				syn = n + 31;
				break;
			}
		}
	}

	else if (isDigit(ch)) //数字 ，如果是数字，就用sum来保存这个数字
	{
		m = p;
		sum = 0;
		while (!isSign(ch))
		{
			char tch = prog[m++];
			if (isLetter(tch))
			{
				syn = -1;
				errorCause = "命名错误";
				p=m+1;
				return;
			}
		}

		while (isDigit(ch))
		{
			//这里*10是只考虑十进制数
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		p--;
		syn = 11;
		//可接收的数字的最大值为32767，如果更大，会报错
		if (sum > 32767)
			syn = -1;
	}

	else
		switch (ch) //如果是其他的字符
		{
		case '<':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '>')
			{
				//说明是不等号
				syn = 21;
				token[m++] = ch;
			}
			else if (ch == '=')
			{
				//说明是<=
				syn = 22;
				token[m++] = ch;
			}
			else
			{
				//否则，就只是一个<符号
				syn = 23;
				//此时p回退一个
				p--;
			}
			break;
		case '>':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=')
			{
				syn = 24;
				token[m++] = ch;
			}
			else
			{
				syn = 20;
				p--;
			}
			break;
		case ':':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=')
			{
				//说明是赋值运算符
				syn = 18;
				token[m++] = ch;
			}
			else
			{
				//否则就只是个:
				syn = 17;
				p--;
			}
			break;
		case '*':
			syn = 13;
			token[0] = ch;
			break;
		case '/':
			syn = 14;
			token[0] = ch;
			break;
		case '+':
			syn = 15;
			token[0] = ch;
			break;
		case '-':
			syn = 16;
			token[0] = ch;
			break;
		case '=':
			syn = 25;
			token[0] = ch;
			break;
		case ';':
			syn = 26;
			token[0] = ch;
			break;
		case '(':
			syn = 27;
			token[0] = ch;
			break;
		case ')':
			syn = 28;
			token[0] = ch;
			break;
		case ',':
			syn = 29;
			token[0] = ch;
			break;
		case '!':
			syn = 30;
			token[0] = ch;
			break;
		case '.':
			//如果接收到的是.，说明到了源代码的结尾，置syn=0，函数结束
			syn = 0;
			token[0] = ch;
			break;
		case '\n':
			//如果接收到的是换行符，则syn=-2，行+1
			syn = -2;
			break;
		default:
			//如果接收到的是其他未定义的字符，置syn=-1，会报错。
			printf("error ch is %c\n", ch);
			errorCause = "未定义字符";
			syn = -1;
			break;
		}
}

/*
读取源代码文件(.txt)
*/
void read()
{
	FILE *fp;
	fp = fopen(CODE, "r");
	fseek(fp, 0, SEEK_END);
	int file_size;
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	prog = (char *)malloc(file_size * sizeof(char));
	fread(prog, file_size, sizeof(char), fp);

	//关闭文件流
	fclose(fp);
}

int main()
{
	int p = 0;
	int line = 1;
	ofstream outfile(RESULT);

	printf("waitting..........\n");
	//读取源代码文件
	read();

	p = 0;
	outfile << "词法分析的结果为：" << endl;
	do
	{
		scaner();
		switch (syn)
		{
		case 11:

			outfile << "(" << syn << "," << sum << ")" << endl;
			break;
		case -1: //出现错误
			outfile << "Error in line" << line << "is" << errorCause << endl;
			break;
		case -2: //行++
			line++;
			break;
		default:
			outfile << "(" << syn << "," << token << ")" << endl;
			break;
		}
	} while (syn != 0);

	outfile.close();

	cout << "over! written in ans.txt\n"
		 << endl;

	system("pause");
	return 0;
}
#include <bits/stdc++.h>
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

map<string, int> resMap{
	{"begin", 1},
	{"if", 2},
	{"then", 3},
	{"while", 4},
	{"do", 5},
	{"end", 6},
	{"const", 31},
	{"var", 32},
	{"procedure", 33},
	{"call", 34},
};

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
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == ':' || ch == '(' || ch == ')' || ch == ',' || ch == '.' || ch == ';')
		return true;
	else
		return false;
}

bool isBlank(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t')
		return true;
	else
		return false;
}

bool isLegal(char ch)
{
	if (isLetter(ch) || isDigit(ch) || isBlank(ch) || isSign(ch) || isblank(ch))
		return true;
	else
		return false;
}

void scaner()
{
	for (n = 0; n < 100; n++)
		token[n] = '\0'; //将全部置空
	ch = prog[p++];		 //

	//去除除了\n的空字符
	while (ch == ' ' || ch == '\r' || ch == '\t')
	{
		ch = prog[p++];
	}

	//判断变量名
	if (isLetter(ch))
	{
		m = 0;
		//这里，是变量的第一个字符以后，可以是字母，数字
		while (isLetter(ch) || isDigit(ch))
		{
			token[m++] = ch;
			ch = prog[p++];
		}
		//变量的字符串结束标志
		token[m] = '\0';
		string strt = token;
		p--;

		if (resMap.count(strt))
			syn = resMap[strt]; //关键字
		else
			syn = 10; //自定义变量
	}
	//判断数字
	else if (isDigit(ch)) //数字 ，如果是数字，就用sum来保存这个数字
	{
		sum = 0;
		m = 0;
		int float_flag = 0;
		//这里，是变量的第一个数字以后只能时数字
		while (isLetter(ch) || isDigit(ch))
		{
			token[m++] = ch;
			ch = prog[p++];
		}
		p--;
		//如果后面有字母，就是命名错误
		for (int i = 0; i < strlen(token); i++)
		{
			if (isLetter(token[i]))
			{
				syn = -1;
				errorCause = "命名错误";
				return;
			}
		}
		//是数字
		for (int i = 0; i < strlen(token); i++)
			sum = sum * 10 + token[i] - '0';

		if (sum > 32767)
		{
			syn = -1;
			errorCause = "整数溢出";
		}
		// 数字整数
		else
			syn = 11;
	}

	//判断字符
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
				errorCause = "单:非法";
				syn = -1;
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
			// printf("error ch is %c\n", ch);
			errorCause = "未定义字符";
			syn = -1;
			break;
		}
}

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
	outfile << "词法分析的结果为：" << endl;
	do
	{
		scaner();
		switch (syn)
		{
		case 11://int
			outfile << "(" << syn << "," << sum << ")" << endl;
			break;
		case -1: //出现错误
			outfile << "Error in line " << line << " is " << errorCause << endl;
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
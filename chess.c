#include <stdio.h>
#include <math.h>

#define bool int;
#define true 1;
#define false 0;

const int WP=1,WR=2,WH=3,WB=4,WQ=5,WK=6;
const int BP=11,BR=12,BH=13,BB=14,BQ=15,BK=16;

char* transPiece(int num)
{
	switch(num)
	{
		case 1:
			return "WP";
		case 2:
			return "WR";
		case 3:
			return "WH";
		case 4:
			return "WB";
		case 5:
			return "WQ";
		case 6:
			return "WK";
		case 11:
			return "BP";
		case 12:
			return "BR";
		case 13:
			return "BH";
		case 14:
			return "BB";
		case 15:
			return "BQ";
		case 16:
			return "BK";
		default:
			return "  ";
	}
}
void init(int A[8][8])
{
	int i,j;
	for(j=0;j<8;j++)
	{
		A[1][j] = 1;
		A[6][j] = 11;
		A[0][j] = j + 2;
		A[7][j] = j + 12;
	}
	for(j=5;j<8;j++)
	{
		A[0][j] = 9 - j;
		A[7][j] = 19 - j;
	}
	for(i = 2;i<6;i++)
		for(j = 0;j<8;j++)
			A[i][j] = 0;
}
bool pawnCanMove(int a[2],int b[2])
{
	if((b[1] - a[1] == 0)&& ((b[0] - a[0])*(b[0] - a[0]) == 1))
		return true;
	return false;
}
bool rookCanMove(int a[2],int b[2])
{
	if((b[1] - a[1])*(b[0] - a[0]) == 0)
		return true;
	return false;
}
bool horseCanMove(int a[2],int b[2])
{
	if(abs((b[1] - a[1])*(b[0] - a[0])) == 2)
		return true;
	return false;
}
bool bishopCanMove(int a[2],int b[2])
{
	if(abs(b[1] - a[1]) == abs(b[0] - a[0]))
		return true;
	return false;	
}
bool queenCanMove(int a[2],int b[2])
{
	if(((b[1] - a[1])*(b[0] - a[0]) == 0) || (abs(b[1] - a[1]) == abs(b[0] - a[0])))
		return true;
	return false;	
}
bool kingCanMove(int a[2],int b[2])
{
	if(abs(b[1] - a[1])*abs(b[0] - a[0]) < 2)
		return true;
	return false;
}
bool canMove(int num,int a[2],int b[2])
{
	int opt;
	if(num < 10)
		opt = num;
	else
		opt = num - 10;
	switch(opt)
	{
		case 1:
			return pawnCanMove(a,b);
		case 2:
			return rookCanMove(a,b);
		case 3:
			return horseCanMove(a,b);
		case 4:
			return bishopCanMove(a,b);
		case 5:
			return queenCanMove(a,b);
		case 6:
			return kingCanMove(a,b);
		default:
			return false;
	}
}
bool move(int A[8][8],int a[2],int b[2])
{
	if(canMove(A[a[0]][a[1]],a,b))
	{
		A[b[0]][b[1]] = A[a[0]][a[1]];
		A[a[0]][a[1]] = 0;
		return true;
	}
	return false;
}
void convert(char* s,int a[2],int b[2])
{
	a[1] = s[0] - 97;
	a[0] = 56 - s[1];
	b[1] = s[2] - 97;
	b[0] = 56 - s[3];
}
bool checkBK(int A[8][8])
{

}
bool checkWK(int A[8][8])
{
	
}
bool check(int A[8][8])
{
	if(checkWK(A))
		return 1;
	else if (checkBK(A))
		return 2;
	return 0;
}
void drawChess(int A[8][8])
{
	int i,j;
	for(i = 0;i < 8;i++)
	{	
		printf("%d  ",8-i);
		for(j=0;j<8;j++)
			printf("%s|",transPiece(A[i][j]));
		if(i!=7)
			printf("\n   ________________________\n");
		else
			printf("\n   a  b  c  d  e  f  g  h\n");
	}
}

void game(int A[8][8])
{
	int a[2],b[2];
	init(A);
	while(1)
	{
		drawChess(A);
		printf("Your move: ");
		char s[4];
		gets(s);
		convert(s,a,b);
		move(A,a,b);
	}
}

int main(int argv, char* args[])
{
	int A[8][8];
	game(A);
}
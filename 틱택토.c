#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

char whoGoesFirst(int results[3])
{
    int i, cnt=0;
    for(i=0; i<3; i++)
        cnt+=results[i];
    return (cnt%2);
}

void drawBoard(int board[][SIZE])
{
    int i, j, k;
    printf("---------\n");
    for(i=0; i<3; i++)
    {
        printf("|");
        for(j=0; j<3; j++)
        {
            if(board[i][j]==1)
                printf(" X");
            else if(board[i][j]==0)
                printf(" O");
            else
                printf("  ");

        }
        printf(" |\n");
    }
     printf("---------\n");
}

int winer(int board[][SIZE])
{
    int i;
    for(i=0; i<3; i++)
    {
        if(board[0][i]!=2)
        {
            if((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))
            {
                if(board[0][i]==0)
                {
                    drawBoard(board);
                    printf("Hooray! You have won the game!");
                }

                else if(board[0][i]==1)
                    printf("The computer has beaten you! You lose.");
                return 1;
            }
        }

        if(board[i][0]!=2)
        {
            if((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))
            {
                if(board[i][0]==0)
                {
                    drawBoard(board);
                    printf("Hooray! You have won the game!");
                }
                else if(board[i][0]==1)
                    printf("The computer has beaten you! You lose.");
                return 1;
            }
        }

    if(board[1][1]!=2)
    {
        if(((board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) || ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0])))
        {
            if(board[1][1]==0)
            {
                drawBoard(board);
                printf("Hooray! You have won the game!");
            }
            else if(board[1][1]==1)
                printf("The computer has beaten you! You lose.");
            return 1;
        }
    }

    if(i==2)
    {
        return 0;
    }
    }
}

int full(int h, int board[][SIZE])
{
    if(h<4)
    {
        if(board[2][h-1]!=2)
            return 1;
        else
            return 2;
    }
    else if(h<7)
    {
        if(board[1][h-4]!=2)
            return 1;
        else
            return 2;
    }
    else
        if(board[0][h-7]!=2)
            return 1;
        else
            return 2;
}

void getPlayerMove(int board[][SIZE])
{
    int h;
    printf("Please, select a location from the numeric keypad. (1~9) : ");
    scanf("%d", &h);
	if(h>9 || h<1)
	{
		printf("1~9 까지 입력 해주셈~~~~ 뿌잉뿌잉\n");
		getPlayerMove(board);
	}
	else
	{
		if(full(h, board)==2)
		{
			if(h<4)
				board[2][h-1]=0;
			else if(h<7)
				board[1][h-4]=0;
			else
				board[0][h-7]=0;
		}
		else
		{
			printf("Not an empty seat.\n");
			getPlayerMove(board);
		}
	}
}

void getComputerMove(int board[][SIZE])
{
    int i, j, randtime=0;
    for(i=0; i<9; i++)
    {
        //필수 공격 가로
        if(board[i/3][i%3]==1 && board[i/3][(i+1)%3]==1 && randtime==0)
            if(board[i/3][(i+2)%3]==2)
            {
                board[i/3][(i+2)%3]=1;
                randtime++;
                break;
            }
        //세로
        if(board[i%3][i/3]==1 && board[(i+1)%3][i/3]==1 && randtime==0)
            if(board[(i+2)%3][i/3]==2)
            {
                board[(i+2)%3][i/3]=1;
                randtime++;
                break;
            }
    }
    //대각선
        for(i=0; i<3; i++)
    {
        if((board[0][0]==1 && board[2][2]==1 && randtime==0) || (board[0][2]==1 && board[2][0]==1 && randtime==0))
            if(board[1][1]==2)
            {
                board[1][1]=1;
                randtime++;
                break;
            }
        if(board[0][0]==1 && board[1][1]==1 && randtime==0)
            if(board[2][2]==2)
            {
                board[2][2]=1;
                randtime++;
                break;
            }
        if(board[1][1]==1 && board[2][2]==1 && randtime==0)
            if(board[0][0]==2)
            {
                board[0][0]=1;
                randtime++;
                break;
            }
        if(board[0][2]==1 && board[1][1]==1 && randtime==0)
            if(board[2][0]==2)
            {
                board[2][0]=1;
                randtime++;
                break;
            }
        if(board[1][1]==1 && board[2][0]==1 && randtime==0)
            if(board[0][2]==2)
            {
                board[0][2]=1;
                randtime++;
                break;
            }
    }
    for(i=0; i<9; i++)
    {
        //필수 방어 가로
        if(board[i/3][i%3]==0 && board[i/3][(i+1)%3]==0 && randtime==0)
            if(board[i/3][(i+2)%3]==2)
            {
                board[i/3][(i+2)%3]=1;
                randtime++;
                break;
            }
        //필수 방어 세로
        if(board[i%3][i/3]==0 && board[(i+1)%3][i/3]==0 && randtime==0)
            if(board[(i+2)%3][i/3]==2)
            {
                board[(i+2)%3][i/3]=1;
                randtime++;
                break;
            }
    }

    //대각선
        for(i=0; i<3; i++)
    {
        if((board[0][0]==0 && board[2][2]==0 && randtime==0) || (board[0][2]==0 && board[2][0]==0 && randtime==0))
            if(board[1][1]==2)
            {
                board[1][1]=1;
                randtime++;
                break;
            }
        if(board[0][0]==0 && board[1][1]==0 && randtime==0)
            if(board[2][2]==2)
            {
                board[2][2]=1;
                randtime++;
                break;
            }
        if(board[1][1]==0 && board[2][2]==0 && randtime==0)
            if(board[0][0]==2)
            {
                board[0][0]=1;
                randtime++;
                break;
            }
        if(board[0][2]==0 && board[1][1]==0 && randtime==0)
            if(board[2][0]==2)
            {
                board[2][0]=1;
                randtime++;
                break;
            }
        if(board[1][1]==0 && board[2][0]==0 && randtime==0)
            if(board[0][2]==2)
            {
                board[0][2]=1;
                randtime++;
                break;
            }
        if(board[0][2]==0 && board[2][0]==0 && randtime==0)
            if(board[1][1]==2)
        {
            board[1][1]=1;
            randtime++;
            break;
        }
    }
    // Big Pichers Defende
    if(board[1][0]==0 && board[0][1]==0 &&randtime==0)
    {
        if(board[0][0]==2)
        {
            randtime++;
            board[0][0]=1;
        }
    }
    if(board[1][2]==0 && board[0][1]==0 &&randtime==0)
    {
        if(board[0][2]==2)
        {
            randtime++;
            board[0][2]=1;
        }
    }
    if(board[1][2]==0 && board[2][1]==0 &&randtime==0)
    {
        if(board[2][2]==2)
        {
            randtime++;
            board[2][2]=1;
        }
    }
    if(board[1][0]==0 && board[2][1]==0 &&randtime==0)
    {
        if(board[2][0]==2)
        {
            randtime++;
            board[2][0]=1;
        }
    }
    //Big Picher attack!!
        if(board[1][1]==1 && board[2][0]==1 && randtime==0)//15
        {
            if(board[0][0]==2 && board[1][2]==2 && board[1][0]==2 && randtime==0)
            {
                board[1][0]=1;
                randtime++;
	        }
            else if (board[0][1]==2 && board[2][1]==2 && board[2][2]==2 && randtime==0)
            {
                board[2][1]=1;
                randtime++;
            }
        }
        if(board[1][1]==1 && board[0][0]==1 && randtime==0)//75
        {
            if(board[0][2]==2 && board[2][1]==2 && board[0][1]==2 && randtime==0)
            {
                board[0][1]=1;
                randtime++;
	        }
            else if (board[1][2]==2 && board[2][0]==2 && board[1][0]==2 && randtime==0)
            {
                board[1][0]=1;
                randtime++;
            }
        }
        if(board[1][1]==1 && board[0][2]==1 && randtime==0)//75
        {
            if(board[0][0]==2 && board[2][1]==2 && board[0][1]==2 && randtime==0)
            {
                board[0][1]=1;
                randtime++;
	        }
            else if (board[1][0]==2 && board[2][2]==2 && board[1][2]==2 && randtime==0)
            {
                board[1][2]=1;
                randtime++;
            }
        }
        if(board[1][1]==1 && board[2][2]==1 && randtime==0)//75
        {
            if(board[0][2]==2 && board[1][0]==2 && board[1][2]==2 && randtime==0)
            {
                board[1][2]=1;
                randtime++;
	        }
            else if (board[0][1]==2 && board[2][0]==2 && board[2][1]==2 && randtime==0)
            {
                board[2][1]=1;
                randtime++;
            }
        }
//가운데 우선 (필수)
    if(board[1][1]==2 && randtime==0)
    {
        randtime++;
        board[1][1]=1;
    }
    //일반 공격
    for(i=0; i<3; i++)
    {
        if(board[i][0]==2 && board[i][1]==2 && randtime==0)
            if(board[i][2]==1)
            {
                board[i][0]=1;
                randtime++;
                break;
            }
        if(board[i][0]==2 && board[i][2]==2 && randtime==0)
            if(board[i][1]==1)
            {
                board[i][0]=1;
                randtime++;
                break;
            }
        if(board[i][1]==2 && board[i][2]==2 && randtime==0)
            if(board[i][0]==1)
            {
                board[i][1]=1;
                randtime++;
                break;
            }

        //세로
        if(board[0][i]==2 && board[1][i]==2 && randtime==0)
            if(board[2][i]==1)
            {
                board[0][i]=1;
                randtime++;
                break;
            }
        if(board[0][i]==2 && board[2][i]==2 && randtime==0)
            if(board[1][i]==1)
            {
                board[0][i]=1;
                randtime++;
                break;
            }
        if(board[1][i]==2 && board[2][i]==2 && randtime==0)
            if(board[0][i]==1)
            {
                board[1][i]=1;
                randtime++;
                break;
            }
    }
    //////////////////////순차놓기
    if(randtime==0)
    {
        for(j=1; j<10; j++)
        {
            if(full(j,board)==2)
            {
                if(j<4)
                    board[2][j-1]=1;
                else if(j<7)
                    board[1][j-4]=1;
                else
                    board[0][j-7]=1;
                break;
            }
        }
    }
}

int isFull(int board[][SIZE])
{
    int i, j, c=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(board[i][j]!=2)
                c++;
        }
    }
    if(c==9)
        return 1;
    else
        return 0;
}

int ticTacToe(int round, int board[][SIZE], int time[])
{
    if(whoGoesFirst(time)==0)
    {
        printf("The player will go first.\n\n");
        drawBoard(board);
        while(1)
        {
            getPlayerMove(board);
            if(winer(board)==1)
                return 0;

            else if(isFull(board)==1)
            {
                drawBoard(board);
                printf("The game is a tie!");
                return 1;
            }

            getComputerMove(board);
            drawBoard(board);
            if(winer(board)==1)
                return 2;
            else if(isFull(board)==1)
            {
                printf("The game is a tie!");
                return 1;
            }
        }

    }

    else
    {
        printf("The computer will go first.\n\n");
        while(1)
        {
            getComputerMove(board);
            drawBoard(board);
            if(winer(board)==1)
                return 2;
            else if(isFull(board)==1)
            {
                printf("The game is a tie!");
                return 1;
            }

            getPlayerMove(board);
            if(winer(board)==1)
            {
                drawBoard(board);
                return 0;
            }

            else if(isFull(board)==1)
            {
                drawBoard(board);
                printf("The game is a tie!");
                return 1;
            }
        }
    }
}
int main()
{
    int board[3][3]={{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
    int i, j, k, round, h;///////////////////////////////////////////////////
    int results[3] = {0};
    printf("How many times do you want to play the game? ");

    scanf("%d", &round);
    for(i=0; i<round; i++)
    {
        printf("\n==========================================\n\n");
        results[ticTacToe(round, board, results)]++;
        for(j=0; j<3; j++)
            for(k=0; k<3; k++)
            board[j][k]=2;
    }
    printf("\n\n%d win, %d draw and %d loss", results[0], results[1], results[2]);
    getchar();
    getchar();
    return 0;
}

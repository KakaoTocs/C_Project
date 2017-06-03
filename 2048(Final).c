#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void getmartime(int board[4][4], int num)
{
    int i, j;
    srand(time(NULL));
    if(rand()%5==1 || rand()%5==3)
        num=4;
    else
        num=2;

    printf("\n");

    while(1)
    {
        i=rand()%4;
        j=(rand()+1)%4;

        if(board[i][j]==0)
        {
            board[i][j]=num;
            break;
        }
    }
}

void showboard(int board[4][4])
{
    int i, j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%5d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int matchcan(int board[4][4])
{
    int i, j=0, copy;

    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            copy=board[i][j];

            if(i-1>=0)
                if(copy==board[i-1][j] || board[i-1][j]==0 || board[i][j]==0)
                    return 1;
            if(i+1<4)
                if(copy==board[i+1][j] || board[i+1][j]==0 || board[i][j]==0)
                    return 1;
        }
    for(j=0; j<4; j++)
        for(i=0; i<4; i++)
        {
            copy=board[i][j];

            if(j-1>=0)
                if(copy==board[i][j-1] || board[i][j-1]==0 || board[i][j]==0)
                    return 1;
            if(j+1<4)
                if(copy==board[i][j+1] || board[i][j+1]==0 || board[i][j]==0)
                    return 1;
        }
    return 0;
}

void endscore(int board[4][4])
{
    int i, j, max=0;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if(max<board[i][j])
                max=board[i][j];
    printf("\nBest Score : [%d]", max);
}

int win(int board[4][4])
{
    int i, j, max=0;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if(max<board[i][j])
                max=board[i][j];
    return max;
}

void playertime(int board[4][4])
{
    int i, j, k, answer, copy[4][4], cnt=0;

    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            copy[i][j]=board[i][j];
    while(1)
    {
        if(getch() == 224)
            answer=getch();

        if(answer==75 || answer==97)//LEFT
        {
            for(k=0; k<2; k++)
                for(j=0; j<4; j++)
                    for(i=0; i<4; i++)
                    {
                        if(j+1<4)
                        {
                            if(board[i][j+1]==0 || board[i][j]==0)
                            {
                                board[i][j]+=board[i][j+1];
                                if(j+2<4)
                                {
                                    board[i][j+1]=board[i][j+2];
                                        if(j+3<4)
                                        {
                                            board[i][j+2]=board[i][j+3];
                                            board[i][j+3]=0;
                                        }
                                        else
                                            board[i][j+2]=0;
                                }
                                else
                                    board[i][j+1]=0;
                            }
                        }
                    }
            for(j=0; j<4; j++)
                for(i=0; i<4; i++)
                {
                    if(j+1<4)
                    {
                        if(board[i][j]==board[i][j+1])
                        {
                            board[i][j]+=board[i][j+1];
                            if(j+2<4)
                            {
                                board[i][j+1]=board[i][j+2];
                                    if(j+3<4)
                                    {
                                        board[i][j+2]=board[i][j+3];
                                        board[i][j+3]=0;
                                    }
                                    else
                                        board[i][j+2]=0;
                            }
                            else
                                board[i][j+1]=0;
                        }
                    }
                }
        }
        if(answer==77 || answer==100)//RIGHT
        {
            for(k=0; k<2; k++)
                for(i=0; i<4; i++)
                    for(j=3; j>=0; j--)
                    {
                        if(j-1>=0)
                        {
                            if(board[i][j-1]==0 || board[i][j]==0)
                            {
                                board[i][j]+=board[i][j-1];
                                if(j-2>=0)
                                {
                                    board[i][j-1]=board[i][j-2];
                                        if(j-3>=0)
                                        {
                                            board[i][j-2]=board[i][j-3];
                                            board[i][j-3]=0;
                                        }
                                        else
                                            board[i][j-2]=0;
                                }
                                else
                                    board[i][j-1]=0;
                            }
                        }
                    }
            for(i=0; i<4; i++)
                for(j=3; j>=0; j--)
                {
                    if(j-1>=0)
                    {
                        if(board[i][j]==board[i][j-1])
                        {
                            board[i][j]+=board[i][j-1];
                            if(j-2>=0)
                            {
                                board[i][j-1]=board[i][j-2];
                                    if(j-3>=0)
                                    {
                                        board[i][j-2]=board[i][j-3];
                                        board[i][j-3]=0;
                                    }
                                    else
                                        board[i][j-2]=0;
                            }
                            else
                                board[i][j-1]=0;
                        }
                    }
                }
        }
        if(answer==72 || answer==119)//UP
        {
            for(k=0; k<2; k++)
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                    {
                        if(i+1<4)
                            if(board[i+1][j]==0 || board[i][j]==0)
                            {
                                board[i][j]+=board[i+1][j];
                                if(i+2<4)
                                {
                                    board[i+1][j]=board[i+2][j];
                                        if(i+3<4)
                                        {
                                            board[i+2][j]=board[i+3][j];
                                            board[i+3][j]=0;
                                        }
                                        else
                                            board[i+2][j]=0;
                                }
                                else
                                    board[i+1][j]=0;
                            }
                    }
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                {
                    if(i+1<4)
                        if(board[i][j]==board[i+1][j])
                        {
                            board[i][j]+=board[i+1][j];
                            if(i+2<4)
                            {
                                board[i+1][j]=board[i+2][j];
                                    if(i+3<4)
                                    {
                                        board[i+2][j]=board[i+3][j];
                                        board[i+3][j]=0;
                                    }
                                    else
                                        board[i+2][j]=0;
                            }
                            else
                                board[i+1][j]=0;
                        }
                }
        }
        if(answer==80)//DOWN
        {
            for(k=0; k<2; k++)
                for(i=3; i>=0; i--)
                    for(j=0; j<4; j++)
                    {
                        if(i-1>=0)
                            if(board[i-1][j]==0 || board[i][j]==0)
                            {
                                board[i][j]+=board[i-1][j];
                                if(i-2>=0)
                                {
                                    board[i-1][j]=board[i-2][j];
                                        if(i-3>=0)
                                        {
                                            board[i-2][j]=board[i-3][j];
                                            board[i-3][j]=0;
                                        }
                                        else
                                            board[i-2][j]=0;
                                }
                                else
                                    board[i-1][j]=0;
                            }
                    }
            for(i=3; i>=0; i--)
                for(j=0; j<4; j++)
                {
                    if(i-1>=0)
                        if(board[i][j]==board[i-1][j])
                        {
                            board[i][j]+=board[i-1][j];
                            if(i-2>=0)
                            {
                                board[i-1][j]=board[i-2][j];
                                    if(i-3>=0)
                                    {
                                        board[i-2][j]=board[i-3][j];
                                        board[i-3][j]=0;
                                    }
                                    else
                                        board[i-2][j]=0;
                            }
                            else
                                board[i-1][j]=0;
                        }
                }
        }
        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
                if(board[i][j]==copy[i][j])
                    cnt++;
        if(cnt!=16)
            break;
        else
        {
            printf("Can't move\n");
            cnt=0;
        }
    }
}

int main()
{
    int board[4][4]={{0, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, i, j, num;

    printf("When Finish, If you want END, Press Enter");
    while(1)
    {
        getmartime(board, num);
        showboard(board);

        if(matchcan(board)==0)
        {
            printf("----------\n");
            endscore(board);
            getchar();
            break;
        }

        if(win(board)==2048)
        {
            printf("You Win");
            getchar();
            break;
        }
        playertime(board);
    }
    return 0;
}

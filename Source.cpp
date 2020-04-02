#include<iostream>// mai nhat hoang
using namespace std;
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include "console.cpp"
#define chieudai 85
#define chieurong 25
int A[100][100];
int Y;//toạ độ khi full hàng
int a1, b1,a2,b2;//tọa độ đầu hàng và cuối hàng
int x1, x2;//tọa độ 2 bên cạnh  bảng

typedef struct highscore
{
    char name[30];
    int score;
}hs;
void play(int& x, int& y, int &k, int& t);
void goi(int a, int b);
void hinh(int& x, int& y, int k);
void xoa(int x, int y,int k);
void bang(int& a2, int& b2, int& a1, int& b1);
void move(int k,int &y,int &x);
void goi(int a, int b);
void len(int& k);
bool kt(int x, int y, int k);
void dichuyenh(int Y);
void xoah(int Y);
bool kthang(int& Y);
void goilaihang();
void Nocursortype();
void menu();
void highscoreN(hs ngc[]);
void highscore(hs ngc[]);
void highscoret(hs ngc[]);
void xuaths(hs ngc[]);
int main()
{
    hs ngc[6];
    ngc[5].score=0;
    resizeConsole(80, 40);
    srand((int)time(0));
    int y = 1,x=1;
    Nocursortype();
    // menu();
    system("pause");
    system("cls");
    bang(a2,b2,a1,b1);
    goi(a1, b1);
    goi(a2, b2);
    while (y!=3)
    {
        
        int k = rand() % 7 + 1;
        move(k,y,x);
        goilaihang();
        if (kthang(Y))
        {
            xoah(Y);
            ngc[5].score += 100;
        }
    }
    if (y == 3)
    {
        system("cls");
        x = (chieudai - 35) / 2, y = 0;
        gotoXY(x, y);
        cout << "YOU LOSE" << endl;
        highscoreN(ngc);
        highscore(ngc);
    } 
    system("pause");
}
void hinh(int& x, int& y, int k)
{//hàm in hình
    switch (k)
    {
        case 1://thanh ngang
            setColor(11);
            gotoXY(x, y);
            cout << "====";
         
            setColor(15);
            break;
        case 2://hình vuông
            setColor(2);
            gotoXY(x, y);
            cout << "==";
            gotoXY(x, y + 1);
            cout << "==";
            setColor(15);
            break;
        case 3:// chữ L phải
            setColor(14);
            gotoXY(x, y);
            cout << "=";
            gotoXY(x, y + 1);
            cout << "=";
            gotoXY(x, y + 2);
            cout << "==";
            setColor(15);
            break;
        case 4://chữ L trái
            setColor(14);
            gotoXY(x, y);
            cout << " =";
            gotoXY(x, y + 1);
            cout << " =";
            gotoXY(x, y + 2);
            cout << "==";
            setColor(15);
            break;
        case 5://ziczac trái
            setColor(12);
            gotoXY(x, y);
            cout << "== ";
            gotoXY(x + 1, y + 1);
            cout << "==";
            setColor(15);
            break;
        case 6://ziczac phải
            setColor(12);
            gotoXY(x, y);
            cout << " ==";
            gotoXY(x, y + 1);
            cout << "==";
            setColor(15);
            break;
        case 7://dấu cộng
            setColor(5);
            gotoXY(x, y);
            cout << " = ";
            gotoXY(x, y + 1);
            cout << "===";
            setColor(15);
            break;
        case 8://thanh ngang đứng
            setColor(11);
            gotoXY(x, y);
            cout << "=";
            
            gotoXY(x, y + 1);
            cout << "=";
            
            gotoXY(x, y + 2);
            cout << "=";
       
            gotoXY(x, y + 3);
            cout << "=";
            setColor(15);
            break;
        
        case 9://xoay chữ L phải
            setColor(14);
            gotoXY(x, y);
            cout << "  =";
            gotoXY(x, y + 1);
            cout << "===";
            setColor(15);
            break;
        case 10:
            setColor(14);
            gotoXY(x, y);
            cout << "==";
            gotoXY(x+1, y + 1);
            cout << "=";
            gotoXY(x+1, y + 2);
            cout << "=";
            setColor(15);
            break;
        case 11:
            setColor(14);
            gotoXY(x, y);
            cout << "===";
            gotoXY(x, y + 1);
            cout << "=";
            setColor(15);
            break;
        case 12://xoay chữ L trái
            setColor(14);
            gotoXY(x, y);
            cout << "=";
            gotoXY(x, y + 1);
            cout << "===";
            setColor(15);
            break;
        case 13:
            setColor(14);
            gotoXY(x, y);
            cout << "==";
            gotoXY(x, y + 1);
            cout << "=";
            gotoXY(x, y + 2);
            cout << "=";
            setColor(15);
            break;
        case 14:
            setColor(14);
            gotoXY(x, y);
            cout << "===";
            gotoXY(x + 2, y + 1);
            cout << "=";
            setColor(15);
            break;
        case 15://xoay ziczac trái
            setColor(12);
            gotoXY(x+1, y);
            cout << "=";
            gotoXY(x, y + 1);
            cout << "==";
            gotoXY(x, y + 2);
            cout << "=";
            setColor(15);
            break;
        case 16://xoay ziczac phải
            setColor(12);
            gotoXY(x, y);
            cout << "=";
            gotoXY(x, y + 1);
            cout << "==";
            gotoXY(x + 1, y + 2);
            cout << "=";
            setColor(15);
            break;

        case 17://xoay dấu cộng
            setColor(5);
            gotoXY(x, y);
            cout << "=";
            gotoXY(x, y + 1);
            cout << "==";
            gotoXY(x, y + 2);
            cout << "=";
            setColor(15);
            break;
        case 18:
            setColor(5);
            gotoXY(x, y);
            cout << "===";
            gotoXY(x + 1, y + 1);
            cout << "=";
            setColor(15);
            break;
        case 19:
            setColor(5);
            gotoXY(x + 1, y);
            cout << "=";
            gotoXY(x, y + 1);
            cout << "==";
            gotoXY(x + 1, y + 2);
            cout << "=";
            setColor(15);
            break;
    }
}
void xoa(int x, int y,int k)
{//hàm xóa
    switch (k)
    {
        case 1:
            gotoXY(x, y-1);
            cout << "    ";
            break;
        case 2:
            gotoXY(x, y-1);
            cout << "  ";
            gotoXY(x, y );
            cout << "  ";
            break;
        case 3:
            
            gotoXY(x, y-1);
            cout << " ";
            gotoXY(x, y);
            cout << " ";
            gotoXY(x, y + 1);
            cout << "  ";
            break;
        case 4:
            
            gotoXY(x, y - 1);
            cout << "  ";
            gotoXY(x, y);
            cout << "  ";
            gotoXY(x, y + 1);
            cout << "  ";
            break;
        case 5:
            gotoXY(x, y-1);
            cout << "  ";
            gotoXY(x+1, y);
            cout << "  ";
            break;
        case 6:
            gotoXY(x, y-1);
            cout << "   ";
            gotoXY(x, y);
            cout << "  ";
            break;
        case 7:
            gotoXY(x, y-1);
            cout << "   ";
            gotoXY(x, y );
            cout << "   ";
            break;
        case 8:
            gotoXY(x, y-1);
            cout << " ";
            gotoXY(x, y);
            cout << " ";
            gotoXY(x, y + 1);
            cout << " ";
            gotoXY(x, y + 2);
            cout << " ";
            break;
        case 9:
            gotoXY(x, y - 1);
            cout << "   ";
            gotoXY(x, y );
            cout << "   ";
            break;
        case 10:
            gotoXY(x, y - 1);
            cout << "  ";
            gotoXY(x, y);
            cout << "  ";
            gotoXY(x, y + 1);
            cout << "  ";
            break;
        case 11:
            gotoXY(x, y-1);
            cout << "   ";
            gotoXY(x, y);
            cout << " ";
            break;
        case 12:
            gotoXY(x, y - 1);
            cout << " ";
            gotoXY(x, y);
            cout << "   ";
            break;
        case 13:
            gotoXY(x, y - 1);
            cout << "  ";
            gotoXY(x, y);
            cout << " ";
            gotoXY(x, y + 1);
            cout << " ";
            break;
        case 14:
            gotoXY(x, y - 1);
            cout << "   ";
            gotoXY(x + 2, y);
            cout << " ";
            break;
        case 15:
            gotoXY(x + 1, y - 1);
            cout << " ";
            gotoXY(x, y);
            cout << "  ";
            gotoXY(x, y + 1);
            cout << " ";
            break;
        case 16:
            gotoXY(x, y - 1);
            cout << " ";
            gotoXY(x, y);
            cout << "  ";
            gotoXY(x + 1, y + 1);
            cout << " ";
            break;
        case 17:
            gotoXY(x, y - 1);
            cout << " ";
            gotoXY(x, y);
            cout << "  ";
            gotoXY(x, y + 1);
            cout << " ";
            break;
        case 18:
            gotoXY(x, y - 1);
            cout << "   ";
            gotoXY(x + 1, y);
            cout << " ";
            break;
        case 19:
            gotoXY(x + 1, y - 1);
            cout << " ";
            gotoXY(x, y);
            cout << "  ";
            gotoXY(x + 1, y + 1);
            cout << " ";
            break;
    }
    
}
void bang(int &a2,int &b2,int &a1,int &b1)
 {//hàm tạo bảng
     int x = (chieudai - 35) / 2, y = 0;
     a1 = x,b1 = y;
     gotoXY(x, y);
     setColor(11);
     cout<<" ________________________________"<<endl;
     y++;
     for(int i=0;i<35;i++)
     {
         
         
         gotoXY(x-1, y);
             
         
         cout<<"|                                  |"<<endl;
         y++;
         
     }
     gotoXY(x, y);
     cout<<" ________________________________"<<endl;
     setColor(15);
     a2 = x, b2 = y;
     x1 = x+1; x2 = x + 30;
 }
void move(int k,int &y,int &x)
 { 
     int t=171;//thời gian
     x = (chieudai - 2) / 2, y = 2;
      while(1)
     {
         play(x, y, k, t);
         if (kt(x, y, k))
         {
             switch (k) 
             {//kiểm tra xem đúng ko đúng thì gọi mảng phần tử đó
                case 1://thanh ngang
                    A[x][y - 1] = -1;
                    A[x + 1][y - 1] = -1;
                    A[x + 2][y - 1] = -1;
                    A[x + 3][y - 1] = -1;
                    Sleep(0);
                    break;
                case 2://hình vuông
                    A[x][y] = -1;//goi mang khi den cuoi
                    A[x + 1][y] = -1;
                    A[x][y - 1] = -1;
                    A[x + 1][y - 1] = -1;
                    Sleep(0);
                    break;
                case 3://chữ L phải
                    A[x][y] = -1;
                    A[x][y - 1] = -1;
                    A[x][y + 1] = -1;
                    A[x + 1][y + 1] = -1;
                    Sleep(0);
                    break;
               case 4://chữ L trái
                   A[x + 1][y] = -1;
                   A[x + 1][y - 1] = -1;
                   A[x][y + 1] = -1;
                   A[x + 1][y + 1] = -1;
                   Sleep(0);
                   break;
               case 5://ziczac trái
                    A[x+1][y] = -1;
                    A[x][y - 1] = -1;
                    A[x + 2][y] = -1;
                    A[x + 1][y - 1] = -1;
                    Sleep(0);
                    break;
               case 6://ziczac phải
                   A[x][y] = -1;
                   A[x + 1][y] = -1;
                   A[x + 2][y - 1] = -1;
                   A[x + 1][y - 1] = -1;
                   Sleep(0);
                   break;
                case 7://cộng
                    A[x + 1][y - 1] = -1;
                    A[x][y] = -1;
                    A[x + 2][y] = -1; 
                    A[x + 1][y] = -1;
                    Sleep(0);
                    break;
                case 8://thanh dọc
                    A[x][y] = -1;
                    A[x][y + 1] = -1;
                    A[x][y + 2] = -1;
                    A[x][y + 3] = -1;
                    Sleep(0);
                    break;
                
                case 9://xoay chữ L phải
                    A[x + 2][y - 1] = -1;
                    A[x][y] = -1;
                    A[x + 1][y] = -1;
                    A[x + 2][y] = -1;
                    Sleep(0);
                    break;
                case 10:
                    A[x + 1][y - 1] = -1;
                    A[x + 1][y + 1] = -1;
                    A[x ][y-1] = -1;
                    A[x + 1][y] = -1;
                    Sleep(0);
                    break;
                case 11:
                    A[x][y - 1] = -1;
                    A[x][y] = -1;
                    A[x + 1][y - 1] = -1;
                    A[x + 2][y - 1] = -1;
                    Sleep(0);
                    break;
                
                case 12://xoay chữ L trái
                    A[x + 1][y] = -1;
                    A[x][y] = -1;
                    A[x + 2][y] = -1;
                    A[x][y - 1] = -1;
                    Sleep(0);
                    break;
                case 13:
                    A[x + 1][y - 1] = -1;
                    A[x][y + 1] = -1;
                    A[x][y - 1] = -1;
                    A[x][y] = -1;
                    Sleep(0);
                    break;
                case 14:
                    A[x + 2][y - 1] = -1;
                    A[x + 2][y] = -1;
                    A[x][y - 1] = -1;
                    A[x + 1][y - 1] = -1;
                    Sleep(0);
                    break;
                
                case 15://xoay ziczac trái
                    A[x][y] = -1;
                    A[x][y + 1] = -1;
                    A[x + 1][y] = -1;
                    A[x + 1][y - 1] = -1;
                    Sleep(0);
                    break;

                case 16://xoay ziczac phải
                    A[x][y] = -1;
                    A[x][y - 1] = -1;
                    A[x + 1][y] = -1;
                    A[x + 1][y + 1] = -1;
                    Sleep(0);
                    break;

                case 17://xoay dấu cộng
                    A[x][y] = -1;
                    A[x][y - 1] = -1;
                    A[x][y + 1] = -1;
                    A[x + 1][y] = -1;
                    Sleep(0);
                    break;
                case 18:
                    A[x][y - 1] = -1;
                    A[x + 1][y - 1] = -1;
                    A[x + 2][y - 1] = -1;
                    A[x + 1][y] = -1;
                    Sleep(0);
                    break;
                case 19:
                    A[x][y] = -1;
                    A[x + 1][y] = -1;
                    A[x + 1][y - 1] = -1;
                    A[x + 1][y + 1] = -1;
                    Sleep(0);
                    break;
             }
             break;
         }
         
     }
 }
void goi(int a, int b)
 {//hàm gọi phần tử mảng là -1
     for (int i = 0; i < 35; i++)
     {
         A[a][b] = -1;
         ++a;
     }
 }
void play(int& x, int& y,int &k,int& t)
{//hàm chạy
    xoa(x, y,k);
    hinh(x, y, k);//in hình
    
    ++y;
    Sleep(t);
    if (_kbhit()&& kt(x, y, k)==0)
    {
        xoa(x, y - 1, k);
        char c = _getch();
        if (c == -32)
        {
            c = _getch();
       
            if (c == 72)
            {
                xoa(x, y, k);
                len(k);
            }
            if (c == 80)//xuống
            {
                ++y;
                if (t > 100)t = t - 170;//quy định chỉ nhanh đc 1 lần
            }
            if (c == 75)//trái
            {
                //if(x>x1)
                    --x;
                xoa(x + 1, y, k);
            }
            if (c == 77)//phải
            {
                //if(x<x2) 
                    ++x;
                xoa(x - 1, y, k);
            }
            
        }
    }
}
void len(int& k)
{
    switch (k)
    {
    case 1://thanh ngang
        k = 8;
        break;
    case 8:
        k = 1;
        break;

    case 3://chữ L phải
        k = 9;
        break;
    case 9:
        k = 10;
        break;
    case 10:
        k = 11;
        break;
    case 11:
        k = 3;
        break;

    case 4://chữ L trái
        k = 12;
        break;
    case 12:
        k = 13;
        break;
    case 13:
        k = 14;
        break;
    case 14:
        k = 4;
        break;
    
    case 15://ziczac trái
        k = 5;
        break;
    case 5://ziczac trái
        k = 15;
        break;

    case 16://ziczac phải
        k = 6;
        break;
    case 6://ziczac phải
        k = 16;
        break;

    case 7://dấu cộng
        k = 17;
        break;
    case 17://dấu cộng
        k = 18;
        break;
    case 18://dấu cộng
        k = 19;
        break;
    case 19://dấu cộng
        k = 7;
        break;
    }
}
bool kt(int x, int y, int k)
{//kiểm tra xem một trong dâu chấm có -1 ko
    switch (k)
    {
        case 1://thanh ngang
            if (A[x][y] == -1 || A[x + 1][y] == -1 || A[x + 2][y] == -1 || A[x + 3][y] == -1)
                return 1;
            else
                return 0;
        case 2://lập phương
            if (A[x][y + 1] == -1 || A[x + 1][y + 1] == -1)
                return 1;
            else 
                return 0;
        case 3://chữ L phải
            if (A[x ][y + 2] == -1 || A[x + 1][y + 2] == -1)
                return 1;
            else
                return 0;
        case 4://chữ L trái
            if (A[x][y + 2] == -1 || A[x + 1][y + 2] == -1)
                return 1;
            else
                return 0;
        case 5://ziczac trái
            if (A[x][y] == -1 || A[x + 1][y + 1 ] == -1 || A[x + 2][y + 1] == -1)
                return 1;
            else
                return 0;
        case 6://ziczac phải
            if (A[x][y + 1] == -1 || A[x + 1][y + 1] == -1 || A[x + 2][y] == -1)
                return 1;
            else
                return 0;
        case 7://cong
            if (A[x][y+1] == -1 || A[x + 1][y + 1] == -1 || A[x + 2][y + 1] == -1)
                return 1;
            else
                return 0;
        
        case 8://thanh dọc
            if (A[x][y + 4] == -1)
                return 1;
            else
                return 0;
        
        case 9://xoay chữ L phải
            if (A[x][y + 1] == -1 || A[x + 1][y + 1] == -1 || A[x + 2][y + 1] == -1)
                return 1;
            else
                return 0;
        case 10:
            if (A[x + 1][y + 2] == -1 || A[x][y] == -1)
                return 1;
            else
                return 0;
        case 11:
            if (A[x][y + 1] == -1 || A[x + 1][y] == -1 || A[x + 2][y] == -1)
                return 1;
            else
                return 0;

        case 12://xoay chữ L trái
            if (A[x][y + 1] == -1 || A[x + 1][y + 1] == -1 || A[x + 2][y + 1] == -1)
                return 1;
            else
                return 0;
        case 13:
            if (A[x][y + 2] == -1 || A[x + 1][y] == -1)
                return 1;
            else
                return 0;
        case 14:
            if (A[x][y] == -1 || A[x + 1][y] == -1 || A[x + 2][y + 1] == -1)
                return 1;
            else
                return 0;

        case 15://xoay ziczac trái
            if (A[x][y + 2] == -1 || A[x + 1][y + 1] == -1)
                return 1;
            else
                return 0;
        
        case 16://xoay ziczac phải
            if (A[x + 1][y + 2] == -1 || A[x][y + 1] == -1)
                return 1;
            else
                return 0;

        case 17://xoay dấu cộng
            if (A[x][y + 2] == -1 || A[x + 1][y + 1] == -1)
                return 1;
            else
                return 0;
        case 18://xoay dấu cộng
            if (A[x][y] == -1 || A[x + 2][y] == -1 || A[x + 1][y + 1] == -1)
                return 1;
            else
                return 0;
        case 19://xoay dấu cộng
            if (A[x][y + 1] == -1 || A[x + 1][y + 2] == -1)
                return 1;
            else
                return 0;
    }
}
bool kthang(int &Y)
{//kiểm tra hàng có đầy hay ko
    for (int i = b2-1; i >4; i--)//bắt đầu từ dưới kiểm tra lên
    {
        int s = 0;
        for (int j = a2 + 1; j < (a2 + 33); j++)//từ trái qua phải
        {
            if (A[j][i] == 0)
            {
                s++;
            }
        }
        if (s == 0)
        {
            Y = i;
            return 1;
        }
    }
    return 0;
}
void xoah(int Y)
{//xóa hàng
    for (int i = a2 + 1; i < (a2 + 33); i++)
    {
        A[i][Y] = 0;
        gotoXY(i, Y);
        setColor(0);
        cout << "=";
        setColor(15);
    }
    dichuyenh(Y);
}
void dichuyenh(int Y)
{//di chuyển hàng trên khi xóa hàng dưới
    for (int i = Y - 1; i > 4; i--)
    {
        for (int j = a2 + 1; j < (a2 + 33); j++)
        {
            if (A[j][i] == -1)
            {
                A[j][i] = 0;
                A[j][i + 1] = -1;
                gotoXY(j, i);
                setColor(0);
                cout << "=";
                setColor(8);
                gotoXY(j, i+1);
                cout << "=";
                setColor(15);
            }
        }
    }
}
void goilaihang()
{//hàm gọi lại phần tử =
    for (int i = b2-1; i > 1; i--)//bắt đầu từ dưới kiểm tra lên
    {
        for (int j = a2 + 1; j < (a2 + 33); j++)//từ trái qua phải
        {
            if (A[j][i] == -1)
            {
                gotoXY(j, i);
                setColor(1);
                cout << "=";
                setColor(15);
            }
            if(A[j][i] == 0)
            {
                gotoXY(j, i);
                cout << " ";
            }
        }
       
    }
}
void Nocursortype()//hàm ẩn con chuột trên màn hình console
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void menu()
{
    int x = 10 , y = 10,k;
   
    while(1)
    {
        system("cls");
        gotoXY(x,y);
        cout<<"=========================================================";gotoXY(x,y+1);
        cout<<"=                     GAME XEP GACH                     =";gotoXY(x,y+2);
        cout<<"=========================================================";gotoXY(x,y+3);
        cout<<"=                                                       =";gotoXY(x,y+4);
        cout<<"=                                                       =";gotoXY(x,y+5);
        cout<<"=                      1.PLAY GAME                      =";gotoXY(x,y+6);
        cout<<"=                      2.HIGH SCORE                     =";gotoXY(x,y+7);
        cout<<"=                      3.EXIT GAME                      =";gotoXY(x,y+8);
        cout<<"=                                                       =";gotoXY(x,y+9);
        cout<<"=                                                       =";gotoXY(x,y+10);
        cout<<"=                                                       =";gotoXY(x,y+11);
        cout<<"=========================================================";gotoXY(x,y+12);
        cin>>k;
        switch(k)
        case 1:
            break;
    }
}
void highscore(hs ngc[] )
{
    
    gotoXY(1,5);
    setColor(6);
    cout<<"===============================HIGH SCORE===============================";
    setColor(15);
    xuaths(ngc);
    gotoXY(1,13);
    setColor(6);
    cout<<"===============================HIGH SCORE===============================";
    setColor(15);
   
}
void highscoreN(hs ngc[])
{
    int x = 18,y = 3;
    gotoXY(x,y);
    cout<<"MY NAME IS: ";
    gotoXY(x+12,y);
    fgets(ngc[5].name,30,stdin);
    fstream f;
    int j=0;
    f.open("HighScore.txt",ios::in);
    while(!f.eof())
    {
        f>>ngc[j].score;
        f>>ngc[j].name;
        j++;
        if(j==6)break;
    }
    for(int i=0;i < 4;i++)
    {
        for(int j=1;j<5;j++)
        {
            if(ngc[i].score<ngc[j].score)
            {
                ngc[6]=ngc[j];
                ngc[j]=ngc[i];
                ngc[i]=ngc[6];
            }
        }
        
    }
    highscoret(ngc);
}
void highscoret(hs ngc[])
{
    fstream f;
    f.open("HighScore.txt",ios::out);
    for(int i=0; i < 5;i++ )
    {
        f<<ngc[i].score;
        f<<ngc[i].name;
        f<<endl;
        i++;
    }
}
void xuaths(hs ngc[])
{
    int a;
    char b[30];
    fstream f;
    f.open("HighScore.txt",ios::in);
    while(!f.eof())
    {
        f>>a;
        f>>b;
        cout<<b<<" "<<a<<endl;
    }
}
#include<iostream>
#include<conio.h>
#include<time.h>
#include <stdio.h>
#include<Windows.h>
#include<cmath>
#include<math.h>
using namespace std;
#define Dai 29
#define Rong 29
void clrscr(void)
{
CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
HANDLE hConsoleOut;
COORD Home = {0,0};
DWORD dummy;

hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
csbiInfo.dwCursorPosition.X = 0; 
csbiInfo.dwCursorPosition.Y = 0; 
SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition); 
}
class BongDen
{
	private:
		int x,y;
	public:
		BongDen(int _x,int _y)
		{
			x = _x;
			y = _y;
		}
		int GetX()
		{
			return x;
		}
		int GetY()
		{
			return y;
		}
	
		
		
};
class Nguoi
{
	private:
		int xNguoi,yNguoi;
	public:
		Nguoi(int _xNguoi,int _yNguoi)
		{
			xNguoi = _xNguoi;
			yNguoi = _yNguoi;
		}
		void SetXNguoi(int ToaDoX)
		{
			this->xNguoi = ToaDoX;
			
		}
		void SetYNguoi(int ToaDoY)
		{
			this->yNguoi = ToaDoY;
		}
		int GetXNguoi()
		{
			return xNguoi;
		}
		int GetYNguoi()
		{
			return yNguoi;
		}
		
};
void HienThi(Nguoi N,BongDen D1, BongDen D2, BongDen D3, BongDen D4, BongDen D5, BongDen D6);
Nguoi DieuKhien(Nguoi N);
int XuLy(Nguoi N);
double KhoangCachNguoiDen(Nguoi N, BongDen D);
BongDen SoSanh(Nguoi N,BongDen D1, BongDen D2, BongDen D3, BongDen D4, BongDen D5, BongDen D6);
void HienThiKetNoi(Nguoi N,BongDen D1, BongDen D2, BongDen D3, BongDen D4, BongDen D5, BongDen D6);
void HienThi(Nguoi N,BongDen D1, BongDen D2, BongDen D3, BongDen D4, BongDen D5, BongDen D6)
{
	clrscr();
	for(int i=0 ;i<Dai;++i)
	{
		for(int j=0;j<Rong;++j)
		{
			if(N.GetXNguoi() == i && N.GetYNguoi() == j)
			{
				cout<<"N1";
			}
			else if(D1.GetX() == i && D1.GetY() == j)
			{
				cout<<"D1";
			}
			else if(D2.GetX() == i && D2.GetY() == j)
			{
				cout<<"D2";
			}
			else if(D3.GetX() == i && D3.GetY() == j)
			{
				cout<<"D3";
			}
			else if(D4.GetX() == i && D4.GetY() == j)
			{
				cout<<"D4";
			}
			else if(D5.GetX() == i && D5.GetY() == j)
			{
				cout<<"D5";
			}
			else if(D6.GetX() == i && D6.GetY() == j)
			{
				cout<<"D6";
			}
			else
			{
				cout<<"  ";
			}
		}
		cout<<"|"<<endl;
	}
	HienThiKetNoi(N,D1,D2,D3,D4,D5,D6);
	
}
Nguoi DieuKhien(Nguoi N)
{
	int i=N.GetXNguoi(),j=N.GetYNguoi();
	int key = _getch();
	if (key == 'a' || key == 'A')
	{
		j--;
		N.SetYNguoi(j);
		return N;
	}
	else if (key == 'w' || key == 'W')
	{
		i--;
		N.SetXNguoi(i);
		return N;
	}
	else if (key == 'S' || key == 's')
	{
		i++;
		N.SetXNguoi(i);
		return N;
	}
	else if (key == 'd' || key == 'D')
	{
		j++;
		N.SetYNguoi(j);
		return N;
	}
}
int XuLy(Nguoi N)
{
	if(N.GetXNguoi() >= Dai || N.GetYNguoi() >= Rong || N.GetXNguoi() < 0 || N.GetYNguoi() < 0)
	{
		return -1;
	}
}
double KhoangCachNguoiDen(Nguoi N, BongDen D)
{
	double A,R,h,m, CosA, Tong;
	A = 0.0001;
	R = 0.6;
	h = 3.0;
	m = 1;
	double KhoangCach, ToaDoX, ToaDoY, KhoangCachND;
	ToaDoX = (D.GetX() - N.GetXNguoi());
//	cout<<"Toa Do X : "<<ToaDoX<<endl;
	ToaDoY = (D.GetY() - N.GetYNguoi());
//	cout<<"Toa Do Y : "<<ToaDoY<<endl;
	KhoangCach = sqrt((ToaDoX*ToaDoX)+(ToaDoY*ToaDoY));
//	cout<<"Khoang cach : "<<KhoangCach<<endl;
	CosA = h/KhoangCach;
	double radian=acos(CosA);
	double Do = (radian*180)/3.1415;
//	cout<<"Do la : "<<Do<<endl;
//	cout<<"COSA : "<<CosA<<endl;
	Tong = ((m+1)*A*R*CosA*CosA)/(2*3.14*(KhoangCach*KhoangCach));
//	cout<<"Tong : "<<Tong<<endl;
	if(0<Do<60)
	{
		return Tong;
	}
	else
	{
		return 0;
	}
	
}
void HienThiKetNoi(Nguoi N,BongDen D1, BongDen D2, BongDen D3, BongDen D4, BongDen D5, BongDen D6)
{
	double DanhSachDen[] = {KhoangCachNguoiDen(N,D1),KhoangCachNguoiDen(N,D2),KhoangCachNguoiDen(N,D3),KhoangCachNguoiDen(N,D4),KhoangCachNguoiDen(N,D5),KhoangCachNguoiDen(N,D6)};
	double SoSanh = KhoangCachNguoiDen(N,D1);
	int SoDen = 1;
	for(int i=0;i<6;i++)
	{
		if(SoSanh < DanhSachDen[i])
		{
			SoSanh = DanhSachDen[i];
			SoDen = i+1;
		}
	}
	cout<<"Ket Noi Voi Den "<<SoDen<<endl;
	
}
int main()
{

	int ma;
	Nguoi N(20,21);
	BongDen D1(9,3);
	BongDen D2(9,12);
	BongDen D3(9,21);
	BongDen D4(20,3);
	BongDen D5(20,12);
	BongDen D6(20,21);
	double K1,K2,K3,K4,K5,K6;
	KhoangCachNguoiDen(N, D1);
//	cout<<"Hien Thi Den 2"<<endl;
	KhoangCachNguoiDen(N, D2);
//	cout<<"Hien thi Den 3 "<<endl;
	KhoangCachNguoiDen(N, D3);
//	cout<<"Hien thi Den 4 "<<endl;
	KhoangCachNguoiDen(N, D4);
//	cout<<"Hien thi Den 5 "<<endl;
	KhoangCachNguoiDen(N, D5);
//	cout<<"Hien thi Den 6 "<<endl;
	KhoangCachNguoiDen(N, D6);

	
	while(1)
	{
		HienThi(N,D1,D2,D3,D4,D5,D6);
		cout<<"Dien khien bang a s d w"<<endl;
		cout<<"Toa Do X : ";
		cout<<N.GetXNguoi();
		cout<<endl;
		cout<<"Toa Do Y :";
		cout<<N.GetYNguoi();
		cout<<endl;
		N = DieuKhien(N);
		ma = XuLy(N);
		if(ma==-1) 
		{
			cout<<"Ban Da Thoat Ra Khoi Phong"<<endl;
			break;
		}
	}
	return 0;
}

#include<iostream>
#include<conio.h>
#include<time.h>
#include <stdio.h>
#include<Windows.h>
#include<cmath>
#include<math.h>
#include<cstdlib>
using namespace std;
#define Dai 15
#define Rong 20
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
		double NangLuongDen;
	public:
		BongDen(int _x,int _y)
		{
			x = _x;
			y = _y;
			NangLuongDen = 27;
		}
		int GetX()
		{
			return x;
		}
		int GetY()
		{
			return y;
		}
		double GetNangLuongDen()
		{
			return NangLuongDen;
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
Nguoi ViTriNgauNhien(Nguoi N);
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
Nguoi ViTriNgauNhien(Nguoi N)
{
	int i=N.GetXNguoi(),j=N.GetYNguoi();
	N.SetXNguoi(rand() % 15 + 0);
	N.SetYNguoi(rand() % 20 + 0);
	return N;

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
	double 	radian=acos(CosA);
	int Do = (radian*180)/3.1415;
//	cout<<"Do la : "<<Do<<endl;
//	cout<<"COSA : "<<CosA<<endl;
	Tong = ((m+1)*A*R*CosA*CosA)/(2*3.14*(KhoangCach*KhoangCach));
//	cout<<"Tong : "<<Tong<<endl;
	if(Do<60)
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
	double PR = 0, CongSuat, SNR, Data;
	double DanhSachDen[] = {KhoangCachNguoiDen(N,D1),KhoangCachNguoiDen(N,D2),KhoangCachNguoiDen(N,D3),KhoangCachNguoiDen(N,D4),KhoangCachNguoiDen(N,D5),KhoangCachNguoiDen(N,D6)};
	double SoSanh = KhoangCachNguoiDen(N,D1);
	int SoDen = 1;
	for(int i=0;i<6;i++)
	{
		PR = PR + DanhSachDen[i];
		if(SoSanh < DanhSachDen[i])
		{
			SoSanh = DanhSachDen[i];
			SoDen = i+1;
		}
	}
	CongSuat = PR * 27;
	SNR = (CongSuat)/(pow(10,-20));
	cout<<"SNR : "<<SNR<<endl;
	Data = (5*(pow(10,6)))*log2(1+SNR)/(pow(10,6));
	double D = 10*log(SNR);
	cout<<"D : "<<D<<endl;
	cout<<"Ket Noi Voi Den : "<<SoDen<<endl;
	cout<<"Cong Suat Cua Den : "<<CongSuat<<endl;
	cout<<"Data : "<<Data<<endl;
	
}
int main()
{

	Nguoi N(0,0);
	BongDen D1(4,5);
	BongDen D2(4,10);
	BongDen D3(4,15);
	BongDen D4(10,5);
	BongDen D5(10,10);
	BongDen D6(10,15);
	while(1)
	{
		N = ViTriNgauNhien(N);
		HienThi(N,D1,D2,D3,D4,D5,D6);
		Sleep(3000);
	}
	return 0;
}

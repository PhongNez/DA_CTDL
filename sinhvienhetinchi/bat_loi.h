#pragma once
#include"loadfile.h"
//Chuan hoa in hoa het
void chuan_hoa(string& a)
{
	//   tU lANh   
	//xoa khoang trang dau
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	//xoa cuoi
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
		}
	}
}

void chuan_hoa_ten(string& a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	//xoa cuoi
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
		}
	}
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			i++;
			if (a[i] >= 97 && a[i] <= 122)
			{
				a[i] -= 32;
			}
		}
		else
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a[i] += 32;
			}

		}
	}
}

void xuLyNhapHo(string& ho, int x,int &thoat,int dodai)
{
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == DAUCACH) && ho.length() < dodai)
		{
			if (ho.length()>0)
			{
				if(ho[ho.length() - 1] == ' ' && c== DAUCACH)
				continue;
			}
				cout << c;
				ho.insert(ho.end(), c);
				xtemp++;
			
		}
		else if (c == ENTER && ho.length() > 0 && ho !=" ")//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && ho.length() > 0)
		{
			ho.erase(ho.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}

}

void xuLyNhapTen(string& ten, int x, int& thoat,int dodai)
{
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && ten.length() < dodai)
		{
			cout << c;
			ten.insert(ten.end(), c);
			xtemp++;

		}
		else if (c == ENTER && ten.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && ten.length() > 0)
		{
			ten.erase(ten.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}

}

void xuLyNhapSoDienThoai(string& so, int x, int& thoat,int dodai)
{
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if (c >= 48 && c <= 57 && so.length() < dodai)
		{
			cout << c;
			so.insert(so.end(), c);
			xtemp++;

		}
		else if (c == ENTER && so.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && so.length() > 0)
		{
			so.erase(so.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}
}

void xuLyNhapMaSV(string& masv, int x, int& thoat,int dodai)
{
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if (((c >= 48 && c <= 57)|| (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && masv.length() < dodai)
		{
			cout << c;
			masv.insert(masv.end(), c);
			xtemp++;

		}
		else if (c == ENTER)//ENTER
		{
			if (masv.length() == 0)
			{
				thoat = -1;
			}
			break;
		}
		else if (c == BACKSPACE && masv.length() > 0)
		{
			masv.erase(masv.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}
}

void xuLyNhapMaLop(string& masv, int x, int& thoat,int dodai)
{
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 45) && masv.length() < dodai)
		{
			cout << c;
			masv.insert(masv.end(), c);
			xtemp++;

		}
		else if (c == ENTER && masv.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && masv.length() > 0)
		{
			masv.erase(masv.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}
}

void xuLyNhapSoNguyen(int &so, int x, int& thoat,int dodai)
{
	string chuoi = "";
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if ((c >= 48 && c <= 57) && chuoi.length() < dodai)
		{
			cout << c;
			chuoi.insert(chuoi.end(), c);
			xtemp++;

		}
		else if (c == ENTER && chuoi.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && chuoi.length() > 0)
		{
			chuoi.erase(chuoi.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}
	if (!chuoi.empty())
		so = stoi(chuoi.c_str());
}

void xuLyNhapNienKhoa(string& nienkhoa, int x, int& thoat,int dodai)
{
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if (((c >= 48 && c <= 57) || c == 45) && nienkhoa.length() < dodai)
		{
			if (nienkhoa.length() > 0)
			{
				if (nienkhoa[nienkhoa.length() - 1] == '-' && c == 45)
					continue;
			}
			cout << c;
			nienkhoa.insert(nienkhoa.end(), c);
			xtemp++;

		}
		else if (c == ENTER && nienkhoa.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && nienkhoa.length() > 0)
		{
			nienkhoa.erase(nienkhoa.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}
}

void xuLyNhapHocKy(int& hocky, int x, int& thoat,int dodai)
{
	string chuoi ="";
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if ((c >= 49 && c <= 51) && chuoi.length() < dodai)
		{
			cout << c;
			chuoi.insert(chuoi.end(), c);
			xtemp++;

		}
		else if (c == ENTER && chuoi.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && chuoi.length() > 0)
		{
			chuoi.erase(chuoi.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}
	if (!chuoi.empty())
		hocky = stoi(chuoi.c_str());
}

void xuLyNhapSV_Min_Max(int& hocky, int x, int& thoat, int dodai)
{
	string chuoi = "";
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if ((c >= 48 && c <= 57) && chuoi.length() < dodai)
		{
			cout << c;
			chuoi.insert(chuoi.end(), c);
			xtemp++;

		}
		else if (c == ENTER && chuoi.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && chuoi.length() > 0)
		{
			chuoi.erase(chuoi.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}
	if (!chuoi.empty())
		hocky = stoi(chuoi.c_str());
}

void xuLyDongYHuy(int& thoat)
{
	char c;
	while (true)
	{
		c = _getch();
		if (c == ENTER)//ENTER
		{
			break;
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
	}
}

void xuLyNhapDiem(float& diem, int x, int& thoat, int dodai)
{
	string chuoi = "";
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if (((c >= 48 && c <= 57)||c==46) && chuoi.length() < dodai)
		{
			cout << c;
			chuoi.insert(chuoi.end(), c);
			xtemp++;

		}
		else if (c == ENTER && chuoi.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && chuoi.length() > 0)
		{
			chuoi.erase(chuoi.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
		/*else if (c == -32)
		{
			c = _getch();
			if (c == 80 )
			{
				break;
			}
			else if (c == 72)
			{
				break;
			}

		}*/

	}
	if (!chuoi.empty())
		diem = atof(chuoi.c_str());
}

void xuLyNhapNhapTrangThai(int& trangthai, int x, int& thoat, int dodai)
{
	string chuoi = "";
	int xtemp = x - 1;
	char c;
	while (true)
	{
		c = _getch();
		if ((c >= 48 && c <= 49) && chuoi.length() < dodai)
		{
			cout << c;
			chuoi.insert(chuoi.end(), c);
			xtemp++;

		}
		else if (c == ENTER && chuoi.length() > 0)//ENTER
		{

			break;
		}
		else if (c == BACKSPACE && chuoi.length() > 0)
		{
			chuoi.erase(chuoi.length() - 1, 1);
			gotoXY(xtemp, whereY());
			cout << " ";
			gotoXY(xtemp--, whereY());
		}
		else if (c == ESC)//ESC
		{
			thoat = -1;
			break;
		}
	}
	if (!chuoi.empty())
		trangthai = stoi(chuoi.c_str());
}
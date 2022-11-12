#pragma once
#include"menu_sv_dk.h"

void menu_chinh()
{
	//setting
	DS_LOP_TC ds_lop;
	DS_SV ds_sv;
	DS_MON_HOC ds_mh;
	//loadfile
	loadfile(ds_lop);
	loadfile_sv_dangky(ds_lop);
	loadfile_sv(ds_sv);
	loadfile_mon_hoc(ds_mh);
	//menu
	bool kt_menu = true;
	while (kt_menu == true)
	{
		system("cls");
		cout << "1.LOP TIN CHI" << endl;
		cout << "2.SINH VIEN" << endl;
		cout << "3.MON HOC" << endl;
		cout << "4.SINH VIEN DANG KY" << endl;
		cout << "0.Thoat" << endl;
		char c;
		while (true)
		{
			c = _getch();
			if (c == 49)
			{
				menu_loptc(ds_lop,ds_sv,ds_mh);
				_getch();
				break;
			}
			else if (c == 50)
			{
				menu_sv(ds_lop, ds_sv, ds_mh);
				_getch();
				break;
			}
			else if (c == 51)
			{
				menu_mon_hoc(ds_lop, ds_sv, ds_mh);
				system("pause");
				break;
			}
			else if (c == 52)
			{
				menu_sv_dk(ds_lop, ds_sv, ds_mh);
				_getch();
				break;
			}
			else if (c == 48) {
				kt_menu = false;
				break;
			}
		}
	}
}
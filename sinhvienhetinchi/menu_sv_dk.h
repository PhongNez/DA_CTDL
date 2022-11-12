#pragma once
#include"mylib.h"
#include"ds_sv.h"


void menu_sv_dk(DS_LOP_TC ds_lop, DS_SV ds_sv, DS_MON_HOC ds_mh)
{
	//menu
	bool kt_menu = true;
	while (kt_menu == true)
	{
		system("cls");
		cout << "1.Dang ky lop tin chi" << endl;//dk
		cout << "2.Nhap diem cho sinh vien" << endl;//dk
		cout << "3.In danh sach dang ky" << endl;
		cout << "4.Huy sinh vien dang ky" << endl;//dk
		cout << "0.Thoat" << endl;
		char c;
		while (true)
		{
			c = _getch();
			if (c == 51)
			{
				//in_ds_sv_dk(ds_lop);
				sap_xep_sv(ds_sv);
				in_ds_sv_con_dk(ds_lop, ds_sv);
				_getch();
				break;
			}
			else if (c == 49)
			{
				dang_ky_loptc(ds_lop, ds_sv, ds_mh.t, ds_mh);
				_getch();
				break;
			}
			else if (c == 50)
			{
				sap_xep_sv(ds_sv);
				nhap_diem_sv(ds_lop, ds_sv);
				system("pause");
				break;
			}
			else if (c == 52)
			{
				huy_sv_dk(ds_lop, ds_sv);
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




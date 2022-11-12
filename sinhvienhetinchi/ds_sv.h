#pragma once
#include"ds_mon.h"

//=======================Them sinh vien==================
int kt_ma_sv(DS_SV ds_sv, string masv);
void them_sinh_vien(DS_SV& dssv);
//=======================Them sinh vien==================

//==========in danh sach sinh vien===========
int kt_malop_sv(DS_SV dssv, string malop);
void in_ds_sv(DS_SV dssv);
//==========in danh sach sinh vien===========

//========================Xoa so sinh vien================
int kt_ma_lop_sv(DS_SV ds_sv, string malop, string massv);
void xoa_sinh_vien(DS_SV& ds_sv);
//========================Xoa so sinh vien================

//=======================Hieu chinh sinh vien==============
void hieu_chinh_sinh_vien(DS_SV& ds_sv);
//=======================Hieu chinh sinh vien==============

//=======================Sap xep danh sach sinh vien===============
//void sap_xep_sv(DS_SV& ds_sv);
//=======================Sap xep danh sach sinh vien===============




void menu_sv(DS_LOP_TC ds_lop, DS_SV dssv, DS_MON_HOC ds_mh)
{
	//setting
	
	//DS_SV ds_sv;
	//loadfile
	/*loadfile(ds_lop);
	loadfile_sv_dangky(ds_lop);
	loadfile_sv(dssv);
	loadfile_mon_hoc(ds_mh);*/
	//loadfile
	//loadfile_sv(dssv);

	//menu
	
	bool kt_menu = true;
	//char c;
	while (kt_menu == true)
	{
		system("cls");
		cout << "1.Them sinh vien" << endl;
		cout << "2.In danh sach sinh vien" << endl;
		cout << "3.Xoa bo sinh vien" << endl;
		cout << "4.Hieu chinh sinh vien" << endl;
		cout << "0.Thoat" << endl;
		char c;
		while (true) {
			c = _getch();
			if (c == 49)
			{
				//them_sinh_vien(dssv);
				if (dssv.sl == MAX_SV)
				{
					cout << "Khong the them sinh vien nua!\n";
				}
				else
				{
					//chen_mang(dssv);
					them_sinh_vien(dssv);
				}
				system("pause");
				break;
			}
			else if (c == 50)
			{
				sap_xep_sv(dssv);
				in_ds_sv(dssv);
				system("pause");
				break;
			}
			else if (c == 51)
			{
				xoa_sinh_vien(dssv);
				system("pause");
				break;
			}
			else if (c == 52)
			{
				hieu_chinh_sinh_vien(dssv);
				system("pause");
				break;
			}
			else if (c == 48) {
				kt_menu = false;
				/*textcolor(2);
				system("cls");
				menu_giaodien();*/
				break;
			}
		}
	}
}

//============them sv==============
void them_sinh_vien(DS_SV &dssv)
{
	SINHVIEN sv;
	//nhap sinh vien
	int thoat = 0;
	cout << "Nhap ma lop: ";
	string malop = "";
	xuLyNhapMaLop(malop, 13,thoat,11);
	if (thoat == -1)
	{
		return;
	}
	sv.malop = malop;
	//getline(cin, sv.malop);
	//cout << "\nNhap ma sinh vien: ";
	string masv;
	do {
		cout << "\nNhap ma sinh vien: ";
		masv = "";
		xuLyNhapMaSV(masv, 19,thoat,10);
		if (masv == "" || thoat==-1)
		{
			return;
		}
		if (kt_ma_sv(dssv, masv) >= 0)
		{
			cout << "\nMA SINH VIEN DA BI NHAP TRUNG!";
		}
		
	} while (kt_ma_sv(dssv, masv) >= 0);
	sv.ma_sv = masv;
	
	/*if (kt_ma_sv(dssv, sv.ma_sv) >= 0)
	{
		cout << "\nMA SINH VIEN DA BI NHAP TRUNG!\n";
		return;
	}*/
	//getline(cin, sv.ma_sv);
	//Nhap vao chuoi rong
	
	cout << "\nNhap ho: ";
	string ho = "";
	xuLyNhapHo(ho, 9,thoat,50);
	if (thoat == -1)
	{
		return;
	}
	sv.ho = ho;
	//getline(cin, sv.ho);
	cout << "\nNhap ten: ";
	string ten = "";
	xuLyNhapTen(ten, 10,thoat,10);
	if (thoat == -1)
	{
		return;
	}
	sv.ten = ten;
	//getline(cin, sv.ten);
	cout << "\nNhap phai: ";
	string phai = "";
	xuLyNhapTen(phai, 11,thoat,3);
	if (thoat == -1)
	{
		return;
	}
	sv.phai = phai;
	//getline(cin, sv.phai);
	cout << "\nNhap so dien thoai: ";
	string sdt = "";
	xuLyNhapSoDienThoai(sdt, 20,thoat,10);
	if (thoat == -1)
	{
		return;
	}
	sv.sodt = sdt;
	//chuan hoa
	chuan_hoa(sv.malop);
	chuan_hoa(sv.ma_sv);
	chuan_hoa_ten(sv.phai);
	chuan_hoa_ten(sv.ho);
	chuan_hoa_ten(sv.ten);
	//them sinh vien
	dssv.dssv[dssv.sl] = sv;
	dssv.sl++;
}



//==========in danh sach sinh vien===========
int kt_malop_sv(DS_SV dssv, string malop)
{
	for (int i = 0; i < dssv.sl; i++)
	{
		if (_strcmpi(dssv.dssv[i].malop.c_str(), malop.c_str()) == 0)
		{
			return i;
		}
	}
	return -1;
}

void in_ds_sv(DS_SV dssv)
{
	cout << "Nhap ma lop can in danh sach: ";
	//getline(cin, malop);
	int thoat = 0;
	string malop = "";
	xuLyNhapMaLop(malop, 30, thoat, 11);
	if (thoat == -1)
	{
		return;
	}
	int vt = kt_malop_sv(dssv, malop);
	if (vt < 0)
	{
		cout << "\nMa lop khong ton tai!" << endl;
	}
	else
	{
		cout << "\n\t\tLOP: " << malop << endl;
		for (int j = 0; j < dssv.sl; j++)
		{
			if (_stricmp(dssv.dssv[j].malop.c_str(), malop.c_str()) == 0)
			{
				cout << "\nMa sinh vien: " << dssv.dssv[j].ma_sv << endl;
				cout << "Ho ten: " << dssv.dssv[j].ho << " " << dssv.dssv[j].ten << endl;
				cout << "Phai: " << dssv.dssv[j].phai << endl;
				cout << "So dien thoai: " << dssv.dssv[j].sodt << endl;
				cout << "Ma lop: " << dssv.dssv[j].malop << endl;
			}
		}
	}
}

//========================Xoa so sinh vien================
//xoa sinh vien
int kt_ma_lop_sv(DS_SV ds_sv, string malop, string massv)
{
	for (int i = 0; i < ds_sv.sl; i++)
	{
		if ((_strcmpi(ds_sv.dssv[i].malop.c_str(), malop.c_str()) == 0) && (_strcmpi(ds_sv.dssv[i].ma_sv.c_str(), massv.c_str()) == 0))
		{
			return i;
		}
	}
	return -1;
}

void xoa_sinh_vien(DS_SV& ds_sv)
{
	int thoat = 0;
	cout << "Nhap ma lop can xoa sinh vien: ";
	string malop = "";
	xuLyNhapMaLop(malop, 31, thoat, 11);
	if (thoat == -1)
	{
		return;
	}
	//getline(cin, malop);
	if (kt_malop_sv(ds_sv, malop) < 0)
	{
		cout << "\nMa lop khong ton tai!";
		return;
	}
	cout << "\nNhap ma sinh vien can xoa: ";
	string mssv = "";
	xuLyNhapMaSV(mssv, 27, thoat, 10);
	if (mssv == "" || thoat == -1)
	{
		return;
	}
	//getline(cin, mssv);
	int vt = kt_ma_lop_sv(ds_sv, malop, mssv);
	cout << "\n\nBan co muon xoa MON HOC nay?\n\nENTER: DONG Y       ESC:THOAT\n";
	xuLyDongYHuy(thoat);
	if (thoat == -1)
	{
		return;
	}
	if (vt < 0)
	{
		cout << "\nMa sinh vien khong hop le!";
	}
	else
	{
		for (int i = vt; i < ds_sv.sl - 1; i++)
		{
			ds_sv.dssv[i].malop = ds_sv.dssv[i + 1].malop;
			ds_sv.dssv[i].ma_sv = ds_sv.dssv[i + 1].ma_sv;
			ds_sv.dssv[i].ho = ds_sv.dssv[i + 1].ho;
			ds_sv.dssv[i].ten = ds_sv.dssv[i + 1].ten;
			ds_sv.dssv[i].phai = ds_sv.dssv[i + 1].phai;
			ds_sv.dssv[i].sodt = ds_sv.dssv[i + 1].sodt;
		}
		ds_sv.sl--;
		cout << "\n\nXOA THANH CONG!\n";
	}
}

void hieu_chinh_sinh_vien(DS_SV& ds_sv)
{
	int thoat;
	cout << "Nhap ma lop can hieu chinh sinh vien: ";
	string malop = "";
	xuLyNhapMaLop(malop, 38, thoat, 11);
	if (thoat == -1)
	{
		return;
	}
	//getline(cin, malop);
	if (kt_malop_sv(ds_sv, malop) < 0)
	{
		cout << "\nMa lop khong ton tai!";
		return;
	}
	cout << "\nNhap ma sinh vien can hieu chinh: ";
	string mssv = "";
	xuLyNhapMaSV(mssv, 34, thoat, 10);
	if (mssv == "" || thoat == -1)
	{
		return;
	}
	//getline(cin, mssv);
	int vt = kt_ma_lop_sv(ds_sv, malop, mssv);
	if (vt < 0)
	{
		cout << "Khong ton tai ma lop!";
	}
	else
	{
		while (true)
		{
			thoat = 0;
			system("cls");
			cout << "\t\nSinh vien " << ds_sv.dssv[vt].ho + " " + ds_sv.dssv[vt].ten << endl;
			cout << "Ho: " << ds_sv.dssv[vt].ho << endl;
			cout << "Ten: " << ds_sv.dssv[vt].ten << endl;
			cout << "Phai: " << ds_sv.dssv[vt].phai << endl;
			cout << "So dien thoai: " << ds_sv.dssv[vt].sodt << endl;
			cout << "\n\t\tMoi nhap lua chon";
			cout << "\n1 Sua ho " << endl;
			cout << "2 Sua ten " << endl;
			cout << "3 Sua phai " << endl;
			cout << "4 Sua so dien thoai " << endl;
			char c;
			while (true)
			{
				c = _getch();
				if (c == 49)//1
				{
					cout << "\nNhap ho: ";
					string ho = "";
					xuLyNhapHo(ho, 9, thoat, 50);
					if (thoat == -1)
					{
						return;
					}
					chuan_hoa_ten(ho);
					ds_sv.dssv[vt].ho = ho;
				}
				else if (c == 50)
				{
					cout << "\nNhap ten: ";
					string ten = "";
					xuLyNhapTen(ten, 10, thoat, 10);
					if (thoat == -1)
					{
						return;
					}
					chuan_hoa_ten(ten);
					ds_sv.dssv[vt].ten = ten;
				}
				else if (c == 51)
				{
					cout << "\nNhap phai: ";
					string phai = "";
					xuLyNhapTen(phai, 11, thoat, 3);
					if (thoat == -1)
					{
						return;
					}
					chuan_hoa_ten(phai);
					ds_sv.dssv[vt].phai = phai;
				}
				else if (c == 52)
				{
					cout << "\nNhap so dien thoai: ";
					string sdt = "";
					xuLyNhapSoDienThoai(sdt, 20, thoat, 10);
					if (thoat == -1)
					{
						return;
					}
					ds_sv.dssv[vt].sodt = sdt;
				}
				else if (c == ENTER)//ENTER
				{
					break;
				}
				else if (c == ESC)//ESC
				{
					thoat = -1;
					return;
				}
			}
		}
	}
}


//Sap xep danh sach sinh vien theo thu tu alphabet
void sap_xep_sv(DS_SV& ds_sv)
{
		for (int i = 0; i <ds_sv.sl - 1; i++)
		{
			for (int j = i + 1; j < ds_sv.sl; j++)
			{
				if (ds_sv.dssv[i].ten > ds_sv.dssv[j].ten)
				{
					swap(ds_sv.dssv[i], ds_sv.dssv[j]);
				}
				else if (ds_sv.dssv[i].ten == ds_sv.dssv[j].ten)
				{
					if (ds_sv.dssv[i].ho > ds_sv.dssv[j].ho)
					{
						swap(ds_sv.dssv[i], ds_sv.dssv[j]);
					}
				}
			}
		}
}

int kt_ma_sv(DS_SV ds_sv,string masv)
{
	chuan_hoa(masv);
	for (int i = 0; i < ds_sv.sl; i++)
	{
		if (_strcmpi(ds_sv.dssv[i].ma_sv.c_str(), masv.c_str()) == 0)
		{
			return i;
		}
	}
	return -1;
}
//void them_sv(DS_SV& ds_sv, int vt, SINHVIEN sv)
//{
//	for (int i = ds_sv.sl; i > vt; i--)
//	{
//		ds_sv.dssv[i] = ds_sv.dssv[i - 1];
//	}
//	ds_sv.dssv[vt] = sv;
//	ds_sv.sl++;
//}


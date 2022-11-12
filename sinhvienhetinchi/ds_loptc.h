#pragma once
#include"bat_loi.h"
//Danh sach lop tin chi
//========================Them lop tin chi========================
int kt_ma_mh_nien_khoa_nhom(DS_LOP_TC ds_lop, string ma_mh, string nienkhoa,int hocky, int nhom);
void kt_mon_co_trong_ds_mon(TREE t, string ma_mon, int& kt);
void them_lop_tc(DS_LOP_TC& ds_lop,DS_MON_HOC ds_mon);
//========================Them lop tin chi========================

//=========================xuat=================================
void xuat_lop_tin_chi(DS_LOP_TC ds_lop);
//=========================xuat=================================

//=============================Xoa lop tin chi===============
void xoa_lop_tin_chi(DS_LOP_TC& ds_lop);
//=============================Xoa lop tin chi===============

//int kt_trung_ma_lop(DS_LOP_TC ds_lop, int malop);
//======================Hieu chinh lop ======================
void hieu_chinh_lop(DS_LOP_TC& ds_lop);
//======================Hieu chinh lop ======================

//NODE_DK* khoi_tao_node_dk(DANG_KY_LTC dk);
//void them_sv_dk(DS_DANG_KY& ds_dk, NODE_DK* sv_dk);
//============Lam tron diem 1 chu so thap phan
float lam_tron(float a);
float lam_tron_den_so_thap_phan(float so);

//================In danh sach sinh vien con dang ky lop tin chi ============
int kt_lop_cau_b(DS_LOP_TC ds, string nienkhoa, int hocky, int nhom, string ma_mh);
void in_ds_sv_con_dk(DS_LOP_TC ds_lop, DS_SV ds_sv);
//================In danh sach sinh vien con dang ky lop tin chi ============

//=================Đăng ký lớp tín chỉ============================================
int kt_sv_da_dk(DS_DANG_KY ds_dk, string ma_sv);
int kt_ma_sv_cau_h(DS_SV ds_sv, string masv);
int kt_loptc_cau_h(DS_LOP_TC ds_lop, string nienkhoa, int hocky);
void duyet_cay(DS_MON_HOC ds_mon, TREE t, string ma_mh, int x, int x_cach, int y, int j);
void dang_ky_loptc(DS_LOP_TC ds_lop, DS_SV ds_sv, TREE t, DS_MON_HOC ds_mon);
//=================Đăng ký lớp tín chỉ============================================

//=============================Huy lop tin chi===============
void huy_lop_tin_chi(DS_LOP_TC& ds_lop);
//=============================Huy lop tin chi===============

//========================NHAP DIEM=========================
void nhap_diem_sv(DS_LOP_TC ds_lop, DS_SV ds_sv);
//========================NHAP DIEM=========================

//====================IN BANG DIEM 1 LOP TIN CHI========================
void lay_ra_mon_hoc(TREE t, string mamh, string &tenmon);
void in_bang_diem_1_loptc(DS_LOP_TC ds_lop, DS_SV ds_sv,DS_MON_HOC ds_mon);
//====================IN BANG DIEM 1 LOP TIN CHI========================
void sap_xep_sv(DS_SV& ds_sv);

//==========================Huy sinh vien dang ky==============
void huy_sv_dk(DS_LOP_TC ds_lop, DS_SV ds_sv);
//==========================Huy sinh vien dang ky==============
void menu_loptc(DS_LOP_TC ds_lop, DS_SV ds_sv, DS_MON_HOC ds_mh)
{
	//menu
	bool kt_menu = true;
	while (kt_menu == true)
	{
		system("cls");
		cout << "1.Them lop tin chi" << endl;
		cout << "2.Xuat lop tin chi" << endl;
		cout << "3.Xoa lop tin chi" << endl;
		cout << "4.Hieu chinh lop tin chi" << endl;
		cout << "5.Huy lop tin chi" << endl;
		cout << "6.In bang diem 1 lop tin chi" << endl;
		cout << "0.Thoat" << endl;
		char c;
		while (true) {
			c = _getch();
			if (c == 49)
			{
				if (ds_lop.sl == MAX_LTC)
				{
					cout << "Khong the them lop duoc nua!" << endl;
				}
				else
				{
					them_lop_tc(ds_lop, ds_mh);
				}
				system("pause");
				break;
			}
			else if (c == 50)
			{
				xuat_lop_tin_chi(ds_lop);
				_getch();
				break;
			}
			else if (c == 51)
			{
				xoa_lop_tin_chi(ds_lop);
				/*system("pause");*/
				_getch();
				break;
			}
			else if (c == 52)
			{
				hieu_chinh_lop(ds_lop);
				//system("pause");
				_getch();
				break;
			}
			else if (c == 53)
			{
				huy_lop_tin_chi(ds_lop);
				system("pause");
				break;
			}
			else if (c == 54)
			{
				sap_xep_sv(ds_sv);
				in_bang_diem_1_loptc(ds_lop, ds_sv, ds_mh);
				//system("pause");
				_getch();
				break;
			}
			else if (c == 48) {
				kt_menu = false;
				break;
			}
			/*else if (c == ESC)
			{
				break;
			}*/
		}
	}
}

int kt_ma_mh_nien_khoa_nhom(DS_LOP_TC ds_lop,string ma_mh,string nienkhoa,int hocky,int nhom)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (ma_mh == ds_lop.ds_lop_tc[i]->ma_mh)
		{
			if (nienkhoa == ds_lop.ds_lop_tc[i]->nienkhoa)
			{
				if (hocky == ds_lop.ds_lop_tc[i]->hocky)
				{
					if (nhom == ds_lop.ds_lop_tc[i]->nhom)
					{
						return i;
					}
				}	
			}
		}
	}
	return -1;
}

//Them lop tin chi
void them_lop_tc(DS_LOP_TC& ds_lop,DS_MON_HOC ds_mon) {
	int thoat = 0;
	//cap phat
	LOP_TIN_CHI* p = new LOP_TIN_CHI;
	if (ds_lop.sl == 0)
	{
		p->ma_loptc = 1;
	}
	else
	{
		p->ma_loptc = ds_lop.ds_lop_tc[ds_lop.sl - 1]->ma_loptc + 1;
	}
	//ma lop tu dong tang
	cout << "Ma lop tin chi: " << p->ma_loptc << endl;
	int kt_mon_trong_ds=-1;
	do
	{
		cout << "Nhap ma mon hoc: ";
		string ma_mh = "";
		xuLyNhapMaSV(ma_mh, 17, thoat,10);
		if (thoat == -1)
		{
			return;
		}
		p->ma_mh = ma_mh;
		//getline(cin, p->ma_mh);
		chuan_hoa(p->ma_mh);
		kt_mon_co_trong_ds_mon(ds_mon.t, p->ma_mh, kt_mon_trong_ds);
		if (kt_mon_trong_ds < 0)
		{
			cout << "\nMA MON HOC KHONG TON TAI!" << endl;
		}
	} 	while (kt_mon_trong_ds < 0);

	cout << "\nNhap nien khoa: ";
	string nienkhoa = "";
	xuLyNhapNienKhoa(nienkhoa, 16, thoat,9);
	if (thoat == -1)
	{
		return;
	}
	p->nienkhoa = nienkhoa;
	//getline(cin, p->nienkhoa);

	cout << "\nNhap hoc ky: ";
	int hocky = 0;
	xuLyNhapHocKy(hocky, 13, thoat, 1);
	if (thoat == -1)
	{
		return;
	}
	p->hocky = hocky;
	//cin >> p->hocky;
	int kt;
	int nhom;
	do {
		cout << "\nNhap nhom: ";
		nhom = 0;
		xuLyNhapSoNguyen(nhom, 11, thoat, 4);
		kt = kt_ma_mh_nien_khoa_nhom(ds_lop, p->ma_mh, p->nienkhoa, p->hocky, nhom);
		if (thoat == -1)
		{
			return;
		}
		if (kt >= 0)
		{
			cout << "\nNhom da trung!";
		}
	} while (kt >= 0);
	
	p->nhom = nhom;
	//cin >> p->nhom;
	cout << "\nNhap so sinh vien min: ";
	int svmin = 0;
	xuLyNhapSV_Min_Max(svmin, 23, thoat, 4);
	if (thoat == -1)
	{
		return;
	}
	p->svmin = svmin;
	//cin >> p->svmin;

	int svmax;
	do {
		cout << "\nNhap so sinh vien max: ";
		svmax = 0;
		xuLyNhapSV_Min_Max(svmax, 23, thoat, 4);
		if (thoat == -1)
		{
			return;
		}
		if (svmin > svmax)
		{
			cout << "\nSo sinh vien max > svmin!";
		}
	} while (svmin > svmax);
	p->svmax = svmax;
	//cin >> p->svmax;
	p->trangthai_lop = 1;

	//chuan hoa
	chuan_hoa(p->ma_mh);
	//Them vao danh sach
	ds_lop.ds_lop_tc[ds_lop.sl] = p;
	ds_lop.sl++;
}

void xuat_lop_tin_chi(DS_LOP_TC ds_lop)
{
	//Toa do
	int x = 35;
	int x_cach = 15;
	int y = 2;
	//------------
	gotoXY(x, 1);
	cout << "MA LOP";
	gotoXY(x + x_cach, 1);
	cout << "MA MON HOC";
	gotoXY(x + x_cach * 2, 1);
	cout << "NIEN KHOA ";
	gotoXY(x + x_cach * 3, 1);
	cout << "HOC KY ";
	gotoXY(x + x_cach * 4, 1);
	cout << "NHOM ";
	gotoXY(x + x_cach * 5, 1);
	cout << "SL MIN ";
	gotoXY(x + x_cach * 6, 1);
	cout << "SL MAX ";
	for (int i = 0; i < ds_lop.sl; i++)
	{
		//cout << "\t\tLOP TIN CHI " << ds_lop.ds_lop_tc[i]->ma_loptc << ": " << endl;
		 
		 gotoXY(x, y + i + 2);cout << ds_lop.ds_lop_tc[i]->ma_loptc << endl;
		 gotoXY(x + x_cach, y + i + 2); cout << ds_lop.ds_lop_tc[i]->ma_mh << endl;
		 gotoXY(x + x_cach*2, y + i + 2); cout << ds_lop.ds_lop_tc[i]->nienkhoa << endl;
		 gotoXY(x + x_cach*3, y + i + 2); cout << ds_lop.ds_lop_tc[i]->hocky << endl;
		 gotoXY(x + x_cach*4, y + i + 2); cout << ds_lop.ds_lop_tc[i]->nhom << endl;
		 gotoXY(x + x_cach*5, y + i + 2); cout << ds_lop.ds_lop_tc[i]->svmin << endl;
		 gotoXY(x + x_cach*6, y + i + 2); cout << ds_lop.ds_lop_tc[i]->svmax << endl;

		//cout << ds_lop.ds_lop_tc[i]->trangthai_lop << endl;
	}
}

//=================xoa=========================================
void xoa_lop_tin_chi(DS_LOP_TC& ds_lop)
{
	int thoat = 0;
	int malop=0;
	cout << "Nhap ma lop can xoa: ";
	xuLyNhapSV_Min_Max(malop, 21, thoat, 5);
	if (thoat == -1)
	{
		return;
	}
	int vt = kt_trung_ma_lop(ds_lop, malop);
	cout << "\n\nBan co muon xoa LOP TIN CHI nay?\n\nENTER: DONG Y     ESC:THOAT\n";
	xuLyDongYHuy(thoat);
	if (thoat == -1)
	{
		return;
	}
	if (vt < 0)
	{
		cout << "Lop tin chi khong ton tai";
	}
	else
	{
		for (int j = vt; j < ds_lop.sl - 1; j++)
		{
			ds_lop.ds_lop_tc[j]->ma_loptc = ds_lop.ds_lop_tc[j + 1]->ma_loptc;
			ds_lop.ds_lop_tc[j]->ma_mh = ds_lop.ds_lop_tc[j + 1]->ma_mh;
			ds_lop.ds_lop_tc[j]->nienkhoa = ds_lop.ds_lop_tc[j + 1]->nienkhoa;
			ds_lop.ds_lop_tc[j]->hocky = ds_lop.ds_lop_tc[j + 1]->hocky;
			ds_lop.ds_lop_tc[j]->nhom = ds_lop.ds_lop_tc[j + 1]->nhom;
			ds_lop.ds_lop_tc[j]->svmin = ds_lop.ds_lop_tc[j + 1]->svmin;
			ds_lop.ds_lop_tc[j]->svmax = ds_lop.ds_lop_tc[j + 1]->svmax;
			ds_lop.ds_lop_tc[j]->trangthai_lop = ds_lop.ds_lop_tc[j + 1]->trangthai_lop;
			ds_lop.ds_lop_tc[j]->ds_dk = ds_lop.ds_lop_tc[j + 1]->ds_dk;
		}
		delete ds_lop.ds_lop_tc[ds_lop.sl - 1];
		ds_lop.ds_lop_tc[ds_lop.sl - 1] = NULL;
		ds_lop.sl--;
		cout << "\n\nXOA LOP TIN CHI THANH CONG";
	}
}


void huy_lop_tin_chi(DS_LOP_TC& ds_lop)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		int dem = 0;
		for (NODE_DK* k = ds_lop.ds_lop_tc[i]->ds_dk.phead; k != NULL; k = k->pnext)
		{
			dem++;
		}
		if (dem < ds_lop.ds_lop_tc[i]->svmin)
		{
			for (int j = i; j < ds_lop.sl - 1; j++)
			{
				ds_lop.ds_lop_tc[j]->ma_loptc = ds_lop.ds_lop_tc[j + 1]->ma_loptc;
				ds_lop.ds_lop_tc[j]->ma_mh = ds_lop.ds_lop_tc[j + 1]->ma_mh;
				ds_lop.ds_lop_tc[j]->nienkhoa = ds_lop.ds_lop_tc[j + 1]->nienkhoa;
				ds_lop.ds_lop_tc[j]->hocky = ds_lop.ds_lop_tc[j + 1]->hocky;
				ds_lop.ds_lop_tc[j]->nhom = ds_lop.ds_lop_tc[j + 1]->nhom;
				ds_lop.ds_lop_tc[j]->svmin = ds_lop.ds_lop_tc[j + 1]->svmin;
				ds_lop.ds_lop_tc[j]->svmax = ds_lop.ds_lop_tc[j + 1]->svmax;
				ds_lop.ds_lop_tc[j]->trangthai_lop = ds_lop.ds_lop_tc[j + 1]->trangthai_lop;
				ds_lop.ds_lop_tc[j]->ds_dk = ds_lop.ds_lop_tc[j + 1]->ds_dk;
			}
			//Giai phong
			delete ds_lop.ds_lop_tc[ds_lop.sl - 1];
			ds_lop.ds_lop_tc[ds_lop.sl - 1] = NULL;
			ds_lop.sl--;
			i--;
			cout << "Xoa thanh cong!" << endl;
		}
	}
}

int kt_trung_ma_lop(DS_LOP_TC ds_lop, int malop)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (ds_lop.ds_lop_tc[i]->ma_loptc == malop)
		{
			return i;
		}
	}
	return -1;
}

//Hieu chinh lop tin chi
void hieu_chinh_lop(DS_LOP_TC& ds_lop)
{
	int thoat=0;
	int malop = 0;
	cout << "Nhap ma lop can hieu chinh: ";
	xuLyNhapSV_Min_Max(malop, 28, thoat, 5);
	if (thoat == -1)
	{
		return;
	}
	int vt = kt_trung_ma_lop(ds_lop, malop);
	if (vt >= 0)
	{
		while (true)
		{
			thoat = 0;
			system("cls");
			cout << "LOP TIN CHI " << ds_lop.ds_lop_tc[vt]->ma_loptc << endl;
			cout << "\nMA MON HOC " << ds_lop.ds_lop_tc[vt]->ma_mh << endl;
			cout << "NIEN KHOA " <<ds_lop.ds_lop_tc[vt]->nienkhoa << endl;
			cout << "HOC KY " <<ds_lop.ds_lop_tc[vt]->hocky << endl;
			cout << "NHOM " << ds_lop.ds_lop_tc[vt]->nhom << endl;
			cout << "SV MIN "<<ds_lop.ds_lop_tc[vt]->svmin << endl;
			cout << "SV MAX "<<ds_lop.ds_lop_tc[vt]->svmax << endl;
			cout << "\n\n\t\tMoi nhap lua chon";
			cout << "\n1 Sua nien khoa " << endl;
			cout << "2 Sua hoc ky " << endl;
			cout << "3 Sua nhom " << endl;
			cout << "4 Sua so sinh vien min " << endl;
			cout << "5 Sua so sinh vien max " << endl;
			char c;
			while (true)
			{
				c = _getch();
				if (c == 49)//1
				{
					cout << "\nNhap nien khoa: ";
					string nienkhoa = "";
					xuLyNhapNienKhoa(nienkhoa, 16, thoat, 9);
					if (thoat == -1)
					{
						break;
					}
					ds_lop.ds_lop_tc[vt]->nienkhoa = nienkhoa;
				}
				else if (c == 50)
				{
					cout << "\nNhap hoc ky: ";
					int hocky = 0;
					xuLyNhapHocKy(hocky, 13, thoat, 1);
					if (thoat == -1)
					{
						break;
					}
					ds_lop.ds_lop_tc[vt]->hocky = hocky;
				}
				else if (c == 51)
				{
					cout << "\nNhap nhom: ";
					int nhom = 0;
					xuLyNhapSoNguyen(nhom, 11, thoat, 4);
					if (thoat == -1)
					{
						break;
					}
					ds_lop.ds_lop_tc[vt]->nhom = nhom;
				}
				else if (c == 52)
				{
					cout << "\nNhap so sinh vien min: ";
					int svmin = 0;
					xuLyNhapSV_Min_Max(svmin, 23, thoat, 4);
					if (thoat == -1)
					{
						break;
					}
					if (svmin <= ds_lop.ds_lop_tc[vt]->svmax)
					{
						ds_lop.ds_lop_tc[vt]->svmin = svmin;
					}
					else
					{
						cout << "\n\nSo sinh vien min <= so sinh vien max!\n";
					}
				}
				else if (c == 53)
				{
					cout << "\nNhap so sinh vien max: ";
					int svmax = 0;
					xuLyNhapSV_Min_Max(svmax, 23, thoat, 4);
					if (thoat == -1)
					{
						break;
					}
					if (ds_lop.ds_lop_tc[vt]->svmin <= svmax)
					{
						ds_lop.ds_lop_tc[vt]->svmax = svmax;
					}
					else
					{
						cout << "\n\nSo sinh vien max >= so sinh vien min!\n";
					}
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
		//chuan hoa
		chuan_hoa(ds_lop.ds_lop_tc[vt]->ma_mh);
		cout << "Ban da chinh sua thanh cong!" << endl;
	}
	else
	{
		cout << "Ma lop khong hop le!" << endl;
	}
}

//Danh sach dang ky
NODE_DK* khoi_tao_node_dk(DANG_KY_LTC dk)
{
	NODE_DK* p = new NODE_DK;
	p->data = dk;
	p->pnext = NULL;
	return p;
}
//Them sv dk
void them_sv_dk(DS_DANG_KY& ds_dk, NODE_DK* sv_dk)
{
	if (ds_dk.phead == NULL)//ds rong
	{
		ds_dk.phead = ds_dk.ptail = sv_dk;
	}
	else if (ds_dk.phead != NULL && ds_dk.phead->pnext == NULL)//1 phan tu
	{
		if (_strcmpi(sv_dk->data.masv.c_str(), ds_dk.phead->data.masv.c_str()) > 0)
		{
			ds_dk.ptail->pnext = sv_dk;
			ds_dk.ptail = sv_dk;
		}
		else if (_strcmpi(sv_dk->data.masv.c_str(), ds_dk.phead->data.masv.c_str()) < 0)
		{
			sv_dk->pnext = ds_dk.phead;
			ds_dk.phead = sv_dk;
		}
	}
	else
	{
		NODE_DK* h = new NODE_DK;
		for (NODE_DK* k = ds_dk.phead; k != NULL; k = k->pnext)
		{
			if ((_strcmpi(sv_dk->data.masv.c_str(), k->data.masv.c_str()) > 0) && k == ds_dk.ptail)
			{
				k->pnext = sv_dk;
				ds_dk.ptail = sv_dk;
				break;
			}
			else if ((_strcmpi(sv_dk->data.masv.c_str(), k->data.masv.c_str()) < 0) && k == ds_dk.phead)
			{
				sv_dk->pnext = k;
				ds_dk.phead = sv_dk;
				break;
			}
			else if (_strcmpi(sv_dk->data.masv.c_str(), k->data.masv.c_str()) < 0)
			{
				sv_dk->pnext = k;
				h->pnext = sv_dk;
				break;
			}
			h = k;
		}
	}
}

//=============them danh sach dang ky
//============Lam tron diem 1 chu so thap phan
float lam_tron(float a)
{
	//12447
	int b = a * 10;
	int phan_du = b % 10;
	if (phan_du >= 5)
	{
		return (int(a) + 1);
	}
	return int(a);
}

float lam_tron_den_so_thap_phan(float so)
{
	float result = lam_tron(so * 10) / 10;
	return result;
}



//================In danh sach sinh vien con dang ky lop tin chi ============
int kt_lop_cau_b(DS_LOP_TC ds, string nienkhoa, int hocky, int nhom, string ma_mh)
{
	for (int i = 0; i < ds.sl; i++)
	{
		if (_strcmpi(nienkhoa.c_str(), ds.ds_lop_tc[i]->nienkhoa.c_str()) == 0)
		{
			if (ds.ds_lop_tc[i]->hocky == hocky)
			{
				if (ds.ds_lop_tc[i]->nhom == nhom)
				{
					if (_strcmpi(ma_mh.c_str(), ds.ds_lop_tc[i]->ma_mh.c_str()) == 0)
					{
						return i;
					}
				}
			}
		}
	}
	return -1;
}

void in_ds_sv_con_dk(DS_LOP_TC ds_lop, DS_SV ds_sv)
{
	//cin.ignore();
	int thoat = 0;
	LOP_TIN_CHI* p = new LOP_TIN_CHI;
	cout << "\nNhap nien khoa: ";
	string nienkhoa = "";
	xuLyNhapNienKhoa(nienkhoa, 16, thoat, 9);
	if (thoat == -1)
	{
		return;
	}
	p->nienkhoa = nienkhoa;
	
	cout << "\nNhap hoc ky: ";
	int hocky = 0;
	xuLyNhapHocKy(hocky, 13, thoat, 1);
	if (thoat == -1)
	{
		return;
	}
	p->hocky = hocky;

	cout << "\nNhap nhom: ";
	int nhom = 0;
	xuLyNhapSoNguyen(nhom, 11, thoat, 4);
	if (thoat == -1)
	{
		return;
	}
	p->nhom = nhom;

	cout << "\nNhap ma mon hoc: ";
	string ma_mh = "";
	xuLyNhapMaSV(ma_mh, 17, thoat, 10);
	if (thoat == -1)
	{
		return;
	}
	p->ma_mh = ma_mh;
	int vt = kt_lop_cau_b(ds_lop, p->nienkhoa, p->hocky, p->nhom, p->ma_mh);
	if (vt < 0)
	{
		cout << "Lop tin chi khong ton tai!\n";
	}
	else
	{
		for (NODE_DK* k = ds_lop.ds_lop_tc[vt]->ds_dk.phead; k != NULL; k = k->pnext)
		{
			if (k->data.trangthai_dangky == 1)
			{
				int tk = kt_ma_sv_cau_h(ds_sv, k->data.masv);
				if (tk >= 0)
				{
					cout << "\nMa sinh vien: " << ds_sv.dssv[tk].ma_sv << endl;
					cout << "Ho ten sinh vien: " << ds_sv.dssv[tk].ho + " " + ds_sv.dssv[tk].ten << endl;
				}
			}
		}
	}
}

//=================Đăng ký lớp tín chỉ========== 
int kt_ma_sv_cau_h(DS_SV ds_sv, string masv)
{
	for (int i = 0; i < ds_sv.sl; i++)
	{
		if (_strcmpi(masv.c_str(), ds_sv.dssv[i].ma_sv.c_str()) == 0)
		{
			return i;
		}
	}
	return -1;
}

int kt_loptc_cau_h(DS_LOP_TC ds_lop, string nienkhoa, int hocky)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (nienkhoa==ds_lop.ds_lop_tc[i]->nienkhoa)
		{
			if (hocky == ds_lop.ds_lop_tc[i]->hocky)
			{
				return i;
			}
		}
	}
	return -1;
}

void duyet_cay(DS_MON_HOC ds_mon, TREE t, string ma_mh,int x,int x_cach,int y,int j)
{
	if (t != NULL)
	{
		if (_strcmpi(ma_mh.c_str(), t->data.ma_mh.c_str()) == 0)
		{
			gotoXY(x, y + j); cout << t->data.ma_mh << endl;
			gotoXY(x + x_cach * 1, y + j);cout << t->data.tenmh << endl;
		}
		duyet_cay(ds_mon, t->pleft, ma_mh,x,x_cach,y,j);
		duyet_cay(ds_mon, t->pright, ma_mh, x, x_cach, y, j);
	}
}

int kt_sv_da_dk(DS_DANG_KY ds_dk,string ma_sv)
{
	for (NODE_DK* k = ds_dk.phead; k != NULL; k = k->pnext)
	{
		if (_strcmpi(k->data.masv.c_str(),ma_sv.c_str())==0)
		{
			return 1;
		}
	}
	return -1;
}

void dang_ky_loptc(DS_LOP_TC ds_lop, DS_SV ds_sv, TREE t, DS_MON_HOC ds_mon)
{
	int thoat =0;
	string masv = "";
	cout << "\nNhap ma sinh vien: ";
	
	xuLyNhapMaSV(masv, 19, thoat, 10);
	if (masv == "" || thoat == -1)
	{
		return;
	}
	//getline(cin, masv);
	int kt_masv = kt_ma_sv_cau_h(ds_sv, masv);
	if (kt_masv < 0)
	{
		cout << "Sinh vien khong ton tai!" << endl;
		return;
	}
	else
	{
		cout << "\nMa sinh vien: " << ds_sv.dssv[kt_masv].ma_sv << endl;
		cout << "Ho ten: " << ds_sv.dssv[kt_masv].ho << " " << ds_sv.dssv[kt_masv].ten << endl;
		cout << "Phai: " << ds_sv.dssv[kt_masv].phai << endl;
		cout << "So dien thoai: " << ds_sv.dssv[kt_masv].sodt << endl;
		cout << "Ma lop: " << ds_sv.dssv[kt_masv].malop << endl;
	}
	cout << "\nNhap nien khoa: ";
	string nienkhoa = "";
	xuLyNhapNienKhoa(nienkhoa, 16, thoat, 9);
	if (thoat == -1)
	{
		return;
	}

	cout << "\nNhap hoc ky: ";
	int hocky = 0;
	xuLyNhapHocKy(hocky, 13, thoat, 1);
	if (thoat == -1)
	{
		return;
	}
	
	//int vt = kt_loptc_cau_h(ds_lop, nienkhoa, hocky);
	//Toa do
	int x = 35;
	int x_cach = 15;
	int y = 3;
	//------------
	gotoXY(x, 1);
	cout << "MA MON HOC";
	gotoXY(x + x_cach, 1);
	cout << "TEN MON HOC ";
	gotoXY(x + x_cach * 3, 1);
	cout << "NHOM ";
	gotoXY(x + x_cach * 4, 1);
	cout << "SV DK ";
	gotoXY(x + x_cach * 5, 1);
	cout << "SV CON LAI ";
	int j = 0;
	for (int i = 0; i < ds_lop.sl; i++)
	{

		if (nienkhoa == ds_lop.ds_lop_tc[i]->nienkhoa)
		{
			if (hocky == ds_lop.ds_lop_tc[i]->hocky)
			{
				duyet_cay(ds_mon, t, ds_lop.ds_lop_tc[i]->ma_mh,x,x_cach,y,j);
				gotoXY(x + x_cach * 3, y + j); cout << ds_lop.ds_lop_tc[i]->nhom << endl;
				int dem = 0;
				for (NODE_DK* k = ds_lop.ds_lop_tc[i]->ds_dk.phead; k != NULL; k = k->pnext)
				{
					if (k->data.trangthai_dangky == 1)
					{
						dem++;
					}	
				}
				gotoXY(x + x_cach * 4, y + j); cout << dem << endl;
				gotoXY(x + x_cach * 5, y + j); cout << ds_lop.ds_lop_tc[i]->svmax - dem << endl;
				j++;
			}
		}
	}
	gotoXY(0, 22);
	string ma_mh;
	int nhom,kt,kt_sv_dk;
	do {
		cout << "\nNhap ma mon: ";
		ma_mh = "";
		xuLyNhapMaSV(ma_mh, 13, thoat, 10);
		if (thoat == -1)
		{
			return;
		}
		cout << "\nNhap nhom: ";
		nhom = 0;
		xuLyNhapSoNguyen(nhom, 11, thoat, 4);
		if (thoat == -1)
		{
			return;
		}
		kt = kt_ma_mh_nien_khoa_nhom(ds_lop, ma_mh, nienkhoa, hocky, nhom);
		
		
		if (kt < 0)
		{
			cout << "Ma mon hoc hoac nhom khong dung!";
		}
		else
		{
			kt_sv_dk = kt_sv_da_dk(ds_lop.ds_lop_tc[kt]->ds_dk, masv);
			if (kt_sv_dk == 1)
			{
				cout << "\nSINH VIEN DA DANG KY ROI KHONG THE DANG KY NUA";
				return;
			}
			int dem = 0;
			for (NODE_DK* k = ds_lop.ds_lop_tc[kt]->ds_dk.phead; k != NULL; k = k->pnext)
			{
				if (k->data.trangthai_dangky == 1)
				{
					dem++;
				}
			}
			if (ds_lop.ds_lop_tc[kt]->svmax - dem <= 0)
			{
				cout << "\nHET SLOT DANG KY!";
				return;
			}
			DANG_KY_LTC dk;
			dk.masv = masv;
			dk.trangthai_dangky = 1;
			dk.diem = 0;
			NODE_DK* p = khoi_tao_node_dk(dk);
			them_sv_dk(ds_lop.ds_lop_tc[kt]->ds_dk, p);
			cout << "\nDANG KY THANH CONG";
		}
	} while (kt<0);
}


void nhap_diem_sv(DS_LOP_TC ds_lop, DS_SV ds_sv)
{
	LOP_TIN_CHI* p = new LOP_TIN_CHI;
	int thoat = 0;
	cout << "\nNhap nien khoa: ";
	string nienkhoa = "";
	xuLyNhapNienKhoa(nienkhoa, 16, thoat, 9);
	if (thoat == -1)
	{
		return;
	}
	p->nienkhoa = nienkhoa;

	cout << "\nNhap hoc ky: ";
	int hocky = 0;
	xuLyNhapHocKy(hocky, 13, thoat, 1);
	if (thoat == -1)
	{
		return;
	}
	p->hocky = hocky;

	cout << "\nNhap nhom: ";
	int nhom = 0;
	xuLyNhapSoNguyen(nhom, 11, thoat, 4);
	if (thoat == -1)
	{
		return;
	}
	p->nhom = nhom;

	cout << "\nNhap ma mon: ";
	string ma_mh = "";
	xuLyNhapMaSV(ma_mh, 13, thoat, 10);
	if (thoat == -1)
	{
		return;
	}
	p->ma_mh = ma_mh;
	int vt = kt_lop_cau_b(ds_lop, p->nienkhoa, p->hocky, p->nhom, p->ma_mh);

	if (vt < 0)
	{
		cout << "Lop tin chi khong ton tai!\n";
	}
	else
	{
		//Toa do
		int x = 45;
		int x_cach = 15;
		int y = 3;
		//------------
		gotoXY(x, 1);
		cout << "STT";
		gotoXY(x + x_cach, 1);
		cout << "MA SINH VIEN ";
		gotoXY(x + x_cach * 2, 1);
		cout << "HO ";
		gotoXY(x + x_cach * 3, 1);
		cout << "TEN ";
		gotoXY(x + x_cach * 4, 1);
		cout << "DIEM ";
		int j = 0;
		for (NODE_DK* k = ds_lop.ds_lop_tc[vt]->ds_dk.phead; k != NULL; k = k->pnext)
		{
			if (k->data.trangthai_dangky == 1)
			{
				int tk = kt_ma_sv_cau_h(ds_sv, k->data.masv);
				if (tk >= 0)
				{
					gotoXY(x, y + j); cout << j+1 << endl;
					gotoXY(x + x_cach * 1, y + j);cout << ds_sv.dssv[tk].ma_sv << endl;
					gotoXY(x+ x_cach * 2, y + j);cout << ds_sv.dssv[tk].ho  << endl;
					gotoXY(x+x_cach * 3, y + j);cout << ds_sv.dssv[tk].ten << endl;
					gotoXY(x+x_cach * 4, y + j); cout << k->data.diem << endl;
					j++;
				}
			}
		}
		gotoXY(0, 10);
		string masv="";
		cout << "Nhap ma sinh vien can nhap diem: ";
		if (thoat == -1)
		{
			return;
		}
		xuLyNhapMaSV(masv, 33, thoat, 10);
		for (NODE_DK * k = ds_lop.ds_lop_tc[vt]->ds_dk.phead; k != NULL; k = k->pnext)
		{
			if (k->data.trangthai_dangky == 1 && k->data.masv==masv)
			{
				int tk = kt_ma_sv_cau_h(ds_sv, k->data.masv);
				
				if (tk >= 0)
				{
					cout << "\nMa sinh vien: " << ds_sv.dssv[tk].ma_sv << endl;
					cout << "Ho: " << ds_sv.dssv[tk].ho << endl;
					cout << "Ten: " << ds_sv.dssv[tk].ten << endl;
					cout << "Diem hien tai: " << k->data.diem << endl;
					cout << "Nhap diem: ";
					//cin >> k->data.diem;			
					float diem = 0;
					xuLyNhapDiem(diem, 11, thoat, 5);
					diem=lam_tron_den_so_thap_phan(diem);
					k->data.diem=diem;
				}
			}
		}
	}
}

void in_bang_diem_1_loptc(DS_LOP_TC ds_lop, DS_SV ds_sv,DS_MON_HOC ds_mon)
{
	LOP_TIN_CHI* p = new LOP_TIN_CHI;
	int thoat = 0;
	cout << "\nNhap nien khoa: ";
	string nienkhoa = "";
	xuLyNhapNienKhoa(nienkhoa, 16, thoat, 9);
	if (thoat == -1)
	{
		return;
	}
	p->nienkhoa = nienkhoa;

	cout << "\nNhap hoc ky: ";
	int hocky = 0;
	xuLyNhapHocKy(hocky, 13, thoat, 1);
	if (thoat == -1)
	{
		return;
	}
	p->hocky = hocky;

	cout << "\nNhap nhom: ";
	int nhom = 0;
	xuLyNhapSoNguyen(nhom, 11, thoat, 4);
	if (thoat == -1)
	{
		return;
	}
	p->nhom = nhom;

	cout << "\nNhap ma mon: ";
	string ma_mh = "";
	xuLyNhapMaSV(ma_mh, 13, thoat, 10);
	if (thoat == -1)
	{
		return;
	}
	p->ma_mh = ma_mh;
	int vt = kt_lop_cau_b(ds_lop, p->nienkhoa, p->hocky, p->nhom, p->ma_mh);
	
	if (vt < 0)
	{
		cout << "Lop tin chi khong ton tai!\n";
	}
	else
	{
		//Toa do
		int x = 45;
		int x_cach = 15;
		int y = 12;
		int y_bangdiem = 4;
		//------------bang diem
		gotoXY(x + x_cach * 2, y_bangdiem);
		string tenmon = "";
		lay_ra_mon_hoc(ds_mon.t, p->ma_mh, tenmon);
		cout << "BANG DIEM MON HOC " << tenmon;
		gotoXY(x + x_cach * 2, y_bangdiem * 2);
		cout << "Nien khoa: " << p->nienkhoa;
		gotoXY(x + x_cach * 4, y_bangdiem * 2);
		cout << "Hoc ky: " << p->hocky;
		gotoXY(x + x_cach * 5, y_bangdiem * 2);
		cout << "Nhom: " << p->nhom;
		//----------- stt masv
		gotoXY(x, y);
		cout << "STT";
		gotoXY(x + x_cach, y);
		cout << "MA SINH VIEN ";
		gotoXY(x + x_cach * 3, y);
		cout << "HO ";
		gotoXY(x + x_cach * 5, y);
		cout << "TEN ";
		gotoXY(x + x_cach * 6, y);
		cout << "DIEM ";
		int j = 0;
		for (NODE_DK* k = ds_lop.ds_lop_tc[vt]->ds_dk.phead; k != NULL; k = k->pnext)
		{
			if (k->data.trangthai_dangky == 1)
			{
				int tk = kt_ma_sv_cau_h(ds_sv, k->data.masv);
				if (tk >= 0)
				{
					gotoXY(x, y + j+2); cout << j + 1 << endl;
					gotoXY(x + x_cach	 , y + j+2); cout << ds_sv.dssv[tk].ma_sv << endl;
					gotoXY(x + x_cach * 3, y + j+2); cout << ds_sv.dssv[tk].ho << endl;
					gotoXY(x + x_cach * 5, y + j+2); cout << ds_sv.dssv[tk].ten << endl;
					gotoXY(x + x_cach * 6, y + j+2); cout << k->data.diem << endl;
					j++;
				}
			}
		}
	}
}

void lay_ra_mon_hoc(TREE t,string mamh,string &tenmon)
{
	if (t != NULL)
	{
		if (mamh < t->data.ma_mh)
		{
			lay_ra_mon_hoc(t->pleft, mamh, tenmon);
		}
		else if (mamh > t->data.ma_mh)
		{
			lay_ra_mon_hoc(t->pright, mamh, tenmon);
		}
		else
		{
			tenmon=t->data.tenmh;
		}
	}
}

void kt_mon_co_trong_ds_mon(TREE t,string ma_mon,int& kt)
{
	if (t != NULL)
	{
		if (_strcmpi(ma_mon.c_str(), t->data.ma_mh.c_str()) < 0)
		{
			kt_mon_co_trong_ds_mon(t->pleft, ma_mon, kt);
		}
		else if (_strcmpi(ma_mon.c_str(), t->data.ma_mh.c_str()) > 0)
		{
			kt_mon_co_trong_ds_mon(t->pright, ma_mon, kt);
		}
		else if ((_strcmpi(ma_mon.c_str(), t->data.ma_mh.c_str()) == 0))
		{
			kt = 1;
		}
	}
}

void huy_sv_dk(DS_LOP_TC ds_lop, DS_SV ds_sv)
{
	LOP_TIN_CHI* p = new LOP_TIN_CHI;
	int thoat = 0;
	
	cout << "\nNhap nien khoa: ";
	string nienkhoa = "";
	xuLyNhapNienKhoa(nienkhoa, 16, thoat, 9);
	if (thoat == -1)
	{
		return;
	}
	p->nienkhoa = nienkhoa;
	//getline(cin, p->nienkhoa);

	cout << "\nNhap hoc ky: ";
	int hocky = 0;
	xuLyNhapHocKy(hocky, 13, thoat, 1);
	if (thoat == -1)
	{
		return;
	}
	p->hocky = hocky;
	//cin >> p->hocky;
	cout << "\nNhap nhom: ";
	int nhom = 0;
	xuLyNhapSoNguyen(nhom, 11, thoat, 4);
	if (thoat == -1)
	{
		return;
	}
	p->nhom = nhom;
	cout << "\nNhap ma mon hoc: ";
	string mamh = "";
	xuLyNhapMaLop(mamh, 17, thoat, 6);
	if (thoat == -1)
	{
		return;
	}
	p->ma_mh = mamh;
	int vt = kt_lop_cau_b(ds_lop, p->nienkhoa, p->hocky, p->nhom, p->ma_mh);

	if (vt < 0)
	{
		cout << "\nLop tin chi khong ton tai!\n";
	}
	else
	{
		string ma_sv = "";
		cout << "\nNhap ma sinh vien: ";
		xuLyNhapMaSV(ma_sv, 19, thoat, 10);
		if (ma_sv == "" || thoat == -1)
		{
			return;
		}
		for (NODE_DK* k = ds_lop.ds_lop_tc[vt]->ds_dk.phead; k != NULL; k = k->pnext)
		{
			if (k->data.trangthai_dangky == 1 && k->data.masv == ma_sv)
			{
				cout << "\nTrang thai dang ky: ";
				/*cin >> k->data.trangthai_dangky;*/
				int trangthai = 0;
				xuLyNhapNhapTrangThai(trangthai, 20, thoat, 1);
				if (thoat == -1)
				{
					return;
				}
				k->data.trangthai_dangky = trangthai;
			}
		}
	}
}
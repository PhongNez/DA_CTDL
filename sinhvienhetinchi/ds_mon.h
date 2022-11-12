#pragma once
#include"ds_loptc.h"

//Them mon hoc
//Khoi tao node mon hoc
//NODE_MON* khoi_tao_node_mon(MON_HOC mon);
void nhap_mon_hoc(DS_MON_HOC& ds_mh);
//void them_mon_hoc(TREE& t, NODE_MON* p);
string tao_ma_mh(TREE t);
bool kt_trung_ma_mon_hoc(TREE t, string mamh);
//=============================Xoa mon hoc=======================
void node_trai_nhat(TREE& x, TREE& y);
void xoa_mon_hoc(TREE& t, string mamh);
//=============================Xoa mon hoc=======================

//=========================Hieu chinh mon hoc=====================
void hieu_chinh_mon_hoc(TREE& t, string mamh);
//=========================Hieu chinh mon hoc====================

//======================In danh sach mon hoc=======================================
void hoan_vi_mon_hoc(MON_HOC* a, MON_HOC* b);
void chuyen_cay_sang_mang(TREE t, MON_HOC* ds_mon[], int& sl);
void sap_xep_ten_mon_hoc(MON_HOC* ds_mon[], int& sl);
void in_danh_sach_mon_hoc(MON_HOC* ds_mon[], int sl);
//======================In danh sach mon hoc=======================================


void menu_mon_hoc(DS_LOP_TC ds_lop, DS_SV dssv, DS_MON_HOC ds_mon)
{
	//setting
	
	//loadfile

	//menu
	bool kt_menu = true;
	while (kt_menu == true)
	{
		system("cls");
		cout << "1.Them mon hoc" << endl;
		cout << "2.In danh sach mon hoc" << endl;
		cout << "3.Xoa mon hoc" << endl;
		cout << "4.Hieu chinh mon hoc" << endl;
		cout << "0.Thoat" << endl;
		char c;
		while (true)
		{
			c = _getch();
			if(c==49)
			{
				if (ds_mon.sl == 10000)
				{
					cout << "\nSo luong mon hoc da day!";
				}
				else
				{
					nhap_mon_hoc(ds_mon);
				}
				system("pause");
				break;
			}
			else if(c==50) {
				MON_HOC* mon[10000];
				int sl = 0;
				chuyen_cay_sang_mang(ds_mon.t, mon, sl);
				sap_xep_ten_mon_hoc(mon, sl);
				in_danh_sach_mon_hoc(mon, sl);
				system("pause");
				break;
			}
			else if(c==51)
			{
				int thoat = 0;
				string mamh = "";
				cout << "Nhap ma mon hoc can xoa: ";
	
				//getline(cin, mamh);
				xuLyNhapMaLop(mamh, 25, thoat, 6);
				if (thoat == -1)
				{
					break;
				}
				chuan_hoa(mamh);

				cout << "\n\nBan co muon xoa mon hoc nay?\n\nENTER: Dong y xoa  ESC:Thoat\n";
				xuLyDongYHuy(thoat);
				if (thoat == -1)
				{
					break;
				}
				xoa_mon_hoc(ds_mon.t, mamh);
				system("pause");
				break;
			}
			else if(c==52)
			{
				int thoat = 0;
				string mamh = "";
				cout << "Nhap ma mon hoc can hieu chinh: ";
				//getline(cin, mamh);
				xuLyNhapMaLop(mamh, 32, thoat, 5);
				if (thoat == -1)
				{
					break;
				}
				chuan_hoa(mamh);
				hieu_chinh_mon_hoc(ds_mon.t, mamh);
				system("pause");
				break;
			}
			else if(c==48) {
				kt_menu = false;
				break;
			}
		}
		
	}
}

//Them mon hoc
NODE_MON* khoi_tao_node_mon(MON_HOC mon)
{
	NODE_MON* p = new NODE_MON;
	p->data = mon;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}

void nhap_mon_hoc(DS_MON_HOC& ds_mh)
{
	//nhap
	MON_HOC mon;
	// thoat
	int thoat = 0;
	mon.ma_mh = tao_ma_mh(ds_mh.t);
	cout << "Ma mon hoc: " << mon.ma_mh << endl;
	cout << "Nhap ten mon hoc: ";
	string tenmh = "";
	xuLyNhapHo(tenmh,18,thoat,50);
	if (thoat == -1)
	{
		return;
	}
	mon.tenmh = tenmh;
	//getline(cin, mon.tenmh);
	cout << "\nNhap so tin chi ly thuyet: ";
	int stclt = 0;
	xuLyNhapSoNguyen(stclt, 27, thoat,3);
	if (thoat == -1)
	{
		return;
	}
	mon.stclt = stclt;
	//cin >> mon.stclt;
	cout << "\nNhap so tin chi thuc hanh: ";
	int stcth = 0;
	xuLyNhapSoNguyen(stcth, 27, thoat,3);
	if (thoat == -1)
	{
		return;
	}
	mon.stcth = stcth;
	//cin >> mon.stcth;

	//chuan hoa
	chuan_hoa_ten(mon.tenmh);
	NODE_MON* p = khoi_tao_node_mon(mon);
	
	//them
	them_mon_hoc(ds_mh.t, p);
	ds_mh.sl++;
}

//Tao ma mon hoc random
string tao_ma_mh(TREE t)
{
	string mamh = "MH0000";
	do
	{
		for (int i = 2; i < mamh.length(); i++)
		{
			mamh[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung_ma_mon_hoc(t, mamh) == true);
	return mamh;
}

//Kiem tra ma mon hoc co trung
bool kt_trung_ma_mon_hoc(TREE t, string mamh)
{
	if (t == NULL)
	{
		return false;
	}
	else
	{
		if (mamh < t->data.ma_mh)
		{
			kt_trung_ma_mon_hoc(t->pleft, mamh);
		}
		else if (mamh > t->data.ma_mh)
		{
			kt_trung_ma_mon_hoc(t->pright, mamh);
		}
		else
		{
			return true;
		}
	}
}


void them_mon_hoc(TREE& t, NODE_MON* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->data.ma_mh < t->data.ma_mh)
		{
			them_mon_hoc(t->pleft, p);
		}
		else if (p->data.ma_mh > t->data.ma_mh)
		{
			them_mon_hoc(t->pright, p);
		}
	}
}

//Xoa mon hoc 
void node_trai_nhat(TREE& x, TREE& y)
{
	if (y->pleft != NULL)
	{
		node_trai_nhat(x, y->pleft);
	}
	else
	{
		x->data.ma_mh = y->data.ma_mh;
		x->data.tenmh = y->data.tenmh;
		x->data.stclt = y->data.stclt;
		x->data.stcth = y->data.stcth;
		x = y;
		y = y->pright;
	}
}

void xoa_mon_hoc(TREE& t, string mamh)
{
	if (t == NULL)
	{
		cout << "\n\nMa mon hoc khong ton tai!";
		return;
	}
	else
	{
		if (mamh < t->data.ma_mh)
		{
			xoa_mon_hoc(t->pleft, mamh);
		}
		else if (mamh > t->data.ma_mh)
		{
			xoa_mon_hoc(t->pright, mamh);
		}
		else
		{
			NODE_MON* x = t;
			if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if (t->pright == NULL)
			{
				t = t->pleft;
			}
			else
			{
				node_trai_nhat(x, t->pright);
			}
			delete x;
			cout << "\n\nXOA THANH CONG!";
		}
	}
}

//In danh sach mon hoc
//Sap xep theo ten mon hoc
void chuyen_cay_sang_mang(TREE t, MON_HOC* ds_mon[], int& sl)
{
	if (t != NULL)
	{
		ds_mon[sl] = new MON_HOC;
		ds_mon[sl]->ma_mh = t->data.ma_mh;
		ds_mon[sl]->tenmh = t->data.tenmh;
		ds_mon[sl]->stclt = t->data.stclt;
		ds_mon[sl]->stcth = t->data.stcth;
		sl++;
		chuyen_cay_sang_mang(t->pleft, ds_mon, sl);
		chuyen_cay_sang_mang(t->pright, ds_mon, sl);
	}
}

void hoan_vi_mon_hoc(MON_HOC* a, MON_HOC* b)
{
	MON_HOC* tam = new MON_HOC;
	tam->ma_mh = a->ma_mh;
	tam->stclt = a->stclt;
	tam->stcth = a->stcth;
	tam->tenmh = a->tenmh;
	//
	a->ma_mh = b->ma_mh;
	a->stclt = b->stclt;
	a->stcth = b->stcth;
	a->tenmh = b->tenmh;
	//
	b->ma_mh = tam->ma_mh;
	b->stclt = tam->stclt;
	b->stcth = tam->stcth;
	b->tenmh = tam->tenmh;
	delete tam;
}

void sap_xep_ten_mon_hoc(MON_HOC* ds_mon[], int& sl)
{
	for (int i = 0; i < sl - 1; i++)
	{
		for (int j = i + 1; j < sl; j++)
		{
			if (_strcmpi(ds_mon[i]->tenmh.c_str(), ds_mon[j]->tenmh.c_str()) > 0)
			{
				hoan_vi_mon_hoc(ds_mon[i], ds_mon[j]);
			}
		}
	}
}

void in_danh_sach_mon_hoc(MON_HOC* ds_mon[], int sl)
{
	for (int i = 0; i < sl; i++)
	{
		cout << "\n\t\tMON HOC: " << ds_mon[i]->tenmh << endl;
		cout << "Ma mon hoc: " << ds_mon[i]->ma_mh << endl;
		cout << "Ten mon hoc: " << ds_mon[i]->tenmh << endl;
		cout << "So tin chi ly thuyet: " << ds_mon[i]->stclt << endl;
		cout << "So tin chi thuc hanh: " << ds_mon[i]->stcth << endl;
	}
}

//Hieu chinh mon hoc
void hieu_chinh_mon_hoc(TREE& t, string mamh)
{
	if (t == NULL)
	{
		cout << "\nMa mon hoc khong ton tai!\n" << endl;
		return;
	}
	else
	{
		if (mamh< t->data.ma_mh)
		{
			hieu_chinh_mon_hoc(t->pleft, mamh);
		}
		else if (mamh > t->data.ma_mh)
		{
			hieu_chinh_mon_hoc(t->pright, mamh);
		}
		else
		{
			
			while (true)
			{
				system("cls");
				int thoat = 0;
				cout << "\n\t\tMa mon hoc dang chinh: " << t->data.ma_mh << endl;
				cout << "Ten mon hoc: " << t->data.tenmh << endl;
				cout << "So tin chi ly thuyet: " << t->data.stclt << endl;
				cout << "So tin chi thuc hanh: " << t->data.stcth << endl;
				cout << "\n\t\tMoi nhap lua chon";
				cout << "\n1 Sua ten mon hoc " << endl;
				cout << "2 Sua so tin chi ly thuyet " << endl;
				cout << "3 Sua so tin chi thuc hanh " << endl;
				char c;
				while (true)
				{
					c = _getch();
					if (c == 49)//1
					{
						cout << "Nhap ten mon hoc: ";
						string tenmh = "";
						xuLyNhapHo(tenmh, 18, thoat, 50);
						if (thoat == -1)
						{
							return;
						}
						t->data.tenmh = tenmh;
						chuan_hoa_ten(t->data.tenmh);
					}
					else if (c == 50)
					{
						cout << "\nNhap so tin chi ly thuyet: ";

						int stclt = 0;
						xuLyNhapSoNguyen(stclt, 27, thoat, 3);
						if (thoat == -1)
						{
							return;
						}
						t->data.stclt = stclt;
					}
					else if (c == 51)
					{
						cout << "\nNhap so tin chi thuc hanh: ";
						int stcth = 0;
						xuLyNhapSoNguyen(stcth, 27, thoat, 3);
						if (thoat == -1)
						{
							return;
						}
						t->data.stcth = stcth;
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
}


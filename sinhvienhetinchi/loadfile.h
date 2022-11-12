#pragma once
#include"ctdl.h"

int kt_trung_ma_lop(DS_LOP_TC ds_lop, int malop);
//
////======================Khoi tao node mon hoc============================
NODE_MON* khoi_tao_node_mon(MON_HOC mon);
void them_mon_hoc(TREE& t, NODE_MON* p);
////======================Khoi tao node mon hoc============================
NODE_DK* khoi_tao_node_dk(DANG_KY_LTC dk);
void them_sv_dk(DS_DANG_KY& ds_dk, NODE_DK* sv_dk);

//loadfile lop tin chi
void loadfile(DS_LOP_TC& ds_lop)
{
	ifstream filein;
	filein.open("loptinchi.txt");
	while (filein.eof() != true)
	{
		LOP_TIN_CHI* lop = new LOP_TIN_CHI;
		filein >> lop->ma_loptc;
		filein.ignore();
		getline(filein, lop->ma_mh, ',');
		getline(filein, lop->nienkhoa, ',');
		filein >> lop->hocky;
		filein.ignore();
		filein >> lop->nhom;
		filein.ignore();
		filein >> lop->svmin;
		filein.ignore();
		filein >> lop->svmax;
		filein.ignore();
		filein >> lop->trangthai_lop;
		filein.ignore();
		//them
		ds_lop.ds_lop_tc[ds_lop.sl] = lop;
		ds_lop.sl++;
	}
	filein.close();
}
//
//loadfile sinh vien
void loadfile_sv(DS_SV& dssv)
{
	ifstream filein;
	filein.open("danhsachsv.txt");
	while (filein.eof() != true)
	{
		SINHVIEN sv;
		getline(filein, sv.malop, ',');
		getline(filein, sv.ma_sv, ',');
		getline(filein, sv.ho, ',');
		getline(filein, sv.ten, ',');
		getline(filein, sv.phai, ',');
		getline(filein, sv.sodt);
		//filein.ignore();
		//Them
		dssv.dssv[dssv.sl] = sv;
		dssv.sl++;
	}
	filein.close();
}
//
void loadfile_mon_hoc(DS_MON_HOC& ds_mh)
{
	ifstream filein;
	filein.open("danhsachmonhoc.txt");
	while (filein.eof() != true)
	{
		MON_HOC mon;
		getline(filein, mon.ma_mh, ',');
		getline(filein, mon.tenmh, ',');
		filein >> mon.stclt;
		filein.ignore();
		filein >> mon.stcth;
		NODE_MON* p = khoi_tao_node_mon(mon);
		filein.ignore();

		//them
		them_mon_hoc(ds_mh.t, p);
		ds_mh.sl++;
	}
	filein.close();
}

void loadfile_sv_dangky(DS_LOP_TC ds_lop)
{
	ifstream filein;
	filein.open("danhsachdangky.txt");
	while (filein.eof() != true)
	{
		int x, sl;
		filein >> x;
		filein.ignore();
		int vt = kt_trung_ma_lop(ds_lop, x);
		filein >> sl;
		filein.ignore();
		for (int i = 0; i < sl; i++)
		{
			DANG_KY_LTC dk;
			getline(filein, dk.masv, ',');
			filein >> dk.trangthai_dangky;
			filein.ignore();
			filein >> dk.diem;
			filein.ignore();
			//Them
			NODE_DK* p = khoi_tao_node_dk(dk);
			them_sv_dk(ds_lop.ds_lop_tc[vt]->ds_dk, p);
		}
	}
	filein.close();
}
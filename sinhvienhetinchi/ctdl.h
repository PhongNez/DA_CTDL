#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#define MAX_LTC 10000
#define MAX_SV 5000
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define DAUCACH 32
using namespace std;

//-------------Danh sach mon hoc
struct mon_hoc {
	string ma_mh;
	string tenmh;
	int stclt;
	int stcth;
};
typedef mon_hoc MON_HOC;

struct node_mon_hoc {
	MON_HOC data;
	node_mon_hoc* pleft;
	node_mon_hoc* pright;
};
typedef node_mon_hoc NODE_MON;
typedef node_mon_hoc* TREE;

struct danh_sach_mh {
	TREE t = NULL;//khoi tao danh sach
	int sl = 0;
};
typedef danh_sach_mh DS_MON_HOC;

//---------Danh sach sinh vien
struct sinh_vien {
	string ma_sv;
	string ho;
	string ten;
	string phai;
	string sodt;
	string malop;
};
typedef  sinh_vien SINHVIEN;

struct ds_sinh_vien {
	SINHVIEN dssv[MAX_SV];//5000 sv
	int sl = 0;
};
typedef ds_sinh_vien DS_SV;

//---------Danh sach dang ky lop tin chi
struct dang_ky_lop_tc {
	string masv;
	bool trangthai_dangky;//0:huy    1:con
	float diem;
};
typedef dang_ky_lop_tc DANG_KY_LTC;

struct node_dk {
	DANG_KY_LTC data;
	struct node_dk* pnext;
};
typedef node_dk NODE_DK;

struct danh_sach_dang_ky {
	NODE_DK* phead = NULL;
	NODE_DK* ptail = NULL;
};
typedef danh_sach_dang_ky DS_DANG_KY;

//-----------Danh sach lop tin chi
struct lop_tin_chi {
	int ma_loptc;//tu dong tang
	string ma_mh;
	string nienkhoa;
	int hocky;
	int nhom;
	int svmin;
	int svmax;
	bool trangthai_lop;
	//--con tro dssv dang ky lop tin chi
	DS_DANG_KY ds_dk;
};
typedef lop_tin_chi LOP_TIN_CHI;

struct danh_sach_lop_tin_chi {
	LOP_TIN_CHI* ds_lop_tc[MAX_LTC] = { NULL };//10000
	int sl = 0;
};
typedef danh_sach_lop_tin_chi DS_LOP_TC;

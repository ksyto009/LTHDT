#pragma once
#include <iostream>

#include <fstream>
#include "Menu.h"
#include "MatHang.h"
#include "LoaiHang.h"
#include "HoaDonBan.h"
#include "HoaDonNhap.h"
#include "NgayThangNam.h"
using namespace std;
class CuaHang
{
private:
	static CuaHang* instance;
	CuaHang();

	vector<MatHang> dsMH;
	vector<LoaiHang> dsLH;
	vector<HoaDonBan> dsHDB;
	vector<HoaDonNhap> dsHDN;

	vector<string> tieuDe;
	vector<int> doRongCot;
public:
	static CuaHang* getInstance();

	void docFile();
	void ghiFile();

	int menuChinh();
	int menuMatHang();
	int menuLoaiHang();
	int menuHoaDonBan();
	int menuHoaDonNhap();

	void xuatKeNgang();
	void xuatTieuDe();
	void xuatDSMatHang();
	void xuatDSLoaiHang();
	void xuatDSHDB();
	void xuatDSHDN();
	
	void themMatHang();
	void themLoaiHang();
	void themHoaDonBan();
	void themHoaDonNhap();

	void xoaMatHang(const string& id);
	void xoaLoaiHang(const string& id);
	void xoaHDB(const string& id);
	void xoaHDN(const string& id);

	void suaMatHang(const string& id);
	void suaLoaiHang(const string& id);
	void suaHDB(const string& id);
	void suaHDN(const string& id);

	void timKiemMatHang(const string& keyword);
	void timKiemLoaiHang(const string& keyword);
	void timKiemHoaDonBan(const string& keyword);
	void timKiemHoaDonNhap(const string& keyword);

	void suaMaHangTrongHDB(const string& maHangCu, const string& maHangMoi);
	void suaMaHangTrongHDN(const string& maHangCu, const string& maHangMoi);
	void suaTenHangTrongHDB(const string& maHang, const string& tenHangMoi);
	void suaTenHangTrongHDN(const string& maHang, const string& tenHangMoi);
	
	void suaLoaiHangTrongMatHang(const string& loaiHangCu, const string& loaiHangMoi);

	ChiTietHoaDon themChiTietHoaDonBan();
	ChiTietHoaDon themChiTietHoaDonNhap();

	bool tonTaiLoaiHang(const string& id);
	bool tonTaiMatHang(const string& id);
	bool tonTaiMatHangTrongHDB(const string& id);
	bool tonTaiMatHangTrongHDN(const string& id);

	MatHang* timKiemMatHangTheoID(const string& id);
	LoaiHang* timKiemLoaiHangTheoID(const string& id);
	HoaDonBan* timKiemHoaDonBanTheoID(const string& id);
	HoaDonNhap* timKiemHoaDonNhapTheoID(const string& id);

	void thongKeHangConLai();
	void thongKeHangHetHan();

	void docFileMH();
	void docFileLH();
	void docFileHDB();
	void docFileHDN();

	void ghiFileMH();
	void ghiFileLH();
	void ghiFileHDB();
	void ghiFileHDN();
	~CuaHang();
};


#pragma once
#include "ChiTietHoaDon.h"
using namespace std;

class HoaDon
{
private:
	string maHD;
	string ngay;
	vector<ChiTietHoaDon> chiTiet;
public:
	HoaDon();
	HoaDon(string maHD, string ngay, vector<ChiTietHoaDon> chiTiet);

	string getMaHD();
	string getNgay();
	vector<ChiTietHoaDon>& getChiTiet();

	void setMaHD(string maHD);
	void setNgay(string ngay);

	void xoaCTHD(int i);

	void nhap();
	void xuat();
};


#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class ChiTietHoaDon
{
protected:
	string maHang;
	string tenHang;
	int soLuong;
	double gia;
public:
	ChiTietHoaDon();
	ChiTietHoaDon(string maHang, string tenHang, int soLuong, double gia);

	void setMaHang(string maHang);
	void setTenHang(string tenHang);
	void setSoLuong(int soLuong);
	void setGia(double gia);

	string getMaHang();
	string getTenHang();
	int getSoLuong();
	double getGia();

	virtual void nhap();
	void xuat();
};


#pragma once
#include "HoaDon.h"
class HoaDonBan : public HoaDon
{
private:
	string tenKhachHang;
public:
	HoaDonBan();
	HoaDonBan(string maHD, string ngayBan, string tenKhachHang, vector<ChiTietHoaDon> chiTiet);

	string getTenKhachHang();

	void setTenKhachHang(string tenCongTyNhap);

	void xuat();
};


#pragma once
#include "HoaDon.h"
class HoaDonNhap : public HoaDon
{
private:
	string tenCongTyNhap;
public:
	HoaDonNhap();
	HoaDonNhap(string maHD, string ngayBan,string tenCongTyNhapHang, vector<ChiTietHoaDon> chiTiet);

	string getTenCongTyNhap();

	void setTenCongTyNhap(string tenCongTyNhap);

	void xuat();
};


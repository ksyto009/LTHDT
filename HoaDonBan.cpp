#include "HoaDonBan.h"
HoaDonBan::HoaDonBan()
{

}

HoaDonBan::HoaDonBan(string maHD, string ngayBan, string tenKhachHang, vector<ChiTietHoaDon> chiTiet) :HoaDon(maHD, ngayBan, chiTiet)
{
	this->tenKhachHang = tenKhachHang;
}

string HoaDonBan::getTenKhachHang()
{
	return tenKhachHang;
}

void HoaDonBan::setTenKhachHang(string tenKhachHang)
{
	this->tenKhachHang = tenKhachHang;
}

void HoaDonBan::xuat()
{
	vector<string> tieuDe = { getMaHD(),getNgay(), tenKhachHang };
	vector<int> doRongCot = { 10,10,30 };

	for (int i = 0; i < tieuDe.size(); i++)
	{
		int space = max(0, (int)(doRongCot[i] - tieuDe[i].length()));
		cout << "|" << tieuDe[i] << string(space, ' ');

		//cout << "|" << tieuDe[i] << string(doRongCot[i] - tieuDe[i].length(), ' ');
	}

	for (int i = 0; i < getChiTiet().size(); i++)
	{
		if (i != 0)
		{
			cout << "|" << string(10, ' ');
			cout << "|" << string(10, ' ');
			cout << "|" << string(30, ' ');
		}
		getChiTiet()[i].xuat();
	}

}
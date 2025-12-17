#include "HoaDonNhap.h"
HoaDonNhap::HoaDonNhap()
{

}

HoaDonNhap::HoaDonNhap(string maHD, string ngayBan, string tenCongTyNhap, vector<ChiTietHoaDon> chiTiet):HoaDon(maHD,ngayBan,chiTiet)
{
	this->tenCongTyNhap = tenCongTyNhap;
}

string HoaDonNhap::getTenCongTyNhap()
{
	return tenCongTyNhap;
}

void HoaDonNhap::setTenCongTyNhap(string tenCongTyNhap)
{
	this->tenCongTyNhap = tenCongTyNhap;
}

void HoaDonNhap::xuat()
{
	vector<string> tieuDe = { getMaHD(),getNgay(), tenCongTyNhap};
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
#include "HoaDon.h"

HoaDon::HoaDon()
{

}

HoaDon::HoaDon(string maHD, string ngay, vector<ChiTietHoaDon> chiTiet)
{
	this->maHD = maHD;
	this->ngay = ngay;
	this->chiTiet = chiTiet;
}

string HoaDon::getMaHD()
{
	return maHD;
}

string HoaDon::getNgay()
{
	return ngay;
}

vector<ChiTietHoaDon>& HoaDon::getChiTiet()
{
	return chiTiet;
}

void HoaDon::setMaHD(string maHD)
{
	this->maHD = maHD;
}
void HoaDon::setNgay(string ngay)
{
	this->ngay = ngay;
}

void HoaDon::xoaCTHD(int i)
{
	chiTiet.erase(chiTiet.begin() + i);
}

void HoaDon::nhap()
{

}

void HoaDon::xuat()
{
	vector<string> tieuDe = { maHD,ngay };
	vector<int> doRongCot = { 10,10 };

	for (int i = 0; i < tieuDe.size(); i++)
	{
		int space = max(0, (int)(doRongCot[i] - tieuDe[i].length()));
		cout << "|" << tieuDe[i] << string(space, ' ');

		//cout << "|" << tieuDe[i] << string(doRongCot[i] - tieuDe[i].length(), ' ');
	}

	for (int i = 0; i < chiTiet.size(); i++)
	{
		if (i != 0)
		{
			cout << "|" << string(10, ' ');
			cout << "|" << string(10, ' ');
		}
		chiTiet[i].xuat();
	}

}
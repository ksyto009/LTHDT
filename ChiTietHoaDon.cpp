#include "ChiTietHoaDon.h"


ChiTietHoaDon::ChiTietHoaDon()
{

}

ChiTietHoaDon::ChiTietHoaDon(string maHang, string tenHang, int soLuong, double gia)
{
	this->maHang = maHang;
	this->tenHang = tenHang;
	this->soLuong = soLuong;
	this->gia = gia;
}


void ChiTietHoaDon::setMaHang(string maHang)
{
	this->maHang = maHang;
}

void ChiTietHoaDon::setTenHang(string tenHang)
{
	this->tenHang = tenHang;
}

void ChiTietHoaDon::setSoLuong(int soLuong)
{
	this->soLuong = soLuong;
}

void ChiTietHoaDon::setGia(double gia)
{
	this->gia = gia;
}

string ChiTietHoaDon::getMaHang()
{
	return maHang;
}

string ChiTietHoaDon::getTenHang()
{
	return tenHang;
}

int ChiTietHoaDon::getSoLuong()
{
	return soLuong;
}

double ChiTietHoaDon::getGia()
{
	return gia;
}

void ChiTietHoaDon::nhap()
{

}

void ChiTietHoaDon::xuat()
{
	vector<string> tieuDe = { maHang,tenHang,to_string(soLuong),to_string(gia) };
	vector<int> doRongCot = { 10,30,10,20 };

	for (int i = 0; i < tieuDe.size(); i++)
	{
		int space = max(0, (int)(doRongCot[i] - tieuDe[i].length()));
		cout << "|" << tieuDe[i] << string(space, ' ');

		//cout << "|" << tieuDe[i] << string(doRongCot[i] - tieuDe[i].length(), ' ');
	}
	cout << "|\n";
}

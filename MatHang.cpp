#include "MatHang.h"
#include "MatHang.h"

MatHang::MatHang()
{

}

MatHang::MatHang(string maHang, string tenHang, string hanDung, int soLuong, double donGia, string congTySX, int namSX, string loaiHang)
{
	this->maHang = maHang;
	this->tenHang = tenHang;
	this->hanDung = hanDung;
	this->soLuong = soLuong;
	this->donGia = donGia;
	this->congTySX = congTySX;
	this->namSX = namSX;
	this->loaiHang = loaiHang;
}

string MatHang::getMaHang()
{
	return maHang;
}

string MatHang::getTenHang()
{
	return tenHang;
}

string MatHang::getHanDung()
{
	return hanDung;
}

int MatHang::getSoLuong()
{
	return soLuong;
}

double MatHang::getDonGia()
{
	return donGia;
}

string MatHang::getCongTySX()
{
	return congTySX;
}

int MatHang::getNamSX()
{
	return namSX;
}

string MatHang::getLoaiHang()
{
	return loaiHang;
}

void MatHang::setMaHang(string maHang)
{
	this->maHang = maHang;
}

void MatHang::setTenHang(string tenHang)
{
	this->tenHang = tenHang;
}

void MatHang::setHanDung(string hanDung)
{
	this->hanDung = hanDung;
}

void MatHang::setSoLuong(int soLuong)
{
	this->soLuong = soLuong;
}

void MatHang::setDonGia(double donGia)
{
	this->donGia = donGia;
}

void MatHang::setCongTySX(string congTySX)
{
	this->congTySX = congTySX;
}

void MatHang::setNamSX(int namSX)
{
	this->namSX = namSX;
}

void MatHang::setLoaiHang(string loaiHang)
{
	this->loaiHang = loaiHang;
}

void MatHang::nhap() {
	//cout << "Nhap ma hang: "; getline(cin, maHang);
	//cout << "Nhap ten hang: "; getline(cin, tenHang);
	//cout << "Nhap han dung (dd/mm/yyyy): "; getline(cin, hanDung);
	//cout << "Nhap so luong: "; cin >> soLuong; cin.ignore();
	//cout << "Nhap don gia: "; cin >> donGia; cin.ignore();
	//cout << "Nhap cong ty san xuat: "; getline(cin, congTySX);
	//cout << "Nhap nam san xuat: "; cin >> namSX; cin.ignore();
	//cout << "Nhap loai hang: "; getline(cin, loaiHang);
}

void MatHang::xuat() {
	vector<string> tieuDe = { maHang, tenHang, hanDung,to_string(soLuong),to_string(donGia), congTySX, to_string(namSX), loaiHang };
	vector<int> doRongCot = { 10,30,10,10,20,30,10,30 };

	for (int i = 0; i < tieuDe.size(); i++)
	{
		int space = max(0, (int)(doRongCot[i] - tieuDe[i].length()));
		cout << "|" << tieuDe[i] << string(space, ' ');

		//cout << "|" << tieuDe[i] << string(doRongCot[i] - tieuDe[i].length(), ' ');
	}
	cout << "|\n";
}
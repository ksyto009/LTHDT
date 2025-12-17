#include "LoaiHang.h"
LoaiHang::LoaiHang()
{

}

LoaiHang::LoaiHang(string maLoai, string tenLoai, string moTa)
{
	this->maLoai = maLoai;
	this->tenLoai = tenLoai;
	this->moTa = moTa;
}

string LoaiHang::getMaLoai()
{
	return maLoai;
}

string LoaiHang::getTenLoai()
{
	return tenLoai;
}
string LoaiHang::getMoTa()
{
	return moTa;
}
void LoaiHang::setMaLoai(string maLoai)
{
	this->maLoai = maLoai;
}

void LoaiHang::setTenLoai(string tenLoai)
{
	this->tenLoai = tenLoai;
}

void LoaiHang::setMoTa(string moTa)
{
	this->moTa = moTa;
}

void LoaiHang::nhap() {
	/*cout << "Nhap ma loai: "; getline(cin, maLoai);
	//cout << "Nhap ten loai: "; getline(cin, tenLoai);
	//cout << "Nhap mo ta: "; getline(cin, moTa);*/

}

void LoaiHang::xuat() {
	vector<string> tieuDe = { maLoai,tenLoai,moTa };
	vector<int> doRongCot = { 10,30,100 };

	for (int i = 0; i < tieuDe.size(); i++)
	{
		int space = max(0, (int)(doRongCot[i] - tieuDe[i].length()));
		cout << "|" << tieuDe[i] << string(space, ' ');
	}
	cout << "|\n";
}
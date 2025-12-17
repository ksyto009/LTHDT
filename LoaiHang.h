#pragma once
#include<vector>
#include<string>
#include <iostream>

using namespace std;

class LoaiHang
{
private:
	string maLoai;
	string tenLoai;
	string moTa;
public:
	LoaiHang();
	LoaiHang(string maLoai, string tenLoai, string moTa);

	string getMaLoai();
	string getTenLoai();
	string getMoTa();

	void setMaLoai(string maLoai);
	void setTenLoai(string tenLoai);
	void setMoTa(string moTa);

	void nhap();
	void xuat();
};


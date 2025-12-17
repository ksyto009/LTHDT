#pragma once
#include <string>
#include <sstream>

using namespace std;

class NgayThangNam
{
private:
	int ngay, thang, nam;
	char sep1, sep2;
	bool namNhuan();
	int soNgayTrongThang();
	int demSoNgay();

public:
	NgayThangNam(string ngayThangNam);
	bool ngayHopLe();
	string xuatChuoi();

	int khoangCachNgay(NgayThangNam& ngayThangNam);
	//static NgayThangNam NhapTuChuoi(string ngayThangNam);
};


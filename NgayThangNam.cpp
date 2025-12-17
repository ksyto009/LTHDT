#include "NgayThangNam.h"

NgayThangNam::NgayThangNam(string ngayThangNam)
{
    stringstream ss(ngayThangNam);
    ss >> ngay >> sep1 >> thang >> sep2 >> nam;
}

bool NgayThangNam::namNhuan()
{
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}


bool NgayThangNam::ngayHopLe()
{
    if (sep1 != '/' || sep2 != '/') return false;
    if (nam < 1900 || nam > 3000) return false;
    if (thang < 1 || thang > 12) return false;
    if (ngay < 1) return false;

    if (thang == 2) {
        if (namNhuan()) {
            return ngay <= 29;
        }
        else {
            return ngay <= 28;
        }
    }
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return ngay <= 30;
    }
    else {
        return ngay <= 31;
    }
}

int NgayThangNam::soNgayTrongThang()
{
    if (thang == 2) {
        if (namNhuan()) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int NgayThangNam::demSoNgay()
{
    int ngay = 0;
    for (int y = 1900; y < nam; y++)
    {
        ngay = ngay + namNhuan() ? 366 : 365;
    }

    for (int m = 1; m < thang; m++)
    {
        ngay = ngay + soNgayTrongThang();
    }

    ngay = ngay + this->ngay;
    return ngay;
}

string NgayThangNam::xuatChuoi()
{
    return (ngay < 10 ? "0" : "") + to_string(ngay) + "/" +
        (thang < 10 ? "0" : "") + to_string(thang) + "/" +
        to_string(nam);
}

int NgayThangNam::khoangCachNgay(NgayThangNam& ngayThangNam)
{
    return this->demSoNgay() - ngayThangNam.demSoNgay();
}

#pragma once
#include<vector>
#include<string>
#include <iostream>

using namespace std;

class MatHang
{
private:
    string maHang;
    string tenHang;
    string hanDung;
    int soLuong;
    double donGia;
    string congTySX;
    int namSX;
    string loaiHang;
public:
    MatHang();
    MatHang(string maHang, string tenHang, string hanDung, int soLuong, double donGia, string congTySX, int namSX, string loaiHang);

    string getMaHang();
    string getTenHang();
    string getHanDung();
    int getSoLuong();
    double getDonGia();
    string getCongTySX();
    int getNamSX();
    string getLoaiHang();

    void setMaHang(string maHang);
    void setTenHang(string tenHang);
    void setHanDung(string hanDung);
    void setSoLuong(int soLuong);
    void setDonGia(double donGia);
    void setCongTySX(string congTySX);
    void setNamSX(int namSX);
    void setLoaiHang(string loaiHang);

    void nhap();
    void xuat();
};


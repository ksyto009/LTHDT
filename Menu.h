#pragma once
#include<vector>
#include<string>

using namespace std;

class Menu
{
private:
	string tieuDe;
	vector<string> chucNang;
public:
	Menu(string td = "Menu");
	void renderMenu(bool thoat = true);
	void themChucNang(const string cn);
	int nhapLuaChon();
	int XuLyThoat();
};


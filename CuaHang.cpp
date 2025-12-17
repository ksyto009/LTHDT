#include "CuaHang.h"

CuaHang* CuaHang::instance = NULL;

CuaHang::CuaHang()
{
	docFile();
}

CuaHang* CuaHang::getInstance()
{
	if (instance == NULL)
	{
		instance = new CuaHang();
	}
	return instance;
}

void CuaHang::docFile()
{
	docFileMH();
	docFileLH();
	docFileHDB();
	docFileHDN();
	system("pause");
}

void CuaHang::ghiFile()
{
	ghiFileMH();
	ghiFileLH();
	ghiFileHDB();
	ghiFileHDN();
	system("pause");
}

int CuaHang::menuChinh()
{
	Menu menu("MENU CHINH");
	menu.themChucNang("Quan ly mat hang");
	menu.themChucNang("Quan ly loai hang");
	menu.themChucNang("Quan ly hoa don ban");
	menu.themChucNang("Quan ly hoa don nhap");
	menu.themChucNang("Thong ke hang con lai");
	menu.themChucNang("Thong ke hang het han");
	menu.renderMenu();
	int key = menu.nhapLuaChon();

	if (key == 1)
	{
		int flag = 1;
		do
		{
			flag = menuMatHang();
			if (flag == -1) return 0;
		} while (flag == 1);
	}
	else if (key == 2)
	{
		int flag = 1;
		do
		{
			flag = menuLoaiHang();
			if (flag == -1) return 0;
		} while (flag == 1);
	}
	else if (key == 3)
	{
		int flag = 1;
		do
		{
			flag = menuHoaDonBan();
			if (flag == -1) return 0;
		} while (flag == 1);
	}
	else if (key == 4)
	{
		int flag = 1;
		do
		{
			flag = menuHoaDonNhap();
			if (flag == -1) return 0;
		} while (flag == 1);
	}
	else if (key == 5)
	{
		thongKeHangConLai();
		system("pause");
	}
	else if (key == 6)
	{
		thongKeHangHetHan();
		system("pause");
	}
	else if (key == 0)
	{
		int flag = menu.XuLyThoat();
		if (flag == 0) return 0;
		return 1;
	}
	else
	{
		cout << "Lua chon khong hop le!\n";
		system("pause");
	}

	return 1;
}

int CuaHang::menuMatHang()
{
	Menu menu("MENU MAT HANG");
	menu.themChucNang("Quay ve menu chinh");
	menu.themChucNang("Them mat hang");
	menu.themChucNang("Xoa mat hang");
	menu.themChucNang("Sua mat hang");
	menu.themChucNang("Tim kiem mat hang");
	menu.renderMenu();
	int key = menu.nhapLuaChon();

	if (key == 1)
	{
		return 0;// tra ve 0 de xoa khoi menu con
	}
	else if (key == 2)
	{
		cout << "Them mat hang\n";
		themMatHang();
		system("pause");
		return 1;// tra ve 1 de tiep tuc vong lap voi menu con
	}
	else if (key == 3)
	{
		cout << "Xoa mat hang\n";
		xuatDSMatHang();
		string id;
		cout << "Nhap ma hang muon xoa: ";
		getline(cin, id);
		xoaMatHang(id);
		system("pause");
		return 1;
	}
	else if (key == 4)
	{
		cout << "Sua mat hang\n";
		xuatDSMatHang();
		string id;
		cout << "Nhap ma hang muon chinh sua: ";
		getline(cin, id);
		suaMatHang(id);
		system("pause");
		return 1;
	}
	else if (key == 5)
	{
		cout << "Tim kiem mat hang\n";
		xuatDSMatHang();
		string keyword;
		cout << "Nhap tu khoa can tim: ";
		getline(cin, keyword);
		timKiemMatHang(keyword);
		system("pause");
		return 1;
	}
	else if (key == 0)
	{
		int flag = menu.XuLyThoat();
		if (flag == 0) return -1;
		return 1;
	}
	else
	{
		cout << "Lua chon khong hop le!\n";
		system("pause");
		return 1;
	}
}

int CuaHang::menuLoaiHang()
{
	Menu menu("MENU LOAI HANG");
	menu.themChucNang("Quay ve menu chinh");
	menu.themChucNang("Them loai hang");
	menu.themChucNang("Xoa loai hang");
	menu.themChucNang("Sua loai hang");
	menu.themChucNang("Tim kiem loai hang");
	menu.renderMenu();
	int key = menu.nhapLuaChon();

	if (key == 1)
	{
		return 0;// tra ve 0 de xoa khoi menu con
	}
	else if (key == 2)
	{
		cout << "Them loai hang\n";
		themLoaiHang();
		system("pause");
		return 1;// tra ve 1 de tiep tuc vong lap voi menu con
	}
	else if (key == 3)
	{
		cout << "Xoa loai hang\n";
		xuatDSLoaiHang();
		string id;
		cout << "Nhap ma loai muon xoa: ";
		getline(cin, id);
		xoaLoaiHang(id);
		system("pause");
		return 1;
	}
	else if (key == 4)
	{
		cout << "Sua ma loai\n";
		xuatDSLoaiHang();
		string id;
		cout << "Nhap ma loai muon chinh sua: ";
		getline(cin, id);
		suaLoaiHang(id);
		system("pause");
		return 1;
	}
	else if (key == 5)
	{
		cout << "Tim kiem loai hang\n";
		xuatDSLoaiHang();
		string keyword;
		cout << "Nhap tu khoa can tim: ";
		getline(cin, keyword);
		timKiemLoaiHang(keyword);
		system("pause");
		return 1;
	}
	else if (key == 0)
	{
		int flag = menu.XuLyThoat();
		if (flag == 0) return -1;
		return 1;
	}
	else
	{
		cout << "Lua chon khong hop le!\n";
		system("pause");
		return 1;
	}
}

int CuaHang::menuHoaDonBan()
{
	Menu menu("MENU HOA DON BAN HANG");
	menu.themChucNang("Quay ve menu chinh");
	menu.themChucNang("Them hoa don ban hang");
	menu.themChucNang("Xoa hoa don ban hang");
	menu.themChucNang("Sua hoa don ban hang");
	menu.themChucNang("Tim kiem hoa don ban hang");
	menu.renderMenu();
	int key = menu.nhapLuaChon();

	if (key == 1)
	{
		return 0;// tra ve 0 de xoa khoi menu con
	}
	else if (key == 2)
	{
		cout << "Them hoa don ban hang\n";
		themHoaDonBan();
		system("pause");
		return 1;// tra ve 1 de tiep tuc vong lap voi menu con
	}
	else if (key == 3)
	{
		cout << "Xoa hoa don ban hang\n";
		xuatDSHDB();
		string id;
		cout << "Nhap ma hoa don ban muon xoa: ";
		getline(cin, id);
		xoaHDB(id);
		system("pause");
		return 1;
	}
	else if (key == 4)
	{
		cout << "Sua hoa don ban hang\n";
		xuatDSHDB();
		string id;
		cout << "Nhap ma hoa don ban muon sua: ";
		getline(cin, id);
		suaHDB(id);
		system("pause");
		return 1;
	}
	else if (key == 5)
	{
		cout << "Tim kiem hoa don ban hang\n";
		xuatDSHDB();
		string keyword;
		cout << "Nhap tu khoa can tim: ";
		getline(cin, keyword);
		timKiemHoaDonBan(keyword);
		system("pause");
		return 1;
	}
	else if (key == 0)
	{
		int flag = menu.XuLyThoat();
		if (flag == 0) return -1;
		return 1;
	}
	else
	{
		cout << "Lua chon khong hop le!\n";
		system("pause");
		return 1;
	}
}

int CuaHang::menuHoaDonNhap()
{
	Menu menu("MENU HOA DON NHAP HANG");
	menu.themChucNang("Quay ve menu chinh");
	menu.themChucNang("Them hoa don nhap hang");
	menu.themChucNang("Xoa hoa don nhap hang");
	menu.themChucNang("Sua hoa don nhap hang");
	menu.themChucNang("Tim kiem hoa don nhap hang");
	menu.renderMenu();
	int key = menu.nhapLuaChon();

	if (key == 1)
	{
		return 0;// tra ve 0 de xoa khoi menu con
	}
	else if (key == 2)
	{
		cout << "Them hoa don nhap hang\n";
		themHoaDonNhap();
		system("pause");
		return 1;// tra ve 1 de tiep tuc vong lap voi menu con
	}
	else if (key == 3)
	{
		cout << "Xoa hoa don nhap hang\n";
		xuatDSHDN();
		string id;
		cout << "Nhap ma hoa don nhap muon xoa: ";
		getline(cin, id);
		xoaHDN(id);
		system("pause");
		return 1;
	}
	else if (key == 4)
	{
		cout << "Sua hoa don nhap hang\n";
		xuatDSHDN();
		string id;
		cout << "Nhap ma hoa don nhap muon sua: ";
		getline(cin, id);
		suaHDN(id);
		system("pause");
		return 1;
	}
	else if (key == 5)
	{
		cout << "Tim kiem hoa don nhap hang\n";
		xuatDSHDN();
		string keyword;
		cout << "Nhap tu khoa can tim: ";
		getline(cin, keyword);
		timKiemHoaDonNhap(keyword);
		system("pause");
		return 1;
	}
	else if (key == 0)
	{
		int flag = menu.XuLyThoat();
		if (flag == 0) return -1;
		return 1;
	}
	else
	{
		cout << "Lua chon khong hop le!\n";
		system("pause");
		return 1;
	}
}

void CuaHang::xuatKeNgang()
{
	for (int i = 0; i < doRongCot.size(); i++)
	{
		cout << "+" << string(doRongCot[i], '-');
	}
	cout << "+\n";
}

void CuaHang::xuatTieuDe()
{
	xuatKeNgang();
	for (int i = 0; i < tieuDe.size(); i++)
	{
		cout << "|" << string((doRongCot[i] - tieuDe[i].length()) / 2, ' ')
			<< tieuDe[i]
			<< string((doRongCot[i] - tieuDe[i].length() + 1) / 2, ' ');
	}
	cout << "|\n";
	xuatKeNgang();

}

void CuaHang::xuatDSMatHang()
{
	tieuDe = { "Ma hang", "Ten hang", "Han dung","So luong","Don gia", "Cong ty", "Nam SX", "Loai hang" };
	doRongCot = { 10,30,10,10,20,30,10,30 };
	xuatTieuDe();

	for (int i = 0; i < dsMH.size(); i++)
	{
		dsMH[i].xuat();
	}

	xuatKeNgang();
}

void CuaHang::xuatDSLoaiHang()
{
	tieuDe = { "Ma loai", "Ten loai", "Mo ta" };
	doRongCot = { 10,30,100 };
	xuatTieuDe();

	for (int i = 0; i < dsLH.size(); i++)
	{
		dsLH[i].xuat();
	}

	xuatKeNgang();
}

void CuaHang::xuatDSHDB()
{
	tieuDe = { "Ma HD", "Ngay ban", "Ten khach hang", "Ma hang", "Ten hang", "So luong", "Gia ban"};
	doRongCot = { 10,10,30,10,30,10,20 };
	xuatTieuDe();

	for (int i = 0; i < dsHDB.size(); i++)
	{
		dsHDB[i].xuat();
	}

	xuatKeNgang();
}

void CuaHang::xuatDSHDN()
{
	tieuDe = { "Ma HD", "Ngay nhap", "Ten cong ty nhap","Ma hang", "Ten hang", "So luong", "Gia nhap" };
	doRongCot = { 10,10,30,10,30,10,20 };
	xuatTieuDe();

	for (int i = 0; i < dsHDN.size(); i++)
	{
		dsHDN[i].xuat();
	}

	xuatKeNgang();

}

void CuaHang::themMatHang()
{
	string maHang, tenHang, hanDung, congTySX, loaiHang;
	int soLuong, namSX;
	double donGia;
	xuatDSLoaiHang();
	cout << "Nhap loai hang: ";
	getline(cin, loaiHang);

	if (!tonTaiLoaiHang(loaiHang))
	{
		cout << "Ma loai hang khong ton tai. Vui long kiem tra lai.\n";
		return;
	}

	do
	{
		cout << "Nhap ma hang: ";
		getline(cin, maHang);
		bool trung = false;
		for (int i = 0; i < dsMH.size(); i++)
		{
			if (maHang == dsMH[i].getMaHang())
			{
				cout << "Ma hang da ton tai. Vui long nhap lai.\n";
				trung = true;
				break;
			}
		}

		if (!trung) break;
	} while (true);

	cout << "Nhap ten hang: ";
	getline(cin, tenHang);

	do
	{
		cout << "Nhap han dung (dd/mm/yyyy): ";
		getline(cin, hanDung);
		NgayThangNam han(hanDung);
		if (han.ngayHopLe())
		{
			//cho ra dinh dang 01/01/2025
			hanDung = han.xuatChuoi();
			break;
		}
		else
		{
			cout << "Ngay thang nam chua hop le\n";
		}
	} while (true);

	do
	{
		cout << "Nhap so luong: ";
		while (!(cin >> soLuong)) {
			cout << "Loi: Vui long nhap so nguyen!\n";
			cin.clear();             // xóa trạng thái lỗi
			cin.ignore(1000, '\n');  // bỏ phần còn lại của dòng sai
			cout << "Nhap lai so luong: ";
		}
		cin.ignore();

		if (soLuong < 0)
		{
			cout << "So luong phai lon hon hoac bang 0\n";
		}
	} while (soLuong < 0);

	do
	{
		cout << "Nhap don gia: ";
		while (!(cin >> donGia)) {
			cout << "Loi: Vui long nhap so nguyen!\n";
			cin.clear();             // xóa trạng thái lỗi
			cin.ignore(1000, '\n');  // bỏ phần còn lại của dòng sai
			cout << "Nhap lai don gia: ";
		}
		cin.ignore();

		if (donGia < 0)
		{
			cout << "Don gia phai lon hon hoac bang 0\n";
		}
	} while (donGia < 0);

	cout << "Nhap cong ty san xuat: ";
	getline(cin, congTySX);

	cout << "Nhap nam san xuat: ";
	while (!(cin >> namSX)) {
		cout << "Loi: Vui long nhap so nguyen!\n";
		cin.clear();             // xóa trạng thái lỗi
		cin.ignore(1000, '\n');  // bỏ phần còn lại của dòng sai
		cout << "Nhap lai nam san xuat: ";
	}
	cin.ignore();

	MatHang mh(maHang, tenHang, hanDung, soLuong, donGia, congTySX, namSX, loaiHang);
	dsMH.push_back(mh);
}

void CuaHang::themLoaiHang()
{
	string maLoai, tenLoai, moTa;

	do
	{
		cout << "Nhap ma loai: ";
		getline(cin, maLoai);
		bool trung = false;
		for (int i = 0; i < dsLH.size(); i++)
		{
			if (maLoai == dsLH[i].getMaLoai())
			{
				cout << "Ma loai da ton tai. Vui long nhap lai.\n";
				trung = true;
				break;
			}
		}

		if (!trung) break;
	} while (true);

	cout << "Nhap ten loai: ";
	getline(cin, tenLoai);

	cout << "Nhap mo ta: ";
	getline(cin, moTa);

	LoaiHang lh(maLoai, tenLoai, moTa);
	dsLH.push_back(lh);
}

void CuaHang::themHoaDonBan()
{
	string maHD, ngayBan, tenKhachHang;
	vector<ChiTietHoaDon> chiTiet;

	do
	{
		cout << "Nhap ma hoa don ban: ";
		getline(cin, maHD);
		bool trung = false;
		for (int i = 0; i < dsHDB.size(); i++)
		{
			if (maHD == dsHDB[i].getMaHD())
			{
				cout << "Ma hoa don ban da ton tai. Vui long nhap lai.\n";
				trung = true;
				break;
			}
		}

		if (!trung) break;
	} while (true);

	do
	{
		cout << "Nhap ngay ban (dd/mm/yyyy): ";
		getline(cin, ngayBan);
		NgayThangNam ngay(ngayBan);
		if (ngay.ngayHopLe())
		{
			//cho ra dinh dang 01/01/2025
			ngayBan = ngay.xuatChuoi();
			break;
		}
		else
		{
			cout << "Ngay thang nam chua hop le\n";
		}
	} while (true);

	cout << "Nhap ten khach hang: ";
	getline(cin, tenKhachHang);

	int n;
	do
	{
		cout << "Nhap so luong mat hang ban: ";
		while (!(cin >> n)) {
			cout << "Loi: Vui long nhap so nguyen!\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Nhap lai so luong mat hang ban: ";
		}
		cin.ignore();

		if (n < 0)
		{
			cout << "So luong phai lon hon hoac bang 0\n";
		}
	} while (n < 0);

	xuatDSMatHang();

	for (int i = 0; i < n; i++)
	{
		chiTiet.push_back(themChiTietHoaDonBan());
	}

	HoaDonBan hd(maHD, ngayBan, tenKhachHang, chiTiet);
	dsHDB.push_back(hd);
}

void CuaHang::themHoaDonNhap()
{
	string maHD, ngayNhap, tenCongTyNhap;
	vector<ChiTietHoaDon> chiTiet;

	do
	{
		cout << "Nhap ma hoa don nhap: ";
		getline(cin, maHD);
		bool trung = false;
		for (int i = 0; i < dsHDN.size(); i++)
		{
			if (maHD == dsHDN[i].getMaHD())
			{
				cout << "Ma hoa don nhap da ton tai. Vui long nhap lai.\n";
				trung = true;
				break;
			}
		}

		if (!trung) break;
	} while (true);

	do
	{
		cout << "Nhap ngay nhap (dd/mm/yyyy): ";
		getline(cin, ngayNhap);
		NgayThangNam ngay(ngayNhap);
		if (ngay.ngayHopLe())
		{
			//cho ra dinh dang 01/01/2025
			ngayNhap = ngay.xuatChuoi();
			break;
		}
		else
		{
			cout << "Ngay thang nam chua hop le\n";
		}
	} while (true);

	cout << "Nhap ten cong ty nhap: ";
	getline(cin, tenCongTyNhap);


	int n;
	do
	{
		cout << "Nhap so luong mat hang nhap: ";
		while (!(cin >> n)) {
			cout << "Loi: Vui long nhap so nguyen!\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Nhap lai so luong mat hang nhap: ";
		}
		cin.ignore();

		if (n < 0)
		{
			cout << "So luong phai lon hon hoac bang 0\n";
		}
	} while (n < 0);

	xuatDSMatHang();

	for (int i = 0; i < n; i++)
	{
		chiTiet.push_back(themChiTietHoaDonNhap());
	}

	HoaDonNhap hd(maHD, ngayNhap, tenCongTyNhap, chiTiet);
	dsHDN.push_back(hd);
}

void CuaHang::xoaMatHang(const string& id)
{
	for (int i = 0; i < dsMH.size(); i++)
	{
		if (id == dsMH[i].getMaHang())
		{
			if (tonTaiMatHangTrongHDB(id))
			{
				cout << "Ton tai mat hang trong hoa don ban\n";
				cout << "Khong the xoa mat hang co ma: " + id << "\n";
				return;
			}
			else if (tonTaiMatHangTrongHDN(id))
			{
				cout << "Ton tai mat hang trong hoa don ban\n";
				cout << "Khong the xoa mat hang co ma: " + id << "\n";
				return;
			}

			cout << "Ban xoa mat hang co ma hang la: " << id << "\n";
			char key;
			bool flag = false;
			printf("Ban co muon xoa khong?[y/n]: ");
			cin >> key;
			if (key == 'y' || key == 'Y') flag = true;
			if (flag)
			{
				dsMH.erase(dsMH.begin() + i);
				cout << "Da xoa ma hang co ma la " << id << " ra khoi cua hang\n";
				return;
			}
			else
			{
				return;
			}
		}
	}
	cout << "Khong tim thay ma hang: " << id << "\n";
}

void CuaHang::xoaLoaiHang(const string& id)
{
	for (int i = 0; i < dsLH.size(); i++)
	{
		if (id == dsLH[i].getMaLoai())
		{
			if (tonTaiMatHang(id))
			{
				cout << "Ton tai mat hang co loai hang la ma loai dang xoa\n";
				return;
			}
			cout << "Ban xoa loai hang co ma loai la: " << id << "\n";
			char key;
			bool flag = false;
			printf("Ban co muon xoa khong?[y/n]: ");
			cin >> key;
			if (key == 'y' || key == 'Y') flag = true;
			if (flag)
			{
				dsLH.erase(dsLH.begin() + i);
				cout << "Da xoa loai hang co ma la " << id << " ra khoi cua hang\n";
				return;
			}
			else
			{
				return;
			}
		}
	}
	cout << "Khong tim thay ma loai: " << id << "\n";
}

void CuaHang::xoaHDB(const string& id)
{
	for (int i = 0; i < dsHDB.size(); i++)
	{
		if (id == dsHDB[i].getMaHD())
		{
			cout << "Ban xoa hoa don ban co ma hoa don la: " << id << "\n";
			char key;
			bool flag = false;
			printf("Ban co muon xoa khong?[y/n]: ");
			cin >> key;
			if (key == 'y' || key == 'Y') flag = true;
			if (flag)
			{
				dsHDB.erase(dsHDB.begin() + i);
				cout << "Da xoa hoa don ban co ma la " << id << " ra khoi cua hang\n";
				return;
			}
			else
			{
				return;
			}
		}
	}
	cout << "Khong tim thay ma hoa don ban: " << id << "\n";
}

void CuaHang::xoaHDN(const string& id)
{
	for (int i = 0; i < dsHDN.size(); i++)
	{
		if (id == dsHDN[i].getMaHD())
		{
			cout << "Ban xoa hoa don nhap co ma hoa don la: " << id << "\n";
			char key;
			bool flag = false;
			printf("Ban co muon xoa khong?[y/n]: ");
			cin >> key;
			if (key == 'y' || key == 'Y') flag = true;
			if (flag)
			{
				dsHDN.erase(dsHDN.begin() + i);
				cout << "Da xoa hoa don nhap co ma la " << id << " ra khoi cua hang\n";
				return;
			}
			else
			{
				return;
			}
		}
	}
	cout << "Khong tim thay ma hoa don nhap: " << id << "\n";
}

void CuaHang::suaMatHang(const string& id)
{
	for (int i = 0; i < dsMH.size(); i++)
	{
		if (id == dsMH[i].getMaHang())
		{
			string tieuDe = "SUA THONG TIN MAT HANG CO MA ID: " + dsMH[i].getMaHang();
			Menu menuSua(tieuDe);
			menuSua.themChucNang("Chinh sua ma hang");
			menuSua.themChucNang("Chinh sua ten hang");
			menuSua.themChucNang("Chinh sua han dung");
			menuSua.themChucNang("Chinh sua so luong");
			menuSua.themChucNang("Chinh sua don gia");
			menuSua.themChucNang("Chinh sua cong ty san xuat");
			menuSua.themChucNang("Chinh sua nam san xuat");
			menuSua.themChucNang("Chinh sua loai hang");
			menuSua.themChucNang("Quay ve menu mat hang");
			menuSua.renderMenu(false);

			xuatTieuDe();
			dsMH[i].xuat();
			xuatKeNgang();

			int key = menuSua.nhapLuaChon();
			if (key == 1)
			{
				string maHang;
				cout << "Chinh sua thong tin ma hang\n";
				do
				{
					cout << "Nhap ma hang: ";
					getline(cin, maHang);
					bool trung = false;
					for (int i = 0; i < dsMH.size(); i++)
					{
						if (maHang == dsMH[i].getMaHang())
						{
							cout << "Ma hang da ton tai. Vui long nhap lai.\n";
							trung = true;
							break;
						}
					}

					if (!trung) break;
				} while (true);

				dsMH[i].setMaHang(maHang);

				suaMaHangTrongHDB(id, maHang);
				suaMaHangTrongHDN(id, maHang);
				cout << "Chinh sua ma hang thanh cong\n";
			}
			else if (key == 2)
			{
				string tenHang;
				cout << "Chinh sua thong tin ten hang: ";
				getline(cin, tenHang);
				dsMH[i].setTenHang(tenHang);
				suaTenHangTrongHDB(id, tenHang);
				suaTenHangTrongHDN(id, tenHang);
				cout << "Chinh sua ten hang thanh cong\n";
			}
			else if (key == 3)
			{
				string hanDung;
				cout << "Chinh sua thong tin han dung\n";
				do
				{
					cout << "Nhap han dung (dd/mm/yyyy): ";
					getline(cin, hanDung);
					NgayThangNam han(hanDung);
					if (han.ngayHopLe())
					{
						//cho ra dinh dang 01/01/2025
						hanDung = han.xuatChuoi();
						break;
					}
					else
					{
						cout << "Ngay thang nam chua hop le\n";
					}
				} while (true);

				dsMH[i].setHanDung(hanDung);
				cout << "Chinh sua han dung thanh cong\n";
			}
			else if (key == 4)
			{
				int soLuong;
				cout << "Chinh sua thong tin so luong\n";
				do
				{
					cout << "Nhap so luong: ";
					while (!(cin >> soLuong)) {
						cout << "Loi: Vui long nhap so nguyen!\n";
						cin.clear();             // xóa trạng thái lỗi
						cin.ignore(1000, '\n');  // bỏ phần còn lại của dòng sai
						cout << "Nhap lai so luong: ";
					}
					cin.ignore();

					if (soLuong < 0)
					{
						cout << "So luong phai lon hon hoac bang 0\n";
					}
				} while (soLuong < 0);

				dsMH[i].setSoLuong(soLuong);
				cout << "Chinh sua so luong thanh cong\n";
			}
			else if (key == 5)
			{
				double donGia;
				do
				{
					cout << "Nhap don gia: ";
					while (!(cin >> donGia)) {
						cout << "Loi: Vui long nhap so nguyen!\n";
						cin.clear();             // xóa trạng thái lỗi
						cin.ignore(1000, '\n');  // bỏ phần còn lại của dòng sai
						cout << "Nhap lai don gia: ";
					}
					cin.ignore();

					if (donGia < 0)
					{
						cout << "Don gia phai lon hon hoac bang 0\n";
					}
				} while (donGia < 0);

				dsMH[i].setDonGia(donGia);
				cout << "Chinh sua don gia thanh cong\n";
			}
			else if (key == 6)
			{
				string congTySX;
				cout << "Chinh sua thong tin cong ty san xuat\n";
				cout << "Nhap cong ty san xuat: ";
				getline(cin, congTySX);
				dsMH[i].setCongTySX(congTySX);
				cout << "Chinh sua cong ty san xuat thanh cong\n";
			}
			else if (key == 7)
			{
				int namSX;
				cout << "Chinh sua thong tin nam san xuat\n";
				cout << "Nhap nam san xuat: ";
				while (!(cin >> namSX)) {
					cout << "Loi: Vui long nhap so nguyen!\n";
					cin.clear();             // xóa trạng thái lỗi
					cin.ignore(1000, '\n');  // bỏ phần còn lại của dòng sai
					cout << "Nhap lai nam san xuat: ";
				}
				cin.ignore();
				dsMH[i].setNamSX(namSX);
				cout << "Chinh sua nam san xuat thanh cong\n";
			}
			else if (key == 8)
			{
				string loaiHang;
				cout << "Chinh sua thong tin loai hang\n";
				cout << "Nhap loai hang: ";
				getline(cin, loaiHang);
				if (!tonTaiLoaiHang(loaiHang))
				{
					cout << "Ma loai hang khong ton tai. Vui long kiem tra lai.\n";
					return;
				}
				dsMH[i].setLoaiHang(loaiHang);
				cout << "Chinh sua loai hang thanh cong\n";
			}
			else if (key == 9)
			{
				return;
			}
			else
			{
				cout << "Lua chon khong hop le!\n";
			}
			return;
		}
	}
	cout << "Khong tim thay ma hang: " << id << "\n";
}

void CuaHang::suaLoaiHang(const string& id)
{
	for (int i = 0; i < dsLH.size(); i++)
	{
		if (id == dsLH[i].getMaLoai())
		{
			string tieuDe = "SUA THONG TIN LOAI HANG CO MA ID: " + dsLH[i].getMaLoai();
			Menu menuSua(tieuDe);
			menuSua.themChucNang("Chinh sua ma loai");
			menuSua.themChucNang("Chinh sua ten loai");
			menuSua.themChucNang("Chinh sua mo ta");
			menuSua.themChucNang("Quay ve menu loai hang");
			menuSua.renderMenu(false);

			xuatTieuDe();
			dsLH[i].xuat();
			xuatKeNgang();

			int key = menuSua.nhapLuaChon();
			if (key == 1)
			{
				string maLoai;
				cout << "Chinh sua thong tin ma loai\n";
				do
				{
					cout << "Nhap ma loai: ";
					getline(cin, maLoai);
					bool trung = false;
					for (int i = 0; i < dsLH.size(); i++)
					{
						if (maLoai == dsLH[i].getMaLoai())
						{
							cout << "Ma loai da ton tai. Vui long nhap lai.\n";
							trung = true;
							break;
						}
					}

					if (!trung) break;
				} while (true);
				dsLH[i].setMaLoai(maLoai);
				suaLoaiHangTrongMatHang(id, maLoai);
				cout << "Chinh sua ma loai thanh cong\n";
			}
			else if (key == 2)
			{
				string tenLoai;
				cout << "Chinh sua thong tin ten loai: ";
				getline(cin, tenLoai);
				dsLH[i].setTenLoai(tenLoai);
				cout << "Chinh sua ten loai thanh cong\n";
			}
			else if (key == 3)
			{
				string moTa;
				cout << "Chinh sua thong tin mo ta: ";
				getline(cin, moTa);
				dsLH[i].setMoTa(moTa);
				cout << "Chinh sua mo ta thanh cong\n";
			}
			else if (key == 4)
			{
				return;
			}
			else
			{
				cout << "Lua chon khong hop le!\n";
			}
			return;
		}
	}
	cout << "Khong tim thay ma loai: " << id << "\n";
}

void CuaHang::suaHDB(const string& id)
{
	for (int i = 0; i < dsHDB.size(); i++)
	{
		if (id == dsHDB[i].getMaHD())
		{
			string tieuDe = "SUA THONG TIN MAT HANG CO MA ID: " + dsHDB[i].getMaHD();
			Menu menuSua(tieuDe);
			menuSua.themChucNang("Chinh sua ma hoa don ban");
			menuSua.themChucNang("Chinh sua ngay ban");
			menuSua.themChucNang("Chinh sua ten khach hang");
			menuSua.themChucNang("Chinh sua chi tiet hoa don");
			menuSua.themChucNang("Quay ve menu hoa don ban");
			menuSua.renderMenu(false);

			xuatTieuDe();
			dsHDB[i].xuat();
			xuatKeNgang();

			int key = menuSua.nhapLuaChon();
			if (key == 1)
			{
				string maHD;
				cout << "Chinh sua thong tin ma hoa don ban\n";
				do
				{
					cout << "Nhap ma hoa don ban: ";
					getline(cin, maHD);
					bool trung = false;
					for (int i = 0; i < dsHDB.size(); i++)
					{
						if (maHD == dsHDB[i].getMaHD())
						{
							cout << "Ma hoa don ban da ton tai. Vui long nhap lai.\n";
							trung = true;
							break;
						}
					}

					if (!trung) break;
				} while (true);

				dsHDB[i].setMaHD(maHD);
				cout << "Chinh sua ma hoa don ban thanh cong\n";
			}
			else if (key == 2)
			{
				string ngayBan;
				cout << "Chinh sua thong tin ngay ban\n";
				do
				{
					cout << "Nhap ngay ban (dd/mm/yyyy): ";
					getline(cin, ngayBan);
					NgayThangNam ngay(ngayBan);
					if (ngay.ngayHopLe())
					{
						//cho ra dinh dang 01/01/2025
						ngayBan = ngay.xuatChuoi();
						break;
					}
					else
					{
						cout << "Ngay thang nam chua hop le\n";
					}
				} while (true);

				dsHDB[i].setNgay(ngayBan);
				cout << "Chinh sua ngay ban thanh cong\n";
			}
			else if (key == 3)
			{
				string tenKhachHang;
				cout << "Chinh sua thong tin ten khach hang: ";
				getline(cin, tenKhachHang);
				dsHDB[i].setTenKhachHang(tenKhachHang);
				cout << "Chinh sua ten khach hang thanh cong\n";
			}
			else if (key == 4)
			{
				string tieuDe = "CHINH SUA DS CTHD CO MA ID: " + dsHDB[i].getMaHD();
				Menu menuDSCTHD(tieuDe);
				menuDSCTHD.themChucNang("Them chi tiet hoa don");
				menuDSCTHD.themChucNang("Xoa chi tiet hoa don");
				menuDSCTHD.themChucNang("Sua chi tiet hoa don");
				menuDSCTHD.themChucNang("Quay ve menu hoa don ban");
				menuDSCTHD.renderMenu(false);


				vector<ChiTietHoaDon> ct = dsHDB[i].getChiTiet();
				for (int j = 0; j < ct.size(); j++)
				{
					cout << j + 1 << ". ";
					ct[j].xuat();
				}

				key = menuDSCTHD.nhapLuaChon();

				if (key == 1)
				{
					int n;
					do
					{
						cout << "Nhap so luong mat hang ban: ";
						while (!(cin >> n)) {
							cout << "Loi: Vui long nhap so nguyen!\n";
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Nhap lai so luong mat hang ban: ";
						}
						cin.ignore();

						if (n < 0)
						{
							cout << "So luong phai lon hon hoac bang 0\n";
						}
					} while (n < 0);

					xuatDSMatHang();

					for (int k = 0; k < n; k++)
					{
						dsHDB[i].getChiTiet().push_back(themChiTietHoaDonBan());
					}
				}
				else if (key == 2)
				{
					int dong;
					cout << "Nhap dong muon xoa: ";
					do
					{
						while (!(cin >> dong)) {
							cout << "Loi: Vui long nhap so nguyen!\n";
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Nhap lai dong muon xoa: ";
						}
						cin.ignore();

						if (ct.size() < dong)
						{
							cout << "So dong phai nho hon " << ct.size() << ", moi nhap lai so dong:";
						}
					} while (ct.size() < dong);

					cout << "Ban xoa chi tiet hoa don dong: " << dong << "\n";
					ct[dong - 1].xuat();
					char key1;
					bool flag = false;
					printf("Ban co muon xoa khong?[y/n]: ");
					cin >> key1;
					if (key1 == 'y' || key == 'Y') flag = true;
					if (flag)
					{
						dsHDB[i].xoaCTHD(dong - 1);
						cout << "Xoa dong chi tiet hoa don thanh cong\n";
						return;
					}
					else
					{
						return;
					}
				}
				else if (key == 3)
				{
					int dong;
					cout << "Nhap dong muon sua: ";
					do
					{
						while (!(cin >> dong)) {
							cout << "Loi: Vui long nhap so nguyen!\n";
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Nhap lai dong muon sua: ";
						}
						cin.ignore();

						if (ct.size() < dong)
						{
							cout << "So dong phai nho hon " << ct.size() << ", moi nhap lai so dong:";
						}
					} while (ct.size() < dong);

					Menu menuCTHD("CHINH SUA CHI TIET HOA DON");
					menuCTHD.themChucNang("Sua ma hang");
					menuCTHD.themChucNang("Sua so luong");
					menuCTHD.themChucNang("Sua gia ban");
					menuCTHD.themChucNang("Quay ve menu hoa don ban");
					menuCTHD.renderMenu(false);
					ct[dong - 1].xuat();

					int key = menuCTHD.nhapLuaChon();


					if (key == 1)
					{
						MatHang* matHang = NULL;
						string maHang;
						while (true)
						{
							xuatDSMatHang();
							cout << "Nhap ma hang: ";
							getline(cin, maHang);

							matHang = timKiemMatHangTheoID(maHang);

							if (matHang == NULL)
							{
								cout << "Ma mat hang khong ton tai. Vui long nhap lai.\n";
							}
							else
							{
								dsHDB[i].getChiTiet()[dong - 1].setMaHang(maHang);
								break;
							}
						}
						dsHDB[i].getChiTiet()[dong - 1].setTenHang(matHang->getTenHang());
					}
					else if (key == 2)
					{
						MatHang* matHang = NULL;
						matHang = timKiemMatHangTheoID(dsHDB[i].getChiTiet()[dong - 1].getMaHang());
						int soLuong;

						while (true)
						{
							cout << "Nhap so luong nhap: ";
							while (!(cin >> soLuong)) {
								cout << "Loi: Vui long nhap so nguyen!\n";
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Nhap lai so luong nhap: ";
							}
							cin.ignore();

							if (soLuong < 0)
							{
								cout << "So luong nhap phai lon hon hoac bang 0\n";
							}
							else
							{
								break;
							}
						}

						dsHDB[i].getChiTiet()[dong - 1].setSoLuong(soLuong);
					}
					else if (key == 3)
					{
						double giaBan;
						cout << "Nhap gia ban: ";
						while (!(cin >> giaBan)) {
							cout << "Loi: Vui long nhap so!\n";
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Nhap lai gia ban: ";
						}
						cin.ignore();

						dsHDB[i].getChiTiet()[dong - 1].setGia(giaBan);
					}
				}
			}
			else if (key == 5)
			{
				return;
			}
			else
			{
				cout << "Lua chon khong hop le!\n";
			}
			return;
		}
	}
	cout << "Khong tim thay ma hang: " << id << "\n";
}

void CuaHang::suaHDN(const string& id)
{
	for (int i = 0; i < dsHDN.size(); i++)
	{
		if (id == dsHDN[i].getMaHD())
		{
			string tieuDe = "SUA THONG TIN MAT HANG CO MA ID: " + dsHDN[i].getMaHD();
			Menu menuSua(tieuDe);
			menuSua.themChucNang("Chinh sua ma hoa don nhap");
			menuSua.themChucNang("Chinh sua ngay nhap");
			menuSua.themChucNang("Chinh sua ten cong ty nhap");
			menuSua.themChucNang("Chinh sua chi tiet hoa don");
			menuSua.themChucNang("Quay ve menu hoa don nhap");
			menuSua.renderMenu(false);

			xuatTieuDe();
			dsHDN[i].xuat();
			xuatKeNgang();

			int key = menuSua.nhapLuaChon();
			if (key == 1)
			{
				string maHD;
				cout << "Chinh sua thong tin ma hoa don nhap\n";
				do
				{
					cout << "Nhap ma hoa don nhap: ";
					getline(cin, maHD);
					bool trung = false;
					for (int i = 0; i < dsHDN.size(); i++)
					{
						if (maHD == dsHDN[i].getMaHD())
						{
							cout << "Ma hoa don nhap da ton tai. Vui long nhap lai.\n";
							trung = true;
							break;
						}
					}

					if (!trung) break;
				} while (true);

				dsHDN[i].setMaHD(maHD);
				cout << "Chinh sua ma hoa don nhap thanh cong\n";
			}
			else if (key == 2)
			{
				string ngayBan;
				cout << "Chinh sua thong tin ngay nhap\n";
				do
				{
					cout << "Nhap ngay nhap (dd/mm/yyyy): ";
					getline(cin, ngayBan);
					NgayThangNam ngay(ngayBan);
					if (ngay.ngayHopLe())
					{
						//cho ra dinh dang 01/01/2025
						ngayBan = ngay.xuatChuoi();
						break;
					}
					else
					{
						cout << "Ngay thang nam chua hop le\n";
					}
				} while (true);

				dsHDN[i].setNgay(ngayBan);
				cout << "Chinh sua ngay nhap thanh cong\n";
			}
			else if (key == 3)
			{
				string tenCongTyNhap;
				cout << "Chinh sua thong tin ten cong ty nhap: ";
				getline(cin, tenCongTyNhap);
				dsHDN[i].setTenCongTyNhap(tenCongTyNhap);
				cout << "Chinh sua ten cong ty nhap thanh cong\n";
			}
			else if (key == 4)
			{
				string tieuDe = "CHINH SUA DS CTHD CO MA ID: " + dsHDN[i].getMaHD();
				Menu menuDSCTHD(tieuDe);
				menuDSCTHD.themChucNang("Them chi tiet hoa don");
				menuDSCTHD.themChucNang("Xoa chi tiet hoa don");
				menuDSCTHD.themChucNang("Sua chi tiet hoa don");
				menuDSCTHD.themChucNang("Quay ve menu hoa don ban");
				menuDSCTHD.renderMenu(false);


				vector<ChiTietHoaDon> ct = dsHDN[i].getChiTiet();
				for (int j = 0; j < ct.size(); j++)
				{
					cout << j + 1 << ". ";
					ct[j].xuat();
				}

				key = menuDSCTHD.nhapLuaChon();

				if (key == 1)
				{
					int n;
					do
					{
						cout << "Nhap so luong mat hang nhap: ";
						while (!(cin >> n)) {
							cout << "Loi: Vui long nhap so nguyen!\n";
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Nhap lai so luong mat hang nhap: ";
						}
						cin.ignore();

						if (n < 0)
						{
							cout << "So luong phai lon hon hoac bang 0\n";
						}
					} while (n < 0);

					xuatDSMatHang();

					for (int k = 0; k < n; k++)
					{
						dsHDN[i].getChiTiet().push_back(themChiTietHoaDonBan());
					}
				}
				else if (key == 2)
				{
					int dong;
					cout << "Nhap dong muon xoa: ";
					do
					{
						while (!(cin >> dong)) {
							cout << "Loi: Vui long nhap so nguyen!\n";
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Nhap lai dong muon xoa: ";
						}
						cin.ignore();

						if (ct.size() < dong)
						{
							cout << "So dong phai nho hon " << ct.size() << ", moi nhap lai so dong:";
						}
					} while (ct.size() < dong);

					cout << "Ban xoa chi tiet hoa don dong: " << dong << "\n";
					ct[dong - 1].xuat();
					char key1;
					bool flag = false;
					printf("Ban co muon xoa khong?[y/n]: ");
					cin >> key1;
					if (key1 == 'y' || key == 'Y') flag = true;
					if (flag)
					{
						dsHDN[i].xoaCTHD(dong - 1);
						cout << "Xoa dong chi tiet hoa don thanh cong\n";
						return;
					}
					else
					{
						return;
					}
				}
				else if (key == 3)
				{
					int dong;
					cout << "Nhap dong muon sua: ";
					do
					{
						while (!(cin >> dong)) {
							cout << "Loi: Vui long nhap so nguyen!\n";
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Nhap lai dong muon sua: ";
						}
						cin.ignore();

						if (ct.size() < dong)
						{
							cout << "So dong phai nho hon " << ct.size() << ", moi nhap lai so dong:";
						}
					} while (ct.size() < dong);

					Menu menuCTHD("CHINH SUA CHI TIET HOA DON");
					menuCTHD.themChucNang("Sua ma hang");
					menuCTHD.themChucNang("Sua so luong");
					menuCTHD.themChucNang("Sua gia ban");
					menuCTHD.themChucNang("Quay ve menu hoa don ban");
					menuCTHD.renderMenu(false);
					ct[dong - 1].xuat();

					int key = menuCTHD.nhapLuaChon();


					if (key == 1)
					{
						MatHang* matHang = NULL;
						string maHang;
						while (true)
						{
							xuatDSMatHang();
							cout << "Nhap ma hang: ";
							getline(cin, maHang);

							matHang = timKiemMatHangTheoID(maHang);

							if (matHang == NULL)
							{
								cout << "Ma mat hang khong ton tai. Vui long nhap lai.\n";
							}
							else
							{
								dsHDN[i].getChiTiet()[dong - 1].setMaHang(maHang);
								break;
							}
						}
						dsHDN[i].getChiTiet()[dong - 1].setTenHang(matHang->getTenHang());
					}
					else if (key == 2)
					{
						MatHang* matHang = NULL;
						matHang = timKiemMatHangTheoID(dsHDN[i].getChiTiet()[dong - 1].getMaHang());
						int soLuong;

						while (true)
						{
							cout << "Nhap so luong nhap: ";
							while (!(cin >> soLuong)) {
								cout << "Loi: Vui long nhap so nguyen!\n";
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Nhap lai so luong nhap: ";
							}
							cin.ignore();

							if (soLuong < 0)
							{
								cout << "So luong nhap phai lon hon hoac bang 0\n";
							}
							else
							{
								break;
							}
						}

						dsHDN[i].getChiTiet()[dong - 1].setSoLuong(soLuong);
					}
					else if (key == 3)
					{
						double giaNhap;
						cout << "Nhap gia nhap: ";
						while (!(cin >> giaNhap)) {
							cout << "Loi: Vui long nhap so!\n";
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Nhap lai gia nhap: ";
						}
						cin.ignore();

						dsHDN[i].getChiTiet()[dong - 1].setGia(giaNhap);
					}
				}
			}
			else if (key == 5)
			{
				return;
			}
			else
			{
				cout << "Lua chon khong hop le!\n";
			}
			return;
		}
	}
	cout << "Khong tim thay ma hang: " << id << "\n";
}

void CuaHang::timKiemMatHang(const string& keyword)
{
	bool timThay = false;
	xuatTieuDe();
	for (int i = 0; i < dsMH.size(); i++)
	{
		if (dsMH[i].getMaHang().find(keyword) != string::npos ||
			dsMH[i].getTenHang().find(keyword) != string::npos ||
			dsMH[i].getHanDung().find(keyword) != string::npos ||
			dsMH[i].getCongTySX().find(keyword) != string::npos ||
			dsMH[i].getLoaiHang().find(keyword) != string::npos)
		{
			timThay = true;
			dsMH[i].xuat();
		}
	}
	xuatKeNgang();
	if (!timThay)
	{
		cout << "Khong tim thay mat hang nao voi tu khoa: " << keyword << "\n";
	}
}

void CuaHang::timKiemLoaiHang(const string& keyword)
{
	bool timThay = false;
	xuatTieuDe();
	for (int i = 0; i < dsLH.size(); i++)
	{
		if (dsLH[i].getMaLoai().find(keyword) != string::npos ||
			dsLH[i].getTenLoai().find(keyword) != string::npos ||
			dsLH[i].getMoTa().find(keyword) != string::npos)
		{
			timThay = true;
			dsLH[i].xuat();
		}
	}
	xuatKeNgang();
	if (!timThay)
	{
		cout << "Khong tim thay loai hang nao voi tu khoa: " << keyword << "\n";
	}
}

void CuaHang::timKiemHoaDonBan(const string& keyword)
{
	bool timThay = false;
	xuatTieuDe();
	for (int i = 0; i < dsHDB.size(); i++)
	{

		if (dsHDB[i].getMaHD().find(keyword) != string::npos ||
			dsHDB[i].getNgay().find(keyword) != string::npos ||
			dsHDB[i].getTenKhachHang().find(keyword) != string::npos)
		{
			timThay = true;
			dsHDB[i].xuat();
		}
	}
	xuatKeNgang();
	if (!timThay)
	{
		cout << "Khong tim thay hoa don ban nao voi tu khoa: " << keyword << "\n";
	}
}

void CuaHang::timKiemHoaDonNhap(const string& keyword)
{
	bool timThay = false;
	xuatTieuDe();
	for (int i = 0; i < dsHDN.size(); i++)
	{

		if (dsHDN[i].getMaHD().find(keyword) != string::npos ||
			dsHDN[i].getNgay().find(keyword) != string::npos ||
			dsHDN[i].getTenCongTyNhap().find(keyword) != string::npos)
		{
			timThay = true;
			dsHDN[i].xuat();
		}
	}
	xuatKeNgang();
	if (!timThay)
	{
		cout << "Khong tim thay hoa don nhap nao voi tu khoa: " << keyword << "\n";
	}
}

void CuaHang::suaMaHangTrongHDB(const string& maHangCu, const string& maHangMoi)
{
	for (int i = 0; i < dsHDB.size(); i++)
	{
		for (int j = 0; j < dsHDB[i].getChiTiet().size(); j++)
		{
			if (maHangCu == dsHDB[i].getChiTiet()[j].getMaHang())
			{
				dsHDB[i].getChiTiet()[j].setMaHang(maHangMoi);
			}
		}
	}
}

void CuaHang::suaMaHangTrongHDN(const string& maHangCu, const string& maHangMoi)
{
	for (int i = 0; i < dsHDN.size(); i++)
	{

		for (int j = 0; j < dsHDN[i].getChiTiet().size(); j++)
		{
			if (maHangCu == dsHDN[i].getChiTiet()[j].getMaHang())
			{
				dsHDN[i].getChiTiet()[j].setMaHang(maHangMoi);
			}
		}
	}
}

void CuaHang::suaTenHangTrongHDB(const string& maHang, const string& tenHangMoi)
{
	for (int i = 0; i < dsHDB.size(); i++)
	{
		for (int j = 0; j < dsHDB[i].getChiTiet().size(); j++)
		{
			if (maHang == dsHDB[i].getChiTiet()[j].getMaHang())
			{
				dsHDB[i].getChiTiet()[j].setTenHang(tenHangMoi);
			}
		}
	}
}

void CuaHang::suaTenHangTrongHDN(const string& maHang, const string& tenHangMoi)
{
	for (int i = 0; i < dsHDN.size(); i++)
	{
		for (int j = 0; j < dsHDN[i].getChiTiet().size(); j++)
		{
			if (maHang == dsHDN[i].getChiTiet()[j].getMaHang())
			{
				dsHDN[i].getChiTiet()[j].setTenHang(tenHangMoi);
			}
		}
	}
}

void CuaHang::suaLoaiHangTrongMatHang(const string& loaiHangCu, const string& loaiHangMoi)
{
	for (int i = 0; i < dsMH.size(); i++)
	{
		if (dsMH[i].getLoaiHang() == loaiHangCu)
		{
			dsMH[i].setLoaiHang(loaiHangMoi);
		}
	}
}

ChiTietHoaDon CuaHang::themChiTietHoaDonBan()
{
	MatHang* matHang = NULL;
	string maHang, tenHang;
	int soLuong;
	double gia;
	while (true)
	{
		cout << "Nhap ma hang: ";
		getline(cin, maHang);

		matHang = timKiemMatHangTheoID(maHang);
		if (matHang == NULL)
		{
			cout << "Ma mat hang khong ton tai. Vui long nhap lai.\n";
		}
		else
		{
			break;
		}
	}

	tenHang = matHang->getTenHang();

	while (true)
	{
		cout << "Nhap so luong ban: ";
		while (!(cin >> soLuong)) {
			cout << "Loi: Vui long nhap so nguyen!\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Nhap lai so luong ban: ";
		}
		cin.ignore();

		if (soLuong < 0 or soLuong > matHang->getSoLuong())
		{
			cout << "So luong ban phai lon hon hoac bang 0 va nho hon hoac bang so luong co trong mat hang\n";
		}
		else
		{
			break;
		}
	}

	cout << "Nhap gia ban: ";
	while (!(cin >> gia)) {
		cout << "Loi: Vui long nhap so!\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Nhap lai gia ban: ";
	}
	cin.ignore();

	matHang->setSoLuong(matHang->getSoLuong() - soLuong);
	ChiTietHoaDon cthd(maHang, tenHang, soLuong, gia);
	return cthd;
}

ChiTietHoaDon CuaHang::themChiTietHoaDonNhap()
{
	MatHang* matHang = NULL;
	string maHang,tenHang;
	int soLuong;
	double gia;
	while (true)
	{
		cout << "Nhap ma hang: ";
		getline(cin, maHang);

		matHang = timKiemMatHangTheoID(maHang);
		if (matHang == NULL)
		{
			cout << "Ma mat hang khong ton tai. Vui long nhap lai.\n";
		}
		else
		{
			break;
		}
	}

	tenHang = matHang->getTenHang();

	while (true)
	{
		cout << "Nhap so luong ban: ";
		while (!(cin >> soLuong)) {
			cout << "Loi: Vui long nhap so nguyen!\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Nhap lai so luong ban: ";
		}
		cin.ignore();

		if (soLuong < 0 or soLuong > matHang->getSoLuong())
		{
			cout << "So luong ban phai lon hon hoac bang 0 va nho hon hoac bang so luong co trong mat hang\n";
		}
		else
		{
			break;
		}
	}

	cout << "Nhap gia ban: ";
	while (!(cin >> gia)) {
		cout << "Loi: Vui long nhap so!\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Nhap lai gia ban: ";
	}
	cin.ignore();

	matHang->setSoLuong(matHang->getSoLuong() + soLuong);
	ChiTietHoaDon cthd(maHang, tenHang, soLuong, gia);
	return cthd;
}

bool CuaHang::tonTaiLoaiHang(const string& id)
{
	for (int i = 0; i < dsLH.size(); i++)
	{
		if (dsLH[i].getMaLoai() == id)
		{
			return true;
		}
	}
	return false;
}

bool CuaHang::tonTaiMatHang(const string& id)
{
	for (int i = 0; i < dsMH.size(); i++)
	{
		if (dsMH[i].getMaHang() == id)
		{
			return true;
		}
	}
	return false;
}

bool CuaHang::tonTaiMatHangTrongHDB(const string& id)
{
	for (int i = 0; i < dsHDB.size(); i++)
	{
		for (int j = 0; j < dsHDB[i].getChiTiet().size(); j++)
		{
			if (id == dsHDB[i].getChiTiet()[j].getMaHang())
			{
				return true;
			}
		}
	}
	return false;
}

bool CuaHang::tonTaiMatHangTrongHDN(const string& id)
{
	for (int i = 0; i < dsHDN.size(); i++)
	{
		for (int j = 0; j < dsHDN[i].getChiTiet().size(); j++)
		{
			if (id == dsHDN[i].getChiTiet()[j].getMaHang())
			{
				return true;
			}
		}
	}
	return false;
}

MatHang* CuaHang::timKiemMatHangTheoID(const string& id)
{
	for (int i = 0; i < dsMH.size(); i++)
	{
		if (dsMH[i].getMaHang() == id)
		{
			return &dsMH[i];
		}
	}
	return NULL;
}

LoaiHang* CuaHang::timKiemLoaiHangTheoID(const string& id)
{
	for (int i = 0; i < dsLH.size(); i++)
	{
		if (dsLH[i].getMaLoai() == id)
		{
			return &dsLH[i];
		}
	}
	return NULL;
}

HoaDonBan* CuaHang::timKiemHoaDonBanTheoID(const string& id)
{
	for (int i = 0; i < dsHDB.size(); i++)
	{
		if (dsHDB[i].getMaHD() == id)
		{
			return &dsHDB[i];
		}
	}
	return NULL;
}

HoaDonNhap* CuaHang::timKiemHoaDonNhapTheoID(const string& id)
{
	for (int i = 0; i < dsHDN.size(); i++)
	{
		if (dsHDN[i].getMaHD() == id)
		{
			return &dsHDN[i];
		}
	}
	return NULL;
}

void CuaHang::thongKeHangConLai()
{
	cout << "Thong ke hang con lai\n";
	tieuDe = { "Ma hang", "Ten hang", "Han dung","So luong","Don gia", "Cong ty", "Nam SX", "Loai hang" };
	doRongCot = { 10,30,10,10,20,30,10,30 };
	xuatTieuDe();
	for (int i = 0; i < dsMH.size(); i++)
	{
		if (dsMH[i].getSoLuong() > 0)
		{
			dsMH[i].xuat();
		}
	}
	xuatKeNgang();
}

void CuaHang::thongKeHangHetHan()
{
	cout << "Thong ke hang het han\n";
	string ngaystr;
	do
	{
		cout << "Nhap ngay hom nay (dd/mm/yyyy): ";
		getline(cin, ngaystr);
		NgayThangNam ngay(ngaystr);
		if (ngay.ngayHopLe())
		{
			ngaystr = ngay.xuatChuoi();
			break;
		}
		else
		{
			cout << "Ngay thang nam chua hop le\n";
		}
	} while (true);

	tieuDe = { "Ma hang", "Ten hang", "Han dung","So luong","Don gia", "Cong ty", "Nam SX", "Loai hang" };
	doRongCot = { 10,30,10,10,20,30,10,30 };
	xuatTieuDe();
	for (int i = 0; i < dsMH.size(); i++)
	{
		NgayThangNam ngayHT(ngaystr);
		NgayThangNam ngayMH(dsMH[i].getHanDung());

		if (ngayMH.khoangCachNgay(ngayHT) < 0)
		{
			dsMH[i].xuat();
		}
	}
	xuatKeNgang();
}

void CuaHang::docFileMH() 
{
	ifstream in("data\\mathang.txt");
	if (!in.is_open())
	{
		cout << "Khong the mo file de doc!\n";
		return;
	}

	string line;
	while (getline(in, line)) {
		stringstream ss(line);
		string ma, ten, han, cty, maloai;
		int so, nam;
		double don;
		getline(ss, ma, '|');
		getline(ss, ten, '|');
		getline(ss, han, '|');
		string sostr;
		getline(ss, sostr, '|');
		so = stoi(sostr);
		string donstr;
		getline(ss, donstr, '|');
		don = stod(donstr);
		getline(ss, cty, '|');
		string namStr;
		getline(ss, namStr, '|');
		nam = stoi(namStr);
		getline(ss, maloai, '|');

		MatHang mh(ma, ten, han, so, don, cty, nam, maloai);
		dsMH.push_back(mh);
	}

	cout << "Doc file mat hang thanh cong\n";
	in.close();
}

void CuaHang::docFileLH()
{
	ifstream in("data\\loaihang.txt");
	if (!in.is_open())
	{
		cout << "Khong the mo file de doc!\n";
		return;
	}

	string line;
	while (getline(in, line)) {
		stringstream ss(line);
		string ma, ten, moTa;

		getline(ss, ma, '|');
		getline(ss, ten, '|');
		getline(ss, moTa, '|');

		LoaiHang lh(ma, ten, moTa);
		dsLH.push_back(lh);
	}

	cout << "Doc file loai hang thanh cong\n";
	in.close();
}

void CuaHang::docFileHDB()
{
	ifstream in("data\\hoadonban.txt");
	if (!in.is_open())
	{
		cout << "Khong the mo file de doc!\n";
		return;
	}

	string line;
	while (getline(in, line)) {
		stringstream ss(line);
		string ma, ngay , ten;
		vector<ChiTietHoaDon> dscthd;
		int n;
		string nstr;

		getline(ss, ma, '|');
		getline(ss, ngay, '|');
		getline(ss, ten, '|');
		getline(ss, nstr, '|');
		n = stoi(nstr);
		for (int i = 0; i < n; i++)
		{
			getline(in, line);
			stringstream ss(line);

			string maHang, tenHang;
			int soLuong;
			double giaBan;

			getline(ss, maHang, '|');
			getline(ss, tenHang, '|');
			string slstr;
			getline(ss, slstr, '|');
			soLuong = stoi(slstr);

			string gbstr;
			getline(ss, gbstr, '|');
			giaBan = stod(gbstr);
			ChiTietHoaDon cthd(maHang, tenHang, soLuong, giaBan);
			dscthd.push_back(cthd);
		}

		HoaDonBan hdb(ma, ngay, ten, dscthd);
		dsHDB.push_back(hdb);
	}

	cout << "Doc file hoa don ban thanh cong\n";
	in.close();
}

void CuaHang::docFileHDN()
{
	ifstream in("data\\hoadonnhap.txt");
	if (!in.is_open())
	{
		cout << "Khong the mo file de doc!\n";
		return;
	}

	string line;
	while (getline(in, line)) {
		stringstream ss(line);
		string ma, ngay, ten;
		vector<ChiTietHoaDon> dscthd;
		int n;
		string nstr;

		getline(ss, ma, '|');
		getline(ss, ngay, '|');
		getline(ss, ten, '|');
		getline(ss, nstr, '|');
		n = stoi(nstr);
		for (int i = 0; i < n; i++)
		{
			getline(in, line);
			stringstream ss(line);

			string maHang, tenHang;
			int soLuong;
			double giaNhap;

			getline(ss, maHang, '|');
			getline(ss, tenHang, '|');
			string slstr;
			getline(ss, slstr, '|');
			soLuong = stoi(slstr);

			string gbstr;
			getline(ss, gbstr, '|');
			giaNhap = stod(gbstr);
			ChiTietHoaDon cthd(maHang, tenHang, soLuong, giaNhap);
			dscthd.push_back(cthd);
		}

		HoaDonNhap hdn(ma, ngay, ten, dscthd);
		dsHDN.push_back(hdn);
	}

	cout << "Doc file hoa don nhap thanh cong\n";
	in.close();
}

void CuaHang::ghiFileMH()
{
	ofstream out("data\\mathang.txt");
	if (!out.is_open())
	{
		cout << "Khong the mo file de ghi!\n";
		return;
	}

	for (int i = 0; i < dsMH.size(); i++)
	{
		out << dsMH[i].getMaHang() << "|"
			<< dsMH[i].getTenHang() << "|"
			<< dsMH[i].getHanDung() << "|"
			<< dsMH[i].getSoLuong() << "|"
			<< dsMH[i].getDonGia() << "|"
			<< dsMH[i].getCongTySX() << "|"
			<< dsMH[i].getNamSX() << "|"
			<< dsMH[i].getLoaiHang() << "\n";
	}

	cout << "Ghi file mat hang thanh cong\n";
	out.close();
}

void CuaHang::ghiFileLH()
{
	ofstream out("data\\loaihang.txt");
	if (!out.is_open())
	{
		cout << "Khong the mo file de doc!\n";
		return;
	}

	for (int i = 0; i < dsLH.size(); i++)
	{
		out << dsLH[i].getMaLoai() << "|"
			<< dsLH[i].getTenLoai() << "|"
			<< dsLH[i].getMoTa() << "\n";
	}

	cout << "Ghi file loai hang thanh cong\n";
	out.close();
}

void CuaHang::ghiFileHDB()
{
	ofstream out("data\\hoadonban.txt");
	if (!out.is_open())
	{
		cout << "Khong the mo file de ghi!\n";
		return;
	}

	vector<ChiTietHoaDon> dscthd;
	for (int i = 0; i < dsHDB.size(); i++)
	{
		dscthd = dsHDB[i].getChiTiet();
		out << dsHDB[i].getMaHD() << "|"
			<< dsHDB[i].getNgay() << "|"
			<< dsHDB[i].getTenKhachHang() << "|"
			<< dscthd.size() << "\n";

		for (int i = 0; i < dscthd.size(); i++)
		{
			out << dscthd[i].getMaHang() << "|"
				<< dscthd[i].getTenHang() << "|"
				<< dscthd[i].getSoLuong() << "|"
				<< dscthd[i].getGia() << '\n';
		}
	}

	cout << "Ghi file hoa don ban thanh cong\n";
	out.close();
}

void CuaHang::ghiFileHDN()
{
	ofstream out("data\\hoadonnhap.txt");
	if (!out.is_open())
	{
		cout << "Khong the mo file de ghi!\n";
		return;
	}

	vector<ChiTietHoaDon> dscthd;
	for (int i = 0; i < dsHDN.size(); i++)
	{
		dscthd = dsHDN[i].getChiTiet();
		out << dsHDN[i].getMaHD() << "|"
			<< dsHDN[i].getNgay() << "|"
			<< dsHDN[i].getTenCongTyNhap() << "|"
			<< dscthd.size() << "\n";

		for (int i = 0; i < dscthd.size(); i++)
		{
			out << dscthd[i].getMaHang() << "|"
				<< dscthd[i].getTenHang() << "|"
				<< dscthd[i].getSoLuong() << "|"
				<< dscthd[i].getGia() << '\n';
		}
	}

	cout << "Ghi file hoa don nhap thanh cong\n";
	out.close();
}

CuaHang::~CuaHang()
{
	ghiFile();
}
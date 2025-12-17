#include "Menu.h"
#include <iostream>
#include <cstdlib>

Menu::Menu(string td)
{
    tieuDe = td;
}

void Menu::renderMenu(bool thoat)
{
    system("cls");
    const int width = 50;

    // In tiêu đề
    cout << "+" << string(width - 2, '-') << "+\n";
    cout << "|" << string((width - 2 - tieuDe.length()) / 2, ' ')
        << tieuDe
        << string((width - 2 - tieuDe.length() + 1) / 2, ' ') << "|\n";
    cout << "+" << string(width - 2, '-') << "+\n";

    // In các lựa chọn
    for (int i = 0; i < chucNang.size(); i++) {
        string dong = to_string(i + 1) + ". " + chucNang[i];
        cout << "| " << dong << string(width - 3 - dong.length(), ' ') << "|\n";
    }

    if (thoat)
    {
        string dong = "0. Thoat chuong trinh";
        cout << "| " << dong << string(width - 3 - dong.length(), ' ') << "|\n";
    }

    cout << "+" << string(width - 2, '-') << "+\n";
}

void Menu::themChucNang(const string cn)
{
    chucNang.push_back(cn);
}

int Menu::nhapLuaChon()
{
    string input;
    int key;

    while (true)
    {
        cout << "Nhap lua chon: ";
        cin >> input;
        getchar();

        bool hople = true;
        for (int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                hople = false;
                break;
            }
        }

        if (hople)
        {
            key = stoi(input);
            return key;
        }
        else
        {
            cout << "Lua chon khong hop le. Vui long nhap so.\n";
        }
    }
}

int Menu::XuLyThoat()
{
    char flag;
    printf("Ban co muon thoat khong?[y/n]: ");
    cin >> flag;
    if (flag == 'y' || flag == 'Y')	return 0;
    return 1;
}
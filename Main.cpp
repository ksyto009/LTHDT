#include "CuaHang.h"

int main()
{
	CuaHang* ch;
	ch = CuaHang::getInstance();

	int flag = 1;
	do
	{
		flag = ch->menuChinh();
	} while (flag == 1);

	delete ch;
	return 0;
}
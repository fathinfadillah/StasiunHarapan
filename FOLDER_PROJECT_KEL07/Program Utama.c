#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<conio.h>
#include<time.h>
#include"getlib.h"
#include"GOTOXY.h"
#include"ADMIN.h"
#include"MEMBER.h"
#include"KASIR.h"
#include"MANAGER.h"
#include"Login.h"


main()
{
	fullscreen();
	pembuka();getch();
	MenuLogin();getch();
}

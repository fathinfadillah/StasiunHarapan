void MenuLogin()
{
	int menu;
	system("cls");
	DesainUtama();
	gotoxy(10, 21), printf("MASUK SEBAGAI");
	gotoxy(7, 23),	printf("1. ADMIN");
	gotoxy(7, 24),	printf("2. KASIR");
	gotoxy(7, 25),	printf("3. MANAGER");
	gotoxy(7, 26),	printf("4. Keluar Program");
	gotoxy(7, 28),	printf("Pilih Menu : "); getnum(&menu,1);
	switch(menu)
	{
		case 1: 
				{
					LoginAdmin(); break;
				}
		case 2:
				{
					LoginKasir(); break;
				}
		case 3: 
				{
					LoginManager(); break;
				}
		case 4: 
				{
					penutup(); exit(0); break;
				}
		default : MenuLogin(); break;
	}
}

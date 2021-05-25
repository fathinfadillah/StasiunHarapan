
void MenuManager();
void sortdate();

void LoginManager()
{
	//DEKLARASI
	char username[10];
	char pass[10];
	
	//ALGORYTHM
	
	system("cls");
	KotakLogin();
	gotoxy(70, 25), printf("Masukan Username : "); 
	gotoxy(70, 27), printf("Masukan Password : ");
	gotoxy(90, 25), getteks(username,10);
	gotoxy(90, 27), getpass(pass,10);
	if(strcmp(username,"manager")==0 && strcmp(pass,"manager")==0) 
	{
		MessageBox(NULL,"Login berhasil","Login Manager",MB_ICONINFORMATION | MB_OK);
		MenuManager();
	} else
	{
		MessageBox(NULL,"Username/Password Salah","Login Manager",MB_ICONSTOP | MB_OK);
		MenuLogin();
	}
}

void MenuManager()
{
	int PilMenu;
	int jawab;
	
	system ("cls");
	DesainUtama();
	gotoxy(10, 21), printf("MENU MANAGER");
	gotoxy(6, 23),  printf("1. Riwayat Penjualan");
	gotoxy(6, 24),	printf("2. Laporan Keuangan");
	gotoxy(6, 25),	printf("3. Logout");
	gotoxy(6, 26),	printf("4. Keluar Program");
	gotoxy(6, 28),	printf("Pilihan Menu : "); getnum(&PilMenu,1);
	switch (PilMenu)
	{
		case 1 : laporan();
				 MenuManager();
				 break;
		case 2 : sortdate();
				 break;
		case 3 : MenuLogin(); break;
		case 4 : penutup(); exit(0); break;
		default : MenuManager(); break;
	}
}

//laporan

void laporan()
{
	tabeltransaksi();
	int i;
	char harga[50];
		
	Laporan = fopen ("laporan.dat","rb");
	fread(&pesan,sizeof(pesan),1,Laporan);
	
	for(i=109;i<=121;i++)
	{
		gotoxy(i,16), printf("%c", 205);
		gotoxy(i,18), printf("%c", 205);
	}
	
	gotoxy (35,17), printf("Tanggal Transaksi");
	gotoxy (55,17), printf("ID KA");
	gotoxy (65,17), printf("Nama Kereta Api");
	gotoxy (85,17), printf("Jumlah");
	gotoxy (94,17), printf("Harga");
	gotoxy (109,17), printf("Total");
	jumlah = 0;
	i=19;
	while (!feof(Laporan))
	{
		gotoxy(38,i),	printf ("%d/%d/%d",pesan.tgl,pesan.bulan,pesan.tahun);
		gotoxy (55,i),	printf ("KA%d",pesan.id);
		gotoxy (65,i),	printf ("%s",pesan.nama);
		gotoxy (85,i),	printf ("%d",pesan.jumlah);
		gotoxy (94,i),	rupiah(pesan.harga,harga);printf ("Rp. %s",harga);
		gotoxy (109,i),	rupiah(pesan.store,harga);printf ("Rp. %s",harga);
		jumlah = jumlah + pesan.store;
	 	fread(&pesan,sizeof(pesan),1,Laporan);
	 	i++;
	}
	gotoxy (35,i+2), printf("Total Pendapatan Stasiun adalah  : ");
	gotoxy (109,i+2), rupiah(jumlah,harga);printf("Rp. %s",harga);
	fclose(Laporan);
	getch();
}



void sortdate()
{
	int nomor;
	
	system ("cls");
	DesainUtama();
	gotoxy(13, 20), printf("SORTING");
	gotoxy(6, 22), printf("1. Sorting Tanggal");
	gotoxy(6, 23), printf("2. Sorting Bulan");
	gotoxy(6, 24), printf("3. Sorting Tahun");
	gotoxy(6, 25), printf("4. Menu Manager");
	gotoxy(6, 26), printf("5. Logout");
	gotoxy(6, 27), printf("6. Keluar Program");
	gotoxy(6, 29), printf("Pilihan Menu : ");scanf("%d",&nomor);
	
	switch(nomor)
	{
		case 1 : 
				{
				 system("cls");
				 DesainUtama();
				 hari();		
				 sortdate();
				 break;
				}
		
				 
		case 2 : 
				{
				 system("cls");
				 DesainUtama();
				 bulan();
				 sortdate();
				 break;
				}
				 
		case 3 : 
				{
				 system("cls");
				 DesainUtama();
				 tahun();
				 sortdate();
				 break;
				}
				 
		case 4 :
				 {
				MenuManager(); 
				break;
				}
		case 5 :
				{
		 		MenuLogin(); break;
		 		}
		case 6 :
				{
		 		penutup(); exit(0); break;
		 		}
		default : sortdate(); break;
	}
}



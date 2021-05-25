
//transaksi

typedef struct
{
	int Kodetrx;
	int pesanan[225];
	int keranjang;
	int jumlah;
	int store;
	int id;
	char nama[100];
	int harga;
	char rp[25];
	int tgl;
	int bulan;
	int tahun;
}transaksi;

transaksi pesan;

FILE *ArsKeretaApi;
FILE *temp;
FILE *Diskon;
FILE *Laporan;

void MenuKasir();
void mesenKeretaApi();
void StrukPembelian();
void bayar();
void Member();
void rupiah();
void getRp();


int jumlah;
bool found;


void LoginKasir()
{
	//DEKLARASI
	FILE* flkasir;
	
	bool found;
	
	typedef struct {
		char user[40];
		char password[40];
	}lgn;
	
	lgn login; 
	
	//ALGORYTHM
	system("cls");
	KotakLogin();
	flkasir = fopen ("flkasir.dat", "rb");
	
	gotoxy(70, 25), printf("Masukan Username : "); 
	gotoxy(70, 27), printf("Masukan Password : ");
	gotoxy(90, 25), getteks(login.user,10);
	gotoxy(90, 27), getpass(login.password,10);
	
	while((found==0) && !feof(flkasir))
	{
		fread(&kasir,sizeof(kasir),1,flkasir);
		if (strcmp(login.user,kasir.Username)==0 && strcmp(login.password, kasir.password)==0)
		{
			found = 1;
			break;
		}
	}
	/* if (found == 1) */
	if (found)
	{
		MessageBox(NULL,"Login berhasil","Login Kasir",MB_ICONINFORMATION | MB_OK);
		getch(); MenuKasir();
	}
	else
	{
		MessageBox(NULL,"Username/Password Salah","Login Kasir",MB_ICONSTOP | MB_OK);
		getch(); MenuLogin();
	}
}


void MenuKasir()
{
	int PilMenu;
	char konfirmasi;
	
	setColor(07);
	system ("cls");
	DesainUtama();
	gotoxy(11, 21), printf("MENU KASIR");
	gotoxy(7,23),	printf("1.Membuat Transaksi");
	gotoxy(7,24),	printf("2.Pembayaran");
	gotoxy(7,25),	printf("3.Data Member");
	gotoxy(7,26),	printf("4.Logout"); //keluar akun
	gotoxy(7,27),	printf("5.Keluar Program"); //keluar program
	gotoxy(7,29),	printf("Pilihan anda : "); getnum(&PilMenu,1);
	switch(PilMenu)
	{
		case 1 :
				{
				
					 
				 	//system ("cls");
				 	DesainUtama();
				 	LihatDataKeretaApi();			// cetak daftar KeretaApi
				 	mesenKeretaApi();				//transaksi
				 	
	
					break;
				}
		case 2 :
				{
					 //system ("cls");
					 DesainUtama();
					 StrukPembelian();
					 bayar();
					 	
					 getch(); 
					 MenuKasir();
					 break;
				}
		case 3 : MenuMember(); break;		 
		case 4 : MenuLogin(); break;
		case 5 : penutup(); exit(0); break;
		default : MenuKasir(); break;
	}
}


void mesenKeretaApi()
{
	FILE *Transaksi;

	int id;
	char ans;
	char harga [50];
	
	ArsKeretaApi 	= fopen("arska.dat","rb");
	temp 		= fopen("temp.dat","wb");
	
	gotoxy(126,17), printf ("Masukan ID Kereta Api : KA");
	getnum(&id,3);
	
	found = false;
	
	Transaksi = fopen("transaksi.dat","rb");
	
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	
	if (Transaksi != NULL)
	{
		while((!feof(Transaksi)&&(!found)))
		{
			fread(&pesan,sizeof(pesan),1,Transaksi);
			if (id == pesan.id)
			{
				found = true;
			}
			else
			{
				fwrite(&pesan,sizeof(pesan),1,temp);
			}
		}
	
		if (found == true)
		{
			gotoxy(126,19), printf ("ID Kereta Api\t: KA%d",pesan.id);
			gotoxy(126,20), printf ("Nama Kereta Api\t: %s",pesan.nama);
			gotoxy(126,21), printf ("Jumlah Kereta Api\t: %d",pesan.jumlah);
			gotoxy(126,22),rupiah(pesan.harga,harga); printf ("Harga Kereta Api\t: Rp %s",harga);
			gotoxy(126,24), rupiah(pesan.store,harga); printf ("Harga Total Kereta Api : %s",harga);
		
			
			gotoxy(126,27), printf("Kereta Api sudah ada dalam keranjang");
			gotoxy(126,28), printf("Anda ingin menggantinya (y/t) ? "); ans=getch();
			if (ans == 'y'||ans == 'Y')
			{
				int nomor;
				int jmlh;
				
				gotoxy(126,29), printf("1.Mengganti Jumlah");
				gotoxy(126,30), printf("2.Menghapus Kereta Api");
				gotoxy(126,31), printf("Jawaban : "); getnum(&nomor,1);
				switch (nomor)
				{
					case 1 : gotoxy(126,33), printf("Masukan jumlah baru : "); scanf("%d",&jmlh);
							 pesan.jumlah = jmlh;
							 pesan.store = pesan.harga * pesan.jumlah;
							 fwrite(&pesan,sizeof(pesan),1,temp);
							 break;
							 
					case 2 : gotoxy(126,33), printf("Loading . . "); Sleep(1500); 
							 gotoxy(126,34), printf("Kereta Api dikembalikan"); getch();
							 MenuKasir(); break;
				}
				
				fread(&pesan,sizeof(pesan),1,Transaksi);
				while (!feof(Transaksi))
				{
					fwrite(&pesan,sizeof(pesan),1,temp);
					fread(&pesan,sizeof(pesan),1,Transaksi);
				}
				fclose(Transaksi);
				fclose(temp);
	
				Transaksi = fopen ("transaksi.dat","wb");
				temp = fopen ("temp.dat","rb");
				
				fread(&pesan,sizeof(pesan),1,temp);
				while(!feof(temp))
				{
					fwrite(&pesan,sizeof(pesan),1,Transaksi);
					fread(&pesan,sizeof(pesan),1,temp);
				}
				fclose(temp);
				fclose(Transaksi);
				MenuKasir();
			}
			else
			{
				MenuKasir();
				fclose(Transaksi);
				fclose(ArsKeretaApi);
				fclose(temp);
			}
		}
		else
		{
		
			fclose(Transaksi);
			fclose(temp);
		}
	}
	
	//KeretaApi yang belum ada dalam keranjang
	temp = fopen ("temp.dat","wb");
	while ((!feof(ArsKeretaApi))&&(found==false))
	{
		fread (&KeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);
		if (KeretaApi.IDKeretaApi==id)
		{
			found = true;
		}
		else
		{
			fwrite(&KeretaApi,sizeof(KeretaApi),1,temp);
		}
	}
	
	if (found == true)
	{
		Transaksi = fopen("transaksi.dat","a+b");
		gotoxy(126,19), printf ("ID Kereta Api\t: KA%d",KeretaApi.IDKeretaApi);
		gotoxy(126,20), printf ("Nama Kereta Api\t: %s",KeretaApi.Nama);
	
		gotoxy(126,23), printf ("Stok Kereta Api\t: %d",KeretaApi.Stock);
		gotoxy(126,24),rupiah(KeretaApi.Harga,harga); printf ("Harga Kereta Api\t: Rp %s",harga);

		//nomor keranjang
		while (!feof(Transaksi))
		{
			fflush(stdin);
			fread(&pesan,sizeof(pesan),1,Transaksi);
		}
	
		pesan.keranjang++;
		
		gotoxy(126,28), printf ("Jumlah Kereta Api : ");scanf ("%d",&pesan.jumlah);
		if (pesan.jumlah > KeretaApi.Stock )
		{
			gotoxy(126,30), printf("Jumlah Kereta Api tidak mencukupi");
			getch(); MenuKasir();
		}
		else if (pesan.jumlah == 0)
		{
			gotoxy(126,30), printf("Maaf tidak bisa memasukan 0");
			getch(); MenuKasir();
		}

		pesan.tgl 	= str_t.wDay;
		pesan.bulan = str_t.wMonth;
		pesan.tahun = str_t.wYear;
		KeretaApi.Stock = KeretaApi.Stock - pesan.jumlah;
		pesan.store = pesan.jumlah * KeretaApi.Harga;
		pesan.harga = KeretaApi.Harga;
		pesan.id 	= KeretaApi.IDKeretaApi;
	
		strcpy(pesan.nama,KeretaApi.Nama);		fflush(stdin);
		
		fwrite(&pesan,sizeof(pesan),1,Transaksi);
		fclose(Transaksi);
	
		fwrite(&KeretaApi,sizeof(KeretaApi),1,temp);
				
		fread(&KeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);
		while(!feof(ArsKeretaApi))
		{
			fwrite(&KeretaApi,sizeof(KeretaApi),1,temp);
			fread(&KeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);
		}
		fclose(ArsKeretaApi);
		fclose(temp);
				
		temp = fopen("temp.dat","rb");
		ArsKeretaApi= fopen("arska.dat","wb");
		fread(&KeretaApi,sizeof(KeretaApi),1,temp);
		while(!feof(temp))
		{
			fwrite(&KeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);
			fread(&KeretaApi,sizeof(KeretaApi),1,temp);
		}
		fclose(ArsKeretaApi);
		fclose(temp);
		MenuKasir();
	}
	else 
	{
		gotoxy(126,19), printf ("Data yang anda masukan tidak ada");
		gotoxy(128,19),getch();
		fclose(ArsKeretaApi);
		fclose(temp);
		MenuKasir();
	}
}

void StrukPembelian()
{
	FILE *Transaksi;
	int batas;
	int i;
	char harga[50];

	Transaksi = fopen ("transaksi.dat","rb");
	fread(&pesan,sizeof(pesan),1,Transaksi);
	pesan.Kodetrx=1;
	
	while(!feof(Transaksi))
	{
		fread(&pesan,sizeof(pesan),1,Transaksi);
	}
	batas = pesan.Kodetrx + 1;
	
	fclose(Transaksi);
	
	Transaksi = fopen ("transaksi.dat","r");
	fread(&pesan,sizeof(pesan),1,Transaksi);
	if (Transaksi == NULL)
	{
		gotoxy(35,17), printf ("Tidak Ada Kereta Api Dalam Keranjang ");
		getch();
		mesenKeretaApi();
	}
	
	
	tabelpembayaran();
	gotoxy (35,17), printf("ID");
	gotoxy (45,17), printf("Nama Kereta Api");
	gotoxy (65,17), printf("Jumlah");
	gotoxy (76,17), printf("Nominal");
		
	i=19;
	while (!feof(Transaksi))
	{
		gotoxy (35,i), printf ("KA%d",pesan.id);
		gotoxy (45,i), printf ("%s",pesan.nama);
		gotoxy (65,i), printf ("%d",pesan.jumlah);
		gotoxy (76,i),rupiah(pesan.store,harga); printf ("Rp. %s",harga);
		fread(&pesan,sizeof(pesan),1,Transaksi);
		i++;
	}

	fclose(Transaksi);
	
	Transaksi = fopen("transaksi.dat","rb");
	jumlah = 0;
	fread(&pesan,sizeof(pesan),1,Transaksi);
	
	while (!feof(Transaksi))
	{
		jumlah = jumlah + pesan.store;
		pesan.Kodetrx = batas;
		fwrite(&pesan,sizeof(pesan),1,Transaksi);
		fread(&pesan,sizeof(pesan),1,Transaksi);
	}
	
	fclose (Transaksi);
	
}
void bayar()
{
	FILE *Laporan;
	FILE *Transaksi;
	FILE *Diskon;
	FILE *temp;
	
	time_t jam;
	time(&jam);
	
	char ans,ans1;
	int diskon;
	char harga[50];
	
	int uang,kembalian = 0,del;
	int p,i; //untuk tampilan garis pinggir

	Transaksi = fopen("transaksi.dat","rb");
	Diskon = fopen("diskon.dat","wb");
	temp = fopen ("temp.dat","wb");
	fread(&pesan,sizeof(pesan),1,Transaksi);
	
	while(!feof(Transaksi))
	{
		fwrite(&pesan,sizeof(pesan),1,Diskon);
		fread(&pesan,sizeof(pesan),1,Transaksi);
	}
	fclose(Diskon);
	fclose(Transaksi);
	gotoxy(118,18), printf ("Menlanjutkan Pembayaran ? <y/t> "); 
	gotoxy(118,19),printf("Masukan jawaban : ");ans=getch();
	if (ans == 'y'|| ans == 'Y')
	{
	
	gotoxy(118,18), printf ("Apakah anda memliki account member ? <y/t> "); 
	gotoxy(118,19),printf("Masukan jawaban : ");ans=getch();
	if (ans == 'y'|| ans == 'Y')
	{
		Member();
		gotoxy(118,22), printf("Mendapatkan diskon 10/100 per-item");
	}
	
	Transaksi = fopen("transaksi.dat","rb");
	Laporan = fopen ("laporan.dat","a+b");
	fread(&pesan,sizeof(pesan),1,Transaksi);
	
	while(!feof(Transaksi))
	{
		fwrite(&pesan,sizeof(pesan),1,Laporan);
		fread(&pesan,sizeof(pesan),1,Transaksi);
	}
	fclose(Laporan);
	fclose(Transaksi);
	
	Transaksi = fopen("transaksi.dat","rb");
	
	jumlah = 0;
	fread(&pesan,sizeof(pesan),1,Transaksi);
	while (!feof(Transaksi))
	{
		jumlah = jumlah + pesan.store;
		fread(&pesan,sizeof(pesan),1,Transaksi);
	}
	gotoxy(118,23),rupiah(jumlah,harga);printf("Total Harga \t  : Rp. %s", harga);
	
	gotoxy(118,25), printf("Masukan jumlah uang : Rp. "); scanf("%d",&uang);
	
	if (uang >= jumlah)
	{
		kembalian = uang - jumlah;
		fclose(Transaksi);
	

	fclose(Laporan);
	fclose(Transaksi);
	
	getch();
	
	system("cls");
	
	//print struk
	Transaksi = fopen ("transaksi.dat","rb");
	fread(&pesan,sizeof(pesan),1,Transaksi);
	
	//tampilan struk 
	
	//garis atas
	for (i=57; i<=112; i++)
	{
		gotoxy(i,14), printf("%c",219);
	}
	
	gotoxy(81,16), printf("Stasiun Harapan");
	
	i=19;
	while (!feof(Transaksi))
	{
		gotoxy (61,i), printf ("%s",pesan.nama);
		gotoxy (88,i), printf ("%d",pesan.jumlah);
		gotoxy (98,i),rupiah(pesan.store,harga); printf ("Rp. %s",harga);
		
		fread(&pesan,sizeof(pesan),1,Transaksi);
		i++;
	}
	gotoxy(61,i+2), printf ("Harga Total");
	gotoxy(61,i+3), printf ("Bayar");
	gotoxy(61,i+4), printf ("Kembalian");

	gotoxy(98,i+2), rupiah(jumlah,harga);printf ("Rp. %s", harga);
	gotoxy(98,i+3), rupiah(uang,harga);printf ("Rp. %s", harga);
	gotoxy(98,i+4), rupiah(kembalian,harga);printf ("Rp. %s", harga);

	//samping kanan dan kiri
	for (p=15;p<=i+5;p++)
	{
		gotoxy(57,p), printf("%c", 219);
		gotoxy(112,p), printf("%c", 219);
	}
	//garis bawah
	i=i+6;
	for(p=57;p<=112;p++)
	{
		gotoxy(p,i), printf("%c", 219);
	}
//	fclose(Transaksi);
		
	//bersihkan keranjang
	pesan.keranjang = 0;
	
	fread(&pesan,sizeof(pesan),1,Transaksi);
			while (!feof(Transaksi))
			{
				fwrite(&pesan,sizeof(pesan),1,temp);
				fread(&pesan,sizeof(pesan),1,Transaksi);
			}
			fclose(Transaksi);
			fclose(temp);
			
			temp =  fopen ("temp.dat", "rb");
			Transaksi = fopen ("Transaksi.dat", "wb");
			
			fread(&pesan,sizeof(pesan),1,temp);
			while(!feof(temp))
			{
				fwrite(&pesan,sizeof(pesan),1,Transaksi);
				fread(&pesan,sizeof(pesan),1,temp);
			}
			fclose(Transaksi);
			fclose(temp);

	}
		else 
	{
		gotoxy(118,27), printf("Uang anda tidak mencukupi !");
		fclose(Transaksi);
		MenuKasir();
	}
}
else
{
	MenuKasir();
}
}

void Member()
{
	FILE*Transaksi;
	int id;
	
	gotoxy(118,21),printf ("Masukan id member anda : MBR");scanf("%d",&id);

	datambr = fopen("datambr.dat","rb");
	temp = fopen("temp.dat","wb");
	while((!feof(datambr))&&(!found))
	{	
		fread(&mbr,sizeof(mbr),1,datambr);
		if (id==mbr.id)
		{
			found = true;
		}
		else
		{
			fwrite(&mbr,sizeof(mbr),1,temp);
		}
	}
	
	if (found == true)
	{
		Diskon = fopen("diskon.dat","rb");
		Transaksi = fopen("transaksi.dat","wb");
		fread(&pesan,sizeof(pesan),1,Diskon);
		while (!feof(Diskon))
		{
			pesan.store = pesan.store * 0.90;
			fwrite(&pesan,sizeof(pesan),1,Transaksi);
			fread(&pesan,sizeof(pesan),1,Diskon);
		}
		fclose(Diskon);
		fclose(Transaksi);

		fclose(datambr);
		fclose(temp);
	}
	else 
	{
		gotoxy(118,23),printf ("Salah memasukan ID !");
		fclose(datambr);
		fclose(temp);
		bayar();
	}
}

void hari()
{
	int a,b,c;
	int jumlah;
	char harga[50];
	
	Laporan = fopen("laporan.dat","rb");
	temp = fopen("temp.dat","wb");
	
	gotoxy(8,21), printf("Sort Dalam Tanggal");
	gotoxy(6,23), printf("Masukan Tanggal : ");getnum(&a,2);
	gotoxy(6,24), printf("Masukan Bulan : ");getnummin(&b,1,12);
	gotoxy(6,25), printf("Masukan Tahun : ");getnum(&c,4);
	
	tabeltransaksi();
	int i;
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
	
	jumlah=0;
	i=19;
	fread(&pesan,sizeof(pesan),1,Laporan);
	while(!feof(Laporan))
	{
		if (pesan.tgl == a && pesan.bulan == b && pesan.tahun == c)
		{
			gotoxy(38,i),	printf ("%d/%d/%d",pesan.tgl,pesan.bulan,pesan.tahun);
			gotoxy (55,i),	printf ("KA%d",pesan.id);
			gotoxy (65,i),	printf ("%s",pesan.nama);
			gotoxy (85,i),	printf ("%d",pesan.jumlah);
			gotoxy (94,i),	rupiah(pesan.harga,harga);printf ("Rp. %s",harga);
			gotoxy (109,i),	rupiah(pesan.store,harga);printf ("Rp. %s",harga);
			jumlah = jumlah + pesan.store;
			i++;
		}
		else
		{
			fwrite(&pesan,sizeof(pesan),1,temp);
		}
		fread(&pesan,sizeof(pesan),1,Laporan);
	}
	if(jumlah!=0)
	{
		gotoxy(35,i+2), printf("Total Pendapatan Stasiun Adalah :");
		gotoxy(109, i+2),rupiah(jumlah,harga);printf("Rp. %s", harga);
	}
	else
	{
		gotoxy(35, 15), printf("Tanggal yang anda masukan salah");
	}
	fclose(Laporan);
	fclose(temp);
	getch();
}

void bulan ()
{
	int b,c;
	int jumlah;
	char harga[50];
	
	Laporan = fopen("laporan.dat","rb");
	temp = fopen("temp.dat","wb");
	
	gotoxy (8,21), printf("Sort Dalam Bulan");
	gotoxy (6,23), printf("Masukan Bulan : "); getnummin(&b,1,12);
	gotoxy (6,24), printf("Masukan Tahun : "); getnum(&c,4);
	
	tabeltransaksi();
	int i;
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
	
	jumlah=0;
	i=19;
	fread(&pesan,sizeof(pesan),1,Laporan);
	while(!feof(Laporan))
	{
		if (pesan.bulan == b && pesan.tahun == c)
		{
			gotoxy(38,i),	printf ("%d/%d/%d",pesan.tgl,pesan.bulan,pesan.tahun);
			gotoxy (55,i),	printf ("KA%d",pesan.id);
			gotoxy (65,i),	printf ("%s",pesan.nama);
			gotoxy (85,i),	printf ("%d",pesan.jumlah);
			gotoxy (94,i),	rupiah(pesan.harga,harga);printf ("Rp. %s",harga);
			gotoxy (109,i),	rupiah(pesan.store,harga);printf ("Rp. %s",harga);
			jumlah = jumlah + pesan.store;
			i++;
		}
		else
		{
			fwrite(&pesan,sizeof(pesan),1,temp);
		}
		fread(&pesan,sizeof(pesan),1,Laporan);
	}
	if(jumlah!=0)
	{
		gotoxy(35,i+2), printf("Total Pendapatan Stasiun Adalah :");
		gotoxy(109, i+2),rupiah(jumlah,harga);printf("Rp. %s", harga);
	}
	else
	{
		gotoxy(35, 15), printf("Bulan yang anda masukan salah");
	}
	fclose(Laporan);
	fclose(temp);
	getch();
}

void tahun ()
{
	int c;
	int jumlah;
	int i;
	char harga[50];

	
	Laporan = fopen("laporan.dat","rb");
	temp = fopen("temp.dat","wb");
	
	gotoxy (8,21), printf("Sort Dalam Tahun");
	gotoxy (6,23), printf("Masukan Tahun : "); getnum(&c,4);
	
	tabeltransaksi();
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
		
	jumlah=0;
	i=19;
	fread(&pesan,sizeof(pesan),1,Laporan);
	while(!feof(Laporan))
	{
		if (pesan.tahun == c)
		{
			gotoxy(38,i),	printf ("%d/%d/%d",pesan.tgl,pesan.bulan,pesan.tahun);
			gotoxy (55,i),	printf ("KA%d",pesan.id);
			gotoxy (65,i),	printf ("%s",pesan.nama);
			gotoxy (85,i),	printf ("%d",pesan.jumlah);
			gotoxy (94,i),	rupiah(pesan.harga,harga);printf ("Rp. %s",harga);
			gotoxy (109,i),	rupiah(pesan.store,harga);printf ("Rp. %s",harga);
			jumlah = jumlah + pesan.store;
			i++;
		}
		else
		{
			fwrite(&pesan,sizeof(pesan),1,temp);
		}
		fread(&pesan,sizeof(pesan),1,Laporan);
	}
	
	if(jumlah!=0)
	{
		gotoxy(35,i+2), printf("Total Pendapatan :");
		gotoxy(109, i+2),rupiah(jumlah,harga);printf("Rp. %s", harga);
	}
	else
	{
		gotoxy(35, 15), printf("Tahun yang anda masukan salah");
	}
	fclose(Laporan);
	fclose(temp);
	getch();
}




typedef struct {char username[50];
				char pass[50];
				} Admin;
Admin Login;

typedef struct { 
	int IDKeretaApi;
	char Nama [30];
	char Jurusan [30];
	char Kelas [30];
	int Harga;
	int Stock;
} ArsipKeretaApi;

ArsipKeretaApi KeretaApi;

typedef struct {
	int ID;
	char Nama[25];
	char Username[25];
	char password[25];
	char Telp[13];
	char lahir[25];
	int tgl;
	int bln;
	int thn;
} DataAkun;

DataAkun kasir;

bool found;

FILE *ArsKeretaApi;
FILE *temp;
FILE *DataAdmin;
FILE *DataPesananAmbil;
FILE *DataPesananBeli;
FILE *MasterKeuntungan;


void LoginAdmin();
void FiturAdmin();
void TambahDataKeretaApi();
void LihatDataKeretaApi();
void EditDataKeretaApi();
void HapusDataKeretaApi();
void MenuLogin();
void laporan();
void TambahKaryawan();
void BacaKaryawan();
void UpdateKaryawan();
void HapusKaryawan();
void KotakTanya();
void Rupiah();



void LoginAdmin()
{
	char user[50];
	char pass[50];
	
	system("cls");
	KotakLogin();
	DataAdmin = fopen("DataAdmin.dat", "r");
	fread (&Login, sizeof(Login), 1, DataAdmin);
	fclose(DataAdmin);
	
	gotoxy(70, 25),printf("Masukan Username : ");
	gotoxy(70, 27),printf("Masukan Password : ");
	gotoxy(90, 25),scanf("%s",&user);
	fflush(stdin);
	gotoxy(90, 27),getpass(pass,5); 
	fflush(stdin);
	if((strcmp(user,"admin")==0)&&(strcmp(pass,"admin")==0))
		{
			MessageBox(NULL,"Login berhasil","Login Admin",MB_ICONINFORMATION | MB_OK);
			system("cls");
			FiturAdmin();
		}
	else
		{
			MessageBox(NULL,"Username/Password Salah","Login Admin",MB_ICONSTOP | MB_OK);
			system("cls");
			MenuLogin();
		}
}

void FiturAdmin()
{
	int angka;	// nomer yang dipilih
	char Pilihan; //jawaban yg dipilih
	setColor(07);
	system("cls");
	DesainUtama();
	gotoxy(13, 21),printf("ADMIN");
	gotoxy(6, 23),printf("1. Data KA");
	gotoxy(6, 24),printf("2. Data Karyawan ");
	gotoxy(6, 25),printf("3. Logout");
	gotoxy(6, 26),printf("4. Keluar Program");
	gotoxy(6, 27),printf("Pilih Menu :");
	gotoxy(20, 27),scanf("%d", &angka);
	fflush(stdin);
	switch (angka)
	{
		case(1):
			{
				system("cls");
				DesainUtama();
				gotoxy(10, 21),printf("Kereta Api");
				gotoxy(6, 23),printf("1. Tambah Data KA");
				gotoxy(6, 24),printf("2. Lihat Data KA");
				gotoxy(6, 25),printf("3. Edit Data KA");
				gotoxy(6, 26),printf("4. Hapus Data KA");
				gotoxy(6, 27),printf("5. Menu Admin");
				gotoxy(6, 28),printf("6. Logout");
				gotoxy(6, 29),printf("7. Keluar Program");
				gotoxy(6, 30),printf("Pilih Menu : ");
				gotoxy(22,30),scanf("%d", &angka);
				gotoxy(6, 31),printf("Loading . .");
				Sleep(1000);
				fflush(stdin);
				switch (angka)
				{
					case 1  :
						{
							TambahDataKeretaApi();
							break;
							
						}
					case 2	:
						{
							LihatDataKeretaApi();
							KotakTanyaLiatKereta();
							gotoxy(126,20),printf("Kembali ke Menu Utama? <y/t>");
							gotoxy(126,22),printf("Masukan jawaban : ");scanf("%c",&Pilihan);
							if(Pilihan=='y' || Pilihan=='Y')
							{
								system("cls");
								FiturAdmin();
							}
							else
							{
								penutup();
							}
							break;
						}
					case 3	:
						{
							EditDataKeretaApi();
							break;
						}
					case 4 :
						{
							HapusDataKeretaApi();
							break;
						}
					case 5 :
						{
							FiturAdmin();
							break;
						}
					case 6 :
						{
							system("cls");
							MenuLogin();
							break;
						}
					case 7  :
						{
							system("cls");
							exit(0);
							break;
						}
					default : FiturAdmin();break;
				}
				break;
			}
		case(2) :
			{
				system("cls");
				DesainUtama();
				gotoxy(10, 20),	printf("KARYAWAN");			
				gotoxy(7, 22),	printf("1. Tambah Karyawan");
				gotoxy(7, 23),	printf("2. Lihat Karyawan");
				gotoxy(7, 24),	printf("3. Update Karyawan");
				gotoxy(7, 25),	printf("4. Hapus Karyawan");
				gotoxy(7, 26),	printf("5. Menu Admin");
				gotoxy(7, 27),	printf("6. Logout");
				gotoxy(7, 28),	printf("7. Keluar Program");
				gotoxy(6, 30),printf("Pilih Menu : ");
				gotoxy(24,30),scanf("%d", &angka);
				gotoxy(6, 31),printf("Loading . .");
				Sleep(1000);
				fflush(stdin);
				switch (angka)
				{
					case 1  :
						{
							TambahKaryawan();
							break;
							
						}
					case 2	:
						{
							BacaKaryawan();
							KotakTanyaLiat();
							gotoxy(110,20),printf("Kembali ke Menu Admin? <y/t>");
							gotoxy(110,22),printf("Masukan jawaban : ");scanf("%c",&Pilihan);
							if(Pilihan=='y' || Pilihan=='Y')
							{
								system("cls");
								FiturAdmin();
								
							}
							else
							{
								penutup();
							}
							break;
						}
					case 3	:
						{
							UpdateKaryawan();
							break;
						}
					case 4 :
						{
							HapusKaryawan();
							break;
						}
					case 5 :
						{
							FiturAdmin();
							break;
						}
					case 6 :
						{
							system("cls");
							MenuLogin();
							break;
						}
					case 7  :
						{
							system("cls");
							exit(0);
							break;
						}
					default : FiturAdmin();break;
				}
				break;
			}
		case(3) :
			{
				system("cls");
				MenuLogin();
				break;
				
			}
		case(4) :
			{
				system ("cls");
				penutup();
				exit(0);
				break;
			}
		default : FiturAdmin();break;
	}

	
}

void TambahDataKeretaApi()
{
	char pil;
	int i;
	
	ArsKeretaApi = fopen("arska.dat","a+b");
	while (!feof(ArsKeretaApi))
	{
	
		fflush(stdin); //supaya datanya urut{tidak ada yang kelewat}
		fread(&KeretaApi.IDKeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);
	
	}
		KeretaApi.IDKeretaApi++;
	if (KeretaApi.IDKeretaApi<100)//tetapan kode harus 100
	{
		KeretaApi.IDKeretaApi=KeretaApi.IDKeretaApi+100;//{apabila kode kurang dari 100 maka, akan ditambah 100
	}

	DesainUtama();
	KotakTambahdata();
	for(i=37;i<=78;i++)
	{
		gotoxy(i,21),	printf("%c",205);
	}
	gotoxy(40,20),printf("Tambah Data Kereta Api");
	gotoxy(40,23),printf("ID Kereta Api \t : KA%d",KeretaApi.IDKeretaApi);
	gotoxy(40,25),printf("Nama Kereta Api  : ");
	gotoxy(40,27),printf("Jurusan \t : ");
	gotoxy(40,29),printf("Kelas \t         : ");
	gotoxy(40,31),printf("Stock \t\t : ");	
	gotoxy(40,33),printf("Harga \t\t : Rp. ");
	fflush (stdin);
	gotoxy(59,25),gets(KeretaApi.Nama);
	fflush (stdin);
	gotoxy(59,27),gets(KeretaApi.Jurusan);
	fflush (stdin);
	gotoxy(59,29),gets(KeretaApi.Kelas);
	fflush (stdin);	
	gotoxy(59,31),getnum(&KeretaApi.Stock,3);
	fflush (stdin);		
	gotoxy(62,33),getnum(&KeretaApi.Harga,6);
	fwrite(&KeretaApi, sizeof(KeretaApi),1,ArsKeretaApi);

	fclose(ArsKeretaApi);
	KotakTanya();
	gotoxy(89,20),printf("Tambah Data Kereta Api Lagi?<y/t>\n");
	gotoxy(89,22),printf("Pilihan : ");
	scanf("%s",&pil);
	gotoxy(40,23),printf("                                     ");
	gotoxy(40,24),printf("                                     ");
	gotoxy(40,25),printf("                                     ");
	gotoxy(40,26),printf("                                     ");
	gotoxy(40,27),printf("                                       ");
	gotoxy(40,28),printf("                                     ");
	gotoxy(89,20),printf("                                     ");
	gotoxy(89,22),printf("                                     ");
	gotoxy(40,30),printf("                                     ");
	gotoxy(40,31),printf("                                     ");  
	gotoxy(40,32),printf("                                     ");
	gotoxy(40,33),printf("                                     ");          
	gotoxy(40,29),printf("                                     ");
	gotoxy(40,34),printf("                                     ");
	Sleep(1000);
	if(pil=='y' || pil=='Y')
	{
		TambahDataKeretaApi();
	}
	else
	{
		FiturAdmin();
	}
	getch();
}

void LihatDataKeretaApi()
{
	int i;
	int baris;
	int x;
	char duit[1000];

	FILE *ArsKeretaApi;

	ArsKeretaApi = fopen("arska.dat","rb");
	
	fread(&KeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);
	tabelkereta();
	setColor(112);
	for(x=35;x<119;x++)
		{
			gotoxy(x,17),printf(" ");
		}
	gotoxy (35,17),printf("ID");
	gotoxy (45,17),printf("Nama Kereta Api");
	gotoxy (65,17),printf("Jurusan");
	gotoxy (102,17),printf("Kelas");		
	gotoxy (115,17),printf("Stok");
	gotoxy (88,17),printf("Harga");
	
	i=19;
	while(!feof(ArsKeretaApi))
	{
		baris++;
		if(baris%2==0)
		{
			gotoxy(17,baris);
			setColor(112);
			
		}
		
		else
		{
			gotoxy(17,baris);
			setColor(7);
		}
		for(x=35;x<119;x++)
		{
			gotoxy(x,i),printf(" ");
		}
		gotoxy(35,i),printf ("KA%d\n",KeretaApi.IDKeretaApi);
		gotoxy(45,i),printf ("%s\n",KeretaApi.Nama);
		gotoxy(65,i),printf ("%s\n",KeretaApi.Jurusan);
		gotoxy(102,i),printf ("%s\n",KeretaApi.Kelas);
		gotoxy(115,i),printf ("%d\n",KeretaApi.Stock);
		gotoxy(88,i),rupiah(KeretaApi.Harga,duit);printf ("Rp %s\n\n",duit);
		fread(&KeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);	
		i++;
	}
	fclose(ArsKeretaApi);

}

void EditDataKeretaApi()
{
	bool temukan;
	
	char namabaru[30];
	char jurusanbaru[30];
	char kelasbaru[30];
	char harga[50];
	int hargabaru;
	int stockbaru;
	int IDKeretaApi;
	int nomor;
	int i;
	char pilihan;
	
	DesainUtama();
	KotakTambahdata();
	for(i=37;i<=78;i++)
	{
		gotoxy(i,21),	printf("%c",205);
	}
	gotoxy(46,16),printf("UPDATE DATA Kereta Api\n");
	gotoxy(40,20),printf("Masukan ID Kereta Api : KA"); scanf("%d",&IDKeretaApi);
	
	ArsKeretaApi = fopen("arska.dat","rb");
	temp = fopen("temp.dat","wb");
	temukan = false;
	while((temukan==false)&&(!feof(ArsKeretaApi)))
	{
		fread(&KeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);	
		if (KeretaApi.IDKeretaApi ==IDKeretaApi)
		{
   			temukan = true;
		}
		else
		{		
			fwrite(&KeretaApi,sizeof(KeretaApi),1,temp);
		}
	}
	
	if(temukan == true)
	{
		gotoxy(40,22),printf("Nama KA \t : %s",	KeretaApi.Nama);
		gotoxy(40,23),printf("Jurusan \t : %s",	KeretaApi.Jurusan);
		gotoxy(40,24),printf("Kelas \t\t : %s",	KeretaApi.Kelas); 
		rupiah(KeretaApi.Harga,harga);			
		gotoxy(40,25), printf ("Harga KA \t : Rp. %s",  harga);		
		gotoxy(40,26),printf ("Stock KA \t : %d",  KeretaApi.Stock);
		gotoxy(40,28),printf("Pilih Menu Yang Ingin Di Edit");
		gotoxy(40,29),printf("1. Edit Nama KA");
		gotoxy(40,30),printf("2. Edit Jurusan KA");
		gotoxy(40,31),printf("3. Edit Kelas KA");
		gotoxy(40,32),printf("4. Edit Harga KA");
		gotoxy(40,33),printf("5. Edit Stok KA");
		gotoxy(40,34),printf("6. Batal");
		gotoxy(40,35),printf("Pilih Menu : "); scanf("%d",&nomor);
		switch (nomor)
		{
			case 1 : 
					{	
						gotoxy(40,36),printf("Masukan Nama Baru KA :  ");
					 	getletter(namabaru,20);
						strcpy(KeretaApi.Nama,namabaru);break;
					}
		    case 2 : 
					{	
						gotoxy(40,36),printf("Masukan Jurusan Baru KA :  ");
					 	getletter(jurusanbaru,20);
						strcpy(KeretaApi.Jurusan,jurusanbaru);break;
					}
			case 3 :
				    {
				        gotoxy(40,36),printf("Masukan Kelas Baru KA :  ");
					 	getletter(kelasbaru,20);
						strcpy(KeretaApi.Kelas,kelasbaru);break;	
					}
			case 4 : 
					{
						gotoxy(40,36),printf("Masukan Harga Baru KA : Rp ");
					 	getnum(&hargabaru,6);
						KeretaApi.Harga = hargabaru;break;
					}
			case 5 : 
					{
						gotoxy(40,36),printf("Masukan Stok Baru KA : "); 
						getnum(&stockbaru,3);
						KeretaApi.Stock = stockbaru;break;
					}
			case 6 : 
					{
						system("cls");
						FiturAdmin;break;	
					}		
		}
		
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
		gotoxy(40,37),printf("Data Berhasil Di Ubah");
		KotakTanya();
		gotoxy(89,20),printf("Ingin Edit Data Lagi? <y/t>");
		gotoxy(89,22),printf("Jawaban: ");	scanf("%s",&pilihan);
		gotoxy(40,19),printf("                                        ");
	//	gotoxy(40,21),printf("                                        ");
		gotoxy(40,22),printf("                                        ");
		gotoxy(40,23),printf("                                        ");
		gotoxy(40,27),printf("                                        ");
		gotoxy(40,28),printf("                                        ");
		gotoxy(40,29),printf("                                        ");
		gotoxy(40,30),printf("                                        ");
		gotoxy(40,31),printf("                                        ");
		gotoxy(40,34),printf("                                        ");
		gotoxy(85,20),printf("                                        ");
		gotoxy(85,21),printf("                                        ");
		gotoxy(85,25),printf("                                        ");
		gotoxy(40,24),printf("                                        ");
		gotoxy(40,25),printf("                                        ");
		gotoxy(40,32),printf("                                        ");
		gotoxy(40,35),printf("                                        ");
		gotoxy(89,22),printf("                                        ");
		gotoxy(40,20),printf("                                        ");
		gotoxy(40,33),printf("                                        ");
		gotoxy(40,26),printf("                                        ");
		
		if(pilihan =='y' || pilihan =='Y')
		{
			EditDataKeretaApi();
		}
		else
		{
			system("cls");
			FiturAdmin();
			
		}
	}
	else
	{
		gotoxy(40,35),printf("ID KA Tidak Di Temukan",IDKeretaApi);
		KotakTanya();
		gotoxy(89,20),printf("Ingin Cari Data Lagi?<y/t>");
		gotoxy(89,22),printf("Jawaban :");
		scanf("%s",&pilihan);
		gotoxy(40,37),printf("Loading ..");
		Sleep(1000);
		gotoxy(40,20),printf("                                             ");
		gotoxy(40,35),printf("                                             ");
		gotoxy(40,36),printf("                                             ");
		gotoxy(40,37),printf("                                             ");
		gotoxy(40,21),printf("                                             ");
		gotoxy(89,20),printf("                                    ");
		gotoxy(89,22),printf("                                    ");
		if(pilihan=='y' || pilihan=='Y')
		{
			//system("cls");
			EditDataKeretaApi();
		}
		else
		{
			//system("cls");
			FiturAdmin();
		}
		fclose(ArsKeretaApi);
		fclose(temp);
		
	}			
}

void HapusDataKeretaApi()
{
	char pil;
	
	bool temukan;

	int IDKeretaApi;
	int i;
	char harga[50];
	 
	ArsKeretaApi = fopen("arska.dat","rb");
	temp = fopen("temp.dat","wb");

	KotakTambahdata();
	gotoxy(46,16),printf("HAPUS DATA Kereta Api");
	for(i=37;i<=78;i++)
	{
		gotoxy(i,21),	printf("%c",205);
	}
	gotoxy(40,20),printf("ID KA \t : KA");scanf("%d",&IDKeretaApi);

	temukan = false;
	while((temukan==false)&&(!feof(ArsKeretaApi)))
	{
		fread(&KeretaApi,sizeof(KeretaApi),1,ArsKeretaApi);	
		if (KeretaApi.IDKeretaApi ==IDKeretaApi)
		{
   			temukan = true;
		}
		else
		{		
			fwrite(&KeretaApi,sizeof(KeretaApi),1,temp);
		}
	}
	
	if(temukan == true)
	{
		gotoxy(40,22),printf("Nama KA \t : %s",	KeretaApi.Nama); 
		gotoxy(40,23),printf("Jurusan KA \t : %s", KeretaApi.Jurusan); 
		gotoxy(40,24),printf("Kelas KA \t : %s", KeretaApi.Kelas); 
		rupiah(KeretaApi.Harga,harga);			
		gotoxy(40,25),printf ("Harga KA \t : Rp.%s", harga);		
 		gotoxy(40,28),printf ("Stock KA \t : %d", KeretaApi.Stock);
		gotoxy(40,30),printf ("Yakin menghapus data? <y/t> ");
		gotoxy(40,32),printf("Jawaban : ");
		scanf("%s", &pil);
		if(pil=='y' || pil=='Y')
		{
		
			gotoxy(40,37),printf("Loading . .");
			Sleep(1000);
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
			gotoxy(40,36),printf ("Data telah dihapus");
			KotakTanya();
			gotoxy(89,20),printf("Ingin Hapus Data Lagi?<y/t>");
			gotoxy(89,22),printf("Jawaban : ");
			scanf("%s", &pil);
			gotoxy(40,35),printf("                                     ");
			gotoxy(40,36),printf("                                     ");
			gotoxy(40,37),printf("                                     ");
			gotoxy(40,32),printf("                                     ");       
			gotoxy(40,29),printf("                                     ");
			gotoxy(40,20),printf("                                     ");
			gotoxy(89,20),printf("                                     ");
			gotoxy(89,22),printf("                                     ");
			gotoxy(40,22),printf("                            ");
			gotoxy(40,23),printf("                            ");
			gotoxy(40,24),printf("                            ");
			gotoxy(40,25),printf("                                     ");
			gotoxy(40,26),printf("                            ");
			gotoxy(40,27),printf("                            ");
			gotoxy(40,28),printf("                            ");
			gotoxy(40,30),printf("                            ");
			gotoxy(40,32),printf("                            ");
			gotoxy(89,24),printf("                            ");

			if(pil=='y' || pil=='Y')
			{
				HapusDataKeretaApi();
			}
			else
			{
				FiturAdmin();
			}		
		}
		else
		{
			FiturAdmin();
		}
		getch();
	}
	else
	{
		gotoxy(40,35),printf("ID Kereta Api Tidak Di Temukan",IDKeretaApi);
		fclose(ArsKeretaApi);
		fclose(temp);
		KotakTanya();
		gotoxy(89,20),printf("Ingin Cari Data Lagi?<y/t>");
		gotoxy(89,22),printf("Jawaban : ");
			scanf("%s", &pil);
			gotoxy(40,35),printf("                                     ");
			gotoxy(40,36),printf("                                     ");
			gotoxy(40,37),printf("                                     ");
			gotoxy(40,32),printf("                                     ");       
			gotoxy(40,29),printf("                                     ");
			gotoxy(40,20),printf("                                     ");
			gotoxy(89,20),printf("                                     ");
			gotoxy(89,22),printf("                                     ");
			if(pil=='y' || pil=='Y')
			{
				HapusDataKeretaApi();
			}
			else
			{
				FiturAdmin();
			}
		
		getch();
	}
}

void TambahKaryawan()
{
	int i;
	char pil;
	FILE *flkasir; 	//nama file
	
	flkasir = fopen("flkasir.dat", "a+b"); 	//membuka file arsip
	
	KotakTambahdata();
	//ID kasir otomatis bukan input dari user
	while(!feof(flkasir))
	{
		fflush(stdin); //Agar semua perintah tereksekusi
		fread(&kasir.ID,sizeof(kasir),1,flkasir);
	}
	kasir.ID++; // agar setiap menambahkan id bisa urut
	
	gotoxy(45,20),	printf("Tambah Akun Kasir");
		for(i=37;i<=78;i++)
	{
		gotoxy(i,21),	printf("%c",205);
	}
	gotoxy(40,22),	printf("ID Kasir \t : KSR%d", kasir.ID);
	gotoxy(40,24),	printf("Nama Lengkap \t : "); 		
	gotoxy(40,26),	printf("Username \t : "); 		
	gotoxy(40,28),	printf("Password \t :  "); 
	gotoxy(40,30),	printf("Nomor Telepon\t :");			
	gotoxy(59,24),	getletter(kasir.Nama,16);
	gotoxy(59,26),	getteks(kasir.Username,10);
	gotoxy(59,28),	getteks(kasir.password,16);
	gotoxy(59,30),	getteksnum(kasir.Telp,13); 				
		
	fwrite(&kasir,sizeof(kasir),1,flkasir);
	fclose(flkasir);
	KotakTanya();
	gotoxy(90,20),printf("Tambah Data Karyawan Lagi?<y/t>");
	gotoxy(90,22),printf("Jawaban : ");
	scanf("%s",&pil);
	gotoxy(40,21),printf("                                     ");
	gotoxy(40,22),printf("                                     ");
	gotoxy(40,23),printf("                                     ");
	gotoxy(40,24),printf("                                     ");
	gotoxy(40,25),printf("                                     ");
	gotoxy(40,26),printf("                                     ");
	gotoxy(40,27),printf("                                     ");
	gotoxy(40,28),printf("                                     ");
	gotoxy(89,20),printf("                                     ");
	gotoxy(89,22),printf("                                     ");
	gotoxy(40,30),printf("                                     ");
	gotoxy(40,31),printf("                                     ");
	if(pil=='y' || pil=='Y')
	{
		TambahKaryawan();
	}
	else
	{
		FiturAdmin();
	}
	getch();
	
}

void BacaKaryawan()
{
	int i;
	int x;
	int baris;

	FILE *flkasir;
	
	
	flkasir = fopen("flkasir.dat", "rb");
	
	fread(&kasir, sizeof(kasir),1,flkasir);
	
	DesainUtama();
	tabel();
	setColor(112);
	for(x=35;x<95;x++)
		{
			gotoxy(x,17),printf(" ");
		}
	
	gotoxy (35,17), printf("ID");
	gotoxy (43,17), printf("Nama");
	gotoxy (60,17), printf("Nomor Telepon");
	gotoxy (76,17), printf("Username");
	gotoxy (90,17), printf("Password");
	
	i=19;
	while (!feof(flkasir))
	{
		baris++;
		if(baris%2==0)
		{
			gotoxy(17,baris);
			setColor(112);
			
		}
		
		else
		{
			gotoxy(17,baris);
			setColor(7);
		}
		for(x=35;x<95;x++)
		{
			gotoxy(x,i),printf(" ");
		}
		gotoxy (35,i), printf ("KSR%d",kasir.ID);
		gotoxy (43,i), printf ("%s",kasir.Nama);
		gotoxy (60,i), printf ("%s",kasir.Telp);
		gotoxy (76,i), printf ("%s",kasir.Username);
		gotoxy (90,i), printf ("%s",kasir.password);
		fread(&kasir, sizeof(kasir),1,flkasir);
		i++;
	}
	fclose(flkasir);
	getch;
}

void UpdateKaryawan()
{
	FILE *temp;
	FILE *flkasir;
	
	char pilihan;
	int menu;
	int i;
	
	typedef struct {
		int id;
		char Usname[25];
		char pass[25];
		char nohp[15];
	}Baru;
	Baru kasirbaru;
	
	flkasir = fopen ("flkasir.dat", "rb"); //dibuka untuk update saja
	temp = fopen ("temp.dat", "wb");
	
	KotakTambahdata();
	gotoxy(48,20), printf("Update Akun Kasir");
	for(i=37;i<=78;i++)
	{
		gotoxy(i,21),	printf("%c",205);
	}
	gotoxy(40,22), printf("Masukan ID Kasir : KSR"); scanf("%d", &kasirbaru.id);
	
	found = false;
	while((!found)&&(!feof(flkasir)))
	{
		fread(&kasir,sizeof(kasir),1,flkasir);	
		if (kasir.ID == kasirbaru.id)
		{
			found = true;
		}
		else
		{
			fwrite(&kasir,sizeof(kasir),1,temp);
		}			
	}
	
	if(found == true)
	{
		gotoxy(40,23), printf("Data Berhasil Ditemukan");
		gotoxy(40,24), printf("Nama Lengkap\t : %s", kasir.Nama);
		gotoxy(40,25), printf("Username\t : %s",kasir.Username);
		gotoxy(40,26), printf("Password\t : %s",kasir.password);
		gotoxy(40,27), printf("Nomor Telepon \t : %s",kasir.Telp);
		gotoxy(40,31), printf("Data Mana yang Akan Anda edit : ");
		gotoxy(40,32), printf("1. Username");
		gotoxy(40,33), printf("2. Password");
		gotoxy(40,34), printf("3. Nomor Telepon");
		gotoxy(40,35), printf("4. Batal");
		gotoxy(40,36), printf("Pilihan Anda : "); scanf("%d", &menu);
		fflush(stdin);
		switch(menu)
		{
			case 1 :gotoxy(87,31), printf("Masukkan Username baru : "); getteks(kasirbaru.Usname,10);
					strcpy (kasir.Username,kasirbaru.Usname);fflush(stdin); break;
			case 2 :gotoxy(87,31), printf("Masukkan Password baru : "); getteks(kasirbaru.pass,16);
					strcpy (kasir.password,kasirbaru.pass);fflush(stdin); break;
			case 3 :gotoxy(87,31), printf("Masukkan Nomor Telepon baru : "); getteksnum(kasirbaru.nohp,13);
					strcpy(kasir.Telp,kasirbaru.nohp);fflush(stdin); break;
			case 4 :FiturAdmin(); break;
		}
		fwrite(&kasir,sizeof(kasir),1,temp);
		fread(&kasir,sizeof(kasir),1,flkasir);
		while(!feof(flkasir))
		{
			fwrite(&kasir,sizeof(kasir),1,temp);
			fread(&kasir,sizeof(kasir),1,flkasir);
		}
		gotoxy(87,32), printf("Loading . . ");
		Sleep(1500);
		
		fclose(flkasir);
		fclose(temp);
	
		temp = fopen("temp.dat","rb");
		flkasir = fopen("flkasir.dat","wb"); 
		
		fread(&kasir,sizeof(kasir),1,temp);
		while(!feof(temp))
		{	
			fwrite(&kasir,sizeof(kasir),1,flkasir);
			fread(&kasir,sizeof(kasir),1,temp);
		} 
		
		fclose(flkasir);
		fclose(temp);
		
		gotoxy(87,33), printf("Data Berhasil Di Update.");
		KotakTanya();
		gotoxy(89,20),printf("Ingin Edit Data Lagi? <y/t>");
		gotoxy(89,22),printf("Jawaban: ");	scanf("%s",&pilihan);
		gotoxy(40,21),printf("                                     ");
				gotoxy(40,22),printf("                                     ");
				gotoxy(40,23),printf("                                     ");
				gotoxy(40,24),printf("                                     ");
				gotoxy(40,25),printf("                                     ");
				gotoxy(40,26),printf("                                     ");
				gotoxy(40,27),printf("                                     ");
				gotoxy(40,28),printf("                                     ");
				gotoxy(89,20),printf("                                     ");
				gotoxy(89,22),printf("                                     ");
				gotoxy(40,30),printf("                                     ");
				gotoxy(40,31),printf("                                     ");
				gotoxy(40,32),printf("                                     ");
				gotoxy(40,33),printf("                                     ");
				gotoxy(40,34),printf("                                     ");
				gotoxy(40,35),printf("                                     ");
				gotoxy(40,36),printf("                                     ");
				gotoxy(87,31),printf("                                     ");
				gotoxy(87,32),printf("                                     ");
				gotoxy(87,33),printf("                                     ");
		if(pilihan =='y' || pilihan =='Y')
		{
			//system("cls");
			UpdateKaryawan();
			
		}
		
		else
		{
			//system("cls");
			FiturAdmin();
			getch();	
			
		}
	
	}

	else
	{
		gotoxy(41,23), printf("ID KSR%d tidak ditemukan", kasirbaru.id);
		KotakTanya();
		gotoxy(89,20),printf("Ingin Cari Data Lagi?<y/t>");
		gotoxy(89,22),printf("Jawaban : ");
		scanf("%s",&pilihan);
		gotoxy(40,37),printf("Loading ..");
		Sleep(1000);
		gotoxy(40,35),printf("                                             ");
		gotoxy(41,23),printf("                                             ");
		gotoxy(40,36),printf("                                             ");
		gotoxy(40,37),printf("                                             ");
		gotoxy(40,21),printf("                                             ");
		gotoxy(40,22),printf("                                             ");
		if(pilihan=='y' || pilihan=='Y')
		{
			//system("cls");
			UpdateKaryawan();
			
		}
		else
		{
			system("cls");
			FiturAdmin();
		}
		fclose(flkasir);
		fclose(temp);
	}
	getch;
}

void HapusKaryawan()
{
	FILE *temp;
	FILE *flkasir;
	
	
	int idkasir;
	char konfirmasi;
	int i;
	char pilihan;
	char pil;
	
	flkasir = fopen ("flkasir.dat", "rb");
	temp = fopen ("temp.dat","wb");

	DesainUtama();
	KotakTambahdata();
	gotoxy(48,20), printf("Hapus Data Akun");
	for(i=37;i<=78;i++)
	{
		gotoxy(i,21),	printf("%c",205);
	}
	gotoxy(40,22), printf("Masukan id kasir : KSR"); scanf("%d", &idkasir);
	found = false;
	while ((!found)&&(!feof(flkasir)))
	{
		fread(&kasir,sizeof(kasir),1,flkasir);
		if(kasir.ID==idkasir)
		{
			found = true;
		}
		else
		{
			fwrite(&kasir,sizeof(kasir),1,temp);
		}
	}
	
	if(found == true)
	{
		gotoxy(40,23), printf("Data Berhasil Ditemukan");
		gotoxy(40,24), printf("Nama	Lengkap\t : %s", kasir.Nama);
		gotoxy(40,25), printf("Username\t : %s",kasir.Username);
		gotoxy(40,26), printf("Password\t : %s",kasir.password);
		gotoxy(40,27), printf("Nomor Telepon \t : %s",kasir.Telp);
		KotakTanya();
		gotoxy(89,20), printf("Yakin ingin menghapus Data ini ? y/t ");
		gotoxy(89,22), printf("Jawaban Anda : "); scanf("%s", &konfirmasi);
		if(konfirmasi=='Y' || konfirmasi == 'y')
		{
			gotoxy(40,34), printf("Loading . . ");
			Sleep(1000);
			
			fread(&kasir,sizeof(kasir),1,flkasir);
			while (!feof(flkasir))
			{
				fwrite(&kasir,sizeof(kasir),1,temp);
				fread(&kasir,sizeof(kasir),1,flkasir);
			}
			fclose(flkasir);
			fclose(temp);
			
			temp =  fopen ("temp.dat", "rb");
			flkasir = fopen ("flkasir.dat", "wb");
			
			fread(&kasir,sizeof(kasir),1,temp);
			while(!feof(temp))
			{
				fwrite(&kasir,sizeof(kasir),1,flkasir);
				fread(&kasir,sizeof(kasir),1,temp);
			}
			fclose(flkasir);
			fclose(temp);
			
			gotoxy(40,35), printf("Data Berhasil di Hapus");
			KotakTanya();
			gotoxy(89,22),printf("                                 ");
			gotoxy(89,20),printf("Ingin Menghapus Data Kasir Lagi?<y/t>\n");
			gotoxy(89,22),printf("Pilihan : "); scanf("%s",&pil);
			gotoxy(40,22),printf("                                   ");
			gotoxy(40,23),printf("                                   ");
			gotoxy(40,24),printf("                                   ");
			gotoxy(40,25),printf("                                   ");
			gotoxy(40,26),printf("                                   ");
			gotoxy(40,27),printf("                                   ");
			gotoxy(40,31),printf("                                   ");
			gotoxy(40,32),printf("                                   ");
			gotoxy(40,34),printf("                                   ");
			gotoxy(40,35),printf("                                   ");
			gotoxy(89,20),printf("                                       ");
			gotoxy(89,22),printf("                                       ");
			if(pil == 'y' || pil == 'Y')
			{
				HapusKaryawan();
			}
			else
			{
				FiturAdmin();
			}
	
			getch();
		} 
		else
		{
			FiturAdmin();
		}
	}
	else
	{
//		gotoxy(40,23), printf("Data tidak ditemukan");
//		KotakTanya();
//		gotoxy(89,20),printf("Ingin Cari Data Lagi?<y/t>");
//		gotoxy(89,22),printf("Jawaban : ");
//		fclose(flkasir);
//		fclose(temp);
//		HapusKaryawan();
		
		gotoxy(41,23), printf("ID  tidak ditemukan");
		KotakTanya();
		gotoxy(89,20),printf("Ingin Cari Data Lagi?<y/t>");
		gotoxy(89,22),printf("Jawaban : ");
		scanf("%s",&pilihan);
		gotoxy(40,37),printf("Loading ..");
		Sleep(1000);
		gotoxy(40,35),printf("                                             ");
		gotoxy(41,23),printf("                                             ");
		gotoxy(40,36),printf("                                             ");
		gotoxy(40,37),printf("                                             ");
		gotoxy(40,21),printf("                                             ");
		gotoxy(40,22),printf("                                             ");
		if(pilihan=='y' || pilihan=='Y')
		{
			//system("cls");
			HapusKaryawan();
			
		}
		else
		{
			system("cls");
			FiturAdmin();
		}
		fclose(flkasir);
		fclose(temp);
	}
	getch;

}


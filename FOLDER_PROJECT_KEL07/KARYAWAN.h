
//Data Kasir

bool found;

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

void TambahKaryawan()
{

	FILE *flkasir;
	
	flkasir = fopen("flkasir.dat", "a+b");
	
	while(!feof(flkasir))
	{
		fflush(stdin);
		fread(&kasir.ID,sizeof(kasir),1,flkasir);
	}
	kasir.ID++;
	
	gotoxy(30,18),	printf("Tambah Akun Kasir");
	gotoxy(30,21),	printf("ID Kasir 	\t : KSR%d", kasir.ID);
	gotoxy(30,22),	printf("Nama Lengkap \t : "); 		
	gotoxy(30,23),	printf("Username 	\t : "); 		
	gotoxy(30,24),	printf("Password 	\t :  "); 
	gotoxy(30,25),	printf("Nomor Telepon\t :");			
	gotoxy(50,22),	gets (kasir.Nama);
	gotoxy(50,23),	scanf("%s", &kasir.Username);
	gotoxy(50,24),	scanf("%s", &kasir.password);
	gotoxy(50,25),	scanf("%s", &kasir.Telp); 				
		
	fwrite(&kasir,sizeof(kasir),1,flkasir);
	fclose(flkasir);
	
}

void BacaKaryawan()
{
	int i;
	system("cls");
	FILE *flkasir;
	
	flkasir = fopen("flkasir.dat", "rb");
	
	fread(&kasir, sizeof(kasir),1,flkasir);
	
	gotoxy (35,17), printf("ID");
	gotoxy (43,17), printf("Nama");
	gotoxy (60,17), printf("Nomor Telepon");
	gotoxy (76,17), printf("Username");
	gotoxy (90,17), printf("Password");
	
	i=19;
	while (!feof(flkasir))
	{
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
	system("cls");
	
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
	
	for(i=37;i<=78;i++)
	{
		gotoxy(i,28),	printf("%c",205);
	}
	gotoxy(40,18), printf("Update Akun Kasir");
	gotoxy(40,20), printf("Masukan ID Kasir : KSR"); scanf("%d", &kasirbaru.id);
	
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
		gotoxy(40,22), printf("Data Berhasil Ditemukan");
		gotoxy(40,23), printf("Nama Lengkap\t : %s", kasir.Nama);
		gotoxy(40,24), printf("Username\t : %s",kasir.Username);
		gotoxy(40,25), printf("Password\t : %s",kasir.password);
		gotoxy(40,26), printf("Nomor Telepon \t : %s",kasir.Telp);
		gotoxy(40,30), printf("Data Mana yang Akan Anda edit : ");
		gotoxy(40,31), printf("1. Username");
		gotoxy(40,32), printf("2. Password");
		gotoxy(40,33), printf("3. Nomor Telepon");
		gotoxy(40,34), printf("4. Batal");
		gotoxy(40,35), printf("Pilihan Anda : "); scanf("%d", &menu);
		fflush(stdin);
		switch(menu)
		{
			case 1 :gotoxy(40,36), printf("Masukkan Username baru : "); scanf("%s", kasirbaru.Usname);
					strcpy (kasir.Username,kasirbaru.Usname);fflush(stdin); break;
			case 2 :gotoxy(40,36), printf("Masukkan Password baru : "); scanf("%s", kasirbaru.pass);
					strcpy (kasir.password,kasirbaru.pass);fflush(stdin); break;
			case 3 :gotoxy(40,36), printf("Masukkan Nomor Telepon baru : "); scanf("%s", kasirbaru.nohp);
					strcpy(kasir.Telp,kasirbaru.nohp);fflush(stdin); break;
			case 4 :printf("MenuCRUDKasir"); break;
		}
		fwrite(&kasir,sizeof(kasir),1,temp);
		fread(&kasir,sizeof(kasir),1,flkasir);
		while(!feof(flkasir))
		{
			fwrite(&kasir,sizeof(kasir),1,temp);
			fread(&kasir,sizeof(kasir),1,flkasir);
		}
		gotoxy(40,39), printf("Loading . . ");
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
		
		gotoxy(40,40), printf("Data Berhasil Di Update.");
		getch();
	}

	else
	{
		gotoxy(41,23), printf("Id KSR%d tidak ditemukan", kasirbaru.id);
		fclose(flkasir);
		fclose(temp);
	}
	getch;
}

void HapusKaryawan()
{
	FILE *temp;
	FILE *flkasir;
	system("cls");
	
	int idkasir;
	char konfirmasi;
	int i;
	
	flkasir = fopen ("flkasir.dat", "rb");
	temp = fopen ("temp.dat","wb");


	for(i=37;i<=78;i++)
	{
		gotoxy(i,29),	printf("%c",205);
	}
	gotoxy(40,18), printf("Hapus Data Akun");
	gotoxy(40,21), printf("Masukan ID Kasir : KSR"); scanf("%d", &idkasir);
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
		gotoxy(40,31), printf("Yakin ingin menghapus Data ini ? y/t : ");
		gotoxy(40,32), printf("Jawaban Anda : "); scanf("%s", &konfirmasi);
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
			getch();
		} 
	}
	else
	{
		gotoxy(40,23), printf("Data tidak ditemukan");
		fclose(flkasir);
		fclose(temp);
		getch();
	}
}
 


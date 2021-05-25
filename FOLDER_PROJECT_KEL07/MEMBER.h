
typedef struct {
	int id;
	char nik[200];
	char nama[200];
	char tmptlahir[200];
	char tgllahir[20];
	char notelp[13];
} Data;

Data mbr;
FILE *datambr;
FILE *TEMP;

void TambahDataMember();
void LihatDataMember();
void UpdateDataMember();
void HapusDataMember();
void MenuKasir();

void MenuMember()
{
	char jawab;
	int nomor;
	
	setColor(07);
	system("cls");
	DesainUtama();
	gotoxy(6,21),printf ("Data Member : ");
	gotoxy(6,22),printf ("1. Tambah Member");
	gotoxy(6,23),printf ("2. Lihat Member");
	gotoxy(6,24),printf ("3. Update Member");
	gotoxy(6,25),printf ("4. Hapus Member");
	gotoxy(6,26),printf ("5. Menu Kasir");
	gotoxy(6,27),printf ("6. Logout");
	gotoxy(6,28),printf ("7. Keluar Program");
	gotoxy(6,29),printf("Masukan menu : "); scanf("%i",&nomor);
	
	switch(nomor)
	{
		case (1) :
			{
				//system("cls");
				kasus1 :
				DesainUtama();
				KotakTambahdata();
				TambahDataMember();
				KotakTanya();
				gotoxy(89,20),printf("Tambah Data Lagi?<y/t>");
				gotoxy(89,22),printf("Pilihan Anda : ");scanf("%s",&jawab);
				gotoxy(40,21),printf("                                     ");
				gotoxy(40,22),printf("                                     ");
				gotoxy(40,23),printf("                                     ");
				gotoxy(40,24),printf("                                     ");
				gotoxy(40,25),printf("                                     ");
				gotoxy(40,26),printf("                                     ");
				gotoxy(40,27),printf("                                     ");
				gotoxy(40,28),printf("                                     ");
				gotoxy(40,29),printf("                                     ");
				gotoxy(89,20),printf("                                     ");
				gotoxy(89,22),printf("                                     ");
				gotoxy(40,30),printf("                                     ");
				gotoxy(40,31),printf("                                     ");
				if(jawab== 'y' || jawab== 'Y')
				{
					goto kasus1;
				}
				else
				{
					MenuMember();
				}
			} break;
		case (2) :
			{
				
				//system("cls");
				DesainUtama();
				LihatDataMember();
				KotakTanyaLiatMember();
				gotoxy(130,20);printf("Kembali ke Menu Member?<y/t>\n");
				gotoxy(130,22);printf("Jawaban : ");
				scanf("%s",&jawab);
				gotoxy(40,20),printf("                                  ");
				gotoxy(40,23),printf("                                  ");
				gotoxy(40,24),printf("                                  ");
				gotoxy(40,25),printf("                                  ");
				gotoxy(40,26),printf("                                  ");
				gotoxy(75,19),printf("                                  ");
				gotoxy(75,21),printf("                                  ");
				gotoxy(40,22),printf("                                  ");
				
				if(jawab== 'y' || jawab== 'Y')
				{
					system("cls");
					MenuMember();
				}
				else
				{
					penutup();
					break;
				}
			}
		case (3) :
			{
				kasus2 :
				//system("cls");
					DesainUtama();
				UpdateDataMember();
				KotakTanya();
				gotoxy(89,20),printf("Ingin Update Data Lagi?<y/t>\n");
				gotoxy(89,22),printf("Jawaban : ");
				scanf("%s",&jawab);
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
				if(jawab== 'y' || jawab== 'Y')
				{
					goto kasus2;
					
				}
				else
				{
					system("cls");
					MenuMember();
				}
					
			}
		case (4) :
			{
				kasus3 : 
				//system("cls");
				DesainUtama();
				HapusDataMember();
				KotakTanya();
				gotoxy(89,22),printf("                                     ");
				gotoxy(89,20),printf("Ingin Hapus Data Lagi?<y/t>\n");
				gotoxy(89,22),printf("Jawaban : ");scanf("%s",&jawab);
				gotoxy(40,21),printf("                                     ");
				gotoxy(40,22),printf("                                     ");
				gotoxy(40,23),printf("                                     ");
				gotoxy(40,24),printf("                                     ");
				gotoxy(40,25),printf("                                     ");
				gotoxy(40,26),printf("                                     ");
				gotoxy(40,27),printf("                                     ");
				gotoxy(40,28),printf("                                     ");
				gotoxy(40,29),printf("                                     ");
				gotoxy(89,20),printf("                                     ");
				gotoxy(89,22),printf("                                     ");
				gotoxy(40,30),printf("                                     ");
				gotoxy(40,31),printf("                                     ");
				gotoxy(40,32),printf("                                     ");
				gotoxy(40,33),printf("                                     ");
				if(jawab == 'y' || jawab == 'Y')
				{
					//system("cls");
					goto kasus3;
				}
				else
				{
					//system("cls");
					MenuMember();
				}
				
			}
		case (5) :
			{
				system("cls");
				MenuKasir();
			}
		case (6) :
			{
				MenuLogin();
			}
		case (7) :
			{
				penutup();
				exit(0); 
				break;
			}
		default : MenuMember();break;
					
	}
	
}

void TambahDataMember()
{
	char pil;
//membuka file arsip
	datambr = fopen("datambr.dat","a+b");
	fread(&mbr.id,sizeof(mbr),1,datambr);
	while (!feof(datambr))
	{
		fflush (stdin);
		fread(&mbr.id,sizeof(mbr),1,datambr);
	}
	fclose(datambr);
	mbr.id++;
	datambr = fopen("datambr.dat","a+b");
	gotoxy(40,21),printf("Tambah Member\n");
	
	gotoxy(40,24),printf ("ID Member\t: MBR%i\n",mbr.id);
	
	gotoxy(40,25),printf ("NIK\t\t: ");getteksnum(mbr.nik,16);fflush(stdin);
	gotoxy(40,26),printf ("Nama Lengkap\t: ");getletter(mbr.nama,15);fflush(stdin);
	gotoxy(40,27),printf ("Tempat Lahir\t: ");getletter(mbr.tmptlahir,16);fflush(stdin);
	gotoxy(40,29),printf ("TanggalBulanTahun");
	gotoxy(40,30),printf ("Tanggal Lahir\t: ");getteksnum(mbr.tgllahir,8);fflush(stdin);
	gotoxy(40,32),printf ("Nomor Telepon\t: ");getteksnum(mbr.notelp,12);fflush(stdin);
	gotoxy(40,34),printf ("Data Berhasil Ditambahkan");
		
	fwrite (&mbr,sizeof(mbr),1,datambr);
	fclose (datambr);
	
}

void LihatDataMember()
{
	int i;
	int x;
	int baris;

		
	datambr = fopen("datambr.dat","rb");
	
	fread(&mbr,sizeof(mbr),1,datambr);
	
	//system("cls");
	tabelmember();
	setColor(112);
	for(x=35;x<124;x++)
		{
			gotoxy(x,17),printf(" ");
		}
	gotoxy(35,17),printf("ID   ");
	gotoxy(41,17),printf("NIK   ");
	gotoxy(59,17),printf("Nama Lengkap   ");	
	gotoxy(76,17),printf("Tempat Lahir   ");
	gotoxy(91,17),printf("Tanggal Lahir   ");
	gotoxy(108,17),printf("Nomor Telepon   ");

	
	i=19;
	while (!feof(datambr))
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
		for(x=35;x<124;x++)
		{
			gotoxy(x,i),printf(" ");
		}
		gotoxy(35,i), printf("MBR%i",mbr.id);
		gotoxy(41,i), printf("%s",mbr.nik);
		gotoxy(59,i), printf("%s",mbr.nama);
		gotoxy(76,i), printf("%s",mbr.tmptlahir);
		gotoxy(91,i), printf("%s",mbr.tgllahir);
		gotoxy(108,i), printf("%s",mbr.notelp);
		fread (&mbr,sizeof(mbr),1,datambr);
		i++;
	}
	fclose (datambr);
	
}

void UpdateDataMember()
{
	bool found;
	char pil;
	int id1;
	int i;
	typedef struct {
		char notelp1[15];
	} Baru;
	
	Baru Memberbaru;
	
	datambr=fopen("datambr.dat","rb");
	TEMP = fopen("TEMP.dat","wb");
	
	KotakTambahdata();
	gotoxy(40,21),printf("Update Data Member \n");
	gotoxy(40,23),printf("Masukan ID Member : MBR");
	scanf("%i",&id1);
	
		found = false;
	while((!feof(datambr))&&(!found))
	{	
		fread(&mbr,sizeof(mbr),1,datambr);
		if (id1==mbr.id)
		{
			found = true;
		}
		else
		{
			fwrite(&mbr,sizeof(mbr),1,TEMP);
		}
	}
	
	if (found == true)
	{
		
		gotoxy(40,25),printf ("Data berhasil ditemukan \n")	;
		gotoxy(40,26),printf("Nama \t\t   : %s\n",mbr.nama);
		gotoxy(40,27),printf("No Telp \t   : %s\n",mbr.notelp);
		
		gotoxy(40,28),printf("No telp baru \t   : ");
		getteksnum(Memberbaru.notelp1,13);//scanf("%s", &Memberbaru.notelp1);
		strcpy(mbr.notelp,Memberbaru.notelp1); fflush(stdin);
		
		fwrite (&mbr,sizeof(mbr),1,TEMP);
		fread(&mbr,sizeof(mbr),1,datambr);
		while (!feof(datambr))
		{
			fwrite(&mbr,sizeof(mbr),1,TEMP);
			fread(&mbr,sizeof(mbr),1,datambr);
		}
		
		gotoxy(40,30),printf("Loading..\n");
		Sleep(1500);
		gotoxy(40,31),printf("Sukses Mengupdate Data ");
		
		fclose (datambr);
		fclose (TEMP);
	
		TEMP = fopen ("TEMP.dat","rb");
		datambr = fopen("datambr.dat","wb");
	
		fread (&mbr,sizeof(mbr),1,TEMP);
		while (!feof(TEMP))
		{
			fwrite(&mbr,sizeof(mbr),1,datambr);
			fread (&mbr,sizeof(mbr),1,TEMP);
		}
		
		fclose(datambr);
		fclose (TEMP);
		
	}
	else
	{
		gotoxy(40,26),printf ("Data yang anda masukan salah \n");
		fclose(datambr);
		fclose(TEMP);
	}
}

void HapusDataMember()
{
	bool found;
	int id1;
	int i;
	char pil;
	char confirm;
	
	datambr = fopen("datambr.dat","rb");
	TEMP = fopen("TEMP.dat","wb");
	
	KotakTambahdata();
	gotoxy(40,21),printf("Hapus Data Member\n");
	gotoxy(40,23),printf("Masukan ID member : MBR");
	scanf("%i",&id1);

	found = false;
	fread(&mbr,sizeof(mbr),1,datambr);
	while((!feof(datambr)&&(!found)))
	{
		if (id1==mbr.id)
		{
			found = true;
		}
		else 
		{
			fwrite(&mbr,sizeof(mbr),1,TEMP);
		}
		fread(&mbr,sizeof(mbr),1,datambr);
	}
	if (found == true)
	{
		gotoxy(40,25),printf("Data berhasil ditemukan ");
		gotoxy(40,26),printf("ID Member \t: MBR%i",mbr.id);
		gotoxy(40,27),printf("Nama Lengkap\t: %s",mbr.nama);
		gotoxy(40,28),printf("NIK\t\t: %s",mbr.nik);
		gotoxy(40,29),printf("Tempat Lahir\t: %s",mbr.tmptlahir);
		gotoxy(40,30),printf("Tanggal Lahir\t: %s",mbr.tgllahir);
		gotoxy(40,31),printf("Nomor telepon \t: %s",mbr.notelp);
		

		KotakTanya();
		gotoxy(89,20),printf("Ingin menghapus data (y/t) ?");		
		gotoxy(89,22),printf("Jawaban : "); scanf("%s",&pil);
		if (pil == 'Y' || pil == 'y')
		{
			gotoxy(40,33),printf("Loading . . \n");
			Sleep(1000);
			fread(&mbr,sizeof(mbr),1,datambr);
			while(!feof(datambr))
			{
				fwrite(&mbr,sizeof(mbr),1,TEMP);
				fread(&mbr,sizeof(mbr),1,datambr);
			}
			fclose (TEMP);
			fclose(datambr);
	
			datambr = fopen ("datambr.dat","wb");
			TEMP = fopen ("TEMP.dat","rb");
		
			fread(&mbr,sizeof(mbr),1,TEMP);
			while (!feof(TEMP))
			{
				fwrite(&mbr,sizeof(mbr),1,datambr);
				fread(&mbr,sizeof(mbr),1,TEMP);
			}
			fclose(datambr);
			fclose(TEMP);
			
			gotoxy(40,33),printf ("Data telah dihapus\n");
			/*printf("kembali ke menu utama?<y/t>");
			scanf("%s",&Pil);
			if(Pil=='y' || Pil=='Y')
			{
				exit(2);
			}
			else
			{
				exit(2);
			}*/
		}
		else
		{
			//MenuMember();
		}
	}
	else 
	{
		gotoxy(40,26),printf("Data tidak ditemukan");
		fclose(datambr);
		fclose(TEMP);
		/*gotoxy(40,24),printf("Ingin Coba Lagi?<y/t>");
		gotoxy(40,25),printf("Jawaban Anda :");scanf("%s",&pil);
		gotoxy(40,21),printf("                                   ");
		gotoxy(40,23),printf("                                   ");
		gotoxy(40,24),printf("                                   ");
		gotoxy(40,25),printf("                                   ");
		gotoxy(75,18),printf("                                   ");
		gotoxy(75,19),printf("                                   ");
		if(pil== 'y' || pil== 'Y')
		{
			HapusDataMember();
		}
		else
		{
			MenuMember();
		}*/
		/*printf("kembali ke menu utama?<y/t>");
			scanf("%s",&Pil);
			if(Pil=='y' || Pil=='Y')
			{
				exit(2);
			}
			else
			{
				exit(2);
			}*/
		
	}
}




void gotoxy(int x, int y);
void DesainUtama();
void pembuka();
void fullscreen();
void KotakLogin();
void KotakTambahdata();
void penutup();
void tabel();
void tabelkereta();
void tabelmember();
void tabeltransaksi();
void tabelpembayaran();
void KotakTambah();
void KotakTanya();
void KotakTanyaLiat();
void KotakTanyaLiatKereta();
void getRp();
void rupiah();


void gotoxy(int x, int y)
{
	COORD tempat = {x,y}; //COORD=tipe data; TEMPAT= variabel {menentukan koordinat sel karakter di layar konsole}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),tempat);//menghandle ke standar output
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void setColor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void printFile(char file[], int x, int y)
{
	FILE *ffile;
	int n = 200;
	char data[n];
	if((ffile=fopen(file, "r")) == NULL){
		system("CLS");
		puts("Can't open file");
		return;
	}
	while(fgets(data, n, ffile)){
		gotoxy(x, y);
		printf("%s", data);
		y++;
	}
	fclose(ffile);
}

void pembuka()
{
	int i;
	printFile("selamatdatang.txt",40,1);
	printFile("StasiunHarapan.txt",37,14);
	printFile("SH2.txt",0,24);
		//Pojok Kiri
	gotoxy(0,0); printf("\xc9");
		//Pojok  Kanan
	gotoxy(166,0); printf("\xbb");
	//pojok kiri bawah
	gotoxy(0,46); printf("\xc8");
	//pojok kanan bawah
	gotoxy(166,46); printf("\xbc");
	//garis atas, bawah, tengah
	
	time_t t = time(NULL);
	struct tm tm = * localtime(&t);
	gotoxy(7, 5); printf("NOW : %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	for(i=1;i<=165;i++)
	{
		gotoxy(i,0),printf("\xcd"); //atas
		gotoxy(i,1),printf("\xcd");
		gotoxy(i,10),printf("\xcd"); //tengah
		gotoxy(i,11),printf("\xcd");
		gotoxy(i,45),printf("\xcd"); //bawah
		gotoxy(i,46),printf("\xcd");
	}
	for(i=1;i<=45;i++)
	{
		gotoxy(0,i),printf("\xba");//kiri
		gotoxy(166,i),printf("\xba");//kanan
	}	
	for(i=60;i<=112;i++)//untuk kotak tengah
	{
		gotoxy(i,34),printf("%c",205);//untuk kotak atas
		gotoxy(i,42),printf("%c",205);//bawah
	}
	for(i=34;i<=42;i++)//kotak tengah
	{
		gotoxy(60,i),printf("%c",205);//kiri
		gotoxy(112,i),printf("%c",205);//kanan
	}
	gotoxy(81, 36), printf("CREATED BY :");
	gotoxy(78, 38), printf("FARHAN DARMAWAN");
	gotoxy(76, 39), printf("MUHAMMAD FATHIN FADILLAH");
	

	
}

void DesainUtama()
{
	int i;
	printFile("StasiunHarapanAtas.txt",48,1);
	printFile("SH.txt",4,1);
	
	time_t t = time(NULL);
	struct tm tm = * localtime(&t);
	gotoxy(7, 14); printf("%d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	//garis kiri, kanan, tengah
	for(i=0;i<=45;i++)
	{
		gotoxy(1,i),printf("%c%c",219,219);//kiri
		gotoxy(166,i),printf("%c%c",219,219);//kanan
		gotoxy(29,i),printf("%c%c",219,219);//tengah
	}
	
	//kotak pinggir pilihan menu 
	for(i=18;i<=32;i++)
	{
		gotoxy(5,i),	printf("%c",219);//sebelah atas
		gotoxy(26,i),	printf("%c",219);//sebelah bawah
	}
	for(i=5;i<=26;i++)
	{
		gotoxy(i,18),	printf("%c",219);//sebelah kiri
		gotoxy(i,32),	printf("%c",219);//sebelah kanan
	}
	//garis atas, bawah, tengah
	for(i=1;i<=165;i++)
	{
		gotoxy(i,0),	printf("%c%c",219,219); //atas
		gotoxy(i,10),	printf("%c",219); //tengah
		gotoxy(i,45),	printf("%c",219); //bawah
	}
	//logobawah
	for(i=38;i<44;i++)
	{
		gotoxy(7,i),	printf("%c",179); //garis kiri gambar
		gotoxy(24,i),	printf("%c",179); //garis kanan gambar
	}
	for(i=8;i<24;i++)	
	{
		
		gotoxy(i,37),	printf("%c",95); //garis atas gambar
	}
	gotoxy(8,43),	printf("%c%c%c",95,95,95); //garis bawah gambar
	gotoxy(21,43),	printf("%c%c%c",95,95,95); //garis bawah gambar
	//Logo di bawah
	for(i=40;i<44;i++)
	{
		gotoxy(11,i),	printf("%c",179); //garis kiri M
		gotoxy(20,i),	printf("%c",179); //garis kanan M
		gotoxy(12,40),	printf("%c",92); //garis miring kekiri
		gotoxy(13,41),	printf("%c",92);
		gotoxy(14,42),	printf("%c",92);
		gotoxy(15,43),	printf("%c",92);
		gotoxy(16,43),	printf("%c",47); //garis miring kekanan
		gotoxy(17,42),	printf("%c",47);
		gotoxy(18,41),	printf("%c",47);
		gotoxy(19,40),	printf("%c",47);
		gotoxy(18,37),	printf("%c",179); //garis tentengan berdiri
		gotoxy(13,37),	printf("%c",179); 
		gotoxy(17,36),	printf("%c",92);
		gotoxy(14,36),	printf("%c",47);
		gotoxy(16,35),	printf("%c",95); //garis puncak
		gotoxy(15,35),	printf("%c",95);
	}
	
	
}

void KotakLogin()
{
	int i;
	 //kiri kanan luar 
	for(i=21;i<=31;i++)
	{
		gotoxy(62,i),	printf("%c%c",219,219);
		gotoxy(111,i),	printf("%c%c",219,219);
	}
	//pinggir kanan 
	for(i=62;i<=111;i++)
	{
		gotoxy(i,21),	printf("%c%c",219,219); 
		gotoxy(i,31),	printf("%c%c",219,219);
	}
	//atas bawah tenah dalem
	for(i=66;i<=108;i++)
	{
		gotoxy(i,24), 	printf("%c",205);
		gotoxy(i,26), 	printf("%c",205);
		gotoxy(i,28),	printf("%c",205);
	}
	//pinggir atas
	gotoxy(65,24), 	printf("%c", 201);
	gotoxy(109,24),	printf("%c", 187);
	
	//pinggir bawah
	gotoxy(65,28), 	printf("%c", 200);
	gotoxy(109,28), printf("%c", 188);
	
	//samping dalem
	gotoxy(65,25), 	printf("%c", 186);
	gotoxy(109,25), printf("%c", 186);
	gotoxy(65,26), 	printf("%c", 186);
	gotoxy(109,26), printf("%c", 186);
	gotoxy(65,27), 	printf("%c", 186);
	gotoxy(109,27), printf("%c", 186);	
	
	
}
void KotakTambahdata()
{
	int i;
	//pinggir kotak atas

	gotoxy(36,19), 	printf("%c", 201);
	gotoxy(79,19),	printf("%c", 187);
	
	//Atas bawah
	for(i=37;i<=78;i++)
	{
		gotoxy(i,19),	printf("%c",205);
		gotoxy(i,38),	printf("%c",205); 
	}
	
	//pinggir kotak bawah
	
	gotoxy(36,38), 	printf("%c", 200);
	gotoxy(79,38), 	printf("%c", 188);
	
	//Kiri Kanan
	for(i=20;i<=37;i++)
	{
		gotoxy(36,i), printf("%c", 186);
		gotoxy(79,i), printf("%c", 186);
	}
}
void KotakTanya()
{
	int i;
	for(i=87;i<=125;i++)
	{
		gotoxy(i,19),	printf("%c",205);
		gotoxy(i,21),	printf("%c",205); 
		gotoxy(i,23),	printf("%c",205);
	}
	//samping
	for(i=20;i<=23;i++)
	{
		gotoxy(86,i), printf("%c", 186);
		gotoxy(86,i), printf("%c", 186);
		gotoxy(86,i), printf("%c", 186);
		gotoxy(126,i), printf("%c", 186);
		gotoxy(126,i), printf("%c", 186);
		gotoxy(126,i), printf("%c", 186);
	}

	//pinggir atas
	gotoxy(86,19), 	printf("%c", 201);
	gotoxy(126,19),	printf("%c", 187);
	
	//pinggir bawah
	gotoxy(86,23), 	printf("%c", 200);
	gotoxy(126,23), printf("%c", 188);
	
}

void KotakTanyaLiat()
{
	int i;
	for(i=108;i<=146;i++)
	{
		gotoxy(i,19),	printf("%c",205);
		gotoxy(i,21),	printf("%c",205); 
		gotoxy(i,23),	printf("%c",205);
	}
	//samping
	for(i=20;i<=23;i++)
	{
		gotoxy(107,i), printf("%c", 186);
		gotoxy(107,i), printf("%c", 186);
		gotoxy(107,i), printf("%c", 186);
		gotoxy(147,i), printf("%c", 186);
		gotoxy(147,i), printf("%c", 186);
		gotoxy(147,i), printf("%c", 186);
	}

	//pinggir atas
	gotoxy(107,19), 	printf("%c", 201);
	gotoxy(147,19),	printf("%c", 187);
	
	//pinggir bawah
	gotoxy(107,23), 	printf("%c", 200);
	gotoxy(147,23), printf("%c", 188);
	
}

void KotakTanyaLiatKereta()
{
	int i;
	//atas
	for(i=123;i<=161;i++)
	{
		gotoxy(i,19),	printf("%c",205);
		gotoxy(i,21),	printf("%c",205); 
		gotoxy(i,23),	printf("%c",205);
	}
	//samping
	for(i=20;i<=23;i++)
	{
		gotoxy(123,i), printf("%c", 186);
		gotoxy(123,i), printf("%c", 186);
		gotoxy(123,i), printf("%c", 186);
		gotoxy(161,i), printf("%c", 186);
		gotoxy(161,i), printf("%c", 186);
		gotoxy(161,i), printf("%c", 186);
	}

	//pinggir atas
	gotoxy(123,19), 	printf("%c", 201);
	gotoxy(161,19),	printf("%c", 187);
	
	//pinggir bawah
	gotoxy(123,23), 	printf("%c", 200);
	gotoxy(161,23), printf("%c", 188);
	
}

void KotakTanyaLiatMember()
{
	int i;
	for(i=128;i<=160;i++)
	{
		gotoxy(i,19),	printf("%c",205);
		gotoxy(i,21),	printf("%c",205); 
		gotoxy(i,23),	printf("%c",205);
	}
	//samping
	for(i=20;i<=23;i++)
	{
		gotoxy(128,i), printf("%c", 186);
		gotoxy(128,i), printf("%c", 186);
		gotoxy(128,i), printf("%c", 186);
		gotoxy(160,i), printf("%c", 186);
		gotoxy(160,i), printf("%c", 186);
		gotoxy(160,i), printf("%c", 186);
	}

	//pinggir atas
	gotoxy(128,19), 	printf("%c", 201);
	gotoxy(160,19),	printf("%c", 187);
	
	//pinggir bawah
	gotoxy(128,23), 	printf("%c", 200);
	gotoxy(160,23), printf("%c", 188);
	
}

void tabel()
{
	int i;
	for(i=34;i<=98;i++)
	{
		gotoxy(i,16), printf("%c", 205);
		gotoxy(i,18), printf("%c", 205);
	}
}

void tabelkereta()
{
	int i;
	for(i=34;i<=119;i++)
	{
		gotoxy(i,16), printf("%c", 205);
		gotoxy(i,18), printf("%c", 205);
	}
}

void tabelmember()
{
	int i;
	for(i=34;i<=124;i++)
	{
		gotoxy(i,16), printf("%c", 205);
		gotoxy(i,18), printf("%c", 205);
	}
}

void tabeltransaksi()
{
	int i;
	for(i=34;i<=104;i++)
	{
		gotoxy(i,16), printf("%c", 205);
		gotoxy(i,18), printf("%c", 205);
	}
}

void tabelpembayaran()
{
	int i;
	for(i=34;i<=98;i++)
	{
		gotoxy(i,16), printf("%c", 205);
		gotoxy(i,18), printf("%c", 205);
	}
}

void KotakTambah()
{
	int i,j;
	//Pojok Kiri
	gotoxy(39,16); printf("\xc9");
	//Atas
	for(i=39; i<=79; i++)
	{
		gotoxy(i,16); printf("\xcd");
	}
	
	//Pojok  Kanan
	gotoxy(80,16); printf("\xbb");
	
	//Kanan
	for(j=17; j<=28; j++)
	{
		gotoxy(80,j); printf("\xba");
	}
	//kiri
		for(j=17; j<=28; j++)
	{
		gotoxy(38,j); printf("\xba");
	}
	//pojok kiri bawah
	gotoxy(38,j); printf("\xc8");
	//bawah
	for(i=39; i<=79; i++)
	{
		gotoxy(i,29); printf("\xcd");
	}
	
	gotoxy(80,29); printf("\xbc");
	
}

void penutup()
{
	system("cls");
	printFile("terimakasih.txt",20,50);
	getch();
}

void rupiah(int number, char output[])
{
	// menampilkan Bentuk Rupiah
	if(number < 1000) sprintf(output, "%d", number);
    else if(number < 1000000) sprintf(output, "%d.%03d", number/1000, number%1000);
    else if(number < 1000000000) sprintf(output, "%d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
    else sprintf(output, "%d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
}



#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <time.h>
using namespace std;
int sinifsayi = 0;
int ogrlimit = 0;
char solUstKose = 201;
char duz = 205;
char sagUstKose = 187;
char solAltKose = 200;
char sagAltKose = 188;
char dikey = 186;
class Ogrenci
{
private:
	string isim, soyisim, numara;
public:
	string getisim()
	{
		return isim;
	}
	string getsoyisim()
	{
		return soyisim;
	}
	string getnumara()
	{
		return numara;
	}
	void setisim(string Isim)
	{
		isim = Isim;
	}
	void setsoyisim(string Soyisim)
	{
		soyisim = Soyisim;
	}
	void setnumara(string no)
	{
		numara = no;
	}

public:void ogrenciolustur()
{
	ifstream DosyaOku("isimler.txt");
	int sayi;
	srand(time(0));
	sayi = rand() % (4940 - 1) + 1;
	for (int i = 0; i < sayi; i++)
	{
		DosyaOku >> isim;
	}
	cout << isim;
	DosyaOku.close();
	ifstream DosyaOku_1("soyisimler.txt");
	sayi = rand() % 278;
	for (int i = 0; i < sayi; i++)
	{
		DosyaOku_1 >> soyisim;
	}
	cout << " " << soyisim;
}
};
class DosyaYonetim
{
public:
	string rastisim()
	{
		srand(time(NULL));
		int random = rand() % dosyauzunlukrastgele("isimler.txt");
		int sayac = 0;
		ifstream oku;
		oku.open("isimler.txt");
		string s;
		while (oku >> s)
		{
			if (random == sayac)
			{
				return s;
			}
			sayac++;
		}
	}
	string rastsoyisim()
	{
		srand(time(NULL));
		int random = rand() % dosyauzunlukrastgele("soyisimler.txt");
		int sayac = 0;
		ifstream oku;
		oku.open("soyisimler.txt");
		string s;
		while (oku >> s)
		{
			if (random == sayac)
			{
				return s;
			}
			sayac++;
		}
	}
	string rastnumara()
	{
		int numara;
		numara = rand() % 100 + 100;
		return to_string(numara);
	}
	int dosyauzunlukrastgele(string dosyaYolu)
	{
		ifstream oku;
		oku.open(dosyaYolu);
		string text;
		int dosyaUzunlugu = 0;
		while (oku >> text)
		{
			dosyaUzunlugu++;
		}
		return dosyaUzunlugu;
	}
};
class Sinif
{
private:
public:
	string sinifisim;
	Ogrenci ogrencidizi[100];
	int ogrencisayi = 0;
	Sinif()
	{
		srand(time(NULL));
		char harfler[] = "ABCDEFGHIJKLMNOPQRSTYVWXUZ";
		char sinifKarakter = harfler[rand() % 25];
		sinifisim = to_string(sinifsayi) + sinifKarakter;
	}

	void ogrenciEkle(Ogrenci ogr)
	{
		ogrencidizi[ogrencisayi] = ogr;
		ogrencisayi++;
	}

	void ogrenciSil(string no)
	{
		for (int i = 0; i < ogrencisayi; i++)
		{
			if (no == ogrencidizi[i].getnumara())
			{
				for (int j = i; j < ogrencisayi; j++)
				{
					ogrencidizi[j] = ogrencidizi[j + 1];
				}
				ogrencisayi--;
			}
		}
	}
};

class Okul
{
private:
public:
	Sinif sinifdizi[20];
	string suanki[1000];
	int suankiindex = 0;
	int ogrenciSayisi = 0;
	Okul()
	{
		ifstream oku;
		oku.open("kayitlar.txt");
		string s;
		while (oku >> s)
		{
			suanki[suankiindex] = s;
			suankiindex++;
		}
		for (int i = 0; i < suankiindex; i++)
		{
			sinifdizi[sinifsayi].sinifisim = suanki[i];
			i++;
			ogrenciSayisi = 0;
			int index = stoi(suanki[i]);
			for (int j = 0; j < index; j++)
			{
				i++;
				sinifdizi[sinifsayi].ogrencidizi[j].setisim(suanki[i]);
				i++;
				sinifdizi[sinifsayi].ogrencidizi[j].setsoyisim(suanki[i]);
				i++;
				sinifdizi[sinifsayi].ogrencidizi[j].setnumara(suanki[i]);
				ogrenciSayisi++;
				sinifdizi[sinifsayi].ogrencisayi = ogrenciSayisi;
			}
			sinifsayi++;
		}
	}
public:void ustYazdir(int elemanSayisi)
{

	cout << solUstKose;
	for (int i = 0; i < elemanSayisi; i++) {
		cout << duz;
	}
	cout << sagUstKose;
}
public:void altYazdir(int elemanSayisi)
{
	cout << solAltKose;
	for (int i = 0; i < elemanSayisi; i++) {
		cout << duz;
	}
	cout << sagAltKose;
}

	  void ekranaYazdir()
	  {

		  for (int i = 0; i < sinifsayi; i++)
		  {
			  ustYazdir(14);
		  }
		  cout << endl;
		  for (int i = 0; i < sinifsayi; i++)
		  {
			  cout << dikey << "      " << sinifdizi[i].sinifisim << "      " << dikey;
		  }
		  cout << endl;
		  for (int i = 0; i < sinifsayi; i++)
		  {
			  altYazdir(14);
		  }
		  cout << endl << endl;
		  for (int j = 0; j < ogrlimit; j++)
		  {
			  for (int i = 0; i < sinifsayi; i++)
			  {
				  cout << setw(15) << left << sinifdizi[i].ogrencidizi[j].getisim();
			  }
			  cout << endl;
			  for (int i = 0; i < sinifsayi; i++)
			  {
				  cout << setw(15) << left << sinifdizi[i].ogrencidizi[j].getsoyisim();
			  }
			  cout << endl;
			  for (int i = 0; i < sinifsayi; i++)
			  {
				  cout << setw(15) << left << sinifdizi[i].ogrencidizi[j].getnumara();

			  }
			  cout << endl << endl;
		  }
	  }

	  void dosyayaYazdir()
	  {
		  ofstream yaz;
		  yaz.open("kayitlar.txt");
		  int count = 0;
		  while (count < sinifsayi)
		  {

			  yaz << sinifdizi[count].sinifisim << endl;
			  yaz << sinifdizi[count].ogrencisayi << endl;
			  for (int i = 0; i < sinifdizi[count].ogrencisayi; i++)
			  {
				  yaz << sinifdizi[count].ogrencidizi[i].getisim() + " " +
					  sinifdizi[count].ogrencidizi[i].getsoyisim() + " " +
					  sinifdizi[count].ogrencidizi[i].getnumara() << endl;
			  }
			  count++;
		  }
	  }
};
class Program
{
private:
public:
	Okul okul;
	DosyaYonetim dosya;
	void calistir()
	{
		okul.ekranaYazdir();
		menuyazdir();
		int secim = 0;
		cin >> secim;
		menuislem(secim);
	}
	void menuyazdir()
	{
		cout << "\n1.Ogrenci Ekle" << endl
			<< "2.Sinif Ekle" << endl
			<< "3.Ogrenci Degistir" << endl
			<< "4.Ogrenci Sil" << endl
			<< "5.Sinif Sil" << endl
			<< "6.Cikis" << endl;;
	}
	void menuislem(int input)
	{
		switch (input)
		{
		case 1:
			menuogrekle();
			break;
		case 2:
			menusinifekle();
			break;
		case 3:
			menuogrdegistir();
			break;
		case 4:
			menuogrsil();
			break;
		case 5:
			menusinifsil();
			break;
		case 6:
			menucikis();
			break;
		}
	}
	void menuogrekle()
	{
		string sinifAdi;
		string isim, soyisim, numara;
		int ogrSira;
		cout << "Sinif adi: ";
		cin >> sinifAdi;
		for (int i = 0; i < sinifsayi; i++)
		{
			if (okul.sinifdizi[i].sinifisim == sinifAdi)
			{
				isim = dosya.rastisim();
				soyisim = dosya.rastsoyisim();
				numara = dosya.rastnumara();

				cout << setw(20) << left << "Ogrenci adi: " << isim << endl;
				cout << setw(20) << left << "Ogrenci soyadi: " << soyisim << endl;
				cout << setw(20) << left << "Ogrenci numarasi: " << numara << endl;
				ogrSira = okul.sinifdizi[i].ogrencisayi;
				okul.sinifdizi[i].ogrencidizi[ogrSira].setisim(isim);
				okul.sinifdizi[i].ogrencidizi[ogrSira].setsoyisim(soyisim);
				okul.sinifdizi[i].ogrencidizi[ogrSira].setnumara(numara);
				okul.sinifdizi[i].ogrencisayi++;
				if (okul.sinifdizi[i].ogrencisayi > ogrlimit)
					ogrlimit++;
				okul.dosyayaYazdir();
				system("pause");
				system("cls");
				calistir();
			}
		}
	}
	void menusinifekle()
	{
		sinifsayi++;
		string sinifIsmi;
		char sinifKarakter = rand() % 26 + 65;
		sinifIsmi = to_string(sinifsayi) + sinifKarakter;
		sinifsayi--;
		okul.sinifdizi[sinifsayi].sinifisim = sinifIsmi;
		sinifsayi++;
		system("cls");
		calistir();
	}
	void menuogrdegistir()
	{
		string ogrenciNo;
		string isim, soyisim, numara;
		cout << "Ogrenci no:";
		cin >> ogrenciNo;
		for (int i = 0; i < sinifsayi; i++)
		{
			for (int j = 0; j < okul.sinifdizi[i].ogrencisayi; j++)
			{
				if (ogrenciNo == okul.sinifdizi[i].ogrencidizi[j].getnumara())
				{
					isim = dosya.rastisim();
					soyisim = dosya.rastsoyisim();
					numara = dosya.rastnumara();

					okul.sinifdizi[i].ogrencidizi[j].setisim(isim);
					okul.sinifdizi[i].ogrencidizi[j].setsoyisim(soyisim);
					okul.sinifdizi[i].ogrencidizi[j].setnumara(numara);
					cout << setw(20) << left << "Ogrenci adi: " << okul.sinifdizi[i].ogrencidizi[j].getisim() << endl;
					cout << setw(20) << left << "Ogrenci soyadi: " << okul.sinifdizi[i].ogrencidizi[j].getsoyisim() << endl;
					cout << setw(20) << left << "Ogrenci numarasi: " << okul.sinifdizi[i].ogrencidizi[j].getnumara() << endl;
					system("pause");
				}
			}
		}
		system("cls");
		calistir();
	}
	void menuogrsil()
	{
		string ogrenciNo;
		cout << "Ogrenci no:";
		cin >> ogrenciNo;
		for (int i = 0; i < sinifsayi; i++)
		{
			okul.sinifdizi[i].ogrenciSil(ogrenciNo);
		}
		system("cls");
		calistir();
	}
	void menusinifsil()
	{
		string sinif;
		cout << "Sinif ismi: ";
		cin >> sinif;
		for (int i = 0; i < sinifsayi; i++)
		{
			if (okul.sinifdizi[i].sinifisim == sinif)
			{
				for (int j = i; j < sinifsayi; j++)
				{
					okul.sinifdizi[j] = okul.sinifdizi[j + 1];
				}
				sinifsayi--;
			}
		}
		system("cls");
		calistir();
	}
	void menucikis()
	{
	}
};
int main()
{
	Program prog;
	prog.calistir();


}
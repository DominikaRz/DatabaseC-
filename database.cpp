#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "struktura.hpp"

using namespace std;

int Menu() {
	int m;
	cout<<"    Baza Zarzadu Transportu Miejskiego"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"1-Wypisz dane"<<endl;
	cout<<"2-Zamien dane"<<endl;
	cout<<"3-Odczyt z pliku"<<endl;
	cout<<"4-Zapisz do pliku"<<endl;
	cout<<"5-Kasowanie danych"<<endl;
	cout<<"6-Pomoc"<<endl;
	cout<<"7-Wyszukaj osoby"<<endl;
	cout<<"8-Sortowanie"<<endl;
	cout<<"9-Autor"<<endl;
	cout<<"10-Koniec"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"Wybierz: "<<endl;
	cin>>m;
	return m;
}

void BazaDanych() {
	const int wt=1000;
	char c='n';
	int rekord;
	Baza Osoba[wt];
	fstream plik;
	string imie, nazwisko;
	int wyb;
	
	do {
		system("cls");
		int wybor=Menu();
		switch(wybor) {
			case 1: system("cls"); //Wypisz dane	
				for(int i=0; i<wt; i++) {
					if(Osoba[i].NrEwid!=0) {
						cout<<" "<<i<<"-Nr: "<<Osoba[i].NrEwid
						<<", Stanowisko: "<<Osoba[i].Stanowisko
						<<", Imie i nazwisko: "<<Osoba[i].Imie
						<<", Nazwisko: "<<Osoba[i].Nazwisko
						<<", Rok urodzenia: "<<Osoba[i].RokUr
						<<", Miejsce zamieszkania: "<<Osoba[i].MiejscZam
						<<", Ulca: "<<Osoba[i].Ulica
						<<", Wyksztalcenie: "<<Osoba[i].Wyksztalcenie
						<<", Stan cywilny: "<<Osoba[i].StanCyw
						<<", Ilosc dzieci: "<<Osoba[i].IloscDzieci<<endl;
					} else break;
				}
				break;
			case 2: system("cls"); //Zamien dane
					cout<<" Nr rekordu: ";
					cin>>rekord;
					cout<<"  Nr: ";                  cin>>Osoba[rekord].NrEwid;                       
					cout<<", Stanowisko: ";          cin>>Osoba[rekord].Stanowisko;                   
					cout<<", Imie: ";                cin>>Osoba[rekord].Imie;
					cout<<", Nazwisko: ";            cin>>Osoba[rekord].Nazwisko;  
					cout<<", Rok urodzenia: ";       cin>>Osoba[rekord].RokUr;                        
					cout<<", Miejsce zamieszkania: ";cin>>Osoba[rekord].MiejscZam;
					cout<<", Ulica: ";               cin>>Osoba[rekord].Ulica;
					cout<<", Wyksztalcenie: ";       cin>>Osoba[rekord].Wyksztalcenie;                
					cout<<", Stan cywilny: ";        cin>>Osoba[rekord].StanCyw;                      
					cout<<", Ilosc dzieci: ";        cin>>Osoba[rekord].IloscDzieci;                  
				break;  
			case 3: system("cls"); //Odczyt z pliku
					plik.open("plik.txt", ios::in);
					if(plik.is_open()) {
						cout<<"Odczytano dane z pliku."<<endl;
						for(int i=0; i<wt; i++) {
							plik>>Osoba[i].NrEwid;
							plik>>Osoba[i].Stanowisko;
							plik>>Osoba[i].Imie;
							plik>>Osoba[i].Nazwisko;
							plik>>Osoba[i].RokUr;
							plik>>Osoba[i].MiejscZam;
							plik>>Osoba[i].Ulica;
							plik>>Osoba[i].Wyksztalcenie;
							plik>>Osoba[i].StanCyw;
							plik>>Osoba[i].IloscDzieci;
						}
						plik.close();
					}else cout<<"Blad otwarcia pliku.";
				break;
			case 4: system("cls"); //Zapisz do pliku
					plik.open("plik.txt", ios::out);
					if(plik.is_open()) {
						cout<<"Zapisano dane do pliku."<<endl;
						for(int i=0; i<wt; i++) {
							plik<<Osoba[i].NrEwid<<" ";
							plik<<Osoba[i].Stanowisko<<" ";
							plik<<Osoba[i].Imie<<" ";
							plik<<Osoba[i].Nazwisko<<" ";
							plik<<Osoba[i].RokUr<<" ";
							plik<<Osoba[i].MiejscZam<<" ";
							plik<<Osoba[i].Ulica<<" ";
							plik<<Osoba[i].Wyksztalcenie<<" ";
							plik<<Osoba[i].StanCyw<<" ";
							plik<<Osoba[i].IloscDzieci<<endl;
						}
						plik.close();
					}else cout<<"Blad zapisu pliku.";
				break;
			case 5: system("cls"); //Kasowanie danych
					cout<<"Nr rekordu do skasowania: ";
					cin>>rekord;
						Osoba[rekord].NrEwid=0;
						Osoba[rekord].Stanowisko="brak";
						Osoba[rekord].Imie="brak";
						Osoba[rekord].Nazwisko="brak";
						Osoba[rekord].RokUr=0;
						Osoba[rekord].MiejscZam="brak";
						Osoba[rekord].Ulica="brak";
						Osoba[rekord].Wyksztalcenie="brak";
						Osoba[rekord].StanCyw="brak";
						Osoba[rekord].IloscDzieci=0;
					cout<<"Pozycja nr: "<<rekord<<" zostala skasowana";
				break;
			case 6: system("cls"); //Pomoc 
					cout<<" Opis pracy z danymi bazy danych."<<endl;
					cout<<"  1-Pobierz dane z pliku."<<endl;
					cout<<"  2-Sprawdz zawartosc basy danych."<<endl;
					cout<<"  3-Dokonaj modyfikacji."<<endl;
					cout<<"  4-Na koniec zapisz dane do pliku."<<endl;
				break;
			case 7: system("cls"); //Wyszukaj osobe
					cout<<" Podaj imie i nazwisko: ";
					cin>>imie>>nazwisko;
					for(int i=0; i<wt; i++) {
						if((imie==Osoba[i].Imie)&(nazwisko==Osoba[i].Nazwisko)) {					
							cout<<"  Nr: "<<Osoba[i].NrEwid;                       
							cout<<", Stanowisko: "<<Osoba[i].Stanowisko;                   
							cout<<", Imie: "<<Osoba[i].Imie;
							cout<<", Nazwisko: "<<Osoba[i].Nazwisko;  
							cout<<", Rok urodzenia: "<<Osoba[i].RokUr;                        
							cout<<", Miejsce zamieszkania: "<<Osoba[i].MiejscZam;
							cout<<", Ulica: "<<Osoba[i].Ulica;
							cout<<", Wyksztalcenie: "<<Osoba[i].Wyksztalcenie;                
							cout<<", Stan cywilny: "<<Osoba[i].StanCyw;                      
							cout<<", Ilosc dzieci: "<<Osoba[i].IloscDzieci;
						}
					}  
				break;	
			case 8: system("cls"); //Sortowanie
					cout<<"Podaj w jakiej kolejnosci chcesz posortowac baze danych."<<endl;
					cout<<"		1 - W kolejnosci do 1 do 1000."<<endl;
					cout<<"		2 - W kolejnosci do 1000 do 1. "<<endl<<endl;
					cout<<"Twoj wybor: ";
					cin>>wyb;
					switch(wyb) {
						case 1: 
							for(int i=0; i<wt; i++) {
								if(Osoba[i].NrEwid!=0) {
									cout<<" "<<i<<"-Nr: "<<Osoba[i].NrEwid
									<<", Stanowisko: "<<Osoba[i].Stanowisko
									<<", Imie i nazwisko: "<<Osoba[i].Imie
									<<", Nazwisko: "<<Osoba[i].Nazwisko
									<<", Rok urodzenia: "<<Osoba[i].RokUr
									<<", Miejsce zamieszkania: "<<Osoba[i].MiejscZam
									<<", Ulca: "<<Osoba[i].Ulica
									<<", Wyksztalcenie: "<<Osoba[i].Wyksztalcenie
									<<", Stan cywilny: "<<Osoba[i].StanCyw
									<<", Ilosc dzieci: "<<Osoba[i].IloscDzieci<<endl;
								}
							} break; 
						case 2: 
							for(int i=wt; i>0; i--) {				
								if(Osoba[i].NrEwid!=0) {
									cout<<" "<<i<<"-Nr: "<<Osoba[i].NrEwid
									<<", Stanowisko: "<<Osoba[i].Stanowisko
									<<", Imie i nazwisko: "<<Osoba[i].Imie
									<<", Nazwisko: "<<Osoba[i].Nazwisko
									<<", Rok urodzenia: "<<Osoba[i].RokUr
									<<", Miejsce zamieszkania: "<<Osoba[i].MiejscZam
									<<", Ulca: "<<Osoba[i].Ulica
									<<", Wyksztalcenie: "<<Osoba[i].Wyksztalcenie
									<<", Stan cywilny: "<<Osoba[i].StanCyw
									<<", Ilosc dzieci: "<<Osoba[i].IloscDzieci<<endl;
								}
							} break; 
						default: system("cls");
					 			cout<<"Bald wyboru. ";	
				break;				
					}  
				break;
			case 9: system("cls"); //Autor
					cout<<" Nazwa: Baza danych"<<endl;
					cout<<" Autor: Dominika Rzepka"<<endl;
					cout<<" Data : 2016.11.19"<<endl;
				break;	
			case 10: system("cls"); //Koniec
					cout<<"Czy na pewno chcesz zamknac baze: [t]ak, [n]ie  ";
					cin>>c;
					if(c=='t') continue; else c='n';
				break;	
			default: system("cls");
					 cout<<"Bald wyboru. ";	
				break;			
		}
		cin.ignore();
		getchar();
	} while(c=='n');
}

int main() {
	BazaDanych();
	return 0;
}

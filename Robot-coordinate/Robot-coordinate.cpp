#include<iostream> //Predprocesorska naredba. Od kompajlera zahtjeva da u program ukljuci biblioteku <iostream> koja omogucava ispis podataka na ekranu ili citanje podataka
#include<cmath> //Zaglavlje <cmath> izjavljuje skup funkcija za racunanje uobicajenih matematickih operacija i transformacija


using namespace std; //Svi elementi standardne C++ biblioteke su deklarirani u ovome što piše namespace sa imenom std.



class Robot { //kreiranje klase Robot

private: //Privatni članovi nisu dostupni izvan klase; njima se može pristupiti samo metodom razreda.
	//deklarisanje varijabli sa double tipom podataka;
	double kordinatax;
	double kordinatay;
	double glavniUgao;
	double alfaUgao, betaUgao;
	const double PI = 3.14;

public: //Javni članovi tvore sučelje klase i dostupni su izvan klase.
	Robot() { //Deklarisanje konstruktora klase. 
		//Konstruktor klase je posebna funkcija klase koja se izvršava kad god kreiramo nove objekte te klase. Konstruktor će imati točno isti naziv kao i klasa i uopće nema povratni tip, čak ni void.
		//Konstruktor klase se poziva kad god se kreiranje objekt klase.
		kordinatax = 0;
		kordinatay = 0;
		glavniUgao = 0;
		alfaUgao = 0;
		betaUgao = 0;
	}
	void Postavi(double x, double y, double ugao) { //deklarisanje funkcije Postavi sa 3 parametra
		kordinatax = x;
		kordinatay = y;
		glavniUgao = ugao;
	}
	void IdiNaprijed(double pomak) {
		//Provjera uglova za pomjeranje robota. Za kretanje tijela po kordinatu se koristi formula za tačku pomicanja kartezijanske koordinate kroz udaljenost u datom smjeru
		//U C++ moramo provjeriti koji je ugao u pitanju kako bi mogli ispisati tacne kordinate i tacku pomjeranja
		if (glavniUgao > 0 && glavniUgao < 90) {
			alfaUgao = glavniUgao;
			betaUgao = 90 - glavniUgao;
			kordinatax += pomak * cos(alfaUgao * PI / 180); //poziavnje fukncije "cos" iz biblioteke "cmath" za izracunavanje kordinate x
			kordinatay += pomak * cos(betaUgao * PI / 180);
		}
		else if (glavniUgao > 90 && glavniUgao < 180) {
			alfaUgao = 180 - glavniUgao;
			betaUgao = glavniUgao - 90;
			kordinatax -= pomak * cos(alfaUgao * PI / 180);
			kordinatay += pomak * cos(betaUgao * PI / 180);
		}
		else if (glavniUgao > 180 && glavniUgao < 270) {
			alfaUgao = glavniUgao - 180;
			betaUgao = 270 - glavniUgao;
			kordinatax -= pomak * cos(alfaUgao * PI / 180);
			kordinatay -= pomak * cos(betaUgao * PI / 180);
		}
		else if (glavniUgao > 270) {
			alfaUgao = 360 - glavniUgao;
			betaUgao = glavniUgao - 270;
			kordinatax += pomak * cos(alfaUgao * PI / 180);
			kordinatay -= pomak * cos(betaUgao * PI / 180);
		}
		else if (glavniUgao == 0) {
			kordinatax += pomak;
		}
		else if (glavniUgao == 90) {
			kordinatay += pomak;
		}
		else if (glavniUgao == 180) {
			kordinatax -= pomak;
		}
		else if (glavniUgao == 270) {
			kordinatay -= pomak;
		}
	}
	void IdiNazad(double pomak) { //Funkcija za pomjeranje robota unazad
		//Slicna kao i u funkcija IdiNaprijed opet se koristi slicna formula za izracunavanje tačke pomicanja kartezijanske koordinate kroz udaljenost u datom smjeru
		if (glavniUgao > 0 && glavniUgao < 90) {
			alfaUgao = glavniUgao;
			betaUgao = 90 - glavniUgao;
			kordinatax -= pomak * cos(alfaUgao * PI / 180);
			kordinatay -= pomak * cos(betaUgao * PI / 180);
		}
		else if (glavniUgao > 90 && glavniUgao < 180) {
			alfaUgao = 180 - glavniUgao;
			betaUgao = glavniUgao - 90;
			kordinatax += pomak * cos(alfaUgao * PI / 180);
			kordinatay -= pomak * cos(betaUgao * PI / 180);
		}
		else if (glavniUgao > 180 && glavniUgao < 270) {
			alfaUgao = glavniUgao - 180;
			betaUgao = 270 - glavniUgao;
			kordinatax += pomak * cos(alfaUgao * PI / 180);
			kordinatay += pomak * cos(betaUgao * PI / 180);
		}
		else if (glavniUgao > 270) {
			alfaUgao = 360 - glavniUgao;
			betaUgao = glavniUgao - 270;
			kordinatax -= pomak * cos(alfaUgao * PI / 180);
			kordinatay += pomak * cos(betaUgao * PI / 180);
		}
		else if (glavniUgao == 0) {
			kordinatax -= pomak;
		}
		else if (glavniUgao == 90) {
			kordinatay -= pomak;
		}
		else if (glavniUgao == 180) {
			kordinatax += pomak;
		}
		else if (glavniUgao == 270) {
			kordinatay += pomak;
		}
	}
	void OkreniSeNaijevo(double noviglavniUgao) { //funkcija za pomjeranje robota u lijevo
		//Na osnovu prethodno unesenog ugla, parametar noviglavniUgao kada se unese ce se sabrati sa tim uglom
		glavniUgao += noviglavniUgao;
		if (glavniUgao > 360) { //Ako je uneseni ugao veci od 360 taj isti ugao oduzimamo sa 360
			glavniUgao = glavniUgao - 360;
		}
	}
	void OkreniSeNadesno(double glavniUgao) {
		//Na osnovu prethodno unesenog ugla, parametar glavniUgao kada se unese ce se oduzeti sa tim uglom
		glavniUgao -= glavniUgao;
		if (glavniUgao < 0) {
			glavniUgao = glavniUgao + 360;
		}
	}
	double DajPozicijuX() {
		return kordinatax; //returnamo kordinatu y
	}
	double DajPozicijuY() {
		return kordinatay; //returnamo kordinatu y
	}
	double DajOrjentaciju() {
		return glavniUgao; //returnamo ugao koji je potreban da bismo odredili orijentaciju
	}
	void Ispisi() { //funkcija za ispis podataka
		cout << "Robot je na poziciji (" << DajPozicijuX() << ", " << DajPozicijuY() << ")\ni gleda pod uglom od " << DajOrjentaciju() << " stepeni u odnosu na x osu.\n";
	}
};

int main() {
	Robot robot; //kreiranjja objekta klase
	int odabirMenija; //deklarisanje varijable
	//do while petlja - odabir menija. U zavisnosti od toga sta korisnik unese tj. koji broj unese taj padajuci meni ce se prikazati i njegove funkcije u konzoli
	do {
		system("cls"); //clear screen funkcija
		cout << "1. Postavi robota\n";
		cout << "2. Idi naprijed\n";
		cout << "3. Idi nazad\n";
		cout << "4. Okreni se na lijevo\n";
		cout << "5. Okreni se na desno\n";
		cout << "6. Ispisi\n";
		cout << "0. KRAJ\n";
		cout << "Unesite izbor: ";
		cin >> odabirMenija;
		cin.ignore();

		if (odabirMenija == 1) {
			system("cls");
			double x, y, glavniUgao;
			cout << "Unesite koordinate(x,y) robota:\n";
			cout << "";
			cin >> x >> y;
			cout << "Unesite ugao pod koji robot gleda u odnosu na x osu:\n";
			cin >> glavniUgao;
			cout << "";
			robot.Postavi(x, y, glavniUgao); //pozivanje funkcije Postavi koja se nalazi u klasi Robot
			robot.Ispisi(); //pozivanje funkcije Ispisi koja se nalazi u klasi Robot
			cout << "";
			system("pause>0");
		}
		if (odabirMenija == 2) {
			system("cls");
			double pomak;
			cout << "Unesite pomak\n";
			cout << "";
			cin >> pomak;
			cout << "";
			robot.IdiNaprijed(pomak);
			robot.Ispisi();
			cout << "";
			system("pause>0");
		}
		if (odabirMenija == 3) {
			system("cls");
			double pomak;
			cout << "Unesite pomak\n";
			cout << "";
			cin >> pomak;
			cout << "";
			robot.IdiNazad(pomak);

			robot.Ispisi();
			cout << "";
			system("pause>0");
		}
		if (odabirMenija == 4) {
			system("cls");
			double glavniUgao;
			cout << "Unesite ugao\n";
			cout << "";
			cin >> glavniUgao;
			cout << "";
			robot.OkreniSeNaijevo(glavniUgao);
			robot.Ispisi();
			cout << "";
			system("pause>0");
		
		}
		if (odabirMenija == 5) {
			system("cls");
			double glavniUgao;
			cout << "Unesite ugao\n";
			cout << "";
			cin >> glavniUgao;
			cout << "";
			robot.OkreniSeNadesno(glavniUgao);

			robot.Ispisi();
			cout << "";
			system("pause>0");
		}
		if (odabirMenija == 6) {
			system("cls");
			cout << "";
			robot.Ispisi();
			cout << "";
			system("pause>0");
		}

	} while (odabirMenija != 0);
	return 0; //kraj programa
}


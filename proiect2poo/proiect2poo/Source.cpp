#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#pragma warning(push)
#pragma warning(disable:4996)
using namespace std;

class ParametruIncorect {
private:
	string mesaj;
public:
	ParametruIncorect(string mesaj) {
		this->mesaj = mesaj;
	}
	string getMesajExceptie() {
		return mesaj;
	}

};

class Comenzi {
private:
	char* numeComanda;
	int nrComenzi;
	friend class Tabel;
	friend class Coloane;
public:


	Comenzi() {
		this->nrComenzi = 1;
		this->numeComanda = new char[100];
		strcpy(this->numeComanda, "CREATE");
	}
	Comenzi(int nrComenzi, char* numeComanda) {
		this->nrComenzi = nrComenzi;
		this->numeComanda = new char[strlen(numeComanda) + 1];
		strcpy(this->numeComanda, numeComanda);
	}
	Comenzi(int nrCom) {
		this->nrComenzi = nrCom;
		this->numeComanda = nullptr;
	}
	Comenzi(const Comenzi& c) {
		this->nrComenzi = c.nrComenzi;
		this->numeComanda = new char[strlen(c.numeComanda) + 1];
		strcpy(this->numeComanda, c.numeComanda);
	}
	Comenzi operator=(const Comenzi& com) {
		this->nrComenzi = com.nrComenzi;
		this->numeComanda = new char[strlen(com.numeComanda) + 1];
		strcpy(this->numeComanda, com.numeComanda);
	}
	bool operator!() {
		return!(this->nrComenzi > 1);
	}
	bool operator<=(Comenzi& c) {
		return (this->nrComenzi <= c.nrComenzi);
	}
	friend void parsare(char* comanda);
};
void parsare(char* comanda) {
	char aux[100];
	strcpy(aux, comanda);
	char* identifcomanda = strtok(aux, " ");

	if ((strcmp(identifcomanda, "drop") == 0) || (strcmp(identifcomanda, "DROP") == 0) || (strcmp(identifcomanda, "display") == 0) ||
		(strcmp(identifcomanda, "DISPLAY") == 0) || (strcmp(identifcomanda, "insert") == 0) || (strcmp(identifcomanda, "INSERT") == 0) ||
		(strcmp(identifcomanda, "delete") == 0) || (strcmp(identifcomanda, "DELETE") == 0) || (strcmp(identifcomanda, "create") == 0) ||
		(strcmp(identifcomanda, "CREATE") == 0) || (strcmp(identifcomanda, "select") == 0) || (strcmp(identifcomanda, "SELECT") == 0) ||
		(strcmp(identifcomanda, "update") == 0 || (strcmp(identifcomanda, "UPDATE") == 0)))
	{

		//CREATE 
		if ((strcmp(identifcomanda, "create") == 0) || (strcmp(identifcomanda, "CREATE") == 0)) {

			identifcomanda = strtok(NULL, " ");
			if (identifcomanda == NULL) {
				throw ParametruIncorect("Comanda a fost scrisa gresit!");
			}
			else
			{
				if ((strcmp(identifcomanda, "table") == 0) || (strcmp(identifcomanda, "TABLE") == 0)) {

					identifcomanda = strtok(NULL, " ");

					if (identifcomanda == NULL) {
						throw ParametruIncorect("Comanda a fost scrisa gresit!");

					}
					else {

						if (strlen(identifcomanda) != NULL) {

							identifcomanda = strtok(NULL, " ");

							if ((strcmp(identifcomanda, "((") == 0)) {

								identifcomanda = strtok(NULL, "((");

								if (identifcomanda != NULL) {
									cout << "Comanda realizata cu succes";
								}
								else throw ParametruIncorect("Comanda a fost scrisa gresit!");


							}
							else { throw ParametruIncorect("Comanda a fost scrisa gresit!"); }



						}
					}
				}



			}


		}
		//DROP TABLE 
		if ((strcmp(identifcomanda, "drop") == 0) || (strcmp(identifcomanda, "DROP") == 0)) {

			identifcomanda = strtok(NULL, " ");

			if (identifcomanda == NULL) {
				throw ParametruIncorect("Comanda a fost scrisa gresit!");
			}
			else
			{
				if ((strcmp(identifcomanda, "table") == 0) || (strcmp(identifcomanda, "TABLE") == 0)) {

					identifcomanda = strtok(NULL, " ");

					if (identifcomanda == NULL) {
						throw ParametruIncorect("Comanda a fost scrisa gresit!");

					}
					else {

						if (strlen(identifcomanda) != NULL) {
							cout << "Comanda a fost scrisa corect";


						}
					}
				}



			}


		}

		//display
		if ((strcmp(identifcomanda, "display") == 0) || (strcmp(identifcomanda, "DISPLAY") == 0)) {

			identifcomanda = strtok(NULL, " ");

			if (identifcomanda == NULL) {
				throw ParametruIncorect("Comanda a fost scrisa gresit!");
			}
			else
			{
				if ((strcmp(identifcomanda, "table") == 0) || (strcmp(identifcomanda, "TABLE") == 0)) {

					identifcomanda = strtok(NULL, " ");

					if (identifcomanda == NULL) {
						throw ParametruIncorect("Comanda a fost scrisa gresit!");

					}
					else {

						if (strlen(identifcomanda) != NULL) {
							cout << "Comanda a fost scrisa corect";


						}
					}
				}



			}
		}

		//insert values
		if ((strcmp(identifcomanda, "insert") == 0) || (strcmp(identifcomanda, "INSERT") == 0)) {
			identifcomanda = strtok(NULL, " ");
			if (identifcomanda == NULL) {
				throw ParametruIncorect("Comanda a fost scrisa gresit!");
			}
			else {
				if ((strcmp(identifcomanda, "into") == 0) || (strcmp(identifcomanda, "INTO") == 0)) {
					identifcomanda = strtok(NULL, " ");
					if (identifcomanda == NULL) {
						throw ParametruIncorect("Comanda a fost scrisa gresit!");
					}
					else {
						if (identifcomanda == NULL) {
							throw ParametruIncorect("Comanda a fost scrisa gresit!");
						}
						else {
							identifcomanda = strtok(NULL, " ");
							if ((strcmp(identifcomanda, "VALUES(") == 0) || (strcmp(identifcomanda, "values(") == 0)) {
								if (identifcomanda == NULL) {
									throw ParametruIncorect("Comanda a fost scrisa gresit!");
								}
								else {
									while (identifcomanda != NULL) {
										identifcomanda = strtok(NULL, ",) ' '");

									}
									cout << "Comanda realizata cu succes";

								}

							}

						}

					}


				}
				else throw ParametruIncorect("Comanda a fost scrisa gresit!");


			}
		}

		//delete
		if ((strcmp(identifcomanda, "delete") == 0) || (strcmp(identifcomanda, "DELETE") == 0)) {
			identifcomanda = strtok(NULL, " ");
			if (identifcomanda == NULL) {
				cout << "Comanda a fost introdusa gresit";
			}
			else
			{
				if ((strcmp(identifcomanda, "from") == 0) || (strcmp(identifcomanda, "FROM") == 0)) {
					identifcomanda = strtok(NULL, " ");
					if (identifcomanda == NULL) {
						cout << "Comanda a fost scrisa gresit";
					}
					else {
						identifcomanda = strtok(NULL, " ");
						if (identifcomanda == NULL) {
							cout << "Comanda a fost scrisa gresit";
						}
						else
						{
							if ((strcmp(identifcomanda, "where") == 0) || (strcmp(identifcomanda, "WHERE") == 0)) {
								identifcomanda = strtok(NULL, " ");
								if (identifcomanda == NULL) {
									cout << "Comanda a fost scrisa gresit";
								}
								else {
									identifcomanda = strtok(NULL, " ");
									if (strcmp(identifcomanda, "=") == 0) {
										identifcomanda = strtok(NULL, " ");
										if (identifcomanda == NULL) {
											cout << "Comanda a fost scrisa gresit";
										}
										else
										{
											cout << "Comanda a fost realizata cu succes";
										}
									}
									else cout << "Comanda a fost scrisa gresit";
								}
							}
							else cout << "Comanda a fost scrisa gresit";
						}
					}
				}
				else cout << "Comanda a fost scrisa gresit";
			}

		}

		//select
		if ((strcmp(identifcomanda, "select") == 0) || (strcmp(identifcomanda, "SELECT") == 0)) {

			identifcomanda = strtok(NULL, " ");
			if (identifcomanda == NULL) {
				cout << "Comanda a fost scrisa gresit";
			}
			else {
				if (strcmp(identifcomanda, "(") == 0) {
					identifcomanda = strtok(NULL, " ");
					if (identifcomanda != NULL) {
						identifcomanda = strtok(NULL, " ");
						if (strcmp(identifcomanda, ")") == 0)
						{
							identifcomanda = strtok(NULL, ")");

							if (identifcomanda == NULL) {
								cout << "Comanda a fost scrisa gresit";
							}
							else
							{
								cout << "Comanda a fost realizata cu succes";
							}




						}
						else cout << "Comanda a fost scrisa gresit";

					}
					else cout << "Comanda a fost scrisa gresit";

				}
				else if ((strcmp(identifcomanda, "all") == 0) || (strcmp(identifcomanda, "ALL") == 0)) {
					identifcomanda = strtok(NULL, " ");
					if ((strcmp(identifcomanda, "from") == 0) || (strcmp(identifcomanda, "FROM") == 0)) {
						identifcomanda = strtok(NULL, " ");
						if (identifcomanda == NULL) {
							cout << "Comanda a fost scrisa gresit";
						}
						else {
							cout << "Comanda a fost realizata cu succes";
						}
					}

				}

			}

		}
		//update 
		if ((strcmp(identifcomanda, "update") == 0) || (strcmp(identifcomanda, "UPDATE") == 0)) {
			identifcomanda = strtok(NULL, " ");
			if (identifcomanda == NULL) {
				cout << "Comanda a fost scrisa gresit";
			}
			else
			{
				identifcomanda = strtok(NULL, " ");
				if ((strcmp(identifcomanda, "set") == 0) || (strcmp(identifcomanda, "SET") == 0))
				{
					identifcomanda = strtok(NULL, " ");
					if (identifcomanda != NULL) {
						identifcomanda = strtok(NULL, " ");
						if (strcmp(identifcomanda, "=") == 0) {
							identifcomanda = strtok(NULL, " ");
							if (identifcomanda != NULL) {
								identifcomanda = strtok(NULL, " ");
								if ((strcmp(identifcomanda, "where") == 0) || (strcmp(identifcomanda, "WHERE") == 0)) {
									identifcomanda = strtok(NULL, " ");
									if (identifcomanda != NULL) {
										identifcomanda = strtok(NULL, " ");
										if (strcmp(identifcomanda, "=") == 0) {
											identifcomanda = strtok(NULL, " ");
											if (identifcomanda != NULL)
											{
												cout << "Comanda realizata cu succes";
											}
											else cout << "Comanda a fost scrisa gresit";
										}
										else cout << "Comanda a fost scrisa gresit";
									}
									else cout << "Comanda a fost scrisa gresit";

								}
								else cout << "Comanda a fost scrisa gresit";
							}
							else cout << "Comanda a fost scrisa gresit";
						}
						else cout << "Comanda a fost scrisa gresit";
					}
					else cout << "Comanda a fost scrisa gresit";
				}
				else cout << "Comanda a fost scrisa gresit";
			}


		}
	}
	else throw ParametruIncorect("Comanda a fost scrisa gresit!");

}
class Coloane {
private:
	char* nume;
	char* tip;
	int dimensiune[1000];
	char* valoareImplicita;
	friend class Tabel;
	friend class Comenzi;
public:

	Coloane() {

		this->dimensiune[999] = 0;
		this->nume = nullptr;
		this->tip = nullptr;
		this->valoareImplicita = nullptr;
	}
	Coloane(const char* nume, const  char* tip, int dimensiune, const char* valoareImplicita) {
		this->dimensiune[999] = dimensiune;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
		this->valoareImplicita = new char[strlen(valoareImplicita) + 1];
		strcpy(this->valoareImplicita, valoareImplicita);
	}
	Coloane(char* nume) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->dimensiune[999] = 0;
		this->valoareImplicita = nullptr;
		this->tip = nullptr;
	}
	Coloane(const Coloane& col) {
		this->dimensiune[999] = col.dimensiune[999];
		this->nume = new char[strlen(col.nume) + 1];
		strcpy(this->nume, col.nume);
		this->tip = new char[strlen(col.tip) + 1];
		strcpy(this->tip, col.tip);
		this->valoareImplicita = new char[strlen(col.valoareImplicita) + 1];
		strcpy(this->valoareImplicita, col.valoareImplicita);
	}
	~Coloane() {
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
		if (this->tip != nullptr) {
			delete[] this->tip;
		}

		if (this->valoareImplicita != nullptr) {
			delete[] this->valoareImplicita;
		}

	}
	Coloane& operator= (const Coloane& c) {
		this->dimensiune[999] = c.dimensiune[999];

		if (this->nume != nullptr) {
			delete[] this->nume;
		}
		this->nume = new char[strlen(c.nume) + 1];
		strcpy(this->nume, c.nume);
		if (this->tip != nullptr) {
			delete[] this->tip;
		}
		this->tip = new char[strlen(c.tip) + 1];
		strcpy(this->tip, c.tip);
		if (this->valoareImplicita != nullptr) {
			delete[] this->valoareImplicita;
		}
		this->valoareImplicita = new char[strlen(c.valoareImplicita)] + 1;
		strcpy(this->valoareImplicita, c.valoareImplicita);
		return *this;
	}


	void setNume(char* nume) {
		if (this->nume != nullptr) {
			delete[] this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	char* getNume() {
		return this->nume;
	}
	void setTip(char* tip) {
		if (this->tip != nullptr) {
			delete[] this->tip;
		}
		if (strcmp(tip, "varchar2") == 0)
		{
			this->tip = new char[strlen(tip) + 1];
			strcpy(this->tip, tip);
		}
		else throw "Tip gresit!";
	}
	char* getTip() {
		return this->tip;
	}
	void setDimensiune(int dimensiune) {
		if (this->dimensiune != 0) {
			this->dimensiune[999] = dimensiune;
		}
	}
	int getDimensiune() {
		return this->dimensiune[999];
	}

	void setValoareImplicita(char* valoareImplicita) {
		if (this->valoareImplicita != nullptr) {
			delete[] this->valoareImplicita;
		}
		this->valoareImplicita = new char[strlen(valoareImplicita) + 1];
		strcpy(this->valoareImplicita, valoareImplicita);
	}
	char* getValoareImplicita() {
		return this->valoareImplicita;
	}

	friend istream& operator>>(istream& in, Coloane& c) {
		cout << "Denumire coloana: ";
		char buffer[1000];
		in.get(buffer, 1000);
		c.nume = new char[strlen(buffer) + 1];
		strcpy_s(c.nume, strlen(buffer) + 1, buffer);
		cout << "Tipul: ";
		in.get();
		in.get(buffer, 1000);
		if (c.tip != nullptr) {
			delete[] c.tip;
		}
		if (strcmp(buffer, "varchar2") == 0 || strcmp(buffer, "VARCHAR2") == 0 ||
			strcmp(buffer, "number") == 0 || strcmp(buffer, "NUMBER") == 0) {
			c.tip = new char[strlen(buffer) + 1];
			strcpy_s(c.tip, strlen(buffer) + 1, buffer);
		}
		else {
			cout << " Tip incorect! ";

		}
		cout << "Dimensiunea: ";
		if (c.dimensiune > 0) {
			in >> c.dimensiune[999];
		}
		cout << "Valoarea implicita: ";
		in.get();
		in.get(buffer, 1000);
		if (c.valoareImplicita != nullptr) {
			delete[] c.valoareImplicita;
		}
		c.valoareImplicita = new char[strlen(buffer) + 1];
		strcpy_s(c.valoareImplicita, strlen(buffer) + 1, buffer);

		cout << endl;
		return in;
	}


	friend ostream& operator<<(ostream& out, Coloane& c);

	//void afisareColoane() {
	//	for(int i=0 ; i<this->)
	//	cout << getNume() << " ";
	//	cout << getTip();
	//	cout << "[" << getDimensiune() << "]" << endl;
	//	cout << getValoareImplicita() << endl;
	//}
};



ostream& operator<<(ostream& out, Coloane& c) {
	out << c.getNume() << " ";
	out << c.getTip();
	out << "[" << c.getDimensiune() << "]" << endl;
	out << c.getValoareImplicita() << endl;

	return out;
}


class Tabel {

private:
	string denumire;
	int nrColoane;
	Coloane* coloane;
	friend class Coloane;
	friend class Comenzi;
public:

	Tabel() {
		this->nrColoane = 0;
		this->denumire = denumire;
		this->coloane = nullptr;
	}
	Tabel(string denumire, int nrColoane, Coloane* coloane) {

		this->denumire = denumire;
		this->nrColoane = nrColoane;
		this->coloane = new Coloane[nrColoane];
		for (int i = 0; i < nrColoane; i++)
		{
			this->coloane[i] = coloane[i];
		}
	}
	Tabel(string denumire) {

		this->denumire = denumire;
		this->nrColoane = 0;
		this->coloane = new Coloane[nrColoane];
	}
	Tabel(const Tabel& tab) {
		this->denumire = tab.denumire;
		this->nrColoane = tab.nrColoane;
		this->coloane = new Coloane[tab.nrColoane];
		for (int i = 0; i < tab.nrColoane; i++) {
			this->coloane[i] = tab.coloane[i];
		}
	}
	Tabel& operator=(const Tabel& t) {
		this->denumire = t.denumire;
		this->nrColoane = t.nrColoane;
		if (this->coloane != nullptr) {
			delete[]this->coloane;
		}
		this->coloane = new Coloane[t.nrColoane];
		for (int i = 0; i < t.nrColoane; i++) {
			this->coloane[i] = t.coloane[i];
		}
		return *this;

	}
	friend istream& operator>>(istream& in, Tabel t) {
		cout << "Denumire tabela: ";
		in >> t.denumire;
		cout << "Nr coloane: ";
		in >> t.nrColoane;
		for (int i = 0; i < t.nrColoane; i++) {
			cout << "Coloana: " << t.coloane[i];
			in >> t.coloane[i];
		}
		return in;
	}

	void afisareTabel() {

		cout << this->coloane->getNume();
		for (int i = 0; i < this->nrColoane; i++) {
			cout << this->coloane[i].getTip()[i];
			cout << this->coloane[i].getDimensiune();
			cout << this->coloane[i].getValoareImplicita()[i];
		}

	}
	void setDenumireTabel(string denumire) {
		if (this->denumire.length() > 1) {
			this->denumire = denumire;
		}
	}
	string getDenumireTabel() {
		return this->denumire;
	}
	void setColoaneTabel(int nrColoane, Coloane* coloane) {
		if (nrColoane > 0) {
			if (this->coloane != nullptr) {
				delete[] this->coloane;
			}
			this->coloane = new Coloane[nrColoane];
			for (int i = 0; i < this->nrColoane; i++) {
				this->coloane[i] = coloane[i];
			}
			this->nrColoane = nrColoane;
		}
	}
	int getColoaneTabel() {
		return this->nrColoane;
	}

	Tabel operator+(Coloane c) {
		Tabel t = *this; //facem o copie a lui this in f
		Coloane* aux = new Coloane[t.nrColoane + 1]; //alocam spatiu cu cate elem aveam anterior  + 1, adica acesta nou
		for (int i = 0; i < t.nrColoane; i++) {
			aux[i] = t.coloane[i];  //le copiem in aux
		}
		aux[t.nrColoane] = c; //pe ultima pozitie il adaugam pe pf
		t.nrColoane++;
		if (t.coloane != NULL) {
			delete[] t.coloane;
		}
		t.coloane = aux; //shallow copy 
		return t;
	}
	Tabel operator+=(Coloane c) {
		*this = *this + c;
		return *this;
	}
	friend double operator+(Tabel& t, double x) {
		return t.nrColoane + x;
	}
	friend double operator+(double x, Tabel& t) {
		return t.nrColoane + x;
	}

	explicit operator string() {
		return this->denumire;
	}
	char& operator[](int index) {
		if (index >= 0 && index < this->nrColoane) {
			return this->denumire[index];
		}
		else throw "Indexul primit nu este corect";
	}

	bool operator==(Tabel t) {
		return(this->nrColoane == t.nrColoane);
	}
	void functie(Tabel t) {
		int a = t.nrColoane;
	}
	~Tabel() {
		if (this->coloane != nullptr) {
			delete[]this->coloane;
		}
	}
	friend const Tabel& operator++(Tabel&);

};
const Tabel& operator++(Tabel& t) {
	t.nrColoane++;
	return t;
}

void main() {

	try {
		char c[100];
		while (c != NULL) {
			cin.getline(c, 100);
			parsare(c);
			cout << endl;
		}
		
	}
	catch (ParametruIncorect) {
		cout << "Comanda a fost scrisa gresit!";

	}

}
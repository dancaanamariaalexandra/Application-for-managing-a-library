#include <iostream>
#include <string>

using namespace std;


struct Carte {
	int cod;
	string nume;
	string autor;
	int an;
	bool ok = 0;//cartea nu a fost imprumutata
	string numePersoana;
	bool deleted = 0;
};

struct Persoana{
string numepers;
int cod;
string carteimprumutata[10];
int nrcarti=0;
int carte[10];

};

Carte citesteCarteNoua() {
	int cod;
	int an;
	string nume;
	string autor;

	cout << "Cod identificare: ";
	cin >> cod;
	cout << "Autor: ";
	cin >> autor;
	//getline(cin, autor);
	cout << "Nume: ";
	cin >> nume;
	//getline(cin, nume);
	cout << "An publicatie: ";
	cin >> an;

	//alocare memorie carte

	Carte *carteNoua = new Carte;

	carteNoua->cod = cod;
	carteNoua->autor = autor;
	carteNoua->nume = nume;
	carteNoua->an = an;

	return *carteNoua;

}


Persoana* citestePersoana() {

	string nume;
	cout << "Numele persoanei este :";
	cin >> nume;
	Persoana* persoanaNoua = new Persoana;
	persoanaNoua->numepers = nume;
	return persoanaNoua;

}

void adaugaCarte(Carte* biblioteca, Carte carteNoua, int position) {

	//adaugare carte in biblioteca
	biblioteca[position] = carteNoua;

}

void adaugaPersoana(Persoana* persoane[], Persoana* persoanaNoua, int dimPersoane) {
     
	for (int i = 0; i < dimPersoane; i++) {

		if (persoane[i] == NULL) {
			persoane[i] = persoanaNoua;
			return;
		}
	}

}


void listare(Carte* biblioteca, int lastBookPosition) {
	for (int i = 0; i < lastBookPosition; i++) {
		if (&biblioteca[i] != NULL && biblioteca[i].deleted == 0) {
			cout << biblioteca[i].nume << " " << biblioteca[i].autor << " " << biblioteca[i].an << "/";
		}
	}
	cout << endl;
}


void imprumut(Carte* biblioteca, Persoana* persoane[]){
    int ok = 0;
    int cod;
    string numePersoana;
    int n=10;

    cout << "Cod identificare: ";
    cin >> cod;
    cout << "Nume persoana care imprumuta cartea: ";
    cin >> numePersoana;
    for(int i = 0; i < n; i++){
             for(int j = 0; j < n; j++){
        if(&biblioteca[i] != NULL  && persoane[j] != NULL){
                if(persoane[j]->numepers == numePersoana && biblioteca[i].cod == cod)
				{

                  if (biblioteca[i].ok==0){

                        persoane[j]->carte[persoane[j]->nrcarti]=cod;
                        persoane[j]->nrcarti++;
                        cout<< "Cartea "<<biblioteca[i].cod<<"este imprumutata de persoana "<< persoane[j]->numepers<<" ";}
                else if (biblioteca[i].ok==1){

                    cout<<"Cartea nu a fost imprumutata"<<endl;

                }

             }
        }
    }
    }
    }



void eliminare(Carte* biblioteca, int dimBiblioteca){

   int cod;
    cout << "Introduceti cod identificare: ";
    cin >> cod;
    //cautarea cartii cu id/cod citit:
    for(int i = 0; i < dimBiblioteca; i++){

        if(&biblioteca[i] !=NULL  && biblioteca[i].cod == cod){

            biblioteca[i].deleted = 1;
            //&biblioteca[i]=NULL;

        }

    }

}


void listareC(Carte* biblioteca, int dimBiblioteca) {

	int cod;
	cout << "Introduceti cod identificare: ";
	cin >> cod;

	for (int i = 0; i < dimBiblioteca; i++) {

		if (&biblioteca[i] != NULL && biblioteca[i].cod == cod && biblioteca[i].ok == 0) {

			cout << biblioteca[i].nume << " " << biblioteca[i].autor << " " << biblioteca[i].an << " "
				<< "Cartea nu a fost imprumutata" << endl;
		}
		else {
			cout << biblioteca[i].nume << " " << biblioteca[i].autor << " " << biblioteca[i].an << " "
				<< "Cartea  a fost imprumutata" << endl;
		}
	}
}

void cartiImprumutate(Persoana *persoane[], Carte *biblioteca, int dimPersoana ){



string numepers;
cout << "Numele persoanei este: ";
cin >> numepers;

for(int j=0; j<dimPersoana; j++)
if(persoane[j] != NULL && persoane[j]->numepers==numepers){

    if(persoane[j]->nrcarti != 0)
    {
        cout<< "Persoana cu numele: "<<persoane[j]->numepers<<"a imprumutat cartile cu codul de identificare: ";
        for(int i=0; i<persoane[j]->nrcarti; i++)
        cout<<persoane[j]->carte[i]<<" "<<endl;

    }
    else if(persoane[j]->nrcarti == 0){
        cout<< numepers <<"nu a imprumutat nicio carte."<<endl;
    }
}



}
int main()
{
	char op;
	int n;
	int position = 0;

	cout << "Introduceti numarul de carti din biblioteca: " << endl;
	cin >> n;


	Carte* biblioteca = new Carte[n];
	Persoana *persoane[100];
	for(int i=0; i<100; i++)
	{
	
	 persoane[i] = NULL;
	
	}
	do {
		cout << "Introduceti optiunea: " << endl;
		cout << "A-Adaugarea unei carti in biblioteca: " << endl;
		cout << "L-Listarea tuturor cartilor din biblioteca" << endl;
		cout << "E-Eliminarea unei carti din biblioteca" << endl;
		cout << "C-Listarea informatiilor despre o carte" << endl;
		cout << "B-Adaugare persoane" << endl;
		cout << "I-Imprumutul unei carti catre o persoana" << endl;
		cout << "P-Listarea informatiilor despre o persoana" << endl;
		cout << "Q-Inchide" << endl;
		cin >> op;

		switch (op) {
		case 'A':
			adaugaCarte(biblioteca, citesteCarteNoua(), position);
			position++;
			break;

                    case 'B':
                        adaugaPersoana(persoane,citestePersoana(),n);
                        break;

                    case 'L':
                        listare(biblioteca, n);
                        break;
                    case 'E':
                        eliminare(biblioteca,n);
                        break;
                    case 'I':
                        imprumut(biblioteca,persoane);
                        break;
                    case 'C':
                        listareC(biblioteca,n);
                        break;
                    case 'P':
                        cartiImprumutate(persoane,biblioteca,10);
                        break;

                }



	} while (op != 'Q');
	delete[]biblioteca;
	delete[]persoane;
	return 0;

}

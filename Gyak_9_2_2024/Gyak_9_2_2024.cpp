#include <iomanip> //kiiratáshoz
#include <string> //string kezelés
#include <ctime> //random szám miatt
#include <fstream> //fájl megnyitása
#include <iostream> //konzol kezelés

using namespace std;

struct dolgozo {
    string nev;
    int ev, oraszam, fizetes;
};

int main()
{
    dolgozo majus[20];
    int i, ossz = 0, eletkor = 0, letszam = 0, szaz = 0;

    srand((unsigned)time(NULL)); //véletlen számok generálása miatt minden futtatásnál

    ifstream jelentes("majus.txt");

    for ( i = 0; i < 20 && !jelentes.eof(); i++)
    {
        if (jelentes.is_open()) jelentes >> majus[i].nev;
        else cout << "A file megnyitasa sikertelen";

        do{
            cout << "\nAdja meg " << majus[i].nev << " dolgozo szuletesi evet:";
            cin >> majus[i].ev;
            cin.ignore();
            if (majus[i].ev < 1957 || majus[i].ev > 2004)
                cout << "Hibas adat a szul ev 1957-2004 kozott lehet" << endl;

        } while (majus[i].ev < 1957 || majus[i].ev > 2004);
        majus[i].oraszam = rand() % 160 + 1;
        majus[i].fizetes = majus[i].oraszam * 2800;
        letszam++;
    }
    jelentes.close();

    system("cls");
    cout << "Osszesen " << letszam << " fo dolgozott majusban" << endl;
    //4. eredmenyek tablazatosn

    cout.setf(ios::left);
    for ( i = 0; i < letszam; i++)
    {
        cout << setw(20) << majus[i].nev 
            << setw(10) << majus[i].ev 
            << setw(10) << majus[i].oraszam 
            << setw(10) << majus[i].fizetes 
            << endl;
        ossz = ossz + majus[i].oraszam; //össze óraszám
        if (majus[i].oraszam > 100) szaz++; //hány db 100 óránál töb adat van
        eletkor = eletkor + (2024 - majus[i].ev);
    }

    cout << "\nMajus havi osszes ledolgozott orak szama: " << ossz << endl;
    cout << szaz << " dolgozo teljesitett 100 oranal tobbet" << endl;
    cout << "\nA dolgozok atlag eletkora: " << (float)eletkor / letszam
        << " ev" << endl;

    cout << "\nAz utolso rogzitett dolgozo adatai:" <<
        majus[letszam -1].nev << "\t szuletesi eve: " <<
        majus[letszam -1].ev << "\t majusi oraszama: " <<
        majus[letszam -1].oraszam << "\t majusi  bere: " <<
        majus[letszam -1].fizetes * 1.27 << "Ft " << endl;


    ofstream kesz("majus_teljes.txt");
    if (kesz.is_open())
    {
        for (i = 0; i < letszam; i++)
        {
            kesz << majus[i].nev << " \t";
            kesz << majus[i].ev << " \t";
            kesz << majus[i].oraszam << " \t";
            kesz << majus[i].fizetes << endl;
        }
        kesz.close();
        cout << "A lista sikeresen elkeszult" << endl;
    }
    else cout << "A lista letrehozasa sikertelen" << endl;

    return 0;
}

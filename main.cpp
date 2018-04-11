#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct pakiet
{
    int numer;
    int rozmiar;
};
int main()
{
    int ile_pakietow, ile_bajtow,ost_pakiet=0;
    ifstream in("pakiet.txt",ios::binary);
    ofstream out("zapisane.txt",ios::binary);
    in.seekg(0,ios::end);
    long size = in.tellg();
    in.seekg(0);
    char *buffer = new char [size];
    in.read(buffer,size);
    cout << "Ilu bajtowe chcesz pakiety? ";
    cin >> ile_bajtow;
   if (size%ile_bajtow == 0)
   {
    ile_pakietow= size/ile_bajtow;
    }
   else
   {
       ile_pakietow= size/ile_bajtow+1;
       ost_pakiet = size%ile_bajtow;
   }
    cout << "pakietow: " << ile_pakietow << endl;
    cout <<  "Plik: ";
     for(int i=0;i<size;i++)
    {
        cout   << buffer[i];
    }

// nowy buffer
char* nowybuffer = new char[ile_pakietow * sizeof(pakiet) + size];
cout << endl;
for (int i =0;i < ile_pakietow;i++)
{
    char* mojpakiet = new char[sizeof(pakiet) + ile_bajtow];
pakiet* p =  (pakiet*)mojpakiet;
    p->numer = i+1;
    p->rozmiar = ile_bajtow;
    if (ile_pakietow-1==i && i!=0 && ost_pakiet !=0)
        p->rozmiar = ost_pakiet;
    if (ile_pakietow !=1)
    {
    for (int j = sizeof(pakiet); j < sizeof(pakiet) + ile_bajtow; j++)
		{
			mojpakiet[j] = buffer[j - sizeof(pakiet) + ile_bajtow-1] ;

		}
    }
    else
    {
        for (int j = sizeof(pakiet); j < sizeof(pakiet) + ile_bajtow; j++)
		{
			mojpakiet[j] = buffer[j - sizeof(pakiet)] ;

		}
    }

		for (int k = 0; k < ile_bajtow + sizeof(pakiet); k++)
		{
			nowybuffer[k + i*(sizeof(pakiet)+ile_bajtow)] = mojpakiet[k];
		}
		delete []mojpakiet;
}
cout << endl;
for (int i=0;i< ile_pakietow * sizeof(pakiet) + size ; i++)
    {

        if ((int)nowybuffer[i]>64 && (int)nowybuffer[i] <127)
            cout << " " << nowybuffer[i];
        else
            cout  << " " <<(int) nowybuffer[i];
        out << nowybuffer[i];
    }
in.close();
out.close();
/*char* wypisz = new char[sizeof(pakiet) + ile_bajtow];
for (int j=ile_pakietow * sizeof(pakiet) + size;j> 0 ; j--)
wypisz[j];
int tmp;
pakiet *p = reinterpret_cast<pakiet*>(&nowybuffer[i* (sizeof(pakiet) + ile_bajtow)]);
for (int k=0;k<ile_pakietow;k++)
{
  p->numer < p->numer+1;
  tmp = p->numer+1;
  p->numer+1 = p->numer;
  p->numer = tmp;

}
*/
    return 0;
}

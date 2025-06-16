#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

struct Microsoft
{
    string nev;
    int evszam;
    string kategoria;
    string platform;
};

int main()
{
    //;007: Blood Stone;2010;Action;NintendoDS;
    //; név ; évszám ; kategória ; platform(ok);
    vector<Microsoft> microsoft;
    ifstream file("adat.txt");
    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            Microsoft adat;
            stringstream ss(line);
            ss.ignore(1, ';');
            getline(ss, adat.nev, ';');
            ss >> adat.evszam;
            ss.ignore(1, ';');
            getline(ss, adat.kategoria, ';');
            getline(ss, adat.platform, ';');
            microsoft.push_back(adat);
        }
    }
    else
    {
        cout << "nem tudja megnyitni a fajlt " << endl;
        return 1;
    }
    //cout << microsoft[1318].nev << " "<<  microsoft[1318].evszam << " " <<  microsoft[1318].kategoria << " " <<  microsoft[1318].platform << endl;
    // A a)
    int xbox_szum;
    for(int i = 0; i < microsoft.size(); i++)
    {
        int xbox_e = microsoft[i].platform.find("Xbox360");
        if(xbox_e >= 0)
        {
            if(microsoft[i].evszam < 2005)
            {
                xbox_szum++;
            }
        }

    }
    cout << "A a) xbox_szum: " << xbox_szum << endl;
    cout << endl;
    //A b)
    map<string, int> kateg;
    for (int i= 0; i < microsoft.size(); i++)
    {
        stringstream ss(microsoft[i].platform);
        string plat;
        while(getline(ss, plat, ','))
        {
            plat.erase(0, plat.find_first_not_of(' ')); // vezető space eltávolítása
            kateg[plat] += 1;
        }
    }
    vector<pair<int, string>> vec;
    for (auto iter=kateg.begin(); iter!=kateg.end(); iter++) // vec vektor feltöltése a kateg map tartalmával
    {
        vec.push_back(make_pair(iter->second, iter->first));
    }
    sort(vec.rbegin(), vec.rend()); // mivel helyet cserélt a string és az int, simán lesortolhatjuk az első mezőre
    cout << "A b)" << endl;
	for (auto iter=vec.begin(); iter!=vec.end(); iter++)
	{
		cout << iter->second << ": " << iter->first << endl;
	}


    return 0;
}

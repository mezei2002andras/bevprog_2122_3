#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <string>
#include <set>
//#include <bits/stdc++.h>

using namespace std;

struct Microsoft
{
    string nev;
    int evszam;
    string kategoria;
    string platform;
};
/*
struct comp {
    template <typename T>
 
    // Comparator function
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};

void sort(map<string, int>& M)
{
    set<pair<string, int>, comp> S(M.begin(), M.end());
    for (auto& it : S) 
    {
        cout << it.first << ' ' << it.second << endl;
    }
}
*/
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
    cout << xbox_szum << endl;
    //A b)
    map<string, int> kateg;
    for (int i= 0; i < microsoft.size(); i++)
    {
        stringstream ss(microsoft[i].platform);
        string plat;
        while(getline(ss, plat, ','))
        {
            kateg[plat] += 1;
        }
    }
    //sort(kateg);
    vector<pair<string, int>> vec;
	// copy key-value pairs from the map to the vector
    map<string, int> :: iterator it2;
    for (it2=kateg.begin(); it2!=kateg.end(); it2++) 
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }

	// print the multimap
	cout << "The map, sorted by value is: " << endl;
 	map<string, int> :: iterator iter;
	for (iter=vec.begin(); iter!=vec.end(); iter++) 
	{
		// printing the second value first because the 
		// order of (key,value) is reversed in the multimap
		cout << iter->second << ": " << iter->first << endl; 
	}
    /*for(auto i : kateg)
    {
        cout <<  i.second << "\t" <<i.first << endl;
    }*/
    
    return 0;
}   

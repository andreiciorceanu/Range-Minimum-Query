#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <chrono>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "etapa2.h"
#include "alg1.h"
#include "segment.h"
#include "tournament.h"


#define MAX 1000 //limita maxima a vectorului
#define D  500 //limita tabloului 2D

using namespace std::chrono;
using namespace std;
//Un RMQ rezolva problema gasirii elementului minim dintr un sub-tablou al unui tablou de elemente comparabile
	void readFromFile(vector<int> &V, ifstream& ins) {
		int nr;
		while (ins >> nr) {
			V.push_back(nr);
		}
	} //citim datele din fisierele de intrare



int main(int argc, char *argv[]) {

	ifstream in;
	vector<int> vect;

	in.open(argv[1]);

	readFromFile(vect, in);
	vector<int> vect2(vect);
	string name = argv[1];
	name.replace(5, 4, ".out");

	ofstream out;
	out.open(name);

	int n = vect.size();
	vect = vect2;
	int *st = malloc(vect, n); //construim segment tree
	int qs = 3; //index de start
	int qe = 5; //index de sfarsit
	//afisam val min din intervalul qs qe
	auto start1 = high_resolution_clock::now(); 
	out << "Segment Tree - Minimul din: ["<< qs <<", "<< qe <<"] "<< 
    "este = " << RMQ2(st, n, qs, qe) << endl;
    auto stop1 = high_resolution_clock::now();
    //get execution time
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    out << "Segment execution time: " << duration1.count() << endl;

    auto start2 = high_resolution_clock::now(); 
    int m = vect.size();
    int min = getMinMax(vect, 0, m - 1);
    out << "Tournament Methodo - Minimul este: " << min << endl;
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	out << "Tournament Method execution time :" << duration2.count() << endl;

	auto start3 = high_resolution_clock::now();
    int x = vect.size();
    Query q[] = {0, 3};
    int y = sizeof(q) / sizeof(q[0]);
    out << "Minimul pentru aceasta interogare este: " << Range(vect, x, y, q) << endl;
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    out << "Execution time for this algorithm is: " << duration3.count() << endl;
    //inchidem fisierele
    in.close();
    out.close();
    return 0;
 }

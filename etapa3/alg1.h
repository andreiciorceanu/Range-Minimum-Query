#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

#define MAX 1000 //limita maxima a vectorului
#define D  500 //limita tabloului 2D

using namespace std;

struct Query {
	int L,R;
};
//Metoda banala
//Solutia banala:folosind inca un tablou pentru stocarea minimului din [i,j]
//Gasirea solutiei se face in O(1),dar necesita extra spatiu O(n^2)
//completam cu valorile din interogari
void preprocess(vector<int> &arr, int n);
//afisam minimul fiecarei interogari dintr un interval
int Range(vector<int> &arr, int n, int m, Query q[]);

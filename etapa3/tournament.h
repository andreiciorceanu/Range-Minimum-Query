#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

#define MAX 1000 //limita maxima a vectorului
#define D  500 //limita tabloului 2D

using namespace std;

//Tournament Method
//functie care returneaza minimul dupa impartirea intervalului mare in alte 2 subintervale ca la divide et impera
//dupa care facem comparatiile intre minimele si maximele din cele 2 sub-intervale
int getMinMax(vector<int> &arr, int low, int high);
//functia de main
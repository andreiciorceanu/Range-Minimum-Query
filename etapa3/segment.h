#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

#define MAX 1000 //limita maxima a vectorului
#define D  500 //limita tabloului 2D

using namespace std;
//Segment Tree
//face minimul dintre 2 nr
int minVal(int x, int y);
//returnam valoarea din mijloc dintre 2 nr
int getMid(int x, int y);
//initializam segment tree-ul
int RMQ(int *st, int ss, int se, int qs, int qe, int index);
//returneaza elem minim dintr un interval si se bazeaza pe RMQ
int RMQ2(int *st, int n, int qs, int qe);
//functie care genereaza segment tree-ul dintr un interval
int construct(vector<int> &arr, int ss, int se,int *st, int si);
//alocam memorie pentru segment tree
int *malloc(vector<int> &arr, int n); //returnam pointerul la inceputul segment tree ului
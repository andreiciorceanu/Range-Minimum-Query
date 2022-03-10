#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "segment.h"

//Segment Tree
	int minVal(int x, int y){ //pentru a returna val minima dintre 2 numere
		if( x  < y){
			return x;
		} else {
			return y;
		}
	}

	int getMid(int x, int y) { //pentru a returna valoarea din mijloc dintr un interval
		return x + (y-x)/2;
	}
	//pentru functia de segment tree vom avea nevoie de mai multi pointer:st-pointer la segment tree
	//index -indexul nodului curent in segment tree,se porneste de la radacina care are nodul 0
	//ss & se -indici de inceput/sfarsit pentru segmentul reprezentat de nodul curent
	//qs & qe -indici de inceput/sfarsit pentru interogare
	int RMQ(int *st, int ss, int se, int qs, int qe, int index){ //o fucntie recursiva pentru a gasi minimul dintr un interval de vectori
		if (qs <= ss && qe >= se)  
        return st[index];  //daca segmentul acestui nod este parte din intervalul dat returnam minimul segmentului

    	if(se < qs || ss > qe)
    		return MAX; //daca segmentul acestui nod este inafara intervalului dat
    	//daca o parte a segmentului se suprapune cu intervalul dat
    	int mid = getMid(ss, se);
    	int x, y;
    	x = RMQ(st, ss ,mid ,qs, qe, 2*index + 1);
    	y = RMQ(st, mid + 1, se ,qs, qe, 2 * index +2);
    	return minVal(x, y);
    }

    int RMQ2(int *st, int n, int qs, int qe){ //returneaza elem minim din intervalul cu capetele qe si qs,se bazeaza pe implementarea aterioara de RMQ
    	if (qs < 0 || qe > n-1 || qs > qe)  {  
        return -1;  //verificam daca exista greseli de input,nu respecta termenii intervalului
    	} 

    return RMQ(st, 0, n-1, qs, qe , 0);
	}

	//implementam o functie care va construi segement tree-ul pentru un interval [ss..se]
	int construct(vector<int> &arr, int ss, int se,int *st, int si){
		//si-indicele nodului curent
		//verificam daca avem un singur element in interval
		if(ss == se){
			st[si] = arr[ss];
			return arr[ss];
		}
		//daca sunt mai multe elemente vor imparti tree-ul in 2 sub-treeuri dupa care folosim minVal pentru aflarea minimului
		int mid = getMid(ss, se);
		int a, b;
		a = construct(arr, ss, mid, st, si * 2 + 1);
		b = construct(arr, mid + 1, se, st, si * 2 + 2);
		st[si] = minVal(a, b);
		return st[si];
	}

	//mai avem nevoie de o functie care sa aloce memorie pentru segment tree
	int *malloc(vector<int> &arr, int n) {
		int x = (int)(ceil(log2(n))); //inaltimea segment tree, o sa fie totodata si complexitatea cand ne va lua sa gasim un element prin parcurgerea tree ului

		int maxsize = 2 * (int)(pow(2, x) - 1);
		int *st = new int[maxsize];
		//umplem memoria alocata
		construct(arr , 0, n-1, st, 0);
		return st;
	}
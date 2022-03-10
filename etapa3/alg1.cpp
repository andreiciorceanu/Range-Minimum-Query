#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "alg1.h"

// Solutia banala:folosind inca un tablou pentru stocarea minimului din [i,j]
//Gasirea solutiei se face in O(1),dar necesita extra spatiu O(n^2)

int lookvect[D][D]; //acest vector va stoca in lookvect[i][j] minimul din [i,..j]

	void preprocess(vector<int> &arr, int n) { //completam lookvect cu toate valorile posibile ale interogarilor
		for(int i = 0; i < n; i++)
		lookvect[i][i] = i; //initializam intervalele de lungime 1

		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++)

		if(arr[lookvect[i][j-1]] < arr[j]) //pentru a  gasi minimul din [0,7] comparam arr[lookvect[0][3]] cu arr[4]
		lookvect[i][j] = lookvect[i][j-1];
			else
		lookvect[i][j] = j; //facem un fel de comparatie recursica pentru a gasi minimul
		
	}
}
//printam minimul a m interogari dintr un tablou de genul arr[0..n-1]
	int Range(vector<int> &arr, int n, int m, Query q[]){
		preprocess(arr,n); //construim tablouri pentru toate interogarile
		//facem suma fiecarei interogari
		for(int i = 0; i < m;i++){
			int L = q[i].L; //L si R sunt limitele stanga si dreapta ale noului interval
			int R = q[i].R;
		//returnam suma interogarii curente
			return arr[lookvect[L][R]];
		}
	}


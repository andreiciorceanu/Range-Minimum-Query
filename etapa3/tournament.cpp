#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "tournament.h"


//Tournament Method
	//impartim un interval in 2 parti si comparam minimul si maximul din cele 2 sub-intervale pentru a obtine min si max pentru tot intervalul

	int getMinMax(vector<int> &arr, int low, int high) {
		int min;
		int half1, half2;
		int mid;
		//verificam daca avem doar un elem in interval
		if( low == high) {
			min = arr[low];

			return min;
		}
		//verificam daca avem 2 elemente
		if(low == high - 1){

			if(arr[low] > arr[high]) 
			min = arr[high];

			else
				min = arr[low];
				
			

			return min;
		}
		//caz3: avem mai mult de 2 elem in interval
		mid = (low + high) / 2;
		half1 = getMinMax(arr, low ,mid); //impartim in cele 2 sub-intervale si cautam in continuare minim(ca un fel de divide et impera)
		half2 = getMinMax(arr, mid, high);
		//comparam minimele si maximele din cele 2 parti
		if(half1 < half2) 
			min = half1;
			else
			min = half2;

		return min;
	}
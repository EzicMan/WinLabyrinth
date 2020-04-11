#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv){
	srand(time(nullptr));
	if(argc < 3){
		cout << "Not enough arguments!" << endl;
		return 0;
	}
	int x, y;
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	cout << x << " " << y << endl;
	vector<vector<char>> pole(y);
	for (int i = 0; i < y; i++) {
		pole[i].resize(x);
	}
	vector<pair<int, int>> otv;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			pole[i][j] = 'E';
		}
	}
	int j = 0;
	int i = rand() % y;
	cout << i << endl;
	int povorot;
	int lol;
	while(j != x - 1){
		pole[i][j] = ' ';
		povorot = rand() % 3;
		if(povorot == 0 && i != 0 && pole[i-1][j] != 'W' && pole[i-1][j] != ' '){
			if(j != 0 && pole[i][j-1] != ' ') pole[i][j-1] = 'W';
			if(j < x - 1 && pole[i][j+1] != ' ') pole[i][j+1] = 'W';
			if(i < y - 1 && pole[i+1][j] != ' ') pole[i+1][j] = 'W';
			i--;
		}
		if(povorot == 1 && i < y - 1 && pole[i+1][j] != 'W' && pole[i+1][j] != ' '){
			if(j != 0 && pole[i][j-1] != ' ') pole[i][j-1] = 'W';
			if(j < x - 1 && pole[i][j+1] != ' ') pole[i][j+1] = 'W';
			if(i != 0 && pole[i-1][j] != ' ') pole[i-1][j] = 'W';
			i++;
		}
		if(povorot == 2 && j < x - 1 && pole[i][j+1] != 'W' && pole[i][j+1] != ' '){
			if(i != 0 && pole[i-1][j] != ' ') pole[i-1][j] = 'W';
			if(j != 0 && pole[i][j-1] != ' ') pole[i][j-1] = 'W';
			if(i < y - 1 && pole[i+1][j] != ' ') pole[i+1][j] = 'W';
			j++;
		}
		lol = rand() % 10;
		if(lol == 4 && j != x - 1){
			otv.push_back(make_pair(j,i));
		}
	}
	pole[i][j] = ' ';
	if(i != 0 && pole[i-1][j] != ' ') pole[i-1][j] = 'W';
	if(i < y - 1 && pole[i+1][j] != ' ') pole[i+1][j] = 'W';
	for(int k = 0; k < y; k++){
		if(k != i){
			pole[k][x-1] = 'W';
		}
	}
	int rofl = 0;
	for(int k = 0; k < otv.size(); k++){
		i = otv[k].second;
		j = otv[k].first;
		bool haha = false;
		while(true){
			povorot = rand() % 4;
			if(povorot == 0 && i != 0 && pole[i-1][j] == 'W'){
				i--;
				break;
			}
			if(povorot == 1 && i < y - 1 && pole[i+1][j] == 'W'){
				i++;
				break;
			}
			if(povorot == 2 && j != 0 && pole[i][j-1] == 'W'){
				j--;
				break;
			}
			if(povorot == 3 && j < x - 1 && pole[i][j+1] == 'W' && j != x - 2){
				j++;
				break;
			}
			if (i == 0 && pole[i + 1][j] != 'W' && pole[i][j + 1] != 'W') {
				haha = true;
				break;
			}
			if(i == y - 1 && pole[i-1][j] != 'W' && pole[i][j+1] != 'W'){
				haha = true;
				break;
			}
			if (rofl >= 1000) {
				haha = true;
				break;
			}
			rofl++;
		}
		if(haha) continue;
		int exit = 0;
		while(exit != 1){
			pole[i][j] = ' ';
			povorot = rand() % 4;
			if(povorot == 0 && i != 0 && pole[i-1][j] != 'W' && pole[i-1][j] != ' '){
				if(j != 0 && pole[i][j-1] != ' ')
					pole[i][j-1] = 'W';
				if(j < x - 1 && pole[i][j+1] != ' ')
					pole[i][j+1] = 'W';
				if(i < y - 1 && pole[i+1][j] != ' ')
					pole[i+1][j] = 'W';
				i--;
			}
			if(povorot == 1 && i < y - 1 && pole[i+1][j] != 'W' && pole[i+1][j] != ' '){
				if(j != 0 && pole[i][j-1] != ' ')
					pole[i][j-1] = 'W';
				if(j < x - 1 && pole[i][j+1] != ' ')
					pole[i][j+1] = 'W';
				if(i != 0 && pole[i-1][j] != ' ')
					pole[i-1][j] = 'W';
				i++;
			}
			if(povorot == 2 && j != 0 && pole[i][j-1] != 'W' && pole[i][j-1] != ' '){
				if(i != 0 && pole[i-1][j] != ' ')
					pole[i-1][j] = 'W';
				if(j < x - 1 && pole[i][j+1] != ' ')
					pole[i][j+1] = 'W';
				if(i < y - 1 && pole[i+1][j] != ' ')
					pole[i+1][j] = 'W';
				j--;
			}
			if(povorot == 3 && j < x - 1 && pole[i][j+1] != 'W' && pole[i][j+1] != ' '){
				if(i != 0 && pole[i-1][j] != ' ')
					pole[i-1][j] = 'W';
				if(j != 0 && pole[i][j-1] != ' ')
					pole[i][j-1] = 'W';
				if(i < y - 1 && pole[i+1][j] != ' ')
					pole[i+1][j] = 'W';
				j++;
			}
			exit = rand() % 100;
		}
		pole[i][j] = ' ';
		if(i != 0 && pole[i-1][j] != ' ') pole[i-1][j] = 'W';
		if(i < y - 1 && pole[i+1][j] != ' ') pole[i+1][j] = 'W';
		if(j != 0 && pole[i][j-1] != ' ') pole[i][j-1] = 'W';
		if(j < x - 1 && pole[i][j+1] != ' ') pole[i][j+1] = 'W';
	}
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			cout << pole[i][j];
		}
		cout << endl;
	}
	return 0;
}

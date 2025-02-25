﻿#include "stdafx.h"
#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

void Hamiltonian_draw(int n, int k, int **tab) { 
	int counter = 0;
	bool *V = new bool[n];  
	for (int i = 0; i < n; i++)
		V[i] = 0; /
	int random1 = (rand() % n) + 0; 
	int random2, random3;
	int g = random1; 
	V[random1] = 1;
	while (counter <n - 1) { 

		random2 = (rand() % n) + 0;
		if (random1 != random2 && tab[random1][random2] == 0 && V[random2] == 0) {
			tab[random1][random2] = tab[random2][random1] = 1; 
			V[random2] = 1; 
			random1 = random2;
			counter++;
		}
	}
	tab[random2][g] = tab[g][random2] = 1; 
	counter++;

	while (counter< k) { 
		random1 = (rand() % n) + 0;
		random2 = (rand() % n) + 0;
		random3 = (rand() % n) + 0;
		if (random1 != random2 && random1!= random3 && random2!=random3 && tab[random1][random2] == 0 && tab[random2][random3] == 0 && tab[random1][random3] == 0) {
			tab[random1][random2] = tab[random2][random1] = 1; 
			tab[random2][random3] = tab[random3][random2] = 1; 
			tab[random1][random3] = tab[random3][random1] = 1;
			counter += 3;

		}
	}
	/*for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < n; ++j)
			cout << tab[i][j];*/

}
int counter_in, counter_out;

void Eulerian(int n, int k, int **tab, int v, int temp[], int out[]) {

	temp[counter_in] = v;
	counter_in++;
	for (int i = 0; i < n; i++) {
		if (tab[v][i]) {
			tab[v][i] = tab[i][v] = 0;
			Eulerian(n, k, tab, i, temp, out);
		}
	}
		out[counter_out] = v;
		counter_out++;
		counter_in--;
}
bool helper;

void Hamiltonian(int n, int k, int **tab, int visited[], int sol[], int x, int licznik) {

	if (!helper){
		visited[x] = 1;
		sol[licznik] = x;
		++licznik;

		if (licznik == n) {
			if (tab[0][x]) {
				helper = 1;

			}
		}

		else {
			for (int i = 0; i < n; i++) {
				if (tab[x][i] && visited[i] == 0)
					Hamiltonian(n, k, tab, visited, sol, i, licznik);
				visited[x] = 0;

			}
		}
	}
	
}

int Hamiltonian_cycle(int n, int k, int **tab, int visited[], int sol[], int x, int counter, int cycle) {

	
	visited[x] = 1;
	sol[counter] = x;
	++counter;
	
	if (counter == n) {
		if (tab[0][x]) {
			cycle += 1;
			return cycle;

		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (tab[x][i] && visited[i] == 0)
				Hamiltonian_cycle(n, k, tab, visited, sol, i, counter, cycle);
			visited[x] = 0;

		}
	}
}

int main()
{
	int menu, menu2, n, k;
	counter_in = 0;
	counter_out = 0;
	double stoper;
	long time;
	clock_t start, stop;


	cout << "Algorithms with returning" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	do {
		cout << "Choose satiation factor:" << endl;
		cout << "1. Equal 30%" << endl;
		cout << "2. Equal 70%" << endl;
		cout << "3. All posible Hamiltonian cycle" << endl;
		cout << "4. Turn off program" << endl;
		cin >> menu;
		if (menu == 1) {
			system("cls");
			cout << "1. Eulerian trail" << endl;
			cout << "2.Hamiltonian cycle" << endl;
			cout << "3. Return" << endl;
			cin >> menu2;
			cout << "Enter the number of vertices:" << endl;
			cin >> n;
			
			
			k = n * (n - 1) / 2 * 0.3; 
			int *temp = new int[k];
			int *out = new int[k];
			int *visited = new int[n];
			for (int i = 0; i < n; i++)
				visited[i] = 0;

			int *sol = new int[n];
			int **tab = new int*[n];
			for (int i = 0; i < n; i++)
			{
				tab[i] = new int[n];
				for (int j = 0; j < n; j++)
				{
					tab[i][j] = 0;
				}
			}
			Hamilton_draw(n, k, tab);
			if (menu2 == 1) {
				start = clock();
				Eulerian(n, k, tab, 0, temp, out);
				stop = clock();
				time = (long)(stop - start);
				cout << "The search time for the Eulerian trail is: " << time << "ms" << endl;
				cout << endl<<endl;
				/*for (int i = 0; i < k; i++)
					cout << out[i]+1 << "  ";*/
			}
			if (menu2 == 2) {
				counter_in = 0;
				helper = 0;
				start = clock();
				Hamiltonian(n, k, tab, visited, sol, 0, 0);
				stop = clock();
				time = (long)(stop - start);
				cout << "The search time for the Hamiltonian cycle is: " << time << "ms" << endl;
				cout << "Cycle found!" << endl;

			}
		}

		if (menu == 2) {
			system("cls");
			cout << "1. Eulerian trail" << endl;
			cout << "2.Hamiltonian cycle" << endl;
			cout << "3. Return" << endl;
			cin >> menu2;
			cout <<"Enter the number of vertices:" << endl;
			cin >> n;


			k = n * (n - 1) / 2 * 0.7;
			int *temp = new int[k];
			int *out = new int[k];
			int *visited = new int[n];
			for (int i = 0; i < n; i++)
				visited[i] = 0;

			int *sol = new int[n];
			int **tab = new int*[n];
			for (int i = 0; i < n; i++)
			{
				tab[i] = new int[n];
				for (int j = 0; j < n; j++)
				{
					tab[i][j] = 0;
				}
			}
			Hamilton_draw(n, k, tab);
			if (menu2 == 1) {
				start = clock();
				Eulerian(n, k, tab, 0, temp, out);
				stop = clock();
				time = (long)(stop - start);
				cout << "The search time for the Eulerian trail is: " << time << "ms" << endl;
				cout << endl << endl;
				/*for (int i = 0; i < k; i++)
					cout << out[i]+1 << "  ";*/
			}
			if (menu2 == 2) {
				counter_in = 0;
				int h;
				helper = 0;
				start = clock();
				Hamiltonian(n, k, tab, visited, sol, 0, 0);
				stop = clock();
				time = (long)(stop - start);
				cout << "The search time for the Hamiltonian cycle is: " << time << "ms" << endl;
				 cout << "Cycle found!" << endl;

			}
		}
		if (menu == 3) {
			system("cls");
			cout << "Enter the number of vertices : " << endl;
			cin >> n;
			k = n * (n - 1) / 2 * 0.5;
			int *visited = new int[n];
			for (int i = 0; i < n; i++)
				visited[i] = 0;
			int *sol = new int[n];
			int **tab = new int*[n];
			for (int i = 0; i < n; i++)
			{
				tab[i] = new int[n];
				for (int j = 0; j < n; j++)
				{
					tab[i][j] = 0;
				}
			}
			Hamilton_draw(n, k, tab);
			start = clock();
			int c = Hamiltonian_cycle(n, k, tab, visited, sol, 0, 0, 0);
			stop = clock();
			time = (long)(stop - start);
			cout << "The search time for the Hamiltonian cycle is: " << time << "ms" << endl;
			cout << "Found: " << c << " cycle(s)" << endl;
		}
	} while (menu != 4);
	cout << "Thank you, goodnight :)" << endl;
		system("pause");
		return 0;
	

}

#include<stdio.h>

int const n = 999999;
typedef int bool;
typedef bool Graph[n][n];

int EdgeCounter(Graph G, int currentV){

	int counter = 0;
	for (int i = 0; i < n; i++){

		if (G[currentV][i])counter++;
	}
	return counter;
}

bool BodyCheck(Graph G, int currentV){

	int stingIndex = 0;
	while ((G[currentV][stingIndex] == true || stingIndex == currentV))stingIndex++;
	if (EdgeCounter(G, stingIndex) == 1){

		int tailIndex = 0;
		while ((G[currentV][tailIndex] == false || tailIndex == currentV) && tailIndex < n)tailIndex++;
		if (EdgeCounter(G, tailIndex) == 2)return true;
		else return false;
	}
	else return false;
}

bool TailCheck(Graph G, int tail) {
	if (EdgeCounter(G, tail) == 2){

		int body = 1;
		while (G[tail][body] == false )body++;
		if (EdgeCounter(G, body) == n - 2)return true;
		else return false;
	}
	else return false;
}

//Следващата функция разделя върховете на графа на 2 множества- свързани с нашия връх(за които предполагаме че е крак) и такива които не са.
//Някои от несвързаните е жилото.
//Взимаме по един връх от всяко множество, ако двата върха са свързани, то махаме връх от несвързаните, ако не са махаме от свързаните,така когато достигнем до жилото, множеството на върховете,които са свързани трябва да е празно
bool LegOfScorpionCheck(Graph G, int currentV) {
	int connectedToV[n];
	int notConnected[n];
	int i = 0, j = 0;
	for (int index = 0; index < n; index){
		if (G[currentV][i] == true) {
			connectedToV[i] = index;
			i++;
		}
		else {
			notConnected[j] = index;
			j++;
		}
	}
	int connected = 0;
	int notconn = 0;
	while (connected < i && notconn < j){
		int x = connectedToV[i];
		int y = notConnected[j];
		if (G[x][y] == false)connected++;
		else notconn++;
	}
	if (connected == i){
		int tail = 0;
		while (G[notconn][tail] == false)tail++;
		return TailCheck(G, tail);
	}
	else return false;
}

bool IsScorpion(Graph G)
{
	int currentV = 0;
	if (EdgeCounter(G, currentV) == n - 2) return BodyCheck(G, EdgeCounter(G, currentV));


	else if (EdgeCounter(G, currentV) == 1) {

		int relatedV = 0;
		while (G[EdgeCounter(G, currentV)][relatedV] == false)relatedV++;
		if (EdgeCounter(G, relatedV) == n - 2) return BodyCheck(G, relatedV);
		else return TailCheck(G, relatedV);
	}

	else if (EdgeCounter(G, currentV) == 2) {

		int firstNeighbour = 0;
		while ((G[currentV][firstNeighbour] == false || firstNeighbour == currentV) && firstNeighbour < n)firstNeighbour++;
		int secondNeighbour = firstNeighbour + 1;
		while ((G[currentV][secondNeighbour] == false || secondNeighbour == currentV) && secondNeighbour < n)secondNeighbour++;
		if ((EdgeCounter(G, firstNeighbour) == 1 && EdgeCounter(G, secondNeighbour) == n - 2) || (EdgeCounter(G, secondNeighbour) == 1 && EdgeCounter(G, firstNeighbour) == n - 2))return true;
		else if (EdgeCounter(G, firstNeighbour) == n - 2) return BodyCheck(G, firstNeighbour);
		else if (EdgeCounter(G, secondNeighbour) == n - 2) return BodyCheck(G, secondNeighbour);
		else return false;
	}

	else return LegOfScorpionCheck(G, currentV);
}

int main()
{
	Graph G;
	IsScorpion(G);
	return 0;
}

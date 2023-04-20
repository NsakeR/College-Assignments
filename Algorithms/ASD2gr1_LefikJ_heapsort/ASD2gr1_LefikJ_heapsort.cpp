//////////////////////////////////////////////////////////////////////////////////////
//	
//	Autor: Jakub Lefik  Wersja: 1.0
//	Data utworzenia: 20.04.2021
//
//	Program realizuje sortowanie kopcujące (heapsort)
//
/////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

void swap(int arr[], int ind1, int ind2) {
	int abc = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = abc;
}

void buildingHeap(int temp[], int size, int index) {
	// Indeksy w tablicy
	int d1 = 2 * index + 1;
	int d2 = 2 * index + 2;
	// Potrzebujesz zmienną na indeks pod którym będzie się chować największa liczba w pod-drzewie
	int abcd = index;

	// Jeżeli wartość pod indeksem jest większa niż pod aktualnie wybranym największym elementem i indeks ten mieści sie w zakresie tablicy, to:
	if (d1 < size) {
		if (temp[d1] > temp[abcd]) {
			abcd = d1;
			swap(temp, index, abcd);
			buildingHeap(temp, size, abcd);
			abcd = index;
		}
	}

	if (d2 < size) {
		if (temp[d2] > temp[abcd]) {
			abcd = d2;
			swap(temp, index, abcd);
			buildingHeap(temp, size, abcd);
			abcd = index;
		}
	}
}

void heapSort(int temp[], int size) {
	// Liczba drzew z dziećmi które trzeba sprawdzić 
	int numOfSubTreesWithKids = size / 2 - 1;

	for (int i = 0; i <= numOfSubTreesWithKids; i++) {
		buildingHeap(temp, size, i);
	}

	for (int j = size - 1; j > 0; j--) {
		for (int g = 0; g < j + 1; g++) {
			std::cout << temp[g] << " ";
		}
		std::cout << std::endl;

		swap(temp, 0, j);
		buildingHeap(temp, j, 0);
	}
}

int main()
{
	int testCases = 0, sizeOfTab = 0;
	int* Tab;
	std::cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		std::cin >> sizeOfTab;
		Tab = new int[sizeOfTab];

		for (int j = 0; j < sizeOfTab; j++) {
			std::cin >> Tab[j];
		}

		heapSort(Tab, sizeOfTab);

		for (int i = 0; i < sizeOfTab; i++) {
			std::cout << Tab[i] << " ";
		}
		std::cout << std::endl;
	}

	delete[] Tab;
	return 0;
}

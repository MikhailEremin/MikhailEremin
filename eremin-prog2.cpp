#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream> 

using namespace std;

bool checksimple(int **arr, int n) {
	for (int count = 0; count < n; count++) {
		for (int count1 = 0; count1 < n; count1++) {
			if ((arr[count][count1] == 1)&&(arr[count1][count] == 1)) {
				cout << arr[count][count1] << " " << count << " " << count1 <<" обратный " << arr[count1][count]  << endl;
				return false;
			}
		}
	}
	return true;
}

bool checklink(int **graph, int n) {
	int num = 0;
	for (int count = 0; count < n; count++) {
		for (int count1 = 0; count1 < n; count1++) {
			if (graph[count][count1] == 1) {
				num++;
				graph[count1][count] = 0;
			}
		}
	}
	cout << (((n - 1)*(n - 2)) / 2) << endl;
	if(num==(((n-1)*(n-2))/2))return true;
	
	else return false;
}
int cins(int type = 0) {
	string k;
	cin >> k;
	bool brek = false;
	int len = k.length();
	if (type == 0) {
		for (int i = 0; i < len; i++) {
			if ((k[i] > '9') || (k[i] < '0') && (k[i] != '-')) {
				cout << "Введите корректное число!\n";
				while (true) {
					cin >> k;
					len = k.length();
					for (int i = 0; i < len; i++) {
						if (!((k[i] > '9') || (k[i] < '0') && (k[i] != '-'))) {
							brek = true;
						}
						if (!brek) cout << "Введите корректное число!\n";
					}
					if (brek)break;
				}

			}
		}
	}
	else if (type = 1) {
		for (int i = 0; i < len; i++) {
			if ((k[i] != '1') && (k[i] != '0')) {
				cout << "Введите либо 1 либо 0.\n";
				while (true) {
					cin >> k;
					len = k.length();
					for (int i = 0; i < len; i++) {
						if (!((k[i] != '1') && (k[i] != '0'))) {
							brek = true;
						}
						if (!brek) cout << "Введите либо 1 либо 0.\n";
					}
					if (brek)break;
				}

			}
		}
	}
	int chislo = atoi(k.c_str());
	return chislo;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов в графе:\n";
	int n;
	n = cins();
	int **graph = new int*[n];
	for (int count = 0; count < n; count++)
		graph[count] = new int[n];

	for (int count = 0; count < n; count++) {
		for (int count1 = 0; count1 < n; count1++) {
			cout << "Введите элемент таблицы смежности [" << count << "][" << count1 << "]\n";
			graph[count][count1] = cins(1);
		}
	}
	if (checksimple(graph, n)) {
		cout << "Граф простой, проверяем с помощью теоремы\n";
		if (checklink(graph, n)) {
			cout << "Граф связный\n";
		}
		else {
			cout << "Граф не связный\n";
		}
	}
	else {
		cout << "Граф не простой, нельзя проверить по теореме\n";
	}
	//вывод графа 
	ofstream File("file.dot");
	if (File.is_open()) {
		cout << "File opened!\n";
	}
	else {
		cout << "file error\n";
		return 0;
	}
	cout << "Какой граф? (1-ориентированный; 2-нет)\n";
	int vb;
	cin >> vb;
	if (vb == 1) {
		File << "digraph G{";
		for (int count = 0; count < n; count++) {
			for (int count1 = 0; count1 < n; count1++) {
				if (graph[count][count1] == 1) {
					File << count << "->" << count1 << ";";
					
				}
			}
		}
		File << "}";
		File.close();
	}
	else {

		File << "graph G{";
		for (int count = 0; count < n; count++) {
			for (int count1 = 0; count1 < n; count1++) {
				if (graph[count][count1] == 1) {
					File << count << "--" << count1 << ";";
				
				}
			}
		}
		File << "}";
		File.close();
	}
	system("gvedit -Tpng file.dot");
	///вывод графа конец 

	system("pause");
}

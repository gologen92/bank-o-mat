
#include <iostream>
const int SIZE = 6;

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	unsigned short money[] = { 5000, 2000, 1000, 500, 200, 100 };
	unsigned inStock[] = { 6, 5, 0, 1, 3, 0 };
	int outputCash[SIZE];
	int limit = 0;
	int x, y = 0;
	cout << "сколько хотите забрать?" << endl;
	cin >> x;
	//а сколько всего денег в наличии
	for (int i = 0; i < SIZE; i++)
		limit += money[i] * inStock[i];
	y = x;

	if (x <= limit) {
		for (int i = 0; i < SIZE; i++) {
			outputCash[i] = x / money[i];
			if (outputCash[i] > inStock[i])
				outputCash[i] = inStock[i];
			x -= outputCash[i] * money[i];
			inStock[i] -= outputCash[i];
			/*while (money[i] + n <= x && sum[i] != 0) {
				sum[i]--;
				n += money[i];
				end[j] = money[i];
				j++;
			}*/
		}
	}
	else
		cout << "а у нас столько нету" << endl;

	if (x != 0)
	{	//найдем старший номинал, на который исходная x делится без остатка	
		int j = 0;
		for (; j < SIZE; j++)
			if (y % money[j] == 0)
				break;
		if (j < SIZE - 1)
		{
			//вернем в банкомат купюру предыдущего номинала и все купюры последующих номиналов
			if (outputCash[j - 1] > 0)
			{
				outputCash[j - 1]--;
				x += money[j - 1];
				inStock[j - 1]++;
				for (int k = j + 1; k < SIZE; k++)
				{
					x += money[k] * outputCash[k];
					inStock[k] += outputCash[k];
					outputCash[k] = 0;
				}
				//попробуем выдать начиная с j-го номинала
				for (int l = j; l < SIZE; l++) {
					outputCash[l] = x / money[l];
					if (outputCash[l] > inStock[l])
						outputCash[l] = inStock[l];
					x -= outputCash[l] * money[l];
					inStock[l] -= outputCash[l];
				}
			}
		}
	}

	if (x != 0)
		cout << "try again and choose different number" << endl;

	else {
		for (int i = 0; i < SIZE; i++) {
			cout << outputCash[i] << " купюр по " << money[i] << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	int n_items;
	double cap;
	cin >> n_items >> cap;
	double *weight = new double[n_items];	
	double *vperw = new double[n_items];
	
										
	for (int i = 0; i < n_items; i++)	
	{									
		double val, w;
		cin >> val >> w;
		weight[i] = w;
		vperw[i] = val / w;	
	}
	int first, second;
	double temp, temp2;
	for (int i = n_items - 1; i > 0; --i)	
	{
		int first = 0, second = 0;
		for (int j = 1; j <= i; j++) {
			if (vperw[j] < vperw[first]) {
				first = j;
				second = j;
			}
			temp = vperw[first];	
			vperw[first] = vperw[i];
			vperw[i] = temp;

			temp2 = weight[second];	
			weight[second] = weight[i];	
			weight[i] = temp2;
		}
	}

	/*for (int i = 0; i < n_items; i++)	//testing to see if my sorting did its job properly.
	{
		cout << vperw[i] << " ";	//value per item array output
	}
	cout << endl;
	for (int j = 0; j < n_items; j++)	
	{
		cout << weight[j] << " ";	//weight array output
	}
	cout << endl;*/

	double capfill = 0;
	double value = 0;
	for (int i = 0; i < n_items; i++)
	{

		if (weight[i] >= cap)
		{
			value += vperw[i] * cap;
			break;
		}
		else {
			value += vperw[i] * weight[i];
			cap -= weight[i];
		}
		
	}
	cout.precision(10);
	cout << value << endl;
	return 0;
}
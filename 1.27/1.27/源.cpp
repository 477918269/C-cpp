int array[5] = { 1, 4, 3, 5, 2 };

for (int i = 0; i < 5; i++)

	cout << array[i] << " ";

cout << endl;

memset(array, 0, 5 * sizeof(int));

for (int k = 0; k < 5; k++)

	cout << array[k] << " ";

cout << endl;

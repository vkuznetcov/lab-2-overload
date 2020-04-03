#include "image.h"
#include <climits>
#include "libutils/io.h"
//#include <Windows.h>
#include <iostream>

using namespace std;

int main() {

	/*Image pic1(10, 15);

	cout << pic1 << endl << endl;*/

	Image pic2(4, 5);
	Image pic3(4, 4);

	cout << pic2 << endl << endl << pic3 << endl << endl;

	pic2 += pic3;

	cout << pic2;

	/*Image pic1(4, 5);

	cout << pic1 << endl << endl;

	pic1 = pic2 + pic3;

	cout << pic1;*/

	//Image pic3(3, 3);

	/*cout << pic2 << endl << endl;

	bool a = true, b = false;

	b *= pic2;

	cout << pic2 << endl << endl;
*/
	//cout << pic3 << endl << endl;

	/*Image pic2 = !pic1;

	cout << pic2 << endl << endl;*/

	/*Image pic2(10, 15);

	cout << pic2 << endl << endl;

	bool a = true, b = false;

	pic1 = pic1 * b;

	cout << pic1;*/

	//Image pic2(1, 2);

	//Image pic3(pic1);

	//cout << pic3;

	/*if (pic1 == pic2)
		cout << "correct" << endl;*/

	/*int m = pic1.getM();

	int n = pic1.getN();

	
*/
	/*pic1.setData(true, 0, 0);

	pic2.setData(true, 0, 0);

	Image pic3 = pic1 * pic2;

	cout << pic3;*/

	//pic3 += pic1;

	//pic3.setData(false, 0, 0);

	//pic3 = pic1 + pic2;

	//cout << pic3;

	//bool res = pic1(0, 0);

	//cout << pic3 << endl << pic1 << endl << pic2;

	/*if (pic1 != pic2)
		cout << endl << "incorrect" << endl << endl;*/

	/*double ratio = pic1.ratio();

	cout << "current ratio is:" << ratio << endl << endl;*/

	/*int a = 1;
	int b = 0;

	bool res = pic1.getData(a, b);

	cout << res << endl;*/

	//cout << "number of rows:" << m << endl << "number of columns:" << n << endl;

	//cout << pic1 << endl << endl;

	/*pic2 = !pic1;

	cout << pic2;*/
	/*Image pic2(3, 3);

	Image pic3 = pic1 * pic2;

	cout << pic3;
*/
	getchar();
}
#include "image.h"

using namespace std;

Image::Image() : m(0), n(0), data(nullptr), s(-1) {}

Image::Image(int m, int n) : m(m), n(n), s(-1) {//работает

	data = new bool* [m];  //создаем двумерный массив

	for (int i = 0; i < m; ++i)
		data[i] = new bool[n];	

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = rand()%2;

}

Image::Image(const Image& obj) {//работает

	data = new bool* [obj.m];
	for (int i = 0; i < obj.m; ++i)
		data[i] = new bool[obj.n];

	m = obj.m;
	n = obj.n;
	s = obj.s;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = obj.data[i][j];

}

Image::Image(Image&& obj) noexcept : m(obj.m), n(obj.n), s(obj.s), data(obj.data){//работает

	obj.data = nullptr;

}

Image::~Image() {//работает
	if(data)
		for (int i = 0; i < m; ++i)
			delete[] data[i];
	delete[] data;
	
}

int Image::getM() const {//работает

	return m;

}

int Image::getN() const {//работает

	return n;

}

bool Image::getData(int m, int n)const {//работает

	bool temp = data[m][n];
	return temp;

}

void Image::setData(bool set, int m, int n) {//работает

	data[m][n] = set;
	s = -1,0;
}

Image& Image::operator=(const Image& obj) {//работает

	if (this == &obj)
		return *this;

	for (int i = 0; i < n; ++i)
		delete[] data[i];
	delete[] data;

	data = new bool* [obj.m];
	for (int i = 0; i < obj.m; ++i)
		data[i] = new bool[obj.n];

	m = obj.m;
	n = obj.n;
	s = obj.s;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = obj.data[i][j];

	return *this;
}

Image& Image::operator=(Image&& obj) noexcept {

	for (int i = 0; i < m; ++i)
		delete[] data[i];
	delete[] data;

	m = obj.m;
	n = obj.n;
	s = obj.s;

	data = obj.data;

	obj.data = nullptr;

	return *this;

}

bool& Image::operator()(int x, int y)const {//работает

	return data[x][y];

}

bool& Image::operator()(int x, int y) {//работает

	s = -1.0;
	return data[x][y];

}

Image operator*(const Image& lhs, const Image& rhs) {//работает

	try {

		if ((lhs.getM() != rhs.getM()) || (lhs.getN() != rhs.getN()))
			throw 5;

		Image res(lhs);

		res *= rhs;

		return res;
	}

	catch (int i) { 
		
		cout << "Error No:" << i << " - array sizes do not match" << endl;

		Image no;

		return no;

	}

}

Image operator+(const Image& lhs, const Image& rhs) {//работает

	try {
		if ((lhs.getM() != rhs.getM()) || (lhs.getN() != rhs.getN()))
			throw 5;

		Image res(lhs);

		res += rhs;

		return res;
	}

		catch (int i) {
			
			cout << "Error No:" << i << " - array sizes do not match" << endl;
			
			Image no;

			return no;
		
		}

}

Image& operator*=(Image& lhs, const Image& rhs) {

	try {

		if ((lhs.getM() != rhs.getM()) || (lhs.getN() != rhs.getN()))
			throw 5;

		for (int i = 0; i < lhs.getM(); ++i)
			for (int j = 0; j < lhs.getN(); ++j) {

				if (lhs.getData(i, j) && rhs.getData(i, j))
					lhs.setData(true, i, j);
				else lhs.setData(false, i, j);

			}
		return lhs;
	}

	catch (int i) { 
		
		cout << "Error No:" << i << " - array sizes do not match" << endl; 

		return lhs;
	
	}

}

Image& operator+=(Image& lhs, const Image& rhs) {//работает

	try {
		if ((lhs.getM() != rhs.getM()) || (lhs.getN() != rhs.getN()))
			throw 5;

		for (int i = 0; i < lhs.getM(); ++i)
			for (int j = 0; j < lhs.getN(); ++j) {

				if (lhs.getData(i, j) || rhs.getData(i, j))
					lhs.setData(true, i, j);
				else lhs.setData(false, i, j);

			}

		return lhs;
	}

	catch (int i) {
		
		cout << "Error No:" << i << " - array sizes do not match" << endl; 

		return lhs;

	}
}

Image operator*(bool a, const Image& obj) {//работает

		if (a)
			return Image(obj);
		else {
			Image res(obj.getM(), obj.getN());
			for (int i = 0; i < obj.getM(); ++i)
				for (int j = 0; j < obj.getN(); ++j)
					res.setData(false, i, j);

			return res;

		}

}

Image operator*(const Image& obj, bool a) {//работает

	return a * obj;

}

Image& operator*=(bool a, Image& obj) {

	if (a)
		return obj;
	else {
		for (int i = 0; i < obj.getM(); ++i)
			for (int j = 0; j < obj.getN(); ++j)
				obj.setData(false, i, j);

		return obj;

	}

}

Image& operator*=(Image& obj, bool a) {

	return a*=obj;

}

Image& operator+=(Image& obj, bool a) {//работает

	for (int i = 0; i < obj.getM(); ++i)
		for (int j = 0; j < obj.getN(); ++j) {

			if (obj.getData(i, j) || a)
				obj.setData(true, i, j);
			else obj.setData(false, i, j);

		}

	return obj;

}

Image& operator+=(bool a, Image& obj) {//работает

	obj += a;

	return obj;
}

Image operator+(bool a, const Image& obj) {//работает

		Image res(obj.getM(), obj.getN());

		for (int i = 0; i < obj.getM(); ++i)
			for (int j = 0; j < obj.getN(); ++j) {

				if ((obj.getData(i, j) == false) && (a == false))
					res.setData(false, i, j);
				else res.setData(true, i, j);

			}

	return res;

}

Image operator+(const Image& obj, bool a) {//работает

	return a + obj;

}

Image operator!(const Image& obj) {//работает

	Image res(obj.getM(), obj.getN());

	for (int i = 0; i < obj.getM(); ++i)
		for (int j = 0; j < obj.getN(); ++j) {

			if (obj.getData(i, j))
				res.setData(false, i, j);
			else res.setData(true, i, j);

		}

	return res;

}

const double Image::ratio()const {//работает
	if (s != -1)
		return s;
	double count = 0;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (data[i][j])
				count++;
	s = (count / (m * n));
	return s;

}

bool operator==(const Image& lhs, const Image& rhs) {//работает

	for (int i = 0; i < lhs.getM(); ++i)
		for (int j = 0; j < lhs.getN(); ++j)
			if (lhs.getData(i, j) != rhs.getData(i, j))
				return false;

	return true;

}

bool operator!=(const Image& lhs, const Image& rhs) {//работает

	for (int i = 0; i < lhs.getM(); ++i)
		for (int j = 0; j < lhs.getN(); ++j)
			if (lhs.getData(i, j) != rhs.getData(i, j))
				return true;

	return false;

}

ostream& operator<<(ostream& out, const Image& rhs) {//работает
	int m = rhs.getM(), n = rhs.getN();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (rhs.getData(i, j)) {
				out << "O";
			}
			else {
				out << ".";
			}
		}
		out << endl;
	}
	return out;
}



















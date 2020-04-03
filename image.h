#pragma once

#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>

class Image {

private:

	int m, n;
	bool** data;
	mutable double s;

public:
	Image();														//конструктор по умолчанию

	Image(int m, int n);											//конструктор с заданной размерностью

	Image(const Image& obj);										//конструктор копирования

	Image(Image&& obj)noexcept;										//конструктор перемещения
	
	~Image();														//деструктор

	int getM()const;												//геттер М		

	int getN()const;												//геттер N		

	bool getData(int m, int n)const;								//геттер даты

	void setData(bool data, int m, int n);							//сеттер даты с заданным индексом

	Image& operator=(const Image& obj);								//оператор присваивания копированием

	Image& operator=(Image&& obj)noexcept;									//оператор присваивания перемещением

	bool& operator()(int x, int y)const;						//доступ к значению по индексу, если справа, то просто выводится

	bool& operator()(int x, int y);								//доступ к значению по индексу, если слева, то выводится и меняет свое значение

	//Image operator*(const Image& obj);		

	//Image operator+(const Image& obj);		

	//Image operator+=(const Image* obj);		

	const double ratio()const;									//оператор нахождения true к общему количеству

};

Image operator*(bool a, const Image& obj);							//произведение объекта на число

Image operator*(const Image& obj, bool a);							//произведение числа на объект

Image operator+(const Image& lhs, const Image& rhs);				//оператор сложения двух объектов

Image operator*(const Image& lhs, const Image& rhs);				//оператор умножения двух объектов

Image& operator+=(Image& lhs, const Image& rhs);					//оператор прибавления одного объекта к другому

Image& operator+=(Image& obj, bool a);

Image& operator+=(bool a, Image& obj);

Image& operator*=(bool a, Image& obj);

Image& operator*=(Image& obj, bool a);

Image& operator*=(Image& lhs, const Image& rhs);

bool operator==(const Image& lhs, const Image& rhs);				//оператор сравнения на равенство

bool operator!=(const Image& lhs, const Image& rhs);				//оператор сравнения на неравенство

Image operator+(bool a, const Image& obj);							//сложение объекта с числом

Image operator+(const Image& obj, bool a);							//сложение числа с объектом

Image operator!(const Image& obj);									//инвертирование значений

std::ostream& operator<<(std::ostream& out, const Image& rhs);		//оператор вывода	






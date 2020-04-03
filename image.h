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
	Image();														//����������� �� ���������

	Image(int m, int n);											//����������� � �������� ������������

	Image(const Image& obj);										//����������� �����������

	Image(Image&& obj)noexcept;										//����������� �����������
	
	~Image();														//����������

	int getM()const;												//������ �		

	int getN()const;												//������ N		

	bool getData(int m, int n)const;								//������ ����

	void setData(bool data, int m, int n);							//������ ���� � �������� ��������

	Image& operator=(const Image& obj);								//�������� ������������ ������������

	Image& operator=(Image&& obj)noexcept;									//�������� ������������ ������������

	bool& operator()(int x, int y)const;						//������ � �������� �� �������, ���� ������, �� ������ ���������

	bool& operator()(int x, int y);								//������ � �������� �� �������, ���� �����, �� ��������� � ������ ���� ��������

	//Image operator*(const Image& obj);		

	//Image operator+(const Image& obj);		

	//Image operator+=(const Image* obj);		

	const double ratio()const;									//�������� ���������� true � ������ ����������

};

Image operator*(bool a, const Image& obj);							//������������ ������� �� �����

Image operator*(const Image& obj, bool a);							//������������ ����� �� ������

Image operator+(const Image& lhs, const Image& rhs);				//�������� �������� ���� ��������

Image operator*(const Image& lhs, const Image& rhs);				//�������� ��������� ���� ��������

Image& operator+=(Image& lhs, const Image& rhs);					//�������� ����������� ������ ������� � �������

Image& operator+=(Image& obj, bool a);

Image& operator+=(bool a, Image& obj);

Image& operator*=(bool a, Image& obj);

Image& operator*=(Image& obj, bool a);

Image& operator*=(Image& lhs, const Image& rhs);

bool operator==(const Image& lhs, const Image& rhs);				//�������� ��������� �� ���������

bool operator!=(const Image& lhs, const Image& rhs);				//�������� ��������� �� �����������

Image operator+(bool a, const Image& obj);							//�������� ������� � ������

Image operator+(const Image& obj, bool a);							//�������� ����� � ��������

Image operator!(const Image& obj);									//�������������� ��������

std::ostream& operator<<(std::ostream& out, const Image& rhs);		//�������� ������	






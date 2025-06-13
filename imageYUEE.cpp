#include "pch.h" 
#include <afxwin.h> 

#include "imageYUEE.h"
#include <string>
#include <fstream>
#include <iostream>
   
#include <atlconv.h> 
using namespace std;

// define class member functions
imageYUEE::imageYUEE()
{
	AfxMessageBox(_T("Default image constructor"));
}
imageYUEE::imageYUEE(CString fname)
{
	CString msg;
	ifstream infile(fname, ios::in | ios::binary);
	string inputLine = "";
	getline(infile, inputLine);
	if (inputLine.compare("P5") != 0)
	{
		//cerr << "Version error" << endl;
		msg.Format(_T("Version error"));
		AfxMessageBox(msg);
	}
	else
	{
		CA2CT str(inputLine.c_str()); // type conversion
		AfxMessageBox(str);
	}
	infile >> numcols >> numrows;
	infile >> max_val;
	pixelValues = new unsigned char[numrows * numcols]; // for data read
	infile.read(reinterpret_cast<char*>(pixelValues), numrows * numcols * sizeof(unsigned char));
	infile.close();
}

int imageYUEE::imageLoad(CString fname)
{
	CString msg;
	ifstream infile(fname, ios::in | ios::binary);
	string inputLine = "";
	getline(infile, inputLine);
	if (inputLine.compare("P5") != 0)
	{
		//cerr << "Version error" << endl;
		msg.Format(_T("잘못된 버전 입력"));
		AfxMessageBox(msg);
	}
	else
	{
		CA2CT str(inputLine.c_str()); // type conversion
		AfxMessageBox(str);
	}
	infile >> numcols >> numrows;
	infile >> max_val;
	pixelValues = new unsigned char[numrows * numcols]; // for data read
	infile.read(reinterpret_cast<char*>(pixelValues), numrows * numcols * sizeof(unsigned char));
	if (infile) //data load check
		AfxMessageBox(_T("이미지 인식 성공"));
	infile.close();
	return(1);
}
int imageYUEE::getImage(unsigned char* data)
{
	// copy image data
	for (int i = 0; i < numcols * numrows; i++)
		data[i] = pixelValues[i];

	return(1);
}

int imageYUEE::getWidth()
{
	return numcols;
}
int imageYUEE::getHeight()
{
	return numrows;
}

// define a destructor function
imageYUEE::~imageYUEE()
{
	delete(pixelValues);
}
int imageYUEE::imageProc(int Mode) {
	if (Mode == 1) {
		for (rows = 0; rows < numrows; ++rows) {
			for (cols = 0; cols < numcols; ++cols) {
				cout << (int)pixelValues[rows * numcols + cols] << ' ';
				pixelValues[rows * numcols + cols] = 255 - pixelValues[rows * numcols + cols];
			}
			cout << rows << endl;
		}
	}
	else if (Mode == 0) {
		for (rows = 0; rows < numrows; ++rows) {
			for (cols = 0; cols < numcols; ++cols) {
				cout << (int)pixelValues[rows * numcols + cols] << ' ';
				if (pixelValues[rows * numcols + cols] > 100) {
					pixelValues[rows * numcols + cols] = 255;
				}
				else {
					pixelValues[rows * numcols + cols] = 0;
				}
			}
			cout << rows << endl;
		}
	}
	else if (Mode == 2) {
		for (rows = 0; rows < numrows; ++rows) {
			for (cols = 0; cols < numcols; ++cols) {
				cout << (int)pixelValues[rows * numcols + cols] << ' ';
				if (pixelValues[rows * numcols + cols] > 200) {
					pixelValues[rows * numcols + cols] = 255;
				}
				else {
					pixelValues[rows * numcols + cols] = 0;
				}
			}
			cout << rows << endl;
		}
	}
	else {
		cout << "잘못된 모드" << endl;
	}
	pixelpProcessed = pixelValues; // pixelpProcessed can be allocated by new
	return 0;
}

int imageYUEE::imageWrite(CString fname)
{
	ofstream ofp;
	ofp.open(fname, ios::binary);
	if (!ofp) {
		cout << "파일 오류 : " << fname << endl;
		exit(1);
	}
	// write image header
	ofp << "P5 " << endl;
	ofp << numcols << " " << numrows << endl;
	ofp << max_val << endl;
	ofp.write(reinterpret_cast<const char*>(pixelpProcessed), numcols * numrows);
	if (ofp.fail()) {
		cout << "이미지 인식 불가 " << fname << endl;
		exit(0);
	}
	ofp.close();
	return 0;
}

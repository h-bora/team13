#pragma once
#include <afx.h>        // MFC �ٽ� Ŭ����
#include <afxstr.h>     // CString ���
#include <string>
#include <fstream>
#include<iostream>
using namespace std;
// declare a new class
class imageYUEE
{
	// declare class member variables
private:
	int cols = 0;
	int rows = 0;
	int numcols = 0;
	int numrows = 0;
	int max_val;
	unsigned char* pixelValues;
	unsigned char* pixelpProcessed;
	// declare class member functions
public:
	imageYUEE();
	imageYUEE(CString fname);
	int imageLoad(CString);
	int getImage(unsigned char* data);
	int imageProc(int);
	int imageWrite(CString);
	int getWidth();
	int getHeight();
	~imageYUEE();
};

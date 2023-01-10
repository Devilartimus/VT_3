// lab3.cpp : Вычислить целочисленное выражение, указанное в варианте задания. При этом, и
//  операнды и результаты вычислений следует выводить как в десятичном, так и в
//  шестнадцатеричном виде.
//  7) A (int), B (dword), C (word).
//  Вычислить: D = (С/A)*C+B; 
//			   E = (B - C) / A * C.

#include <iostream>

using namespace std;

int main()
{
	unsigned __int8 A = 4;				//int
	unsigned __int32 B = 6, D = 0, E;	//dword
	unsigned __int16 C = 3;				//word

	__asm {
		//D = (С/A)*C+B
		mov AX, C;
		cwde;
		div A;
		imul C;
		mov EBX, B;
		add EAX, EBX;
		mov D, EBX;

		//E = (B - C) / A * C
		mov EBX, B;
		mov AX, C;
		cwde;
		SUB EBX, EAX;
		mov AL, A;
		cbw;
		cwd;
		cwde;
		imul C;
		mov ECX, EAX;	//ECX = B-C
		mov EAX, EBX;	//EAX = B-C
		mov EBX, ECX;	//EBX = B-C
		mov EDX, 0;
		div EBX;
		mov E, EAX;
	}
	cout << dec << "D = " << D << " D = 0x" << hex << D << endl;

	cout << dec << "E = " << E << " E = 0x" << hex << E << endl;

}
#ifndef __HEADER_H__
#define __HEADER_H__
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>



using namespace std;

struct product
{
	string idp, namep, type;
	long long price;
	unsigned int numberpro;

};
struct nodep
{
	struct product data;
	nodep* pNext;
};
struct listp
{
	nodep* pHead;
	nodep* pTail;
};
struct employee
{
	string ide, acc, passe, fullname;

};
struct nodee
{
	struct employee data;
	nodee* pNext;
};
struct liste
{
	nodee* pHead;
	nodee* pTail;
};
struct bill
{
	unsigned int day,month, year;
	product pro;
	long long summoney;
};
struct nodeb
{
	bill data;
	nodeb* pNext;
};
struct listb
{
	nodeb* pHead;
	nodeb* pTail;
};

void menu();
void listpinit(listp& lp);
nodep* makenodepoduct(product x);
void addproductintolist(listp& lp,string fileoutp);
void inputproduct(product &x);
bool checkIDProduct(listp& lp, string id);
void inputemployee(employee &x);
nodee* makenodeemployee(employee x);
void listeinit(liste& le);
bool checkIDEmployee(liste& le, string id);
void dataproinit(product& x);
nodep* addTailproduct(listp& lp, nodep* p);
nodee* addTailemployee(liste& le, nodee* p);
void addemployeeintolist(liste& le, string filee);
void deleteproduct(listp& lp, string iddelete,string filep);
void deleteemployee(liste& le, string iddelete,string filee);
void OutputProduct(listp lp);
void OutputEmployee(liste le);
void changeInformationProductInList(listp& lp, string idchange,string filep);
void changeInformationEmployeeInList(liste& le, string idchange,string filee);
bool login(liste& le, string account, string password);
bool login2(liste& le);
void runmenu(listp lp, liste le,listb lb);
void CreateBill(listb&lb,bill& b,listp lp,string fileb);
void listbinit(listb& lb);
nodeb* MakeNodeBill(bill b);
nodeb* AddTailBill(listb& lb, nodeb* p);
void OutputBill(listb lb);
void SumBill(listb& lb);
void OutFileP(listp& lp, string fileoutp);
void InFileP(listp& lp, string fileinp);
void OutFileE(liste& le, string fileoute);
void InFileE(liste& le, string fileine);
void OutFileB(listb& lb, string fileoutb);
void InFileB(listb& lb, string fileinb);

#endif // !__HEADER_H__


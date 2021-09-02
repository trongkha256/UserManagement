#include "Header.h"
void dataproinit(product& x) {
	x.price = 0;
	x.numberpro = 0;
}
void listpinit(listp& lp)
{
	lp.pHead = lp.pTail = NULL;
}
void listeinit(liste& le)
{
	le.pHead = le.pTail = NULL;
}

void inputproduct(product& x)
{
	cout << "ID of Product: ";
	getline(cin, x.idp);
	cout << "Name of Product: ";
	getline(cin, x.namep);
	cout << "Type of Product: ";
	getline(cin, x.type);
	cout << "Price of Product: ";
	cin >> x.price;
	cin.ignore(100, '\n');
}
nodep* makenodepoduct(product x)
{
	nodep* p = new nodep;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}

nodep* addTailproduct(listp& lp, nodep* p)
{
	if (lp.pHead == NULL)
	{
		lp.pHead = lp.pTail = p;
	}
	else
	{
		lp.pTail->pNext = p;
		lp.pTail = p;
	}
	return p;
}
bool checkIDProduct(listp& lp, string id)
{
	if (lp.pHead != NULL)
	{
		for (nodep* k = lp.pHead; k != NULL; k = k->pNext)
		{
			if (id == k->data.idp)
			{
				return 0;
			}
		}
	}
	return 1;
}
void addproductintolist(listp& lp,string fileoutsp)
{
	product pro;
	dataproinit(pro);
	inputproduct(pro);
	if (checkIDProduct(lp, pro.idp) == 1)
	{
		nodep* p = makenodepoduct(pro);
		addTailproduct(lp, p);
		OutFileP(lp, fileoutsp);
	}
	else
	{
		cout << "This ID is existed. Please check this ID." << endl;
	}
}


void inputemployee(employee& x)
{
	cout << "ID of Employee: ";
	getline(cin, x.ide);
	cout << "Account of Employee: ";
	getline(cin, x.acc);
	cout << "Password of Employee: ";
	getline(cin, x.passe);
	cout << "Full name of Employee: ";
	getline(cin, x.fullname);
}
nodee* makenodeemployee(employee x)
{
	nodee* p = new nodee;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}
nodee* addTailemployee(liste& le, nodee* p)
{
	if (le.pHead == NULL)
	{
		le.pHead = le.pTail = p;
	}
	else
	{
		le.pTail->pNext = p;
		le.pTail = p;
	}
	return p;
}
bool checkIDEmployee(liste& le, string id)
{
	if (le.pHead != NULL)
	{
		for (nodee* k = le.pHead; k != NULL; k = k->pNext)
		{
			if (id == k->data.ide)
			{
				return 0;
			}
		}
	}
	return 1;
}
void addemployeeintolist(liste& le,string filee)
{
	employee em;
	inputemployee(em);
	if (checkIDEmployee(le, em.ide) == 1)
	{
		nodee* p = makenodeemployee(em);
		addTailemployee(le, p);
		OutFileE(le, filee);
	}
	else
	{
		cout << "This ID is existed. Please check this ID." << endl;
	}
}
void deleteproduct(listp& lp, string iddelete)
{
	bool kt = 1;
	if (lp.pHead == NULL)
	{
		cout << "There is no product!" << endl;
		return;
	}
	else
	{
		if (lp.pHead->data.idp == iddelete)
		{
			kt = 0;
			nodep* p = lp.pHead;
			if (lp.pHead == lp.pTail)
			{
				lp.pHead = NULL;
				lp.pTail = NULL;
			}
			else
			{
				lp.pHead = p->pNext;
			}
			delete p;
		}
		else
		{
			if (lp.pTail->data.idp == iddelete)
			{
				kt = 0;
				for (nodep* k = lp.pHead; k != NULL; k = k->pNext)
				{
					if (k->pNext == lp.pTail)
					{
						delete lp.pTail;
						k->pNext = NULL;
						lp.pTail = k;
					}
				}
			}
			else
			{
				for (nodep* k = lp.pHead; k->pNext != NULL; k = k->pNext)
				{
					if (k->pNext->data.idp == iddelete)
					{
						kt = 0;
						nodep* temp = k->pNext;
						k->pNext = temp->pNext;
						delete temp;
						break;

					}
				}

			}
		}
		if (kt == 1) {
			cout << "This ID isn't existed. Please check this ID." << endl;
		}
		else
		{
			cout << "Deleting successful." << endl;
		}
		
	}
}
void deleteemployee(liste& le, string iddelete,string filee)
{
	if (le.pHead == NULL)
	{
		cout << "There is no employee!" << endl;
		return;
	}
	else
	{
		bool kt = 1;
		if (le.pHead->data.ide == iddelete)
		{
			kt = 0;
			nodee* p = le.pHead;
			if (le.pHead == le.pTail)
			{
				le.pHead = le.pTail = NULL;
			}
			else
			{

				le.pHead = p->pNext;
			}
			delete p;
		}
		else
		{
			if (le.pTail->data.ide == iddelete)
			{
				kt = 0;
				for (nodee* k = le.pHead; k != NULL; k = k->pNext)
				{
					if (k->pNext == le.pTail)
					{
						delete le.pTail;
						k->pNext = NULL;
						le.pTail = k;
					}
				}
			}
			else
			{
				for (nodee* k = le.pHead; k->pNext != NULL; k = k->pNext)
				{
					if (k->pNext->data.ide == iddelete)
					{
						kt = 0;
						nodee* temp = k->pNext;
						k->pNext = temp->pNext;
						delete temp;
					}
				}

			}
		}
		if (kt == 1)
		{
			cout << "ID isn't existed.Please check this ID." << endl;

		}
		else cout << "Deleting successful." << endl;

	}
}
void OutputProduct(listp lp)
{
	if (lp.pHead == NULL)
	{
		cout << "There is no product in this list." << endl;
		return;
	}
	else
	{
		for (nodep* k = lp.pHead; k != NULL; k = k->pNext)
		{
			cout << "ID:" << k->data.idp << endl;
			cout << "Name: " << k->data.namep << endl;
			cout << "Type: " << k->data.type << endl;
			cout << "Price: " << k->data.price << endl;
			cout << endl;
		}
	}
}
void OutputEmployee(liste le)
{
	if (le.pHead == NULL)
	{
		cout << "Employee is empty." << endl;
	}
	else
	{
		for (nodee* k = le.pHead; k != NULL; k = k->pNext)
		{
			cout << "ID: " << k->data.ide << endl;
			cout << "Account: " << k->data.acc << endl;
			cout << "Password: " << k->data.passe << endl;
			cout << "Full Name: " << k->data.fullname << endl;
		}
	}
}
void changeInformationProductInList(listp& lp, string idchange, string filep)
{
	bool check = 1;
	if (lp.pHead == NULL)
	{
		cout << "There is no product!" << endl;
		return;
	}
	else
	{
		for (nodep* k = lp.pHead; k != NULL; k = k->pNext)
		{
			if (k->data.idp == idchange)
			{
				check = 0;
				cout << "Name of Product: ";
				getline(cin, k->data.namep);
				cout << "Type of Product: ";
				getline(cin, k->data.type);
				cout << "Price of Product: ";
				cin >> k->data.price;
				cin.ignore(100, '\n');
				OutFileP(lp, filep);
				break;
			}
		}
		if (check == 1)
		{
			cout << "There is no id need to change information." << endl;
		}
	}
}
void changeInformationEmployeeInList(liste& le, string idchange,string filee)
{
	bool check = 1;
	if (le.pHead == NULL)
	{
		cout << "There is no product!" << endl;
		return;
	}
	else
	{
		for (nodee* k = le.pHead; k != NULL; k = k->pNext)
		{
			if (k->data.ide == idchange)
			{
				check = 0;
				cout << "Account of Employee: ";
				getline(cin, k->data.acc);
				cout << "Password of Employee: ";
				getline(cin, k->data.passe);
				cout << "Full name of Employee: ";
				getline(cin, k->data.fullname);
				cin.ignore(100, '\n');
				OutFileE(le, filee);
			}
		}
		if (check == 1)
		{
			cout << "There is no id need to change information." << endl;
		}
	}
}
bool login(liste& le, string account, string password)
{
	string accountadmin = "admin";
	string passwordadmin = "12345";
	if (le.pHead == NULL)
	{
		if (account == accountadmin && password == passwordadmin)
		{
			return 1;
		}
	}
	else
	{
		for (nodee* k = le.pHead; k != NULL; k = k->pNext)
		{
			if ((account == accountadmin && password == passwordadmin) || (k->data.acc == account && k->data.passe == password))
			{
				return 1;
			}
		}
	}
	return 0;
}
bool login2(liste& le)
{
	string account;
	string password;
	do
	{
		cout << "Account: ";
		getline(cin, account);
		cout << "Password: ";
		getline(cin, password);
		if (login(le, account, password) ==1 )
		{
			return 1;
		}
		else
		{
			cout << "Please log in again." << endl;
		}
	} while (login(le, account, password) == 0);
	return 0;
}

void CreateBill(listb& lb,bill& b,listp lp,string fileb)
{
	int check1 = 0;
	if (lp.pHead == NULL)
	{
		cout << "Product empty!" << endl;
		return;
	}
	while (1)
	{
		system("cls");
		string id;
		cout << "ID need to add to Bill: ";
		getline(cin, id);
		if (lp.pHead == NULL)
		{
			cout << "List Product is empty. " << endl;
			return;
		}
		for (nodep* k = lp.pHead; k != NULL; k = k->pNext)
		{
			if (id == k->data.idp)
			{
				check1 = 1;
				unsigned day, month, year;
				cout << "Day: ";
				cin >> day;
				cin.ignore(100, '\n');
				cout << "Month: ";
				cin >> month;
				cin.ignore(100, '\n');
				cout << "Year: ";
				cin >> year;
				cin.ignore(100, '\n');
				cout << "ID: " << k->data.idp << endl;
				cout << "Name: " << k->data.namep << endl;
				cout << "Type: " << k->data.type << endl;
				cout << "Price: " << k->data.price << endl;
				cout << "The number of this product: ";
				cin >> k->data.numberpro;
				cin.ignore(100, '\n');	
				b.day = day;
				b.month = month;
				b.year = year;
				b.pro.idp = k->data.idp;
				b.pro.namep = k->data.namep;
				b.pro.type = k->data.type;
				b.pro.price = k->data.price;
				b.pro.numberpro = k->data.numberpro;
				b.summoney = b.pro.price * b.pro.numberpro;
			}
		}
		if (check1 == 1)
		{
			nodeb* p = MakeNodeBill(b);
			AddTailBill(lb, p);
			OutFileB(lb, fileb);
		}
		else
		{
			cout << "ID isn't exist." << endl;
		}
		cout << "+Press 0 to stop and print Bill." << endl;
		cout << "+Press Another Number To Add New Product into Bill." << endl;
		cout << "Choice: ";
		int choice;
		cin >> choice;
		cin.ignore(100, '\n');
		if (choice == 0)
		{
			break;
		}
	}
	if (check1 == 1)
	{
		system("cls");
		OutputBill(lb);
	}
	else
	{
		return;
	}
}
void listbinit(listb& lb)
{
	lb.pHead = lb.pTail = NULL;
}

nodeb* MakeNodeBill(bill b)
{
	nodeb* p = new nodeb;
	p->data = b;
	p->pNext = NULL;
	return p;
}
nodeb* AddTailBill(listb& lb, nodeb* p)
{
	if (lb.pHead == NULL)
	{
		lb.pHead = lb.pTail = p;
	}
	else
	{
		lb.pTail->pNext = p;
		lb.pTail = p;
	}
	return p;
}
void OutputBill(listb lb)
{
	if (lb.pHead == NULL)
	{
		cout << "Bill empty." << endl;
		return;
	}
	else
	{
		int c = 0;

		for (nodeb* k = lb.pHead; k != NULL; k = k->pNext)
		{
			c++;
			cout << "BILL " << c << ":" << endl;
			cout << "ID: " << k->data.pro.idp << endl;
			cout << "Name: " << k->data.pro.namep << endl;
			cout << "Type: " << k->data.pro.type << endl;
			cout << "Price: " << k->data.pro.price << endl;
			cout << "Day: " << k->data.day << "-" << k->data.month << "-" << k->data.year << endl;
			cout << "Number of this product: " << k->data.pro.numberpro << endl;
			cout << "All price of product: " << k->data.summoney << endl;
			cout << endl;
		}
	}

}
void SumBill(listb& lb)
{
	if (lb.pHead == NULL)
	{
		cout << "Empty Bill. " << endl;
		return;
	}
	else
	{
		int count = 0;
		long long sum=0;
		unsigned int day, month, year;
		cout << "Day needs to Reckon: ";
		cin >> day;
		cin.ignore(100, '\n');
		cout << "Month needs to Reckon: ";
		cin >> month;
		cin.ignore(100, '\n');
		cout << "Year needs to Reckon: ";
		cin >> year;
		cin.ignore(100, '\n');
		system("cls");
		for (nodeb* k = lb.pHead; k != NULL; k = k->pNext)
		{
			if (day == k->data.day && month == k->data.month && year == k->data.year)
			{
				count++;
				sum += k->data.summoney;

			}
		}
		cout << "BILL: " << endl;
		cout << "+Day Reckoning: " << day << "-" << month << "-" << year << endl;
		cout << "+The number of bill: " << count << endl;
		cout << "+Sum: " << sum << endl;
	}
}
void OutFileP(listp& lp, string fileoutp)
{
	ofstream fileout;
	fileout.open(fileoutp, ios::out);
	if (fileout.is_open())
	{
		for (nodep* k = lp.pHead; k != NULL; k = k->pNext)
		{
			fileout << k->data.idp<<endl ;
			fileout<< k->data.namep<<endl;
			fileout << k->data.type<<endl ;
			fileout << k->data.price<<endl;
		}
		fileout.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}
void InFileP(listp& lp, string fileinp)
{
	ifstream filein;
	filein.open(fileinp, ios::in);
	if (filein.is_open())
	{
			while (!filein.eof())			
			{
				product pr;
				char tempid[255], tempnamep[255], temptype[255];
				filein.getline(tempid,255);
				filein.getline(tempnamep, 255);
				filein.getline(temptype, 255);
				filein >> pr.price;
				filein.ignore(100, '\n');
				pr.idp = tempid;
				pr.namep = tempnamep;
				pr.type = temptype;
				if (pr.idp == "") continue;
				nodep* p = makenodepoduct(pr);
				addTailproduct(lp, p);

			}
		filein.close();
	}
	else
	{
		cout << "Unable to open file." << endl;
	}
}
void OutFileE(liste& le, string fileoute)
{
	ofstream fileout;
	fileout.open(fileoute, ios::out);
	if (fileout.is_open())
	{
		for (nodee* k = le.pHead; k != NULL; k = k->pNext)
		{
			fileout << k->data.ide << endl;
			fileout << k->data.acc << endl;
			fileout << k->data.passe << endl;
			fileout << k->data.fullname << endl;
		}
		fileout.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}
void InFileE(liste& le, string fileine)
{
	ifstream filein;
	filein.open(fileine, ios::in);
	if (filein.is_open())
	{
		while (!filein.eof())
		{
			employee e;
			char tempid[255], tempacc[255],temppass[255], tempfull[255];
			filein.getline(tempid, 255);
			filein.getline(tempacc, 255);
			filein.getline(temppass, 255);
			filein.getline(tempfull, 255);
			e.ide = tempid;
			e.acc = tempacc;
			e.passe = temppass; 
			e.fullname=tempfull;
			if (e.ide == "") continue;
			nodee* p = makenodeemployee(e);
			addTailemployee(le, p);

		}
		filein.close();
	}
	else
	{
		cout << "Unable to open file." << endl;
	}
}
void OutFileB(listb& lb, string fileoutb)
{
	ofstream fileout;
	fileout.open(fileoutb, ios::out);
	if (fileout.is_open())
	{
		for (nodeb* k = lb.pHead; k != NULL; k = k->pNext)
		{
			fileout << k->data.day << endl;
			fileout << k->data.month << endl;
			fileout << k->data.year << endl;
			fileout << k->data.pro.idp<< endl;
			fileout << k->data.pro.namep << endl;
			fileout << k->data.pro.type << endl;
			fileout << k->data.pro.price << endl;
			fileout << k->data.pro.numberpro <<endl;
			fileout << k->data.summoney <<endl;
		}
		fileout.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}
void InFileB(listb& lb, string fileinb)
{
	ifstream filein;
	filein.open(fileinb, ios::in);
	if (filein.is_open())
	{
		while (!filein.eof())
		{
			bill  b;
			filein >> b.day;
			filein.ignore(100, '\n');
			filein >> b.month;
			filein.ignore(100, '\n');
			filein >> b.year;
			filein.ignore(100, '\n');
			char tempid[255], tempnamep[255], temptype[255];
			filein.getline(tempid, 255);
			filein.getline(tempnamep, 255);
			filein.getline(temptype, 255);
			b.pro.idp = tempid;
			b.pro.namep = tempnamep;
			b.pro.type = temptype;
			filein >> b.pro.price;
			filein.ignore(100, '\n');
			filein >> b.pro.numberpro;
			filein.ignore(100, '\n'); 
			filein>> b.summoney;
			filein.ignore(100, '\n');
			if (b.pro.idp == "") continue;
			nodeb* p = MakeNodeBill(b);
			AddTailBill(lb, p);

		}
		filein.close();
	}
	else
	{
		cout << "Unable to open file." << endl;
	}
}
void menu()
{
	cout << "====================MENU====================" << endl;
	cout << "*SAN PHAM*:" << endl;
	cout << "1.Them san pham." << endl;
	cout << "2.Xoa san pham." << endl;
	cout << "3.Sua thong tin san pham." << endl;
	cout << "4.In danh sach san pham." << endl;
	cout << "*NHAN VIEN*: " << endl;
	cout << "5.Them nhan vien vao cua hang." << endl;
	cout << "6.Xoa nhan vien ra khoi cua hang." << endl;
	cout << "7.Sua thong tin nhan vien" << endl;
	cout << "*DON HANG*:" << endl;
	cout << "8.Tao thong tin cho don hang." << endl;
	cout << "*THONG KE*:" << endl;
	cout << "9.Thong ke so luong va doanh thu trong 1 ngay." << endl;
	cout << "0.Dang xuat." << endl;
	cout << "============================================" << endl;
	cout << "Nhap lua chon cua ban: ";
}
void runmenu(listp lp, liste le,listb lb)
{
	string filep = "product.txt";
	string filee = "employee.txt";
	string fileb = "bill.txt";
	InFileP(lp, filep);
	InFileE(le, filee);
	InFileB(lb, fileb);
	if (login2(le) == 1)
	{

		cout << "Login Sucessfull." << endl;
		while (1)
		{
			system("cls");
			int chon;
			menu();
			cin >> chon;
			cin.ignore(100, '\n');

			if (chon == 0)
			{
				break;
			}
			if (chon == 1)
			{
				system("cls");
				int n;
				cout << "Number of product needs to add: ";
				cin >> n;
				cin.ignore(100, '\n');
				for (int i = 1; i <= n; i++)
				{
					addproductintolist(lp, filep);
				}
				system("pause");
			}
			if(chon==4)
			{
				system("cls");
				OutputProduct(lp);
				system("pause");
			}
			if (chon == 2)
			{
				system("cls");
				string iddelete;
				cout << "ID of product needs to delete: ";
				cin >> iddelete;
				deleteproduct(lp, iddelete);
				OutFileP(lp, filep);
				system("pause");
			}
			if (chon == 3)
			{
				system("cls");
				string idchange;
				cout << "ID of product needs to change: ";
				cin >> idchange;
				cin.ignore(100, '\n');
				changeInformationProductInList(lp, idchange,filep);
				system("pause");
			}
			if (chon == 5)
			{
				system("cls");
				int n;
				cout << "Number of employee needs to add: ";
				cin >> n;
				cin.ignore(100, '\n');
				for (int i = 1; i <= n; i++)
				{
					addemployeeintolist(le,filee);
				}
				system("pause");
			}
			if (chon == 6)
			{
				system("cls");
				string iddelete;
				cout << "ID of employee needs to delete: ";
				cin >> iddelete;
				deleteemployee(le, iddelete,filee);
				OutFileE(le, filee);
				system("pause");
			}
			if (chon == 7)
			{
				system("cls");
				string idchange;
				cout << "ID of employee needs to change: ";
				cin >> idchange;
				cin.ignore(100, '\n');
				changeInformationEmployeeInList(le, idchange,filee);
				system("pause");
			}
			if (chon == 8)
			{
				system("cls");
				bill b;
				CreateBill(lb, b, lp,fileb);
				system("pause");

			}
			if (chon == 9)
			{
				system("cls");
				SumBill(lb);
				system("pause");
			}
			if (chon == 10)
			{
				system("cls");
				OutputEmployee(le);
				system("pause");

			}

		}
	}
}


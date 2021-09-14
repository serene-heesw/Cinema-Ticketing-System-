#include<iostream>
#include<iomanip>
#include<string>


using namespace std;

void display_logo();
void MovieShow(string *movie, string *dateTime);
void displaySeatAvailable();
void input(int *classRequired, int *adultSeat, int *childSeat, int *studentSeat, int seat0, int seat1, int seat2, int classAvailable0, int classAvailable1, int classAvailable2);
void findPrice(int classRequired, double *adult, double *child, double *student);
void sales(int classRequired, int adultSeat, int childSeat, int studentSeat, int * adultSold, int * childSold, int * studentSold, int * seat0, int * seat1, int * seat2);
void billCalculation(int classRequired, int adultSeat, int childSeat, int studentSeat, double, double, double, int, int, double, double *popcornSales, double *adultPrice, double *childPrice, double *studentPrice, double *totalPay, double *cashPayment, double *changeDue, double *adultSales, double *childSales, double *studentSales);
void displayTickets(string movie, string dateTime, int classRequired, int adultSeat, int childSeat, int studentSeat, int *classAvailable0, int *classAvailable1, int *classAvailable2);
void displaySeatLeft(int classAvailable0, int classAvailable1, int classAvailable2);
void displayTicketReport(string movie, string dateTime, int seat0, int seat1, int seat2, int adultSold, int childSold, int studentSold, int popcornSold, double popcoenSales, double adultSales, double studentSales, double childSales);


int main() {
	char choice;
	string movie, dateTime;
	int classRequired, adultSeat, childSeat, studentSeat, Class0Seat = 001, Class1Seat = 101, Class2Seat = 201, seat0 = 0, seat1 = 0, seat2 = 0;
	int classAvailable0 = 15, classAvailable1 = 15, classAvailable2 = 30;
	int adultSold = 0, childSold = 0, studentSold = 0;
	double totalAddOn = 0;
	double adultSales = 0, childSales = 0, studentSales = 0;
	double adultPrice, childPrice, studentPrice, totalPay, cashPayment, changeDue;
	double adult, child, student;
	int popcornCombo, popcornSold = 0;
	double popcornPrice = 15.00, popcornSales = 0;
	int paymentMethod;


	display_logo();
	MovieShow(&movie, &dateTime);
	displaySeatAvailable();

	do {

		input(&classRequired, &adultSeat, &childSeat, &studentSeat, seat0, seat1, seat2, classAvailable0, classAvailable1, classAvailable2);

		findPrice(classRequired, &adult, &child, &student);

		sales(classRequired, adultSeat, childSeat, studentSeat, &adultSold, &childSold, &studentSold, &seat0, &seat1, &seat2);

		//Popcorn Combo
		cout << endl;
		cout << " Popcorn and Drinks (RM 10 per combo)" << endl;
		cout << " How many combo(s) need :  ";
		cin >> popcornCombo;
		popcornSold += popcornCombo;

		billCalculation(classRequired, adultSeat, childSeat, studentSeat, adult, child, student, popcornCombo, popcornSold, popcornPrice, &popcornSales, &adultPrice, &childPrice, &studentPrice, &totalPay, &cashPayment, &changeDue, &adultSales, &childSales, &studentSales);

		displayTickets(movie, dateTime, classRequired, adultSeat, childSeat, studentSeat, &classAvailable0, &classAvailable1, &classAvailable2);

		displaySeatLeft(classAvailable0, classAvailable1, classAvailable2);

		cout << " Next Customer? ";
		cin >> choice;
		cin.get();
	} while (choice == 'Y' || choice == 'y');

	displayTicketReport(movie, dateTime, seat0, seat1, seat2, adultSold, childSold, studentSold, popcornSold, popcornSales, adultSales, studentSales, childSales);

	system("pause");
	return 0;
}


void display_logo()
{
	cout << setw(20) << "----------------------------------" << endl;
	cout << setw(20) << "| TAR CINEMAX TICKETING SYSTEMS |" << endl;
	cout << setw(20) << "----------------------------------" << endl;
	cout << endl;
}

void MovieShow(string *movie, string *dateTime)
{
	cout << "This Friday's Movie:" << setw(10) << "";
	getline(cin, *movie);
	cout << "Date / Time " << setw(8) << ":" << setw(10) << "";
	getline(cin, *dateTime);
	cout << endl;
	cout << " Counter is now Open for Selling of Tickets ! Grab yours now !" << endl;
	cout << endl;
}

void displaySeatAvailable()
{
	cout << " Here are your tickets : " << endl;
	cout << endl;
	cout << setw(33) << "Seats Available : " << endl;
	cout << setw(30) << "CLASS 0 - 15 " << endl;
	cout << setw(30) << "CLASS 1 - 15 " << endl;
	cout << setw(30) << "CLASS 2 - 30 " << endl;
	cout << endl;
}

void input(int *classRequired, int *adultSeat, int *childSeat, int *studentSeat, int seat0, int seat1, int seat2, int classAvailable0, int classAvailable1, int classAvailable2)
{

	do
	{
		do
		{
			cout << " Class Required (0, 1, 2) ? ";
			cin >> *classRequired;
			cout << endl;

			if (*classRequired > 2)
				cout << " Invalid Class ! Enter again ! " << endl;
		} while (*classRequired > 2);

		cout << " Number of Adult Seats required" << setw(11) << ": ";
		cin >> *adultSeat;
		cout << endl;
		cout << " Number of Child Seats required " << endl;
		cout << " (Children must be below 12 years old)" << setw(4) << ": ";
		cin >> *childSeat;
		cout << endl;
		cout << " Number of Students Seats required " << endl;
		cout << " (Must show student registration cards)" << setw(3) << ": ";
		cin >> *studentSeat;
		cout << endl;

		if ((*adultSeat + *childSeat + *studentSeat) > classAvailable0 || (*adultSeat + *childSeat + *studentSeat) > classAvailable1 || (*adultSeat + *childSeat + *studentSeat) > classAvailable2)
			cout << " Seats are insufficient ! Choose another class or reduce the number of seats required." << endl;
	} while
		((*adultSeat + *childSeat + *studentSeat) > classAvailable0 || (*adultSeat + *childSeat + *studentSeat) > classAvailable1 || (*adultSeat + *childSeat + *studentSeat) > classAvailable2);

}


void findPrice(int classRequired, double *adult, double *child, double *student)
{
	switch (classRequired)
	{
	case 0:
		*adult = 20.00;
		*child = 10.00;
		*student = 12.00;
		break;

	case 1:
		*adult = 16.00;
		*child = 6.00;
		*student = 8.00;
		break;

	case 2:
		*adult = 18.00;
		*child = 8.00;
		*student = 10.00;
		break;
	}

}


void sales(int classRequired, int adultSeat, int childSeat, int studentSeat, int * adultSold, int * childSold, int * studentSold, int * seat0, int * seat1, int * seat2)
{
	switch (classRequired) {
	case 0:
		*seat0 += (adultSeat + childSeat + studentSeat);
		break;
	case 1:
		*seat1 += (adultSeat + childSeat + studentSeat);
		break;
	case 2:
		*seat2 += (adultSeat + childSeat + studentSeat);
		break;
	}

	*adultSold += adultSeat;
	*childSold += childSeat;
	*studentSold += studentSeat;
}

void billCalculation(int classRequired, int adultSeat, int childSeat, int studentSeat, double adult, double child, double student, int popcornCombo, int popcornSold, double popcornPrice, double *popcornSales, double *adultPrice, double *childPrice, double *studentPrice, double *totalPay, double *cashPayment, double *changeDue, double *adultSales, double *childSales, double *studentSales)
{
	int paymentMethod;

	cout << endl;
	cout << " Bill Calculation - Class " << classRequired << endl;
	cout << endl;
	*adultPrice = adultSeat * adult;
	*childPrice = childSeat * child;
	*studentPrice = studentSeat * student;
	*totalPay = *adultPrice + *childPrice + *studentPrice + (popcornCombo * popcornPrice);


	cout << " Number of Adults    =  " << adultSeat << setw(3) << " @ " << "RM " << setw(6) << fixed << setprecision(2) << adult << setw(4) << "= " << "RM" << setw(6) << fixed << setprecision(2) << *adultPrice << endl;
	cout << " Number of Children  =  " << childSeat << setw(3) << " @ " << "RM " << setw(6) << fixed << setprecision(2) << child << setw(4) << "= " << "RM" << setw(6) << fixed << setprecision(2) << *childPrice << endl;
	cout << " Number of Students  =  " << studentSeat << setw(3) << " @ " << "RM " << setw(6) << fixed << setprecision(2) << student << setw(4) << "= " << "RM" << setw(6) << fixed << setprecision(2) << *studentPrice << endl;
	cout << setw(24) << " Popcorn Combo =  " << setw(20) << right << "RM " << setw(5) << fixed << setprecision(2) << popcornCombo * popcornPrice << endl;
	cout << setw(23) << " Total to Pay = " << setw(21) << right << "RM " << setw(5) << fixed << setprecision(2) << *totalPay << endl;

	do {
		cout << endl;
		cout << setw(20) << "Paymeny Method :" << endl;
		cout << left << setw(30) << "          1.Cash          " << endl;
		cout << left << setw(30) << "          2.Credit/Debit Card   " << endl;
		cout << left << setw(30) << "          3.Boost (10% OFF) " << endl;
		cout << endl;

		cout << "Enter you payment method : ";
		cin >> paymentMethod;
		cout << endl;
		switch (paymentMethod)
		{
		case 1:
			cout << right << setw(23) << " CASH PAYMENT : " << setw(21) << right << "RM ";
			cin >> *cashPayment;
			*changeDue = *cashPayment - *totalPay;
			cout << setw(23) << " CHANGE DUE   = " << setw(21) << right << "RM " << setw(5) << fixed << setprecision(2) << *changeDue << endl;
			cout << endl;

			break;
		case 2:
			cout << right << setw(23) << " CASH PAYMENT : " << setw(21) << right << "RM " << *totalPay << endl;
			*changeDue = 0;
			cout << setw(23) << " CHANGE DUE   = " << setw(21) << right << "RM " << setw(5) << fixed << setprecision(2) << *changeDue << endl;
			cout << endl;

			break;
		case 3:
			cout << "You get 10% off by using Boost e-wallet !" << endl;
			*totalPay = *totalPay * 0.9;
			cout << right << setw(23) << " CASH PAYMENT : " << setw(21) << right << "RM " << *totalPay << endl;
			*changeDue = 0;
			cout << setw(23) << " CHANGE DUE   = " << setw(21) << right << "RM " << setw(5) << fixed << setprecision(2) << *changeDue << endl;
			cout << endl;
		default:
			cout << "Enter the payment method again !" << endl;
			break;
		}

	} while (paymentMethod != 1 && paymentMethod != 2 && paymentMethod != 3);



	*adultSales += adult * adultSeat;
	*childSales += child * childSeat;
	*studentSales += student * studentSeat;
	*popcornSales += popcornCombo * popcornPrice;
}

void displayTickets(string movie, string dateTime, int classRequired, int adultSeat, int childSeat, int studentSeat, int *classAvailable0, int *classAvailable1, int *classAvailable2)
{
	int Class0Seat = 001, Class1Seat = 101, Class2Seat = 201;

	cout << " Here are your tickets : " << endl;
	cout << endl;

	if (classRequired == 0)
	{

		for (int i = 0; i < adultSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "ADULT - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class0Seat << setw(34) << right << "Price : RM 20.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class0Seat++;
		}

		for (int i = 0; i < childSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "CHILD - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class0Seat << setw(34) << right << "Price : RM 10.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class0Seat++;
		}

		for (int i = 0; i < studentSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "STUDENT - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class0Seat << setw(34) << right << "Price : RM 12.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class0Seat++;
		}
		*classAvailable0 = *classAvailable0 - adultSeat - childSeat - studentSeat;
	}

	else if (classRequired == 1)
	{

		for (int i = 0; i < adultSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "ADULT - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class1Seat << setw(32) << right << "Price : RM 16.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class1Seat++;
		}

		for (int i = 0; i < childSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "CHILD - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class1Seat << setw(31) << right << "Price : RM 6.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class1Seat++;
		}

		for (int i = 0; i < studentSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "STUDENT - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class1Seat << setw(31) << right << "Price : RM 8.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class1Seat++;
		}
		*classAvailable1 = *classAvailable1 - adultSeat - childSeat - studentSeat;
	}


	else if (classRequired == 2)
	{

		for (int i = 0; i < adultSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "ADULT - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class2Seat << setw(32) << right << "Price : RM 18.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class2Seat++;
		}

		for (int i = 0; i < childSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "CHILD - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class2Seat << setw(31) << right << "Price : RM 8.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class2Seat++;
		}

		for (int i = 0; i < studentSeat; i++)
		{
			cout << string(90, '=') << endl;
			cout << " TAR Cinemax Ticket" << right << setw(50) << "STUDENT - Class " << classRequired << endl;
			cout << endl;
			cout << setw(30) << left << " Movie       : " << movie << endl;
			cout << setw(30) << left << " Date / Time : " << dateTime << endl << endl;
			cout << " Seat No : " << Class2Seat << setw(32) << right << "Price : RM 10.00" << endl;
			cout << string(90, '=') << endl;
			cout << endl;
			Class2Seat++;
		}
		*classAvailable2 = *classAvailable2 - adultSeat - childSeat - studentSeat;
	}

	cout << "Enjoy Your Movie !" << endl << endl;
}


void displaySeatLeft(int classAvailable0, int classAvailable1, int classAvailable2)
{
	cout << setw(33) << right << "Seats Still Available : " << endl;
	cout << setw(24) << right << "CLASS 0 - " << classAvailable0 << endl;
	cout << setw(24) << right << "CLASS 1 - " << classAvailable1 << endl;
	cout << setw(24) << right << "CLASS 2 - " << classAvailable2 << endl;
	cout << endl;
}

void displayTicketReport(string movie, string dateTime, int seat0, int seat1, int seat2, int adultSold, int childSold, int studentSold, int popcornSold, double popcornSales, double adultSales, double studentSales, double childSales)
{
	cout << endl;
	cout << setfill('=') << setw(90) << "" << endl;
	cout << setfill(' ');
	cout << setw(15) << "" << " TICKET SALES REPORT" << endl << endl;
	cout << " Movie Tittle : " << setw(8) << "" << movie << endl;
	cout << " Date / Time : " << setw(9) << "" << dateTime << endl << endl;

	cout << " SEAT OCCUPANCY FOR EACH CLASS: " << endl << endl;
	cout << setw(14) << "" << "Total Seats  " << "Quantity Sold     " << "Sold %\n";
	cout << fixed << setprecision(0);
	cout << setw(10) << "CLASS 0" << setw(10) << "15" << setw(14) << seat0 << setw(15) << (double)seat0 / 15 * 100 << endl;
	cout << setw(10) << "CLASS 1" << setw(10) << "15" << setw(14) << seat1 << setw(15) << (double)seat1 / 15 * 100 << endl;
	cout << setw(10) << "CLASS 2" << setw(10) << "30" << setw(14) << seat2 << setw(15) << (double)seat2 / 30 * 100 << endl;
	cout << setw(22) << "------" << setw(14) << "------" << setw(17) << "-------" << endl;
	cout << setw(10) << "OVERALL" << setw(10) << (15 + 15 + 30) << setw(14) << seat0 + seat1 + seat2
		<< setw(15) << (double)(seat0 + seat1 + seat2) / (15 + 15 + 30) * 100 << endl << endl;

	cout << " SALES FOR EACH CATEGORY TYPE : \n\n";
	cout << setw(23) << "Category" << setw(14) << "Seats" << setw(16) << "Sales (RM)" << endl;
	cout << fixed << setprecision(2);
	cout << setw(16) << "" << "ADULT" << setw(14) << adultSold << setw(16) << adultSales << endl;
	cout << setw(16) << "" << "CHILD" << setw(14) << childSold << setw(16) << childSales << endl;
	cout << setw(16) << "" << "STUDENT" << setw(12) << studentSold << setw(16) << studentSales << endl;
	cout << setw(31) << "" << "------" << setw(17) << "-----------" << endl;
	cout << setw(16) << "" << "Total" << setw(14) << adultSold + childSold + studentSold
		<< setw(16) << adultSales + childSales + studentSales << endl << endl;

	cout << " SALES FOR POPCORN COMBO : \n\n";
	cout << setw(22) << " " << setw(15) << "Quantity Sold" << setw(16) << "Sales (RM)" << endl;
	cout << fixed << setprecision(2);
	cout << setw(5) << "" << "POPCORN COMBO" << setw(14) << popcornSold << setw(19) << popcornSales << endl << endl;
}

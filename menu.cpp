#include <iostream>
#include "Utilities.h"
#include "classHeader.h"
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>

using namespace std;

void writeToMembers(string firstName, string lastName, string id, string miles, string fileName) {	//adds user input to last line in file
	//Creating and openning file to write using fstream::out
	std::fstream fs(fileName, std::ios::in | std::ios::out | std::ios::ate);
	fs << endl << firstName << "," << lastName << "," << id << "," << miles;
	fs.close();

}
void rewriteToMembers(string fileName, memberList list) {	//idk how to delete one thing so i just made the function rewrite file
	ofstream fs(fileName);
	fs << list.showfname(0) << "," << list.showlname(0) << "," << list.showid(0) << "," << list.showmiles(0);	//writes the first line of file
	for (int i = 1; i < list.getLength(); i++) {			//keeps writing to file until the array list is empty
		fs << endl << list.showfname(i) << "," << list.showlname(i) << "," << list.showid(i) << "," << list.showmiles(i);	//writes the rest
	}
	fs.close();
}
//----------------------------------------------------MemberMenu-----------------------------------------------------------------//
void subMenuMember()
{
	char selection;
	memberList memList;
	string member = "members.txt";
	ifstream memberin(member);

	//check if inputting file failed
	if (!memberin)
	{
		cout << "input failed" << endl;
	}
	//fill the list from the file
	//increment length to current
	//ifstream memberin(filename);
	string tempf, templ, tempid, tempmiles;;
	while (!memberin.eof())						//fill the array with file until file is empty
	{
		getline(memberin, tempf, ',');			
		getline(memberin, templ, ',');
		getline(memberin, tempid, ',');
		getline(memberin, tempmiles, '\n');
		memList.insertItem(tempf, templ, tempid, tempmiles);
	}

	do {
		system("Color 2B");
		system("CLS");
		gotoxy(50, 9);
		cout << " Reward Program Members Menu\n";
		gotoxy(50, 10);
		cout << " ====================================\n";
		gotoxy(50, 11);
		cout << " 1. Display List\n";
		gotoxy(50, 12);
		cout << " 2. Add New Member\n";
		gotoxy(50, 13);
		cout << " 3. Delete Member\n";
		gotoxy(50, 14);
		cout << " 4. Find Member\n";
		gotoxy(50, 15);
		cout << " 5. Exit\n";
		gotoxy(50, 16);
		cout << " ====================================\n";
		gotoxy(50, 19);
		cout << " Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case '1':							//display
			memList.dispalyList();
			system("pause");
			break;

		case '2': {							//add new
			string first;
			string last;
			string id;
			string miles;
			gotoxy(50, 21);
			cout << "Type first name: ";
			cin >> first;
			gotoxy(50, 22);
			cout << "Type last name: ";
			cin >> last;
			gotoxy(50, 23);
			cout << "Type id: ";
			cin >> id;
			gotoxy(50, 24);
			cout << "Type miles traveled: ";
			cin >> miles;
			memList.insertItem(first, last, id, miles);			//add(first,last,id,miles)
			writeToMembers(first, last, id, miles, member);		//rewrite to file
			break;
		}
		case '3': {							//find
			string id;
			gotoxy(50, 21);
			cout << "Type id number of the member you want to find: ";
			cin >> id;
			memList.deleteItem(id);
			rewriteToMembers(member, memList);
			break;
		}
		case '4': {							//delete
			string id;
			gotoxy(50, 21);
			cout << "Type id number of the member you want to delete: ";
			cin >> id;
			gotoxy(50, 22);
			memList.findNum(id);
			break;
		}
		case '5':							//exit
			cout << "Goodbye.\n";
			return;

		default: cout << selection << " is not a valid menu item.\n";

			cout << endl;
		}
	} while (selection != 6);
}
//------------------------------------------------------------DomesticMenu---------------------------------------------------------//
void subMenuDomestic()
{
	char selection;
	memberList domList;
	string member = "domestic.txt";
	ifstream memberin(member);

	//check if inputting file failed
	if (!memberin)
	{
		cout << "input failed" << endl;
	}

	//fill the list from the file
	//increment length to current
	//ifstream memberin(filename);
	string tempf, templ, tempid, tempmiles;;
	while (!memberin.eof())					//fill the array with file until file is empty
	{
		getline(memberin, tempf, ',');
		getline(memberin, templ, ',');
		getline(memberin, tempid, ',');
		getline(memberin, tempmiles, '\n');
		domList.insertItem(tempf, templ, tempid, tempmiles);
	}

	do {
		system("Color 3B");
		system("CLS");
		gotoxy(50, 9);
		cout << " Available Flights: Domestic\n";
		gotoxy(50, 10);
		cout << " ====================================\n";
		gotoxy(50, 11);
		cout << " 1. Display Flights \n";
		gotoxy(50, 12);
		cout << " 2. Add Flight\n";
		gotoxy(50, 13);
		cout << " 3. Delete Flight\n";
		gotoxy(50, 14);
		cout << " 4. Find Flight List\n";
		gotoxy(50, 15);
		cout << " 5. Exit\n";
		gotoxy(50, 17);
		cout << " ====================================\n";
		gotoxy(50, 18);
		cout << " Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case '1':							//display
			domList.dispalyList();
			system("pause");
			break;

		case '2':							//add
		{string domesticDest;
		string departureDestdom;
		string depatTimedom;
		string arriveTimedom;
		gotoxy(50, 21);
		cout << "Enter Domestic Destination: ";
		cin >> domesticDest;
		gotoxy(50, 22);
		cout << "Enter City of Departure: ";
		cin >> departureDestdom;
		gotoxy(50, 23);
		cout << "Enter Flight id: ";
		cin >> depatTimedom;
		gotoxy(50, 24);
		cout << "Enter Departure Time: ";
		cin >> arriveTimedom;
		domList.insertItem(domesticDest, departureDestdom, depatTimedom, arriveTimedom);		//add(end,start,id,time)
		writeToMembers(domesticDest, departureDestdom, depatTimedom, arriveTimedom, member);	//rewrite file
		break; }

		case '3':							//delete
		{string domesticDest;
		gotoxy(50, 21);
		cout << "Type id of flight you want to delete: ";
		cin >> domesticDest;
		domList.deleteItem(domesticDest);			
		rewriteToMembers(member, domList);
		break; }

		case '4':							//find
		{string domesticDest;
		gotoxy(50, 21);
		cout << "Type id of flight you want to find: ";
		cin >> domesticDest;
		gotoxy(50, 22);
		domList.findNum(domesticDest);
		break; }

		case '5':							//delete
			cout << "Goodbye.\n";
			return;

		default: cout << selection << " is not a valid menu item.\n";

			cout << endl;
		}
	} while (selection != 6);
}
//-------------------------------------------------------------------InternationalMenu-----------------------------------------------------//
void subMenuInternational()
{
	char selection;
	memberList intList;
	string member = "international.txt";
	ifstream memberin(member);

	//check if inputting file failed
	if (!memberin)
	{
		cout << "input failed" << endl;
	}

	//fill the list from the file
	//increment length to current
	//ifstream memberin(filename);
	string tempf, templ, tempid, tempmiles;;
	while (!memberin.eof())					//fill the array with file until file is empty
	{
		getline(memberin, tempf, ',');
		getline(memberin, templ, ',');
		getline(memberin, tempid, ',');
		getline(memberin, tempmiles, '\n');
		intList.insertItem(tempf, templ, tempid, tempmiles);
	}

	do {
		system("Color 4B");
		system("CLS");
		gotoxy(50, 9);
		cout << " Available Flights: International\n";
		gotoxy(50, 10);
		cout << " ====================================\n";
		gotoxy(50, 11);
		cout << " 1. Display Flights \n";
		gotoxy(50, 12);
		cout << " 2. Add Flight\n";
		gotoxy(50, 13);
		cout << " 3. Delete Flight\n";
		gotoxy(50, 14);
		cout << " 4. Find Flight\n";
		gotoxy(50, 15);
		cout << " 5. Exit\n";
		gotoxy(50, 17);
		cout << " ====================================\n";
		gotoxy(50, 18);
		cout << " Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case '1':							//display
		{intList.dispalyList();
		system("pause"); }
		break;

		case '2':							//add
		{string internationalDest;
		string departureDestint;
		string depatTimeint;
		string arriveTimeint;
		gotoxy(50, 21);
		cout << "Enter Domestic Destination: ";
		cin >> internationalDest;
		gotoxy(50, 22);
		cout << "Enter City of Departure: ";
		cin >> departureDestint;
		gotoxy(50, 23);
		cout << "Enter Flight id: ";
		cin >> depatTimeint;
		gotoxy(50, 24);
		cout << "Enter Depature Time: ";
		cin >> arriveTimeint;
		intList.insertItem(internationalDest, departureDestint, depatTimeint, arriveTimeint);			//add(end,start,id,time)
		writeToMembers(internationalDest, departureDestint, depatTimeint, arriveTimeint, member);		//rewrite to file
		break; }

		case '3':							//delete
		{string internationalDest;
		gotoxy(50, 21);
		cout << "Type id of flight you want to delete: ";
		cin >> internationalDest;
		intList.deleteItem(internationalDest);
		rewriteToMembers(member, intList);
		break; }

		case '4':							//find
		{string internationalDest;
		gotoxy(50, 21);
		cout << "Type id of flight you want to find: ";
		cin >> internationalDest;
		gotoxy(50, 22);
		intList.findNum(internationalDest);
		break; }

		case '5':							//exit
			cout << "Goodbye.\n";
			return;

		default: cout << selection << " is not a valid menu item.\n";

			cout << endl;
		}

	} while (selection != 6);
}
//---------------------------------------------------------------------MainMenu--------------------------------------------------------------//
void mainMenu()
{
	char selection;
	do
	{
		system("Color 1A");
		system("CLS");
		gotoxy(50, 9);
		cout << " Farmingdale Computer Systems Registration Menu\n";
		gotoxy(50, 10);
		cout << " ====================================\n";
		gotoxy(50, 11);
		cout << " 1. Reward Program Members\n";
		gotoxy(50, 12);
		cout << " 2. Available Flights: Domestic\n";
		gotoxy(50, 13);
		cout << " 3. Available Flights: International\n";
		gotoxy(50, 14);
		cout << " 4. Exit\n";
		gotoxy(50, 17);
		cout << " ====================================\n";
		gotoxy(50, 18);
		cout << " Enter your selection: ";
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case '1':
			subMenuMember();		//membermenu
			break;
		case '2':
			subMenuDomestic();		//domesticmenu
			break;
		case '3':
			subMenuInternational();	//internationalmenu
			break;
		case '4':
			cout << "Goodbye.\n";
			return;

		default: cout << selection << " is not a valid menu item.\n";

			cout << endl;
		}
	} while (selection != 6);
}

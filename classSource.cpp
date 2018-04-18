#include "classHeader.h"
#include "Utilities.h"
#include <iostream>

using namespace std;

//--------------------------------------------------memberType-------------------------------------------------------------//
// "::" = scope resolution

//Default Constructor
//set all stuff to 0 (default state)
memberType::memberType(){
	newid = "0";
	newMiles = "0.0";
}

//Overloaded Constructor
//set all stuff to whatever user puts in
memberType::memberType(string fname, string lname, string id, string miles){
	newfName = fname;
	newlName = lname;
	newid = id;
	newMiles = miles;

}
//Deconstructor
memberType::~memberType(){

}

//---------------Accessor Functinons--------------------
string memberType::getfName(){
	return newfName;
}
string memberType::getlName(){
	return newlName;
}
string memberType::getid(){
	return newid;
}
string memberType::getmiles(){
	return newMiles;
}
//----------------Mutator Functions-------------------
void memberType::setfName(string fname){
	newfName = fname;
}
void memberType::setlName(string lname){
	newlName = lname;
}
void memberType::setid(string id){
	newid = id;
}
void memberType::setmiles(string miles){
	newMiles = miles;
}

//--------------------------------------------------------------memberList-------------------------------------------------
//O(1)
memberList::memberList()
{
	length = 0;
}

//O(1)
void memberList::insertItem(string fname, string lname, string id, string miles)
{
	info[length].setfName(fname);
	info[length].setlName(lname);
	info[length].setid(id);
	info[length].setmiles(miles);
	length++;
}
//O(1)
bool memberList::isFull() const
{
	return (length == 10);
}
//O(1)
bool memberList::isEmpty() const
{
	return (length == 0);
}

//O(n)
void memberList::deleteItem(string item)
{
	for (int i = 0; i < length; i++)
	{
		if (info[i].getid() == item)
		{
			info[i] = info[length - 1];
			length--;
		}
	}
}
//O(n)
void memberList::dispalyList()
{
	if (!isEmpty()){
		for (int i = 0; i < length; i++)
		{
			gotoxy(50, i+21);
			cout << info[i].getfName() << ", ";
			cout << info[i].getlName() << ", " ;
			cout << info[i].getid() << ", ";
			cout << info[i].getmiles() << endl;
		}
	}
	else{
		cout << "Member list is empty" << endl;
	}
}

//O(1)
int memberList::getLength()
{
	return length;
}

//O(1)
int memberList::incLength()
{
	length++;
	return length;
}

void memberList::findNum(string item){
	int index = -1;
	for (int i = 0; i < length; i++){
		if (item == info[i].getid()){
			index = i;
		}
	}
	if (index != -1){
		cout << info[index].getfName() << ", " << info[index].getlName() << ", " << info[index].getid() << ", " << info[index].getmiles() << endl;
	}
	else{
		cout << "couldn't find item '" << item << "' in the array" << endl;
	}
	system("pause");
}
string memberList::showfname(int index){
	return info[index].getfName();
}
string memberList::showlname(int index){
	return info[index].getlName();
}
string memberList::showid(int index){
	return info[index].getid();
}
string memberList::showmiles(int index){
	return info[index].getmiles();
}

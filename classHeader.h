#include <iostream>
#include <string>

using namespace std;



class memberType{
public:
	//Default Constructor (default stuff)
	memberType();

	//Overload Constructor (user defined stuff)
	memberType(string, string, string, string);

	//Destructor (destroy stuff at end of program)
	~memberType();

	//Accessor Functions	//we can use "const" here coz they dont mutate or modify anything
	string getfName();		//getfName - get first name of customer
	string getlName();		//getlName - get last name of customer
	string getid();		//getid - get id of customer
	string getmiles();	//getmiles - get total miles traveled

	//Mutator Functions (kinda like overload constructor but they only get one param at a time)
	void setfName(string);		//setName - set first name of customer		@param string - name of customer
	void setlName(string);		//setName - set last name of customer		@param string - name of customer
	void setid(string);			//setid - set id of customer				@param int - id
	void setmiles(string);		//setmiles - set miles traveled				@param double - miles


private:
	//Member variables
	string newfName;
	string newlName;
	string newid;
	string newMiles;

};

class memberList
{
private:
	int length;
	memberType info[50];
public:
	memberList();
	bool isEmpty() const;
	bool isFull() const;
	int getLength();
	int incLength();
	string showfname(int index);
	string showlname(int index);
	string showid(int index);
	string showmiles(int index);
	void showall(int index);
	void insertItem(string fname, string lname, string id, string miles);
	void deleteItem(string item);
	void dispalyList();
	void findNum(string item);
};

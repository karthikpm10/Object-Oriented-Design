#include "../DBWrapper/DBWrapper.h"
#include <iostream>
#include"TestExecutive.h"
using namespace std;
int main()
{
	/*DBWrapper<string> stringDBWrapperobj1("../XMLInputFiles/xmlstring.xml", 5);
	TestExecutive obj;
	obj.runFirstFewreq(stringDBWrapperobj1);
	obj.runNextFewReq(stringDBWrapperobj1);
	obj.runnextfew(stringDBWrapperobj1);*/
	cout << "GO TO InMemoryDB/XMLInputFiles/xmlstring.xml : THIS FILE CONTAINS THE XML file, that describeS project's package structure and dependency relationships, that can be loaded ";
	cout << "\n*************************Requirement 11: Running Test Executive, to demonstrate all the requirements******************************\n";
	vector<string> childrenvector;
	childrenvector.push_back("key4");
	childrenvector.push_back("key3");
	childrenvector.push_back("key2");
	cout << "\n************************creating data with string db******************************\n";
	DBWrapper<string> stringDBWrapperobj("../XMLInputFiles/xmlstring.xml", 9);
	cout << "\n*************************Requirement 5:Loading the db from xml file which describes project dependencies******************************\n";
	stringDBWrapperobj.LoadDBfromXmlStr("../XMLInputFiles/xmlstring.xml");
	stringDBWrapperobj.showDB();
	//addition of key value pairs{requirement 3}
	stringDBWrapperobj.insertElement("key1", "string1", "Category string data1", "string data1 inserted from test executive", childrenvector, "data1str");
	childrenvector.pop_back();
	stringDBWrapperobj.insertElement("key2", "string2", "Category string dataa2", "string data2 inserted from test executive", childrenvector, "data2str");
	childrenvector.pop_back();
	stringDBWrapperobj.insertElement("key3", "string3", "Category string data3", "string data3 inserted from test executive", childrenvector, "data3str");
	childrenvector.pop_back();
	childrenvector.push_back("dummy key");
	stringDBWrapperobj.insertElement("key4", "string4", "Category string dataa4", "string data4 inserted from test executive", childrenvector, "data4str");
	cout << "\n************************ db after inserting******************************\n";
	cout << "\n***************Requirement 2:****************************************\n";
	stringDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Adding \"newchild\" to the child relationship to an already existing \"key4\" ******************************\n";
	stringDBWrapperobj.updateElement("key4", "children", "newchild", true);
	stringDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Removing \"newchild\" from the child relationship to an already existing \"key4\" ******************************\n";
	stringDBWrapperobj.updateElement("key4", "children", "newchild", false);
	stringDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Editing text metadata \"description\" to an already existing \"key3\" ******************************\n";
	stringDBWrapperobj.updateElement("key3", "description", "newdescription");
	stringDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Editing text metadata \"category\" to an already existing \"key3\" ******************************\n";
	stringDBWrapperobj.updateElement("key3", "category", "newcategory");
	stringDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Editing text metadata \"name\" to an already existing \"key3\" ******************************\n";
	stringDBWrapperobj.updateElement("key3", "name", "newname");
	stringDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Replacing exissting values instance with a new instance to an already existing \"key3\" ******************************\n";
	stringDBWrapperobj.updateElement("key3", "Newdata3");
	stringDBWrapperobj.showDB();
	cout << "\n************************Requirement 7:Querying for value of key=key1******************************\n";
	Element<string> ele = stringDBWrapperobj.getRecord(stringDBWrapperobj.getDBKeys(), "key1");
	cout << ele.show();
	cout << "\n";
	cout << "\n************************Requirement 7:Querying for children of key=key1******************************\n";
	vector<string> keys = stringDBWrapperobj.getChildren(stringDBWrapperobj.getDBKeys(), "key1");
	cout << "\n children of key1 are\n";
	for (string key : keys)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*ke.*\" pattern******************************\n";
	vector<string> keys2 = stringDBWrapperobj.query(stringDBWrapperobj.getDBKeys(), ".*ke.*");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys2)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*ing.*\" pattern in there item name******************************\n";
	vector<string> keys3 = stringDBWrapperobj.query(stringDBWrapperobj.getDBKeys(), ".*ing.*", "ItemName");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys3)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*str.*\" pattern in there data section******************************\n";
	vector<string> keys4 = stringDBWrapperobj.query(stringDBWrapperobj.getDBKeys(), ".*str.*", "data");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys4)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 7:Querying for The set of all keys thet contain values written within a specified time-date interval******************************\n";
	                                                                                             //start date( takes default end date
	vector<string> keys6 = stringDBWrapperobj.queryTimeInterval(stringDBWrapperobj.getDBKeys(), "2017-02-07_00:17:06");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys6)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*dataa.*\" pattern in there category section******************************\n";
	vector<string> keys5 = stringDBWrapperobj.query(stringDBWrapperobj.getDBKeys(), ".*dataa.*", "category");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys5)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 8:Querying for The set of all keys thet contain values written within a specified time-date interval, using keys returned from previous queries******************************\n";
	                                                                     //start date         //end date
	vector<string> keys7 = stringDBWrapperobj.queryTimeInterval(keys5, "2017-02-07_00:17:06","2017-03-08_00:20:05");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys7)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 9:union of keys******************************\n";
	vector<string> unionKeys = stringDBWrapperobj.unionKeys(keys6, keys7);
	for (string key : unionKeys)
	{
		cout << key << "\n";
	}
	cout << "\n**********************Requirement 3: Deletion of key/value pairs********************************\n";
	cout << "\n**********************Database before deleting key2********************************\n";
	stringDBWrapperobj.showDB();
	stringDBWrapperobj.removeElement("key2");
	cout << "\n**********************Database after delete********************************\n";
	stringDBWrapperobj.showDB();
	cout << "\n*************************Requirement 5:writing db to xml file******************************\n";
	stringDBWrapperobj.writeDBToFile("../XMLInputFiles/xmlstring.xml");
	vector<string> childrenvector1;
	childrenvector1.push_back("key4");
	childrenvector1.push_back("key3");
	childrenvector1.push_back("key2");
	cout << "\n************************creating data with int db******************************\n";
	DBWrapper<int> intDBWrapperobj("../XMLInputFiles/xmlint.xml", 9);
	cout << "\n*************************Requirement 5:Loading the db from xml file******************************\n";
	//intDBWrapperobj.LoadDBfromXmlStr("../XMLInputFiles/xmlint.xml");
	intDBWrapperobj.showDB();
	//addition of key value pairs{requirement 3}
	intDBWrapperobj.insertElement("key1", "int1", "Category int data1", "int data1 inserted from test executive", childrenvector1, 10);
	childrenvector1.pop_back();
	intDBWrapperobj.insertElement("key2", "int2", "Category int dataa2", "int data2 inserted from test executive", childrenvector1, 11);
	childrenvector1.pop_back();
	intDBWrapperobj.insertElement("key3", "int3", "Category int data3", "int data3 inserted from test executive", childrenvector1, 12);
	childrenvector1.pop_back();
	childrenvector1.push_back("dummy key");
	intDBWrapperobj.insertElement("key4", "int4", "Category int dataa4", "int data4 inserted from test executive", childrenvector1, 13);
	cout << "\n************************ db after inserting******************************\n";
	cout << "\n***************Requirement 2:****************************************\n";
	intDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Adding \"newchild\" to the child relationship to an already existing \"key4\" ******************************\n";
	intDBWrapperobj.updateElement("key4", "children", "newchild", true);
	intDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Removing \"newchild\" from the child relationship to an already existing \"key4\" ******************************\n";
	intDBWrapperobj.updateElement("key4", "children", "newchild", false);
	intDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Editing text metadata \"description\" to an already existing \"key3\" ******************************\n";
	intDBWrapperobj.updateElement("key3", "description", "newdescription");
	intDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Editing text metadata \"category\" to an already existing \"key3\" ******************************\n";
	intDBWrapperobj.updateElement("key3", "category", "newcategory");
	intDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Editing text metadata \"name\" to an already existing \"key3\" ******************************\n";
	intDBWrapperobj.updateElement("key3", "name", "newname");
	intDBWrapperobj.showDB();
	cout << "\n************************Requirement 4:Replacing exissting values instance with a new instance to an already existing \"key3\" ******************************\n";
	intDBWrapperobj.updateElement("key3", 33);
	intDBWrapperobj.showDB();
	cout << "\n************************Requirement 7:Querying for value of key=key1******************************\n";
	Element<int> eleint = intDBWrapperobj.getRecord(intDBWrapperobj.getDBKeys(), "key1");
	cout << eleint.show();
	cout << "\n";
	cout << "\n************************Requirement 7:Querying for children of key=key1******************************\n";
	vector<string> keys11 = intDBWrapperobj.getChildren(intDBWrapperobj.getDBKeys(), "key1");
	cout << "\n children of key1 are\n";
	for (string key : keys11)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*ke.*\" pattern******************************\n";
	vector<string> keys22 = intDBWrapperobj.query(intDBWrapperobj.getDBKeys(), ".*ke.*");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys22)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*nt.*\" pattern in there item name******************************\n";
	vector<string> keys33 = intDBWrapperobj.query(intDBWrapperobj.getDBKeys(), ".*nt.*", "ItemName");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys33)
	{
		cout << key << "\n";
	}
	/*cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*str.*\" pattern in there data section******************************\n";
	vector<string> keys44 = intDBWrapperobj.query(intDBWrapperobj.getDBKeys(), ".*str.*", "data");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys44)
	{
		cout << key << "\n";
	}*/
	cout << "\n************************Requirement 7:Querying for The set of all keys thet contain values written within a specified time-date interval******************************\n";
	vector<string> keys66 = intDBWrapperobj.queryTimeInterval(intDBWrapperobj.getDBKeys(), "2017-02-07_00:17:06");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys66)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*dataa.*\" pattern in there category section******************************\n";
	vector<string> keys55 = intDBWrapperobj.query(intDBWrapperobj.getDBKeys(), ".*dataa.*", "category");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys55)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 8:Querying for The set of all keys thet contain values written within a specified time-date interval, using keys returned from previous queries******************************\n";
	vector<string> keys77 = intDBWrapperobj.queryTimeInterval(keys55, "2017-02-07_00:17:06");
	cout << "\n Keys matching pattern are\n";
	for (string key : keys7)
	{
		cout << key << "\n";
	}
	cout << "\n************************Requirement 9:union of keys******************************\n";
	vector<string> unionKeys1 = intDBWrapperobj.unionKeys(keys66, keys77);
	for (string key : unionKeys1)
	{
		cout << key << "\n";
	}
	cout << "\n**********************Requirement 3: Deletion of key/value pairs********************************\n";
	cout << "\n**********************Database before deleting key2********************************\n";
	intDBWrapperobj.showDB();
	intDBWrapperobj.removeElement("key2");
	cout << "\n**********************Database after delete********************************\n";
	intDBWrapperobj.showDB();
	
}
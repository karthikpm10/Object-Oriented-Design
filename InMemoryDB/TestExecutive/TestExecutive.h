#pragma once
//////////////////////////////////////////////////////////////////////////////
// TestExecutive.h - key/value pair in-memory database                          //
//                                                                          //
// Karthik Palepally Muniyappa,CSE687 - Object Oriented Design, Spring 2017 // 
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This module defines an TestExecutive Class
this class uses DBWrapper class and inserts,deletes ,updates,queries the db to demostrate the requirements
* Required Files:
* ---------------
*   DBWrapper.h
* Build Process:
* --------------
*   devenv TestExecutive.sln /debug rebuild
*
* Maintenance History:
* --------------------
ver 0.1 : 2nd Feb 2017
*
/*
* -
*/
#include "../DBWrapper/DBWrapper.h"
#include <iostream>
using namespace std;
class TestExecutive
{
public:
	void runFirstFewreq(DBWrapper<string> &stringDBWrapperobj)
	{
		cout << "\n*************************Requirement 11: Running Test Executive, to demonstrate all the requirements******************************\n";
		vector<string> childrenvector;
		childrenvector.push_back("key4");
		childrenvector.push_back("key3");
		childrenvector.push_back("key2");
		cout << "\n*************************Requirement 5:Loading the db from xml file******************************\n";
		stringDBWrapperobj.LoadDBfromXmlStr("../XMLInputFiles/xmlstring.xml");
		stringDBWrapperobj.showDB();
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
	}
	void runNextFewReq(DBWrapper<string> &stringDBWrapperobj)
	{
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
		cout << "\n************************Requirement 7:Querying for The set of all keys matching a \".*dataa.*\" pattern in there category section******************************\n";
		vector<string> keys5 = stringDBWrapperobj.query(stringDBWrapperobj.getDBKeys(), ".*dataa.*", "category");
		cout << "\n Keys matching pattern are\n";
		for (string key : keys5)
		{
			cout << key << "\n";
		}
	}
	void runnextfew(DBWrapper<string> &stringDBWrapperobj)
	{
		cout << "\n************************Requirement 7:Querying for The set of all keys thet contain values written within a specified time-date interval******************************\n";
		vector<string> keys6 = stringDBWrapperobj.queryTimeInterval(stringDBWrapperobj.getDBKeys(), "2017-02-07_00:17:06");
		cout << "\n Keys matching pattern are\n";
		for (string key : keys6)
		{
			cout << key << "\n";
		}
		cout << "\n************************Requirement 8:Querying for The set of all keys thet contain values written within a specified time-date interval, using keys returned from previous queries******************************\n";
		vector<string> keys7 = stringDBWrapperobj.queryTimeInterval(keys6, "2017-02-07_00:17:06");
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
		stringDBWrapperobj.query(stringDBWrapperobj.getDBKeys(), ".*ke.*");
	}
};

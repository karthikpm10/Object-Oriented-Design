# Object-Oriented-Design

Projects
************************************************************************************************************************************************************************************************************
InMemoryDB - C++
In This project I developed a Non SQL database using unordered map and c++ template classes, this database has api's for CRUD operations.
The data stored in the database can be persisted to and from an xml file.

************************************************************************************************************************************************************************************************************

Code Analyser - C++
Code analysis consists of extracting lexical content from source code files, analyzing the code's syntax from its lexical content, and building a Type Table (TT) or an Abstract Syntax Tree (AST) that hold the results of our analysis. It is then fairly easy to build several backends that can do further analyses on the data held in TT or AST to construct code metrics, search for particular constructs, or some other interesting features of the code.
This project takes in source code files of c++ and c# project. 

************************************************************************************************************************************************************************************************************
Code Publisher - C++
Code publisher publishes the source code files of projects as web pages with embedded child links. Each link refers to a code file that the displayed code file depends on.
Code Publisher creates .Html files for each source code file.

************************************************************************************************************************************************************************************************************
Remote Code Publisher - C++

A Code Repository is a Program responsible for managing source code resources, e.g., files and documents. A fully developed Repository will support file persistance, management of versions, and the acquisition and publication of source and document files. A Remote Repository adds the capability to access the Repository's functionality over a communication channel, e.g., interprocess communication, inter-network communication, and communication across the internet.

This project focuses on the publication functionality of a Remote Repository. This project includes a remote code publisher, local client, and communication channel that supports client access to the publisher from any internet enabled processor.

The communication channel will use sockets and support an HTTP like message structure. 

The channel supports:

HTTP style request/response transactions
One-way communication, allowing asynchronous messaging between any two endpoints that are capable of listening for connection requests and connecting to a remote listener.
Transmission of byte streams that are set up with one or more negotiation messages followed by transmission of a stream of bytes of specified stream size2.


The Remote Code Publisher :

Support publishing web pages that are small wrappers around C++ source code files.
Accept source code text files, sent from a local client.
Support building dependency relationships between code files saved in specific repository folders.
Support HTML file creation for all the files in a specified repository folder1, including linking information that displays dependency relationships, and supports and navigation based on dependency relationships.
Delete stored files, as requested by a local client.


Clients of the Remote Code Publisher provides a Graphical User Interface (GUI) with means to:

Upload one or more source code text files to the Remote Publisher, specifying a category with which those files are associated1.
Display file categories, based on the directory structure supported by the Repository.
Display all the files in any category.
Display all of the files in any category that have no parents.
Display the web page for any file in that file list by clicking within a GUI control.

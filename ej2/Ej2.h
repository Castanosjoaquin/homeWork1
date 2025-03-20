#include <iostream> 
#include <string>
#include <fstream>


using namespace std; 


void logMessage(string message, int severity);
void logMessage(string error, string file, int line); 
void logMessage(string accessMsg,string user); 

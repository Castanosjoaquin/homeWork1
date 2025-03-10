#include "Ej2.h"	
enum class severity_levels: int{DEBUG =1,INFO,WARNING,ERROR,CRITICAL}; 

int main(){ 
    logMessage("puto el que lee, re troll xd", 1); 
    return 0; 
}

void logMessage(string message, auto severity){ 
    ofstream logFile("logFile.txt", ios::app); 
    if(logFile.is_open()){
        switch (severity) {
        case severity_levels::DEBUG: 
            logFile << "[DEBUG]" << ' ' << message; 
        case severity_levels::INFO: 
            logFile<<"[INFO]"<< ' ' << message; 
        case severity_levels::WARNING: 
            logFile<<"[WARNING]"<< ' ' << message; 
        case severity_levels::ERROR: 
            logFile<<"[ERROR]"<< ' ' << message; 
        case severity_levels::CRITICAL: 
            logFile<<"[CRITICAL]"<< ' ' << message; 
        default:
            cout<<"chupame la pija"; 
        }
        logFile.close(); 
}else
    cerr<<"Erro al abrir el archivo"; 
}
#include "Ej2.h"	
enum class severity_levels: int{DEBUG =1,INFO,WARNING,ERROR,CRITICAL}; 

int main(){ 
    return 0; 
} 

void logMessage(string message, auto severity){ 
    ofstream logFile("logFile.txt", ios::app); 
    if(logFile.is_open()){
        switch (severity) {
        case severity_levels::DEBUG: 
            logFile << "[DEBUG]" << ' ' << message; 
            break;
        case severity_levels::INFO: 
            logFile<<"[INFO]"<< ' ' << message; 
            break;
        case severity_levels::WARNING: 
            logFile<<"[WARNING]"<< ' ' << message; 
            break;
        case severity_levels::ERROR: 
            logFile<<"[ERROR]"<< ' ' << message; 
            break;
        case severity_levels::CRITICAL: 
            logFile<<"[CRITICAL]"<< ' ' << message; 
            break;
        default:
            cout<<"Unknow alert"; 
        }
        logFile.close(); 
}else
    cerr<<"Erro al abrir el archivo"; 
}
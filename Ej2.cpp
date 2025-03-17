#include "Ej2.h"	
enum severity_levels: int{DEBUG =1,INFO,WARNING,ERROR,CRITICAL}; 

int main(){ 

    try{ 

    }
    catch(){  
        
    }



    return 0;  
} 

void logMessage(string message,int  severity){ 
    ofstream logFile("logFile.txt", ios::app); 
    if(logFile.is_open()){
        switch (severity) {
            case severity_levels::DEBUG: 
                logFile << "[DEBUG]" << " <" << message << ">"; 
                break;
            case severity_levels::INFO: 
                logFile<<"[INFO]"<< " <" << message<< ">"; 
                break;
            case severity_levels::WARNING: 
                logFile<<"[WARNING]"<< " <" << message<< ">"; 
                break;
            case severity_levels::ERROR: 
                logFile<<"[ERROR]"<< " <" << message<< ">"; 
                break;
            case severity_levels::CRITICAL: 
                logFile<<"[CRITICAL]"<<" <"<< message<< ">"; 
                break;
            default:
                cout<<"Unknow alert"; 
        }
        logFile.close(); 
}else
    cerr<<""; 
}


void logMessage(string error, string file, int line){ 
    ofstream logFile("logFile.txt",ios::app); 
    if(logFile.is_open()){ 
        logFile<<"On file: " << file<< error<< " at "<< line<<endl;
        logFile.close(); 
    }
    else cerr<<"Error opening the file."<<endl; 
}


void logMessage(string accessMsg,string user){ 
    ofstream logFile("logFile.txt", ios::app);  
    if(logFile.is_open()){ 
        logFile<<"[Security]" <<accessMsg<<" <"<< user<<">"<<endl; 
        logFile.close();
    }
    else cerr<<"Error opening the file."<<endl ;
}




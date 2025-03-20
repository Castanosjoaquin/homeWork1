#include "Ej2.h"	
enum severity_levels: int{DEBUG =1,INFO,WARNING,ERROR,CRITICAL}; 

int main(){ 
    try{ 
        //verificacion de la funciones del primero item
        string message = "Mensaje"; 
        logMessage(message,DEBUG ); 
        logMessage(message, 2); 
        logMessage(message, 3); 
        logMessage(message, ERROR);  
        logMessage(message, CRITICAL); 
        //verificacion del segundo item 
        logMessage("Unknow error, check with chat gpt","homework.cpp",19); 
        //verficacion del tercer item
        logMessage("Access denied", "castanosjoaquin");

        //verificacion de captura de runtime error 
        throw runtime_error("Algo salio mal!");
    }
    catch(runtime_error& e){
        std::cout << "Runtime error: " << e.what() << std::endl;
        return 1; 
    }
    return 0;  
} 
void logMessage(string message,int  severity){ 
    ofstream logFile("logFile.txt", ios::app); 
    if(logFile.is_open()){
        switch (severity) {
            case severity_levels::DEBUG: 
                logFile << "[DEBUG]" << " <" << message << ">"<<endl; 
                break;
            case severity_levels::INFO: 
                logFile<<"[INFO]"<< " <" << message<< ">"<<endl; 
                break;
            case severity_levels::WARNING: 
                logFile<<"[WARNING]"<< " <" << message<< ">"<<endl; 
                break;
            case severity_levels::ERROR: 
                logFile<<"[ERROR]"<< " <" << message<< ">"<<endl; 
                break;
            case severity_levels::CRITICAL: 
                logFile<<"[CRITICAL]"<<" <"<< message<< ">"<<endl; 
                break;
            default:
                cout<<"Unknow alert"<<endl; 
        }
        logFile.close(); 
}else
    cerr<<"Error opening the file."<<endl ;
}


void logMessage(string error, string file, int line){ 
    ofstream logFile("logFile.txt",ios::app); 
    if(logFile.is_open()){ 
        logFile<<error<<" On file: " << file<< " at "<< line<<endl;
        logFile.close(); 
    }
    else cerr<<"Error opening the file."<<endl; 
}


void logMessage(string accessMsg,string user){ 
    ofstream logFile("logFile.txt", ios::app);  
    if(logFile.is_open()){ 
        logFile<<"[Security]" <<accessMsg<<": <"<< user<<">"<<endl; 
        logFile.close();
    }
    else cerr<<"Error opening the file."<<endl ;
}




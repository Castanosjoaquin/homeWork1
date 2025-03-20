#include "Ej4.h"

consteval bool are_equal(const char* txt1, const char* txt2){  
    if (*txt1 == '\0' && *txt2 == '\0') return true;
    if( *txt1 != *txt2) return false; 
    return are_equal(txt1 + 1, txt2 + 1);   
} 

int main(){ 

    //Se chequea el tiempo de comparar en tiempo de compilacion 
    constexpr const char x1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";
    constexpr const char x2[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";

    cout<<"Tiempo de compilacion"<<endl;
    auto startTime = chrono::high_resolution_clock::now(); 
    are_equal(x1, x2); 
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    cout << "A are_equal le tomó: " << elapsedTime.count() << " nanosegundos" << endl; 


    //Se chequea el tiempo de comparar dos char* en tiempo de ejecucion 
    char t1[] ="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";
    char t2[] ="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";

    cout<<"Se chequea el tiempo de comparar dos char* en tiempo de ejecucion"<<endl; ; 
    check_comparation_time(t1,t2); 

    //Se chequea el tiempo de comparar dos string en tiempo de ejecucion
    string s1 ="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";
    string s2 ="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";

    cout<<"Se chequea el tiempo de comparar dos string en tiempo de ejecucion"<<endl; 
    check_comparation_time(s1,s2);

    return 0;
}

bool are_equal(char* txt1, char* txt2){ 
    if (txt1[0] == '\0' && txt2[0] == '\0') return true; //chequeo si el el string llego al final
    if( txt1[0] != txt2[0]) return false; // si los characters son distintos 
    return are_equal(txt1 + 1, txt2 + 1); // llamado recursivo moviendo el puntero hacia adelante
} 

bool are_equal(string txt1, string txt2){ 
    if(txt1.length() != txt2.length()) return false; //si los largos son distintos return falseX
    if(txt1.length()==1 ) return txt1 == txt2; // si llegamos a la ultima letra, devolve si son iguales
    int middle= txt1.length()/2; 
    if (middle == 0)  return txt1 == txt2; // si middle dio 0, devolve si son iguales 
    return(are_equal(txt1.substr(0,middle),txt2.substr(0,middle)) && (are_equal(txt1.substr(middle),txt2.substr(middle)))); //divide and conquer
}

void check_comparation_time(auto txt1, auto txt2){ 
    auto startTime = chrono::high_resolution_clock::now(); 
    are_equal(txt1, txt2); 
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    cout << "A are_equal le tomó: " << elapsedTime.count() << " nanosegundos" << endl;   
}
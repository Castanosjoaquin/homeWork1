#include <iostream>
#include <chrono>

using namespace std;


constexpr bool are_equal( const char* txt1, const char* txt2){ 
    if (*txt1 == '\0' && *txt2 == '\0') return true;
    if( *txt1 != *txt2) return false; 
    return are_equal(txt1 + 1, txt2 + 1);
} 

int main(){  
    constexpr char x1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";
    constexpr char x2[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";

    cout<<"char* complation time test"<<endl; 
    constexpr bool r =  are_equal(x1,x2); 
    

    auto startTime = chrono::high_resolution_clock::now(); 
    if (r) {
        cout << "Los strings son iguales." << endl;
    } else {
        cout << "Los strings no son iguales." << endl;
    }
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    cout << "A are_equal le tomó: " << elapsedTime.count() << " nanosegundos" << endl;   



}
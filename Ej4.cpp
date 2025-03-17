#include "Ej4.h"


// Para hacer la recursion es mejor usar char* debido a la diferencia de velocidad q tiene, que se destada mas en los textos largos. 
// sin embargo, seguramente se puede bajar el tiempo de los str con otra implentacion pero no se va a acercar a los char* 


constexpr bool are_equal(const char* txt1, const char* txt2){ 
    if (*txt1 == '\0' && *txt2 == '\0') return true;
    if( *txt1 != *txt2) return false; 
    return are_equal(txt1 + 1, txt2 + 1);
} 

int main(){ 

    constexpr const char x1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";
    constexpr const char x2[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";

    const bool  r = are_equal(x1,x2); 
    cout<<"char* complation time test"<<endl;
    check_comparation_time(x1,x2);  

    char t[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";
    char t2[] = "lorem ipsum dolor sit amet, consectetur whwadipiscing elit. Sed do.";
    string s1= "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";
    string s2 = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed Do.";

    cout<<"Negative test"<< endl; 
    cout<< are_equal(t,t2)<<endl; 
    cout<< are_equal(s1,s2)<<endl; 

    char t3[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";
    string s3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do.";

    cout<<"Positive test"<<endl; ; 
    cout<< are_equal(t,t3)<<endl; 
    cout<< are_equal(s1,s3)<<endl; 
    
    cout<<"char* time test"<<endl; ;
    check_comparation_time(t,t2);
    cout<<"str time test"<<endl; 
    check_comparation_time(s1,s2);

    cout<<"char* complation time test again"<<endl;
    check_comparation_time(r);

    return 0;
}

bool are_equal(string txt1, string txt2){ 
    if(txt1.length() != txt2.length()) return false; 
    if(txt1.length()==1 ) return txt1 == txt2; 

    int middle= txt1.length()/2; 
    if (middle == 0)  return txt1 == txt2; 

    string subString1a = txt1.substr(0,middle);
    string subString2a = txt2.substr(0,middle);
    string subString1b = txt1.substr(middle);
    string subString2b = txt2.substr(middle);
  
    return(are_equal(subString1a,subString2a) && (are_equal(subString1b, subString2b))); 
}

bool are_equal(char* txt1, char* txt2){ 
    if (txt1[0] == '\0' && txt2[0] == '\0') return true;
    if( txt1[0] != txt2[0]) return false; 
    return are_equal(txt1 + 1, txt2 + 1);
} 

void check_comparation_time(auto txt1, auto txt2){ 
    auto startTime = chrono::high_resolution_clock::now(); 
    are_equal(txt1, txt2); 
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    cout << "A are_equal le tomó: " << elapsedTime.count() << " nanosegundos" << endl;   
}

void check_comparation_time(bool r){ 
    auto startTime = chrono::high_resolution_clock::now(); 
    if (r) {
        cout << "Los textos son iguales" << endl;
    } else {
        cout << "Los textos son distintos" << endl;
    }
    auto endTime = chrono::high_resolution_clock::now(); 
    auto elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    cout << "A are_equal le tomó: " << elapsedTime.count() << " nanosegundos" << endl;   
}



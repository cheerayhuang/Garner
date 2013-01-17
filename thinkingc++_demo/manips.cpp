#include <fstream> 
#include <iomanip> 
#include <iostream> 

using namespace std; 

int main()
{
    int i = 47; 

    ofstream trc("trace.out"); 

    trc.setf(ios::left, ios::adjustfield); 

    trc << setw(10) << setfill('c') << i << endl; 

    trc << right << i << endl; 
    trc << setw(10) << i << endl; 

    trc << setw(10); 
    trc << i << endl; 

    trc << i << setw(10); 
    trc << i << endl;

    trc << i << setw(10) << endl;
    trc << i << endl; 

    float f = 2300114.414; 

    trc << fixed << setprecision(1) << f << endl; 
    trc << scientific << f << endl; 
    
    //trc << resetiosflags(ios::scientific) << f << endl; 

    // automatic mode.
    trc.unsetf(ios::scientific); 
    trc << f << endl; 


    trc.fill('0');
    trc << showbase << oct << setw(10) << i << endl;
    trc << i << endl; 

    trc << noshowbase; 
    trc << hex << setw(10) << i << endl; 

    trc << setiosflags(ios::showbase) << setw(10) << i << endl; 



    return 0; 
}

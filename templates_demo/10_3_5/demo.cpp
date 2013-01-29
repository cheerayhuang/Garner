template <typename T> 
void f1(T x) 
{
    g1(x); 
}

void g1(int)
{

}

int main() 
{
    f1(7); 

    return 0; 
}

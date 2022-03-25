#include <iostream>
bool b=true; //1 бит(но занимает 1 байт)
char c='\n';// 1 байт
short s=0b10;//2 байта (16 битов)
int i=012;//4 байта () 
signed si=012;// знаковый (+ или -)
long l=0x16;//64 бита (8 байтов)
unsigned long ul=-1ul;//(только + либо 0)
float f=0.7;// число с точками (плавающие точки)
double d=0.7f;// двйоной float 
const char* str=&c;// указатель на байты (число 78)
int main(int argc,const char** argv){
    std::cout<< "argc="<<argc<<'\n';
    std::cout<< "argv="<<*argv<<'\n';
    system("echo 1337");
    int Term,array[78];
    int matrix[89][26];
    int* ptr=array;
    std::cout<< "int size="<<sizeof(int)<<'\n';
    std::cout<< "HelloWorld"<<'\n'; 
    fprintf (stdout,"HelloWorld""\n");
    std::cout<< "Unit"<<"\n";
    std::cin>>Term;
    std::cout<<Term;
    return 0xae01;
}

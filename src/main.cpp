/* первый тип коментария должен заканчиваться на подобноый но обратный символ 
(коментарий много строчный) */
#include <iostream> 
#include <filesystem>
//main() - второй тип коментария 
void test_operators();
void test_filesystem();
void test_pointers();
void test_arrays();
int main()
{
    ::test_operators();
    ::test_filesystem();
    ::test_pointers();
    return 0;
}
void test_operators()
{
    std::cout<<(void*)test_operators<<std::endl;
    std::cout<<(void*)test_pointers<<std::endl;
    std::cout<<(void*)test_filesystem<<std::endl;
    std::cout<<(void*)main<<std::endl;
}
void test_filesystem()
{
    ::std::cout <<"my first program"<<std::endl;
    ::std::cout <<std::filesystem::current_path()<<std::endl;
    std::filesystem::current_path("C://");
    ::std::cout <<std::filesystem::current_path()<<std::endl;
    return;
}
void test_pointers() 
{
    int mino=78;
    mino=13654;
    int* ptr=&mino;
    ::std::cout<<&mino<<std::endl;
    ::std::cout<<*ptr<<std::endl;
    *ptr=635;
    ::std::cout<<*ptr;
}
void test_arrays()
{
    int arr[797];
    int* ptr=arr;
    arr[632]=54;
    ptr[702]=389;
}
/* первый тип коментария должен заканчиваться на подобноый но обратный символ 
(коментарий много строчный) */
#include <iostream> 
#include <filesystem>
//main() - второй тип коментария 
void test_operators();
void test_filesystem();
void test_pointers();
void test_arrays();
void test_statements();
int main()
{
    ::test_statements();
    //::test_operators();
    //::test_filesystem();
    //::test_pointers();
    return 0;
}
void test_operators()
{
    std::cout<<(void*)test_operators<<std::endl;
    std::cout<<(void*)test_pointers<<std::endl;
    std::cout<<(void*)test_filesystem<<std::endl;
    std::cout<<(void*)main<<std::endl;
    const wchar_t*wstr=L"Привет Мир!";
    std::wcout<<*wstr<<std::endl;
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
    ::std::cout<<"--mino==78="<<(--mino==78)<<'\n';
    mino++;
    ::std::cout<<"mino--==78="<<(mino--==78)<<'\n';
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
void test_statements()
{
    if (false)
    {
        std::cout<<"This is inside of if(true)"<<std::endl;
    }
    else if (true)
    {
        std::cout<<"This is inside of else if(false)"<<std::endl;
    }
    else 
    {
        std::cout<<"This is inside of else"<<std::endl;
    }
    bool flag=true;
    while (flag) //while (eng)- пока "в то время как" 
    {
        flag=false;
        ::std::cout<<"While"<<std::endl;
        //break;
    }
    do 
    {
        flag=false;
        ::std::cout<<"Do while"<<std::endl;
    } while (flag);
    // Первый часть - объявление переменных; Вторая часть - условие; Третья часть - что делать после каждой итерации(выполнение кода в скобочках "{}");
    for (int i = 0; ++i <= 10;)
    {
        ::std::cout<<i<<std::endl;
    }
    int exp=1;
    switch (exp)
    {
    case 0: //case(eng) -случай
        ::std::cout<<"case zero"<<std::endl;
        ::std::cout<<"case zero"<<std::endl;
        break; //break - закончить (обязательно в случае использования case для того чтобы закончить исполнение)
    
    default:
        break;

    case 1:
        ::std::cout<<"case one"<<std::endl;
        ::std::cout<<"case one"<<std::endl;
        break; //break - закончить (обязательно в случае использования case для того чтобы закончить исполнение)
    }
    
}
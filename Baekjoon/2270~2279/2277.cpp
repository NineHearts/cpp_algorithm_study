#include <iostream>
#include <string>

class Locker
{
    private:
        short dial_n;
        short range_m;
        short * number;
        short number_length;
        int center;
    public:
    
        void init_locker(std::string n, std::string num);
        void show_locker();
        void get_center();
        ~Locker();
};

void Locker::init_locker(std::string n, std::string num)
{

    dial_n = atoi(n.substr(0, n.find(' ')).c_str());
    range_m = atoi(n.substr(n.find(' ') + 1, n.length()).c_str());
    number = new short[num.length()]();
    number_length = num.length();

    for (int i = 0; i < num.length(); i++)
    {
        number[i] = atoi(num.substr(i, 1).c_str());
        std::cout << number[i] << std::endl;
    }

    show_locker();
}

void Locker::show_locker()
{
    using std::cout;

    cout << "count of dials : " << dial_n << std::endl;
    cout << "range of dial number : " << range_m << std::endl;
    cout << "setup number : ";
    for (int i = 0; i < number_length; i++)
        cout << number[i];
    
}

void Locker::get_center()
{
    for (int i = 0; i < number_length; i++)
    {
        
    }
}

Locker::~Locker()
{
    delete[] number;
}


int main()
{
    using std::cout;
    using std::cin;

    std::string n;
    std::string m;

    Locker lock;

    getline(cin, n);
    getline(cin, m);

    lock.init_locker(n, m);

    return 0;
}
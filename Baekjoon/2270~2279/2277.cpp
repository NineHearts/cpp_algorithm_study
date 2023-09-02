#include <iostream>
#include <string>

class Lock
{
    private:
        short dial_n;
        short range_m;
        short *number;
        short number_length;
        short *forward, *reverse;
    public:
        void init_lock(std::string n, std::string num);
        void show_lock();
        void solve();
        ~Lock();
};

void Lock::init_lock(std::string n, std::string num)
{

    dial_n = atoi(n.substr(0, n.find(' ')).c_str());
    range_m = atoi(n.substr(n.find(' ') + 1, n.length()).c_str());
    number = new short[num.length()]();
    number_length = num.length();
    forward = new short[num.length() - 1]();
    reverse = new short[num.length() - 1]();

    for (int i = 0; i < num.length(); i++)
    {
        number[i] = atoi(num.substr(i, 1).c_str());
        std::cout << number[i] << std::endl;
    }

    using std::cout;

    cout << "count of dials : " << dial_n << std::endl;
    cout << "range of dial number : " << range_m << std::endl;
    cout << "setup number : ";
    for (int i = 0; i < number_length; i++)
        cout << number[i];
}

void Lock::show_lock()
{
    for (int i = 0; i < number_length; i++)
        std::cout << number[i];
}

void Lock::solve()
{
    int i;
    int temp = 0;
    for (i = 0; i < number_length - 1; i++)
    {
        if (temp == 0)
            temp = number[i+1];
        else
            forward[i] = (temp < number[i+1]) ? (number[i+1] - temp) : (number[i+1] - temp) + 10 
    }
}

Lock::~Lock()
{
    delete[] number;
}


int main()
{
    using std::cin;
    using std::string;

    string n;
    string m;

    Lock lock;

    getline(cin, n);
    getline(cin, m);

    lock.init_lock(n, m);

    return 0;
}
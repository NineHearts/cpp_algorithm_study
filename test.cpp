#include <iostream>
#include <string>
#include <algorithm>

class Lock
{
    private:
        short dial_n;
        short range_m;
        short *number;
        short *forward, *reverse;
        short time_lapse;
    public:
        void init_lock(std::string n, std::string num);
        void show_lock();
        void solve();
        void get_correction();
        int *get_data();
        void turn_dial(int *data);
        ~Lock();
};

void Lock::init_lock(std::string n, std::string num)
{
    dial_n = atoi(n.substr(0, n.find(' ')).c_str());
    range_m = atoi(n.substr(n.find(' ') + 1, n.length()).c_str());
    number = new short[dial_n]();
    forward = new short[num.length() - 1]();
    reverse = new short[num.length() - 1]();
    time_lapse = 0;

    int start = 0;
    int end = num.find(' ');

    for (int i = 0; i < dial_n; i++) 
    {
        if (i == (dial_n - 1))
        {
            number[i] = atoi(num.substr(start).c_str());
        } 
        else 
        {
            number[i] = atoi(num.substr(start, end - start).c_str());
            start = end + 1;
            end = num.find(' ', start);
        }
    }

}

void Lock::show_lock()
{
    std::cout << time_lapse;
}

void Lock::solve()
{
    int * data;

    while (1)
    {
        get_correction();
        data = get_data();
        if (data[0] == -1)
            break;
        turn_dial(data);
    }
    show_lock();
}

void Lock::get_correction()
{
    int i;
    int temp = 0;
    for (i = 0; i < dial_n - 1; i++)
    {
        temp = number[i];
        forward[i] = (number[i+1] >= temp) ? (number[i+1] - temp) : (number[i+1] - temp + range_m);

    }

    for (i = dial_n - 1; i > 0; i--)
    {
        temp = number[i];

            reverse[i-1] = (number[i-1] >= temp) ? (number[i-1] - temp) : (number[i-1] - temp) + range_m;

    }
}

int *Lock::get_data()
{
    int * data = new int[3];
    int min = range_m + 1;
    int index, type;   
    for (int i = 0; i < dial_n - 1; i++)
{
        if (forward[i] != 0)
        {
            if (min > forward[i])
            {
                min = forward[i];
                index = i;
                type = 0;
            }    
        }
    }
    
    for (int i = 0; i < dial_n - 1; i++)
    {
        if (reverse[i] != 0)
        {
            if (min > reverse[i])
            {
                min = reverse[i];
                index = i;
                type = 1;
            }
        }
    }
    
    if (min == range_m + 1)
        min = -1;

    data[0] = min;
    data[1] = index;
    data[2] = type;

    return data;
}

void Lock::turn_dial(int *data)
{
    int temp = -1;
    if (data[2])
    {
        for (int i = data[1]; i < dial_n; i++)
        {
            if (temp == -1)
                temp = i+1;
            else
                if (number[i] == number[temp])
                    temp = i;
        }

        for (int i = data[1]; i < temp; i++)
        {
            number[i + 1] += data[0];
            number[i + 1] %= range_m;
        }

    }
    else
    {
        for (int i = data[1]; i >= 0; i--)
        {
            if (temp == -1)
                temp = i;
            else
                if (number[i] == number[temp])
                    temp = i;
        }

        for (int i = data[1]; i >= temp; i--)
        {
            number[i] += data[0];
            number[i] %= range_m;
        }
    }

    time_lapse += data[0];
    delete[] data;
}

Lock::~Lock()
{
    delete[] number;
    delete[] forward;
    delete[] reverse;
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
    lock.solve();

    return 0;
}
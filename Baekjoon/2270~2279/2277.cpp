#include <iostream>
#include <string>
#include <algorithm>

class Lock
{
    private:
        short dial_n;
        short range_m;
        short *number;
        short number_length;
        short *forward, *reverse;
        short * _history;
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
    number = new short[num.length()]();
    number_length = num.length();
    forward = new short[num.length() - 1]();
    reverse = new short[num.length() - 1]();
    time_lapse = 0;

    for (int i = 0; i < num.length(); i++)
    {
        number[i] = atoi(num.substr(i, 1).c_str());
    }

    using std::cout;

    // cout << "count of dials : " << dial_n << std::endl;
    // cout << "range of dial number : " << range_m << std::endl;
    // cout << "setup number : ";
    // for (int i = 0; i < number_length; i++)
    //     cout << number[i];
    // cout << std::endl;
}

void Lock::show_lock()
{
    std::cout<< "dial number is : ";
    for (int i = 0; i < number_length; i++)
        std::cout << number[i];
    std::cout << std::endl;
    std::cout << "time : " << time_lapse << std::endl;
}

void Lock::solve()
{
    int * data;     // [0] : min value, [1] : index of min value, [2] : where the min value is(0 : forward, 1 : reverse)
    
    // do
    // {
    //     get_correction();
    //     data = get_data();
    //     turn_dial(data);
    // }
    // while (data[0] != -1);

    do
    {
        std::cout << "==========================" << std::endl;
        std::cout << "before turn dial : ";
        show_lock();
        get_correction();
        data = get_data();
        turn_dial(data);
        std::cout << "==========================" << std::endl;
    }
    while (data[0] != -1);
    show_lock();
    

}

void Lock::get_correction() // 각 자릿수에서 인접한 다이얼과의 차이
{
    int i;
    int temp = 0;
    for (i = 0; i < number_length - 1; i++) // number의 마지막 배열 원소 뒤로는 더이상 연산을 못하므로 -1을 한다.
    {
        temp = number[i];
        forward[i] = (number[i+1] >= temp) ? (number[i+1] - temp) : (number[i+1] - temp + range_m);

    }

    for (i = number_length - 1; i > 0; i--) // number의 맨 뒤에서 시작하므로 배열의 크기인 number length 에서 1을 뺴 배열의 마지막 원소 위치를 넣는다.
    {
        temp = number[i];

            reverse[i-1] = (number[i-1] >= temp) ? (number[i-1] - temp) : (number[i-1] - temp) + range_m;

    }

    // print array print array print array print array print array print array print array print array print array print array 
    // print array print array print array print array print array print array print array print array print array print array 
    std::cout << "forward array : ";
    for (int i = 0; i < number_length - 1; i++)
        std::cout << forward[i];
    
    std::cout << std::endl;
    std::cout << "reverse array : ";
    for (int i = 0; i < number_length - 1; i++)
        std::cout << reverse[i];
    std::cout << std::endl;
}

int *Lock::get_data()
{
    int * data = new int[3];    // [0]:min value, [1]:index of min value, [2]:where the min value is(0 : forward, 1 : reverse)
    int min = range_m + 1;      // 어떤 숫자가 나오던 1 더 높은 숫자로 설정
    int index, type;   
    for (int i = 0; i < number_length - 1; i++)
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
    
    for (int i = 0; i < number_length - 1; i++)
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
    std::cout << "min : " << min << "\tindex : " << index << "\ttype : " << type << std::endl;

    return data;
}

void Lock::turn_dial(int *data)
{
    int temp = -1;
    if (data[2])    // if array is reverse.
    {
        std::cout << "reverse dial turn..." << std::endl;
        for (int i = data[1]; i < number_length; i++)
        {
            if (temp == -1)
                temp = i+1;
            else
                std::cout << "num[i] : " << number[i] << "\tnum[temp] : " << number[temp] << std::endl;
                if (number[i] == number[temp])
                    temp = i;
                    std::cout << "temp : " << temp << std::endl;
        }

        for (int i = data[1]; i < temp; i++)
        {
            number[i + 1] += data[0];    // reverse 배열은 뒤의 번호를 앞의 번호에 맞춰야 함으로 +1 한 배열의 값을 바꿈
            number[i + 1] %= range_m;
        }

    }
    else            // if array is forward
    {
        std::cout << "forward dial turn..." << std::endl;
        for (int i = data[1]; i > 0; i--)
        {
            if (temp == -1)
                temp = i;
            else
                std::cout << "num[i] : " << number[i] << "\tnum[temp] : " << number[temp] << std::endl;
                if (number[i] == number[temp])
                    temp = i;
                    std::cout << "temp : " << temp << std::endl;
        }

        for (int i = data[1]; i >= temp; i--)
        {
            number[i] += data[0];
            number[i] %= range_m;
        }
    }

    time_lapse += data[0];
    show_lock();
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
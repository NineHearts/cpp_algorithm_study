#include <iostream>
#include <string>
#include <algorithm>
// 10 50
// 24 1 13 38 47 10 3 25 6 9
// 29 13 4 2 11 24 26 0 9 10
class Lock
{
    private:
        short dial_n;               // 다이얼의 갯수
        short range_m;              // 다이얼 숫자의 범위
        short *number;              // 현재 다이얼 숫자
        short *forward, *reverse;   // 앞의 번호를 기준으로 뒤에 번호를 바꿀지, 뒤의 번호를 기준으로 바꿀지 편차값 저장 배열
        short * _history;           // 사용x 바꾼 다이얼 번호 저장용
        short time_lapse;           // 지난 시간 저장
    public:
        void init_lock(std::string n, std::string num);
        void show_lock();
        void solve();
        void get_difference();
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

    show_lock();

    //using std::cout;
    // cout << "count of dials : " << dial_n << std::endl;
    // cout << "range of dial number : " << range_m << std::endl;
    // cout << "setup number : ";
    // for (int i = 0; i < dial_n; i++)
    //     cout << number[i];
    // cout << std::endl;
}

void Lock::show_lock()
{
    std::cout<< "dial number is : ";
    for (int i = 0; i < dial_n; i++)
        std::cout << number[i] << '\t';
    std::cout << std::endl;
    std::cout << "time : " << time_lapse << std::endl;
}

void Lock::solve()
{
    int * data;     // [0] : min value, [1] : index of min value, [2] : where the min value is(0 : forward, 1 : reverse)
    
    // do
    // {
    //     get_difference();
    //     data = get_data();
    //     turn_dial(data);
    // }
    // while (data[0] != -1);

    while (1)
    {
        std::cout << "==========================" << std::endl;
        //std::cout << "before turn dial : ";

        get_difference();
        data = get_data();
        if (data[0] == -1)
            break;
        show_lock();
        turn_dial(data);
        std::cout << "==========================" << std::endl;
    }
    show_lock();
    

}
void Lock::get_difference() // 각 자릿수에서 인접한 다이얼과의 차이, 
{
    int i;
    int temp = 0;
    for (i = 0; i < dial_n - 1; i++) // number의 마지막 배열 원소 뒤로는 더이상 연산을 못하므로 -1을 한다.
    {
        temp = number[i];
        forward[i] = (number[i+1] >= temp) ? (number[i+1] - temp) : (number[i+1] - temp + range_m);

    }
    for (i = dial_n - 1; i > 0; i--) // number의 맨 뒤에서 시작하므로 배열의 크기인 number length 에서 1을 뺴 배열의 마지막 원소 위치를 넣는다.
    {
        temp = number[i];

            reverse[i-1] = (number[i-1] >= temp) ? (number[i-1] - temp) : (number[i-1] - temp) + range_m;

    }

    // print array print array print array print array print array print array print array print array print array print array 
    // print array print array print array print array print array print array print array print array print array print array 
    std::cout << "forward array : ";
    for (int i = 0; i < dial_n - 1; i++)
        std::cout << forward[i] << "\t";
    
    std::cout << std::endl;
    std::cout << "reverse array : ";
    for (int i = 0; i < dial_n - 1; i++)
        std::cout << reverse[i] << "\t";
    std::cout << std::endl;
}

int *Lock::get_data()
{
    int * data = new int[3];    // [0]:min value, [1]:index of min value, [2]:where the min value is(0 : forward, 1 : reverse)
    int min = range_m + 1;      // 어떤 숫자가 나오던 1 더 높은 숫자로 설정
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
    //std::cout << "min : " << min << "\tindex : " << index << "\ttype : " << type << std::endl;

    return data;
}

void Lock::turn_dial(int *data)
{
    int temp = -1;
    if (data[2])        // if array is reverse.
    {
        //std::cout << "reverse dial turn..." << std::endl;
        for (int i = data[1]; i < dial_n; i++)
        {
            if (temp == -1)
                temp = i+1;
            else
                //std::cout << "num[i] : " << number[i] << "\tnum[temp] : " << number[temp] << std::endl;
                if (number[i] == number[temp])
                    temp = i;
                    //std::cout << "temp : " << temp << std::endl;
        }

        

        for (int i = data[1]; i < temp; i++)
        {
            number[i + 1] += data[0];    // reverse 배열은 뒤의 번호를 앞의 번호에 맞춰야 함으로 +1 한 배열의 값을 바꿈
            number[i + 1] %= range_m;
        }

    }
    else            // if array is forward
    {
                    //std::cout << "forward dial turn..." << std::endl;
        for (int i = data[1]; i >= 0; i--)
        {
            if (temp == -1)
                temp = i;
            else
                //std::cout << "num[i] : " << number[i] << "\tnum[temp] : " << number[temp] << std::endl;
                if (number[i] == number[temp])
                    temp = i;
                    //std::cout << "temp : " << temp << std::endl;
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
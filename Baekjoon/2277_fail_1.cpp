#include <iostream>
#include <string>
#include <algorithm>

// 첫번째 솔루션
// 각 자리에서 각각 왼쪽, 오른쪽 숫자에 맞추는데 필요한 시간을 저장한 배열을 만듦
// 만든 배열에서 가장 시간이 적게 걸리는 인덱스의 숫자를 해당 걸리는 시간만큼 돌림,
// 다시 각 자리에서 각각 왼쪽, 오른쪽 숫자에 맞추는데 필요한 시간을 계산 후 반복
// 그리디 알고리즘
// 실패!

class Lock
{
    private:
        short dial_n;               // 다이얼의 갯수
        short range_m;              // 다이얼 숫자의 범위
        short *number;              // 현재 다이얼 숫자
        short *forward, *reverse;   // 앞의 번호를 기준으로 뒤에 번호를 바꿀지, 뒤의 번호를 기준으로 바꿀지 결정하기 위한 배열
                                    // forward : 다이얼 숫자의 0번째 인덱스부터 n-1까지 앞의 다이얼 번호가 다음 다이얼 번호가 되기 위한 값을 저장
                                    // reverse : 다이얼 숫자의 n-1번째 인덱스부터 0까지 뒤의 다이얼 번호가 앞의 다이얼 번호가 되기 위한 값을 저장
        short *correction;          // 변화량 최솟값을 기준으로 다이얼 값을 변경하기 전 인접한 다이얼들의 횟수가 낭비되는지 확인용
        short * _history;           // 사용x 바꾼 다이얼 번호 저장용
        short time_lapse;           // 지난 시간 저장
    public:
        void init_lock();           // 변수들 입력 및 초기화
        void show_lock();
        void solve();
        void get_difference();      // 각 자릿수에서 인접한 다이얼과의 차이
        void get_correction(int range, int dir);
        int *get_data();                // 
        void turn_dial(int *data);      // new solution
        void turn_dial_(int *data);     // wrong solution
        ~Lock();
};


// 초기값 입력 및 초기화
void Lock::init_lock()
{
    using std::cin;
    cin >> dial_n >> range_m;
    number = new short[dial_n]();
    forward = new short[dial_n - 1]();                        
    reverse = new short[dial_n - 1]();

    for (int i = 0; i < dial_n; ++i)
    {
        cin >> number[i];
    }

    show_lock();
}

// 현재 다이얼 돌림판의 숫자를 보기 위한 함수
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
    int * data;     // 
    
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

// 각 자릿수에서 인접한 다이얼과의 차이, 
void Lock::get_difference()
{
    int i;
    int temp = 0;
    for (i = 0; i < dial_n - 1; i++) // number의 마지막 배열 원소 뒤로는 더이상 연산을 못하므로 -1을 한다.
    {
        temp = number[i];
        forward[i] = (number[i+1] >= temp) ? (number[i+1] - temp) : (number[i+1] - temp + range_m);

    }
    for (i = dial_n - 1; i > 0; i--) // number의 맨 마지막 인덱스에서 시작하므로 배열의 크기인 number length 에서 1을 뺴 배열의 마지막 원소 위치를 넣는다.
    {
        temp = number[i];
        reverse[i-1] = (number[i-1] >= temp) ? (number[i-1] - temp) : (number[i-1] - temp) + range_m;

    }
}


void Lock::get_correction(int idx, int dir)
//  idx : 차이가 가장 적은 값과 인접한 위치와 동일한 값을 가지는 마지막 다이얼의 위치, dir : 좌에서 우인지, 우에서 좌인지 방향
{
    int ref = idx;
    int i = 0;
    int range = 0;
    int index = 0; // 가장 차이가 큰 다이얼의 인덱스
    int value = 0; // 다이얼을 변경할 값
    int dif_1 = 0, dif_2 = 0;       // dif_1 data[ref]와 현재 비교할자다이얼 숫자의 차이

    if (dir)      // reverse
    {
        for (i = (idx); i < dial_n; i++)
        {
            std::cout << "idx? : " << i << " / " << 0 << std::endl;
            if (i <= ref-1)
            {
                int dif_1 = number[i] - number[ref] > 0 ? number[i] - number[ref] : number[i] - number[ref] + range_m;
                int dif_2;
            }
        }
    }
    else        // forward
    {
        for (i = ref; i >= 0; i--)
        {
            std::cout << "idx? : " << i << " / " << dial_n-1 << std::endl;
            if (i <= ref-1)
            {
                dif_1 = number[ref] - number[i] > 0 ? number[ref] - number[i] : number[ref] - number[i] + range_m;
                dif_2;
                if (i == 0){     // 마지막 인덱스, 뒤의 다이얼이 존재하지 않음.
                    range = i;
                }
                else{
                    dif_2 = number[i-1] - number[i] > 0 ? number[i-1] - number[i] : number[i-1] - number[i] + range_m;
                }
                std::cout << "dif_1 : " << dif_1 << "\tdif_2 : " << dif_2 << std::endl;
            }
        }
    }

}

int *Lock::get_data()
{
    // [0]:min value, [1]:index of min value, [2]:where the min value is(0 : forward, 1 : reverse)
    int * data = new int[3];
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
    std::cout << "min : " << min << "\tindex : " << index << "\ttype : " << type << std::endl;

    return data;
}

void Lock::turn_dial_(int *data)
{
    int range = -1;
    int index = 0;
    int left, right;
    if (data[2])        // if array is reverse.
    {

    }
    else            // if array is forward
    {
        for (index = data[1]; index >= 0; index--)      // 동일한 다이얼 번호의 data[i] 부터 다이얼 번호의 처음까지 반복하며 같은 숫자를 찾음
        {
            if (range == -1)                            // 처음 값은 현재의 인덱스로 초기화
                range = index;
            else
                if (number[index] == number[range])     // 이후 값을 바꿀 다이얼의 값과 인접한 같은 값을 가지는 다이얼의 위치 범위를 저장
                    range = index;
                else
                    break;
        }
        std::cout << "range last index number : " << range << std::endl;
        for (index = range; index >= 0; index--)
        {
            std::cout << "back dial number : " << number[index] << std::endl;
        }
        get_correction(range, data[2]);
    }

    time_lapse += data[0];
    show_lock();
    delete[] data;
}

void Lock::turn_dial(int *data)
{
    int range = -1;
    if (data[2])        // if array is reverse.
    {
        //std::cout << "reverse dial turn..." << std::endl;
        for (int i = data[1]; i < dial_n; i++)          // range : 같은 값을 가지는 숫자들의 범위
        {
            if (range == -1)
                range = i+1;
            else
                //std::cout << "num[i] : " << number[i] << "\tnum[temp] : " << number[temp] << std::endl;
                if (number[i] == number[range])
                    range = i;
                    //std::cout << "temp : " << temp << std::endl;
                else
                    break;
        }

        for (int i = range; i < dial_n; i++)
        {
            std::cout << "back dial number : " << number[i] << std::endl;
        }
        get_correction(range, data[2]);
        std::cout << "range last index number : " << range << "(" << number[range] << ")" << std::endl;
        for (int i = data[1]; i < range; i++)
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
            if (range == -1)
                range = i;
            else
                //std::cout << "num[i] : " << number[i] << "\tnum[temp] : " << number[temp] << std::endl;
                if (number[i] == number[range])
                    range = i;
                    //std::cout << "temp : " << temp << std::endl;
                else
                    break;
        }
        for (int i = range; i >= 0; i--)
        {
            std::cout << "back dial number : " << number[i] << std::endl;
        }
        get_correction(range, data[2]);
        std::cout << "range last index number : " << range << "(" << number[range] << ")" << std::endl;
        for (int i = data[1]; i >= range; i--)
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

    lock.init_lock();
    lock.solve();

    return 0;
}
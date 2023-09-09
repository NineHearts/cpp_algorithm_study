#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>

class Lock{
    private:
        int n;                // 다이얼의 갯수
        int m;                // 다이얼 숫자의 범위
        int *number;          // 다이얼 숫자
        int max_index;
    public:
        void init_lock(std::string d, std::string nums);
        void solve();
        ~Lock();
};

// 데이터가 문자열 형태로 전달되므로 정수형 변환이 필요하다.
void Lock::init_lock(std::string d, std::string nums){
    n = atoi(d.substr(0, d.find(' ')).c_str());                // 다이얼 갯수의 수
    m = atoi(d.substr(d.find(' ') + 1, d.length()).c_str());  // 다이얼 숫자의 범위
    number = new int[n]();                                   // 다이얼 숫자

    int start = 0;
    int end = nums.find(' ');

    for (int i = 0; i < n; i++){
        if (i == (n - 1))
            number[i] = atoi(nums.substr(start).c_str());
        else {
            number[i] = atoi(nums.substr(start, end - start).c_str());
            start = end + 1;
            end = nums.find(' ', start);
        }
    }
}

void Lock::solve(){
    int count = -1;
    for (int i = 0; i < n; ++i){
        std::vector<int> gap;
        int temp = 0;
        int sum = 0;

        for (int j = 0; j < n; ++j)
            gap.push_back((number[i] >= number[j]) ? (number[i] - number[j]) : (number[i] - number[j] + m));
        
        for (int num : gap)
            std::cout << num << " ";
        std::cout << std::endl;

        auto max_iter = std::max_element(gap.begin(), gap.end());
        int max_index = std::distance(gap.begin(), max_iter);
        
        while (gap[max_index]){
            
            std::cout << "maximum gap : " << gap[max_index] << std::endl;

            if (max_index == 0){
                temp = gap[max_index] - gap[max_index + 1];
                gap[max_index] -= temp;
                sum += temp;
                std::cout << "temp? : " << temp;
                std::cout << std::endl;

            }else if (max_index == gap.size() - 1){
                temp = gap[max_index] - gap[max_index - 1];
                gap[max_index] -= temp;
                sum += temp;
                std::cout << "temp? : " << temp;
                std::cout << std::endl;

            }else{
                temp = gap[max_index] - (gap[max_index - 1] > gap[max_index + 1] ? gap[max_index - 1] : gap[max_index + 1]);
                gap[max_index] -= temp;
                sum += temp;
                std::cout << "temp? : " << temp;
                std::cout << std::endl;
            }

            for (int num : gap)
                std::cout << num << " ";
            std::cout << std::endl;

            for (int k = gap.size() - 1; k > 0; --k) {
                if (gap[k] == gap[k - 1]) {
                    gap.erase(gap.begin() + k);
                }
            }

            max_iter = std::max_element(gap.begin(), gap.end());
            max_index = std::distance(gap.begin(), max_iter);
        }
        if (count > sum || count == -1)
            count = sum;
    }
    std::cout << count;
}

// void Lock::solve(){
//     std::vector<int> counts;
//     for (int i = 0; i < n; i++){
//         std::vector<int> gap;
//         int count = 0;
//         int max = 0;

//         for (int j = 0; j < n; j++){

//             if (number[i] == number[j])
//                 gap.push_back(0);
//             else
//                 gap.push_back(number[i] - number[j] >= 0 ? number[i] - number[j] : number[i] - number[j] + m);
//         }

//         for (int num : gap) {
//             std::cout << "gap" << num << " ";
//         }
//         std::cout << std::endl;
        
//         auto max_iter = std::max_element(gap.begin(), gap.end());
//         int max_index = std::distance(gap.begin(), max_iter);

//         std::cout << "max idx : " << max_index << ", val : " << gap[max_index_index] << std::endl;

//         while (gap[max_index]){
//             if (max == 0) {
//                 if (gap[max_index] == gap[max_index + 1]) {
//                     gap.erase(gap.begin() + max);
//                 } else {
//                     count = count + gap[max_index] - gap[max_index + 1];
//                     gap[max_index] = gap[max_index + 1];
//                 }
//             } else if (gap[max_index] == gap[max_index + 1]) {
//                 gap.erase(gap.begin() + max);
//             } else if (gap[max_index] == gap[max_index - 1]) {
//                 gap.erase(gap.begin() + max);
//             } else if (gap[max_index - 1] >= gap[max_index + 1]) {
//                 count += gap[max_index] - gap[max_index - 1];
//                 gap[max_index] = gap[max_index - 1];
//             } else if (gap[max_index - 1] < gap[max_index + 1]) {
//                 count += count + gap[max_index] - gap[max_index + 1];
//                 gap[max_index] = gap[max_index + 1];
//             } else if (max == gap.size() - 1) {
//                 count += count + gap[max_index] - gap[max_index - 1];
//                 gap[max_index] = gap[max_index - 1];
//             }
//             max_iter = std::max_element(gap.begin(), gap.end());
//             max_index = std::distance(gap.begin(), max_iter);

//             for (int num : gap) 
//                 std::cout << num << " ";
//             std::cout << std::endl;
//         }

//         counts.push_back(count);
//         std::cout << "count : " << count << std::endl;
//     }
//     auto max_iter = std::max_element(counts.begin(), counts.end());
//     int max_index = std::distance(counts.begin(), max_iter);
//     std::cout << std::distance(counts.begin(), max_iter) << std::endl;
// }

Lock::~Lock()
{
    delete[] number;
}

int main(){
    using std::cin;
    using std::string;

    string data;
    string numbers;
    Lock lock;

    getline(cin, data);
    getline(cin, numbers);

    lock.init_lock(data, numbers);
    lock.solve();

    return 0;
}
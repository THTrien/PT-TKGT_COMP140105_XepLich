#include <iostream>
#include <vector>
#include <algorithm>

struct Meeting {
    int startTime;
    int endTime;
};

bool sortByEndTime(const Meeting& m1, const Meeting& m2) {
    return m1.endTime < m2.endTime;
}

int main() {
    int n;
    //cout << "Nhap so luong cuoc hop: ";
    std::cin >> n;

    std::vector<Meeting> meetings(n);
    for (int i = 0; i < n; i++) {
        //cout << "Nhap thoi gian bat dau va ket thuc cua cuoc hop " ;
        std::cin >> meetings[i].startTime >> meetings[i].endTime;
    }

    std::sort(meetings.begin(), meetings.end(), sortByEndTime);

    std::vector<int> schedule;
    schedule.push_back(0); // Chọn cuộc họp đầu tiên
    int lastEndTime = meetings[0].endTime;

    for (int i = 1; i < n; i++) {
        if (meetings[i].startTime >= lastEndTime) {
            schedule.push_back(i); // Chọn cuộc họp không xung đột
            lastEndTime = meetings[i].endTime;
        }
    }

    std::cout << "Cac cuoc hop duoc to chuc: ";
    for (int i : schedule) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}


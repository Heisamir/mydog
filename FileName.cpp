#include <iostream>
#include <chrono>
#include <string>
using namespace std;

class Dog
{
private:
    int score = 0;
public:
    string name;
    int birthyear;
    void setscore()
    {
        score++;
    }
    int getscore()
    {
        return score;
    }
    void bork()
    {
        cout << "Bork!" << endl;
    }
    int calAge()
    {
        using namespace std::chrono;
        auto now = system_clock::now();
        time_t now_time = system_clock::to_time_t(now);
        tm mytime;
#ifdef _WIN32
        localtime_s(&mytime, &now_time);  // For Windows
#else
        localtime_r(&now_time, &mytime);  // For POSIX
#endif
        int currentYear = mytime.tm_year + 1900;
        return currentYear - birthyear;
    }
};

int main()
{
    Dog myDog;
    myDog.birthyear = 2015;
    myDog.name = "Buddy";
    cout << "Dog's name: " << myDog.name << endl;
    cout << "Dog's age: " << myDog.calAge() << endl;
    myDog.bork();
    myDog.setscore();
    cout << "Dog's score: " << myDog.getscore() << endl;
    return 0;
}

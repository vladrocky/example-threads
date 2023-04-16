#include <iostream>
#include <thread>
#include <vector>

using namespace std;

namespace simpleThread
{

    int worker_A(const vector<int> &collection)
    {

        srand(time(0));

        for (int item : collection)
        {
            this_thread::sleep_for(chrono::milliseconds(10));
            cout << item << " ";
        }

        cout << endl;

        return rand() % 1000;
    }

    void worker_B(int &result, const vector<int> &collection)
    {

        srand(time(0));

        for (int item : collection)
        {
            this_thread::sleep_for(chrono::milliseconds(10));
            cout << item << " ";
        }

        cout << endl;

        result = rand() % 1000;
    }

    void showExample()
    {

        vector<int> collection{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        int result;

        /*
        используем лямбду
        thread threadA([collection, &result]
        {
            result = worker_A(collection);
        });*/

        thread threadB(worker_B, ref(result), ref(collection));

        for (int item : {11, 12, 13, 14, 15, 16, 17, 18, 19, 20})
        {
            this_thread::sleep_for(chrono::milliseconds(10));
            cout << item << " ";
        }

        cout << endl;

        // threadA.join();
        threadB.join();

        // if (threadA.joinable()) {
        //     threadA.join();
        // }

        if (threadB.joinable())
        {
            threadB.join();
        }

        cout << "Result: " << result << endl;
    }
}

int main()
{
    // THREAD
    simpleThread::showExample();

    return 0;
}
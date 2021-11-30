//C++: Implementing max heap and min heap using priority queue.

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Mountain {

public:
    string name;
    int height;

public:
    Mountain(string arg_name, int arg_height) : name(arg_name), height(arg_height)
    {}
};

class CompareName {

public:
    bool operator() (const Mountain& a, const Mountain& b) const {
        // Mountain with smaller name goes below
        if (a.name.size() < b.name.size())
            return true;
        return false;
    }
};

int main()
{
    priority_queue<Mountain, vector<Mountain>, CompareName> pq_mountains;

    Mountain m1("K2", 8611);
    Mountain m2("Kangchenjunga", 8586);
    Mountain m3("Everest", 8848);
    Mountain m4("Annapurna", 8091);

    pq_mountains.push(m1);
    pq_mountains.push(m2);
    pq_mountains.push(m3);
    pq_mountains.push(m4);


    cout << "Arranging mountain name(s) based on the length (max_heap) of the names" << endl;
    while (!pq_mountains.empty()) {
        Mountain mount = pq_mountains.top();
        pq_mountains.pop();
        cout << mount.name << " " << mount.height << endl;
    }

    /* The default template argument to compare template is std::less<T> i.e it is a max heap by default.
       For a min heap "std::greater<T>" needs to be passed */
    priority_queue<int, vector<int>> pq_maxheap;
    pq_maxheap.push(5);
    pq_maxheap.push(2);
    pq_maxheap.push(7);
    pq_maxheap.push(13);
    pq_maxheap.push(11);

    cout << "Elements in max heap : ";
    while (!pq_maxheap.empty()) {
        cout << pq_maxheap.top() << " ";
        pq_maxheap.pop();
    }

    priority_queue<int, vector<int>, greater<int>> pq_minheap;
    pq_minheap.push(5);
    pq_minheap.push(2);
    pq_minheap.push(7);
    pq_minheap.push(13);
    pq_minheap.push(11);

    cout << "\nElements in min heap : ";
    while (!pq_minheap.empty()) {
        cout << pq_minheap.top() << " ";
        pq_minheap.pop();
    }
    return 0;
}
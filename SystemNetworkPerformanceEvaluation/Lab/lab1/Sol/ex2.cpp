#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/* ===== EVENTQUEUE CLASS ===== */

class EventQueue {

    struct Comparator {
        bool operator()(const float& f1, const float& f2)
        {
            if (f1 > f2)
                return true;
            return false;
        }
    };    
    priority_queue<float, vector<float>, Comparator> queue_;
    
public:
    EventQueue() {}
    ~EventQueue() {}
    
    void insert(const float& f);
    float next();
};

void EventQueue::insert(const float& f)
{
    queue_.push(f);
}

float EventQueue::next()
{
    if (queue_.empty())
        return -1;
    
    float f = queue_.top();
    queue_.pop();
    return f;
}


/* ===== MAIN FUNCTION ===== */

int main()
{
    EventQueue q;
    float val;
     
    while(cin >> val)
    {
        if(val < 0)
            break;
        q.insert(val);
    }
    
    while ((val = q.next()) >= 0)
        cout << "Extracted " << val << endl;
 
    return 0;
}

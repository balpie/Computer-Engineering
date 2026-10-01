 
#include <iostream>
#include <vector>

using namespace std;


/* ===== EVENTQUEUE CLASS ===== */

class EventQueue {
    
    std::vector<float> queue_;
    
public:
    EventQueue() {}
    ~EventQueue() {}
    
    void insert(const float& f);
    float next();
};

void EventQueue::insert(const float& f)
{
    queue_.push_back(f);
}

float EventQueue::next()
{
    if (queue_.empty())
        return -1;

    std::vector<float>::iterator min_it = queue_.begin();
    float min = (*min_it);

    std::vector<float>::iterator it; 
    for (it = queue_.begin(); it != queue_.end(); ++it)
    {
        if ((*it) < min)
        {
            min = (*it);
            min_it = it;
        }
    }
    
    queue_.erase(min_it);

    return min;
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

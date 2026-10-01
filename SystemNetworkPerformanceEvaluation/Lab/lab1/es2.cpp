#include <iostream>
#include <queue>

using namespace std;

struct Comp{
    bool operator()(float a, float b)
    {
        if(a > b)
            return true;
        else
            return false;
    }
};

class EventQueue{
    private:
        priority_queue<float, vector<float>,Comp> _queue;
    public:
        void print_q();
        void insert(float num);
        float next();
};

void EventQueue::insert(float num)
{
    _queue.push(num);
}

float EventQueue::next()
{
    if(_queue.empty())
    {
        return -1;
    }
    float num = _queue.top();
    _queue.pop();
    return num;
}

int main()
{
    EventQueue q;
    float n;
    do {
        cout<<"Insert number: ";
        cin>>n;
        if(n < 0) {
            break;
        }
        q.insert(n);
    } while(n > 0.0f);

    // q.print_q();
    float curr;
    do{
        curr = q.next();
        if(curr < 0)
        {
            break;
        }
        cout<<curr<<endl;
    } while(curr > 0);
    
    return 0;
}

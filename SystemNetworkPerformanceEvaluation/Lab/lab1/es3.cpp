#include <iostream>
#include <vector>
#include <list>
#define M 1000
#define DELTA 10

using namespace std;

class EventQueue{
    private:
        vector<list<float>> _queue;
    public:
        EventQueue();
        void insert(float num);
        float next();
};

EventQueue::EventQueue()
{
    cout<<"CONSTRUCTOR"<<endl;
    _queue.resize(M);
}

void EventQueue::insert(float num)
{
    cout<<"INSERT 1"<<endl;
    int pos = ((int)num / DELTA) % M;
    vector<list<float>>::iterator iter_v = _queue.begin() + pos;
    cout<<"INSERT 2, posizione: "<<pos<<endl;
    if(iter_v->empty())
    {

        cout<<"INSERT 3"<<endl;
        iter_v->push_front(num);
        return;
    }
    list<float>::iterator iter;
    for (iter = iter_v->begin(); iter != iter_v->end(); ++iter) {
        if (*iter > num){
            cout<<"INSERT 4"<<endl;
            iter_v->insert(iter, num);
            return;
        }
    }
    iter_v->push_back(num);
}

float EventQueue::next()
{
    vector<list<float>>::iterator iter = _queue.begin();
    for(; iter != _queue.end(); ++iter)
    {
        if(!iter->empty())
        {
            float retv = iter->front();
            iter->pop_front();
            return retv;
        }
    }
    return -1;
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

    // q.print_v();
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

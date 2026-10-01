#include <iostream>
#include <vector>

using namespace std;

/*
EventQueue includes an unordered array of real numbers and supports the following operations:
• insert(n) inserts the number given as argument at the end of the array
• next() returns the number with lowest value and removes it from the array. If the array is empty, the
function returns -1
*/

class EventQueue{
    private:
        vector<float> _queue;
    public:
        void print_v();
        void insert(float num);
        float next();
};

void EventQueue::print_v()
{
    cout<<"printing vector"<<endl;
    vector<float>::iterator iter;
    for(iter = this->_queue.begin(); iter < this->_queue.end(); ++iter)
    {
        cout<<(*iter)<<endl;
    }
}

void EventQueue::insert(float num)
{
    this->_queue.push_back(num);
}

float EventQueue::next()
{
    if(this->_queue.end() == this->_queue.begin())
    {
        return -1;
    }
    vector<float>::iterator iter;
    vector<float>::iterator min_num = this->_queue.begin();
    for(iter = this->_queue.begin(); iter < this->_queue.end(); ++iter)
    {
        if ((*iter) < (*min_num)) 
        {
            min_num = iter;
        }
    }

    float min = *min_num;
    this->_queue.erase(min_num);
    return min;
}
/*
Write a main function that:
• Instantiates one object of type EventQueue, call it q
• Reads real numbers from the keyboard, until the user types a negative number. All the numbers read must
be inserted into q by calling the insert() function
• By using the next() function, extracts and prints out in ascending order all the numbers in q
*/

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

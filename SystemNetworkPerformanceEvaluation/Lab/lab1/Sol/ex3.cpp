#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

using namespace std;


/* ===== EVENTQUEUE CLASS ===== */

class EventQueue {

    const unsigned int M = 1000;
    const float D = 10.0;

    vector<list<float> > queue_;  // vector of buckets, each bucket is a list of events

    unsigned int current_bucket_; // index of the current bucket  
    unsigned int current_year_;   // index of the current calendar year
    unsigned int size_;           // count the number of events in the queue

public:
    EventQueue()
    {
        queue_.resize(M);
        current_bucket_ = 0;
        current_year_ = 1;
        size_ = 0;
    }
    ~EventQueue() {}

    void insert(const float& f);
    float next();
};

void EventQueue::insert(const float& f)
{
    unsigned int slot = (unsigned int)floor(f / D) % M;
    list<float>& bucket = queue_[slot];

    // ensure that the bucket is sorted by firing time f
    list<float>::iterator position = lower_bound(bucket.begin(), bucket.end(), f);
    bucket.insert(position, f);
    ++size_;
}

float EventQueue::next()
{
    if (size_ == 0)
        return -1;

    while (true)
    {
        list<float>& bucket = queue_[current_bucket_];
        unsigned int end_of_year = current_year_ * M * D;

        // the bucket can contain events from different calendar years
        if (!bucket.empty() && bucket.front() < end_of_year)
        {
            float f = bucket.front();
            bucket.pop_front();
            --size_;
            return f;
        }

        ++current_bucket_;
        if (current_bucket_ == M)
        {
            current_bucket_ = 0;
            ++current_year_;
        }
    }
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

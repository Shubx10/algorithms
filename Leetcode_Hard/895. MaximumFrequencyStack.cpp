class FreqStack {
    unordered_map<int, stack<int>> freqToEle;
    unordered_map<int, int> eleToFreq;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        eleToFreq[val]++;
        int currFreq = eleToFreq[val];
        freqToEle[currFreq].push(val);
        maxFreq = max(maxFreq, currFreq);
    }
    
    int pop() {
        int ele = freqToEle[maxFreq].top();
        freqToEle[maxFreq].pop();
        if(freqToEle[maxFreq].empty()) maxFreq--;
        eleToFreq[ele]--;
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

// A TrainComposition is built by attaching and detaching wagons from the left and the right sides.
// For example, if we start by attaching wagon 7 from the left followed by attaching wagon 13, 
// again from the left, we get a composition of two wagons (13 and 7 from left to right). 
// Now the first wagon that can be detached from the right is 7 and the first that can be detached from the left is 13.
// Implement a TrainComposition that models this problem.
// https://www.testdome.com/questions/cpp/train-composition/18036?visibility=1

#include <stdexcept>
#include <iostream>
#include <deque>

class TrainComposition
{
private:
    
    std::deque<int> train;
    
public:
    
    void attachWagonFromLeft(int wagonId)
    {
        //throw std::logic_error("Waiting to be implemented");
        train.push_front(wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        //throw std::logic_error("Waiting to be implemented");
        train.push_back(wagonId);
        
    }

    int detachWagonFromLeft()
    {
        //throw std::logic_error("Waiting to be implemented");
        int result = train.front();
        train.pop_front();
        return result;
        
    }

    int detachWagonFromRight()
    {
        //throw std::logic_error("Waiting to be implemented");
        int result = train.back();
        train.pop_back();
        return result;        
    }    
};

#ifndef RunTests
int main()
{
    TrainComposition tree;
    tree.attachWagonFromLeft(7);
    tree.attachWagonFromLeft(13);
    std::cout << tree.detachWagonFromRight() << "\n"; // 7 
    std::cout << tree.detachWagonFromLeft(); // 13
}
#endif
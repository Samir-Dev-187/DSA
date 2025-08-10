#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
        int canCompleateCircuit(vector<int>& gas, vector<int>& cost)
        {
            int totGas = 0, totCost = 0;

            //unique solution always exists
            int start=0, currGas=0;

            for(int i=0; i<gas.size(); ++i)
            {
                totGas += gas[i];
                totCost += cost[i];

                currGas += (gas[i] - cost[i]);

                if(currGas < 0)
                {
                    start = i+1;
                    currGas = 0;
                }
            }

            return totGas < totCost ? -1 : start;
        }
};

int main()
{
    Solution s1;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << s1.canCompleateCircuit(gas, cost);
    cout << endl;
    
    return 0;
}
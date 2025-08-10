#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    // map<string, int> m;
    // m["tv"] = 100;
    // m["laptop"] = 50;
    // m["headphones"] = 20;
    // m["tablet"] = 120;
    // m["watch"] = 30;

    // m.insert({"camera", 25});
    // m.erase("tv");

    // for(auto p : m)
    // {
    //     cout << p.first << " " <<p.second << endl;
    // }
    // cout << endl;

    // cout << m["laptop"] << endl;

    // if(m.find("camera") != m.end())
    // {
    //     cout << "found";
    // }
    // else{
    //     cout << "not found";
    // }


    multimap<string, int> m2;
    m2.emplace("tv",100);      
    m2.emplace("laptop",50);
    m2.emplace("watch",10);
    m2.emplace("tablet",75);
    m2.emplace("tv",150);      
    m2.emplace("smartphone",50);
    
    m2.erase("tv");

    for(auto p : m2)
    {
        cout << p.first << " " <<p.second << endl;
    }
    cout << endl;
    

    unordered_map<string, int> m3;
    m3.emplace("tv",100);      
    m3.emplace("laptop",50);
    m3.emplace("watch",10);
    m3.emplace("tablet",75);    
    m3.emplace("smartphone",50);
    
    for(auto p : m3)
    {
        cout << p.first << " " <<p.second << endl;
    }
    cout << endl;
    return 0;
}
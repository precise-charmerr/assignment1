#include <iostream>
#include <fstream>
#include <set>
#include <deque>
#include<unordered_map>
#include<unordered_set>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

// More details in the github repo: https://github.com/nlohmann/json
// ifstream f("example.json"); --> Read JSON from a file
// ofstream f("example.json"); --> output data in JSON file

int main() {

    // c++  STL containers serialization
    vector<int> c_vector{ 1, 2, 3, 4 };
    json j_vec(c_vector); // [1, 2, 3, 4]
    cout << j_vec << endl;

    deque<double> c_deque{ 1.2, 2.3, 3.4, 5.6 };
    json j_deque(c_deque); // [1.2, 2.3, 3.4, 5.6]
    cout << j_deque << endl;

    list<bool> c_list{ true, true, false, true };
    json j_list(c_list);// [true, true, false, true]
    cout << j_list << endl;


    forward_list<int64_t> c_flist{ 12345678909876, 23456789098765, 34567890987654, 45678909876543 };
    json j_flist(c_flist);// [12345678909876, 23456789098765, 34567890987654, 45678909876543]
    cout << j_flist << endl;

    array<unsigned long, 4> c_array{ {1, 2, 3, 4} };
    json j_array(c_array);// [1, 2, 3, 4]
    cout << j_array << endl;

    set<string> c_set{ "one", "two", "three", "four", "one" };
    json j_set(c_set); // only one entry for "one" is used ["four", "one", "three", "two"]
    cout << j_set << endl;

    unordered_set<string> c_uset{ "one", "two", "three", "four", "one" };
    json j_uset(c_uset); // only one entry for "one" is used, maybe ["two", "three", "four", "one"]
    cout << j_uset << endl;

    multiset<string> c_mset{ "one", "two", "one", "four" };
    json j_mset(c_mset); // both entries for "one" are used, maybe ["one", "two", "one", "four"]
    cout << j_mset << endl;

    unordered_multiset<string> c_umset{ "one", "two", "one", "four" };
    json j_umset(c_umset); // both entries for "one" are used, maybe ["one", "two", "one", "four"]
    cout << j_umset << endl;

    // -----------------------------------------------------------------------------------------------------

    

    // serialization to a file

    json employee = {
        {"name", "sonoo"},
        {"salary", 56000},
        {"married", true}
    };


    // Get a string representation of a JSON value (serialize)
    string s = employee.dump();
    cout << s << endl;

    // write prettified JSON to another file
    ofstream o("output.json");
    o << setw(4) << s << endl;


    // -----------------------------------------------------------------------------------------------------

    // Deserialization from a file

    // read a JSON file

    // read a JSON file
    ifstream i("output.json");
    json j;
    i >> j;

    // write prettified JSON to console
    cout << setw(4) << j << endl;


    // create object from string literal
    json j1 = "{ \"color\": \"red\", \"value\": \"#f00\" }"_json;
    auto j2 = R"({"color": "green","value": "#0f0"})"_json;

    cout << "j1 object: " << j1 << endl;
    cout << "j2 object: " << j2 << endl;

    return 0;
}
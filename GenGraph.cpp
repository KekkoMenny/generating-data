//
// Created by s5133263 on 25/09/2019.
//

#include <iostream>
#include <string.h>
#include<stdio.h>
#include <bits/stdc++.h>
#include <unordered_map>
#include <limits>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

    int r =0; //starting at row 0
    string vertx;
    
    getline(cin, vertx);

    int n = stoi(vertx),
        NodeCount = n,
        Parent[NodeCount],
        nodCost[NodeCount],
        corrent = 0,
        Source = 0,
        Target = 7;


    vector<vector<int>> nodeCost(n);

    string data;

    getline(cin, data);
    r++;

    while (!data.empty()) {

        size_t position = 0;
        string token;
        string delimiter = " ";
        vector<string> str_data;
        while ((position = data.find(delimiter)) != string::npos) {
            token = data.substr(0, position);
            str_data.push_back(token);
            data.erase(0, position + delimiter.length());
        }

        //insert the last token
        token = data.substr(0, position);
        str_data.push_back(token);

        nodeCost[r-1] = vector<int>(n);
        for(int i = 0; i < n; i++) {
            nodeCost[r-1][i] = stoi(str_data[i]);
        }

        getline(cin, data);
        r++;
    }

    //parent is null
    for(int i = 0; i < n; i++){
        Parent[i]= -1;
    }
    // cost is infinity
    for(int i = 0; i < n; i++){
        nodCost[i]= numeric_limits<int>::max();;
    }

    //Clock start
    clock_t clockStart = clock();


    // Iterative version:
    string arg1 = argv[1];

    if (argc == 2 && arg1 == "queue") {
        queue<int> s;
        s.empty();
        s.push(Source);

        nodCost[Source] = 0;


        while(!s.empty()){
            corrent = s.front();
            s.pop();

            if(corrent != Target){

                for(int neig = nodeCost.size()-1; neig >= 0; neig--){
                    if(nodeCost[corrent][neig] != 0) {
                        if (nodCost[neig] > nodCost[corrent] + nodeCost[corrent][neig]) {
                            nodCost[neig] = nodCost[corrent] + nodeCost[corrent][neig];

                            Parent[neig] = corrent;
                            s.push(neig);
                        }
                    }
                }
            }

        }
        //end time
        clock_t end = clock();

        int t = Target;

        cout << "Minimum dist: " << Source << " -> ";


        while(Parent[t] != Source){
            cout << Parent[t] << " -> ";
            t = Parent[t];
        }

        cout << Target << endl;
        cout << endl;

        //print the cost
        cout << "Cost of route= ";
        cout << nodCost[Target] << endl;
        cout << endl;

        long int time_difference = (end - clockStart) / CLOCKS_PER_SEC;
        cout << "Time= ";
        cout << time_difference << endl;

    }
    else if (argc == 2 && arg1 == "stack") {
        stack<int> s;
        s.empty();
        s.push(Source);

        nodCost[Source] = 0;


        while(!s.empty()){
            if (argc == 2 && arg1 == "stack" || arg1 == "priority") {
                corrent = s.top(); // stack & priority
            }

            s.pop();

            if(corrent != Target){

                for(int neig = nodeCost.size()-1; neig >= 0; neig--){
                    if(nodeCost[corrent][neig] != 0) {
                        if (nodCost[neig] > nodCost[corrent] + nodeCost[corrent][neig]) {
                            nodCost[neig] = nodCost[corrent] + nodeCost[corrent][neig];

                            Parent[neig] = corrent;
                            s.push(neig);
                        }
                    }
                }
            }

        }
        //end time
        clock_t end = clock();

        int t = Target;

        cout << "Minimum dist: " << Source << " -> ";


        while(Parent[t] != Source){
            cout << Parent[t] << " -> ";
            t = Parent[t];
        }

        cout << Target << endl;
        cout << endl;

        //print the cost
        cout << "Cost of route= ";
        cout << nodCost[Target] << endl;
        cout << endl;

        long int time_difference = (end - clockStart) / CLOCKS_PER_SEC;
        cout << "Time= ";
        cout << time_difference << endl;

    }
    else if (argc == 2 && arg1 == "priority") {
        priority_queue<int> s;
        s.empty();
        s.push(Source);

        nodCost[Source] = 0;


        while(!s.empty()){
            if (argc == 2 && arg1 == "stack" || arg1 == "priority") {
                corrent = s.top(); // stack & priority
            }

            s.pop();

            if(corrent != Target){

                for(int neig = nodeCost.size()-1; neig >= 0; neig--){
                    if(nodeCost[corrent][neig] != 0) {
                        if (nodCost[neig] > nodCost[corrent] + nodeCost[corrent][neig]) {
                            nodCost[neig] = nodCost[corrent] + nodeCost[corrent][neig];

                            Parent[neig] = corrent;
                            s.push(neig);
                        }
                    }
                }
            }

        }
        //end time
        clock_t end = clock();

        int t = Target;

        cout << "Minimum dist: " << Source << " -> ";


        while(Parent[t] != Source){
            cout << Parent[t] << " -> ";
            t = Parent[t];
        }

        cout << Target << endl;
        cout << endl;

        //print the cost
        cout << "Cost of route= ";
        cout << nodCost[Target] << endl;
        cout << endl;

        long int time_difference = (end - clockStart) / CLOCKS_PER_SEC;
        cout << "Time= ";
        cout << time_difference << endl;

    }
    else {
        cout << "Input proper iterative version" << endl;

    }

    cout << "Map:" << endl;

    for(int i = 0; i < nodeCost.size(); i++){
        for(int j = 0; j < nodeCost[i].size(); j++) {
            cout << nodeCost[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;




    return 0;

}
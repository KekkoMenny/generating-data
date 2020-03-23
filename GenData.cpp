/*
// Created by s5133263 on 24/09/2019.
*/

#include <iostream>
#include <string>
#include <string.h>
#include<stdio.h>
#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;

//Comparing the index of the ID
template <typename T>
class compareId
{
public:
    //Default Const.
    compareId(T* IDCompare) : c(IDCompare) {}

    //Functor
    bool operator()(int const& l, int const& r) ;

private:
    T* c;
};

template <typename T>
bool compareId<T>::operator()(int const& l, int const& r){
    return c[l] < c[r];
}

//sorting by index without sorting by data
void displaySorted(int multimapSize, string *studentName, int *indexName, unordered_multimap<string, vector<int>> multiMap) {

    for    (int i = 0; i < multimapSize; i++) {
        unordered_multimap<string, vector<int>>::iterator itrts;

        itrts = multiMap.find(studentName[indexName[i]] );

        //Check if the name appears until the end of multiMap, update
        if(itrts != multiMap.end()) {
            vector<int> item_mark = itrts->second;

            cout << studentName[indexName[i]] << endl;

            cout << "Physics Mark= " << item_mark[0] << endl;
            cout << "Maths Mark= " << item_mark[1] << endl;
            cout << "Chemistry Mark= " << item_mark[2] << endl;
            cout << "Biology Mark= " << item_mark[3] << endl;
            cout << "Total Mark= " << item_mark[4] << endl;
            cout << endl;
        }
    }
}


int main(int argc, char* argv[]) {

    /*
     *
     * Multiple same names with different subjects, assume one student has all 4 subjects, therefore use unordered multimap
     * as itrt is able to store multiple duplicate equal keys. Also, because itrt is asked not to order the array, its left unordered
     * by the unordered_multimap.
     * The key is not ordered, therefore when sorting, the function 'displaySorted' sorts by index.
    */

    unordered_multimap<string, vector<int> > multiMap;

    string data;

    // get each line from the provided gendata, use: gendata_lec | GenData
    getline(cin, data);




    while (!data.empty()) {
        size_t position = 0;
        string token;
        string delimiter = " ";
        vector<string> str_data;//str_data can be the name, the mark for a subject etc.

        //split the lines once it finds a space(Francesco Biology Mark=10 ->
        //                                                Francesco
                                                        //Biology Mark=10
        while ((position = data.find(delimiter)) != string::npos) {
            token = data.substr(0, position);
            str_data.push_back(token);
            data.erase(0, position + delimiter.length());
        }

        //insert the last token
        token = data.substr(0, position);
        str_data.push_back(token);

        unordered_multimap<string, vector<int>>::iterator itrts;
        itrts = multiMap.find(str_data[0]);

        //Checking if the person already exists, pushing the newMark for its subject
        if (itrts != multiMap.end()) { //itrts = the iterator of the person that already exists
            vector<int> oldMark = itrts->second; //oldMark = initial mark before it's updated
            vector<int> newMark;

            if (str_data[1] == "Physics") {
                newMark.push_back(stoi(str_data[2]));
                newMark.push_back(oldMark[1]);
                newMark.push_back(oldMark[2]);
                newMark.push_back(oldMark[3]);
                newMark.push_back(oldMark[4]);

                itrts->second = newMark;
            } else if (str_data[1] == "Mathematics") {
                newMark.push_back(oldMark[0]);
                newMark.push_back(stoi(str_data[2]));
                newMark.push_back(oldMark[2]);
                newMark.push_back(oldMark[3]);
                newMark.push_back(oldMark[4]);

                itrts->second = newMark;
            } else if (str_data[1] == "Chemistry") {
                newMark.push_back(oldMark[0]);
                newMark.push_back(oldMark[1]);
                newMark.push_back(stoi(str_data[2]));
                newMark.push_back(oldMark[3]);
                newMark.push_back(oldMark[4]);

                itrts->second = newMark;
            } else if (str_data[1] == "Biology") {
                newMark.push_back(oldMark[0]);
                newMark.push_back(oldMark[1]);
                newMark.push_back(oldMark[2]);
                newMark.push_back(stoi(str_data[2]));
                newMark.push_back(oldMark[4]);

                itrts->second = newMark;
            }
        }
            // if the person does not exist, add it
        else {
            vector<int> myvector;
            if (str_data[1] == "Physics") { // appending the marks at the end of the vector
                myvector.push_back(stoi(str_data[2]));
                myvector.push_back(0);
                myvector.push_back(0);
                myvector.push_back(0);
                myvector.push_back(0);

                multiMap.insert({str_data[0], myvector});
            } else if (str_data[1] == "Mathematics") {
                myvector.push_back(0);
                myvector.push_back(stoi(str_data[2]));
                myvector.push_back(0);
                myvector.push_back(0);
                myvector.push_back(0);

                multiMap.insert({str_data[0], myvector});
            } else if (str_data[1] == "Chemistry") {
                myvector.push_back(0);
                myvector.push_back(0);
                myvector.push_back(stoi(str_data[2]));
                myvector.push_back(0);
                myvector.push_back(0);

                multiMap.insert({str_data[0], myvector});
            } else if (str_data[1] == "Biology") {
                myvector.push_back(0);
                myvector.push_back(0);
                myvector.push_back(0);
                myvector.push_back(stoi(str_data[2]));
                myvector.push_back(0);

                multiMap.insert({str_data[0], myvector});
            }
        }
        getline(cin, data);
    }

    //calculating the total mark
    unordered_multimap<string, vector<int>>::iterator itrt;
    for (itrt = multiMap.begin(); itrt != multiMap.end(); itrt++) {
        vector<int> oldMark = itrt->second;
        int totalMark;
        totalMark = int((oldMark[0] + oldMark[1] + oldMark[2] + oldMark[3]));
        oldMark[4] = totalMark;
        itrt->second = oldMark;
    }

    // sorting by the index, using the functor class 'compareId'
    int size = multiMap.size();
    int counter = 0;
    int *index = new int[size]; //initialize object


    for (int i = 0; i < size; i++) {
        index[i] = i;
    }

    //array ordering by name.
    string *studentName = new string[size];

    //sort by index, by the student name
    for (unordered_multimap<string, vector<int>>::const_iterator i = multiMap.begin();
         i != multiMap.end(); ++i) {
        studentName[counter] = i->first;
        sort(index + 0, index + size, compareId<string>(studentName));
        counter++;
    }


    string arg1 = argv[1];


        if (argc == 2 && arg1 == "student"){



            //print the names in order
            cout << "order by Name:" << endl;

            displaySorted(size, studentName, index, multiMap);


        }

        else if (argc == 2 && arg1 == "mark"){

            //ordering by total mark
            int *index2 = new int[size];
            counter = 0;

            for (int i = 0; i < size; i++) {
                index2[i] = i;
            }

            int *tot = new int[size];

            for (unordered_multimap<string, vector<int>>::const_iterator i = multiMap.begin();
                 i != multiMap.end(); ++i) {
                tot[counter] = i->second[4];
                sort(index + 0, index + size, compareId<int>(tot));
                counter++;
            }


            cout << "Order by total:" << endl;

            displaySorted(size, studentName, index, multiMap);

            delete[] tot;

        }

        delete[] studentName;

    return 0;
}
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TravelPreference{
    int province; //จังหวัด
    int num_place; //จำนวนที่เที่ยว
    int budget = 0; //งบ
    int days; // จน.วันที่ไป
    int people; // จน.คนที่ไป

    bool hascar; // มีรถบ่
    int tripStyle; //ชอบเที่ยวแบบไหนหงะ


};



struct Meal {
    int category;// 1=Noodles, 2=Rice, 3=Surprise me
    string result;// ชื่ออาหารที่สุ่มได้
};

struct Person {
    int meals;// กี่มื้อ
    vector<Meal> mealList;// เก็บทุกมื้อของคนนี้
};

struct Restaurant {
    int customer;// กี่คน
    int budget_food;// งบต่อคน
    vector<Person> peopleList;// เก็บทุกคน
};



TravelPreference getUserInput_1(); //Feature [1]
Restaurant getUserInput_2(); //Feature [2]

//help for validation
int getValid_Integer(const string &prompt);
bool getYes_No_Input(const string &prompt);
string getString_Input(const string &prompt);

//Show UI
void displayBanner();
void clearInputBuffer();

//Error try
void Error();

//check is number
bool Check_number(const string & str);

//Trip style
string Trip();

void select_mode();

void line(); //เส้นกั้น

void show_pv();
void show_place();

#endif
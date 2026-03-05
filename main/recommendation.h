#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;



//กรอง จังหวัด
vector<place> Screening_provice(vector<place> &, int );

//แนะนำสถานที่
vector<place> Recommendation_place(vector<place> &, int );

//โชว์สถานที่
void Show_Place(vector<place> &);
#endif
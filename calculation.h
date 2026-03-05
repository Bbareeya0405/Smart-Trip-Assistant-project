#ifndef CALCULATION_H
#define CALCULATION_H

#include <vector>
#include "recommendation.h"

using namespace std;

// รวมค่าสถานที่
int calculatePlaceCost(vector<Place> places);

// รวมค่าอาหาร
int calculateRestaurantCost(vector<restaurant> foods);

// ค่าใช้จ่ายรวมทั้งหมด
int calculateTotalCost(vector<Place> places, vector<restaurant> foods);

// ค่าใช้จ่ายต่อคน
double calculateCostPerPerson(int totalCost, int people);

// ค่าใช้จ่ายต่อวัน
double calculateCostPerDay(int totalCost, int days);

// เช็คงบประมาณ
bool isWithinBudget(int totalCost, int budget);

// งบคงเหลือ
int calculateRemainingBudget(int budget, int totalCost);

#endif

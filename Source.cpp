#include <iostream>
#include <cmath>

using namespace std;

int check_Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {

	int same_points = 0;
	if (x1 == x2 and y1 == y2) same_points++;
	if (x1 == x3 and y1 == y3) same_points++;
	if (x2 == x3 and y2 == y3) same_points++;

	return same_points;

}

int main() {

	float x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int checker = check_Triangle(x1, y1, x2, y2, x3, y3);
	if (checker == 3) {
		cout << "Error. This is a point.";
		return 0;
	}
	if (checker == 1) {
		cout << "Error. This is a segment.";
		return 0;
	}
	float side_1 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	side_1 = sqrt(side_1);
	float side_2 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
	side_2 = sqrt(side_2);
	float side_3 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
	side_3 = sqrt(side_3);
	float half_per = (side_1 + side_2 + side_3) / 2;
	float area = half_per * (half_per - side_1) * (half_per - side_2) * (half_per - side_3);
	if (area < 0) {
		cout << "Triangle doesn't exist.";
		return 0;
	}
	if (area == 0) {
		cout << "Error. Points are collinear.";
		return 0;
	}
	area = sqrt(area);
	cout << "Triangle area is " << area;

	return 0;
}
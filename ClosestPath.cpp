//Program to find the pair of point with the smallest distance between them
#include <iostream>
#include <math.h>

int findDistance(int x1, int x2, int y1, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void readPoints(int arr[][2], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

void findMin(int arr[][2], int n)
{
	int distance_Now = 0, distance_Min = 0, point1_x, point1_y, point2_x, point2_y;
	point1_x = arr[0][0];
	point1_y = arr[0][1];
	point2_x = arr[1][0];
	point2_y = arr[1][1];
	distance_Min = findDistance(arr[0][0], arr[0][1], arr[1][0], arr[1][1]);

	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			distance_Now = findDistance(arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
			if(distance_Now < distance_Min)
			{
				distance_Min = distance_Now;
				point1_x = arr[i][0];
				point1_y = arr[i][1];
				point2_x = arr[j][0];
				point2_y = arr[j][1];
			}
		}
	}

	std::cout << "(" << point1_x << "," << point1_y << ") and (" << point2_x << "," << point2_y << ")" << std::endl;
}

int main()
{
	int n;
	std::cout << "Enter the number of points: ";
	std::cin >> n;

	int points[n][2];

	std::cout << "Enter the points with the cordinates: " << std::endl;
	readPoints(points, n);

	std::cout << "Finding the pair of points" << std::endl;
	findMin(points, n);

	return 0;
}
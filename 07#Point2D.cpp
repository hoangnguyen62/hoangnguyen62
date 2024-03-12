#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x, y;
};

void swap(Point &a, Point &b)
{
    Point tmp = a;
    a = b;
    b = tmp;
}

void input(vector<Point> &p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
}

int partition_x(vector<Point> &p, int left, int right)
{
    Point ptend = p[right];
    int index = left - 1;
    
    for (int i = left; i < right; i++)
    {
        if (p[i].x <= ptend.x)
        {
            index++;
            swap(p[index], p[i]);
        }
    }
    swap(p[index + 1], p[right]);
    return (index + 1);
}

int partition_y(vector<Point> &p, int left, int right)
{
    Point ptend = p[right];
    int index = left - 1;
    
    for (int i = left; i < right; i++)
    {
        if (p[i].y >= ptend.y)
        {
            index++;
            swap(p[index], p[i]);
        }
    }
    swap(p[index + 1], p[right]);
    return (index + 1);
}

void quickSort_x(vector<Point> &p, int  left, int right)
{
    if (left < right)
    {
        int i = partition_x(p, left, right);

        quickSort_x(p, left, i - 1);
        quickSort_x(p, i + 1, right);
    }
}

void quickSort_y(vector<Point> &p, int  left, int right)
{
    if (left < right)
    {
        int i = partition_y(p, left, right);

        quickSort_y(p, left, i - 1);
        quickSort_y(p, i + 1, right);
    }
}
void xy_coordinateArray(vector<Point> &p, int n)
{
    quickSort_x(p, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        int vt;
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].x != p[i].x)
            {
                vt = j;
                i = j - 1;
                break;
            }
        }
        quickSort_y(p, i, vt);
    }
}

void output(vector<Point> p, int n)
{
    for (int i = 0; i < n; i++)
        cout << p[i].x << " " << p[i].y << endl;
}
int main()
{
    int n; cin >> n;
    vector<Point> p(n);
    input(p, n);
    xy_coordinateArray(p, n);
    output(p, n);
    return 0;
}
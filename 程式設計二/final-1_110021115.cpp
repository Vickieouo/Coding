#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <exception>

using namespace std;

class Geometry_ND;

class Point_ND
{
private:
    vector<double> m_coords;
    unsigned m_dim;
    friend class Geometry_ND;

public:
    // Constructor, initializes dimension and coordinates
    Point_ND(const unsigned &arg_dim = 2) : m_dim(arg_dim), m_coords(arg_dim) {}
    // Copy constructor
    Point_ND(const Point_ND &arg_point) : m_dim(arg_point.m_dim), m_coords(arg_point.m_coords) {}
    // assignment operator
    Point_ND &operator=(const Point_ND &arg_point)
    {
        m_dim = arg_point.m_dim;
        while (m_coords.size() != 0)
        {
            m_coords.pop_back();
        }
        for (int i = 0; i < arg_point.m_coords.size(); i++)
        {
            m_coords.push_back(arg_point.m_coords[i]);
        }
        return *this;
    }
    // get coordinates
    vector<double> get_coords() const;
    // get dimension
    unsigned get_dim() const;
    // set coordinates
    void set_coords(const vector<double> &arg_coords);
    // cout `<<` operator for print Point_ND number
    friend ostream &operator<<(ostream &arg_os, const Point_ND &arg_point)
    {
        for (int i = 0; i < arg_point.m_coords.size() - 1; i++)
        {
            arg_os << arg_point.m_coords[i] << ",";
        }
        arg_os << arg_point.m_coords[arg_point.m_coords.size() - 1];

        return arg_os;
    }
    // cin `>>` operator for input Point_ND number
    friend istream &operator>>(istream &arg_is, Point_ND &arg_point)
    {
        string str, str1;
        getline(arg_is, str);
        stringstream ss(str), ss1;
        while (arg_point.m_coords.size() != 0)
        {
            arg_point.m_coords.pop_back();
        }
        while (getline(ss, str1, ','))
        {
            ss1 << str1;
            double n;
            ss1 >> n;
            ss1.clear();
            arg_point.m_coords.push_back(n);
        }
        return arg_is;
    }
    // friend class
    friend class Geometry_ND;
};

class Geometry_ND
{
protected:
    // data members
    vector<Point_ND> m_point_array;
    unsigned m_dim;

public:
    // Constructor, initializes the array
    Geometry_ND(const unsigned &arg_dim = 2,
                const unsigned int &arg_num_of_vertex = 0) : m_dim(arg_dim), m_point_array(arg_num_of_vertex) {}
    // Copy constructor
    Geometry_ND(const Geometry_ND &arg_geometry) : m_dim(arg_geometry.m_dim), m_point_array(arg_geometry.m_point_array) {}
    // assignment operator
    Geometry_ND &operator=(const Geometry_ND &arg_geometry);
    // print the geometry
    virtual void print_geometry() {}
    // parse the cin to the geometry
    virtual void parse_geometry(istream &arg_is) {}
    // set the geometry
    void set_geometry(const vector<Point_ND> &arg_point_array)
    {
        m_point_array = arg_point_array;
    }
    // get the geometry array
    vector<Point_ND> get_geometry_array();
};

class Triangle_ND : public Geometry_ND
{
public:
    // Constructor, initializes the array
    Triangle_ND(const unsigned &arg_dim = 2) : Geometry_ND(arg_dim) {}
    // Copy constructor
    Triangle_ND(const Triangle_ND &arg_triangle) : Geometry_ND(arg_triangle) {}
    // assignment operator
    Triangle_ND &operator=(const Triangle_ND &arg_triangle);
    // print the geometry
    void print_geometry()
    {
        cout << "t" << endl;
        cout << m_point_array.size() << endl;
        for (int i = 0; i < m_point_array.size(); i++)
        {
            cout << m_point_array[i] << endl;
        }
    }
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is)
    {
        string temp;
        getline(arg_is, temp);
        stringstream ss(temp);
        unsigned int vertex_num;
        ss >> vertex_num;

        for (int i = 0; i < vertex_num; i++)
        {
            getline(arg_is, temp);
            stringstream ss(temp);
            Point_ND p;
            ss >> p;
            m_point_array.push_back(p);
        }
    }
};
const unsigned triangle_num_of_vertex = 3;

class Polygon_ND : public Geometry_ND
{
public:
    // Constructor, initializes the array
    Polygon_ND(const unsigned &arg_dim = 2) : Geometry_ND(arg_dim) {}
    // Copy constructor
    Polygon_ND(const Polygon_ND &arg_polygon) : Geometry_ND(arg_polygon) {}
    // assignment operator
    Polygon_ND &operator=(const Polygon_ND &arg_polygon);
    // print the geometry
    void print_geometry()
    {
        cout << "p" << endl;
        cout << m_point_array.size() << endl;
        for (int i = 0; i < m_point_array.size(); i++)
        {
            cout << m_point_array[i] << endl;
        }
    }
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is)
    {
        string temp;
        getline(arg_is, temp);
        stringstream ss(temp);
        unsigned int vertex_num;
        ss >> vertex_num;

        for (int i = 0; i < vertex_num; i++)
        {
            getline(arg_is, temp);
            stringstream ss(temp);
            Point_ND p;
            ss >> p;
            m_point_array.push_back(p);
        }
    }
};

class Line_ND : public Geometry_ND
{
public:
    // Constructor, initializes the array
    Line_ND(const unsigned &arg_dim = 2) : Geometry_ND(arg_dim) {}
    // Copy constructor
    Line_ND(const Line_ND &arg_line) : Geometry_ND(arg_line) {}
    // assignment operator
    Line_ND &operator=(const Line_ND &arg_line);
    // print the geometry
    void print_geometry()
    {
        cout << "l" << endl;
        cout << m_point_array.size() << endl;
        for (int i = 0; i < m_point_array.size(); i++)
        {
            cout << m_point_array[i] << endl;
        }
    }
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is)
    {
        string temp;
        getline(arg_is, temp);
        stringstream ss(temp);
        unsigned int vertex_num;
        ss >> vertex_num;

        for (int i = 0; i < vertex_num; i++)
        {
            getline(arg_is, temp);
            stringstream ss(temp);
            Point_ND p;
            ss >> p;
            m_point_array.push_back(p);
        }
    }
};
const unsigned line_num_of_vertex = 2;

int main()
{
    vector<Geometry_ND *> geo_ptr_array;
    string input;
    unsigned dim;
    Geometry_ND *geo_ptr;
    // read dimension
    cin >> dim;
    // read geometry
    while (getline(cin, input))
    {
        // check the geometry type
        switch (input[0])
        {
        case 't':
            geo_ptr = new Triangle_ND(dim);
            break;
        case 'p':
            geo_ptr = new Polygon_ND(dim);
            break;
        case 'l':
            geo_ptr = new Line_ND(dim);
            break;
        }
        if (input == "t" || input == "p" || input == "l")
        {
            // parse the cin to the geometry
            geo_ptr->parse_geometry(cin);
            // push the pointer to the array
            geo_ptr_array.push_back(geo_ptr);
        }
    }
    // print the geometry
    // first, print the dimension
    cout << dim << endl;
    // second, print the geometry
    for (int i = 0; i < geo_ptr_array.size(); i++)
    {
        geo_ptr_array[i]->print_geometry();
    }
    // delete the geometry
    for (int i = 0; i < geo_ptr_array.size(); i++)
    {
        delete geo_ptr_array[i];
    }
    return 0;
}

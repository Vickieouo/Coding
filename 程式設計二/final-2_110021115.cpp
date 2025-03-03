#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <exception>
#include <iomanip>

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
    // write data members in binary format
    void write_binary_coords(ofstream &arg_ofs)
    {
        for (int i = 0; i < m_coords.size(); i++)
        {
            arg_ofs.write((char *)&m_coords[i], sizeof(double));
        }
    }
    // read data members in binary format
    void read_binary_coords(ifstream &arg_ifs)
    {
        char a;
        for (int i = 0; i < m_dim; i++)
        {
            arg_ifs.read((char *)&m_coords[i], sizeof(double));
        }
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
    virtual void print_geometry(ofstream &arg_ofs) {}
    // parse the cin to the geometry
    virtual void parse_geometry(ifstream &arg_ifs) {}
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
    void print_geometry(ofstream &arg_ofs)
    {
        int size = m_point_array.size();
        arg_ofs.write("t", sizeof(char));
        arg_ofs.write((char *)&size, sizeof(int));

        for (int i = 0; i < size; i++)
        {
            m_point_array[i].write_binary_coords(arg_ofs);
        }
    }
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs)
    {
        unsigned vertex_num;
        arg_ifs.read((char *)&vertex_num, sizeof(unsigned));

        for (int i = 0; i < vertex_num; i++)
        {
            Point_ND p(m_dim);
            p.read_binary_coords(arg_ifs);
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
    void print_geometry(ofstream &arg_ofs)
    {
        int size = m_point_array.size();
        arg_ofs.write("p", sizeof(char));
        arg_ofs.write((char *)&size, sizeof(int));

        for (int i = 0; i < size; i++)
        {
            m_point_array[i].write_binary_coords(arg_ofs);
        }
    }
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs)
    {
        unsigned int vertex_num;
        arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));

        for (int i = 0; i < vertex_num; i++)
        {
            Point_ND p(m_dim);
            p.read_binary_coords(arg_ifs);
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
    void print_geometry(ofstream &arg_ofs)
    {
        int size = m_point_array.size();
        arg_ofs.write("l", sizeof(char));
        arg_ofs.write((char *)&size, sizeof(int));

        for (int i = 0; i < size; i++)
        {
            m_point_array[i].write_binary_coords(arg_ofs);
        }
    }
    // parse the cin to the geometry
    void parse_geometry(ifstream &arg_ifs)
    {
        unsigned int vertex_num;
        arg_ifs.read((char *)&vertex_num, sizeof(unsigned int));

        for (int i = 0; i < vertex_num; i++)
        {
            Point_ND p(m_dim);
            p.read_binary_coords(arg_ifs);
            m_point_array.push_back(p);
        }
    }
};
const unsigned line_num_of_vertex = 2;

// Ref: https://stackoverflow.com/q/9621893
void print_output_file(int argc, char *argv[])
{
    ifstream ans_ifs(argv[2], ios::in | ios::binary);
    if (!ans_ifs)
    {
        cout << "Error: Cannot open output file" << endl;
        exit(1);
    }
    char ans_block = 0;
    unsigned offset_count = 0;

    ans_ifs.read(&ans_block, 1);
    while (!ans_ifs.eof())
    {
        int z = ans_block & 0xff;
        cout << std::hex
             << std::setfill('0')
             << std::setw(2)
             << z
             << " ";
        offset_count++;
        if (offset_count % 16 == 0)
        {
            cout << endl;
        }
        ans_ifs.read(&ans_block, 1);
    }
    cout << endl;
    ans_ifs.close();
}

int main(int argc, char *argv[])
{
    vector<Geometry_ND *> geo_ptr_array;
    string input_file_path(argv[1]);
    string output_file_path(argv[2]);

    char input;
    unsigned dim;
    Geometry_ND *geo_ptr;

    // open the input file
    ifstream infile(input_file_path, ios::in | ios::binary);

    // open the output file
    ofstream outfile(output_file_path, ios::out | ios::trunc | ios::binary);

    // read dimension
    infile.read((char *)&dim, sizeof(unsigned));

    // read geometry
    while (infile.get(input))
    {
        // check the geometry type
        switch (input)
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
        if (input == 't' || input == 'p' || input == 'l')
        {
            // parse the infile to the geometry
            geo_ptr->parse_geometry(infile);
            // push the pointer to the array
            geo_ptr_array.push_back(geo_ptr);
        }
    }
    // print the geometry
    // first, print the dimension
    outfile.write((char *)&dim, sizeof(unsigned));

    // second, print the geometry
    for (int i = 0; i < geo_ptr_array.size(); i++)
    {
        geo_ptr_array[i]->print_geometry(outfile);
    }
    // close the input & output file
    infile.close();
    outfile.close();

    // delete the geometry
    for (int i = 0; i < geo_ptr_array.size(); i++)
    {
        delete geo_ptr_array[i];
    }

    print_output_file(argc, argv);

    return 0;
}

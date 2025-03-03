#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

class Geometry_Comp;

class Complex
{
private:
    // data members
    // save the real and imaginary parts of the complex number
    // with `double` precision
    double m_real;
    double m_imag;

public:
    // Constructor, initializes real and imaginary parts
    Complex(const double &arg_real = 0.0, const double &arg_imag = 0.0) : m_real(arg_real), m_imag(arg_imag) {}
    // Copy constructor
    Complex(const Complex &arg_c) : m_real(arg_c.m_real), m_imag(arg_c.m_imag) {}
    // assignment operator
    Complex &operator=(const Complex &arg_c)
    {
        m_real = arg_c.m_real;
        m_imag = arg_c.m_imag;
        return *this;
    }
    // add assignment operator
    Complex &operator+=(const Complex &arg_c)
    {
        m_real += arg_c.m_real;
        m_imag += arg_c.m_imag;
        return *this;
    }
    // multiply assignment operator
    Complex &operator*=(const Complex &arg_c)
    {
        double re = m_real, im = m_imag;
        m_real = re * arg_c.m_real - im * arg_c.m_imag;
        m_imag = re * arg_c.m_imag + im * arg_c.m_real;
        return *this;
    }
    // length of the complex number
    double length() const
    {
        double length = sqrt(pow(m_real, 2) + pow(m_imag, 2));
        return length;
    }
    // angle of the complex number in radians
    // use `atan2` to compute the angle by the formula `atan(imag/real)`
    // and use `NAN` for 0/0 case
    // `atan2` ref: https://en.cppreference.com/w/cpp/numeric/math/atan2
    // `NAN` ref: https://en.cppreference.com/w/cpp/numeric/math/NAN
    double angle() const;
    void error_and_exit()
    {
        cout << "Error: Invalid input" << endl;
        exit(1);
    }
    // cout `<<` operator for print complex number
    // note: be careful about the format of output
    friend ostream &operator<<(ostream &arg_os, const Complex &arg_c)
    {
        if (arg_c.m_imag == 0)
        {
            if (arg_c.m_real == 0 || arg_c.m_real == -0)
            {
                arg_os << "0";
            }
            else
            {
                arg_os << arg_c.m_real;
            }
        }
        else if (arg_c.m_imag < 0)
        {
            arg_os << arg_c.m_real << " - " << (-1) * arg_c.m_imag << "i";
        }
        else
        {
            arg_os << arg_c.m_real << " + " << arg_c.m_imag << "i";
        }
        return arg_os;
    }
    // cin `>>` operator for input complex number
    // note: use `>>` to parse the string to double,
    // use `istream::fail()` to check the conversion is successful
    // and use `istream::eof()` to check the is parse to the end of line
    friend istream &operator>>(istream &arg_is, Complex &arg_c)
    {
        string str, str1, str2, str3;
        stringstream ss, ss1, ss2;
        getline(arg_is, str);
        if (str.empty())
        {
            getline(arg_is, str);
        }
        ss << str;
        getline(ss, str1, ' ');
        getline(ss, str2, ' ');
        getline(ss, str3, ' ');
        if (str2.empty() || !str3.empty())
        {
            arg_c.error_and_exit();
        }

        ss1 << str1;
        ss1 >> arg_c.m_real;
        if (ss1.fail() || ss1.rdbuf()->in_avail() != 0)
        {
            arg_c.error_and_exit();
        }
        
        ss2 << str2;
        ss2 >> arg_c.m_imag;
        if (ss2.fail() || ss2.rdbuf()->in_avail() != 0)
        {
            arg_c.error_and_exit();
        }
        return arg_is;
    }
    // friend class
    friend class Geometry_Comp;
};

class Geometry_Comp
{
protected:
    // data members
    vector<Complex> m_comp_array;
    // utility function to check if the transformation is valid
    // hint: use `isnan` to check the angle is valid or not
    // ref: https://en.cppreference.com/w/cpp/numeric/math/isnan
    bool _check_transform(const Complex &arg_trans_c, const char &arg_op);

public:
    // Constructor, initializes the array
    Geometry_Comp(const unsigned int &arg_num_of_vertex = 0) : m_comp_array(arg_num_of_vertex) {}
    // Copy constructor
    Geometry_Comp(const Geometry_Comp &arg_gc) : m_comp_array(arg_gc.m_comp_array) {}
    // assignment operator
    Geometry_Comp &operator=(const Geometry_Comp &arg_gc)
    {
        for (int i = 0; m_comp_array.size() != 0; i++)
        {
            m_comp_array.pop_back();
        }
        for (int i = 0; m_comp_array.size() < i; i++)
        {
            m_comp_array.push_back(arg_gc.m_comp_array[i]);
        }
        return *this;
    }
    // print the geometry
    virtual void print_geometry()
    {
        for (int i = 0; m_comp_array.size() > i; i++)
        {
            cout << m_comp_array[i] << endl;
        }
        cin.clear();
    }
    // parse the cin to the geometry
    virtual void parse_geometry(istream &arg_is)
    {
        stringstream ss;
        char c;
        unsigned int vertex;
        arg_is >> c;
        ss << c;
        ss >> vertex;

        Geometry_Comp gc;
        m_comp_array = gc.get_geometry_array(vertex);
    }
    // apply transformation to the geometry
    void transform_geometry(const Complex &arg_trans_c, const char &arg_op)
    {
        for (int i = 0; m_comp_array.size() > i; i++)
        {
            switch (arg_op)
            {
            case 'r':
                double length;
                length = arg_trans_c.length();
                if (length != 1 || (arg_trans_c.m_real == 0 && arg_trans_c.m_imag == 0))
                {
                    m_comp_array[i].error_and_exit();
                }
                else
                {
                    m_comp_array[i] *= arg_trans_c;
                }
                break;
            case 'z':
                if (arg_trans_c.m_imag != 0)
                {
                    m_comp_array[i].error_and_exit();
                }
                else
                {
                    m_comp_array[i] *= arg_trans_c;
                }
                break;
            case 'm':
                m_comp_array[i] += arg_trans_c;
                break;
            default:
                break;
            }
        }
    }
    // set the geometry
    void set_geometry(const vector<Complex> &arg_comp_array) {}
    // get the geometry array
    vector<Complex> get_geometry_array(const int vertex)
    {
        Geometry_Comp gc;
        for (int i = 0; i < vertex; i++)
        {
            Complex c(0.0, 0.0);
            cin >> c;
            gc.m_comp_array.push_back(c);
        }
        return gc.m_comp_array;
    }
};

class Triangle_Comp : public Geometry_Comp
{
public:
    // Constructor, initializes the array
    Triangle_Comp() {}
    // Copy constructor
    Triangle_Comp(const Triangle_Comp &arg_tc) : Geometry_Comp(arg_tc) {}
    // assignment operator
    Triangle_Comp &operator=(const Triangle_Comp &arg_tc);
    // print the geometry
    void print_geometry()
    {
        cout << "t\n"
             << m_comp_array.size() << endl;
        this->Geometry_Comp::print_geometry();
    }
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is)
    {
        string str;
        arg_is >> str;
        if (str != "3")
        {
            m_comp_array[0].error_and_exit();
        }

        int vertex;
        stringstream ss;
        ss << str;
        ss >> vertex;
        Geometry_Comp gc;
        m_comp_array = gc.get_geometry_array(vertex);
    }
};
const unsigned triangle_num_of_vertex = 3;

class Quadrilateral_Comp : public Geometry_Comp
{
public:
    // Constructor, initializes the array
    Quadrilateral_Comp() {}
    // Copy constructor
    Quadrilateral_Comp(const Quadrilateral_Comp &arg_qc) : Geometry_Comp(arg_qc) {}
    // assignment operator
    Quadrilateral_Comp &operator=(const Quadrilateral_Comp &arg_qc);
    // print the geometry
    void print_geometry()
    {
        cout << "q\n"
             << m_comp_array.size() << endl;
        this->Geometry_Comp::print_geometry();
    }
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is)
    {
        string str;
        arg_is >> str;
        if (str != "4")
        {
            m_comp_array[0].error_and_exit();
        }

        int vertex;
        stringstream ss;
        ss << str;
        ss >> vertex;
        Geometry_Comp gc;
        m_comp_array = gc.get_geometry_array(vertex);
    }
};
const unsigned quadrilateral_num_of_vertex = 4;

class Polygon_Comp : public Geometry_Comp
{
public:
    // Constructor, initializes the array
    Polygon_Comp() {}
    // Copy constructor
    Polygon_Comp(const Polygon_Comp &arg_pc) : Geometry_Comp(arg_pc) {}
    // assignment operator
    Polygon_Comp &operator=(const Polygon_Comp &arg_pc);
    // print the geometry
    void print_geometry()
    {
        cout << "p\n"
             << m_comp_array.size() << endl;
        this->Geometry_Comp::print_geometry();
    }
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is)
    {
        string str;
        arg_is >> str;
        int vertex;
        stringstream ss;
        ss << str;
        ss >> vertex;

        if (ss.fail() || vertex <= 3)
        {
            m_comp_array[0].error_and_exit();
        }

        Geometry_Comp gc;
        m_comp_array = gc.get_geometry_array(vertex);
    }
};

class Circle_Comp : public Geometry_Comp
{
public:
    // Constructor, initializes the array
    Circle_Comp() {}
    // Copy constructor
    Circle_Comp(const Circle_Comp &arg_cc) : Geometry_Comp(arg_cc) {}
    // assignment operator
    Circle_Comp &operator=(const Circle_Comp &arg_cc);
    // print the geometry
    void print_geometry()
    {
        cout << "c\n"
             << m_comp_array.size() << endl;
        this->Geometry_Comp::print_geometry();
    }
    // parse the cin to the geometry
    void parse_geometry(istream &arg_is)
    {
        string str;
        arg_is >> str;
        if (str != "2")
        {
            m_comp_array[0].error_and_exit();
        }

        int vertex;
        stringstream ss;
        ss << str;
        ss >> vertex;
        Geometry_Comp gc;
        m_comp_array = gc.get_geometry_array(vertex);
    }
};
const unsigned circle_num_of_vertex = 2;

// error and exit
void error_and_exit()
{
    cout << "Error: Invalid input" << endl;
    exit(1);
}

// used for process the test cases, do not modify
int main()
{
    string input, temp;
    vector<Geometry_Comp *> geo_ptr_array;
    Geometry_Comp *geo_ptr;
    Complex trans_c;
    char trans_op;

    while (getline(cin, input))
    {
        // check the geometry type
        switch (input[0])
        {
        case 't':
            geo_ptr = new Triangle_Comp();
            break;
        case 'q':
            geo_ptr = new Quadrilateral_Comp();
            break;
        case 'p':
            geo_ptr = new Polygon_Comp();
            break;
        case 'c':
            geo_ptr = new Circle_Comp();
            break;
        case 'r':
        case 'z':
        case 'm':
            getline(cin, temp);
            break;
        }
        if (input[0] == 't' || input[0] == 'q' || input[0] == 'p' || input[0] == 'c')
        {
            // parse the cin to the geometry
            geo_ptr->parse_geometry(cin);
            // print the geometry
            geo_ptr->print_geometry();
            // push the pointer to the array
            geo_ptr_array.push_back(geo_ptr);
        }
        else if (input[0] == 'r' || input[0] == 'z' || input[0] == 'm')
        {
            stringstream ss(temp);
            ss >> trans_c;
            // transform the geometry using operator and complex
            for (int i = 0; i < geo_ptr_array.size(); i++)
            {
                geo_ptr_array[i]->transform_geometry(trans_c, input[0]);
                // print transformed geometry
                geo_ptr_array[i]->print_geometry();
            }
        }
        else
        {
            if (input.empty())
            {
                continue;
            }
            else
            {
                error_and_exit();
            }
        }
    }
    return 0;
}
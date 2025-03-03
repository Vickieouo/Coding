#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

// Define a structure for storing linear coordinate values
struct DataPoint
{
    double m_x{};
    double m_y{};
};

// Read the training data from a file in CSV format.
const vector<DataPoint> &ReadData(string file)
{
    ifstream infile;
    static vector<DataPoint> data{};
    const char split_char{','};
    string line{};

    infile.open(file, ios::in);

    if (!infile.is_open())
    {
        cerr << "!!! Could not open file - '" << file << "'" << endl;
        exit(0);
    }

    while (getline(infile, line))
    {
        stringstream line_stream{line};
        vector<string> split_vector{};
        DataPoint tmpPoint{};

        while (getline(line_stream, line, split_char))
        {
            split_vector.push_back(line);
        }

        tmpPoint.m_x = stod(split_vector[0]);
        tmpPoint.m_y = stod(split_vector[1]);

        data.push_back(tmpPoint);
    }
    infile.close();

    return data;
}

// Use the least square method to linearly fit the input training set data,
// and return the fitting parameters beta0 and beta1.
const pair<double, double> &LinearRegressionModelTrain(const vector<DataPoint> &point_data)
{
    static pair<double, double> model_parameter{};

    // Calculate the x mean.
    double x_mean = accumulate(point_data.begin(), point_data.end(), 0.0,
                               [](double a, DataPoint tmp) -> double
                               {
                                   return a + tmp.m_x;
                               }) /
                    point_data.size();

    // Calculate the y mean.
    double y_mean = accumulate(point_data.begin(), point_data.end(), 0.0,
                               [](double a, DataPoint tmp) -> double
                               {
                                   return a + tmp.m_y;
                               }) /
                    point_data.size();

    // Calculate the beta1 value.
    double beta1_numerator{};
    double beta1_denominator{};

    for (size_t i = 0; i < point_data.size(); ++i)
    {
        beta1_numerator += point_data[i].m_y * (point_data[i].m_x - x_mean);
        beta1_denominator += pow(point_data[i].m_x, 2) - (point_data[i].m_x * x_mean);
    }

    // beta1
    model_parameter.second = beta1_numerator / beta1_denominator;
    // beta0
    model_parameter.first = y_mean - x_mean * model_parameter.second;

    return model_parameter;
}

double ModelPrediction(const pair<double, double> &beta, const double x)
{
    return beta.first + beta.second * x;
}

int main()
{
    // Read the data from csv file.
    string filename{"81-92.csv"};
    const vector<DataPoint> &train_data{ReadData(filename)};

    // Model fitting.
    const pair<double, double> &beta_parameter{LinearRegressionModelTrain(train_data)};

    cout << "The linear regression fitting model of 81y-92y is: "
         << "y = " << beta_parameter.first << " + "
         << beta_parameter.second << "x"
         << "\n";

    return EXIT_SUCCESS;
}
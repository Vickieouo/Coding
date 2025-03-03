#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    char buffer[10001]; // "+1" to store '\0'
    vector<int> a, b, n, r;
    int as = 1, bs = 1, c = 2, az, bz, i, k;

    cout << "Big number calculator\n"
         << "1) display only\n"
         << "2) plus (+)\n"
         << "3) minus (-)\n"
         << "4) multiplication (*)\n"
         << "5) division (/)\n"
         << "Please select the operator: ";
    cin >> buffer;
    if (!isdigit(buffer[0]) || buffer[1] != '\0')
    {
        cout << "Invalid input: " << buffer << endl;
        return 0;
    }
    else
    {
        int N = buffer[0] - '0';
        n.push_back(N);
    }

    switch (n[0])
    {
    case 1:
        cout << "You selected: display only\n";
        break;
    case 2:
        cout << "You selected: +\n";
        break;
    case 3:
        cout << "You selected: -\n";
        break;
    case 4:
        cout << "You selected: *\n";
        break;
    case 5:
        cout << "You selected: /\n";
        break;
    default:
        cout << "Invalid input: ";
        for (int i = 0; i < n.size(); i++)
        {
            cout << n[i];
        }
        cout << endl;
        return 0;
    }

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        buffer[i] = '\0'; // 清空buffer
    }

    cout << "Input integer number (a): ";
    cin >> buffer;

    bool zero = true;
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (!isdigit(buffer[i]))
        {
            if (i == 0 && buffer[i] == '-')
            {
                as = -1;
                continue;
            }
            else
            {
                cout << "Invalid input: " << buffer << endl;
                return 0;
            }
        }

        if (buffer[i] == '0' && zero)
        {
            continue;
        }
        else
        {
            a.push_back((int)(buffer[i] - '0'));
            zero = false;
        }
    }

    reverse(a.begin(), a.end());

    for (int i = 0; i < (10000 + 1); i++)
    {
        buffer[i] = '\0';
    }
    for (int i = a.size() - 1; i >= 1; i--)
    {
        if (a[i] == 0)
        {
            a.pop_back();
        }
        else
        {
            break;
        }
    }

    cout << "Input integer number (b): ";
    cin >> buffer;

    zero = true;
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (!isdigit(buffer[i]))
        {
            if (i == 0 && buffer[i] == '-')
            {
                bs = -1;
                continue;
            }
            else
            {
                cout << "Invalid input: " << buffer << endl;
                return 0;
            }
        }

        if (buffer[i] == '0' && zero)
        {
            continue;
        }
        else
        {
            b.push_back((int)(buffer[i] - '0'));
            zero = false;
        }
    }

    if (n[0] == 5)
    {
        int zero = 1;
        if (buffer[0] == '-' || buffer[0] == '0')
        {
            for (int i = 1; buffer[i] != '\0'; i++)
            {
                if (buffer[i] == '0')
                {
                    zero = 0;
                }
                else
                {
                    zero = 1;
                }
            }
        }
        if (zero == 0)
        {
            cout << "Invalid input: " << buffer << endl;
            return 0;
        }
    }

    reverse(b.begin(), b.end());

    for (int i = 0; i < (10000 + 1); i++)
    {
        buffer[i] = '\0';
    }
    for (int i = b.size() - 1; i >= 1; i--)
    {
        if (b[i] == 0)
        {
            b.pop_back();
        }
        else
        {
            break;
        }
    }

    cout << "(a) = ";
    reverse(a.begin(), a.end());
    if (as > 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
    else
    {
        if (a[0] == 0 && a.size() == 1)
        {
            for (int i = 0; i < a.size(); i++)
            {
                cout << a[i];
            }
        }
        else if (a[0] != 0 || a.size() > 1)
        {
            cout << "-";
            for (int i = 0; i < a.size(); i++)
            {
                cout << a[i];
            }
        }
        cout << endl;
    }
    reverse(a.begin(), a.end());

    cout << "(b) = ";
    reverse(b.begin(), b.end());
    if (bs > 0)
    {
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i];
        }
        cout << endl;
    }
    else
    {
        if (b[0] == 0 && b.size() == 1)
        {
            for (int i = 0; i < b.size(); i++)
            {
                cout << b[i];
            }
        }
        else if (b[0] != 0 || b.size() > 1)
        {
            cout << "-";
            for (int i = 0; i < b.size(); i++)
            {
                cout << b[i];
            }
        }
        cout << endl;
    }
    reverse(b.begin(), b.end());

    // Initialization Done ---------------------------------------------

    if (n[0] == 1) // "Display Only"
    {
        return 0;
    }
    else if (n[0] == 2) // "+"
    {
        if (as * bs < 0)
        {
            goto AminusB;
        }
    AplusB:
        if (a.size() != b.size())
        {
            if (a.size() > b.size())
            {
                while (a.size() > b.size())
                {
                    b.push_back(0);
                }
            }
            else
            {
                while (b.size() > a.size())
                {
                    a.push_back(0);
                }
            }
        }
        for (int i = 0; i < a.size(); i++)
        {
            r.push_back(a[i] + b[i]);
        }
        r.push_back(0);
        for (int i = 0; i < r.size() - 1; i++)
        {
            if (r[i] >= 10)
            {
                r[i + 1]++;
                r[i] = r[i] % 10;
            }
            else if (r[i] < 0 && i != 0)
            {
                r[i] = -1 * r[i];
            }
        }

        for (int i = r.size() - 1; i >= 1; i--)
        {
            if (r[i] == 0)
            {
                r.pop_back();
            }
            else
            {
                break;
            }
        }
        if (n[0] == 3)
        {
            goto AminusB_result;
        }

    AplusB_result:
        reverse(r.begin(), r.end());
        if (as * bs > 0)
        {
            if (as > 0)
            {
                cout << "(a) + (b) = ";
            }
            else
            {
                if ((a[0] == 0 && a.size() == 1) || (b[0] == 0 && b.size() == 1))
                {
                    cout << "(a) + (b) = ";
                }
                else if ((a[0] != 0 || a.size() != 1) || (b[0] != 0 || b.size() != 1))
                {
                    cout << "(a) + (b) = -";
                }
            }
        }
        else if (as * bs < 0)
        {
            if ((as > 0 && c == 1) || (as < 0 && c == -1) || c == 0)
            {
                if (c != 0)
                {
                    cout << "(a) + (b) = ";
                }
                else
                {
                    cout << "(a) + (b) = 0";
                }
            }
            else if ((as > 0 && c == -1) || (as < 0 && c == 1))
            {
                if ((a[0] == 0 && a.size() == 1) || (b[0] == 0 && b.size() == 1))
                {
                    cout << "(a) + (b) = ";
                }
                else if ((a[0] != 0 || a.size() != 1) || (b[0] != 0 || b.size() != 1))
                {
                    cout << "(a) + (b) = -";
                }
            }
        }
        if (c != 0)
        {
            for (int i = 0; i < r.size(); i++)
            {
                cout << r[i];
            }
            cout << endl;
            return 0;
        }
        else
        {
            return 0;
        }
    }
    else if (n[0] == 3) // "-"
    {
        if (as * bs < 0)
        {
            goto AplusB;
        }
    AminusB:
        if (a.size() == b.size())
        {
            for (int i = a.size() - 1; i >= 0; i--)
            {
                if (a[i] == b[i])
                {
                    c = 0;
                }
                else if (a[i] > b[i])
                {
                    c = 1;
                    break;
                }
                else if (a[i] < b[i])
                {
                    c = -1;
                    break;
                }
            }
        }
        if (c == 0)
        {
            if (n[0] == 2)
            {
                goto AplusB_result;
            }
            else if (n[0] == 3)
            {
                goto AminusB_result;
            }
        }

        az = a.size();
        bz = b.size();
        if (a.size() != b.size())
        {
            if (a.size() > b.size())
            {
                while (a.size() > b.size())
                {
                    b.push_back(0);
                }
            }
            else
            {
                while (b.size() > a.size())
                {
                    a.push_back(0);
                }
            }
        }
        for (int i = 0; i < (az >= bz ? az : bz); i++)
        {
            if (az > bz)
            {
                if (a[i] < b[i] && i != az - 1)
                {
                    a[i + 1]--;
                    a[i] = a[i] + 10;
                    r.push_back(a[i] - b[i]);
                }
                else if (a[i] >= b[i])
                {
                    r.push_back(a[i] - b[i]);
                }
                c = 1; //a>b
            }
            else if (az == bz)
            {
                if (a[az - 1] > b[bz - 1])
                {
                    if (a[i] < b[i] && i != az - 1)
                    {
                        a[i + 1]--;
                        a[i] = a[i] + 10;
                        r.push_back(a[i] - b[i]);
                    }
                    else if (a[i] >= b[i])
                    {
                        r.push_back(a[i] - b[i]);
                    }
                    c = 1; //a>b
                }
                else if (a[az - 1] == b[bz - 1])
                {
                    int i = 1;
                    while (a[az - i] == b[bz - i] && i != az - 1)
                    {
                        i++;
                    }
                    if (a[az - i] > b[bz - i])
                    {
                        if (a[i] < b[i] && i != a.size() - 1)
                        {
                            a[i + 1]--;
                            a[i] = a[i] + 10;
                            r.push_back(a[i] - b[i]);
                        }
                        else if (a[i] >= b[i])
                        {
                            r.push_back(a[i] - b[i]);
                        }
                        c = 1; //a>b
                    }
                    else if (a[az - i] < b[bz - i])
                    {
                        if (b[i] < a[i] && i != b.size() - 1)
                        {
                            b[i + 1]--;
                            b[i] = b[i] + 10;
                            r.push_back(b[i] - a[i]);
                        }
                        else if (b[i] >= a[i])
                        {
                            r.push_back(b[i] - a[i]);
                        }
                        c = -1; //a<b
                    }
                }
                else if (a[az - 1] < b[bz - 1])
                {
                    if (b[i] < a[i] && i != a.size() - 1)
                    {
                        b[i + 1]--;
                        b[i] = b[i] + 10;
                        r.push_back(b[i] - a[i]);
                    }
                    else if (b[i] >= a[i])
                    {
                        r.push_back(b[i] - a[i]);
                    }
                    c = -1; //a<b
                }
                else
                {
                    if (b[i] < a[i] && i != a.size() - 1)
                    {
                        b[i + 1]--;
                        b[i] = b[i] + 10;
                        r.push_back(b[i] - a[i]);
                    }
                    else if (b[i] >= a[i])
                    {
                        r.push_back(b[i] - a[i]);
                    }
                    c = -1; //a<b
                }
            }

            else if (az < bz)
            {
                if (b[i] < a[i] && i != a.size() - 1)
                {
                    b[i + 1]--;
                    b[i] = b[i] + 10;
                    r.push_back(b[i] - a[i]);
                }
                else if (b[i] >= a[i])
                {
                    r.push_back(b[i] - a[i]);
                }
                c = -1; //a<b
            }
        }

        for (int i = 0; i < r.size() - 1; i++)
        {
            if (r[i] >= 10)
            {
                r[i + 1]++;
                r[i] = r[i] % 10;
            }
            else if (r[i] < 0 && i != 0)
            {
                r[i] = -1 * r[i];
            }
        }
        for (int i = r.size() - 1; i >= 1; i--)
        {
            if (r[i] == 0)
            {
                r.pop_back();
            }
            else
            {
                break;
            }
        }

        if (n[0] == 2)
        {
            goto AplusB_result;
        }

    AminusB_result:
        if (as * bs < 0)
        {
            if (as > 0)
            {
                cout << "(a) - (b) = ";
            }
            else
            {
                if ((a[0] == 0 && a.size() == 1) || (b[0] == 0 && b.size() == 1))
                {
                    cout << "(a) - (b) = ";
                }
                else if ((a[0] != 0 || a.size() != 1) || (b[0] != 0 || b.size() != 1))
                {
                    cout << "(a) - (b) = -";
                }
            }
        }
        else if (as * bs > 0)
        {
            if ((as > 0 && c == 1) || (as < 0 && c == -1) || c == 0)
            {
                if (c != 0)
                {
                    cout << "(a) - (b) = ";
                }
                else
                {
                    cout << "(a) - (b) = 0";
                }
            }
            else if ((as > 0 && c == -1) || (as < 0 && c == 1))
            {
                if ((a[0] == 0 && a.size() == 1) || (b[0] == 0 && b.size() == 1))
                {
                    cout << "(a) - (b) = ";
                }
                else if ((a[0] != 0 || a.size() != 1) || (b[0] != 0 || b.size() != 1))
                {
                    cout << "(a) - (b) = -";
                }
            }
        }
        if (c != 0)
        {
            reverse(r.begin(), r.end());
            for (int i = 0; i < r.size(); i++)
            {
                cout << r[i];
            }
            cout << endl;
            return 0;
        }
        else
        {
            return 0;
        }
    }
    else if (n[0] == 4) // "*"
    {
        while (r.size() < a.size() + b.size())
        {
            r.push_back(0);
        }
        vector<int> rb;

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                rb.push_back(a[i] * b[j]);
            }
            rb.push_back(0);
            for (int k = 0; k < rb.size() - 1; k++)
            {
                while (rb[k] >= 10)
                {
                    rb[k + 1] = rb[k + 1] + rb[k] / 10;
                    rb[k] = rb[k] % 10;
                }
            }
            for (int k = 0; k < rb.size(); k++)
            {
                r[k + i] = r[k + i] + rb[k];
            }

            while (rb.size() != 0)
            {
                rb.pop_back();
            }
        }
        for (int i = 0; i < r.size() - 1; i++)
        {
            while (r[i] >= 10)
            {
                r[i + 1] = r[i + 1] + r[i] / 10;
                r[i] = r[i] % 10;
            }
        }

        for (int i = r.size() - 1; i >= 1; i--)
        {
            if (r[i] == 0)
            {
                r.pop_back();
            }
            else
            {
                break;
            }
        }
        reverse(r.begin(), r.end());

        if (as * bs > 0)
        {
            cout << "(a) * (b) = ";
        }
        else
        {
            if ((a[0] == 0 && a.size() == 1) || (b[0] == 0 && b.size() == 1))
            {
                cout << "(a) * (b) = ";
            }
            else if ((a[0] != 0 || a.size() != 1) || (b[0] != 0 || b.size() != 1))
            {
                cout << "(a) * (b) = -";
            }
        }
        for (int i = 0; i < r.size(); i++)
        {
            cout << r[i];
        }
        cout << endl;
        return 0;
    }
    else if (n[0] == 5) // "/"
    {
        k = 0;
        if (a.size() < b.size())
        {
            c = -1;
        }
        else if (a.size() == b.size())
        {
            for (int i = a.size() - 1; i >= 0; i--)
            {
                if (a[i] == b[i])
                {
                    c = 0;
                }
                else if (a[i] > b[i])
                {
                    c = 1;
                    break;
                }
                else if (a[i] < b[i])
                {
                    c = -1;
                    break;
                }
            }
        }
        else if (a.size() > b.size())
        {
            c = 1;
        }

        if (c == 0)
        {
            cout << "(a) / (b) = " << as * bs << endl;
            return 0;
        }
        else if (c == -1)
        {
            cout << "(a) / (b) = 0" << endl;
            return 0;
        }

        while (c == 1)
        {
            az = a.size();
            bz = b.size();
            while (a.size() > b.size())
            {
                b.push_back(0);
            }
            for (int i = 0; i < az; i++)
            {
                if (a[i] < b[i])
                {
                    a[i + 1]--;
                    a[i] = a[i] + 10;
                    r.push_back(a[i] - b[i]);
                }
                else if (a[i] >= b[i])
                {
                    r.push_back(a[i] - b[i]);
                }
            }
            for (int i = 0; i < r.size() - 1; i++)
            {
                if (r[i] >= 10)
                {
                    r[i + 1]++;
                    r[i] = r[i] % 10;
                }
                else if (r[i] < 0)
                {
                    r[i] = -1 * r[i];
                }
            }
            for (int i = r.size() - 1; i >= 1; i--)
            {
                if (r[i] == 0)
                {
                    r.pop_back();
                }
                else
                {
                    break;
                }
            }

            k++;

            while (a.size() != r.size())
            {
                a.pop_back();
            }
            for (int i = 0; i < a.size(); i++)
            {
                a[i] = r[i];
            }
            while (r.size() != 0)
            {
                r.pop_back();
            }
            for (int i = b.size() - 1; i >= 1; i--)
            {
                if (b[i] == 0)
                {
                    b.pop_back();
                }
                else
                {
                    break;
                }
            }

            if (a.size() < b.size())
            {
                c = -1;
            }
            else if (a.size() == b.size())
            {
                for (int i = a.size() - 1; i >= 0; i--)
                {
                    if (a[i] == b[i])
                    {
                        c = 0;
                    }
                    else if (a[i] > b[i])
                    {
                        c = 1;
                        break;
                    }
                    else if (a[i] < b[i])
                    {
                        c = -1;
                        break;
                    }
                }
            }
            else if (a.size() > b.size())
            {
                c = 1;
            }

            if (c == 0)
            {
                cout << "(a) / (b) = " << as * bs * (k + 1) << endl;
                return 0;
            }
            else if (c == -1)
            {
                cout << "(a) / (b) = " << as * bs * k << endl;
                return 0;
            }
        }
    }
}
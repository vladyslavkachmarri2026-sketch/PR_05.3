// Labs 05.3
// Качмар Владислав 
// 12 варіант
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(const double x);

int main()
{
    double tp, tk, dt, z;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;

    dt = (tk - tp) / n;
    double t = tp;

    cout << fixed;
    cout << "--------------------------------------" << endl;
    cout << "|" << setw(8) << "t" << "          |" << setw(10) << "z" << "       |" << endl;
    cout << "--------------------------------------" << endl;

    // Цикл табулювання (з урахуванням можливих похибок додаю dt/2)
    while (t <= tk + dt / 2)
    {
        // Основний вираз: f(t^2) + 2 * f(2*t + 1)
        z = f(t * t) + 2 * f(2 * t + 1);

        cout << "|" << setw(10) << setprecision(3) << t << "        |"
            << setw(12) << setprecision(3) << z << "     |" << endl;

        t += dt;
    }
    cout << "--------------------------------------" << endl;

    return 0;
}

// Допоміжна функція f(x)
double f(const double x)
{
    if (abs(x) >= 1.0)
    {
        return (sin(x) + 1.0) / (sin(x) + cos(x));
    }
    else
    {
        // Обчислення суми ряду від i = 0 до 8
        // a_0 = x (при i = 0)
        double a = x;
        double S = a;

        for (int i = 1; i <= 8; i++)
        {
            // Рекурентна формула:
            // ai = a{i-1} * (x^2) / (2i * (2i + 1))
            double R = (x * x) / ((2 * i) * (2 * i + 1));
            a *= R;
            S += a;
        }

        return S;
    }
}
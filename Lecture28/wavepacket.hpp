#include "cptstd.hpp"
#include "linalg.hpp"
using namespace cpt;

// Constants
const double pi = 4 * atan(1.0);

double h_bar = 1;                   // natural units
double mass = 1;                    // natural units

// The spatial grid
int N = 128;                        // number of interior grid points
double L = 100;                     // system extends from x=0 to x=L
double dx = L / N;                  // grid spacing
double dt = 0.1;                    // time step
Matrix<double,1> x;                 // coordinates of grid points
bool periodic = true;               // false = oo potential, true = periodic

// The potential V(x)
double V_0 = 0.5;                   // height of potential barrier
double V_width = 10;                // width of potential barrier
double V_center = 0.75 * L;         // center of potential barrier
bool gaussian = false;              // true = Gaussian, false = step potential

double V(double x)                  // potential function
{
    double half_width = abs(0.5 * V_width);
    if (gaussian) {
        double d = x - V_center;
        return V_0 * exp( - d * d / (2 * half_width * half_width));
    } else {
        if (abs(x - V_center) <= half_width)
            return V_0;
        else
            return 0.0;
    }
}

// Initial wave packet
double x_0 = L / 4;                 // location of center
double E = 1;                       // average energy
double sigma_0 = L / 10;            // width of wave packet
double psi_norm;                    // norm of psi
double k_0;                         // average wavenumber
double velocity;                    // average velocity

Matrix<complex<double>,1> psi(N+2); // complex wave function

double t;                           // time

void initialize ()
{
    t = 0;

    // reset vectors
    x = Matrix<double,1>(N);
    psi = Matrix<complex<double>,1>(N);

    // reset the lattice
    dx = L / N;
    for (int j = 0; j < N; j++)
        x[j] = j * dx;

    // inititalize the packet
    k_0 = sqrt(2*mass*E - h_bar*h_bar/2/sigma_0/sigma_0) / h_bar;
    velocity = k_0 / mass;
    psi_norm = 1 / sqrt(sigma_0 * sqrt(pi));
    for (int j = 0; j < N; j++) {
        double exp_factor =
            exp(-(x[j] - x_0) * (x[j] - x_0) / (2 * sigma_0 * sigma_0));
        psi[j] = complex<double>(
            psi_norm * cos(k_0 * x[j]) * exp_factor,
            psi_norm * sin(k_0 * x[j]) * exp_factor);
    }
}

// definitions for simple Gnuplot animation
#include <cstdio>
#ifdef _WIN32
    string gnuplot = "env pgnuplot.exe -persist ";
    string terminal = "windows";
    FILE *gnupipe = _popen(gnuplot.c_str(), "w");
#else
    string gnuplot = "/usr/bin/env gnuplot -persist ";
    string terminal = "x11";
    FILE *gnupipe = popen(gnuplot.c_str(), "w");
#endif

void save_psi(int plot_number) {
    ostringstream os;
    os  << "psi_" << plot_number << ".data";
    string file_name(os.str());
    ofstream file(file_name.c_str());
    if (file)
        cout << " writing " << file_name << endl;
    else
        cerr << " cannot open " << file_name << endl;
    for (int i = 0; i < N; i++)
        file << x[i] << '\t' << norm(psi[i]) << '\t'
             << psi[i].real() << '\t' << psi[i].imag() << '\n';
    file.close();
}
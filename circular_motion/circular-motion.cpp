#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/*Format of the file init_data.dat
x0 y0 t0 tf dt R omega

*/

void read_init_data(double&, double&, double&, double&, double&, double&, double&);
void calculate_state(double, double, double, double, double, double&, double&, double&, double&);
void output_data(ofstream&, double, double, double, double, double);

int main(){

    double x0, y0, t0, dt, tf, R, x, y, vx, vy;
    double delta_t, theta, omega;
    ofstream output_file ("data.dat");
    output_file.precision(15);

    read_init_data(x0, y0, t0, tf, dt, R, omega);

    for (double t=t0; t<=tf; t = t + dt){
        delta_t = t - t0;
        theta = omega*delta_t;
        calculate_state(x0, y0, R, theta, omega, x, y, vx, vy);
        output_data(output_file, t, x, y, vx, vy);
    }

    return (0);
}

void read_init_data(double& x0, double& y0, double& t0, double& tf, double& dt, double& R, double& omega){

    ifstream input_file ("init_data.dat");
    input_file >> x0 >> y0 >> t0 >> tf >> dt >> R >> omega;
}

void calculate_state(double x0, double y0, double R, double theta, double omega,
                     double& x, double& y, double& vx, double& vy){

    x = x0 + R*cos(theta);
    y = y0 + R*sin(theta);
    vx = -omega*R*sin(theta);
    vy = omega*R*cos(theta);
}

void output_data(ofstream& output_file, double t, double x, double y, double vx, double vy){

    output_file << t << " " << x << " " << y << " " << vx << " " << vy << endl;
}

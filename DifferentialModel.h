using namespace std;

void differentialModel() {
    
    //initial values
    double Sv0 = 10;        // Initial No. of Susceptible Vector
    double Sh0 = 1600;      // Initial No. of Susceptible Host
    double Iv0 = 1;         // Initial No. of Infected Vector
    double Ih0 = 0;         // Initial No. of Infected Host
    double R0 = 0;          // Initial No. of Recovered Patients

    //rates
    double Dv = 1/12;       // Death Rate of Vector
    double Dh = 0;          // Death Rate of Host
    double Bv = 0.000045;   // Transmission Rate Vector
    double Bh = 0.0028;     // Transmission Rate Host
    double r = 0.03;        // Recovery Rate of Patients

    //DIFFERENTIAL EQUATIONS
    // dSh/dt = -BhShIv;
    // dIh/dt = BhShIv - rIh;
    // dR/dt = +rIh;
    // dIv/dt = BvSvIh - dvIv;

    dt = 1;
    lengthOfSeason = 45;
    
    vector<double> Sh;
    vector<double> Ih;
    vector<double> R;
    vector<double> Iv;

    //pushing initial values into vector containers
    Sh.push_back(Sh0);
    Ih.push_back(Ih0);
    R.push_back(R0);
    Iv.push_back(Iv0);

    cout<<endl<<endl;

    for(int day = 1; day <= (int)lengthOfSeason; day++) {
        double prev_Sh = Sh.back();
        double prev_Ih = Ih.back();
        double prev_R = R.back();
        double prev_Iv = Iv.back();

        // dSh/dt = -BhShIv;
        // (next_Sh - prev_Sh) / dt = - Bh0 * prev_Sh * prev_Iv;
        // next_Sh = prev_Sh - Bh0 * prev_Sh * prev_Iv * dt;
        double next_Sh = prev_Sh - Bh * prev_Sh * prev_Iv * dt;
        Sh.push_back(next_Sh);

        // dIh/dt = BhShIv - rIh;
        // (next_Ih - prev_Ih) / dt = Bh0 * prev_Sh * prev_Iv * dt - r * prev_Ih;
        // next_Ih = prev_Ih + (Bh0 * prev_Sh * prev_Iv * dt - r * prev_Ih) * dt;
        double next_Ih = prev_Ih + (Bh * prev_Sh * prev_Iv * dt - r * prev_Ih) * dt;
        Ih.push_back(next_Ih);

        // dR/dt = +rIh;
        // (next_R - prev_R) / dt = r * prev_Ih;
        // next_R = prev_R + r * prev_Ih * dt;
        double next_R = prev_R + r * prev_Ih * dt;
        R.push_back(next_R);

        // dIv/dt = BvSvIh - DvIv;
        // (next_Iv - prev_Iv) / dt = Bv0 * Sv0 * prev_Ih - Dv0 * prev_Iv;
        // next_Iv = prev_IV + (Bv0 * Sv0 * prev_Ih - Dv0 * prev_Iv) * dt;
        double next_Iv = prev_Iv + (Bv * Sv0 * prev_Ih - Dv * prev_Iv) * dt;
        Iv.push_back(next_Iv);

        cout << "Day-" << day << "\t\t";
        cout << "Sh: " << Sh.back() << "\t" << "Ih: " << Ih.back() << "\t" << "Rh: " << R.back() << "\t" << "Iv: " << Iv.back() <<endl;
    }
     
}
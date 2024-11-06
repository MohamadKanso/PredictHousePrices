#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class LinearRegression {
private:
    vector<double> theta;
    
    // Helper function to calculate mean
    double mean(const vector<double>& v) {
        double sum = 0;
        for(double x : v) sum += x;
        return sum / v.size();
    }
    
public:
    void fit(const vector<vector<double>>& X, const vector<double>& y) {
        int n = X.size(); // number of samples
        int m = X[0].size(); // number of features
        theta.resize(m);
        
        // Calculate means for features and target
        vector<double> x_means(m);
        for(int j = 0; j < m; j++) {
            double sum = 0;
            for(int i = 0; i < n; i++) {
                sum += X[i][j];
            }
            x_means[j] = sum / n;
        }
        double y_mean = mean(y);
        
        // Calculate coefficients using normal equation
        vector<vector<double>> xx(m, vector<double>(m));
        vector<double> xy(m);
        
        // Calculate XX' and XY
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                double sum = 0;
                for(int k = 0; k < n; k++) {
                    sum += (X[k][i] - x_means[i]) * (X[k][j] - x_means[j]);
                }
                xx[i][j] = sum;
            }
            
            double sum = 0;
            for(int k = 0; k < n; k++) {
                sum += (X[k][i] - x_means[i]) * (y[k] - y_mean);
            }
            xy[i] = sum;
        }
        
        // Solve system of equations
        double det = xx[0][0] * xx[1][1] - xx[0][1] * xx[1][0];
        theta[0] = (xx[1][1] * xy[0] - xx[0][1] * xy[1]) / det;
        theta[1] = (xx[0][0] * xy[1] - xx[1][0] * xy[0]) / det;
        
        // Calculate intercept
        double intercept = y_mean;
        for(int i = 0; i < m; i++) {
            intercept -= theta[i] * x_means[i];
        }
        theta.push_back(intercept);
    }
    
    double predict(const vector<double>& x) const {
        double result = theta.back(); // intercept
        for(size_t i = 0; i < x.size(); i++) {
            result += theta[i] * x[i];
        }
        return result;
    }
};

int main() {
    int F, N;
    cin >> F >> N;
    
    vector<vector<double>> X(N, vector<double>(F));
    vector<double> y(N);
    
    // Read training data
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < F; j++) {
            cin >> X[i][j];
        }
        cin >> y[i];
    }
    
    // Train model
    LinearRegression model;
    model.fit(X, y);
    
    // Process queries
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        vector<double> query(F);
        for(int j = 0; j < F; j++) {
            cin >> query[j];
        }
        cout << fixed << setprecision(2) << model.predict(query) << endl;
    }
    
    return 0;
}
